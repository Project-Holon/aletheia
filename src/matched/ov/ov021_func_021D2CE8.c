/*
 * function: func_021D2CE8
 * address:  0x021D2CE8
 * packet:   pkt_ov021_021D2CE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The 0x0C-random-plus-0x5A path returns through its own temporary (an
 * else arm with a local); a direct `return f() + 0x5a` merges into v. The
 * loop index reuses the second parameter's register: v is copied out and the
 * parameter becomes the index, which gives the image's r1/r2/r3 colouring
 * (a fresh int index rotates them by one).
 *
 * symbols:
 *   d_021DD718     0x021DD718  data  a4
 *   func_020056EC  0x020056EC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200C234  0x0200C234  thumb
 *   func_02012EBC  0x02012EBC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02012EBC(void *p);
extern void *func_0200C0F0(void *p);
extern int func_0200C234(void *p);
extern u32 func_020056EC(u32 v);
extern u32 d_021DD718[];

u32 func_021D2CE8(void *a, int i)
{
    u32 v = i;
    void *h = func_0200C0F0(func_02012EBC(a));

    for (i = 0; i < 8; i++) {
        if (v == d_021DD718[i]) {
            if (func_0200C234(h)) {
                return v;
            } else {
                u32 r = func_020056EC(0xc);
                return r + 0x5a;
            }
        }
    }
    return v;
}
