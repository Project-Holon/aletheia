/*
 * file:     unit_02072D98.c
 * unit:     yes
 * function: func_02072D98, func_02072DB0
 * address:  0x02072D98
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0214E484       0x0214E484  data
 *   g_0214DEC0      0x0214DEC0  data
 *   g_0214E47C      0x0214E47C  data
 *   g_0214E480      0x0214E480  data
 */
typedef unsigned int u32;

typedef unsigned char u8;

void func_02072D98(u32 idx, u32 val);
void func_02072DB0(int idx, int v);
extern u8 g_0214E484[];
extern char g_0214E47C[];


/*
 * Byte field of record `idx` in the stride-0x24 table.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02072D98.c \
 *       --func func_02072D98 --addr 0x02072D98 --cc 1.1p1 --arm
 */
void func_02072D98(u32 idx, u32 val)
{
    g_0214E484[idx * 0x24] = val;
}

void func_02072DB0(int idx, int v)
{
    *(int *)(g_0214E47C + idx * 0x24) = (unsigned short)v;
}
