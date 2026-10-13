/*
 * file:     itemmenu.c
 * unit:     yes
 * function: func_021B6100, func_021B6120, func_021B6138, func_021B616C, func_021B619C, func_021B61B8, func_021B61C8, func_021B61F4, func_021B6204, func_021B621C, func_021B624C, func_021B6288, func_021B6300, func_021B6374, func_021B63F8, func_021B64A0, func_021B6554, func_021B65E8, func_021B66B8, func_021B66E8, func_021B66FC, func_021B68E8, func_021B690C, func_021B6934, func_021B6A14, func_021B6A78, func_021B6AD8, func_021B6AF0, func_021B6BC4, func_021B6C30, func_021B6C98, func_021B6D00, func_021B6D70, func_021B6DD8, func_021B6E4C, func_021B6EC8, func_021B6EF8, func_021B7128, func_021B7250, func_021B7504, func_021B7584, func_021B75A4, func_021B761C, func_021B7640, func_021B7688, func_021B76E4, func_021B7700, func_021B77E4, func_021B7804, func_021B7868, func_021B795C, func_021B7A7C, func_021B7B08, func_021B7B80, func_021B7C88, func_021B7CD0, func_021B7D20, func_021B7D9C, func_021B7DD0, func_021B7DF4, func_021B7F38, func_021B7F54, func_021B8080, func_021B809C, func_021B80BC, func_021B80C4, func_021B811C, func_021B8134, func_021B81B0, func_021B81B8, func_021B81F4, func_021B822C, func_021B8280, func_021B832C, func_021B83A0, func_021B83B8, func_021B8600, func_021B8640, func_021B8688, func_021B86B8, func_021B8904, func_021B8990, func_021B8AF4, func_021B8B0C, func_021B8B24, func_021B8B6C, func_021B8B7C, func_021B8C1C, func_021B8CB4, func_021B8CE4, func_021B8D88, func_021B8DAC, func_021B8DCC, func_021B8E08, func_021B8E48, func_021B8E84, func_021B8EA8, func_021B8F0C, func_021B8F68, func_021B8F90, func_021B8F98, func_021B913C, func_021B9178, func_021B91FC, func_021B9280, func_021B9758, func_021B97CC, func_021B97E8, func_021B9850, func_021B9AAC, func_021B9AF8, func_021B9BA0, func_021B9BDC, func_021B9DE8, func_021B9E14, func_021B9ED8, func_021B9EF4, func_021BA028, func_021BA1D0, func_021BA218, func_021BA41C, func_021BA4A4, func_021BA654, func_021BA6A4, func_021BA6F4, func_021BA8C0, func_021BA96C, func_021BA9AC, func_021BA9C0, func_021BAAA4, func_021BAB04, func_021BACF0, func_021BADAC, func_021BADB8, func_021BADF0, func_021BAE98, func_021BAF10, func_021BAF38, func_021BAFC4, func_021BB08C, func_021BB0BC, func_021BB0F8, func_021BB1AC, func_021BB1C4, func_021BB260, func_021BB368, func_021BB398, func_021BB3F4, func_021BB580, func_021BB5A4, func_021BB5DC, func_021BB690, func_021BB6E0, func_021BB724, func_021BB73C
 * address:  0x021B6100
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   KEY_SetRepeatSpeed 0x02036270 arm
 *   func_020355C4 0x020355C4 arm
 *   func_021B9850 0x021B9850 thumb ov070
 *   func_021B9AAC 0x021B9AAC thumb ov070
 *   func_021BA218 0x021BA218 thumb ov070
 *   func_021B81F4 0x021B81F4 thumb ov070
 *   func_020081DC 0x020081DC thumb
 *   func_02020FE4 0x02020FE4 thumb
 *   func_02007F7C 0x02007F7C thumb
 *   func_02007FA0 0x02007FA0 thumb
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201EF6C 0x0201EF6C thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_02008298  0x02008298  thumb
 *   func_02008288  0x02008288  thumb
 *   func_02008270  0x02008270  thumb
 *   func_021BA6A4  0x021BA6A4  thumb  ov070
 *   func_021BAF38  0x021BAF38  thumb  ov070
 *   func_021BA96C  0x021BA96C  thumb  ov070
 *   func_021BAAA4  0x021BAAA4  thumb  ov070
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   func_02035C60  0x02035C60  arm
 *   func_021B80C4  0x021B80C4  thumb  ov070
 *   func_0202EDE4  0x0202EDE4  thumb
 *   func_021BA654  0x021BA654  thumb  ov070
 *   func_020061E4  0x020061E4  thumb
 *   func_0203633C  0x0203633C  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_02035D20 0x02035D20 arm
 *   func_021BB5DC 0x021BB5DC thumb ov070
 *   func_021B8AF4 0x021B8AF4 thumb ov070
 *   BLINK_PALANM_Update  0x0202EA40  thumb
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_02035C38  0x02035C38  arm
 *   func_02007CC8  0x02007CC8  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_020362DC  0x020362DC  arm
 *   func_021B8C1C  0x021B8C1C  thumb  ov070
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200D418  0x0200D418  thumb
 *   func_0200D58C  0x0200D58C  thumb
 *   func_0200D55C  0x0200D55C  thumb
 *   func_021B7D20  0x021B7D20  thumb  ov070
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021BACF0  0x021BACF0  thumb  ov070
 *   func_021BADF0  0x021BADF0  thumb  ov070
 *   func_020414EC  0x020414EC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_02028754  0x02028754  thumb
 *   d_021BB9C4  0x021BB9C4  data  a4
 *   func_020279E8  0x020279E8  thumb
 *   func_02027A04  0x02027A04  thumb
 *   GAME_BEACON_SetItemUse  0x02027324  thumb
 *   func_02027858  0x02027858  thumb
 *   PALANM_IsOutsideReservedIdRange  0x020213E0  thumb
 *   func_0202136C  0x0202136C  thumb
 *   func_02051C88  0x02051C88  arm
 *   func_020355D8  0x020355D8  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_02006238  0x02006238  thumb
 *   func_020212B0  0x020212B0  thumb
 *   func_0201EF34  0x0201EF34  thumb
 *   func_02021350  0x02021350  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C278  0x0200C278  thumb
 *   func_02007F1C  0x02007F1C  thumb
 *   func_02007FB8  0x02007FB8  thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   TOUCHPANEL_HitCont  0x02035BA4  arm
 *   d_021BB960     0x021BB960  data  a1
 *   func_02030734  0x02030734  arm
 *   MYITEM_SAVEDATA_CopyPocket   0x02007CC8  thumb
 *   func_02020F14  0x02020F14  thumb
 *   func_02020F20  0x02020F20  thumb
 *   func_02021014  0x02021014  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 *   MATH_QSort     0x02081BE4  arm
 *   d_021BBBC0     0x021BBBC0  data  ov070  a1
 *   BLINK_PALANM_ResetPhase  0x0202EB04  thumb
 *   func_0202E448  0x0202E448  thumb
 *   GAME_DATA_SetSaveFlag  0x02012BE0  thumb
 *   GAME_DATA_CheckSaveFlag 0x02012BF8 thumb
 *   func_02020F34  0x02020F34  thumb
 *   d_021BB998 0x021BB998 data ov070 a4
 *   d_021BB95C 0x021BB95C data a1
 *   d_021BB984     0x021BB984  data  a4
 *   PALANM_TransferPalettes  0x02021D50  thumb
 *   func_0204A648  0x0204A648  arm
 *   func_0202208C  0x0202208C  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_020310C4  0x020310C4  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02027FD8  0x02027FD8  thumb
 *   func_02031140  0x02031140  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0203FB44  0x0203FB44  arm
 *   func_020452E8  0x020452E8  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02028604  0x02028604  thumb
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02051C6C  0x02051C6C  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   BLINK_PALANM_Create  0x0202E940  thumb
 *   func_020490F4  0x020490F4  arm
 *   BLINK_PALANM_LoadPalettes  0x0202E9AC  thumb
 *   func_0202EA20 0x0202EA20 thumb
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   func_0204B98C 0x0204B98C arm
 *   func_02035C08 0x02035C08 arm
 *   d_021BB978 0x021BB978 data a4
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02012B70 0x02012B70 thumb
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040588  0x02040588  arm
 *   func_02040C14  0x02040C14  arm
 *   d_021BBB40     0x021BBB40  data  a4
 *   d_021BBB60     0x021BBB60  data  a4
 *   d_021BBB80     0x021BBB80  data  a4
 *   d_021BBB20     0x021BBB20  data  a4
 *   d_021BBAC0     0x021BBAC0  data  a4
 *   d_021BBAE0     0x021BBAE0  data  a4
 *   d_021BBB00     0x021BBB00  data  a4
 *   func_02008550  0x02008550  thumb
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   d_021BBBE0  0x021BBBE0  data a4
 *   d_021BBA8C  0x021BBA8C  data  ov070
 *   d_021BBAB0  0x021BBAB0  data a4
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   WAZA_TOOL_GetType  0x0201C1C8  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_020456F8  0x020456F8  arm
 *   func_0202130C  0x0202130C  thumb
 *   func_02020FB4  0x02020FB4  thumb
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_020437AC  0x020437AC  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045374  0x02045374  arm
 *   func_02020E60  0x02020E60  thumb
 *   func_0204B294  0x0204B294  arm
 *   func_0204A600 0x0204A600 arm
 *   func_02027974 0x02027974 thumb
 *   func_02043678  0x02043678  arm
 *   func_02021288  0x02021288  thumb
 *   func_02045730  0x02045730  arm
 *   d_021BBA79     0x021BBA79  data  ov070  a1
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   CLACT_SetActorAnimIndex  0x0204B908  arm
 *   func_0204ABBC  0x0204ABBC  arm
 *   func_020437D4  0x020437D4  arm
 *   func_020437EC  0x020437EC  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207E780  0x0207E780  arm
 *   func_0202EE0C  0x0202EE0C  thumb
 *   d_021BBAA8     0x021BBAA8  data  ov070  a1
 *   d_021BBA6C     0x021BBA6C  data  a1
 *   d_021BBA68     0x021BBA68  data  a1
 *   d_021BBA64     0x021BBA64  data  ov070  a1
 *   d_021BBA74     0x021BBA74  data  a1
 *   d_021BBBCC     0x021BBBCC  data  a2
 *   d_021BBA81     0x021BBA81  data  a1
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02027778  0x02027778  thumb
 *   ARC_UTIL_UploadBgPaletteAddFromHandleExt  0x020499D4  arm
 *   WAZA_TOOL_GetMaxPP  0x0201C158  thumb
 *   func_0201BD28  0x0201BD28  thumb
 *   WAZA_TOOL_IsAlwaysHit  0x0201C1F4  thumb
 *   func_02043AF4  0x02043AF4  arm
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_020286C4  0x020286C4  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0203630C  0x0203630C  arm
 *   func_0201CE5C  0x0201CE5C  thumb
 *   func_0201F14C  0x0201F14C  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0200C274 0x0200C274 thumb
 *   func_0204A380  0x0204A380  arm
 *   func_02062B30  0x02062B30  arm
 *   func_02041090  0x02041090  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_020056BC  0x020056BC  thumb
 *   PALANM_RequestFade  0x0202173C  thumb
 *   func_0207D658  0x0207D658  arm
 *   func_0204B3F4  0x0204B3F4  arm
 *   func_0201C724  0x0201C724  thumb
 *   KEY_GetRepeatSpeed  0x02036370  arm  arm9
 */

#include "itemmenu_types.h"

#define reg_GX_POWCNT (*(volatile u16 *)0x04000304)
#define REG_GX_POWCNT_DSEL_MASK 0x8000
#define REG_GX_POWCNT_DSEL_SHIFT 15
struct MsgBank;
struct WordSet;
struct TaskMenu;
struct PrintSys;
struct Ctx;
struct Blk34;
struct Rec;
struct S02021D50;
struct Tcbl;
struct MyItemSave;
struct Descriptor;
struct Node;
struct S02031140;
struct TaskMenuState;
struct U16Vec;
struct S020315D4;
struct Actor;
struct PalAnmSlot;
struct BigObj;
struct Sub0200852CObj;
struct Bank;
struct Cfg;
struct DispConfig;
struct DispVram;
struct CharBuf;
struct Bmp;
struct PtS;
struct Vec2;
struct TaskMenuTmpl;
struct Rec3;
struct StrObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

#include "itemmenu_types.h"





typedef signed int     s32;



















typedef struct Item {
    u16 id;
    u16 count;
} Item;

typedef struct HitRect {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
} HitRect;

typedef struct HitTbl {
    HitRect r[3];
} HitTbl;

typedef struct Ent {
    Item item;
    u32 key;
} Ent;




typedef struct { int v[11]; } T44;

typedef struct { unsigned char v[4]; } T4;


typedef struct TabTbl {
    int v[5];
} TabTbl;

typedef short s16;

typedef struct Parent {
    u8 pad00[0x34];
    u32 f34;
    u32 f38;
} Parent;




typedef enum {
    GX_DISP_SELECT_SUB_MAIN = 0,
    GX_DISP_SELECT_MAIN_SUB = 1
} GXDispSelect;

typedef struct BgTemplate {
    u32 w[8];
} BgTemplate;

typedef struct { u16 x, y, z; u8 a, b; } Rect;

typedef struct { u32 w[4]; } Tbl16;

typedef struct {
    unsigned short a, b, c;
    unsigned char d, e;
} Rect_021B9850;

typedef struct {
    short a, b, c;
    u8 d, e;
} Rect_021B9EF4;

typedef signed short s16_021BB6E0;

typedef struct {
    unsigned short a, b;
} Pt;

typedef struct {
    short a, b, c;
    u8 d, e;
} Rect_021BA6F4;

typedef struct {
    u8 v[5];
} B5;

typedef struct {
    u8 v[2];
} B2;

typedef struct {
    short x, y;
    unsigned short z;
    unsigned char d, e;
} Rect_021BA8C0;


typedef struct {
    int a;
    u8 b;
    u8 pad[3];
    int c;
    int d;
    u8 e;
    u8 f;
    u8 g;
    u8 h;
} Desc;




typedef struct {
    u16 w;
    u16 h;
    u16 pad[4];
    u16 d[1];
} Img;


typedef short s16_021BB3F4;

typedef struct ItemMenuArgs {
    void *saveData;
    void *optionsSave;
    void *myStatus;
    struct MyItemSave *bagCursor;
    void *bag;
    int actionPermissions[6];
    int bagMode;
    int bagFilter;
} ItemMenuArgs;


extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const struct TaskMenu *p);
extern void GAME_BEACON_SetItemUse(u16 id);
extern u32 func_02020FE4(u16 a, u32 sel, u32 id);
extern u32 func_02028754(struct Actor *obj, u32 n);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0204B92C(struct Actor *p, u32 v);
extern u8 func_020355C4(void);
extern void func_02027858(struct TaskMenu *m);
extern u32 PALANM_IsOutsideReservedIdRange(u16 v);
extern unsigned int func_0202136C(u16 v);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern int func_02035C38(void);
extern s32 func_02051C88(struct Ctx *c);
extern s32 BLINK_PALANM_Update(struct BlinkPalAnm *p);
extern u32 func_020362DC(void);
extern void func_020061E4(unsigned int se);
extern void func_020355D8(u8 v);
extern void func_02082BCC(void *p, int v, int n);
extern void func_02007CC8(u8 *base, void *buf, u32 id, int save);
extern void func_0204B878(struct Actor *p, u16 value);
extern unsigned int func_0203633C(void);
extern void func_020414EC(u32 i);
extern int func_02006238(void);
extern int func_02035C60(void);
extern u16 func_020212B0(u16 id);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern u8 func_02021350(u16 id);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void *func_02012F08(int *p);
extern u32 func_0200C278(struct Blk34 *p, u32 v);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_02007FB8(u8 *base, u16 id, u16 d);
extern void func_0204B3DC(struct Actor *p, u32 v);
extern int TOUCHPANEL_HitCont(const void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MYITEM_SAVEDATA_CopyPocket(u8 *base, void *buf, u32 id, int save);
extern void *func_02020F14(u32 a);
extern int func_02020F20(int h, int id, u16 heap);
extern u32 func_02021014(struct Rec *p, u32 sel);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *arc);
extern void MATH_QSort(void *head, u32 num, u32 width, int (*comp)(Ent *, Ent *), void *buf);
extern void BLINK_PALANM_ResetPhase(struct BlinkPalAnm *p);
extern u32 func_0202E448(u32 id);
extern void GAME_DATA_SetSaveFlag(void *p, u32 a, u32 b);
extern int GAME_DATA_CheckSaveFlag(void *p, int a);
extern void *func_02020F34(unsigned int item, unsigned int which, unsigned int heap);
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern void func_0204A648();
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
extern void func_020310C4(struct Tcbl *p);
extern void func_02030EAC(struct Node *n);
extern void func_02008298(struct MyItemSave *p, u16 v);
extern void func_02008288(struct MyItemSave *p, int i, s16 a, s16 b);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_02031140(struct S02031140 *p);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02040DA8(u32 a, u32 b, u32 c);
extern u32 func_0201D83C(void *ptr);
extern int func_02028604(int a0);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02051C6C(void *p);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern int KEY_SetRepeatSpeed(int a0, int a1);
extern void func_020315D4(struct S020315D4 *a);
extern void func_020306F0(unsigned int a);
extern struct BlinkPalAnm *BLINK_PALANM_Create(u16 a0, u16 a1, u32 a2, u16 heap);
extern void *func_020490F4(u32 id, u32 heap);
extern void BLINK_PALANM_LoadPalettes(struct BlinkPalAnm *p, u8 *a1, u32 a2, u32 a3, u32 a4);
extern u32 func_0202EA20(struct BlinkPalAnm *p);
extern void CLACT_SetActorAnimFrame(struct Actor *p, u32 value);
extern u32 func_0204B98C(struct Actor *a);
extern int func_02035C08(const void *p);
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern int func_02012B70(const struct BigObj *p);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(int bg);
extern void func_020409B4(u32 layer);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
extern void func_0201DD60(void);
extern void func_020433E0(const struct DispVram *c);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0201DD68(void);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020434DC(u32 mask, u32 enable);
extern u32 func_020275E4(void);
extern u32 func_020275E8(void);
extern u32 func_020275FC(u32 a);
extern u32 func_02027600(u32 a);
extern u32 func_02027610(u32 a);
extern u32 func_020275F8(u32 a);
extern u8 func_02027604(u8 i);
extern u8 func_020275EC(int i);
extern struct Actor *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B6F4(struct Actor *o, u32 v, u32 flag);
extern int WAZA_TOOL_GetDamageType(int);
extern u8 WAZA_TOOL_GetType(void *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_020456F8(struct Descriptor *d);
extern u32 func_0202130C(u32 id);
extern void func_02020FB4(void *dst, u32 entry, u32 heap);
extern void func_0204B3B4(struct Actor *p);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_020437AC(struct Bmp *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045374(struct Cfg *cfg);
extern int func_02020E60(unsigned short, int);
extern void func_0204A600(void);
extern void func_02027974(void *);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern u32 func_02021288(u32 id);
extern u8 func_02045730(struct Descriptor *p);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Actor *p, const struct Vec2 *delta, u32 which);
extern void CLACT_SetActorAnimIndex(void *, int);
extern int func_0204ABBC(u32 idx, u32 flag);
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void func_020862F0(void *, u32);
extern void func_0207E780(void *, void *, u32);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern u32 func_0202EE0C(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_0201F7A8(void *, unsigned);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern u8 WAZA_TOOL_GetMaxPP(u16 move, u32 ppUp);
extern u32 func_0201BD28(u16 id, u32 field);
extern u32 WAZA_TOOL_IsAlwaysHit(u16 id);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern signed char func_02012FFC(void);
extern int func_0201CCE4(int, int, int, void *, int, int, int, int, int, int);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u32 func_0201CE30(void *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201CE38(void *p);
extern unsigned int func_0203630C(void);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern void func_0201F14C(struct WordSet *p, u32 i, u32 v);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0200C274(struct Blk34 *);
extern void *func_0204A380(void *a0, unsigned int a1, unsigned int a2, unsigned int a3);
extern int func_02062B30(void *file, void **out);
extern void func_02041090(unsigned int index, unsigned int a1, unsigned int a2, unsigned int a3, u8 a4, u8 a5);
extern void func_02041B6C(u32 bit);
extern u32 func_020056BC(void);
extern int PALANM_RequestFade(void *p, u16 mask, u16 col, s16_021BB3F4 step, u8 b, u8 c, u16 d, u32 ctx);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern u32 func_0204B3F4(struct Actor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, void *d, u32 e, u16 f);
extern void func_0203064C();
extern void *func_0203159C();
extern void KEY_GetRepeatSpeed();
extern void func_0200816C();
extern int func_02008284(struct MyItemSave *p);
extern void func_02008270(struct MyItemSave *p, int i, s16 *a, s16 *b);
extern void *func_02045B38();
extern void *func_0201EC64();
extern void *func_0201C450();
extern int func_02028590();
extern int func_0201D7EC();
extern void *func_02051B84();
extern int func_020056A0();
extern int func_0203101C();
extern int func_02027F60();
extern void func_0203D34C();
void func_021B6EF8(ItemMenuWork *work);
void func_021B7128(ItemMenuWork *work);
void func_021B7250(ItemMenuWork *work);
void func_021B7504(ItemMenuWork *work);
void func_021B7584(ItemMenuWork *work);
void func_021B75A4(ItemMenuWork *work);
void func_021B761C(ItemMenuWork *work);
void func_021B7640(ItemMenuWork *work);
void func_021B7688(ItemMenuWork *work);
void func_021B76E4(ItemMenuWork *work);
void func_021B7700(ItemMenuWork *work);
void func_021B77E4(ItemMenuWork *work);
void func_021B7804(ItemMenuWork *work);
void func_021B7868(ItemMenuWork *work);
void func_021B795C(ItemMenuWork *work);
void func_021B7A7C(ItemMenuWork *work);
void func_021B7B08(ItemMenuWork *work);
void func_021B7B80(ItemMenuWork *work);
void func_021B7C88(ItemMenuWork *work);
void func_021B7CD0(ItemMenuWork *work);
void func_021B7D20(ItemMenuWork *work, int x);
void func_021B7D9C(ItemMenuWork *work, int v);
void func_021B7DD0(ItemMenuWork *work);
int func_021B7DF4(ItemMenuWork *work);
int func_021B7F38(Ent *a, Ent *b);
void func_021B7F54(ItemMenuWork *work);
void func_021B8080(ItemMenuWork *work);
void func_021B809C(ItemMenuWork *work);
void func_021B80BC(ItemMenuWork *work);
void func_021B80C4(ItemMenuWork *work, int flag);
int func_021B811C(ItemMenuWork *work);
int func_021B8134(ItemMenuWork *work, int k);
int func_021B81B0(int x);
void func_021B81B8(ItemMenuWork *work);
void func_021B81F4(ItemMenuWork *work);
void func_021B822C(ItemMenuWork *work, void *rec, u16 *p, u8 *out);
void func_021B8280(ItemMenuWork *work, unsigned char *q);
void func_021B832C(ItemMenuWork *work);
int func_021B83A0(ItemMenuWork *work, int value);
void func_021B83B8(u32 idx, int flag, ItemMenuWork *work);
void func_021B8600(int u, ItemMenuWork *work);
void func_021B8640(ItemMenuWork *work);
void func_021B8688(ItemMenuWork *work);
int func_021B86B8(void *proc, int st, ItemMenuArgs *a);
int func_021B8904(int a, int b, int c, ItemMenuWork *work);
int func_021B8990(void *proc, int b, Parent *par, ItemMenuWork *work);
void func_021B8AF4(ItemMenuWork *work);
int func_021B8B0C(ItemMenuWork *work);
void func_021B8B24(ItemMenuWork *work);
void func_021B8B6C(ItemMenuWork *work);
void func_021B8B7C(ItemMenuWork *work);
void func_021B8C1C(ItemMenuWork *work, int a, ItemMenuTaskFn callback);
void func_021B8CB4(ItemMenuWork *work);
void func_021B8CE4(ItemMenuWork *work, int u, int a, ItemMenuTaskFn callback);
void func_021B8D88(ItemMenuWork *work);
int func_021B8DAC(void);
void func_021B8DCC(ItemMenuWork *work);
void func_021B8E08(ItemMenuWork *work);
void func_021B8E48(ItemMenuWork *work);
void func_021B8E84(ItemMenuWork *work);
void func_021B8EA8(ItemMenuWork *work);
void func_021B8F0C(ItemMenuWork *work);
int func_021B8F68(ItemMenuWork *work, int value);
void func_021B8F90(ItemMenuWork *work);
void func_021B8F98(void);
void func_021B913C(void);
void func_021B9178(ItemMenuWork *work, int bg);
void func_021B91FC(ItemMenuWork *work, void *bg);
void func_021B9280(ItemMenuWork *work);
void func_021B9758(ItemMenuWork *work);
void func_021B97CC(void *p, int v);
void func_021B97E8(ItemMenuWork *work, int mode);
void func_021B9850(ItemMenuWork *work);
void func_021B9AAC(ItemMenuWork *work);
void func_021B9AF8(ItemMenuWork *work);
void func_021B9BA0(ItemMenuWork *work);
void func_021B9BDC(ItemMenuWork *work);
void func_021B9DE8(ItemMenuWork *work);
void func_021B9E14(ItemMenuWork *work, int id);
void func_021B9ED8(ItemMenuWork *work);
void func_021B9EF4(ItemMenuWork *work);
void func_021BA028(ItemMenuWork *work);
int func_021BA1D0(u16 x);
void func_021BA218(ItemMenuWork *work);
void func_021BA41C(ItemMenuWork *work);
void func_021BA4A4(ItemMenuWork *work);
void func_021BA654(ItemMenuWork *work);
void func_021BA6A4(ItemMenuWork *work);
void func_021BA6F4(ItemMenuWork *work);
void func_021BA8C0(ItemMenuWork *work);
void func_021BA96C(ItemMenuWork *work, unsigned sel);
void func_021BA9AC(ItemMenuWork *work);
void func_021BA9C0(ItemMenuWork *work, int *tbl, int n);
void func_021BAAA4(ItemMenuWork *work, int mode);
void func_021BAB04(ItemMenuWork *work, int x);
void func_021BACF0(ItemMenuWork *work, int mode);
void func_021BADAC(ItemMenuWork *work);
void func_021BADB8(ItemMenuWork *work, unsigned v);
int func_021BADF0(ItemMenuWork *work);
void func_021BAE98(ItemMenuWork *work);
void func_021BAF10(ItemMenuWork *work);
void func_021BAF38(ItemMenuWork *work, int val);
void func_021BAFC4(ItemMenuWork *work);
void func_021BB08C(ItemMenuWork *work);
void func_021BB0BC(ItemMenuWork *work);
void func_021BB0F8(ItemMenuWork *work);
void func_021BB1AC(ItemMenuWork *work);
void func_021BB1C4(ItemMenuWork *work);
void func_021BB73C(ItemMenuWork *work);
void func_021BB260(ItemMenuWork *work, int val);
int func_021BB368(int x);
void func_021BB398(ItemMenuWork *work, u32 val);
void func_021BB3F4(ItemMenuWork *work, int mode);
void func_021BB580(ItemMenuWork *work, int v);
void func_021BB5A4(ItemMenuWork *work);
void func_021BB5DC(ItemMenuWork *work, int mode);
int func_021BB690(const char *p);
void func_021BB6E0(ItemMenuWork *work, u32 *obj, void *str, u16 x, s16_021BB6E0 y, u16 color);
void func_021BB724(void **p);
extern HitTbl d_021BB960;
extern char d_021BBBC0[];
extern T44 d_021BB998;
extern T4 d_021BB95C;
extern const TabTbl d_021BB984;
extern const char d_021BB978[];
extern const BgTemplate d_021BBB40;
extern const BgTemplate d_021BBB60;
extern const BgTemplate d_021BBB80;
extern const BgTemplate d_021BBB20;
extern const BgTemplate d_021BBAC0;
extern const BgTemplate d_021BBAE0;
extern const BgTemplate d_021BBB00;
extern u8 d_021BBBE0[];
extern u8 d_021BBA8C[];
extern const Tbl16 d_021BBAB0;
extern const u8 d_021BBA79[];
extern const B5 d_021BBAA8;
extern const B5 d_021BBA6C;
extern const B2 d_021BBA68;
extern const B2 d_021BBA64;
extern unsigned char d_021BBA74[];
extern short d_021BBBCC[][2];
extern unsigned char d_021BBA81[];
extern char d_021BBA04[];
/* Item id range with the handler that uses items of that range. */
typedef struct ItemUseRange {
    u16 firstItemId;
    u16 itemCount;
    void (*useHandler)(void *);
} ItemUseRange;
/* Message ids of the bag message bank. */
#define ITEMMENU_MSG_CANT_USE_KEY_ITEM 0x38
#define ITEMMENU_MSG_CANT_USE_IN_CONTEXT 0x39
#define ITEMMENU_MSG_CANT_USE_NOW 0x3A
#define ITEMMENU_MSG_REPEL_USED 0x3F
#define ITEMMENU_MSG_REPEL_STILL_ACTIVE 0x40
extern BagSlot *func_020081DC(void *bag, u32 pocket, u32 index);
extern unsigned int func_02007F7C(const BagSlot *items, unsigned int maxCount);
extern u32 func_02007FA0(void *bag, u32 pocket);
extern void func_0201EF40(void *wordSet, u32 slot, u32 itemId);
extern void func_0201EF6C(void *wordSet, u32 slot, u32 itemId, u32 isPlural, u32 flags);
extern void MI_CpuCopy8(const void *src, void *dest, unsigned int size);
extern u32 func_0202EDE4(u32 range, u32 position, u32 thumbSize, u32 trackSize, u32 flags);
extern u32 func_02035D20(u32 *outX, u32 *outY);
extern void *func_02012EBC(void *saveData);
extern void *func_0200D418(void *fieldSave);
extern u32 func_0200D58C(void *repelState);
extern void func_0200D55C(void *repelState, u8 steps);
void func_021B6100(ItemMenuWork *work, ItemMenuTaskFn taskFn);
void func_021B6120(ItemMenuWork *work);
void func_021B6138(ItemMenuWork *work);
BagSlot *func_021B616C(ItemMenuWork *work, int index);
int func_021B619C(int itemId, int count, unsigned int heapId);
int func_021B61B8(ItemMenuWork *work);
int func_021B61C8(ItemMenuWork *work);
void func_021B61F4(ItemMenuWork *work, int slot, unsigned int itemId);
void func_021B6204(ItemMenuWork *work, int slot, unsigned int itemId, int isPlural, int flags);
void func_021B621C(ItemMenuWork *work, int indexA, int indexB);
void func_021B624C(ItemMenuWork *work, int fromIndex, int toIndex);
void func_021B6288(ItemMenuWork *work, int prevPocket, int nextPocket);
int func_021B6300(ItemMenuWork *work, int itemCount, int canWrap);
int func_021B6374(ItemMenuWork *work, int itemCount, int canWrap);
u32 func_021B63F8(ItemMenuWork *work);
int func_021B64A0(ItemMenuWork *work);
int func_021B6554(ItemMenuWork *work);
int func_021B65E8(ItemMenuWork *work);
int func_021B66B8(void);
void func_021B66E8(ItemMenuWork *work);
void func_021B66FC(ItemMenuWork *work);
int func_021B68E8(u16 itemId);
int func_021B690C(u16 itemId);
void func_021B6934(ItemMenuWork *work);
void func_021B6A14(ItemMenuWork *work);
void func_021B6A78(ItemMenuWork *work);
void func_021B6AD8(ItemMenuWork *work);
u32 func_021B6AF0(ItemMenuWork *work);
u32 func_021B6BC4(ItemMenuWork *work);
u32 func_021B6C30(ItemMenuWork *work);
u32 func_021B6C98(ItemMenuWork *work);
u32 func_021B6D00(ItemMenuWork *work);
u32 func_021B6D70(ItemMenuWork *work);
u32 func_021B6DD8(ItemMenuWork *work);
u32 func_021B6E4C(ItemMenuWork *work);
int func_021B6EC8(u16 itemId);
extern const ItemUseRange d_021BB9C4[8];
extern u32 func_0201C4E4(void *printSys);
extern u32 func_0201C6C4(void *printSys, void *textBuffer);


/* Sets the task function of the screen and the key repeat speed. */
void func_021B6100(ItemMenuWork *work, ItemMenuTaskFn taskFn)
{
    work->taskFn = taskFn;
    KEY_SetRepeatSpeed(work->keyRepeatDelay, work->keyRepeatInterval);
}

/* Forces the list to be drawn again. */
void func_021B6120(ItemMenuWork *work)
{
    work->shownItemId = 0xFFFF;
    func_021B6138(work);
}

void func_021B6138(ItemMenuWork *work)
{
    if (func_020355C4() == 0)
        func_021B9850(work);
    else
        func_021B9AAC(work);
    func_021BA218(work);
    func_021B81F4(work);
    work->listDirty = 1;
}

/* Slot of the shown pocket: the work copy while an item is being moved,
 * the bag otherwise. */
BagSlot *func_021B616C(ItemMenuWork *work, int index)
{
    if (work->usingWorkCopy) return &work->items[index];
    return func_020081DC(work->bag, (u16)(work->currentPocket), (u16)index);
}

/*
 * extent: two bytes of zero alignment follow the 26-byte function.
 * lever: enum quotient preserves its r1 web and the copy to return r0.
 * The signed quotient is multiplied with unsigned modular arithmetic.
 */
int func_021B619C(int itemId, int count, unsigned int heapId)
{
    typedef enum { HALF_ZERO } Half;
    Half unitPrice;
    unitPrice = (Half)((int)func_02020FE4((u16)itemId, 0, heapId) / 2);
    return (int)((unsigned int)unitPrice * (unsigned int)count);
}

/* Index of the selected entry in the whole list. */
int func_021B61B8(ItemMenuWork *work)
{
    return (int)((unsigned int)work->cursorRow + (unsigned int)work->scrollOffset + 1U);
}

int func_021B61C8(ItemMenuWork *work)
{
    if (work->usingWorkCopy) return func_02007F7C(work->items, ITEMMENU_POCKET_ITEM_COUNT);
    return func_02007FA0(work->bag, work->currentPocket);
}

void func_021B61F4(ItemMenuWork *work, int slot, unsigned int itemId)
{
    func_0201EF40(work->wordSet, slot, itemId);
}

/*
 * Extent ends in two zero alignment bytes.
 */
void func_021B6204(ItemMenuWork *work, int slot, unsigned int itemId, int isPlural, int flags)
{
    func_0201EF6C(work->wordSet, slot, itemId, isPlural, flags);
}

void func_021B621C(ItemMenuWork *work, int indexA, int indexB)
{
    int tmp;
    MI_CpuCopy8(&work->items[indexA], &tmp, 4);
    MI_CpuCopy8(&work->items[indexB], &work->items[indexA], 4);
    MI_CpuCopy8(&tmp, &work->items[indexB], 4);
}

/* Moves an entry to a new place by swapping it step by step. */
void func_021B624C(ItemMenuWork *work, int fromIndex, int toIndex)
{
    if (fromIndex == toIndex) return;
    if (fromIndex < toIndex) {
        for (; fromIndex < toIndex; fromIndex++) func_021B621C(work, fromIndex, fromIndex + 1);
    } else {
        for (; fromIndex > toIndex; fromIndex--) func_021B621C(work, fromIndex, fromIndex - 1);
    }
}

/* Stores the cursor of the old pocket and loads the cursor of the new one. */
void func_021B6288(ItemMenuWork *work, int prevPocket, int nextPocket)
{
    s16 loaded[2];

    func_02008298(work->bagCursor, prevPocket);
    func_02008288(work->bagCursor, (u16)prevPocket, work->cursorRow, work->scrollOffset + 1);
    func_02008270(work->bagCursor, (u16)nextPocket, &loaded[1], &loaded[0]);
    work->cursorRow = loaded[1];
    work->scrollOffset = loaded[0] - 1;
    func_021BA6A4(work);
    func_021BAF38(work, nextPocket);
    func_021BA96C(work, nextPocket);
    func_021BAAA4(work, nextPocket);
}

/* Cursor one entry down. Six rows are visible; the list scrolls once the
 * cursor is on the last row. Returns 1 when the cursor moved. */
int func_021B6300(ItemMenuWork *work, int itemCount, int canWrap)
{
    int prevRow, prevScroll;

    if (itemCount == 0)
        return 0;
    prevRow = work->cursorRow;
    prevScroll = work->scrollOffset;
    if (prevRow == 5 && prevScroll + 7 < itemCount) {
        work->scrollOffset = work->scrollOffset + 1;
    } else if (prevRow != 5 && prevRow + 1 < itemCount) {
        work->cursorRow = work->cursorRow + 1;
    } else if (canWrap == 1) {
        work->scrollOffset = -1;
        work->cursorRow = 0;
    }
    return prevRow != work->cursorRow || prevScroll != work->scrollOffset;
}

/* Cursor one entry up, wrapping to the end of the list when allowed. */
int func_021B6374(ItemMenuWork *work, int itemCount, int canWrap)
{
    int prevRow, prevScroll, lastScroll;

    if (itemCount == 0)
        return 0;
    prevRow = work->cursorRow;
    prevScroll = work->scrollOffset;
    if (prevRow == 0 && prevScroll != -1) {
        work->scrollOffset = work->scrollOffset - 1;
    } else if (prevRow != 0) {
        work->cursorRow = work->cursorRow - 1;
    } else if (canWrap == 1) {
        lastScroll = itemCount - 7;
        work->scrollOffset = lastScroll;
        if (lastScroll < -1)
            work->scrollOffset = -1;
        if ((work->cursorRow = 5) >= itemCount)
            work->cursorRow = itemCount - 1;
    }
    return prevRow != work->cursorRow || prevScroll != work->scrollOffset;
}

/* Touch on the scroll bar at the right edge of the list. */
u32 func_021B63F8(ItemMenuWork *work)
{
    u32 touchX, touchY, prevScroll;
    int itemCount;

    itemCount = func_021B61C8(work);
    if (itemCount >= 7 && TOUCHPANEL_GetPointCont(&touchX, &touchY) == 1) {
        if (touchX >= 0x100 || touchX < 0xE0)
            return 0;
        if (work->isTouchActive == 0) {
            if (func_02035C60() == 1) {
                if (touchY < 0x10 || touchY >= 0x98)
                    return 0;
                work->isTouchActive = 1;
            } else
                return 0;
        }
        func_021B80C4(work, 0);
        prevScroll = work->scrollOffset;
        work->scrollOffset = func_0202EDE4(itemCount - 6, touchY, 0x1A, 0x8E, 0) - 1;
        func_021BA654(work);
        if (work->scrollOffset != prevScroll) {
            func_020061E4(ITEMMENU_SE_CURSOR);
            return 1;
        }
    }
    return 0;
}

/* Key input while an item is being moved: the entry follows the cursor. */
int func_021B64A0(ItemMenuWork *work)
{
    int moved = 0;
    int startIndex, itemCount;
    u32 steps;

    startIndex = func_021B61B8(work);
    itemCount = func_021B61C8(work);
    if (func_0203633C() & ITEMMENU_KEY_DOWN) {
        moved = func_021B6300(work, itemCount, 1);
    } else if (func_0203633C() & ITEMMENU_KEY_UP) {
        moved = func_021B6374(work, itemCount, 1);
    } else if (func_0203633C() & ITEMMENU_KEY_R) {
        steps = moved;
        do {
            if (func_021B6300(work, itemCount, 0) == 0)
                break;
            steps++;
        } while (steps < 6);
        if (steps != 0)
            moved = 1;
    } else if (func_0203633C() & ITEMMENU_KEY_L) {
        steps = moved;
        do {
            if (func_021B6374(work, itemCount, 0) == 0)
                break;
            steps++;
        } while (steps < 6);
        if (steps != 0)
            moved = 1;
    }
    if (moved) {
        itemCount = func_021B61B8(work);
        func_020061E4(ITEMMENU_SE_CURSOR);
        func_021B624C(work, startIndex, itemCount);
    }
    return moved;
}

/* Key input in the plain list: up, down, and six entries with L and R. */
int func_021B6554(ItemMenuWork *work)
{
    int moved = 0;
    int itemCount;
    u32 steps;

    itemCount = func_021B61C8(work);
    if (func_0203633C() & ITEMMENU_KEY_DOWN) {
        moved = func_021B6300(work, itemCount, 1);
    } else if (func_0203633C() & ITEMMENU_KEY_UP) {
        moved = func_021B6374(work, itemCount, 1);
    } else if (func_0203633C() & ITEMMENU_KEY_R) {
        steps = moved;
        do {
            if (func_021B6300(work, itemCount, 0) == 0)
                break;
            steps++;
        } while (steps < 6);
        if (steps != 0)
            moved = 1;
    } else if (func_0203633C() & ITEMMENU_KEY_L) {
        steps = moved;
        do {
            if (func_021B6374(work, itemCount, 0) == 0)
                break;
            steps++;
        } while (steps < 6);
        if (steps != 0)
            moved = 1;
    }
    return moved;
}

/* Touch on a list row: moves the cursor to it. Rows are 0x18 pixels high. */
int func_021B65E8(ItemMenuWork *work)
{
    u32 touchX, touchY;
    int itemCount, startIndex;
    u32 targetRow;
    int rowDistance;
    u32 step;

    if (TOUCHPANEL_GetPointCont(&touchX, &touchY) == 1) {
        if (touchX < 0x90 || touchX > 0xE7 || touchY < 0xC || touchY > 0x9B)
            return 0;
        targetRow = (touchY - 0xC) / 0x18;
        if ((u32)work->cursorRow == targetRow)
            return 0;
        itemCount = func_021B61C8(work);
        startIndex = func_021B61B8(work);
        rowDistance = (u32)work->cursorRow - targetRow;
        if (rowDistance < 0)
            rowDistance = -rowDistance;
        if ((u32)work->cursorRow < targetRow) {
            for (step = 0; step < rowDistance; step++) {
                if (func_021B6300(work, itemCount, 0) == 0)
                    break;
            }
        } else if ((u32)work->cursorRow > targetRow) {
            for (step = 0; step < rowDistance; step++) {
                if (func_021B6374(work, itemCount, 0) == 0)
                    break;
            }
        }
        if (step == 0)
            return 0;
        func_021B624C(work, startIndex, func_021B61B8(work));
        func_021B80C4(work, 0);
        return 1;
    }
    return 0;
}

/* Touch on the back button in the bottom right corner. */
int func_021B66B8(void)
{
    unsigned int touchX;
    unsigned int touchY;
    if (func_02035D20(&touchX, &touchY) == 1 && touchX >= 0xE0 && touchX <= 0xF7 && touchY >= 0xA8 && touchY <= 0xBF) return 1;
    return 0;
}

/* Task run after the closing transition. */
void func_021B66E8(ItemMenuWork *work)
{
    func_021BB5DC(work, 1);
    func_021B8AF4(work);
}

/* Main task of the item list: touch, A, B and cursor keys. */
void func_021B66FC(ItemMenuWork *work)
{
    int startIndex;

    BLINK_PALANM_Update(work->blinkPalAnm);
    if (func_0201C6B4(work->printSys) == 0)
        return;
    startIndex = func_021B61B8(work);
    if (func_021B63F8(work)) {
        func_021B624C(work, startIndex, func_021B61B8(work));
        work->shownItemId = 0xFFFF;
        func_021B6138(work);
        return;
    }
    if (func_02035C38() == 0) {
        work->isTouchActive = 0;
        if (work->isDraggingItem == 1) {
            func_020061E4(ITEMMENU_SE_SELECT);
            work->isDraggingItem = 0;
            func_02007CC8(work->bag, work->items, work->currentPocket, 0);
            func_0204B878(work->selectorActor, 1);
            func_021BB5DC(work, 1);
            work->usingWorkCopy = 0;
            func_021B80C4(work, 0);
            func_021B8AF4(work);
            return;
        }
    }
    if (work->isTouchActive == 1)
        return;
    if (func_020362DC() & (ITEMMENU_KEY_A | ITEMMENU_KEY_SELECT)) {
        func_020061E4(ITEMMENU_SE_SELECT);
        func_02007CC8(work->bag, work->items, work->currentPocket, 0);
        func_0204B878(work->selectorActor, 1);
        func_021BB5DC(work, 1);
        work->usingWorkCopy = 0;
        func_021B80C4(work, 1);
        func_021B8AF4(work);
        return;
    }
    if (func_020362DC() & ITEMMENU_KEY_B) {
        func_020061E4(ITEMMENU_SE_CANCEL);
        func_0204B878(work->selectorActor, 1);
        work->usingWorkCopy = 0;
        func_021B80C4(work, 1);
        work->shownItemId = 0xFFFF;
        func_021B6138(work);
        func_021B8C1C(work, 4, func_021B66E8);
        return;
    }
    if (func_021B66B8() == 1) {
        func_020061E4(ITEMMENU_SE_CANCEL);
        func_0204B878(work->selectorActor, 1);
        work->usingWorkCopy = 0;
        func_021B80C4(work, 0);
        work->shownItemId = 0xFFFF;
        func_021B6138(work);
        func_021B8C1C(work, 4, func_021B66E8);
        return;
    }
    if (func_021B65E8(work)) {
        work->isDraggingItem = 1;
        func_021BA6A4(work);
        func_020061E4(ITEMMENU_SE_CURSOR);
        work->shownItemId = 0xFFFF;
        func_021B6138(work);
        return;
    }
    if (func_021B64A0(work)) {
        func_021BA6A4(work);
        func_020061E4(ITEMMENU_SE_CURSOR);
        work->shownItemId = 0xFFFF;
        func_021B6138(work);
    }
}

/* The three repel items (ids 0x4C, 0x4D and 0x4F). */
int func_021B68E8(u16 itemId)
{
    int isRepel = 0;
    itemId = (u16)(itemId + 0xFFB4);
    if (itemId <= 3 && ((1 << itemId) & 0xB)) isRepel = 1;
    return isRepel;
}

/* 1 for the repel items, 2 for items 0x268 and 0x269, 0 for all others. */
int func_021B690C(u16 itemId)
{
    if (func_021B68E8(itemId)) return 1;
    if (itemId == 0x268 || itemId == 0x269) return 2;
    return 0;
}

/* Uses a repel: starts it when none is active, then waits for the message. */
void func_021B6934(ItemMenuWork *work)
{
    void *repelState;
    u8 steps;

    if (func_021B68E8(work->selectedItemId)) {
        repelState = func_0200D418(func_02012EBC(work->saveData));
        if (func_0200D58C(repelState)) {
            steps = func_02020FE4(work->selectedItemId, 2, work->heapId);
            func_0200D55C(repelState, steps);
            func_021B7D20(work, 1);
            func_02045CAC(work->msgBank, ITEMMENU_MSG_REPEL_USED, work->tempString);
            func_0201F02C(work->wordSet, 0, work->myStatus);
            func_021B61F4(work, 1, work->selectedItemId);
            func_0201F250(work->wordSet, work->messageString, work->tempString);
            func_021BACF0(work, 1);
            func_020061E4(ITEMMENU_SE_REGISTER);
        } else {
            func_02045CAC(work->msgBank, ITEMMENU_MSG_REPEL_STILL_ACTIVE, work->tempString);
            func_0201F250(work->wordSet, work->messageString, work->tempString);
            func_021BACF0(work, 1);
        }
        func_021B6100(work, func_021B6A14);
    }
}

/* Task: waits until the message is read, then returns to the list. */
void func_021B6A14(ItemMenuWork *work)
{
    if (func_021BADF0(work) == 0)
        return;
    if ((func_020362DC() & (ITEMMENU_KEY_A | ITEMMENU_KEY_B)) == 0 && func_02035C60() == 0)
        return;
    func_020414EC(3);
    work->shownItemId = 0xFFFF;
    func_021B6138(work);
    work->listDirty = 1;
    func_021BA6A4(work);
    func_0204B92C(work->cursorActor, 1);
    func_021BB3F4(work, 1);
    func_021B8AF4(work);
}

/* Shows the refusal message for the items 0x268 and 0x269. */
void func_021B6A78(ItemMenuWork *work)
{
    if ((unsigned int)work->selectedItemId - 0x268 <= 1) {
        func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_KEY_ITEM, work->tempString);
        func_0201F02C(work->wordSet, 0, work->myStatus);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021BACF0(work, 1);
        func_021B6100(work, func_021B6A14);
    }
}

/* Starts the message already prepared and waits for the player. */
void func_021B6AD8(ItemMenuWork *work) { func_021BACF0(work, 1); func_021B6100(work, func_021B6A14); }

/* Action 0 (use). Enters the state when allowed, else shows the refusal. */
u32 func_021B6AF0(ItemMenuWork *work)
{
    if (work->usageContext == 0) {
        if (func_02028754(work->actionPermissions, 0)) {
            work->nextState = 0xA;
            func_021B6100(work, 0);
            return 1;
        }
        func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
        func_0201F02C(work->wordSet, 0, work->myStatus);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021B6100(work, func_021B6AD8);
        return 0;
    } else if (work->usageContext == 1) {
        if (func_02028754(work->actionPermissions, 0)) {
            work->nextState = 0xB;
            func_021B6100(work, 0);
            return 1;
        }
        func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_IN_CONTEXT, work->tempString);
        func_0201F02C(work->wordSet, 0, work->myStatus);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021B6100(work, func_021B6AD8);
        return 0;
    }
    return 0;
}

/* Action 1 (give). */
u32 func_021B6BC4(ItemMenuWork *work)
{
    u32 started = 1;

    if (func_02028754(work->actionPermissions, 1)) {
        work->nextState = 7;
        func_021B6100(work, 0);
        return started;
    }
    func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
    func_0201F02C(work->wordSet, 0, work->myStatus);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    func_021B6100(work, func_021B6AD8);
    return 0;
}

/* Action 2 (register). */
u32 func_021B6C30(ItemMenuWork *work)
{
    if (func_02028754(work->actionPermissions, 2)) {
        work->nextState = 8;
        func_021B6100(work, 0);
        return 1;
    }
    func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
    func_0201F02C(work->wordSet, 0, work->myStatus);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    func_021B6100(work, func_021B6AD8);
    return 0;
}

/* Action 6 (check). */
u32 func_021B6C98(ItemMenuWork *work)
{
    if (func_02028754(work->actionPermissions, 6)) {
        work->nextState = 0x11;
        func_021B6100(work, 0);
        return 1;
    }
    func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
    func_0201F02C(work->wordSet, 0, work->myStatus);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    func_021B6100(work, func_021B6AD8);
    return 0;
}

/* Action 4 (toss): asks for a quantity first. */
u32 func_021B6D00(ItemMenuWork *work)
{
    if (func_02028754(work->actionPermissions, 4)) {
        work->nextState = 0xF;
        func_021B6100(work, 0);
        func_021B7D20(work, 1);
        return 1;
    }
    func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
    func_0201F02C(work->wordSet, 0, work->myStatus);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    func_021B6100(work, func_021B6AD8);
    return 0;
}

/* Action 5 (sort). */
u32 func_021B6D70(ItemMenuWork *work)
{
    if (func_02028754(work->actionPermissions, 5)) {
        work->nextState = 0x10;
        func_021B6100(work, 0);
        return 1;
    }
    func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
    func_0201F02C(work->wordSet, 0, work->myStatus);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    func_021B6100(work, func_021B6AD8);
    return 0;
}

/* Action 9 (plant), only in usage context 0. */
u32 func_021B6DD8(ItemMenuWork *work)
{
    if (work->usageContext == 0) {
        if (func_02028754(work->actionPermissions, 9)) {
            work->nextState = 0x14;
            func_021B6100(work, 0);
            return 1;
        }
        func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
        func_0201F02C(work->wordSet, 0, work->myStatus);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021B6100(work, func_021B6AD8);
        return 0;
    }
    return 0;
}

/* Action 3 (sell): asks for a quantity first, only in usage context 0. */
u32 func_021B6E4C(ItemMenuWork *work)
{
    if (work->usageContext == 0) {
        if (func_02028754(work->actionPermissions, 3)) {
            work->nextState = 0xE;
            func_021B6100(work, 0);
            func_021B7D20(work, 1);
            return 1;
        }
        func_02045CAC(work->msgBank, ITEMMENU_MSG_CANT_USE_NOW, work->tempString);
        func_0201F02C(work->wordSet, 0, work->myStatus);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021B6100(work, func_021B6AD8);
        return 0;
    }
    return 0;
}

/*
 * Unlabelled leaf (push {r4,r5}, no lr) called twice by func_021B6EF8:
 * finds the entry of the 8-entry range table at 0x021BB9C4 whose
 * [firstItemId, firstItemId + itemCount) holds itemId, or -1.
 */
int func_021B6EC8(u16 itemId)
{
    u32 i;
    const ItemUseRange *range;

    for (i = 0; i < 8; i++) {
        range = &d_021BB9C4[i];
        if (itemId >= range->firstItemId && itemId < range->firstItemId + range->itemCount)
            return i;
    }
    return -1;
}










/*
 * The switch arms are in the original's layout order (0,1,3,4-5,2,8,9,6,7);
 * the table entry at 0x021BB9C8 is d_021BB9C4[i].fn, one extern through
 * its field (the pool word is the symbol + 4).
 */
void func_021B6EF8(ItemMenuWork *work)
{
    int flag = 0;
    u32 x;
    int r;

    if (func_021BADF0(work) == 0)
        return;
    if (func_020279E8(work->menuList)) {
        x = work->menuActionTable[func_02027A04(work->menuList)];
        work->usageContext = x;
        switch (x) {
        case 0:
            func_021BB580(work, 0);
            if (work->currentPocket != 4)
                GAME_BEACON_SetItemUse(work->selectedItemId);
            if (work->currentPocket == 2) {
                func_021B6100(work, func_021B7640);
            } else if (func_02020FE4(work->selectedItemId, 0x1D, work->heapId) == 1) {
                work->nextState = 0xC;
                func_021B6100(work, 0);
            } else if (func_021B6EC8(work->selectedItemId) >= 0) {
                d_021BB9C4[func_021B6EC8(work->selectedItemId)].useHandler(work);
            } else {
                r = func_021B690C(work->selectedItemId);
                if (r == 1) {
                    func_021B6100(work, func_021B6934);
                } else if (r == 2) {
                    func_021B6100(work, func_021B6A78);
                } else {
                    work->nextState = 5;
                    func_021B6100(work, 0);
                }
            }
            break;
        case 1:
            func_021BB580(work, 0);
            if (func_02028754(work->actionPermissions, 0)) {
                work->nextState = 0xB;
                func_021B6100(work, 0);
            } else {
                func_02045CAC(work->msgBank, 0x39, work->tempString);
                func_0201F02C(work->wordSet, 0, work->myStatus);
                func_0201F250(work->wordSet, work->messageString, work->tempString);
                func_021B6100(work, func_021B6AD8);
            }
            break;
        case 3:
            func_021B6100(work, func_021B7804);
            break;
        case 4:
        case 5:
            if (func_021B811C(work) == 1) {
                func_021B8134(work, work->cursorRow);
                func_021B6138(work);
                func_021BB3F4(work, 1);
                func_0204B92C(work->cursorActor, 1);
                func_021B8AF4(work);
            }
            break;
        case 2:
            func_021BB580(work, 0);
            if (work->selectedItemId >= 0x89 && work->selectedItemId <= 0x94) {
                work->nextState = 0x13;
                func_021B6100(work, 0);
            }
            break;
        case 8:
            if (func_020355C4() == 1)
                func_021B9AAC(work);
            func_021B80C4(work, func_020355C4() == 0);
            func_021BB3F4(work, 1);
            func_0204B92C(work->cursorActor, 1);
            func_021B8AF4(work);
            break;
        case 9:
            work->nextState = 1;
            func_021B6100(work, 0);
            break;
        case 6:
            work->nextState = 2;
            func_021BB580(work, 0);
            func_021B6100(work, 0);
            break;
        case 7:
            break;
        }
        flag = 1;
    }
    if (flag) {
        func_021BA9AC(work);
        func_02027858(work->menuList);
        work->menuList = 0;
    }
}









void func_021B7128(ItemMenuWork *work)
{
    u16 *p;
    int s;

    p = (void *)func_021B616C(work, func_021B61B8(work));
    work->selectedItemId = 0;
    if (p != 0)
        work->selectedItemId = *p;
    s = work->bagMode;
    if (s == 2) {
        if (func_02020FE4(work->selectedItemId, 3, work->heapId) == 0 && PALANM_IsOutsideReservedIdRange(work->selectedItemId) == 1) {
            if (func_0202136C(work->selectedItemId) != 0)
                work->nextState = 0x12;
            else
                work->nextState = 3;
            func_021B6100(work, 0);
            return;
        }
        func_02045CAC(work->msgBank, 0x2F, work->tempString);
        func_021B61F4(work, 0, work->selectedItemId);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021BADAC(work);
        func_021BB3F4(work, 0);
        func_021BB580(work, 0);
        func_021B6100(work, func_021B7688);
    } else if (s == 5) {
        work->nextState = 1;
        func_021B6100(work, 0);
    } else if (s == 4) {
        func_021B6100(work, func_021B795C);
    } else {
        func_021B832C(work);
        func_021BADB8(work, work->selectedItemId);
        func_021BADAC(work);
        func_0204B92C(work->cursorActor, 0);
        func_021B6100(work, func_021B6EF8);
    }
}









void func_021B7250(ItemMenuWork *work)
{
    unsigned int k;
    int v;

    if (func_0201C6B4(work->printSys) == 0)
        return;
    if (func_02035C38() == 0)
        work->isTouchActive = 0;
    func_02051C88(work->taskSys);
    BLINK_PALANM_Update(work->blinkPalAnm);
    if (work->taskFn != (ItemMenuTaskFn)func_021B7250)
        return;
    if (func_021B63F8(work) != 0) {
        work->shownItemId = 0xFFFF;
        func_021B6138(work);
        return;
    }
    if (work->isTouchActive == 1)
        return;
    if (func_020355C4() == 1) {
        k = func_020362DC();
        if (k == 0)
            return;
        if (func_021B61C8(work) != 0) {
            if ((k & 0xC0A) == 0) {
                func_020061E4(0x548);
                func_021B9850(work);
                func_021B80C4(work, 1);
                return;
            }
        } else {
            func_021B80C4(work, 1);
            if (k & 0xCD)
                return;
        }
    }
    if (func_020362DC() & 2) {
        work->nextState = 1;
        work->selectedItemId = 0;
        func_020355D8(0);
        func_021B8C1C(work, 4, 0);
        return;
    }
    if (func_020362DC() & 0x400) {
        if (work->bagMode == 2)
            return;
        work->nextState = 0;
        work->selectedItemId = 0;
        func_020355D8(0);
        func_021B8C1C(work, 3, 0);
        return;
    }
    if (func_020362DC() & 0x800) {
        if (func_021B811C(work) != 1)
            return;
        if (work->currentPocket == 4) {
            func_021B8134(work, work->cursorRow);
            func_021B6138(work);
        } else {
            func_021B81B8(work);
        }
        if (func_020355C4() != 1)
            return;
        func_021B9850(work);
        func_021B80C4(work, 1);
        return;
    }
    if ((func_020362DC() & 8) && work->currentPocket != 2 && work->currentPocket != 3 && func_021B61C8(work) > 1) {
        func_021B8080(work);
        func_021B80C4(work, 1);
        work->shownItemId = 0xFFFF;
        func_021B6138(work);
        func_021B6100(work, func_021B8EA8);
        return;
    }
    if (func_020362DC() & 1) {
        if (func_021B61C8(work) > 0) {
            func_021B6100(work, func_021B8B7C);
            return;
        }
    } else if (func_020362DC() & 4) {
        if (work->currentPocket != 2 && work->currentPocket != 3 && func_021B61C8(work) > 1) {
            func_02082BCC(work->items, 0, 0x4D8);
            func_02007CC8(work->bag, work->items, work->currentPocket, 1);
            func_0204B878(work->selectorActor, 2);
            func_021BB5DC(work, 0);
            work->usingWorkCopy = 1;
            func_021B8B0C(work);
        }
        return;
    } else if (func_021B6554(work) != 0) {
        func_021BA6A4(work);
        func_020061E4(0x548);
        func_021B6138(work);
        return;
    }
    if (func_0203633C() & 0x10) {
        v = work->currentPocket;
        work->currentPocket = v + 1;
        if (work->currentPocket >= 5)
            work->currentPocket = 0;
        func_020355D8(0);
        func_021B8CE4(work, v, 1, func_021B8F90);
        return;
    }
    if (func_0203633C() & 0x20) {
        v = work->currentPocket;
        work->currentPocket = v - 1;
        if (work->currentPocket < 0)
            work->currentPocket = 4;
        func_020355D8(0);
        func_021B8CE4(work, v, 0, func_021B8F90);
    }
}








void func_021B7504(ItemMenuWork *work)
{
    if (func_020279E8(work->menuList) == 0)
        return;
    if (func_02027A04(work->menuList) == 0) {
        func_021BA9AC(work);
        work->nextState = 6;
        func_021B6100(work, 0);
    } else {
        func_021BA9AC(work);
        func_020414EC(3);
        func_0204B92C(work->cursorActor, 1);
        func_021BB3F4(work, 1);
        if (func_020355C4() == 1) {
            func_021B9AAC(work);
            func_021B80C4(work, 0);
        } else {
            func_021B80C4(work, 1);
        }
        func_021B8AF4(work);
    }
    func_021BB1AC(work);
}







void func_021B7584(ItemMenuWork *work) { if (func_021BADF0(work)) { func_021BB0F8(work); func_021B6100(work,func_021B7504); } }








void func_021B75A4(ItemMenuWork *work)
{
    if (func_02006238() == 1)
        return;
    if ((func_020362DC() & 3) == 0 && func_02035C60() == 0)
        return;
    func_02045CAC(work->msgBank, 0x3E, work->tempString);
    func_0201EF34(work->wordSet, 0, func_020212B0(work->selectedItemId));
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    func_021BACF0(work, 1);
    func_021B6100(work, func_021B7584);
}







void func_021B761C(ItemMenuWork *work) { if (func_021BADF0(work)) { func_020061E4(0x55C); func_021B6100(work,func_021B75A4); } }







void func_021B7640(ItemMenuWork *work)
{
    if (func_02021350(work->selectedItemId) == 0xFF)
        func_02045CAC(work->msgBank, 0x3C, work->messageString);
    else
        func_02045CAC(work->msgBank, 0x3D, work->messageString);
    func_021BACF0(work, 1);
    func_021B6100(work, func_021B761C);
}







void func_021B7688(ItemMenuWork *work)
{
    if ((func_020362DC() & 3) || func_02035C60() != 0) {
        func_020414EC(3);
        work->shownItemId = 0xFFFF;
        func_021B6138(work);
        work->listDirty = 1;
        func_021BA6A4(work);
        func_0204B92C(work->cursorActor, 1);
        func_021BB3F4(work, 1);
        func_021B8AF4(work);
    }
}






void func_021B76E4(ItemMenuWork *work) { if (func_021BADF0(work)) func_021B6100(work,func_021B7688); }







void func_021B7700(ItemMenuWork *work)
{
    int r;
    int v;

    if (func_020279E8(work->menuList) == 0)
        return;
    r = func_02027A04(work->menuList);
    func_021BB1AC(work);
    func_020414EC(3);
    if (r == 0) {
        func_020061E4(0x647);
        func_021B7D20(work, work->listCount);
        func_02045CAC(work->msgBank, 0x36, work->tempString);
        func_021B6204(work, 0, work->selectedItemId, work->listCount > 1, 0);
        func_0201EFA4(work->wordSet, 1, work->listCount, 3, 0, 1);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021BADAC(work);
        func_021B6100(work, func_021B76E4);
    } else {
        func_0204B92C(work->cursorActor, 1);
        v = 1;
        func_021BB3F4(work, 1);
        if (func_020355C4() != 0)
            v = 0;
        func_021B80C4(work, v);
        func_021B8AF4(work);
    }
}






void func_021B77E4(ItemMenuWork *work) { if (func_021BADF0(work)) { func_021BB0F8(work); func_021B6100(work,func_021B7700); } }







void func_021B7804(ItemMenuWork *work)
{
    work->listCount = 1;
    func_021B7D9C(work, 1);
    func_02045CAC(work->msgBank, 0x35, work->tempString);
    func_021B6204(work, 0, work->selectedItemId, 1, 0);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    func_021BADAC(work);
    func_021B6100(work, func_021B7868);
}







void func_021B7868(ItemMenuWork *work)
{
    int r;

    if (func_021BADF0(work) == 0)
        return;
    if (func_021B7DF4(work) == 1)
        return;
    r = func_021B8DAC();
    if (r == -1) {
        if (func_020362DC() & 1) {
            r = 0;
            func_020355D8(0);
        } else if (func_020362DC() & 2) {
            func_020355D8(0);
            r = 1;
        }
    }
    if (r == 0) {
        func_020061E4(0x54C);
        func_021B7DD0(work);
        func_02045CAC(work->msgBank, 0x37, work->tempString);
        func_021B6204(work, 0, work->selectedItemId, work->listCount > 1, 0);
        func_0201EFA4(work->wordSet, 1, work->listCount, 3, 0, 1);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021BADAC(work);
        func_021B6100(work, func_021B77E4);
        return;
    }
    if (r == 1) {
        func_020061E4(0x551);
        func_021B8C1C(work, 4, func_021B8DCC);
    }
}







void func_021B795C(ItemMenuWork *work)
{
    unsigned int a;
    unsigned int b;

    func_0204B92C(work->cursorActor, 0);
    a = func_02020FE4(work->selectedItemId, 0, (u32)work->heapId);
    b = func_02020FE4(work->selectedItemId, 3, (u32)work->heapId);
    if (a == 0 || b != 0) {
        func_021BB3F4(work, 0);
        func_02045CAC(work->msgBank, 0x4D, work->tempString);
        func_021B61F4(work, 0, work->selectedItemId);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021BADAC(work);
        func_021BB580(work, 0);
        func_021B6100(work, func_021B7C88);
        return;
    }
    work->listCount = 1;
    func_021BB08C(work);
    func_021BB3F4(work, 0);
    if (func_021B616C(work, func_021B61B8(work))->count == 1) {
        func_021B6100(work, func_021B7B08);
        return;
    }
    func_021B7D9C(work, 2);
    func_02045CAC(work->msgBank, 0x4E, work->tempString);
    func_021B61F4(work, 0, work->selectedItemId);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    func_021BADAC(work);
    func_021B6100(work, func_021B7A7C);
}







void func_021B7A7C(ItemMenuWork *work)
{
    int r;

    if (func_021BADF0(work) == 0)
        return;
    if (func_021B7DF4(work) == 1)
        return;
    r = func_021B8DAC();
    if (r == -1) {
        if (func_020362DC() & 1) {
            r = 0;
            func_020355D8(0);
        } else if (func_020362DC() & 2) {
            func_020355D8(0);
            r = 1;
        }
    }
    if (r == 0) {
        func_020061E4(0x54C);
        func_021B7DD0(work);
        func_021B6100(work, func_021B7B08);
        return;
    }
    if (r == 1) {
        func_020061E4(0x551);
        func_021B8C1C(work, 4, func_021B8E08);
    }
}







void func_021B7B08(ItemMenuWork *work)
{
    int v;

    func_021BB0F8(work);
    v = func_021B619C(work->selectedItemId, work->listCount, work->heapId);
    func_02045CAC(work->msgBank, 0x4F, work->tempString);
    func_0201EFA4(work->wordSet, 0, v, 7, 0, 1);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    func_021BADAC(work);
    func_021B6100(work, func_021B7B80);
}






void func_021B7B80(ItemMenuWork *work)
{
    int r;
    int v;

    if (func_021BADF0(work) == 0)
        return;
    if (func_020279E8(work->menuList) == 0)
        return;
    r = func_02027A04(work->menuList);
    func_021BB1AC(work);
    switch (r) {
    case 0:
        v = func_021B619C(work->selectedItemId, work->listCount, work->heapId);
        func_021B7D20(work, work->listCount);
        func_0200C278((struct Blk34 *)((unsigned int)func_02012F08(work->saveData)), v);
        func_020061E4(0x655);
        func_021BAFC4(work);
        func_02045CAC(work->msgBank, 0x50, work->tempString);
        func_021B6204(work, 0, work->selectedItemId, work->listCount > 1, 0);
        func_0201EFA4(work->wordSet, 1, v, 7, 0, 1);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021BADAC(work);
        func_021B6100(work, func_021B7C88);
        break;
    case 1:
        func_021B80C4(work, func_020355C4() == 0);
        func_021B6100(work, func_021B7CD0);
        break;
    }
}






void func_021B7C88(ItemMenuWork *work)
{
    if (func_021BADF0(work) == 0)
        return;
    if (func_020362DC() & 3) {
        func_021B80C4(work, 1);
        func_021B6100(work, func_021B7CD0);
        return;
    }
    if (func_02035C60() != 0) {
        func_021B80C4(work, 0);
        func_021B6100(work, func_021B7CD0);
    }
}







void func_021B7CD0(ItemMenuWork *work)
{
    func_020414EC(3);
    work->shownItemId = 0xFFFF;
    func_021B6138(work);
    work->listDirty = 1;
    func_021BA6A4(work);
    func_021BB0BC(work);
    func_0204B92C(work->cursorActor, 1);
    func_021BB3F4(work, 1);
    func_021B8AF4(work);
}







void func_021B7D20(ItemMenuWork *work, int x)
{
    int v;

    func_021B616C(work, func_021B61B8(work));
    func_02007F1C(work->bag, work->selectedItemId, x, work->heapId);
    if (func_02007FB8(work->bag, work->selectedItemId, work->heapId) != 0)
        return;
    if (func_021B61C8(work) + 1 < 7) {
        v = work->cursorRow - 1;
        if (v <= 0)
            v = 0;
        work->cursorRow = v;
    } else {
        v = work->scrollOffset - 1;
        if (v < -1)
            v = -1;
        work->scrollOffset = v;
    }
}





void func_021B7D9C(ItemMenuWork *work, int v) { work->listMode=v; func_021BB1C4(work); func_021BB260(work,work->listCount); func_0204B3DC(work->listWindowA, 1); func_0204B3DC(work->listWindowB, 1); }





void func_021B7DD0(ItemMenuWork *work) { func_020414EC(3); func_0204B3DC(work->listWindowA, 0); func_0204B3DC(work->listWindowB, 0); }






/*
 * Quantity selector input: touch buttons (hit table d_021BB960, with
 * auto-repeat accelerating after 120 frames) or the d-pad step the count at
 * +0x7F4 by 1 or 10, wrap it between 1 and the item's count, and redraw on
 * change. Returns whether any input was taken.
 */
int func_021B7DF4(ItemMenuWork *work)
{
    HitTbl tbl;
    Item *e;
    int saved;
    int hit;
    int changed;
    int dir;

    changed = 0;
    saved = work->listCount;
    e = (void *)func_021B616C(work, func_021B61B8(work));
    tbl = d_021BB960;
    hit = TOUCHPANEL_HitCont(&tbl);
    if (hit != -1) {
        work->repeatCount++;
        changed = 1;
    } else {
        work->repeatCount = 0;
    }
    if (work->repeatCount == 1 || work->repeatCount > 30) {
        switch (hit) {
        case 0:
            if (work->repeatCount > 120)
                work->listCount += 10;
            else
                work->listCount += 1;
            dir = 0;
            break;
        case 1:
            if (work->repeatCount > 120)
                work->listCount -= 10;
            else
                work->listCount -= 1;
            dir = 1;
            break;
        }
    }
    if (hit == -1) {
        if (func_0203633C() & 0x40) {
            work->listCount += 1;
            dir = 0;
            changed = 1;
        } else if (func_0203633C() & 0x80) {
            work->listCount -= 1;
            dir = 1;
            changed = 1;
        } else if (func_0203633C() & 0x10) {
            work->listCount += 10;
            dir = 0;
            changed = 1;
        } else if (func_0203633C() & 0x20) {
            work->listCount -= 10;
            dir = 1;
            changed = 1;
        }
    }
    if (e->count < work->listCount)
        work->listCount = 1;
    else if (work->listCount < 1)
        work->listCount = e->count;
    if (work->listCount != saved) {
        func_020061E4(0x548);
        if (dir == 0)
            func_0204B878(work->listWindowA, 0xB);
        else
            func_0204B878(work->listWindowB, 0xA);
        func_021BB260(work, work->listCount);
    }
    return changed;
}






int func_021B7F38(Ent *a, Ent *b)
{
    if (a->key == b->key)
        return 0;
    if (a->key > b->key)
        return 1;
    return -1;
}






void func_021B7F54(ItemMenuWork *work)
{
    int i;
    Ent *ents;
    Item *items;
    int n;
    int h;
    int rec;
    u32 x;
    Ent *e;

    ents = func_02030734(work->heapId, 0x9B0, 0, d_021BBBC0, 0xB35);
    items = func_02030734(work->heapId, 0x4D8, 0, d_021BBBC0, 0xB36);
    MYITEM_SAVEDATA_CopyPocket(work->bag, items, (u32)work->currentPocket, 1);
    n = func_021B61C8(work);
    h = (int)func_02020F14(work->heapId);
    for (i = 0; i < n; i++) {
        rec = func_02020F20(h, items[i].id, work->heapId);
        e = &ents[i];
        x = func_02021014((struct Rec *)rec, 0xF);
        e->key = (x << 28) + (func_02021014((struct Rec *)rec, 0x11) << 16) + items[i].id;
        e->item = items[i];
        func_020307B0((void *)rec);
    }
    func_02049238((void *)h);
    MATH_QSort(ents, n, 8, func_021B7F38, 0);
    for (i = 0; i < n; i++) {
        items[i] = ents[i].item;
    }
    MYITEM_SAVEDATA_CopyPocket(work->bag, items, (u32)work->currentPocket, 0);
    func_020307B0(items);
    func_020307B0(ents);
}





void func_021B8080(ItemMenuWork *work) { func_020061E4(0x663); func_0204B878(((work->inputGuard)), 2); }





void func_021B809C(ItemMenuWork *work) { func_021B7F54(work); work->shownItemId=0xFFFF; func_021B6138(work); }





void func_021B80BC(ItemMenuWork *work)
{
    func_021BB5A4(work);
}






void func_021B80C4(ItemMenuWork *work, int flag)
{
    if (work->usingWorkCopy == 1)
        flag = 1;
    if (flag)
        func_020355D8(0);
    else
        func_020355D8(1);
    if (func_021B61C8(work) == 0)
        flag = 0;
    if (flag == 0) {
        func_021BB398(work, 0);
    } else {
        func_021BB398(work, 1);
        BLINK_PALANM_ResetPhase(work->blinkPalAnm);
    }
    func_021B97E8(work, flag);
}





int func_021B811C(ItemMenuWork *work) { int v = work->bagMode; if (v==0 || v==1 || v==3) return 1; return 0; }






int func_021B8134(ItemMenuWork *work, int k)
{
    u16 *p;
    int v;

    k += work->scrollOffset + 1;
    if (work->currentPocket == 4) {
        if (func_021B61C8(work) <= k)
            return 0;
        p = (void *)func_021B616C(work, k);
        v = func_0202E448(*p);
        if (v == 0x19)
            return 0;
        if (func_021B83A0(work, *p) == 1)
            GAME_DATA_SetSaveFlag(work->saveData, v, 0);
        else
            GAME_DATA_SetSaveFlag(work->saveData, v, 1);
        func_020061E4(0x646);
        work->shownItemId = 0xFFFF;
        return 1;
    }
    return 0;
}





int func_021B81B0(int x)
{
    int func_021BB368(int);
    return func_021BB368(x);
}





void func_021B81B8(ItemMenuWork *work) { int a; int v; a=func_021B81B0(work->currentPocket); v=GAME_DATA_CheckSaveFlag(work->saveData,a); GAME_DATA_SetSaveFlag(work->saveData,a,v^1); func_020061E4(0x646); func_021B81F4(work); }





void func_021B81F4(ItemMenuWork *work) { if (work->usingWorkCopy!=1) func_0204B878(((work->sideActor[2])), (unsigned int)GAME_DATA_CheckSaveFlag(work->saveData,func_021B81B0(work->currentPocket))+6u); }






void func_021B822C(ItemMenuWork *work, void *rec, u16 *p, u8 *out)
{
    if (func_02021014(rec, 6) != 0) {
        if (func_0202136C(*p) == 1)
            *out = 2;
        else if (*p == 0x1C2 && work->bagFilter == 1)
            *out = 1;
        else
            *out = 0;
    }
    if ((u16)(*p + 0xFD98) <= 1)
        *out = 0;
}





void func_021B8280(ItemMenuWork *work, unsigned char *q)
{
    unsigned short *e = (void *)func_021B616C(work, func_021B61B8(work));
    if (e != 0 && *e != 0) {
        void *h = func_02020F34(*e, 0, work->heapId);
        unsigned char v = work->currentPocket;
        func_021B822C(work, h, e, q);
        if (func_021B8F68(work, v) == 0 && q[0] != 2) {
            q[0] = 0xFF;
        }
        if (func_02021014(h, 3) == 0) {
            if (PALANM_IsOutsideReservedIdRange(*e) == 1) {
                q[1] = 6;
            }
            if (v != 2) {
                q[2] = 3;
            }
        }
        if (func_02021014(h, 4) != 0) {
            if (func_021B83A0(work, *e) == 1) {
                q[2] = 5;
            } else {
                q[2] = 4;
            }
        }
        q[3] = 8;
        func_020307B0(h);
    }
}




/*
 * lever: func_021BA9C0 reads the count in r2; passing j keeps it in r2.
 */
void func_021B832C(ItemMenuWork *work)
{
    T44 t = d_021BB998;
    T4 a = d_021BB95C;
    int tmp[4];
    int j;
    int i;
    func_021B8280(work, (unsigned char *)(&a));
    i = 0;
    j = 0;
    for (; i < 4; i++) {
        int c = a.v[i];
        if (c != 0xFF) {
            work->menuActionTable[j] = c;
            tmp[j] = t.v[a.v[i]];
            j++;
        }
    }
    func_021BA9C0(work, tmp, j);
}




int func_021B83A0(ItemMenuWork *work, int value)
{
    return GAME_DATA_CheckSaveFlag(work->saveData, (int)func_0202E448((u16)value));
}





/*
 * Touch-button dispatch of the list screen: buttons 0-4 pick a pocket tab
 * through the table d_021BB984, 5/6 step the tab, 7-10 are the sort,
 * select, exit and back buttons, 11-16 pick a list row, 17+ pick a slot.
 * Touch twin of func_021B7250's key handling.
 */
void func_021B83B8(u32 idx, int flag, ItemMenuWork *work)
{
    int tab;
    int count;
    int v;
    int saved;
    int cur;
    TabTbl t;

    tab = -1;
    count = func_021B61C8(work);
    if (flag != 0)
        return;
    if (idx < 5) {
        t = d_021BB984;
        if (work->currentPocket != t.v[idx]) {
            tab = t.v[idx];
            func_021B80C4(work, 0);
        }
    } else if (idx == 5) {
        func_021B80C4(work, 0);
        v = work->currentPocket;
        work->currentPocket = v - 1;
        if (work->currentPocket < 0)
            work->currentPocket = 4;
        func_021B8CE4(work, v, 0, func_021B8F90);
        return;
    } else if (idx == 6) {
        func_021B80C4(work, 0);
        v = work->currentPocket;
        work->currentPocket = v + 1;
        if (work->currentPocket >= 5)
            work->currentPocket = 0;
        func_021B8CE4(work, v, 1, func_021B8F90);
        return;
    } else if (idx == 7) {
        if (work->currentPocket != 2 && work->currentPocket != 3 && func_021B61C8(work) > 1) {
            func_021B8080(work);
            func_021B80C4(work, 0);
            work->shownItemId = 0xFFFF;
            func_021B6138(work);
            func_021B6100(work, func_021B8EA8);
        }
    } else if (idx == 8) {
        if (func_021B811C(work) == 1) {
            func_021B81B8(work);
            func_021B80C4(work, 0);
            work->shownItemId = 0xFFFF;
            func_021B6138(work);
        }
    } else if (idx == 9) {
        if (work->bagMode != 2) {
            work->nextState = 0;
            work->selectedItemId = 0;
            func_021B8C1C(work, 3, 0);
            func_020355D8(1);
        }
    } else if (idx == 10) {
        work->nextState = 1;
        work->selectedItemId = 0;
        func_021B8C1C(work, 4, 0);
        func_020355D8(1);
    } else if (idx >= 11 && idx < 17) {
        if (work->taskFn != (ItemMenuTaskFn)func_021B7250)
            return;
        saved = work->cursorRow;
        cur = func_021B61B8(work);
        if (func_021B61C8(work) == 0)
            return;
        if (work->cursorRow != idx - 11) {
            work->cursorRow = idx - 11;
            if (count <= func_021B61B8(work)) {
                work->cursorRow = saved;
                return;
            }
        }
        func_021B624C(work, cur, func_021B61B8(work));
        func_021B80C4(work, 0);
        work->shownItemId = 0xFFFF;
        func_021B6138(work);
        func_021B9850(work);
        func_021B6100(work, func_021B8B7C);
        return;
    } else if (idx >= 17) {
        if (func_021B811C(work) == 1 && func_021B8134(work, idx - 17) == 1) {
            func_021B80C4(work, 0);
            func_021B6138(work);
        }
    }
    if (tab != -1) {
        v = work->currentPocket;
        work->currentPocket = tab;
        func_020061E4(0x7D9);
        func_021B6288(work, v, work->currentPocket);
        func_021B80BC(work);
        func_021B80C4(work, 0);
        work->shownItemId = 0xFFFF;
        func_021B6138(work);
    }
}





void func_021B8600(int u, ItemMenuWork *work)
{
    int s = work->screenState;
    if (s == 1) {
        func_021B97CC(work, 1);
        work->screenState = 0;
    } else if (s == 2) {
        func_021B97CC(work, 0);
        work->screenState = 0;
    }
    PALANM_TransferPalettes((struct S02021D50 *)((int)work->palAnmSlot));
    func_0204A648();
}





void func_021B8640(ItemMenuWork *work)
{
    if (func_0201C6B4((const struct PrintSys *)(work->printSys))) {
        func_0202208C(0, 1, 1, 0, 6, 1, work->heapId);
        func_020061E4(0x79F);
        func_021B6100(work, func_021B8688);
    }
}





/*
 * blocked:
 */
void func_021B8688(ItemMenuWork *work)
{
    int a = func_020221A4();
    int b = func_021BB690((const char *)work);
    if (a == 1 && b == 0) {
        func_0204B92C(work->cursorActor, 1);
        func_021B8AF4(work);
    }
}


int func_021B86B8(void *proc, int st, ItemMenuArgs *a)
{
    ItemMenuWork *work; u16 i; s16 scr, cur;
    func_0203064C(1, 0xe, 0x34000);
    work = func_0203159C(proc, 0x874, 0xe);
    func_02082BCC(work, 0, 0x874);
    KEY_GetRepeatSpeed(&work->keyRepeatDelay, &work->keyRepeatInterval);
    work->heapId = 0xe;
    work->currentPage = 1;
    work->saveData = a->saveData; work->myStatus = a->myStatus; work->optionsSave = a->optionsSave;
    work->bagCursor = a->bagCursor; work->bag = a->bag;
    work->actionPermissions = a->actionPermissions;
    work->bagMode = a->bagMode; work->bagFilter = a->bagFilter;
    func_0200816C(work->bag, work->bagFilter);
    work->currentPocket = func_02008284(work->bagCursor);
    for (i = 0; i < 5; i++) {
        int n;
        func_02008270(work->bagCursor, i, &scr, &cur);
        n = (u16)func_02007FA0(work->bag, i);
        for (;;) {
            if (scr == 0 && cur == 0) break;
            if (cur + 5 >= n && cur != 0) { cur--; continue; }
            if (scr + cur < n) break;
            if (cur != 0) cur--; else scr--;
        }
        if (i == work->currentPocket) { work->cursorRow = scr; work->scrollOffset = cur - 1; }
        func_02008288(work->bagCursor, i, scr, cur);
    }
    work->msgBank = func_02045B38(0, 2, 3, work->heapId);
    work->tempString = func_020457B0(0xc8, work->heapId);
    work->messageString = func_020457B0(0xc8, work->heapId);
    work->listStrings = func_020457B0(0x40, work->heapId);
    work->wordSet = func_0201EC64(work->heapId);
    work->printSys = func_0201C450(0x40 << 6, work->heapId);
    work->itemDescWindow = func_02028590(0xf, 1, 1, work->heapId);
    work->menuTaskArg = func_0201D7EC(0x17, 0, 0, 0, work->heapId);
    func_021B9280(work);
    func_021B9BDC(work);
    func_021B9EF4(work);
    func_021BA8C0(work);
    func_021B6120(work);
    func_021BA028(work);
    work->taskSys = func_02051B84(d_021BBA04, func_021B83B8, work, work->heapId);
    func_021B8B24(work);
    func_021B8E48(work);
    work->unitList = func_020056A0(func_021B8600, work, 0);
    work->touchTask = func_0203101C(work->heapId, work->heapId, 1, 0);
    func_021BAE98(work);
    work->taskMenuState = func_02027F60(3, 9, work->menuTaskArg, work->printSys, work->heapId);
    func_0203D34C(1, work->heapId);
    func_021B80C4(work, func_020355C4() ? 0 : 1);
    func_021B913C();
    func_021B6100(work, func_021B8640);
    return 1;
}


int func_021B8904(int a, int b, int c, ItemMenuWork *work)
{
    ItemMenuTaskFn fn = work->taskFn;
    if (fn == 0) {
        func_0202208C(0, 0, 0, 0, 6, 1, work->heapId);
        return 1;
    }
    work->shownItemId = work->scrollOffset;
    fn(work);
    if (work->listDirty != 0) {
        func_021BA41C(work);
        work->listDirty = 0;
    }
    if (work->busyCount != 0) {
        func_021BA4A4(work);
        work->busyCount = 0;
    }
    func_021B9ED8(work);
    func_021BB73C(work);
    func_020310C4((struct Tcbl *)(work->touchTask));
    return 0;
}








int func_021B8990(void *proc, int b, Parent *par, ItemMenuWork *work)
{
    if (func_020221A4() != 1)
        return 0;
    if (func_0201C6B4((const struct PrintSys *)work->printSys) == 0)
        return 0;
    func_02030EAC((struct Node *)work->unitList);
    func_02008298(work->bagCursor, work->currentPocket);
    func_02008288(work->bagCursor, (u16)work->currentPocket, work->cursorRow, work->scrollOffset + 1);
    func_02027FD8((struct TaskMenuState *)(u32)work->taskMenuState);
    func_021B9AF8(work);
    func_021B9758(work);
    func_02031140((struct S02031140 *)(u32)work->touchTask);
    func_02045C04((struct Rec *)(u32)work->msgBank);
    func_02045808(work->tempString);
    func_02045808(work->messageString);
    func_02045808(work->listStrings);
    func_0201ED04(work->wordSet);
    func_021BAF10(work);
    if ((u32)work->messageWindows[0].window != 0) {
        func_0203FB44((int)3, (unsigned short)work->keyRepeatPacked, (unsigned short)(work->keyRepeatPacked >> 16));
        func_020452E8((struct Descriptor *)(u32)work->messageWindows[0].window);
    }
    func_02040DA8(3, 1, 0);
    func_0201D83C((void *)work->menuTaskArg);
    func_02028604(work->itemDescWindow);
    func_0201C6EC(work->printSys);
    func_0201C4C0(work->printSys);
    func_021B8E84(work);
    func_021B8B6C(work);
    func_02051C6C((void *)(u32)work->taskSys);
    func_020450C8();
    func_0203F9B4();
    par->f34 = (u32)work->nextState;
    par->f38 = work->selectedItemId;
    KEY_SetRepeatSpeed(work->keyRepeatDelay, work->keyRepeatInterval);
    func_020315D4(proc);
    func_020306F0(0xE);
    return 1;
}







void func_021B8AF4(ItemMenuWork *work)
{
    func_021B6100(work, func_021B7250);
    KEY_SetRepeatSpeed(3, 6);
}







int func_021B8B0C(ItemMenuWork *work)
{
    func_021B6100(work, func_021B66FC);
    return KEY_SetRepeatSpeed(3, 6);
}








void func_021B8B24(ItemMenuWork *work)
{
    void *h;
    *(struct BlinkPalAnm * *)&work->blinkPalAnm =
        BLINK_PALANM_Create(0x10, 0x10, 0xFFFE, work->heapId);
    h = func_020490F4(0x58, work->heapId);
    BLINK_PALANM_LoadPalettes(*(struct BlinkPalAnm * *)&work->blinkPalAnm, h, 0x15, 0x10, 0x20);
    func_02049238(h);
}







void func_021B8B6C(ItemMenuWork *work)
{
    func_0202EA20(*(struct BlinkPalAnm * *)&work->blinkPalAnm);
}








void func_021B8B7C(ItemMenuWork *work)
{
    switch (work->fadeStep) {
    case 0:
        func_020061E4(0x54C);
    case 3:
        func_021BB398(work, 0);
        work->fadeStep += 1;
        return;
    case 1:
    case 4:
    case 6:
        work->fadeTimer += 1;
        if (work->fadeTimer == 4) {
            work->fadeTimer = 0;
            work->fadeStep += 1;
        }
        return;
    case 2:
    case 5:
        func_021BB398(work, 2);
        work->fadeStep += 1;
        return;
    case 7:
        work->fadeStep = 0;
        func_021BB398(work, 1);
        BLINK_PALANM_ResetPhase(work->blinkPalAnm);
        BLINK_PALANM_Update(work->blinkPalAnm);
        func_021B6100(work, func_021B7128);
        return;
    }
}








void func_021B8C1C(ItemMenuWork *work, int a, ItemMenuTaskFn callback)
{
    int x;
    if (a == 4) {
        func_020061E4(0x551);
        x = 9;
    } else if (a == 3) {
        func_020061E4(0x556);
        x = 8;
    } else if (a == 1) {
        func_020061E4(0x7D9);
        x = 0xD;
    } else if (a == 0) {
        func_020061E4(0x7D9);
        x = 0xC;
    }
    work->fadeStep = a;
    CLACT_SetActorAnimFrame(work->sideActor[work->fadeStep], 0);
    func_0204B878(work->sideActor[work->fadeStep], (unsigned short)x);
    func_0204B92C(work->sideActor[work->fadeStep], 1);
    work->fadeCallback = callback;
    func_021B6100(work, func_021B8CB4);
}







void func_021B8CB4(ItemMenuWork *work)
{
    if (func_0204B98C(work->sideActor[work->fadeStep]) == 0) {
        work->fadeStep = 0;
        func_021B6100(work, work->fadeCallback);
    }
}








void func_021B8CE4(ItemMenuWork *work, int u, int a, ItemMenuTaskFn callback)
{
    int x;
    func_021B6288(work, u, work->currentPocket);
    func_021B80BC(work);
    func_021B81F4(work);
    work->shownItemId = 0xFFFF;
    func_021B6138(work);
    if (a == 1) {
        func_020061E4(0x7D9);
        x = 0xD;
    } else if (a == 0) {
        func_020061E4(0x7D9);
        x = 0xC;
    }
    work->fadeStep = a;
    work->fadeTimer = 6;
    CLACT_SetActorAnimFrame(work->sideActor[work->fadeStep], 0);
    func_0204B878(work->sideActor[work->fadeStep], (unsigned short)x);
    func_0204B92C(work->sideActor[work->fadeStep], 1);
    work->fadeCallback = callback;
    func_021B6100(work, func_021B8D88);
}







void func_021B8D88(ItemMenuWork *work)
{
    if (work->fadeTimer == 0) {
        work->fadeStep = 0;
        func_021B6100(work, work->fadeCallback);
    } else {
        work->fadeTimer -= 1;
    }
}







/*
 * Return-observed exception: 02035C08's legacy definition says void,
 * but the original retains its r0 result in r4 and returns it.
 */
int func_021B8DAC(void)
{
    int result;
    result = func_02035C08(d_021BB978);
    if (result != -1)
        func_020355D8(1);
    return result;
}







void func_021B8DCC(ItemMenuWork *work)
{
    int flag;
    func_021B7DD0(work);
    func_0204B92C(work->cursorActor, 1);
    func_021BB3F4(work, 1);
    flag = 1;
    if (func_020355C4())
        flag = 0;
    func_021B80C4(work, flag);
    func_021B8AF4(work);
}








void func_021B8E08(ItemMenuWork *work)
{
    int f;
    func_021B7DD0(work);
    func_0204B92C(work->cursorActor, 1);
    func_021BB3F4(work, 1);
    f = 1;
    if (func_020355C4()) {
        f = 0;
    }
    func_021B80C4(work, f);
    func_021B6100(work, func_021B7CD0);
}







void func_021B8E48(ItemMenuWork *work)
{
    work->palAnmSlot = func_02021518(work->heapId);
    func_0202155C(work->palAnmSlot, 2, 0x200, work->heapId);
    func_0202155C(work->palAnmSlot, 0, 0x20, work->heapId);
    func_020216D4(work->palAnmSlot, 0, 0, 0x20);
}







/*
 * 02021540 forwards r0 to the allocator's free; name the pointer here
 * despite its legacy ARM9 thunk definition omitting that argument.
 */
void func_021B8E84(ItemMenuWork *work)
{
    func_020215A0(work->palAnmSlot, 0);
    func_020215A0(work->palAnmSlot, 2);
    func_02021540(work->palAnmSlot);
}








void func_021B8EA8(ItemMenuWork *work)
{
    if (func_0204B98C(work->inputGuard) == 0) {
        func_0204B878(work->inputGuard, 0);
        func_021B809C(work);
        func_0204B92C(work->cursorActor, 0);
        func_02045CAC(work->msgBank, 0x8A, work->messageString);
        func_021BACF0(work, 0);
        func_021BB580(work, 0);
        func_021BB3F4(work, 0);
        func_021B6100(work, func_021B8F0C);
    }
}








void func_021B8F0C(ItemMenuWork *work)
{
    if (func_020362DC() & 3) {
        func_021B80C4(work, 1);
    } else if (func_02035C60()) {
        func_021B80C4(work, 0);
    } else {
        return;
    }
    work->shownItemId = 0xFFFF;
    func_021B6138(work);
    func_021BA9AC(work);
    func_0204B92C(work->cursorActor, 1);
    func_021BB3F4(work, 1);
    func_021B8AF4(work);
}







int func_021B8F68(ItemMenuWork *work, int value)
{
    if (work->bagMode == 3 || work->bagMode == 1)
        return 0;
    if (func_02012B70((const struct BigObj *)(work->saveData)) == 1 && value == 4)
        return 0;
    return 1;
}








/*
 * Unlabelled tail-call stub (00 4b 18 47 + pool word) after func_021B8F68;
 * installed as a callback by func_021B7250 and at 0x021B85E0.
 */
void func_021B8F90(ItemMenuWork *work)
{
    func_021B8AF4(work);
}








static inline void GX_SetDispSelect(GXDispSelect sel)
{
    reg_GX_POWCNT = (u16)((reg_GX_POWCNT & ~REG_GX_POWCNT_DSEL_MASK) |
                          (sel << REG_GX_POWCNT_DSEL_SHIFT));
}








/*
 * BG setup: GX_SetDispSelect(0), then seven 32-byte BG templates copied
 * to the stack and handed to func_0203FCA0 for BGs 0-6, each followed by
 * its clear/enable calls.
 *
 * volatile: 0x04000304 (POWCNT1, read-modify-write at 0x021B8FA0/0x021B8FA8)
 */
void func_021B8F98(void)
{
    BgTemplate t0;
    BgTemplate t1;
    BgTemplate t2;
    BgTemplate t3;
    BgTemplate t4;
    BgTemplate t5;
    BgTemplate t6;

    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);

    t0 = d_021BBB40;
    func_0203FCA0(0, &t0, 0);
    func_020414AC(0);
    func_020409B4(0);
    func_02040588(0, 0);

    t1 = d_021BBB60;
    func_0203FCA0(1, &t1, 0);
    func_020414AC(1);
    func_020409B4(1);
    func_02040588(1, 0);

    t2 = d_021BBB80;
    func_0203FCA0(2, &t2, 0);
    func_020414AC(2);
    func_020409B4(2);
    func_02040588(2, 0);

    t3 = d_021BBB20;
    func_0203FCA0(3, &t3, 0);
    func_02040C14(3, 0, 1, 0);
    func_020414AC(3);
    func_020409B4(3);
    func_02040588(3, 0);

    t4 = d_021BBAC0;
    func_0203FCA0(4, &t4, 0);
    func_02040588(4, 0);
    func_020409B4(4);

    t5 = d_021BBAE0;
    func_0203FCA0(5, &t5, 0);
    func_02040588(5, 0);

    t6 = d_021BBB00;
    func_0203FCA0(6, &t6, 0);
    func_02040588(6, 0);
    func_02040C14(6, 0, 1, 0);
    func_020414EC(6);
}







