/*
 * file:     mailview.c
 * unit:     yes
 * function: func_021C446C, func_021C44FC, func_021C4528, func_021C4534, func_021C4538, func_021C4590, func_021C45C0, func_021C4700, func_021C479C, func_021C47C4, func_021C483C, func_021C48FC, func_021C4998, func_021C49D0, func_021C4AF8, func_021C4B5C, func_021C4B88, func_021C4BFC, func_021C4C9C, func_021C4D14, func_021C4D54, func_021C4DA8, func_021C4DD4, func_021C4DE4, func_021C4EC4, func_021C4EEC, func_021C5114, func_021C515C, func_021C5268, func_021C52F8, func_021C5360, func_021C5420, func_021C5470, func_021C5480, func_021C54C8, func_021C54DC, func_021C54FC, func_021C5508
 * address:  0x021C446C
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   PMSI_PARAM_IsComplete 0x02024464 thumb
 *   PMSI_PARAM_IsEnabled 0x02024450 thumb
 *   d_021C77A0 0x021C77A0 data a1
 *   PALANM_BlendChannel 0x02021FD8 thumb
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   KEY_GetCont 0x0203630C arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   _s32_div_f 0x0209C0A4 arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_021C7784 0x021C7784 data a4
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02045EC0 0x02045EC0 arm
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   APP_TASKMENU_WIN_ResetDecide 0x020282A4 thumb
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   APP_TASKMENU_WIN_TransChar 0x02028454 thumb
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   SDK_AUTOLOAD_MAIN_TWL_START 0x02FE0000 data
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   func_020419E4 0x020419E4 arm
 *   func_02045B38 0x02045B38 arm
 *   STRBUF_Create 0x020457B0 arm
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030734 0x02030734 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02030DA8 0x02030DA8 arm
 *   d_021C7EF8 0x021C7EF8 data a1
 *   MSGDATA_Delete 0x02045C04 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   CLACT_CreateUnit 0x0204B100 arm
 *   PMS_DRAW_SetNullColorPalette 0x0202DE5C thumb
 *   PMS_DRAW_Delete 0x0202DC08 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   d_021C77C4 0x021C77C4 data a1
 *   func_0203FC28 0x0203FC28 arm
 *   func_0204363C 0x0204363C arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   g_77F4 0x021C77F4 data
 *   g_7804 0x021C7804 data
 *   func_020403F4 0x020403F4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0201F5BC 0x0201F5BC thumb
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_LoadHandlePaletteToSlot 0x020216B4 thumb
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   func_0201F548 0x0201F548 thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   PALANM_Delete 0x02021540 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0207D63C 0x0207D63C arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   PMS_DRAW_Print 0x0202DC48 thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MIi_CpuClearFast 0x02082AC0 arm
 *   func_02008FEC 0x02008FEC thumb
 *   PROCSYS_Create 0x02031324 arm
 *   func_021C68A0 0x021C68A0 thumb
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_0203084C 0x0203084C arm
 *   func_020306F0 0x020306F0 arm
 *   d_021C78E0 0x021C78E0 data a1
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb  arm9
 *   APP_TASKMENU_WIN_ClearScreen  0x0202843C  thumb  arm9
 *   PMS_DRAW_Create  0x0202DB0C  thumb  arm9
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb  arm9
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb  arm9
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb  arm9
 */
#include "ov136_types.h"

struct T;
struct Chan02021FD8;
struct Obj;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec3;
struct TaskMenu;
struct TaskMenuTmpl;
struct U16Vec;
struct S02021D50;
struct R;
struct Ctx;
struct Obj02021EE4;
struct Rec;
struct TaskMenuState;
struct Bank;
struct PmsDraw;
struct PrintSys;
struct DispVram;
struct PalAnmSlot;
struct Node;
struct Obj0203159C;
struct Sub02008F80Obj;
struct S020314B8;
struct S020315D4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char s8;

typedef struct { u32 heap; u8 count; u8 pad[3]; void *items; u32 zero; u8 x,y,w,h; } Template;

struct DispConfig { u32 w[4]; };

struct BgTemplate { u32 w[8]; };

struct BgSet { struct BgTemplate t[5]; };

typedef struct {
    void *win;
    u8 flag;
    u8 pad5[3];
} WinSlot;

typedef struct {
    u32 heapId;
    u8 pad4[0x44 - 4];
    void *win[7];
    WinSlot slot[6];
    u8 pad90[0x98 - 0x90];
    void *f98;
} Obj;

