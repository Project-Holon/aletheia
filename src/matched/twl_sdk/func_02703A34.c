/*
 * function: NWMi_SetCallbackTable
 * address:  0x02703A34
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm twl a2
 */

typedef unsigned int u32;

extern u32 NWMi_GetSystemWork(void);

void NWMi_SetCallbackTable(u32 a0, u32 a1) {
    u32 base = NWMi_GetSystemWork();
    *(u32 *)(base + (a0 << 2) + 0x2284) = a1;
}
