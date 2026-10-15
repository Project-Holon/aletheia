/*
 * file:     wifilogin_message.c
 * unit:     yes
 * function: func_021D5984, func_021D5A88, func_021D5A9C, func_021D5B50, func_021D5B5C, func_021D5C24, func_021D5C30, func_021D5C70, func_021D5C94, func_021D5CCC, func_021D5D3C, func_021D5D5C, func_021D5E34, func_021D5E48, func_021D5E6C, func_021D5EA8, func_021D5ED8, func_021D5F7C, func_021D5FA0, func_021D5FC4, func_021D5FE8, func_021D603C, func_021D60D4, func_021D6104, func_021D6130, func_021D6134, func_021D613C, func_021D6150, func_021D6198, func_021D61B8, func_021D61D8, func_021D61FC, func_021D625C, func_021D6274, func_021D6294, func_021D62B4, func_021D630C, func_021D6328
 * address:  0x021D5984
 * region:   ov115
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from wifilogin_disp.c by tools/splitfile.py.
 *
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_0200FB24 0x0200FB24 thumb
 *   GFL_NET_STATE_SetWifiError 0x0203CA04 arm
 *   func_0200FBA0 0x0200FBA0 thumb
 *   GFL_NET_STATE_ClearErrorMode 0x0203C968 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   func_02034714 0x02034714 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   func_020307B0 0x020307B0 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   TCBL_Create 0x0203101C arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   d_021D6628 0x021D6628 data a4
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_02045CAC 0x02045CAC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   func_02028470 0x02028470 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020056BC 0x020056BC thumb
 *   TIME_ICON_Create 0x0202EE30 thumb
 *   func_02028484 0x02028484 thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   func_0207D658 0x0207D658 arm
 *   APP_TASKMENU_SetCursorPos 0x02027CFC thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   d_021D663C 0x021D663C data a1
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   STRBUF_Clone 0x02045874 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   d_021D6544 0x021D6544 data a2
 *   BMP_MENU_CreateYesNo 0x0201FDA0 thumb
 *   GFL_NET_ClearExitFlag 0x0203CF04 arm
 *   GFL_NET_IRC_WIRELESS_Exit 0x0203D0D0 arm
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   func_021D6328 0x021D6328 thumb ov115
 *   func_021D4D38 0x021D4D38 thumb ov115
 *   func_021D4DF4 0x021D4DF4 thumb ov115
 *   func_021D4E04 0x021D4E04 thumb ov115
 */
#include "../../matched/include/Obj00531.h"
#include "../../matched/include/Obj13852.h"
#include "../../matched/include/Obj00724.h"
#include "../../matched/include/Obj22602.h"
#include "../../matched/include/Obj04466.h"
#include "../../matched/include/Obj08042.h"
#include "../../matched/include/Obj04467.h"
#include "../../matched/include/Obj04468.h"
#include "../../matched/include/Obj08043.h"
#include "../../matched/include/Obj01535.h"
#include "../../matched/include/Obj05321.h"
#include "../../matched/include/Obj13853.h"
#include "../../matched/include/Obj08044.h"
#include "../../matched/include/Obj10334.h"
#include "../../matched/include/Obj10335.h"
#include "../../matched/include/Obj01720.h"
#include "../../matched/include/Obj08045.h"
#include "../../matched/include/Obj13854.h"
#include "../../matched/include/Obj03766.h"
#include "../../matched/include/Obj03767.h"
#include "../../matched/include/Obj10336.h"
#include "../../matched/include/Obj22603.h"
#include "../../matched/include/Obj06415.h"
#include "../../matched/include/Obj22604.h"
#include "../../matched/include/Obj13855.h"
#include "../../matched/include/Obj22605.h"
#include "../../matched/include/Obj22606.h"
#include "../../matched/include/Obj22607.h"
#include "../../matched/include/Obj22608.h"
#include "../../matched/include/Obj22609.h"
#include "../../matched/include/Obj22610.h"
#include "../../matched/include/Obj13856.h"
#include "../../matched/include/Obj13857.h"
#include "../../matched/include/Obj22611.h"
#include "wifilogin_disp_shared_types.h"

