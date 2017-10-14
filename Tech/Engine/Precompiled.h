///////////////////////////////////////////////////////////////////////////////////////
/// All content (c) 2017 The Other Game Engine, all rights reserved
/// FILE: Precompiled.h
/// DATE: 2017-10-14 / 2017-10-15
/// AUTHOR(S): Aditya Subramanian <adu101992@gmail.com>
///////////////////////////////////////////////////////////////////////////////////////

#pragma once

//Standard Template Libraries
#include <algorithm>
#include <chrono>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <string>
#include <list>
#include <map>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

//Libraries included
//SOIL headers
#include "SOIL.h"

//ImGui headers
#include "imgui.h"

//YAML headers
#include "yaml-cpp\yaml.h"
/*TODO: YAML-Helpers.h*/

//GLM headers
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/quaternion.hpp"

//FMOD headers
#include "fmod.hpp"
#include "fmod_errors.h"
#define GLEW_STATIC
#include "glew.h"

//GLFW headers
#define GLFW_EXPOSE_NATIVE_WIN32
#define GLFW_EXPOSE_NATIVE_WGL
#include "glfw3.h"
#include "glfw3native.h"

//assimp headers
#include "Importer.hpp"
#include "scene.h"
#include "postprocess.h"
