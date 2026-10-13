/*
 * function: GPOWER_Init
 * address:  0x02010DB4
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021461E8  0x021461E8  data
 *   GPOWER_ClearAll  0x02010DF4  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *
 * Zeroes the 0x60-byte array and reinitialises it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GPOWER_Init.c \
 *       --func GPOWER_Init --addr 0x02010DB4 --thumb --cc 1.1p1
 * blocker:  unresolved relocation(s): 02010DF4 (thumb, from name)*/

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 g_021461E8[];

extern void MI_CpuFill8(void *dst, u32 v, u32 size);
extern void GPOWER_ClearAll(void);

void GPOWER_Init(void)
{
    MI_CpuFill8(g_021461E8, 0, 0x60);
    GPOWER_ClearAll();
}
