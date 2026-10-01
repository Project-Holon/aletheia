/*
 * function: func_021C7E30
 * address:  0x021C7E30
 * packet:   pkt_ov021_021C7E30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_021C7EEC  0x021C7EEC  thumb  ov021
 *   func_021C7EF4  0x021C7EF4  thumb  ov021
 *   func_021C8078  0x021C8078  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0; u8 sub[0x18]; u16 f1C; u16 f1E; } M;
extern void func_020307B0(void *p);
extern u32 func_021C7EEC(void *p);
extern u32 func_021C7EF4(void *p);
extern void func_021C8078(u32 h, u32 a, u32 b);
void func_021C7E30(M *m)
{
    u32 a;
    if (m != 0) {
        a = func_021C7EEC(m->sub);
        func_021C8078(m->f0, a, func_021C7EF4(m->sub));
    }
}
