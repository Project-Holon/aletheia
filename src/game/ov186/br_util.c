/*
 * file:     br_util.c
 * unit:     yes
 * function: func_021FC6A4, func_021FC734, func_021FC754, func_021FC7C4, func_021FC830, func_021FC868, func_021FC870, func_021FC8C8, func_021FCC80, func_021FCD0C, func_021FCDA0, func_021FCDA8, func_021FCDAC, func_021FCDE8, func_021FCE0C, func_021FCE60, func_021FCEDC, func_021FCF54, func_021FCF90, func_021FCFE0,func_021FD094,func_021FD0A8, func_021FD0B8, func_021FD110, func_021FD12C, func_021FD15C, func_021FD170, func_021FD19C, func_021FD1BC, func_021FD1C4, func_021FD640, func_021FD6B0, func_021FD6D8, func_021FD714, func_021FD71C, func_021FD72C, func_021FD73C, func_021FD744, func_021FD750, func_021FD760, func_021FD820, func_021FD854, func_021FD860, func_021FD938, func_021FD940, func_021FD964, func_021FD9A0, func_021FDA7C, func_021FDBF4, func_021FDE88, func_021FDF40, func_021FDFF4, func_021FE1C4, func_021FE2BC, func_021FE2F8, func_021FE3B4, func_021FE3E4, func_021FE444, func_021FE478, func_021FE4D8, func_021FE54C, func_021FE6C0, func_021FE734, func_021FE768, func_021FE784, func_021FE794, func_021FE7B0, func_021FE7B4, func_021FE7F4, func_021FE7F8, func_021FE840, func_021FE8E8, func_021FE90C, func_021FE970, func_021FE9D4, func_021FEB1C, func_021FEC14, func_021FED08, func_021FED50, func_021FEDC4, func_021FEE00, func_021FEE24, func_021FEE4C, func_021FEE74, func_021FEE9C, func_021FEEC0
 * address:  0x021FC6A4
 * region:   ov186
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
 *   MI_CpuFill8 0x02082BCC arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   d_02200D5C 0x02200D5C data a1
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Copy 0x02045838 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_GetWidth 0x020437DC arm
 *   BMP_GetHeight 0x020437E4 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   func_02034714 0x02034714 arm
 *   func_02041B6C 0x02041B6C arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BMP_Create 0x02043678 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   d_02200D68 0x02200D68 data a4
 *   d_02200B0C 0x02200B0C data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   BMP_Delete 0x020437AC arm
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   GFL_USE_IsSeqPlaying 0x02006254 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   d_02200AF0 0x02200AF0 data a4
 *   BMP_GetPixels 0x020437D4 arm
 *   func_02082A90 0x02082A90 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FBDA4  0x021FBDA4  thumb  ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FC21C 0x021FC21C thumb ov186
 *   PMS_DRAW_Create 0x0202DB0C thumb
 *   PMS_DRAW_SetDecoPriority 0x0202DCFC thumb
 *   PMS_DRAW_SetNullColorPalette 0x0202DE5C thumb
 *   PMS_DRAW_SetPrintColor 0x0202DE64 thumb
 *   PMS_DRAW_PrintOffset 0x0202DC60 thumb
 *   GDS_PROFILE_CreateNameStr 0x0200D6D0 thumb
 *   func_0200D6EC 0x0200D6EC thumb
 *   func_0200D6FC 0x0200D6FC thumb
 *   func_0200D70C 0x0200D70C thumb
 *   func_0200D72C 0x0200D72C thumb
 *   func_0200D73C 0x0200D73C thumb
 *   func_0200D74C 0x0200D74C thumb
 *   func_0200D760 0x0200D760 thumb
 *   func_0200D774 0x0200D774 thumb
 *   func_0200D810 0x0200D810 thumb
 *   func_0200D820 0x0200D820 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Clone 0x02045874 arm
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201F230 0x0201F230 thumb
 *   func_0201F048 0x0201F048 thumb
 *   func_0201F094 0x0201F094 thumb
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   d_02200B34 0x02200B34 data a4
 *   d_02200B6C 0x02200B6C data a4
 *   d_02200AFC 0x02200AFC data a1
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   PMS_DRAW_Delete 0x0202DC08 thumb
 *   PMS_DRAW_Main 0x0202DBC4 thumb
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   d_02200AD0 0x02200AD0 data a4
 *   d_02200AE8 0x02200AE8 data a4
 *   d_02200AD8 0x02200AD8 data a4
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   func_0207CBD0 0x0207CBD0 arm
 *   func_0207C768 0x0207C768 arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   d_02200D6C 0x02200D6C data a1
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_BlendChannelMask 0x02022004 thumb
 *   PALANM_RequestFullTransfer 0x02021F08 thumb
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   func_0207D63C 0x0207D63C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   PALANM_LoadHandlePaletteToSlotAt 0x02021660 thumb
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   FADE_GetSpeed 0x0204E6E0 arm
 *   func_0209C0A4 0x0209C0A4 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021FEEF4 0x021FEEF4 thumb ov186
 *   d_02200D78 0x02200D78 data a1
 *   d_02200B74 0x02200B74 data a4
 *   func_021FF028 0x021FF028 thumb ov186
 *   func_021FF004 0x021FF004 thumb ov186
 *   func_021FF01C 0x021FF01C thumb ov186
 *   func_021FF038 0x021FF038 thumb ov186
 *   func_021FF074 0x021FF074 thumb ov186
 *   func_021FF02C 0x021FF02C thumb ov186
 */
#include "../../matched/include/Obj02901.h"
#include "../../matched/include/Obj10791.h"
#include "../../matched/include/Obj02902.h"
#include "../../matched/include/Obj02903.h"
#include "../../matched/include/Obj05502.h"
#include "../../matched/include/Obj10792.h"
#include "../../matched/include/Obj01571.h"
#include "../../matched/include/Obj00048.h"
#include "../../matched/include/Obj24838.h"
#include "../../matched/include/Obj24839.h"
#include "../../matched/include/Obj08332.h"
#include "../../matched/include/Obj05503.h"
#include "../../matched/include/Obj01283.h"
#include "../../matched/include/Obj14466.h"
#include "../../matched/include/Obj24840.h"
#include "../../matched/include/Obj05504.h"
#include "../../matched/include/Obj08333.h"
#include "../../matched/include/Obj24841.h"
#include "../../matched/include/Obj14467.h"
#include "../../matched/include/Obj10793.h"
#include "../../matched/include/Obj24845.h"
#include "../../matched/include/Obj02236.h"
#include "../../matched/include/Obj24846.h"
#include "../../matched/include/Obj24847.h"
#include "../../matched/include/Obj06632.h"
#include "../../matched/include/Obj01284.h"
#include "../../matched/include/Obj10797.h"
#include "../../matched/include/Obj02904.h"
#include "../../matched/include/Obj06634.h"
#include "../../matched/include/Obj05506.h"
#include "../../matched/include/Obj24849.h"
#include "../../matched/include/Obj05507.h"
#include "../../matched/include/Obj24850.h"
#include "../../matched/include/Obj01285.h"
#include "../../matched/include/Obj01426.h"

struct CharBuf;
struct Descriptor;
struct Cfg;
struct U16Vec;
struct MsgBank;
struct PrintSys;
struct Bmp;
struct StrObj;
struct Actor;
struct Obj;
struct Obj020437AC;
struct GdsProfile;
struct GdsRecord;
struct Obj0202DCC4;
struct PmsDraw;
struct RecGet;
struct WordSet;
struct Obj02021EE4;
struct PalAnmSlot;
struct Obj02021F08;
struct S02021D50;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct {int x,y;} Pair;

typedef struct {int x,y,z;} Triple;

typedef struct {u16 x,y,id;u8 flag,pad;} Request;

typedef struct {void *text;int id;} Item;

typedef struct {Item *list;u32 count;u8 x,y,width,height,palette,bg,spacing,pad;int mode;char *resources;u32 manager,cursor,other;u16 *selection;} Config;

typedef struct {u8 top,bottom,left,right;} Area;

typedef struct {Config cfg;u32 handles[4],descriptor;u16 selected,last,index,start,visible;u8 pad46[7],scroll,pad4e[2];void (*methods[3])(void);Area areas[10];u8 pad84[8];void *bitmaps[];} View_021FC6A4;

typedef struct {char pad[0x8C];int bitmap[1];} View_021FCDA0;

typedef struct {u32 x,y;} Pair_021FD110;

typedef struct {u16 x,y,z,w;} Req;

typedef struct {u8 x,y,w,h;u32 msg;} Ent;

typedef signed int     s32;

typedef void (*Callback)(u8 *,int *,u32);

typedef signed char s8;

typedef signed short s16;

typedef struct {char pad[0xC];int index;int task;char *resources;char pad18[0x1E0];int handles[12];} Handles;

typedef struct {short x,y;} ShortPair;

typedef struct {int x,y;char pad8[4];int heap;int *task;char pad14[4];char record[6][32];char padD8[0x120];void *handles[12];int timer;} Motion_021FD714;

typedef struct {int x,y;char pad8[4];int heap;int *task;char pad14[4];char record[12][32];Pair positions[12];void *handles[12];int timer,flag,done[12];} Motion_021FDA7C;

typedef struct {Pair first,second,third;} Table;

typedef struct {int x,y;char pad8[4];int heap;int *task;char pad14[4];char record[12][32];Pair positions[12];void *handles[12];int timer,flag,done[12];} Motion;

typedef struct {int x,y;char pad8[4];int heap;char pad10[8];char record[6][32];char padD8[0x120];int handles[12];int timer;} Motion_021FDE88;

typedef struct {int x,y;int target;int heap;char pad10[8];char record[6][32];char padD8[0xC0];int positions[12][2];void *handles[12];int timer;} Motion_021FDFF4;

typedef struct {long x,y,z;} VecFx32;

