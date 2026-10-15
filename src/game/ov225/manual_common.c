/*
 * file:     manual_common.c
 * unit:     yes
 * function: func_021B9B3C, func_021B9BA4, func_021B9BC8, func_021B9BD4, func_021B9BE0, func_021B9BEC, func_021B9BF8, func_021B9C0C, func_021B9C20, func_021B9C28, func_021B9C34, func_021B9C40, func_021B9C50, func_021B9C58, func_021B9C98, func_021B9CB0, func_021B9CC8, func_021B9CDC, func_021B9CE0, func_021B9CF0, func_021B9CFC, func_021B9D0C, func_021B9D18, func_021B9DEC, func_021B9E60, func_021B9E80, func_021B9EE8, func_021B9F20, func_021B9F24, func_021B9F8C, func_021B9FBC, func_021BA068, func_021BA0F0, func_021BA154, func_021BA158, func_021BA15C, func_021BA160, func_021BA1C0, func_021BA1C4, func_021BA218, func_021BA240, func_021BA28C, func_021BA2B0, func_021BA30C, func_021BA368, func_021BA41C, func_021BA4D8, func_021BA508, func_021BA644, func_021BA65C, func_021BA740, func_021BA760, func_021BA894, func_021BA898, func_021BA9D0, func_021BAA44, func_021BAA50, func_021BAA88, func_021BAABC, func_021BAE2C, func_021BAFF8, func_021BB034, func_021BB044, func_021BB05C, func_021BB074, func_021BB088, func_021BB1F4, func_021BB258, func_021BB2B4, func_021BB308, func_021BB31C, func_021BB3FC, func_021BB400, func_021BB458, func_021BB4F8, func_021BB504, func_021BB50C, func_021BB53C
 * address:  0x021B9B3C
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   ARC_UTIL_LoadHandleMemberWithSize 0x0204A39C arm
 *   file_021BBFF4 0x021BBFF4 data ov225 a1
 *   func_020307B0 0x020307B0 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_02009210 0x02009210 thumb
 *   func_020090E0 0x020090E0 thumb
 *   func_0201296C 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   MISC_SAVEDATA_GetBlock44  0x0200ED48  thumb
 *   func_0200EDEC  0x0200EDEC  thumb
 *   func_0200EE14 0x0200EE14 thumb
 *   func_021B9900 0x021B9900 thumb ov225
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromArchive 0x02049B90 arm
 *   d_021BC004 0x021BC004 data ov225 a1
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_021B99A0 0x021B99A0 thumb ov225
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_021B99F4 0x021B99F4 thumb ov225
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   GX_LoadBG2Scr 0x0207EB78 arm
 *   func_02040588 0x02040588 arm
 *   ov067_id 0x00000043 data a1
 *   func_02034AC4 0x02034AC4 arm
 *   d_021BC014 0x021BC014 data a1
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   TOUCHBAR_Delete 0x021B639C thumb ov067
 *   func_02034A5C 0x02034A5C arm
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfPressing 0x021B6470 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   d_021BBF2C 0x021BBF2C data a4
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   d_021BBF4C 0x021BBF4C data a4
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021B9A08 0x021B9A08 thumb ov225
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 *   d_021BBF00 0x021BBF00 data a1
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_020275E4 0x020275E4 thumb
 *   func_02027614 0x02027614 thumb
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   func_02027618 0x02027618 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   d_021BBF14 0x021BBF14 data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   KEY_GetRepeat 0x0203633C arm
 *   func_020355D8 0x020355D8 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   d_021BC028 0x021BC028 data ov225 a1
 *   func_02041EE4 0x02041EE4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandleExt 0x020499D4 arm
 *   d_021BBF8C 0x021BBF8C data ov225 a2
 *   d_021BBF94 0x021BBF94 data ov225 a2
 *   func_020414AC 0x020414AC arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   func_02061CA4 0x02061CA4 arm
 *   func_020355C4 0x020355C4 arm
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   sub_02041B6C 0x02041B6C arm
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   KEY_GetTrg 0x020362DC arm
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   APP_TASKMENU_WIN_ClearScreen 0x0202843C thumb
 *   APP_TASKMENU_WIN_DeleteNoClear 0x0202815C thumb
 *   APP_TASKMENU_WIN_CreateExNoScreen 0x0202804C thumb
 *   APP_TASKMENU_WIN_Create 0x02027FEC thumb
 *   file_021BC038 0x021BC038 data a1
 *   d_021BBF9C 0x021BBF9C data a4
 */
#include "../../matched/include/Obj08466.h"
#include "../../matched/include/Obj26135.h"
#include "../../matched/include/Obj26138.h"
#include "../../matched/include/Obj26140.h"
#include "../../matched/include/Obj26141.h"
#include "../../matched/include/Obj26142.h"
#include "../../matched/include/Obj26143.h"
#include "../../matched/include/Obj01787.h"
#include "../../matched/include/Obj08467.h"
#include "../../matched/include/Obj04650.h"
#include "../../matched/include/Obj06734.h"
#include "../../matched/include/Obj26144.h"
#include "../../matched/include/Obj14802.h"
#include "../../matched/include/Obj00367.h"
#include "../../matched/include/Obj03964.h"
#include "../../matched/include/Obj01788.h"
#include "../../matched/include/Obj26145.h"
#include "../../matched/include/Obj26146.h"
#include "../../matched/include/Obj08468.h"
#include "../../matched/include/Obj26147.h"
#include "../../matched/include/Obj26148.h"
#include "../../matched/include/Obj26149.h"
#include "../../matched/include/Obj26150.h"
#include "../../matched/include/Obj26151.h"
#include "../../matched/include/Obj26152.h"
#include "../../matched/include/Obj08469.h"
#include "../../matched/include/Obj26153.h"
#include "../../matched/include/Obj04652.h"
#include "../../matched/include/Obj26154.h"
#include "../../matched/include/Obj26155.h"
#include "../../matched/include/Obj26156.h"
#include "../../matched/include/Obj26157.h"
#include "../../matched/include/Obj04653.h"
#include "../../matched/include/Obj26158.h"
#include "../../matched/include/Obj26159.h"
#include "../../matched/include/Obj26160.h"
#include "../../matched/include/Obj26161.h"
#include "../../matched/include/Obj02561.h"
#include "../../matched/include/Obj26162.h"
#include "../../matched/include/Obj26163.h"
#include "../../matched/include/Obj26164.h"
#include "../../matched/include/Obj26165.h"
#include "../../matched/include/Obj26166.h"
#include "../../matched/include/Obj26167.h"
#include "../../matched/include/Obj02562.h"
#include "../../matched/include/Obj10983.h"
#include "../../matched/include/Obj14803.h"
#include "../../matched/include/Obj26168.h"
#include "../../matched/include/Obj26169.h"
#include "../../matched/include/Obj26170.h"
#include "../../matched/include/Obj26171.h"
#include "../../matched/include/Obj10984.h"
#include "../../matched/include/Obj26178.h"
#include "../../matched/include/Obj00601.h"
#include "../../matched/include/Obj26179.h"
#include "../../matched/include/Obj26180.h"
#include "../../matched/include/Obj26181.h"
#include "../../matched/include/Obj26182.h"
#include "../../matched/include/Obj26183.h"
#include "../../matched/include/Obj26184.h"
#include "../../matched/include/Obj00074.h"
#include "../../matched/include/Obj14804.h"
#include "../../matched/include/Obj14805.h"
#include "../../matched/include/Obj26185.h"
#include "../../matched/include/Obj26186.h"
#include "../../matched/include/Obj26187.h"
#include "../../matched/include/Obj26188.h"
#include "../../matched/include/Obj26189.h"
#include "../../matched/include/Obj26190.h"
#include "../../matched/include/Obj26191.h"
#include "../../matched/include/Obj26192.h"
#include "../../matched/include/Obj26193.h"
#include "../../matched/include/Obj26194.h"
#include "../../matched/include/Obj26195.h"
#include "../../matched/include/Obj26196.h"
#include "../../matched/include/Obj26197.h"
#include "../../matched/include/Obj26198.h"
#include "../../matched/include/Obj26199.h"
#include "../../matched/include/Obj08470.h"
#include "../../matched/include/Obj14806.h"
#include "../../matched/include/Obj26200.h"
#include "../../matched/include/Obj26201.h"
#include "../../matched/include/Obj26202.h"
#include "../../matched/include/Obj26203.h"
#include "../../matched/include/Obj26204.h"
#include "../../matched/include/Obj26205.h"
#include "../../matched/include/Obj26206.h"
#include "../../matched/include/Obj26207.h"
#include "../../matched/include/Obj26208.h"
#include "../../matched/include/Obj26209.h"
#include "../../matched/include/Obj26210.h"
#include "../../matched/include/Obj26211.h"
#include "../../matched/include/Obj26212.h"
#include "../../matched/include/Obj26213.h"
#include "../../matched/include/Obj26214.h"
#include "../../matched/include/Obj26217.h"
#include "../../matched/include/Obj26218.h"
#include "../../matched/include/Obj26219.h"
#include "../../matched/include/Obj26220.h"
#include "../../matched/include/Obj26221.h"
#include "../../matched/include/Obj26222.h"
#include "../../matched/include/Obj26223.h"
#include "../../matched/include/Obj26224.h"
#include "../../matched/include/Obj26225.h"
#include "../../matched/include/Obj26226.h"
#include "../../matched/include/Obj05574.h"
#include "../../matched/include/Obj26227.h"
#include "../../matched/include/Obj26228.h"
#include "../../matched/include/Obj26229.h"
#include "../../matched/include/Obj26230.h"
#include "../../matched/include/Obj00691.h"
#include "../../matched/include/Obj26231.h"
#include "../../matched/include/Obj26232.h"
#include "../../matched/include/Obj26233.h"
#include "../../matched/include/Obj26234.h"
#include "../../matched/include/Obj26235.h"
#include "../../matched/include/Obj26239.h"
#include "../../matched/include/Obj01596.h"
#include "../../matched/include/Obj26240.h"
#include "../../matched/include/Obj26241.h"
#include "../../matched/include/Obj26242.h"
#include "../../matched/include/Obj26243.h"
#include "../../matched/include/Obj26244.h"
#include "../../matched/include/Obj26245.h"
#include "../../matched/include/Obj26246.h"
#include "../../matched/include/Obj26247.h"
#include "../../matched/include/Obj26248.h"
#include "../../matched/include/Obj26249.h"
#include "../../matched/include/Obj26250.h"
#include "../../matched/include/Obj26251.h"
#include "../../matched/include/Obj14809.h"
#include "../../matched/include/Obj26253.h"
#include "../../matched/include/Obj00740.h"

