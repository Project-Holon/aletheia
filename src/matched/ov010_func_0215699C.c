/*
 * function: func_0215699C
 * address:  0x0215699C
 * packet:   pkt_ov010_0215699C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;

typedef struct Work {
    u8 pad00[0x48];
    u8 order[4];        /* 0x48 */
} Work;

u8 func_0215699C(Work *w, u8 i)
{
    return w->order[i];
}
