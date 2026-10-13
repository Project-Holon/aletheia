/*
 * file:     worldtrade_enter.c
 * unit:     yes
 * function: func_021F88B0, func_021F88D8, func_021F8908, func_021F8950, func_021F8990, func_021F89A8, func_021F89B4, func_021F89F0, func_021F8A18, func_021F8A3C, func_021F8A40, func_021F8A44, func_021F8A74, func_021F8A80, func_021F8AB0, func_021F8AF4, func_021F8B0C, func_021F8BBC, func_021F8BE8, func_021F8D10, func_021F8DA4, func_021F8DE4, func_021F8E58, func_021F8E88, func_021F8F5C, func_021F8F68, func_021F8F84, func_021F9024, func_021F9088, func_021F90A0, func_021F90B8, func_021F914C, func_021F91A0, func_021F91DC, func_021F9218, func_021F9254, func_021F9260, func_021F9660, func_021F9890, func_021F9968, func_021F99D0, func_021F99F0, func_021F9A1C, func_021F9A88, func_021F9CB0, func_021F9CDC, func_021F9EEC, func_021F9F00, func_021F9F58, func_021F9FF0, func_021FA15C, func_021FA2B0, func_021FA330, func_021FA394, func_021FA4FC, func_021FA514, func_021FA760, func_021FA7C4, func_021FA85C, func_021FA9C8, func_021FAAD4, func_021FAB70, func_021FAC50, func_021FAC84, func_021FAC8C, func_021FAD08, func_021FAD24, func_021FAD84, func_021FADA8, func_021FADF0, func_021FAE2C, func_021FAE8C, func_021FAEE0, func_021FAFF0, func_021FB164, func_021FB1E4, func_021FB220, func_021FB240, func_021FB26C, func_021FB2F0, func_021FB364, func_021FB3D8, func_021FB510, func_021FB588, func_021FB5E4, func_021FB614, func_021FB674, func_021FB704, func_021FB7A0
 * address:  0x021F88B0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_022030E8 0x022030E8 data a2
 *   tbl_02202F0C  0x02202F0C  data
 *   BMP_MENUWORK_Create 0x0201F81C thumb
 *   BMP_MENUWORK_AddMsgItem 0x0201F878 thumb
 *   tbl_022030E8 0x022030E8 data a2
 *   func_021F50EC 0x021F50EC thumb ov135
 *   d_02203C1C 0x02203C1C data a4
 *   func_021F5074  0x021F5074  thumb  ov135
 *   func_021F4EC8  0x021F4EC8  thumb  ov135
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   func_021F4EC0  0x021F4EC0  thumb
 *   func_02168064  0x02168064  arm
 *   func_02168124 0x02168124 arm ov009
 *   func_02008540 0x02008540 thumb
 *   func_0200853C 0x0200853C thumb
 *   DWC_CreateFriendKey 0x0205994C arm
 *   DPW_TR_Init 0x021C7BA0 arm ov114
 *   func_021F513C  0x021F513C  thumb  ov135
 *   func_021F4FC4  0x021F4FC4  thumb  ov135
 *   DPW_TR_Main  0x021C7C1C  arm
 *   DPW_TR_IsAsyncEnd  0x021C866C  arm
 *   DPW_TR_GetAsyncResult  0x021C86A8  arm
 *   NHTTP_RAP_InitTrainerInfo 0x021B9B00 thumb ov114
 *   DPW_TR_SetProfileAsync 0x021C8E18 arm ov114
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_Push 0x02031348 arm
 *   str_02203C34 0x02203C34 data a1
 *   gNetSaveMainProc 0x021D6338 data ov115 a4
 *   ov115_id 0x00000073 data
 *   func_020307B0 0x020307B0 arm
 *   func_020120F4 0x020120F4 thumb
 *   GFL_NET_ERR_ShowScreen 0x0200F7B8 thumb
 *   tbl_021D654C 0x021D654C data ov115 a4
 *   func_021D5B5C 0x021D5B5C thumb ov115
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_021C8658 0x021C8658 arm ov114
 *   DWC_ShutdownFriendsMatch 0x0216AD50 arm ov009
 *   func_0205CC20 0x0205CC20 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02202878 0x02202878 thumb ov135
 *   func_02202858 0x02202858 thumb ov135
 *   func_022026C4 0x022026C4 thumb ov135
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   func_022028C8  0x022028C8  thumb  ov135
 *   tbl_022031EC   0x022031EC  data
 *   func_02040C14  0x02040C14  arm
 *   BMP_WIN_Create   0x020450F0  arm
 *   BMP_Clear   0x02043B5C  arm
 *   data_02203200  0x02203200  data
 *   data_02203206  0x02203206  data
 *   data_0220322A  0x0220322A  data
 *   data_02203242  0x02203242  data
 *   data_022032AE  0x022032AE  data
 *   BGWINFRM_GetPos  0x0202CF98  thumb
 *   BMP_WIN_Delete  0x020452E8  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040DA8  0x02040DA8  arm
 *   BGWINFRM_Create  0x0202C9B4  thumb
 *   BGWINFRM_AddFrame  0x0202CA3C  thumb
 *   func_021F4FF4  0x021F4FF4  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   func_02202974  0x02202974  thumb
 *   func_022026D8  0x022026D8  thumb
 *   g_02203CD8     0x02203CD8  data  ov135
 *   func_02202744  0x02202744  thumb  ov135
 *   func_022029D4  0x022029D4  thumb  ov135
 *   tbl_02203C48  0x02203C48  data  a4
 *   func_02202770  0x02202770  thumb
 *   func_022029F8  0x022029F8  thumb
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   tbl_02203370   0x02203370  data  a1
 *   tbl_022033C8   0x022033C8  data  a1
 *   tbl_022032DE   0x022032DE  data  a1
 *   tbl_02203270   0x02203270  data  a1
 *   tbl_022032FE   0x022032FE  data  a1
 *   tbl_02203284   0x02203284  data  a1
 *   KEY_GetTrg  0x020362DC  arm
 *   func_020355C4  0x020355C4  arm
 *   func_020355D8  0x020355D8  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   KEY_GetRepeat  0x0203633C  arm
 *   func_02034714  0x02034714  arm
 *   tbl_02203348   0x02203348  data  a1
 *   tbl_022032C6   0x022032C6  data  a1
 *   tbl_022033FC   0x022033FC  data  a4
 *   tbl_02203260   0x02203260  data  a1
 *   tbl_02203324   0x02203324  data  a4
 *   func_021FBF04  0x021FBF04  thumb
 *   tbl_02203220   0x02203220  data  a1
 *   tbl_0220320E  0x0220320E  data
 *   tbl_02203250  0x02203250  data  a4
 *   tbl_02203216   0x02203216  data  a1
 *   tbl_0220339C   0x0220339C  data  a1
 *   tbl_02203298   0x02203298  data  a1
 *   tbl_02203236   0x02203236  data  a1
 *   BGWINFRM_SetFrameDataArc 0x0202CAE4 thumb
 *   BGWINFRM_GetFrameBuffer 0x0202CF84 thumb
 *   func_021F9260 0x021F9260 thumb ov135
 *   func_021FBEB8 0x021FBEB8 thumb ov135
 *   func_021FBFB0 0x021FBFB0 thumb ov135
 *   func_021FC014 0x021FC014 thumb ov135
 *   BGWINFRM_PutFrame 0x0202CB4C thumb
 *   BGWINFRM_ShowFrame 0x0202CC58 thumb
 *   BGWINFRM_StartMove 0x0202CD64 thumb
 *   func_021F87E0 0x021F87E0 thumb ov135
 *   BGWINFRM_PutBmpWin  0x0202CEBC  thumb
 *   BGWINFRM_IsMoving 0x0202CE40 thumb
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   func_021FBE84  0x021FBE84  thumb
 *   func_021FBF6C  0x021FBF6C  thumb
 *   tbl_022033F8   0x022033F8  data
 *   tbl_02203440   0x02203440  data
 *   ZUKAN_SAVE_IsSeen  0x0200D064  thumb
 *   func_021F8498  0x021F8498  thumb
 *   func_021F84BC  0x021F84BC  thumb
 *   g_022033FC  0x022033FC  data  ov135
 *   BMP_MENUWORK_Delete 0x0201F868 thumb
 *   BGWINFRM_Delete  0x0202CA0C  thumb  arm9
 *   BGWINFRM_HideFrame  0x0202CC70  thumb  arm9
 *   BGWINFRM_UpdateMoves  0x0202CD94  thumb  arm9
 *   BMP_MENULIST_Main  0x020200CC  thumb  arm9
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm  arm9
 */
#include "../../matched/include/Obj23396.h"
#include "../../matched/include/Obj23397.h"
#include "../../matched/include/Obj23398.h"
#include "../../matched/include/Obj23399.h"
#include "../../matched/include/Obj23400.h"
#include "../../matched/include/Obj23401.h"
#include "worldtrade_types.h"
#include "../../matched/include/Obj23403.h"

struct Slot;
struct Obj;
struct Sub020097BCObj;
struct DWCstAccUserData;
struct Sub0200852CObj;
struct Ctx;
struct MsgBank;
struct CharBuf;
struct Descriptor;
struct U16Vec;
struct WordSet;
struct WinMgr;
struct Obj;
struct Actor;
struct Blk37;
typedef struct {
    u8 start;
    u8 id;
} Range_021F88B0;

typedef unsigned long long u64;

typedef struct {
    void *handle;
    u32 f4, f8, fc;
    void *f10;
    u32 f14, f18, f1c;
    int (*callback_021F88B0)(void *, u8 *);
    void *user;
} State_p01;

typedef struct {
    void *save;
    int zero;
    int enabled;
    int pad[2];
    u32 (*callback_021F8DA4)(u8 *);
    void *context;
} Req_p02;

typedef struct {
    void **win;
    u8 pad4[0x18 - 4];
    struct WinMgr *f18;
    u8 pad1C[0x50 - 0x1C];
    u32 f50;
} Obj_021F9024;

typedef struct {
    u32 w00;
    u32 w04;
    u32 obj;
    u32 w0c;
    u32 w10;
    u32 w14;
    u32 w18;
    u32 w1c;
    u32 w20;
    u32 w24;
    u32 w28;
    u32 arg;
} Init;

typedef struct {
    u32 w00;
    u32 w04;
    u32 obj;
    u32 w0c;
    u32 w10;
    u32 w14;
    void *frm;
    u32 w24;
    u32 w18;
    u32 w1c;
    u32 w20;
    u32 w28;
    u8 pad30[4];
    void *ctx;
    u16 h38;
    u16 h3a;
    u16 h3c;
    u16 h3e;
    u8 b40;
    u8 b41;
    u8 pad42[2];
    u32 w44;
    u32 w48;
    u8 pad4c[4];
    u32 a;
    u8 pad54[8];
    u32 b;
    u8 pad60[0x1a];
    u8 b7a;
    u8 pad7b;
    u8 sub[0x13c];
} Menu_021F9024;

typedef struct Obj_021F99F0 Obj_021F99F0;

struct Obj_021F99F0 {
    u8 pad0[0x18];
    void *mgr;
    u8 pad1C[0x34 - 0x1C];
    void *printer;
    u8 pad38[0x48 - 0x38];
    int state;
    u8 pad4C[0x7C - 0x4C];
    u8 g[4];
};

typedef struct {
    u8 up;
    u8 down;
    u8 left;
    u8 right;
} Link;

typedef struct {
    u8 x;
    u8 y;
} Cell;

typedef struct {
    int count;
    int f4;
} Layout;

typedef struct {
    u8 x;
    u8 y;
} CurPos;

typedef struct {
    int first;
    int count;
} Range_021FA7C4;