#define ST (*(struct State_021BA508 **)p)
struct Big;
struct Sub02009210Obj;
struct Sub020090B0Obj;
struct BigObj;
struct GfFont;
struct MsgBank;
struct Rec;
struct PrintSys;
struct Node;
struct Obj;
struct Descriptor;
struct CharBuf;
struct Cfg;
struct U16Vec;
struct WordSet;
struct Actor;
struct R;
struct Work;
struct TaskMenuState;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

struct State_021B9B3C {
    void *owner; u16 heap,pad6; void *screen;
    struct GfFont *font; u32 str10,str14,str18;
    struct MsgBank *bank1,*bank2;
    void *arc1,*arc2,*assets; u16 id,pad32; void *group;
};

typedef struct S S;

struct Entry_021B9B3C {unsigned word[7];};

typedef struct {u8 *f0;u32 f4;int f8;u32 fC,f10,f14;int f18,f1c;} A;

typedef struct {int f0;u32 f4;int f8;u8 sub[0x14];u8 elem[1];} R;

struct Block {u32 words[16];};

struct Entry_021BA1C4 {u8 a,b,c,d,e,f,g,h,i;};

typedef signed int     s32;

typedef short s16;

typedef unsigned int u32_021BA508;

struct Entry { u32_021BA508 first; u16 normal,pad6; u8 left,right,top,bottom; u32_021BA508 active,mask,sound,last; };

typedef signed short s16_021BA65C;

typedef unsigned int u32_021BA65C;

struct Vec2_021BA508
{
  s16_021BA65C x;
  s16_021BA65C y;
};

struct Data
{
  void *owner;
  u16 heap;
  u16 pad6;
  char rest[48];
};

struct Work
{
  char *owner;
  struct Data *data;
  u32_021BA65C field8;
  void *a[8];
  void *b[8];
  u32_021BA65C field4c;
  void *res50;
  void *res54;
  void *res58;
  struct Obj *obj;
  void *arr60[8];
  void *task;
  u32_021BA65C field84;
  u32_021BA65C field88;
  u32_021BA65C field8c;
  signed char field90;
  u8 pad91[3];
  u32_021BA65C field94;
};

typedef unsigned int   u32_021BA740;

typedef unsigned int u32_021BA760;

typedef unsigned u32_021BA898;

struct Quad { short x,y,z,w; };

typedef short s16_021BAA44;

typedef unsigned int u32_021BAA44;

typedef short s16_021BAA50;

typedef unsigned int u32_021BAA50;

typedef short s16_021BAA88;

typedef unsigned int u32_021BAA88;

typedef unsigned u32_021BAABC;

struct State_021BA508 {u16 a,b,count,c;void *data;u16 top,selected;};

struct Vec2_021BAABC {short x,y;};

typedef unsigned u32_021BAE2C;

typedef unsigned int u32_021BAFF8;

typedef unsigned u32_021BB088;

struct Entry_021BB088 {void *resource;u16 tag,pad;u32_021BB088 flags;};

typedef unsigned int   u32_021BB308;

typedef unsigned int   u32_021BB31C;

typedef unsigned int   u32_021BB400;

struct Entry_021BB458 { void *resource; u16 tag; u16 pad; unsigned flags; };

typedef unsigned int   u32_021BB458;

typedef unsigned int u32_021BB4F8;

typedef unsigned int u32_021BB504;

typedef unsigned int u32_021BB50C;

