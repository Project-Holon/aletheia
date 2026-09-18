/*
 * function: func_02012E7C
 * address:  0x02012E7C
 * packet:   pkt_02012E4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02012E7C.c \
 *       --func func_02012E7C --addr 0x02012E7C --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern int  func_02005C64(void);
extern int  func_020073B0(u32 h, void *a);
extern void func_020351A0(int mode);
extern void func_02010444(void);
extern void func_02034FB8(int v);

int func_02012E7C(u8 *p, void *a)
{
    int r;

    if (func_02005C64() == 1) {
        return 0;
    }
    r = func_020073B0(*(u32 *)p, a);
    if ((u32)(r - 2) <= 1) {
        func_020351A0(2);
        func_02010444();
        *(u8 *)(p + 0x1ce) = 0;
        func_02034FB8(0x80);
    }
    return r;
}