void func_021B913C(void)
{
    func_02040588(0, 1);
    func_02040588(1, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_02040588(6, 1);
}






void func_021B9178(ItemMenuWork *work, int bg)
{
    int a, b, c, t;
    int r = func_02008550((const struct Sub0200852CObj *)(work->myStatus));
    if (r == 0) {
        a = 4;
        b = 3;
        c = 5;
    } else if (r == 1) {
        a = 1;
        b = 0;
        c = 2;
    }
    func_02049B68((void *)bg, a, 0, 0, 0x20, work->heapId);
    t = func_02049740((void *)bg, b, 0, 0, 0, work->heapId);
    work->frameCounter = t;
    func_02049990((void *)bg, c, 0, 0, (unsigned short)t, 0, 0, work->heapId);
}









void func_021B91FC(ItemMenuWork *work, void *bg)
{
    int a, b, c, d;
    int r = func_02008550((const struct Sub0200852CObj *)(work->myStatus));
    if (r == 0) {
        a = 0x10;
        b = 0xf;
        c = 0xe;
        d = 0xd;
    } else if (r == 1) {
        a = 0xc;
        b = 0xb;
        c = 0xa;
        d = 9;
    }
    work->tabCharRes = func_0204AC18((void *)bg, a, 0, 0xc0, 0, 4, work->heapId);
    work->tabPaletteRes = func_0204A6C8((void *)bg, b, 0, 0, work->heapId);
    work->tabCellRes = func_0204AF28((void *)bg, c, d, work->heapId);
}









static inline void LoadIcons(ItemMenuWork *work)
{
    void *a;
    u32 m;
    u32 i;

    a = func_020490F4(func_020275E4(), work->heapId);
    work->cursorCharRes2 = func_0204AC18(a, func_020275E8(), 1, 0x80, 0, 3, work->heapId);
    m = func_020275FC(2);
    work->cursorPaletteRes2 = func_0204AF28(a, m, func_02027600(2), work->heapId);
    for (i = 0; i < 3; i++)
        work->slotCharRes[i] = func_0204A6C8(a, func_02027610((u8)i), 0, 1, work->heapId);
    for (i = 0; i < 17; i++)
        work->typeIconRes[i] = func_0204A6C8(a, func_020275F8((u8)i), 0, 1, work->heapId);
    func_02049238(a);
}









void func_021B9280(ItemMenuWork *work)
{
    Tbl16 t;
    Rect r2;
    Rect r1;
    Rect r0;
    void *h;
    u32 v;
    u32 i;

    *(volatile u16 *)0x04000050 = 0;
    func_0203F8F4(work->heapId);
    func_02045088(work->heapId);
    func_0201DD60();
    func_020433E0((const struct DispVram *)d_021BBBE0);
    func_0204A48C((const struct Cfg *)d_021BBA8C, (u32)d_021BBBE0, work->heapId);
    t = d_021BBAB0;
    func_0203FC28((struct DispConfig *)(&t));
    func_02043534(0);
    func_020435F4(0);
    func_021B8F98();
    func_0201DD68();
    work->keyRepeatPacked = (u32)func_0201F5DC((void *)3, 13, 0, work->heapId);
    h = func_020490F4(0x58, work->heapId);
    func_02049B68(h, 8, 4, 0, 0, work->heapId);
    if (func_02008550((const struct Sub0200852CObj *)(work->myStatus)) == 0)
        func_02049BDC(h, 8, 4, 0x20, 0, 0x20, work->heapId);
    v = func_02049740(h, 6, 4, 0, 0, work->heapId);
    work->bgPaletteA = v;
    func_02049990(h, 7, 4, 0, (u16)v, 0, 0, work->heapId);
    func_021B9178(work, (int)h);
    v = func_02049740(h, 0x11, 5, 0, 0, work->heapId);
    work->bgPaletteB = v;
    func_02049990(h, 0x17, 5, 0, (u16)v, 0, 0, work->heapId);
    func_021B91FC(work, h);
    work->bgPaletteD = func_02049740(h, 0x21, 3, 0, 0, work->heapId);
    func_02049B68(h, 0x22, 0, 0x60, 0x20, work->heapId);
    func_02049238(h);
    func_02049B40(0x17, 5, 0, 0x180, 0x20, work->heapId);
    work->clactSys = func_0204B100(0x34, 0, work->heapId);
    func_02043598(0x10, 1);
    func_020434DC(0x10, 1);
    h = func_020490F4(0x53, work->heapId);
    func_02049B68(h, 0x1B, 0, 0x100, 0x20, work->heapId);
    v = func_02049740(h, 0x1C, 1, 0, 0, work->heapId);
    work->bgPaletteC = v;
    func_02049990(h, 0x1D, 1, 0, (u16)v + 0x8000, 0, 0, work->heapId);
    func_020409B4(1);
    work->iconCharRes = func_0204AC18(h, 0x13, 0, 0x140, 0, 3, work->heapId);
    work->iconPaletteRes = func_0204A6C8(h, 0x14, 0, 0, work->heapId);
    work->iconCellRes = func_0204AF28(h, 0x17, 0x1A, work->heapId);
    func_02049238(h);
    func_021BA6F4(work);
    LoadIcons(work);
    r2.x = 0x50;
    r2.y = 0xB8;
    r2.a = 1;
    r2.b = 1;
    r2.z = 0;
    for (i = 0; i < 3; i++) {
        work->damageClassActors[i] = func_0204B294(work->clactSys, work->slotCharRes[i], work->cursorCharRes2, work->cursorPaletteRes2, &r2, 1, work->heapId);
        func_0204B6F4(work->damageClassActors[i], func_02027604((u8)i), 1);
        func_0204B3DC(work->damageClassActors[i], 0);
    }
    r1.x = 0x52;
    r1.y = 0xA5;
    r1.a = 1;
    r1.b = 1;
    r1.z = 0;
    for (i = 0; i < 17; i++) {
        work->typeActors[i] = func_0204B294(work->clactSys, work->typeIconRes[i], work->cursorCharRes2, work->cursorPaletteRes2, &r1, 1, work->heapId);
        func_0204B6F4(work->typeActors[i], func_020275EC((u8)i), 1);
        func_0204B3DC(work->typeActors[i], 0);
    }
    h = func_020490F4(0x58, work->heapId);
    work->cursorCharRes = func_0204AC18(h, 0x27, 0, 0x80, 0, 2, work->heapId);
    work->cursorPaletteRes = func_0204A6C8(h, 0x26, 0, 0, work->heapId);
    work->cursorCellRes = func_0204AF28(h, 0x25, 0x24, work->heapId);
    func_02049238(h);
    r0.a = 10;
    r0.b = 1;
    r0.x = 0x92;
    r0.y = 0xB0;
    r0.z = 0;
    work->inputGuard = func_0204B294(work->clactSys, work->cursorPaletteRes, work->cursorCharRes, work->cursorCellRes, &r0, 0, work->heapId);
    func_0204B92C(work->inputGuard, 1);
    func_0204B3DC((work->inputGuard), 1);
    func_021BB5A4(work);
}









void func_021B9758(ItemMenuWork *work)
{
    unsigned v;
    v = work->bgPaletteA;
    func_0203FB44((int)4, (unsigned short)v, (unsigned short)(v >> 16));
    v = work->bgPaletteB;
    func_0203FB44((int)5, (unsigned short)v, (unsigned short)(v >> 16));
    v = work->bgPaletteD;
    func_0203FB44((int)3, (unsigned short)v, (unsigned short)(v >> 16));
    v = (unsigned int)work->frameCounter;
    func_0203FB44((int)0, (unsigned short)v, (unsigned short)(v >> 16));
    v = work->bgPaletteC;
    func_0203FB44((int)1, (unsigned short)v, (unsigned short)(v >> 16));
}








void func_021B97CC(void *p, int v) { func_02040588(5, v); func_02040588(6, v); }







/*
 * blocked: WAZA_TOOL_GetDamageType (arm9 unlabelled leaf, the integrator's; 12 bytes, tail stub)
 * has no witness outside this function. Verified C for the leaf (EXACT,
 * thumb, arm9, no region):
 *   extern int func_0201BD28(int, int);   // symbols: func_0201BD28 0x0201BD28 thumb
 *   int WAZA_TOOL_GetDamageType(int a) { return func_0201BD28(a, 2); }
 */
void func_021B97E8(ItemMenuWork *work, int mode)
{
    int r;
    if (mode == 1) {
        work->screenState = 1;
    } else {
        work->screenState = 2;
    }
    if (work->movingCursorActor != 0) {
        func_0204B3DC(work->movingCursorActor, mode);
    }
    r = func_020212B0(func_021B616C(work, func_021B61B8(work))->itemId);
    if (r != 0) {
        func_0204B3DC(work->damageClassActors[WAZA_TOOL_GetDamageType(r)], mode);
        func_0204B3DC(work->typeActors[WAZA_TOOL_GetType((void *)r)], mode);
    }
}








void func_021B9850(ItemMenuWork *work)
{
    u32 i;
    u32 j;
    u16 *e;
    u16 kind;
    u8 n;

    j = 0;
    for (i = 0; i < 3; i++)
        func_0204B3DC(work->damageClassActors[i], 0);
    for (j = 0; j < 17; j++)
        func_0204B3DC(work->typeActors[j], 0);
    e = (void *)func_021B616C(work, func_021B61B8(work));
    if (e == 0 || *e == 0) {
        func_021B97E8(work, 0);
        return;
    }
    func_021B97E8(work, 1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT].window)), 0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window)), 0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_DESC].window)), 0);
    kind = func_020212B0(*e);
    if (kind == 0) {
        func_02045CAC(work->msgBank, 0x86, work->tempString);
        func_021B61F4(work, 0, *e);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021BB6E0(work, (u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT].window, work->messageString, 0, (s16_021BB6E0)4, 0x3DC0);
        if (work->currentPocket != 4) {
            func_02045CAC(work->msgBank, 0x83, work->tempString);
            func_0201EFA4(work->wordSet, 0, e[1], 3, 0, 1);
            func_0201F250(work->wordSet, work->messageString, work->tempString);
            func_021BB6E0(work, (u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window, work->messageString, 0, (s16_021BB6E0)4, 0x3DC0);
        } else {
            func_02045334((struct Descriptor *)work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window);
        }
        func_020456F8((struct Descriptor *)(*(u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window));
    } else {
        n = func_02021350(*e);
        if (n == 0xFF) {
            func_02045CAC(work->msgBank, 0x45, work->tempString);
            func_0201EFA4(work->wordSet, 0, func_0202130C(*e) + 1, 2, 2, 1);
        } else {
            func_02045CAC(work->msgBank, 0x47, work->tempString);
            func_0201EFA4(work->wordSet, 0, n + 1, 2, 2, 1);
        }
        func_0201EF34(work->wordSet, 1, kind);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021BB6E0(work, (u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT].window, work->messageString, 0, (s16_021BB6E0)4, 0x3DC0);
        func_021BAB04(work, kind);
        func_02045334((struct Descriptor *)work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window);
    }
    func_02020FB4(work->tempString, *e, work->heapId);
    func_021BB6E0(work, (u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_DESC].window, work->tempString, 0, (s16_021BB6E0)4, 0x3DC0);
    func_021BB724((void **)&work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT].window);
    func_021BB724((void **)&work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window);
    func_021BB724((void **)&work->listWindows[ITEMMENU_WINDOW_ITEM_DESC].window);
    func_021B9E14(work, *e);
}









