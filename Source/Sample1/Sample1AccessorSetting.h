#pragma once
#include "Niflect/CommonlyUsed/DefaultAccessorSetting.h"
#include "MyResourceAccessor.h"
#include "MyClass.h"

namespace DefaultAccessorSetting
{
	using namespace NiflectAccessorSetting;

	NIF_AS_A() TSetting<CMyResourceAccessor, CMyResource*>;
}