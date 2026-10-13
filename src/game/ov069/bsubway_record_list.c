/*
 * file:     bsubway_record_list.c
 * unit:     yes
 * function: func_021B95A0, func_021B9658, func_021B9680, func_021B96C8, func_021B96D4, func_021B9784, func_021B97D4, func_021B97F4, func_021B9888, func_021B98AC, func_021B9A44, func_021B9A50, func_021B9B44, func_021B9BF0, func_021B9C44, func_021B9CD8, func_021B9D08, func_021B9DE8, func_021B9DFC, func_021B9E44, func_021B9E5C, func_021B9E74, func_021B9EC0, func_021B9EDC, func_021B9F08, func_021B9F24, func_021B9F58, func_021B9F70, func_021B9F9C, func_021B9FC8, func_021B9FF0, func_021BA2A4, func_021BA2D8, func_021BA350, func_021BA384, func_021BA400, func_021BA438, func_021BA470, func_021BA480, func_021BA520
 * address:  0x021B95A0
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_0202223C  0x0202223C  thumb
 *   func_021B9B44  0x021B9B44  thumb  ov069
 *   func_021B9C44  0x021B9C44  thumb  ov069
 *   func_021B9D08  0x021B9D08  thumb  ov069
 *   func_021B9F24  0x021B9F24  thumb  ov069
 *   func_021BA384  0x021BA384  thumb  ov069
 *   func_021BA438  0x021BA438  thumb  ov069
 *   func_0202208C  0x0202208C  thumb
 *   func_0203D34C  0x0203D34C  arm
 *   func_021B9E44 0x021B9E44 thumb ov069
 *   func_021B9DFC 0x021B9DFC thumb ov069
 *   BGWINFRM_UpdateMoves 0x0202CD94 thumb
 *   func_0204A600 0x0204A600 arm
 *   func_021B9F58  0x021B9F58  thumb  ov069
 *   func_021B9DE8  0x021B9DE8  thumb  ov069
 *   func_021B9CD8  0x021B9CD8  thumb  ov069
 *   func_021B9BF0  0x021B9BF0  thumb  ov069
 *   func_020315D4  0x020315D4  arm
 *   func_0203084C  0x0203084C  arm
 *   func_020306F0  0x020306F0  arm
 *   func_0204A648  0x0204A648  arm
 *   func_020419E4  0x020419E4  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_GetChars  0x02045A90  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201EC74  0x0201EC74  thumb
 *   func_020056A0  0x020056A0  thumb
 *   GAME_DATA_GetSaveBlock3B  0x02012EFC  thumb
 *   func_0200DF58  0x0200DF58  thumb
 *   func_0200DF94  0x0200DF94  thumb
 *   func_021BA350  0x021BA350  thumb  ov069
 *   func_020307B0  0x020307B0  arm
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02049238  0x02049238  arm
 *   func_020433E0 0x020433E0 arm
 *   d_021BA620 0x021BA620 data a4
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040B94  0x02040B94  arm
 *   func_02040588  0x02040588  arm
 *   d_021BA65C  0x021BA65C  data  a4
 *   d_021BA7A0  0x021BA7A0  data  a4
 *   d_021BA60C  0x021BA60C  data  a4
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020275E4  0x020275E4  thumb
 *   func_02027624  0x02027624  thumb
 *   func_02027628  0x02027628  thumb
 *   func_0202762C  0x0202762C  thumb
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049B40  0x02049B40  arm
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   BGWINFRM_Create  0x0202C9B4  thumb
 *   BGWINFRM_AddFrame  0x0202CA3C  thumb
 *   BGWINFRM_SetFrameDataArcHandle  0x0202CB18  thumb
 *   BGWINFRM_PutFrame  0x0202CB4C  thumb
 *   d_021BA66C     0x021BA66C  data  a4
 *   BGWINFRM_Delete  0x0202CA0C  thumb
 *   func_0204A48C  0x0204A48C  arm
 *   d_020A1448     0x020A1448  data  a4
 *   func_0204B100  0x0204B100  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
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
 *   d_021BA6BC  0x021BA6BC  data  a4
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_02045088  0x02045088  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   d_021BA874  0x021BA874  data  a4
 *   func_020452E8 0x020452E8 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   d_021BA860 0x021BA860 data a4
 *   func_020221A4 0x020221A4 thumb
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_02025D2C  0x02025D2C  thumb
 *   func_0204B98C 0x0204B98C arm
 *   func_02025CD0 0x02025CD0 thumb
 *   d_021BA71C 0x021BA71C data a4
 *   d_021BA5EC 0x021BA5EC data a4
 *   func_02025D14 0x02025D14 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_0202616C 0x0202616C thumb
 *   func_0204B404 0x0204B404 arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F048  0x0201F048  thumb
 *   func_0201F094  0x0201F094  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045994  0x02045994  arm
 *   PMSI_PARAM_ToString  0x0202435C  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   func_02035C08 0x02035C08 arm
 *   func_020362DC 0x020362DC arm
 *   d_021BA5FC 0x021BA5FC data a4
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_020260E0 0x020260E0 thumb
 *   func_021BA520  0x021BA520  thumb  ov069
 *   BGWINFRM_HideFrame  0x0202CC70  thumb
 *   func_0201C7D0  0x0201C7D0  thumb
 *   BGWINFRM_PutBmpWin  0x0202CEBC  thumb
 *   BGWINFRM_ShowFrame  0x0202CC58  thumb
 */