void func_021B9AAC(ItemMenuWork *work)
{
    unsigned i;
    unsigned j;
    func_021B97E8(work, 0);
    func_020456F8((struct Descriptor *)(work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window));
    for (i = 0; i < 3; i++) {
        func_0204B3DC(work->damageClassActors[i], 0);
    }
    for (j = 0; j < 0x11; j++) {
        func_0204B3DC(work->typeActors[j], 0);
    }
}









void func_021B9AF8(ItemMenuWork *work)
{
    int i;
    func_020452E8((struct Descriptor *)(work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT].window));
    func_020452E8((struct Descriptor *)(work->listWindows[ITEMMENU_WINDOW_ITEM_DESC].window));
    func_020452E8((struct Descriptor *)(work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window));
    func_020452E8((struct Descriptor *)(work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window));
    func_020452E8((struct Descriptor *)(work->listWindows[ITEMMENU_WINDOW_MENU_0].window));
    func_020452E8((struct Descriptor *)(work->listWindows[ITEMMENU_WINDOW_MENU_3].window));
    func_020452E8((struct Descriptor *)(work->listWindows[ITEMMENU_WINDOW_MENU_4].window));
    func_0204B3B4(work->cursorActor);
    if (work->movingCursorActor != 0) {
        func_0204B3B4(work->movingCursorActor);
        func_0204A8D4(work->cellAnimRes);
        func_0204ADA4(work->cellRes);
    }
    func_0204AFD8(work->cellTransRes);
    for (i = 0; i < 8; i++) {
        func_020437AC((struct Bmp *)(*(int *)&work->slotBitmap[i]));
    }
    func_0204B1CC(work->clactSys);
    func_0204A5AC();
}








