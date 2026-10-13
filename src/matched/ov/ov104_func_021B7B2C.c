/*
 * function: func_021B7B2C
 * address: 0x021B7B2C
 * packet: pkt_ov104_021B7B2C
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: ABF0 forwards AC18's index; B294 forwards CFDC's pointer live in r0.
 * symbols:
 *   gClActorInitParam 0x020A1448 data
 *   func_02082BCC 0x02082BCC arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   func_020434DC 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   func_020490F4 0x020490F4 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   func_0204B92C 0x0204B92C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   func_0204B6F4 0x0204B6F4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cfg;
struct Bank;
struct Obj;
typedef struct { char pad[0x60]; u32 f60; } S;
extern const struct Cfg gClActorInitParam;
extern void func_02082BCC(void *,int,int);
extern void CLACT_InitSystem(const struct Cfg *,u32,u32);
extern struct Bank *CLACT_CreateUnit(int,u8,u32);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *);
extern void func_020434DC(u32,u32);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern signed int CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
typedef signed int     s32;
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void ARC_TOOL_DeleteHandle(void *);
extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,unsigned short,unsigned short);
extern void func_0204B3DC(struct Obj *,u32);
extern void CLACT_SetActorBgPriority(S *,u32);
extern void func_0204B92C(struct Obj *,u32);
extern void CLACT_SetActorAnimSeq(struct Obj *,u16);
extern void func_0204B6F4(struct Obj *,u32,u32);
typedef struct { u16 x,y,z,w; } Desc;
void func_021B7B2C(u32 *p,const void *config,u16 heap) {
 void *archive; int i; Desc desc;
 func_02082BCC(p,0,0xb4);
 CLACT_InitSystem(&gClActorInitParam,(u32)config,heap);
 p[0]=(u32)CLACT_CreateUnit(0x80,0,heap);
 CLACT_SetUnitDefaultRenderer((struct Bank *)p[0]);
 func_020434DC(0x10,1);
 BG_SYS_SetSubPlaneVisible(0x10,1);
 archive=func_020490F4(0x5e,heap);
 p[1]=CLACT_RegisterPalette((void *)archive,0x23,0,0,heap);
 p[2]=CLACT_RegisterCharacter((void *)((u32)archive),0x22,0,0,heap);
 p[3]=CLACT_RegisterCellAnim((void *)((u32)archive),0x21,0x20,heap);
 p[7]=CLACT_RegisterPaletteEx((void *)((u32)archive),0xc,0,0xe0,0xc,1,heap);
 p[8]=CLACT_RegisterCharacter((void *)((u32)archive),0xb,0,0,heap);
 p[9]=CLACT_RegisterCellAnim((void *)((u32)archive),0xa,9,heap);
 p[4]=CLACT_RegisterPalette((void *)archive,0x23,1,0,heap);
 p[5]=CLACT_RegisterCharacter((void *)((u32)archive),0x22,0,1,heap);
 p[6]=CLACT_RegisterCellAnim((void *)((u32)archive),0x21,0x20,heap);
 ARC_TOOL_DeleteHandle(archive);
 func_02082BCC(&desc,0,8);
 for(i=0;i<30;i++) {
  p[i+10]=(u32)CLACT_CreateActor((void *)p[0],p[2],p[1],p[3],&desc,0,heap);
  func_0204B3DC((struct Obj *)p[i+10],0);
  CLACT_SetActorBgPriority((S *)p[i+10],3);
  func_0204B92C((struct Obj *)p[i+10],1);
  CLACT_SetActorAnimSeq((struct Obj *)p[i+10],0);
 }
 desc.x=128; desc.y=96;
 for(i=31;i<34;i++) {
  desc.z=i-30;
  p[i+10]=(u32)CLACT_CreateActor((void *)p[0],p[8],p[7],p[9],&desc,0,heap);
  func_0204B3DC((struct Obj *)p[i+10],0);
  func_0204B6F4((struct Obj *)p[i+10],0,1);
 }
}