struct Tcbl;

struct U16Vec;

struct GfFont;

struct MsgBank;

struct WordSet;

struct R;

struct PrintSys;

struct Descriptor;

struct Rec;

struct Rec3;

struct S02031140;

struct TaskMenuState;

struct CharBuf;

struct TaskMenu;

struct TaskMenuTmpl;

typedef void (*StepFn)(u8 *);

typedef struct Blk {u8 first,pad[3]; u32 flags;} Blk;

typedef struct {
    u32 heap;
    u8 count, pad[3];
    const void *items;
    u32 param;
    u8 x, y, a, b;
} Template;

enum Kind { K0,K1 };

typedef struct { u8 a, b, c, d; u16 e; } Record;

typedef enum { FALSE, TRUE } BOOL;

extern u32 WIPE_SYS_EndCheck(void);

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern u32 func_0200FB24(void);

extern void GFL_NET_STATE_SetWifiError(void);

extern void func_0200FBA0(void);

extern void GFL_NET_STATE_ClearErrorMode(void);

extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

extern void GFL_USE_FadeOutBgm(u32 a);

extern void func_02034714(const char *,u32,const char *);

extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);

extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);

extern void MI_CpuFill8(void *,int,unsigned);

extern void GFL_USE_CancelChangeAndPlayBgm(int,int);

extern void func_020315D4(struct S020315D4 *p);

extern void GFL_HEAP_DeleteChecked(unsigned int heap);

extern u32 func_020307B0(void *p);

extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);

extern void BMP_WIN_Init(u16);

extern void GF_FONT_InitTextColor(void);

extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);

extern u32 PRINTSYS_QUE_Create(void *);

extern struct U16Vec *STRBUF_Create(u32,u32);

extern struct GfFont *GF_FONT_Create(int,int,int,int,u32);

extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern struct WordSet *GF_FONT_Create_EC64(u32);

extern struct R *APP_TASKMENU_RES_Create(u16,u16,u32,u32,u16);

extern void *BMP_MENUWORK_LoadFrameGfx(void *,u32,u32,u32);

extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32,u32,u32,u32,u32,u16);

extern void TCBL_Main(struct Tcbl *p);

extern u32 PRINTSYS_QUE_Main(struct PrintSys *);

extern void TIME_ICON_Delete(u8 *p);

extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);

extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);

extern void GF_FONT_SetDefaultTextColor(void);

extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);

extern u32 MSGDATA_Delete(struct Rec *rec);

extern u32 GF_FONT_Delete(void *ptr);

extern void STRBUF_Delete(struct U16Vec *vec);

extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);

extern void TCBL_Destroy(struct S02031140 *p);

extern void PRINTSYS_QUE_Clear(struct PrintSys *p);

extern void PRINTSYS_QUE_Delete(struct PrintSys *p);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern void BMP_WIN_Exit(void);

extern void func_02045CAC(struct MsgBank *, u32, void *);

extern u32 BMP_WIN_Create(u32, u32, u32, u32, u8, u8, u8);

extern void *BMP_WIN_GetBmp(struct Descriptor *);

extern void BMP_Clear(struct CharBuf *, u8);

extern void GF_FONT_SetTextColor(u32, u32, u32);

extern void func_02028470(u8 *p, u32 v);

extern signed char MSG_SPEED_GetWait(void);

extern u32 PRINTSYS_PrintStream(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);

extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);

extern void BMP_WIN_TransferChars(struct Descriptor *);

extern void BMP_WIN_MakeScreen(struct Cfg *);

extern void func_02041B6C(u32);

extern unsigned int func_020056BC(void);

extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);

extern int func_02028484(Blk *,void *);

extern void BMP_MENUWORK_DrawWindowBorder(void *,u32);

extern void BMP_WIN_ClearScreen(struct Descriptor *d);

extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);

extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);

extern void func_0207D658(u32, int, int);

extern void APP_TASKMENU_SetCursorPos(u8 *, int);