void func_021B9BA0(ItemMenuWork *work) { func_02045CAC(work->msgBank, 0x87, work->tempString); func_021BB6E0(work, (unsigned *)&work->listWindows[ITEMMENU_WINDOW_MENU_4].window, work->tempString, 0, (s16_021BB6E0)4, 0x3DC0); }









void func_021B9BDC(ItemMenuWork *work)
{
    void *bg;

    work->listWindows[ITEMMENU_WINDOW_MENU_4].window = func_020450F0(3, 0x12, 9, 0xc, 3, 3, 1);
    func_021B9BA0(work);
    func_020456F8((struct Descriptor *)(work->listWindows[ITEMMENU_WINDOW_MENU_4].window));
    work->listWindows[ITEMMENU_WINDOW_MENU_0].window = func_020450F0(3, 0x11, 0xd, 0xb, 2, 3, 1);
    work->listWindows[ITEMMENU_WINDOW_MENU_3].window = func_020450F0(3, 0x11, 0xf, 0xb, 2, 3, 1);
    work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window = func_020450F0(6, 0, 0x13, 0x20, 5, 0, 1);
    work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT].window = func_020450F0(6, 7, 5, 0x12, 3, 0, 1);
    *(int *)&work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window = func_020450F0(6, 0x14, 8, 6, 3, 0, 1);
    work->listWindows[ITEMMENU_WINDOW_ITEM_DESC].window = func_020450F0(6, 2, 0xc, 0x1d, 7, 0, 1);
    func_02045374((struct Cfg *)(work->listWindows[ITEMMENU_WINDOW_ITEM_COUNT].window));
    func_02045374((struct Cfg *)(*(int *)&work->listWindows[ITEMMENU_WINDOW_ITEM_PRICE].window));
    func_02045374((struct Cfg *)(work->listWindows[ITEMMENU_WINDOW_ITEM_DESC].window));
    func_02045374((struct Cfg *)(work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window));
    bg = func_020490F4(0x19, work->heapId);
    work->cellTransRes = func_0204AF28(bg, 1, 0, work->heapId);
    func_02049238(bg);
    func_02045CAC(work->msgBank, 0x66, work->tempString);
    func_021BB6E0(work, (u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window, work->tempString, 8, (s16_021BB6E0)4, 0x3DC0);
    func_02045CAC(work->msgBank, 0x5d, work->tempString);
    func_021BB6E0(work, (u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window, work->tempString, 8, (s16_021BB6E0)0x18, 0x3DC0);
    func_02045CAC(work->msgBank, 0x5b, work->tempString);
    func_021BB6E0(work, (u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window, work->tempString, 0x70, (s16_021BB6E0)4, 0x3DC0);
    func_02045CAC(work->msgBank, 0x5c, work->tempString);
    func_021BB6E0(work, (u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window, work->tempString, 0x70, (s16_021BB6E0)0x18, 0x3DC0);
    func_02045CAC(work->msgBank, 0x5a, work->tempString);
    func_021BB6E0(work, (u32 *)&work->listWindows[ITEMMENU_WINDOW_ITEM_NAME].window, work->tempString, 0xd0, (s16_021BB6E0)4, 0x3DC0);
    if (func_020355C4() == 0) {
        func_021B9850(work);
    }
}








void func_021B9DE8(ItemMenuWork *work) { if (work->movingCursorActor) { func_0204B3B4(work->movingCursorActor); func_0204A8D4(work->cellAnimRes); func_0204ADA4(work->cellRes); *(void * *)&work->movingCursorActor = 0; } }









void func_021B9E14(ItemMenuWork *work, int id)
{
    void *bg;
    Rect_021B9850 r;
    if (work->movingCursorActor != 0) {
        func_021B9DE8(work);
    }
    bg = func_020490F4(0x19, work->heapId);
    work->cellRes = func_0204AC18(bg, func_02020E60(id, 2), 1, 0, 0, 1, work->heapId);
    work->cellAnimRes = func_0204A6C8(bg, func_02020E60(id, 1), 0, 1, work->heapId);
    func_02049238(bg);
    r.a = 0x84;
    r.b = 0x50;
    r.c = 0;
    r.d = 0;
    r.e = 0;
    work->movingCursorActor = func_0204B294(work->clactSys, work->cellAnimRes, work->cellRes, work->cellTransRes, &r, 1, work->heapId);
    func_0204B92C(work->movingCursorActor, 1);
    func_0204B3DC(work->movingCursorActor, 1);
}








void func_021B9ED8(ItemMenuWork *work) { func_0204A600(); if (work->menuList) func_02027974(work->menuList); }








/*
 * lever:    the loop's array slots are spelled `p + i * 4 + 0x614` (index
 *           before offset), which keeps `p + i*4` in one register across both
 *           calls; `p + 0x614 + i * 4` and `((int *)(p + 0x614))[i]` both DIFF.
 */
void func_021B9EF4(ItemMenuWork *work)
{
    /* Byte view of the work area: the slot arrays below stay spelled
     * p + i * 4 + offset, because the array form does not share the base. */
    char *p = (char *)work;
    void *bg;
    int i;

    bg = func_020490F4(0x58, work->heapId);
    work->pocketCharRes = func_0204AC18(bg, 0x20, 0, 0x1a0, 0, 1, work->heapId);
    work->pocketPaletteRes = func_0204A6C8(bg, 0x1f, 0, 0, work->heapId);
    work->pocketCellRes = func_0204AF28(bg, 0x1e, 0x1d, work->heapId);
    work->bagCharRes = func_0204AC18(bg, 0x1c, 0, 0x60, 0, 1, work->heapId);
    work->bagPaletteRes = func_0204A6C8(bg, 0x1b, 0, 0, work->heapId);
    work->bagCellRes = func_0204AF28(bg, 0x1a, 0x19, work->heapId);
    for (i = 0; i < 8; i++) {
        *(int *)(p + i * 4 + 0x614) = (int)func_02043678(0xc, 2, 0x20, work->heapId);
        *(int *)(p + i * 4 + 0x5F4) =func_0204A6C8(bg, 0x14, 0, 0, work->heapId);
    }
    func_02008550((const struct Sub0200852CObj *)(work->myStatus));
    work->barCharRes = func_0204AC18(bg, 0x15, 0, 0, 0, 3, work->heapId);
    work->bagAnimRes = func_0204AF28(bg, 0x13, 0x12, work->heapId);
    func_02049238(bg);
}








void func_021BA028(ItemMenuWork *work)
{
    /* Byte view of the work area: the slot arrays below stay spelled
     * p + i * 4 + offset, because the array form does not share the base. */
    char *p = (char *)work;
    Rect_021B9EF4 r1;
    Rect_021B9EF4 r2;
    Rect_021B9EF4 r3;
    int i;

    r1.a = 0xf8;
    r1.b = 0x1a;
    r1.d = 1;
    r1.e = 2;
    r1.c = 0;
    work->cursorActor = func_0204B294(work->clactSys, work->bagPaletteRes, work->bagCharRes, work->bagCellRes, &r1, 0, work->heapId);
    func_0204B3DC(work->cursorActor, 1);
    func_0204B92C(work->cursorActor, 1);
    func_021BA6A4(work);
    r2.a = 0x8c;
    r2.b = 0x30;
    r2.d = 1;
    r2.e = 2;
    r2.c = 1;
    work->selectorActor = func_0204B294(work->clactSys, work->bagPaletteRes, work->bagCharRes, work->bagCellRes, &r2, 0, work->heapId);
    func_0204B3DC(work->selectorActor, 1);
    func_0204B92C(work->selectorActor, 1);
    for (i = 0; i < 8; i++) {
        r3.a = 0x8c;
        r3.b = i * 0x18;
        r3.d = 0xa;
        r3.e = 3;
        r3.c = 0;
        *(struct Actor **)(p + i * 4 + 0x634) = func_0204B294(work->clactSys, *(int *)(p + i * 4 + 0x5F4), work->barCharRes, work->bagAnimRes, &r3, 0, work->heapId);
        r3.a -= 0x18;
        r3.c = 1;
        *(struct Actor **)(p + i * 4 + 0x674) = func_0204B294(work->clactSys, work->pocketPaletteRes, work->pocketCharRes, work->pocketCellRes, &r3, 0, work->heapId);
        func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x634), 0);
        func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x674), 0);
    }
}




