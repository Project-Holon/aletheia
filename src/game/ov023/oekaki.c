/*
 * file:     oekaki.c
 * unit:     yes
 * function: func_021841E0, func_021841F8, func_021842A4, func_021842BC, func_02184320, func_02184368, func_02184454, func_02184474, func_021844B4, func_021844D8, func_0218454C, func_02184560, func_0218456C, func_02184674, func_021847C8, func_0218489C, func_021848A8, func_021848CC, func_021848D0, func_021848E0, func_021849F8, func_02184B04, func_02184B34, func_02184B78, func_02184C48, func_02184D30, func_02184ECC, func_02185004, func_0218506C, func_02185080, func_021850A0, func_021852B4, func_021852F4, func_0218530C, func_02185354, func_02185378, func_021853D0, func_021853F0, func_02185420, func_02185454, func_02185584, func_021855C8, func_021855EC, func_02185628, func_02185670, func_021856AC, func_021856CC, func_021856F4, func_02185730, func_02185764, func_021857F4, func_02185814, func_02185854, func_02185880, func_021858B8, func_02185930, func_02185934, func_02185954, func_02185974, func_021859C4, func_02185A1C, func_02185AB0, func_02185BBC, func_02185C38, func_02185DA8, func_02185DE8, func_02185EA0, func_02185F10, func_02185F50, func_02185F74, func_021860D0, func_02186164, func_02186170, func_021861C4, func_021862B0, func_021862F4, func_02186304, func_02186324, func_02186444, func_0218644C, func_02186480, func_021864A8, func_021864C4, func_0218654C, func_02186558, func_02186564, func_021865B4, func_02186660, func_02186694, func_021866C4, func_02186708, func_021867C4, func_02186860, func_02186878, func_02186888, func_021868C8, func_02186938, func_02186958, func_02186988, func_021869C0, func_02186A04
 * address:  0x021841E0
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203A574 0x0203A574 arm
 *   d_02186A6C 0x02186A6C data ov023 a4
 *   func_02039338  0x02039338  arm
 *   func_02082B0C  0x02082B0C  arm
 *   func_02045770  0x02045770  arm
 *   func_020437D4  0x020437D4  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02186860  0x02186860  thumb  ov023
 *   func_02186988 0x02186988 thumb ov023
 *   func_02185AB0  0x02185AB0  thumb  ov023
 *   func_02082AC0  0x02082AC0  arm
 *   func_021841A4  0x021841A4  thumb  ov022
 *   func_021841A0  0x021841A0  thumb  ov022
 *   func_02080D24  0x02080D24  arm
 *   func_02184134  0x02184134  thumb  ov022
 *   func_0203996C  0x0203996C  arm
 *   GFL_NET_COMMAND_SetSendSlot  0x0203AA94  arm
 *   func_02184148  0x02184148  thumb
 *   BG_SYS_ClearMainPlanes  0x020434CC  arm
 *   BG_SYS_ClearSubPlanes  0x02043588  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0202208C  0x0202208C  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_02184D30  0x02184D30  thumb  ov023
 *   func_02184ECC  0x02184ECC  thumb  ov023
 *   func_02186564  0x02186564  thumb  ov023
 *   func_021866C4  0x021866C4  thumb  ov023
 *   func_0203D34C  0x0203D34C  arm
 *   func_02049238  0x02049238  arm
 *   func_02186558  0x02186558  thumb  ov023
 *   func_0218644C  0x0218644C  thumb  ov023
 *   func_020221A4  0x020221A4  thumb
 *   func_021840FC  0x021840FC  thumb  ov022
 *   func_02185F74  0x02185F74  thumb  ov023
 *   func_02186324  0x02186324  thumb  ov023
 *   func_02185F10  0x02185F10  thumb  ov023
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_02184174  0x02184174  thumb  ov022
 *   func_0218417C  0x0218417C  thumb  ov022
 *   func_021867C4  0x021867C4  thumb  ov023
 *   func_0204A600  0x0204A600  arm
 *   func_020310C4  0x020310C4  arm
 *   func_02186708  0x02186708  thumb  ov023
 *   func_0200FB24  0x0200FB24  thumb
 *   d_02186E80     0x02186E80  data   a4
 *   func_02030EAC  0x02030EAC  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_02186694  0x02186694  thumb  ov023
 *   func_02185004  0x02185004  thumb  ov023
 *   func_02045C04  0x02045C04  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_0204A648  0x0204A648  arm
 *   func_020419E4  0x020419E4  arm
 *   func_020433E0  0x020433E0  arm
 *   d_02186ACC     0x02186ACC  data  ov023  a4
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040B94  0x02040B94  arm
 *   d_02186B3C     0x02186B3C  data  ov023  a4
 *   d_02186BCC     0x02186BCC  data  ov023  a4
 *   d_02186B6C     0x02186B6C  data  ov023  a4
 *   d_02186B8C     0x02186B8C  data  ov023  a4
 *   d_02186BAC     0x02186BAC  data  ov023  a4
 *   d_02186B4C     0x02186B4C  data  ov023  a4
 *   func_020457B0  0x020457B0  arm
 *   func_02186444  0x02186444  thumb  ov023
 *   func_02045CAC  0x02045CAC  arm
 *   func_02030734  0x02030734  arm
 *   d_02186F58     0x02186F58  data  ov023  a4
 *   func_020307B0 0x020307B0 arm
 *   func_02045808 0x02045808 arm
 *   func_0207D534  0x0207D534  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_020275E4  0x020275E4  thumb
 *   func_0204A48C  0x0204A48C  arm
 *   d_020A1448     0x020A1448  data  a4
 *   func_0204B100  0x0204B100  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02027618  0x02027618  thumb
 *   func_02027614  0x02027614  thumb
 *   func_0204AC18  0x0204AC18  arm
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B84C  0x0204B84C  arm
 *   CLACT_SetActorDrawPriority  0x0204B800  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_02185930  0x02185930  thumb  ov023
 *   d_02186BEC     0x02186BEC  data  ov023  a2
 *   func_02045088  0x02045088  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0203101C  0x0203101C  arm
 *   func_0201C440  0x0201C440  thumb
 *   TCBL_DeleteAllTasks  0x0203115C  arm
 *   func_02031140  0x02031140  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0204B528 0x0204B528 arm
 *   d_02186AFC     0x02186AFC  data  ov023  a4
 *   d_02186AB4     0x02186AB4  data  ov023  a4
 *   func_02035C08  0x02035C08  arm
 *   TOUCHPANEL_HitCont  0x02035BA4  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   func_02035C38  0x02035C38  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0207D658  0x0207D658  arm
 *   APP_TASKMENU_TransWinAfterPrint  0x020278F4  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02184560  0x02184560  thumb  ov023
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_02184114  0x02184114  thumb  ov022
 *   func_02184180 0x02184180 thumb ov022
 *   func_0201F02C 0x0201F02C thumb
 *   GFL_NET_HANDLE_SetUserInfo 0x0203A424 arm
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_020436FC  0x020436FC  arm
 *   func_020439A0  0x020439A0  arm
 *   func_020437AC  0x020437AC  arm
 *   d_02186C34     0x02186C34  data  ov023  a4
 *   func_0203F684  0x0203F684  arm
 *   GX_LoadOBJPltt  0x0207E51C  arm
 *   func_02043AF4  0x02043AF4  arm
 *   func_02008500  0x02008500  thumb
 *   func_0201C724  0x0201C724  thumb
 *   GFL_NET_ResetSendQueue  0x0203D56C  arm
 *   func_02186A04  0x02186A04  thumb  ov023
 */
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed int     s32;

typedef signed short   s16;

#include "../ov022/union_app_types.h"
typedef struct StrBuf StrBuf;
typedef struct ClActor ClActor;
typedef struct TextPrinter TextPrinter;
typedef struct TcbList TcbList;
typedef struct TaskMenuRes TaskMenuRes;
typedef struct TaskMenu TaskMenu;
typedef struct NetHandle NetHandle;
typedef struct MetList MetList;
struct BmpWin;
struct WordSet;
struct MsgBank;
#include "oekaki_types.h"

#define OEKAKI_HEAP_ID          0x28
#define REG_MASTER_BRIGHT_A     0x0400006C
#define REG_MASTER_BRIGHT_B     0x0400106C

struct BmpWin;
struct Bmp;
struct MsgBank;
struct WordSet;
struct S020315D4;
struct DispVram;
typedef struct DispConfig { u32 word[4]; } DispConfig;

typedef struct BgTemplate { u32 word[8]; } BgTemplate;

