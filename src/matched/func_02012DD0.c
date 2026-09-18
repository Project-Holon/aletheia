/*
 * function: func_02012DD0
 * address:  0x02012DD0
 * packet:   pkt_02012DD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012DD0.c \
 *       --func func_02012DD0 --addr 0x02012DD0 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern int  func_02005C64(void);
extern int  func_02007168(u32 h);
extern void func_020351A0(int mode);
extern void func_02010444(void);

int func_02012DD0(u8 *p)
{
    int r;

    if (func_02005C64() == 1) {
        return 0;
    }
    r = func_02007168(*(u32 *)p);
    if ((u32)(r - 2) <= 1) {
        func_020351A0(2);
        func_02010444();
        *(u8 *)(p + 0x1ce) = 0;
    }
    return r;
}
