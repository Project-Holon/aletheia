/*
 * function: func_021EF988
 * address:  0x021EF988
 * packet:   pkt_ov093_021EF988
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EF83C  0x021EF83C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 v; } Slot;

typedef struct {
    u32 pad00[2];       /* 0x000 */
    u32 t[8];           /* 0x008 */
    Slot c[8];          /* 0x028 */
    u32 z48[8];         /* 0x048 */
    u32 w[8][6];        /* 0x068 */
    u32 z128[8];        /* 0x128 */
    u32 used[8];        /* 0x148 */
} S;

extern void func_021EF83C(S *a, u32 i);

void func_021EF988(S *p, u32 v)
{
    u32 i;

    for (i = 0; i < 8; i++)
        func_021EF83C(p, i);
    p->pad00[0] = v;
    p->pad00[1] = 0xff;
}
