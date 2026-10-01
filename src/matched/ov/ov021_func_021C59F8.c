/*
 * function: func_021C59F8
 * address:  0x021C59F8
 * packet:   pkt_ov021_021C59F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Sets the y offset of the three sprite handles (EXACT*: pad). The split i =
 * 0; y = v; ordering is what schedules the zero before the sign extension.
 */

typedef unsigned char u8;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    s16 x;
    s16 y;
} P2;

typedef struct {
    u8 pad[0x28];
    u32 h[3];
} S;

extern void func_0204B454(u32 h, P2 *p, u32 c);
extern void func_0204B404(u32 h, P2 *p, u32 c);

void func_021C59F8(S *p, int v)
{
    s16 y;
    int i;
    P2 t;

    i = 0;
    y = v;
    for (; i < 3; i++) {
        func_0204B454(p->h[i], &t, 0);
        t.y = y;
        func_0204B404(p->h[i], &t, 0);
    }
}
