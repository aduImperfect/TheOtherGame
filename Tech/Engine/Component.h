///////////////////////////////////////////////////////////////////////////////////////
/// All content (c) 2017 The Other Game Engine, all rights reserved
/// FILE: Component.h
/// DATE: 2017-10-15 / 2017-10-15
/// AUTHOR(S): Aditya Subramanian <adu101992@gmail.com>
///////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Precompiled.h"

enum class ComponentType
{
	Transform = 0,
	Model,
	Script,
	Controller,
	GameplayIdentifier,
	/*
	Physics collision type components*/
	Count
};

class GameObject;
class ComponentFactoryBase;

class Component
{
	template<typename Component, const uint size>
	friend class ComponentFactory;
	friend class GameObject;

private:
	Handle handle;
	ComponentType type;
	GameObject* owner;
	bool active;
	bool fromArchetype;

	//Needed so we can have a component remove itself from the active instances of itself.
	ComponentFactoryBase * factory;

protected:
	Component(ComponentType type);
	virtual void Clone(Component* target) const = 0;

	void Unregister();

public:
	//This is run when the component is actually instantiated - put any one time initialization code here.
	virtual void Initialize() {}

	//This is run when a component is deactivated - handle anything that won't be overwritten at next activation here (lists that are appended rather than cleared...)
	virtual void Clear() = 0;

	virtual bool operator==(const Component& rhs) = 0;

	ComponentType GetType() const { return type; }

	GameObject* GetOwner() const { return owner; }
	void SetOwner(GameObject * newOwner) { owner = newOwner; }

	virtual void Serialize(YAML::Node &node) const = 0;
	virtual void Deserialize(YAML::Node &node) = 0;

	virtual void FlushToEditor() = 0;
};