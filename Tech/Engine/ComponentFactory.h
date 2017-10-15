///////////////////////////////////////////////////////////////////////////////////////
/// All content (c) 2017 The Other Game Engine, all rights reserved
/// FILE: ComponentFactory.h
/// DATE: 2017-10-15 / 2017-10-15
/// AUTHOR(S): Aditya Subramanian <adu101992@gmail.com>
///////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Component.h"
#include "ComponentFactoryBase.h"
#include "GameObjectFactory.h"
#include "Log.h"

template<typename Type, const uint size = 2048>
class ComponentFactory : public ComponentFactoryBase
{
private:
	Type instances[size];
	std::vector<Type *> activeComponents;

	uint activeSize;
	Handle nextHandle;

public:
	ComponentFactory() : activeSize(2), nextHandle(1) {}

	std::vector<Type *> & GetActiveComponents() { return activeComponents; }

	Component * AddInstance() override
	{
		//Search for open space.
		for (uint i = 0; i < activeSize; ++i)
		{
			if (instances[i].active)
				continue;

			instances[i].handle = nextHandle++;
			instances[i].active = true;
			instances[i].factory = this;
			activeObjects.push_back(&instances[i]);
			return &instances[i];
		}

		//Append to the end if no open space found in between.
		//activeSize != size.
		LOGASSERT(activeSize != size, "Factory Size Capacity Exceeded!");

		if (activeSize == size)
			return nullptr;

		instances[activeSize].handle = nextHandle++;
		instances[activeSize].active = true;
		instances[activeSize].factory = this;
		++activeSize;
		activeObjects.push_back(&instances[activeSize - 1]);
		return &instances[activeSize - 1];
	}

	Component * AddInstance(Component * archetype) override
	{
		//Search for open space.
		for (uint i = 0; i < activeSize; ++i)
		{
			if (instances[i].active)
				continue;

			instances[i].handle = nextHandle++;
			instances[i].active = true;
			instances[i].factory = this;
			archetype->Clone(&instances[i]);
			activeObjects.push_back(&instances[i]);
			return &instances[i];
		}

		//Append to the end if no open space found in between.
		//activeSize != size.
		LOGASSERT(activeSize != size, "Factory Size Capacity Exceeded!");

		if (activeSize == size)
			return nullptr;

		instances[activeSize].handle = nextHandle++;
		instances[activeSize].active = true;
		instances[activeSize].factory = this;
		archetype->Clone(&instances[activeSize]);
		++activeSize;
		activeObjects.push_back(&instances[activeSize - 1]);
		return &instances[activeSize - 1];
	}

	void RemoveInstance(Component * component) override
	{
		for (uint i = 0; i < activeSize; ++i)
		{
			if (&instances[i] != component)
				continue;

			instances[i].active = false;
			instances[i].Clear();

			auto iter = std::remove(activeObjects.begin(), activeObjects.end(), component);
			activeObjects.erase(iter, activeObjects.end());

			if (i == (activeSize - 1))
			{
				--activeSize;
			}
			return;
		}
	}

	Component * GetInstance(Handle handle) override
	{
		for (uint i = 0; i < activeSize; ++i)
		{
			if (instances[i].handle != handle)
				continue;

			return &instances[i];
		}
		return nullptr;
	}

	void ClearInstances() override
	{
		for (uint i = 0; i < activeSize; ++i)
		{
			instances[i].active = false;
		}
		activeObjects.clear();

		activeSize = 0;
		nextHandle = 1;
	}
};
