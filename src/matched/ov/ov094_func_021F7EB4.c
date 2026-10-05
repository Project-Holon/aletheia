/*
 * function: func_021F7EB4
 * address:  0x021F7EB4
 * packet:   pkt_ov094_021F7EB4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094  a4
 */
typedef unsigned int u32;
typedef struct { char pad[0x1E8]; u32 w; u32 a : 8; u32 b : 8; u32 c : 2; u32 d : 14; } Obj;

extern Obj *d_0220AF20;

int func_021F7EB4(void)
{
    Obj *p = d_0220AF20;
    u32 t = p->w | p->a | p->b | p->c;

    if (t != 0)
        return 1;
    return 0;
}
