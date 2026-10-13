/*
 * function: GPOWER_ApplyCaptureRate
 * address:  0x020111BC
 * packet:   pkt_0201104C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_02146208  0x02146208  data
 *   g_02146228  0x02146228  data
 *   _ll_mul     0x0209C054  arm
 *   _ll_sdiv    0x0209BE5C  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_ApplyCaptureRate.c
 *       --func GPOWER_ApplyCaptureRate --addr 0x020111BC --cc 1.1p1
 *
 * Scales v by the rate at +0x16 of the second record (v * rate / 100 in
 * 64 bits) unless the mode byte at +0x1e of the first is 0x30.  The 0x30
 * path has no return statement: the original falls off the end and hands
 * back v, still in r0.  Any written `return v;` makes the compiler join
 * the two paths through a copy (48 bytes); an s64 return type keeps the
 * size but colours the mode load in r3 (r1 is the high half of the
 * result).  See docs/idioms/a-missing-return-hands-back-the-parameter.md.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed int     s32;
typedef signed long long s64;

extern u8 g_02146208[];
extern u8 g_02146228[];

s32 GPOWER_ApplyCaptureRate(s32 v)
{
    if (g_02146208[0x1e] != 0x30) {
        return (s64)*(u16 *)(g_02146228 + 0x16) * v / 100;
    }
}