extern void APP_TASKMENU_CloseMenu(struct TaskMenu *);

extern void APP_TASKMENU_UpdateMenu(struct Obj *);

extern u32 BMP_MENU_ProcessYesNo(u8 *);

extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);

extern u8 APP_TASKMENU_GetCursorPos(const u8 *);

extern struct U16Vec *STRBUF_Clone(struct U16Vec *src, u32 heapId);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

extern void PRINTSYS_Print(void *,s16,s16,void *,void *);

extern void *BMP_MENU_CreateYesNo(const Record *, u16, u8, u8, u16);

extern void GFL_NET_ClearExitFlag(void);

extern void GFL_NET_IRC_WIRELESS_Exit(void);

extern int GFL_NET_IsSessionNull(void);

extern int GFL_NET_Exit(int a0);

extern void func_021D6328(u8 *p);

u8 *func_021D4D38(u16 heap, u32 mode, int a2);

void func_021D4DF4(u8 *p);

void func_021D4E04(u8 *p);

u8 *func_021D5984(u32 heap, u32 bank, u32 mode);

void func_021D5A88(u8 *p);

void func_021D5A9C(u8 *p);

void func_021D5B50(void *p, int b);

void func_021D5B5C(char *p, struct MsgBank *a, int b);

void func_021D5C24(void *p, int b);

void func_021D5C30(u8 *p, unsigned int a, int b);

int func_021D5C70(u8 *p);

void func_021D5C94(u8 *p);

void func_021D5CCC(u8 *p, u32 n);

void func_021D5D3C(u8 *p);

void *func_021D5D5C(u8 *p, int mode, int flag, int selected);

void func_021D5E34(u8 *p);

void func_021D5E48(u8 *p);

int func_021D5E6C(u8 *p);

u8 func_021D5EA8(u8 *p);

void func_021D5ED8(u8 *p,u32 n);

void func_021D5F7C(u8 *p);

u32 func_021D5FA0(u32 a);

u32 func_021D5FC4(u32 a);

void *func_021D5FE8(u8 *p, int mode, int n);

int func_021D603C(void *ctx,int unused,u8 *q);

int func_021D60D4(void *a,int b,u8 *c,u8 *p);

int func_021D6104(int a,int b,int c,u8 *p);

void func_021D6130(int *p, int v);

void func_021D6134(void *a0, StepFn fn, int a2);

int func_021D613C(u8 *p);

void func_021D6150(u8 *p);

void func_021D6198(u8 *p);

void func_021D61B8(u8 *p);

void func_021D61D8(u8 *p);

void func_021D61FC(u8 *p);

void func_021D625C(u8 *p);

void func_021D6274(u8 *p);

void func_021D6294(u8 *p);

void func_021D62B4(u8 *p);

void func_021D630C(u8 *a0);

extern const char d_021D6628[];

extern const char d_021D663C[];

extern const Record d_021D6544;

/*
 * ABI: DD60 and its forwarding chain ignore the live r0 from45088;
 *   45B38 explicitly truncates its third argument to16 at this call.
 */
