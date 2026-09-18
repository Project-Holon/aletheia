/*
 * function: func_0202C268
 * address:  0x0202C268
 * packet:   pkt_0202C268
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef int           s32;

extern s32 func_0202C240(void *p);
extern u32 func_0202C244(void *p, u8 i);
extern u32 func_0202C340(u32 v);

u32 func_0202C268(void *p, u32 v)
{
    s32 n = func_0202C240(p);
    s32 i;

    for (i = 0; i < n; i++) {
        u32 r = func_0202C244(p, (u8)i);

        if (v == func_0202C340(r)) {
            return r;
        }
    }
    return 0;
}