typedef struct {
    int  f0;
    char pad8[8];
    char at_c[0x10];
    int  f1c;
} S;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,int,unsigned);
extern void *STRBUF_Create(unsigned,unsigned short);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_020307B0(void *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Copy(struct U16Vec *dst, struct U16Vec *src);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern u16 BMP_GetHeight(const struct Bmp *bmp);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void func_02034714(const char *,u32,const char *);
extern void func_02041B6C(u32);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, int heap);
extern void CLACT_SetActorAutoAnim(struct Obj *,u32);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern void PRINTSYS_PrintColor(void *,short,short,void *,void *,u16);
extern void func_021FBE54(char *,u32,u32);
extern int func_021FC124(char *,int,Triple *);
extern unsigned func_021FC20C(char *p);
extern void CLACT_DeleteActor(struct Obj *p);
extern void BMP_Delete(struct Obj020437AC *p);
extern void func_021FC0C8(char *p, unsigned i);
extern int GFL_USE_IsSeqPlaying(u32 a);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int TOUCHPANEL_HitCont(const void *);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void func_02082A90(void *,const void *,unsigned);
extern int TOUCHPANEL_HitTrg(const void *);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void func_021FBDA4(int a, unsigned mode);
extern int func_021FC214(char *);
extern int func_021FC21C(char *p);
extern struct PmsDraw *PMS_DRAW_Create(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
extern void PMS_DRAW_SetDecoPriority(struct Obj0202DCC4 *p, u32 i, u32 val);
extern void PMS_DRAW_SetNullColorPalette(struct PmsDraw *p, u8 v);
extern void PMS_DRAW_SetPrintColor(struct PmsDraw *p, u16 v);
extern void PMS_DRAW_PrintOffset(struct Obj *p, u32 a, void *w, u32 i, u32 e);
extern void *GDS_PROFILE_CreateNameStr(const void *,u32);
extern u32 func_0200D6EC(struct RecGet *p);
extern u32 func_0200D6FC(struct RecGet *p);
extern u32 func_0200D70C(struct RecGet *p);
extern u32 func_0200D72C(struct RecGet *p);
extern u32 func_0200D73C(struct RecGet *p);
extern u32 func_0200D74C(struct GdsProfile *p);
extern u32 func_0200D760(struct GdsProfile *p);
extern u32 func_0200D810(struct GdsProfile *p);
extern u32 func_0200D820(struct GdsProfile *p);
extern void *func_0200D774(struct GdsProfile *p, struct GdsRecord *out, u32 tag);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Clone(struct U16Vec *src, u32 heapId);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201F230(struct WordSet *p, u32 i, u32 v);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void *func_020490F4(u32,u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern int func_0201BC3C(void);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern u32 POKE_TOOL_CalcGraphicIndex(u32,u32,u32,u32);
extern u32 POKE_TOOL_CalcIconPalette(u32,u32,u32,u32);
extern int CLACT_RegisterPaletteCompressed(void *,u32,u32,u32,u16);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern int CLACT_RegisterPaletteEx(void *,u32,u32,u32,u16,u16,u16);
extern void *CLACT_SetActorPaletteOffset(void *,u32,u32);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void PMS_DRAW_Delete(struct Obj *p);
extern void PMS_DRAW_Main(u8 *);
extern void CLACT_SetActorAnimSeq(struct Obj *,u16);
extern void CLACT_AddActorSurfacePos(void *,const ShortPair *,u16);
extern long func_0207CBD0(const VecFx32 *);
extern u32 func_0207C768(u32,u32);
extern void *PALANM_Create(unsigned);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *,u32);
extern void PALANM_Delete(void *);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void PALANM_BlendChannelMask(unsigned, unsigned, unsigned short, unsigned, unsigned);
extern void PALANM_RequestFullTransfer(struct Obj02021F08 *o, int v);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern void func_0207D63C(unsigned, int, int, int, int);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void PALANM_LoadHandlePaletteToSlotAt(struct PalAnmSlot *,void *,u32,u32,u32,u32,u16,u16);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern int FADE_GetSpeed(void);
extern int func_0209C0A4(int,int);
extern u32 _u32_div_f(u32,u32);
extern void func_021FEEF4(char *, int, char *, const char *, unsigned);
extern int func_021FF028(u32 *p);
extern void func_021FF004(char *);
extern void func_021FF01C(char *);
extern void func_021FF038(char *,u32);
extern void func_021FF074(char *);
extern void func_021FF02C(u8 *p, u32 v);
void *func_021FC6A4(unsigned short plane,unsigned a,unsigned short b,unsigned short c,unsigned char d,unsigned char e,void *owner,unsigned short heap);
void func_021FC734(u8*p);
void func_021FC754(char *p,void *a,void *b,void *font,unsigned short value);
void func_021FC7C4(char *p,void *text,void *font,unsigned short value);
int func_021FC830(u8*p);
void func_021FC868(u8*p,u32 a,u32 b,u32 c);
void func_021FC870(int mode,Pair *base,const void *bmp,void *text,void *font,Pair *out);
View_021FC6A4 *func_021FC8C8(const Config *cfg,u16 heap);
void func_021FCC80(char *p);
void func_021FCD0C(char *p);
int func_021FCDA0(char *p);
int func_021FCDA8(char *p);
void func_021FCDAC(u8 *p, u16 i, u32 v);
u32 func_021FCDE8(u8 *p, u16 i);
int func_021FCE0C(char *p,unsigned field);
void func_021FCE50(char *p);
void func_021FCE60(char *p,int start);
int func_021FCEDC(char *p);
void func_021FCF54(int dest,int src,int dx,int dy,unsigned short sx,unsigned short sy,unsigned short width,unsigned short height);
int func_021FCF90(char *p,int change);
int func_021FCFE0(char *p,int step);
int func_021FD094(char *p);
int func_021FD0A8(char *p);
void func_021FD0B8(char *p);
void func_021FD110(char *p);
void *func_021FD12C(int a,void *owner,u16 heap);
void func_021FD15C(void *p, int a1);
void func_021FD170(char *p,char *q,void *text);
void func_021FD19C(char *p,void *q,void *text);
void func_021FD1BC(void *p);
char *func_021FD1C4(void *prof,char *q,void *a2,void *a3,int mode,u16 heap);
void func_021FD640(int *p);
int func_021FD6B0(u8 *p);
int *func_021FD6D8(int payload,int callback,u32 heap);
void func_021FD714(void *p);
void func_021FD71C(u8 *p);
int func_021FD72C(int *p);
int *func_021FD73C(int *p, int v);
int func_021FD744(int *a);
int func_021FD750(int *p, int v);
char *func_021FD760(unsigned owner,char *resources,int index,int heap);
void func_021FD820(char *r5);
void func_021FD854(char *p);
void func_021FD860(char *p,u32 mode,const Pair *pair);
int func_021FD938(char *p);
void func_021FD940(u8 *p,u32 value);
void func_021FD964(void *unused,int *state,u8 *p);
void func_021FD9A0(int unused,int *state,Motion_021FD714 *p);
void func_021FDA7C(int unused,int *state,Motion_021FDA7C *p);
void func_021FDBF4(int unused,int *state,Motion *p);
void func_021FDE88(int unused,int *state,Motion_021FDE88 *p);
void func_021FDF40(int unused,int *state,Motion_021FDE88 *p);
void func_021FDFF0(void);
void func_021FDFF4(int *obj,int *state,Motion_021FDFF4 *p);
void func_021FE1C4(int *task,int *state,char *p);
int func_021FE2BC(u8 *p,const Pair *origin,u16 a,u16 b,u16 c,u16 d,int duration);
int func_021FE2F8(char *p, int *out, int step);
int func_021FE3B4(u8 *p,const Pair *origin,u16 a,u16 b,int duration);
int func_021FE3E4(char *p, int *out, int step);
void func_021FE444(int *p,const Pair *a,const Pair *b,int c,int d);
int func_021FE478(int *p, Pair *out, int step);
void func_021FE4D8(int *p, int a, const int *values, int duration);
int func_021FE54C(char *p,int *out);
int *func_021FE6C0(unsigned heap);
void func_021FE734(char *p);
void func_021FE768(S *p);
void func_021FE784(int a, int b, int c, int d);
void func_021FE794(char *p,u32 index,u32 a,u32 b,u32 c);
int func_021FE7B0(int *p);
void func_021FE7B4(char *p);
void func_021FE7F4(char *p,u16 value);
void func_021FE7F8(char *p, int mask);
void func_021FE840(int unused, int mask, int value);
void func_021FE8E8(char *p,void *arc,u32 file,u32 idx,u32 off,u32 count,u16 tag);
int func_021FE90C(u32 *p, u32 *state);
int func_021FE970(u32 *p, u32 *state);
int func_021FE9D4(char *p,int *state);
int func_021FEB1C(char *p,int *state);
int func_021FEC14(char *p,int *state);
void *func_021FED08(unsigned index);
char *func_021FED50(int a, int unused, char *resources, unsigned heap);
void func_021FEDC4(char *p,char *ctx);
void func_021FEE00(char *p);
void func_021FEE24(char *p);
void func_021FEE4C(char *p);
void func_021FEE74(char *p);
void func_021FEE9C(char *p);
void func_021FEEC0(char *p,int mode,u32 value);
extern const char d_02200D5C[];
extern const char d_02200D68[];
extern const Pair d_02200B0C[];
extern const char d_02200AF0[];
extern const Ent d_02200B34[];
extern const Pair_021FD110 d_02200B6C;
extern const u8 d_02200AFC[];
extern const Table d_02200AD0;
extern const Table d_02200AE8;
extern const u32 d_02200AD8[];
extern const short FX_SinCosTable_[];
extern const char d_02200D6C[];
extern const char d_02200D78[];
extern const char d_02200B74[];







void *func_021FC6A4(unsigned short plane,unsigned a,unsigned short b,unsigned short c,unsigned char d,unsigned char e,void *owner,unsigned short heap)
{
    char *p;
    void *bmp;
    p=func_02030734(heap,0x24,0,d_02200D5C,0x5f);
    MI_CpuFill8(p,0,0x24);
    ((struct Obj02901 *)p)->f14=0;
    ((struct Obj02901 *)p)->f8=owner;
    ((struct Obj02901 *)p)->f16=plane;
    ((struct Obj02901 *)p)->f10=STRBUF_Create(0xff,heap);
    bmp=(void *)BMP_WIN_Create((unsigned char)plane,a,b,c,d,e,1);
    ((struct Obj02901 *)p)->fC=bmp;
    ((struct Obj02901 *)p)->f0=bmp;
    p[4]=0;
    BMP_Clear(BMP_WIN_GetBmp(bmp),((struct Obj02901 *)p)->f14);
    bmp=((struct Obj02901 *)p)->fC;
    BMP_WIN_TransferChars(bmp);
    BMP_WIN_MakeScreen(bmp);
    func_020409B4(BMP_WIN_GetBgLayer(bmp));
    return p;
}







void func_021FC734(u8*p){BMP_WIN_ClearScreen(*(void* *)&((struct Obj10791 *)p)->fC);BMP_WIN_Delete(*(void* *)&((struct Obj10791 *)p)->fC);STRBUF_Delete(*(void* *)&((struct Obj10791 *)p)->f10);func_020307B0(p);}







void func_021FC754(char *p,void *a,void *b,void *font,unsigned short value)
{
    Pair xy;
    void *owner;
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj02902 *)p)->fC),((struct Obj02902 *)p)->f14);
    func_02045CAC(a,(u32)b,((struct Obj02902 *)p)->f10);
    func_021FC870(((struct Obj02902 *)p)->f18, (Pair *)(p+28), BMP_WIN_GetBmp(((struct Obj02902 *)p)->fC), ((struct Obj02902 *)p)->f10, font, (Pair *)&xy);
    owner=((struct Obj02902 *)p)->f8;
    PRINTSYS_PrintQueColor(owner,(u32)BMP_WIN_GetBmp(((struct Obj02902 *)p)->f0),(short)xy.x,(short)xy.y,(u32)(((struct Obj02902 *)p)->f10),(u32)font,value);
    p[4]=1;
}







void func_021FC7C4(char *p,void *text,void *font,unsigned short value)
{
    Pair xy;
    void *owner;
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj02903 *)p)->fC),((struct Obj02903 *)p)->f14);
    STRBUF_Copy(((struct Obj02903 *)p)->f10,text);
    func_021FC870(((struct Obj02903 *)p)->f18, (Pair *)(p+28), BMP_WIN_GetBmp(((struct Obj02903 *)p)->fC), ((struct Obj02903 *)p)->f10, font, (Pair *)&xy);
    owner=((struct Obj02903 *)p)->f8;
    PRINTSYS_PrintQueColor(owner,(u32)BMP_WIN_GetBmp(((struct Obj02903 *)p)->f0),(short)xy.x,(short)xy.y,(u32)(((struct Obj02903 *)p)->f10),(u32)font,value);
    p[4]=1;
}







int func_021FC830(u8*p){void*owner=*(void* *)&((struct Obj05502 *)p)->f8;if(p[4]){if(!PRINTSYS_QUE_IsExistTarget(owner,BMP_WIN_GetBmp(*(void* *)&((struct Obj05502 *)p)->f0))){BMP_WIN_TransferChars(*(void* *)&((struct Obj05502 *)p)->f0);p[4]=0;}}if(!p[4])return 1;return 0;}








void func_021FC868(u8*p,u32 a,u32 b,u32 c){((struct Obj10792 *)p)->f18=c;((struct Obj10792 *)p)->f1C=a;((struct Obj10792 *)p)->f20=b;}







/*
 * extent: two zero alignment bytes follow the 86-byte function.
 */
void func_021FC870(int mode,Pair *base,const void *bmp,void *text,void *font,Pair *out)
{
    unsigned x,y;
    switch(mode) {
    case 0:*out=*base;break;
    case 1:
        x=(unsigned)BMP_GetWidth(bmp)>>1;y=(unsigned)BMP_GetHeight(bmp)>>1;
        x-=func_0201D304(text,(unsigned)font,0)>>1;
        y-=func_0201D42C(text,font)>>1;
        out->x=x+base->x;out->y=y+base->y;break;
    }
}





/*
 * lever: u16 heap and const Config pointer restore scheduling; bounded permuter count-before-limit restores the clamp registers. Resource before font gives the original spill slots.
 */
View_021FC6A4 *func_021FC8C8(const Config *cfg,u16 heap)
{
    Triple arrows,marks;
    Request arrow,mark;
    View_021FC6A4 *p;
    int size,mode,count;
    int limit;
    u16 resource;
    int font;
    int i;
    size=cfg->count*4+0x8c;
    p=func_02030734(heap,size,0,d_02200D5C,0x1a1);
    MI_CpuFill8(p,0,size);
    p->cfg=*cfg;
    p->selected=0;p->last=cfg->count;
    p->visible=cfg->height/cfg->spacing;
    count=cfg->count;
    limit=p->visible;
    if((int)limit>count) limit=count;
    p->visible=limit;
    if(cfg->selection) {p->start=cfg->selection[0];p->index=cfg->selection[1];}
    if(p->cfg.mode==0) {
        for(i=0;i<p->visible;i++) {
            if(i>=10) func_02034714(d_02200D68,0,d_02200D68);
            p->areas[i].left=p->cfg.x*8;
            p->areas[i].top=(p->cfg.y+i*p->cfg.spacing)*8;
            p->areas[i].right=(p->cfg.x+p->cfg.width)*8;
            p->areas[i].bottom=(p->cfg.y+(i+1)*p->cfg.spacing)*8;
        }
        if(i>=10) func_02034714(d_02200D68,0,d_02200D68);
        p->areas[i].left=255;p->areas[i].top=255;p->areas[i].right=255;p->areas[i].bottom=255;
        p->methods[0]=(void (*)(void))func_021FCF90;p->methods[1]=(void (*)(void))func_021FD094;p->methods[2]=(void (*)(void))func_021FD0B8;
    } else if(p->cfg.mode==1) {
        p->methods[0]=(void (*)(void))func_021FCFE0;p->methods[1]=(void (*)(void))func_021FD0A8;p->methods[2]=(void (*)(void))func_021FD110;
        if(p->cfg.cursor) func_021FD860((char *)p->cfg.cursor,5,&d_02200B0C[p->index]);
    }
    p->descriptor=BMP_WIN_Create(cfg->bg,cfg->x,cfg->y,cfg->width,cfg->height,cfg->palette,1);
    BMP_WIN_MakeScreen((struct Cfg *)p->descriptor);
    func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)p->descriptor));
    i=0;
    MI_CpuFill8(&arrow,0,8);
    if(cfg->bg<4) {
        func_021FBE54(p->cfg.resources,7,heap);
        if(!func_021FC124(p->cfg.resources,7,&arrows)) func_02034714(d_02200D68,0,d_02200D68);
        mode=0;
    } else {
        func_021FBE54(p->cfg.resources,8,heap);
        if(!func_021FC124(p->cfg.resources,8,&arrows)) func_02034714(d_02200D68,0,d_02200D68);
        mode=1;
    }
    arrow.x=128;arrow.flag=0;
    i=0;
    resource=mode;
    for(;i<2;i++) {
        if(cfg->mode==0) arrow.y=i==0?16:128;
        else arrow.y=i==0?64:184;
        arrow.id=i;
        p->handles[i]=(u32)CLACT_CreateActor((void *)cfg->manager,arrows.y,arrows.z,arrows.x,&arrow,resource,heap);
        CLACT_SetActorAutoAnim((struct Obj *)p->handles[i],1);CLACT_SetActorObjMode((struct Actor *)p->handles[i],1);
    }
    i=0;
    CLACT_SetActorDrawEnable((struct Obj *)p->handles[0],0);
    MI_CpuFill8(&mark,0,8);
    mark.y=72;mark.id=5;mark.flag=0;
    if(!func_021FC124(p->cfg.resources,6,&marks)) func_02034714(d_02200D68,0,d_02200D68);
    for(i=2;i<4;i++) {
        mark.x=i==2?24:232;
        p->handles[i]=(u32)CLACT_CreateActor((void *)p->cfg.manager,marks.y,marks.z,marks.x,&mark,1,heap);
        CLACT_SetActorObjMode((struct Actor *)p->handles[i],1);
    }
    font=func_021FC20C(p->cfg.resources);
    for(i=0;(u32)i<p->cfg.count;i++) {
        void *text;
        text=p->cfg.list[i].text;
        if(text) {
            p->bitmaps[i]=BMP_Create(p->cfg.width,p->cfg.spacing,32,heap);
            BMP_Clear(p->bitmaps[i],0);
            PRINTSYS_PrintColor(p->bitmaps[i],0,0,text,(void *)font,0x3da0);
        }
    }
    func_021FCE60((char *)p,p->start);
    if(cfg->count<p->visible) {
        p->scroll=0;CLACT_SetActorDrawEnable((struct Obj *)p->handles[0],0);CLACT_SetActorDrawEnable((struct Obj *)p->handles[1],0);
    } else {
        p->scroll=1;
        if(p->scroll) {
            if(p->start==0) CLACT_SetActorDrawEnable((struct Obj *)p->handles[0],0);
            else CLACT_SetActorDrawEnable((struct Obj *)p->handles[0],1);
            if(p->cfg.count==p->start+p->visible) CLACT_SetActorDrawEnable((struct Obj *)p->handles[1],0);
            else CLACT_SetActorDrawEnable((struct Obj *)p->handles[1],1);
        }
    }
    if(func_021FCDA0((char *)p)) for(i=2;i<4;i++) CLACT_SetActorAutoAnim((struct Obj *)p->handles[i],1);
    return p;
}





