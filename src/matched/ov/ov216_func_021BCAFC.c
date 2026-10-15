/*
 * function: BEACON_DETAIL_GRA_InitClact
 * address: 0x021BCAFC
 * packet: pkt_ov216_021BCAFC
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_CreateRenderer 0x0204B034 arm
 *   CLACT_SetRendererCulling 0x0204B0F4 arm
 *   CLACT_SetUnitRenderer 0x0204B258 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021BDBBC 0x021BDBBC data a4
 *   d_021BDC08 0x021BDC08 data a4
 */
struct Block { unsigned w[8]; };
extern const unsigned d_021BDBBC[];
extern const struct Block d_021BDC08;
extern void MI_CpuFill8(void *,int,int);
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
struct Obj;
extern struct Obj *CLACT_CreateRenderer(u8 *a0, u32 a1, u32 heap);
struct Actor;
extern void CLACT_SetRendererCulling(struct Actor *a0, int a1);
extern void CLACT_SetUnitRenderer(struct Bank *bank, void *p);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
void BEACON_DETAIL_GRA_InitClact(void **p,void *a,int heap)
{
    struct Block b;
    MI_CpuFill8(p,0,8);
    CLACT_InitSystem((const struct Cfg *)d_021BDBBC,(unsigned int)a,heap);
    p[0]=CLACT_CreateUnit(128,0,heap);
    b=d_021BDC08;
    p[1]=CLACT_CreateRenderer((u8 *)(&b),2,heap);
    CLACT_SetRendererCulling(p[1],1);
    CLACT_SetUnitRenderer(p[0],p[1]);
    BG_SYS_SetMainPlaneVisible(16,1);
    BG_SYS_SetSubPlaneVisible(16,1);
}