extern void func_0203A574(u32 firstCommand, const void *commandTable, u32 commandCount, void *work);
extern u16 func_02039338(void);
extern void func_02082B0C(const void *src, void *dst, u32 size);
extern struct Bmp *func_02045770(struct BmpWin *window);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02045334(struct BmpWin *window);
extern void func_02045374(struct BmpWin *window);
extern u8 func_02045730(struct BmpWin *window);
extern void func_020409B4(u32 layer);
extern void func_02082AC0(int value, void *dst, u32 size);
extern int func_021841A4(UnionAppWork *app);
extern unsigned char func_021841A0(UnionAppWork *app);
extern u32 func_02080D24(u32 x);
extern void func_02184134(UnionAppWork *app);
extern NetHandle *func_0203996C(s32 netId);
extern u32 GFL_NET_COMMAND_SetSendSlot(NetHandle *dest, u32 targetBits, u32 commandId, u32 size, const void *data);
extern void func_02184148(UnionAppWork *app, int maxCount);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void func_0203064C(u32 a, u32 heapId, u32 size);
extern void *func_0203159C(void *task, u32 size, u32 heapId);
extern void func_02082BCC(void *dst, int value, int size);
extern void func_0203F8F4(u16 heapId);
extern struct WordSet *func_0201EC64(u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 heapId);
extern void *func_020490F4(u32 id, u32 heapId);
extern void *func_020056A0(void (*callback)(void), void *context, int priority);
extern void func_0203D34C(u32 a, u32 heapId);
extern void func_02049238(void *archive);
extern u32 func_020221A4(void);
extern void func_021840FC(UnionAppWork *app, UnionAppMemberCallback joinCallback, UnionAppMemberCallback leaveCallback, void *callbackArg);
extern void func_0203A5E4(u32 firstCommand);
extern void func_02184174(UnionAppWork *app);
extern u32 func_0218417C(UnionAppWork *app);
extern void func_0204A600(void);
extern void func_020310C4(TcbList *taskList);
extern u32 func_0200FB24(void);
extern void func_02030EAC(void *task);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0204AFD8(u32);
extern u32 func_0204B1CC(void *clactSys);
extern void func_0204A5AC(void);
extern u32 func_02045C04(struct MsgBank *msgBank);
extern u32 func_0201ED04(struct WordSet *wordSet);
extern u32 func_0201D83C(void *font);
extern void func_020315D4(struct S020315D4 *task);
extern void func_020306F0(u32 heapId);
void func_0204A648(void);
void func_020419E4(void);
extern void func_020433E0(const struct DispVram *);
extern void func_0203FC28(const DispConfig *config);
extern void func_0203FCA0(unsigned int bgId, const BgTemplate *tmpl, unsigned int type);
extern void func_020414EC(u32 bgId);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern StrBuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, StrBuf *dest);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02045808(StrBuf *vec);
void func_0207D534(volatile u16 *reg, int brightness);
void func_020403F4(u32 layer);
void func_0203F9B4(void);
extern void func_02049B68(void *archive, u32 b, u32 c, u32 d, u32 e, u16 heapId);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 heapId);
extern u32 func_02049658(void *archive, u32 b, u32 c, u32 d, u32 e, u32 f, u16 heapId);
extern void func_020498F4(void *archive, u32 b, u32 c, u32 d, u32 e, u32 f, u16 heapId);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 heapId);
extern u32 func_020275E4(void);
extern void func_0204A48C(const void *config, const struct DispVram *vram, u32 heapId);
extern void *func_0204B100(int count, u8 flag, u32 heapId);
extern s32 func_0204A6C8(void *archive, u32 b, u32 c, u32 d, u16 heapId);
extern s32 func_0204ABF0(void *archive, u32 b, u32 c, u32 d, u16 heapId);
extern s32 func_0204AF28(void *archive, u32 first, u32 second, u32 heapId);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern s32 func_0204AC18(void *archive, u32 b, u32 c, u32 d, u16 e, u16 f, u16 heapId);
void func_021841E0(OekakiWork *work);
void func_021841F8(int netId, int size, CanvasChunk *chunk, OekakiWork *work, int netHandle);
void func_021842A4(int netId, int size, const StrokeRec *stroke, OekakiWork *work);
void func_021842BC(int netId, int size, const u8 *strokes, OekakiWork *work);
void func_02184320(int netId, int size, int unused, OekakiWork *work);
void func_02184368(int netId, int size, const OekakiSyncMsg *msg, OekakiWork *work);
void func_02184454(int netId, int size, int unused, OekakiWork *work);
void func_02184474(int netId, int size, u8 *data, OekakiWork *work, int netHandle);
void func_021844B4(int netId, int size, int unused, OekakiWork *work);
u32 func_021844D8(OekakiWork *work, int chunkIndex, int unused);
CanvasChunk *func_0218454C(int netId, OekakiWork *work);
void func_02184560(OekakiWork *work, int maxCount);
int func_0218456C(void *task, int *state, OekakiParam *param);
int func_02184674(void *task, int *state, int unused, OekakiWork *work);
int func_021847C8(struct S020315D4 *task, int *seq, void *unused, OekakiWork *work);
void func_0218489C(void);
void func_021848A8(int netId, UnionAppEntry *entry, void *work);
void func_021848CC(int netId, UnionAppEntry *entry, void *work);
void func_021848D0(void);
void func_021848E0(void);
void func_021849F8(OekakiWork *work);
void func_02184B04(OekakiWork *work);
void func_02184B34(void);
void func_02184B78(OekakiWork *work, void *archive);
void func_02184C48(OekakiWork *work, void *archive);
extern char d_02186A6C[];
extern OekakiSceneStep d_02186E80[];
extern const struct DispVram d_02186ACC;
extern const DispConfig d_02186B3C;
extern const BgTemplate d_02186BCC;
extern const BgTemplate d_02186B6C;
extern const BgTemplate d_02186B8C;
extern const BgTemplate d_02186BAC;
extern const BgTemplate d_02186B4C;
extern char d_02186F58[];
extern u8 d_020A1448[];

/* A stroke record copied bytewise (the copy order of the original differs from the member copy). */
typedef struct StrokeBytes {
    u8 b[4];
    u8 lo : 3, mid : 3, hi : 2;
    u8 extra;
} StrokeBytes;

typedef struct StrokeBytesGroup {
    StrokeBytes r[5];
} StrokeBytesGroup;

/* Position of a sprite when it is created. */
typedef struct ClActorPos {
    s16 x;
    s16 y;
    s16 z;
    u8 drawType;
    u8 visible;
} ClActorPos;

/* Screen position and animation of one touch button. */
typedef struct ButtonLayout {
    u16 x;
    u16 y;
    u16 anim;
} ButtonLayout;

typedef struct Point16 {
    u16 x;
    u16 y;
} Point16;

/* Message and result of one item of the yes/no menu. */
typedef struct MenuItemInit {
    u32 msgId;
    u32 result;
} MenuItemInit;

