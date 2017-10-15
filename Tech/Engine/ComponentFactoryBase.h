///////////////////////////////////////////////////////////////////////////////////////
/// All content (c) 2017 The Other Game Engine, all rights reserved
/// FILE: ComponentFactoryBase.h
/// DATE: 2017-10-15 / 2017-10-15
/// AUTHOR(S): Aditya Subramanian <adu101992@gmail.com>
///////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Component.h"

class Component;

class ComponentFactoryBase
{
public:
	virtual Component* AddInstance(Component * archetype) = 0;
	virtual Component* AddInstance() = 0;
	virtual void RemoveInstance(Component * component) = 0;
	virtual Component * GetInstance(Handle handle) = 0;
	virtual void ClearInstances() = 0;
};