void func_021FCC80(char *p)
{
    int i;
    if(((struct Obj01571 *)p)->f1C) func_021FD860((char *)((struct Obj01571 *)p)->f1C,0,0);
    for(i=0;i<4;i++) CLACT_DeleteActor((struct Obj *)(*(int *)(p+0x28+i*4)));
    for(i=0;(unsigned)i<((struct Obj01571 *)p)->f4;i++) {
        if(*(int *)(p+0x8C+i*4) && *(int *)(((struct Obj01571 *)p)->f0+i*8)) BMP_Delete((struct Obj020437AC *)(*(int *)(p+0x8C+i*4)));
    }
    BMP_WIN_ClearScreen((struct Descriptor *)(((struct Obj01571 *)p)->f38));BMP_WIN_Delete((struct Descriptor *)(((struct Obj01571 *)p)->f38));
    if(((struct Obj01571 *)p)->fD<4) func_021FC0C8((char *)(((struct Obj01571 *)p)->f14),7);
    else func_021FC0C8((char *)(((struct Obj01571 *)p)->f14),8);
    if(((struct Obj01571 *)p)->f24) {
        *(unsigned short *)(((struct Obj01571 *)p)->f24)=((struct Obj01571 *)p)->f42;
        *(unsigned short *)(((struct Obj01571 *)p)->f24+2)=((struct Obj01571 *)p)->f40;
    }
    func_020307B0(p);
}





void func_021FCD0C(char *p)
{
    if(func_021FCDA0(p)) {
        ((struct Obj00048 *)p)->f4C=func_021FCEDC(p);
        if(((struct Obj00048 *)p)->f4C) {
            if(((int (*)(char *,int))*(int *)(p+0x50))(p,((struct Obj00048 *)p)->f4C)) {
                if(GFL_USE_IsSeqPlaying(0x6FE)==0) GFL_USE_PlaySeDefaultVolume(0x6FE);
                func_021FCE60(p,((struct Obj00048 *)p)->f42);
            }
            if(((struct Obj00048 *)p)->f4D) {
                if(((struct Obj00048 *)p)->f42==0) CLACT_SetActorDrawEnable((struct Obj *)*(int *)&((struct Obj00048 *)p)->f28,0);
                else CLACT_SetActorDrawEnable((struct Obj *)*(int *)&((struct Obj00048 *)p)->f28,1);
                if(((struct Obj00048 *)p)->f4==((struct Obj00048 *)p)->f42+((struct Obj00048 *)p)->f44) CLACT_SetActorDrawEnable((struct Obj *)*(int *)&((struct Obj00048 *)p)->f2C,0);
                else CLACT_SetActorDrawEnable((struct Obj *)*(int *)&((struct Obj00048 *)p)->f2C,1);
            }
        }
    }
    ((void (*)(char *))*(int *)(p+0x58))(p);
}










int func_021FCDA0(char *p){return (*(int(**)(char *))(p+0x54))(p);}









/*
 * leaf: S27 parent clearance; ov183 callers DFFB0 and E024C sole blocker.
 */
int func_021FCDA8(char *p)
{
    return ((struct Obj24838 *)p)->f48;
}









void func_021FCDAC(u8 *p, u16 i, u32 v)
{
    if(i>=*(u32 *)(p+4))func_02034714(d_02200D68,0,d_02200D68);
    if(*(u32 *)(*(u32 *)p+i*8)!=0)func_02034714(d_02200D68,0,d_02200D68);
    *(u32 *)((u32)p+i*4+0x8c)=v;
}









u32 func_021FCDE8(u8 *p, u16 i)
{
    if(i>=((struct Obj24839 *)p)->f4)func_02034714(d_02200D68,0,d_02200D68);
    return *(u32 *)((u32)p+i*4+0x8c);
}









/*
 * extent: lead plus tail-call stub at 021FCE50.
 */
int func_021FCE0C(char *p,unsigned field)
{
    switch(field) {
    case 0:return ((struct Obj08332 *)p)->f40;
    case 1:return ((struct Obj08332 *)p)->f42;
    case 2:return ((struct Obj08332 *)p)->f4C;
    case 3:return ((struct Obj08332 *)p)->f4;
    default:func_02034714(d_02200D68,0,d_02200D68);return 0;
    }
}









void func_021FCE50(char *p)
{
    func_021FCE60(p,((struct Obj00048 *)p)->f42);
}









void func_021FCE60(char *p,int start)
{
    int i,height;
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)*(int *)&((struct Obj00048 *)p)->f38)),0);
    for(i=start;i<start+((struct Obj00048 *)p)->f44;i++) {
        if((unsigned)i<((struct Obj00048 *)p)->f4 && ((View_021FCDA0 *)p)->bitmap[i]) {
            height=((struct Obj00048 *)p)->fE;
            func_021FCF54(((View_021FCDA0 *)p)->bitmap[i],(int)BMP_WIN_GetBmp((struct Descriptor *)*(int *)&((struct Obj00048 *)p)->f38),0,0,0,(i-start)*height,((struct Obj00048 *)p)->fA,height);
        }
    }
    BMP_WIN_TransferChars((struct Descriptor *)*(int *)&((struct Obj00048 *)p)->f38);
}









int func_021FCEDC(char *p)
{
    int x,y;
    int direction=0;
    int delta,absolute;
    if(TOUCHPANEL_HitCont(d_02200AF0)!=-1) {
        TOUCHPANEL_GetPointCont((u32 *)(&x),(u32 *)(&y));
        if(((struct Obj00048 *)p)->f84==0) {((struct Obj00048 *)p)->f84=1;((struct Obj00048 *)p)->f88=y;}
        else {
            delta=y-((struct Obj00048 *)p)->f88;
            if(delta<0) absolute=-delta;else absolute=delta;
            if(absolute>8) {
                if(delta<0) direction=-1;else direction=1;
                ((struct Obj00048 *)p)->f88=y;
            }
        }
    } else if(((struct Obj00048 *)p)->f84) ((struct Obj00048 *)p)->f84=0;
    return direction;
}









/*
 * extent: 80-byte scrolling follower filed as ov186_func_021FCF90.c.
 * lever: width-first multiply preserves the stack load and register order.
 */
void func_021FCF54(int dest,int src,int dx,int dy,unsigned short sx,unsigned short sy,unsigned short width,unsigned short height)
{
    char *d,*s;
    int doff,soff;
    d=BMP_GetPixels((const struct Bmp *)dest);s=BMP_GetPixels((const struct Bmp *)src);
    doff=width*dy+dx;
    soff=width*sy+sx;
    func_02082A90(d+doff*32,s+soff*32,width*height*32);
}







/*
 * follower: scroll range update after func_021FCF54.
 */
int func_021FCF90(char *p,int change)
{
    if(((struct Obj05503 *)p)->f42!=0 && change==-1) {
        ((struct Obj05503 *)p)->f42+=(unsigned short)change;
        return 1;
    }
    if(((struct Obj05503 *)p)->f42+((struct Obj05503 *)p)->f44<((struct Obj05503 *)p)->f4 && change==1) {
        ((struct Obj05503 *)p)->f42+=(unsigned short)change;
        return 1;
    }
    return 0;
}






/*
 * followers: unlabelled store-free accessors 021FD094 and 021FD0A8 included; final 2-byte alignment outside TU length.
 */
int func_021FCFE0(char *p,int step)
{
    int count,changed,half;
    count=((struct Obj01283 *)p)->f44;
    changed=0;
    half=(count-1)/2+(count-1)%2;
    if(step>0) {
        if(half==((struct Obj01283 *)p)->f40 && (u32)(((struct Obj01283 *)p)->f42+count)<((struct Obj01283 *)p)->f4) {
            ((struct Obj01283 *)p)->f42+=(u16)step;changed=1;
        } else if((u32)(((struct Obj01283 *)p)->f42+((struct Obj01283 *)p)->f40)<((struct Obj01283 *)p)->f4-1) {
            ((struct Obj01283 *)p)->f40+=(u16)step;changed=1;
        }
    } else if(step<0) {
        if(half==((struct Obj01283 *)p)->f40 && ((struct Obj01283 *)p)->f42) {
            ((struct Obj01283 *)p)->f42+=(u16)step;changed=1;
        } else if(((struct Obj01283 *)p)->f40) {
            ((struct Obj01283 *)p)->f40+=(u16)step;changed=1;
        }
    }
    if(changed && ((struct Obj01283 *)p)->f1C) func_021FD860((char *)((struct Obj01283 *)p)->f1C,5,&d_02200B0C[((struct Obj01283 *)p)->f40]);
    return changed;
}






int func_021FD094(char *p) { return ((struct Obj14466 *)p)->f4>=((struct Obj14466 *)p)->f44; }






int func_021FD0A8(char *p) { return ((struct Obj24840 *)p)->f4>1; }





/*
 * extent: accessor at 021FD110 filed separately, then two zero alignment bytes.
 */
void func_021FD0B8(char *p)
{
    int x,y;
    Pair pair;
    int result;
    ((struct Obj05504 *)p)->f48=-1;
    result=TOUCHPANEL_HitTrg(p+0x5C);
    if(result!=-1) {
        if(((struct Obj05504 *)p)->f20) {
            TOUCHPANEL_GetPointTrg((u32 *)(&x),(u32 *)(&y));pair.x=x;pair.y=y;
            func_021FD860((char *)((struct Obj05504 *)p)->f20, 1, (const Pair *)&pair);
        }
        GFL_USE_PlaySeDefaultVolume(0x703);
        ((struct Obj05504 *)p)->f48=((int *)(((struct Obj05504 *)p)->f0+(result+((struct Obj05504 *)p)->f42)*8))[1];
    }
}





/*
 * follower: accessor after func_021FD0B8; two alignment bytes after return.
 */
void func_021FD110(char *p)
{
    ((struct Obj08333 *)p)->f48=((int *)(((struct Obj08333 *)p)->f0+(((struct Obj08333 *)p)->f40+((struct Obj08333 *)p)->f42)*8))[1];
}





void *func_021FD12C(int a,void *owner,u16 heap)
{
    u8 *p;
    func_021FB964((void *)a,2,heap);
    p=func_021FC6A4(0,1,19,30,4,2,owner,heap);
    ((struct Obj02901 *)p)->f14=12;
    return p;
}






void func_021FD15C(void *p, int a1)
{
    func_021FC734(p);
    func_021FBDA4(a1, 2);
}





void func_021FD170(char *p,char *q,void *text)
{
    u32 font;
    font=func_021FC20C(q);
    func_021FC754(p,(void *)func_021FC214(q),text,(void *)font,0x3dac);
}





void func_021FD19C(char *p,void *q,void *text)
{
    func_021FC7C4(p,text,(void *)func_021FC20C(q),0x3dac);
}






/*
 * note: 2026-10-05 integrator: label left open after the pengy waves; written from the listing.
 */
void func_021FD1BC(void *p)
{
    func_021FC830(p);
}





