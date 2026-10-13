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
 *   GPOWER_GetSpecialPowerId  0x020111E8  thumb
 */
typedef unsigned int u32;
typedef int s32;

struct BigObj;
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern u32 GPOWER_GetSpecialPowerId(void);

s32 func_0202C934(void *a0, u32 a1, u32 a2)
{
    u32 r = func_0201296C((const struct BigObj *)a1);

    if (a2 == 0x151) {
        if (func_020142E8((void *)r, 0x96f) != 0) {
            if (GPOWER_GetSpecialPowerId() == 0x15) return 7;
            return 6;
        }
    }
    return 0xffff;
}
