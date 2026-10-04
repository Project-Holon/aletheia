/*
 * function: func_021F199C
 * address:  0x021F199C
 * packet:   pkt_ov032_021F199C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F199C 0x021F199C thumb
 *   func_02165EBC 0x02165EBC thumb ov010
 *   func_02165D20 0x02165D20 thumb ov010
 *   sub_02010EA0  0x02010EA0 thumb
 *   func_02165FCC 0x02165FCC thumb ov010
 *   func_0201F250 0x0201F250 thumb
 *   func_021F1A28 0x021F1A28 thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Rec;
extern u16 func_02165EBC(struct Rec *r);
extern u8 func_02165D20(struct Rec *r);
extern u8 sub_02010EA0(int slot, u8 *rec);
extern void func_02165FCC(void *r, u32 win, u32 heap);
struct WordSet;
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021F1A28(char *p, int a, int b, char *c);

int func_021F199C(char *p, void *x, int flag)
{
    int r;

    if (flag)
        r = func_02165EBC(x);
    else
        r = func_02165D20(x);
    if (r == 0x30 || r > 0x2d)
        return 0;
    if (r == sub_02010EA0(r, *(u8 **)(p + 0x24)))
        return 0;
    func_02165FCC(x, *(u32 *)(p + 0x110), *(u16 *)(p + 0x96));
    func_0201F250((struct WordSet *)(*(u32 *)(p + 0x110)), (void *)(*(u32 *)(p + 0x11c)), (void *)(*(u32 *)(p + 0x118)));
    func_021F1A28(p, r, 1, p + 0xa8);
    return 1;
}