/*
 * 2026-10-05 (wave P2, lane Q6, pengy share): first full draft, 1148 B,
 * same size as the original, 12 bytes differ. Constructor of the GDS
 * profile screen (pair of func_021FD640, the matched destructor): 0x44 B
 * object, 7 text windows from the 8-byte table d_02200B34 (switch on the
 * row: 0 name, 1 and 3 and 4 number rows, 6 optional record with a
 * fallback draw, 2 and 5 plain message), then an arc load that builds the
 * object at +0x24 when the profile has a icon and a second one at +0x28
 * chosen by mode (0, 1, other). The earlier layout residue is closed:
 * the table row is read as d_02200B34[i].f at every use (CSE gives the
 * r6 address), the pair constant d_02200B6C is read twice by initialiser
 * (Pair_021FD110 b = d at function level, Pair_021FD110 c = d in case 6, which gives the
 * hidden copy at [sp,#0x38]), the two position records are memset with
 * MI_CpuFill8(&r,0,8) then only x,y,z / x,y are stored, hf is a u32 so
 * the u16 truncation is repeated per call, mode is a switch.
 * Residue (12 B, two spots): (1) in the icon block the original builds the
 * z=1 store and the later CLACT_SetActorObjMode(obj,1) argument with separate
 * movs r1,#1; mine pools the 1 in r7 (movs r7,#1; strh r7; adds r1,r7,#0).
 * (2) in mode 0 the original schedules movs r7,#4 and movs r7,#6 before the
 * str of k2 (the [sp,#0x20] slot); mine stores first. Tried, no change:
 * store order z first (moves the pooled 1 earlier), scheduling off,
 * opt_lifetimes off. opt_common_subs off breaks the whole body. Not
 * tried: opt_propagation off, peephole off, opt_dead_assignments off.
 * Callee prototypes for the unlabelled arm9 getters func_0200D6FC,
 * 70C, 72C, 73C, 810, 820 are guessed (u32 f(void *)); func_0200D774
 * takes the 4-halfword record out pointer.
 *
 * 2026-10-05 (wave P2, lane Q6b): 12 B -> 4 B, and now compiles in --lang c
 * (Pair_021FD110 b moved into a block that wraps the row loop, Req r declared at the
 * top of its block). Residue (2) closed: assign k3 first in each mode-0 arm
 * (k3=4;k1=0x14;k2=0x12;k4=0x13; and k3=6;k1=0x17;...), which gives the
 * original's movs r7 before the str to [sp,#0x20]; k1,k3,k2,k4 also works.
 * Residue left (4 B, icon block): original `movs r1,#1; strh r1,[r0,#0x14]`
 * and later `movs r1,#1` for CLACT_SetActorObjMode(obj,1); mine pools the 1 in r7
 * (movs r7,#1; strh r7; adds r1,r7,#0). Pragmas opt_propagation off and
 * opt_dead_assignments off break the whole body (960+ B); peephole off: no
 * change. Tried, no change: B688 second parameter u8 or int; Req as
 * {short x,y,z;u8 a,b} (the ov183 021DCBD8 Position shape); z and the B688
 * argument spelled as an enum TRUE (each alone); z from a u16 local and the
 * argument from an int local; Req as u16 r[4]. In block 2 the same two 1s
 * (B6F4 arg and B688 arg, call between) are not pooled, so the pooling is
 * caused by the strh of a constant before the call; no source spelling found
 * that keeps the store value apart from the later argument.
 *
 * 2026-10-05 (wave P2, lane Q6c): still 4 B (same icon-block residue). New
 * tries, all unchanged (movs r7,#1; strh r7; adds r1,r7,#0): z=1 inside a
 * static inline SetPos(&r,x,y) (ov183 021DCBD8 shape); z and the B688 argument
 * both as enum BOOL TRUE; z as 1u; z as (u16)1; z stored between x and y;
 * B688 prototype unprototyped (K&R); object kept in a local `icon` (breaks
 * the body: the original reloads [r4,#0x24]); B688 (alone, or with B6F4) moved
 * into a second `if(B)` (the branch stays and B moves to r7, breaks layout);
 * one function-level Req shared by both blocks (moves the slots); pragmas
 * opt_lifetimes off and scheduling off on the current shape. z first moves the
 * pooled 1 to the top (as before). Reading: docs/idioms/a-repeated-constant-
 * pools-only-within-one-block-... says the pooler works per block, so the
 * original probably has a block boundary between the strh and the B688 call
 * that emits no branch; none found. In block 2 the same two 1s (both call
 * arguments, precoloured r2 and r1) do not pool, so only a store operand 1
 * followed by an argument 1 merges. Not tried: opt_common_subs off alone
 * (breaks the body per Q6).
 *
 * recoup 2026-10-05 (lane R10): still 4 B, same icon-block residue
 * (movs r7,#1; strh r7; adds r1,r7,#0 vs original movs r1,#1 twice). New
 * tries, all unchanged or worse: tail B6F4+B688 as a static inline (1152 B,
 * 326 off); opt_common_subs off alone (1176 B); z stored through
 * *(u16 *)((char *)&r+4) (4 B); z as *(u32 *)&r.z (5 B); B688 argument as
 * r.z (14 B); Req reached through a pointer rp (4 B); block locals declared
 * Req first, or Req then hf,h,t (4 B each); B688 second parameter u16, short
 * or char (4 B each). Matched twins read: ov183 021DF428 and 021DCBD8,
 * ov208 021C0B6C, ov206 021BB304 and 021BB534 (none has a strh of 1 before a
 * later literal 1 argument in one block). Reading: only a store operand 1
 * followed by an argument 1 merges, and no real source form splits them.
 *
 * final push 2026-10-05 G1L6: still 4 B (same icon-block residue). Research
 * first (idioms: repeated-constant-pools-only-within-one-block, repeated-small-
 * constant-takes-a-callee-saved-register, small-constant-is-rematerialised...,
 * store-stays-above-the-argument-constant, pool-constant-kept-live-past-a-join,
 * narrow-flag-local-is-spilled, sub-word-parameter-type..., one-element-array-
 * initialiser; twins ov183 021DCBD8/021DF428, ov206, ov208, ov218 021BA328:
 * none has a constant strh then a literal 1 argument in one block with a free
 * register). New tries, bytes off: aggregate initialiser `Req r={0x4b,0x40,1,0}`
 * (246 B: compiler copies the record from a pool table, no memset); do/while(0)
 * around B6F4+B688 (4); mid-function `#pragma opt_common_subs off` before the
 * if(B) (1093); B688 through a static inline SetVis(obj,v) or SetVis(obj) (4
 * each); stores through a static inline SetReq(&r,x,y,z) with int or u16
 * params (4 each); Req of short fields with B688 arg 1u (4); z as 1u with arg
 * -1+2 (4); keeping h live past the stores (ARC_TOOL_DeleteHandle moved after B688)
 * to test register pressure: still pooled (r6 instead of r7), so pressure is
 * not the cause; the whole icon block as a static inline MakeIcon (11 B, slots
 * move, still pooled). Conclusion unchanged: store operand 1 followed by an
 * argument 1 in one block always merges; no human source form found.
 *
 * final push 2026-10-05 G1R5: still 4 B (same icon-block residue). Control
 * test: B688 argument 2 instead of 1 gives 1 B off (only the constant), so
 * the merge is a plain value-number CSE of the two literal 1s, and with them
 * apart the whole block matches. New tries, all 4 B (movs r7,#1 pooled) unless
 * noted: Req stores and B294 in an inner block; function-level int vis=1 for
 * the argument, and for both z and argument; goto/label, switch(1), for(;;)
 * around B6F4+B688; z through a u16 *zp; B688 argument as (u8)1, (u16)1,
 * (char)1, (short)1, 1u, 1L, (u32)1, (unsigned long)1; per-function pragmas
 * opt_strength_reduction, opt_dead_code, opt_unroll_loops, opt_vectorize_loops,
 * optimize_for_size off (no change), opt_loop_invariants off (948 B off);
 * argument as B!=0, B>0, !!B, mode>=0 (real compares, 328+ B off); z stored
 * after B294 (42 B off, registers shift). Matched-assembly search (strh of a
 * fresh movs #1 followed later by a fresh movs #1 before a call): hits ov070
 * 021B6A14, 021B7688, 021B7CD0 (p->f83E = 1 then B92C(..,1), BB3F4(p,1)), plus
 * ov103/ov170/ov035 with no call-arg 1. ov070 021B6A14's C stores through a
 * pointer member and does not merge; our store goes to an address-taken stack
 * record and merges. No source form found that separates them.
 *
 * pass 2 2026-10-06 P2L06: still 4 B (same icon-block residue), form unchanged.
 * 40 compiles. Findings: compiler pins dsi/1.2 and 1.3 give the same 4 B, 1.6sp2
 * 7 lines, 2.0 1188 B. opt_common_subs off and optimization_level 3 keep the
 * merge (it is backend, not IRO CSE). Diagnostics: replacing BB5C(B,C,D,A) by
 * constants (or the B6F4 argument by 5) removes the merge, so it appears only
 * while the spilled A..D stay live across the icon tail; tiny repros never merge
 * the 1. Stores through a walking or indexed u16 pointer from &r.x also remove
 * the merge but use r6 as the base instead of sp+0x70 (60 lines off). Tried, all
 * 4 B: A..D as a local struct, a u32 info[4] array, an array with a call
 * initialiser, BB5C result in a local, one function-level h, declaration orders
 * of A..D and of the icon-block locals, z first, B294 stack arg changes.
 * Open lead: a form that keeps A..D in real memory (not spilled registers).
 *
 * pass 3 2026-10-06 P3L02: EXACT (c99 and c). The icon-block residue was the
 * callee declaration, not the block: CLACT_SetActorPaletteOffset declared `void *` (returns
 * its object) instead of `void`. With a void declaration r0 is dead after the
 * call and mwcc keeps the constant 1 in r7 across it (store z=1, later
 * CLACT_SetActorObjMode(obj,1)); with a value return it rebuilds `movs r1,#1` at each
 * use, as the image does (docs/idioms/a-callee-declared-void-that-returns-a-
 * value-changes-later-constant-copies.md). Evidence: the ARM body of
 * CLACT_SetActorPaletteOffset (src/matched/arm9/unit_0204B6F4.c, written there as void) never
 * writes r0, so it is byte-identical to a definition that ends `return o;`.
 * The integrator should know that the matched definition is spelled void.
 * Also: t inlined into the CLACT_RegisterCellAnim call (same bytes, one fewer local).
 */
