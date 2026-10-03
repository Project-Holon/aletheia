/*
 * function: func_021E3648
 * address:  0x021E3648
 * packet:   pkt_ov093_021E3648
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7040  0x021D7040  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(void *l, u32 v);
extern void func_021C88C8(void *a, void *b);
struct Node;
extern void func_021D7040(struct Node *n);

void func_021E3648(void *u, void *p, int key, int *o)
{
    u8 *q;
    if (key == func_021D775C(2) && *o != 0) {
        q = func_021C88A4(p, 4, key);
        func_021C8838(q + 4, 2, 754);
        func_021C8860(q + 4, key);
        func_021C8860(q + 4, func_021D775C(3));
        func_021C88C8(p, q);
        func_021D7040(u);
    }
}
