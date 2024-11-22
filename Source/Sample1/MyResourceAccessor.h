#pragma once
#include "Niflect/NiflectAccessor.h"
#include "MyClass.h"

using namespace RwTree;

class CMyResourceAccessor : public Niflect::CAccessor
{
	using MyPtr = CMyResource*;
protected:
	virtual bool SaveInstanceImpl(const AddrType base, CRwNode* rw) const
	{
		const auto& instance = *static_cast<const MyPtr*>(base);
		AddRwString(rw, "Path", instance->m_path.c_str());
		return true;
	}
	virtual bool LoadInstanceImpl(AddrType base, const CRwNode* rw) const
	{
		auto& instance = *static_cast<MyPtr*>(base);
		auto path = FindRwString(rw, "Path");
		instance = g_factory.FindOrAddResource(path.c_str());
		return true;
	}
};