typedef unsigned int   u32_021BB53C;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *ARC_UTIL_LoadHandleMemberWithSize(void *, int, int, u32, u32 *);
extern u32 func_020307B0(void *p);
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern struct Sub02009210Obj *func_02009210(void *);
extern u8 func_020090E0(const struct Sub020090B0Obj *);
extern u32 func_0201296C(const struct BigObj *p);
extern unsigned ZONEDATA_CheckEventFlag(void *,int);
extern void *MISC_SAVEDATA_GetBlock44(void *p);
extern int func_0200EDEC(char *obj, int i);
extern void func_0200EE14(char *obj, int i);
extern void *func_021B9900(u32,u32);
extern struct GfFont *GF_FONT_Create(int,int,int,int,u32);
extern u32 PRINTSYS_QUE_Create(void *);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_UTIL_UploadPaletteFromArchive(u32,u32,u32,u32,u32,u32,u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);
extern unsigned int GF_FONT_Delete(void *ptr);
extern void func_021B99A0(char *);
extern unsigned PRINTSYS_QUE_Main(struct PrintSys *);
extern void func_021B99F4(char *);
extern void DWCi_ScreenDC_FlushRange(const void *,unsigned);
extern void GX_LoadBG2Scr(const void *,unsigned,unsigned);
extern void func_02040588(unsigned char which, unsigned char enable);
extern int func_02034AC4(int);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern void func_02030EAC(struct Node *n);
extern void TOUCHBAR_Delete(unsigned char *);
extern void func_02034A5C(int);
extern void TOUCHBAR_Update(struct S *p);
extern int TOUCHBAR_GetPressedButtonIdIfPressing(u8 *);
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned);
extern void MI_CpuFill8(void *,u8,u32);
extern u32 func_021B9A08(const u8 *p);
extern R *TOUCHBAR_Create(A *,int);
extern unsigned BMP_WIN_Create(unsigned,unsigned,unsigned,unsigned,u8,u8,u8);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *,u8);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void PRINTSYS_QUE_Clear(struct PrintSys *),BMP_WIN_Delete(struct Descriptor *);
extern unsigned PRINTSYS_QUE_IsExistTarget(struct PrintSys *,void *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_02041B6C(unsigned);
extern void *func_02045EC0(struct MsgBank *,unsigned);
extern void PRINTSYS_PrintQueColor(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void STRBUF_Delete(struct U16Vec *);
extern struct WordSet *func_0201EC64(u32);
extern struct U16Vec *STRBUF_Create(u32,u32);
extern void func_0201EFA4(struct WordSet *,u32,u32,u32,u32,u32);
extern void func_0201F250(struct WordSet *,void *,void *);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_020275E4(void);
extern u32 func_02027614(void);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 func_02027618(void);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorAutoAnim(struct Obj *,u32);
extern void CLACT_DeleteActor(struct Obj *);
extern void CLACT_ReleaseCellAnim(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleasePalette(u32);
extern u32_021BA508 CLACT_GetActorDrawEnable(struct Obj *);
extern u32_021BA508 KEY_GetRepeat(void);
extern void func_020355D8(u8);
extern u32_021BA508 TOUCHPANEL_GetPointTrg(u32_021BA508 *,u32_021BA508 *);
extern void CLACT_SetActorAnimSeq(struct Obj *,u16);
extern void GFL_USE_PlaySeDefaultVolume(u32_021BA508);
extern u32_021BA508 CLACT_IsActorAnimActive(struct Actor *);
extern void func_02041EE4(u32_021BA65C, u32_021BA65C, u32_021BA65C);
extern void CLACT_AddActorSurfacePos(struct Obj *, const struct Vec2_021BA508 *, u32_021BA65C);
extern u32_021BA760 PRINTSYS_QUE_IsFinished(const struct PrintSys *);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern u32_021BA760 APP_TASKMENU_WIN_IsFinish(u8 *);
extern void func_02049B68(void *,u32_021BA898,u32_021BA898,u32_021BA898,u32_021BA898,u16);
extern u32_021BA898 func_02049658(void *a, u32_021BA898 b, u32_021BA898 c, u32_021BA898 d, u32_021BA898 e, u32_021BA898 f, u16 g);
extern u32_021BA898 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *,u32_021BA898,u32_021BA898,u32_021BA898,u32_021BA898,u32_021BA898,u32_021BA898,u16);
extern void func_020414AC(unsigned);
extern struct R *APP_TASKMENU_RES_Create(u16, u16, unsigned, unsigned, u16);
extern int func_02061CA4(void *, unsigned, void *, int);
extern u8 func_020355C4(void);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *, unsigned);
extern void sub_02041B6C(u32_021BAA44);
extern void APP_TASKMENU_WIN_Delete(u8 *);
extern u32_021BAA88 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern int TOUCHPANEL_HitTrg(const void *);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern void APP_TASKMENU_WIN_ClearScreen(u8 *);
extern void APP_TASKMENU_WIN_DeleteNoClear(void);
extern u32_021BB088 *APP_TASKMENU_WIN_CreateExNoScreen(u32_021BB088 a0, u32_021BB088 a1, u32_021BB088 a2, u32_021BB088 a3, u8 a4, u8 a5, u32_021BB088 a6, u32_021BB088 a7, u16 a8);
extern u32_021BB088 APP_TASKMENU_WIN_Create(u32_021BB088 a0, u32_021BB088 a1, u32_021BB088 a2, u32_021BB088 a3, u8 a4, u16 a5);
void *func_021B9B3C(void *narc, u32 heap);
void func_021B9BA4(char *p);
u16 func_021B9BC8(char *p,int index);
u16 func_021B9BD4(char *p,int index);
u16 func_021B9BE0(char *p,int index);
u16 func_021B9BEC(char *p,int index);
u16 func_021B9BF8(char *p, int idx, int c);
u16 func_021B9C0C(char *p, int idx, int c);
u16 func_021B9C20(const char *p);
u16 func_021B9C28(char *p,int index);
u16 func_021B9C34(char *p,int index);
u16 func_021B9C40(char *p, int idx, int c);
u16 func_021B9C50(const char *p);
int func_021B9C58(void *unused,int kind,void *save);
int func_021B9C98(void *unused, int b, int c);
void func_021B9CB0(void *unused,int code,struct Big *save);
int func_021B9CC8(unsigned unused,unsigned key);
int func_021B9CDC(void *a0);
int func_021B9CE0(char *p, int idx);
unsigned short func_021B9CF0(char *p,unsigned i);
int func_021B9CFC(char *p, int idx);
unsigned short func_021B9D0C(char *p,unsigned i);
void *func_021B9D18(void *owner,u16 heap);
void func_021B9DEC(char *p);
void func_021B9E60(char *p);
void func_021B9E80(char *p,unsigned id);
void func_021B9EE8(void *a0);
void func_021B9F20(void *a0);
void *func_021B9F24(char *owner);
void func_021B9F8C(char *p);
void func_021B9FBC(char *p);
void func_021BA068(char *p,unsigned state);
void func_021BA0F0(char *p,unsigned b,unsigned c);
unsigned func_021BA154(char *p);
unsigned func_021BA158(char *p);
void func_021BA15C(void *task,void *data);
void func_021BA160(char *p);
void func_021BA1C0(void *a0);
void func_021BA1C4(char *p);
void func_021BA218(char *p);
void func_021BA240(char *p);
void func_021BA28C(char *p);
void func_021BA2B0(char *p);
void func_021BA30C(char *p);
void func_021BA368(char *p);
void func_021BA41C(char *p);
void func_021BA4D8(char *p);
void func_021BA508(char *p);
void func_021BA644(char *p);
void *func_021BA65C(char *owner, struct Data *data);
void func_021BA740(char *p);
int func_021BA760(char *p);
void func_021BA894(void);
void func_021BA898(char *p);
void func_021BA9D0(char *p);
void func_021BAA44(struct Work *a0);
void func_021BAA50(char *p);
void func_021BAA88(char *p);
int func_021BAABC(char *p);
int func_021BAE2C(char *p);
void func_021BAFF8(u8 *p);
u16 func_021BB034(u16 **p);
u16 func_021BB044(u16 **p);
u16 func_021BB05C(u16 **p);
u16 func_021BB074(u16 **p);
void func_021BB088(char *p);
u16 func_021BB1F4(void *p, u16 count, u16 value);
u16 func_021BB258(void *p, u16 count, u16 index);
char *func_021BB2B4(char *p, char *data);
void func_021BB308(char *p);
int func_021BB31C(char *p);
void func_021BB3FC(void *p);
void func_021BB400(char *p);
void func_021BB458(char *p);
void func_021BB4F8(char *a0);
void func_021BB504(char *p);
void func_021BB50C(char *p);
int func_021BB53C(char *p);
extern char file_021BBFF4[];
extern const char d_021BC004[];
extern const char ov067_id[];
extern const char d_021BC014[];
extern const struct Entry_021B9B3C d_021BBF2C[];
extern const struct Block d_021BBF4C;
extern const struct Entry_021BA1C4 d_021BBF00[];
extern const struct Entry d_021BBF14[];
extern const char d_021BC028[];
extern const struct Quad d_021BBF8C,d_021BBF94;
extern const char file_021BC038[];
extern const u8 d_021BBF9C[];



void *func_021B9B3C(void *narc, u32 heap)
{
    void **p = func_02030734(heap, 16, 1, file_021BBFF4, 0x9c);
    u32 size;
    p[0] = ARC_UTIL_LoadHandleMemberWithSize(narc, 11, 0, heap, &size);
    p[1] = ARC_UTIL_LoadHandleMemberWithSize(narc, 12, 0, heap, &size);
    p[2] = ARC_UTIL_LoadHandleMemberWithSize(narc, 9, 0, heap, &size);
    p[3] = ARC_UTIL_LoadHandleMemberWithSize(narc, 10, 0, heap, &size);
    return p;
}



void func_021B9BA4(char *p) {func_020307B0(((struct Obj08466 *)p)->fC);func_020307B0(((struct Obj08466 *)p)->f8);func_020307B0(((struct Obj08466 *)p)->f4);func_020307B0(((struct Obj08466 *)p)->f0);func_020307B0(p);}



u16 func_021B9BC8(char *p,int index) {return *(u16 *)(func_021B9CE0(p,index)+6);}



u16 func_021B9BD4(char *p,int index) {return *(u16 *)(func_021B9CE0(p,index)+8);}



u16 func_021B9BE0(char *p,int index) {return *(u16 *)(func_021B9CE0(p,index)+10);}



u16 func_021B9BEC(char *p,int index) {return *(u16 *)(func_021B9CE0(p,index)+12);}




/*
 * Addresses are Black-image addresses.
 */
u16 func_021B9BF8(char *p, int idx, int c)
{
    return ((u16 *)func_021B9CE0(p, idx))[(c << 1) + 7];
}




u16 func_021B9C0C(char *p, int idx, int c)
{
    return ((u16 *)func_021B9CE0(p, idx))[(c << 1) + 8];
}



u16 func_021B9C20(const char *p) {return **(u16 * *)&((struct Obj26135 *)p)->f4;}



u16 func_021B9C28(char *p,int index) {return *(u16 *)(func_021B9CFC(p,index)+2);}



u16 func_021B9C34(char *p,int index) {return *(u16 *)(func_021B9CFC(p,index)+4);}




u16 func_021B9C40(char *p, int idx, int c)
{
    return ((u16 *)func_021B9CFC(p, idx))[c + 3];
}



u16 func_021B9C50(const char *p) {return **(u16 * *)&((struct Obj26138 *)p)->fC;}



int func_021B9C58(void *unused,int kind,void *save)
{
    int result=0;
    switch(kind) {
    case 0:result=1;break;
    case 1:
        if(func_020090E0((const struct Sub020090B0Obj *)func_02009210(GAME_DATA_GetSaveControl((struct Big *)save)))!=0)result=1;
        break;
    case 2:
        if(ZONEDATA_CheckEventFlag((void *)func_0201296C(save),2400)!=0)result=1;
        break;
    }
    return result;
}




int func_021B9C98(void *unused, int b, int c)
{
    return func_0200EDEC(MISC_SAVEDATA_GetBlock44(GAME_DATA_GetSaveControl((struct Big *)c)), b);
}



void func_021B9CB0(void *unused,int code,struct Big *save) {func_0200EE14(MISC_SAVEDATA_GetBlock44(GAME_DATA_GetSaveControl(save)),code);}



int func_021B9CC8(unsigned unused,unsigned key) {if(key!=65535)return 1;return 0;}



int func_021B9CDC(void *a0){return 0x48;}




int func_021B9CE0(char *p, int idx)
{
    return func_021B9CF0(p, idx) + ((struct Obj26140 *)p)->f0;
}



unsigned short func_021B9CF0(char *p,unsigned i){return *(unsigned short *)(((struct Obj26141 *)p)->f4+i*2+2);}




int func_021B9CFC(char *p, int idx)
{
    return func_021B9D0C(p, idx) + ((struct Obj26142 *)p)->f8;
}



unsigned short func_021B9D0C(char *p,unsigned i){return *(unsigned short *)(((struct Obj26143 *)p)->fC+i*2+2);}



void *func_021B9D18(void *owner,u16 heap)
{
    struct State_021B9B3C *p=func_02030734(heap,0x38,1,d_021BC004,0x4b);
    p->owner=owner; p->heap=heap;
    p->screen=func_021B9900(1,p->heap);
    p->font=GF_FONT_Create(23,0,0,0,p->heap);
    p->str10=PRINTSYS_QUE_Create((void *)(u32)p->heap);
    p->str14=PRINTSYS_QUE_Create((void *)(u32)p->heap);
    p->str18=PRINTSYS_QUE_Create((void *)(u32)p->heap);
    p->bank1=func_02045B38(0,2,61,p->heap);
    p->bank2=func_02045B38(0,2,62,p->heap);
    p->arc1=func_020490F4(223,p->heap);
    p->arc2=func_020490F4(231,p->heap);
    ARC_UTIL_UploadPaletteFromArchive(23,5,4,0,64,32,p->heap);
    p->assets=func_021B9B3C(p->arc1,p->heap);
    func_021B9EE8(p);
    p->id=65535;
    func_021B9E80((char *)p,func_021B9CDC(p->assets));
    p->group=func_021B9F24((char *)p);
    return p;
}



void func_021B9DEC(char *p)
{
    func_021B9F8C(((struct Obj01787 *)p)->f34);func_021B9E80(p,0xffff);func_021B9F20(p);
    func_021B9BA4(((struct Obj01787 *)p)->f2C);ARC_TOOL_DeleteHandle(((struct Obj01787 *)p)->f24);ARC_TOOL_DeleteHandle(((struct Obj01787 *)p)->f28);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj01787 *)p)->f1C);MSGDATA_Delete(*(struct Rec * *)&((struct Obj01787 *)p)->f20);
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj01787 *)p)->f10);PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj01787 *)p)->f10);
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj01787 *)p)->f14);PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj01787 *)p)->f14);
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj01787 *)p)->f18);PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj01787 *)p)->f18);
    GF_FONT_Delete(((struct Obj01787 *)p)->fC);func_021B99A0(*(char * *)&((struct Obj01787 *)p)->f8);func_020307B0(p);
}



