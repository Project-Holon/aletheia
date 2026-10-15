/*
 * function: Wf2dmapFriend_InitActors
 * address: 0x021C67A8
 * packet: pkt_ov128_021C67A8
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * calls: Heap parameters are widened where the original supplies no truncation.
 * symbols:
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   CLACT_CreateRenderer 0x0204B034 arm
 *   CLACT_SetUnitRenderer 0x0204B258 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   func_020490F4 0x020490F4 arm
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   gClActorInitParam 0x020A1448 data a4
 *   d_021CA5CC 0x021CA5CC data a4
 *   d_021CA7D0 0x021CA7D0 data a4
 */
#include "../include/Obj01936.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {u32 a,b;u8 c,d,e,f;u32 g;u16 h[6];} Config;
extern const Config gClActorInitParam;
extern u8 d_021CA5CC[],d_021CA7D0[];
struct Cfg;
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
struct Bank;
struct Obj;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern struct Obj *CLACT_CreateRenderer(u8 *a0, u32 a1, u32 heap);
extern void CLACT_SetUnitRenderer(struct Bank *bank, void *p);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u32);
extern int CLACT_RegisterPalette(void *,u32,u32,u32,u32);
extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);
extern u32 APP_ICON_GetArchiveId(void);
extern void *func_020490F4(u32,u32);
extern u32 APP_ICON_GetMoveKindAnimFileId(void);
extern u32 APP_ICON_GetMoveKindPaletteFileId(void);
extern u32 APP_ICON_GetStatusCellFileId(u32);
extern u32 APP_ICON_GetStatusPaletteFileId(u32);
extern void ARC_TOOL_DeleteHandle(void *);
void Wf2dmapFriend_InitActors(char *p,int heap)
{
    Config config=gClActorInitParam;
    void *bank,*archive;
    u32 first,second;
    config.c=16;
    config.d=112;
    CLACT_InitSystem((const struct Cfg *)(&config),(u32)d_021CA5CC,heap);
    bank=CLACT_CreateUnit(32,0,heap);
    ((struct Obj01936 *)p)->f138=bank;
    CLACT_SetUnitDefaultRenderer(bank);
    ((struct Obj01936 *)p)->f140=CLACT_CreateRenderer(d_021CA7D0,1,heap);
    bank=CLACT_CreateUnit(18,1,heap);
    ((struct Obj01936 *)p)->f13C=bank;
    CLACT_SetUnitRenderer(bank,((struct Obj01936 *)p)->f140);
    ((struct Obj01936 *)p)->f144=CLACT_RegisterCharacter(((struct Obj01936 *)p)->f8,4,0,0,heap);
    ((struct Obj01936 *)p)->f14C=CLACT_RegisterPalette(((struct Obj01936 *)p)->f8,1,0,0,heap);
    ((struct Obj01936 *)p)->f154=CLACT_RegisterCellAnim(((struct Obj01936 *)p)->f8,15,16,heap);
    archive=func_020490F4(APP_ICON_GetArchiveId(),heap);
    ((struct Obj01936 *)p)->f148=CLACT_RegisterCharacter(archive,APP_ICON_GetMoveKindAnimFileId(),0,0,heap);
    ((struct Obj01936 *)p)->f150=CLACT_RegisterPalette(archive,APP_ICON_GetMoveKindPaletteFileId(),0,96,heap);
    first=APP_ICON_GetStatusCellFileId(2);
    second=APP_ICON_GetStatusPaletteFileId(2);
    ((struct Obj01936 *)p)->f158=CLACT_RegisterCellAnim(archive,first,second,heap);
    ARC_TOOL_DeleteHandle(archive);
}
