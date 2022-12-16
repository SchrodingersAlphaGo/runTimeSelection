#ifndef RUN_TIME_SELECTION_H
#define RUN_TIME_SELECTION_H

#include <string>
#include <map>

#define declareRTStable(baseType, argName)				\
	/* construct function pointer */				\
	typedef baseType* (*constructorPtr)(const string& typeName);	\
	/* construct function table */					\
	typedef map<string, constructorPtr> constructorTable;		\
	/* construct function pointer table pointer */			\
	static constructorTable* constructorTablePtr_;			\
	/* Class to add constructor to table */ \
	template<typename baseType>\
	class addConstructorToTable\
	{ \
	public: \
		/* define a function -- New */ \
		static baseType* New(const string& typeName) \
		{ return (baseType*)(new baseType(typeName)); }\
		\
		/* constructor */ \
		addConstructorToTable( \
				const string& lookup = baseType::typeName_\
				)\
		{\}\
		~addConstructorToTable() \
	};\
	/* add removable constructor to table */	\
	class addRemovableConstructorToTable		\
	{};\

//Constructor aid 
#define defineRunTimeSelectionTableConstructor(baseType, argNames) 

// Create pinter to hash-table of functions
#define defineRunTimeSelectionTablePtr(baseType, argNames)


// Define run-time selection table
#define defineRunTimeSelectionTable(baseType, argNames)

// 










/*
create run-time-selection-table by macro define
*/
// #define declareRunTimeSelectionTable(baseType, argNames)                \
//     /* define function pointer */                                       \
//     typedef baseType* (*argNames##constructorPtr) (const string& tname);    \
//                                                                             \
//     typedef map<string, baseType*> argNames##ConstructorTable;          \
//     static argNames##ConstructorTable* argNames##ConstructorTablePtr_;  \
//                                                                         \
//     static void construct##argNames##ConstructorTables();               \
//     static void destroy##argNames##ConstructorTables();                 \
//                                                                         \
//     template<typename baseType##Type>
//     class add##argNames##ConstructorToTable
//     {
//         public:
//         static: baseType* New 
//     }
                                                                    
                                                                        





#endif // RUN_TIME_SELECTION_H

