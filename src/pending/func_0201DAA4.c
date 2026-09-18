/*
 * function: func_0201DAA4
 * address:  0x0201DAA4
 * packet:   pkt_0201DA24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201DAA4.c \
 *       --func func_0201DAA4 --addr 0x0201DAA4 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern void func_0201DBF4(void);
extern void func_0201DE40(void);
extern void func_0201E538(void);
extern void func_0201E738(void);
extern void func_0201E928(void);

void func_0201DAA4(void *p, u32 a1, u32 a2)
{
    *(u32 *)((u8 *)p + 0xc) = 0;
    *(void **)((u8 *)p + 4) = func_0201DBF4;
    if (a1 == 1) {
        *(void **)((u8 *)p + 8) = (a2 == 1) ? func_0201DE40 : func_0201E538;
    } else {
        *(void **)((u8 *)p + 8) = (a2 == 1) ? func_0201E738 : func_0201E928;
    }
}
