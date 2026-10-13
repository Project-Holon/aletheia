/*
 * function: STARTMENU_SaveEraseEnd
 * address:  0x021BCD64
 * packet:   pkt_ov088_021BCD64
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   PROCSYS_ReplaceGlobal  0x020312F8  arm
 *   d_021BD574     0x021BD574  data  a4
 *   ov088_id       0x00000058  data  a1
 */

struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
typedef unsigned int   u32;
extern void PROCSYS_ReplaceGlobal(u32 a1, u32 a2, u32 a3);
extern char d_021BD574[];
extern char ov088_id[];

int STARTMENU_SaveEraseEnd(int a0)
{
    func_020315D4((struct S020315D4 *)a0);
    func_020306F0(0x81);
    PROCSYS_ReplaceGlobal((u32)ov088_id, (u32)d_021BD574, 0);
    return 1;
}
