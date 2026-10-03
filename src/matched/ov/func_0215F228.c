/*
 * function: func_0215F228
 * address:  0x0215F228
 * packet:   pkt_0215F228
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020121CC  0x020121CC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
struct IcaAnime;
extern u32 func_020121CC(struct IcaAnime *p);

int func_0215F228(int a0, int a1)
{
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215F230:
    a0 = func_020121CC(v0);
loc_0215F234:
a0 = 1;
    return a0;}