u8 *func_021D5984(u32 heap, u32 bank, u32 mode)
{
    u8 *p;
    u32 sel;
    p = GFL_HEAP_Alloc(heap, 132, 1, d_021D6628, 135);
    ((struct Obj00531 *)p)->f4C = heap;
    ((struct Obj00531 *)p)->f50 = mode;
    BMP_WIN_Init(((struct Obj00531 *)p)->f4C);
    GF_FONT_InitTextColor();
    *(struct Tcbl * *)&((struct Obj00531 *)p)->f44 = TCBL_Create(((struct Obj00531 *)p)->f4C, ((struct Obj00531 *)p)->f4C, 1, 0);
    ((struct Obj00531 *)p)->f48 = PRINTSYS_QUE_Create((void *)((struct Obj00531 *)p)->f4C);
    *(struct U16Vec * *)&((struct Obj00531 *)p)->f28 = STRBUF_Create(400, ((struct Obj00531 *)p)->f4C);
    *(struct GfFont * *)&((struct Obj00531 *)p)->f24 = GF_FONT_Create(23, 0, 0, 0, ((struct Obj00531 *)p)->f4C);
    *(struct MsgBank * *)&((struct Obj00531 *)p)->f1C = MSGDATA_CreateFromArchive(0, 2, (u16)bank, ((struct Obj00531 *)p)->f4C);
    *(struct WordSet * *)&((struct Obj00531 *)p)->f20 = GF_FONT_Create_EC64(((struct Obj00531 *)p)->f4C);
    *(struct R * *)&((struct Obj00531 *)p)->f70 = APP_TASKMENU_RES_Create(5, 9, *(u32 *)&((struct Obj00531 *)p)->f24, ((struct Obj00531 *)p)->f48, ((struct Obj00531 *)p)->f4C);
    ((struct Obj00531 *)p)->f0 = BMP_MENUWORK_LoadFrameGfx((void *)func_021D5FA0(((struct Obj00531 *)p)->f50), 12, 0, ((struct Obj00531 *)p)->f4C);
    ((struct Obj00531 *)p)->f4 = BMP_MENUWORK_LoadFrameGfx((void *)func_021D5FC4(((struct Obj00531 *)p)->f50), 12, 0, ((struct Obj00531 *)p)->f4C);
    sel = 0;
    if (((struct Obj00531 *)p)->f50 == 0) sel = 4;
    ARC_UTIL_UploadPaletteFromArchiveWhole(23, 5, sel, 352, 32, ((struct Obj00531 *)p)->f4C);
    return p;
}

void func_021D5A88(u8 *p) { TCBL_Main(((struct Obj13852 *)p)->f44); PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct Obj13852 *)p)->f48); }

void func_021D5A9C(u8 *p) {
    u32 n;
    if (((struct Obj00724 *)p)->f80) { TIME_ICON_Delete(((struct Obj00724 *)p)->f80); ((struct Obj00724 *)p)->f80=0; }
    if (((struct Obj00724 *)p)->f38) { PRINTSYS_PrintStreamDelete(((struct Obj00724 *)p)->f38); ((struct Obj00724 *)p)->f38=0; }
    func_021D5D3C(p);
    n=((struct Obj00724 *)p)->f0;
    BG_SYS_DeleteHalf(func_021D5FA0(((struct Obj00724 *)p)->f50),(u16)n,(u16)(n>>16));
    n=((struct Obj00724 *)p)->f4;
    BG_SYS_DeleteHalf(func_021D5FC4(((struct Obj00724 *)p)->f50),(u16)n,(u16)(n>>16));
    GF_FONT_SetDefaultTextColor();
    WORDSET_DeleteStrbufED04(((struct Obj00724 *)p)->f20);
    MSGDATA_Delete(((struct Obj00724 *)p)->f1C);
    GF_FONT_Delete(((struct Obj00724 *)p)->f24);
    STRBUF_Delete(((struct Obj00724 *)p)->f28);
    APP_TASKMENU_RES_Delete(((struct Obj00724 *)p)->f70);
    TCBL_Destroy(((struct Obj00724 *)p)->f44);
    PRINTSYS_QUE_Clear(((struct Obj00724 *)p)->f48);
    PRINTSYS_QUE_Delete(((struct Obj00724 *)p)->f48);
    if (((struct Obj00724 *)p)->f2C) { BMP_WIN_Delete(((struct Obj00724 *)p)->f2C); ((struct Obj00724 *)p)->f2C=0; }
    if (((struct Obj00724 *)p)->f30) { BMP_WIN_Delete(((struct Obj00724 *)p)->f30); ((struct Obj00724 *)p)->f30=0; }
    BMP_WIN_Exit();
    func_020307B0(p);
}

void func_021D5B50(void *p, int b) { func_021D5B5C(p, (struct MsgBank *)(((struct Obj22602 *)p)->f1C), b); }

/*
 * note 2026-10-05 (wD9r lane A6): first read of the field at +0x50 is an int read, later reads u32; the same-type form gets CSE'd and loads r1 for +0x2c. Row set after the first call.
 */