extern ClActor *func_0204B294(void *clactSys, unsigned int charRes, unsigned int plttRes, unsigned int cellRes, const ClActorPos *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(ClActor *p, u32 v);
extern void func_0204B878(ClActor *p, u16 value);
extern void func_0204B3DC(ClActor *p, unsigned int v);
extern void func_0204B84C(ClActor *actor, int priority);
extern void CLACT_SetActorDrawPriority(ClActor *node, u32 val);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02045088(u16 heapId);
extern struct BmpWin *func_020450F0(u32 bgLayer, u32 x, u32 y, u32 width, u8 height, u8 paletteNo, u8 tileBase);
extern void func_02043B5C(struct Bmp *bmp, u8 color);
extern TcbList *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern TextPrinter *func_0201C440(u32 heapId);
extern void TCBL_DeleteAllTasks(TcbList *p);
extern void func_02031140(TcbList *p);
extern void func_0201C6EC(TextPrinter *p);
extern void func_0201C4C0(TextPrinter *p);
extern u32 func_020452E8(struct BmpWin *d);
extern void func_020450C8(void);
extern void func_0204B528(ClActor *actor, const Point16 *position);
extern int  func_02035C08(const void *p);
extern int  TOUCHPANEL_HitCont(const void *p);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern int  func_02035C38(void);
extern void func_020061E4(u32 a);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void APP_TASKMENU_TransWinAfterPrint(TaskMenu *menu);
extern void func_0201F7A8(struct BmpWin *window, u32 kind);
extern NetHandle *func_020399A8(void);
extern int func_0203D3A8(NetHandle *a, u32 b, u32 c, u32 d);
extern int func_02184114(UnionAppWork *app);
extern UnionAppEntry *func_02184180(UnionAppWork *app, int netId);
extern void func_0201F02C(struct WordSet *wordSet, u32 index, UnionAppEntry *entry);
extern void GFL_NET_HANDLE_SetUserInfo(NetHandle *handle, int a, int b, int c);
extern u32 func_0203D1C0(u32 index);
extern u32 func_02039CB4(NetHandle *h, u32 a, u32 b);
extern struct Bmp *func_020436FC(const void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int srcX, int srcY, u32 width, u32 height, u32 key);
extern void func_020437AC(struct Bmp *p);
extern short func_0203F684(unsigned short x);
extern void GX_LoadOBJPltt(void *src, unsigned long offset, unsigned long size);
extern void func_02043AF4(struct Bmp *bmp, u32 x, u32 y, u32 width, u32 height, u32 color);
extern void func_02008500(UnionAppEntry *entry, StrBuf *dst);
extern void func_0201C724(TextPrinter *printer, struct Bmp *bmp, u32 x, u32 y, StrBuf *text, void *font, u16 color);
extern int  GFL_NET_ResetSendQueue(void *h);
extern void func_0201F250(struct WordSet *wordSet, StrBuf *dst, StrBuf *src);
extern void func_0201F73C(struct BmpWin *window, int a, int b, int c);
extern void func_0201CE48(void *stream);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(struct BmpWin *window, u32 x, u32 y, StrBuf *text, void *font, u32 speed, TcbList *taskList, u32 a, u16 heap, u32 color);
extern u32 func_0201CE30(void *stream);
extern u32 func_020362DC(void);
extern void func_0201CE38(void *h);
extern void func_02040588(unsigned char which, unsigned char enable);
extern TaskMenuRes *func_02027F60(u16 a0, u16 a1, void *font, TextPrinter *printer, u16 heap);
extern StrBuf *func_02045EC0(struct MsgBank *bank, u32 index);
extern TaskMenu *func_02027778(MenuTemplate *tmpl, TaskMenuRes *res);
extern void func_02027974(TaskMenu *menu);
extern u32 func_020279E8(TaskMenu *);
extern u8 func_02027A04(TaskMenu *menu);
extern void func_02027858(TaskMenu *);
extern u32 func_02027FD8(TaskMenuRes *s);
extern void *func_02012EBC(void *gameData);
extern MetList *func_0200ED48(void *p);
extern u32 func_02008530(const UnionAppEntry *obj);
extern void func_0200ED54(MetList *l, u32 val);
extern u32 func_0201C4E4(TextPrinter *ps);
extern u32 func_0201C6C4(TextPrinter *p, void *v);
extern const ButtonLayout d_02186BEC[];
extern char d_02186AFC[];
extern char d_02186AB4[];
extern const u8 d_02186C34[];
extern int d_02186E84[][2];
extern char d_02186AAC[];
extern const MenuItemInit d_02186ABC[];

void func_02184D30(OekakiWork *p);
void func_02184ECC(OekakiWork *p, void *task);
void func_02185004(OekakiWork *p);
void func_0218506C(ClActor *actor, int x, int y);
void func_02185080(StrokeRec *stroke, int color, int size);
void func_021850A0(OekakiWork *p);
void func_021852B4(ClActor **buttons, int selected);
void func_021852F4(ClActor *button, int pressed);
int func_0218530C(OekakiWork *p, int procState);
void func_02185354(OekakiWork *p);
int func_02185378(OekakiWork *p, int procState);
int func_021853D0(OekakiWork *p, int procState);
int func_021853F0(OekakiWork *p, int procState);
int func_02185420(OekakiWork *p, int procState);
int func_02185454(OekakiWork *p, int procState);
int func_02185584(OekakiWork *p, int procState);
int func_021855C8(OekakiWork *p, int procState);
int func_021855EC(OekakiWork *p, int procState);
int func_02185628(OekakiWork *p, int procState);
int func_02185670(OekakiWork *p, int procState);
int func_021856AC(OekakiWork *p, int procState);
int func_021856CC(OekakiWork *p, int procState);
int func_021856F4(OekakiWork *p, int procState);
int func_02185730(OekakiWork *p, int procState);
int func_02185764(OekakiWork *p, int procState);
void func_021857F4(OekakiWork *p, int wordIndex, int netId);
int func_02185814(OekakiWork *p, int procState);
int func_02185854(OekakiWork *p, int procState);
int func_02185880(OekakiWork *p, int procState);
int func_021858B8(OekakiWork *p, int procState);
int func_02185930(int unused, int procState);
int func_02185934(OekakiWork *p, int procState);
int func_02185954(OekakiWork *p, int procState);
int func_02185974(OekakiWork *p, int procState);
int func_021859C4(OekakiWork *p, int procState);
int func_02185A1C(OekakiWork *p, int procState);
void func_02185AB0(OekakiWork *p, int event, int netId);
void func_02185BBC(struct BmpWin *canvas, const u8 *brushPixels, int x, int y, int width, int height, int srcX, int srcY, int maxCutX, int maxCutY);
void func_02185C38(struct BmpWin *canvas, const u8 *brushPixels, int x1, int y1, int *px, int *py, int newStroke, int prevCount);
void func_02185DA8(StrokeRec *strokes, LastPoint *last);
void func_02185DE8(struct BmpWin *canvas, StrokeRec *strokes, LastPoint *last, int redraw);
void func_02185EA0(OekakiWork *p);
void func_02185F10(u16 *angle);
int func_02185F50(OekakiWork *p);
void func_02185F74(struct BmpWin **windows, u16 color, OekakiWork *p);
void func_021860D0(OekakiWork *p);
int func_02186164(OekakiWork *p);
int func_02186170(OekakiWork *p);
void func_021861C4(OekakiWork *p, u32 msgId, int mode);
int func_021862B0(OekakiWork *p);
void func_021862F4(OekakiWork *p);
void func_02186304(OekakiWork *p, int flag);
int func_02186324(OekakiWork *p);
void func_02186444(OekakiWork *p, u32 nextScene);
void func_0218644C(OekakiWork *p, int mode);
void func_02186480(OekakiWork *p);
int func_021864A8(OekakiWork *p);
void func_021864C4(StrokeRec *stroke, TouchPoint *path, int color, int size);
int func_0218654C(OekakiWork *p);
int func_02186558(OekakiWork *p);
void func_02186564(void);
TaskMenu *func_021865B4(OekakiWork *p);
int func_02186660(OekakiWork *p);
void func_02186694(OekakiWork *p);
void func_021866C4(OekakiWork *p);
void func_02186708(OekakiWork *p);
void func_021867C4(OekakiWork *p);
void func_02186860(OekakiWork *p, int commandId, int arg);
int func_02186878(StrokeQueue *queue);
void func_02186888(StrokeQueue *queue);
void func_021868C8(StrokeQueue *queue);
void func_02186938(StrokeRec *rec);
void func_02186958(StrokeQueue *queue);
void func_02186988(StrokeBytes *stroke, StrokeQueue *queue, int index);
void func_021869C0(StrokeRec *dst, StrokeQueue *queue);
void func_02186A04(StrokeGroup *sendGroup, StrokeQueue *queue);






/*
 * Registers the net commands 0x2900..0x2907 of the application.
 */
void func_021841E0(OekakiWork *work)
{
    func_0203A574(OEKAKI_CMD_CANVAS_CHUNK, d_02186A6C, 8, work);
}






/*
 * Net command 0x2900: a chunk of the canvas arrives.
 */
void func_021841F8(int netId, int size, CanvasChunk *chunk, OekakiWork *work, int netHandle)
{
    int sent;
    int offset;
    struct BmpWin *window;

    if (func_02039338() != 0) {
        offset = chunk->index * 0x3e8;
        if (offset > 0x3840) {
            func_02082B0C(chunk, work->canvas + offset, 0x190);
        } else {
            func_02082B0C(chunk, work->canvas + offset, 0x3e8);
        }
        func_02082B0C(work->canvas,
                      func_020437D4(func_02045770(work->canvasWindow)),
                      OEKAKI_CANVAS_BYTES);
        window = work->canvasWindow;
        func_02045334(window);
        func_02045374(window);
        func_020409B4(func_02045730(window));
    } else {
        sent = work->nextChunk;
        if (sent * 1000 < 0x3840) {
            work->nextChunk += 1;
            func_021844D8(work, work->nextChunk, netHandle);
        } else {
            func_02186860(work, OEKAKI_CMD_CANVAS_DONE, 0);
        }
    }
}





/*
 * Net command 0x2901: one stroke of the member netId arrives (parent only).
 */
void func_021842A4(int netId, int size, const StrokeRec *stroke, OekakiWork *work)
{
    if (netId != 0)
        func_02186988((StrokeBytes *)stroke, &work->strokeQueue, netId);
}






/*
 * Net command 0x2902: the strokes of all members of one frame arrive (children).
 *
 * stand-in: the six bytes of each record are stored at dst[0x4212 + k] with
 * dst = work + i * 6. Typed fields (work->remoteStroke[i], with or without
 * a struct copy) hoist the address of the array and compile differently.
 */
void func_021842BC(int netId, int size, const u8 *strokes, OekakiWork *work)
{
    int i;
    u8 *dst;
    const u8 *src;

    if (work != 0 && netId == 0) {
        for (i = 0; i < OEKAKI_MEMBER_MAX; i++) {
            dst = (u8 *)work + i * 6;
            src = strokes + i * 6;
            dst[0x4212] = src[0];
            dst[0x4213] = src[1];
            dst[0x4214] = src[2];
            dst[0x4215] = src[3];
            dst[0x4216] = src[4];
            dst[0x4217] = src[5];
        }
    }
}






/*
 * The canvas is cleared and the member list is read again from the
 * union application.
 */
void func_02184320(int netId, int size, int unused, OekakiWork *work)
{
    func_02185AB0(work, 3, 0);
    func_02082AC0(0, work->canvas, OEKAKI_CANVAS_BYTES);
    work->baseMemberCount = func_021841A4(work->param->app);
    work->baseJoinedBits = func_021841A0(work->param->app);
    work->syncMode = 1;
}






/*
 * The message is copied field by field through a const pointer: that is
 * what lets the four loads pair up ahead of the stores and keeps msg->kind in
 * r0 for the switch (a struct copy, or a non-const msg, reloads it).
 *
 * Addresses are Black-image addresses.
 */
void func_02184368(int netId, int size, const OekakiSyncMsg *msg, OekakiWork *work)
{
    int sender;

    if (netId != 0) {
        if (func_02039338() != 0) {
            return;
        }
        work->stateMsg.netId = msg->netId;
        work->stateMsg.memberCount = msg->memberCount;
        work->stateMsg.kind = msg->kind;
        work->stateMsg.accepted = msg->accepted;
        work->stateMsg.netId = netId;
        work->stateMsg.memberCount = work->baseMemberCount;
        switch (msg->kind) {
        case OEKAKI_SYNC_CHECK:
            if (work->baseMemberCount != func_021841A4(work->param->app)
                || work->baseMemberCount != func_02080D24(func_021841A0(work->param->app))) {
                work->stateMsg.accepted = 0;
            } else {
                work->stateMsg.accepted = 1;
                func_02184134(work->param->app);
            }
            break;
        case OEKAKI_SYNC_STATUS:
            break;
        }
        func_02186860(work, OEKAKI_CMD_SYNC_MESSAGE, 0);
        return;
    }
    switch (msg->kind) {
    case OEKAKI_SYNC_CHECK:
        sender = msg->netId;
        if (sender != func_02039338()) {
            return;
        }
        if (msg->accepted == 0) {
            func_02185AB0(work, 0xb, sender);
            return;
        }
        work->agreedMemberCount = msg->memberCount;
        func_02185AB0(work, 9, msg->netId);
        work->quitting = 1;
        return;
    case OEKAKI_SYNC_STATUS:
        if (work->quitting == 0) {
            func_02185AB0(work, 0x18, msg->netId);
        }
        return;
    }
}






/*
 * Net command 0x2907: a child answers; its bit is set in ackBits (parent only).
 */
void func_02184454(int netId, int size, int unused, OekakiWork *work)
{
    if (func_02039338())
        return;
    work->waitMemberBits |= 1 << netId;
}






/*
 * Net command 0x2903: a member joined. The parent then starts to send the
 * canvas, chunk by chunk.
 */
void func_02184474(int netId, int size, u8 *data, OekakiWork *work, int netHandle)
{
    if (work->canvasReceived == 0) {
        func_02185AB0(work, 1, *data);
        if (func_02039338() == 0 && work->state == 1) {
            work->nextChunk = 0;
            func_021844D8(work, 0, netHandle);
        }
    }
}





/*
 * Net command 0x2904: the whole canvas was sent.
 */
void func_021844B4(int netId, int size, int unused, OekakiWork *work)
{
    work->canvasReceived = 1;
    if (func_02039338() != 0)
        func_02185AB0(work, 0x12, 0);
}




/*
 * Sends chunk chunkIndex of the canvas to all members. The extent runs
 * long: 0x0218454C is an unlabelled leaf,
 * CanvasChunk *f(int netId, OekakiWork *work) { return &work->recvChunk[netId]; }
 */
u32 func_021844D8(OekakiWork *work, int chunkIndex, int unused)
{
    int i;
    u32 *words;
    u8 *pixels;
    u32 sum;
    u8 joinedBits;

    pixels = func_020437D4(func_02045770(work->canvasWindow));
    func_02082B0C(pixels + chunkIndex * 1000, work->sendChunk.data, 1000);
    words = (u32 *)work->sendChunk.data;
    sum = 0;
    for (i = 0; i < 250; i++)
        sum ^= words[i];
    work->sendChunk.checksum = sum;
    work->sendChunk.index = chunkIndex;
    joinedBits = (u32)func_021841A0(work->param->app);
    return GFL_NET_COMMAND_SetSendSlot(func_0203996C(0xff), joinedBits, OEKAKI_CMD_CANVAS_CHUNK, 0x3f0, &work->sendChunk);
}




CanvasChunk *func_0218454C(int netId, OekakiWork *work)
{
    return &work->recvChunk[netId];
}





/*
 * Opens the group to maxCount members (the parent decides how many join).
 */
void func_02184560(OekakiWork *work, int maxCount)
{
    func_02184148(work->param->app, maxCount);
}





/*
 * Step function: builds the application (screens, graphics, resources, net
 * commands) and starts the main step.
 *
 * Addresses are Black-image addresses.
 */
int func_0218456C(void *task, int *state, OekakiParam *param)
{
    OekakiWork *work;
    void *archive;

    switch (*state) {
    case 0:
        BG_SYS_ClearMainPlanes();
        BG_SYS_ClearSubPlanes();
        func_0203064C(1, OEKAKI_HEAP_ID, 0x50000);
        work = func_0203159C(task, OEKAKI_WORK_SIZE, OEKAKI_HEAP_ID);
        func_02082BCC(work, 0, OEKAKI_WORK_SIZE);
        func_0203F8F4(OEKAKI_HEAP_ID);
        work->wordSet = func_0201EC64(OEKAKI_HEAP_ID);
        work->msgBank = func_02045B38(0, 2, 0x53, OEKAKI_HEAP_ID);
        work->font = func_0201D7EC(0x17, 0, 0, 0, OEKAKI_HEAP_ID);
        func_021848D0();
        func_021848E0();
        func_0202208C(0, 9, 9, 0, 0x10, 1, OEKAKI_HEAP_ID);
        work->param = param;
        archive = func_020490F4(0xbf, OEKAKI_HEAP_ID);
        func_02184B78(work, archive);
        work->vblankTask = func_020056A0(func_0218489C, work, 0);
        func_021849F8(work);
        func_02184C48(work, archive);
        func_02184D30(work);
        func_02184ECC(work, task);
        func_02186564();
        func_021841E0(work);
        func_021866C4(work);
        func_0203D34C(1, OEKAKI_HEAP_ID);
        func_02049238(archive);
        (*state)++;
        break;
    case 1:
        *state = 0;
        return 1;
    }
    return 0;
}





/*
 * Main step. The mode handlers take (work, *state): the switch value,
 * reused as their second argument, is what keeps it live in r1 through the
 * dispatch (a one-argument callback puts the whole dispatch in r0).
 * func_0218644C is void but leaves r0 = work; no hidden argument here.
 *
 * Addresses are Black-image addresses.
 */
int func_02184674(void *task, int *state, int unused, OekakiWork *work)
{
    int (*handler)(OekakiWork *work, int state);
    int next;

    if (func_02039338() == 0 && work->waitMemberBits != 0) {
        work->waitMemberBits = func_02186558(work) & work->waitMemberBits;
    }
    work->state = *state;
    func_0218644C(work, *state);
    switch (*state) {
    case 0:
        if (func_020221A4() != 0) {
            func_021840FC(work->param->app, func_021848A8, func_021848CC, work);
            if (func_02039338() == 0) {
                func_02184560(work, 1);
            }
            *state = 1;
        }
        break;
    case 1:
        handler = d_02186E80[work->scene].handler;
        if (handler != 0) {
            *state = handler(work, *state);
        }
        func_02185F74(work->nameWindow, 0x44f, work);
        if (func_02039338() == 0) {
            next = func_02186324(work);
            if (*state == 1) {
                *state = next;
            }
        }
        func_02185F10(&work->paletteAngle);
        break;
    case 2:
        handler = d_02186E80[work->scene].handler;
        if (handler != 0 && d_02186E80[work->scene].runsInWait != 0) {
            *state = handler(work, *state);
        }
        break;
    case 3:
        if (func_020221A4() != 0) {
            func_0203A5E4(OEKAKI_CMD_CANVAS_CHUNK);
            func_02184174(work->param->app);
            *state = 4;
        }
        break;
    case 4:
        if (func_0218417C(work->param->app) != 0) {
            return 1;
        }
        break;
    }
    func_021867C4(work);
    func_0204A600();
    func_020310C4(work->taskList);
    func_02186708(work);
    if (func_020221A4() != 0 && func_0200FB24() != 0) {
        return 1;
    }
    return 0;
}





/*
 * Exit step: frees the resources and the work in order.
 */
int func_021847C8(struct S020315D4 *task, int *seq, void *unused, OekakiWork *work)
{
    switch (*seq) {
    case 0:
        func_02030EAC(work->vblankTask);
        func_0204A8D4(work->nameTagRes.charRes);
        func_0204ADA4(work->nameTagRes.plttRes);
        func_0204AFD8(work->nameTagRes.cellRes);
        func_0204A8D4(work->buttonRes.charRes);
        func_0204ADA4(work->buttonRes.plttRes);
        func_0204AFD8(work->buttonRes.cellRes);
        func_0204A8D4(work->cursorRes.charRes);
        func_0204ADA4(work->cursorRes.plttRes);
        func_0204AFD8(work->cursorRes.cellRes);
        func_0204B1CC(work->clactSys);
        func_0204A5AC();
        if (work->menu != 0) {
            func_02186694(work);
        }
        func_02185004(work);
        func_02184B34();
        func_02045C04(work->msgBank);
        func_0201ED04(work->wordSet);
        func_0201D83C(work->font);
        (*seq)++;
        break;
    case 1:
        (*seq)++;
        break;
    case 2:
        if (work->memberLeft != 0) {
            if (func_02186558(work) == 1) {
                (*seq)++;
            }
        } else {
            (*seq)++;
        }
        break;
    case 3:
        func_02184B04(work);
        func_020315D4(task);
        func_020306F0(OEKAKI_HEAP_ID);
        return 1;
    }
    return 0;
}





/*
 * Task that runs every vertical blank.
 */
void func_0218489C(void)
{
    func_0204A648();
    func_020419E4();
}




/*
 * Member join callback of the union application (the parent announces the
 * new member to the others). Extent follower 0x021848CC is already matched
 * separately.
 */
void func_021848A8(int netId, UnionAppEntry *entry, void *arg)
{
    OekakiWork *work = arg;

    if (func_02039338() == 0)
        func_02186860(work, OEKAKI_CMD_MEMBER_JOINED, netId);
    func_021866C4(work);
}




/*
 * Member leave callback of the union application: nothing to do. An
 * unlabelled empty function (a lone bx lr after func_021848A8's pool);
 * func_02184674 hands its address to ov022 func_021840FC. Blocker of
 * ov023 func_02184674.
 */
void func_021848CC(int netId, UnionAppEntry *entry, void *work)
{
}





/*
 * Tail call: apply the VRAM bank descriptor at 0x02186ACC.
 */
void func_021848D0(void)
{
    func_020433E0(&d_02186ACC);
}



void func_021848E0(void)
{
    DispConfig dispConfig;
    BgTemplate bg0;
    BgTemplate bg1;
    BgTemplate bg2;
    BgTemplate bg4;
    BgTemplate bg5;

    dispConfig = d_02186B3C;
    func_0203FC28(&dispConfig);

    bg0 = d_02186BCC;
    func_0203FCA0(0, &bg0, 0);
    func_020414EC(0);

    bg1 = d_02186B6C;
    func_0203FCA0(1, &bg1, 0);
    func_020414EC(1);

    bg2 = d_02186B8C;
    func_0203FCA0(2, &bg2, 0);

    bg4 = d_02186BAC;
    func_0203FCA0(4, &bg4, 0);
    func_020414EC(4);

    bg5 = d_02186B4C;
    func_0203FCA0(5, &bg5, 0);

    func_02040B94(0, 0x20, 0, OEKAKI_HEAP_ID);
    func_02040B94(4, 0x20, 0, OEKAKI_HEAP_ID);
    func_02040B94(1, 0x20, 0, OEKAKI_HEAP_ID);
    func_02040B94(5, 0x20, 0, OEKAKI_HEAP_ID);
}



/*
 * Sets the initial values of the work.
 */
void func_021849F8(OekakiWork *work)
{
    int i = 0;
    int zero = i;

    for (; i < OEKAKI_MEMBER_MAX; i++) {
        work->playerName[i] = func_020457B0(8, OEKAKI_HEAP_ID);
        work->remoteStroke[i].count = 0;
        work->lastPoint[i].count = zero;
        work->memberSlot[i].current = (UnionAppEntry *)zero;
        work->memberSlot[i].previous = (UnionAppEntry *)zero;
    }
    work->labelText = func_020457B0(0xA, OEKAKI_HEAP_ID);
    work->messageText = func_020457B0(0x50, OEKAKI_HEAP_ID);
    work->penColor = zero;
    work->penSize = 1;
    work->syncMode = 1;
    work->menuOpen = zero;
    work->baseMemberCount = 2;
    work->baseJoinedBits = func_02186558(work);
    work->leaveRequested = zero;
    work->memberLeft = zero;
    work->scene = zero;
    work->newMemberPending = zero;
    work->newMemberBits = zero;
    work->menu = (TaskMenu *)zero;
    func_02039338();
    func_02186444(work, 4);
    func_02045CAC(work->msgBank, 7, work->labelText);
    work->tempBuf = func_02030734(OEKAKI_HEAP_ID, 0x3C00, zero, d_02186F58, 0x31D);
    work->lastMemberCount = zero;
}


void func_02184B04(OekakiWork *work)
{
    int i;
    func_020307B0(work->tempBuf);
    for (i = 0; i < OEKAKI_MEMBER_MAX; i++)
        func_02045808(work->playerName[i]);
    func_02045808(work->messageText);
    func_02045808(work->labelText);
}



void func_02184B34(void)
{
    func_0207D534((volatile u16 *)REG_MASTER_BRIGHT_A, -16);
    func_0207D534((volatile u16 *)REG_MASTER_BRIGHT_B, -16);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_0203F9B4();
}



void func_02184B78(OekakiWork *work, void *archive)
{
    func_02049B68(archive, 0, 0, 0, 0x180, OEKAKI_HEAP_ID);
    func_02049B68(archive, 1, 4, 0, 0x180, OEKAKI_HEAP_ID);
    func_02049B40(0x17, 5, 0, 0x1A0, 0x20, OEKAKI_HEAP_ID);
    func_02049B40(0x17, 5, 4, 0x1A0, 0x20, OEKAKI_HEAP_ID);
    func_02049658(archive, 2, 2, 0, 0x2000, 0, OEKAKI_HEAP_ID);
    func_020498F4(archive, 6, 2, 0, 0x600, 0, OEKAKI_HEAP_ID);
    func_02049658(archive, 4, 5, 0, 0x2000, 0, OEKAKI_HEAP_ID);
    func_020498F4(archive, 7, 5, 0, 0x600, 0, OEKAKI_HEAP_ID);
    func_0201F5BC(0, 1, 10, 0, OEKAKI_HEAP_ID);
    func_0201F5BC(0, 0x1F, 11, 0, OEKAKI_HEAP_ID);
}



void func_02184C48(OekakiWork *work, void *archive)
{
    void *uiArchive;
    u32 plttIndex;

    uiArchive = func_020490F4(func_020275E4(), OEKAKI_HEAP_ID);
    func_0204A48C(d_020A1448, &d_02186ACC, OEKAKI_HEAP_ID);
    work->clactSys = func_0204B100(0x35, 1, OEKAKI_HEAP_ID);
    work->cursorRes.charRes = func_0204A6C8(archive, 3, 0, 0, OEKAKI_HEAP_ID);
    work->cursorRes.plttRes = func_0204ABF0(archive, 0, 0, 0, OEKAKI_HEAP_ID);
    work->cursorRes.cellRes = func_0204AF28(archive, 5, 8, OEKAKI_HEAP_ID);
    work->buttonRes.charRes = func_0204A6C8(uiArchive, func_02027618(), 0, 0, OEKAKI_HEAP_ID);
    work->buttonRes.plttRes = func_0204AC18(uiArchive, func_02027614(), 0, 0x160, 0, 3, OEKAKI_HEAP_ID);
    plttIndex = func_0202761C(0);
    work->buttonRes.cellRes = func_0204AF28(uiArchive, plttIndex, func_02027620(0), OEKAKI_HEAP_ID);
    work->nameTagRes.charRes = func_0204A6C8(archive, 3, 0, 1, OEKAKI_HEAP_ID);
    work->nameTagRes.plttRes = func_0204ABF0(archive, 0, 1, 0, OEKAKI_HEAP_ID);
    work->nameTagRes.cellRes = func_0204AF28(archive, 5, 8, OEKAKI_HEAP_ID);
    func_02049238(uiArchive);
}


void func_02184D30(OekakiWork *p)
{
    ClActorPos pos;
    int i;
    int j;

    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    pos.drawType = 1;
    pos.visible = 1;
    for (i = 0; i < 5; i++) {
        pos.x = i * 0x28 + 0x18;
        pos.y = 0x40;
        p->cursorActor[i] = func_0204B294(p->clactSys, p->cursorRes.charRes, p->cursorRes.plttRes, p->cursorRes.cellRes, &pos, 0, 0x28);
        func_0204B92C(p->cursorActor[i], 1);
        func_0204B878(p->cursorActor[i], i);
        func_0204B3DC(p->cursorActor[i], 0);
    }
    for (j = 0; j < 12; j++) {
        pos.x = d_02186BEC[j].x;
        pos.y = d_02186BEC[j].y;
        p->colorButton[j] = func_0204B294(p->clactSys, p->cursorRes.charRes, p->cursorRes.plttRes, p->cursorRes.cellRes, &pos, 0, 0x28);
        func_0204B92C(p->colorButton[j], 1);
        func_0204B878(p->colorButton[j], d_02186BEC[j].anim);
        if (j >= 8) {
            func_0204B84C(p->colorButton[j], 2);
        }
    }
    func_0204B878(p->colorButton[0], 6);
    for (i = 0; i < 5; i++) {
        pos.x = 0x18;
        pos.y = i * 0x20 + 0x20 + 0x100000u;
        p->nameTagActor[i] = func_0204B294(p->clactSys, p->nameTagRes.charRes, p->nameTagRes.plttRes, p->nameTagRes.cellRes, &pos, 1, 0x28);
        func_0204B92C(p->nameTagActor[i], 1);
        func_0204B878(p->nameTagActor[i], i);
        CLACT_SetActorDrawPriority(p->nameTagActor[i], 1);
        func_0204B3DC(p->nameTagActor[i], 0);
    }
    pos.x = 0xD4;
    pos.y = 0xA0;
    p->quitButton = func_0204B294(p->clactSys, p->buttonRes.charRes, p->buttonRes.plttRes, p->buttonRes.cellRes, &pos, 0, 0x28);
    func_0204B92C(p->quitButton, 1);
    func_0204B878(p->quitButton, 1);
    func_0204B3DC(p->quitButton, 1);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}

/* The task argument is unused; the caller passes it and the compiled code must carry it in r1. */
void func_02184ECC(OekakiWork *p, void *task)
{
    int i;
    struct BmpWin *window;

    func_02045088(0x28);
    p->messageWindow = func_020450F0(0, 2, 1, 0x1b, 4, 0xd, 1);
    func_02043B5C(func_02045770(p->messageWindow), 0xf);
    p->printJob[6].window = p->messageWindow;
    p->printJob[6].busy = 0;
    p->canvasWindow = func_020450F0(1, 1, 2, 0x1e, 0xf, 0, 1);
    func_02043B5C(func_02045770(p->canvasWindow), 2);
    p->taskList = func_0203101C(0x28, 0x28, 0x20, 0x20);
    p->namePrinter = func_0201C440(0x28);
    p->messagePrinter = func_0201C440(0x28);
    for (i = 0; i < 5; i++) {
        p->nameWindow[i] = func_020450F0(4, 5, (u8)(i * 4 + 3), 0xa, 2, 0xd, 1);
        func_02043B5C(func_02045770(p->nameWindow[i]), 0);
        /* the print job keeps its own copy of the window pointer */
        p->printJob[i].window = p->nameWindow[i];
        p->printJob[i].busy = 0;
        window = p->nameWindow[i];
        func_02045334(window);
        func_02045374(window);
        func_020409B4(func_02045730(window));
    }
    func_02185F74(p->nameWindow, 0x44f, p);
}

void func_02185004(OekakiWork *p)
{
    int i;

    TCBL_DeleteAllTasks(p->taskList);
    func_02031140(p->taskList);
    func_0201C6EC(p->messagePrinter);
    func_0201C4C0(p->messagePrinter);
    func_0201C6EC(p->namePrinter);
    func_0201C4C0(p->namePrinter);
    for (i = 0; i < 5; i++)
        func_020452E8(p->nameWindow[i]);
    func_020452E8(p->canvasWindow);
    func_020452E8(p->messageWindow);
    func_020450C8();
}

void func_0218506C(ClActor *actor, int x, int y)
{
    Point16 pt;

    pt.x = x;
    pt.y = y - 8;
    func_0204B528(actor, &pt);
}

void func_02185080(StrokeRec *stroke, int color, int size)
{
    TouchPath path;

    path.pt[0].count = 0;
    path.pt[0].x = 0;
    path.pt[0].y = 0;
    func_021864C4(stroke, path.pt, color, size);
}

/* Shared tail of the quit button press: message, state change, button animation, sound. */
static inline u8 pressQuit(OekakiWork *p, int value)
{
    func_021861C4(p, value, value);
    func_02186444(p, 5);
    func_021852F4(p->quitButton, 1);
    func_020061E4(0x551);
    return value;
}

/*
 * Lever: the activation tail is an inline returning its flag value;
 * assigning the returned u8 to pressed recolours the merged flag store to r1.
 * The pointer-out helper and inline assignment stayed DIFF by two bytes.
 */
void func_021850A0(OekakiWork *p)
{
    TouchPath path;
    int touchX;
    int touchY;
    StrokeRec stroke;
    int x;
    int y;
    u8 pressed;
    int hit;
    int i;

    pressed = 0;
    hit = func_02035C08(d_02186AFC);
    if (hit != -1) {
        switch (hit) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            if (p->penColor != hit) {
                p->penColor = hit;
                func_021852B4(p->colorButton, hit);
                func_020061E4(0x548);
            }
            break;
        case 8:
            if (p->scene != 4)
                break;
            if (func_02039338() == 0) {
                if (p->baseJoinedBits != func_02186558(p)) {
                    func_020061E4(0x54b);
                } else {
                    p->syncMode = 2;
                    pressed = pressQuit(p, 1);
                }
            } else {
                if (p->remoteStroke[0].syncMode == 2) {
                    func_020061E4(0x54b);
                } else {
                    pressed = pressQuit(p, 1);
                }
            }
            break;
        case 9:
        case 10:
        case 11:
            for (i = 0; i < 3; i++) {
                if (hit - 9 == i)
                    func_0204B878(p->sizeButton[i], i * 2 + 0x1e);
                else
                    func_0204B878(p->sizeButton[i], i * 2 + 0x1d);
            }
            if (p->penSize != hit - 9) {
                p->penSize = hit - 9;
                func_020061E4(0x548);
            }
            break;
        }
    }
    hit = TOUCHPANEL_HitCont(d_02186AB4);
    func_0204B3DC(p->cursorActor[func_02039338()], 0);
    if (hit != -1) {
        TOUCHPANEL_GetPointCont((u32 *)&touchX, (u32 *)&touchY);
        func_0218506C(p->cursorActor[func_02039338()], touchX, touchY);
        func_0204B3DC(p->cursorActor[func_02039338()], 1);
    }
    x = 0;
    y = 0;
    if (func_02035C38() == 1) {
        TOUCHPANEL_GetPointCont((u32 *)&x, (u32 *)&y);
        path.pt[0].count = 2;
        path.pt[0].x = p->touchPath.pt[1].x;
        path.pt[0].y = p->touchPath.pt[1].y;
        path.pt[1].x = x;
        path.pt[1].y = y;
        func_021864C4(&stroke, path.pt, p->penColor, p->penSize);
        if (pressed == 1)
            stroke.count = 0;
    } else {
        path.pt[1].x = 0;
        path.pt[1].y = 0;
        func_02185080(&stroke, p->penColor, p->penSize);
    }
    func_02186988((StrokeBytes *)&stroke, &p->strokeQueue, 0);
    if (func_02039338() == 0)
        func_021868C8(&p->strokeQueue);
    else
        func_02186888(&p->strokeQueue);
    p->touchPath = path;
}

