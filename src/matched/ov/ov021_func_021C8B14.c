/*
 * function: func_021C8B14
 * address:  0x021C8B14
 * packet:   pkt_ov021_021C8B14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02006148  0x02006148  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_02006224  0x02006224  thumb
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_021C8A7C  0x021C8A7C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; } P;
extern u32 func_021C8A7C(P *p);
extern void func_0216D410(u32 a, u32 b);
extern void func_0216D548(u32 a, u32 b);
extern int func_02006148(u32 a0);
extern int func_02006224(u32 a0);
extern void func_020061E4(u32 id);
void func_021C8B14(P *p)
{
    func_0216D410(p->fC, func_021C8A7C(p));
    func_0216D548(p->fC, 8);
    if (func_02006224(func_02006148(0x694)) == 0)
        func_020061E4(0x694);
}
