/*
 * function: func_021E2B18
 * address:  0x021E2B18
 * packet:   pkt_ov093_021E2B18
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
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021E8860  0x021E8860  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D6D7C(int x);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021E8860(int n);

void func_021E2B18(int u, void *p, int k)
{
    void *q;
    if (k == func_021D775C(3)) {
        q = func_021C7CF4(p, (u8)func_021D775C(4));
        if (func_021D6D7C((int)q) == 0) {
            if (func_021D62C4(q, 2) != 0)
                func_021E8860(2);
        }
    }
}
