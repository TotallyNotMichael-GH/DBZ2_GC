#define OS_MODULE_LIST_ADDR  0x800030C8
#define OS_STRING_TABLE_ADDR 0x800030D0
#define OS_BASE_CACHED       0x80003000

/**
 * @note Address: 0x800EF4A4
 * @note Size: 0x18
 */
struct OSModuleQueue { /* Relocatable Module Queue @ 800030c8 */
	int* pFirst;
	int* pLast;
};

struct OSModuleQueue __OSModuleInfoList : (OS_BASE_CACHED | OS_MODULE_LIST_ADDR);
const void* __OSStringTable : (OS_BASE_CACHED | OS_STRING_TABLE_ADDR);

/**
 * @note Address: 0x801F979C
 * @note Size: 0x18
 */
void __OSModuleInit(void)
{
	__OSModuleInfoList.pLast  = 0;
	__OSModuleInfoList.pFirst = 0;
	__OSStringTable           = 0;
}