extern int PMSI_PARAM_IsComplete(struct T *p, u32 a1);
extern int PMSI_PARAM_IsEnabled(const u16 *p);
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int TOUCHPANEL_GetCont(void);
extern unsigned int KEY_GetCont(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);
extern int TOUCHPANEL_HitTrg(const void *p);
extern void func_0201F73C(void *, int, int, int);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 PRINTSYS_PrintStream(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *p);
extern void APP_TASKMENU_WIN_ResetDecide(struct Obj *obj);
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(struct TaskMenuTmpl *tmpl, void *arg1);
extern void APP_TASKMENU_WIN_ClearScreen(u8 *p);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void APP_TASKMENU_UpdateMenu(void *p);
extern void APP_TASKMENU_WIN_TransChar(u8 *p);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern void CLACT_VBlankSystem(void);
extern void func_020419E4(void);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern struct R *APP_TASKMENU_RES_Create(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void PALANM_SetAutoTransfer(struct Obj02021EE4 *o, int v);
extern u32 func_02030CB0(u32 idx);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void *func_02030DA8(void *, void (*)(void *, u8 *), u8 *, int);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct PmsDraw *PMS_DRAW_Create(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
extern void PMS_DRAW_SetNullColorPalette(struct PmsDraw *p, u8 v);
extern void PMS_DRAW_Delete(struct Obj *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *);
extern void func_0204363C(u32);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_020403F4(u32 i);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *PALANM_Create(u32 heap);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_LoadHandlePaletteToSlot(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern u8 func_0201F548(int i);
extern void func_0201DD68(void);
extern void ARC_TOOL_DeleteHandle(void *h);
extern void func_02041300(unsigned int, int, int, int, unsigned char, unsigned char, unsigned char);
extern void func_02041B6C(u32 layer);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *a0);
extern void func_02030EAC(struct Node *n);
extern void func_02030DA4(void *);
extern u32 func_020307B0(void *p);
extern void func_0207D63C(void *, int, int, int, int);
extern void BMP_WIN_Init(u16);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 APP_TASKMENU_WIN_Create(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
extern void PMS_DRAW_Print(u32 a, u32 b, u32 c, u32 d);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void CLACT_ExitSystem(void);
extern void GFL_HEAP_CreateChildHeap(unsigned int,unsigned int,unsigned int);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MIi_CpuClearFast(int,void *,int);
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern void *PROCSYS_Create(int);
extern int func_021C68A0(u8 *p, int *st);
extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void *func_0203084C(u32 heapId);
extern void func_020306F0(u32 v);
int func_021C446C(void *a);
void func_021C44FC(u8 *p);
int func_021C4528(void *a);
int func_021C4534(void);
int func_021C4538(u8 *p);
int func_021C4590(u8 *p);
int func_021C45C0(u8 *p);
int func_021C4700(u8 *p);
int func_021C479C(u8 *p);
void func_021C47C4(u8 *p, int n);
int func_021C483C(u8 *p);
void func_021C48FC(u8 *p);
int func_021C4998(u8 *p);
int func_021C49D0(u8 *p);
void func_021C4AF8(void);
void func_021C4B5C(void *a, u32 *p);
void func_021C4B88(void *unused, u8 *p);
int func_021C4BFC(u8 *p);
void func_021C4C9C(u8 *p);
int func_021C4D14(u8 *p);
void func_021C4D54(u8 *p);
void func_021C4DA8(u8 *p);
void func_021C4DD4(void);
void func_021C4DE4(u32 *p);
void func_021C4EC4(void *p);
void func_021C4EEC(u8 *p);
void func_021C5114(u8 *p);
void func_021C515C(Obj *p);
void func_021C5268(u8 *p);
void func_021C52F8(u8 *p);
void func_021C5360(u8 *p);
void func_021C5420(u8 *p);
void func_021C5470(u8 *p);
int func_021C5480(void *a, int unused, void **arg);
int func_021C54C8(void *a, void *b, void *c, void *p);
int func_021C54DC(void *a, void *b, void *c, u32 *p);
void func_021C54FC(void *unused);
void func_021C5508(void);
extern const u8 d_021C77A0[][3];
extern u8 d_021C7784[];
extern u32 SDK_AUTOLOAD_MAIN_TWL_START[];
extern char d_021C7EF8[];
extern const char d_021C77C4[];
extern const struct DispConfig g_77F4;
extern const struct BgSet g_7804;
extern u8 gClActorInitParam[];
extern const char d_021C78E0[];



int func_021C446C(void *a)
{
    int t = 1;
    int n = 0;
    int c0 = 0;
    int c1 = 0;
    int i;
    for (i = 0; i < 3; i++) {
        if (d_021C77A0[((u8 *)((struct MailViewCtx *)a)->f1C)[0xb]][i] != 0xFF) n++;
    }
    if (n == 3) t = 0;
    for (i = 0; i < 3; i++) {
        u8 *x = *(u8 * *)&((struct MailViewCtx *)a)->f1C;
        if (d_021C77A0[x[0xb]][i] != 0xFF) {
            if (PMSI_PARAM_IsComplete((struct T *)(x + 0x16 + i * 8), 0x64)) c1++;
        } else {
            if (PMSI_PARAM_IsEnabled((u16 *)(x + 0x16 + i * 8))) c0++;
        }
    }
    if (c0 < t || c1 < n) return 1;
    return 0;
}



void func_021C44FC(u8 *p)
{
    PALANM_BlendChannel((struct Chan02021FD8 *)(*(u32 *)&((struct MailViewCtx *)p)->f38), 0, (u16)(p[0x1b] + 0x21), 1, 0, 0x7FFF);
    p[0x19] = 0;
    p[0x18] = 0;
}



int func_021C4528(void *a)
{
    func_021C44FC(a);
    return 0;
}



int func_021C4534(void)
{
    return 0;
}



/*
 * tail: 021C458E..021C4590 zero alignment padding.
 */
int func_021C4538(u8 *p)
{
    if (p[0xA] == 0) {
        if (TOUCHPANEL_GetCont()) return 0;
        if (KEY_GetCont()) {
            if (*(void (**)(void *))(p + 0x3C)) (*(void (**)(void *))(p + 0x3C))(p);
            p[0xA] = 1;
            return 1;
        }
    } else {
        if (KEY_GetCont()) return 0;
        if (TOUCHPANEL_GetCont()) {
            if (*(void (**)(void *))(p + 0x40)) (*(void (**)(void *))(p + 0x40))(p);
            p[0xA] = 0;
            return 0;
        }
    }
    return 0;
}



int func_021C4590(u8 *p)
{
    if (KEY_GetTrg()) {
        p[0xA] = 1;
    } else if (TOUCHPANEL_GetTrg()) {
        p[0xA] = 0;
    } else {
        return 0;
    }
    GFL_USE_PlaySeDefaultVolume(0x54E);
    return 1;
}




int func_021C45C0(u8 *p)
{
    int moved;

    if (KEY_GetTrg() & 1) {
        if (p[0x16] == 4) {
            if (func_021C446C(p)) {
                GFL_USE_PlaySeDefaultVolume(0x551);
                p[0xB] = 2;
                return 0;
            }
            **(u16 * *)&((struct MailViewCtx *)p)->f1C = 4;
            GFL_USE_PlaySeDefaultVolume(0x54E);
            (*(u8 * *)&((struct MailViewCtx *)p)->f1C)[2] = 0;
            (*(u8 * *)&((struct MailViewCtx *)p)->f1C)[3] = 0;
            APP_TASKMENU_WIN_SetDecide(((struct MailViewCtx *)p)->f128, 1);
            return 1;
        }
        if (p[0x16] == 5) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            p[0xB] = 3;
            return 0;
        }
        (*(u8 * *)&((struct MailViewCtx *)p)->f1C)[2] = p[0x16];
        **(u16 * *)&((struct MailViewCtx *)p)->f1C = (*(u8 * *)&((struct MailViewCtx *)p)->f1C)[2];
        (*(u8 * *)&((struct MailViewCtx *)p)->f1C)[3] = p[0x17];
        GFL_USE_PlaySeDefaultVolume(0x54D);
        return 1;
    }
    if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        p[0xB] = 3;
        return 0;
    }
    if (KEY_GetTrg() & 8) {
        p[0x16] = 4;
        p[0x17] = 0;
        moved = 1;
    } else if (KEY_GetTrg() & 0x80) {
        p[0x16] = (p[0x16] + 1) % 6;
        moved = 1;
    } else if (KEY_GetTrg() & 0x40) {
        p[0x16] = (p[0x16] + 5) % 6;
        moved = 1;
    } else {
        return 0;
    }
    if (moved == 0) {
        return 0;
    }
    GFL_USE_PlaySeDefaultVolume(0x54C);
    if (p[0x16] < 4) {
        APP_TASKMENU_WIN_SetActive(((struct MailViewCtx *)p)->f128, 0);
        APP_TASKMENU_WIN_SetActive(((struct MailViewCtx *)p)->f12C, 0);
    } else if (p[0x16] == 4) {
        APP_TASKMENU_WIN_SetActive(((struct MailViewCtx *)p)->f128, 1);
        APP_TASKMENU_WIN_SetActive(((struct MailViewCtx *)p)->f12C, 0);
    } else if (p[0x16] == 5) {
        APP_TASKMENU_WIN_SetActive(((struct MailViewCtx *)p)->f128, 0);
        APP_TASKMENU_WIN_SetActive(((struct MailViewCtx *)p)->f12C, 1);
    }
    p[0x1A] = p[0x16];
    return 0;
}



int func_021C4700(u8 *p)
{
    int n;
    n = TOUCHPANEL_HitTrg(d_021C7784);
    if (n == -1) return 0;
    if (n == 4) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        p[0xB] = 3;
        return 0;
    }
    if (n < 4) {
        (*(u8 * *)&((struct MailViewCtx *)p)->f1C)[2] = n;
        *(u16 *)*(u8 * *)&((struct MailViewCtx *)p)->f1C = (*(u8 * *)&((struct MailViewCtx *)p)->f1C)[2];
        (*(u8 * *)&((struct MailViewCtx *)p)->f1C)[3] = p[0x17];
        GFL_USE_PlaySeDefaultVolume(0x54D);
        return 1;
    }
    if (func_021C446C(p)) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        p[0xB] = 2;
        return 0;
    }
    *(u16 *)*(u8 * *)&((struct MailViewCtx *)p)->f1C = 4;
    GFL_USE_PlaySeDefaultVolume(0x54E);
    (*(u8 * *)&((struct MailViewCtx *)p)->f1C)[2] = 0;
    (*(u8 * *)&((struct MailViewCtx *)p)->f1C)[3] = 0;
    APP_TASKMENU_WIN_SetDecide(((struct MailViewCtx *)p)->f128, 1);
    APP_TASKMENU_WIN_SetActive(((struct MailViewCtx *)p)->f12C, 0);
    return 1;
}