void func_021D5B5C(char *p, struct MsgBank *a, int b)
{
    int row;
    int kind;
    u32 w;
    func_02045CAC(a, b, *(void **)(p + 0x28));
    row = 1;
    if (*(int *)(p + 0x50) != 0) row = 19;
    if (*(u32 *)(p + 0x2c) == 0) {
        *(u32 *)(p + 0x2c) = BMP_WIN_Create(func_021D5FA0(*(u32 *)(p + 0x50)), 1, row, 30, 4, 11, 1);
    }
    w = *(u32 *)(p + 0x2c);
    BMP_Clear((struct CharBuf *)BMP_WIN_GetBmp((struct Descriptor *)w), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    kind = 2;
    if (*(u32 *)(p + 0x50) == 0) kind = 6;
    func_02028470((u8 *)(p + 0x3c), (int)kind);
    if (*(u32 *)(p + 0x38) != 0) PRINTSYS_PrintStreamDelete(*(struct Rec3 **)(p + 0x38));
    *(u32 *)(p + 0x38) = PRINTSYS_PrintStream(w, 0, 0, *(u32 *)(p + 0x28), *(u32 *)(p + 0x24), MSG_SPEED_GetWait(), *(u32 *)(p + 0x44), 2, *(u16 *)(p + 0x4c), 15);
    BMP_MENUWORK_DrawWindow((void *)w, 1, (u16)(*(u32 *)p), 12);
    BMP_WIN_TransferChars((struct Descriptor *)w);
    BMP_WIN_MakeScreen((struct Cfg *)w);
    func_02041B6C(func_021D5FA0(*(u32 *)(p + 0x50)));
}

void func_021D5C24(void *p, int b) { func_021D5C30(p, ((struct Obj04466 *)p)->f1C, b); }

void func_021D5C30(u8 *p, unsigned int a, int b) {
    func_021D5B5C((char *)p, (struct MsgBank *)a, b);
    if (((struct Obj04466 *)p)->f80) {
        TIME_ICON_Delete(((struct Obj04466 *)p)->f80);
        ((struct Obj04466 *)p)->f80 = 0;
    }
    ((struct Obj04466 *)p)->f80 = TIME_ICON_Create((void *)func_020056BC(), ((struct Obj04466 *)p)->f2C, 15, 16, ((struct Obj04466 *)p)->f4C);
}

int func_021D5C70(u8 *p) { int result=1; if(((struct Obj08042 *)p)->f38) { result=func_02028484((Blk *)(p+60),((struct Obj08042 *)p)->f38); if(result) { PRINTSYS_PrintStreamDelete(((struct Obj08042 *)p)->f38); ((struct Obj08042 *)p)->f38=0; } } return result; }

void func_021D5C94(u8 *p) { if(*(u8 * *)&((struct Obj04467 *)p)->f80) { TIME_ICON_Delete(*(u8 * *)&((struct Obj04467 *)p)->f80); *(u8 * *)&((struct Obj04467 *)p)->f80=0; } if(((struct Obj04467 *)p)->f2C) { BMP_MENUWORK_DrawWindowBorder(((struct Obj04467 *)p)->f2C,2); BMP_WIN_ClearScreen(((struct Obj04467 *)p)->f2C); func_02041B6C(func_021D5FA0(((struct Obj04467 *)p)->f50)); } }

void func_021D5CCC(u8 *p, u32 n) {
    void *w;
    if (((struct Obj04468 *)p)->f34==0) ((struct Obj04468 *)p)->f34=(void *)BMP_WIN_Create(1,4,7,24,2,11,1);
    w=((struct Obj04468 *)p)->f34;
    BMP_Clear(BMP_WIN_GetBmp(w),0);
    func_02045CAC(((struct Obj04468 *)p)->f1C,n,((struct Obj04468 *)p)->f28);
    PRINTSYS_PrintColor(BMP_WIN_GetBmp(w),0,0,((struct Obj04468 *)p)->f28,((struct Obj04468 *)p)->f24,0x3cc0);
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    func_02041B6C(1);
}

void func_021D5D3C(u8 *p) { if(((struct Obj08043 *)p)->f34) { BMP_WIN_ClearScreen(((struct Obj08043 *)p)->f34); BMP_WIN_Delete(((struct Obj08043 *)p)->f34); ((struct Obj08043 *)p)->f34=0; func_02041B6C(1); } }

/*
 * evidence: 5FE8 forwards the pointer returned by matched 0201FDA0;
 * this caller consumes that return. All six observed ov115 caller sites
 * (45F8,4630,46F4,47AE,488E,4926) set mode to literal0/1, so meaningful
 * Template fields are initialized on reachable case0. Complete original
 * contexts/reference search: B10/5D5C-interface-proof.txt; body unchanged.
 */
void *func_021D5D5C(u8 *p, int mode, int flag, int selected)
{
    u8 *q = p + 0x54;
    Template t;
    ((struct Obj01535 *)q)->f0 = ((struct Obj05321 *)p)->f50;
    switch (((struct Obj01535 *)q)->f0) {
    case 0:
        t.heap = ((struct Obj05321 *)p)->f4C;
        t.count = 2;
        t.items = q + 4;
        switch (mode) {
        case 0: t.x = 32; t.y = 13; t.param = 1; break;
        case 1: t.x = 32; t.y = 24; t.param = 1; break;
        }
        t.a = 13;
        t.b = 3;
        ((struct Obj01535 *)q)->f4 = STRBUF_Create(100, ((struct Obj05321 *)p)->f4C);
        func_02045CAC(((struct Obj05321 *)p)->f1C, 28, ((struct Obj01535 *)q)->f4);
        ((struct Obj01535 *)q)->f8 = 0x39e0;
        ((struct Obj01535 *)q)->f10 = STRBUF_Create(100, ((struct Obj05321 *)p)->f4C);
        func_02045CAC(((struct Obj05321 *)p)->f1C, 29, ((struct Obj01535 *)q)->f10);
        ((struct Obj01535 *)q)->f14 = 0x39e0;
        ((struct Obj01535 *)q)->f20 = APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&t), ((struct Obj01535 *)q)->f1C);
        STRBUF_Delete(((struct Obj01535 *)q)->f4);
        STRBUF_Delete(((struct Obj01535 *)q)->f10);
        if (flag != 0) func_0207D658(0x04001050, 17, -8);
        APP_TASKMENU_SetCursorPos(*(u8 * *)&((struct Obj01535 *)q)->f20, selected);
        break;
    case 1:
        ((struct Obj01535 *)q)->f24 = func_021D5FE8(p, mode, selected);
        ((struct Obj01535 *)q)->f28 = -1;
        break;
    }
    return q;
}