void func_021852B4(ClActor **buttons, int selected)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (i == selected)
            func_0204B878(buttons[i], (u16)(d_02186BEC[i].anim + 1));
        else
            func_0204B878(buttons[i], d_02186BEC[i].anim);
    }
}

void func_021852F4(ClActor *button, int pressed)
{
    if (pressed == 1)
        func_0204B878(button, 9);
    else
        func_0204B878(button, 1);
}

int func_0218530C(OekakiWork *p, int procState)
{
    func_021850A0(p);
    if (func_02039338() == 0) {
        if (func_02185F50(p) == 1) {
        } else {
            func_021860D0(p);
        }
    } else {
        func_021860D0(p);
    }
    func_02185EA0(p);
    func_02185DE8(p->canvasWindow, p->remoteStroke, p->lastPoint, 1);
    return procState;
}

void func_02185354(OekakiWork *p)
{
    func_02185EA0(p);
    func_02185DE8(p->canvasWindow, p->remoteStroke, p->lastPoint, 0);
}

int func_02185378(OekakiWork *p, int procState)
{
    if (p->painterNetId == func_02039338())
        func_021861C4(p, 0xd, 0);
    else
        func_021861C4(p, 0, 0);
    func_02186444(p, 2);
    func_02186480(p);
    func_020061E4(0x54c);
    func_0207D658(0x04000050, 14, -6);
    func_02185354(p);
    return procState;
}