int func_021C479C(u8 *p)
{
    if (func_021C4538(p)) return 0;
    if (p[0xA] == 1) return func_021C45C0(p);
    return func_021C4700(p);
}



void func_021C47C4(u8 *p, int n)
{
    void *q;
    func_0201F73C(((struct MailViewCtx *)p)->f5C, 2, 13, 4);
    BMP_Clear(BMP_WIN_GetBmp(((struct MailViewCtx *)p)->f5C), 255);
    func_02045CAC(((struct MailViewCtx *)p)->f20, n, ((struct MailViewCtx *)p)->f34);
    *(unsigned int *)&((struct MailViewCtx *)p)->f9C = PRINTSYS_PrintStream(*(u32 *)&((struct MailViewCtx *)p)->f5C, 0, 0, *(u32 *)&((struct MailViewCtx *)p)->f34, *(unsigned int *)&((struct MailViewCtx *)p)->f24, ((struct MailViewCtx *)p)->f15, *(unsigned int *)&((struct MailViewCtx *)p)->f100, 4, (u16)((struct MailViewCtx *)p)->f0, 15);
    q = ((struct MailViewCtx *)p)->f5C;
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_020409B4(BMP_WIN_GetBgLayer(q));
}



int func_021C483C(u8 *p)
{
    void *q;
    switch (((struct MailViewCtx *)p)->f8) {
    case 0:
        APP_TASKMENU_WIN_SetDecide(((struct MailViewCtx *)p)->f128, 1);
        APP_TASKMENU_WIN_SetActive(((struct MailViewCtx *)p)->f12C, 0);
        ((struct MailViewCtx *)p)->f8 = 1;
        break;
    case 1:
        if (APP_TASKMENU_WIN_IsFinish(((struct MailViewCtx *)p)->f128) != 0) {
            APP_TASKMENU_WIN_ResetDecide(((struct MailViewCtx *)p)->f128);
            APP_TASKMENU_WIN_SetActive(((struct MailViewCtx *)p)->f128, 1);
            func_021C47C4(p, 2);
            ((struct MailViewCtx *)p)->f8 = 2;
        }
        break;
    case 2:
        if (PRINTSYS_PrintStreamGetState(((struct MailViewCtx *)p)->f9C) == 2) {
            if ((KEY_GetTrg() & 1) || TOUCHPANEL_GetTrg()) {
                PRINTSYS_PrintStreamDelete(((struct MailViewCtx *)p)->f9C);
                ((struct MailViewCtx *)p)->f8 = 3;
            }
        }
        break;
    case 3:
        func_0201F7A8(((struct MailViewCtx *)p)->f5C, 2);
        q = ((struct MailViewCtx *)p)->f5C;
        BMP_WIN_ClearScreen(q);
        func_020409B4(BMP_WIN_GetBgLayer(q));
        func_021C44FC(p);
        ((struct MailViewCtx *)p)->f8 = 0;
        p[0xB] = p[0xC];
        break;
    }
    return 0;
}



