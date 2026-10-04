/*
 * function: func_021DB7E8
 * address:  0x021DB7E8
 * packet:   pkt_ov093_021DB7E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021DB7E8(void *a, void *p, int id)
{
    u16 t;
    u8 *r;

    if (id == func_021D775C(4)) {
        t = func_021D775C(0x12);
        if (t == 0x10f || t == 0x19f) {
            if (func_021D76BC(0x40, 1) != 0) {
                r = (u8 *)func_021C88A4(p, 4, id);
                *(u32 *)r |= 0x800000;
                func_021C8838(r + 4, 2, 0xd2);
                func_021C8860((struct S *)(r + 4), id);
                func_021C88C8(p, r);
            }
        }
    }
}
