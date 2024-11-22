#include "MyClass.h"

void CMyClass::InitForTest()
{
	m_resource_0 = g_factory.FindOrAddResource("/Dir/Image.bmp");
}

CMyResource* CMyFactory::FindOrAddResource(const std::string& pathOfSingleton)
{
	auto ret = m_mapNameToResource.insert({ pathOfSingleton, NULL });
	if (ret.second)
		ret.first->second = std::make_shared<CMyResource>(pathOfSingleton);
	return ret.first->second.get();
}

CMyFactory g_factory;