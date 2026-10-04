/*
 * function: func_021BB400
 * address: 0x021BB400
 * packet: pkt_ov225_021BB400
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 86 compiled bytes followed by two zero alignment bytes at 021BB456.
 * symbols:
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020499D4 0x020499D4 arm
 *   func_021BB458 0x021BB458 thumb ov225
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_020499D4(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_021BB458(char *);
void func_021BB400(char *p)
{
    func_02049B68((void *)(*(unsigned *)(*(char **)(p + 4) + 0x24)), 0, 4, 0, 64, *(u16 *)(*(char **)(p + 4) + 4));
    func_02049658((void *)(*(unsigned *)(*(char **)(p + 4) + 0x24)), 2, 4, 0, 0, 0, *(u16 *)(*(char **)(p + 4) + 4));
    func_020499D4((void *)(*(unsigned *)(*(char **)(p + 4) + 0x24)), 4, 4, 0, 0, 0, 0, *(u16 *)(*(char **)(p + 4) + 4));
    func_021BB458(p);
}