void func_021C48FC(u8 *p)
{
    Template t;
    *(unsigned int *)&((struct MailViewCtx *)p)->f110 = (u32)func_02045EC0(((struct MailViewCtx *)p)->f20, 4);
    ((struct MailViewCtx *)p)->f114 = 0x39E3;
    ((struct MailViewCtx *)p)->f118 = 0;
    *(unsigned int *)&((struct MailViewCtx *)p)->f11C = (u32)func_02045EC0(((struct MailViewCtx *)p)->f20, 5);
    ((struct MailViewCtx *)p)->f120 = 0x39E3;
    ((struct MailViewCtx *)p)->f124 = 0;
    t.heap = ((struct MailViewCtx *)p)->f0;
    t.count = 2;
    t.items = p + 0x110;
    t.zero = 0;
    t.x = 23;
    t.y = 6;
    t.w = 8;
    t.h = 3;
    ((struct MailViewCtx *)p)->f10C = APP_TASKMENU_OpenMenu((struct TaskMenuTmpl *)(&t), ((struct MailViewCtx *)p)->f108);
    PALANM_BlendChannel(((struct MailViewCtx *)p)->f38, 0, 0, 48, 10, 0);
    APP_TASKMENU_WIN_ClearScreen(((struct MailViewCtx *)p)->f128);
    APP_TASKMENU_WIN_ClearScreen(((struct MailViewCtx *)p)->f12C);
}



int func_021C4998(u8 *p)
{
    int r = -1;
    if (APP_TASKMENU_IsFinish(((struct MailViewCtx *)p)->f10C)) {
        r = APP_TASKMENU_GetCursorPos(((struct MailViewCtx *)p)->f10C);
        APP_TASKMENU_CloseMenu(((struct MailViewCtx *)p)->f10C);
        STRBUF_Delete(((struct MailViewCtx *)p)->f110);
        STRBUF_Delete(((struct MailViewCtx *)p)->f11C);
    }
    return r;
}