void func_021B9E60(char *p){PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj08467 *)p)->f10);PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj08467 *)p)->f14);PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj08467 *)p)->f18);func_021B99F4(*(char * *)&((struct Obj08467 *)p)->f8);}



void func_021B9E80(char *p,unsigned id)
{
    if(((struct Obj04650 *)p)->f30!=id) {
        unsigned size;
        void *buf;
        ((struct Obj04650 *)p)->f30=id;
        if(((struct Obj04650 *)p)->f30==0xffff) {
            buf=func_02030734(((struct Obj04650 *)p)->f4,0x18000,1,d_021BC004,245);
            size=0x18000;
        } else {
            buf=ARC_UTIL_LoadHandleMemberWithSize(((struct Obj04650 *)p)->f28,((struct Obj04650 *)p)->f30,1,((struct Obj04650 *)p)->f4,&size);
        }
        DWCi_ScreenDC_FlushRange(buf,size);GX_LoadBG2Scr(buf,0,0x18000);func_020307B0(buf);
    }
}



/*
 * volatile: 021B9EEC,021B9EF8 re-read 0400000C;021B9F02 read 04000008.
 */
void func_021B9EE8(void *a0){*(volatile unsigned short *)0x0400000C=(*(volatile unsigned short *)0x0400000C&0x43)|0x4084;*(volatile unsigned short *)0x0400000C=(unsigned short)(*(volatile unsigned short *)0x0400000C&~3);*(volatile unsigned short *)0x04000008&=~0x40;func_02040588(2,1);}



void func_021B9F20(void *a0){}



void *func_021B9F24(char *owner)
{
    char *p;
    func_02034AC4((int)ov067_id);
    p=func_02030734(((struct Obj26144 *)owner)->f4,0x4c,1,d_021BC014,235);
    ((struct Obj06734 *)p)->f0=owner;func_021BA160(p);func_021BA1C0(p);func_021BA1C4(p);func_021BA41C(p);
    ((struct Obj06734 *)p)->f8=4;p[0xc]=0;p[0xd]=0;func_021BA068(p,0);func_021BA644(p);
    ((struct Obj06734 *)p)->f48=func_020056A0((unsigned)func_021BA15C,(unsigned)p,1);
    return p;
}



void func_021B9F8C(char *p){func_02030EAC(((struct Obj14802 *)p)->f48);func_021BA4D8(p);func_021BA218(p);TOUCHBAR_Delete(*(unsigned char * *)&((struct Obj14802 *)p)->f4);func_020307B0(p);func_02034A5C((int)ov067_id);}



void func_021B9FBC(char *p)
{
    ((struct Obj00367 *)p)->f24=-1;((struct Obj00367 *)p)->f28=-1;func_021BA240(p);
    if(((struct Obj00367 *)p)->f20==1) {((struct Obj00367 *)p)->f20=0;return;}
    if(((struct Obj00367 *)p)->f20==0 || ((struct Obj00367 *)p)->f20==2) {
        TOUCHBAR_Update(*(S * *)&((struct Obj00367 *)p)->f4);
        if(((struct Obj00367 *)p)->f20==0) {
            int result=TOUCHBAR_GetPressedButtonIdIfPressing(*(u8 * *)&((struct Obj00367 *)p)->f4);
            if(result!=-1) {((struct Obj00367 *)p)->f20=2;((struct Obj00367 *)p)->f24=result;}
        } else {
            int result=TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((struct Obj00367 *)p)->f4);
            if(result!=-1) {((struct Obj00367 *)p)->f20=1;((struct Obj00367 *)p)->f28=result;}
        }
    }
    if(((struct Obj00367 *)p)->f20==0 || ((struct Obj00367 *)p)->f20==3) {
        func_021BA508(p);
        if(((struct Obj00367 *)p)->f20==0) {
            if(((struct Obj00367 *)p)->f44==1) {((struct Obj00367 *)p)->f20=3;*(unsigned *)&((struct Obj00367 *)p)->f24=d_021BBF2C[*(u8 *)(p+0x40)].word[0];}
        } else {
            if(((struct Obj00367 *)p)->f44==3) {((struct Obj00367 *)p)->f20=1;*(unsigned *)&((struct Obj00367 *)p)->f28=d_021BBF2C[*(u8 *)(p+0x40)].word[0];}
        }
    }
}



void func_021BA068(char *p,unsigned state)
{
    if(((struct Obj03964 *)p)->f8==state)return;
    switch(((struct Obj03964 *)p)->f8) {
    case 0:TOUCHBAR_SetButtonVisible(((struct Obj03964 *)p)->f4,0,0);break;
    case 3:CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj03964 *)p)->f38,0);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj03964 *)p)->f3C,0);break;
    case 1:case 2:case 4:break;
    }
    ((struct Obj03964 *)p)->f8=state;func_021BA644(p);
    switch(((struct Obj03964 *)p)->f8) {
    case 0:TOUCHBAR_SetButtonVisible(((struct Obj03964 *)p)->f4,0,1);func_021BA28C(p);break;
    case 1:func_021BA2B0(p);break;
    case 2:func_021BA30C(p);break;
    case 3:case 4:break;
    }
}



/*
 * trailing: 021BA152..021BA154 zero alignment padding, inspected in full show.
 */
void func_021BA0F0(char *p,unsigned b,unsigned c)
{
    p[0xc]=b;p[0xd]=c;
    if(((struct Obj01788 *)p)->f8==3) {
        if(((struct Obj01788 *)p)->fC<=1) {
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01788 *)p)->f38,0);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01788 *)p)->f3C,0);func_021BA28C(p);return;
        }
        if(((struct Obj01788 *)p)->fD==0) {
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01788 *)p)->f38,0);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01788 *)p)->f3C,1);
        } else if(((struct Obj01788 *)p)->fD==b-1) {
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01788 *)p)->f38,1);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01788 *)p)->f3C,0);
        } else {
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01788 *)p)->f38,1);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj01788 *)p)->f3C,1);
        }
        func_021BA368(p);
    }
}



unsigned func_021BA154(char *p){return ((struct Obj26145 *)p)->f28;}



unsigned func_021BA158(char *p){return ((struct Obj26146 *)p)->f24;}



void func_021BA15C(void *task,void *data)
{
}



/*
 * lever: args before table declaration puts the 64-byte copy at sp+0.
 */
void func_021BA160(char *p)
{
    A args;
    struct Block table=d_021BBF4C;
    MI_CpuFill8(&args,0,sizeof(args));
    args.f0=(u8 *)&table;args.f4=2;
    args.f8=(int)func_021B9A08(((struct Obj26147 *)(*(char * *)&((struct Obj08468 *)p)->f0))->f8);
    args.fC=6;args.f10=3;args.f14=1;args.f18=0;
    *(R * *)&((struct Obj08468 *)p)->f4=TOUCHBAR_Create(&args,((struct Obj26148 *)(*(char * *)&((struct Obj08468 *)p)->f0))->f4);
    TOUCHBAR_SetButtonVisible(((struct Obj08468 *)p)->f4,0,0);
}



void func_021BA1C0(void *a0){}



void func_021BA1C4(char *p)
{
    u8 i;
    for(i=0;i<2;i++) {
        const struct Entry_021BA1C4 *t=&d_021BBF00[i];
        *(unsigned *)(p+i*4+0x10)=BMP_WIN_Create(t->a,t->b,t->c,t->d,t->e,t->f,t->g);
        BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(p+i*4+0x10)),0);
        BMP_WIN_TransferChars(*(struct Descriptor **)(p+i*4+0x10));
        *(unsigned *)(p+i*4+0x18)=0;
    }
}



void func_021BA218(char *p){unsigned char i;PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj26150 *)(*(char * *)&((struct Obj26149 *)p)->f0))->f18);for(i=0;i<2;i++){*(unsigned *)((unsigned)p+i*4+24)=0;BMP_WIN_Delete(*(struct Descriptor **)((unsigned)p+i*4+16));}}



void func_021BA240(char *p)
{
    u8 i;
    for(i=0;i<2;i++) {
        if(*(unsigned *)(p+i*4+0x18)!=0) {
            if(PRINTSYS_QUE_IsExistTarget(*(struct PrintSys * *)&((struct Obj26152 *)(*(char * *)&((struct Obj26151 *)p)->f0))->f18,BMP_WIN_GetBmp(*(struct Descriptor **)(p+i*4+0x10)))==0) {
                struct Descriptor *d=*(struct Descriptor **)(p+i*4+0x10);
                BMP_WIN_TransferChars(d);BMP_WIN_MakeScreen((struct Cfg *)d);
                func_02041B6C(BMP_WIN_GetBgLayer(d));
                *(unsigned *)(p+i*4+0x18)=0;
            }
        }
    }
}



void func_021BA28C(char *p){PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj26153 *)(*(char * *)&((struct Obj08469 *)p)->f0))->f18);BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj08469 *)p)->f14),0);BMP_WIN_TransferChars(*(struct Descriptor * *)&((struct Obj08469 *)p)->f14);((struct Obj08469 *)p)->f1C=0;}



