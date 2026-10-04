/*
 * function: func_021C8AAC
 * address:  0x021C8AAC
 * packet:   pkt_ov021_021C8AAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021AB0D4  0x021AB0D4  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;
typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; void *f10; } P;
struct VecFx32;
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern u32 func_02188C98(u32 a);
extern u32 func_021AB0D4(u32 a, V *v);
extern u16 func_021AB0F0(u32 a);
u16 func_021C8AAC(P *p)
{
    V t;
    func_021A3038((unsigned char *)p->f8, (struct VecFx32 *)&t);
    return func_021AB0F0(func_021AB0D4(func_02188C98(p->f4), &t));
}
