/*
 * function: func_021B7A88
 * address: 0x021B7A88
 * packet: pkt_ov105_021B7A88
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: later pos2 declaration reproduces its lower stack slot.
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   gClActorInitParam 0x020A1448 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void MI_CpuFill8(void *,int,int);
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
typedef unsigned int   u32;
struct Bank;
struct Node;
struct Obj;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void *CLACT_RegisterPalette(void *,int,int,int,int);
extern void *CLACT_RegisterCharacter(void *,int,int,int,int);
typedef signed int     s32;
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern void *CLACT_CreateActor(void *,void *,void *,void *,void *,int,int);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorBgPriority(void *,int);
extern void CLACT_SetActorDrawPriority(struct Node *node, u32 val);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern const u8 gClActorInitParam[];
void func_021B7A88(void **p,const void *config,int heap)
{
    u16 pos[4],pos2[4];
    void *archive;
    int i;
    MI_CpuFill8(p,0,0xa8);
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam,(unsigned int)config,heap);
    p[0]=CLACT_CreateUnit(128,0,heap);
    CLACT_SetUnitDefaultRenderer(p[0]);
    BG_SYS_SetMainPlaneVisible(16,1); BG_SYS_SetSubPlaneVisible(16,1);
    archive=func_020490F4(0x5e,heap);
    p[1]=CLACT_RegisterPalette(archive,12,0,0,heap);
    p[2]=CLACT_RegisterCharacter(archive,11,0,0,heap);
    p[3]=(void *)CLACT_RegisterCellAnim(archive,10,9,heap);
    ARC_TOOL_DeleteHandle(archive);
    MI_CpuFill8(pos,0,8);
    for(i=0;i<3;++i) p[4+i]=CLACT_CreateActor(p[0],p[2],p[1],p[3],pos,0,heap);
    MI_CpuFill8(pos2,0,8);
    pos2[0]=128; pos2[1]=96;
    p[41]=CLACT_CreateActor(p[0],p[2],p[1],p[3],pos2,0,heap);
    CLACT_SetActorDrawEnable(p[41],0); CLACT_SetActorBgPriority(p[41],0); CLACT_SetActorDrawPriority(p[41],0);
    CLACT_SetActorAutoAnim(p[41],1); CLACT_SetActorAnimSeq(p[41],11);
    for(i=0;i<3;++i) {
        CLACT_SetActorDrawEnable(p[4+i],0); CLACT_SetActorBgPriority(p[4+i],0); CLACT_SetActorDrawPriority(p[4+i],0);
    }
}