extern void *BMP_MENUWORK_Create(u32 n, u32 heap);
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern s32 BMP_MENULIST_Main(struct Obj *o);
extern void func_020202EC(struct Obj *obj, u16 *out);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern void func_021F50EC(u8 *);
extern void func_021F5074(u8 *p);
extern void func_021F4EC8(u8 *p);
extern void GFL_USE_CancelChangeAndPlayBgm(u32 a, u32 b);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_02168064(void);
extern int func_02168124(void);
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern int func_02009CC0(void *a0);
extern void func_02008540(struct Sub0200852CObj *obj, u32 value);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern unsigned long long DWC_CreateFriendKey(struct DWCstAccUserData *userdata);
extern void DPW_TR_Init(u32 a, u32 b, u32 c, int d);
extern void func_021C8DA0(u8 *p);
extern void *DPW_TR_Main();
extern u32 DPW_TR_IsAsyncEnd();
extern s32 DPW_TR_GetAsyncResult(void);
extern void func_021F513C(u8 *p);
extern void func_021F4FC4(u8 *p);
extern void NHTTP_RAP_InitTrainerInfo(u8 *,int);
extern void DPW_TR_SetProfileAsync(u8 *,u32);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *p, u32 value, u32 size);
extern void *func_020120F4(const struct Ctx *p);
extern void PROCSYS_Push(void *h, u32 id, const void *a, void *b);
extern u32 GFL_NET_ERR_ShowScreen(u32 a0);
extern u32 func_020307B0(void *p);
extern void func_021C8658();
extern void func_021D5B5C(char *p, struct MsgBank *a, int b);
extern int func_021D5C70(u8 *p);
extern void DWC_ShutdownFriendsMatch(void);
extern void func_0205CC20(void);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_0201F73C(void *, int, int, int);
extern void func_02202878(void *a, unsigned b, unsigned c, int d, int e, u8 *p);
extern u32 func_02202858(void *p, u8 b, void *s, u32 x, u32 y, void *out);
extern int func_022026C4(u32 *p, u32 b, u32 a, u32 c);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern u32 func_022028C8(u8 *p, u32 z, u32 b, u32 r, u32 d, u32 z2, u16 f, u32 g);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern u32  BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BGWINFRM_GetPos(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void func_02041300(u32 layer, int a1, int a2, int a3, u8 a4, u8 a5, u8 a6);
extern void func_020409B4(u32 layer);
extern void func_02040DA8(u32, u32, u32);
extern struct WinMgr *BGWINFRM_Create(u32 a0, u32 a1, u32 heap);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void *func_02202974(u32 a, u32 b, u32 c, u32 heap);
extern void func_022026D8(void *ctx, u32 arg);
extern void func_02202744(u8 *p);
extern void func_022029D4(u8 *p);
extern void BGWINFRM_Delete(struct WinMgr *mgr);
extern void BGWINFRM_UpdateMoves(struct WinMgr *mgr);
extern void func_02202770(void *g);
extern void func_022029F8(void *printer);
extern int TOUCHPANEL_HitTrg(const void *p);
extern u32 KEY_GetTrg(void);
extern u8 func_020355C4(void);
extern void func_020355D8(u8 v);
extern unsigned int KEY_GetRepeat(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_0209C0A4(u8 *p, u32 n, u32 m);
extern void func_021FBF04(void *mgr, void *ctx, void *win, int page, u32 pages);
extern void BGWINFRM_SetFrameDataArc(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 BGWINFRM_GetFrameBuffer(struct WinMgr *mgr, u32 idx);
extern void func_021F9260(void *, u32);
extern void func_021FBEB8(void *, void *, void *, u32, void *);
extern int func_021FBFB0(void *, int);
extern int func_021FC014(void *, int);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void BGWINFRM_ShowFrame(struct WinMgr *mgr, u32 idx);
extern void BGWINFRM_StartMove(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern int func_021F87E0(void **, void *, int);
extern void BGWINFRM_PutBmpWin(struct WinMgr *mgr, u32 idx, void *a);
extern u32 BGWINFRM_IsMoving(struct WinMgr *mgr, u32 idx);
extern u32 CLACT_IsActorAnimActive(struct Actor *a);
extern void BGWINFRM_HideFrame(struct WinMgr *mgr, u32 idx);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void func_021FBE84(void *mgr, void *bank, void *win, u32 index, u32 x, u16 color, void *g);
extern int func_021FBF6C(Menu *m, u32 idx);
extern u32 ZUKAN_SAVE_IsSeen(struct Blk37 *p, u16 id);
extern u16 *func_021F8498(u32 heap, u32 unused, u32 *count);
extern void func_021F84BC(u32 i, int *start, int *end);
extern u32 BMP_MENUWORK_Delete(void *p);
void func_021F88B0(Work *p,u32 n);
int func_021F88D8(u32 id, u32 *start);
int func_021F8908(void **menu, void *msg, int id);
int func_021F8950(void *p, u16 *old);
void func_021F8990(WorldtradeEnterObj3 *p);
void func_021F89A8(u8 *p, int i, u16 a, u16 b);
int func_021F89B4(Work *p);
int func_021F89F0(Work *p);
u32 func_021F8A18(Menu *p);
void func_021F8A3C(Work *a0);
void func_021F8A40(void);
int func_021F8A44(Work *p);
int func_021F8A74(Work *a0);
int func_021F8A80(Work *a0);
int func_021F8AB0(u8 **p);
int func_021F8AF4(Work *p);
int func_021F8B0C(WorldtradeEnterObj2 *p);
int func_021F8BBC(Work *p);
int func_021F8BE8(Work *p);
int func_021F8D10(Work *p);
int func_021F8DA4(Work *p);
int func_021F8DE4(Work *p);
int func_021F8E58(Work *p);
int func_021F8E88(void *dialog, u8 *p);
u32 func_021F8F5C(u8 *p);
int func_021F8F68(Work *p);
int func_021F8F84(Work *p, void *dialog);
int func_021F9024(WorldtradeEnterObj1 *p, void *dialog);
void func_021F9088(u32 a, u32 b, u32 c, u32 d, u16 e);
void func_021F90A0(u32 a, u32 b, u32 c, u32 d, u16 e);
void func_021F90B8(Work *p, void *bank, u32 index, int unused1, int unused2, int slow);
int func_021F914C(void *win, void *str, int x, int align, int unused, int font, void *ctx);
int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
int func_021F91DC(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g);
void func_021F9218(void *win, void *bank, int idx, void *g);
void func_021F9254(u8 *a0);
void ov135_func_021F9260(Menu *p, u32 mode);
void func_021F9660(Obj_021F9024 *p, int mode);
Menu_021F9024 *func_021F9890(Init *init, u32 a, u32 b);
void func_021F9968(Menu *p, int mode);
void func_021F99D0(Menu *p);
int func_021F99F0(Obj_021F99F0 *p);
int func_021F9A1C(Menu *p, int mode);
int func_021F9A88(Menu *p, u8 *enable);
int func_021F9CB0(Menu *p, int v);
int func_021F9CDC(Menu *p, int base);
u32 func_021F9EEC(u8 *p, u32 n);
int func_021F9F00(Menu *m, int key);
void func_021F9F58(Menu *m, int dir);
int func_021F9FF0(Menu *m);
int func_021FA15C(Menu *p);
void func_021FA2B0(Menu *m, int dir);
int func_021FA330(Menu *m, int key);
int func_021FA394(Menu *m);
int func_021FA4FC(int unused, int mode);
int func_021FA514(Menu *p, u8 *enable);
int func_021FA760(Menu *m, int key);
void func_021FA7C4(Menu *m, int dir);
int func_021FA85C(Menu *m);
void func_021FA9C8(Menu *p, int mode, int pos);
void func_021FAAD4(Menu *p);
void func_021FAB70(Menu *p);
void func_021FAC50(void *mgr, void *win, void *str, u32 x, u16 color, void *g);
int func_021FAC84(void);
int func_021FAC8C(Menu *p);
int func_021FAD08(Menu *p);
int func_021FAD24(Menu *p);
int func_021FAD84(Menu *p);
int func_021FADA8(Menu *p);
void func_021FADF0(Menu *p);
int func_021FAE2C(Menu *p);
int func_021FAE8C(Menu *p);
int func_021FAEE0(Menu *p);
int func_021FAFF0(Menu *m);
int func_021FB164(Menu *p);
int func_021FB1E4(Menu *p);
int func_021FB220(Menu *p);
int func_021FB240(u32 unused, u32 item, u32 c, u16 *list, int start, int end);
int func_021FB26C(Item **menu, void *msg, void *bank, u32 x, u32 kind, void *bag);
void func_021FB2F0(Menu *m, int page, int total);
void func_021FB364(Menu *m, int page, int total);
int func_021FB3D8(Menu *p);
int func_021FB510(Menu *p);
int func_021FB588(Menu *p);
int func_021FB5E4(Menu *p);
int func_021FB614(Menu *p);
int func_021FB674(Menu *p);
int func_021FB704(Menu *p);
int func_021FB7A0(Menu *p);
extern const u16 d_022030E8[];
extern const Range_021F88B0 tbl_02202F0C[];
extern u16 tbl_022030E8[];
extern const char str_02203C34[], ov115_id[];
extern const u32 gNetSaveMainProc[];
extern u8 tbl_021D654C[];
extern const u32 tbl_022031EC[];
extern const u8 data_02203200[3][2];
extern const u8 data_02203206[4][2];
extern const u8 data_0220322A[4][3];
extern const u8 data_02203242[5][2];
extern const u8 data_022032AE[9][2];
extern u8 g_02203CD8[];
extern u8 tbl_02203370[];
extern u8 tbl_022033C8[];
extern u8 tbl_022032DE[];
extern u8 tbl_02203270[];
extern u8 tbl_022032FE[];
extern u8 tbl_02203284[];
extern const Link tbl_02203348[];
extern const Cell tbl_022032C6[];
extern const Layout tbl_022033FC[];
extern const Link tbl_02203260[];
extern u8 *const tbl_02203324[];
extern const CurPos tbl_02203220[];
extern const Cell tbl_0220320E[];
extern const int tbl_02203250[];
extern const CurPos tbl_02203216[];
extern const Link tbl_0220339C[];
extern const Cell tbl_02203298[];
extern const CurPos tbl_02203236[];
extern const Range_021FA7C4 tbl_022033F8[];
extern const u32 tbl_02203440[];
extern u8 g_022033FC[];





void func_021F88B0(Work *p,u32 n) { if(n==0){p->fF84=0;return;}n--;if(n<130)p->fF84=d_022030E8[n]; }





int func_021F88D8(u32 id, u32 *start)
{
    int i;

    for (i = 0; i < 28; i++) {
        if (id == tbl_02202F0C[i].id) {
            *start = tbl_02202F0C[i].start;
            return tbl_02202F0C[i + 1].start - tbl_02202F0C[i].start;
        }
    }
    return 0;
}





#pragma opt_common_subs off





/*
 * Builds a message menu: reads the entry range for an id, allocates the table
 * and fills one slot per entry. The slot call takes five arguments (heap id
 * 0x48 on the stack), as in the other matched callers of BMP_MENUWORK_AddMsgItem (the
 * arm9 definition lists four parameters; the fifth is passed but not read).
 * Closed with opt_common_subs off: the original does not share start + i
 * between the table index and the tag. 2026-10-05 (P21): plain form 16 bytes
 * off, only that pragma closes it. Table extern is not const (const gave 18).
 */
int func_021F8908(void **menu, void *msg, int id)
{
    int i;
    int count;
    u32 start;
    count = func_021F88D8(id, &start);
    *menu = BMP_MENUWORK_Create(count, 0x48);
    for (i = 0; (i < count) ? 1 : 0; i++) {
        BMP_MENUWORK_AddMsgItem(*menu, (u32)msg, tbl_022030E8[start + i], start + i + 1, 0x48);
    }
    return count;
}





#pragma opt_common_subs reset





int func_021F8950(void *p, u16 *old)
{
    u16 current;
    int result;
    result = BMP_MENULIST_Main(p);
    func_020202EC(p, &current);
    if (*old != current) {
        if (*old != 0xFFFF) GFL_USE_PlaySeDefaultVolume(0x548);
        *old = current;
    }
    return result;
}





/*
 * Clear the two ten-entry u16 tables at +4 and +0x18 and the two header words.
 */
void func_021F8990(WorldtradeEnterObj3 *p)
{
    int i;
    u16 z = 0;

    for (i = 0; i < 10; i++) {
        *(u16 *)((u8 *)p + i * 2 + 4) = z;
        *(u16 *)((u8 *)p + i * 2 + 0x18) = z;
    }
    p->f0 = z;
    p->f2 = z;
}





/*
 * Store a pair of u16 values at +4 and +0x18 of record i.
 */
void func_021F89A8(u8 *p, int i, u16 a, u16 b)
{
    u8 *q = p + i * 2;

    ((WorldtradeEnterObj4 *)q)->f4 = a;
    ((WorldtradeEnterObj4 *)q)->f18 = b;
}





/*
 * volatile: hardware read-modify-write at 021F89C6/021F89CA, 0x04000304.
 */
int func_021F89B4(Work *p) {func_021F50EC((u8 *)p);func_021F8A3C(p);*(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000);switch(p->kind){case 19:case 21:p->state=2;break;case 20:p->state=4;break;}return 1;}





extern int (*const d_02203C1C[])(void *);





int func_021F89F0(Work *p) { int state,r;state=p->state_i;r=d_02203C1C[state]((u8 *)p);if(state!=p->state_i){p->fF88=0;p->fF8A=0;}return r; }





/*
 * Run the three teardown steps, then report 4 while the +0x10 handle is gone.
 */
u32 func_021F8A18(Menu *p)
{
    func_021F8A40();
    func_021F5074((u8 *)p);
    func_021F4EC8((u8 *)p);
    if (p->down == 0) {
        return 4;
    }
    return 0;
}





/*
 * Empty stub.
 */
void func_021F8A3C(Work *a0)
{
}





void func_021F8A40(void)
{
}





int func_021F8A44(Work *p)
{
    GFL_USE_CancelChangeAndPlayBgm(0x486, 0xFFFF);
    p->state = 1;
    p->xEB2 = 1;
    p->x30 = 0;
    func_021F4EC0((u8 *)p, 1, 0);
    return 2;
}





/*
 * Call func_02168064 and report success.
 */
int func_021F8A74(Work *a0)
{
    func_02168064();
    return 1;
}





/*
 * Extent remainder: 2-byte zero alignment padding.
 */
int func_021F8A80(Work *a0) { switch(func_02168124()) {case 3:return 1;case 0:case 4:case 5:return 2;default:return 0;} }





/*
 * extent: 0x021F8AF2..0x021F8AF4 is two zero alignment bytes.
 */
int func_021F8AB0(u8 **p)
{
    void *handle;
    u32 id;
    u64 key;
    handle = func_02009860(((struct Obj23396 *)(*p))->f14);
    func_02008540(((struct Obj23397 *)(*p))->f1C, func_02009CC0(((struct Obj23398 *)(*p))->f14));
    id = func_0200853C(((struct Obj23399 *)(*p))->f1C);
    key = DWC_CreateFriendKey(handle);
    DPW_TR_Init(id, (u32)key, (u32)(key >> 32), 0);
    return 1;
}





/*
 * Hand the object over, clear the +0xf8c slot and latch 1.
 */
int func_021F8AF4(Work *p)
{
    func_021C8DA0((u8 *)p);
    p->timer = 0;
    return 1;
}





/*
 * 18-slot switch on the 0x021C86A8 index (case value = index + 15, bound 17):
 * index 14 returns 1, and four separate case groups (15, 13+16, 0+3, 1+12)
 * each call func_021F4FC4 and archive n at +0x38 before returning 2; the
 * remaining indexes fall through to the shared tail (one more func_021F4FC4)
 * and the function returns 0.  DPW_TR_Main(p) runs first, unconditionally.
 * Concrete bytes are identical to the image; the only wildcards are the two
 * BLX sites to 0x021C866C and 0x021C86A8, which carry no func_ label in any
 * overlay listing (match.py's `label` class needs exactly one listing to
 * carry the label, so no region hint can witness them).  One-line fix:
 * trace 0x021C866C / 0x021C86A8 in layout/function_starts.txt and this
 * promotes automatically.
 *
 * UNBLOCKED: DPW_TR_IsAsyncEnd (0x021C866C) and DPW_TR_GetAsyncResult
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int func_021F8B0C(WorldtradeEnterObj2 *p)
{
    s32 n;

    if (DPW_TR_IsAsyncEnd(DPW_TR_Main((u8 *)p)) != 0) {
        n = DPW_TR_GetAsyncResult();
        p->fF8C = 0;
        switch (n + 15) {
        case 15:
            return 1;
        case 16:
            func_021F4FC4((u8 *)p);
            p->f38 = n;
            return 2;
        case 14:
        case 17:
            func_021F4FC4((u8 *)p);
            p->f38 = n;
            return 2;
        case 0:
        case 3:
            func_021F4FC4((u8 *)p);
            p->f38 = n;
            return 2;
        case 1:
        case 13:
            func_021F4FC4((u8 *)p);
            p->f38 = n;
            return 2;
        }
        func_021F4FC4((u8 *)p);
        func_021F513C((u8 *)p);
    } else {
        if (++p->fF8C == 0xe10) {
            func_021F513C((u8 *)p);
        }
    }
    return 0;
}





int func_021F8BBC(Work *p) { NHTTP_RAP_InitTrainerInfo((u8 *)p+0xf18,((struct Obj23400 *)(*(u8 * *)(void **)&p->ctx))->f1C);DPW_TR_SetProfileAsync((u8 *)p+0xf18,(u32)((u8 *)p+0xf7c));p->timer=0;return 1; }





/*
 * note: 2026-10-05 wave P19: the sub switch exit (state 0, sub out of range) is a cross-jumped copy of the tail, `b 0x021F8CEC` in the image. Written as `func_021F513C(p); goto done;` after the sub switch, with `done: return 0;` at the end. EXACT in c99 and c (296 bytes). Idiom: a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy.
 */
int func_021F8BE8(Work *p)
{
    int code;

    DPW_TR_Main();
    if (DPW_TR_IsAsyncEnd() != 0) {
        code = DPW_TR_GetAsyncResult();
        p->wait = 0;
        switch (code) {
        case 0:
            switch (p->state_iF7C) {
            case 0:
                switch (p->sub_i) {
                case 0:
                    func_021F4EC0((u8 *)p, 1, 0);
                    return 1;
                case 3:
                    p->err = -5003;
                    return 2;
                case 1:
                    p->err = -5000;
                    return 2;
                case 2:
                    p->err = -5001;
                    return 2;
                }
                func_021F513C((u8 *)p);
                goto done;
            case 1:
                p->err = -5004;
                return 2;
            case 2:
                p->err = -5005;
                return 2;
            default:
                func_021F4FC4((u8 *)p);
                break;
            }
            break;
        case 1:
            func_021F4FC4((u8 *)p);
            p->err = code;
            return 2;
        case -1:
        case 2:
            func_021F4FC4((u8 *)p);
            p->err = code;
            return 2;
        case -15:
        case -12:
            func_021F4FC4((u8 *)p);
            p->err = code;
            return 2;
        case -14:
        case -2:
            func_021F4FC4((u8 *)p);
            p->err = code;
            return 2;
        default:
            func_021F4FC4((u8 *)p);
            break;
        }
        func_021F513C((u8 *)p);
    } else if (++p->wait == 0xE10) {
        func_021F513C((u8 *)p);
    }
done:
    return 0;
}





/*
 * lever: ov115 data hint is witnessed by this function loading ov115 via PROCSYS_Push; no hint remains MATCH.
 */
int func_021F8D10(Work *p)
{
    State_p01 *s;
    *(State_p01 * *)(void **)&p->req = func_02030734(0x48, sizeof(State_p01), 0, str_02203C34, 0x263);
    MI_CpuFill8(*(State_p01 * *)(void **)&p->req, 0, sizeof(State_p01));
    s = *(State_p01 * *)(void **)&p->req;
    s->handle = func_020120F4(((struct Obj23401 *)(*(u8 * *)(void **)&p->ctx))->f40);
    s->f4 = 0;
    s->f8 = 1;
    s->f10 = (u8 *)p + 0x116C;
    s->fc = 30;
    s->callback_021F88B0 = func_021F8E88;
    s->user = (u8 *)p;
    p->f12EC = 0;
    if ((*(unsigned int *)&p->kind) == 21) s->f14 = 1;
    else s->f14 = 0;
    PROCSYS_Push(p->f12F0, (u32)ov115_id, gNetSaveMainProc, *(State_p01 **)((u8 *)p + 0x10DC));
    GFL_NET_ERR_ShowScreen(0);
    p->state = 3;
    return 2;
}





int func_021F8DA4(Work *p)
{
    u32 *state = *(u32 * *)(void **)&p->req;
    if (p->busy_u == 0) {
        switch (state[7]) {
        case 0: p->state = 0; break;
        case 1:
            func_021F4EC0((u8 *)p, 0, 0);
            p->state = 1;
            break;
        }
        func_020307B0((void *)p->req);
    }
    return 2;
}





int func_021F8DE4(Work *p)
{
    Req_p02 *r;
    *(Req_p02 * *)(void **)&p->req = func_02030734(72, 28, 0, str_02203C34, 689);
    MI_CpuFill8(*(Req_p02 * *)(void **)&p->req, 0, 28);
    r = *(Req_p02 * *)(void **)&p->req;
    r->save = func_020120F4(((struct Obj23403 *)(*(u8 * *)(void **)&p->ctx))->f40);
    r->zero = 0;
    r->enabled = 1;
    r->callback_021F8DA4 = func_021F8F5C;
    r->context = (u8 *)p;
    PROCSYS_Push(p->f12F0, (u32)ov115_id, tbl_021D654C, *(Req_p02 * *)(void **)&p->req);
    p->state_i = 5;
    GFL_NET_ERR_ShowScreen(0);
    return 2;
}





int func_021F8E58(Work *p)
{
    if (p->busy_u == 0) {
        func_020307B0((void *)((*(unsigned int *)&p->req)));
        func_021F4EC0((u8 *)p, 0, 0);
        p->state = 1;
    }
    return 2;
}





int func_021F8E88(void *dialog, u8 *p)
{
    int result;
    switch (((Work *)p)->f12EC) {
    case 0:
        if (func_021F8A74((Work *)p))
            (((Work *)p)->f12EC)++;
        break;
    case 1:
        result = func_021F8A80((Work *)p);
        switch (result) {
        case 1: (((Work *)p)->f12EC)++; break;
        case 2: ((Work *)p)->f12EC = 9; break;
        }
        break;
    case 2:
        if (func_021F8AB0((u8 **)p)) (((Work *)p)->f12EC)++;
        break;
    case 3:
        if (func_021F8AF4((Work *)p)) (((Work *)p)->f12EC)++;
        break;
    case 4:
        result = func_021F8B0C((WorldtradeEnterObj2 *)p);
        switch (result) {
        case 1: (((Work *)p)->f12EC)++; break;
        case 2: ((Work *)p)->f12EC = 7; break;
        }
        break;
    case 5:
        if (func_021F8BBC((Work *)p)) (((Work *)p)->f12EC)++;
        break;
    case 6:
        result = func_021F8BE8((Work *)p);
        switch (result) {
        case 1: ((Work *)p)->f12EC = 0; return 0;
        case 2: ((Work *)p)->f12EC = 7; break;
        }
        break;
    case 7:
        if (func_021F8F84((Work *)p, dialog)) (((Work *)p)->f12EC)++;
        break;
    case 8:
        if (func_021F9024((WorldtradeEnterObj1 *)p, dialog)) (((Work *)p)->f12EC)++;
        break;
    case 9:
        ((Work *)p)->f12EC = 0;
        return 1;
    }
    return 2;
}





/*
 * Every concrete byte is reproduced.  The one wildcard is the BLX at +0002 to
 * func_021C8658, which has no independent witness outside 021F8F5C..021F8F66;
 * the resolver reports "(arm, from name) ... 8 overlays overlap this address
 * (ov016, ov021, ov093, ov111, ov114, ov128, ov172, ov208), none resolvable
 * without a region hint on the symbols: line".  Same blocker as func_02201FDC
 * and func_021FEB84/func_02201C88: naming one of those eight regions would be
 * a guess, so the site stays parked until the region that owns 0x021C8658 is
 * established.
 */
u32 func_021F8F5C(u8 *p)
{
    func_021C8658(p);
    return 0;
}





/*
 * Reset the object, latch state 0 and set the +0xeb4 slot to 1.
 */
int func_021F8F68(Work *p)
{
    func_021F4FC4((u8 *)p);
    p->state = 0;
    p->eb4 = 1;
    return 3;
}





int func_021F8F84(Work *p, void *dialog)
{
    int text;
    switch (p->err) {
    case 1: text = 166; break;
    case 2: text = 167; break;
    case -1: text = 157; break;
    case -2: text = 169; break;
    case -3: text = 162; break;
    case -4: text = 164; break;
    case -5: text = 163; break;
    case -6: text = 27; break;
    case -7: text = 28; break;
    case -8: text = 29; break;
    case -9: text = 30; break;
    case -10: text = 31; break;
    case -11: text = 32; break;
    case -12: text = 160; break;
    case -13: text = 165; break;
    case -14: text = 170; break;
    case -15: text = 161; break;
    default: text = 159; break;
    }
    func_021D5B5C(dialog, p->bank, text);
    (*(short *)&p->fF88) = 0;
    return 1;
}





int func_021F9024(WorldtradeEnterObj1 *p, void *dialog)
{
    switch (p->fF88) {
    case 0:
        (p->fF88)++;
        break;
    case 1:
        if (func_021D5C70(dialog)) (p->fF88)++;
        break;
    case 2:
        (p->fF88)++;
        break;
    case 3:
        func_021C8658();
        DWC_ShutdownFriendsMatch();
        func_0205CC20();
        (p->fF88)++;
        break;
    default:
        (p->fF8A)++;
        if (p->fF8A > 60) return 1;
        break;
    }
    return 0;
}





/*
 * Forward the u16 stack argument to func_021F90B8 with mode 1.
 */
void func_021F9088(u32 a, u32 b, u32 c, u32 d, u16 e)
{
    func_021F90B8((Work *)a, (void *)b, c, d, e, 1);
}





/*
 * Forward the u16 stack argument to func_021F90B8 with mode 0.
 */
void func_021F90A0(u32 a, u32 b, u32 c, u32 d, u16 e)
{
    func_021F90B8((Work *)a, (void *)b, c, d, e, 0);
}





void func_021F90B8(Work *p, void *bank, u32 index, int unused1, int unused2, int slow)
{
    void *str;
    str = func_02045EC0(bank, index);
    func_0201F250(p->words, p->str, str);
    STRBUF_Delete(str);
    BMP_Clear(BMP_WIN_GetBmp(p->d40), 15);
    BMP_WIN_TransferChars(p->d40);
    func_0201F73C(p->d40, 0, 1, 14);
    if (slow)
        func_02202878(p->d40, 0, (unsigned int)(p->str), 0, 0, (u8 *)p + 0xfa0);
    else
        func_02202858(p->d40, 0, p->str, 0, 0, (u8 *)p + 0xfa0);
    p->cnt = 0;
}





/*
 * lever: unused fifth argument leaves font and context in stack slots +4/+8.
 */
int func_021F914C(void *win, void *str, int x, int align, int unused, int font, void *ctx)
{
    int width;
    switch (align) {
    case 1:
        width = func_022026C4(ctx, (u8)font, (u32)str, (int)0);
        x = (BMP_WIN_GetWidth(win) * 8 - width) / 2;
        break;
    case 2:
        width = func_022026C4(ctx, (u8)font, (u32)str, (int)0);
        x = BMP_WIN_GetWidth(win) * 8 - width;
        break;
    }
    return x;
}





/*
 * Seven-argument wrapper: forwards the object, three words, the 0 and the u16/g pair to the two helpers.
 */
int func_021F91A0(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g)
{
    u32 r = func_021F914C(p, (void *)b, c, e, f, 0, (void *)g);

    return func_022028C8(p, 0, b, r, d, 0, f, g);
}





int func_021F91DC(u8 *p, u32 b, u32 c, u32 d, u32 e, u16 f, u32 g)
{
    u32 r = func_021F914C(p, (void *)b, c, e, f, 0, (void *)g);

    return func_022028C8(p, 0, b, r, d, 0, f, g);
}





void func_021F9218(void *win, void *bank, int idx, void *g)
{
    void *str;

    str = func_02045EC0(bank, tbl_022031EC[idx]);
    func_021F91A0(win, (u32)str, 0, 0, 0, 0x440, (u32)g);
    STRBUF_Delete(str);
}





/*
 * Tail call into GFL_NET_RestartWithDefaultTimeout with the fixed 0/0x48 pair.
 */
void func_021F9254(u8 *a0)
{
    GFL_NET_RestartWithDefaultTimeout(0, 0x48);
}





void ov135_func_021F9260(Menu *p, u32 mode)
{
    int i;

    func_02040C14(p->layer, 0, 1, 0);
    switch (mode) {
    case 4:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[14])), 10);
        for (i = 0; i < 9; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_022032AE[i][0], data_022032AE[i][1], 3, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[i])), 10);
        }
        break;
    case 5:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[14])), 10);
        p->wins[0] = (void *)BMP_WIN_Create((u8)p->layer, 2, 2, 3, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[0])), 7);
        for (i = 1; i < 4; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_022032AE[i - 1][0], data_022032AE[i - 1][1], 2, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[i])), 10);
        }
        break;
    case 0:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[14])), 10);
        for (i = 0; i < 4; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_0220322A[i][0], data_0220322A[i][1], 8, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[i])), 10);
        }
        p->wins[4] = (void *)BMP_WIN_Create((u8)p->layer, 5, 14, 5, 1, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[4])), 8);
        break;
    case 6:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[14])), 10);
        for (i = 0; i < 9; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_022032AE[i][0], data_022032AE[i][1], 3, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[i])), 10);
        }
        p->wins[15] = (void *)BMP_WIN_Create((u8)p->layer, 1, 2, 9, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[15])), 10);
        break;
    case 3:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 24, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[14])), 10);
        for (i = 0; i < 5; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_02203242[i][0], data_02203242[i][1], 23, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[i])), 10);
        }
        p->wins[5] = (void *)BMP_WIN_Create((u8)p->layer, 14, 16, 5, 1, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[5])), 10);
        break;
    case 1:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[14])), 10);
        for (i = 0; i < 3; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_02203200[i][0], data_02203200[i][1], 9, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[i])), 10);
        }
        break;
    case 2:
        p->wins[14] = (void *)BMP_WIN_Create((u8)p->layer, 9, 17, 6, 2, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[14])), 10);
        for (i = 0; i < 4; i++) {
            p->wins[i] = (void *)BMP_WIN_Create((u8)p->layer, data_02203206[i][0], data_02203206[i][1], 11, 2, 1, 1);
            BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[i])), 10);
        }
        p->wins[4] = (void *)BMP_WIN_Create((u8)p->layer, 5, 14, 5, 1, 1, 1);
        BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)p->wins[4])), 8);
        break;
    }
}