void func_021D5E34(u8 *p) { switch(((struct Obj13853 *)p)->f0) { case K0: APP_TASKMENU_CloseMenu(*(struct TaskMenu * *)&((struct Obj13853 *)p)->f20); break; case K1: break; } }

void func_021D5E48(u8 *p) { switch(((struct Obj08044 *)p)->f0) { case 0: APP_TASKMENU_UpdateMenu(*(struct Obj * *)&((struct Obj08044 *)p)->f20); break; case 1: ((struct Obj08044 *)p)->f28=BMP_MENU_ProcessYesNo(*(u8 * *)&((struct Obj08044 *)p)->f24); break; } }

int func_021D5E6C(u8 *p) { switch(((struct Obj10334 *)p)->f0) { case 0: return APP_TASKMENU_IsFinish(((struct Obj10334 *)p)->f20); case 1: if(((struct Obj10334 *)p)->f28!=-1) return 1; else return 0; default: func_02034714(d_021D663C,0,d_021D663C); return 0; } }

u8 func_021D5EA8(u8 *p) { switch(((struct Obj10335 *)p)->f0) { case 0: return APP_TASKMENU_GetCursorPos(*(const u8 * *)&((struct Obj10335 *)p)->f20); case 1: return (u8)((struct Obj10335 *)p)->f28; default: func_02034714(d_021D663C,0,d_021D663C); return 0; } }

