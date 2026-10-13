/*
 * function: func_02183F6C
 * address:  0x02183F6C
 * packet:   pkt_02183F6C
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_InitSystem  0x0204A48C  arm
 *   func_020434DC  0x020434DC  arm
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm
 *   gClActorInitParam     0x020A1448  data  a4
 *   d_021848D4     0x021848D4  data  ov168  a4
 */
typedef unsigned int u32;
typedef unsigned short u16;

struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

void func_02183F6C(int unused, u32 b)
{
    CLACT_InitSystem((void *)0x020A1448, (u32)((void *)0x021848D4), (u16)b);
    func_020434DC(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}