/*
 * Redraw the text windows of layout `mode` (0..6): clear and refresh the
 * first n windows of the window table, and when the second brightness
 * byte read by BGWINFRM_GetPos is 0x10 reset the two BG2 screen blocks
 * (func_02041300) and commit them; then refresh window 14 (and 15 for
 * layout 6) and schedule the +0x50 screen.
 */
void func_021F9660(Obj_021F9024 *p, int mode)
{
    s8 bright[2];
    int i = 0;

    BGWINFRM_GetPos(p->f18, 0, &bright[1], &bright[0]);
    switch (mode) {
    case 4:
        for (i = 0; i < 9; i++) {
            BMP_Clear(BMP_WIN_GetBmp(p->win[i]), 10);
            BMP_WIN_TransferChars(p->win[i]);
            BMP_WIN_Delete(p->win[i]);
        }
        if (bright[1] == 0x10) {
            func_02041300(2, 5, 0x10, 1, 1, 0xF, 0x10);
            func_02041300(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            func_020409B4(2);
        }
        BMP_WIN_Delete(p->win[14]);
        break;
    case 5:
        for (i = 0; i < 4; i++) {
            BMP_Clear(BMP_WIN_GetBmp(p->win[i]), 10);
            BMP_WIN_TransferChars(p->win[i]);
            BMP_WIN_Delete(p->win[i]);
        }
        if (bright[1] == 0x10) {
            func_02041300(2, 5, 0x10, 1, 1, 0xF, 0x10);
            func_02041300(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            func_020409B4(2);
        }
        BMP_WIN_Delete(p->win[14]);
        break;
    case 0:
        for (i = 0; i < 5; i++) {
            BMP_Clear(BMP_WIN_GetBmp(p->win[i]), 10);
            BMP_WIN_TransferChars(p->win[i]);
            BMP_WIN_Delete(p->win[i]);
        }
        if (bright[1] == 0x10) {
            func_02041300(2, 5, 0x10, 1, 1, 0xF, 0x10);
            func_02041300(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            func_020409B4(2);
        }
        BMP_WIN_Delete(p->win[14]);
        break;
    case 6:
        for (i = 0; i < 9; i++) {
            BMP_Clear(BMP_WIN_GetBmp(p->win[i]), 10);
            BMP_WIN_TransferChars(p->win[i]);
            BMP_WIN_Delete(p->win[i]);
        }
        if (bright[1] == 0x10) {
            func_02041300(2, 5, 0x10, 1, 1, 0xF, 0x10);
            func_02041300(2, 6, 0x11, 1, 0xF, 0xF, 0x10);
            func_020409B4(2);
        }
        BMP_WIN_Delete(p->win[14]);
        BMP_WIN_Delete(p->win[15]);
        break;
    case 3:
        for (i = 0; i < 6; i++) {
            BMP_Clear(BMP_WIN_GetBmp(p->win[i]), 10);
            BMP_WIN_TransferChars(p->win[i]);
            BMP_WIN_Delete(p->win[i]);
        }
        BMP_WIN_Delete(p->win[14]);
        break;
    case 1:
        for (i = 0; i < 3; i++) {
            BMP_WIN_Delete(p->win[i]);
        }
        BMP_WIN_Delete(p->win[14]);
        break;
    case 2:
        for (i = 0; i < 5; i++) {
            BMP_WIN_Delete(p->win[i]);
        }
        BMP_WIN_Delete(p->win[14]);
        break;
    }
    func_02040DA8(p->f50, 1, 0);
}





Menu_021F9024 *func_021F9890(Init *init, u32 a, u32 b)
{
    Menu_021F9024 *m;

    m = func_02030734(0x48, 0x1b8, 0, (const char *)g_02203CD8, 0x336);
    m->w00 = init->w00;
    m->w04 = init->w04;
    m->obj = init->obj;
    m->w0c = init->w0c;
    m->w10 = init->w10;
    m->w14 = init->w14;
    m->w18 = init->w18;
    m->w1c = init->w1c;
    m->w20 = init->w20;
    m->w24 = init->w24;
    m->w28 = init->w28;
    m->a = a;
    m->b = b;
    m->h38 = 0;
    m->h3a = 0;
    m->h3c = 0;
    m->h3e = 0;
    m->b40 = 0;
    m->b41 = 0;
    m->w44 = 0;
    m->b7a = 0;
    m->w48 = 0;
    m->frm = BGWINFRM_Create(2, 1, 0x48);
    BGWINFRM_AddFrame(m->frm, 0, 2, 0x20, 0x14);
    func_021F4FF4(m->obj, 0x90, 0x28);
    CLACT_SetActorAnimSeq((struct Obj *)m->obj, 4);
    CLACT_SetActorAutoAnim((struct Obj *)m->obj, 1);
    CLACT_SetActorDrawEnable((struct Obj *)m->obj, 0);
    m->ctx = func_02202974(0xf, 0xe, 2, 0x48);
    func_022026D8(m->sub, init->arg);
    return m;
}





/*
 * trailing: two-byte zero alignment padding at 0x021F99CE.
 */
void func_021F9968(Menu *p, int mode)
{
    p->f54 = mode;
    switch (mode) {
    case 0:
        ((u8 *)p)[122] = 0;
        p->pos = 0;
        p->layout = 0;
        p->start = 0;
        p->state = 6;
        return;
    case 3:
        ((u8 *)p)[122] = 0;
        p->pos = 0;
        p->layout = 0;
        p->start = 0;
        p->state = 18;
        return;
    case 1:
        ((u8 *)p)[122] = 0;
        p->pos = 0;
        p->state = 30;
        return;
    case 2:
        ((u8 *)p)[122] = 0;
        p->pos = 0;
        p->state = 33;
        break;
    }
}





/*
 * Tear the object down: sub-object at +0x7c, buffer at +0x34, then the object.
 */
void func_021F99D0(Menu *p)
{
    func_02202744((u8 *)p + 0x7c);
    func_022029D4(*(u8 * *)&p->num);
    BGWINFRM_Delete(*(struct WinMgr * *)&p->mgr);
    func_020307B0((void *)((u32)p));
}





extern int (*const tbl_02203C48[])(Obj_021F99F0 *p);





int func_021F99F0(Obj_021F99F0 *p)
{
    int r = tbl_02203C48[p->state](p);

    BGWINFRM_UpdateMoves(p->mgr);
    func_02202770(p->g);
    func_022029F8(p->printer);
    return r;
}





/*
 * Touch hit test against the rectangle table of screen mode `mode`
 * (0..7; modes 0/2 and 5/7 share a table). Any other mode falls off the
 * end and hands back the first argument still in r0.
 */
int func_021F9A1C(Menu *p, int mode)
{
    switch (mode) {
    case 4:
        return TOUCHPANEL_HitTrg(tbl_02203370);
    case 6:
        return TOUCHPANEL_HitTrg(tbl_022033C8);
    case 0:
    case 2:
        return TOUCHPANEL_HitTrg(tbl_022032DE);
    case 1:
        return TOUCHPANEL_HitTrg(tbl_02203270);
    case 3:
        return TOUCHPANEL_HitTrg(tbl_022032FE);
    case 5:
    case 7:
        return TOUCHPANEL_HitTrg(tbl_02203284);
    }
}





/*
 * Cursor input for the ten-entry mode-4 menu: the mode-6 grid of nine
 * entries with one button (9). Returns the entry, -2 for cancel (B or
 * the button), -1 for nothing or an entry `enable` marks off. A grid
 * position past 9 under A reports through func_02034714 (raw address
 * 0x02203CEC, a plain constant as in func_02202B20).
 */
int func_021F9A88(Menu *p, u8 *enable)
{
    int old = p->pos;
    int r;
    int ret;

    if (old < 9) {
        p->last = old;
    }
    if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)p->cursor), 1);
        func_020355D8(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -1;
    }
    if (KEY_GetRepeat() & 0x40) {
        p->pos = tbl_02203348[p->pos].up;
    } else if (KEY_GetRepeat() & 0x80) {
        p->pos = tbl_02203348[p->pos].down;
    } else if (KEY_GetRepeat() & 0x20) {
        p->pos = tbl_02203348[p->pos].left;
    } else if (KEY_GetRepeat() & 0x10) {
        p->pos = tbl_02203348[p->pos].right;
    }
    if (old >= 9 && p->pos < 9) {
        if (KEY_GetRepeat() & 0x40) {
            p->pos = p->last;
            while (p->pos + 3 < 9) {
                p->pos += 3;
            }
        } else if (KEY_GetRepeat() & 0x80) {
            p->pos = p->last;
            while (p->pos - 3 >= 0) {
                p->pos -= 3;
            }
        }
    }
    if (old != p->pos) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021F4FF4(p->cursor, (tbl_022032C6[p->pos].x + 0x10) * 8, tbl_022032C6[p->pos].y * 8);
        if (p->pos == 9) {
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 5);
        } else {
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 0x12);
        }
    }
    ret = -1;
    r = func_021F9A1C(p, 4);
    if (r != ret) {
        func_021F4FF4(p->cursor, (tbl_022032C6[r].x + 0x10) * 8, tbl_022032C6[r].y * 8);
        if (r == 9) {
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 5);
        } else {
            p->pos = r;
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 0x12);
        }
        if (r == 9) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            ret = -2;
        } else if (enable == 0 || enable[r] != 0) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            ret = r;
        }
        if (ret == -1 && func_020355C4() == 0) {
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)p->cursor), 0);
        }
        func_020355D8(1);
        return ret;
    }
    if (KEY_GetTrg() & 1) {
        if (p->pos == 9) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            return -2;
        }
        if (p->pos >= 9) {
            func_02034714((void *)0x02203CEC, 0, (void *)0x02203CEC);
        }
        if (enable == 0 || enable[p->pos] != 0) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            return p->pos;
        }
    } else if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 5);
        func_021F4FF4(p->cursor, 0xC0, 0x88);
        return -2;
    }
    return -1;
}





