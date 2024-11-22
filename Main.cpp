#include "MyClass.h"
#include "MyApp/ModuleReg/MyApp_private.h"
#include "Niflect/NiflectTable.h"
#include "Niflect/Serialization/JsonFormat.h"

int main()
{
	using namespace Niflect;

	CNiflectTable table;

	{
		Niflect::GeneratedInitialReg(&table);
		table.InitTypesLayout();
	}

	CRwNode rw;

	{
		CMyClass srcData;
		srcData.InitForTest();
		
		{
			// Save the 'srcData' instance to the 'rw' node
			auto type = StaticGetType<CMyClass>();
			type->SaveInstanceToRwNode(&srcData, &rw);
		}

		TSharedPtr<void*> dummy;
		{
			auto type = StaticGetType<CMyClass>();
			// Create CMyClass dummy instance from reflected type info.
			dummy = type->MakeSharedInstance<void*>();
			// Load the dummy instance from the 'rw' node
			type->LoadInstanceFromRwNode(dummy.Get(), &rw);
		}
		
		// Copy the loaded dummy instance to 'dstData'
		CMyClass dstData = *reinterpret_cast<CMyClass*>(dummy.Get());
		// Assert that the saving and laoding were successful
		ASSERT(srcData == dstData);
	}

	// Serialize 'rw' to JSON format and then print the result
	CStringStream ss;
	CJsonFormat::Write(&rw, ss);
	printf("%s\n", ss.str().c_str());

	return 0;
}