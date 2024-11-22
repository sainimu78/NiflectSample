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

NIF_T()
class CMyClass
{
	GENERATED_BODY()
public:
	CMyClass()
		: m_resource_0(NULL)
	{
	}
	void InitForTest();
	bool operator==(const CMyClass& rhs) const
	{
		return m_resource_0 == rhs.m_resource_0
			;
	}

public:
	NIF_F()
	CMyResource* m_resource_0;
};

class CMyFactory
{
public:
	CMyResource* FindOrAddResource(const std::string& pathOfResource);

	std::map<std::string, std::shared_ptr<CMyResource> > m_mapNameToResource;
};

extern CMyFactory g_factory;