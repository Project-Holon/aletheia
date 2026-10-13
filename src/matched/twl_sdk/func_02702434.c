/*
 * function: NWM_Init
 * address:  0x02702434
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NWMi_CheckEnableFlag  0x027026B4  arm twl a2
 *   NWMi_InitCore  0x02702468  arm twl a2
 */

typedef unsigned int u32;

extern u32 NWMi_CheckEnableFlag(void);
extern u32 NWMi_InitCore(u32, u32, u32);

u32 NWM_Init(u32 a0, u32 a1, u32 a2) {
    if (NWMi_CheckEnableFlag() == 0) {
        return 4;
    }
    return NWMi_InitCore(a0, a1, a2);
}
