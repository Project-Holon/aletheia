/*
 * function: PRINTSYS_PrintStream
 * address:  0x0201CCE4
 * packet:   pkt_0201CA78
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PRINTSYS_PrintStream.c \
 *       --func PRINTSYS_PrintStream --addr 0x0201CCE4 --cc 1.1p1 --thumb
 *
 * symbols:
 *   PRINTSYS_PrintStreamCallBack  0x0201CD10  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern void PRINTSYS_PrintStreamCallBack(u32 a0, u32 a1, u32 a2, u32 a3, u32 a5, u32 a6,
                          u32 a7, u32 a8, u16 a9, u16 a10, u32 a11);

void PRINTSYS_PrintStream(u32 a0, u32 a1, u32 a2, u32 a3, u32 a5, u32 a6, u32 a7,
                   u32 a8, u16 a9, u16 a10)
{
    PRINTSYS_PrintStreamCallBack(a0, a1, a2, a3, a5, a6, a7, a8, a9, a10, 0);
}
