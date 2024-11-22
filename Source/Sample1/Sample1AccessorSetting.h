#pragma once
#include "Niflect/CommonlyUsed/DefaultAccessorSetting.h"
#include "MySingletonAccessor.h"
#include "MySingleton.h"

namespace DefaultAccessorSetting
{
	using namespace NiflectAccessorSetting;

	NIF_AS_A() TSetting<CMySingletonAccessor, CMySingleton*>;
}