#include "bsubway_record_list_types.h"

struct BsubwayWifiData;
struct BsubwayWifiRecordList;
struct S020315D4;
struct DispVram;
struct ActorSystemConfig;

typedef struct {
    int x;
    int y;
} Pos;

/* Display configuration, four words. */
struct DispConfig {
    u32 word[4];
};

/* Background template, eight words. */
struct BgTemplate {
    u32 word[8];
};

struct BgTemplateSet {
    struct BgTemplate bg[5];
};

extern void func_0203064C(unsigned int a, unsigned int heap, unsigned int size);
extern void *func_0203159C(void *proc, u32 size, u32 heap);
extern void  func_02082AC0(u32 val, void *dst, u32 size);
extern void  func_0202223C(u32 a, u32 color);
extern void func_021B9B44(BsubwayRecordListWork *work);
extern void func_021B9C44(BsubwayRecordListWork *work);
extern void func_021B9D08(BsubwayRecordListWork *work);
extern void func_021B9F24(BsubwayRecordListWork *work);
extern void  func_021BA384(BsubwayRecordListWork *work, int page, int pageCount);
extern void func_021BA438(BsubwayRecordListWork *work, int page);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void  func_0203D34C(u32 a, u32 b);
extern int func_021B9E44(BsubwayRecordListWork *work);
extern void func_021B9DFC(BsubwayRecordListWork *work);
extern void BGWINFRM_UpdateMoves(struct WinMgr *mgr);
extern void func_0204A600(void);
extern int func_021B9F58(BsubwayRecordListWork *work);
extern void func_021B9DE8(BsubwayRecordListWork *work);
extern void func_021B9CD8(BsubwayRecordListWork *work);
extern void func_021B9BF0(BsubwayRecordListWork *work);
extern void func_020315D4(struct S020315D4 *p);
extern void *func_0203084C(u32 heapId);
extern void func_020306F0(unsigned int heap);
extern void *func_020490F4(u32 id, u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u16 *STRBUF_GetChars(struct Strbuf *vec);
extern struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern void *func_020056A0(void (*fn)(void), void *arg, u32 priority);
extern void *GAME_DATA_GetSaveBlock3B(struct GameData *gameData);
extern struct BsubwayWifiRecordList *func_0200DF58(struct BsubwayWifiData *saveBlock, u32 heap);
extern u32 func_0200DF94(struct BsubwayWifiRecordList *recordList);
extern void func_021BA350(BsubwayRecordListWork *work);
extern u32 func_020307B0(void *p);
extern void func_02045808(struct Strbuf *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct MsgBank *bank);
extern void func_02030EAC(void *task);
extern void func_02049238(void *p);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u8);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(u32 layer);
extern void func_0203F9B4(void);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 index);
extern struct WinMgr *BGWINFRM_Create(u32 a0, u32 a1, u32 heap);
extern void BGWINFRM_AddFrame(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void BGWINFRM_SetFrameDataArcHandle(struct WinMgr *mgr, u32 idx, void *arc, u32 member, u32 alloc);
extern void BGWINFRM_PutFrame(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void BGWINFRM_Delete(struct WinMgr *mgr);
extern void func_0204A48C(const struct ActorSystemConfig *cfg, const struct DispVram *vram, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern void func_0204A648(void);
extern void func_020419E4(void);
int func_021B95A0(void *proc, u32 unusedSeq, BsubwayRecordListArgs *args);
int func_021B9658(u32 proc, u32 unusedSeq, u32 unusedArgs, BsubwayRecordListWork *work);
int func_021B9680(u32 proc, u32 unusedSeq, u32 unusedArgs, BsubwayRecordListWork *work);
void func_021B96C8(void);
void func_021B96D4(BsubwayRecordListWork *work, BsubwayRecordListArgs *args);
void func_021B9784(BsubwayRecordListWork *work);
void func_021B97D4(void);
void func_021B97F4(BsubwayRecordListWork *unusedWork);
void func_021B9888(BsubwayRecordListWork *unusedWork);
void func_021B98AC(BsubwayRecordListWork *work);
void func_021B9A44(BsubwayRecordListWork *work);
void func_021B9A50(BsubwayRecordListWork *work);
extern const struct DispVram d_021BA620;
extern const struct DispConfig d_021BA65C;
extern const struct BgTemplateSet d_021BA7A0;
extern const u32 d_021BA60C[];
extern const Pos d_021BA66C[];
extern const struct ActorSystemConfig d_020A1448;


#define SE_CURSOR_MOVE 0x548
#define SE_CANCEL      0x551
#define KEY_B_BUTTON   2
#define ARROW_ANIM_PREV 12
#define ARROW_ANIM_NEXT 13
#define BACK_ANIM_PRESS 9

struct Bitmap;
struct Strbuf;
struct WordSet;
struct Vec2;

typedef short s16;

/* Sprite template: position and the resource indexes (into spriteRes). */
typedef struct ActorTemplate {
    int x;
    int y;
    int z;
    int charRes;
    int palRes;
    int cellRes;
} ActorTemplate;

typedef struct ActorSetup {
    s16 x;
    s16 y;
    s16 z;
    u8 animIndex;
    u8 bgPriority;
} ActorSetup;

/* Window template of the text windows. */
typedef struct BmpWinTemplate {
    u32 layer;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    u16 charBase;
} BmpWinTemplate;

typedef struct CursorPos {
    u16 x;
    u16 y;
} CursorPos;

typedef int (*InputStateFunc)(BsubwayRecordListWork *work);

extern struct Actor *func_0204B294(struct Bank *bank, unsigned int charRes, unsigned int palRes, unsigned int cellRes, const ActorSetup *setup, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Actor *actor, unsigned int enabled);
extern void func_0204A8D4(u32 res);
extern void func_0204ADA4(u32 res);
extern void func_0204AFD8(u32 res);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02045088(u16 heapId);
extern struct BmpWin *func_020450F0(u32 layer, u32 x, u32 y, u32 width, u8 height, u8 charBase, u8 palette);
extern struct Bitmap *func_02045770(struct BmpWin *win);
extern void func_02043B5C(struct Bitmap *bitmap, u8 fill);
extern void func_02045334(struct BmpWin *win);
extern void func_02045374(struct BmpWin *win);
extern u8 func_02045730(struct BmpWin *win);
extern u32 func_020452E8(struct BmpWin *win);
extern void func_020450C8(void);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct PrintSys *func_0201C440(u32 heapId);
extern void func_0201C724(struct PrintSys *printSys, struct Bitmap *bitmap, u32 x, u32 y, struct Strbuf *text, struct GfFont *font, u16 color);
extern void func_0201C4C0(struct PrintSys *printSys);
extern u32 func_0201D83C(struct GfFont *font);
extern u32 func_0201C4E4(struct PrintSys *printSys);
extern u32 func_0201C6C4(struct PrintSys *printSys, struct Bitmap *bitmap);
extern u32 func_020221A4(void);
extern u32 func_0201C6B4(const struct PrintSys *printSys);
extern int func_02025D2C(struct CursorMove *cursor);
extern u32 func_0204B98C(struct Actor *actor);
extern struct CursorMove *func_02025CD0(const void *entries, const void *callbacks, void *work, u32 a3, u8 a4, u16 heapId);
extern u32 func_02025D14(struct CursorMove *cursor);
extern void func_020061E4(u32 seId);
extern const u8 *func_0202616C(struct CursorMove *cursor, unsigned int index);
extern void func_0204B404(struct Actor *actor, const struct Vec2 *delta, u32 which);
extern void func_0201EFA4(struct WordSet *wordSet, u32 index, u32 number, u32 digits, u32 dispType, u32 codeType);
extern void func_0201F048(struct WordSet *wordSet, u32 index, u32 trainerClass);
extern void func_0201F094(struct WordSet *wordSet, u32 index, u32 trainerClass, u32 trainerIndex);
extern void func_0201F250(struct WordSet *wordSet, void *dst, void *src);
extern void func_02045994(struct Strbuf *dst, const u16 *src, u32 len);
extern struct Strbuf *PMSI_PARAM_ToString(const BsubwayPmsData *pms, unsigned int heap);
extern void func_02041B6C(u32);
extern int func_02035C08(const void *rects);
extern unsigned func_020362DC(void);
extern void func_0204B878(struct Actor *actor, u16 animIndex);
extern void func_0204B3DC(struct Actor *actor, unsigned int enabled);
extern u8 func_020260E0(struct CursorMove *cursor);
extern void func_021BA520(BsubwayRecordListWork *work, int row, struct Strbuf *name, int isFemale);
extern void BGWINFRM_HideFrame(struct WinMgr *mgr, u32 idx);
int func_021B9E5C(BsubwayRecordListWork *work);
int func_021B9E74(BsubwayRecordListWork *work);
int func_021B9EC0(BsubwayRecordListWork *work);
int func_021B9EDC(BsubwayRecordListWork *work);
int func_021B9F08(BsubwayRecordListWork *work);
void func_021B9F68(void);
void func_021B9F6C(void);
void func_021B9F70(BsubwayRecordListWork *work, int row);
void func_021B9F9C(BsubwayRecordListWork *work, int row);
void func_021B9FC8(BsubwayRecordListWork *work, int row);
void func_021B9FF0(BsubwayRecordListWork *work, BsubwayWifiRecord *records, int index);
int func_021BA2A4(BsubwayRecordListWork *work);
void func_021BA2D8(BsubwayRecordListWork *work, int action);
int func_021BA400(BsubwayRecordListWork *work, int direction);
int func_021BA470(int page, int pageCountUnused, int entryCount);
void func_021BA480(BsubwayRecordListWork *work);
extern const ActorTemplate d_021BA6BC[];
extern const BmpWinTemplate *d_021BA874[];
extern InputStateFunc d_021BA860[];
extern const char d_021BA71C[], d_021BA5EC[];
extern const char d_021BA5FC[];

struct GfFont;


extern void func_0201C7D0(struct Bitmap *bitmap, s16 x, s16 y, struct Strbuf *text, struct GfFont *font, u16 color);
extern void BGWINFRM_PutBmpWin(struct WinMgr *mgr, u32 idx, struct BmpWin *win);
extern void BGWINFRM_ShowFrame(struct WinMgr *mgr, u32 idx);



int func_021B95A0(void *proc, u32 unusedSeq, BsubwayRecordListArgs *args)
{
    BsubwayRecordListWork *work;

    func_0203064C(1, 0x80, 0x20000);
    work = func_0203159C(proc, sizeof(BsubwayRecordListWork), 0x80);
    func_02082AC0(0, work, sizeof(BsubwayRecordListWork));
    func_0202223C(0, 0);
    func_0202223C(1, 0);
    func_021B96D4(work, args);
    func_021B97D4();
    func_021B97F4(work);
    func_021B98AC(work);
    func_021B9A50(work);
    func_021B9B44(work);
    func_021B9C44(work);
    func_021B9D08(work);
    func_021B9F24(work);
    func_021BA384(work, work->page, work->pageCount);
    func_021BA438(work, work->page);
    func_0202208C(0, 1, 1, 0, 0x10, 1, 0x80);
    func_0203D34C(1, 0x80);
    return 1;
}


int func_021B9658(u32 proc, u32 unusedSeq, u32 unusedArgs, BsubwayRecordListWork *work)
{
    if (func_021B9E44(work) == 0)
        return 1;
    func_021B9DFC(work);
    BGWINFRM_UpdateMoves(work->frameMgr);
    func_0204A600();
    return 0;
}



int func_021B9680(u32 proc, u32 unusedSeq, u32 unusedArgs, BsubwayRecordListWork *work)
{
    func_021B9F58(work);
    func_021B9DE8(work);
    func_021B9CD8(work);
    func_021B9BF0(work);
    func_021B9A44(work);
    func_021B9888(work);
    func_021B9784(work);
    func_020315D4((struct S020315D4 *)proc);
    func_0203084C(0x80);
    func_020306F0(0x80);
    return 1;
}


void func_021B96C8(void)
{
    func_0204A648();
    func_020419E4();
}



void func_021B96D4(BsubwayRecordListWork *work, BsubwayRecordListArgs *args)
{
    int i;

    work->args = args;
    work->chosenEntry = 0;
    work->arcHandle = func_020490F4(0xc7, 0x80);
    work->msgBank = func_02045B38(0, 2, 0x39, 0x80);
    for (i = 0; i < BSUBWAY_RECORD_LIST_MESSAGE_COUNT; i++) {
        work->messages[i] = func_02045EC0(work->msgBank, i);
        STRBUF_GetChars(work->messages[i]);
    }
    work->textBuf = func_020457B0(0x40, 0x80);
    work->wordSet = func_0201EC74(8, 0x40, 0x80);
    work->vblankTask = func_020056A0(func_021B96C8, work, 0);
    work->recordList = func_0200DF58(GAME_DATA_GetSaveBlock3B(work->args->gameData), 0x80);
    work->entryCount = func_0200DF94(work->recordList);
    func_021BA350(work);
}



void func_021B9784(BsubwayRecordListWork *work)
{
    int i;

    func_020307B0(work->recordList);
    for (i = 0; i < BSUBWAY_RECORD_LIST_MESSAGE_COUNT; i++) {
        func_02045808(work->messages[i]);
    }
    func_02045808(work->textBuf);
    func_0201ED04(work->wordSet);
    func_02045C04(work->msgBank);
    func_02030EAC(work->vblankTask);
    func_02049238(work->arcHandle);
}


void func_021B97D4(void) { func_020433E0(&d_021BA620); *(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000); }



void func_021B97F4(BsubwayRecordListWork *unusedWork)
{
    struct DispConfig dispConfig;
    struct BgTemplateSet bgTemplates;
    u32 i;
    u32 bgId;

    func_0203F8F4(0x80);
    dispConfig = d_021BA65C;
    func_0203FC28(&dispConfig);
    bgTemplates = d_021BA7A0;
    for (i = 0; i < 5; i++) {
        bgId = d_021BA60C[i];
        func_0203FCA0((u8)bgId, &bgTemplates.bg[i], 0);
        func_020414EC(bgId);
        func_02040B94(bgId, 0x20, 0, 0x80);
        func_02040588(bgId, 1);
    }
    func_02040588(6, 0);
    func_02040588(7, 0);
    func_02040588(3, 0);
}


void func_021B9888(BsubwayRecordListWork *unusedWork) { u32 i; for(i=0;i<5;i++) func_020403F4((u8)d_021BA60C[i]); func_0203F9B4(); }



void func_021B98AC(BsubwayRecordListWork *work)
{
    void *uiArc = work->arcHandle;
    void *spriteArc;
    int i;

    func_02049658(uiArc, 5, 5, 0, 0, 1, 0x80);
    func_020498F4(uiArc, 4, 5, 0, 0, 1, 0x80);
    func_02049B68(uiArc, 6, 4, 0, 0, 0x80);
    func_02049658(uiArc, 1, 2, 0, 0, 1, 0x80);
    func_020498F4(uiArc, 0, 2, 0, 0, 1, 0x80);
    func_02049B68(uiArc, 2, 0, 0, 0, 0x80);
    func_02049658(uiArc, 1, 1, 0, 0, 1, 0x80);
    func_020498F4(uiArc, 0, 1, 0, 0, 1, 0x80);
    spriteArc = func_020490F4(func_020275E4(), 0x80);
    func_02049658(spriteArc, func_02027628(), 1, 0, 0, 0, 0x80);
    func_020498F4(spriteArc, func_0202762C(), 1, 0, 0, 0, 0x80);
    func_02049BDC(spriteArc, func_02027624(), 0, 0, 0x1C0, 0x20, 0x80);
    func_020413B0(1, 0, 0x15, 0x20, 3, 0xE);
    func_020409B4(1);
    func_02049238(spriteArc);
    func_02049B40(0x17, 5, 0, 0x1E0, 0x20, 0x80);
    func_02049B40(0x17, 5, 4, 0x1E0, 0x20, 0x80);
    work->frameMgr = BGWINFRM_Create(2, 10, 0x80);
    for (i = 0; i < BSUBWAY_RECORD_LIST_ENTRIES_PER_PAGE; i++) {
        BGWINFRM_AddFrame(work->frameMgr, i, 1, 0xE, 4);
        BGWINFRM_SetFrameDataArcHandle(work->frameMgr, i, uiArc, 3, 1);
        BGWINFRM_PutFrame(work->frameMgr, i, d_021BA66C[i].x, d_021BA66C[i].y);
    }
}


void func_021B9A44(BsubwayRecordListWork *work)
{
    BGWINFRM_Delete(work->frameMgr);
}



void func_021B9A50(BsubwayRecordListWork *work)
{
    void *spriteArc;
    u32 cellAnimId;

    spriteArc = func_020490F4(func_020275E4(), 0x80);
    func_0204A48C(&d_020A1448, &d_021BA620, 0x80);
    work->actorBank = func_0204B100(4, 1, 0x80);
    work->subActorBank = func_0204B100(2, 1, 0x80);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    work->spriteRes[1] = func_0204A6C8(work->arcHandle, 7, 1, 2, 0x80);
    work->spriteRes[0] = func_0204ABF0(work->arcHandle, 10, 2, 0, 0x80);
    work->spriteRes[2] = func_0204AF28(work->arcHandle, 8, 9, 0x80);
    work->spriteRes[4] = func_0204A6C8(spriteArc, func_02027618(), 0, 0, 0x80);
    work->spriteRes[3] = func_0204AC18(spriteArc, func_02027614(), 0, 0x160, 0, 3, 0x80);
    cellAnimId = func_0202761C(0);
    work->spriteRes[5] = func_0204AF28(spriteArc, cellAnimId, func_02027620(0), 0x80);
    func_02049238(spriteArc);
}




/*
 * Creates four sprites from a const 6-word template table (x, y, z, then
 * three resource-slot indices).  The table must be `const`: a non-const
 * table lets the stores into the stack record alias it, and the index loads
 * are then scheduled after the stack-argument stores (42 bytes of DIFF).
 * Twin: ov111_func_021C75E4.
 */
void func_021B9B44(BsubwayRecordListWork *work)
{
    int i;
    ActorSetup setup;

    for (i = 0; i < 4; i++) {
        setup.x = d_021BA6BC[i].x;
        setup.y = d_021BA6BC[i].y;
        setup.z = d_021BA6BC[i].z;
        setup.bgPriority = 0;
        setup.animIndex = 0;
        work->actors[i] = func_0204B294(work->actorBank, work->spriteRes[d_021BA6BC[i].charRes], work->spriteRes[d_021BA6BC[i].palRes], work->spriteRes[d_021BA6BC[i].cellRes], &setup, 0, 0x80);
        func_0204B92C(work->actors[i], 1);
    }
}



void func_021B9BF0(BsubwayRecordListWork *work)
{
    func_0204A8D4(work->spriteRes[4]);
    func_0204ADA4(work->spriteRes[3]);
    func_0204AFD8(work->spriteRes[5]);
    func_0204A8D4(work->spriteRes[1]);
    func_0204ADA4(work->spriteRes[0]);
    func_0204AFD8(work->spriteRes[2]);
    func_0204B1CC(work->subActorBank);
    func_0204B1CC(work->actorBank);
    func_0204A5AC();
}



void func_021B9C44(BsubwayRecordListWork *work)
{
    int i;
    int j;
    struct BmpWin *win;
    const BmpWinTemplate *tmpl;

    func_02045088(0x80);
    for (i = 0; i < 8; i++) {
        tmpl = d_021BA874[i];
        work->windows[BSUBWAY_RECORD_LIST_ENTRIES_PER_PAGE + i] = func_020450F0((u8)tmpl->layer, tmpl->x, tmpl->y, tmpl->width, tmpl->height, tmpl->charBase, 1);
        func_02043B5C(func_02045770(work->windows[BSUBWAY_RECORD_LIST_ENTRIES_PER_PAGE + i]), 0);
        win = work->windows[BSUBWAY_RECORD_LIST_ENTRIES_PER_PAGE + i];
        func_02045334(win);
        func_02045374(win);
        func_020409B4(func_02045730(win));
    }
    for (j = 0; j < 10; j++) {
        work->windows[j] = func_020450F0(1, 2, 1, 10, 2, 1, 1);
        func_02043B5C(func_02045770(work->windows[j]), 4);
    }
}


/*
 * extent: final two bytes are alignment padding before next labelled function.
 */
void func_021B9CD8(BsubwayRecordListWork *work)
{
    int i;

    for (i = 0; i < 10; i++)
        func_020452E8(work->windows[i]);
    for (i = 0; i < 8; i++)
        func_020452E8(work->windows[BSUBWAY_RECORD_LIST_ENTRIES_PER_PAGE + i]);
    func_020450C8();
}



void func_021B9D08(BsubwayRecordListWork *work)
{
    int i;
    struct PrintSys *printSys;

    work->font = func_0201D7EC(0x17, 0, 0, 0, 0x80);
    work->printSys = func_0201C440(0x80);
    for (i = 0; i < BSUBWAY_RECORD_LIST_WIN_COUNT; i++) {
        work->printJobs[i].window = work->windows[i];
        work->printJobs[i].isPending = 0;
    }
    printSys = work->printSys;
    func_0201C724(printSys, func_02045770(work->printJobs[BSUBWAY_RECORD_LIST_WIN_TITLE].window), 0, 0,
                  work->messages[0], work->font, 0x3DC0);
    work->printJobs[BSUBWAY_RECORD_LIST_WIN_TITLE].isPending = 1;
    printSys = work->printSys;
    func_0201C724(printSys, func_02045770(work->printJobs[BSUBWAY_RECORD_LIST_WIN_LABEL_B].window), 0, 0,
                  work->messages[3], work->font, 0x3DC0);
    work->printJobs[BSUBWAY_RECORD_LIST_WIN_LABEL_B].isPending = 1;
    printSys = work->printSys;
    func_0201C724(printSys, func_02045770(work->printJobs[BSUBWAY_RECORD_LIST_WIN_LABEL_C].window), 0, 0,
                  work->messages[6], work->font, 0x3DC0);
    work->printJobs[BSUBWAY_RECORD_LIST_WIN_LABEL_C].isPending = 1;
}


void func_021B9DE8(BsubwayRecordListWork *work) { func_0201C4C0(work->printSys); func_0201D83C(work->font); }



void func_021B9DFC(BsubwayRecordListWork *work)
{
    int i;
    struct PrintSys *printSys;

    func_0201C4E4(work->printSys);
    for (i = 0; i < BSUBWAY_RECORD_LIST_WIN_COUNT; i++) {
        printSys = work->printSys;
        if (work->printJobs[i].isPending != 0) {
            if (func_0201C6C4(printSys, func_02045770(work->printJobs[i].window)) == 0) {
                func_02045334(work->printJobs[i].window);
                work->printJobs[i].isPending = 0;
            }
        }
    }
}


int func_021B9E44(BsubwayRecordListWork *work) { return d_021BA860[work->state](work); }


int func_021B9E5C(BsubwayRecordListWork *work) { if (func_020221A4()) work->state = BSUBWAY_RECORD_LIST_STATE_INPUT; return 1; }



int func_021B9E74(BsubwayRecordListWork *work)
{
    int result;

    if (func_0201C6B4(work->printSys) == 0)
        return 1;
    if (func_021BA2A4(work) == -1) {
        result = func_02025D2C(work->cursorMove);
        if (result == -6)
            func_021BA2D8(work, 0);
        else if (result == -5)
            func_021BA2D8(work, 1);
    }
    return 1;
}


int func_021B9EC0(BsubwayRecordListWork *work) { if (func_0204B98C(work->actors[BSUBWAY_RECORD_LIST_ACTOR_BACK])==0) work->state = BSUBWAY_RECORD_LIST_STATE_FADE_OUT_START; return 1; }


int func_021B9EDC(BsubwayRecordListWork *work) { func_0202208C(0,0,0,0,16,1,128); work->state = BSUBWAY_RECORD_LIST_STATE_FADE_OUT_WAIT; return 1; }


/*
 * extent: Two bytes of alignment padding follow.
 */
int func_021B9F08(BsubwayRecordListWork *work)
{
    if (func_020221A4()) {
        work->state = BSUBWAY_RECORD_LIST_STATE_FADE_IN;
        return 0;
    }
    return 1;
}


void func_021B9F24(BsubwayRecordListWork *work)
{
    work->cursorMove = func_02025CD0(d_021BA71C, d_021BA5EC, work, 1, 0, 0x80);
    func_021B9FC8(work, 0);
}


/*
 * evidence: 02025D14 forwards r0 to 02030164, whose body reads the pointer
 * and returns a predicate; its legacy void(void) declaration is incomplete.
 */
int func_021B9F58(BsubwayRecordListWork *work)
{
    return func_02025D14(work->cursorMove);
}


/* Cursor callback table slots 0 and 1: no action. */
void func_021B9F68(void) {}


void func_021B9F6C(void) {}


/* Cursor callback table slot 2: the cursor moved to row "row". */
void func_021B9F70(BsubwayRecordListWork *work, int row)
{
    func_021B9FF0(work, work->recordList->records, (int)((unsigned)row + (unsigned)work->page * 10u));
    func_021B9FC8(work, row);
    func_020061E4(SE_CURSOR_MOVE);
}


/* Cursor callback table slot 3: same body as slot 2 (two functions, both are table targets). */
void func_021B9F9C(BsubwayRecordListWork *work, int row)
{
    func_021B9FF0(work, work->recordList->records, (int)((unsigned)row + (unsigned)work->page * 10u));
    func_021B9FC8(work, row);
    func_020061E4(SE_CURSOR_MOVE);
}


void func_021B9FC8(BsubwayRecordListWork *work, int row)
{
    CursorPos pos;
    const u8 *entry;

    entry = func_0202616C(work->cursorMove, row);
    pos.x = entry[0];
    pos.y = entry[1];
    func_0204B404(work->actors[BSUBWAY_RECORD_LIST_ACTOR_CURSOR], (const struct Vec2 *)(&pos), 0);
}


void func_021B9FF0(BsubwayRecordListWork *work, BsubwayWifiRecord *records, int index)
{
    u32 trainerClass;
    u32 trainerIndex;
    BsubwayWifiRecord *record;
    BsubwayPmsData *greeting;
    int offset;
    struct Strbuf *nameStr;
    struct BmpWin *win;
    int nameLen;
    struct PrintSys *printSys;
    struct Strbuf *greetingStr;

    offset = index * 0x22;
    record = &records[index];
    trainerClass = record->trainerClass;
    trainerIndex = record->trainerIndex;
    greeting = &record->greeting;
    nameStr = func_020457B0(0x10, 0x80);
    func_0201EFA4(work->wordSet, 0, work->args->wordNumber0, 2, 0, 1);
    func_0201EFA4(work->wordSet, 1, work->args->wordNumber1, 3, 0, 1);
    func_0201F048(work->wordSet, 2, trainerClass);
    func_0201F094(work->wordSet, 3, trainerClass, trainerIndex);
    func_02043B5C(func_02045770(work->windows[BSUBWAY_RECORD_LIST_WIN_SUMMARY]), 0);
    func_02043B5C(func_02045770(work->windows[BSUBWAY_RECORD_LIST_WIN_TRAINER_LINE]), 0);
    func_02043B5C(func_02045770(work->windows[BSUBWAY_RECORD_LIST_WIN_NAME]), 0);
    func_02043B5C(func_02045770(work->windows[BSUBWAY_RECORD_LIST_WIN_SCORE]), 0);
    func_02043B5C(func_02045770(work->windows[BSUBWAY_RECORD_LIST_WIN_GREETING]), 0);
    if (index < work->entryCount) {
        nameLen = 8;
        /* stand-in: record->trainerName changes the bytes; the byte offset (index * 0x22) must be computed first. */
        func_02045994(nameStr, (const u16 *)((char *)records + offset), nameLen);
        printSys = work->printSys;
        func_0201C724(printSys, func_02045770(work->printJobs[BSUBWAY_RECORD_LIST_WIN_NAME].window), 0, 0, nameStr, work->font, 0x3DC0);
        work->printJobs[BSUBWAY_RECORD_LIST_WIN_NAME].isPending = 1;
        func_0201F250(work->wordSet, work->textBuf, work->messages[1]);
        printSys = work->printSys;
        func_0201C724(printSys, func_02045770(work->printJobs[BSUBWAY_RECORD_LIST_WIN_SUMMARY].window), 0, 0, (struct Strbuf *)work->textBuf, work->font, 0x3DC0);
        work->printJobs[BSUBWAY_RECORD_LIST_WIN_SUMMARY].isPending = 1;
        func_0201F250(work->wordSet, work->textBuf, work->messages[2]);
        printSys = work->printSys;
        func_0201C724(printSys, func_02045770(work->printJobs[BSUBWAY_RECORD_LIST_WIN_TRAINER_LINE].window), 0, 0, (struct Strbuf *)work->textBuf, work->font, 0x3DC0);
        work->printJobs[BSUBWAY_RECORD_LIST_WIN_TRAINER_LINE].isPending = 1;
        func_0201F250(work->wordSet, work->textBuf, work->messages[4]);
        printSys = work->printSys;
        func_0201C724(printSys, func_02045770(work->printJobs[BSUBWAY_RECORD_LIST_WIN_SCORE].window), 0, 0, (struct Strbuf *)work->textBuf, work->font, 0x3DC0);
        work->printJobs[BSUBWAY_RECORD_LIST_WIN_SCORE].isPending = 1;
        func_0201F250(work->wordSet, work->textBuf, work->messages[5]);
        printSys = work->printSys;
        func_0201C724(printSys, func_02045770(work->printJobs[BSUBWAY_RECORD_LIST_WIN_SCORE].window), 0, 0x10, (struct Strbuf *)work->textBuf, work->font, 0x3DC0);
        work->printJobs[BSUBWAY_RECORD_LIST_WIN_SCORE].isPending = 1;
        greetingStr = PMSI_PARAM_ToString(greeting, 0x80);
        printSys = work->printSys;
        func_0201C724(printSys, func_02045770(work->printJobs[BSUBWAY_RECORD_LIST_WIN_GREETING].window), 0, 0, greetingStr, work->font, 0x3DC0);
        work->printJobs[BSUBWAY_RECORD_LIST_WIN_GREETING].isPending = 1;
        func_02045808(greetingStr);
    } else {
        win = work->windows[BSUBWAY_RECORD_LIST_WIN_NAME];
        func_02045334(win); func_02045374(win); func_02041B6C(func_02045730(win));
        win = work->windows[BSUBWAY_RECORD_LIST_WIN_SCORE];
        func_02045334(win); func_02045374(win); func_02041B6C(func_02045730(win));
        win = work->windows[BSUBWAY_RECORD_LIST_WIN_GREETING];
        func_02045334(win); func_02045374(win); func_02041B6C(func_02045730(win));
    }
    func_02045808(nameStr);
}


int func_021BA2A4(BsubwayRecordListWork *work)
{
    int touched;

    touched = func_02035C08(d_021BA5FC);
    if (func_020362DC() & KEY_B_BUTTON) {
        func_020061E4(SE_CANCEL);
        touched = 2;
    }
    func_021BA2D8(work, touched);
    return touched;
}



void func_021BA2D8(BsubwayRecordListWork *work, int action)
{
    switch (action) {
    case 0:
        if (func_021BA400(work, action) != 0) {
            func_020061E4(SE_CURSOR_MOVE);
            func_0204B878(work->actors[BSUBWAY_RECORD_LIST_ACTOR_PREV_ARROW], ARROW_ANIM_PREV);
            func_021BA438(work, work->page);
        }
        break;
    case 1:
        if (func_021BA400(work, action) != 0) {
            func_020061E4(SE_CURSOR_MOVE);
            func_0204B878(work->actors[BSUBWAY_RECORD_LIST_ACTOR_NEXT_ARROW], ARROW_ANIM_NEXT);
            func_021BA438(work, work->page);
        }
        break;
    case 2:
        work->state = BSUBWAY_RECORD_LIST_STATE_BACK_ANIM;
        func_0204B878(work->actors[BSUBWAY_RECORD_LIST_ACTOR_BACK], BACK_ANIM_PRESS);
        break;
    }
}


void func_021BA350(BsubwayRecordListWork *work)
{
    work->page = 0;
    work->pageCount = work->entryCount / BSUBWAY_RECORD_LIST_ENTRIES_PER_PAGE;
    if (work->entryCount % BSUBWAY_RECORD_LIST_ENTRIES_PER_PAGE != 0)
        (work->pageCount)++;
}



void func_021BA384(BsubwayRecordListWork *work, int page, int pageCount)
{
    if (pageCount == 1) {
        func_0204B3DC(work->actors[BSUBWAY_RECORD_LIST_ACTOR_PREV_ARROW], 0);
        func_0204B3DC(work->actors[BSUBWAY_RECORD_LIST_ACTOR_NEXT_ARROW], 0);
    } else if (page == 0) {
        func_0204B3DC(work->actors[BSUBWAY_RECORD_LIST_ACTOR_PREV_ARROW], 0);
        func_0204B3DC(work->actors[BSUBWAY_RECORD_LIST_ACTOR_NEXT_ARROW], 1);
    } else if (page != 0 && page < pageCount - 1) {
        func_0204B3DC(work->actors[BSUBWAY_RECORD_LIST_ACTOR_PREV_ARROW], 1);
        func_0204B3DC(work->actors[BSUBWAY_RECORD_LIST_ACTOR_NEXT_ARROW], 1);
    } else if (page == pageCount - 1) {
        func_0204B3DC(work->actors[BSUBWAY_RECORD_LIST_ACTOR_PREV_ARROW], 1);
        func_0204B3DC(work->actors[BSUBWAY_RECORD_LIST_ACTOR_NEXT_ARROW], 0);
    }
}


/* direction 0: previous page, 1: next page. Returns 1 when the page changed. */
int func_021BA400(BsubwayRecordListWork *work, int direction)
{
    int changed = 0;
    if (direction == 0) {
        if (work->page != 0) {
            work->page = work->page - 1;
            changed = 1;
        }
    } else if (direction == 1) {
        if (work->page < work->pageCount - 1) {
            work->page = work->page + 1;
            changed = 1;
        }
    }
    return changed;
}


/*
 * extent: Two bytes of alignment padding follow.
 * lever: Inline the getter result into the sum; a named result reverses
 * the final adds operands (one concrete byte).
 */
void func_021BA438(BsubwayRecordListWork *work, int page)
{
    work->page = page;
    func_021BA384(work, page, work->pageCount);
    func_021BA480(work);
    func_021B9FF0(work, work->recordList->records, work->page * 10 + func_020260E0(work->cursorMove));
}


/*
 * Unlabelled leaf: remaining count after a - 10 per page, capped at 10.
 */
int func_021BA470(int page, int pageCountUnused, int entryCount)
{
    int rows = entryCount - page * 10;

    if (rows > 10)
        rows = 10;
    return rows;
}



void func_021BA480(BsubwayRecordListWork *work)
{
    struct Strbuf *nameStr;
    int rowCount;
    int i;

    nameStr = func_020457B0(0x10, 0x80);
    rowCount = func_021BA470(work->page, work->pageCount, work->entryCount);
    i = 0;
    if (rowCount > 0) {
        do {
            func_02045994(nameStr, work->recordList->records[i + work->page * 10].trainerName, 8);
            func_021BA520(work, i, nameStr, work->recordList->records[i + work->page * 10].isFemale);
            i++;
        } while (i < rowCount);
    }
    for (; i < 10; i++)
        BGWINFRM_HideFrame(work->frameMgr, i);
    func_02045808(nameStr);
}


/* Draws the trainer name of one list row into its row window and shows the row frame. */
void func_021BA520(BsubwayRecordListWork *work, int row, struct Strbuf *name, int isFemale)
{
    func_02043B5C(func_02045770(work->windows[row]), 4);
    if (isFemale == 0)
        func_0201C7D0(func_02045770(work->windows[row]), 0, 0, name,
                      work->font, 0x3584);
    else
        func_0201C7D0(func_02045770(work->windows[row]), 0, 0, name,
                      work->font, 0x2D44);
    func_02045334(work->windows[row]);
    BGWINFRM_PutBmpWin(work->frameMgr, row, work->windows[row]);
    BGWINFRM_ShowFrame(work->frameMgr, row);
}
