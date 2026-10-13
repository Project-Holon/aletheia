/*
 * function: NWMi_CheckEnableFlag
 * address:  0x027026B4
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087DC4  0x02087DC4  arm twl a2
 *   func_02087E84  0x02087E84  arm twl a2
 */

typedef unsigned int u32;

extern u32 func_02087DC4(void);
extern u32 func_02087E84(void);

u32 NWMi_CheckEnableFlag(void) {
    if (func_02087DC4() == 1) {
        if (func_02087E84() == 0) {
            return 1;
        }
    }
    return 0;
}
