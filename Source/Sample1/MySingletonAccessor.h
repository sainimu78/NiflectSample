#pragma once
#include "Niflect/NiflectAccessor.h"

using namespace RwTree;

class CMySingletonAccessor : public Niflect::CAccessor
{
protected:
	virtual bool SaveInstanceImpl(const AddrType base, CRwNode* rw) const;
	virtual bool LoadInstanceImpl(AddrType base, const CRwNode* rw) const;
};