int func_021853D0(OekakiWork *p, int procState)
{
    int i;

    for (i = 0; i < 5; i++)
        func_0204B3DC(p->cursorActor[i], 0);
    return procState;
}

/*
 * volatile: hardware halfword store at 0x021853F8 to 0x04000050.
 */
int func_021853F0(OekakiWork *p, int procState)
{
    *(volatile u16 *)0x04000050 = 0;
    func_02186304(p, 1);
    func_02186444(p, 4);
    func_02185354(p);
    p->newMemberPending = 0;
    return procState;
}

int func_02185420(OekakiWork *p, int procState)
{
    if (func_021862B0(p)) {
        if (p->menu == 0)
            p->menu = func_021865B4(p);
        func_02186444(p, 6);
    }
    func_02185354(p);
    return procState;
}

int func_02185454(OekakiWork *p, int procState)
{
    struct BmpWin *window;

    p->localStroke.count = 0;
    if (p->remoteStroke[0].syncMode == 2 && func_02039338() != 0) {
        func_02185354(p);
        APP_TASKMENU_TransWinAfterPrint(p->menu);
        if (func_021864A8(p))
            func_020061E4(0x54b);
        return procState;
    }
    if (func_02039338() == 0 && p->waitMemberBits != 0) {
        func_02185354(p);
        APP_TASKMENU_TransWinAfterPrint(p->menu);
        return procState;
    }
    switch (func_02186660(p)) {
    case 0:
        if (func_02039338() == 0) {
            func_02186444(p, 0xf);
            func_021861C4(p, 4, 1);
        } else {
            func_02186444(p, 8);
            func_0201F7A8(p->messageWindow, 2);
        }
        window = p->canvasWindow;
        func_02045334(window);
        func_02045374(window);
        func_020409B4(func_02045730(window));
        break;
    case 1:
        func_02186444(p, 4);
        func_021852F4(p->quitButton, 0);
        func_0201F7A8(p->messageWindow, 2);
        window = p->canvasWindow;
        func_02045334(window);
        func_02045374(window);
        func_020409B4(func_02045730(window));
        if (func_02039338() == 0) {
            func_02184560(p, 1);
            p->syncMode = 1;
        }
        break;
    }
    func_02185354(p);
    return procState;
}

