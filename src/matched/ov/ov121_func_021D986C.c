/*
 * function: MYSTERY_GRAPHIC_InitClact
 * address: 0x021D986C
 * packet: pkt_ov121_021D986C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_CreateRenderer 0x0204B034 arm
 *   CLACT_SetUnitRenderer 0x0204B258 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021DF5A8 0x021DF5A8 data a4
 *   d_021DF5C4 0x021DF5C4 data a4
 */
typedef unsigned int u32;
extern void MI_CpuFill8(void *, int, u32);
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
typedef unsigned char  u8;
struct Bank;
struct Obj;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct Obj *CLACT_CreateRenderer(u8 *a0, u32 a1, u32 heap);
extern void CLACT_SetUnitRenderer(struct Bank *bank, void *p);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern const u32 d_021DF5A8[];
extern const u32 d_021DF5C4[];
void MYSTERY_GRAPHIC_InitClact(void **p, u32 a, u32 heap)
{
    void *q;
    MI_CpuFill8(p, 0, 8);
    CLACT_InitSystem((const struct Cfg *)d_021DF5A8, a, heap);
    p[0] = CLACT_CreateUnit(128, 0, heap);
    q = CLACT_CreateRenderer((unsigned char *)d_021DF5C4, 2, heap);
    p[1] = q;
    CLACT_SetUnitRenderer(p[0], q);
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
}
