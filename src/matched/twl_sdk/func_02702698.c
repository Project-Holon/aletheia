/*
 * function: NWMi_CheckInitialized
 * address:  0x02702698
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_027341A0  0x027341A0  data twl a2
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 data_027341A0[];

u32 NWMi_CheckInitialized(void) {
    if (data_027341A0[0] != 0) {
        return 0;
    }
    return 3;
}
