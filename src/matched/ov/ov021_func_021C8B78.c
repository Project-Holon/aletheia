/*
 * function: func_021C8B78
 * address:  0x021C8B78
 * packet:   pkt_ov021_021C8B78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D550  0x0216D550  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_021C8A8C  0x021C8A8C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; } P;
extern void func_0216D550(u32 *p, u32 v);
extern u32 func_021C8A8C(P *p);
extern void func_0216D5E0(int a0, int a1);
void func_021C8B78(P *p)
{
    func_0216D550((u32 *)p->fC, 8);
    if (p->f10 != 0)
        func_0216D5E0(p->fC, func_021C8A8C(p));
}
