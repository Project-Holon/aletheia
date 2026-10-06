/*
 * function: func_021DFB4C
 * address:  0x021DFB4C
 * packet:   pkt_ov093_021DFB4C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021EF948  0x021EF948  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern int func_021D775C(int key);
extern int func_021EF948(int k);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);

void func_021DFB4C(void *self, void *q, int id)
{
    u8 *r;

    if (id != func_021D775C(2))
        return;
    if (func_021EF948(2) != 0)
        return;
    r = (u8 *)func_021C88A4(q, 4, id);
    func_021C8838(r + 4, 2, 0x198);
    func_021C8860((struct S *)(r + 4), id);
    func_021C88C8(q, r);
}
