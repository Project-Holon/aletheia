/*
 * function: func_020134F4
 * address:  0x020134F4
 * packet:   pkt_02013360
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020134F4.c \
 *       --func func_020134F4 --addr 0x020134F4 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern void func_020130C4(u8 *p);
extern void func_02013360(u8 *o, void *a1, const void *a2);
extern void func_0201333C(void *p, u32 a, u16 h);

void func_020134F4(u8 *p, u32 a1, u32 a2, u32 a3, u16 h)
{
    func_020130C4(p);
    func_02013360(p, (void *)a1, (const void *)a3);
    func_0201333C(p, a1, h);
    *(u32 *)p = 1;
    *(u32 *)(p + 4) = a2;
    *(u16 *)(p + 0x1a) = 0x47d;
}
