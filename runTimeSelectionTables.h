#ifndef RUN_TIME_SELECTION_H
#define RUN_TIME_SELECTION_H

#include <string>
#include <map>

// declareRTST(
// 	autoPtr, 
// 	classBase,  // baseType
// 	Word, 		// argName
// 	(const word& classDerivedTypeName),  //argList
// 	(classDerivedTypeName)	// parList
// )
#define declareRTStable(baseType, argList, parList)				\
	/* construct function pointer */				\
	typedef baseType* (*constructorPtr)argList;	\
	/* construct function table */					\
	typedef map<string, constructorPtr> constructorTable;		\
	/* construct function pointer table pointer */			\
	static constructorTable* constructorTablePtr_;			\
	static void constructConstructorTables(); \
	static void destroyConstructorTable();\
	\
	/* Class to add constructor to table */ \
	template<typename baseTypeType>\
	class addWordConstructorToTable\
	{ \
	public: \
		/* define a function -- New */ \
		static baseTypeType* New argList \
		{ return (baseTypeType*)(new baseTypeType(typeName)); }\
										\
		/* constructor */ \
		addWordConstructorToTable( \
				const string& lookup = baseTypeType::typeName_\
				)\
		{\
			constructorConstructorTables(); \
			if(!constructorTablePtr_->insert(lookup, New) \
			{ cout << "Duplicate entry: " << lookup << endl;\
				exit(1);} \
		}\
		/*~addConstructorToTable(){}*/ \
	};
	/* add removable constructor to table */	
/*	class addRemovableConstructorToTable	*/	
	

//Constructor aid 
#define defineRunTimeSelectionTableConstructor(baseType, argNames) 

// Create pinter to hash-table of functions
#define defineRunTimeSelectionTablePtr(baseType, argNames)


// Define run-time selection table
#define defineRunTimeSelectionTable(baseType, argNames)\
	baseType::constructorTable* baseType::constructorTablePtr_ = null;\
	void baseType::constructConstructorTables()\
{\
			
			static bool constructed = false; \
			if (!constructed) \
			{\
				constructed = true;	\
				baseType::constructorTablePtr = 	\
				new baseType::constructorTable; 	\
			}\

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

