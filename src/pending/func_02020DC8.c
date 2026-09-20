/*
 * function: func_02020DC8
 * address:  0x02020DC8
 * packet:   pkt_02020D5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocker:  +0020 ABS32 sub_0209E8CC_Obj       : 0209E8CC (data, from header) has no witness outside 02020DC8..02020DEC
 * symbols:
 *   sub_0209E8CC_Obj  0x0209E8CC  data
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;

extern void *func_020436FC(int a0, int a1, int a2, int a3, u16 a4);
extern u8 sub_0209E8CC_Obj[];

void func_02020DC8(char *p, int a)
{
    *(u32 *)(p + 8) = (u32)func_020436FC((int)sub_0209E8CC_Obj, 1, 1, 0x20, a);
}
