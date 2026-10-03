/*
 * function: func_021E5C18
 * address:  0x021E5C18
 * packet:   pkt_ov093_021E5C18
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C8168  0x021C8168  thumb  ov093
 *   func_021C815C  0x021C815C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021C8168(void *p);
extern int func_021C815C(void *p);
struct Unk021D62A8;
extern int func_021D76BC(int key, u32 val);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);

void func_021E5C18(u8 *p, void *a, int b)
{
    void *r;
    if (func_021C8168(a) != 0 || func_021C815C(a) != 0)
        func_021D76BC(0x22, 0x1a);
    r = func_021C7CF4(a, b);
    if (func_021D62C4(r, 8) != 0 && func_021D62C4(r, 0x16) != 0)
        func_021D76BC(0x22, 0x1a);
}