int func_021C49D0(u8 *p)
{
    int r;
    void *w;

    switch (((struct MailViewCtx *)p)->f8) {
    case 0:
        APP_TASKMENU_WIN_SetActive(((struct MailViewCtx *)p)->f128, 0);
        APP_TASKMENU_WIN_SetDecide(((struct MailViewCtx *)p)->f12C, 1);
        break;
    case 1:
        if (APP_TASKMENU_WIN_IsFinish(((struct MailViewCtx *)p)->f12C)) {
            APP_TASKMENU_WIN_ResetDecide(((struct MailViewCtx *)p)->f12C);
            APP_TASKMENU_WIN_SetActive(((struct MailViewCtx *)p)->f12C, 1);
            *(int *)&((struct MailViewCtx *)p)->f10 = 1;
            func_021C47C4(p, 3);
            func_021C44FC(p);
            p[0x1B] = p[0x1A];
            break;
        }
        return 0;
    case 2:
        if (PRINTSYS_PrintStreamGetState(((struct MailViewCtx *)p)->f9C) == 2) {
            PRINTSYS_PrintStreamDelete(((struct MailViewCtx *)p)->f9C);
            func_021C48FC(p);
            ((struct MailViewCtx *)p)->f8 = 3;
        }
        return 0;
    case 3:
        APP_TASKMENU_UpdateMenu(((struct MailViewCtx *)p)->f10C);
        r = func_021C4998(p);
        if (r < 0)
            return 0;
        func_0201F7A8(((struct MailViewCtx *)p)->f5C, 2);
        w = ((struct MailViewCtx *)p)->f5C;
        BMP_WIN_ClearScreen(w);
        func_020409B4(BMP_WIN_GetBgLayer(w));
        ((struct MailViewCtx *)p)->f8 = 0;
        if (r == 0) {
            **(u16 * *)&((struct MailViewCtx *)p)->f1C = 0xFFFF;
            p[0xB] = p[0xC];
            return 1;
        }
        *(int *)&((struct MailViewCtx *)p)->f10 = 0;
        p[0xB] = p[0xC];
        PALANM_BlendChannel(((struct MailViewCtx *)p)->f38, 0, 0, 0x30, 0, 0);
        APP_TASKMENU_WIN_TransChar(((struct MailViewCtx *)p)->f128);
        APP_TASKMENU_WIN_TransChar(((struct MailViewCtx *)p)->f12C);
        return 0;
    }
    (((struct MailViewCtx *)p)->f8)++;
    return 0;
}



void func_021C4AF8(void)
{
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    BG_SYS_SetMainPlaneVisible(1, 0);
    BG_SYS_SetMainPlaneVisible(2, 0);
    BG_SYS_SetMainPlaneVisible(4, 0);
    BG_SYS_SetMainPlaneVisible(8, 0);
    BG_SYS_SetMainPlaneVisible(16, 0);
    BG_SYS_SetMainPlaneVisible(1, 0);
    BG_SYS_SetSubPlaneVisible(1, 0);
    BG_SYS_SetSubPlaneVisible(2, 0);
    BG_SYS_SetSubPlaneVisible(4, 0);
    BG_SYS_SetSubPlaneVisible(8, 0);
    BG_SYS_SetSubPlaneVisible(16, 0);
}



