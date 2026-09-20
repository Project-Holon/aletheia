/*
 * function: func_02010DB4
 * address:  0x02010DB4
 * packet:   pkt_0201058C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 *
 * symbols:
 *   g_021461E8  0x021461E8  data
 *
 * Zeroes the 0x60-byte array and reinitialises it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010DB4.c \
 *       --func func_02010DB4 --addr 0x02010DB4 --thumb --cc 1.1p1
 * blocker:  unresolved relocation(s): 02010DF4 (thumb, from name)*/

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 g_021461E8[];

extern void func_02082BCC(void *dst, u32 v, u32 size);
extern void func_02010DF4(void);

void func_02010DB4(void)
{
    func_02082BCC(g_021461E8, 0, 0x60);
    func_02010DF4();
}
