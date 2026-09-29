/*
 * function: func_021BBD10
 * address:  0x021BBD10
 * packet:   pkt_ov088_021BBD10
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020452E8  0x020452E8  arm
 *   func_021BBB84  0x021BBB84  thumb  ov088
 *   func_02041570  0x02041570  arm
 *   func_02041EE4  0x02041EE4  arm
 *   func_021BB9DC  0x021BB9DC  thumb  ov088
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_020452E8(void *);
extern void func_021BBB84(int, int, int, int, u8);
extern void func_02041570(u32 layer, u32 a1);
extern void func_02041EE4(u32, u32, u32);
extern void func_021BB9DC(char *, int);

void func_021BBD10(char *p, int mode)
{
    func_020452E8(*(void **)(p + 0xf0));
    if (mode != 1) {
        func_021BBB84(0x20, 1, 0x20, 0x16, 2);
        func_02041570(0, 0);
        func_02041EE4(1, 0, 0);
        func_02041EE4(1, 3, *(u32 *)(p + 0x130));
        func_02041EE4(2, 0, 0);
        func_02041EE4(2, 3, *(u32 *)(p + 0x130));
        if (*(u8 *)(p + 0x120) == 0)
            func_021BB9DC(p, 1);
    }
}
