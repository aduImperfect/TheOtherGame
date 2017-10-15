///////////////////////////////////////////////////////////////////////////////////////
/// All content (c) 2017 The Other Game Engine, all rights reserved
/// FILE: GameObjectFactory.h
/// DATE: 2017-10-15 / 2017-10-15
/// AUTHOR(S): Aditya Subramanian <adu101992@gmail.com>
///////////////////////////////////////////////////////////////////////////////////////

#pragma once
#include "Component.h"
#include "ComponentFactoryBase.h"
#include "Log.h"

template<const uint size = 2048>
class GameObjectFactory
{
private:
	GameObject instances[size];
	uint activeSize;
	Handle nextHandle;

	std::vector<GameObject*> activeObject;

public:
	GameObjectFactory() : activeSize(0), nextHandle(1) {}

	std::vector<GameObject*>& GetActiveObjects() { return activeObjects; }

	GameObject * AddInstance(Handle handle)
	{
		//Search for open space.
		for (uint i = 0; i < activeSize; ++i)
		{
			if (instances[i].active)
				continue;

			instances[i].handle = handle;
			instances[i].active = true;
			activeObjects.push_back(&instances[i]);
			return &instances[i];
		}

		//Append to the end if no open space found in between.
		//activeSize != size.
		LOGASSERT(activeSize != size, "Factory Size Capacity Exceeded!");

		if (activeSize == size)
			return nullptr;

		instances[activeSize].handle = handle;
		instances[activeSize].active = true;
		++activeSize;
		activeObjects.push_back(&instances[activeSize - 1]);
		return &instances[activeSize - 1];
	}

	void RemoveInstance(GameObject * gameObject)
	{
		for (uint i = 0; i < activeSize; ++i)
		{
			if (&instances[i] != gameObject)
				continue;

			instances[i].active = false;
			instances[i].RemoveAllComponents();

			auto iter = std::remove(activeObjects.begin(), activeObjects.end(), gameObject);
			activeObjects.erase(iter, activeObjects.end());

			if (i == (activeSize - 1))
			{
				--activeSize;
			}
			return;
		}
	}

	GameObject * GetInstance(Handle handle)
	{
		for (uint i = 0; i < activeSize; ++i)
		{
			if (instances[i].handle != handle)
				continue;

			return &instances[i];
		}
		return nullptr;
	}

	void ClearInstances()
	{
		for (uint i = 0; i < activeSize; ++i)
		{
			instances[i].active = false;
			instances[i].RemoveAllComponents();
		}
		activeObjects.clear();

		activeSize = 0;
		nextHandle = 1;
	}

	void FlushToEditor()
	{
		for (uint i = 0; i < activeSize; ++i)
		{
			if (!instances[i].active)
				continue;

			instances[i].FlushToEditor();
		}
	}
};
