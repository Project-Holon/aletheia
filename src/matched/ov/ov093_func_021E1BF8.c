/*
 * function: func_021E1BF8
 * address:  0x021E1BF8
 * packet:   pkt_ov093_021E1BF8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021D76BC(int key, u32 val);

void func_021E1BF8(int a, void *p, int id)
{
    int two = 2;
    void *q;
    int k;
    if (id == func_021D775C(2)) {
        q = func_021C7CF4(p, id);
        k = 0x22;
        if (func_021D775C(k) == 2) {
            func_021D76BC(k, 0);
            return;
        }
        if (func_021D62C4(q, two) == 0)
            func_021D76BC(k, 0x1a);
    }
}
