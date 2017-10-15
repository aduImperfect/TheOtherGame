///////////////////////////////////////////////////////////////////////////////////////
/// All content (c) 2017 The Other Game Engine, all rights reserved
/// FILE: Component.cpp
/// DATE: 2017-10-15 / 2017-10-15
/// AUTHOR(S): Aditya Subramanian <adu101992@gmail.com>
///////////////////////////////////////////////////////////////////////////////////////

#include "Precompiled.h"
#include "Component.h"
#include "ComponentFactoryBase.h"

Component::Component(ComponentType type) : type(type), fromArchetype(true), factory(nullptr)
{

}

void Component::Unregister()
{
	factory->RemoveInstance(this);
	Clear();
}