/*
 * Validate a touched entry index: 3 maps to -2; for layouts 0..8 (+0x38)
 * an index at or past the layout's entry count (first word of its 8-byte
 * row) maps to -1; anything else is returned unchanged.
 */
int func_021F9CB0(Menu *p, int v)
{
    if (v != 3) {
        if (p->layout <= 8) {
            if (v >= tbl_022033FC[p->layout].count) {
                v = -1;
            }
            return v;
        }
        return v;
    }
    return -2;
}





/*
 * Cursor input for the five-entry mode-5 menu: the d-pad walks the link
 * table (entry 3 is the fixed bottom button, leaving it restores the last
 * grid entry from +0x7A), a touch (func_021F9A1C) or A selects. Returns
 * the selected entry, -2 for cancel (B or the button), -1 for nothing or
 * for an entry the per-layout enable row marks unavailable at `base`.
 */
int func_021F9CDC(Menu *p, int base)
{
    int old = p->pos;
    int r;

    if (old < 3) {
        p->last = old;
    }
    if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)p->cursor), 1);
        func_020355D8(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -1;
    }
    if (KEY_GetRepeat() & 0x40) {
        p->pos = tbl_02203260[p->pos].up;
    } else if (KEY_GetRepeat() & 0x80) {
        p->pos = tbl_02203260[p->pos].down;
    } else if (KEY_GetRepeat() & 0x20) {
        p->pos = tbl_02203260[p->pos].left;
    } else if (KEY_GetRepeat() & 0x10) {
        p->pos = tbl_02203260[p->pos].right;
    }
    if (old == 3 && p->pos < 3) {
        p->pos = p->last;
    }
    if (old != p->pos) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        if (p->pos == 3) {
            func_021F4FF4(p->cursor, 0xC0, 0x88);
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 5);
        } else {
            func_021F4FF4(p->cursor, (tbl_022032C6[p->pos].x + 0x10) * 8, tbl_022032C6[p->pos].y * 8);
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 4);
        }
    }
    r = func_021F9A1C(p, 5);
    if (r != -1) {
        if (r == 3) {
            func_021F4FF4(p->cursor, 0xC0, 0x88);
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 5);
        } else {
            p->pos = r;
            func_021F4FF4(p->cursor, (tbl_022032C6[r].x + 0x10) * 8, tbl_022032C6[r].y * 8);
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 4);
        }
        r = func_021F9CB0((Menu *)p, r);
        if (r == -2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
        } else if (base == 0 || tbl_02203324[p->layout][base + r] != 0) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
        } else {
            r = -1;
            if (func_020355C4() == 0) {
                CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)p->cursor), 0);
            }
        }
        func_020355D8(1);
        return r;
    }
    if (KEY_GetTrg() & 1) {
        r = func_021F9CB0((Menu *)p, p->pos);
        if (r == -1) {
            return r;
        }
        if (r == -2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            return r;
        }
        if (base == 0 || tbl_02203324[p->layout][base + r] != 0) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            return r;
        }
    } else if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 5);
        func_021F4FF4(p->cursor, 0xC0, 0x88);
        return -2;
    }
    return -1;
}





