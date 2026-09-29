/*
 * function: func_021E0944
 * address:  0x021E0944
 * packet:   pkt_ov093_021E0944
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_021C7CF4(void *p, int k);
extern int func_021D7B74(void *a0, u32 a1);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);

void func_021E0944(int unused, void *q, int id)
{
    u8 *r;
    int n;

    n = func_021D7B74(func_021C7CF4(q, id), 2);
    r = (u8 *)func_021C88A4(q, 7, id);
    r[6] = id;
    *(u16 *)(r + 4) = n;
    func_021C8838(r + 0xc, 2, 0x386);
    func_021C8860(r + 0xc, id);
    func_021C88C8(q, r);
}
