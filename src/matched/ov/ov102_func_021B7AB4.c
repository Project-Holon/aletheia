/*
 * function: func_021B7AB4
 * address: 0x021B7AB4
 * packet: pkt_ov102_021B7AB4
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * declaration: 0204ABF0 forwards the live result of int-returning 0204AC18; 0204B294 forwards the pointer result of 0204CFDC. Its fifth word is copied unchanged as 0204CFDC's request pointer.
 * symbols:
 * MI_CpuFill8 0x02082BCC arm
 * CLACT_InitSystem 0x0204A48C arm
 * CLACT_CreateUnit 0x0204B100 arm
 * CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 * BG_SYS_SetMainPlaneVisible 0x020434DC arm
 * BG_SYS_SetSubPlaneVisible 0x02043598 arm
 * func_020490F4 0x020490F4 arm
 * CLACT_RegisterPalette 0x0204ABF0 arm
 * CLACT_RegisterCharacter 0x0204A6C8 arm
 * CLACT_RegisterCellAnim 0x0204AF28 arm
 * ARC_TOOL_DeleteHandle 0x02049238 arm
 * CLACT_CreateActor 0x0204B294 arm
 * CLACT_SetActorDrawEnable 0x0204B3DC arm
 * CLACT_SetActorBgPriority 0x0204B84C arm
 * CLACT_SetActorAutoAnim 0x0204B92C arm
 * gClActorInitParam 0x020A1448 data a4
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern char gClActorInitParam[];
extern void MI_CpuFill8(void *,int,u32);
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
typedef unsigned char  u8;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void BG_SYS_SetMainPlaneVisible(u32,u32),BG_SYS_SetSubPlaneVisible(u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern int CLACT_RegisterPalette(void *,u32,u32,u32,u16);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);
extern void ARC_TOOL_DeleteHandle(void *);
struct Obj;
extern struct Obj *CLACT_CreateActor(void *,u32,u32,u32,const void *,u16,u16);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int),CLACT_SetActorBgPriority(void *,u32),CLACT_SetActorAutoAnim(struct Obj *,u32);
struct State { void *bank; u32 palette, chars, other; void *actors[32]; };
void func_021B7AB4(struct State *p,const void *config,u16 heap)
{
    void *arc;
    int i;
    u16 point[4];
    MI_CpuFill8(p,0,0x90);
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam,(u32)config,heap);
    p->bank=CLACT_CreateUnit(128,0,heap);
    CLACT_SetUnitDefaultRenderer(p->bank);
    BG_SYS_SetMainPlaneVisible(16,1);
    BG_SYS_SetSubPlaneVisible(16,1);
    arc=func_020490F4(94,heap);
    p->palette=CLACT_RegisterPalette(arc,12,1,0,heap);
    p->chars=CLACT_RegisterCharacter(arc,11,0,1,heap);
    p->other=CLACT_RegisterCellAnim(arc,10,9,heap);
    ARC_TOOL_DeleteHandle(arc);
    MI_CpuFill8(point,0,8);
    for(i=0;i<30;i++) {
        p->actors[i]=CLACT_CreateActor(p->bank,p->chars,p->palette,p->other,point,1,heap);
        CLACT_SetActorDrawEnable(p->actors[i],0);
        CLACT_SetActorBgPriority(p->actors[i],3);
        CLACT_SetActorAutoAnim(p->actors[i],1);
    }
    point[0]=129; point[1]=104; point[2]=15;
    p->actors[31]=CLACT_CreateActor(p->bank,p->chars,p->palette,p->other,point,1,heap);
    CLACT_SetActorDrawEnable(p->actors[31],1);
    CLACT_SetActorBgPriority(p->actors[31],2);
    CLACT_SetActorAutoAnim(p->actors[31],0);
}