void func_021C4B5C(void *a, u32 *p)
{
    if (p[14]) PALANM_TransferPalettes((struct S02021D50 *)p[14]);
    CLACT_VBlankSystem();
    func_020419E4();
    *(u32 *)((u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3FF8) |= 1;
}



/*
 * lever: p[0x18] >> 1 promotes to signed int before the u8 argument;
 * an unsigned cast drops the narrowing shift pair, a bitfield shifts 24/25.
 */
void func_021C4B88(void *unused, u8 *p)
{
    u8 old;
    u8 direction;
    if (*(unsigned int *)&((struct MailViewCtx *)p)->f10 != 0 || p[0xA] == 0) return;
    if (p[0x1B] != p[0x1A]) {
        func_021C44FC(p);
        p[0x1B] = p[0x1A];
    }
    PALANM_BlendChannel(((struct MailViewCtx *)p)->f38, 0, (u16)(p[0x1A] + 33), 1, p[0x18] >> 1, 0x7FFF);
    direction = p[0x19];
    old = p[0x18];
    if (direction != 0) {
        p[0x18] = old - 1;
        if (old == 1) p[0x19] = direction ^ 1;
    } else {
        p[0x18] = old + 1;
        if (old == 24) p[0x19] = direction ^ 1;
    }
}



/*
 * tail: 0x021C4C9A..0x021C4C9C is a zero alignment halfword.
 */
int func_021C4BFC(u8 *p)
{
    switch (((struct MailViewCtx *)p)->f8) {
    case 0:
        ((struct MailViewCtx *)p)->f20 = func_02045B38(0, 2, 60, (u16)((struct MailViewCtx *)p)->f0);
        ((struct MailViewCtx *)p)->f34 = STRBUF_Create(128, (u16)((struct MailViewCtx *)p)->f0);
        func_021C4DE4((u32 *)p);
        break;
    case 1:
        func_021C4EEC(p);
        break;
    case 2:
        func_021C515C((Obj *)p);
        break;
    case 3:
        func_021C5420(p);
        ((struct MailViewCtx *)p)->f108 = APP_TASKMENU_RES_Create(0, 8, (u32)(((struct MailViewCtx *)p)->f24), (u32)(((struct MailViewCtx *)p)->f98), (u16)((struct MailViewCtx *)p)->f0);
        ((struct MailViewCtx *)p)->f8 = 0;
        func_021C4D54(p);
        func_021C5360(p);
        func_021C5268(p);
        func_021C4C9C(p);
        return 1;
    }
    (((struct MailViewCtx *)p)->f8)++;
    return 0;
}



void func_021C4C9C(u8 *p)
{
    void *q;
    PALANM_BlendChannel(((struct MailViewCtx *)p)->f38, 0, 0, 112, 16, 0);
    PALANM_SetAutoTransfer(((struct MailViewCtx *)p)->f38, 1);
    PALANM_TransferPalettes(((struct MailViewCtx *)p)->f38);
    p[0x18] = 0;
    p[0x19] = 0;
    q = func_02030734((u16)((struct MailViewCtx *)p)->f0, func_02030CB0(3), 0, d_021C7EF8, 0x4F3);
    ((struct MailViewCtx *)p)->fF4 = q;
    ((struct MailViewCtx *)p)->fF8 = func_02030CBC(3, q);
    ((struct MailViewCtx *)p)->fFC = func_02030DA8(((struct MailViewCtx *)p)->fF8, func_021C4B88, p, 0);
}



int func_021C4D14(u8 *p)
{
    func_021C4DA8(p);
    func_021C5470(p);
    if (p + 0x28) MSGDATA_Delete(((struct MailViewCtx *)p)->f20);
    STRBUF_Delete(((struct MailViewCtx *)p)->f34);
    APP_TASKMENU_RES_Delete(((struct MailViewCtx *)p)->f108);
    func_021C52F8(p);
    func_021C5114(p);
    func_021C4EC4(p);
    return 1;
}



void func_021C4D54(u8 *p)
{
    ((struct MailViewCtx *)p)->f158 = (void *)PRINTSYS_QUE_Create((void *)((u16)((struct MailViewCtx *)p)->f0));
    ((struct MailViewCtx *)p)->f154 = CLACT_CreateUnit(8, 1, (u16)((struct MailViewCtx *)p)->f0);
    ((struct MailViewCtx *)p)->f148 = PMS_DRAW_Create(*(u32 *)&((struct MailViewCtx *)p)->f154, 0, *(u32 *)&((struct MailViewCtx *)p)->f158, *(u32 *)&((struct MailViewCtx *)p)->f24, 0, 4, (u16)((struct MailViewCtx *)p)->f0);
    PMS_DRAW_SetNullColorPalette(((struct MailViewCtx *)p)->f148, 0);
}



void func_021C4DA8(u8 *p)
{
    PMS_DRAW_Delete(((struct MailViewCtx *)p)->f148);
    PRINTSYS_QUE_Delete(((struct MailViewCtx *)p)->f158);
    ((struct MailViewCtx *)p)->f158 = 0;
    CLACT_DeleteUnit(((struct MailViewCtx *)p)->f154);
}



void func_021C4DD4(void)
{
    BG_SYS_SetVramBanks((const struct DispVram *)d_021C77C4);
}




void func_021C4DE4(u32 *p)
{
    func_021C4DD4();
    {
        struct DispConfig d = g_77F4;
        func_0203FC28(&d);
    }
    func_0204363C(0);
    {
        struct BgSet s = g_7804;
        func_0203FCA0(0, &s.t[0], 0);
        func_0203FCA0(1, &s.t[1], 0);
        func_0203FCA0(2, &s.t[2], 0);
        func_0203FCA0(3, &s.t[3], 0);
        func_0203FCA0(4, &s.t[4], 0);
    }
    func_020414EC(0);
    func_020414EC(1);
    func_020414EC(2);
    func_020414EC(3);
    func_020414EC(4);
    func_02040B94(0, 0x20, 0, (u16)(*p));
    func_02040B94(1, 0x20, 0, (u16)(*p));
    func_02040B94(2, 0x20, 0, (u16)(*p));
    func_02040B94(3, 0x20, 0, (u16)(*p));
    func_02040B94(4, 0x20, 0, (u16)(*p));
}



void func_021C4EC4(void *p)
{
    func_020403F4(4);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_0204363C(1);
}




/*
 * note (2026-10-02): byte-correct; only the ABS32 word for func_021C4534 (an unlabelled
 *   ov136 leaf "return 0", not in any lane) lacks a witness. File that leaf, then re-verify.
 */
void func_021C4EEC(u8 *p)
{
    u32 k = (*(u8 * *)&((struct MailViewCtx *)p)->f1C)[0xB];
    void *h = func_020490F4(0x9B, (u16)((struct MailViewCtx *)p)->f0);
    u32 sz;
    u32 pal;
    u32 chr;

    func_0201F5BC(0, 1, 4, 0, (u16)((struct MailViewCtx *)p)->f0);
    func_0201F5BC(0, 0xD, 6, 0, (u16)((struct MailViewCtx *)p)->f0);
    pal = k + 0xC;
    func_02049658(h, pal, 3, 0, 0, 1, (u16)((struct MailViewCtx *)p)->f0);
    func_02049658(h, pal, 4, 0, 0, 1, (u16)((struct MailViewCtx *)p)->f0);
    chr = k + 0x18;
    sz = 0x800;
    func_020498F4(h, chr, 3, 0, sz, 1, (u16)((struct MailViewCtx *)p)->f0);
    func_020498F4(h, chr, 4, 0, sz, 1, (u16)((struct MailViewCtx *)p)->f0);
    func_02049B68(h, k, 4, 0, 0, (u16)((struct MailViewCtx *)p)->f0);
    func_02049B40(0x17, 5, 0, 0xA0, 0x20, (u16)((struct MailViewCtx *)p)->f0);
    *(unsigned int *)&((struct MailViewCtx *)p)->f38 = (u32)PALANM_Create(((struct MailViewCtx *)p)->f0);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)(*(unsigned int *)&((struct MailViewCtx *)p)->f38), 0, 0xE0, (u16)((struct MailViewCtx *)p)->f0);
    PALANM_LoadHandlePaletteToSlot((struct PalAnmSlot *)(*(unsigned int *)&((struct MailViewCtx *)p)->f38), h, k, (u16)((struct MailViewCtx *)p)->f0, 0, 0x60, 0);
    PALANM_LoadArcPaletteToSlot((struct PalAnmSlot *)(*(unsigned int *)&((struct MailViewCtx *)p)->f38), 0x17, 7, (u16)((struct MailViewCtx *)p)->f0, 0, 0x20, 0x30);
    PALANM_LoadArcPaletteToSlot((struct PalAnmSlot *)(*(unsigned int *)&((struct MailViewCtx *)p)->f38), 0x17, 5, (u16)((struct MailViewCtx *)p)->f0, 0, 0x20, 0x50);
    PALANM_LoadArcPaletteToSlot((struct PalAnmSlot *)(*(unsigned int *)&((struct MailViewCtx *)p)->f38), 5, func_0201F548(0), (u16)((struct MailViewCtx *)p)->f0, 0, 0x20, 0x40);
    PALANM_LoadArcPaletteToSlot((struct PalAnmSlot *)(*(unsigned int *)&((struct MailViewCtx *)p)->f38), 5, func_0201F548(1), (u16)((struct MailViewCtx *)p)->f0, 0, 0x20, 0x60);
    func_0201DD68();
    ARC_TOOL_DeleteHandle(h);
    func_02041300(4, 0x2001, 0, 0, 0x20, 0x20, 0x11);
    func_02041B6C(4);
    BG_SYS_SetMainPlaneVisible(1, 1);
    BG_SYS_SetMainPlaneVisible(2, 1);
    BG_SYS_SetMainPlaneVisible(8, 1);
    if (p[0xB] != 0) {
        h = func_020490F4(0x9B, (u16)((struct MailViewCtx *)p)->f0);
        func_020498F4(h, 0x24, 2, 0, sz, 1, (u16)((struct MailViewCtx *)p)->f0);
        ARC_TOOL_DeleteHandle(h);
        ((struct MailViewCtx *)p)->f3C = (void *)func_021C4534;
        ((struct MailViewCtx *)p)->f40 = (void *)func_021C4528;
        BG_SYS_SetMainPlaneVisible(4, 1);
    }
}



