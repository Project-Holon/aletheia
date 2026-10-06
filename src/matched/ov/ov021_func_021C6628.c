/*
 * function: func_021C6628
 * address:  0x021C6628
 * packet:   pkt_ov021_021C6628
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C6A90  0x021C6A90  thumb  ov021
 */


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0x2c]; } Item;
typedef struct { u32 k:2; u32 rest:30; u16 f4; u8 pad[0x62]; } Elem;
typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; Item *f8; Elem *fC; } Mgr;
extern void func_021C6A90(u32 *p, u8 *q);
void func_021C6628(Mgr *m, int idx)
{
    Elem *e;
    e = &m->fC[idx];
    m->f2 = 0;
    if (e->k == 1)
        func_021C6A90((u32 *)e, (u8 *)(&m->f8[e->f4]));
    m->f2 = 1;
}
