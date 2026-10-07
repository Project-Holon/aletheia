/*
 * function: func_021E5E7C
 * address:  0x021E5E7C
 * packet:   pkt_ov093_021E5E7C
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

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern int func_021D76BC(int key, u32 val);

void func_021E5E7C(int a, void *b, int c)
{
    void *r;

    if (c == func_021D775C(2)) {
        r = func_021C7CF4(b, c);
        if (func_021D62C4(r, 0x15) != 0 || func_021D62C4(r, 0x1f) != 0)
            func_021D76BC(0x22, 0x1a);
    }
}