void func_021C5114(u8 *p)
{
    PALANM_FreeSlotBuffers(((struct MailViewCtx *)p)->f38, 0);
    PALANM_Delete(((struct MailViewCtx *)p)->f38);
    ((struct MailViewCtx *)p)->f38 = 0;
    func_02030EAC(((struct MailViewCtx *)p)->fFC);
    func_02030DA4(((struct MailViewCtx *)p)->fF8);
    func_020307B0(((struct MailViewCtx *)p)->fF4);
    func_0207D63C((void *)0x04000050, 0, 0, 31, 0);
}




void func_021C515C(Obj *p)
{
    int i;
    void *w;

    BMP_WIN_Init((u16)p->heapId);
    p->win[0] = (void *)BMP_WIN_Create(1, 0, 0, 1, 1, 5, 0);
    p->win[1] = (void *)BMP_WIN_Create(1, 3, 3, 0x1A, 4, 1, 0);
    p->win[2] = (void *)BMP_WIN_Create(1, 3, 8, 0x1A, 4, 1, 0);
    p->win[3] = (void *)BMP_WIN_Create(1, 3, 0xD, 0x1A, 4, 1, 0);
    p->win[4] = (void *)BMP_WIN_Create(1, 8, 0x13, 0xB, 2, 1, 0);
    p->win[5] = (void *)BMP_WIN_Create(1, 0x15, 0x13, 8, 2, 1, 0);
    p->win[6] = (void *)BMP_WIN_Create(0, 2, 1, 0x1C, 4, 5, 1);
    for (i = 0; i < 6; i++) {
        p->slot[i].win = p->win[i];
        p->slot[i].flag = 0;
    }
    p->f98 = (void *)PRINTSYS_QUE_Create((void *)((u16)p->heapId));
    for (i = 0; i < 7; i++) {
        BMP_Clear(BMP_WIN_GetBmp(p->win[i]), 0);
        if (i < 5) {
            w = p->win[i];
            BMP_WIN_TransferChars(w);
            BMP_WIN_MakeScreen(w);
            func_020409B4(BMP_WIN_GetBgLayer(w));
        }
    }
}


void func_021C5268(u8 *p)
{
    if (p[0xB] == 1) {
        *(unsigned int *)&((struct MailViewCtx *)p)->f130 = (u32)func_02045EC0(((struct MailViewCtx *)p)->f20, 0);
        ((struct MailViewCtx *)p)->f134 = 0x39E3;
        ((struct MailViewCtx *)p)->f138 = 0;
        *(unsigned int *)&((struct MailViewCtx *)p)->f13C = (u32)func_02045EC0(((struct MailViewCtx *)p)->f20, 1);
        ((struct MailViewCtx *)p)->f140 = 0x39E3;
        ((struct MailViewCtx *)p)->f144 = 1;
        *(unsigned int *)&((struct MailViewCtx *)p)->f128 = APP_TASKMENU_WIN_Create(*(u32 *)&((struct MailViewCtx *)p)->f108, (u32)(p + 0x130), 21, 18, 10, (u16)((struct MailViewCtx *)p)->f0);
        *(unsigned int *)&((struct MailViewCtx *)p)->f12C = APP_TASKMENU_WIN_Create(*(u32 *)&((struct MailViewCtx *)p)->f108, (u32)(p + 0x13C), 21, 21, 10, (u16)((struct MailViewCtx *)p)->f0);
    }
}


