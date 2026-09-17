/*
 * function: func_02031994
 * address:  0x02031994
 * packet:   pkt_0203195C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031994.c \\
 *       --func func_02031994 --addr 0x02031994 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_020307B0(void *p);
extern void func_020339B4(u32 v);
extern u32  func_02033B68(u32 v);
extern void func_020339D0(u32 a, u32 b);
extern void func_02033410(u8 *p, u32 v);

u32 func_02031994(u8 *p, u32 *out)
{
    *out = *(u32 *)(p + 0x30);
    return *(u32 *)(p + 0x34);
}
