/*
 * function: func_02072EC8
 * address:  0x02072EC8
 * packet:   pkt_02072EA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * blocker:  +0014 ABS32 g_0214E46C             -> unresolved: 0214E46C (data, from header) has no witness outside 02072EC8..02072EE0
 *
 * symbols:
 *   g_0214E46C       0x0214E46C  data
 *
 * Reads the leading halfword of record `idx` at the same stride.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02072EC8.c \
 *       --func func_02072EC8 --addr 0x02072EC8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

extern u8 g_0214E46C[];

u16 func_02072EC8(u32 idx)
{
    return *(u16 *)(g_0214E46C + idx * 0x24);
}