int func_02185584(OekakiWork *p, int procState)
{
    OekakiSyncMsg msg;

    func_02082BCC(&msg, 0, 4);
    msg.kind = OEKAKI_SYNC_CHECK;
    msg.netId = func_02039338();
    if (func_0203D3A8(func_020399A8(), 0x2905, 4, (u32)&msg))
        func_02186444(p, 7);
    func_02185354(p);
    return procState;
}

int func_021855C8(OekakiWork *p, int procState)
{
    p->localStroke.count = 0;
    p->waitFrames = 0;
    func_02185354(p);
    return procState;
}

int func_021855EC(OekakiWork *p, int procState)
{
    p->localStroke.count = 0;
    (*(s16 *)&p->waitFrames) += 1;
    if ((s16)p->waitFrames > 0x1e) {
        func_02186444(p, 0xa);
        p->waitFrames = 0;
    }
    func_02185354(p);
    return procState;
}

int func_02185628(OekakiWork *p, int procState)
{
    OekakiSyncMsg msg;

    func_02082BCC(&msg, 0, 4);
    msg.kind = OEKAKI_SYNC_STATUS;
    msg.netId = func_02039338();
    if (func_0203D3A8(func_020399A8(), 0x2905, 4, (u32)&msg))
        func_02186444(p, 12);
    func_02185354(p);
    return procState;
}

int func_02185670(OekakiWork *p, int procState)
{
    p->localStroke.count = 0;
    p->quitting = 0;
    func_02186444(p, 4);
    func_021852F4(p->quitButton, 0);
    func_02185354(p);
    return procState;
}

int func_021856AC(OekakiWork *p, int procState)
{
    func_021861C4(p, 6, 1);
    func_02186444(p, 0xd);
    func_02185354(p);
    return procState;
}

int func_021856CC(OekakiWork *p, int procState)
{
    if (func_021862B0(p)) {
        p->timer = 0;
        func_02186444(p, 0xe);
    }
    func_02185354(p);
    return procState;
}

int func_021856F4(OekakiWork *p, int procState)
{
    if (++p->timer > 60) {
        func_0202208C(0, 8, 8, 0, 0x10, 1, 0x28);
        procState = 3;
    }
    func_02185354(p);
    return procState;
}

int func_02185730(OekakiWork *p, int procState)
{
    if (func_021862B0(p)) {
        if (p->menu == 0)
            p->menu = func_021865B4(p);
        func_02186444(p, 0x10);
    }
    func_02185354(p);
    return procState;
}

int func_02185764(OekakiWork *p, int procState)
{
    int menuResult;

    menuResult = func_02186660(p);
    if (p->baseMemberCount != func_02186164(p) || p->waitMemberBits != 0) {
        func_02185354(p);
        return procState;
    }
    switch (menuResult) {
    case 0:
        func_02186444(p, 0x11);
        func_02184114(p->param->app);
        break;
    case 1:
        func_02186444(p, 4);
        func_021852F4(p->quitButton, 0);
        func_0201F7A8(p->messageWindow, 2);
        if (func_02039338() == 0) {
            func_02184560(p, 1);
            p->syncMode = 1;
        }
        break;
    }
    func_02185354(p);
    return procState;
}

/*
 * Original narrows the lookup index to u8; its extern expresses the observed call-site width.
 */
void func_021857F4(OekakiWork *p, int wordIndex, int netId)
{
    UnionAppEntry *entry;

    entry = func_02184180(p->param->app, (u8)netId);
    if (entry != 0)
        func_0201F02C(p->wordSet, wordIndex, entry);
}

int func_02185814(OekakiWork *p, int procState)
{
    int zero;

    zero = 0;
    if (func_0203D3A8(func_0203996C(0xff), 0x2906, 0, 0)) {
        func_02186444(p, 0x12);
        func_021857F4(p, zero, zero);
        procState = 2;
    }
    func_02185354(p);
    return procState;
}

int func_02185854(OekakiWork *p, int procState)
{
    func_021857F4(p, 0, 0);
    func_021861C4(p, 3, 1);
    func_02186444(p, 0x13);
    func_02185354(p);
    return procState;
}

/*
 * extent: two zero padding bytes follow the return at 0x021858B4.
 * Original narrows r3 to u16 before GFL_NET_HANDLE_SetUserInfo, retained in the call prototype.
 */
int func_02185880(OekakiWork *p, int procState)
{
    if (func_021862B0(p)) {
        func_02186444(p, 0x14);
        GFL_NET_HANDLE_SetUserInfo(func_020399A8(), 0xc8, 0x29, (u16)p->baseJoinedBits);
    }
    func_02185354(p);
    return procState;
}

int func_021858B8(OekakiWork *p, int procState)
{
    NetHandle *handle;
    int i;
    int connectedBits;

    handle = func_020399A8();
    connectedBits = 0;
    for (i = 0; i < 5; i++) {
        if (func_0203D1C0((unsigned char)i) == 1)
            connectedBits |= 1 << i;
    }
    if (func_02039CB4(handle, 0xc8, 0x29) != 0 || func_0218654C(p) == 1
        || connectedBits != p->baseJoinedBits) {
        func_0202208C(0, 8, 8, 0, 0x10, 1, 0x28);
        procState = 3;
    }
    func_02185354(p);
    return procState;
}

int func_02185930(int unused, int procState)
{
    return procState;
}

int func_02185934(OekakiWork *p, int procState)
{
    func_021861C4(p, 5, 1);
    func_02186444(p, 0x17);
    func_02185354(p);
    return procState;
}

int func_02185954(OekakiWork *p, int procState)
{
    if (func_021862B0(p))
        func_02186444(p, 0xe);
    func_02185354(p);
    return procState;
}

int func_02185974(OekakiWork *p, int procState)
{
    func_021861C4(p, 2, 1);
    func_02186480(p);
    func_02186444(p, 0x19);
    func_020061E4(0x54c);
    if (func_02039338() == 0)
        func_02186304(p, 0);
    p->waitMemberCount = func_0218654C(p);
    func_02185354(p);
    return procState;
}

int func_021859C4(OekakiWork *p, int procState)
{
    if (!((p->waitMemberCount == 0 || p->waitMemberCount == func_0218654C(p))
          && (func_02186558(p) & p->waitMemberBits)))
        p->waitMemberCount = 0;
    if (func_021862B0(p)) {
        func_02186444(p, 0x1a);
        p->timer = 0;
    }
    func_02185354(p);
    return procState;
}

int func_02185A1C(OekakiWork *p, int procState)
{
    if (!((p->waitMemberCount == 0 || p->waitMemberCount == func_0218654C(p))
          && (func_02186558(p) & p->waitMemberBits)))
        p->waitMemberCount = 0;
    p->timer += 1;
    if (p->timer > 0x3c && p->waitMemberCount == 0) {
        func_021862F4(p);
        func_02186444(p, 4);
        if (func_02039338() == 0) {
            p->syncMode = 1;
            func_02186304(p, 1);
        }
        p->baseMemberCount = func_021841A4(p->param->app);
        p->baseJoinedBits = func_021841A0(p->param->app);
    }
    func_02185354(p);
    return procState;
}

void func_02185AB0(OekakiWork *p, int event, int netId)
{
    struct BmpWin *window;

    switch (event) {
    case 1:
        if (p->quitting == 1)
            return;
        if (p->scene == 6 || p->scene == 0x10)
            func_02186480(p);
        func_021852F4(p->quitButton, 0);
        func_021857F4(p, 0, netId);
        p->painterNetId = netId;
        p->waitMemberBits = 0;
        break;
    case 3:
        func_021862F4(p);
        break;
    case 0xb:
    case 0x12:
        break;
    case 0x18:
        if (p->quitting == 1)
            return;
        func_021857F4(p, 0, netId);
        if (netId == func_02039338())
            return;
        if (func_02039338() == 0)
            p->waitMemberBits = p->waitMemberBits & (netId ^ 0xFFFF);
        if (p->scene == 6 || p->scene == 0x10) {
            func_02186480(p);
            window = p->canvasWindow;
            func_02045334(window);
            func_02045374(window);
            func_020409B4(func_02045730(window));
        }
        func_021852F4(p->quitButton, 0);
        break;
    case 9:
        func_02186860(p, 0x2907, func_02039338());
        break;
    default:
        return;
    }
    func_02186444(p, event);
}

/*
 * Clearing dx/dy before the w/h subtraction is what moves a1 into r0 at
 * entry (t in r1, the bound in r2); clearing it last keeps a1 in r1.
 */
void func_02185BBC(struct BmpWin *canvas, const u8 *brushPixels, int x, int y, int width, int height, int srcX, int srcY,
                   int maxCutX, int maxCutY)
{
    struct Bmp *brushBmp;
    int cut;

    if (srcX < 0) {
        cut = -srcX;
        if (cut > maxCutX)
            cut = maxCutX;
        x += cut;
        srcX = 0;
        width -= cut;
    }
    if (srcY < 0) {
        cut = -srcY;
        if (cut > maxCutY)
            cut = maxCutY;
        y += cut;
        srcY = 0;
        height -= cut;
    }
    brushBmp = func_020436FC(brushPixels, 8, 8, 0x20, 0x28);
    func_020439A0(brushBmp, func_02045770(canvas), x, y, srcX, srcY, width, height, 0);
    func_020437AC(brushBmp);
}