/*
 * Step one byte short of the end, or report 1 when there is no buffer.
 */
u32 func_021F9EEC(u8 *p, u32 n)
{
    u32 m;

    if (p == 0) {
        return 1;
    }
    m = n - 1;
    return func_0209C0A4(p + m, n, m);
}





int func_021F9F00(Menu *m, int key)
{
    int idx;

    switch (key) {
    case 4:
        return -2;
    case 5:
        func_021F9F58((Menu *)m, -1);
        return -1;
    case 6:
        func_021F9F58((Menu *)m, 1);
        return -1;
    }
    idx = key + m->page * 4;
    if (idx < m->total) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return m->items[idx].val;
    }
    return -1;
}





void func_021F9F58(Menu *m, int dir)
{
    int last;

    last = func_021F9EEC((u8 *)m->total, 4) - 1;
    if (last == 0) {
        return;
    }
    if (dir < 0) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        CLACT_SetActorAutoAnim((struct Obj *)((struct Obj *)m->down), 1);
        CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)m->down), 0x27);
        if (m->page != 0) {
            m->page = m->page - 1;
        } else {
            m->page = last;
        }
    } else {
        GFL_USE_PlaySeDefaultVolume(0x548);
        CLACT_SetActorAutoAnim((struct Obj *)((struct Obj *)m->up), 1);
        CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)m->up), 0x26);
        if (m->page < last) {
            m->page = m->page + 1;
        } else {
            m->page = 0;
        }
    }
    func_021FB2F0((Menu *)m, m->page, m->total);
    func_021FBF04(m->mgr, m->num, m->wins[4], m->page, func_021F9EEC((u8 *)m->total, 4));
}





int func_021F9FF0(Menu *m)
{
    int old;
    int r;

    old = m->pos;
    if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)m->cursor), 1);
        func_020355D8(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -1;
    }
    if (KEY_GetRepeat() & 0x40) {
        if (m->pos != 0) {
            m->pos = m->pos - 1;
        } else {
            m->pos = 4;
        }
    } else if (KEY_GetRepeat() & 0x80) {
        if (m->pos != 4) {
            m->pos = m->pos + 1;
        } else {
            m->pos = 0;
        }
    } else if (KEY_GetRepeat() & 0x20) {
        func_021F9F58((Menu *)m, -1);
    } else if (KEY_GetRepeat() & 0x10) {
        func_021F9F58((Menu *)m, 1);
    }
    if (old != m->pos) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021F4FF4(m->cursor, tbl_02203220[m->pos].x, tbl_02203220[m->pos].y);
        if (m->pos == 4) {
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)m->cursor), 5);
        } else {
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)m->cursor), 6);
        }
    }
    r = func_021F9A1C(m, 0);
    if (r != -1) {
        if ((u32)r < 5) {
            func_021F4FF4(m->cursor, tbl_02203220[r].x, tbl_02203220[r].y);
            if (r == 4) {
                CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)m->cursor), 5);
            } else {
                m->pos = r;
                CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)m->cursor), 6);
            }
        }
        r = func_021F9F00((Menu *)m, r);
        if (r == -1 && func_020355C4() == 0) {
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)m->cursor), 0);
        }
        func_020355D8(1);
        return r;
    }
    if (KEY_GetTrg() & 1) {
        return func_021F9F00((Menu *)m, m->pos);
    }
    if (KEY_GetTrg() & 2) {
        func_021F4FF4(m->cursor, 0xC0, 0x88);
        CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)m->cursor), 5);
        GFL_USE_PlaySeDefaultVolume(0x551);
        return -2;
    }
    return -1;
}





