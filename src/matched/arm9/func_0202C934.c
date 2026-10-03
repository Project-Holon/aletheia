/*
 * function: func_0202C934
 * address:  0x0202C934
 * packet:   pkt_0202C860
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_020111E8  0x020111E8  thumb
 */
typedef unsigned int u32;
typedef int s32;

extern u32 func_0201296C(u32 a);
extern s32 func_020142E8(u32 a, u32 b);
extern u32 func_020111E8(void);

s32 func_0202C934(void *a0, u32 a1, u32 a2)
{
    u32 r = func_0201296C(a1);

    if (a2 == 0x151) {
        if (func_020142E8(r, 0x96f) != 0) {
            if (func_020111E8() == 0x15) return 7;
            return 6;
        }
    }
    return 0xffff;
}
