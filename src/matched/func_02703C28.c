/*
 * function: func_02703C28
 * address:  0x02703C28
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02FFDFFC  0x02FFDFFC  data twl a2
 *   func_02004632  0x02004632  code twl a2
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 data_02FFDFFC[];
extern u16 func_02004632(u32, u32, u32);

u32 func_02703C28(void) {
    u32 *r4 = (u32 *)*data_02FFDFFC;
    u16 crc = func_02004632(0xFFFF, (u32)r4 + 0x1e4, 0xc);
    u32 target = r4[0x1e0/4] >> 16;
    if (crc == target) {
        return 1;
    }
    return 0;
}