int func_021FA15C(Menu *p)
{
    int old = p->pos;
    int r;

    if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)p->cursor), 1);
        func_020355D8(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -1;
    }
    if (KEY_GetRepeat() & 0x40) {
        if (p->pos != 0) {
            p->pos = p->pos - 1;
        } else {
            p->pos = 3;
        }
    } else if (KEY_GetRepeat() & 0x80) {
        if (p->pos != 3) {
            p->pos = p->pos + 1;
        } else {
            p->pos = 0;
        }
    }
    if (old != p->pos) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021F4FF4(p->cursor, tbl_0220320E[p->pos].x, tbl_0220320E[p->pos].y);
        if (p->pos == 3) {
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 5);
        } else {
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 6);
        }
    }
    r = func_021F9A1C(p, 1);
    if (r != -1) {
        func_020355D8(1);
        func_021F4FF4(p->cursor, tbl_0220320E[r].x, tbl_0220320E[r].y);
        if (r == 3) {
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 5);
        } else {
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 6);
        }
        r = tbl_02203250[r];
        if (r == -2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x54C);
        }
        return r;
    }
    if (KEY_GetTrg() & 1) {
        if (tbl_02203250[p->pos] == -2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
        } else {
            GFL_USE_PlaySeDefaultVolume(0x54C);
        }
        return tbl_02203250[p->pos];
    }
    if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_021F4FF4(p->cursor, 0xC0, 0x88);
        CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 5);
        return -2;
    }
    return -1;
}





void func_021FA2B0(Menu *m, int dir)
{
    if (dir < 0) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        CLACT_SetActorAutoAnim((struct Obj *)((struct Obj *)m->down), 1);
        CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)m->down), 0x27);
        if (m->page != 0) {
            m->page = m->page - 1;
        } else {
            m->page = 2;
        }
    } else {
        GFL_USE_PlaySeDefaultVolume(0x548);
        CLACT_SetActorAutoAnim((struct Obj *)((struct Obj *)m->up), 1);
        CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)m->up), 0x26);
        if (m->page < 2) {
            m->page = m->page + 1;
        } else {
            m->page = 0;
        }
    }
    func_021FB2F0((Menu *)m, m->page, m->total);
    func_021FBF04(m->mgr, m->num, m->wins[4], m->page, func_021F9EEC((u8 *)m->total, 4));
}





int func_021FA330(Menu *m, int key)
{
    int idx;

    switch (key) {
    case 4:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return -2;
    case 5:
        func_021FA2B0((Menu *)m, -1);
        return -1;
    case 6:
        func_021FA2B0((Menu *)m, 1);
        return -1;
    }
    idx = key + m->page * 4;
    if (idx < m->total) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return m->items[key].val;
    }
    return -1;
}





int func_021FA394(Menu *m)
{
    int old;
    int r;

    old = m->pos;
    if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)m->cursor), 1);
        func_020355D8(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -1;
    }
    if (KEY_GetRepeat() & 0x40) {
        if (m->pos != 0) {
            m->pos = m->pos - 1;
        } else {
            m->pos = 4;
        }
    } else if (KEY_GetRepeat() & 0x80) {
        if (m->pos != 4) {
            m->pos = m->pos + 1;
        } else {
            m->pos = 0;
        }
    } else if (KEY_GetRepeat() & 0x20) {
        func_021FA2B0((Menu *)m, -1);
    } else if (KEY_GetRepeat() & 0x10) {
        func_021FA2B0((Menu *)m, 1);
    }
    if (old != m->pos) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021F4FF4(m->cursor, tbl_02203216[m->pos].x, tbl_02203216[m->pos].y);
        if (m->pos == 4) {
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)m->cursor), 5);
        } else {
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)m->cursor), 6);
        }
    }
    r = func_021F9A1C(m, 2);
    if (r != -1) {
        if ((u32)r < 5) {
            func_021F4FF4(m->cursor, tbl_02203216[r].x, tbl_02203216[r].y);
            if (r == 4) {
                CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)m->cursor), 5);
            } else {
                m->pos = r;
                CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)m->cursor), 6);
            }
        }
        r = func_021FA330((Menu *)m, r);
        if (r == -1 && func_020355C4() == 0) {
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)m->cursor), 0);
        }
        func_020355D8(1);
        return r;
    }
    if (KEY_GetTrg() & 1) {
        return func_021FA330((Menu *)m, m->pos);
    }
    if (KEY_GetTrg() & 2) {
        func_021F4FF4(m->cursor, 0xC0, 0x88);
        CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)m->cursor), 5);
        GFL_USE_PlaySeDefaultVolume(0x551);
        return -2;
    }
    return -1;
}





/*
 * Map a mode value: 9 and 10 have fixed answers, everything else passes through.
 */
int func_021FA4FC(int unused, int mode)
{
    switch (mode) {
    case 9:
        return ~1;
    case 10:
        return 10;
    default:
        return mode;
    }
}





/*
 * Cursor input for the eleven-entry mode-6 menu: a 3-column grid of nine
 * entries plus two buttons (9, 10). Leaving a button with up or down
 * returns to the last grid entry (+0x7A) moved to the bottom or top row.
 * A touch (func_021F9A1C) or A selects. Returns the entry, -2 for cancel
 * (B or entry 9), -1 for nothing or a grid entry `enable` marks off.
 */
int func_021FA514(Menu *p, u8 *enable)
{
    int old = p->pos;
    int r;

    if (old < 9) {
        p->last = old;
    }
    if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)p->cursor), 1);
        func_020355D8(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -1;
    }
    if (KEY_GetRepeat() & 0x40) {
        p->pos = tbl_0220339C[p->pos].up;
    } else if (KEY_GetRepeat() & 0x80) {
        p->pos = tbl_0220339C[p->pos].down;
    } else if (KEY_GetRepeat() & 0x20) {
        p->pos = tbl_0220339C[p->pos].left;
    } else if (KEY_GetRepeat() & 0x10) {
        p->pos = tbl_0220339C[p->pos].right;
    }
    if (old >= 9 && p->pos < 9) {
        if (KEY_GetRepeat() & 0x40) {
            p->pos = p->last;
            while (p->pos + 3 < 9) {
                p->pos += 3;
            }
        } else if (KEY_GetRepeat() & 0x80) {
            p->pos = p->last;
            while (p->pos - 3 >= 0) {
                p->pos -= 3;
            }
        }
    }
    if (old != p->pos) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021F4FF4(p->cursor, (tbl_02203298[p->pos].x + 0x10) * 8, tbl_02203298[p->pos].y * 8);
        switch (p->pos) {
        case 9:
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 5);
            break;
        case 10:
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 6);
            break;
        default:
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 0x12);
            break;
        }
    }
    r = func_021F9A1C(p, 6);
    if (r != -1) {
        func_021F4FF4(p->cursor, (tbl_02203298[r].x + 0x10) * 8, tbl_02203298[r].y * 8);
        switch (r) {
        case 9:
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 5);
            break;
        case 10:
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 6);
            break;
        default:
            CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 0x12);
            p->pos = r;
            break;
        }
        r = func_021FA4FC((int)p, r);
        if (r == -2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
        } else if (r == 10 || enable == 0 || enable[r] != 0) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
        } else {
            r = -1;
        }
        if (r == -1 && func_020355C4() == 0) {
            CLACT_SetActorDrawEnable((struct Obj *)((struct Obj *)p->cursor), 0);
        }
        func_020355D8(1);
        return r;
    }
    if (KEY_GetTrg() & 1) {
        r = func_021FA4FC((int)p, p->pos);
        if (r == -2) {
            GFL_USE_PlaySeDefaultVolume(0x551);
            return r;
        }
        if (r == 10 || enable == 0 || enable[r] != 0) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            return r;
        }
    } else if (KEY_GetTrg() & 2) {
        func_021F4FF4(p->cursor, 0xC0, 0x88);
        CLACT_SetActorAnimSeq((struct Obj *)((struct Obj *)p->cursor), 5);
        GFL_USE_PlaySeDefaultVolume(0x551);
        return -2;
    }
    return -1;
}





int func_021FA760(Menu *m, int key)
{
    int idx;

    switch (key) {
    case 5:
        GFL_USE_PlaySeDefaultVolume(0x551);
        return -2;
    case 6:
        func_021FA7C4(m, -1);
        return -1;
    case 7:
        func_021FA7C4(m, 1);
        return -1;
    }
    idx = key + m->page * 5;
    if (idx < m->total) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return m->items[idx].val;
    }
    return -1;
}




void func_021FA7C4(Menu *m, int dir)
{
    int last;

    last = func_021F9EEC((u8 *)m->total, 5) - 1;
    if (last == 0) {
        return;
    }
    if (dir < 0) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        CLACT_SetActorAutoAnim((struct Obj *)m->down, 1);
        CLACT_SetActorAnimSeq((struct Obj *)m->down, 0x27);
        if (m->page != 0) {
            m->page = m->page - 1;
        } else {
            m->page = last;
        }
    } else {
        GFL_USE_PlaySeDefaultVolume(0x548);
        CLACT_SetActorAutoAnim((struct Obj *)m->up, 1);
        CLACT_SetActorAnimSeq((struct Obj *)m->up, 0x26);
        if (m->page < last) {
            m->page = m->page + 1;
        } else {
            m->page = 0;
        }
    }
    func_021FB364((Menu *)m, m->page, m->total);
    func_021FBF04(m->mgr, m->num, m->wins[5], m->page, func_021F9EEC((u8 *)m->total, 5));
}




int func_021FA85C(Menu *m)
{
    int old;
    int r;

    old = m->pos;
    if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)m->cursor, 1);
        func_020355D8(0);
        GFL_USE_PlaySeDefaultVolume(0x548);
        return -1;
    }
    if (KEY_GetRepeat() & 0x40) {
        if (m->pos != 0) {
            m->pos = m->pos - 1;
        } else {
            m->pos = 5;
        }
    } else if (KEY_GetRepeat() & 0x80) {
        if (m->pos != 5) {
            m->pos = m->pos + 1;
        } else {
            m->pos = 0;
        }
    } else if (KEY_GetRepeat() & 0x20) {
        func_021FA7C4((Menu *)m, -1);
    } else if (KEY_GetRepeat() & 0x10) {
        func_021FA7C4((Menu *)m, 1);
    }
    if (old != m->pos) {
        GFL_USE_PlaySeDefaultVolume(0x548);
        func_021F4FF4(m->cursor, tbl_02203236[m->pos].x, tbl_02203236[m->pos].y);
        if (m->pos == 5) {
            CLACT_SetActorAnimSeq((struct Obj *)m->cursor, 5);
        } else {
            CLACT_SetActorAnimSeq((struct Obj *)m->cursor, 7);
        }
    }
    r = func_021F9A1C(m, 3);
    if (r != -1) {
        if ((u32)r < 6) {
            func_021F4FF4(m->cursor, tbl_02203236[r].x, tbl_02203236[r].y);
            if (r == 5) {
                CLACT_SetActorAnimSeq((struct Obj *)m->cursor, 5);
            } else {
                m->pos = r;
                CLACT_SetActorAnimSeq((struct Obj *)m->cursor, 7);
            }
        }
        r = func_021FA760((Menu *)m, r);
        if (r == -1 && func_020355C4() == 0) {
            CLACT_SetActorDrawEnable((struct Obj *)m->cursor, 0);
        }
        func_020355D8(1);
        return r;
    }
    if (KEY_GetTrg() & 1) {
        return func_021FA760((Menu *)m, m->pos);
    }
    if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        func_021F4FF4(m->cursor, 0xC0, 0x88);
        CLACT_SetActorAnimSeq((struct Obj *)m->cursor, 5);
        return -2;
    }
    return -1;
}




