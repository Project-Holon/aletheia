/*
 * function: func_02072EC8
 * address:  0x02072EC8
 * packet:   pkt_02072EA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  +0014 ABS32 g_0214E46C             -> unresolved: 0214E46C (data,
 * from header) has no witness outside 02072EC8..02072EE0.  The `literal` class
 * finds no pool word outside the compared range and the address is a record
 * table, not a string or a data table by the rules' tests: permanent.
 *
 * Reads the leading halfword of record `idx` at the same stride.
 *
 * symbols:
 *   g_0214E46C       0x0214E46C  data
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

extern u8 g_0214E46C[];

u16 func_02072EC8(u32 idx)
{
    return *(u16 *)(g_0214E46C + idx * 0x24);
}