void func_021BA2B0(char *p)
{
    void *s;
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj26154 *)(*(char * *)&((struct Obj04652 *)p)->f0))->f18);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj04652 *)p)->f14),0);
    s=func_02045EC0(*(struct MsgBank * *)&((struct Obj26155 *)(*(char * *)&((struct Obj04652 *)p)->f0))->f1C,2);
    PRINTSYS_PrintQueColor(((struct Obj26156 *)(*(char * *)&((struct Obj04652 *)p)->f0))->f18,(unsigned)BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj04652 *)p)->f14),0,4,(unsigned)s,((struct Obj26157 *)(*(char * *)&((struct Obj04652 *)p)->f0))->fC,0x3c40);
    STRBUF_Delete(s);((struct Obj04652 *)p)->f1C=1;func_021BA240(p);
}



void func_021BA30C(char *p)
{
    void *s;
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj26158 *)(*(char * *)&((struct Obj04653 *)p)->f0))->f18);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj04653 *)p)->f14),0);
    s=func_02045EC0(*(struct MsgBank * *)&((struct Obj26159 *)(*(char * *)&((struct Obj04653 *)p)->f0))->f1C,3);
    PRINTSYS_PrintQueColor(((struct Obj26160 *)(*(char * *)&((struct Obj04653 *)p)->f0))->f18,(unsigned)BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj04653 *)p)->f14),0,4,(unsigned)s,((struct Obj26161 *)(*(char * *)&((struct Obj04653 *)p)->f0))->fC,0x3c40);
    STRBUF_Delete(s);((struct Obj04653 *)p)->f1C=1;func_021BA240(p);
}



/*
 * extent: 178 compiled bytes followed by two zero alignment bytes at 021BA41A.
 */
void func_021BA368(char *p)
{
    struct WordSet *words;
    struct U16Vec *str;
    void *slot;
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj26162 *)(*(char * *)&((struct Obj02561 *)p)->f0))->f18);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj02561 *)p)->f14),0);
    words=func_0201EC64(((struct Obj26163 *)(*(char * *)&((struct Obj02561 *)p)->f0))->f4);
    slot=func_02045EC0(*(struct MsgBank * *)&((struct Obj26164 *)(*(char * *)&((struct Obj02561 *)p)->f0))->f1C,4);
    str=STRBUF_Create(16,((struct Obj26165 *)(*(char * *)&((struct Obj02561 *)p)->f0))->f4);
    func_0201EFA4(words,0,((struct Obj02561 *)p)->fD+1,1,0,1);
    func_0201EFA4(words,1,((struct Obj02561 *)p)->fC,1,0,1);
    func_0201F250(words,str,slot);
    PRINTSYS_PrintQueColor(((struct Obj26166 *)(*(char * *)&((struct Obj02561 *)p)->f0))->f18,(u32)BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj02561 *)p)->f14),32,4,(u32)str,((struct Obj26167 *)(*(char * *)&((struct Obj02561 *)p)->f0))->fC,0x3c40);
    STRBUF_Delete(str);STRBUF_Delete(slot);func_0201ED04(words);
    ((struct Obj02561 *)p)->f1C=1;func_021BA240(p);
}



void func_021BA41C(char *p)
{
    u8 i;
    void *loader;
    u32 first;
    loader=func_020490F4(func_020275E4(),((struct Obj26168 *)(*(char * *)&((struct Obj02562 *)p)->f0))->f4);
    *(int *)&((struct Obj02562 *)p)->f30=CLACT_RegisterPaletteEx((void *)((u32)loader),func_02027614(),1,128,0,3,((struct Obj26169 *)(*(char * *)&((struct Obj02562 *)p)->f0))->f4);
    *(int *)&((struct Obj02562 *)p)->f2C=CLACT_RegisterCharacter((void *)((u32)loader),func_02027618(),0,1,((struct Obj26170 *)(*(char * *)&((struct Obj02562 *)p)->f0))->f4);
    first=func_0202761C(0);
    *(int *)&((struct Obj02562 *)p)->f34=CLACT_RegisterCellAnim((void *)((u32)loader),first,func_02027620(0),((struct Obj26171 *)(*(char * *)&((struct Obj02562 *)p)->f0))->f4);
    ARC_TOOL_DeleteHandle(loader);
    for(i=0;i<2;i++) {
        char *parent=*(char * *)&((struct Obj02562 *)p)->f0;
        char *dest=p+i*4;
        *(struct Obj * *)&((struct Obj10983 *)dest)->f38=CLACT_CreateActor((void *)func_021B9A08(((struct Obj14803 *)parent)->f8),((struct Obj02562 *)p)->f2C,((struct Obj02562 *)p)->f30,((struct Obj02562 *)p)->f34,&d_021BBF14[i],1,((struct Obj14803 *)parent)->f4);
        CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj10983 *)dest)->f38,0);
        CLACT_SetActorAutoAnim(*(struct Obj * *)&((struct Obj10983 *)dest)->f38,1);
    }
}



void func_021BA4D8(char *p) { u8 i; for(i=0;i<2;i++) CLACT_DeleteActor(*(struct Obj **)(p+i*4+0x38)); CLACT_ReleaseCellAnim(((struct Obj10984 *)p)->f34); CLACT_ReleaseCharacter(((struct Obj10984 *)p)->f2C); CLACT_ReleasePalette(((struct Obj10984 *)p)->f30); }



void func_021BA508(char *p)
{
 u8 i;
 u32_021BA508 found,x,y;
 const struct Entry *row;
 switch(((struct Obj00367 *)p)->f44) {
 case 0:
  found=0;
  for(i=0;i<2;i++) {
   if(CLACT_GetActorDrawEnable(*(struct Obj **)(p+i*4+0x38))) {
    row=&d_021BBF14[i];
    if(KEY_GetRepeat()&row->mask) {
     ((struct Obj00367 *)p)->f40=i;
     func_020355D8(0);
     found=1;
     break;
    }
    if(TOUCHPANEL_GetPointTrg(&x,&y)) {
     if(row->left<=x && x<=row->right && row->top<=y && y<=row->bottom) {
      ((struct Obj00367 *)p)->f40=i;
      found=1;
      func_020355D8(1);
      break;
     }
    }
   }
  }
  if(found) {
   CLACT_SetActorAnimSeq(*(struct Obj **)(p+((struct Obj00367 *)p)->f40*4+0x38),d_021BBF14[*(u8 *)(p+0x40)].active);
   if(d_021BBF14[*(u8 *)(p+0x40)].sound) GFL_USE_PlaySeDefaultVolume(d_021BBF14[*(u8 *)(p+0x40)].sound);
   ((struct Obj00367 *)p)->f44=1;
  }
  break;
 case 1: ((struct Obj00367 *)p)->f44=2; break;
 case 2:
  if(!CLACT_IsActorAnimActive(*(struct Actor **)(p+((struct Obj00367 *)p)->f40*4+0x38))) {
   CLACT_SetActorAnimSeq(*(struct Obj **)(p+((struct Obj00367 *)p)->f40*4+0x38),d_021BBF14[*(u8 *)(p+0x40)].normal);
   ((struct Obj00367 *)p)->f44=3;
  }
  break;
 case 3: ((struct Obj00367 *)p)->f44=0; ((struct Obj00367 *)p)->f40=255; break;
 }
}




void func_021BA644(char *p)
{
    int z = 0;
    int m = z - 1;
    *(int *)(p + 0x20) = z;
    *(int *)(p + 0x24) = m;
    *(int *)(p + 0x28) = m;
    *(u8 *)(p + 0x40) = 0xFF;
    *(int *)(p + 0x44) = z;
}



void *func_021BA65C(char *owner, struct Data *data)
{
  struct Work *p;
  struct Vec2_021BA508 v;
  u8 i;
  u32_021BA65C flag;
  u32_021BA65C state;
  int n;
  s16_021BA65C y;
  int mode;
  p = func_02030734(data->heap, 0x98, 1, d_021BC028, 0xdf);
  p->owner = owner;
  *((u32_021BA65C *) (owner + 0x10)) = 0;
  p->data = data;
  i = 0;
  do
  {
    p->a[i] = 0;
    p->b[i] = 0;
    i++;
  }
  while (i < 8);
  p->field94 = 0;
  func_021BA898((char *)p);
  func_021BAA44(p);
  func_02041EE4(5, 3, 12);
  flag = 0;
  if ((*((u16 *) (p->owner + 4))) > 6)
    flag = 1;
  CLACT_SetActorDrawEnable(p->obj, flag);
  n = func_021BB074((u16 **) p);
  n = n + 1;
  y = func_021BB258(p, n, *((u16 *) (p->owner + 0xc)));
  v.x = 240;
  v.y = y;
  CLACT_AddActorSurfacePos(p->obj, (const struct Vec2_021BA508 *)&v, 1);
  p->task = func_020056A0((u32_021BA65C) func_021BA894, (u32_021BA65C) p, 1);
  p->field84 = 0;
  p->field88 = 0;
  p->field8c = 0;
  p->field90 = -1;
  mode = *((int *) p->owner);
  state = 2;
  if (mode == 0)
    state = 1;
  else
    if (mode == 1)
    state = 2;
  func_021BA068(*((char **) (((char *) p->data) + 0x34)), state);
  return p;
}




void func_021BA740(char *p)
{
    func_02030EAC(((struct Obj26178 *)p)->f80);
    func_02041EE4(5, 3, 0);
    func_020307B0(p);
}



/*
 * extent: lead 308 bytes; empty callback at 021BA894 and two zero alignment bytes.
 * arity: 02028178 retains original r1 payload despite unused input in its body.
 */
