/*
 * function: func_02012E08
 * address:  0x02012E08
 * packet:   pkt_02012DD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02012E08.c \
 *       --func func_02012E08 --addr 0x02012E08 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern void func_020351A0(int mode);
extern void func_02010444(void);
extern void func_020071A8(u32 h);
extern int  func_02034FE8(int v);
extern void func_02034FB8(int v);

void func_02012E08(u8 *p)
{
    if (*(u8 *)(p + 0x1ce) == 1) {
        func_020351A0(2);
        func_02010444();
        *(u8 *)(p + 0x1ce) = 0;
        func_020071A8(*(u32 *)p);
        if (func_02034FE8(0x80) == 1) {
            func_02034FB8(0x80);
        }
    }
}

