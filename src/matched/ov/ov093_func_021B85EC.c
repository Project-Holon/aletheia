/*
 * function: func_021B85EC
 * address:  0x021B85EC
 * packet:   pkt_ov093_021B85EC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov231_id       0x000000E7  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021809D8  0x021809D8  thumb  ov231
 *   func_021BA1A8  0x021BA1A8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 ov231_id[];
extern int func_02034AC4(int id);
extern void func_02034A5C(int id);
extern int func_021809D8(void);
extern int func_021BA1A8(u32 **p, int k);

int func_021B85EC(u32 **p)
{
    int r;
    if (**p <= 1) {
        func_02034AC4((int)ov231_id);
        r = func_021809D8();
        func_02034A5C((int)ov231_id);
        if (r == 0) {
            return 0;
        }
        if (func_021BA1A8(p, 0x200) == 0) {
            return 1;
        }
    }
    return 0;
}