int func_021BA760(char *p)
{
 u8 i;
 int result=0;
 unsigned selected;
 if(!PRINTSYS_QUE_IsFinished(*(const struct PrintSys * *)&((struct Obj26179 *)(*(char * *)&((struct Obj00601 *)p)->f4))->f14)) return 0;
 if(((struct Obj00601 *)p)->f90==0) result=1;
 else if(((struct Obj00601 *)p)->f90>0) {
  if(((struct Obj00601 *)p)->f90==1) func_021BAA50(p);
  (((struct Obj00601 *)p)->f90)--;
 }
 if(((struct Obj00601 *)p)->f84!=1) {
  for(i=0;i<8;i++) {
   if(*(u8 **)(p+i*4+0xc) && *(void **)(p+i*4+0x2c))
    APP_TASKMENU_WIN_Update(*(u8 **)(p+i*4+0xc));
  }
 }
 if(((struct Obj00601 *)p)->f84==0 || ((struct Obj00601 *)p)->f84==2) {
  if(func_021BAE2C(p)) ((struct Obj00601 *)p)->f84=2;
  else ((struct Obj00601 *)p)->f84=0;
 }
 if(((struct Obj00601 *)p)->f84==0 || ((struct Obj00601 *)p)->f84==3) {
  func_021B9FBC(*(char * *)&((struct Obj26180 *)(*(char * *)&((struct Obj00601 *)p)->f4))->f34);
  if(((struct Obj00601 *)p)->f84==0) {
   if(func_021BA158(*(char * *)&((struct Obj26181 *)(*(char * *)&((struct Obj00601 *)p)->f4))->f34)!=(unsigned)-1) ((struct Obj00601 *)p)->f84=3;
  } else {
   selected=func_021BA154(*(char * *)&((struct Obj26182 *)(*(char * *)&((struct Obj00601 *)p)->f4))->f34);
   if(selected!=(unsigned)-1) {
    if(selected==1) ((struct Obj26183 *)(*(char * *)&((struct Obj00601 *)p)->f0))->f10=0;
    ((struct Obj00601 *)p)->f84=1;
    ((struct Obj00601 *)p)->f90=1;
   }
  }
 }
 if(((struct Obj00601 *)p)->f84==0 || ((struct Obj00601 *)p)->f84==4) {
  if(((struct Obj00601 *)p)->f84==0) {
   if(func_021BAABC(p)) ((struct Obj00601 *)p)->f84=4;
  } else {
   if(APP_TASKMENU_WIN_IsFinish(*(u8 **)(p+func_021BB034((u16 **)p)*4+0xc))) {
    ((struct Obj26184 *)(*(char * *)&((struct Obj00601 *)p)->f0))->f10=1;
    ((struct Obj00601 *)p)->f84=1;
    ((struct Obj00601 *)p)->f90=1;
   }
  }
 }
 return result;
}




void func_021BA894(void) {}



/*
 * Lever: index before 0x60 keeps field offset in immediate; distinct loop
 * parent local restores r7 parent / r6 destination allocation.
 */
