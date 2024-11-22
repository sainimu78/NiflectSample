#pragma once
#include "MyClass_gen.h"

class CMyResource
{
public:
	CMyResource(const std::string& path)
		: m_path(path)
	{
	}
	std::string m_path;
};

class CMyFactory
{
public:
	CMyResource* FindOrAddResource(const std::string& pathOfResource)
	{
		auto ret = m_mapNameToResource.insert({ pathOfResource, NULL });
		if (ret.second)
			ret.first->second = std::make_shared<CMyResource>(pathOfResource);
		return ret.first->second.get();
	}

	std::map<std::string, std::shared_ptr<CMyResource> > m_mapNameToResource;
};

extern CMyFactory g_factory;

NIF_T()
class CMyClass
{
	GENERATED_BODY()
public:
	CMyClass()
		: m_resource_0(NULL)
	{
	}
	void InitForTest()
	{
		m_resource_0 = g_factory.FindOrAddResource("/Dir/Image.bmp");
	}
	bool operator==(const CMyClass& rhs) const
	{
		return m_resource_0 == rhs.m_resource_0
			;
	}

public:
	NIF_F()
	CMyResource* m_resource_0;
};