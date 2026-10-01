/*
 * function: func_021C8DD4
 * address:  0x021C8DD4
 * packet:   pkt_ov021_021C8DD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C8BD8  0x021C8BD8  thumb  ov021
 *   func_021C8D18  0x021C8D18  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; void *f14; u32 f18; u32 f1C; u32 f20; u32 f24; } P;
extern u16 func_021C8D18(P *p);
extern void *func_021C8BD8(u16 id);
void func_021C8DD4(P *p)
{
    p->f14 = func_021C8BD8(func_021C8D18(p));
}