/*
 * lever: base + i * 4 + 0x44 keeps the base-plus-index inside the loop;
 * base + 0x44 + i * 4 hoists the field address and changes the loads.
 */
void func_021C52F8(u8 *p)
{
    int i;
    void *q;
    if (p[0xB] == 1) {
        APP_TASKMENU_WIN_Delete(((struct MailViewCtx *)p)->f128);
        APP_TASKMENU_WIN_Delete(((struct MailViewCtx *)p)->f12C);
        STRBUF_Delete(((struct MailViewCtx *)p)->f130);
        STRBUF_Delete(((struct MailViewCtx *)p)->f13C);
    }
    PRINTSYS_QUE_Delete(((struct MailViewCtx *)p)->f98);
    ((struct MailViewCtx *)p)->f98 = 0;
    for (i = 0; i < 7; i++) {
        q = *(void **)(p + i * 4 + 0x44);
        BMP_WIN_ClearScreen(q);
        func_020409B4(BMP_WIN_GetBgLayer(q));
        BMP_WIN_Delete(*(void **)(p + i * 4 + 0x44));
    }
    BMP_WIN_Exit();
}



/*
 * note: 2026-10-02 byte-exact; waiting on arm9 witness shard for PMSI_PARAM_IsEnabled
 */
void func_021C5360(u8 *p)
{
    int i;
    u8 *q;
    u32 t;
    for (i = 0; i < 3; i++) {
        if (PMSI_PARAM_IsEnabled((u16 *)(*(u8 * *)&((struct MailViewCtx *)p)->f1C + 0x16 + i * 8))) {
            PMS_DRAW_Print(*(u32 *)&((struct MailViewCtx *)p)->f148, *(u32 *)(p + i * 4 + 0x48), (u32)(*(u8 * *)&((struct MailViewCtx *)p)->f1C + 0x16 + i * 8), (u8)i);
        }
    }
    q = *(u8 * *)&((struct MailViewCtx *)p)->f1C;
    if (((struct MailViewCtx_f1C *)q)->f32 != 0xFFFF) {
        ((struct MailViewCtx *)p)->f14C = 6;
        ((struct MailViewCtx *)p)->f14E = 0;
        ((struct MailViewCtx *)p)->f150 = ((struct MailViewCtx_f1C *)q)->f32;
        PMS_DRAW_Print(*(u32 *)&((struct MailViewCtx *)p)->f148, ((struct MailViewCtx *)p)->f54, (u32)(p + 0x14C), (u8)3);
    }
    if (p[0xB] == 0) {
        u32 a = *(u32 *)&((struct MailViewCtx *)p)->f98;
        PRINTSYS_PrintQueColor((void *)a, (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct MailViewCtx *)p)->f88), 0, 2, (u32)(((struct MailViewCtx_f1C *)((struct MailViewCtx *)p)->f1C)->fC), *(u32 *)&((struct MailViewCtx *)p)->f24, 0x440);
        p[0x8C] = 1;
        t = ((struct MailViewCtx *)p)->f58;
        BMP_WIN_TransferChars((struct Descriptor *)t);
        BMP_WIN_MakeScreen((struct Cfg *)t);
        func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)t));
    }
}


void func_021C5420(u8 *p)
{
    CLACT_InitSystem((const struct Cfg *)gClActorInitParam,(unsigned int)d_021C77C4,(u16)(*(int *)&((struct MailViewCtx *)p)->f0));
    ((struct MailViewCtx *)p)->fA0 = CLACT_CreateUnit(4,(int)0,(u16)(*(int *)&((struct MailViewCtx *)p)->f0));
    CLACT_SetUnitDefaultRenderer(((struct MailViewCtx *)p)->fA0);
    BG_SYS_SetMainPlaneVisible(16,1);
    BG_SYS_SetSubPlaneVisible(16,1);
    GFL_NET_RestartWithDefaultTimeout((int)0,(u16)(*(int *)&((struct MailViewCtx *)p)->f0));
}


void func_021C5470(u8 *p)
{
    CLACT_DeleteUnit(((struct MailViewCtx *)p)->fA0);
    CLACT_ExitSystem();
}


int func_021C5480(void *a, int unused, void **arg)
{
    u8 *p;
    GFL_HEAP_CreateChildHeap(1,101,65536);
    p = PROCSYS_AllocProcWork(a,52,101);
    MIi_CpuClearFast(0,p,52);
    ((struct MbSeqCtx *)p)->f4 = arg;
    ((struct MbSeqCtx *)p)->f0 = func_02008FEC(*arg);
    *(int *)&((struct MbSeqCtx *)p)->f28 = 8;
    *(int *)&((struct MbSeqCtx *)p)->f2C = 0;
    ((struct MbSeqCtx *)p)->f30 = PROCSYS_Create(101);
    return 1;
}


int func_021C54C8(void *a, void *b, void *c, void *p)
{
    if (func_021C68A0(p, b) == 0) return 1;
    return 0;
}


int func_021C54DC(void *a, void *b, void *c, u32 *p)
{
    func_0203133C((struct S020314B8 *)p[12]);
    func_020315D4(a);
    func_0203084C(0x65);
    func_020306F0(0x65);
    return 1;
}


void func_021C54FC(void *unused)
{
    func_020419E4();
    CLACT_VBlankSystem();
}


void func_021C5508(void)
{
    BG_SYS_SetVramBanks((const struct DispVram *)d_021C78E0);
}