/*
 * 2026-10-05 (wave P2, lane Q6, pengy share): first full draft, 1148 B,
 * same size as the original, 12 bytes differ. Constructor of the GDS
 * profile screen (pair of func_021FD640, the matched destructor): 0x44 B
 * object, 7 text windows from the 8-byte table d_02200B34 (switch on the
 * row: 0 name, 1 and 3 and 4 number rows, 6 optional record with a
 * fallback draw, 2 and 5 plain message), then an arc load that builds the
 * object at +0x24 when the profile has a icon and a second one at +0x28
 * chosen by mode (0, 1, other). The earlier layout residue is closed:
 * the table row is read as d_02200B34[i].f at every use (CSE gives the
 * r6 address), the pair constant d_02200B6C is read twice by initialiser
 * (Pair b = d at function level, Pair c = d in case 6, which gives the
 * hidden copy at [sp,#0x38]), the two position records are memset with
 * MI_CpuFill8(&r,0,8) then only x,y,z / x,y are stored, hf is a u32 so
 * the u16 truncation is repeated per call, mode is a switch.
 * Residue (12 B, two spots): (1) in the icon block the original builds the
 * z=1 store and the later CLACT_SetActorObjMode(obj,1) argument with separate
 * movs r1,#1; mine pools the 1 in r7 (movs r7,#1; strh r7; adds r1,r7,#0).
 * (2) in mode 0 the original schedules movs r7,#4 and movs r7,#6 before the
 * str of k2 (the [sp,#0x20] slot); mine stores first. Tried, no change:
 * store order z first (moves the pooled 1 earlier), scheduling off,
 * opt_lifetimes off. opt_common_subs off breaks the whole body. Not
 * tried: opt_propagation off, peephole off, opt_dead_assignments off.
 * Callee prototypes for the unlabelled arm9 getters func_0200D6FC,
 * 70C, 72C, 73C, 810, 820 are guessed (u32 f(void *)); func_0200D774
 * takes the 4-halfword record out pointer.
 *
 * 2026-10-05 (wave P2, lane Q6b): 12 B -> 4 B, and now compiles in --lang c
 * (Pair b moved into a block that wraps the row loop, Req r declared at the
 * top of its block). Residue (2) closed: assign k3 first in each mode-0 arm
 * (k3=4;k1=0x14;k2=0x12;k4=0x13; and k3=6;k1=0x17;...), which gives the
 * original's movs r7 before the str to [sp,#0x20]; k1,k3,k2,k4 also works.
 * Residue left (4 B, icon block): original `movs r1,#1; strh r1,[r0,#0x14]`
 * and later `movs r1,#1` for CLACT_SetActorObjMode(obj,1); mine pools the 1 in r7
 * (movs r7,#1; strh r7; adds r1,r7,#0). Pragmas opt_propagation off and
 * opt_dead_assignments off break the whole body (960+ B); peephole off: no
 * change. Tried, no change: B688 second parameter u8 or int; Req as
 * {short x,y,z;u8 a,b} (the ov183 021DCBD8 Position shape); z and the B688
 * argument spelled as an enum TRUE (each alone); z from a u16 local and the
 * argument from an int local; Req as u16 r[4]. In block 2 the same two 1s
 * (B6F4 arg and B688 arg, call between) are not pooled, so the pooling is
 * caused by the strh of a constant before the call; no source spelling found
 * that keeps the store value apart from the later argument.
 *
 * 2026-10-05 (wave P2, lane Q6c): still 4 B (same icon-block residue). New
 * tries, all unchanged (movs r7,#1; strh r7; adds r1,r7,#0): z=1 inside a
 * static inline SetPos(&r,x,y) (ov183 021DCBD8 shape); z and the B688 argument
 * both as enum BOOL TRUE; z as 1u; z as (u16)1; z stored between x and y;
 * B688 prototype unprototyped (K&R); object kept in a local `icon` (breaks
 * the body: the original reloads [r4,#0x24]); B688 (alone, or with B6F4) moved
 * into a second `if(B)` (the branch stays and B moves to r7, breaks layout);
 * one function-level Req shared by both blocks (moves the slots); pragmas
 * opt_lifetimes off and scheduling off on the current shape. z first moves the
 * pooled 1 to the top (as before). Reading: docs/idioms/a-repeated-constant-
 * pools-only-within-one-block-... says the pooler works per block, so the
 * original probably has a block boundary between the strh and the B688 call
 * that emits no branch; none found. In block 2 the same two 1s (both call
 * arguments, precoloured r2 and r1) do not pool, so only a store operand 1
 * followed by an argument 1 merges. Not tried: opt_common_subs off alone
 * (breaks the body per Q6).
 *
 * recoup 2026-10-05 (lane R10): still 4 B, same icon-block residue
 * (movs r7,#1; strh r7; adds r1,r7,#0 vs original movs r1,#1 twice). New
 * tries, all unchanged or worse: tail B6F4+B688 as a static inline (1152 B,
 * 326 off); opt_common_subs off alone (1176 B); z stored through
 * *(u16 *)((char *)&r+4) (4 B); z as *(u32 *)&r.z (5 B); B688 argument as
 * r.z (14 B); Req reached through a pointer rp (4 B); block locals declared
 * Req first, or Req then hf,h,t (4 B each); B688 second parameter u16, short
 * or char (4 B each). Matched twins read: ov183 021DF428 and 021DCBD8,
 * ov208 021C0B6C, ov206 021BB304 and 021BB534 (none has a strh of 1 before a
 * later literal 1 argument in one block). Reading: only a store operand 1
 * followed by an argument 1 merges, and no real source form splits them.
 *
 * final push 2026-10-05 G1L6: still 4 B (same icon-block residue). Research
 * first (idioms: repeated-constant-pools-only-within-one-block, repeated-small-
 * constant-takes-a-callee-saved-register, small-constant-is-rematerialised...,
 * store-stays-above-the-argument-constant, pool-constant-kept-live-past-a-join,
 * narrow-flag-local-is-spilled, sub-word-parameter-type..., one-element-array-
 * initialiser; twins ov183 021DCBD8/021DF428, ov206, ov208, ov218 021BA328:
 * none has a constant strh then a literal 1 argument in one block with a free
 * register). New tries, bytes off: aggregate initialiser `Req r={0x4b,0x40,1,0}`
 * (246 B: compiler copies the record from a pool table, no memset); do/while(0)
 * around B6F4+B688 (4); mid-function `#pragma opt_common_subs off` before the
 * if(B) (1093); B688 through a static inline SetVis(obj,v) or SetVis(obj) (4
 * each); stores through a static inline SetReq(&r,x,y,z) with int or u16
 * params (4 each); Req of short fields with B688 arg 1u (4); z as 1u with arg
 * -1+2 (4); keeping h live past the stores (ARC_TOOL_DeleteHandle moved after B688)
 * to test register pressure: still pooled (r6 instead of r7), so pressure is
 * not the cause; the whole icon block as a static inline MakeIcon (11 B, slots
 * move, still pooled). Conclusion unchanged: store operand 1 followed by an
 * argument 1 in one block always merges; no human source form found.
 *
 * final push 2026-10-05 G1R5: still 4 B (same icon-block residue). Control
 * test: B688 argument 2 instead of 1 gives 1 B off (only the constant), so
 * the merge is a plain value-number CSE of the two literal 1s, and with them
 * apart the whole block matches. New tries, all 4 B (movs r7,#1 pooled) unless
 * noted: Req stores and B294 in an inner block; function-level int vis=1 for
 * the argument, and for both z and argument; goto/label, switch(1), for(;;)
 * around B6F4+B688; z through a u16 *zp; B688 argument as (u8)1, (u16)1,
 * (char)1, (short)1, 1u, 1L, (u32)1, (unsigned long)1; per-function pragmas
 * opt_strength_reduction, opt_dead_code, opt_unroll_loops, opt_vectorize_loops,
 * optimize_for_size off (no change), opt_loop_invariants off (948 B off);
 * argument as B!=0, B>0, !!B, mode>=0 (real compares, 328+ B off); z stored
 * after B294 (42 B off, registers shift). Matched-assembly search (strh of a
 * fresh movs #1 followed later by a fresh movs #1 before a call): hits ov070
 * 021B6A14, 021B7688, 021B7CD0 (p->f83E = 1 then B92C(..,1), BB3F4(p,1)), plus
 * ov103/ov170/ov035 with no call-arg 1. ov070 021B6A14's C stores through a
 * pointer member and does not merge; our store goes to an address-taken stack
 * record and merges. No source form found that separates them.
 *
 * pass 2 2026-10-06 P2L06: still 4 B (same icon-block residue), form unchanged.
 * 40 compiles. Findings: compiler pins dsi/1.2 and 1.3 give the same 4 B, 1.6sp2
 * 7 lines, 2.0 1188 B. opt_common_subs off and optimization_level 3 keep the
 * merge (it is backend, not IRO CSE). Diagnostics: replacing BB5C(B,C,D,A) by
 * constants (or the B6F4 argument by 5) removes the merge, so it appears only
 * while the spilled A..D stay live across the icon tail; tiny repros never merge
 * the 1. Stores through a walking or indexed u16 pointer from &r.x also remove
 * the merge but use r6 as the base instead of sp+0x70 (60 lines off). Tried, all
 * 4 B: A..D as a local struct, a u32 info[4] array, an array with a call
 * initialiser, BB5C result in a local, one function-level h, declaration orders
 * of A..D and of the icon-block locals, z first, B294 stack arg changes.
 * Open lead: a form that keeps A..D in real memory (not spilled registers).
 *
 * pass 3 2026-10-06 P3L02: EXACT (c99 and c). The icon-block residue was the
 * callee declaration, not the block: CLACT_SetActorPaletteOffset declared `void *` (returns
 * its object) instead of `void`. With a void declaration r0 is dead after the
 * call and mwcc keeps the constant 1 in r7 across it (store z=1, later
 * CLACT_SetActorObjMode(obj,1)); with a value return it rebuilds `movs r1,#1` at each
 * use, as the image does (docs/idioms/a-callee-declared-void-that-returns-a-
 * value-changes-later-constant-copies.md). Evidence: the ARM body of
 * CLACT_SetActorPaletteOffset (src/matched/arm9/unit_0204B6F4.c, written there as void) never
 * writes r0, so it is byte-identical to a definition that ends `return o;`.
 * The integrator should know that the matched definition is spelled void.
 * Also: t inlined into the CLACT_RegisterCellAnim call (same bytes, one fewer local).
 */
char *func_021FD1C4(void *prof,char *q,void *a2,void *a3,int mode,u16 heap)
{
    char *p;
    void *font;
    int i;
    void *bank;
    void *words;
    int ready;
    u32 k2,k1,k3,k4;
    void *text;
    u32 A,B,C,D;
    p=func_02030734(heap,0x44,0,d_02200D5C,0x541);
    MI_CpuFill8(p,0,0x44);
    *(char **)(p+0x1c)=q;
    font=(void *)func_021FC20C(q);
    *(void **)(p+0x20)=PMS_DRAW_Create((u32)a2,0,(u32)a3,(u32)font,7,1,heap);
    PMS_DRAW_SetDecoPriority(*(void **)(p+0x20),0,1);
    func_021FB964(*(void **)(p+0x1c),8,heap);
    bank=(void *)(u32)func_021FC214(q);
    words=(void *)(u32)func_021FC21C(q);
    {
    Pair_021FD110 b=d_02200B6C;
    for(i=0;i<7;i++) {
        *(void **)(p+i*4)=func_021FC6A4(1,d_02200B34[i].x,d_02200B34[i].y,d_02200B34[i].w,d_02200B34[i].h,14,a3,heap);
        func_021FC868(*(void **)(p+i*4),0,1,0);
        ready=1;
        switch(i) {
        case 0:
            {
            void *name;
            void *msg;
            text=STRBUF_Create(0x80,(u16)heap);
            name=GDS_PROFILE_CreateNameStr(prof,heap);
            msg=func_02045EC0(bank,d_02200B34[i].msg);
            func_0201EE0C(words,0,name,func_0200D6EC(prof),1,2);
            func_0201F250(words,text,msg);
            STRBUF_Delete(name);
            STRBUF_Delete(msg);
            break;
            }
        case 1:
            {
            u32 v;
            void *msg;
            v=func_0200D810(prof);
            text=STRBUF_Create(0x80,(u16)heap);
            msg=func_02045EC0(bank,d_02200B34[i].msg);
            func_0201F230(words,0,v);
            func_0201F250(words,text,msg);
            STRBUF_Delete(msg);
            break;
            }
        case 3:
            {
            u32 v;
            void *msg;
            v=func_0200D74C(prof);
            text=STRBUF_Create(0x80,(u16)heap);
            msg=func_02045EC0(bank,d_02200B34[i].msg);
            func_0201F048(words,0,v);
            func_0201F250(words,text,msg);
            STRBUF_Delete(msg);
            func_021FC868(*(void **)(p+i*4),8,1,0);
            break;
            }
        case 4:
            {
            u32 v,w;
            void *msg;
            v=func_0200D74C(prof);
            w=func_0200D760(prof);
            text=STRBUF_Create(0x80,(u16)heap);
            msg=func_02045EC0(bank,d_02200B34[i].msg);
            func_0201F094(words,0,v,w);
            func_0201F250(words,text,msg);
            STRBUF_Delete(msg);
            func_021FC868(*(void **)(p+i*4),8,1,0);
            break;
            }
        case 6:
            {
            u16 rec[4];
            void *msg;
            msg=func_0200D774(prof,(struct GdsRecord *)rec,heap);
            if(msg) {
                text=STRBUF_Clone(msg,heap);
                STRBUF_Delete(msg);
                func_021FC868(*(void **)(p+i*4),8,1,0);
            } else {
                Pair_021FD110 c=d_02200B6C;
                PMS_DRAW_SetNullColorPalette(*(void **)(p+0x20),0);
                PMS_DRAW_SetPrintColor(*(void **)(p+0x20),0x3da0);
                PMS_DRAW_PrintOffset(*(void **)(p+0x20),(u32)(*(void **)(*(char **)(p+i*4)+0xc)),rec,0,(u32)(&c));
                ready=0;
            }
            break;
            }
        default:
            text=func_02045EC0(bank,d_02200B34[i].msg);
            break;
        }
        if(ready) {
            func_021FC7C4(*(void **)(p+i*4),text,font,0x3da0);
            STRBUF_Delete(text);
        }
    }
    }
    A=func_0200D73C(prof);
    B=func_0200D6FC(prof);
    C=func_0200D70C(prof);
    D=func_0200D72C(prof);
    if(B) {
        u32 hf;
        void *h;
        Req r;
        hf=(heap&0x7fff)|0x8000;
        h=func_020490F4(7,hf);
        *(int *)(p+0x2c)=CLACT_RegisterPaletteCompressed(h,func_0201BC3C(),0,0x80,hf);
        *(int *)(p+0x34)=CLACT_RegisterCellAnim(h,func_0201BC40(),func_0201BCB4(),(u16)hf);
        *(int *)(p+0x30)=CLACT_RegisterCharacter(h,POKE_TOOL_CalcGraphicIndex(B,C,D,A),0,0,hf);
        ARC_TOOL_DeleteHandle(h);
        MI_CpuFill8(&r,0,8);
        r.x=0x4b;r.y=0x40;r.z=1;
        *(void **)(p+0x24)=CLACT_CreateActor(a2,*(u32 *)(p+0x30),*(u32 *)(p+0x2c),*(u32 *)(p+0x34),&r,0,heap);
        CLACT_SetActorPaletteOffset(*(void **)(p+0x24),POKE_TOOL_CalcIconPalette(B,C,D,A),0);
        CLACT_SetActorObjMode(*(void **)(p+0x24),1);
    }
    switch(mode) {
    case 0:
        {
        void *h;
        if(!func_0200D6EC(prof)) {
            k3=4;k1=0x14;k2=0x12;k4=0x13;
        } else {
            k3=6;k1=0x17;k2=0x15;k4=0x16;
        }
        h=func_020490F4(0x1f,(heap&0x7fff)|0x8000);
        *(int *)(p+0x38)=CLACT_RegisterPaletteEx(h,k3,0,0x1a0,0,1,heap);
        *(int *)(p+0x40)=CLACT_RegisterCellAnim(h,k2,k4,(u16)heap);
        *(int *)(p+0x3c)=CLACT_RegisterCharacter(h,k1,0,0,heap);
        ARC_TOOL_DeleteHandle(h);
        break;
        }
    case 1:
        {
        u32 k;
        void *h;
        k=func_0200D820(prof);
        h=func_020490F4(0x20,(heap&0x7fff)|0x8000);
        *(int *)(p+0x38)=CLACT_RegisterPaletteEx(h,0,0,0x1a0,d_02200AFC[k],1,heap);
        *(int *)(p+0x40)=CLACT_RegisterCellAnim(h,0x41,0x42,(u16)heap);
        *(int *)(p+0x3c)=CLACT_RegisterCharacter(h,k+0x31,0,0,heap);
        ARC_TOOL_DeleteHandle(h);
        break;
        }
    }
    {
        Req r;
        MI_CpuFill8(&r,0,8);
        r.x=0x30;r.y=0x40;
        *(void **)(p+0x28)=CLACT_CreateActor(a2,*(u32 *)(p+0x3c),*(u32 *)(p+0x38),*(u32 *)(p+0x40),&r,0,heap);
        CLACT_SetActorPaletteOffset(*(void **)(p+0x28),0,1);
        CLACT_SetActorObjMode(*(void **)(p+0x28),1);
    }
    return p;
}