void func_021FA9C8(Menu *p, int mode, int pos)
{
    int i;
    void *str;
    u16 color;
    u8 *g;
    BGWINFRM_SetFrameDataArc(p->mgr, 0, 96, mode == 6 ? 27 : 28, 1);
    BGWINFRM_GetFrameBuffer(p->mgr, 0);
    func_021F9260(p, mode);
    func_021FBEB8(p->mgr, p->bank, (*(void ***)p)[14], 74, (u8 *)p + 124);
    MI_CpuFill8((u8 *)p + 96, 1, 26);
    g = (u8 *)p;
    g += 124;
    for (i = 0; i < 9; i++) {
        str = func_02045EC0(p->bank, i + 116);
        if (mode == 4) {
            if (func_021FBFB0(p, i) == 1) {
                color = 0x3dc2;
                ((u8 *)p)[i + 96] = 1;
            } else {
                color = 0x2122;
                ((u8 *)p)[i + 96] = 0;
            }
        } else {
            if (func_021FC014(p, i) == 1) {
                color = 0x3dc2;
                ((u8 *)p)[i + 96] = 1;
            } else {
                color = 0x2122;
                ((u8 *)p)[i + 96] = 0;
            }
        }
        func_021FAC50(p->mgr, (*(void ***)p)[i], str, 2, color, g);
        STRBUF_Delete(str);
    }
    if (mode == 6) {
        str = func_02045EC0(p->bank, 188);
        func_021FAC50(p->mgr, (*(void ***)p)[15], str, 2, 0x3dc2, (u8 *)p + 124);
        STRBUF_Delete(str);
    }
    BGWINFRM_PutFrame(p->mgr, 0, pos, 0);
    BGWINFRM_ShowFrame(p->mgr, 0);
}




void func_021FAAD4(Menu *p)
{
    int i;
    void *str;
    BGWINFRM_SetFrameDataArc(p->mgr, 0, 96, 25, 1);
    BGWINFRM_GetFrameBuffer(p->mgr, 0);
    func_021F9260(p, 1);
    for (i = 0; i < 3; i++) {
        str = func_02045EC0(p->bank, i + 130);
        func_021FAC50(p->mgr, (*(void ***)p)[i], str, 2, 0x3dc2, (u8 *)p + 124);
        STRBUF_Delete(str);
    }
    func_021FBEB8(p->mgr, p->bank, (*(void ***)p)[14], 74, (u8 *)p + 124);
    BGWINFRM_PutFrame(p->mgr, 0, 32, 0);
    BGWINFRM_ShowFrame(p->mgr, 0);
    BGWINFRM_StartMove(p->mgr, 0, -4, 0, 4);
}




void func_021FAB70(Menu *p)
{
    BGWINFRM_SetFrameDataArc(p->mgr, 0, 96, 29, 1);
    BGWINFRM_GetFrameBuffer(p->mgr, 0);
    func_021F9260(p, 2);
    if (p->f5C == 1)
        p->total = func_021F87E0((void **)((u8 *)p + 48), p->bank, 1);
    else if (p->f5C == 0)
        p->total = func_021F87E0((void **)((u8 *)p + 48), p->bank, 0);
    func_021FB2F0((Menu *)p, 0, p->total);
    p->page = 0;
    func_021FBF04(p->mgr, p->num, (*(void ***)p)[4], p->page, func_021F9EEC((u8 *)(p->total), 4));
    func_021FBEB8(p->mgr, p->bank, (*(void ***)p)[14], 74, (u8 *)p + 124);
    BGWINFRM_PutFrame(p->mgr, 0, 32, 0);
    CLACT_SetActorAnimSeq((struct Obj *)(p->cursor), 6);
    p->last = 0;
    *(int *)(unsigned int *)&p->pos = 0;
    func_021F4FF4(p->cursor, tbl_02203220[p->pos].x, tbl_02203220[p->pos].y);
    BGWINFRM_ShowFrame(p->mgr, 0);
    BGWINFRM_StartMove(p->mgr, 0, -4, 0, 4);
    *(int *)(unsigned int *)&p->state = 34;
}




void func_021FAC50(void *mgr, void *win, void *str, u32 x, u16 color, void *g)
{
    func_022028C8((u8 *)win, 0, (u32)str, x, 0, 0, color, (u32)g);
    BMP_WIN_TransferChars((struct Descriptor *)win);
    BGWINFRM_PutBmpWin((struct WinMgr *)mgr, 0, win);
}




int func_021FAC84(void)
{
    return -1;
}




/*
 * lever: explicit if/else calls preserve the flag argument's scheduling.
 */
int func_021FAC8C(Menu *p)
{
    if (!BGWINFRM_IsMoving(*(struct WinMgr * *)&p->mgr, 0)) {
        if (func_020355C4() == 1)
            CLACT_SetActorDrawEnable((*(void * *)&p->cursor), 0);
        else
            CLACT_SetActorDrawEnable((*(void * *)&p->cursor), 1);
        if (p->f54 == 2) {
            CLACT_SetActorAutoAnim((*(void * *)&p->up), 0);
            CLACT_SetActorAutoAnim((*(void * *)&p->down), 0);
            CLACT_SetActorAnimSeq((*(void * *)&p->up), 38);
            CLACT_SetActorAnimSeq((*(void * *)&p->down), 39);
            func_021F4FF4(*(u32 *)(void * *)&p->up, 228, 120);
            func_021F4FF4(*(u32 *)(void * *)&p->down, 154, 120);
            CLACT_SetActorDrawEnable((*(void * *)&p->up), 1);
            CLACT_SetActorDrawEnable((*(void * *)&p->down), 1);
        }
        p->state = p->f4C;
    }
    return -1;
}




/*
 * Flush the queued value when the probe reports empty, then answer -1.
 */
int func_021FAD08(Menu *p)
{
    if (BGWINFRM_IsMoving(*(struct WinMgr * *)&p->mgr, 0) == 0) {
        (*(unsigned int *)&p->state) = (*(unsigned int *)&p->f4C);
    }
    return -1;
}




/*
 * trailing: two-byte zero alignment padding at 0x021FAD82.
 */
int func_021FAD24(Menu *p)
{
    if (CLACT_IsActorAnimActive((*(void * *)&p->cursor))) return -1;
    CLACT_SetActorDrawEnable((*(void * *)&p->cursor), 0);
    CLACT_SetActorDrawEnable((*(void * *)&p->up), 0);
    CLACT_SetActorDrawEnable((*(void * *)&p->down), 0);
    if (p->f54 == 3 && p->f4C == 28)
        BGWINFRM_StartMove(p->mgr, 0, 6, 0, 6);
    else
        BGWINFRM_StartMove(p->mgr, 0, 4, 0, 4);
    p->state = 4;
    return -1;
}




/*
 * Drain the queue then flush the shadowed value, always answering -1.
 */
int func_021FAD84(Menu *p)
{
    if (BGWINFRM_IsMoving(*(struct WinMgr * *)&p->mgr, 0) == 0) {
        BGWINFRM_HideFrame(*(struct WinMgr * *)&p->mgr, 0);
        (*(unsigned int *)&p->state) = (*(unsigned int *)&p->f4C);
    }
    return -1;
}




int func_021FADA8(Menu *p)
{
    if (CLACT_IsActorAnimActive((*(void * *)&p->cursor))) return -1;
    CLACT_SetActorDrawEnable((*(void * *)&p->cursor), 0);
    CLACT_SetActorDrawEnable((*(void * *)&p->up), 0);
    CLACT_SetActorDrawEnable((*(void * *)&p->down), 0);
    BGWINFRM_StartMove(p->mgr, 0, 4, 0, 4);
    p->state = 2;
    return -1;
}




void func_021FADF0(Menu *p) {func_021FA9C8(p,4,32);CLACT_SetActorAnimSeq((*(void * *)&p->cursor),18);func_021F4FF4(*(u32 *)(void * *)&p->cursor,144,40);BGWINFRM_StartMove(p->mgr,0,-4,0,4);(*(unsigned int *)&p->state)=1;(*(unsigned int *)&p->f4C)=7;p->layout=-1;}




int func_021FAE2C(Menu *p)
{
    u32 sel = func_021F9A88((Menu *)p, (u8 *)p + 96);
    if (sel != -2) {
        if (sel <= 8) {
            CLACT_SetActorDrawEnable((*(void * *)&p->cursor), 1);
            CLACT_SetActorAnimSeq((*(void * *)&p->cursor), 19);
            p->state = 8;
            p->layout = sel;
        }
    } else {
        CLACT_SetActorDrawEnable((*(void * *)&p->cursor), 1);
        CLACT_SetActorAnimSeq((*(void * *)&p->cursor), CLACT_GetActorAnimSeq((*(void * *)&p->cursor)) + 9);
        p->state = 3;
        p->f4C = 8;
        p->layout = -1;
    }
    return -1;
}




int func_021FAE8C(Menu *p)
{
    if (CLACT_IsActorAnimActive((*(void * *)&p->cursor))) return -1;
    func_021F9660((Obj_021F9024 *)p, 4);
    CLACT_SetActorDrawEnable((*(void * *)&p->cursor), 0);
    if (p->layout >= 0) {
        if (tbl_022033FC[p->layout].count != 1)
            p->state = 10;
        else {
            p->start = 0;
            p->state = 14;
        }
    } else return -2;
    return -1;
}




int func_021FAEE0(Menu *p)
{
    int i;
    void *str;
    u16 color;
    u8 *g;
    BGWINFRM_SetFrameDataArc(p->mgr, 0, 96, 28, 1);
    BGWINFRM_GetFrameBuffer(p->mgr, 0);
    func_021F9260(p, 4);
    func_021FBEB8(p->mgr, p->bank, (*(void ***)p)[14], 74, (u8 *)p + 124);
    MI_CpuFill8((u8 *)p + 96, 1, 26);
    g = (u8 *)p + 124;
    for (i = 0; i < 9; i++) {
        str = func_02045EC0(p->bank, i + 116);
        if (func_021FBFB0(p, i) == 1) {
            color = 0x3dc2;
            ((u8 *)p)[i + 96] = 1;
        } else {
            color = 0x2122;
            ((u8 *)p)[i + 96] = 0;
        }
        func_021FAC50(p->mgr, (*(void ***)p)[i], str, 2, color, g);
        STRBUF_Delete(str);
    }
    BGWINFRM_PutFrame(p->mgr, 0, 16, 0);
    BGWINFRM_ShowFrame(p->mgr, 0);
    CLACT_SetActorAnimSeq((struct Obj *)(p->cursor), 18);
    func_021F4FF4(p->cursor, (tbl_022032C6[p->layout].x + 16) * 8, tbl_022032C6[p->layout].y * 8);
    p->pos = p->layout;
    CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
    p->state = 7;
    if (func_020355C4() == 1)
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 0);
    else
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
    return -1;
}