/* Draws a line of brush stamps from (*px, *py) to (x1, y1) (Bresenham). */
void func_02185C38(struct BmpWin *canvas, const u8 *brushPixels, int x1, int y1, int *px, int *py, int newStroke, int prevCount)
{
    int startX;
    int startY;
    int endX;
    int deltaX;
    int endY;
    int deltaY;
    int error;
    int step;

    startX = *px;
    startY = *py;
    endX = x1;
    endY = y1;
    if (newStroke == 0 && prevCount == 0) {
        *px = x1;
        *py = y1;
        return;
    }
    deltaX = x1 - startX;
    if (deltaX < 0)
        deltaX = -deltaX;
    deltaY = y1 - startY;
    if (deltaY < 0)
        deltaY = -deltaY;
    if (deltaX > deltaY) {
        if (startX > x1) {
            step = (startY > y1) ? 1 : -1;
            endX = startX;
            startX = x1;
            startY = y1;
        } else {
            step = (startY < y1) ? 1 : -1;
        }
        func_02185BBC(canvas, brushPixels, 0, 0, 6, 6, startX, startY, 6, 6);
        error = deltaX >> 1;
        for (startX++; startX <= endX; startX++) {
            error -= deltaY;
            if (error < 0) {
                error += deltaX;
                startY += step;
            }
            func_02185BBC(canvas, brushPixels, 0, 0, 6, 6, startX, startY, 6, 6);
        }
    } else {
        if (startY > y1) {
            step = (startX > x1) ? 1 : -1;
            endY = startY;
            startY = y1;
            startX = x1;
        } else {
            step = (startX < x1) ? 1 : -1;
        }
        func_02185BBC(canvas, brushPixels, 0, 0, 6, 6, startX, startY, 6, 6);
        error = deltaY >> 1;
        for (startY++; startY <= endY; startY++) {
            error -= deltaX;
            if (error < 0) {
                error += deltaY;
                startX += step;
            }
            func_02185BBC(canvas, brushPixels, 0, 0, 6, 6, startX, startY, 6, 6);
        }
    }
    *px = x1;
    *py = y1;
}

/* Remembers the last point and the point count of every member's stroke. */
void func_02185DA8(StrokeRec *strokes, LastPoint *last)
{
    int i;

    for (i = 0; i < 5; i++) {
        last[i].count = strokes[i].count;
        if (strokes[i].count != 0) {
            last[i].x = *((unsigned char *)&strokes[i] + strokes[i].count - 1);
            last[i].y = *((unsigned char *)&strokes[i] + strokes[i].count + 1);
        }
    }
}

void func_02185DE8(struct BmpWin *canvas, StrokeRec *strokes, LastPoint *last, int redraw)
{
    int drew;
    int i;
    int x;
    int y;

    drew = 0;
    for (i = 0; i < 5; i++) {
        if (strokes[i].count == 2) {
            x = strokes[i].x0 - 9;
            y = strokes[i].y0 - 0x11;
            func_02185C38(canvas, d_02186C34 + strokes[i].size * 0xc0 + strokes[i].color * 0x18,
                          strokes[i].x1 - 9, strokes[i].y1 - 0x11, &x, &y, 1, last[i].count);
            drew = 1;
        }
    }
    if (drew && redraw) {
        func_02045334(canvas);
        func_02045374(canvas);
        func_020409B4(func_02045730(canvas));
    }
    func_02185DA8(strokes, last);
    for (i = 0; i < 5; i++)
        strokes[i].count = 0;
}

/*
 * The 6-byte records at +0x4212 are reached through a byte cast of a struct
 * pointer at every use (remoteStrokes below): the base is hoisted into r6 and the
 * element address is recomputed (muls) at each use. A local pointer, or a
 * `char *` parameter with the same cast, CSEs the element pointer instead.
 */
#define REMOTE_STROKES(p) ((StrokeRec *)((char *)(p) + ((int)&((OekakiWork *)0)->remoteStroke)))
void func_02185EA0(OekakiWork *p)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (i == func_02039338())
            continue;
        if (REMOTE_STROKES(p)[i].count != 0 && func_02184180(p->param->app, (unsigned char)i) != 0) {
            func_0204B3DC(p->cursorActor[i], 1);
            func_0218506C(p->cursorActor[i], (&REMOTE_STROKES(p)[i].x0)[REMOTE_STROKES(p)[i].count - 1],
                          (&REMOTE_STROKES(p)[i].x0)[REMOTE_STROKES(p)[i].count + 1]);
        } else {
            func_0204B3DC(p->cursorActor[i], 0);
        }
    }
}

/* Cycles the colour of palette entry 12 of the object palette (the name tag blink). */
void func_02185F10(u16 *angle)
{
    u16 color;

    *angle += 20;
    if (*angle > 360)
        *angle = 0;
    color = (u16)((((func_0203F684(*angle) * 10) / 0x1000) + 15) << 5 | 0x1d);
    GX_LoadOBJPltt(&color, 0x18, 2);
}

/*
 * lever: index declared before count places i in r4 and n in r5.
 */
int func_02185F50(OekakiWork *p)
{
    int i;
    int count;

    count = 0;
    for (i = 0; i < 5; i++) {
        if (func_02184180(p->param->app, (u8)i) != 0)
            count++;
    }
    return count;
}

void func_02185F74(struct BmpWin **windows, u16 color, OekakiWork *p)
{
    int selfId;
    int i;
    struct BmpWin *window;
    TextPrinter *printer;

    selfId = func_02039338();
    if (!func_02186170(p))
        return;
    for (i = 0; i < 5; i++) {
        if (p->memberSlot[i].current == 0)
            func_0204B3DC(p->nameTagActor[i], 0);
        else
            func_0204B3DC(p->nameTagActor[i], 1);
    }
    func_0201C6EC(p->namePrinter);
    for (i = 0; i < 5; i++)
        func_02043AF4(func_02045770(windows[i]), 0, 0, 0x50, 0x10, 0);
    for (i = 0; i < 5; i++) {
        if (p->memberSlot[i].current != 0) {
            func_02008500(p->memberSlot[i].current, p->playerName[i]);
            if (selfId == i) {
                printer = p->namePrinter;
                func_0201C724(printer, func_02045770(p->printJob[i].window), 0, 0, p->playerName[i], p->font, 0xc80);
                p->printJob[i].busy = 1;
            } else {
                printer = p->namePrinter;
                func_0201C724(printer, func_02045770(p->printJob[i].window), 0, 0, p->playerName[i], p->font, color);
                p->printJob[i].busy = 1;
            }
        }
        window = windows[i];
        func_02045334(window);
        func_02045374(window);
        func_020409B4(func_02045730(window));
    }
}

void func_021860D0(OekakiWork *p)
{
    NetHandle *handle;

    if (func_02039338() == 0) {
        handle = func_020399A8();
        if (GFL_NET_ResetSendQueue(handle) == 0)
            return;
        func_02186A04(&p->sendPacket, &p->strokeQueue);
        p->sendPacket.rec[0].syncMode = p->syncMode;
        if (func_0203D3A8(handle, 0x2902, 0x1e, (u32)&p->sendPacket) == 1)
            func_02186958(&p->strokeQueue);
    } else {
        handle = func_020399A8();
        func_021869C0(&p->localStroke, &p->strokeQueue);
        if (GFL_NET_ResetSendQueue(handle) == 0)
            return;
        if (func_0203D3A8(func_020399A8(), 0x2901, 6, (u32)&p->localStroke) == 1)
            func_02186958(&p->strokeQueue);
    }
}

/*
 * Unblocked by matching the leaf at 0x021841A4 in ov022: the address is
 * below ov023's own base (0x021841E0) and ov022 is its only coherent code
 * home; the region hint is corrected from ov023 to ov022.
 */
int func_02186164(OekakiWork *p)
{
    return func_021841A4(p->param->app);
}

/* Returns 1 when the member list changed since the last call. */
int func_02186170(OekakiWork *p)
{
    int i;
    int changed;

    changed = 0;
    for (i = 0; i < 5; i++) {
        p->memberSlot[i].previous = p->memberSlot[i].current;
        p->memberSlot[i].current = func_02184180(p->param->app, (unsigned char)i);
    }
    for (i = 0; i < 5; i++) {
        if (p->memberSlot[i].previous != p->memberSlot[i].current)
            changed = 1;
    }
    return changed;
}

/* Prints message msgId in the message window: mode 0 with the printer, otherwise as a stream. */
void func_021861C4(OekakiWork *p, u32 msgId, int mode)
{
    StrBuf *text;
    TextPrinter *printer;
    struct BmpWin *window;

    text = func_020457B0(0x50, 0x28);
    func_02045CAC(p->msgBank, msgId, text);
    func_0201F250(p->wordSet, p->messageText, text);
    func_02045808(text);
    func_02043B5C(func_02045770(p->messageWindow), 15);
    func_0201F73C(p->messageWindow, 0, 1, 10);
    if (p->messageStream != 0) {
        func_0201CE48(p->messageStream);
        p->messageStream = 0;
    }
    if (mode == 0) {
        printer = p->messagePrinter;
        func_0201C724(printer, func_02045770(p->printJob[6].window), 0, 0, p->messageText, p->font, 0x44F);
        p->printJob[6].busy = 1;
    } else {
        p->messageStream = func_0201CCE4(p->messageWindow, 0, 0, p->messageText,
                                         p->font, func_02012FFC(),
                                         p->taskList, 1, 0x28, 0xF0F);
    }
    window = p->messageWindow;
    func_02045334(window);
    func_02045374(window);
    func_020409B4(func_02045730(window));
}

/* Returns 1 when the message has been shown completely (or none runs). */
int func_021862B0(OekakiWork *p)
{
    int state = func_0201CE30(p->messageStream);

    if (state == 1) {
        if (func_020362DC() & 1) {
            func_0201CE38(p->messageStream);
        }
        return 0;
    }
    if (state == 2) {
        func_0201CE48(p->messageStream);
        p->messageStream = 0;
        return 1;
    }
    return p->messageStream == 0;
}

void func_021862F4(OekakiWork *p)
{
    func_0201F7A8(p->messageWindow, 0);
}

/*
 * extent: two zero padding bytes follow the return at 0x02186320.
 * Caller explicitly sets r1 for func_02184560, retained despite its legacy one-argument definition.
 */
void func_02186304(OekakiWork *p, int flag)
{
    if (func_02039338() == 0) {
        func_0218654C(p);
        func_02184560(p, flag);
    }
}