void func_021FD640(int *p)
{
    int i;
    if(p[10]) {CLACT_DeleteActor((struct Obj *)p[10]);CLACT_ReleasePalette(p[14]);CLACT_ReleaseCharacter(p[15]);CLACT_ReleaseCellAnim(p[16]);}
    if(p[9]) {CLACT_DeleteActor((struct Obj *)p[9]);CLACT_ReleasePalette(p[11]);CLACT_ReleaseCharacter(p[12]);CLACT_ReleaseCellAnim(p[13]);}
    for(i=0;i<7;i++) if(p[i]) {func_021FC734((void *)p[i]);p[i]=0;}
    PMS_DRAW_Delete((struct Obj *)p[8]);func_021FBDA4(p[7],8);func_020307B0(p);func_020409B4(1);
}





int func_021FD6B0(u8 *p)
{
    int result=1;
    int i;
    for(i=0;i<7;i++)if(*(void **)((u32)p+(u32)i*4)!=0)result &=func_021FC830(*(void **)((u32)p+(u32)i*4));
    PMS_DRAW_Main(*(u8 * *)&((struct Obj24841 *)p)->f20);
    return result;
}





int *func_021FD6D8(int payload,int callback,u32 heap)
{
    int *p;
    p=func_02030734(heap,16,0,d_02200D5C,0x6a2);
    MI_CpuFill8(p,0,16);
    p[2]=payload;
    func_021FD73C(p,callback);
    return p;
}






void func_021FD714(void *p)
{
    func_020307B0(p);
}






void func_021FD71C(u8 *p)
{
    if(*(Callback *)&((struct Obj14467 *)p)->f0!=0)(*(Callback *)p)(p,(int *)(p+4),((struct Obj14467 *)p)->f8);
}






/*
 * Blocker leaf for ov183 021E1D48 and 021E20F8, parent cleared.
 */
int func_021FD72C(int *p)
{
    if (*p==0) return 1;
    return 0;
}






int *func_021FD73C(int *p, int v)
{
    p[0] = v;
    p[1] = 0;
    return p;
}







int func_021FD744(int *a)
{
    return (int)func_021FD73C(a, 0);
}







int func_021FD750(int *p, int v)
{
    return *p == v;
}






char *func_021FD760(unsigned owner,char *resources,int index,int heap)
{
    Triple triple;
    Pair pair;
    unsigned short res;
    char *p;
    int i;
    p=func_02030734(heap,0x264,0,d_02200D5C,0x7CA);
    MI_CpuFill8(p,0,0x264);
    ((Handles *)p)->resources=resources;((Handles *)p)->index=index;
    ((Handles *)p)->task=(int)func_021FD6D8((int)p,(int)func_021FD964,heap);
    func_021FBE54(((Handles *)p)->resources,index+9,heap);
    MI_CpuFill8(&pair,0,8);
    if(!func_021FC124(((Handles *)p)->resources,index+9,&triple)) func_02034714(d_02200D68,0,d_02200D68);
    i=0;
    res=index;
    for(;i<12;i++) {
        ((Handles *)p)->handles[i]=(int)CLACT_CreateActor((void *)owner,triple.y,triple.z,triple.x,&pair,res,heap);
        CLACT_SetActorDrawEnable((struct Obj *)((Handles *)p)->handles[i],0);
        CLACT_SetActorObjMode((struct Actor *)(((Handles *)p)->handles[i]),1);
    }
    return p;
}







/*
 * Release the twelve handles at r5+0x1F8, then tear the object down.
 */
void func_021FD820(char *r5)
{
    int i;
    for (i = 0; i < 0xC; i++)
        CLACT_DeleteActor((struct Obj *)(*(int *)(r5 + 0x1F8 + i * 4)));
    func_021FC0C8((char *)(((struct Obj10793 *)r5)->f14), ((struct Obj10793 *)r5)->fC + 9);
    func_021FD714((void *)(((struct Obj10793 *)r5)->f10));
    func_020307B0((int *)r5);
}






void func_021FD854(char *p)
{
    func_021FD71C((u8 *)(((struct Obj24845 *)p)->f10));
}






/*
 * follower: 021FD938 already filed separately; lead excludes that existing accessor.
 */
void func_021FD860(char *p,u32 mode,const Pair *pair)
{
    if(pair) {
        *(Pair *)p=*pair;
        *(const Pair * *)&((struct Obj02236 *)p)->f8=pair;
    }
    ((struct Obj02236 *)p)->f22C=0;
    if(mode==0 && func_021FD750(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDE88)) GFL_USE_PlaySeDefaultVolume(0x701);
    switch(mode) {
    case 0: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FD964);break;
    case 1: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FD9A0);break;
    case 2: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDA7C);break;
    case 3: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDBF4);break;
    case 4: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDE88);break;
    case 5: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDF40);break;
    case 6: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDFF0);break;
    case 7: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FDFF4);break;
    case 8: func_021FD73C(*(int * *)&((struct Obj02236 *)p)->f10,(int)func_021FE1C4);break;
    }
}






int func_021FD938(char *p){return ((struct Obj24846 *)p)->f22C;}






/*
 * lever: Set the counter before narrowing value; its initialization splits the two shifts.
 */
void func_021FD940(u8 *p,u32 value)
{
    int i;
    u16 narrow;
    i=0;
    narrow=value;
    for(;i<12;i++)CLACT_SetActorAnimSeq(*(struct Obj **)((u32)p+(u32)i*4+0x1f8),narrow);
}






void func_021FD964(void *unused,int *state,u8 *p)
{
    int i;
    switch(*state) {
    case 0:
        for(i=0;i<12;i++)CLACT_SetActorDrawEnable(*(struct Obj **)((u32)p+(u32)i*4+0x1f8),0);
        ((struct Obj24847 *)p)->f22C=1;
        *state=1;
        break;
    case 1:break;
    }
}




void func_021FD9A0(int unused,int *state,Motion_021FD714 *p)
{
    Pair full;
    ShortPair pos;
    int i;
    switch(*state) {
    case 0:
        p->timer=0;
        for(i=0;i<6;i++) {
            int angle;
            angle=i*0xffff/6;
            func_021FE2BC((unsigned char *)p->record[i],(const Pair *)p,8,20,angle,angle+0x3333,15);
            CLACT_SetActorDrawEnable(p->handles[i],1);
        }
        *state=1;
    case 1:
        for(i=0;i<6;i++) {
            func_021FE2F8(p->record[i],(int *)&full,p->timer);
            pos.x=full.x;pos.y=full.y;
            CLACT_AddActorSurfacePos(p->handles[i],&pos,p->heap);
        }
        if(p->timer++>15) *state=2;
        break;
    case 2:
        func_021FD73C(p->task,(int)func_021FD964);
        break;
    }
}



/*
 * lever: ShortPair declared before Pair gives +2C and +24 stack objects; initialize reused i=1 before FE478 so the call precedes its loop without relocating movs.
 */
void func_021FDA7C(int unused,int *state,Motion_021FDA7C *p)
{
    ShortPair pos;
    Pair initial;
    int i,done;
    switch(*state) {
    case 0:
        p->timer=0;
        initial=d_02200AD0.first;
        for(i=0;i<12;i++) {
            p->positions[i]=initial;
            CLACT_SetActorDrawEnable(p->handles[i],1);
        }
        func_021FE444((int *)p->record[0],&p->positions[0],&d_02200AE8.first,0,50);
        for(i=1;i<12;i++) func_021FE4D8((int *)p->record[i],(int)&p->positions[i-1],(int *)&p->positions[i],0x4000-i*0x666/2);
        *state=1;
    case 1:
        i=1;
        p->flag=func_021FE478((int *)p->record[0],&p->positions[0],p->timer);
        done=1;
        done&=p->flag;
        for(;i<12;i++) done&=func_021FE54C((char *)p->record[i],(int *)(&p->positions[i]));
        for(i=0;i<12;i++) {
            pos.x=p->positions[i].x;pos.y=p->positions[i].y;
            CLACT_AddActorSurfacePos(p->handles[i],&pos,p->heap);
        }
        p->timer++;
        if(done) *state=2;
        break;
    case 2: func_021FD73C(p->task,(int)func_021FD964);break;
    }
}


void func_021FDBF4(int unused,int *state,Motion *p)
{
    ShortPair pos;
    ShortPair pos2;
    Pair initial;
    int i;
    switch(*state) {
    case 0:
        p->timer=0;
        initial=d_02200AD0.third;
        for(i=0;i<6;i++) {
            p->positions[i]=initial;
            CLACT_SetActorDrawEnable(p->handles[i],1);
        }
        func_021FE444((int *)p->record[0], (const Pair *)(&p->positions[0]), (const Pair *)(&d_02200AD0.second), 0, 36);
        for(i=1;i<6;i++) func_021FE4D8((int *)p->record[i],(int)&p->positions[i-1],(int *)&p->positions[i],0x3800-i*0xb33/2);
        *state=1;
    case 1:
        p->done[1]=func_021FE478((int *)p->record[0], (Pair *)(&p->positions[0]), p->timer);
        for(i=1;i<6;i++) p->done[i+1]=func_021FE54C((char *)p->record[i],(int *)(&p->positions[i]));
        for(i=0;i<6;i++) {
            pos.x=p->positions[i].x;pos.y=p->positions[i].y;
            CLACT_AddActorSurfacePos(p->handles[i],&pos,p->heap);
        }
        p->timer++;
        if(p->done[1]) {CLACT_SetActorDrawEnable(p->handles[0],0);*state=2;}
        break;
    case 2:
        p->timer=0;
        for(i=6;i<12;i++) {
            func_021FE3B4((u8 *)p->record[i], (const Pair *)((void *)&d_02200AD0.second), 15, (i*0xffff-0x5fffa)/6, 90);
            CLACT_SetActorDrawEnable(p->handles[i],1);
        }
        *state=3;
    case 3:
        for(i=6;i<12;i++) func_021FE3E4(p->record[i],(int *)(&p->positions[i]),p->timer);
        for(i=1;i<6;i++) {
            p->done[i+1]=func_021FE54C((char *)p->record[i],(int *)(&p->positions[i]));
            if(p->done[i+1]) CLACT_SetActorDrawEnable(p->handles[i],0);
        }
        for(i=0;i<12;i++) {
            pos2.x=p->positions[i].x;pos2.y=p->positions[i].y;
            CLACT_AddActorSurfacePos(p->handles[i],&pos2,p->heap);
        }
        p->flag=1;
        p->timer++;
        break;
    }
}







void func_021FDE88(int unused,int *state,Motion_021FDE88 *p)
{
    Pair full;
    ShortPair pos;
    int i;
    switch(*state) {
    case 0:
        p->timer=0;
        for(i=0;i<6;i++) {
            func_021FE3B4((u8 *)p->record[i], (const Pair *)((const Pair *)p), 15, (i*0xFFFF)/6, 90);
            CLACT_SetActorDrawEnable((struct Obj *)p->handles[i],1);
        }
        GFL_USE_PlaySeDefaultVolume(0x705);
        *state=1;
    case 1:
        for(i=0;i<6;i++) {
            func_021FE3E4(p->record[i],(int *)(&full),p->timer);
            pos.x=full.x;pos.y=full.y;
            CLACT_AddActorSurfacePos((void *)(p->handles[i]), (const ShortPair *)((ShortPair *)&pos), p->heap);
        }
        p->timer++;
        break;
    }
}







/*
 * follower: empty return at 021FDFF0; trailing two zero alignment bytes excluded.
 */
void func_021FDF40(int unused,int *state,Motion_021FDE88 *p)
{
    Pair full;
    ShortPair pos;
    int i;
    switch(*state) {
    case 0:
        p->timer=0;
        for(i=0;i<6;i++) {
            func_021FE3B4((u8 *)p->record[i], (const Pair *)((const Pair *)p), 10, (i*0xFFFF)/6, 90);
            CLACT_SetActorDrawEnable((struct Obj *)p->handles[i],1);
        }
        *state=1;
    case 1:
        for(i=0;i<6;i++) {
            func_021FE3E4(p->record[i],(int *)(&full),p->timer);
            pos.x=full.x;pos.y=full.y;
            CLACT_AddActorSurfacePos((void *)(p->handles[i]), (const ShortPair *)((ShortPair *)&pos), p->heap);
        }
        p->timer++;
        break;
    }
}







void func_021FDFF0(void)
{
}