int func_021FAFF0(Menu *m)
{
    int i;
    u16 color;

    i = 1;
    BGWINFRM_SetFrameDataArc(m->mgr, 0, 0x60, 0x1A, 1);
    BGWINFRM_GetFrameBuffer(m->mgr, 0);
    ov135_func_021F9260(m, 5);
    MI_CpuFill8(m->flags, 1, 0x1A);
    func_021FBE84(m->mgr, m->bank, m->wins[0], m->layout + 0x74, 2, 0x3DC2, m->g);
    for (i = 1; i < tbl_022033F8[m->layout].count + 1; i++) {
        if (func_021FBF6C(m, (int)tbl_02203324[m->layout] + i - 1) > 0) {
            color = 0x3DC2;
            m->flags[(int)tbl_02203324[m->layout] + i - 1] = 1;
        } else {
            color = 0x2122;
            m->flags[(int)tbl_02203324[m->layout] + i - 1] = 0;
        }
        func_021FBE84(m->mgr, m->bank, m->wins[i], tbl_02203440[i + tbl_022033F8[m->layout].first - 1], 5, color, m->g);
    }
    func_021FBEB8(m->mgr, m->bank, m->wins[14], 0x4A, m->g);
    BGWINFRM_PutFrame(m->mgr, 0, 0x10, 0);
    CLACT_SetActorAnimSeq((struct Obj *)m->cursor, 4);
    if (m->start < 0) {
        m->pos = 0;
    } else {
        m->pos = m->start;
    }
    func_021F4FF4(m->cursor, (tbl_022032C6[m->pos].x + 0x10) * 8, tbl_022032C6[m->pos].y * 8);
    if (func_020355C4() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)m->cursor, 0);
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)m->cursor, 1);
    }
    m->state = 0xB;
    return -1;
}




int func_021FB164(Menu *p)
{
    int r;
    r = func_021F9CDC((Menu *)p, (int)((u8 *)p + 0x60));
    switch ((u32)r) {
    case 0: case 1: case 2: case 3: case 4:
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct Obj *)(p->cursor), CLACT_GetActorAnimSeq((struct Obj *)(p->cursor)) + 9);
        p->state = 12;
        p->start = r;
        break;
    case -2:
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct Obj *)(p->cursor), CLACT_GetActorAnimSeq((struct Obj *)(p->cursor)) + 9);
        p->state = 12;
        p->start = -1;
        break;
    }
    return -1;
}




int func_021FB1E4(Menu *p) { if(CLACT_IsActorAnimActive((*(void * *)&p->cursor)))return -1;CLACT_SetActorDrawEnable((*(void * *)&p->cursor),0);func_021F9660((Obj_021F9024 *)p, 5);if(p->start>=0)*(u32 *)&p->state=14;else *(u32 *)&p->state=9;return -1; }




/*
 * State select before the notify call.
 */
int func_021FB220(Menu *p)
{
    u32 v;
    int n;

    if (func_020355C4() == 1) {
        v = p->cursor;
        n = 0;
    } else {
        v = p->cursor;
        n = 1;
    }
    CLACT_SetActorDrawEnable((struct Obj *)v, n);
    (*(unsigned int *)&p->state) = 0xa;
    return -1;
}



/*
 * Count the entries of a u16 table that the query accepts.
 */
int func_021FB240(u32 unused, u32 item, u32 c, u16 *list, int start, int end)
{
    int i;
    int n = 0;

    for (i = start; i < end; i++) {
        if (ZUKAN_SAVE_IsSeen((struct Blk37 *)item, list[i]) != 0) {
            n++;
        }
    }
    return n;
}



int func_021FB26C(Item **menu, void *msg, void *bank, u32 x, u32 kind, void *bag)
{
    u32 count;
    int start;
    int end;
    int n;
    int i;
    u16 *list;

    list = func_021F8498(0x48, 0, &count);
    func_021F84BC(kind, &start, &end);
    count = end - start;
    n = func_021FB240(x, (u32)bag, count, list, start, end);
    *menu = BMP_MENUWORK_Create(n + 1, 0x48);
    for (i = start; i < end; i++) {
        if (ZUKAN_SAVE_IsSeen(bag, list[i]) != 0) {
            BMP_MENUWORK_AddMsgItem((struct Slot *)*menu, (u32)msg, list[i], list[i], 0x48);
        }
    }
    func_020307B0(list);
    return n;
}



void func_021FB2F0(Menu *m, int page, int total)
{
    int i;

    for (i = 0; i < 4; i++) {
        BMP_Clear(BMP_WIN_GetBmp(m->wins[i]), 0xA);
        if (i + page * 4 < total) {
            func_021FAC50(m->mgr, m->wins[i], m->items[page * 4 + i].str, 0, 0x3DC2, m->g);
        } else {
            BMP_WIN_TransferChars(m->wins[i]);
            BGWINFRM_PutBmpWin(m->mgr, 0, m->wins[i]);
        }
    }
}



void func_021FB364(Menu *m, int page, int total)
{
    int i;

    for (i = 0; i < 5; i++) {
        BMP_Clear(BMP_WIN_GetBmp(m->wins[i]), 0xA);
        if (i + page * 5 < total) {
            func_021FAC50(m->mgr, m->wins[i], m->items[page * 5 + i].str, 0, 0x3DC2, m->g);
        } else {
            BMP_WIN_TransferChars(m->wins[i]);
            BGWINFRM_PutBmpWin(m->mgr, 0, m->wins[i]);
        }
    }
}



int func_021FB3D8(Menu *p)
{
    u8 pages;

    BGWINFRM_SetFrameDataArc(p->mgr, 0, 0x60, 0x1D, 1);
    BGWINFRM_GetFrameBuffer(p->mgr, 0);
    func_021F9260(p, 0);
    p->total = func_021FB26C(&p->items, p->msg, p->bank, p->x2c, (int)tbl_02203324[p->layout] + p->start, p->bag);
    p->page = 0;
    func_021FB2F0((Menu *)p, 0, p->total);
    pages = func_021F9EEC((u8 *)p->total, 4);
    func_021FBF04(p->mgr, p->num, p->wins[4], p->page, pages);
    func_021FBEB8(p->mgr, p->bank, p->wins[14], 0x4A, p->g);
    BGWINFRM_PutFrame(p->mgr, 0, 0x10, 0);
    CLACT_SetActorAnimSeq((struct Obj *)p->cursor, 6);
    p->pos = 0;
    func_021F4FF4(p->cursor, tbl_02203220[p->pos].x, tbl_02203220[p->pos].y);
    func_021F4FF4(p->up, 0xE4, 0x78);
    func_021F4FF4(p->down, 0x9A, 0x78);
    if (func_020355C4() == 1) {
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 0);
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
    }
    if (pages == 1) {
        CLACT_SetActorAnimSeq((struct Obj *)p->up, 0x3D);
        CLACT_SetActorAnimSeq((struct Obj *)p->down, 0x3E);
    } else {
        CLACT_SetActorAnimSeq((struct Obj *)p->up, 0x26);
        CLACT_SetActorAnimSeq((struct Obj *)p->down, 0x27);
    }
    CLACT_SetActorAutoAnim((struct Obj *)p->up, 0);
    CLACT_SetActorAutoAnim((struct Obj *)p->down, 0);
    CLACT_SetActorDrawEnable((struct Obj *)p->up, 1);
    CLACT_SetActorDrawEnable((struct Obj *)p->down, 1);
    p->state = 0xF;
    return -1;
}



int func_021FB510(Menu *p)
{
    int r;
    r = func_021F9FF0((Menu *)p);
    switch (r) {
    case -2:
        GFL_USE_PlaySeDefaultVolume(0x551);
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct Obj *)(p->cursor), CLACT_GetActorAnimSeq((struct Obj *)(p->cursor)) + 9);
        p->state = 16;
        p->f3C = -1;
        break;
    case -1: break;
    default:
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct Obj *)(p->cursor), CLACT_GetActorAnimSeq((struct Obj *)(p->cursor)) + 9);
        p->state = 3;
        p->f4C = 17;
        p->f3C = r;
        break;
    }
    return -1;
}



/*
 * If the buffer is still live return -1; otherwise release the three pointers and pick the 0xd/0x9 code from the table.
 */
int func_021FB588(Menu *p)
{
    if (CLACT_IsActorAnimActive((struct Actor *)(*(u32 *)(void * *)&p->cursor)) != 0) {
        return -1;
    }
    CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)(void * *)&p->cursor, 0);
    CLACT_SetActorDrawEnable((struct Obj *)p->up, 0);
    CLACT_SetActorDrawEnable((struct Obj *)p->down, 0);
    func_021F9660((Obj_021F9024 *)p, 0x0);
    BMP_MENUWORK_Delete((void *)(*(u32 *)(void **)&p->items));
    *(u32 *)&p->state = (*(s32 *)(g_022033FC + p->layout * 8) != 1) ? 0xd : 0x9;
    return -1;
}



int func_021FB5E4(Menu *p) { if(CLACT_IsActorAnimActive((*(void * *)&p->cursor)))return -1;CLACT_SetActorDrawEnable((*(void * *)&p->cursor),0);func_021F9660((Obj_021F9024 *)p, 0);BMP_MENUWORK_Delete((void *)p->items);return p->f3C; }



int func_021FB614(Menu *p)
{
    func_021FA9C8(p, 6, 0x20);
    CLACT_SetActorAnimSeq((struct Obj *)(p->cursor), 18);
    BGWINFRM_StartMove(p->mgr, 0, -4, 0, 4);
    p->state = 1;
    p->f4C = 19;
    p->pos = 10;
    p->layout = -1;
    func_021F4FF4(p->cursor, (tbl_02203298[p->pos].x + 16) * 8, tbl_02203298[p->pos].y * 8);
    CLACT_SetActorAnimSeq((struct Obj *)(p->cursor), 6);
    return -1;
}



int func_021FB674(Menu *p)
{
    int r;
    r = func_021FA514((Menu *)p, (u8 *)p + 0x60);
    switch ((u32)r) {
    case -2:
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct Obj *)(p->cursor), CLACT_GetActorAnimSeq((struct Obj *)(p->cursor)) + 9);
        p->state = 3;
        p->f4C = 20;
        p->layout = -1;
        break;
    case 10:
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct Obj *)(p->cursor), CLACT_GetActorAnimSeq((struct Obj *)(p->cursor)) + 9);
        p->state = 3;
        p->f4C = 20;
        p->layout = -2;
        break;
    case -1: break;
    default:
        CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
        CLACT_SetActorAnimSeq((struct Obj *)(p->cursor), 19);
        p->layout = r;
        p->state = 20;
        break;
    }
    return -1;
}



int func_021FB704(Menu *p)
{
    if (CLACT_IsActorAnimActive((*(void * *)&p->cursor)) != 0) return -1;
    CLACT_SetActorDrawEnable((struct Obj *)*(u32 *)(void * *)&p->cursor, 0);
    func_021F9660((Obj_021F9024 *)p, 6);
    if (p->layout < 0) {
        if (p->layout == -1) return -2;
        else if (p->layout == -2) return 0;
    } else {
        if (tbl_022033FC[p->layout].count != 1) {
            p->state = 22;
        } else {
            p->start = 0;
            BGWINFRM_StartMove(p->mgr, 0, -4, 0, 3);
            if (p->f14 != 0) CLACT_SetActorDrawEnable((struct Obj *)p->f14, 0);
            CLACT_SetActorAnimSeq((struct Obj *)(*(u32 *)(void * *)&p->cursor), 7);
            p->state = 2;
            BGWINFRM_SetFrameDataArc(p->mgr, 0, 0x60, 0x18, 1);
            p->f4C = 26;
        }
    }
    return -1;
}



int func_021FB7A0(Menu *p)
{
    func_021FA9C8(p, 6, 0x10);
    CLACT_SetActorAnimSeq((struct Obj *)(p->cursor), 18);
    CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
    p->pos = p->layout;
    func_021F4FF4(p->cursor, (tbl_02203298[p->pos].x + 16) * 8, tbl_02203298[p->pos].y * 8);
    if (func_020355C4() == 1) CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 0);
    else CLACT_SetActorDrawEnable((struct Obj *)p->cursor, 1);
    p->state = 19;
    return -1;
}