void func_021D5ED8(u8 *p,u32 n) {
    void *w;
    void *s;
    func_02045CAC(((struct Obj01720 *)p)->f1C,n,((struct Obj01720 *)p)->f28);
    s=STRBUF_Clone(((struct Obj01720 *)p)->f28,((struct Obj01720 *)p)->f4C);
    WORDSET_CopyTaggedText(((struct Obj01720 *)p)->f20,((struct Obj01720 *)p)->f28,s);
    if (((struct Obj01720 *)p)->f30==0) ((struct Obj01720 *)p)->f30=(void *)BMP_WIN_Create(func_021D5FC4(((struct Obj01720 *)p)->f50),1,1,30,16,11,1);
    w=((struct Obj01720 *)p)->f30;
    BMP_Clear(BMP_WIN_GetBmp(w),15);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(BMP_WIN_GetBmp(w),0,0,((struct Obj01720 *)p)->f28,((struct Obj01720 *)p)->f24);
    BMP_MENUWORK_DrawWindow(w,(u32)1,(u16)(((struct Obj01720 *)p)->f4),(u32)12);
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    func_02041B6C(func_021D5FC4(((struct Obj01720 *)p)->f50));
    STRBUF_Delete(s);
}

void func_021D5F7C(u8 *p) { if(((struct Obj08045 *)p)->f30){BMP_MENUWORK_DrawWindowBorder(((struct Obj08045 *)p)->f30,2);BMP_WIN_ClearScreen(((struct Obj08045 *)p)->f30);func_02041B6C(func_021D5FC4(((struct Obj08045 *)p)->f50));} }

u32 func_021D5FA0(u32 a) { switch(a){case 1:return 1;case 0:return 5;default:func_02034714(d_021D663C,0,d_021D663C);return 0;} }

u32 func_021D5FC4(u32 a) { switch(a){case 1:return 2;case 0:return 5;default:func_02034714(d_021D663C,0,d_021D663C);return 0;} }

void *func_021D5FE8(u8 *p, int mode, int n) {
    Record r = d_021D6544;
    r.e = ((struct Obj13854 *)p)->f0;
    switch (mode) {
    case 0: r.b = 24; r.c = 13; break;
    case 1: r.b = 24; r.c = 19; break;
    }
    return BMP_MENU_CreateYesNo(&r, r.e, 12, n, ((struct Obj13854 *)p)->f4C);
}

int func_021D603C(void *ctx,int unused,u8 *q) {
    u8 *p;
    BOOL flag;
    GFL_HEAP_CreateChildHeap(1,121,0x18000);
    p=PROCSYS_AllocProcWork(ctx,32,121);
    MI_CpuFill8(p,0,32);
    *(u8 * *)&((struct Obj03766 *)p)->f10=q;
    ((struct Obj03766 *)p)->f14=121;
    if(((struct Obj03767 *)q)->f10==0) ((struct Obj03767 *)q)->f10=6;
    ((struct Obj03766 *)p)->f4=func_021D4D38(((struct Obj03766 *)p)->f14,*(int *)&((struct Obj03767 *)q)->f4,((struct Obj03767 *)q)->f8);
    ((struct Obj03766 *)p)->f8=func_021D5984(((struct Obj03766 *)p)->f14,232,((struct Obj03767 *)q)->f8);
    func_021D6134(p,func_021D6150,173);
    if(((struct Obj03767 *)q)->f4==0) {
        func_021D5CCC(((struct Obj03766 *)p)->f8,36);
        if(((struct Obj03767 *)q)->fC==0) GFL_USE_CancelChangeAndPlayBgm(1153,65535);
    }
    if(*(u32 *)&((struct Obj03767 *)q)->f8==0) flag=FALSE; else flag=TRUE;
    GFL_NET_RestartWithDefaultTimeout(flag,((struct Obj03766 *)p)->f14);
    return 1;
}

int func_021D60D4(void *a,int b,u8 *c,u8 *p) { if(!((struct Obj22603 *)c)->f4)func_021D5D3C(((struct Obj10336 *)p)->f8);func_021D5A9C(*(u8 * *)&((struct Obj10336 *)p)->f8);func_021D4E04(*(u8 * *)&((struct Obj10336 *)p)->f4);func_020315D4(a);GFL_HEAP_DeleteChecked(121);return 1; }