int func_021BA1D0(u16 x)
{
    if (func_02021288(x) == 1) {
        switch (func_020212B0(x)) {
        case 0xF:
        case 0x13:
        case 0x39:
        case 0x46:
        case 0x7F:
        case 0x123:
            return 1;
        }
    }
    return 0;
}









void func_021BA218(ItemMenuWork *work)
{
    int h;
    int i;
    int idx;
    u16 *e;
    int rec;
    u32 kind;
    u16 color;
    u16 r;
    u32 w;

    if (func_021B61C8(work) == 0) {
        func_021BB724((void **)&work->listWindows[ITEMMENU_WINDOW_MENU_4].window);
    } else {
        w = (unsigned int)work->listWindows[ITEMMENU_WINDOW_MENU_4].window;
        func_020456F8((struct Descriptor *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
    }
    if (work->shownItemId == work->scrollOffset) {
        return;
    }
    h = (int)func_02020F14(work->heapId);
    for (i = 0; i < 8; i++) {
        work->slotAnimIndex[i] = 0;
        idx = work->scrollOffset + i;
        if (idx < 0) {
            continue;
        }
        e = (void *)func_021B616C(work, idx);
        if (e == 0 || *e == 0) {
            continue;
        }
        rec = func_02020F20(h, *e, work->heapId);
        kind = func_02021014((struct Rec *)rec, 0xf);
        if (d_021BBA79[i] == 0) {
            if (func_021BA1D0(*e) == 1) {
                color = 0x18AD;
            } else {
                color = 0x82D;
            }
        } else {
            if (func_021BA1D0(*e) == 1) {
                color = 0x20ED;
            } else {
                color = 0x106D;
            }
        }
        func_02043B5C((struct CharBuf *)(work->slotBitmap[i]), 0xd);
        func_02045CAC(work->msgBank, 0x82, work->tempString);
        r = func_020212B0(*e);
        if (r == 0) {
            func_021B61F4(work, 0, *e);
        } else {
            func_0201EF34(work->wordSet, 0, r);
        }
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_0201C7D0((void *)(work->slotBitmap[i]), 0, 0, work->messageString, (void *)(work->menuTaskArg), color);
        if (kind == 4) {
            work->slotAnimIndex[i] = 4;
        } else if (kind == 5) {
            work->slotAnimIndex[i] = 5;
        } else if (kind == 1) {
            work->slotAnimIndex[i] = 6;
        } else if (func_02021350(*e) != 0xff) {
            work->slotAnimIndex[i] = 8;
        } else if (func_0202130C(*e) != 0xff) {
            work->slotAnimIndex[i] = 7;
        } else if (func_02021014((struct Rec *)rec, 4) == 0) {
            work->slotAnimIndex[i] = 3;
        } else if (func_021B83A0(work, *e) == 0) {
            work->slotAnimIndex[i] = 2;
        } else {
            work->slotAnimIndex[i] = 1;
        }
        func_020307B0((void *)rec);
    }
    func_02049238((void *)h);
    work->busyCount = 1;
}










void func_021BA41C(ItemMenuWork *work)
{
    Pt pt;
    func_021BB398(work, 0);
    func_0204B454(work->selectorActor, (struct PtS *)&pt, 0xFFFF);
    pt.b = (work->cursorRow + 1) * 0x18;
    func_0204B404(work->selectorActor, (const struct Vec2 *)(&pt), 0xFFFF);
    if (func_020355C4() == 0) {
        func_021BB398(work, 1);
    }
    BLINK_PALANM_ResetPhase(work->blinkPalAnm);
    func_0204B3DC(work->cursorActor, func_021B61C8(work) >= 7);
    CLACT_SetActorAnimIndex(work->selectorActor, 0);
    CLACT_SetActorAnimIndex(work->cursorActor, 0);
}










void func_021BA4A4(ItemMenuWork *work)
{
    /* Byte view of the work area: the slot arrays below stay spelled
     * p + i * 4 + offset, because the array form does not share the base. */
    char *p = (char *)work;
    int i;
    u8 *src;
    u8 *dst;

    for (i = 0; i < 8; i++) {
        src = (u8 *)func_0204ABBC(*(u32 *)(p + i * 4 + 0x5F4), 0);
        dst = func_020437D4(*(void **)(p + i * 4 + 0x614));
        func_020862F0(dst, func_020437EC(*(void **)(p + i * 4 + 0x614)));
        func_0207E780(dst + 0x100, src + 0x80, 0x80);
        func_0207E780(dst + 0x280, src + 0x100, 0x80);
        func_0207E780(dst, src + 0x300, 0x100);
        func_0207E780(dst + 0x180, src + 0x400, 0x100);
        if (*(u32 *)(p + i * 4 + 0x654) != 0) {
            if (work->currentPocket == 4) {
                if (func_021B811C(work) == 1 && *(u32 *)(p + i * 4 + 0x654) != 3) {
                    func_0204B878(*(struct Actor **)(p + i * 4 + 0x674), *(u32 *)(p + i * 4 + 0x654) - 1);
                    func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x674), 1);
                } else {
                    func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x674), 0);
                }
            } else if (work->currentPocket == 0 && *(u32 *)(p + i * 4 + 0x654) >= 4) {
                func_0204B878(*(struct Actor **)(p + i * 4 + 0x674), *(u32 *)(p + i * 4 + 0x654) - 1);
                func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x674), 1);
            } else if (work->currentPocket == 2 && *(u32 *)(p + i * 4 + 0x654) >= 7) {
                func_0204B878(*(struct Actor **)(p + i * 4 + 0x674), *(u32 *)(p + i * 4 + 0x654) - 1);
                func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x674), 1);
            } else {
                func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x674), 0);
            }
            func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x634), 1);
        } else {
            func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x674), 0);
            func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x634), 0);
        }
    }
}










