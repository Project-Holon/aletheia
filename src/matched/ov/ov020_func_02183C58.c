/*
 * function: func_02183C58
 * address:  0x02183C58
 * packet:   pkt_ov020_02183C58
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020127C4  0x020127C4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_021860D4  0x021860D4  thumb  ov020
 *   func_02161D64  0x02161D64  thumb  ov010
 *   func_020127F0  0x020127F0  thumb
 *   func_02161F14  0x02161F14  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned char  u8;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern int func_020127C4(int a);
extern u8 *func_02012944(void *p);
extern void func_021860D4(u16 *p, int a1, int id);
extern void func_02161D64(int a);
extern int func_020127F0(int a);
extern void func_02161F14(u16 *out, u8 *in, int c);

void func_02183C58(int a)
{
    int w = (int)func_020120F4((const struct Ctx *)a);
    int r5 = func_020127C4(w);

    func_021860D4((u16 *)r5, (int)func_02012944((void *)w), 1);
    func_02161D64(func_020127C4(w));
    r5 = func_020127F0(w);
    func_02161F14((u16 *)r5, (u8 *)func_020127C4(w), 1);
}
