#include "MySingleton.h"

void CMyClass::InitForTest()
{
	m_singleton_0 = g_factory.FindOrAddSingleton("/Dir/Asset.bin");
}

CMySingleton* CMyFactory::FindOrAddSingleton(const std::string& pathOfSingleton)
{
	auto ret = m_mapNameToSingleton.insert({ pathOfSingleton, NULL });
	if (ret.second)
		ret.first->second = Niflect::MakeShared<CMySingleton>(pathOfSingleton);
	return ret.first->second.Get();
}

CMyFactory g_factory;