void func_021FDFF4(int *obj,int *state,Motion_021FDFF4 *p)
{
    ShortPair pos;
    ShortPair pos2;
    int i;
    int all;
    switch(*state) {
    case 0:
        p->timer=0;
        for(i=0;i<6;i++) {
            func_021FE2BC((u8 *)p->record[i], (const Pair *)((const Pair *)p), 8, 20, (i*0xFFFF)/6, (i*0xFFFF)/6+0x3333, 16);
            CLACT_SetActorDrawEnable((struct Obj *)p->handles[i],1);
        }
        *state=1;
    case 1:
        for(i=0;i<6;i++) {
            func_021FE2F8(p->record[i],p->positions[i],p->timer);
            pos.x=p->positions[i][0];pos.y=p->positions[i][1];
            CLACT_AddActorSurfacePos((void *)((int)(p->handles[i])), (const ShortPair *)((ShortPair *)&pos), p->heap);
        }
        if(p->timer++>16) *state=2;
        break;
    case 2:
        *state=3;
        break;
    case 3:
        for(i=0;i<6;i++)
            func_021FE4D8((int *)p->record[i],p->target,p->positions[i],0x4000-(i*0x99A)/2);
        *state=4;
    case 4:
        all=1;
        for(i=0;i<6;i++) {
            all&=func_021FE54C(p->record[i],p->positions[i]);
            pos2.x=p->positions[i][0];pos2.y=p->positions[i][1];
            CLACT_AddActorSurfacePos((void *)((int)(p->handles[i])), (const ShortPair *)((ShortPair *)&pos2), p->heap);
        }
        if(all) *state=5;
        break;
    case 5:
        func_021FD73C(obj,(int)func_021FD964);
        break;
    }
}






/*
 * lever: Initialize i before the second start=p+18 assignment to interleave movs with the pointer adds (four bytes out to EXACT).
 * abi: B404 third parameter is u16 because the original truncates the loaded heap word immediately before blx.
 * note 2026-10-05 (wave D9r lane 131): removed the 2 dead first assignments
 * (`start=p;` before `start=p+0x18;`; `offset=0x228;` before
 * `offset=0x1f8;`). Game code has no line table, so these were stand-ins.
 * The plain single assignment gives EXACT in --lang c99 and --lang c: the
 * output bytes do not change. Older text in this header that asks for the
 * double assignment is superseded.
 */
void func_021FE1C4(int *task,int *state,char *p)
{
    Pair full;
    ShortPair pos;
    int i;
    switch(*state) {
    case 0: {
        char *start;
        int offset;
        func_021FD940((unsigned char *)p,0);
        start=p+0x18;
        offset=0x1f8;
        for(i=6;i<12;i++) {
            u16 angle;
            angle=*(u16 *)(p+i*32+0x2a)+((struct Obj06632 *)p)->f228/ *(int *)(p+i*32+0x2c);
            func_021FE2BC((unsigned char *)(start+i*32),(void *)d_02200AD8,15,1,angle,angle+0xf000,30);
            CLACT_SetActorObjMode(*(void **)(p+i*4+offset),0);
        }
        ((struct Obj06632 *)p)->f228=0;
        *state=1;
    }
    case 1: {
        char *start;
        int offset;
        offset=0x228;start=p;i=6;start=p+0x18;offset=0x1f8;
        for(;i<12;i++) {
            func_021FE2F8(start+i*32,(int *)&full,((struct Obj06632 *)p)->f228);
            pos.x=full.x;pos.y=full.y;
            CLACT_AddActorSurfacePos((void *)((int)(*(void **)(p+i*4+offset))), (const ShortPair *)((ShortPair *)&pos), ((struct Obj06632 *)p)->fC);
        }
        if((((struct Obj06632 *)p)->f228)++>60)*state=2;
        break;
    }
    case 2:func_021FD73C(task,(int)func_021FD964);break;
    }
}






/*
 * lever: A named x load before the last halfword store preserves the interleaved copy.
 */
int func_021FE2BC(u8 *p,const Pair *origin,u16 a,u16 b,u16 c,u16 d,int duration)
{
    int x;
    MI_CpuFill8(p,0,28);
    ((struct Obj01284 *)p)->f10=a;
    ((struct Obj01284 *)p)->f12=b;
    ((struct Obj01284 *)p)->f14=c;
    x=origin->x;
    ((struct Obj01284 *)p)->f16=d;
    ((struct Obj01284 *)p)->f0=x;
    ((struct Obj01284 *)p)->f18=duration;
    ((struct Obj01284 *)p)->f4=origin->y;
    return func_021FE2F8((char *)p,(int *)(p+8),0);
}





int func_021FE2F8(char *p, int *out, int step)
{
    unsigned short angle_delta;
    signed char direction;
    int angle;
    int initial_angle;
    int duration;
    unsigned short initial_radius;
    int radius_delta;
    int radius, x, y;
    initial_angle = ((struct Obj01284 *)p)->f14;
    angle_delta = ((struct Obj01284 *)p)->f16 - initial_angle;
    initial_radius = ((struct Obj01284 *)p)->f10;
    radius_delta = (short)(*(short *)&((struct Obj01284 *)p)->f12 - (short)initial_radius);
    direction = radius_delta / (radius_delta < 0 ? -radius_delta : radius_delta);
    duration = ((struct Obj01284 *)p)->f18;
    angle = (unsigned short)(initial_angle + angle_delta * step / duration);
    if (radius_delta < 0) radius_delta = -radius_delta;
    radius = initial_radius + direction * (step * radius_delta / duration);
    if (radius < 0) radius = 0;
    x = (FX_SinCosTable_[(angle >> 4) * 2 + 1] * radius) >> 12;
    y = (FX_SinCosTable_[(angle >> 4) * 2] * radius) >> 12;
    x += ((struct Obj01284 *)p)->f0;
    y += ((struct Obj01284 *)p)->f4;
    ((struct Obj01284 *)p)->f8 = x;
    ((struct Obj01284 *)p)->fC = y;
    if (out) { out[0] = x; out[1] = y; }
    return step == ((struct Obj01284 *)p)->f18;
}





/*
 * lever: The two-word origin copy is a Pair assignment; separate field stores reorder it.
 */
int func_021FE3B4(u8 *p,const Pair *origin,u16 a,u16 b,int duration)
{
    MI_CpuFill8(p,0,24);
    *(Pair *)p=*origin;
    ((struct Obj10797 *)p)->f14=duration;
    ((struct Obj10797 *)p)->f10=a;
    ((struct Obj10797 *)p)->f12=b;
    return func_021FE3E4((char *)p,0,0);
}





#pragma opt_common_subs off





/*
 * note: pass 2 2026-10-06 P2L30: EXACT (c and c99). The twin shape of
 *   ov186_func_021FE2F8 (x, y products, then x += f0, y += f4, then the two
 *   stores) gives the original tail; with common subexpressions on, the
 *   front end turns the two radius reads into one temp and hoists it to
 *   right after the angle load. #pragma opt_common_subs off keeps the read
 *   inline at its first use (between the two table reads); a named index
 *   local i = (angle >> 4) * 2 then gives the shared index the pragma no
 *   longer finds. Earlier lanes: 26 (P19 lane 5), 15 (G6L8).
 */
int func_021FE3E4(char *p, int *out, int step)
{
    int angle, i, x, y;
    angle = (unsigned short)(*(unsigned short *)(p + 0x12) + 0xFFFF * step / *(int *)(p + 0x14));
    i = (angle >> 4) * 2;
    x = (FX_SinCosTable_[i + 1] * *(unsigned short *)(p + 0x10)) >> 12;
    y = (FX_SinCosTable_[i] * *(unsigned short *)(p + 0x10)) >> 12;
    x += *(int *)p;
    y += *(int *)(p + 4);
    *(int *)(p + 8) = x;
    *(int *)(p + 12) = y;
    if (out) { out[0] = x; out[1] = y; }
    return step == *(int *)(p + 0x14);
}





#pragma opt_common_subs reset





static inline void copyPair(Pair *dest,const Pair *src) { int y,x; y=src->y; x=src->x; dest->y=y; dest->x=x; }





/*
 * lever: inline pair copy loads y then x before storing; aggregate copy differed by 20 bytes, raw field stores by 23, const raw stores by 22.
 */
void func_021FE444(int *p,const Pair *a,const Pair *b,int c,int d) { MI_CpuFill8(p,0,0x20); copyPair((Pair *)p,a); copyPair((Pair *)(p+2),b); p[7]=d; p[6]=c; func_021FE478(p,0,0); }





int func_021FE478(int *p, Pair *out, int step)
{
    int done = 0;
    int progress = step - p[6];
    if (progress < 0)
        progress = 0;
    p[4] = p[0] + (p[2] - p[0]) * progress / p[7];
    p[5] = p[1] + (p[3] - p[1]) * progress / p[7];
    if (progress >= p[7]) {
        *(Pair *)(p + 4) = *(Pair *)(p + 2);
        done = 1;
    }
    if (out) {
        *out = *(Pair *)(p + 4);
    }
    return done;
}





void func_021FE4D8(int *p, int a, const int *values, int duration)
{
    float value;
    MI_CpuFill8(p, 0, 0x14);
    p[0] = a;
    if (values[0] > 0)
        value = 0.5f + (float)(values[0] << 12);
    else
        value = (float)(values[0] << 12) - 0.5f;
    p[1] = (int)value;
    if (values[1] > 0)
        value = 0.5f + (float)(values[1] << 12);
    else
        value = (float)(values[1] << 12) - 0.5f;
    p[2] = (int)value;
    p[3] = 0;
    p[4] = duration;
}





static inline int roundFixed(int x)
{
    float f;
    if(x>0)f=0.5f+(float)(x<<12);
    else f=(float)(x<<12)-0.5f;
    return (int)f;
}





int func_021FE54C(char *p,int *out)
{
    VecFx32 delta;
    int length,x,y;
    delta.x=roundFixed((*(int **)p)[0])-((struct Obj02904 *)p)->f4;
    delta.y=roundFixed((*(int **)p)[1])-((struct Obj02904 *)p)->f8;
    delta.z=0;
    length=func_0207CBD0(&delta);
    if(length) {
        x=func_0207C768((int)(((long long)delta.x* ((struct Obj02904 *)p)->f10+2048)>>12),length);
        y=func_0207C768((int)(((long long)delta.y* ((struct Obj02904 *)p)->f10+2048)>>12),length);
        if((delta.x<0?-delta.x:delta.x)>(x<0?-x:x))((struct Obj02904 *)p)->f4+=x;
        else ((struct Obj02904 *)p)->f4=roundFixed((*(int **)p)[0]);
        if((delta.y<0?-delta.y:delta.y)>(y<0?-y:y))((struct Obj02904 *)p)->f8+=y;
        else ((struct Obj02904 *)p)->f8=roundFixed((*(int **)p)[1]);
    }
    if(out){out[0]=((struct Obj02904 *)p)->f4>>12;out[1]=((struct Obj02904 *)p)->f8>>12;}
    return length==0;
}





int *func_021FE6C0(unsigned heap)
{
    int *p = func_02030734(heap, 0x40, 0, d_02200D6C, 0x62);
    MI_CpuFill8(p, 0, 0x40);
    p[15] = 0xFFFF;
    p[8] = (int)PALANM_Create(heap);
    PALANM_AllocSlotBuffers((void *)p[8], 0, 0x200, heap);
    PALANM_AllocSlotBuffers((void *)p[8], 2, 0x1C0, heap);
    PALANM_AllocSlotBuffers((void *)p[8], 1, 0x200, heap);
    PALANM_AllocSlotBuffers((void *)p[8], 3, 0x1C0, heap);
    PALANM_SetAutoTransfer((void *)p[8], 1);
    return p;
}





/*
 * extent: two zero alignment bytes at 0x021FE766 follow; no follower.
 * ABI: 02021540's legacy source declares void(void), but this caller loads r0 from p+0x20 at 021FE758; its tail-forward target 020307B0 saves and reads r0. Preserve that pointer argument.
 */
void func_021FE734(char *p) { PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj06634 *)p)->f20,2); PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj06634 *)p)->f20,0); PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj06634 *)p)->f20,3); PALANM_FreeSlotBuffers(*(struct PalAnmSlot * *)&((struct Obj06634 *)p)->f20,1); PALANM_Delete(((struct Obj06634 *)p)->f20); func_020307B0(p); }






void func_021FE768(S *p)
{
    int (*fn)(S *, void *);

    fn = (int (*)(S *, void *))p->f1c;
    if (fn != 0) {
        p->f0 = fn(p, p->at_c);
        if (p->f0 != 0)
            p->f1c = 0;
    }
}






void func_021FE784(int a, int b, int c, int d)
{
    func_021FE794((char *)a, b, c, d, 0);
}




void func_021FE794(char *p,u32 index,u32 a,u32 b,u32 c) { ((struct Obj05506 *)p)->f4=a; ((struct Obj05506 *)p)->f18=c; ((struct Obj05506 *)p)->f8=b; ((struct Obj05506 *)p)->f1C=func_021FED08(index); ((struct Obj05506 *)p)->f0=0; ((struct Obj05506 *)p)->fC=0; }




/*
 * Unlabelled ov186 leaf hidden in a word run: loads the word its argument
 * points at.  Matched to supply the `matched` witness for the two pending
 * ov184 callers (func_021F85DC, func_021F8624).
 */
int func_021FE7B0(int *p)
{
    return *p;
}




/*
 * lever: plain literals 512 and 448; mwcc derives 448 from the held 512 itself. Twin shape: matched ov197 0220C980 call to PALANM_CopyHwPaletteToSlot.
 */
