/*
 * file:     monolith_tool.c
 * unit:     yes
 * function: func_021B6100, func_021B6250, func_021B6458, func_021B64D0, func_021B6524, func_021B652C, func_021B6538, func_021B6540, func_021B6588, func_021B65B4, func_021B6624, func_021B6644, func_021B677C, func_021B6790, func_021B6808, func_021B6844, func_021B68B4, func_021B68E0, func_021B6960, func_021B699C, func_021B69AC, func_021B6A0C, func_021B6B38, func_021B6B58, func_021B6B70, func_021B6B98, func_021B6BEC, func_021B6C30, func_021B6C48, func_021B6C54, func_021B6C74, func_021B6C7C, func_021B6DB4, func_021B6E00, func_021B6E0C, func_021B6E18, func_021B6E1C, func_021B6EEC, func_021B6F04, func_021B6F2C, func_021B6F40, func_021B6F54, func_021B6FD8, func_021B6FE0, func_021B7014, func_021B7068, func_021B7070, func_021B70B8, func_021B70C4, func_021B7108, func_021B7114, func_021B7118, func_021B7168, func_021B7170, func_021B7174, func_021B718C, func_021B7194, func_021B71FC, func_021B7204, func_021B7234, func_021B730C, func_021B739C, func_021B7824, func_021B7880, func_021B78D4, func_021B78F4, func_021B7924, func_021B7994, func_021B79A0, func_021B7A08, func_021B7A14, func_021B7A68, func_021B7AAC, func_021B7AC4, func_021B7AE8, func_021B7B10, func_021B7B9C, func_021B7BB4, func_021B7BD8, func_021B7BE4, func_021B7BF0, func_021B7BFC, func_021B7C3C, func_021B7D00, func_021B7D34, func_021B7D6C, func_021B7D98, func_021B7DAC, func_021B7DE0, func_021B7E24, func_021B7E3C, func_021B7E60, func_021B7EE0, func_021B8150, func_021B81A0, func_021B8270, func_021B82A4, func_021B82E4, func_021B82F0, func_021B82FC, func_021B8308, func_021B833C, func_021B8350, func_021B83C0, func_021B83CC, func_021B8434, func_021B8440, func_021B8494, func_021B855C, func_021B8618, func_021B8650, func_021B869C, func_021B86BC, func_021B86E8, func_021B8750, func_021B8764, func_021B878C, func_021B8798, func_021B889C, func_021B8968, func_021B8A38, func_021B8A70, func_021B8ABC, func_021B8ADC, func_021B8B08, func_021B8BF4, func_021B8C0C, func_021B8EC4, func_021B8ED0, func_021B8EDC, func_021B8EE8, func_021B9070, func_021B94CC, func_021B9560, func_021B95CC, func_021B95FC, func_021B9694, func_021B96A4, func_021B9734, func_021B9750, func_021B9798, func_021B9818, func_021B98B4, func_021B98C4, func_021B992C, func_021B9970, func_021B9A18, func_021B9A40, func_021B9AE4, func_021B9B3C, func_021B9B64, func_021B9BA0, func_021B9BAC, func_021B9BB8, func_021B9BC8, func_021B9BD8, func_021B9BE8, func_021B9C1C, func_021B9C30, func_021B9C7C, func_021B9F2C, func_021B9F74, func_021B9FEC, func_021B9FF8, func_021BA004, func_021BA01C, func_021BA0CC, func_021BA11C, func_021BA140, func_021BA1B0, func_021BA1DC, func_021BA1FC, func_021BA2CC, func_021BA384, func_021BA3B4, func_021BA400, func_021BA420, func_021BA44C, func_021BA4D4, func_021BA4EC, func_021BA528, func_021BA5D4
 * address:  0x021B6100
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207D534  0x0207D534  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_0204363C  0x0204363C  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02010F7C  0x02010F7C  thumb
 *   PROCSYS_Create  0x02031324  arm
 *   func_02028470  0x02028470  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_0203D34C  0x0203D34C  arm
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0202208C  0x0202208C  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   INTRUDE_COMM_SendBusyBegin  0x0217440C  thumb  ov011
 *   INTRUDE_COMM_SendBusyEnd  0x0217446C  thumb  ov011
 *   func_020221A4  0x020221A4  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02026454  0x02026454  thumb
 *   PROCSYS_Push  0x02031348  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   PROCSYS_Main  0x02031330  arm
 *   func_020310C4  0x020310C4  arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0204A600  0x0204A600  arm
 *   d_021BA774     0x021BA774  data  a4
 *   func_0203133C  0x0203133C  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02010F8C  0x02010F8C  thumb
 *   func_02049238  0x02049238  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_020433E0  0x020433E0  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_02082A7C  0x02082A7C  arm
 *   d_021BA7D4     0x021BA7D4  data  ov071  a4
 *   d_021BA764     0x021BA764  data  a4
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02045088  0x02045088  arm
 *   func_020450C8  0x020450C8  arm
 *   func_02021518  0x02021518  thumb
 *   func_0202155C  0x0202155C  thumb
 *   PALANM_SetAutoTransfer  0x02021EE4  thumb
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02041300  0x02041300  arm
 *   func_02040588  0x02040588  arm
 *   d_021BA794     0x021BA794  data  a4
 *   d_021BA7B4     0x021BA7B4  data  a4
 *   func_020403F4 0x020403F4 arm
 *   PALANM_LoadHandlePaletteToSlotAt  0x02021660  thumb
 *   PALANM_LoadArcPaletteToSlotAt  0x020215EC  thumb
 *   PALANM_LoadHandlePaletteToSlot  0x020216B4  thumb
 *   func_020498F4  0x020498F4  arm
 *   func_02049658  0x02049658  arm
 *   func_0203FA08  0x0203FA08  arm
 *   func_02027634  0x02027634  thumb
 *   func_020409B4  0x020409B4  arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_0203101C  0x0203101C  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02031140 0x02031140 arm
 *   d_020A1448     0x020A1448  data  a4
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   CLACT_SetUnitDefaultRenderer  0x0204B270  arm
 *   ACTOR_TOOL_Create  0x02025318  thumb
 *   func_02025538  0x02025538  thumb
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_02025588 0x02025588 thumb
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   ACTOR_TOOL_Delete 0x02025358 thumb
 *   ACTOR_TOOL_LoadCharPalAnm  0x02025470  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   ACTOR_TOOL_LoadCharSimplePalAnm  0x020254BC  thumb
 *   ACTOR_TOOL_FreeChar 0x02025518 thumb
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A648 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   func_02048F60  0x02048F60  arm
 *   func_020490A8  0x020490A8  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02043678  0x02043678  arm
 *   func_0204B294  0x0204B294  arm
 *   func_020255A0  0x020255A0  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_02045808  0x02045808  arm
 *   d_021BA80C     0x021BA80C  data  a2
 *   d_021BA814     0x021BA814  data  a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02025774 0x02025774 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020257D0 0x020257D0 thumb
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_02034714  0x02034714  arm
 *   PALANM_GetColor  0x02021F3C  thumb
 *   func_02021FD8  0x02021FD8  thumb
 *   d_021BABE0     0x021BABE0  data  a1
 *   d_021BA82C     0x021BA82C  data  a4
 *   func_020120F4 0x020120F4 thumb
 *   func_021583EC 0x021583EC thumb ov010
 *   func_021583CC 0x021583CC thumb ov010
 *   d_021BA844     0x021BA844  data  a2
 *   func_0204B92C  0x0204B92C  arm
 *   CLACT_ChangeActorAnimSeq 0x0204B8A0 arm
 *   d_021BA854     0x021BA854  data  a4
 *   d_021BA84C     0x021BA84C  data  a4
 *   d_021BA804     0x021BA804  data  a4
 *   func_02027F60 0x02027F60 thumb
 *   func_02027FD8  0x02027FD8  thumb
 *   func_02027778  0x02027778  thumb
 *   func_02027858  0x02027858  thumb
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02030734  0x02030734  arm
 *   func_02041090  0x02041090  arm
 *   d_021BABE4     0x021BABE4  data  a1
 *   d_021BA8A0     0x021BA8A0  data  a4
 *   func_02158590 0x02158590 thumb ov010
 *   func_02035C60 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 *   func_02035C08 0x02035C08 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020355D8x 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_02175B14 0x02175B14 thumb ov011
 *   func_02175B4C 0x02175B4C thumb ov011
 *   INTRUDE_COMM_TakeJoinReply 0x021761EC thumb ov011
 *   INTRUDE_CMD_SendJoinRequest 0x02173E2C thumb ov011
 *   d_021BA87C 0x021BA87C data a4
 *   d_021BA85C 0x021BA85C data a1
 *   d_021BA862 0x021BA862 data a1
 *   d_021BAA4C 0x021BAA4C data a4
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   d_021BA8DC     0x021BA8DC  data  a4
 *   d_021BA8FC     0x021BA8FC  data  a4
 *   func_0201F554  0x0201F554  thumb
 *   func_0201F548  0x0201F548  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   d_021BABF4     0x021BABF4  data  a1
 *   func_02028484  0x02028484  thumb
 *   func_02045334  0x02045334  arm
 *   func_0204B404 0x0204B404 arm
 *   func_020355C4  0x020355C4  arm
 *   func_020084F4  0x020084F4  thumb
 *   func_02045994  0x02045994  arm
 *   func_02008550  0x02008550  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   d_021BA928 0x021BA928 data a4
 *   d_021BA948     0x021BA948  data  a4
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0203633C  0x0203633C  arm
 *   d_021BA978     0x021BA978  data  a4
 *   d_021BA9F8     0x021BA9F8  data  a4
 *   d_021BA9C8     0x021BA9C8  data  a4
 *   d_021BA9A4     0x021BA9A4  data  a4
 *   d_021BA984 0x021BA984 data a4
 *   d_021BABF8     0x021BABF8  data  a1
 *   d_021BAA64     0x021BAA64  data  a4
 *   d_021BAA84     0x021BAA84  data  a4
 *   func_02175B34  0x02175B34  thumb  ov011
 *   func_021762D8  0x021762D8  thumb  ov011
 *   d_021BAAA4     0x021BAAA4  data  a4
 *   d_021BAAB8     0x021BAAB8  data  ov071  a4
 *   d_021BAAD8     0x021BAAD8  data  ov071  a4
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   _ll_sdiv       0x0209BE5C  arm
 *   func_0216FEAC  0x0216FEAC  thumb  ov010
 *   func_0201F184 0x0201F184 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   func_02005F38 0x02005F38 thumb
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BE48 0x0200BE48 thumb
 *   func_0200BF08 0x0200BF08 thumb
 *   func_02012B58 0x02012B58 thumb
 *   GAME_COMM_PushPairMessage 0x020266AC thumb
 *   INTRUDE_COMM_SendPairMessage 0x02174660 thumb ov011
 *   func_02035C38 0x02035C38 arm
 *   func_0203630C 0x0203630C arm
 *   d_021BAAFC 0x021BAAFC data a4
 *   d_021BABFC 0x021BABFC data a4
 *   d_021BAB28     0x021BAB28  data  ov071  a4
 *   d_021BAB48     0x021BAB48  data  ov071  a4
 *   d_021BAB68     0x021BAB68  data  a4
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_0216FE2C  0x0216FE2C  thumb  ov010
 *   func_0201C7D0  0x0201C7D0  thumb
 *   d_021BAAF8     0x021BAAF8  data  a2
 *   d_021BAB10     0x021BAB10  data  a4
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_0202590C  0x0202590C  thumb
 *   func_02043814  0x02043814  arm
 *   d_021BAB94     0x021BAB94  data  a4
 *   d_021BABB4     0x021BABB4  data  a4
 *   func_0200BF10  0x0200BF10  thumb
 */

struct S02021D50;
struct Proc;
struct Ctx;
struct PrintSys;
struct Tcbl;
struct Node;
struct PalAnmSlot;
struct S020314B8;
struct Proc;
struct DispConfig;
struct DispVram;
struct Obj02021EE4;
struct BgTemplate;
struct GfFont;
struct MsgBank;
struct WordSet;
struct Rec;
struct S02031140;
struct Bank;
struct Cfg;
struct Bitmap;
struct BmpOamGrid;
struct Sys;
struct Strbuf;
struct Actor;
struct Bitmap;
struct Chan02021FD8;
struct R;
struct TaskMenuState;
struct TaskMenu;
struct TaskMenuTmpl;
struct Rec3;
struct Bitmap;
struct BmpWin;
struct Blk;
struct P;
struct Vec2;
struct Strbuf;
struct Sub0200852CObj;
struct BigObj;
struct Big;
struct Rec1B0;
struct Pos;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

#include "monolith_tool_types.h"

typedef struct {
    int a;
    int b;
} Pair;

struct S6844 {
    int w0, w4;
    u8 b8, b9, ba, bb;
    int wc;
    u16 h10, h12, h14, h16;
    int w18;
};

typedef signed int     s32;

typedef enum { SLOT_FIRST, SLOT_COUNT = 2 } Slot;

typedef enum { IDX_FIRST, IDX_COUNT = 6 } Idx;

typedef signed short s16;

typedef enum { B_FALSE, B_TRUE } Bool;

struct Pair {
    int x, y;
};

struct MonolithToolActorPos {
    s16 x;
    s16 y;
    u16 animSeq;
    u8 reserved6;
    u8 reserved7;
};

struct MonolithToolGridParam {
    void *bitmap;
    s16 x;
    s16 y;
    u32 palette;
    u32 reservedC;
    u8 reserved10;
    u8 reserved11;
    u16 subScreenA;
    u32 subScreenB;
};

typedef struct {
    u16 v;
    u8 state;
    u8 dir;
    u8 timer;
    u8 cnt;
    u8 pad[2];
} Ent;

struct MonolithToolIconPos {
    u16 x, y, animSeq, reserved6;
};

struct Ent {
    int w[4];
};

struct P { int w[6]; int pad[10]; struct Ent e[2]; };

typedef enum { V4 = 4, V5 = 5 } Value;

struct MonolithToolCursorPos {
    u16 x, y, animSeq, reserved6;
};

typedef struct { void *s; u16 h; int z; } Item;

typedef struct {void **f0;u8 *f4;u8 *f8;u8 padc[0x20];u8 f2c,f2d,f2e;} C;

typedef signed char s8;

typedef struct {
    u8 b[0x14];
} Menu;

typedef long long s64;

typedef enum { FALSE, TRUE } Bool_021B9070;

typedef struct {
    char pad0[0x2c];
    int f2c;
    s64 f30;
    u8 f38[1];
} Save;

extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void func_0204363C(u32 a);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Proc *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02010F7C(u32 heap);
extern void *PROCSYS_Create(int a0);
extern void func_02028470(u8 *p, u32 v);
extern u32 func_020056A0(void (*cb)(void), void *arg, int pri);
extern void func_0203D34C(u32 a, u32 b);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_0200FB24(void);
extern u32 INTRUDE_COMM_SendBusyBegin(void);
extern u32 INTRUDE_COMM_SendBusyEnd(void);
extern u32 func_020221A4(void);
extern u32 func_0202648C(void *obj);
extern u32 func_02026454(void *obj);
extern void PROCSYS_Push(int h, int id, int a, void *b);
extern void func_0201DD78(u32, u32, u32);
extern u32 PROCSYS_Main(void *h);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0204A600(void);
extern void func_0203133C(struct S020314B8 *p);
extern void func_02030EAC(struct Node *n);
extern void func_02010F8C(void *p);
extern void func_02049238(void *a);
extern void func_020315D4(struct Proc *p);
extern void func_020306F0(u32 heap);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02082A7C(int, int, int);
extern void func_020215A0(struct PalAnmSlot *, u32);
extern u32 func_02021540(void *a0);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(u32);
extern void PALANM_LoadHandlePaletteToSlotAt(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern void PALANM_LoadArcPaletteToSlotAt(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern void PALANM_LoadHandlePaletteToSlot(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_0203FA08(u32 layer, u32 size, u32 top);
extern void func_02027634(void *arc, int id, u32 heap, int base, u32 pal);
extern void func_020409B4(u32 a);
extern void func_0203FB44(u32, u32, u32);
extern unsigned int func_02045C04(struct MsgBank *bank);
extern unsigned int func_0201ED04(struct WordSet *p);
extern void func_0201C6EC(struct PrintSys *);
extern void func_0201C4C0(struct PrintSys *);
extern u32 func_0201D83C(void *ptr);
extern void func_02031140(struct Tcbl *);
extern void func_020434DC(u32, u32);
extern void func_02043598(u32, u32);
extern void func_02025588(void *);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void ACTOR_TOOL_Delete(void *);
extern void ACTOR_TOOL_FreeChar(u32, u32, u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern void func_0204A648(void);
extern void PALANM_TransferPalettes(struct PalAnmSlot *);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern u32 func_020490A8(u32 a, u32 b);
extern u32 func_020307B0(void *p);
extern struct Bitmap *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Actor *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern struct BmpOamGrid *func_020255A0(struct Sys *sys, const struct MonolithToolGridParam *param);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C6FC(struct PrintSys *printSys, struct Bitmap *bitmap, u32 x, u32 y, struct Strbuf *text, u32 font);
extern void func_02045808(struct Strbuf *vec);
extern void func_0204B3B4(struct Actor *);
extern void func_0202570C(struct BmpOamGrid *);
extern void func_020437AC(struct Bitmap *);
extern void func_0204B3DC(struct Actor *, u32);
extern void func_02025774(u8 *, u32);
extern u32 func_0201C6C4(struct PrintSys *, void *);
extern void func_020257D0(struct BmpOamGrid *);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u16 PALANM_GetColor(int base, int idx, int which, u16 pos);
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern void *func_020120F4(const struct Ctx *p);
extern int func_021583EC(void *a0, int a1);
extern int func_021583CC(void *a0, int a1);
extern void func_0204B92C(struct Actor *, unsigned int);
extern void CLACT_ChangeActorAnimSeq(struct Actor *p, u16 v);
extern void func_0204B6F4(struct Actor *o, u32 v, u32 flag);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_02027974(void *);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_0203F9B4(void);
extern void func_02045088(u16 heapId);
extern void func_020450C8(void);
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern unsigned int PALANM_SetAutoTransfer(struct PalAnmSlot *slots, int v);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02041300(u32 a, u32 b, u32 c, u32 d, u8 e, u8 f, u8 g);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);
extern u8 *ACTOR_TOOL_Create(u32 a0, u8 a1, u8 a2);
extern void *func_02025538(unsigned int a0, void *a1);
extern u32 ACTOR_TOOL_LoadCharPalAnm(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 ACTOR_TOOL_LoadCharSimplePalAnm(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_02027858(struct TaskMenu *m);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern int func_02158590(void *);
extern int func_02035C60(void);
extern u32 func_020362DC(void);
extern int func_02035C08(const void *);
extern void func_020355D8(int);
extern void func_020355D8x(int);
extern void func_020061E4(u32);
extern int func_02175B14(u8 *);
extern void func_02175B4C(u8 *,u8 *);
extern u8 INTRUDE_COMM_TakeJoinReply(char *p);
extern int INTRUDE_CMD_SendJoinRequest(char *a, int b);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201F554(u32 a, u32 b, u32 c, u32 d);
extern u8 func_0201F548(int i);
extern struct BmpWin *func_020450F0(u32 layer, u32 x, u32 y, u32 width, u8 height, u8 palette, u8 slot);
extern void *func_02045770(struct BmpWin *p);
extern void func_02043B5C(struct Bitmap *buf, u8 value);
extern void func_02045374(struct BmpWin *window);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *a0, u32 a1, u32 a2, void *a3, u32 a4, u32 a5, void *a6, u32 a7, u32 a8, u32 a9);
extern s32 func_02028484(struct Blk *blk, void *h);
extern void func_02045334(struct BmpWin *d);
extern u32 func_020452E8(struct BmpWin *d);
extern void func_0204B404(struct Actor *p, const struct Vec2 *delta, u32 which);
extern u8 func_020355C4(void);
extern const void *func_020084F4(const void *p);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern unsigned int func_0203633C(void);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern u8 *func_02175B34(u8 *p);
extern void func_021762D8(MonolithToolSlotInfo *, void *, void *, int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int func_0216FEAC(MonolithEntry *table, MonolithCounts *counts, u8 *rankData);
extern int func_02035C38(void);
extern u32 func_0203630C(void);
extern void func_0201F184(struct WordSet *p, u32 i, s32 v);
extern int INTRUDE_COMM_SendPairMessage(int,...);
extern void GFL_USE_FadeOutBgm(u32 a);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern int func_02005F38(void);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_FadeInBgmFull(u32 a);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern void func_0200BF08(struct Rec1B0 *p, u32 v);
extern u8 func_02012B58(const struct BigObj *p);
extern void GAME_COMM_PushPairMessage(u32,u32,u32);
extern void func_0201F7A8(void *desc, u32 kind);
extern int func_0216FE2C(MonolithEntry *table, int index, MonolithCounts *counts, u8 *rankData);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern u32 TOUCHPANEL_GetPointCont(u32 *outX, u32 *outY);
extern void func_020413B0(u8 layer, u8 x, u8 y, u8 width, u8 height, u8 palette);
extern void func_02041B6C(u32 layerBit);
extern void func_02041EE4(unsigned layer, unsigned axis, unsigned offset);
extern void func_0202590C(struct BmpOamGrid *grid, s16 x, s16 y);
extern void func_02043814(struct Bitmap *dst, const struct Bitmap *src);
extern u8 func_0200BF10(void *saveBlock);
extern const struct MonolithToolGridParam d_021BAB10;
extern const struct BgTemplate d_021BAB94;
extern const struct BgTemplate d_021BABB4;
int func_021B6100(struct Proc *ctx, int unused, MonolithToolSetup *setup);
int func_021B6250(int a, int *seq, void **pwk, MonolithToolWork *work);
int func_021B6458(int a, int b, int c, MonolithToolWork *work);
void func_021B64D0(void);
void func_021B6524(void);
void func_021B652C(void);
void func_021B6538(void);
unsigned int func_021B6540(MonolithToolWork *work);
void func_021B6588(MonolithToolWork *work);
void func_021B65B4(void);
void func_021B6624(void);
void func_021B6644(MonolithToolWork *work, MonolithToolWork *work2);
void func_021B677C(MonolithToolWork *work);
void func_021B6790(MonolithToolWork *work);
void func_021B6808(MonolithToolWork *work);
void func_021B6844(MonolithToolWork *work);
void func_021B68B4(MonolithToolWork *work);
void func_021B68E0(MonolithToolWork *work);
void func_021B6960(MonolithToolWork *work);
void func_021B699C(void *unused, MonolithToolWork *work);
void func_021B69AC(MonolithToolWork *work, MonolithToolSetup *setup);
void func_021B6A0C(MonolithToolWork *work, MonolithToolButton *button, int resIndex, int sizeClass, int x, int y, int msgId, void *wordSet);
void func_021B6B38(MonolithToolButton *button);
void func_021B6B58(MonolithToolButton *button, int visible);
int func_021B6B70(MonolithToolWork *work, MonolithToolButton *button);
void func_021B6B98(MonolithToolProcArgs *args, MonolithToolButton *button, int count, int selected, int slot);
void func_021B6BEC(MonolithToolProcArgs *args, MonolithToolButton *button, int count, int selected, int slot);
void func_021B6C30(MonolithToolProcArgs *args, int pulse, int slot);
void func_021B6C48(MonolithToolProcArgs *args, int slot);
void func_021B6C54(MonolithToolProcArgs *args);
u8 func_021B6C74(MonolithToolProcArgs *args, int slot);
void func_021B6C7C(MonolithToolProcArgs *args, int slot);
void func_021B6DB4(MonolithToolProcArgs *args, int mode, int slot);
int func_021B6E00(unsigned int x);
int func_021B6E0C(unsigned int x);
int func_021B6E18(int a0);
void func_021B6E1C(MonolithToolWork *work, MonolithToolLabel *label, int resIndex, int x, int y, int widthTiles, int heightTiles, int msgId, void *wordSet);
void func_021B6EEC(MonolithToolLabel *label);
int func_021B6F04(MonolithToolWork *work, MonolithToolLabel *label);
void *func_021B6F2C(MonolithToolProcArgs *args);
MonolithCounts *func_021B6F40(MonolithToolProcArgs *args);
int func_021B6F54(MonolithToolWork *work, MonolithCounts *counts, int slot, const int *pos, int resIndex);
void func_021B6FD8(void *p);
void func_021B6FE0(void *p, MonolithCounts *counts, int i);
int func_021B7014(MonolithToolWork *work, const int *pos, int resIndex);
void func_021B7068(void *p);
void func_021B7070(MonolithToolWork *work, MonolithToolBlink *blink);
void func_021B70B8(MonolithToolBlink *blink);
void func_021B70C4(MonolithToolBlink *p);
void func_021B7108(MonolithToolBlink *blink);
int func_021B7114(MonolithToolBlink *blink);
struct Actor *func_021B7118(MonolithToolWork *work, int x, int y, int animSeq);
void func_021B7168(void *p);
void func_021B7170(void *a);
struct R *func_021B7174(u32 *p, int a, u16 heap);
void func_021B718C(void *p);
void *func_021B7194(int *p, void *arg1, u32 heap);
void func_021B71FC(void *p);
int func_021B7204(MonolithToolWork *work, int unused, void *p, int *q);
void func_021B7234(void *a, int flag, int bg);
int func_021B730C(void *ctx, int *state, MonolithToolProcArgs *args);
int func_021B739C(int unused, int *state, MonolithToolProcArgs *args, MonolithToolSlotSelect *screen);
int func_021B7824(void *proc, void *unused, MonolithToolProcArgs *args, MonolithToolSlotSelect *screen);
void func_021B7880(void);
void func_021B78D4(void);
void func_021B78F4(MonolithToolProcArgs *args, MonolithToolWork *work);
void func_021B7924(MonolithToolSlotSelect *screen, MonolithToolWork *work);
void func_021B7994(MonolithToolSlotSelect *screen);
void func_021B79A0(MonolithToolSlotSelect *screen, MonolithToolWork *work, int msgId);
int func_021B7A08(MonolithToolWork *work, MonolithToolSlotSelect *screen);
void func_021B7A14(MonolithToolSlotSelect *screen);
void func_021B7A68(MonolithToolSlotSelect *screen, MonolithToolProcArgs *args);
void func_021B7AAC(MonolithToolSlotSelect *screen);
void func_021B7AC4(MonolithToolSlotSelect *screen, MonolithToolProcArgs *args);
void func_021B7AE8(MonolithToolSlotSelect *screen,int slot);
void func_021B7B10(MonolithToolProcArgs *args, MonolithToolSlotSelect *screen);
void func_021B7B9C(MonolithToolSlotSelect *screen);
void func_021B7BB4(MonolithToolProcArgs *args,MonolithToolSlotSelect *screen);
void func_021B7BD8(MonolithToolProcArgs *args, MonolithToolSlotSelect *screen);
void func_021B7BE4(MonolithToolSlotSelect *screen);
void func_021B7BF0(MonolithToolSlotSelect *screen);
void func_021B7BFC(MonolithToolProcArgs *args, MonolithToolSlotSelect *screen, unsigned char mode);
int func_021B7C3C(void *ctx, int *state, MonolithToolProcArgs *args);
int func_021B7D00(int unused,int *state,MonolithToolProcArgs *args,MonolithToolTitle *screen);
int func_021B7D34(void *proc,int unused,MonolithToolProcArgs *args,MonolithToolTitle *screen);
void func_021B7D6C(void);
void func_021B7D98(void);
void func_021B7DAC(MonolithToolProcArgs *args,MonolithToolWork *work);
void func_021B7DE0(MonolithToolTitle *screen, MonolithToolProcArgs *args);
void func_021B7E24(MonolithToolTitle *screen);
void func_021B7E3C(MonolithToolTitle *screen,MonolithToolProcArgs *args);
int func_021B7E60(struct Proc *ctx, int unused, MonolithToolProcArgs *args);
int func_021B7EE0(int unused, int *state, MonolithToolProcArgs *args, MonolithToolMenu *screen);
int func_021B8150(void *proc, int unused, MonolithToolProcArgs *args, MonolithToolMenu *screen);
void func_021B81A0(MonolithToolProcArgs *args, MonolithToolMenu *screen);
void func_021B8270(MonolithToolMenu *screen);
void func_021B82A4(MonolithToolProcArgs *args, MonolithToolMenu *screen);
void func_021B82E4(MonolithToolProcArgs *args, MonolithToolMenu *screen);
void func_021B82F0(MonolithToolMenu *screen);
void func_021B82FC(MonolithToolMenu *screen);
void func_021B8308(void);
void func_021B833C(void);
void func_021B8350(MonolithToolMenu *screen, MonolithToolWork *work);
void func_021B83C0(MonolithToolMenu *screen);
void func_021B83CC(MonolithToolMenu *screen, MonolithToolWork *work, unsigned msgId);
int func_021B8434(MonolithToolWork *work, MonolithToolMenu *screen);
void func_021B8440(MonolithToolMenu *screen);
int func_021B8494(struct Proc *ctx, int *state, MonolithToolProcArgs *args, MonolithToolSummary *screen);
int func_021B855C(int unused, int *state, MonolithToolProcArgs *args, MonolithToolSummary *screen);
int func_021B8618(void *proc, int unused, MonolithToolProcArgs *args, MonolithToolSummary *screen);
void func_021B8650(void);
void func_021B869C(void);
void func_021B86BC(MonolithToolWork *work);
void func_021B86E8(int unused, MonolithToolSummary *screen);
void func_021B8750(MonolithToolSummary *screen);
void func_021B8764(MonolithToolWork *work, MonolithToolSummary *screen);
void func_021B878C(MonolithToolSummary *screen);
void func_021B8798(MonolithToolProcArgs *args, MonolithToolWork *work, MonolithToolSummary *screen, u8 *saveData, unsigned slot);
int func_021B889C(struct Proc *ctx, int *state, MonolithToolProcArgs *args, MonolithToolStats *screen);
int func_021B8968(int unused, int *state, MonolithToolProcArgs *args, MonolithToolStats *screen);
int func_021B8A38(void *proc, int unused, MonolithToolProcArgs *args, MonolithToolStats *screen);
void func_021B8A70(void);
void func_021B8ABC(void);
void func_021B8ADC(MonolithToolWork *work);
void func_021B8B08(int unused, MonolithToolStats *screen);
void func_021B8BF4(MonolithToolStats *screen);
void func_021B8C0C(MonolithToolProcArgs *args, MonolithToolWork *work, MonolithToolStats *screen);
void func_021B8EC4(MonolithToolProcArgs *args, MonolithToolStats *screen);
void func_021B8ED0(MonolithToolStats *screen);
void func_021B8EDC(MonolithToolStats *screen);
int func_021B8EE8(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithListWork *work);
int func_021B9070(int unused, int *state, MonolithToolProcArgs *args, MonolithListWork *work);
int func_021B94CC(void *proc, void *unused, MonolithToolProcArgs *args, MonolithListWork *work);
void func_021B9560(void);
void func_021B95CC(void);
void func_021B95FC(MonolithListWork *work, MonolithToolWork *toolWork);
void func_021B9694(MonolithListWork *work);
void func_021B96A4(MonolithListWork *work, MonolithToolWork *toolWork);
void func_021B9734(MonolithListWork *work);
void func_021B9750(MonolithToolProcArgs *args, MonolithListWork *work);
void func_021B9798(MonolithListWork *work, MonolithToolWork *toolWork, u32 msgId);
void func_021B9818(MonolithListWork *work, MonolithToolWork *toolWork, u32 msgId);
int func_021B98B4(MonolithToolWork *toolWork, MonolithListWork *work);
void func_021B98C4(MonolithListWork *work);
void func_021B992C(MonolithListWork *work);
void func_021B9970(MonolithToolProcArgs *args, MonolithListWork *work, MonolithToolWork *toolWork);
void func_021B9A18(MonolithListWork *work);
int func_021B9A40(MonolithListWork *work, MonolithToolWork *toolWork);
void func_021B9AE4(MonolithListWork *work, MonolithToolWork *toolWork);
void func_021B9B3C(MonolithListWork *work);
void func_021B9B64(MonolithToolProcArgs *args, MonolithListWork *work);
void func_021B9BA0(MonolithListWork *work);
void func_021B9BAC(MonolithToolWork *toolWork, MonolithListWork *work);
void func_021B9BB8(MonolithToolProcArgs *args, MonolithListWork *work);
void func_021B9BC8(MonolithListWork *work);
void func_021B9BD8(MonolithListWork *work);
void func_021B9BE8(MonolithToolProcArgs *args, MonolithListWork *work);
void func_021B9C1C(MonolithListWork *work);
void func_021B9C30(MonolithListWork *work);
int func_021B9C7C(MonolithToolProcArgs *args, MonolithListWork *work);
int func_021B9F2C(MonolithListWork *work, int index, int inputMode);
void func_021B9F74(MonolithListWork *work, int index, int palette);
void func_021B9FEC(MonolithListWork *work, int index);
void func_021B9FF8(MonolithListWork *work, int index);
void func_021BA004(MonolithListWork *work);
void func_021BA01C(MonolithToolProcArgs *args, MonolithListWork *work);
int func_021BA0CC(MonolithListWork *work, int delta);
void func_021BA11C(MonolithListWork *work);
void func_021BA140(MonolithListWork *work);
void func_021BA1B0(void *task, MonolithListWork *work);
int func_021BA1DC(MonolithListWork *work, unsigned y);
int func_021BA1FC(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work);
int func_021BA2CC(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work);
int func_021BA384(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work);
void func_021BA3B4(void);
void func_021BA400(void);
void func_021BA420(MonolithToolWork *toolWork);
void func_021BA44C(MonolithToolWork *toolWork, MonolithInfoWork *work);
void func_021BA4D4(MonolithInfoWork *work);
void func_021BA4EC(MonolithToolWork *toolWork, MonolithInfoWork *work);
void func_021BA528(MonolithToolProcArgs *args, MonolithToolWork *toolWork, MonolithInfoWork *work);
void func_021BA5D4(MonolithToolProcArgs *args, MonolithToolWork *toolWork, MonolithInfoWork *work);
extern Pair d_021BA774[];
extern char d_021BA7D4;
extern char d_021BA764;
extern char d_021BA794;
extern char d_021BA7B4;
extern struct S6844 d_020A1448;
extern const struct MonolithToolActorPos d_021BA80C;
extern const struct MonolithToolGridParam d_021BA814;
extern char d_021BABE0[];
extern const struct MonolithToolGridParam d_021BA82C;
extern struct MonolithToolIconPos d_021BA844;
extern const struct MonolithToolCursorPos d_021BA854;
extern const struct MonolithToolCursorPos d_021BA84C;
extern const struct MonolithToolCursorPos d_021BA804;
extern const char d_021BABE4[];
extern const struct Pair d_021BA8A0[];
extern const u32 d_021BA87C[];
extern const u8 d_021BA85C[],d_021BA862[][4];
extern const u32 d_021BAA4C[];
extern char d_021BA8DC[];
extern char d_021BA8FC[];
extern char d_021BABF4[];
extern const char d_021BA928[];
extern const char d_021BA948[];
extern unsigned d_021BA978[];
extern Menu d_021BA9F8[];
extern int d_021BA9C8[][4];
extern int d_021BA9A4[][3];
extern const char d_021BA984[];
extern char d_021BABF8[];
extern char d_021BAA64[];
extern char d_021BAA84[];
extern char d_021BAAA4[];
extern char d_021BAAB8[];
extern char d_021BAAD8[];
extern const u32 d_021BAAFC[];
extern char d_021BABFC[];
extern char d_021BAB28[];
extern char d_021BAB48[];
extern struct Config d_021BAB68;
extern u16 d_021BAAF8[];



int func_021B6100(struct Proc *ctx, int unused, MonolithToolSetup *setup)
{
    MonolithToolWork *work;


    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_02043534(0);
    func_020435F4(0);
    *(volatile u32 *)0x04000000 &= 0xFFFFE0FF;
    *(volatile u32 *)0x04001000 &= 0xFFFFE0FF;
    *(volatile u32 *)0x04000000 &= 0xFFFF1FFF;
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
    func_0207D63C(0x04000050, 4, 8, 0xF, 0xF);
    func_0207D63C(0x04001050, 4, 8, 0xF, 0xF);
    func_0204363C(1);
    func_0203064C(1, 0x61, 0x70000);
    work = func_0203159C(ctx, sizeof(MonolithToolWork), 0x61);
    func_02082BCC(work, 0, sizeof(MonolithToolWork));
    work->selection.selected = MONOLITH_ENTRY_NONE;
    func_021B69AC(work, setup);
    work->archive = func_020490F4(0x27, 0x61);
    func_021B64D0();
    func_021B652C();
    func_021B6540(work);
    func_021B65B4();
    func_021B6644(work, work);
    func_021B6790(work);
    func_021B6844(work);
    func_021B68E0(work);
    work->entryTable = func_02010F7C(0x61);
    work->topProcSys = (int)PROCSYS_Create(0x61);
    work->subProcSys = (int)PROCSYS_Create(0x61);
    func_02028470(work->scratchList, 6);
    work->vblankTask = func_020056A0((void (*)(void))func_021B699C, work, 0xA);
    func_0203D34C(0, 0x61);
    work->procArgs.setup = setup;
    work->procArgs.work = work;
    work->procArgs.param = &work->selection;
    return 1;
}



int func_021B6250(int a, int *seq, void **pwk, MonolithToolWork *work)
{
    void *h;
    u8 *r;
    int s1;
    int s2;
    u8 k;

    h = (void *)func_02012138(*pwk);
    r = (u8 *)func_02158344((int)h);
    switch (*seq) {
    case 0:
        func_0202208C(0, 1, 1, 0, 6, 1, 0x8061);
        (*seq)++;
        break;
    case 1:
        if (r == 0 || func_0200FB24() != 0)
            (*seq)++;
        else if (INTRUDE_COMM_SendBusyBegin() == 1)
            (*seq)++;
        break;
    case 2:
        if (func_020221A4() == 1)
            (*seq)++;
        break;
    case 3:
        if (func_0200FB24() != 0 || (r == 0 && func_0202648C(h) != 0) || (r == 0 && func_02026454(h) == 2))
            work->procArgs.abortRequested = 1;
        if (work->procArgs.abortRequested == 0) {
            if (work->topProcStarted == 0) {
                PROCSYS_Push(work->topProcSys, -1, d_021BA774[work->currentScreen].a, &work->procArgs);
                work->topProcStarted = 1;
            }
            if (work->subProcStarted == 0) {
                func_0201DD78(0xF, 2, 0);
                PROCSYS_Push(work->subProcSys, -1, d_021BA774[work->currentScreen].b, &work->procArgs);
                work->subProcStarted = 1;
            }
        }
        s2 = PROCSYS_Main((void *)work->subProcSys);
        k = work->procArgs.requestedScreen;
        if (k == 4 || (s2 != 1 && work->procArgs.abortRequested == 1)) {
            work->procArgs.topProcDone = 1;
        } else if (work->currentScreen != k && d_021BA774[work->currentScreen].a != d_021BA774[k].a) {
            work->procArgs.topProcDone = 1;
        }
        s1 = PROCSYS_Main((void *)work->topProcSys);
        if (s1 == 1 && s2 == 1)
            break;
        if (work->procArgs.abortRequested == 1 || work->procArgs.requestedScreen == 4) {
            if (s1 == 0 && s2 == 0)
                (*seq)++;
        } else {
            work->currentScreen = work->procArgs.requestedScreen;
            if (s1 != 1) {
                work->topProcStarted = 0;
                work->procArgs.topProcDone = 0;
            }
            if (s2 != 1)
                work->subProcStarted = 0;
        }
        break;
    case 4:
        func_0202208C(0, 0, 0, 0, 6, 1, 0x8061);
        (*seq)++;
        break;
    case 5:
        if (r == 0 || func_0200FB24() != 0)
            (*seq)++;
        else if (INTRUDE_COMM_SendBusyEnd() == 1)
            (*seq)++;
        break;
    case 6:
        if (func_020221A4() == 1)
            (*seq)++;
        break;
    case 7:
        return 1;
    }
    func_020310C4(work->taskList);
    func_0201C4E4(work->printSys);
    func_0204A600();
    return 0;
}

/*
 * Byte-correct. Blocker: func_02010F8C (arm9 unlabelled tail-call stub,
 * the integrator's leaf) has no witness outside this range. Verified C for the leaf
 * (EXACT, arm9, --thumb, symbols: func_020307B0 0x020307B0 arm):
 *   void func_02010F8C(void *p) { void func_020307B0(void *); func_020307B0(p); }
 */
int func_021B6458(int a, int b, int c, MonolithToolWork *work)
{

    func_0203133C((struct S020314B8 *)work->topProcSys);
    func_0203133C((struct S020314B8 *)work->subProcSys);
    func_02030EAC((struct Node *)work->vblankTask);
    func_02010F8C(work->entryTable);
    func_021B6960(work);
    func_021B68B4(work);
    func_021B6808(work);
    func_021B677C(work);
    func_021B6624();
    func_021B6588(work);
    func_021B6538();
    func_021B6524();
    func_02049238(work->archive);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    func_020315D4((struct Proc *)a);
    func_020306F0(0x61);
    return 1;
}

void func_021B64D0(void)
{

    func_020433E0((const struct DispVram *)(&d_021BA7D4));
    func_0203F8F4(0x61);
    func_0203FC28((struct DispConfig *)(&d_021BA764));
    func_02082A7C(0, 0x06000000, 0x80000);
    func_02082A7C(0, 0x06200000, 0x20000);
    func_02082A7C(0, 0x06400000, 0x40000);
    func_02082A7C(0, 0x06600000, 0x20000);
}



/*
 * Three ARM9 thunks that share a literal-pool tail-call shape.
 */
void func_021B6524(void)
{
    func_0203F9B4();
}



void func_021B652C(void)
{
    func_02045088(0x61);
}



void func_021B6538(void)
{
    func_020450C8();
}



unsigned int func_021B6540(MonolithToolWork *work)
{
    work->palAnm = func_02021518(0x61);
    func_0202155C(work->palAnm, 2, 0x1c0, 0x61);
    func_0202155C(work->palAnm, 3, 0x1c0, 0x61);
    func_0202155C(work->palAnm, 0, 0x1c0, 0x61);
    func_0202155C(work->palAnm, 1, 0x1c0, 0x61);
    return PALANM_SetAutoTransfer(work->palAnm, 1);
}







void func_021B6588(MonolithToolWork *work)
{
    func_020215A0(work->palAnm, 2);
    func_020215A0(work->palAnm, 3);
    func_020215A0(work->palAnm, 0);
    func_020215A0(work->palAnm, 1);
    func_02021540(work->palAnm);
}



void func_021B65B4(void)
{
    int i;

    func_0203FCA0((int)3, (const struct BgTemplate *)(&d_021BA794), (int)0);
    func_0203FCA0((int)7, (const struct BgTemplate *)(&d_021BA7B4), (int)0);
    func_02041300(3, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(7, 0, 0, 0, 0x20, 0x20, 0x11);
    for (i = 0; i <= 7; i++) {
        func_02040588((u8)i, (int)0);
    }
    func_02040588((u8)3, (int)1);
    func_02040588((u8)7, (int)1);
}







void func_021B6624(void)
{
    func_02040588(3, 0);
    func_02040588(7, 0);
    func_020403F4(3);
    func_020403F4(7);
}








void func_021B6644(MonolithToolWork *work, MonolithToolWork *work2)
{
    void *h;

    PALANM_LoadHandlePaletteToSlotAt(work2->palAnm, work2->archive, 0x10, 0x61, 0, 0x1c0, 0, 0);
    PALANM_LoadHandlePaletteToSlotAt(work2->palAnm, work2->archive, 0x11, 0x61, 1, 0x1c0, 0, 0);
    func_02049658(work2->archive, 0xf, 3, 0, 0, 1, 0x61);
    func_020498F4(work2->archive, 0xa, 3, 0, 0, 1, 0x61);
    func_02049658(work2->archive, 0xe, 7, 0, 0, 1, 0x61);
    func_020498F4(work2->archive, 4, 7, 0, 0, 1, 0x61);
    PALANM_LoadArcPaletteToSlotAt(work2->palAnm, 0x17, 5, 0x61, 0, 0, 0xd0, 0);
    PALANM_LoadArcPaletteToSlotAt(work2->palAnm, 0x17, 5, 0x61, 1, 0, 0xd0, 0);
    h = func_020490F4(0x53, 0x61);
    work->subBgCharOffset = func_0203FA08(7, 0x80, 1);
    func_02049658(h, 0x1c, 7, work->subBgCharOffset, 0x80, 0, 0x61);
    func_02027634(h, 7, 0x61, work->subBgCharOffset, 0xc);
    PALANM_LoadHandlePaletteToSlot(work2->palAnm, h, 0x1b, 0x61, 1, 0x20, 0xc0);
    func_02049238(h);
    func_020409B4(7);
    func_020409B4(3);
    func_020409B4(7);
}







void func_021B677C(MonolithToolWork *work)
{
    func_0203FB44(7, work->subBgCharOffset, 0x80);
}



void func_021B6790(MonolithToolWork *work)
{
    func_0201DD78(0xf, 2, 0);
    work->taskList = func_0203101C(0x61, 0x61, 4, 0x20);
    work->font = func_0201D7EC(0x17, 0, 0, 0, 0x61);
    work->printSys = (struct PrintSys *)func_0201C440((void *)0x61);
    work->wordSet = func_0201EC64(0x61);
    work->msgBank[0] = func_02045B38(0, 2, 0x43, 0x61);
    work->msgBank[1] = func_02045B38(0, 2, 0xa0, 0x61);
    work->msgBank[2] = func_02045B38(0, 2, 0xa1, 0x61);
    work->msgBank[3] = func_02045B38(0, 2, 0x45, 0x61);
}







void func_021B6808(MonolithToolWork *work)
{
    func_02045C04(work->msgBank[0]);
    func_02045C04(work->msgBank[1]);
    func_02045C04(work->msgBank[2]);
    func_02045C04(work->msgBank[3]);
    func_0201ED04(work->wordSet);
    func_0201C6EC(work->printSys);
    func_0201C4C0(work->printSys);
    func_0201D83C(work->font);
    func_02031140(work->taskList);
}



void func_021B6844(MonolithToolWork *work)
{
    struct S6844 s;

    s = d_020A1448;
    s.b8 = 4;
    s.b9 = 0x7c;
    s.ba = 4;
    s.bb = 0x7c;
    s.h10 = 0x60;
    s.h14 = 0x40;
    func_0204A48C((const struct Cfg *)(&s), (u32)(&d_021BA7D4), 0x61);
    work->unitBank = func_0204B100(0x60, 0, 0x61);
    CLACT_SetUnitDefaultRenderer(work->unitBank);
    work->actorTool = ACTOR_TOOL_Create(0x61, 0x10, 0x10);
    work->actorToolUnit = func_02025538(0x61, work->unitBank);
}







/*
 * split: TU confirms one image-wide witness, inside this caller; no cuts.
 * ARM9 stub: 02025358 ldr r3,[pc,#0]; bx r3; pool 020307B0.
 */
void func_021B68B4(MonolithToolWork *work)
{
    func_020434DC(0x10, 0);
    func_02043598(0x10, 0);
    func_02025588(work->actorToolUnit);
    func_0204B1CC(work->unitBank);
    func_0204A5AC();
    ACTOR_TOOL_Delete(work->actorTool);
}



void func_021B68E0(MonolithToolWork *work)
{
    void *tmp;
    int i;
    int flag;

    tmp = func_020490F4(0x17, 0x61);
    for (i = 0; i < 2; i++) {
        flag = 0;
        if (i != 0) {
            flag = 1;
        }
        work->actorRes[i].charPalAnm = ACTOR_TOOL_LoadCharPalAnm((u32)work->palAnm, (u32)work->actorTool, (u32)work->archive, 3, flag, 3, 0x61);
        work->actorRes[i].cellRes = func_0204A6C8(work->archive, 0, 1, flag, 0x61);
        work->actorRes[i].animRes = func_0204AF28(work->archive, 1, 2, 0x61);
        work->actorRes[i].simplePalAnm = ACTOR_TOOL_LoadCharSimplePalAnm((u32)work->palAnm, (u32)work->actorTool, (u32)tmp, 5, flag, 1, 0x61);
    }
    func_02049238(tmp);
}







/*
 * extent: two-byte alignment padding at 0x021B699A.
 * Enum counter preserves the first iteration's cmp/branch.
 */
void func_021B6960(MonolithToolWork *work)
{
    Slot i;
    int flag;

    i = SLOT_FIRST;
    do {
        flag = 0;
        if (i != 0) {
            flag = 1;
        }
        ACTOR_TOOL_FreeChar((u32)work->actorTool, work->actorRes[i].charPalAnm, flag);
        func_0204A8D4(work->actorRes[i].cellRes);
        func_0204AFD8(work->actorRes[i].animRes);
        ACTOR_TOOL_FreeChar((u32)work->actorTool, work->actorRes[i].simplePalAnm, flag);
        i++;
    } while (i < SLOT_COUNT);
}






void func_021B699C(void *unused, MonolithToolWork *work)
{
    func_0204A648();
    PALANM_TransferPalettes(work->palAnm);
}







void func_021B69AC(MonolithToolWork *work, MonolithToolSetup *setup)
{
    MonolithToolSlotRecord *tbl;
    u32 n;
    u32 idx;
    Idx i;

    if (setup->useSlotRecords != 0) {
        tbl = func_02048F60(0x25, 0, 0x61);
        n = func_020490A8(0x25, 0);
        for (i = IDX_FIRST; i < IDX_COUNT; i++) {
            idx = setup->slotIndex[i];
            if (idx >= n) {
                idx = 0;
            }
            work->slotRecord[i] = tbl[idx];
        }
        func_020307B0(tbl);
    }
}







/*
 * The 0/1 flag keeps its bne-to-one polarity only as an enum ternary
 * (a-flag-ternary-over-enum-constants-keeps-the-bne-to-one-polarity.md);
 * `case 2:` shares its arm with `default:` (the dead `cmp r6, #2; b`).
 */
void func_021B6A0C(MonolithToolWork *work, MonolithToolButton *button, int resIndex, int sizeClass, int x, int y, int msgId, void *wordSet)
{
    struct MonolithToolActorPos pos = d_021BA80C;
    struct MonolithToolGridParam param = d_021BA814;
    u32 widthTiles;
    void *bitmap;
    void *text;
    void *expanded;
    int onSubScreen;

    switch (sizeClass) {
    case 0:
        widthTiles = 0x16;
        pos.animSeq = 0;
        param.x = x - 0x58;
        break;
    case 1:
        widthTiles = 0x12;
        pos.animSeq = 1;
        param.x = x - 0x48;
        break;
    case 2:
    default:
        widthTiles = 0xc;
        pos.animSeq = 8;
        param.x = x - 0x30;
        break;
    }
    bitmap = func_02043678(widthTiles, 2, 0x20, 0x61);
    button->bitmap = bitmap;
    pos.x = x;
    pos.y = y;
    param.y = y - 8;
    param.bitmap = bitmap;
    param.palette = work->actorRes[resIndex].simplePalAnm;
    onSubScreen = resIndex == 0 ? B_FALSE : B_TRUE;
    param.subScreenB = onSubScreen;
    param.subScreenA = onSubScreen;
    button->actor = func_0204B294((void *)work->unitBank, work->actorRes[resIndex].cellRes, work->actorRes[resIndex].charPalAnm, work->actorRes[resIndex].animRes, &pos, onSubScreen, 0x61);
    button->grid = func_020255A0(work->actorToolUnit, &param);
    text = func_02045EC0(work->msgBank[3], msgId);
    if (wordSet) {
        expanded = func_020457B0(0x80, 0x61);
        func_0201F250(wordSet, expanded, text);
        func_0201C6FC(work->printSys, button->bitmap, 0, 0, expanded, (u32)work->font);
        func_02045808(expanded);
    } else {
        func_0201C6FC(work->printSys, button->bitmap, 0, 0, text, (u32)work->font);
    }
    func_02045808(text);
    button->on = 1;
}






void func_021B6B38(MonolithToolButton *button)
{
    func_0204B3B4(button->actor);
    func_0202570C(button->grid);
    func_020437AC(button->bitmap);
    button->actor = 0;
    button->grid = 0;
    button->bitmap = 0;
}






/*
 * extent: two-byte alignment padding at 0x021B6B6E.
 */
void func_021B6B58(MonolithToolButton *button, int visible)
{
    func_0204B3DC(button->actor, visible);
    func_02025774(button->grid, visible);
}






int func_021B6B70(MonolithToolWork *work, MonolithToolButton *button)
{
    if (button->on == 1) {
        if (func_0201C6C4(work->printSys, button->bitmap) == 0) {
            func_020257D0(button->grid);
            button->on = 0;
            return 1;
        }
    }
    return 0;
}



void func_021B6B98(MonolithToolProcArgs *args, MonolithToolButton *button, int count, int selected, int slot)
{
    int i;

    for (i = 0; i < count; i++) {
        if (i == selected) {
            func_0204B6F4((struct Actor *)button[i].actor, 1, 1);
            func_021B6DB4(args, 1, slot);
        } else {
            func_0204B6F4((struct Actor *)button[i].actor, 0, 1);
        }
    }
    if (selected == 0xff) {
        func_021B6DB4(args, 0, slot);
    }
}



void func_021B6BEC(MonolithToolProcArgs *args, MonolithToolButton *button, int count, int selected, int slot)
{
    int i;

    for (i = 0; i < count; i++) {
        if (i == selected) {
            func_0204B6F4((struct Actor *)button[i].actor, 1, 1);
            func_021B6DB4(args, 2, slot);
        } else {
            func_0204B6F4((struct Actor *)button[i].actor, 0, 1);
        }
    }
}






void func_021B6C30(MonolithToolProcArgs *args, int pulse, int slot)
{
    if (pulse == 1) {
        func_021B6DB4(args, 1, slot);
    } else {
        func_021B6DB4(args, 0, slot);
    }
}



void func_021B6C48(MonolithToolProcArgs *args, int slot)
{
    func_021B6DB4(args, 2, slot);
}






void func_021B6C54(MonolithToolProcArgs *args) { int i; for(i=0;i<4;i++) func_02082BCC(&args->highlight[i],0,8); }







u8 func_021B6C74(MonolithToolProcArgs *args, int slot)
{
    return args->highlight[slot].mode;
}







/*
 * sites to PALANM_GetColor stay wildcarded because 0x02021F3C is an
 * unlabelled arm9 Thumb leaf (a bare `cmp r2, #1` entry, no lr save), so
 * no class attests it. The leaf verifies EXACT with this body
 * (`one --thumb`, no --region), outside this lane's write set (arm9):
 *
 *   typedef struct { u16 *a; u16 *b; int pad[3]; } Slot;
 *   u16 PALANM_GetColor(Slot *s, int idx, int which, u16 pos)
 *   {
 *       if (which == 1) {
 *           return s[idx].a[pos];
 *       }
 *       if (which == 0) {
 *           return s[idx].b[pos];
 *       }
 *       return 0;
 *   }
 *
 * note 2026-10-05 (D8 lane16): witness PALANM_GetColor filed as src/matched/arm9/PALANM_GetColor.c (EXACT); this file becomes EXACT once the integrator seeds that label/manifest. Body unchanged.
 */
void func_021B6C7C(MonolithToolProcArgs *args, int slot)
{
    MonolithToolHighlight *highlight;
    int firstColor, srcColor, colorCount;
    int i;
    int level;
    highlight = &args->highlight[slot];
    if (slot >= 4) {
        func_02034714(d_021BABE0, (int)0, d_021BABE0);
    }
    firstColor = func_021B6E00((int)slot);
    srcColor = func_021B6E0C((int)slot);
    colorCount = func_021B6E18(slot);
    switch (highlight->mode) {
    case 1:
        level = highlight->level;
        if (highlight->fadeDown == 0) {
            level += 0x80;
            if (level >= 0x1100) {
                level = 0x1000;
                highlight->fadeDown ^= 1;
            }
        } else {
            level -= 0x80;
            if (level <= 0) {
                level = 0x100;
                highlight->fadeDown ^= 1;
            }
        }
        highlight->level = level;
        for (i = 0; i < colorCount; i++) {
            func_02021FD8((struct Chan02021FD8 *)args->work->palAnm, (int)slot, (u16)(firstColor + i), (u16)1, level >> 8,
                          PALANM_GetColor((int)args->work->palAnm, slot, 1, srcColor + i));
        }
        break;
    case 2:
        if (highlight->timer == 0) {
            highlight->timer = 3;
            if (highlight->level == 0) {
                highlight->level = 0x1000;
            } else {
                highlight->level = 0;
                highlight->flashCount++;
                if (highlight->flashCount > 1) {
                    func_021B6DB4(args, 0, slot);
                }
            }
            for (i = 0; i < colorCount; i++) {
                func_02021FD8((struct Chan02021FD8 *)args->work->palAnm, (int)slot, (u16)(firstColor + i), (u16)1, highlight->level >> 8,
                              PALANM_GetColor((int)args->work->palAnm, slot, 1, srcColor + i));
            }
        } else {
            highlight->timer--;
        }
        break;
    }
}



void func_021B6DB4(MonolithToolProcArgs *args, int mode, int slot)
{
    MonolithToolHighlight *highlight;
    highlight = &args->highlight[slot];
    func_02082BCC(highlight, 0, 8);
    highlight->mode = mode;
    func_02021FD8((struct Chan02021FD8 *)args->work->palAnm, (int)slot, (u16)func_021B6E00(slot), (u16)func_021B6E18(slot), 0, 0);
}






/*
 * Two bounded constant selectors and a constant return.
 */
int func_021B6E00(unsigned int x)
{
    return x <= 1 ? 0x32 : 0x12;
}







int func_021B6E0C(unsigned int x)
{
    return x <= 1 ? 0x42 : 0x22;
}







int func_021B6E18(int a0)
{
    return 3;
}







/*
 * The 0/1 flag is written in each if/else arm (param.f14 and param.f12 stores), so the
 * param address stays in r0 across the diamond and tail merging rebuilds the join. Callee
 * types from matched definitions (02043678 returns Bmp *, 020255A0 Grid *, 02045EC0 void *,
 * 020457B0 U16Vec *). Twin ov071 021B6A0C. final push 2026-10-05 G7L5.
 */
void func_021B6E1C(MonolithToolWork *work, MonolithToolLabel *label, int resIndex, int x, int y, int widthTiles, int heightTiles, int msgId, void *wordSet)
{
    struct MonolithToolGridParam param = d_021BA82C;
    void *bitmap;
    void *text;
    void *expanded;
    bitmap = func_02043678(widthTiles, heightTiles, 0x20, 0x61);
    label->bitmap = bitmap;
    param.x = x - (widthTiles / 2) * 8;
    param.y = y - (heightTiles / 2) * 8;
    param.bitmap = bitmap;
    param.palette = work->actorRes[resIndex].simplePalAnm;
    if (resIndex == 0) {
        param.subScreenB = 0;
        param.subScreenA = 0;
    } else {
        param.subScreenB = 1;
        param.subScreenA = 1;
    }
    label->grid = func_020255A0(work->actorToolUnit, &param);
    text = func_02045EC0(work->msgBank[3], msgId);
    if (wordSet) {
        expanded = func_020457B0(0x80, 0x61);
        func_0201F250(wordSet, expanded, text);
        func_0201C6FC(work->printSys, label->bitmap, 0, 0, expanded, (u32)work->font);
        func_02045808(expanded);
    } else {
        func_0201C6FC(work->printSys, label->bitmap, 0, 0, text, (u32)work->font);
    }
    func_02045808(text);
    label->on = 1;
}






void func_021B6EEC(MonolithToolLabel *label) { func_0202570C(label->grid); func_020437AC(label->bitmap); label->grid = 0; label->bitmap = 0; }






int func_021B6F04(MonolithToolWork *work, MonolithToolLabel *label) { if(label->on==1) { if(func_0201C6C4(work->printSys, label->bitmap)==0) { func_020257D0(label->grid); label->on=0; return 1; } } return 0; }





void *func_021B6F2C(MonolithToolProcArgs *args)
{
    MonolithToolSetup *setup = args->setup;
    return (void *)func_021583EC(func_020120F4(setup->gameCtx), setup->areaId);
}





MonolithCounts *func_021B6F40(MonolithToolProcArgs *args)
{
    MonolithToolSetup *setup = args->setup;
    return (void *)func_021583CC(func_020120F4(setup->gameCtx), setup->areaId);
}






/*
 * The flag is a u16 local assigned from a ternary over enum constants: every
 * int-constant spelling (ternary, if/else, e != 0) is folded to a boolean and
 * comes out with the opposite branch polarity (beq to 0, not bne to 1).
 * const on d lets both d[] loads go ahead of the stores into s.
 */
int func_021B6F54(MonolithToolWork *work, MonolithCounts *counts, int slot, const int *pos, int resIndex)
{
    struct MonolithToolIconPos iconPos;
    int actor;
    u16 onSubScreen;
    u8 *states;
    iconPos = d_021BA844;
    onSubScreen = resIndex == 0 ? B_FALSE : B_TRUE;
    iconPos.x = pos[0];
    iconPos.y = pos[1];
    states = counts->slotIconState;
    if (states[slot] == 1) {
        iconPos.animSeq = 5;
    }
    actor = (int)func_0204B294((void *)work->unitBank, work->actorRes[resIndex].cellRes, work->actorRes[resIndex].charPalAnm, work->actorRes[resIndex].animRes, &iconPos, onSubScreen, 0x61);
    if (states[slot] == 0) {
        func_0204B3DC((struct Actor *)actor, 0);
    }
    func_0204B92C((struct Actor *)actor, 1);
    return actor;
}



/*
 * Tail call to func_0204B3B4.
 */
void func_021B6FD8(void *p)
{
    func_0204B3B4(p);
}





void func_021B6FE0(void *p, MonolithCounts *counts, int i) { Value v; if(counts->slotIconState[i]==1) v=V5; else if(counts->slotIconState[i]==2) v=V4; else {func_0204B3DC(p,0);return;} func_0204B3DC(p,1);CLACT_ChangeActorAnimSeq(p,v); }






int func_021B7014(MonolithToolWork *work, const int *pos, int resIndex)
{
    struct MonolithToolCursorPos cursorPos;
    int onSubScreen;
    cursorPos = d_021BA854;
    onSubScreen = 0;
    if (resIndex != 0)
        onSubScreen = 1;
    cursorPos.x = pos[0];
    cursorPos.y = pos[1];
    return (int)func_0204B294((void *)work->unitBank, work->actorRes[resIndex].cellRes, work->actorRes[resIndex].charPalAnm, work->actorRes[resIndex].animRes, &cursorPos, (u16)onSubScreen, 0x61);
}



void func_021B7068(void *p)
{
    func_0204B3B4(p);
}






void func_021B7070(MonolithToolWork *work, MonolithToolBlink *blink)
{
    struct MonolithToolCursorPos cursorPos;
    int actor;
    cursorPos = d_021BA84C;
    actor = (int)func_0204B294((void *)work->unitBank, work->actorRes[1].cellRes, work->actorRes[1].charPalAnm, work->actorRes[1].animRes, &cursorPos, 1, 0x61);
    func_0204B92C((struct Actor *)actor, 1);
    blink->actor = actor;
}



/*
 * Unlabelled leaf thunk: loads *p then tail-calls the ARM9 ARM function
 * func_0204B3B4 with it.  It is the callee whose only image-wide callers are
 * the three ov071 offset-thunks (matched via this EXACT entry).
 */
void func_021B70B8(MonolithToolBlink *blink)
{
    func_0204B3B4((void *)blink->actor);
}






void func_021B70C4(MonolithToolBlink *p)
{
    if (p->active == 1) {
        if (p->frame % 5 == 0) {
            func_0204B6F4((struct Actor *)p->actor, p->phase, 1);
            p->phase ^= 1;
            if (p->frame / 5 == 3)
                p->active = 0;
        }
        p->frame++;
    }
}






/*
 * Byte initialiser and its getter.
 */
void func_021B7108(MonolithToolBlink *blink)
{
    blink->active = 1;
    blink->frame = 0;
    blink->phase = 1;
}






int func_021B7114(MonolithToolBlink *blink)
{
    return blink->active;
}






struct Actor *func_021B7118(MonolithToolWork *work, int x, int y, int animSeq)
{
    struct MonolithToolCursorPos cursorPos;
    struct Actor *actor;
    cursorPos = d_021BA804;
    cursorPos.x = x;
    cursorPos.y = y;
    cursorPos.animSeq = animSeq;
    actor = func_0204B294((void *)work->unitBank, work->actorRes[1].cellRes, work->actorRes[1].charPalAnm, work->actorRes[1].animRes, &cursorPos, 1, 0x61);
    func_0204B92C(actor, 1);
    return actor;
}



/*
 * ARM9 tail call followed by an empty function.
 */
void func_021B7168(void *p)
{
    func_0204B3B4(p);
}






void func_021B7170(void *a)
{
}






struct R *func_021B7174(u32 *p, int a, u16 heap)
{
    return func_02027F60((u8)a, 14, p[3], p[2], heap);
}



/*
 * Tail call to func_02027FD8.
 */
void func_021B718C(void *p)
{
    func_02027FD8(p);
}






void *func_021B7194(int *p, void *arg1, u32 heap)
{
    Item it[2];
    struct {
        u32 heapId;
        u8 count;
        u8 pad05[3];
        Item *items;
        u32 unk0c;
        u8 b0, b1, b2, b3;
    } t;
    void *r;

    it[0].s = func_02045EC0((void *)p[0x28 / 4], 0x1e);
    it[1].s = func_02045EC0((void *)p[0x28 / 4], 0x1f);
    it[0].h = 0x39E0;
    it[1].h = 0x39E0;
    it[0].z = 0;
    it[1].z = 0;
    t.heapId = heap;
    t.count = 2;
    t.items = it;
    t.unk0c = 0;
    t.b0 = 0x18;
    t.b1 = 0xc;
    t.b2 = 8;
    t.b3 = 3;
    r = func_02027778((struct TaskMenuTmpl *)(&t), arg1);
    func_02045808(it[0].s);
    func_02045808(it[1].s);
    return r;
}



/*
 * Tail call to func_02027858.
 */
void func_021B71FC(void *p)
{
    func_02027858(p);
}





int func_021B7204(MonolithToolWork *work, int unused, void *p, int *q) { func_02027974(p); if(func_020279E8(p)==1) { *q=func_02027A04(p)==0 ? 1 : 0;return 1;} return 0; }






void func_021B7234(void *a, int flag, int bg)
{
    MonolithCounts *c;
    u16 *buf;
    int y;
    int n, m;
    int left, right;
    int i;

    c = func_021B6F40((MonolithToolProcArgs *)a);
    y = 0x14;
    if (flag) {
        y = 0xe;
    }
    n = c->current;
    m = c->limit;
    if (n == m) {
        left = 0x78;
        right = 0x78;
    } else {
        left = n * 0xf0 / (n + m);
        if (m > 0) {
            right = 0xf0 - left;
        } else {
            right = 0;
            left = 0xf0;
        }
    }
    if (n > 0 && left == 0) {
        right--;
    } else if (m > 0 && right == 0) {
        right++;
    }
    buf = func_02030734(0x61, 0x3c, 1, d_021BABE4, 0x474);
    for (i = 0; right > 0; i++) {
        if (right >= 8) {
            buf[i] = 1;
            right -= 8;
        } else {
            buf[i] = 9 - right;
            right = 0;
        }
    }
    for (; i < 30; i++) {
        buf[i] = 9;
    }
    for (i = 0; i < 30; i++) {
        buf[i] |= 0x1000;
    }
    func_02041090((u8)bg, (u32)buf, (u8)1, (u8)y, 30, 1);
    func_020307B0(buf);
}






int func_021B730C(void *ctx, int *state, MonolithToolProcArgs *args)
{
    MonolithToolSlotSelect *screen;

    switch (state[0]) {
    case 0:
        screen = func_0203159C(ctx, sizeof(MonolithToolSlotSelect), 0x61);
        func_02082BCC(screen, 0, sizeof(MonolithToolSlotSelect));
        screen->backMode = 0;
        func_021B7880();
        func_021B78F4(args, args->work);
        func_021B7924(screen, args->work);
        func_021B7A68(screen, args);
        func_021B7B10(args, screen);
        func_021B7BD8(args, screen);
        screen->cursorActor = (void *)func_021B7014(args->work, (const int *)&d_021BA8A0[args->param->slot], 1);
        state[0]++;
        break;
    case 1:
        func_02040588(6, 1);
        func_02043598(0x10, 1);
        return 1;
    }
    return 0;
}





#pragma opt_lifetimes off





#pragma opt_common_subs off





int func_021B739C(int unused, int *state, MonolithToolProcArgs *args, MonolithToolSlotSelect *screen)
{
 u16 *nameDst;
 u16 *nameSrc;
 u8 *intrude;
 int keyState,touchResult,result;
 u32 slot;
 u8 nextSlot;
 const u8 *neighbors;
 intrude=(u8 *)func_02158344(func_02012138(args->setup->gameCtx));
 func_021B7AC4(screen,args); func_021B7AE8(screen,args->param->slot);func_021B7BB4(args,screen);func_021B7BF0(screen);
 if(args->abortRequested==1 && *state==3) return 1;
 switch(*state) {
 case 0:
  if(intrude!=0 && func_02175B14(intrude+0x1ac)==1) func_021B7BFC(args,screen,1);
  *state=1;break;
 case 1:
  if(func_02158590(func_020120F4(args->setup->gameCtx))==0) func_021B79A0(screen,args->work,0x16);
  else func_021B79A0(screen,args->work,0x12);
  ++*state;break;
 case 2:
  if(func_021B7A08(args->work,screen)!=1) break;
  if(func_02035C60()==0 && (func_020362DC()&3)==0) break;
  func_021B7A14(screen);func_020061E4(0x547);
  if(func_02035C60()!=0) {screen->buttonHighlight=1;func_021B6B98(args,&screen->button[0],1,0xff,3);}
  else {screen->buttonHighlight=0;func_021B6B98(args,&screen->button[0],1,0,3);}
  if(screen->backMode==0) *state=3;else *state=4;
  break;
 case 3:
  keyState=func_020362DC();touchResult=func_02035C08(d_021BA87C);
  if(intrude!=0 && func_02175B14(intrude+0x1ac)==1) {func_021B7BFC(args,screen,1);screen->linkLost=1;*state=4;break;}
  if(keyState>0 && screen->buttonHighlight==1) {screen->buttonHighlight=0;func_021B6B98(args,&screen->button[0],1,0,3);func_020061E4(0x548);break;}
  if(keyState&0xf0) {
   nextSlot=0xff;
   for(slot=0;(slot<6)?1:0;slot++) if(d_021BA85C[slot]==args->param->slot) break;
   slot=args->param->slot;
   if(keyState&0x40) {neighbors=d_021BA862[slot];nextSlot=neighbors[0];}
   else if(keyState&0x80) {neighbors=d_021BA862[slot];nextSlot=neighbors[1];}
   else if(keyState&0x20) {neighbors=d_021BA862[slot];nextSlot=neighbors[2];}
   else if(keyState&0x10) {neighbors=d_021BA862[slot];nextSlot=neighbors[3];}
   if(nextSlot!=0xff) slot=nextSlot;
   args->param->slot=slot;func_020061E4(0x548);
  }
  if(touchResult>=0 && touchResult<6) {args->param->slot=touchResult;screen->buttonHighlight=1;func_021B6B98(args,&screen->button[0],1,0xff,3);func_020061E4(0x548);break;}
  if(touchResult==6 || (keyState&1)) {
   func_020355D8(touchResult==6);
   if(func_02158590(func_020120F4(args->setup->gameCtx))==0) {
    result=d_021BAA4C[args->param->slot];
    if(result!=2 && result!=1) {*state=9;break;}
   }
   func_021B6BEC(args,&screen->button[0],1,0,3);func_020061E4(0x736);*state=5;
  } else if(touchResult==7 || (keyState&2)) {
   func_021B7108(&screen->cursorBlink);func_020355D8(touchResult==7);func_020061E4(0x551);*state=11;
  }
  break;
 case 4: {
  int keyState4,touchResult4;
  keyState4=func_020362DC();touchResult4=func_02035C08(d_021BA87C);
  if(touchResult4==7 || (keyState4&2)) {func_020355D8x(touchResult4==7);func_020061E4(0x551);*state=11;}
  break;}

 case 5:
  screen->joinRecord=args->work->slotRecord[d_021BAA4C[args->param->slot]];
  screen->playerGender=args->setup->playerGender;
  nameDst=screen->playerName;
  nameSrc=args->setup->playerName;
  for(slot=10;slot!=0;slot--) {*nameDst=*nameSrc;nameDst++;nameSrc++;}
  if(intrude!=0 && INTRUDE_CMD_SendJoinRequest((char *)intrude,(int)&screen->joinRecord)!=1) break;
  *state=6;break;
 case 6:
  if(intrude==0) {*state=3;break;}
  result=INTRUDE_COMM_TakeJoinReply((char *)(intrude+0x1ac));
  if(result==1) {func_021B79A0(screen,args->work,0x10);*state=7;}
  else if(result==2) {func_021B79A0(screen,args->work,0x11);*state=8;}
  else if(result==3) {func_021B79A0(screen,args->work,0x15);*state=8;}
  else if(result==4) {func_021B79A0(screen,args->work,0x14);*state=8;}
  break;
 case 7:case 8:
  if(func_021B7A08(args->work,screen)!=1) break;
  if(*state==7) {
  } else if(*state==8) {
   if(func_02035C60()==0 && !(func_020362DC()&3)) break;
  } else break;
  if(*state==7 && intrude!=0 && func_02175B14(intrude+0x1ac)==0) break;
  func_021B7A14(screen);func_020061E4(0x547);
  if(*state==7) {if(intrude!=0) func_02175B4C(intrude,intrude+0x1ac);screen->joined=1;*state=11;}
  else *state=11;
  break;
 case 9:func_021B79A0(screen,args->work,0x17);++*state;break;
 case 10:
  if(func_021B7A08(args->work,screen)==1 && (func_02035C60()!=0 || (func_020362DC()&3)!=0)) {func_021B7A14(screen);*state=3;}
  break;
 case 11:
  if(func_021B6C74(args,3)==2) break;
  if(func_021B7114(&screen->cursorBlink)!=0) break;
  if(screen->joined==1) args->requestedScreen=4;else args->requestedScreen=0;
  return 1;
 }
 return 0;
}





#pragma opt_lifetimes reset





#pragma opt_common_subs reset






int func_021B7824(void *proc, void *unused, MonolithToolProcArgs *args, MonolithToolSlotSelect *screen)
{
    if (func_0201C6B4(args->work->printSys) == 0)
        return 0;
    func_020435F4(8);
    if (screen->msgPrinter != 0)
        func_0201CE48(screen->msgPrinter);
    if (screen->msgString != 0)
        func_02045808(screen->msgString);
    func_021B7068(screen->cursorActor);
    func_021B7BE4(screen);
    func_021B7B9C(screen);
    func_021B7AAC(screen);
    func_021B7994(screen);
    func_021B78D4();
    func_020315D4(proc);
    return 1;
}






void func_021B7880(void)
{
    func_0203FCA0(5, (const struct BgTemplate *)d_021BA8DC, 0);
    func_0203FCA0(6, (const struct BgTemplate *)d_021BA8FC, 0);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02040588(5, 0);
}





void func_021B78D4(void) { func_02040588(5,0); func_02040588(6,0); func_020403F4(5); func_020403F4(6); }





void func_021B78F4(MonolithToolProcArgs *args, MonolithToolWork *work) {func_020498F4(work->archive,6,6,0,0,1,0x61);func_021B7234(args,1,6);func_020409B4(6);}






void func_021B7924(MonolithToolSlotSelect *screen, MonolithToolWork *work)
{
    func_0201F554(5, 1, 0, 0x61);
    PALANM_LoadArcPaletteToSlotAt(work->palAnm, 5, func_0201F548(0), 0x61, 1, 0x20, 0xb0, 0);
    screen->msgWindow = (void *)func_020450F0(5, 1, 0x13, 0x1e, 4, 0xd, 1);
    func_02043B5C(func_02045770(screen->msgWindow), 0xff);
    func_02045374(screen->msgWindow);
    func_0201F73C(screen->msgWindow, 0, 1, 0xb);
}



void func_021B7994(MonolithToolSlotSelect *screen)
{
    func_020452E8(screen->msgWindow);
}






void func_021B79A0(MonolithToolSlotSelect *screen, MonolithToolWork *work, int msgId)
{
    if (screen->msgPrinter != 0)
        func_02034714(d_021BABF4, 0, d_021BABF4);
    func_0201DD78(1, 2, 15);
    screen->msgString = func_02045EC0((void *)work->msgBank[3], msgId);
    screen->msgPrinter = func_0201CCE4(screen->msgWindow, 0, 0, screen->msgString, (int)work->font, func_02012FFC(), (void *)work->taskList, 10, 0x61, 15);
    func_02040588(5, 1);
}





int func_021B7A08(MonolithToolWork *work, MonolithToolSlotSelect *screen) { return func_02028484((struct Blk *)work->scratchList, screen->msgPrinter); }






void func_021B7A14(MonolithToolSlotSelect *screen)
{
    void *window;
    window = func_02045770(screen->msgWindow);
    if (screen->msgPrinter == 0)
        func_02034714(d_021BABF4, 0, d_021BABF4);
    func_0201CE48(screen->msgPrinter);
    screen->msgPrinter = 0;
    func_02045808(screen->msgString);
    screen->msgString = 0;
    func_02040588(5, 0);
    func_02043B5C(window, 0xff);
    func_02045334(screen->msgWindow);
    func_0201DD78(15, 2, 0);
}



void func_021B7A68(MonolithToolSlotSelect *screen, MonolithToolProcArgs *args)
{
    int i;
    MonolithCounts *counts = func_021B6F40(args);
    for (i = 0; i < 6; i++) {
        int icon;
        unsigned recordIndex = d_021BAA4C[i];
        icon = func_021B6F54(args->work, counts, i, (const int *)&d_021BA8A0[recordIndex], 1);
        screen->slotIcon[i] = (void *)icon;
    }
}










void func_021B7AAC(MonolithToolSlotSelect *screen) { int i; for(i=0;i<6;i++) func_021B6FD8(screen->slotIcon[i]); }










void func_021B7AC4(MonolithToolSlotSelect *screen, MonolithToolProcArgs *args) { MonolithCounts *counts;int i;counts=func_021B6F40(args);for(i=0;i<6;i++)func_021B6FE0(screen->slotIcon[i],counts,i);}










void func_021B7AE8(MonolithToolSlotSelect *screen,int slot) { u16 pos[2];pos[0]=d_021BA8A0[slot].x;pos[1]=d_021BA8A0[slot].y;func_0204B404(screen->cursorActor,(const struct Vec2 *)pos,1);}











void func_021B7B10(MonolithToolProcArgs *args, MonolithToolSlotSelect *screen)
{
    func_021B6C54(args);
    func_021B6A0C(args->work, &screen->button[0], 1, 1, 0x80, 0x90, 14, 0);
    if (func_020355C4() == 0) {
        func_021B6B98(args, &screen->button[0], 1, 0, 3);
    } else {
        func_021B6B98(args, &screen->button[0], 1, 0xff, 3);
        screen->buttonHighlight = 1;
    }
    func_021B6A0C(args->work, &screen->button[1], 1, 1, 0x80, 0x90, 15, 0);
    func_021B6B58(&screen->button[1], 0);
}










void func_021B7B9C(MonolithToolSlotSelect *screen) { int i; for (i=0;i<2;i++) func_021B6B38(&screen->button[i]); }










void func_021B7BB4(MonolithToolProcArgs *args,MonolithToolSlotSelect *screen) { int i; func_021B6C7C(args,3); for(i=0;i<2;i++) func_021B6B70(args->work,&screen->button[i]); }








/*
 * Tail call to func_021B7070(word at 0x4, a + 0x24).
 */
void func_021B7BD8(MonolithToolProcArgs *args, MonolithToolSlotSelect *screen)
{
    func_021B7070(args->work, &screen->cursorBlink);
}








/*
 * Tail call to func_021B70B8 with the pointer advanced by 0x24.  The callee
 * is an unlabelled leaf in this overlay; it is reproduced in
 * src/matched/ov071_func_021B70B8.c, whose EXACT entry attests this pool-word
 * site (`matched`).
 */
void func_021B7BE4(MonolithToolSlotSelect *screen)
{
    func_021B70B8(&screen->cursorBlink);
}








/*
 * Tail call to func_021B70C4((char *)p + 0x24).
 */
void func_021B7BF0(MonolithToolSlotSelect *screen)
{
    func_021B70C4(&screen->cursorBlink);
}











void func_021B7BFC(MonolithToolProcArgs *args, MonolithToolSlotSelect *screen, unsigned char mode)
{
    if (mode == 0) {
        func_021B6B58(&screen->button[0], 1);
        func_021B6B58(&screen->button[1], 0);
    } else {
        args->param->slot = 6;
        func_021B6B58(&screen->button[0], 0);
        func_021B6B58(&screen->button[1], 1);
    }
    screen->backMode = mode;
}








int func_021B7C3C(void *ctx, int *state, MonolithToolProcArgs *args)
{
    MonolithToolTitle *screen;
    void *monsterName;
    void *name;
    int species;
    switch (*state) {
    case 0:
        screen = func_0203159C(ctx, sizeof(MonolithToolTitle), 0x61);
        func_02082BCC(screen, 0, sizeof(MonolithToolTitle));
        func_021B7D6C();
        func_021B7DAC(args, args->work);
        species = (int)func_021B6F2C(args);
        name = func_020457B0(8, 0x61);
        func_02045994(name, func_020084F4((const void *)species), 8);
        func_0201EE0C((struct WordSet *)args->work->wordSet, 0, name, func_02008550((const struct Sub0200852CObj *)species), 1, 2);
        func_02045808(name);
        func_021B6E1C(args->work, &screen->nameLabel, 0, 0x80, 0xc, 0x1e, 2, 0, (void *)args->work->wordSet);
        func_021B7DE0(screen, args);
        *state = *state + 1;
        break;
    case 1:
        func_02040588(2, 1);
        func_020434DC(0x10, 1);
        return 1;
    }
    return 0;
}










int func_021B7D00(int unused,int *state,MonolithToolProcArgs *args,MonolithToolTitle *screen) { if(args->topProcDone==1) return 1; func_021B6F04(args->work,&screen->nameLabel); func_021B7E3C(screen,args); switch(*state) { case 0:return 0; default:return 0; } }










int func_021B7D34(void *proc,int unused,MonolithToolProcArgs *args,MonolithToolTitle *screen) { if(func_0201C6B4(args->work->printSys)==0) return 0; func_02043534(8); func_021B7E24(screen); func_021B6EEC(&screen->nameLabel); func_021B7D98(); func_020315D4(proc); return 1; }









void func_021B7D6C(void) { func_0203FCA0(2,(const struct BgTemplate *)d_021BA928,0); func_02041300(2,0,0,0,0x20,0x20,0x11); }









void func_021B7D98(void) { func_02040588(2, 0); func_020403F4(2); }









void func_021B7DAC(MonolithToolProcArgs *args,MonolithToolWork *work) { func_020498F4(work->archive,11,2,0,0,1,0x61); func_021B7234(args,0,2); func_020409B4(2); }








void func_021B7DE0(MonolithToolTitle *screen, MonolithToolProcArgs *args)
{
    int i;
    MonolithCounts *counts = func_021B6F40(args);
    for (i = 0; i < 6; i++) {
        int icon;
        unsigned recordIndex = d_021BAA4C[i];
        icon = func_021B6F54(args->work, counts, i, (const int *)(d_021BA948 + recordIndex * 8), 0);
        screen->slotIcon[i] = (void *)icon;
    }
}









void func_021B7E24(MonolithToolTitle *screen) { int i; for(i=0;i<6;i++) func_021B6FD8(screen->slotIcon[i]); }









void func_021B7E3C(MonolithToolTitle *screen,MonolithToolProcArgs *args) { int i; MonolithCounts *counts; counts=func_021B6F40(args); for(i=0;i<6;i++) func_021B6FE0(screen->slotIcon[i],counts,i); }








int func_021B7E60(struct Proc *ctx, int unused, MonolithToolProcArgs *args)
{
    void *gameData = func_020120F4(args->setup->gameCtx);
    MonolithToolMenu *screen = func_0203159C(ctx, sizeof(MonolithToolMenu), 0x61);

    func_02082BCC(screen, 0, sizeof(MonolithToolMenu));
    if (func_020142E8((void *)func_0201296C(gameData), 0x980) == 0) {
        screen->kind = 2;
    } else if (args->setup->useSlotRecords == 1) {
        screen->kind = 1;
    } else {
        screen->kind = 0;
    }
    func_021B8308();
    func_021B8350(screen, args->work);
    func_021B81A0(args, screen);
    func_021B82E4(args, screen);
    func_02043598(0x10, 1);
    return 1;
}










int func_021B7EE0(int unused, int *state, MonolithToolProcArgs *args, MonolithToolMenu *screen)
{
    u8 *saveData;
    int touchResult;
    u32 keys;
    int touch;

    saveData = (u8 *)func_02158344(func_02012138(args->setup->gameCtx));
    func_021B82A4(args, screen);
    func_021B82FC(screen);
    if (args->abortRequested == 1) {
        return 1;
    }
    switch (*state) {
    case 0:
        touchResult = func_02035C08(&d_021BA9F8[screen->kind]);
        if (touchResult != -1) {
            screen->selected = touchResult;
            screen->result = d_021BA9C8[screen->kind][touchResult];
            func_020355D8(1);
            screen->touchArmed = 0;
            (*state)++;
            break;
        }
        keys = func_0203633C();
        touch = func_020362DC();
        if (touch > 0 && screen->touchArmed == 1) {
            func_020355D8(0);
            screen->touchArmed = 0;
            func_021B6B98(args, &screen->button[0], d_021BA978[screen->kind], screen->selected, 3);
            func_020061E4(0x548);
            break;
        }
        if (touch & 1) {
            screen->result = d_021BA9C8[screen->kind][screen->selected];
            (*state)++;
        } else if (touch & 2) {
            screen->result = 3;
            (*state)++;
        } else if (keys & 0x80) {
            screen->selected++;
            if (screen->selected >= d_021BA978[screen->kind]) {
                screen->selected = 0;
            }
            func_021B6B98(args, &screen->button[0], d_021BA978[screen->kind], screen->selected, 3);
            func_020061E4(0x548);
        } else if (keys & 0x40) {
            screen->selected--;
            if (screen->selected < 0) {
                screen->selected = d_021BA978[screen->kind] - 1;
            }
            func_021B6B98(args, &screen->button[0], d_021BA978[screen->kind], screen->selected, 3);
            func_020061E4(0x548);
        }
        break;
    case 1:
        if (screen->result == 0) {
            if (args->setup->useSlotRecords == 0) {
                (*state)--;
                break;
            }
            if (saveData != 0 && func_02175B14(saveData + 0x1ac) == 1) {
                func_020061E4(0x54c);
                func_021B83CC(screen, args->work, 4);
                *state = 3;
                break;
            }
        }
        if (screen->result != 3) {
            func_021B6BEC(args, &screen->button[0], d_021BA978[screen->kind], screen->selected, 3);
            func_020061E4(0x54c);
        } else {
            func_021B7108(&screen->cursorBlink);
            func_020061E4(0x551);
        }
        (*state)++;
        break;
    case 2:
        if (screen->result != 3) {
            if (func_021B6C74(args, 3) != 2) {
                args->requestedScreen = screen->result + 1;
                return 1;
            }
        } else {
            if (func_021B7114(&screen->cursorBlink) == 0) {
                args->requestedScreen = screen->result + 1;
                return 1;
            }
        }
        break;
    case 3:
        if (func_021B8434(args->work, screen) == 1) {
            if (func_02035C60() != 0 || (func_020362DC() & 3) != 0) {
                func_021B8440(screen);
                func_020061E4(0x547);
                *state = 0;
            }
        }
        break;
    }
    return 0;
}








int func_021B8150(void *proc, int unused, MonolithToolProcArgs *args, MonolithToolMenu *screen)
{

    if (func_0201C6B4(args->work->printSys) == 0) {
        return 0;
    }
    func_020435F4(8);
    if (screen->messageBox != 0) {
        func_0201CE48(screen->messageBox);
    }
    if (screen->messageText != 0) {
        func_02045808(screen->messageText);
    }
    func_021B8270(screen);
    func_021B82F0(screen);
    func_021B83C0(screen);
    func_021B833C();
    func_020315D4(proc);
    return 1;
}









void func_021B81A0(MonolithToolProcArgs *args, MonolithToolMenu *screen)
{
    unsigned i;
    unsigned kind;

    func_021B6C54(args);
    for (i = 0; i < d_021BA978[screen->kind]; i++) {
        kind = screen->kind;
        if (kind == 1) {
            func_021B6A0C(args->work, &screen->button[i], 1, 1, 0x80, d_021BA9A4[kind][i], i + 1, 0);
        } else if (kind == 0) {
            func_021B6A0C(args->work, &screen->button[i], 1, 1, 0x80, d_021BA9A4[kind][i], i + 2, 0);
        } else if (kind == 2) {
            func_021B6A0C(args->work, &screen->button[i], 1, 1, 0x80, d_021BA9A4[kind][i], i == 0 ? 1 : 3, 0);
        }
    }
    if (func_020355C4() == 0) {
        func_021B6B98(args, &screen->button[0], d_021BA978[screen->kind], 0, 3);
        screen->touchArmed = 0;
    } else {
        screen->touchArmed = 1;
    }
}








void func_021B8270(MonolithToolMenu *screen) { unsigned i; for(i=0;i<d_021BA978[screen->kind];i++) func_021B6B38(&screen->button[i]); }







void func_021B82A4(MonolithToolProcArgs *args, MonolithToolMenu *screen)
{
    unsigned i;

    func_021B6C7C(args, 3);
    for (i = 0; i < d_021BA978[screen->kind]; i++) {
        func_021B6B70(args->work, &screen->button[i]);
    }
}







/*
 * Tail call to func_021B7070(word at 0x4, a + 0x34).
 */
void func_021B82E4(MonolithToolProcArgs *args, MonolithToolMenu *screen)
{
    func_021B7070(args->work, &screen->cursorBlink);
}







void func_021B82F0(MonolithToolMenu *screen)
{
    func_021B70B8(&screen->cursorBlink);
}







void func_021B82FC(MonolithToolMenu *screen)
{
    func_021B70C4(&screen->cursorBlink);
}








void func_021B8308(void) { func_0203FCA0(5,(const struct BgTemplate *)d_021BA984,0); func_02041300(5,0,0,0,0x20,0x20,0x11); func_02040588(5,0); }








void func_021B833C(void) { func_02040588(5, 0); func_020403F4(5); }







void func_021B8350(MonolithToolMenu *screen, MonolithToolWork *work)
{

    func_0201F554(5, 1, 0, 0x61);
    PALANM_LoadArcPaletteToSlotAt(work->palAnm, 5, func_0201F548(0), 0x61, 1, 0x20, 0xb0, 0);
    screen->window = (void *)func_020450F0(5, 1, 0x13, 0x1e, 4, 0xd, 1);
    func_02043B5C((struct Bitmap *)((int)func_02045770((struct BmpWin *)screen->window)), 0xff);
    func_02045374(screen->window);
    func_0201F73C(screen->window, 0, 1, 0xb);
}






/*
 * Tail call to func_020452E8 on the pointer loaded from offset 0x3c.
 */
void func_021B83C0(MonolithToolMenu *screen)
{
    func_020452E8(screen->window);
}






void func_021B83CC(MonolithToolMenu *screen, MonolithToolWork *work, unsigned msgId)
{
    if (screen->messageBox != 0) {
        func_02034714(d_021BABF8, 0, d_021BABF8);
    }
    func_0201DD78(1, 2, 0xf);
    screen->messageText = func_02045EC0(work->msgBank[3], msgId);
    screen->messageBox = func_0201CCE4(screen->window, 0, 0, (void *)screen->messageText, (unsigned)work->font, func_02012FFC(),
                           (void *)work->taskList, 10, 0x61, 0xf);
    func_02040588(5, 1);
}








int func_021B8434(MonolithToolWork *work, MonolithToolMenu *screen)
{
    return func_02028484((struct Blk *)work->scratchList, screen->messageBox);
}






void func_021B8440(MonolithToolMenu *screen)
{
    unsigned r = (unsigned)func_02045770(screen->window);

    if (screen->messageBox == 0) {
        func_02034714(d_021BABF8, 0, d_021BABF8);
    }
    func_0201CE48(screen->messageBox);
    screen->messageBox = 0;
    func_02045808(screen->messageText);
    screen->messageText = 0;
    func_02040588(5, 0);
    func_02043B5C((struct Bitmap *)r, 0xff);
    func_02045334(screen->window);
    func_0201DD78(0xf, 2, 0);
}






int func_021B8494(struct Proc *ctx, int *state, MonolithToolProcArgs *args, MonolithToolSummary *screen)
{
    MonolithToolSummary *created;
    int busy;
    int i;

    switch (*state) {
    case 0:
        created = func_0203159C(ctx, sizeof(MonolithToolSummary), 0x61);
        func_02082BCC(created, 0, sizeof(MonolithToolSummary));
        func_021B8650();
        func_021B86BC(args->work);
        func_021B86E8((int)args->work, created);
        func_021B8764(args->work, created);
        created->shownSlot = 0xff;
        *state = *state + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 2; i++) {
            void *printSys = args->work->printSys;
            if (screen->text[i].on != 0) {
                if (func_0201C6C4(printSys, (void *)((unsigned)func_02045770(screen->text[i].window))) == 0) {
                    func_02045334(screen->text[i].window);
                    screen->text[i].on = 0;
                }
            }
            if ((!screen->text[i].on) == 0) {
                busy = 1;
            }
        }
        if (busy == 0) {
            func_02040588(0, 1);
            func_02040588(2, 1);
            func_020434DC(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}






/*
 * Both tail returns are 0; the load of *p survives only through a
 * `switch` with a `default`, and `(!s[0xc]) == 1` keeps the boolean.
 */
int func_021B855C(int unused, int *state, MonolithToolProcArgs *args, MonolithToolSummary *screen)
{
    int saveData;
    int idleCount;
    int i;

    saveData = func_02158344(func_02012138(args->setup->gameCtx));
    idleCount = 0;
    if (args->topProcDone == 1) {
        return 1;
    }
    func_021B6F04(args->work, &screen->nameLabel);
    for (i = 0; i < 2; i++) {
        void *printSys = args->work->printSys;
        if (screen->text[i].on != 0) {
            if (func_0201C6C4(printSys, (void *)((unsigned)func_02045770(screen->text[i].window))) == 0) {
                func_02045334(screen->text[i].window);
                screen->text[i].on = 0;
            }
        }
        if ((!screen->text[i].on) == 1) {
            idleCount++;
        }
    }
    if (idleCount == 2) {
        unsigned slot = args->param->slot;
        if (screen->shownSlot != slot) {
            func_021B8798(args, args->work, screen, (u8 *)saveData, slot);
            screen->shownSlot = args->param->slot;
        }
    }
    switch (*state) {
    case 0:
        return 0;
    default:
        return 0;
    }
}







int func_021B8618(void *proc, int unused, MonolithToolProcArgs *args, MonolithToolSummary *screen)
{
    if (func_0201C6B4(args->work->printSys) == 0) return 0;
    func_02043534(8);
    func_021B8750(screen);
    func_021B869C();
    func_021B878C(screen);
    func_020315D4(proc);
    return 1;
}






void func_021B8650(void)
{

    func_0203FCA0(0, (const struct BgTemplate *)d_021BAA64, 0);
    func_0203FCA0(2, (const struct BgTemplate *)d_021BAA84, 0);
    func_02041300(0, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(2, 0, 0, 0, 0x20, 0x20, 0x11);
}







void func_021B869C(void) { func_02040588(0,0); func_02040588(2,0); func_020403F4(0); func_020403F4(2); }






void func_021B86BC(MonolithToolWork *work) { func_020498F4(work->archive,12,2,0,0,1,0x61); func_020409B4(0); func_020409B4(2); }





void func_021B86E8(int unused, MonolithToolSummary *screen)
{
    int i;

    screen->window[0] = (void *)func_020450F0(0, 2, 0, 0x1c, 3, 0xd, 1);
    func_02045334((struct BmpWin *)screen->window[0]);
    func_02045374(screen->window[0]);
    screen->window[1] = (void *)func_020450F0(0, 2, 5, 0x1c, 0x10, 0xd, 1);
    func_02045334((struct BmpWin *)screen->window[1]);
    func_02045374(screen->window[1]);
    for (i = 0; i < 2; i++) {
        screen->text[i].window = screen->window[i];
        screen->text[i].on = 0;
    }
    func_020409B4(0);
}






void func_021B8750(MonolithToolSummary *screen) { func_020452E8(screen->window[0]); func_020452E8(screen->window[1]); }






void func_021B8764(MonolithToolWork *work, MonolithToolSummary *screen) { func_021B6E1C(work, &screen->nameLabel, 1, 0x80, 0xb4, 0x1c, 2, 0x13, 0); }





/*
 * Tail call to func_021B6EEC((char *)p + 0x18).
 */
void func_021B878C(MonolithToolSummary *screen)
{
    func_021B6EEC(&screen->nameLabel);
}





/*
 * The `src + 0x18` is written in each arm (the compiler tail-merges the
 * adds at the join), the bitfield `y` is read into a local before the
 * first call, and `q->f8` goes through a local reassigned before each
 * draw call so it loads ahead of the nested call.
 */
void func_021B8798(MonolithToolProcArgs *args, MonolithToolWork *work, MonolithToolSummary *screen, u8 *saveData, unsigned slot)
{
    void *numberText;
    u8 *src;
    MonolithToolSlotInfo *info;
    u32 detailId;
    void *labelText;
    void *detailText;
    void *printSys;

    numberText = func_020457B0(0x100, 0x61);
    func_02043B5C(func_02045770(screen->window[0]), 0);
    func_02043B5C(func_02045770(screen->window[1]), 0);
    if (slot == 6 && saveData != 0 && func_02175B14(saveData + 0x1AC) == 1) {
        info = (MonolithToolSlotInfo *)func_02175B34(saveData + 0x1AC);
        src = (u8 *)info + 0x18;
    } else {
        if (slot > 6) {
            slot = 0;
        }
        info = (MonolithToolSlotInfo *)&work->slotRecord[d_021BAA4C[slot]];
        src = (u8 *)args->setup + 0x18;
    }
    detailId = info->detailId;
    labelText = func_02045EC0(work->msgBank[0], info->labelId);
    detailText = func_02045EC0(work->msgBank[0], detailId);
    func_021762D8(info, src, work->wordSet, 0x61);
    func_0201F250(work->wordSet, numberText, detailText);
    printSys = work->printSys;
    func_0201C6FC(printSys, func_02045770(screen->text[0].window), 0, 4, labelText, (u32)work->font);
    screen->text[0].on = 1;
    printSys = work->printSys;
    func_0201C6FC(printSys, func_02045770(screen->text[1].window), 0, 0, numberText, (u32)work->font);
    screen->text[1].on = 1;
    func_02045808(labelText);
    func_02045808(detailText);
    func_02045808(numberText);
}





/*
 * Twin of func_021B8494 (six handle slots at +0x18 instead of two at +8).
 */
int func_021B889C(struct Proc *ctx, int *state, MonolithToolProcArgs *args, MonolithToolStats *screen)
{
    MonolithToolStats *created;
    int busy;
    int i;

    switch (*state) {
    case 0:
        created = func_0203159C(ctx, sizeof(MonolithToolStats), 0x61);
        func_02082BCC(created, 0, sizeof(MonolithToolStats));
        func_021B8A70();
        func_021B8ADC(args->work);
        func_021B8B08((int)args->work, created);
        func_021B8EC4(args, created);
        func_021B8C0C(args, args->work, created);
        *state = *state + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 6; i++) {
            void *printSys = args->work->printSys;
            if (screen->text[i].on != 0) {
                if (func_0201C6C4(printSys, (void *)((unsigned)func_02045770(screen->text[i].window))) == 0) {
                    func_02045334(screen->text[i].window);
                    screen->text[i].on = 0;
                }
            }
            if ((!screen->text[i].on) == 0) {
                busy = 1;
            }
        }
        if (busy == 0) {
            func_02040588(4, 1);
            func_02040588(6, 1);
            func_02043598(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}





/*
 * `func_020355D8(0)`/`func_020355D8(1)` in the arms of `if (t & 2)`: the
 * two calls tail-merge into one `blx` with the then-arm's `movs r0, #0`
 * falling through; every ternary or `!` spelling of the argument emits
 * `bne` to the 1 instead (same size, polarity flipped).
 */
int func_021B8968(int unused, int *state, MonolithToolProcArgs *args, MonolithToolStats *screen)
{
    int i;
    int touch;

    if (args->abortRequested == 1) {
        return 1;
    }
    for (i = 0; i < 6; i++) {
        void *printSys = args->work->printSys;
        if (screen->text[i].on != 0) {
            if (func_0201C6C4(printSys, (void *)((unsigned)func_02045770(screen->text[i].window))) == 0) {
                func_02045334(screen->text[i].window);
                screen->text[i].on = 0;
            }
        }
    }
    func_021B8EDC(screen);
    switch (*state) {
    case 0:
        touch = func_020362DC();
        if (func_02035C08(d_021BAAA4) != -1 || (touch & 2) != 0) {
            func_021B7108(&screen->cursorBlink);
            if (touch & 2) {
                func_020355D8(0);
            } else {
                func_020355D8(1);
            }
            func_020061E4(0x551);
            *state = *state + 1;
        }
        break;
    case 1:
        if (func_021B7114(&screen->cursorBlink) == 0) {
            args->requestedScreen = 0;
            return 1;
        }
        break;
    }
    return 0;
}






int func_021B8A38(void *proc, int unused, MonolithToolProcArgs *args, MonolithToolStats *screen)
{
    if (func_0201C6B4(args->work->printSys) == 0) return 0;
    func_020435F4(8);
    func_021B8ED0(screen);
    func_021B8BF4(screen);
    func_021B8ABC();
    func_020315D4(proc);
    return 1;
}







void func_021B8A70(void)
{
    func_0203FCA0(4, (const struct BgTemplate *)d_021BAAB8, 0);
    func_0203FCA0(6, (const struct BgTemplate *)d_021BAAD8, 0);
    func_02041300(4, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
}






void func_021B8ABC(void) { func_02040588(4,0); func_02040588(6,0); func_020403F4(4); func_020403F4(6); }






void func_021B8ADC(MonolithToolWork *work) { func_020498F4(work->archive,5,6,0,0,1,0x61); func_020409B4(6); func_020409B4(4); }




/*
 * Six-window twin of func_021B86E8.
 */
void func_021B8B08(int unused, MonolithToolStats *screen)
{
    int i;

    screen->window[0] = (void *)func_020450F0(4, 2, 0x0, 0x1e, 0x3, 0xd, 1);
    func_02045334((struct BmpWin *)screen->window[0]);
    func_02045374(screen->window[0]);
    screen->window[1] = (void *)func_020450F0(4, 2, 0x5, 0x1e, 0x2, 0xd, 1);
    func_02045334((struct BmpWin *)screen->window[1]);
    func_02045374(screen->window[1]);
    screen->window[2] = (void *)func_020450F0(4, 2, 0x8, 0x1e, 0x2, 0xd, 1);
    func_02045334((struct BmpWin *)screen->window[2]);
    func_02045374(screen->window[2]);
    screen->window[3] = (void *)func_020450F0(4, 2, 0xe, 0x1e, 0x4, 0xd, 1);
    func_02045334((struct BmpWin *)screen->window[3]);
    func_02045374(screen->window[3]);
    screen->window[4] = (void *)func_020450F0(4, 2, 0x10, 0x1e, 0x2, 0xd, 1);
    func_02045334((struct BmpWin *)screen->window[4]);
    func_02045374(screen->window[4]);
    screen->window[5] = (void *)func_020450F0(4, 2, 0x12, 0x1e, 0x2, 0xd, 1);
    func_02045334((struct BmpWin *)screen->window[5]);
    func_02045374(screen->window[5]);
    for (i = 0; i < 6; i++) {
        screen->text[i].window = screen->window[i];
        screen->text[i].on = 0;
    }
    func_020409B4(4);
}






void func_021B8BF4(MonolithToolStats *screen) { int i; for (i=0;i<6;i++) func_020452E8(screen->window[i]); }







static inline void drawText(MonolithToolWork *work, void *window, u32 x, u32 y, void *text)
{
    void *printSys = work->printSys;
    func_0201C6FC(printSys, func_02045770(window), x, y, text, (u32)work->font);
}







/*
 * Each window draw is a `static inline` (drawText) whose `printSys` local gets its own
 * spill slot per inlined copy (seven slots, 0x24 down to 0xc).
 */
void func_021B8C0C(MonolithToolProcArgs *args, MonolithToolWork *work, MonolithToolStats *screen)
{
    MonolithCounts *counts;
    s64 seconds;
    u32 hours;
    u32 minutes;
    void *labelText;
    void *lineText;

    func_021B6F2C(args);
    counts = func_021B6F40(args);
    labelText = func_020457B0(0x100, 0x61);
    lineText = func_020457B0(0x100, 0x61);
    func_02045CAC(work->msgBank[3], 0xd, labelText);
    drawText(work, screen->text[0].window, 0, 4, labelText);
    screen->text[0].on = 1;
    func_02045CAC(work->msgBank[3], 5, labelText);
    func_0201EFA4(work->wordSet, 0, counts->limit + counts->current, 5, 0, 1);
    func_0201F250(work->wordSet, lineText, labelText);
    drawText(work, screen->text[1].window, 0, 0, lineText);
    screen->text[1].on = 1;
    func_02045CAC(work->msgBank[3], 9, labelText);
    func_0201EFA4(work->wordSet, 0, counts->limit, 4, 0, 1);
    func_0201F250(work->wordSet, lineText, labelText);
    drawText(work, screen->text[2].window, 0, 0, lineText);
    screen->text[2].on = 1;
    func_02045CAC(work->msgBank[3], 8, labelText);
    func_0201EFA4(work->wordSet, 0, counts->current, 4, 0, 1);
    func_0201F250(work->wordSet, lineText, labelText);
    drawText(work, screen->text[2].window, 0x78, 0, lineText);
    screen->text[2].on = 1;
    seconds = args->setup->playSeconds;
    hours = seconds / 60 / 60;
    if (hours > 999) {
        hours = 999;
        minutes = 59;
    } else {
        seconds -= hours * 3600;
        minutes = seconds / 60;
    }
    func_02045CAC(work->msgBank[3], 0xb, labelText);
    func_0201EFA4(work->wordSet, 0, hours, 3, 1, 1);
    func_0201EFA4(work->wordSet, 1, minutes, 2, 2, 1);
    func_0201F250(work->wordSet, lineText, labelText);
    drawText(work, screen->text[3].window, 0, 0, lineText);
    screen->text[3].on = 1;
    func_02045CAC(work->msgBank[3], 0xc, labelText);
    func_0201EFA4(work->wordSet, 0, args->setup->recordCount, 5, 0, 1);
    func_0201F250(work->wordSet, lineText, labelText);
    drawText(work, screen->text[4].window, 0, 0, lineText);
    screen->text[4].on = 1;
    func_02045CAC(work->msgBank[3], 0xa, labelText);
    func_0201EFA4(work->wordSet, 0, func_0216FEAC(work->entryTable, func_021B6F40(args), args->setup->rankData), 4, 0, 1);
    func_0201F250(work->wordSet, lineText, labelText);
    drawText(work, screen->text[5].window, 0, 0, lineText);
    screen->text[5].on = 1;
    func_02045808(labelText);
    func_02045808(lineText);
}




/*
 * Tail call to func_021B7070(word at 0x4, a + 0x48).
 */
void func_021B8EC4(MonolithToolProcArgs *args, MonolithToolStats *screen)
{
    func_021B7070(args->work, &screen->cursorBlink);
}




/*
 * Tail call to func_021B70B8 with the pointer advanced by 0x48.  The callee
 * is an unlabelled leaf in this overlay; it is reproduced in
 * src/matched/ov071_func_021B70B8.c, whose EXACT entry attests this pool-word
 * site (`matched`).
 */
void func_021B8ED0(MonolithToolStats *screen)
{
    func_021B70B8(&screen->cursorBlink);
}




/*
 * Tail call to func_021B70C4((char *)p + 0x48).
 */
void func_021B8EDC(MonolithToolStats *screen)
{
    func_021B70C4(&screen->cursorBlink);
}







int func_021B8EE8(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithListWork *work)
{
    int busy;
    struct PrintSys *printSys;
    Bool finished;

    switch (*state) {
    case 0:
        work = func_0203159C(proc, sizeof(MonolithListWork), 0x61);
        func_02082BCC(work, 0, sizeof(MonolithListWork));
        work->scrollPos = 0x800;
        work->chosenEntry = MONOLITH_CURSOR_NONE;
        work->prevCursor = MONOLITH_CURSOR_NONE;
        work->lastCursor = MONOLITH_CURSOR_NONE;
        func_021B6C54(args);
        work->entryNameBank = func_02045B38(0, 2, 0xa0, 0x61);
        func_021B9560();
        func_021B95FC(work, args->work);
        func_021B96A4(work, args->work);
        func_021BA11C(work);
        func_021B9BB8(args, work);
        func_021B9AE4(work, args->work);
        func_021B9B64(args, work);
        func_021B9BE8(args, work);
        func_021B9750(args, work);
        work->taskMenuUnit = func_021B7174((u32 *)args->work, 4, 0x61);
        args->param->selected = MONOLITH_ENTRY_NONE;
        work->task = func_020056A0((void (*)(void))func_021BA1B0, work, 3);
        func_021B9970(args, work, args->work);
        func_021B992C(work);
        *state = *state + 1;
        break;
    case 1:
        if (func_021B9A40(work, args->work) == 1) {
            func_021BA140(work);
            work->uploadPending = 1;
            if (func_020355C4() == 0) {
                func_021B9F2C(work, 1, 0);
            } else {
                func_021B9F2C(work, MONOLITH_CURSOR_NONE, 0);
            }
            *state = *state + 1;
        }
        break;
    case 2:
        busy = 0;
        printSys = args->work->printSys;
        if (work->statusPending != 0) {
            if (func_0201C6C4(printSys, func_02045770(work->statusWindow)) == 0) {
                func_02045334(work->statusWindow);
                work->statusPending = 0;
            }
        }
        finished = work->statusPending == 0 ? B_TRUE : B_FALSE;
        if (finished == B_FALSE) {
            busy = 1;
        }
        if (busy == 0) {
            func_02040588(4, 1);
            func_02040588(5, 1);
            func_02040588(6, 1);
            func_02043598(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}






/*
 * extent: final halfword at 021B94CA is alignment padding.
 * lever: state9 writes its state10 tail twice, one reached by goto, preserving the cross-jump.
 */
int func_021B9070(int unused, int *state, MonolithToolProcArgs *args, MonolithListWork *work)
{
    u32 initial, mask, save;
    int active, result;
    struct PrintSys *printSys;

    initial = func_02158344(func_02012138(args->setup->gameCtx));
    func_021B6C7C(args, 1);
    func_021B6C7C(args, 3);
    func_021B9BD8(work);
    func_021B9BAC(args->work, work);
    printSys = args->work->printSys;
    if (work->statusPending != 0 && func_0201C6C4(printSys, func_02045770(work->statusWindow)) == 0) {
        func_02045334(work->statusWindow);
        work->statusPending = 0;
    }
    if (args->abortRequested == 1 && *state == 4) return 1;
    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        func_021B9798(work, args->work, 0x25);
        ++*state;
        break;
    case 2:
        if (func_021B98B4(args->work, work) == 1 && (func_02035C60() != 0 || (func_020362DC() & 3))) {
            func_021B98C4(work);
            func_020061E4(0x547);
            if (func_02035C60() == 0) func_021B9F2C(work, 1, 0);
            else func_021B9F2C(work, MONOLITH_CURSOR_NONE, 0);
            ++*state;
        }
        break;
    case 3:
        if (func_02035C38() == 0 && !(func_0203630C() & 3)) *state = 4;
        break;
    case 4:
        mask = func_020362DC();
        active = func_02035C08(d_021BAAFC);
        if (active == 0 || (mask & 2)) {
            func_021B7108(&work->marker);
            if (active == 0) func_020355D8(TRUE);
            else func_020355D8(FALSE);
            func_020061E4(0x551);
            *state = 17;
            break;
        }
        func_021B9C7C(args, work);
        func_021BA004(work);
        if (func_021BA0CC(work, work->scrollVelocity + work->scrollRequest) == 1) {
            func_021BA11C(work);
            func_021BA140(work);
            work->uploadPending = 1;
        }
        func_021BA01C(args, work);
        if (work->cursor == MONOLITH_CURSOR_NONE) {
            args->param->selected = MONOLITH_ENTRY_NONE;
        } else {
            args->param->selected = work->entryIds[work->cursor];
            args->param->mode = work->entryDisabled[work->cursor];
            if (work->entryDisabled[work->cursor] == 0) {
                func_021B6B58(&work->backButton, 1);
                goto selected;
            }
        }
        func_021B6B58(&work->backButton, 0);
selected:
        if (work->chosenEntry != MONOLITH_CURSOR_NONE) {
            func_020061E4(MONOLITH_SE_CONFIRM);
            *state = 5;
        }
        break;
    case 5:
        if (func_021B6C74(args, 1) != 2 && func_021B6C74(args, 3) != 2) {
            func_021B9798(work, args->work, 0x20);
            ++*state;
        }
        break;
    case 6:
        if (func_021B98B4(args->work, work) == 1) {
            if (work->yesNoMenu != 0) func_02034714((const char *)d_021BABFC, 0, (const char *)d_021BABFC);
            work->yesNoMenu = func_021B7194((int *)args->work, work->taskMenuUnit, 0x61);
            ++*state;
        }
        break;
    case 7:
        if (func_021B7204(args->work, 4, work->yesNoMenu, &result) == 1) {
            func_021B71FC(work->yesNoMenu);
            work->yesNoMenu = 0;
            func_021B98C4(work);
            if (result == 1) *state = 8;
            else {
                work->chosenEntry = MONOLITH_CURSOR_NONE;
                func_021B6C30(args, 1, 1);
                func_021B6B98(args, &work->backButton, 1, 0xff, 3);
                *state = 4;
            }
        }
        break;
    case 8:
        if (func_021B6C74(args, 1) != 2 && func_021B6C74(args, 3) != 2) {
            func_0201F184(args->work->wordSet, 0, work->entryIds[work->chosenEntry]);
            func_021B9818(work, args->work, 0x23);
            *state = 9;
        }
        break;
    case 9:
        if (initial == 0) goto write10;
        if (INTRUDE_COMM_SendPairMessage(args->setup->areaId) == 1) {
            *state = 10;
            break;
        }
        break;
write10:
        *state = 10;
        break;
    case 10:
        if (func_021B98B4(args->work, work) == 1) {
            GFL_USE_FadeOutBgm(6);
            ++*state;
        }
        break;
    case 11:
        if (GFL_USE_IsBgmFading() == 0) {
            GFL_USE_SetBgmPlayerParam((void *)1);
            GFL_USE_PushBgm();
            ++*state;
        }
        break;
    case 12:
        GFL_USE_CancelChangeAndPlayBgm(0x531, 0xffff);
        ++*state;
        break;
    case 13:
        if (func_02005F38() == 0) {
            GFL_USE_PopBgm();
            GFL_USE_SetBgmPlayerParam(0);
            GFL_USE_FadeInBgmFull(6);
            ++*state;
        }
        break;
    case 14:
        if (GFL_USE_IsBgmFading() == 0) *state = 15;
        break;
    case 15:
        if (func_02035C60() != 0 || (func_020362DC() & 3)) {
            func_021B98C4(work);
            func_0200BF08((struct Rec1B0 *)func_0200BE48(func_02012EBC(func_020120F4(args->setup->gameCtx))), work->entryIds[work->chosenEntry]);
            save = func_02012138(args->setup->gameCtx);
            GAME_COMM_PushPairMessage(save, func_02012B58(func_020120F4(args->setup->gameCtx)), args->setup->areaId);
            work->chosenEntry = MONOLITH_CURSOR_NONE;
            func_021B6C30(args, 1, 1);
            func_021B6B98(args, &work->backButton, 1, 0xff, 3);
            if (func_02035C60() != 0) *state = 16;
            else *state = 17;
        }
        break;
    case 16:
        if (func_02035C38() == 0) *state = 17;
        break;
    case 17:
        if (func_021B6C74(args, 1) != 2 && func_021B6C74(args, 3) != 2 && func_021B7114(&work->marker) == 0) {
            args->requestedScreen = 0;
            return 1;
        }
        break;
    }
    func_021B9C30(work);
    return 0;
}







int func_021B94CC(void *proc, void *unused, MonolithToolProcArgs *args, MonolithListWork *work)
{
    if (func_0201C6B4(args->work->printSys) == 0)
        return 0;
    func_020435F4(8);
    func_02030EAC((struct Node *)work->task);
    if (work->messagePrinter != 0)
        func_0201CE48(work->messagePrinter);
    if (work->messageText != 0)
        func_02045808(work->messageText);
    func_021B9A18(work);
    if (work->yesNoMenu != 0)
        func_021B71FC(work->yesNoMenu);
    func_021B718C(work->taskMenuUnit);
    func_021B9BA0(work);
    func_021B9B3C(work);
    func_021B9BC8(work);
    func_021B9C1C(work);
    func_021B9694(work);
    func_021B9734(work);
    func_021B95CC();
    func_02045C04(work->entryNameBank);
    func_020315D4(proc);
    return 1;
}







void func_021B9560(void)
{
    func_0203FCA0(4, (const struct BgTemplate *)d_021BAB28, 0);
    func_0203FCA0(5, (const struct BgTemplate *)d_021BAB48, 0);
    func_0203FCA0(6, (const struct BgTemplate *)((char *)&d_021BAB68), 0);
    func_02041300(4, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(6, 0, 0, 0, 0x20, 0x20, 0x11);
}






void func_021B95CC(void) { func_02040588(4,0); func_02040588(5,0); func_02040588(6,0); func_020403F4(4); func_020403F4(5); func_020403F4(6); }







void func_021B95FC(MonolithListWork *work, MonolithToolWork *toolWork)
{
    void *res;

    func_020498F4(toolWork->archive, 7, 6, 0, 0, 1, 0x61);
    func_02049658(toolWork->archive, 0xe, 5, 0, 0, 1, 0x61);
    func_020498F4(toolWork->archive, 9, 5, 0, 0, 1, 0x61);
    res = func_020490F4(0x53, 0x61);
    work->bgCharOffset = func_0203FA08(5, 0x80, 1);
    func_02049658(res, 0x1c, 5, work->bgCharOffset, 0x80, 0, 0x61);
    func_02027634(res, 5, 0x61, work->bgCharOffset, 0xc);
    func_02049238(res);
    func_020409B4(5);
    func_020409B4(6);
}






void func_021B9694(MonolithListWork *work) { func_0203FB44(5, work->bgCharOffset, 0x80); }







void func_021B96A4(MonolithListWork *work, MonolithToolWork *toolWork)
{
    func_0201F554(4, 1, 0, 0x61);
    PALANM_LoadArcPaletteToSlotAt(toolWork->palAnm, 5, func_0201F548(0), 0x61, 1, 0x20, 0xb0, 0);
    work->messageWindow = func_020450F0(4, 1, 0x13, 0x1e, 4, 0xd, 1);
    func_02043B5C(func_02045770(work->messageWindow), 0xff);
    work->titleWindow = func_020450F0(4, 0, 0, 0x20, 3, 0xd, 1);
    func_02045374(work->titleWindow);
    func_020409B4(4);
    work->statusWindow = work->titleWindow;
    work->statusPending = 0;
}






void func_021B9734(MonolithListWork *work) { int i; for (i=0;i<2;i++) func_020452E8((&work->messageWindow)[i]); }





void func_021B9750(MonolithToolProcArgs *args, MonolithListWork *work)
{
    struct Strbuf *text;
    MonolithToolWork *toolWork;
    struct PrintSys *printSys;

    text = func_02045EC0(args->work->msgBank[3], 0x22);
    toolWork = args->work;
    printSys = toolWork->printSys;
    func_0201C6FC(printSys, func_02045770(work->statusWindow), 0x18, 4, text, (u32)toolWork->font);
    work->statusPending = 1;
    func_02045808(text);
}





void func_021B9798(MonolithListWork *work, MonolithToolWork *toolWork, u32 msgId)
{
    if (work->messagePrinter != 0)
        func_02034714(d_021BABFC, 0, d_021BABFC);
    func_0201DD78(1, 2, 0xf);
    work->messageText = func_02045EC0(toolWork->msgBank[3], msgId);
    work->messagePrinter = func_0201CCE4(work->messageWindow, 0, 0, work->messageText, (u32)toolWork->font, func_02012FFC(), toolWork->taskList, 0xa, 0x61, 0xf);
    func_02045374(work->messageWindow);
    func_0201F73C(work->messageWindow, 1, 1, 0xb);
}





void func_021B9818(MonolithListWork *work, MonolithToolWork *toolWork, u32 msgId)
{
    struct Strbuf *format;

    if (work->messagePrinter != 0)
        func_02034714(d_021BABFC, 0, d_021BABFC);
    func_0201DD78(1, 2, 0xf);
    format = func_02045EC0(toolWork->msgBank[3], msgId);
    work->messageText = func_020457B0(0x100, 0x61);
    func_0201F250(toolWork->wordSet, work->messageText, format);
    func_02045808(format);
    work->messagePrinter = func_0201CCE4(work->messageWindow, 0, 0, work->messageText, (u32)toolWork->font, func_02012FFC(), toolWork->taskList, 0xa, 0x61, 0xf);
    func_02045374(work->messageWindow);
    func_0201F73C(work->messageWindow, 1, 1, 0xb);
}




/*
 * leaf: unlabelled tail stub called by func_021B9070; parent confirmed unowned.
 */
int func_021B98B4(MonolithToolWork *toolWork, MonolithListWork *work)
{
    return func_02028484((struct Blk *)toolWork->scratchList, work->messagePrinter);
}





void func_021B98C4(MonolithListWork *work)
{
    struct Bitmap *bitmap;

    bitmap = func_02045770(work->messageWindow);
    if (work->messagePrinter == 0)
        func_02034714(d_021BABFC, 0, d_021BABFC);
    func_0201CE48(work->messagePrinter);
    work->messagePrinter = 0;
    func_02045808(work->messageText);
    work->messageText = 0;
    func_0201F7A8(work->messageWindow, 0);
    func_02043B5C(bitmap, 0xff);
    func_02045334(work->messageWindow);
    func_0201DD78(0xf, 2, 0);
}





void func_021B992C(MonolithListWork *work)
{
    int count;
    int offset;

    count = work->entryCount;
    if (count - 2 < 7) {
        offset = (count - 1) * 32 / 8;
        func_02041300(6, 0, 0, (u8)offset, 0x20, 0x20 - offset, 0x11);
        func_020409B4(6);
    }
}





void func_021B9970(MonolithToolProcArgs *args, MonolithListWork *work, MonolithToolWork *toolWork)
{
    Idx i = 0;
    int n;
    int kind;
    MonolithCounts *counts;

    func_020120F4(args->setup->gameCtx);
    counts = func_021B6F40(args);
    work->entryIds[0] = i;
    work->entryDisabled[0] = 1;
    work->entryBitmaps[0] = func_02043678(0x17, 2, 0x20, 0x61);
    n = i + 1;
    for (; i < MONOLITH_ENTRY_NONE; i++) {
        kind = func_0216FE2C(toolWork->entryTable, i, counts, args->setup->rankData);
        if (kind != 2) {
            work->entryIds[n] = i;
            work->entryDisabled[n] = kind;
            work->entryBitmaps[n] = func_02043678(0x17, 2, 0x20, 0x61);
            n++;
        }
    }
    work->entryIds[n] = 0;
    work->entryDisabled[n] = 1;
    work->entryBitmaps[n] = func_02043678(0x17, 2, 0x20, 0x61);
    work->entryCount = n + 1;
}




void func_021B9A18(MonolithListWork *work) { int i; for (i = 0; i < work->entryCount; i++) func_020437AC(work->entryBitmaps[i]); }





int func_021B9A40(MonolithListWork *work, MonolithToolWork *toolWork)
{
    int count;
    int i;
    struct Strbuf *text;

    count = 0;
    text = func_020457B0(0x20, 0x61);
    i = work->loadedCount;
    if (i < work->entryCount) {
        do {
            if (i >= 1 && i < work->entryCount - 1) {
                func_02045CAC(work->entryNameBank, work->entryIds[i], text);
                func_0201C7D0(work->entryBitmaps[i], 0, 0, text, (void *)toolWork->font,
                              d_021BAAF8[work->entryDisabled[i]]);
            }
            count++;
            if (count >= 3)
                break;
            i++;
        } while (i < work->entryCount);
    }
    func_02045808(text);
    work->loadedCount = i;
    return work->loadedCount >= work->entryCount;
}


void func_021B9AE4(MonolithListWork *work, MonolithToolWork *toolWork)
{
    int i;
    struct MonolithToolGridParam param;

    param = d_021BAB10;
    param.palette = toolWork->actorRes[1].simplePalAnm;
    for (i = 0; i < MONOLITH_ROW_GRIDS; i++) {
        work->rowBitmaps[i] = func_02043678(0x17, 2, 0x20, 0x61);
        param.bitmap = work->rowBitmaps[i];
        work->rowGrids[i] = func_020255A0(toolWork->actorToolUnit, &param);
    }
}

void func_021B9B3C(MonolithListWork *work)
{
    int i;

    for (i = 0; i < MONOLITH_ROW_GRIDS; i++) {
        func_0202570C(work->rowGrids[i]);
        func_020437AC(work->rowBitmaps[i]);
    }
}

void func_021B9B64(MonolithToolProcArgs *args, MonolithListWork *work)
{
    func_021B6A0C(args->work, &work->backButton, 1, 2, 0x40, 0xb4, 0x24, 0);
    if (func_020355C4() == 1)
        func_021B6B58(&work->backButton, 0);
}

void func_021B9BA0(MonolithListWork *work)
{
    func_021B6B38(&work->backButton);
}

void func_021B9BAC(MonolithToolWork *toolWork, MonolithListWork *work)
{
    func_021B6B70(toolWork, &work->backButton);
}

void func_021B9BB8(MonolithToolProcArgs *args, MonolithListWork *work)
{
    func_021B7070(args->work, &work->marker);
}

void func_021B9BC8(MonolithListWork *work)
{
    func_021B70B8(&work->marker);
}

void func_021B9BD8(MonolithListWork *work)
{
    func_021B70C4(&work->marker);
}

void func_021B9BE8(MonolithToolProcArgs *args, MonolithListWork *work)
{
    work->scrollUpArrow = func_021B7118(args->work, 0x80, 0x1c, 9);
    work->scrollDownArrow = func_021B7118(args->work, 0x80, 0xa4, 10);
    func_0204B3DC(work->scrollUpArrow, 0);
    func_0204B3DC(work->scrollDownArrow, 0);
}

void func_021B9C1C(MonolithListWork *work)
{
    func_021B7168(work->scrollUpArrow);
    func_021B7168(work->scrollDownArrow);
}

void func_021B9C30(MonolithListWork *work)
{
    if (work->scrollPos <= 0x800)
        func_0204B3DC(work->scrollUpArrow, 0);
    else
        func_0204B3DC(work->scrollUpArrow, 1);
    if ((work->scrollPos >> 8) >= work->entryCount * MONOLITH_ROW_HEIGHT - 200)
        func_0204B3DC(work->scrollDownArrow, 0);
    else
        func_0204B3DC(work->scrollDownArrow, 1);
    func_021B7170(work->scrollUpArrow);
    func_021B7170(work->scrollDownArrow);
}

/*
 * `touching = 0` in the key branch is what keeps r7 as the zero stored to
 * scrollVelocity/touchFrames and passed to func_020355D8; `work->scrollRequest
 * = chosen` (not 0) reloads the spilled result as in the image.
 */
int func_021B9C7C(MonolithToolProcArgs *args, MonolithListWork *work)
{
    int chosen;
    int selectedRow;
    u32 touchX;
    u32 touchY;
    int touching;
    int contentY;
    int row;
    int rowRemainder;
    int dragDistance;
    int tappedRow;

    chosen = 0;
    selectedRow = MONOLITH_CURSOR_NONE;
    work->scrollRequest = chosen;
    touching = TOUCHPANEL_GetPointCont(&touchX, &touchY);
    if (work->touchFrames == 0) {
        if (touchX < 0x18 || touchX > 0xe0) {
            touching = 0;
        }
    }
    if (func_0203630C() & (MONOLITH_KEY_A | MONOLITH_KEY_B | MONOLITH_KEY_UP | MONOLITH_KEY_DOWN)) {
        contentY = (work->scrollPos >> 8) + 0x18;
        row = contentY / MONOLITH_ROW_HEIGHT;
        rowRemainder = contentY % MONOLITH_ROW_HEIGHT;
        touching = 0;
        work->scrollVelocity = touching;
        work->touchFrames = touching;
        if (work->cursor == MONOLITH_CURSOR_NONE) {
            if (rowRemainder != 0) {
                row++;
            }
            if (row < 1) {
                row = 1;
            }
            if (row >= work->entryCount - 2) {
                func_021B9F2C(work, work->entryCount - 2, MONOLITH_INPUT_KEY);
            } else {
                func_021B9F2C(work, row, MONOLITH_INPUT_KEY);
            }
            func_020061E4(MONOLITH_SE_MOVE);
            return 0;
        }
        if (func_020362DC() & MONOLITH_KEY_A) {
            func_021B9F2C(work, work->cursor, MONOLITH_INPUT_KEY);
            func_020355D8(0);
            if (work->entryDisabled[work->cursor] == 0) {
                func_020061E4(MONOLITH_SE_CONFIRM);
            }
            return 1;
        }
        if (func_0203633C() & MONOLITH_KEY_UP) {
            if (rowRemainder != 0) {
                row++;
            }
            if (func_021B9F2C(work, work->cursor - 1, MONOLITH_INPUT_KEY) == 1) {
                func_020061E4(MONOLITH_SE_MOVE);
            }
            if (work->cursor < row) {
                work->scrollRequest = -0x2000;
            }
            return 0;
        }
        if (func_0203633C() & MONOLITH_KEY_DOWN) {
            row = ((work->scrollPos >> 8) + 0xa8) / MONOLITH_ROW_HEIGHT;
            if (func_021B9F2C(work, work->cursor + 1, MONOLITH_INPUT_KEY) == 1) {
                func_020061E4(MONOLITH_SE_MOVE);
            }
            if (work->cursor >= row) {
                work->scrollRequest = 0x2000;
            }
            return 0;
        }
    }
    if (work->touchFrames == 0) {
        if (touching == 1) {
            if (touchY > 0x18 && touchY < 0xa8) {
                work->touchFrames = 1;
                work->touchY = touchY;
                work->touchStartY = touchY;
                func_021B9F2C(work, MONOLITH_CURSOR_NONE, MONOLITH_INPUT_NONE);
            } else if (func_02035C60() == 1 && work->cursor != MONOLITH_CURSOR_NONE
                       && touchX >= 0x10 && touchX <= 0x70 && touchY >= 0xac && touchY <= 0xbc) {
                chosen = 1;
                selectedRow = work->cursor;
                func_020355D8(1);
            }
        } else if (work->scrollVelocity != 0) {
            if (work->scrollVelocity > 0) {
                work->scrollVelocity -= 0xc0;
                if (work->scrollVelocity < 0) {
                    work->scrollVelocity = 0;
                }
            } else {
                work->scrollVelocity += 0xc0;
                if (work->scrollVelocity > 0) {
                    work->scrollVelocity = 0;
                }
            }
        }
    } else if (touching == 0) {
        work->touchFrames = 0;
        if (work->touchStartY != MONOLITH_CURSOR_NONE) {
            dragDistance = work->touchY - work->touchStartY;
            if (dragDistance < 0) {
                dragDistance = -dragDistance;
            }
            if (dragDistance < 4) {
                tappedRow = func_021BA1DC(work, work->touchY);
                if (tappedRow != MONOLITH_CURSOR_NONE) {
                    chosen = 1;
                    selectedRow = tappedRow;
                    func_020061E4(MONOLITH_SE_MOVE);
                }
            }
        }
    } else {
        work->scrollVelocity = (work->touchY - touchY) << 8;
        work->touchY = touchY;
        work->touchFrames++;
        if (work->touchStartY != MONOLITH_CURSOR_NONE) {
            dragDistance = touchY - work->touchStartY;
            if (dragDistance < 0) {
                dragDistance = -dragDistance;
            }
            if (dragDistance > 4) {
                work->touchStartY = MONOLITH_CURSOR_NONE;
            }
        }
    }
    if (chosen == 1) {
        work->scrollVelocity = 0;
        func_021B9F2C(work, selectedRow, MONOLITH_INPUT_TOUCH);
    }
    return chosen;
}

int func_021B9F2C(MonolithListWork *work, int index, int inputMode)
{
    int prev;

    if (index != MONOLITH_CURSOR_NONE) {
        if (index >= work->entryCount - 1 || index < 1) {
            return 0;
        }
    }
    prev = work->cursor;
    work->prevCursor = prev;
    work->lastCursor = prev;
    work->cursor = index;
    work->cursorChanged = 1;
    work->inputMode = inputMode;
    return 1;
}

void func_021B9F74(MonolithListWork *work, int index, int palette)
{
    int scrollPixels;
    int firstRow;
    int rowOffset;
    int bgOffset;
    int rowOnScreen;

    if (index != MONOLITH_CURSOR_NONE) {
        scrollPixels = work->scrollPos >> 8;
        firstRow = scrollPixels / MONOLITH_ROW_HEIGHT;
        rowOffset = scrollPixels % MONOLITH_ROW_HEIGHT;
        bgOffset = scrollPixels % 64;
        rowOnScreen = index - firstRow;
        if (rowOnScreen >= 0 && rowOnScreen < firstRow + MONOLITH_ROW_GRIDS) {
            func_020413B0(6, 3, ((rowOnScreen * MONOLITH_ROW_HEIGHT + bgOffset - rowOffset) % 256) / 8, 0x19, 4, palette);
        }
    }
}

/*
 * Two thunks passing a constant third argument.
 */
void func_021B9FEC(MonolithListWork *work, int index)
{
    func_021B9F74(work, index, 3);
}

void func_021B9FF8(MonolithListWork *work, int index)
{
    func_021B9F74(work, index, 0);
}

void func_021BA004(MonolithListWork *work)
{
    if (work->cursorChanged == 1)
        func_021B9FF8(work, work->prevCursor);
}

void func_021BA01C(MonolithToolProcArgs *args, MonolithListWork *work)
{
    int cursor;
    int inputMode;

    if (work->cursorChanged == 1) {
        func_021B9FEC(work, work->cursor);
        cursor = work->cursor;
        if (cursor == MONOLITH_CURSOR_NONE) {
            func_021B6C30(args, 0, 1);
        } else {
            inputMode = work->inputMode;
            if ((inputMode == MONOLITH_INPUT_TOUCH && cursor == work->lastCursor)
                || (inputMode == MONOLITH_INPUT_KEY && cursor == work->prevCursor)) {
                if (work->entryDisabled[cursor] == 0) {
                    work->chosenEntry = cursor;
                    if (work->inputMode == MONOLITH_INPUT_KEY) {
                        func_021B6C48(args, 1);
                    } else {
                        func_021B6BEC(args, &work->backButton, 1, 0, 3);
                    }
                } else if (inputMode == MONOLITH_INPUT_TOUCH) {
                    func_021B6C30(args, 1, 1);
                }
            } else {
                func_021B6C30(args, 1, 1);
            }
        }
        func_02041B6C(6);
        work->cursorChanged = 0;
    }
}

int func_021BA0CC(MonolithListWork *work, int delta)
{
    int limit;
    int oldPos;

    oldPos = work->scrollPos;
    limit = work->entryCount * MONOLITH_ROW_HEIGHT - 8;
    if (limit <= 0xc0) {
        return 0;
    }
    work->scrollPos = oldPos + delta;
    if (work->scrollPos < 0x800) {
        work->scrollPos = 0x800;
    } else if (work->scrollPos > (limit - 0xc0) << 8) {
        work->scrollPos = (limit - 0xc0) << 8;
    }
    if ((work->scrollPos >> 8) != (oldPos >> 8)) {
        return 1;
    }
    return 0;
}

void func_021BA11C(MonolithListWork *work)
{
    func_02041EE4(6, 3, (work->scrollPos >> 8) % 64);
}

void func_021BA140(MonolithListWork *work)
{
    int scrollPixels = work->scrollPos >> 8;
    int gridY = 8 - scrollPixels % MONOLITH_ROW_HEIGHT;
    int firstRow = scrollPixels / MONOLITH_ROW_HEIGHT;
    int i;

    for (i = 0; i < MONOLITH_ROW_GRIDS; i++) {
        func_0202590C(work->rowGrids[i], 0x20, gridY + i * MONOLITH_ROW_HEIGHT);
        if (work->entryBitmaps[firstRow + i] != 0) {
            func_02043814(work->entryBitmaps[firstRow + i], work->rowBitmaps[i]);
        }
    }
}

void func_021BA1B0(void *task, MonolithListWork *work)
{
    int i;

    if (work->uploadPending == 1) {
        for (i = 0; i < MONOLITH_ROW_GRIDS; i++)
            func_020257D0(work->rowGrids[i]);
        work->uploadPending = 0;
    }
}

int func_021BA1DC(MonolithListWork *work, unsigned y)
{
    int row = ((work->scrollPos >> 8) + y) >> 5;

    if (row >= work->entryCount)
        row = MONOLITH_CURSOR_NONE;
    return row;
}

int func_021BA1FC(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work)
{
    MonolithInfoWork *newWork;
    int busy;
    int i;
    struct PrintSys *printSys;
    Bool finished;

    switch (*state) {
    case 0:
        newWork = func_0203159C(proc, 0x28, 0x61);
        func_02082BCC(newWork, 0, 0x28);
        newWork->shownEntry = MONOLITH_ENTRY_NONE;
        func_021BA3B4();
        func_021BA420(args->work);
        func_021BA44C(args->work, newWork);
        func_021BA4EC(args->work, newWork);
        func_021BA528(args, args->work, newWork);
        *state = *state + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 3; i++) {
            printSys = args->work->printSys;
            if (work->slots[i].pending != 0) {
                if (func_0201C6C4(printSys, func_02045770(work->slots[i].window)) == 0) {
                    func_02045334(work->slots[i].window);
                    work->slots[i].pending = 0;
                }
            }
            finished = work->slots[i].pending == 0 ? B_TRUE : B_FALSE;
            if (finished == B_FALSE) {
                busy = 1;
            }
        }
        if (busy == 0) {
            func_02040588(0, 1);
            func_02040588(2, 1);
            func_020434DC(0x10, 1);
            return 1;
        }
        break;
    }
    return 0;
}

int func_021BA2CC(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work)
{
    int i;
    u8 idle[3];
    struct PrintSys *printSys;

    if (args->topProcDone == 1) {
        return 1;
    }
    for (i = 0; i < 3; i++) {
        printSys = args->work->printSys;
        if (work->slots[i].pending != 0) {
            if (func_0201C6C4(printSys, func_02045770(work->slots[i].window)) == 0) {
                func_02045334(work->slots[i].window);
                work->slots[i].pending = 0;
            }
        }
        idle[i] = work->slots[i].pending == 0;
    }
    if (*state == 0) {
        if (args->param->activeDirty == 1 && idle[1] == 1) {
            func_021BA528(args, args->work, work);
            args->param->activeDirty = 0;
        }
        if (args->param->selected != work->shownEntry && idle[2] == 1) {
            func_021BA5D4(args, args->work, work);
            work->shownEntry = args->param->selected;
        }
        return 0;
    }
    return 0;
}

int func_021BA384(struct Proc *proc, int *state, MonolithToolProcArgs *args, MonolithInfoWork *work)
{
    if (func_0201C6B4(args->work->printSys) == 0)
        return 0;
    func_02043534(8);
    func_021BA4D4(work);
    func_021BA400();
    func_020315D4(proc);
    return 1;
}

void func_021BA3B4(void)
{
    func_0203FCA0(0, &d_021BAB94, 0);
    func_0203FCA0(2, &d_021BABB4, 0);
    func_02041300(0, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(2, 0, 0, 0, 0x20, 0x20, 0x11);
}

void func_021BA400(void)
{
    func_02040588(0, 0);
    func_02040588(2, 0);
    func_020403F4(0);
    func_020403F4(2);
}

void func_021BA420(MonolithToolWork *toolWork)
{
    func_020498F4(toolWork->archive, 13, 2, 0, 0, 1, 0x61);
    func_020409B4(0);
    func_020409B4(2);
}

void func_021BA44C(MonolithToolWork *toolWork, MonolithInfoWork *work)
{
    int i;

    work->windows[0] = func_020450F0(0, 2, 0, 0x1c, 3, 0xd, 1);
    func_02045334(work->windows[0]);
    func_02045374(work->windows[0]);
    work->windows[1] = func_020450F0(0, 2, 4, 0x1c, 8, 0xd, 1);
    func_02045334(work->windows[1]);
    func_02045374(work->windows[1]);
    work->windows[2] = func_020450F0(0, 2, 0xf, 0x1c, 9, 0xd, 1);
    func_02045334(work->windows[2]);
    func_02045374(work->windows[2]);
    for (i = 0; i < 3; i++) {
        work->slots[i].window = work->windows[i];
        work->slots[i].pending = 0;
    }
    func_020409B4(0);
}

void func_021BA4D4(MonolithInfoWork *work)
{
    int i;

    for (i = 0; i < 3; i++)
        func_020452E8(work->windows[i]);
}

/*
 * note: trailing two-byte alignment padding.
 */
void func_021BA4EC(MonolithToolWork *toolWork, MonolithInfoWork *work)
{
    struct Strbuf *text;
    struct PrintSys *printSys;

    text = func_02045EC0(toolWork->msgBank[3], 38);
    printSys = toolWork->printSys;
    func_0201C6FC(printSys, func_02045770(work->slots[0].window), 0, 4, text, (u32)toolWork->font);
    work->slots[0].pending = 1;
    func_02045808(text);
}

void func_021BA528(MonolithToolProcArgs *args, MonolithToolWork *toolWork, MonolithInfoWork *work)
{
    struct Strbuf *name;
    struct Strbuf *desc;
    u32 activeEntry;
    struct PrintSys *printSys;

    activeEntry = func_0200BF10(func_0200BE48(func_02012EBC(func_020120F4(args->setup->gameCtx))));
    func_02043B5C(func_02045770(work->windows[1]), 0);
    if (activeEntry == MONOLITH_ENTRY_NONE) {
        name = func_02045EC0(toolWork->msgBank[3], 0x27);
    } else {
        name = func_02045EC0(toolWork->msgBank[1], toolWork->entryTable[activeEntry].nameMsgId);
        desc = func_02045EC0(toolWork->msgBank[2], toolWork->entryTable[activeEntry].descMsgId);
        printSys = toolWork->printSys;
        func_0201C6FC(printSys, func_02045770(work->slots[1].window), 0, 0x10, desc, (u32)toolWork->font);
        work->slots[1].pending = 1;
        func_02045808(desc);
    }
    printSys = toolWork->printSys;
    func_0201C6FC(printSys, func_02045770(work->slots[1].window), 0, 0, name, (u32)toolWork->font);
    work->slots[1].pending = 1;
    func_02045808(name);
}


/*
 * Lever: a 12-byte MonolithEntry subscript retains the second-path scale in r0;
 * byte indexing instead adds a copy and shifts the remainder by 2 bytes.
 * Extent after 0x021BA756 is alignment and rodata, not a code follower.
 */
static inline void PrintText(MonolithToolWork *toolWork, struct BmpWin *window, u32 x, u32 y, struct Strbuf *text)
{
    struct PrintSys *queue = toolWork->printSys;
    func_0201C6FC(queue, func_02045770(window), x, y, text, (u32)toolWork->font);
}

void func_021BA5D4(MonolithToolProcArgs *args, MonolithToolWork *toolWork, MonolithInfoWork *work)
{
    u32 selected;
    struct Strbuf *desc, *format, *line;
    MonolithCounts *counts;
    u32 msgId;
    u32 cost;

    selected = args->param->selected;
    func_02043B5C(func_02045770(work->windows[2]), 0);
    if (selected != MONOLITH_ENTRY_NONE) {
        if (args->param->mode == 0) {
            func_0201EFA4(toolWork->wordSet, 0, toolWork->entryTable[selected].number, 4, 0, 1);
            desc = func_02045EC0(toolWork->msgBank[2], toolWork->entryTable[selected].descMsgId);
            format = func_02045EC0(toolWork->msgBank[3], 0x28);
            line = func_020457B0(0x40, 0x61);
            func_0201F250(toolWork->wordSet, line, format);
            PrintText(toolWork, work->slots[2].window, 0, 4, desc);
            work->slots[2].pending = 1;
            PrintText(toolWork, work->slots[2].window, 0x70, 0x34, line);
            work->slots[2].pending = 1;
            func_02045808(desc);
            func_02045808(format);
            func_02045808(line);
        } else {
            counts = func_021B6F40(args);
            cost = toolWork->entryTable[selected].costA;
            if ((int)cost > counts->current) {
                msgId = 0x29;
            } else {
                cost = toolWork->entryTable[selected].costB;
                msgId = 0x2a;
            }
            func_0201EFA4(toolWork->wordSet, 0, cost, 3, 0, 1);
            func_0201EFA4(toolWork->wordSet, 1, counts->current, 3, 0, 1);
            func_0201EFA4(toolWork->wordSet, 2, counts->limit, 3, 0, 1);
            format = func_02045EC0(toolWork->msgBank[3], msgId);
            line = func_020457B0(0x80, 0x61);
            func_0201F250(toolWork->wordSet, line, format);
            PrintText(toolWork, work->slots[2].window, 0, 4, line);
            work->slots[2].pending = 1;
            func_02045808(line);
            func_02045808(format);
        }
    } else {
        func_02045334(work->windows[2]);
    }
}
