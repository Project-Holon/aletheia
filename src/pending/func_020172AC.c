/*
 * function: func_020172AC
 * address:  0x020172AC
 * packet:   pkt_02017270
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020172AC.c \
 *       --func func_020172AC --addr 0x020172AC --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;
typedef signed int s32;

extern void func_02014CF0(u32 a, void *f, u32 b);
extern void func_020172BC(void);

void func_020172AC(u32 a0, u32 a1)
{
    func_02014CF0(a0, func_020172BC, a1);
}
