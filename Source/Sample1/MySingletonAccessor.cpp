#include "MySingletonAccessor.h"
#include "MySingleton.h"

using MyPtr = CMySingleton*;

bool CMySingletonAccessor::SaveInstanceImpl(const AddrType base, CRwNode* rw) const
{
	const auto& instance = *static_cast<const MyPtr*>(base);
	AddRwString(rw, "Path", instance->m_path.c_str());
	return true;
}
bool CMySingletonAccessor::LoadInstanceImpl(AddrType base, const CRwNode* rw) const
{
	auto& instance = *static_cast<MyPtr*>(base);
	auto path = FindRwString(rw, "Path");
	instance = g_factory.FindOrAddSingleton(path.c_str());
	return true;
}