/*
 * unit:     yes
 * function: func_021C7F44, func_021C7F60
 * address:  0x021C7F44
 * packet:   pkt_ov021_021C7F44
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_021C7EF0  0x021C7EF0  thumb  ov021
 *   func_021C7EF8  0x021C7EF8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M;
extern u32 func_020307B0(void *p);
extern void func_021C7EF0(u8 *p, u32 v);
extern u8 *func_021C7EF8(u8 *p, u8 v);
void func_021C7F60(M *m);
void func_021C7F44(M *m)
{
    m->f1C = 3;
    func_021C7EF0(m->sub, 0xaa00);
    func_021C7EF8(m->sub, 0x1f);
}

void func_021C7F60(M *m)
{
    m->f1C = 0;
    func_021C7EF0(m->sub, 0);
}