void func_021BA654(ItemMenuWork *work)
{
    unsigned w;
    unsigned v;
    Pt pt;
    if (TOUCHPANEL_GetPointCont(&w, &v) == 1) {
        if (v < 0x1A) {
            v = 0x1A;
        } else if (v > 0x8E) {
            v = 0x8E;
        }
        func_0204B454(work->cursorActor, (struct PtS *)&pt, 0xFFFF);
        pt.b = v;
        func_0204B404(work->cursorActor, (const struct Vec2 *)(&pt), 0xFFFF);
    }
}










void func_021BA6A4(ItemMenuWork *work)
{
    Pt pt;
    int n = func_021B61C8(work);
    if (n >= 7) {
        func_0204B454(work->cursorActor, (struct PtS *)&pt, 0xFFFF);
        pt.b = func_0202EE0C(n - 6, work->scrollOffset + 1, 0x1A, 0x8E, 0);
        func_0204B404(work->cursorActor, (const struct Vec2 *)(&pt), 0xFFFF);
    }
}









void func_021BA6F4(ItemMenuWork *work)
{
    /* Byte view of the work area: the slot arrays below stay spelled
     * p + i * 4 + offset, because the array form does not share the base. */
    char *p = (char *)work;
    Rect_021BA6F4 r;
    B5 t1;
    B5 t2;
    B2 t3;
    B2 t4;
    u8 i;

    r.d = 0xa;
    r.e = 1;
    t1 = d_021BBAA8;
    t2 = d_021BBA6C;
    for (i = 0; i < 5; i++) {
        r.a = t2.v[i];
        r.b = 0xa8;
        r.c = t1.v[i];
        if (i == 2) {
            r.b += 4;
        }
        *(struct Actor **)(p + i * 4 + 0x710) = func_0204B294(work->clactSys, work->iconPaletteRes, work->iconCharRes, work->iconCellRes, &r, 0, work->heapId);
        func_0204B3DC(*(struct Actor **)(p + i * 4 + 0x710), 1);
    }
    func_0204B92C(work->sideActor[0], 1);
    func_0204B92C(work->sideActor[1], 1);
    if (func_021B811C(work) == 0) {
        func_0204B3DC(work->sideActor[2], 0);
    }
    if (work->bagMode == 2) {
        func_0204B3DC(work->sideActor[3], 0);
    }
    t3 = d_021BBA68;
    t4 = d_021BBA64;
    for (i = 0; i < 2; i++) {
        r.a = 0xe8;
        r.b = t4.v[i];
        r.c = t3.v[i];
        r.e = 0;
        *(struct Actor **)(p + (u8)(i + 5) * 4 + 0x710) = func_0204B294(work->clactSys, work->iconPaletteRes, work->iconCharRes, work->iconCellRes, &r, 0, work->heapId);
        func_0204B92C(*(struct Actor **)(p + (u8)(i + 5) * 4 + 0x710), 1);
        func_0204B3DC(*(struct Actor **)(p + (u8)(i + 5) * 4 + 0x710), 0);
    }
}









/*
 * Creates five sprites from three small tables.  The work area must be a
 * struct with the resource triple as an array (args res[1], res[0], res[2]):
 * the same fields spelled as `*(int *)(p + 0x594)` offsets colour the x/y
 * loads into different registers (23 bytes of DIFF).  The tables stay
 * non-const: a const coordinate table lets its load float above the two
 * record stores.
 * The data symbols are declared without an ovNNN token (the hint is
 * contested for 0x021BBA74 and 0x021BBBCC; sole-ref/data resolves them).
 */
void func_021BA8C0(ItemMenuWork *work)
{
    unsigned i;
    Rect_021BA8C0 r;
    for (i = 0; i < 5; i++) {
        r.d = d_021BBA74[i];
        r.e = 1;
        r.x = d_021BBBCC[i][0] - 0x10;
        r.y = d_021BBBCC[i][1];
        r.z = d_021BBA81[i * 2 + 1];
        work->tabActor[i] = func_0204B294(work->clactSys, work->tabPaletteRes, work->tabCharRes, work->tabCellRes, &r, 0, work->heapId);
        func_0204B92C(work->tabActor[i], 1);
    }
}









void func_021BA96C(ItemMenuWork *work, unsigned sel)
{
    unsigned i;
    for (i = 0; i < 5; i++) {
        if (i == sel) {
            func_0204B878(work->tabActor[i], d_021BBA81[i * 2]);
        } else {
            func_0204B878(work->tabActor[i], d_021BBA81[i * 2 + 1]);
        }
    }
}







void func_021BA9AC(ItemMenuWork *work) { func_0201F7A8((void *)work->messageWindows[0].window, 1); }








void func_021BA9C0(ItemMenuWork *work, int *tbl, int n)
{
    Desc s;
    int i;
    void *r;
    ItemMenuWork *e;

    s.a = work->heapId;
    s.b = n;
    s.c = (int)&work->listEntries[0].text;
    s.d = 1;
    s.e = 0x20;
    s.f = 0x18;
    s.g = 0xD;
    s.h = 3;
    for (i = 0; i < n; i++) {
        /* e is the work area shifted by one row (0xC bytes) per entry, so its
         * listEntries[0] is entry i: the byte address is formed before the
         * row offset, as the array form listEntries[i] does not match. */
        e = (ItemMenuWork *)((char *)work + i * 0xC);
        r = func_020457B0(0x64, work->heapId);
        e->listEntries[0].text = r;
        func_02045CAC(work->msgBank, tbl[i], r);
        e->listEntries[0].color = 0x39E0;
        e->listEntries[0].extra = 0;
    }
    work->listEntries[i - 1].extra = 1;
    work->menuList = func_02027778((struct TaskMenuTmpl *)(&s), (void *)(work->taskMenuState));
    for (i = 0; i < n; i++) {
        func_02045808((struct U16Vec *)(*(int *)&work->listEntries[i].text));
    }
    func_021BB3F4(work, 0);
}






