/*
 * function: func_021EF9F4
 * address:  0x021EF9F4
 * packet:   pkt_ov093_021EF9F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Eight-slot table object: six u32[8] arrays and a u32[8][6] block, all
 * indexed by the slot b.  Written as struct member arrays, the load of
 * used[b] keeps b*4 in its own register while the c/z48/z128 stores
 * recompute a + b*4 (the raw `*(u32 *)(a + K + b * 4)` casts CSE'd b*4 and
 * swapped b and b*4: docs/notes/pkt_ov093_021EF9F4.c.txt).  The third
 * parameter is a one-word struct passed by value (push {r0-r3} frame).
 *
 * symbols:
 *   func_021EFA84  0x021EFA84  thumb  ov093
 *   func_021E8A98  0x021E8A98  thumb  ov093
 *   func_021EFAD8  0x021EFAD8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_021EFA84(u32 a, int b);
typedef struct { u32 v; } Slot;
extern u32 func_021E8A98(Slot a);
extern int func_021EFAD8(char *p, u32 i, u32 v);

typedef struct {
    u32 pad00[2];       /* 0x000 */
    u32 t[8];           /* 0x008 */
    u32 c[8];           /* 0x028 */
    u32 z48[8];         /* 0x048 */
    u32 w[8][6];        /* 0x068 */
    u32 z128[8];        /* 0x128 */
    u32 used[8];        /* 0x148 */
} S;

int func_021EF9F4(S *a, u32 b, Slot c, int d)
{
    u32 i;
    u32 x;

    if (a->used[b] == 0) {
        if (d != 0) {
            a->t[b] = func_021EFA84(b, 0);
            if (a->t[b] == 0)
                return 0;
        }
        a->used[b] = 1;
        a->c[b] = c.v;
        a->z48[b] = 0;
        a->z128[b] = 0;
        for (i = 0; i < 6; i++)
            a->w[b][i] = 0x1f;
        x = func_021E8A98(c);
        if (x != 0x1f)
            func_021EFAD8((char *)a, b, x);
        return 1;
    }
    return 0;
}