int func_021D6104(int a,int b,int c,u8 *p) { int result;if(((struct Obj06415 *)p)->f0)func_021D5E48(((struct Obj06415 *)p)->f0);func_021D4DF4(((struct Obj06415 *)p)->f4);func_021D5A88(((struct Obj06415 *)p)->f8);result=0;if(func_021D613C(p))result=1;return result; }

void func_021D6130(int *p, int v)
{
    ((struct Obj22604 *)p)->fC = v;
}

/*
 * Byte-correct but witness-blocked (MATCH).
 * +0004 ABS32 func_021D6130          -> unresolved: 021D6130 (arm, from name) has no witness outside 021D6134..021D613C; 9 overlays overlap this address (ov016, ov021, ov093, ov115, ov118, ov120, ov123, ov131, ov175), none resolvable without a region hint on the symbols: line
 */
void func_021D6134(void *a0, StepFn fn, int a2) { func_021D6130(a0, (int)fn); }

int func_021D613C(u8 *p) { void (*cb)(u8 *);cb=*(void (**)(u8 *))(p+12);if(cb){cb(p);return 0;}return 1; }

void func_021D6150(u8 *p) {
    int color;
    if (((struct Obj22605 *)(*(u8 * *)&((struct Obj13855 *)p)->f10))->f10 & 8) color = 0x7fff;
    else color = 0;
    WIPE_SYS_Start(0, 1, 1, (u16)color, 6, 1, ((struct Obj13855 *)p)->f14);
    func_021D6134(p, func_021D6198, 0x15b);
}

void func_021D6198(u8 *p) { if(WIPE_SYS_EndCheck())func_021D6134(p,func_021D61B8,0x169); }

void func_021D61B8(u8 *p) { func_021D5C24(((struct Obj22606 *)p)->f8,26);func_021D6134(p, func_021D61D8, 0x194); }

void func_021D61D8(u8 *p) { if(func_021D5C70(((struct Obj22607 *)p)->f8))func_021D6134(p,func_021D61FC,0x1a2); }

void func_021D61FC(u8 *p) {
    if (func_0200FB24()) {
        GFL_NET_ClearExitFlag(); GFL_NET_IRC_WIRELESS_Exit(); GFL_NET_STATE_ClearErrorMode(); GFL_NET_STATE_SetWifiError(); func_0200FBA0();
    }
    if (GFL_NET_IsSessionNull()) {
        func_021D6134(p,func_021D6274,0x1bf);
        return;
    }
    if (GFL_NET_Exit((int)func_021D6328)) func_021D6134(p,func_021D625C,0x1c7);
}

void func_021D625C(u8 *p) { if(((struct Obj22608 *)p)->f18)func_021D6134(p,func_021D6274,0x1d8); }

void func_021D6274(u8 *p) { func_021D5C24(((struct Obj22609 *)p)->f8,27);func_021D6134(p,func_021D6294,0x1e6); }

void func_021D6294(u8 *p) { if(func_021D5C70(((struct Obj22610 *)p)->f8))func_021D6134(p,func_021D62B4,0x1f4); }

void func_021D62B4(u8 *p) {
    int color;
    u8 *q = *(u8 * *)&((struct Obj13856 *)p)->f10;
    if (((struct Obj13857 *)q)->f10 & 16) color = 0x7fff;
    else color = 0;
    if (((struct Obj13857 *)q)->fC == 0) GFL_USE_FadeOutBgm(6);
    WIPE_SYS_Start(0, 0, 0, (u16)color, 6, 1, ((struct Obj13856 *)p)->f14);
    func_021D6134(p, func_021D630C, 0x213);
}

void func_021D630C(u8 *a0)
{
    if (WIPE_SYS_EndCheck())
        func_021D6134(a0, 0, 0x221);
}

void func_021D6328(u8 *p) { ((struct Obj22611 *)p)->f18=1; }