void func_021BAAA4(ItemMenuWork *work, int mode)
{
    void *h = func_020490F4(0x58, work->heapId);

    if (mode != 2) {
        ARC_UTIL_UploadBgPaletteAddFromHandleExt(h, 0x17, 5, 0, (u16)work->bgPaletteB, 0, 0, work->heapId);
    } else {
        ARC_UTIL_UploadBgPaletteAddFromHandleExt(h, 0x18, 5, 0, (u16)work->bgPaletteB, 0, 0, work->heapId);
    }
    func_02049238((void *)((int)h));
}





void func_021BAB04(ItemMenuWork *work, int x)
{
    int a;
    int b;
    int c;
    u32 *win;

    win = &work->listWindows[0].window;

    func_0204B3DC(work->damageClassActors[WAZA_TOOL_GetDamageType((u16)x)], (int)1);
    func_0204B3DC(work->typeActors[WAZA_TOOL_GetType((void *)(u16)x)], (int)1);
    a = (int)WAZA_TOOL_GetMaxPP(x, (int)0);
    b = (int)func_0201BD28(x, (int)3);
    c = (int)func_0201BD28(x, (int)4);
    func_02043AF4(func_02045770((struct Descriptor *)(*win)), 0xB0, 0, 0x20, 0x28, 0);
    func_02043AF4(func_02045770((struct Descriptor *)(*win)), 0xE8, 0, 0x18, 0x18, 0);
    if (b <= 1) {
        func_02045CAC(work->msgBank, (int)0x17, work->tempString);
        func_021BB6E0(work, win, work->tempString, 0xB0, (s16_021BB6E0)4, 0x3DC0);
    } else {
        func_02045CAC(work->msgBank, (int)0x5F, work->tempString);
        func_0201EFA4(work->wordSet, (int)0, (int)b, (int)3, (int)0, (int)1);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021BB6E0(work, win, work->messageString, 0xB0, (s16_021BB6E0)4, 0x3DC0);
    }
    if (c == 0 || (int)WAZA_TOOL_IsAlwaysHit(x) == 1) {
        func_02045CAC(work->msgBank, (int)0x17, work->tempString);
        func_021BB6E0(work, win, work->tempString, 0xB0, (s16_021BB6E0)0x18, 0x3DC0);
    } else {
        func_02045CAC(work->msgBank, (int)0x5F, work->tempString);
        func_0201EFA4(work->wordSet, (int)0, (int)c, (int)3, (int)0, (int)1);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021BB6E0(work, win, work->messageString, 0xB0, (s16_021BB6E0)0x18, 0x3DC0);
    }
    func_02045CAC(work->msgBank, (int)0x5E, work->tempString);
    func_0201EFA4(work->wordSet, (int)0, (int)a, (int)2, (int)0, (int)1);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    func_021BB6E0(work, win, work->messageString, 0xE8, (s16_021BB6E0)4, 0x3DC0);
    func_021BB724((void **)win);
}






/*
 * Creates the window at p+0x4FC on first use, clears it, then either prints
 * through func_0201CCE4 (mode 1) or through func_021BB6E0, and finishes the
 * window. The window address is a named local taken after the clear calls:
 * without it the 0x4FC offset went to r4 and mode to r6, the mode-1 arm
 * consumed the offset register destructively and the join reloaded it
 * (4 bytes short).
 */
void func_021BACF0(ItemMenuWork *work, int mode)
{
    u32 *win;

    if (work->messageWindows[0].window == 0) {
        work->messageWindows[0].window = func_020450F0(3, 1, 1, 0x1E, 4, 0xC, 1);
    }
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)work->messageWindows[0].window)), 0xF);
    func_02045334((struct Descriptor *)work->messageWindows[0].window);
    win = &work->messageWindows[0].window;
    if (mode == 1) {
        work->messageWindow = func_0201CCE4(work->messageWindows[0].window, 0, 0, work->messageString,
                                            work->menuTaskArg, func_02012FFC(),
                                            work->touchTask, 2, work->heapId, 0xF);
    } else {
        func_021BB6E0(work, win, work->messageString, 0, 0, 0x44F);
    }
    func_0201F73C((void *)*win, 1, (u16)work->keyRepeatPacked, 0xD);
    func_021BB724((void **)win);
}





/*
 * Tail call to func_021BACF0(p, 0).
 */
void func_021BADAC(ItemMenuWork *work)
{
    func_021BACF0(work, 0);
}





void func_021BADB8(ItemMenuWork *work, unsigned v) { func_02045CAC(work->msgBank, 0x2B, work->tempString); func_021B61F4(work, 0, v); func_0201F250(work->wordSet, work->messageString, work->tempString); }






int func_021BADF0(ItemMenuWork *work)
{
    int r;

    if (work->messageWindow != 0) {
        r = func_0201CE30((void *)(work->messageWindow));
        func_020286C4((struct Ctx *)(work->itemDescWindow), (void *)(work->messageWindow), (void *)(work->messageWindows[0].window));
        switch (r) {
        case 2:
            func_0201CE48((struct Rec3 *)(work->messageWindow));
            work->messageWindow = 0;
            work->messageWindowOpen = 0;
            break;
        case 1:
            if (work->messageWindowOpen == 0) {
                if ((func_020362DC() & 3) != 0 || func_02035C60() != 0) {
                    func_020061E4(0x547);
                    func_0201CE38((void *)(work->messageWindow));
                    work->messageWindowOpen = 1;
                }
            }
            break;
        case 0:
            if ((func_0203630C() & 3) != 0 || func_02035C38() != 0) {
                func_0201CE5C((struct Rec *)(work->messageWindow), 0);
            }
            work->messageWindowOpen = 0;
            break;
        }
        return 0;
    }
    return 1;
}






void func_021BAE98(ItemMenuWork *work)
{
    work->messageWindows[1].window = func_020450F0(2, 3, 0x15, 0xC, 3, 0xC, 1);
    *(int *)&work->listWindows[ITEMMENU_WINDOW_MENU_1].window = func_020450F0(2, 1, 0x15, 8, 3, 0xC, 1);
    *(int *)&work->listWindows[ITEMMENU_WINDOW_MENU_2].window = func_020450F0(2, 9, 0x15, 9, 3, 0xC, 1);
    func_021BAF38(work, work->currentPocket);
    func_021BA96C(work, work->currentPocket);
}





void func_021BAF10(ItemMenuWork *work) { func_020452E8((struct Descriptor *)work->messageWindows[1].window); func_020452E8((struct Descriptor *)work->listWindows[ITEMMENU_WINDOW_MENU_2].window); func_020452E8((struct Descriptor *)work->listWindows[ITEMMENU_WINDOW_MENU_1].window); }






void func_021BAF38(ItemMenuWork *work, int val)
{
    int r;

    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)work->messageWindows[1].window)), 0);
    func_02045CAC(work->msgBank, 0x8B, work->tempString);
    func_0201F14C(work->wordSet, 0, val);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    r = 0x60 - func_0201D304(work->messageString, work->menuTaskArg, 0);
    func_021BB6E0(work, (u32 *)&work->messageWindows[1].window, work->messageString, (unsigned short)(r >> 1), 4, 0x3C40);
    func_021BB724((void **)&work->messageWindows[1].window);
}





void func_021BAFC4(ItemMenuWork *work)
{
    func_02043B5C(func_02045770((struct Descriptor *)work->listWindows[ITEMMENU_WINDOW_MENU_2].window), 0);
    func_02043B5C(func_02045770((struct Descriptor *)work->listWindows[ITEMMENU_WINDOW_MENU_1].window), 0);
    func_02045CAC(work->msgBank, 0x51, work->tempString);
    func_021BB6E0(work, &work->listWindows[ITEMMENU_WINDOW_MENU_1].window, work->tempString, 0, 4, 0x3C40);
    func_021BB724((void **)&work->listWindows[ITEMMENU_WINDOW_MENU_1].window);
    func_02045CAC(work->msgBank, 0x52, work->tempString);
    func_0201EFA4(work->wordSet, 0, func_0200C274(func_02012F08(work->saveData)), 7, 1, 1);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    func_021BB6E0(work, &work->listWindows[ITEMMENU_WINDOW_MENU_2].window, work->messageString, 0, 4, 0x3C40);
    func_021BB724((void **)&work->listWindows[ITEMMENU_WINDOW_MENU_2].window);
}





void func_021BB08C(ItemMenuWork *work) { func_0204B3DC((work->sideActor[0]), 0); func_0204B3DC((work->sideActor[1]), 0); func_020456F8((struct Descriptor *)work->messageWindows[1].window); func_021BAFC4(work); }





void func_021BB0BC(ItemMenuWork *work) { func_0204B3DC((work->sideActor[0]), 1); func_0204B3DC((work->sideActor[1]), 1); func_020456F8((struct Descriptor *)work->listWindows[ITEMMENU_WINDOW_MENU_2].window); func_020456F8((struct Descriptor *)work->listWindows[ITEMMENU_WINDOW_MENU_1].window); func_021BAF38(work, work->currentPocket); }






void func_021BB0F8(ItemMenuWork *work)
{
    Desc s;
    int h;
    void *r;

    h = work->heapId;
    s.a = h;
    s.b = 2;
    s.c = (int)work->listEntries;
    s.d = 1;
    s.e = 0x20;
    s.f = 0xC;
    s.g = 8;
    s.h = 3;
    r = func_020457B0(0x64, h);
    work->listEntries[0].text = r;
    func_02045CAC(work->msgBank, 0x84, (void *)r);
    work->listEntries[0].color = 0x39E0;
    work->listEntries[0].extra = 0;
    r = func_020457B0(0x64, work->heapId);
    work->listEntries[1].text = r;
    func_02045CAC(work->msgBank, 0x85, (void *)r);
    work->listEntries[1].color = 0x39E0;
    work->listEntries[1].extra = 0;
    work->menuList = func_02027778((struct TaskMenuTmpl *)(&s), (void *)(work->taskMenuState));
    func_02045808((struct U16Vec *)(work->listEntries[0].text));
    func_02045808((struct U16Vec *)(work->listEntries[1].text));
    func_021BB580(work, 0);
    func_021BB3F4(work, 0);
}





void func_021BB1AC(ItemMenuWork *work) { func_02027858(work->menuList); work->menuList = 0; }






void func_021BB1C4(ItemMenuWork *work)
{
    void *arc;
    int tex;
    Img *img;
    int i;
    u16 *d;
    int n;

    arc = func_020490F4(0x58, work->heapId);
    tex = (int)func_0204A380(arc, 0x23, 0, work->heapId);
    i = 0;
    if (func_02062B30((void *)tex, (void **)(&img))) {
        d = img->d;
        n = ((unsigned)img->w >> 3) * ((unsigned)img->h >> 3);
        for (; i < n; i++) {
            d[i] += (u16)((u16)(int)work->bgPaletteD | 0x3000);
        }
        func_02041090(3, (unsigned int)img->d, 0x10, 0xC, (unsigned)img->w >> 3, (unsigned)img->h >> 3);
        func_02041B6C(3);
    }
    func_020307B0((void *)tex);
    func_02049238(arc);
}






void func_021BB260(ItemMenuWork *work, int val)
{
    int v;
    u32 *win2;
    u32 *win;

    win = (u32 *)&work->listWindows[ITEMMENU_WINDOW_MENU_0].window;

    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*win)), 5);
    func_02045CAC(work->msgBank, 0x83, work->tempString);
    func_0201EFA4(work->wordSet, 0, val, 3, 0, 1);
    func_0201F250(work->wordSet, work->messageString, work->tempString);
    func_021BB6E0(work, win, work->messageString, 0, 0, 0x3DC5);
    func_021BB724((void **)win);
    if (work->listMode == 2) {
        win2 = (u32 *)&work->listWindows[ITEMMENU_WINDOW_MENU_3].window;
        v = func_021B619C(work->selectedItemId, work->listCount, work->heapId);
        func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*win2)), 5);
        func_02045CAC(work->msgBank, 0x54, work->tempString);
        func_0201EFA4(work->wordSet, 0, v, 7, 0, 1);
        func_0201F250(work->wordSet, work->messageString, work->tempString);
        func_021BB6E0(work, win2, work->messageString, 0, 0, 0x3DC5);
        func_021BB724((void **)win2);
    }
}





int func_021BB368(int x)
{
    switch (x) {
    case 0:
        return 10;
    case 3:
        return 13;
    case 1:
        return 11;
    case 2:
        return 12;
    case 4:
        return 14;
    }
    return x;
}






void func_021BB398(ItemMenuWork *work, u32 val)
{
    short b[2];
    short a[2];
    unsigned i;

    func_0204B454(work->selectorActor, (struct PtS *)b, 0);
    for (i = 0; i < 8; i++) {
        func_0204B454(work->slotActorA[i], (struct PtS *)a, 0);
        if (a[1] == b[1]) {
            break;
        }
    }
    func_0204B6F4(work->slotActorA[i], (u8)val, 0);
}






void func_021BB3F4(ItemMenuWork *work, int mode)
{
    int r;

    if (work->currentPage == mode) {
        return;
    }
    work->currentPage = mode;
    r = GAME_DATA_CheckSaveFlag(work->saveData, func_021BB368(work->currentPocket));
    if (mode == 1) {
        PALANM_RequestFade(work->palAnmSlot, 4, 0x23CF, 0, 0, 0, 0, func_020056BC());
        PALANM_RequestFade(work->palAnmSlot, 1, 1, 0, 0, 0, 0, func_020056BC());
        func_0207D658(0x04000050, 6, 0);
        func_021BB5A4(work);
        func_0204B878(work->sideActor[0], 4);
        func_0204B878(work->sideActor[1], 5);
        func_0204B878(work->sideActor[3], 0);
        if (r == 1) {
            func_0204B878(work->sideActor[2], 7);
        } else {
            func_0204B878(work->sideActor[2], 6);
        }
        func_021BB580(work, 1);
    } else {
        func_020216D4(work->palAnmSlot, 2, 0, 0x200);
        PALANM_RequestFade(work->palAnmSlot, 4, 0x23CF, 0, 8, 8, 0, func_020056BC());
        PALANM_RequestFade(work->palAnmSlot, 1, 1, 0, 8, 8, 0, func_020056BC());
        if (work->bagMode == 4 && func_0204B3F4(work->sideActor[0]) == 0) {
            func_0207D658(0x04000050, 2, -8);
        } else {
            func_0207D658(0x04000050, 6, -8);
        }
        func_0204B878(work->inputGuard, 4);
        func_0204B878(work->sideActor[0], 0x12);
        func_0204B878(work->sideActor[1], 0x13);
        func_0204B878(work->sideActor[3], 0xE);
        if (r == 1) {
            func_0204B878(work->sideActor[2], 0x16);
        } else {
            func_0204B878(work->sideActor[2], 0x15);
        }
    }
}





void func_021BB580(ItemMenuWork *work, int v) { if (v == 1) func_0204B878((work->sideActor[4]), 1); else func_0204B878((work->sideActor[4]), 15); }





void func_021BB5A4(ItemMenuWork *work) { if (work->currentPocket == 2 || work->currentPocket == 3 || func_021B61C8(work) <= 1) func_0204B878((work->inputGuard), 4); else func_0204B878((work->inputGuard), 0); }






void func_021BB5DC(ItemMenuWork *work, int mode)
{
    int r = GAME_DATA_CheckSaveFlag(work->saveData, func_021BB368(work->currentPocket));

    if (mode == 1) {
        func_021BB5A4(work);
        func_0204B878(work->sideActor[0], 4);
        func_0204B878(work->sideActor[1], 5);
        func_0204B878(work->sideActor[3], 0);
        if (r == 1) {
            func_0204B878(work->sideActor[2], 7);
        } else {
            func_0204B878(work->sideActor[2], 6);
        }
    } else {
        func_0204B878(work->inputGuard, 4);
        func_0204B878(work->sideActor[0], 0x12);
        func_0204B878(work->sideActor[1], 0x13);
        func_0204B878(work->sideActor[3], 0xE);
        if (r == 1) {
            func_0204B878(work->sideActor[2], 0x16);
        } else {
            func_0204B878(work->sideActor[2], 0x15);
        }
    }
}





/*
 * lever: expand q at the first call but retain q for the second call.
 */
int func_021BB690(const char *p)
{
    unsigned i;
    short v[2];
    const char *q;
    int off;
    for (i = 0; i < 5; i++) {
        off = i * 4;
        q = p + off;
        func_0204B454(*(struct Actor **)((p + off) + 0x6AC), (struct PtS *)v, 0xFFFF);
        if (v[0] == *((short *)(((char *)d_021BBBCC) + off))) {
            return 0;
        }
        v[0] = v[0] + 4;
        func_0204B404(*(struct Actor **)(q + 0x6AC), (const struct Vec2 *)v, 0xFFFF);
    }
    return 1;
}






void func_021BB6E0(ItemMenuWork *work, u32 *obj, void *str, u16 x, s16_021BB6E0 y, u16 color)
{
    void *print = work->printSys;

    func_0201C724(print, (u32)func_02045770((struct Descriptor *)*obj), (s16_021BB6E0)x, y, str, work->menuTaskArg, color);
    *((unsigned char *)obj + 4) = 1;
}





void func_021BB724(void **p)
{
    func_02045374(*p);
    func_02041B6C(func_02045730(*p));
}


/* Window whose text was printed: once the print system has finished with its
 * buffer, flushes the window to VRAM and clears the dirty flag. */
static inline void flushWindow(ItemMenuWork *work, ItemMenuWindow *slot)
{
    void *printSys = work->printSys;
    if (slot->isDirty != 0) {
        if (func_0201C6C4(printSys, (void *)((u32)func_02045770((struct Descriptor *)slot->window))) == 0) {
            func_02045334((struct Descriptor *)slot->window);
            slot->isDirty = 0;
        }
    }
}

void func_021BB73C(ItemMenuWork *work)
{
    func_0201C4E4(work->printSys);
    flushWindow(work, &work->listWindows[0]);
    flushWindow(work, &work->listWindows[1]);
    flushWindow(work, &work->listWindows[2]);
    flushWindow(work, &work->listWindows[3]);
    flushWindow(work, &work->listWindows[4]);
    flushWindow(work, &work->listWindows[5]);
    flushWindow(work, &work->listWindows[6]);
    flushWindow(work, &work->listWindows[7]);
    flushWindow(work, &work->listWindows[8]);
    flushWindow(work, &work->messageWindows[0]);
    flushWindow(work, &work->messageWindows[1]);
}