void func_021BA898(char *p)
{
    struct Quad q[2];
    u8 i;
    char *parent;
    func_02049B68(((struct Obj26185 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f24,0,4,0,0x40,((struct Obj26186 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    func_02049658(((struct Obj26187 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f24,2,4,0,0,0,((struct Obj26188 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    ARC_UTIL_UploadBgPaletteAddFromHandleExt(((struct Obj26189 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f24,5,4,0,0,0,0,((struct Obj26190 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    *(int *)&((struct Obj00074 *)p)->f54=CLACT_RegisterPaletteEx(((struct Obj26191 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f24,1,1,0,0,1,((struct Obj26192 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    *(int *)&((struct Obj00074 *)p)->f50=CLACT_RegisterCharacter(((struct Obj26193 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f24,3,0,1,((struct Obj26194 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    *(int *)&((struct Obj00074 *)p)->f58=CLACT_RegisterCellAnim(((struct Obj26195 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f24,7,8,((struct Obj26196 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    q[1]=d_021BBF8C;
    parent=*(char * *)&((struct Obj00074 *)p)->f4;
    ((struct Obj00074 *)p)->f5C=CLACT_CreateActor((void *)func_021B9A08(((struct Obj14804 *)parent)->f8),((struct Obj00074 *)p)->f50,((struct Obj00074 *)p)->f54,((struct Obj00074 *)p)->f58,&q[1],1,((struct Obj14804 *)parent)->f4);
    CLACT_SetActorDrawEnable(((struct Obj00074 *)p)->f5C,0);
    CLACT_SetActorAutoAnim(((struct Obj00074 *)p)->f5C,1);
    q[0]=d_021BBF94;
    for(i=0;i<8;i++) {
        char *loopparent;
        q[0].y=i*24-8;
        loopparent=*(char * *)&((struct Obj00074 *)p)->f4;
        *(void **)(p+i*4+0x60)=CLACT_CreateActor((void *)func_021B9A08(((struct Obj14805 *)loopparent)->f8),((struct Obj00074 *)p)->f50,((struct Obj00074 *)p)->f54,((struct Obj00074 *)p)->f58,&q[0],1,((struct Obj14805 *)loopparent)->f4);
        CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x60),0);
        CLACT_SetActorAutoAnim(*(void **)(p+i*4+0x60),1);
    }
    func_021BA9D0(p);
}



void func_021BA9D0(char *p)
{
    func_020414AC(5);
    *(struct R * *)&((struct Obj00074 *)p)->f8 = APP_TASKMENU_RES_Create(5, 4, ((struct Obj26197 *)(*(char * *)&((struct Obj00074 *)p)->f4))->fC, ((struct Obj26198 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f14, ((struct Obj26199 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
    ((struct Obj00074 *)p)->f4C = 0x1ce7;
    func_02061CA4((void *)31, 154, p + 0x4c, 2);
    func_02061CA4((void *)31, 186, p + 0x4c, 2);
    func_021BB088(p);
    if (func_020355C4() == 0) {
        APP_TASKMENU_WIN_SetActive(*(struct Obj **)(p + func_021BB034((u16 **)p) * 4 + 0xc), 1);
        ((struct Obj00074 *)p)->f8C = 0;
    }
}




void func_021BAA44(struct Work *a0) { sub_02041B6C(4); }



void func_021BAA50(char *p) { u8 i; func_021BAA88(p); for(i=0;i<8;i++) CLACT_DeleteActor(*(struct Obj **)(p+i*4+0x60)); CLACT_DeleteActor(*(struct Obj * *)&((struct Obj08470 *)p)->f5C); CLACT_ReleaseCellAnim(((struct Obj08470 *)p)->f58); CLACT_ReleaseCharacter(((struct Obj08470 *)p)->f50); CLACT_ReleasePalette(((struct Obj08470 *)p)->f54); }



void func_021BAA88(char *p) { u8 i; PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj26200 *)(*(char * *)&((struct Obj14806 *)p)->f4))->f14); for(i=0;i<8;i++) if(*(u8 **)(p+i*4+12)) APP_TASKMENU_WIN_Delete(*(u8 **)(p+i*4+12)); APP_TASKMENU_RES_Delete(*(struct TaskMenuState * *)&((struct Obj14806 *)p)->f8); sub_02041B6C(5); }



int func_021BAABC(char *p)
{
    u8 rect[28];
    struct Vec2_021BAABC delta[4];
    int hit;
    u16 count,last,y;
    func_021BAFF8(rect);
    hit=TOUCHPANEL_HitTrg(rect);
    count=func_021BB05C((u16 **)p);
    last=func_021BB044((u16 **)p);
    if(func_020355C4()==0) {
        if(hit>=0 && hit<count) {
            func_020355D8(1);
            APP_TASKMENU_WIN_SetActive(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),0);
        }
    } else {
        if(KEY_GetTrg()!=0 && !(KEY_GetTrg()&2)) {
            func_020355D8(0);
            APP_TASKMENU_WIN_SetActive(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),1);
            ((struct Obj00074 *)p)->f8C=0;
            GFL_USE_PlaySeDefaultVolume(0x548);
            return 0;
        }
    }
    if(func_020355C4()==0) {
        if(KEY_GetTrg()&1) {
            APP_TASKMENU_WIN_SetDecide(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),1);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            return 1;
        }
        if(ST->count>1) {
            if(KEY_GetRepeat()&0x40) {
                APP_TASKMENU_WIN_SetActive(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),0);
                if(ST->selected>ST->top) ST->selected--;
                else if(ST->count<=6) ST->selected=ST->count-1;
                else {
                    if(ST->selected!=0) {
                        ST->top--;
                        ST->selected--;
                    } else {
                        ST->top=func_021BB074((u16 **)p);
                        ST->selected=ST->count-1;
                    }
                    func_021BB088(p);
                    y=func_021BB258(p,(u16)(func_021BB074((u16 **)p)+1),ST->top);
                    delta[3].x=240;
                    delta[3].y=y;
                    CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj00074 *)p)->f5C, (const struct Vec2_021BA508 *)(&delta[3]), 1);
                }
                APP_TASKMENU_WIN_SetActive(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),1);
                ((struct Obj00074 *)p)->f8C=0;
                GFL_USE_PlaySeDefaultVolume(0x548);
            } else if(KEY_GetRepeat()&0x80) {
                APP_TASKMENU_WIN_SetActive(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),0);
                if(ST->selected<last) ST->selected++;
                else if(ST->count<=6) ST->selected=0;
                else {
                    if(ST->selected<ST->count-1) {
                        ST->top++;
                        ST->selected++;
                    } else {ST->top=0;ST->selected=0;}
                    func_021BB088(p);
                    y=func_021BB258(p,(u16)(func_021BB074((u16 **)p)+1),ST->top);
                    delta[2].x=240;
                    delta[2].y=y;
                    CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj00074 *)p)->f5C, (const struct Vec2_021BA508 *)(&delta[2]), 1);
                }
                APP_TASKMENU_WIN_SetActive(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),1);
                ((struct Obj00074 *)p)->f8C=0;
                GFL_USE_PlaySeDefaultVolume(0x548);
            } else if(KEY_GetRepeat()&0x220) {
                if(ST->selected!=0) {
                    APP_TASKMENU_WIN_SetActive(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),0);
                    if(ST->count<=6) ST->selected=0;
                    else {
                        if(ST->top>=6) {ST->top-=6;ST->selected-=6;}
                        else {ST->top=0;if(ST->selected>=6) ST->selected-=6;else ST->selected=0;}
                        func_021BB088(p);
                        y=func_021BB258(p,(u16)(func_021BB074((u16 **)p)+1),ST->top);
                        delta[1].x=240;
                        delta[1].y=y;
                        CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj00074 *)p)->f5C, (const struct Vec2_021BA508 *)(&delta[1]), 1);
                    }
                    APP_TASKMENU_WIN_SetActive(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),1);
                    ((struct Obj00074 *)p)->f8C=0;
                    GFL_USE_PlaySeDefaultVolume(0x548);
                }
            } else if(KEY_GetRepeat()&0x110) {
                if(ST->selected<ST->count-1) {
                    APP_TASKMENU_WIN_SetActive(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),0);
                    if(ST->count<=6) ST->selected=ST->count-1;
                    else {
                        ST->top+=6;
                        if(ST->top>func_021BB074((u16 **)p)) ST->top=func_021BB074((u16 **)p);
                        ST->selected+=6;
                        if(ST->selected>=ST->count) ST->selected=ST->count-1;
                        func_021BB088(p);
                        y=func_021BB258(p,(u16)(func_021BB074((u16 **)p)+1),ST->top);
                        delta[0].x=240;
                        delta[0].y=y;
                        CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj00074 *)p)->f5C, (const struct Vec2_021BA508 *)(&delta[0]), 1);
                    }
                    APP_TASKMENU_WIN_SetActive(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),1);
                    ((struct Obj00074 *)p)->f8C=0;
                    GFL_USE_PlaySeDefaultVolume(0x548);
                }
            }
        }
    } else if(hit>=0 && hit<count) {
        ST->selected=ST->top+hit;
        APP_TASKMENU_WIN_SetActive(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),1);
        ((struct Obj00074 *)p)->f8C=0;
        APP_TASKMENU_WIN_SetDecide(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),1);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return 1;
    }
    return 0;
}



/*
 * Lever: initialise offset after cursor clear, letting zero schedule at
 * that call's argument setup rather than before the touch-mode setter.
 */
int func_021BAE2C(char *p)
{
    u32_021BAE2C dragx,dragy;
    struct Vec2_021BAABC drag;
    u32_021BAE2C clickx,clicky;
    struct Vec2_021BAABC click;
    if(CLACT_GetActorDrawEnable(*(struct Obj * *)&((struct Obj00074 *)p)->f5C)==0) return 0;
    if(((struct Obj00074 *)p)->f88) {
        if(TOUCHPANEL_GetPointCont(&dragx,&dragy)) {
            int offset;
            u16 selection,end;
            func_020355D8(1);
            APP_TASKMENU_WIN_SetActive(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),0);
            offset=0;
            drag.x=240;
            if(dragy>=8) offset=dragy-8;
            drag.y=offset;
            if(drag.y<17) drag.y=17;
            else if(drag.y>135) drag.y=135;
            CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj00074 *)p)->f5C, (const struct Vec2_021BA508 *)&drag, 1);
            selection=func_021BB1F4(p,(u16)(func_021BB074((u16 **)p)+1),(u16)dragy);
            if(selection!=((struct Obj26201 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC) {
                ((struct Obj26202 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC=selection;
                end=func_021BB044((u16 **)p);
                if(((struct Obj00074 *)p)->f8C || ((struct Obj26203 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fE<((struct Obj26204 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC || end<((struct Obj26205 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fE) {
                    ((struct Obj26207 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fE=((struct Obj26206 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC;
                    ((struct Obj00074 *)p)->f8C=1;
                }
                func_021BB088(p);
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
        } else ((struct Obj00074 *)p)->f88=0;
        return 1;
    } else {
        if(TOUCHPANEL_GetPointTrg(&clickx,&clicky) && clickx>=240 && clickx<=247 && clicky>=17 && clicky<=150) {
            int offset;
            u16 selection,end;
            func_020355D8(1);
            APP_TASKMENU_WIN_SetActive(*(void **)(p+func_021BB034((u16 **)p)*4+0xc),0);
            offset=0;
            GFL_USE_PlaySeDefaultVolume(0x548);
            ((struct Obj00074 *)p)->f88=1;
            click.x=240;
            if(clicky>=8) offset=clicky-8;
            click.y=offset;
            if(click.y<17) click.y=17;
            else if(click.y>135) click.y=135;
            CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj00074 *)p)->f5C, (const struct Vec2_021BA508 *)&click, 1);
            selection=func_021BB1F4(p,(u16)(func_021BB074((u16 **)p)+1),(u16)clicky);
            if(selection!=((struct Obj26208 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC) {
                ((struct Obj26209 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC=selection;
                end=func_021BB044((u16 **)p);
                if(((struct Obj00074 *)p)->f8C || ((struct Obj26210 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fE<((struct Obj26211 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC || end<((struct Obj26212 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fE) {
                    ((struct Obj26214 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fE=((struct Obj26213 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC;
                    ((struct Obj00074 *)p)->f8C=1;
                }
                func_021BB088(p);
            }
        }
        if(((struct Obj00074 *)p)->f88) return 1;
        return 0;
    }
}



void func_021BAFF8(u8 *p) { u8 i; for(i=0;i<6;i++) { p[i*4]=i*24+12; p[i*4+1]=(i+1)*24+11; p[i*4+2]=16; p[i*4+3]=239; } p[24]=255; p[25]=0; p[26]=0; p[27]=0; }




u16 func_021BB034(u16 **p)
{
    u16 *q = *p;
    return (u16)(q[7] - q[6] + 1);
}




u16 func_021BB044(u16 **p)
{
    u16 *q = *p;
    u16 a = (u16)(q[6] + 5);
    u16 b = q[2];
    if (a < b)
        return a;
    return (u16)(b - 1);
}




u16 func_021BB05C(u16 **p)
{
    return (u16)(func_021BB044(p) - (*p)[6] + 1);
}




u16 func_021BB074(u16 **p)
{
    u16 v = (*p)[2];
    if (v <= 6)
        return 0;
    return (u16)(v - 6);
}



void func_021BB088(char *p)
{
    struct Entry_021BB088 e;
    u8 first,last,i;
    u16 index,end;
    first=0;
    index=(u16)(((struct Obj26217 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC-1);
    if (((struct Obj26218 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC==0) {
        if (*(u8 * *)&((struct Obj00074 *)p)->fC) {
            APP_TASKMENU_WIN_ClearScreen(*(u8 * *)&((struct Obj00074 *)p)->fC);
            ((struct Obj00074 *)p)->f2C=0;
        }
        index=((struct Obj26219 *)(*(char * *)&((struct Obj00074 *)p)->f0))->fC;
        first=1;
        CLACT_SetActorDrawEnable(((struct Obj00074 *)p)->f60,0);
    }
    end=(u16)(func_021BB044((u16 **)p)+1);
    if (end>=((struct Obj26220 *)(*(char * *)&((struct Obj00074 *)p)->f0))->f4) end--;
    last=(u8)(first+end-index);
    for(i=last+1;i<=7;i++) {
        if (*(u8 **)(p+i*4+0xc)) {
            APP_TASKMENU_WIN_ClearScreen(*(u8 **)(p+i*4+0xc));
            *(u32_021BB088 *)(p+i*4+0x2c)=0;
        }
        CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x60),0);
    }
    for(i=first;i<=last;i++) {
        if (*(u8 **)(p+i*4+0xc)) APP_TASKMENU_WIN_DeleteNoClear();
        e.resource=func_02045EC0(*(struct MsgBank * *)&((struct Obj26221 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f20,*(u16 *)(*(char * *)&((struct Obj26222 *)(*(char * *)&((struct Obj00074 *)p)->f0))->f8+index*8+2));
        if(i==0 || i==7) e.tag=0x3da3; else e.tag=0x39e3;
        e.flags=0;
        if(((struct Obj00074 *)p)->f94)
            *(u32_021BB088 **)(p+i*4+0xc)=APP_TASKMENU_WIN_CreateExNoScreen(*(u32_021BB088 *)&((struct Obj00074 *)p)->f8,(u32_021BB088)&e,2,(u8)(i*3),28,3,0,0,((struct Obj26223 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
        else
            *(u32_021BB088 *)(p+i*4+0xc)=APP_TASKMENU_WIN_Create(*(u32_021BB088 *)&((struct Obj00074 *)p)->f8,(u32_021BB088)&e,2,(u8)(i*3),28,((struct Obj26224 *)(*(char * *)&((struct Obj00074 *)p)->f4))->f4);
        APP_TASKMENU_WIN_Update(*(u8 **)(p+i*4+0xc));
        *(u32_021BB088 *)(p+i*4+0x2c)=1;
        STRBUF_Delete(e.resource);
        if (*(u32_021BB088 *)(*(char * *)&((struct Obj26225 *)(*(char * *)&((struct Obj00074 *)p)->f0))->f8+index*8+4)==0)
            CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x60),0);
        else if (*(u32_021BB088 *)(*(char * *)&((struct Obj26226 *)(*(char * *)&((struct Obj00074 *)p)->f0))->f8+index*8+4)==1)
            CLACT_SetActorDrawEnable(*(void **)(p+i*4+0x60),1);
        index++;
    }
    ((struct Obj00074 *)p)->f94=1;
}



u16 func_021BB1F4(void *p, u16 count, u16 value)
{
    u16 index, upper, lower;
    if (count <= 1) index = 0;
    else if (value < 25) index = 0;
    else if (value >= 144) index = count - 1;
    else {
        for (index = 0; index < count; index++) {
            upper = (119 * (index + 1)) / count + 25;
            lower = (119 * index) / count + 25;
            if (lower <= value && value < upper) break;
        }
    }
    if (index >= count) index = 0;
    return index;
}



/*
 * lever: narrow the average to u16 before subtracting 8; minimum clamp returns directly.
 * extent: 90 compiled bytes followed by two zero alignment bytes at 021BB2B2.
 */
u16 func_021BB258(void *p, u16 count, u16 index)
{
    u16 result, low, high;
    if (index == 0) result = 17;
    else if (index == count - 1) result = 135;
    else {
        low = (119 * index) / count + 25;
        high = (119 * (index + 1)) / count + 25;
        result = (low + high) / 2;
        result -= 8;
    }
    if (result < 17) return 17;
    if (result > 135) result = 135;
    return result;
}



char *func_021BB2B4(char *p, char *data)
{
    char *q;
    q = func_02030734(((struct Obj26227 *)data)->f4, 32, 1, file_021BC038, 157);
    *(char * *)&((struct Obj05574 *)q)->f0 = p;
    ((struct Obj26228 *)p)->f4 = 1;
    *(char * *)&((struct Obj05574 *)q)->f4 = data;
    func_021BB400(q);
    func_021BB4F8(q);
    ((struct Obj05574 *)q)->f14 = func_020056A0((unsigned)func_021BB3FC, (unsigned)q, 1);
    ((struct Obj05574 *)q)->f18 = 0;
    q[0x1c] = -1;
    func_021BA068(*(char * *)&((struct Obj26229 *)(*(char * *)&((struct Obj05574 *)q)->f4))->f34, 0);
    return q;
}




void func_021BB308(char *p)
{
    func_02030EAC((struct Node *)(((struct Obj26230 *)p)->f14));
    func_020307B0(p);
}



/*
 * Tail: 021BB3FA alignment, existing matched follower 021BB3FC.
 * Lever: switch body order 1 then 0 preserves the shared store block.
 */
int func_021BB31C(char *p)
{
    int done = 0;
    u8 i;
    if (((struct Obj00691 *)p)->f1C==0) done=1;
    else if (((struct Obj00691 *)p)->f1C>0) {
        if (((struct Obj00691 *)p)->f1C==1) func_021BB504(p);
        --((struct Obj00691 *)p)->f1C;
    }
    if (((struct Obj00691 *)p)->f18==0 || ((struct Obj00691 *)p)->f18==2) {
        func_021B9FBC(*(char * *)&((struct Obj26231 *)(*(char * *)&((struct Obj00691 *)p)->f4))->f34);
        if (((struct Obj00691 *)p)->f18==0) {
            if (func_021BA158(*(char * *)&((struct Obj26232 *)(*(char * *)&((struct Obj00691 *)p)->f4))->f34)!=-1)
                ((struct Obj00691 *)p)->f18=2;
        } else {
            int result=func_021BA154(*(char * *)&((struct Obj26233 *)(*(char * *)&((struct Obj00691 *)p)->f4))->f34);
            if (result!=-1) {
                switch (result) {
                case 1: ((struct Obj26234 *)(*(char * *)&((struct Obj00691 *)p)->f0))->f4=1; break;
                case 0: ((struct Obj26235 *)(*(char * *)&((struct Obj00691 *)p)->f0))->f4=0; break;
                }
                ((struct Obj00691 *)p)->f18=1;
                ((struct Obj00691 *)p)->f1C=1;
            }
        }
    }
    if (((struct Obj00691 *)p)->f18==0 || ((struct Obj00691 *)p)->f18==3) {
        for (i=0;i<2;i++) APP_TASKMENU_WIN_Update((u8 *)(*(char **)(p+0xc+i*4)));
        if (((struct Obj00691 *)p)->f18==0) {
            if (func_021BB53C(p)) ((struct Obj00691 *)p)->f18=3;
        } else {
            if (APP_TASKMENU_WIN_IsFinish((u8 *)(*(char **)(p+0xc+**(u8 * *)&((struct Obj00691 *)p)->f0*4)))) {
                unsigned value;
                if (**(u8 * *)&((struct Obj00691 *)p)->f0==0) value=2;
                else if (**(u8 * *)&((struct Obj00691 *)p)->f0==1) value=3;
                else goto finish;
                ((struct Obj26239 *)(*(char * *)&((struct Obj00691 *)p)->f0))->f4=value;
finish:
                ((struct Obj00691 *)p)->f18=1;
                ((struct Obj00691 *)p)->f1C=1;
            }
        }
    }
    return done;
}



void func_021BB3FC(void *p)
{
}



/*
 * extent: 86 compiled bytes followed by two zero alignment bytes at 021BB456.
 */
void func_021BB400(char *p)
{
    func_02049B68((void *)(((struct Obj26240 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f24), 0, 4, 0, 64, ((struct Obj26241 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f4);
    func_02049658((void *)(((struct Obj26242 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f24), 2, 4, 0, 0, 0, ((struct Obj26243 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f4);
    ARC_UTIL_UploadBgPaletteAddFromHandleExt((void *)(((struct Obj26244 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f24), 4, 4, 0, 0, 0, 0, ((struct Obj26245 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f4);
    func_021BB458(p);
}



void func_021BB458(char *p)
{
    struct Entry_021BB458 entries[2];
    u8 i;
    *(struct R * *)&((struct Obj01596 *)p)->f8 = APP_TASKMENU_RES_Create(5, 4, ((struct Obj26246 *)(*(char * *)&((struct Obj01596 *)p)->f4))->fC, ((struct Obj26247 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f14, ((struct Obj26248 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f4);
    entries[0].resource = func_02045EC0(*(struct MsgBank * *)&((struct Obj26249 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f1C, 0);
    entries[0].tag = 0x39e3;
    entries[0].flags = 0;
    entries[1].resource = func_02045EC0(*(struct MsgBank * *)&((struct Obj26250 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f1C, 1);
    entries[1].tag = 0x39e3;
    entries[1].flags = 0;
    for (i = 0; i < 2; i++) {
        *(unsigned *)(p + i * 4 + 0xc) = APP_TASKMENU_WIN_Create(*(unsigned *)&((struct Obj01596 *)p)->f8, (unsigned)&entries[i], 1, (u8)((i + 1) * 3), 30, ((struct Obj26251 *)(*(char * *)&((struct Obj01596 *)p)->f4))->f4);
        STRBUF_Delete(entries[i].resource);
    }
    if (func_020355C4() == 0) APP_TASKMENU_WIN_SetActive(*(struct Obj **)(p + *(u8 *)*(char * *)&((struct Obj01596 *)p)->f0 * 4 + 0xc), 1);
}



void func_021BB4F8(char *a0) { sub_02041B6C(4); }



void func_021BB504(char *p) { func_021BB50C(p); }



void func_021BB50C(char *p) { u8 i; PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj26253 *)(*(char * *)&((struct Obj14809 *)p)->f4))->f14); for(i=0;i<2;i++) APP_TASKMENU_WIN_Delete(*(u8 **)(p+i*4+12)); APP_TASKMENU_RES_Delete(*(struct TaskMenuState * *)&((struct Obj14809 *)p)->f8); sub_02041B6C(5); }



/*
 * Lever: unhinted BF9C data uses this function's own overlay region.
 */
int func_021BB53C(char *p)
{
    int hit=TOUCHPANEL_HitTrg(d_021BBF9C);
    if(func_020355C4()==0) {
        if(hit>=0 && hit<=1) {
            func_020355D8(1);
            APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),0);
        }
    } else {
        if(KEY_GetTrg()!=0 && !(KEY_GetTrg()&0x402)) {
            func_020355D8(0);
            APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            return 0;
        }
    }
    if(func_020355C4()==0) {
        if(KEY_GetTrg()&1) {
            APP_TASKMENU_WIN_SetDecide(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            return 1;
        } else if(KEY_GetRepeat()&0x40) {
            APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),0);
            if(**(u8 * *)&((struct Obj00740 *)p)->f0==0) **(u8 * *)&((struct Obj00740 *)p)->f0=1; else **(u8 * *)&((struct Obj00740 *)p)->f0=0;
            APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
            GFL_USE_PlaySeDefaultVolume(0x548);
        } else if(KEY_GetRepeat()&0x80) {
            APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),0);
            if(**(u8 * *)&((struct Obj00740 *)p)->f0==1) **(u8 * *)&((struct Obj00740 *)p)->f0=0; else **(u8 * *)&((struct Obj00740 *)p)->f0=1;
            APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
            GFL_USE_PlaySeDefaultVolume(0x548);
        } else if(KEY_GetRepeat()&0x220) {
            if(**(u8 * *)&((struct Obj00740 *)p)->f0==1) {
                APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),0);
                **(u8 * *)&((struct Obj00740 *)p)->f0=0;
                APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
        } else if(KEY_GetRepeat()&0x110) {
            if(**(u8 * *)&((struct Obj00740 *)p)->f0==0) {
                APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),0);
                **(u8 * *)&((struct Obj00740 *)p)->f0=1;
                APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
        }
    } else if(hit>=0 && hit<=1) {
        **(u8 * *)&((struct Obj00740 *)p)->f0=hit;
        APP_TASKMENU_WIN_SetActive(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
        APP_TASKMENU_WIN_SetDecide(*(void **)(p+**(u8 * *)&((struct Obj00740 *)p)->f0*4+0xc),1);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return 1;
    }
    return 0;
}
