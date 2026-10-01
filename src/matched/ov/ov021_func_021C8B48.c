/*
 * function: func_021C8B48
 * address:  0x021C8B48
 * packet:   pkt_ov021_021C8B48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C8984  0x021C8984  thumb  ov021
 *   func_021C8AAC  0x021C8AAC  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; } P;
extern u16 func_021C8AAC(P *p);
extern void *func_021C8984(u16 id);
void func_021C8B48(P *p)
{
    void *e = func_021C8984(func_021C8AAC(p));
    if (e != 0)
        p->f10 = e;
}
