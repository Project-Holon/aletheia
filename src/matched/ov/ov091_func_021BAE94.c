/*
 * function: func_021BAE94
 * address:  0x021BAE94
 * packet:   pkt_ov091_021BAE94
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9A84  0x021B9A84  thumb  ov091
 *   func_021BB554  0x021BB554  thumb  ov091
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0202D01C  0x0202D01C  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043AF4  0x02043AF4  arm
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021B9A84(u8 *a);
extern u8 func_021BB554(u8 *s);
extern int func_02017E1C(int obj, int key, int off);
extern int func_0202D01C(u16 a, int b, int c);
extern u32 func_02045770(u32 p);
extern void func_02043AF4(u32 a, int b, int c, int d, int e, int f);
extern void func_0204B3DC(int a, int b);

void func_021BAE94(u8 *a, u8 *s)
{
    u8 r;
    int x;
    int y;
    int h;
    u32 w;

    if (func_021B9A84(a) != 0)
        return;
    if (*(int *)(*(u8 **)(a + 0x280) + 0x34) == 6)
        return;
    r = func_021BB554(s);
    h = func_0202D01C(*(u16 *)(s + 6), func_02017E1C(*(int *)s, 0xa1, 0), 0x30);
    w = func_02045770(*(u32 *)(s + 0x20));
    if (r == 2 || r == 3) {
        x = 0xe;
        y = 0xf;
    } else if (r == 1) {
        x = 0xc;
        y = 0xd;
    } else {
        x = 0xa;
        y = 0xb;
    }
    func_02043AF4(w, 0x3d, 0x1b, h, 1, x);
    func_02043AF4(w, 0x3d, 0x1c, h, 1, y);
    func_0204B3DC(*(int *)(s + 0x38), 1);
}
