#pragma once
#include "MySingleton_gen.h"

class CMySingleton
{
public:
	CMySingleton(const std::string& path)
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
		: m_singleton_0(NULL)
	{
	}
	void InitForTest();
	bool operator==(const CMyClass& rhs) const
	{
		return m_singleton_0 == rhs.m_singleton_0
			;
	}

public:
	NIF_F()
	CMySingleton* m_singleton_0;
};

class CMyFactory
{
public:
	CMySingleton* FindOrAddSingleton(const std::string& pathOfSingleton);

	std::map<std::string, std::shared_ptr<CMySingleton> > m_mapNameToSingleton;
};

extern CMyFactory g_factory;