/* Host only: reacts to members joining or leaving. Returns the next procState (1 keep, 2 leave). */
int func_02186324(OekakiWork *p)
{
    int memberCount;
    int joinedBits;

    memberCount = func_02186164(p);
    switch (memberCount) {
    case 0:
        break;
    case 1:
        if (p->scene > 0x10) {
            break;
        }
        if (func_02186558(p) != 1) {
            p->memberLeft = 1;
        }
        p->nextScene = 0x16;
        if (p->menuOpen != 0) {
            func_02186480(p);
            func_0204B878(p->clearButton, 0x15);
        }
        return 2;
    case 2:
    case 3:
    case 4:
        if (memberCount < p->lastMemberCount) {
            if (p->syncMode == 2) {
                func_02186304(p, 0);
            } else if (p->newMemberPending == 0) {
                func_02186304(p, 1);
            } else {
                func_02186304(p, 0);
            }
        }
        break;
    case 5:
        break;
    }
    if (memberCount < p->lastMemberCount) {
        p->baseMemberCount = func_0218654C(p);
        joinedBits = func_02186558(p);
        p->baseJoinedBits = joinedBits;
        if (p->newMemberPending != 0 && (joinedBits & p->newMemberBits) == 0) {
            func_02186304(p, 1);
            p->syncMode = 1;
            p->newMemberPending = 0;
            p->newMemberBits = 0;
        }
    }
    p->lastMemberCount = func_02186164(p);
    if (p->baseMemberCount < func_0218654C(p)) {
        p->syncMode = 2;
        p->newMemberPending = 1;
        p->newMemberBits = func_02186558(p) ^ p->baseJoinedBits;
    }
    return 1;
}

void func_02186444(OekakiWork *p, u32 nextScene)
{
    p->nextScene = nextScene;
}

void func_0218644C(OekakiWork *p, int mode)
{
    int next;

    next = p->nextScene;
    if (p->scene != next) {
        if (mode != 2) {
            p->scene = next;
            return;
        }
        if (d_02186E84[next][0] != 0)
            p->scene = next;
    }
}

/* Closes the yes/no menu if it is open. */
void func_02186480(OekakiWork *p)
{
    if (p->menuOpen != 0) {
        if (p->menu != 0)
            func_02186694(p);
        p->menuOpen = 0;
    }
}

int func_021864A8(OekakiWork *p)
{
    if (func_02035C08(d_02186AAC) != -1)
        return 1;
    return 0;
}

/* Packs the touch path into a stroke record. */
void func_021864C4(StrokeRec *stroke, TouchPoint *path, int color, int size)
{
    int i;
    TouchPoint *last;

    if (path[0].count != 0) {
        ((u8 *)stroke)[0] = path[0].x;
        ((u8 *)stroke)[2] = path[0].y;
        last = &path[path[0].count - 1];
        ((u8 *)stroke)[1] = last->x;
        ((u8 *)stroke)[3] = last->y;
        for (i = 0; i < 2; i++) {
            if (((u8 *)stroke)[i] + ((u8 *)stroke)[i + 2] == 0) {
                path[0].count = 0;
            }
        }
    }
    if (path[0].count >= 2) {
        stroke->count = 2;
    } else {
        stroke->count = path[0].count;
    }
    stroke->color = color;
    stroke->size = size;
}

int func_0218654C(OekakiWork *p)
{
    return func_021841A4(p->param->app);
}

/*
 * Unblocked by matching the leaf at 0x021841A0 in ov022: the address is
 * below ov023's own base (0x021841E0) and ov022 is its only coherent code
 * home; the region hint is corrected from ov023 to ov022.
 */
int func_02186558(OekakiWork *p)
{
    return func_021841A0(p->param->app);
}

void func_02186564(void)
{
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    func_02040588(0, 1);
    func_02040588(1, 1);
    func_02040588(2, 1);
    func_02040588(4, 1);
    func_02040588(5, 1);
    *(volatile u16 *)0x04000304 = *(volatile u16 *)0x04000304 & 0xFFFF7FFF;
}

TaskMenu *func_021865B4(OekakiWork *p)
{
    int i;
    TaskMenu *menu;
    const MenuItemInit *init;
    MenuTemplate tmpl;

    p->menuRes = func_02027F60(0, 2, p->font, p->messagePrinter, 0x28);
    for (i = 0; i < 2; i++) {
        init = &d_02186ABC[i];
        p->menuItem[i].text = func_02045EC0(p->msgBank, d_02186ABC[i].msgId);
        p->menuItem[i].color = 0x39E3;
        p->menuItem[i].result = init->result;
    }
    tmpl.heapId = 0x28;
    tmpl.itemCount = 2;
    tmpl.items = p->menuItem;
    tmpl.flags = 0;
    tmpl.x = 0x15;
    tmpl.y = 7;
    tmpl.width = 10;
    tmpl.height = 3;
    menu = func_02027778(&tmpl, p->menuRes);
    p->menuOpen = 1;
    return menu;
}

/*
 * extent: trailing two-byte zero alignment padding at 0x02186692.
 * lever: naming the accessor result before clearing result preserves call/store scheduling.
 */
int func_02186660(OekakiWork *p)
{
    int result = 2;

    func_02027974(p->menu);
    if (func_020279E8(p->menu) != 0) {
        u8 choice = func_02027A04(p->menu);
        result = 0;
        if (choice != 0) result = 1;
        func_02186694(p);
    }
    return result;
}

/*
 * extent: trailing two-byte zero alignment padding at 0x021866C2.
 */
void func_02186694(OekakiWork *p)
{
    func_02027858(p->menu);
    func_02045808(p->menuItem[1].text);
    func_02045808(p->menuItem[0].text);
    func_02027FD8(p->menuRes);
    p->menu = 0;
}

void func_021866C4(OekakiWork *p)
{
    int i;
    MetList *list;
    UnionAppEntry *entry;

    list = func_0200ED48(func_02012EBC(p->param->gameData));
    for (i = 0; i < 5; i++) {
        entry = func_02184180(p->param->app, (u8)i);
        if (entry != 0) {
            if (i != func_02039338()) {
                func_0200ED54(list, func_02008530(entry));
            }
        }
    }
}

void func_02186708(OekakiWork *p)
{
    int i;
    TextPrinter *printer;

    func_0201C4E4(p->namePrinter);
    func_0201C4E4(p->messagePrinter);
    for (i = 0; i < 5; i++) {
        printer = p->namePrinter;
        if (p->printJob[i].busy != 0) {
            if (func_0201C6C4(printer, func_02045770(p->printJob[i].window)) == 0) {
                func_02045334(p->printJob[i].window);
                p->printJob[i].busy = 0;
            }
        }
    }
    printer = p->messagePrinter;
    if (p->printJob[6].busy != 0) {
        if (func_0201C6C4(printer, func_02045770(p->printJob[6].window)) == 0) {
            func_02045334(p->printJob[6].window);
            p->printJob[6].busy = 0;
        }
    }
}

/* Sends the queued net command; the command is dropped once the send succeeded. */
void func_021867C4(OekakiWork *p)
{
    switch (p->pendingCommand) {
    case 0x2903:
        if (func_0203D3A8(func_0203996C(0xFF), 0x2903, 1, (u32)&p->pendingArg) != 0) {
            p->pendingCommand = 0;
        }
        break;
    case 0x2904:
        if (func_0203D3A8(func_0203996C(0xFF), 0x2904, 0, 0) != 0) {
            p->pendingCommand = 0;
        }
        break;
    case 0x2905:
        if (func_0203D3A8(func_0203996C(0xFF), 0x2905, 4, (u32)&p->stateMsg) != 0) {
            p->pendingCommand = 0;
        }
        break;
    case 0x2906:
        break;
    case 0x2907:
        if (func_0203D3A8(func_020399A8(), 0x2907, 0, 0) != 0) {
            p->pendingCommand = 0;
        }
        break;
    }
}

void func_02186860(OekakiWork *p, int commandId, int arg)
{
    if (p->pendingCommand == 0) {
        p->pendingCommand = commandId;
        p->pendingArg = arg;
    }
}

int func_02186878(StrokeQueue *queue)
{
    int index = queue->tail - 1;

    if (index < 0) index = 99;
    return index;
}

void func_02186888(StrokeQueue *queue)
{
    if (queue->group[queue->tail].rec[0].count != 0
        || queue->group[func_02186878(queue)].rec[0].count != 0) {
        queue->tail += 1;
        if (queue->tail >= 100) {
            queue->tail = 0;
        }
    }
}

/*
 * The second loop indexes group[idx].rec[j] in full and lets the
 * compiler hoist the group address itself: a named group pointer puts the 30*idx
 * temporary in r1 instead of r2.
 * Byte 6 of a record (syncMode) exists also to make sizeof(StrokeRec) == 6 so `rec[i]` is `muls #6`.
 */
void func_021868C8(StrokeQueue *queue)
{
    int i;
    int emptyCount;
    int prevEmptyCount;
    StrokeRec *rec;

    emptyCount = 0;
    prevEmptyCount = 0;
    i = 0;
    rec = queue->group[queue->tail].rec;
    for (; i < 5; i++) {
        if (rec[i].count == 0) {
            emptyCount++;
        }
    }
    if (emptyCount == 5) {
        int prev = func_02186878(queue);
        int j;
        for (j = 0; j < 5; j++) {
            if (queue->group[prev].rec[j].count == 0) {
                prevEmptyCount++;
            }
        }
    }
    if (prevEmptyCount != 5) {
        queue->tail += 1;
        if (queue->tail >= 100) {
            queue->tail = 0;
        }
    }
}

/*
 * extent: trailing two-byte zero alignment padding at 0x02186956.
 */
void func_02186938(StrokeRec *rec)
{
    int i;

    for (i = 0; i < 5; i++) rec[i].count = 0;
}

void func_02186958(StrokeQueue *queue)
{
    if (queue->head != queue->tail) {
        func_02186938(queue->group[queue->head].rec);
        queue->head += 1;
        if (queue->head >= 100) queue->head = 0;
    }
}

/* stand-in: the record is copied as a StrokeBytes (b[4]); a copy of StrokeRec schedules the last two bytes differently */
void func_02186988(StrokeBytes *stroke, StrokeQueue *queue, int index)
{
    ((StrokeBytesGroup *)queue)[queue->tail].r[index] = *stroke;
}

void func_021869C0(StrokeRec *dst, StrokeQueue *queue)
{
    int index = queue->head;

    if (index != queue->tail) {
        *dst = queue->group[index].rec[0];
    } else {
        dst->count = 0;
    }
}


/*
 * Fills the stroke group sent to the members: the group at the queue head,
 * or, when the queue is empty, a group of five empty records.
 */
void func_02186A04(StrokeGroup *sendGroup, StrokeQueue *queue)
{
    int i;
    if (queue->head != queue->tail) {
        for (i = 0; i < OEKAKI_MEMBER_MAX; i++) {
            sendGroup->rec[i] = queue->group[queue->head].rec[i];
        }
    } else {
        for (i = 0; i < OEKAKI_MEMBER_MAX; i++) {
            sendGroup->rec[i].count = 0;
        }
    }
}
