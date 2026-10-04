/*
 * function: func_021E3BBC
 * address:  0x021E3BBC
 * packet:   pkt_ov093_021E3BBC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7040  0x021D7040  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern u8 *func_021C88A4(int a, int k, int b);
extern void func_021C88C8(void *a, void *b);
struct Node;
extern void func_021D7040(struct Node *n);

void func_021E3BBC(void *u, int a, int b)
{
    u8 *s;

    if (b == func_021D775C(2)) {
        s = func_021C88A4(a, 0x26, b);
        s[4] = b;
        s[5] = 3;
        s[6] = 0;
        func_021C88C8((void *)a, s);
        func_021D7040(u);
    }
}
