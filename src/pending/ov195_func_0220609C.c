/*
 * function: func_0220609C
 * address:  0x0220609C
 * packet:   pkt_0220609C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_02014B08 0x02014B08 thumb
 *   func_02016020 0x02016020 thumb
 *   func_02015BF0 0x02015BF0 thumb
 *
 * Blocker: 0x02016020 (arm9, Thumb leaf `str r1,[r0,#0x30]; bx lr`, no lr save)
 * has no func_ label and no witness outside this range; every concrete byte
 * is right. Seed 0x02016020 into function_starts (witness site 0x022060AE) or
 * match it as an arm9 leaf, then this file is EXACT.
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02014B08(int, u16);
extern void func_02016020(u32, u32);
extern void func_02015BF0(u32);

void func_0220609C(char *a)
{
    *(u32 *)(a + 0x4c) = func_02014B08(2, *(u16 *)a);
    func_02016020(*(u32 *)(a + 0x4c), 0x30000);
    func_02015BF0(*(u32 *)(a + 0x4c));
}