void func_021FE7B4(char *p)
{
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot **)(p + 0x20), 0, 0, 512);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot **)(p + 0x20), 2, 0, 448);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot **)(p + 0x20), 1, 0, 512);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot **)(p + 0x20), 3, 0, 448);
}




void func_021FE7F4(char *p,u16 value) { ((struct Obj24849 *)p)->f24=value; }




void func_021FE7F8(char *p, int mask)
{
    if (mask & 1)
        PALANM_BlendChannelMask(*(unsigned *)&((struct Obj05507 *)p)->f20, 0, 0xBFFF, 16, ((struct Obj05507 *)p)->f24);
    if (mask & 2)
        PALANM_BlendChannelMask(*(unsigned *)&((struct Obj05507 *)p)->f20, 1, 0xBFFF, 16, ((struct Obj05507 *)p)->f24);
    PALANM_RequestFullTransfer(((struct Obj05507 *)p)->f20, 1);
    PALANM_TransferPalettes(((struct Obj05507 *)p)->f20);
}




void func_021FE840(int unused, int mask, int value)
{
    if (mask & 1) {
        func_0207D63C(0x04000050, 7, 31, value, 16 - value);
        if (value == 0) {
            BG_SYS_SetMainPlaneVisible(1, 0);
            BG_SYS_SetMainPlaneVisible(2, 0);
            BG_SYS_SetMainPlaneVisible(4, 0);
        } else {
            BG_SYS_SetMainPlaneVisible(1, 1);
            BG_SYS_SetMainPlaneVisible(2, 1);
            BG_SYS_SetMainPlaneVisible(4, 1);
        }
    }
    if (mask & 2) {
        func_0207D63C(0x04001050, 3, 7, value, 16 - value);
        if (value == 0) {
            BG_SYS_SetSubPlaneVisible(1, 0);
            BG_SYS_SetSubPlaneVisible(2, 0);
        } else {
            BG_SYS_SetSubPlaneVisible(1, 1);
            BG_SYS_SetSubPlaneVisible(2, 1);
        }
    }
}




void func_021FE8E8(char *p,void *arc,u32 file,u32 idx,u32 off,u32 count,u16 tag) { PALANM_LoadHandlePaletteToSlotAt(*(struct PalAnmSlot * *)&((struct Obj24850 *)p)->f20,arc,file,tag,idx,count,off,0); }




/*
 * Three-state fade task.  start/end are assigned only for p[2] == 0 or 1:
 * the original passes callee-saved r5 and entry r2 unset on any other
 * value, exactly what C locals left unassigned on that path give
 * (docs/idioms/switch-arms-tail-merge.md).  The earlier DIFF note
 * initialised them to 16/0 and could not lose the extra moves.
 */
int func_021FE90C(u32 *p, u32 *state)
{
    u32 mask;
    s32 start, end;
    switch (*state) {
    case 0:
        mask = 0;
        if (p[1] & 1) mask |= 1;
        if (p[1] & 2) mask |= 2;
        if (p[2] == 0) {
            start = 16;
            end = 0;
        } else if (p[2] == 1) {
            start = 0;
            end = 16;
        }
        FADE_Start(mask, start, end, p[6]);
        *state = 1;
        break;
    case 1:
        if (FADE_IsActive() == 0) *state = 2;
        break;
    case 2:
        return 1;
    }
    return 0;
}




/*
 * Twin of func_021FE90C with mask bits 4/8.  start/end are assigned only
 * for p[2] == 0 or 1; the original forwards entry r1/r2 unset on any
 * other value (docs/idioms/switch-arms-tail-merge.md).  98 bytes; the
 * last two bytes of the 100-byte extent are alignment padding (00 00).
 */
int func_021FE970(u32 *p, u32 *state)
{
    u32 mask;
    s32 start, end;
    switch (*state) {
    case 0:
        mask = 0;
        if (p[1] & 1) mask |= 4;
        if (p[1] & 2) mask |= 8;
        if (p[2] == 0) {
            start = 16;
            end = 0;
        } else if (p[2] == 1) {
            start = 0;
            end = 16;
        }
        FADE_Start(mask, start, end, p[6]);
        *state = 1;
        break;
    case 1:
        if (FADE_IsActive() == 0) *state = 2;
        break;
    case 2:
        return 1;
    }
    return 0;
}




/*
 * volatile: 021FEA84 and 021FEACC write the engine-A/B blend coefficients.
 * abi: E6E0's r0 return is consumed.
 */
int func_021FE9D4(char *p,int *state)
{
    switch(*state) {
    case 0: {
        int a,b,duration;
        if(((struct Obj01285 *)p)->f8==0){a=0;b=16;}
        else if(((struct Obj01285 *)p)->f8==1){a=16;b=0;}
        if(((struct Obj01285 *)p)->f4&1)func_0207D63C(0x04000050,7,31,a,b);
        if(((struct Obj01285 *)p)->f4&2)func_0207D63C(0x04001050,3,7,a,b);
        ((struct Obj01285 *)p)->f10=0;
        duration=((struct Obj01285 *)p)->f18;
        if(duration==0)duration=func_0209C0A4(16,FADE_GetSpeed());
        ((struct Obj01285 *)p)->f14=duration;
        *state=1;
        break;
    }
    case 1: {
        int a,b;
        if(((struct Obj01285 *)p)->f8==0){b=_u32_div_f(((struct Obj01285 *)p)->f10<<4,((struct Obj01285 *)p)->f14);a=16-b;}
        else if(((struct Obj01285 *)p)->f8==1){a=_u32_div_f(((struct Obj01285 *)p)->f10<<4,((struct Obj01285 *)p)->f14);b=16-a;}
        if(((struct Obj01285 *)p)->f4&1) {
            *(volatile u16 *)0x04000052=b|(a<<8);
            if(b==0){BG_SYS_SetMainPlaneVisible(1,0);BG_SYS_SetMainPlaneVisible(2,0);BG_SYS_SetMainPlaneVisible(4,0);}
            else{BG_SYS_SetMainPlaneVisible(1,1);BG_SYS_SetMainPlaneVisible(2,1);BG_SYS_SetMainPlaneVisible(4,1);}
        }
        if(((struct Obj01285 *)p)->f4&2) {
            *(volatile u16 *)0x04001052=b|(a<<8);
            if(b==0){BG_SYS_SetSubPlaneVisible(1,0);BG_SYS_SetSubPlaneVisible(2,0);}
            else{BG_SYS_SetSubPlaneVisible(1,1);BG_SYS_SetSubPlaneVisible(2,1);}
        }
        if((((struct Obj01285 *)p)->f10)++ >= ((struct Obj01285 *)p)->f14)*state=2;
        break;
    }
    case 2:return 1;
    }
    return 0;
}




/*
 * note: 2026-10-05 the older draft used 0x3fff for both calls of the first pair and 0xbfff for both of the second. The listing pairs them as (2,0x3fff) (0,0xbfff) (3,0x3fff) (1,0xbfff). Variable value is read uninitialised when field 8 is not 0 or 1 (original behaviour, kept).
 */
int func_021FEB1C(char *p,int *state)
{
    switch(*state) {
    case 0: {
        int duration;
        *(u32 *)(p+0x10)=0;
        duration=*(int *)(p+0x18);
        if(duration==0)duration=func_0209C0A4(16,FADE_GetSpeed());
        *(u32 *)(p+0x14)=duration;
        PALANM_RequestFullTransfer(*(struct Obj02021F08 **)(p+0x20),1);
        *state=1;
        break;
    }
    case 1: {
        int value;
        if(*(int *)(p+8)==0)value=(u8)(16-_u32_div_f(*(u32 *)(p+0x10)<<4,*(u32 *)(p+0x14)));
        else if(*(int *)(p+8)==1)value=(u8)_u32_div_f(*(u32 *)(p+0x10)<<4,*(u32 *)(p+0x14));
        if(*(int *)(p+4)==15) {
            PALANM_BlendChannelMask(*(u32 *)(p+0x20),1,0x3000,value,0xffff);
        } else {
            if(*(int *)(p+4)&1) {
                PALANM_BlendChannelMask(*(u32 *)(p+0x20),2,0x3fff,value,*(u16 *)(p+0x24));
                PALANM_BlendChannelMask(*(u32 *)(p+0x20),0,0xbfff,value,*(u16 *)(p+0x24));
            }
            if(*(int *)(p+4)&2) {
                PALANM_BlendChannelMask(*(u32 *)(p+0x20),3,0x3fff,value,*(u16 *)(p+0x24));
                PALANM_BlendChannelMask(*(u32 *)(p+0x20),1,0xbfff,value,*(u16 *)(p+0x24));
            }
        }
        PALANM_TransferPalettes(*(struct S02021D50 **)(p+0x20));
        if((*(u32 *)(p+0x10))++ >= *(u32 *)(p+0x14))*state=2;
        break;
    }
    case 2:return 1;
    }
    return 0;
}




/*
 * lever: A duration local updated by the zero arm shares the final store, removing the extra branch (248 to 244 B).
 * volatile: 021FECBC writes the engine-B blend register at 04001052.
 * abi: 0204E6E0 returns the word loaded into r0 despite its asm void declaration.
 */
int func_021FEC14(char *p,int *state)
{
    switch(*state) {
    case 0: {
        int first,second,a,b,duration;
        if(((struct Obj01426 *)p)->f8==0){first=16;second=0;}
        else if(((struct Obj01426 *)p)->f8==1){first=0;second=16;}
        if(((struct Obj01426 *)p)->f8==0){a=0;b=16;}
        else if(((struct Obj01426 *)p)->f8==1){a=16;b=0;}
        FADE_Start(4,first,second,((struct Obj01426 *)p)->f18);
        func_0207D63C(0x04001050,3,7,a,b);
        ((struct Obj01426 *)p)->f10=0;
        duration=((struct Obj01426 *)p)->f18;
        if(duration==0)duration=func_0209C0A4(16,FADE_GetSpeed());
        ((struct Obj01426 *)p)->f14=duration;
        *state=1;
        break;
    }
    case 1: {
        int a,b;
        int done=1;
        if(((struct Obj01426 *)p)->f8==0){a=_u32_div_f(((struct Obj01426 *)p)->f10<<4,((struct Obj01426 *)p)->f14);b=16-a;}
        else if(((struct Obj01426 *)p)->f8==1){b=_u32_div_f(((struct Obj01426 *)p)->f10<<4,((struct Obj01426 *)p)->f14);a=16-b;}
        *(volatile u16 *)0x04001052=a|(b<<8);
        if(a==0)BG_SYS_SetSubPlaneVisible(3,0);else BG_SYS_SetSubPlaneVisible(3,1);
        done&=((((struct Obj01426 *)p)->f10)++ >= ((struct Obj01426 *)p)->f14);
        if(done & !FADE_IsActive())*state=2;
        break;
    }
    case 2:return 1;
    }
    return 0;
}




void *func_021FED08(unsigned index)
{
    switch (index) {
    case 0: return (void *)func_021FE90C;
    case 1: return (void *)func_021FE970;
    case 2: return (void *)func_021FE9D4;
    case 3: return (void *)func_021FEB1C;
    case 4: return (void *)func_021FEC14;
    }
    return 0;
}




char *func_021FED50(int a, int unused, char *resources, unsigned heap)
{
    char *p = func_02030734(heap, 0x390, 0, d_02200D78, 0x132);
    int i;
    MI_CpuFill8(p, 0, 0x390);
    func_021FBE54(resources, 4, heap);
    func_021FBE54(resources, 5, heap);
    for (i = 0; i < 12; i++)
        func_021FEEF4(p + i * 0x4C, a, resources, d_02200B74 + i * 24, heap);
    return p;
}




void func_021FEDC4(char *p,char *ctx) { int i; for(i=0;i<12;i++) if(func_021FF028((u32 *)((u32)p+i*0x4c))) func_021FF004((char *)((u32)p+i*0x4c)); func_021FC0C8(ctx,4); func_021FC0C8(ctx,5); func_020307B0(p); }




void func_021FEE00(char *p) { int i; for(i=0;i<12;i++) if(func_021FF028((u32 *)((u32)p+i*0x4c))) func_021FF01C((char *)((u32)p+i*0x4c)); }




/*
 * extent: two zero alignment bytes at 0x021FEE4A follow; no follower.
 */
void func_021FEE24(char *p) { int i; for(i=0;i<12;i++) if(func_021FF028((u32 *)((u32)p+i*0x4c))) func_021FF038((char *)((u32)p+i*0x4c),1); }




/*
 * extent: two zero alignment bytes at 0x021FEE72 follow; no follower.
 */
void func_021FEE4C(char *p) { int i; for(i=0;i<12;i++) if(func_021FF028((u32 *)((u32)p+i*0x4c))) func_021FF038((char *)((u32)p+i*0x4c),2); }




/*
 * extent: two zero alignment bytes at 0x021FEE9A follow; no follower.
 */
void func_021FEE74(char *p) { int i; for(i=0;i<12;i++) if(func_021FF028((u32 *)((u32)p+i*0x4c))) func_021FF038((char *)((u32)p+i*0x4c),3); }




void func_021FEE9C(char *p) { int i; for(i=0;i<12;i++) if(func_021FF028((u32 *)((u32)p+i*0x4c))) func_021FF074((char *)((u32)p+i*0x4c)); }




void func_021FEEC0(char *p,int mode,u32 value) { int i; for(i=0;i<12;i++) if(mode==*(int *)((u32)d_02200B74+i*24+16)) func_021FF02C((u8 *)((u32)p+i*0x4c),value); }
