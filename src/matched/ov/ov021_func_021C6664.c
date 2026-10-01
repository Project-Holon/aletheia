/*
 * function: func_021C6664
 * address:  0x021C6664
 * packet:   pkt_ov021_021C6664
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT

 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 a, b, c; } V;
typedef struct { u32 f0; u32 f4; V f8; u8 pad[0x68 - 0x14]; } Elem;
typedef struct { u8 pad[0xc]; Elem *fC; } Mgr;
void func_021C6664(Mgr *m, int idx, V *v)
{
    m->fC[idx].f8 = *v;
}
