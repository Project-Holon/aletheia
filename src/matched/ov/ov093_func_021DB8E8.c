/*
 * function: func_021DB8E8
 * address:  0x021DB8E8
 * packet:   pkt_ov093_021DB8E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021DB8E8(void *a, void *p, int id)
{
    u8 *r;

    if (id == func_021D775C(2)) {
        func_021C88B4(p, 2, id);
        r = (u8 *)func_021C88A4(p, 4, id);
        func_021C8838(r + 4, 2, 0x1e7);
        func_021C8860((struct S *)(r + 4), id);
        func_021C88C8(p, r);
        func_021C88B4(p, 3, id);
    }
}
