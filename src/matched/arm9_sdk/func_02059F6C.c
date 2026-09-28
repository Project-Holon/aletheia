/*
 * function: func_02059F6C
 * address:  0x02059F6C
 * packet:   pkt_02059F6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_InitForProduction (libdwccommon.TWL.HYB.a dwc_init.o)
 *
 * symbols:
 *   func_02004EB0        0x02004EB0 arm
 *   DWCi_Init            0x02059FA8 arm
 *   id_string_production 0x02005050 data
 */

typedef unsigned long u32;

typedef void *(*DWCAllocEx)(int name, u32 size, int align);
typedef void (*DWCFreeEx)(int name, void *ptr, u32 size);

#define DWC_AUTHSERVER_PRODUCTION 1

extern void func_02004EB0(const void *symbol);  /* OSi_ReferSymbol */
extern int  DWCi_Init(int authserver, const char *gameName, u32 gameCode, DWCAllocEx alloc, DWCFreeEx free);
extern char id_string_production[68];

int func_02059F6C(const char *gameName, u32 gameCode, DWCAllocEx alloc, DWCFreeEx free)
{
    func_02004EB0(id_string_production);
    return DWCi_Init(DWC_AUTHSERVER_PRODUCTION, gameName, gameCode, alloc, free);
}
