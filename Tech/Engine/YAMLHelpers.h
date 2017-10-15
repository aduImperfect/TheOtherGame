///////////////////////////////////////////////////////////////////////////////////////
/// All content (c) 2017 The Other Game Engine, all rights reserved
/// FILE: YAMLHelpers.h
/// DATE: 2017-10-15 / 2017-10-15
/// AUTHOR(S): Aditya Subramanian <adu101992@gmail.com>
///////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Precompiled.h"
#include "Log.h"

namespace YAML
{
	//Conversion for glm::vec2
	template<>
	struct convert<glm::vec2>
	{
		static Node encode(const glm::vec2& rhs)
		{
			Node node;
			node.push_back(rhs.x);
			node.push_back(rhs.y);
			return node;
		}

		static bool decode(const Node& node, glm::vec2& rhs)
		{
			if ((!node.IsSequence()) || (node.size() != 2))
			{
				return false;
			}

			rhs.x = node[0].as<float>();
			rhs.y = node[1].as<float>();
			return true;
		}
	};

	//Conversion for glm::vec3
	template<>
	struct convert<glm::vec3>
	{
		static Node encode(const glm::vec3& rhs)
		{
			Node node;
			node.push_back(rhs.x);
			node.push_back(rhs.y);
			node.push_back(rhs.z);
			return node;
		}

		static bool decode(const Node& node, glm::vec3& rhs)
		{
			if ((!node.IsSequence()) || (node.size() != 3))
			{
				return false;
			}

			rhs.x = node[0].as<float>();
			rhs.y = node[1].as<float>();
			rhs.z = node[2].as<float>();
			return true;
		}
	};

	//Conversion for glm::ivec2
	template<>
	struct convert<glm::ivec2>
	{
		static Node encode(const glm::ivec2& rhs)
		{
			Node node;
			node.push_back(rhs.x);
			node.push_back(rhs.y);
			return node;
		}

		static bool decode(const Node& node, glm::ivec2& rhs)
		{
			if ((!node.IsSequence()) || (node.size() != 2))
			{
				return false;
			}

			rhs.x = node[0].as<int>();
			rhs.y = node[1].as<int>();
			return true;
		}
	};

	//Conversion for glm::quat
	template<>
	struct convert<glm::quat>
	{
		static Node encode(const glm::quat& rhs)
		{
			Node node;
			node.push_back(rhs.x);
			node.push_back(rhs.y);
			node.push_back(rhs.z);
			node.push_back(rhs.w);
			return node;
		}

		static bool decode(const Node& node, glm::quat& rhs)
		{
			if ((!node.IsSequence()) || (node.size() != 4))
			{
				return false;
			}

			rhs.x = node[0].as<float>();
			rhs.y = node[1].as<float>();
			rhs.z = node[2].as<float>();
			rhs.w = node[3].as<float>();
			return true;
		}
	};

	template<typename T>
	T SafeAs(YAML::Node &node)
	{
		try
		{
			return node.as<T>();
		}
		catch (InvalidNode &errNode)
		{
			LOGASSERT(false, std::string("YAML ERROR: Could not convert the Node because it is invalid: ") + errNode.msg);
			//See http://en.cppreference.com/w/cpp/error/runtime_error
			throw std::runtime_error(std::string("YAML ERROR: Could not convert the Node because it is invalid: ") + errNode.msg);
		}
		catch (BadConversion &badNode)
		{
			LOGASSERT(false, std::string("YAML ERROR: Could not convert the Node because it is of wrong type: ") + errNode.msg);
			throw std::runtime_error(std::string("YAML ERROR: Could not convert the Node because it is of wrong type: ") + errNode.msg);
		}
	}
}
