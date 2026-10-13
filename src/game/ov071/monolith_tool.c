/*
 * file:     monolith_tool.c
 * unit:     yes
 * function: func_021B6100, func_021B6250, func_021B6458, func_021B64D0, func_021B6524, func_021B652C, func_021B6538, func_021B6540, func_021B6588, func_021B65B4, func_021B6624, func_021B6644, func_021B677C, func_021B6790, func_021B6808, func_021B6844, func_021B68B4, func_021B68E0, func_021B6960, func_021B699C, func_021B69AC, func_021B6A0C, func_021B6B38, func_021B6B58, func_021B6B70, func_021B6B98, func_021B6BEC, func_021B6C30, func_021B6C48, func_021B6C54, func_021B6C74, func_021B6C7C, func_021B6DB4, func_021B6E00, func_021B6E0C, func_021B6E18, func_021B6E1C, func_021B6EEC, func_021B6F04, func_021B6F2C, func_021B6F40, func_021B6F54, func_021B6FD8, func_021B6FE0, func_021B7014, func_021B7068, func_021B7070, func_021B70B8, func_021B70C4, func_021B7108, func_021B7114, func_021B7118, func_021B7168, func_021B7170, func_021B7174, func_021B718C, func_021B7194, func_021B71FC, func_021B7204, func_021B7234, func_021B730C, func_021B739C, func_021B7824, func_021B7880, func_021B78D4, func_021B78F4, func_021B7924, func_021B7994, func_021B79A0, func_021B7A08, func_021B7A14, func_021B7A68, func_021B7AAC, func_021B7AC4, func_021B7AE8, func_021B7B10, func_021B7B9C, func_021B7BB4, func_021B7BD8, func_021B7BE4, func_021B7BF0, func_021B7BFC, func_021B7C3C, func_021B7D00, func_021B7D34, func_021B7D6C, func_021B7D98, func_021B7DAC, func_021B7DE0, func_021B7E24, func_021B7E3C, func_021B7E60, func_021B7EE0, func_021B8150, func_021B81A0, func_021B8270, func_021B82A4, func_021B82E4, func_021B82F0, func_021B82FC, func_021B8308, func_021B833C, func_021B8350, func_021B83C0, func_021B83CC, func_021B8434, func_021B8440, func_021B8494, func_021B855C, func_021B8618, func_021B8650, func_021B869C, func_021B86BC, func_021B86E8, func_021B8750, func_021B8764, func_021B878C, func_021B8798, func_021B889C, func_021B8968, func_021B8A38, func_021B8A70, func_021B8ABC, func_021B8ADC, func_021B8B08, func_021B8BF4, func_021B8C0C, func_021B8EC4, func_021B8ED0, func_021B8EDC, func_021B8EE8, func_021B9070, func_021B94CC, func_021B9560, func_021B95CC, func_021B95FC, func_021B9694, func_021B96A4, func_021B9734, func_021B9750, func_021B9798, func_021B9818, func_021B98B4, func_021B98C4, func_021B992C, func_021B9970, func_021B9A18, func_021B9A40
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
 *   func_02031324  0x02031324  arm
 *   func_02028470  0x02028470  thumb
 *   func_020056A0  0x020056A0  thumb
 *   func_0203D34C  0x0203D34C  arm
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0202208C  0x0202208C  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0217440C  0x0217440C  thumb  ov011
 *   func_0217446C  0x0217446C  thumb  ov011
 *   func_020221A4  0x020221A4  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02031348  0x02031348  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02031330  0x02031330  arm
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
 *   func_02021EE4  0x02021EE4  thumb
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02041300  0x02041300  arm
 *   func_02040588  0x02040588  arm
 *   d_021BA794     0x021BA794  data  a4
 *   d_021BA7B4     0x021BA7B4  data  a4
 *   func_020403F4 0x020403F4 arm
 *   func_02021660  0x02021660  thumb
 *   func_020215EC  0x020215EC  thumb
 *   func_020216B4  0x020216B4  thumb
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
 *   func_0204B270  0x0204B270  arm
 *   func_02025318  0x02025318  thumb
 *   func_02025538  0x02025538  thumb
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   func_02025588 0x02025588 thumb
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02025358 0x02025358 thumb
 *   func_02025470  0x02025470  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_020254BC  0x020254BC  thumb
 *   func_02025518 0x02025518 thumb
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A648 0x0204A648 arm
 *   func_02021D50 0x02021D50 thumb
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
 *   func_02021F3C  0x02021F3C  thumb
 *   func_02021FD8  0x02021FD8  thumb
 *   d_021BABE0     0x021BABE0  data  a1
 *   d_021BA82C     0x021BA82C  data  a4
 *   func_020120F4 0x020120F4 thumb
 *   func_021583EC 0x021583EC thumb ov010
 *   func_021583CC 0x021583CC thumb ov010
 *   d_021BA844     0x021BA844  data  a2
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B8A0 0x0204B8A0 arm
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
 *   func_021761EC 0x021761EC thumb ov011
 *   func_02173E2C 0x02173E2C thumb ov011
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
 *   func_021BA11C  0x021BA11C  thumb  ov071
 *   func_021B9BB8  0x021B9BB8  thumb  ov071
 *   func_021B9AE4  0x021B9AE4  thumb  ov071
 *   func_021B9B64  0x021B9B64  thumb  ov071
 *   func_021B9BE8  0x021B9BE8  thumb  ov071
 *   func_021BA1B0  0x021BA1B0  thumb  ov071
 *   func_021BA140  0x021BA140  thumb  ov071
 *   func_021B9F2C  0x021B9F2C  thumb  ov071
 *   func_0201F184 0x0201F184 thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_02005E50 0x02005E50 thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_02005F38 0x02005F38 thumb
 *   func_02005E9C 0x02005E9C thumb
 *   func_02005DF8 0x02005DF8 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BE48 0x0200BE48 thumb
 *   func_0200BF08 0x0200BF08 thumb
 *   func_02012B58 0x02012B58 thumb
 *   func_020266AC 0x020266AC thumb
 *   func_02174660 0x02174660 thumb ov011
 *   func_021B9BD8 0x021B9BD8 thumb ov071
 *   func_021B9BAC 0x021B9BAC thumb ov071
 *   func_021B9C7C 0x021B9C7C thumb ov071
 *   func_021BA004 0x021BA004 thumb ov071
 *   func_021BA0CC 0x021BA0CC thumb ov071
 *   func_021BA01C 0x021BA01C thumb ov071
 *   func_021B9C30 0x021B9C30 thumb ov071
 *   func_02035C38 0x02035C38 arm
 *   func_0203630C 0x0203630C arm
 *   d_021BAAFC 0x021BAAFC data a4
 *   d_021BABFC 0x021BABFC data a4
 *   func_021B9BA0  0x021B9BA0  thumb  ov071
 *   func_021B9B3C  0x021B9B3C  thumb  ov071
 *   func_021B9BC8  0x021B9BC8  thumb  ov071
 *   func_021B9C1C  0x021B9C1C  thumb  ov071
 *   d_021BAB28     0x021BAB28  data  ov071  a4
 *   d_021BAB48     0x021BAB48  data  ov071  a4
 *   d_021BAB68     0x021BAB68  data  a4
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_0216FE2C  0x0216FE2C  thumb  ov010
 *   func_0201C7D0  0x0201C7D0  thumb
 *   d_021BAAF8     0x021BAAF8  data  a2
 */
#include "../../matched/include/Obj00712.h"
#include "../../matched/include/Obj02419.h"
#include "../../matched/include/Obj09885.h"
#include "../../matched/include/Obj07693.h"
#include "../../matched/include/Obj06183.h"
#include "../../matched/include/Obj13166.h"
#include "../../matched/include/Obj13167.h"
#include "../../matched/include/Obj09886.h"
#include "../../matched/include/Obj20689.h"
#include "../../matched/include/Obj13174.h"
#include "../../matched/include/Obj06184.h"
#include "../../matched/include/Obj20691.h"
#include "../../matched/include/Obj20692.h"
#include "../../matched/include/Obj20695.h"
#include "../../matched/include/Obj20703.h"
#include "../../matched/include/Obj20705.h"
#include "../../matched/include/Obj13176.h"
#include "../../matched/include/Obj20709.h"
#include "../../matched/include/Obj20710.h"
#include "../../matched/include/Obj20722.h"
#include "../../matched/include/Obj04337.h"
#include "../../matched/include/Obj20724.h"
#include "../../matched/include/Obj20725.h"
#include "../../matched/include/Obj06186.h"
#include "../../matched/include/Obj06187.h"
#include "../../matched/include/Obj20733.h"
#include "../../matched/include/Obj20734.h"
#include "../../matched/include/Obj20735.h"
#include "../../matched/include/Obj06189.h"
#include "../../matched/include/Obj07702.h"
#include "../../matched/include/Obj20739.h"
#include "../../matched/include/Obj20740.h"
#include "../../matched/include/Obj20741.h"
#include "../../matched/include/Obj06188.h"
#include "../../matched/include/Obj01884.h"
#include "../../matched/include/Obj02123.h"
#include "../../matched/include/Obj13181.h"
#include "../../matched/include/Obj03177.h"
#include "../../matched/include/Obj20746.h"
#include "../../matched/include/Obj20747.h"
#include "../../matched/include/G_Config.h"
#include "../../matched/include/Obj09894.h"
#include "../../matched/include/Obj09895.h"
#include "../../matched/include/Obj04341.h"
#include "../../matched/include/Obj13182.h"
#include "../../matched/include/Obj13183.h"
#include "../../matched/include/Obj20750.h"
#include "../../matched/include/Obj00044.h"
#include "../../matched/include/Obj09896.h"
#include "../../matched/include/Obj07704.h"
#include "../../matched/include/Obj20751.h"
#include "../../matched/include/Obj20752.h"
#include "../../matched/include/Obj04340.h"
#include "../../matched/include/Obj20753.h"
#include "../../matched/include/Obj20755.h"
#include "../../matched/include/Obj03664.h"
#include "../../matched/include/Obj09897.h"
#include "../../matched/include/Obj20756.h"

#define W(k) (*(u32 *)(o+(k)))
#define C_021B8A70(k) (*(u32 *)(c+(k)))
#define CP(k) ((u8 *)C_021B8A70(k))
struct S02021D50;
struct W6844;
struct Obj0203159C;
struct Ctx;
struct PrintSys;
struct Tcbl;
struct Node;
struct PalAnmSlot;
struct S020314B8;
struct S020315D4;
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
struct Bmp;
struct Grid;
struct Sys;
struct U16Vec;
struct Obj;
struct Obj020437AC;
struct Chan02021FD8;
struct R;
struct TaskMenuState;
struct TaskMenu;
struct TaskMenuTmpl;
struct Rec3;
struct CharBuf;
struct Descriptor;
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

struct W6844 {
    int w0;
    u8 *unk_04;
    int pad_08[3];
    void *unk_14;
    int pad_18[5];
    void *unk_2c;
};

typedef signed int     s32;

typedef enum { SLOT_FIRST, SLOT_COUNT = 2 } Slot;

typedef enum { IDX_FIRST, IDX_COUNT = 6 } Idx;

struct E24 {
    int w[6];
};

typedef signed short s16;

typedef enum { B_FALSE, B_TRUE } Bool;

struct Pair {
    int x, y;
};

struct Point {
    s16 x;
    s16 y;
    u16 f4;
    u8 f6;
    u8 f7;
};

struct Param {
    void *bmp;
    s16 x;
    s16 y;
    u32 f8;
    u32 fc;
    u8 f10;
    u8 f11;
    u16 f12;
    u32 f14;
};

typedef struct {
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
} Res;

typedef struct {
    u8 pad0[8];
    void *f8;
    void *fc;
    u8 pad10[4];
    u32 f14;
    u8 pad18[0x10];
    void *f28;
    void *f2c;
    u8 pad30[0x10];
    Res res[1];
} Ctx_021B6A0C;

typedef struct {
    void *act;
    void *grid;
    void *bmp;
    u8 on;
} Out_021B6A0C;

typedef struct {
    u16 v;
    u8 state;
    u8 dir;
    u8 timer;
    u8 cnt;
    u8 pad[2];
} Ent;

typedef struct {
    u8 pad0[8];
    void *f8;
    void *fc;
    u8 pad10[0x18];
    void *f28;
    void *f2c;
    u8 pad30[0x10];
    Res res[1];
} Ctx_021B6E1C;

typedef struct {
    void *bmp;
    void *grid;
    u8 on;
} Out_021B6E1C;

struct H4 {
    u16 a, b, c, d;
};

struct Ent {
    int w[4];
};

struct P { int w[6]; int pad[10]; struct Ent e[2]; };

typedef enum { V4 = 4, V5 = 5 } Value;

typedef struct { u16 a, b, c, d; } Rect;

typedef struct { int h; u8 a, b, c; } St;

typedef struct { void *s; u16 h; int z; } Item;

typedef struct {
    u8 pad[0xc];
    u16 n;
    u16 m;
} Counts;

typedef struct {u32 a[6];} Record;

typedef struct {void **f0;u8 *f4;u8 *f8;u8 padc[0x20];u8 f2c,f2d,f2e;} C;

typedef struct {u8 pad0[0x4c];Record rec;u16 text[10];u8 f78;u8 pad79[7];u8 f80,f81,f82,f83;} D_021B6524;

typedef struct {
    int pad[3];
    int v[6];
} S;

typedef struct {
    char pad[0x10];
    int f10;
} Inner;

typedef struct {
    int f0;
    Inner *f4;
} C_021B7AAC;

typedef struct {
    char pad[0x32];
    unsigned char f32;
} W_021B7E60;

typedef struct {
    char pad[0x3d];
    unsigned char f3d;
} Q_021B7AAC;

typedef struct {
    Q_021B7AAC *q;
    int *f4;
} C_021B7E60;

typedef signed char s8;

typedef struct {
    void **f0;
    void *f4;
    char pad8[0x24];
    u8 f2c;
    u8 f2d;
    u8 f2e;
} C_021B7EE0;

typedef struct {
    u8 pad0[0x30];
    s8 sel;
    s8 res;
    u8 kind;
    u8 armed;
    u8 f34[8];
} D_021B7AAC;

typedef struct {
    u8 b[0x14];
} Menu;

typedef struct {
    char pad[0x40];
    void *f40;
    void *f44;
} W_021B8150;

typedef struct {
    int f0;
    struct {
        char pad[8];
        void *f8;
    } *f4;
} B;

typedef struct {
    char pad[0x3c];
    int f3c;
} W_021B7AAC;

typedef struct {
    char pad[0x3c];
    void *f3c;
    void *f40;
    void *f44;
} W_021B83C0;

typedef struct {
    char pad0[0xc];
    unsigned fc;
    char pad10[8];
    unsigned f18;
    char pad1c[0xc];
    void *f28;
} X;

typedef struct {
    char pad0[8];
    void *f8;
} Q_021B83C0;

typedef struct {
    void **f0;
    Q_021B83C0 *f4;
} C_021B8494;

typedef struct {
    void **f0;
    Q_021B83C0 *f4;
    unsigned char *f8;
    char pad[0x21];
    unsigned char f2d;
} C_021B855C;

typedef struct {
    int h[2];
    struct {
        int h;
        unsigned char on;
    } e[2];
} P_021B86E8;

typedef struct {
    u32 f0;
    u32 kind : 4;
    u32 b4 : 14;
    u32 b18 : 11;
    u32 b29 : 3;
    u32 pad8[4];
} Obj;

typedef struct {
    char pad0[8];
    void *f8;
    void *fc;
    void *f10;
    char pad14[8];
    void *f1c;
    char pad20[0x40];
    Obj ent[1];
} Q_021B8798;

typedef struct {
    void *h[2];
    struct {
        void *h;
        u8 on;
    } e[2];
} P_021B8798;

typedef struct {
    char pad0[8];
    void *f8;
} Q_021B889C;

typedef struct {
    void **f0;
    Q_021B889C *f4;
} C_021B889C;

typedef struct {
    char pad0[8];
    void *f8;
} Q_021B8968;

typedef struct {
    void **f0;
    Q_021B8968 *f4;
    char pad8[0x24];
    u8 f2c;
    u8 f2d;
    u8 f2e;
} C_021B8968;

typedef struct {
    int h[6];
    struct {
        int h;
        unsigned char on;
    } e[6];
} P_021B8B08;

typedef long long s64;

typedef struct {
    char pad0[0x2c];
    int f2c;
    s64 f30;
    u8 f38[1];
} Save;

typedef struct {
    Save *f0;
} C_021B8A70;

typedef struct {
    char pad0[8];
    void *f8;
    void *fc;
    void *f10;
    char pad14[0x14];
    void *f28;
    char pad2c[8];
    void *f34;
} Q;

typedef struct {
    void *h[6];
    struct {
        void *h;
        u8 on;
    } e[6];
} P_021B8C0C;

typedef enum { FALSE, TRUE } Bool_021B9070;

typedef struct {
    u8 pad00[0x24];
    void *obj[50];
    int idx[50];
    int kind[50];
    u8 count;
} List;

extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void func_0204363C(u32 a);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02010F7C(u32 heap);
extern void *func_02031324(int a0);
extern void func_02028470(u8 *p, u32 v);
extern u32 func_020056A0(void (*cb)(void), void *arg, int pri);
extern void func_0203D34C(u32 a, u32 b);
extern u32 func_02012138(const struct Ctx *p);
extern int func_02158344(int a0);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_0200FB24(void);
extern u32 func_0217440C(void);
extern u32 func_0217446C(void);
extern u32 func_020221A4(void);
extern u32 func_0202648C(void *obj);
extern u32 func_02026454(void *obj);
extern void func_02031348(int h, int id, int a, void *b);
extern void func_0201DD78(u32, u32, u32);
extern u32 func_02031330(void *h);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0204A600(void);
extern void func_0203133C(struct S020314B8 *p);
extern void func_02030EAC(struct Node *n);
extern void func_02010F8C(void *p);
extern void func_02049238(void *a);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203F8F4(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_02082A7C(int, int, int);
extern void func_020215A0(struct PalAnmSlot *, u32);
extern u32 func_02021540(void *a0);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(u32);
extern void func_02021660(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern void func_020215EC(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern void func_020216B4(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_0203FA08(u32 layer, u32 size, u32 top);
extern void func_02027634(void *arc, int id, u32 heap, int base, u32 pal);
extern void func_020409B4(u32 a);
extern void func_0203FB44(u32, u32, u32);
extern unsigned int func_02045C04(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern void func_0201C6EC(struct PrintSys *);
extern void func_0201C4C0(struct PrintSys *);
extern u32 func_0201D83C(void *ptr);
extern void func_02031140(struct S02031140 *);
extern void func_020434DC(u32, u32);
extern void func_02043598(u32, u32);
extern void func_02025588(void *);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02025358(void *);
extern void func_02025518(u32, u32, u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern void func_0204A648(void);
extern void func_02021D50(struct S02021D50 *);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern u32 func_020490A8(u32 a, u32 b);
extern u32 func_020307B0(void *p);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02045808(struct U16Vec *vec);
extern void func_0204B3B4(struct Obj *);
extern void func_0202570C(struct Grid *);
extern void func_020437AC(struct Obj020437AC *);
extern void func_0204B3DC(struct Obj *, u32);
extern void func_02025774(u8 *, u32);
extern u32 func_0201C6C4(struct PrintSys *, void *);
extern void func_020257D0(struct Obj *);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u16 func_02021F3C(int base, int idx, int which, u16 pos);
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern void *func_020120F4(const struct Ctx *p);
extern int func_021583EC(void *a0, int a1);
extern int func_021583CC(void *a0, int a1);
extern void func_0204B92C(struct Obj *, unsigned int);
extern void func_0204B8A0(struct Obj *p, u16 v);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
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
extern unsigned int func_02021EE4(struct Obj02021EE4 *o, int v);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02041300(u32 a, u32 b, u32 c, u32 d, u8 e, u8 f, u8 g);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern u8 *func_02025318(u32 a0, u8 a1, u8 a2);
extern void *func_02025538(unsigned int a0, void *a1);
extern u32 func_02025470(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_020254BC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
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
extern u8 func_021761EC(char *p);
extern int func_02173E2C(char *a, int b);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_0201F554(u32 a, u32 b, u32 c, u32 d);
extern u8 func_0201F548(int i);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *a0, u32 a1, u32 a2, void *a3, u32 a4, u32 a5, void *a6, u32 a7, u32 a8, u32 a9);
extern s32 func_02028484(struct Blk *blk, void *h);
extern void func_02045334(struct Descriptor *d);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern u8 func_020355C4(void);
extern const void *func_020084F4(const void *p);
extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern unsigned int func_0203633C(void);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern u8 *func_02175B34(u8 *p);
extern void func_021762D8(Obj *, void *, void *, int);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern int func_0216FEAC(void *, void *, u8 *);
extern void func_021BA11C(char *p);
extern void func_021B9BB8(char *p, char *q);
extern void func_021B9AE4(void *a, void *b);
extern void func_021B9B64(char *p, char *q);
extern void func_021B9BE8(char *p, char *q);
extern void func_021BA1B0(void *unused, char *p);
extern void func_021BA140(u8 *p);
extern int func_021B9F2C(u8 *p, int i, int v);
extern void func_021B9BD8(char *p);
extern void func_021B9BAC(void *p, int a);
extern int func_02035C38(void);
extern u32 func_0203630C(void);
extern void func_021B9C7C(void *,void *);
extern void func_021BA004(char *p);
extern int func_021BA0CC(u8 *p, int d);
extern void func_021BA01C(void *a, u8 *p);
extern void func_0201F184(struct WordSet *p, u32 i, s32 v);
extern int func_02174660(int,...);
extern void func_02005E30(u32 a);
extern int func_02005E50(void);
extern void func_02005DE4(void *p);
extern int func_02005E64(void);
extern void func_02005D90(int,int);
extern int func_02005F38(void);
extern int func_02005E9C(void);
extern void func_02005DF8(u32 a);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern void func_0200BF08(struct Rec1B0 *p, u32 v);
extern u8 func_02012B58(const struct BigObj *p);
extern void func_020266AC(u32,u32,u32);
extern void func_021B9C30(u8 *);
extern void func_021B9BA0(void *a);
extern void func_021B9B3C(char *p);
extern void func_021B9BC8(char *p);
extern void func_021B9C1C(char *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern int func_0216FE2C(struct Rec *tbl, int idx, struct Pos *pos, u8 *flags);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
int func_021B6100(struct Obj0203159C *ctx, int unused, u8 *arg);
int func_021B6250(int a, int *seq, void **pwk, u8 *mywk);
int func_021B6458(int a, int b, int c, int *w);
void func_021B64D0(void);
void func_021B6524(void);
void func_021B652C(void);
void func_021B6538(void);
unsigned int func_021B6540(int *p);
void func_021B6588(struct PalAnmSlot **p);
void func_021B65B4(void);
void func_021B6624(void);
void func_021B6644(void *a, void *b);
void func_021B677C(u32 *p);
void func_021B6790(int *p);
void func_021B6808(void **p);
void func_021B6844(struct W6844 *p);
void func_021B68B4(void **p);
void func_021B68E0(int *p);
void func_021B6960(u32 *p);
void func_021B699C(void *unused, struct S02021D50 **p);
void func_021B69AC(u8 *a, u8 *b);
void func_021B6A0C(Ctx_021B6A0C *a, Out_021B6A0C *b, int c, int d, int e, int f, int g, void *h);
void func_021B6B38(void **p);
void func_021B6B58(void **p, int v);
int func_021B6B70(void **p, u8 *q);
void func_021B6B98(void *p, int *tbl, int n, int sel, int c);
void func_021B6BEC(void *p, int *tbl, int n, int sel, int c);
void func_021B6C30(int *p, int flag, int index);
void func_021B6C48(void *p, int a);
void func_021B6C54(char *p);
u8 func_021B6C74(void *p, int i);
void func_021B6C7C(int *p, int idx);
void func_021B6DB4(int *p, int a, int idx);
int func_021B6E00(unsigned int x);
int func_021B6E0C(unsigned int x);
int func_021B6E18(int a0);
void func_021B6E1C(Ctx_021B6E1C *a, Out_021B6E1C *b, int c, int x, int y, int w, int h, int g, void *ws);
void func_021B6EEC(void **p);
int func_021B6F04(void **p, u8 *q);
void *func_021B6F2C(u8 **p);
void *func_021B6F40(u8 **p);
int func_021B6F54(struct P *p, u8 *q, int c, const int *d, int e);
void func_021B6FD8(void *p);
void func_021B6FE0(void *p, u8 *q, int i);
int func_021B7014(int *p, const int *pos, int flag);
void func_021B7068(void *p);
void func_021B7070(int *p, int *out);
void func_021B70B8(void **p);
void func_021B70C4(St *p);
void func_021B7108(void *p);
int func_021B7114(void *p);
struct Obj *func_021B7118(int *p, int x, int y, int w);
void func_021B7168(void *p);
void func_021B7170(void *a);
struct R *func_021B7174(u32 *p, int a, u16 heap);
void func_021B718C(void *p);
void *func_021B7194(int *p, void *arg1, u32 heap);
void func_021B71FC(void *p);
int func_021B7204(int a, int b, void *p, int *q);
void func_021B7234(void *a, int flag, int bg);
int func_021B730C(void *ctx, int *st, int *w);
int func_021B739C(int a,int *state,C *c,D_021B6524 *d);
int func_021B7824(void *a, void *b, char *c, char *d);
void func_021B7880(void);
void func_021B78D4(void);
void func_021B78F4(void *p, void **q);
void func_021B7924(void **p, void **q);
void func_021B7994(void *p);
void func_021B79A0(void **p, int *c, int idx);
int func_021B7A08(char *p, char *q);
void func_021B7A14(void **p);
void func_021B7A68(S *a, int *b);
void func_021B7AAC(void **p);
void func_021B7AC4(void **p, void *q);
void func_021B7AE8(void **p,int i);
void func_021B7B10(int *a, char *b);
void func_021B7B9C(char *p);
void func_021B7BB4(int *a,char *p);
void func_021B7BD8(void *p, int a);
void func_021B7BE4(void *p);
void func_021B7BF0(void *p);
void func_021B7BFC(int *a, char *p, unsigned char m);
int func_021B7C3C(struct Obj0203159C *a, int *b, C_021B7AAC *c);
int func_021B7D00(int a,int *p,char *c,void **d);
int func_021B7D34(void *a,int b,char *c,void **d);
void func_021B7D6C(void);
void func_021B7D98(void);
void func_021B7DAC(void *a,unsigned *b);
void func_021B7DE0(S *a, int *b);
void func_021B7E24(void **p);
void func_021B7E3C(void **a,void *p);
int func_021B7E60(struct Obj0203159C *a, int unused, C_021B7E60 *c);
int func_021B7EE0(int a, int *state, C_021B7EE0 *c, D_021B7AAC *d);
int func_021B8150(void *a, int unused, B *b, W_021B8150 *w);
void func_021B81A0(int *a, u8 *p);
void func_021B8270(unsigned char *p);
void func_021B82A4(int *a, char *p);
void func_021B82E4(void *p, int a);
void func_021B82F0(void *p);
void func_021B82FC(void *p);
void func_021B8308(void);
void func_021B833C(void);
void func_021B8350(W_021B7AAC *w, int *b);
void func_021B83C0(void *p);
void func_021B83CC(W_021B83C0 *w, X *x, unsigned y);
int func_021B8434(u8 *p, u8 *q);
void func_021B8440(W_021B83C0 *w);
int func_021B8494(struct Obj0203159C *a, int *b, C_021B8494 *c, u8 *d);
int func_021B855C(int a, int *p, C_021B855C *c, unsigned char *d);
int func_021B8618(void *a, void *b, char *c, void **d);
void func_021B8650(void);
void func_021B869C(void);
void func_021B86BC(char *p);
void func_021B86E8(int unused, P_021B86E8 *p);
void func_021B8750(void **p);
void func_021B8764(void *p,char *q);
void func_021B878C(void *p);
void func_021B8798(u8 **c, Q_021B8798 *q, P_021B8798 *d, u8 *r, unsigned v);
int func_021B889C(struct Obj0203159C *a, int *b, C_021B889C *c, u8 *d);
int func_021B8968(int a, int *b, C_021B8968 *c, u8 *d);
int func_021B8A38(void *a, void *b, char *c, void **d);
void func_021B8A70(void);
void func_021B8ABC(void);
void func_021B8ADC(char *p);
void func_021B8B08(int unused, P_021B8B08 *p);
void func_021B8BF4(void **p);
void func_021B8C0C(C_021B8A70 *c, Q *q, P_021B8C0C *d);
void func_021B8EC4(void *p, int a);
void func_021B8ED0(void *p);
void func_021B8EDC(void *p);
int func_021B8EE8(struct Obj0203159C *a, int *b, u8 *c, u8 *o);
int func_021B9070(int unused,int *state,u8 *c,u8 *o);
int func_021B94CC(void *a, void *b, char *c, char *d);
void func_021B9560(void);
void func_021B95CC(void);
void func_021B95FC(void *a, void *b);
void func_021B9694(unsigned int *p);
void func_021B96A4(char *a, void **b);
void func_021B9734(char *p);
void func_021B9750(char *a, char *b);
void func_021B9798(char *a, char *b, u32 c);
void func_021B9818(char *a, char *b, u32 c);
int func_021B98B4(u8 *a,u8 *b);
void func_021B98C4(char *a);
void func_021B992C(char *a);
void func_021B9970(char **a, List *l, char *c);
void func_021B9A18(char *p);
int func_021B9A40(char *a, char *b);
extern Pair d_021BA774[];
extern char d_021BA7D4;
extern char d_021BA764;
extern char d_021BA794;
extern char d_021BA7B4;
extern struct S6844 d_020A1448;
extern const struct Point d_021BA80C;
extern const struct Param d_021BA814;
extern char d_021BABE0[];
extern const struct Param d_021BA82C;
extern struct H4 d_021BA844;
extern const Rect d_021BA854;
extern const Rect d_021BA84C;
extern const Rect d_021BA804;
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



int func_021B6100(struct Obj0203159C *ctx, int unused, u8 *arg)
{
    u8 *o;

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
    o = func_0203159C(ctx, 0x13C, 0x61);
    func_02082BCC(o, 0, 0x13C);
    o[0xF1] = 0x30;
    func_021B69AC(o, arg);
    *(int *)(o + 0x30) = (int)func_020490F4(0x27, 0x61);
    func_021B64D0();
    func_021B652C();
    func_021B6540((int *)o);
    func_021B65B4();
    func_021B6644(o, o);
    func_021B6790((int *)o);
    func_021B6844((struct W6844 *)o);
    func_021B68E0((int *)o);
    *(int *)(o + 0x34) = (int)func_02010F7C(0x61);
    *(int *)(o + 0x12C) = (int)func_02031324(0x61);
    *(int *)(o + 0x130) = (int)func_02031324(0x61);
    func_02028470(o + 0x38, 6);
    *(u32 *)(o + 0x128) = func_020056A0((void (*)(void))func_021B699C, o, 0xA);
    func_0203D34C(0, 0x61);
    *(u8 **)(o + 0xF8) = arg;
    *(u8 **)(o + 0xFC) = o;
    *(u8 **)(o + 0x100) = o + 0xF0;
    return 1;
}



int func_021B6250(int a, int *seq, void **pwk, u8 *mywk)
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
        else if (func_0217440C() == 1)
            (*seq)++;
        break;
    case 2:
        if (func_020221A4() == 1)
            (*seq)++;
        break;
    case 3:
        if (func_0200FB24() != 0 || (r == 0 && func_0202648C(h) != 0) || (r == 0 && func_02026454(h) == 2))
            mywk[0x126] = 1;
        if (mywk[0x126] == 0) {
            if (mywk[0x135] == 0) {
                func_02031348(((struct Obj00712 *)mywk)->f12C, -1, d_021BA774[mywk[0x134]].a, mywk + 0xF8);
                mywk[0x135] = 1;
            }
            if (mywk[0x136] == 0) {
                func_0201DD78(0xF, 2, 0);
                func_02031348(((struct Obj00712 *)mywk)->f130, -1, d_021BA774[mywk[0x134]].b, mywk + 0xF8);
                mywk[0x136] = 1;
            }
        }
        s2 = func_02031330((void *)((struct Obj00712 *)mywk)->f130);
        k = mywk[0x124];
        if (k == 4 || (s2 != 1 && mywk[0x126] == 1)) {
            mywk[0x125] = 1;
        } else if (mywk[0x134] != k && d_021BA774[mywk[0x134]].a != d_021BA774[k].a) {
            mywk[0x125] = 1;
        }
        s1 = func_02031330((void *)((struct Obj00712 *)mywk)->f12C);
        if (s1 == 1 && s2 == 1)
            break;
        if (mywk[0x126] == 1 || mywk[0x124] == 4) {
            if (s1 == 0 && s2 == 0)
                (*seq)++;
        } else {
            mywk[0x134] = mywk[0x124];
            if (s1 != 1) {
                mywk[0x135] = 0;
                mywk[0x125] = 0;
            }
            if (s2 != 1)
                mywk[0x136] = 0;
        }
        break;
    case 4:
        func_0202208C(0, 0, 0, 0, 6, 1, 0x8061);
        (*seq)++;
        break;
    case 5:
        if (r == 0 || func_0200FB24() != 0)
            (*seq)++;
        else if (func_0217446C() == 1)
            (*seq)++;
        break;
    case 6:
        if (func_020221A4() == 1)
            (*seq)++;
        break;
    case 7:
        return 1;
    }
    func_020310C4(((struct Obj00712 *)mywk)->f18);
    func_0201C4E4((struct PrintSys *)(((struct Obj00712 *)mywk)->f8));
    func_0204A600();
    return 0;
}

/*
 * Byte-correct. Blocker: func_02010F8C (arm9 unlabelled tail-call stub,
 * the integrator's leaf) has no witness outside this range. Verified C for the leaf
 * (EXACT, arm9, --thumb, symbols: func_020307B0 0x020307B0 arm):
 *   void func_02010F8C(void *p) { void func_020307B0(void *); func_020307B0(p); }
 */
int func_021B6458(int a, int b, int c, int *w)
{

    func_0203133C((struct S020314B8 *)w[0x12c / 4]);
    func_0203133C((struct S020314B8 *)w[0x130 / 4]);
    func_02030EAC((struct Node *)w[0x128 / 4]);
    func_02010F8C((void *)w[0x34 / 4]);
    func_021B6960((u32 *)w);
    func_021B68B4((void **)w);
    func_021B6808((void **)w);
    func_021B677C((u32 *)w);
    func_021B6624();
    func_021B6588((struct PalAnmSlot **)w);
    func_021B6538();
    func_021B6524();
    func_02049238((void *)w[0x30 / 4]);
    *(volatile unsigned short *)0x04000050 = 0;
    *(volatile unsigned short *)0x04001050 = 0;
    func_020315D4((struct S020315D4 *)a);
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



unsigned int func_021B6540(int *p)
{

    *p = (int)func_02021518(0x61);
    func_0202155C((struct PalAnmSlot *)(*p), 2, 0x1c0, 0x61);
    func_0202155C((struct PalAnmSlot *)(*p), 3, 0x1c0, 0x61);
    func_0202155C((struct PalAnmSlot *)(*p), 0, 0x1c0, 0x61);
    func_0202155C((struct PalAnmSlot *)(*p), 1, 0x1c0, 0x61);
    return func_02021EE4((struct Obj02021EE4 *)(*p), 1);
}







void func_021B6588(struct PalAnmSlot **p)
{
    func_020215A0(*p, 2);
    func_020215A0(*p, 3);
    func_020215A0(*p, 0);
    func_020215A0(*p, 1);
    func_02021540(*p);
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








void func_021B6644(void *a, void *b)
{
    char *d = (char *)a;
    char *r5 = (char *)b;
    void *h;

    func_02021660(((struct Obj02419 *)r5)->f0, (void *)(*(u32 *)&((struct Obj02419 *)r5)->f30), 0x10, 0x61, 0, 0x1c0, 0, 0);
    func_02021660(((struct Obj02419 *)r5)->f0, (void *)(*(u32 *)&((struct Obj02419 *)r5)->f30), 0x11, 0x61, 1, 0x1c0, 0, 0);
    func_02049658(((struct Obj02419 *)r5)->f30, 0xf, 3, 0, 0, 1, 0x61);
    func_020498F4(((struct Obj02419 *)r5)->f30, 0xa, 3, 0, 0, 1, 0x61);
    func_02049658(((struct Obj02419 *)r5)->f30, 0xe, 7, 0, 0, 1, 0x61);
    func_020498F4(((struct Obj02419 *)r5)->f30, 4, 7, 0, 0, 1, 0x61);
    func_020215EC(((struct Obj02419 *)r5)->f0, 0x17, 5, 0x61, 0, 0, 0xd0, 0);
    func_020215EC(((struct Obj02419 *)r5)->f0, 0x17, 5, 0x61, 1, 0, 0xd0, 0);
    h = func_020490F4(0x53, 0x61);
    ((struct Obj09885 *)d)->f138 = (void *)func_0203FA08(7, 0x80, 1);
    func_02049658(h, 0x1c, 7, (u32)(((struct Obj09885 *)d)->f138), 0x80, 0, 0x61);
    func_02027634(h, 7, 0x61, (int)(((struct Obj09885 *)d)->f138), 0xc);
    func_020216B4(((struct Obj02419 *)r5)->f0, h, 0x1b, 0x61, 1, 0x20, 0xc0);
    func_02049238(h);
    func_020409B4(7);
    func_020409B4(3);
    func_020409B4(7);
}







void func_021B677C(u32 *p)
{
    func_0203FB44(7, p[0x138 / 4], 0x80);
}



void func_021B6790(int *p)
{

    func_0201DD78(0xf, 2, 0);
    p[6] = (int)func_0203101C(0x61, 0x61, 4, 0x20);
    p[3] = (int)func_0201D7EC(0x17, 0, 0, 0, 0x61);
    p[2] = func_0201C440((void *)0x61);
    p[4] = (int)func_0201EC64(0x61);
    p[7] = (int)func_02045B38(0, 2, 0x43, 0x61);
    p[8] = (int)func_02045B38(0, 2, 0xa0, 0x61);
    p[9] = (int)func_02045B38(0, 2, 0xa1, 0x61);
    p[10] = (int)func_02045B38(0, 2, 0x45, 0x61);
}







void func_021B6808(void **p)
{
    func_02045C04(p[7]);
    func_02045C04(p[8]);
    func_02045C04(p[9]);
    func_02045C04(p[10]);
    func_0201ED04(p[4]);
    func_0201C6EC(p[2]);
    func_0201C4C0(p[2]);
    func_0201D83C(p[3]);
    func_02031140(p[6]);
}



void func_021B6844(struct W6844 *p)
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
    p->unk_14 = func_0204B100(0x60, 0, 0x61);
    func_0204B270(p->unk_14);
    p->unk_04 = func_02025318(0x61, 0x10, 0x10);
    p->unk_2c = func_02025538(0x61, p->unk_14);
}







/*
 * split: TU confirms one image-wide witness, inside this caller; no cuts.
 * ARM9 stub: 02025358 ldr r3,[pc,#0]; bx r3; pool 020307B0.
 */
void func_021B68B4(void **p)
{
    func_020434DC(0x10, 0);
    func_02043598(0x10, 0);
    func_02025588(p[11]);
    func_0204B1CC(p[5]);
    func_0204A5AC();
    func_02025358(p[1]);
}



void func_021B68E0(int *p)
{
    void *tmp;
    int i;
    int flag;
    int *e;

    tmp = func_020490F4(0x17, 0x61);
    for (i = 0; i < 2; i++) {
        flag = 0;
        if (i != 0) {
            flag = 1;
        }
        e = p + i * 4;
        e[16] = func_02025470(p[0], p[1], p[12], 3, flag, 3, 0x61);
        e[17] = func_0204A6C8((void *)p[12], 0, 1, flag, 0x61);
        e[18] = func_0204AF28((void *)p[12], 1, 2, 0x61);
        e[19] = func_020254BC(p[0], p[1], (u32)tmp, 5, flag, 1, 0x61);
    }
    func_02049238(tmp);
}







/*
 * extent: two-byte alignment padding at 0x021B699A.
 * Enum counter preserves the first iteration's cmp/branch.
 */
void func_021B6960(u32 *p)
{
    Slot i;
    int flag;
    u32 *e;
    i = SLOT_FIRST;
    do {
        flag = 0;
        if (i != 0) {
            flag = 1;
        }
        e = p + i * 4;
        func_02025518(p[1], e[16], flag);
        func_0204A8D4(e[17]);
        func_0204AFD8(e[18]);
        func_02025518(p[1], e[19], flag);
        i++;
    } while (i < SLOT_COUNT);
}






void func_021B699C(void *unused, struct S02021D50 **p)
{
    func_0204A648();
    func_02021D50(*p);
}







void func_021B69AC(u8 *a, u8 *b)
{
    struct E24 *tbl;
    u32 n;
    u32 idx;
    Idx i;

    if (b[0x3d] != 0) {
        tbl = func_02048F60(0x25, 0, 0x61);
        n = func_020490A8(0x25, 0);
        for (i = IDX_FIRST; i < IDX_COUNT; i++) {
            idx = b[4 + i];
            if (idx >= n) {
                idx = 0;
            }
            *(struct E24 *)(a + 0x60 + i * 24) = tbl[idx];
        }
        func_020307B0(tbl);
    }
}







/*
 * The 0/1 flag keeps its bne-to-one polarity only as an enum ternary
 * (a-flag-ternary-over-enum-constants-keeps-the-bne-to-one-polarity.md);
 * `case 2:` shares its arm with `default:` (the dead `cmp r6, #2; b`).
 */
void func_021B6A0C(Ctx_021B6A0C *a, Out_021B6A0C *b, int c, int d, int e, int f, int g, void *h)
{
    struct Point pt = d_021BA80C;
    struct Param param = d_021BA814;
    u32 w;
    void *bmp;
    void *s;
    void *t;
    int x;

    switch (d) {
    case 0:
        w = 0x16;
        pt.f4 = 0;
        param.x = e - 0x58;
        break;
    case 1:
        w = 0x12;
        pt.f4 = 1;
        param.x = e - 0x48;
        break;
    case 2:
    default:
        w = 0xc;
        pt.f4 = 8;
        param.x = e - 0x30;
        break;
    }
    bmp = func_02043678(w, 2, 0x20, 0x61);
    b->bmp = bmp;
    pt.x = e;
    pt.y = f;
    param.y = f - 8;
    param.bmp = bmp;
    param.f8 = a->res[c].f4c;
    x = c == 0 ? B_FALSE : B_TRUE;
    param.f14 = x;
    param.f12 = x;
    b->act = func_0204B294((void *)a->f14, a->res[c].f44, a->res[c].f40, a->res[c].f48, &pt, x, 0x61);
    b->grid = func_020255A0(a->f2c, &param);
    s = func_02045EC0(a->f28, g);
    if (h) {
        t = func_020457B0(0x80, 0x61);
        func_0201F250(h, t, s);
        func_0201C6FC(a->f8, (u32)b->bmp, 0, 0, t, (u32)a->fc);
        func_02045808(t);
    } else {
        func_0201C6FC(a->f8, (u32)b->bmp, 0, 0, s, (u32)a->fc);
    }
    func_02045808(s);
    b->on = 1;
}






void func_021B6B38(void **p)
{
    func_0204B3B4(p[0]);
    func_0202570C(p[1]);
    func_020437AC(p[2]);
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
}






/*
 * extent: two-byte alignment padding at 0x021B6B6E.
 */
void func_021B6B58(void **p, int v)
{
    func_0204B3DC(p[0], v);
    func_02025774(p[1], v);
}






int func_021B6B70(void **p, u8 *q)
{
    if (q[12] == 1) {
        if (func_0201C6C4(p[2], ((struct Obj07693 *)q)->f8) == 0) {
            func_020257D0(*(struct Obj * *)&((struct Obj07693 *)q)->f4);
            q[12] = 0;
            return 1;
        }
    }
    return 0;
}



void func_021B6B98(void *p, int *tbl, int n, int sel, int c)
{
    int i;

    for (i = 0; i < n; i++) {
        if (i == sel) {
            func_0204B6F4((struct Obj *)tbl[i * 4], 1, 1);
            func_021B6DB4(p, 1, c);
        } else {
            func_0204B6F4((struct Obj *)tbl[i * 4], 0, 1);
        }
    }
    if (sel == 0xff) {
        func_021B6DB4(p, 0, c);
    }
}



void func_021B6BEC(void *p, int *tbl, int n, int sel, int c)
{
    int i;

    for (i = 0; i < n; i++) {
        if (i == sel) {
            func_0204B6F4((struct Obj *)tbl[i * 4], 1, 1);
            func_021B6DB4(p, 2, c);
        } else {
            func_0204B6F4((struct Obj *)tbl[i * 4], 0, 1);
        }
    }
}






void func_021B6C30(int *p, int flag, int index)
{
    if (flag == 1) {
        func_021B6DB4(p, 1, index);
    } else {
        func_021B6DB4(p, 0, index);
    }
}



void func_021B6C48(void *p, int a)
{
    func_021B6DB4(p, 2, a);
}






void func_021B6C54(char *p) { int i; for(i=0;i<4;i++) func_02082BCC(p+12+i*8,0,8); }







u8 func_021B6C74(void *p, int i)
{
    return ((u8 *)p + i * 8)[0xe];
}







/*
 * sites to func_02021F3C stay wildcarded because 0x02021F3C is an
 * unlabelled arm9 Thumb leaf (a bare `cmp r2, #1` entry, no lr save), so
 * no class attests it. The leaf verifies EXACT with this body
 * (`one --thumb`, no --region), outside this lane's write set (arm9):
 *
 *   typedef struct { u16 *a; u16 *b; int pad[3]; } Slot;
 *   u16 func_02021F3C(Slot *s, int idx, int which, u16 pos)
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
 * note 2026-10-05 (D8 lane16): witness func_02021F3C filed as src/matched/arm9/func_02021F3C.c (EXACT); this file becomes EXACT once the integrator seeds that label/manifest. Body unchanged.
 */
void func_021B6C7C(int *p, int idx)
{
    Ent *e;
    int a, b, n;
    int i;
    int v;

    e = (Ent *)((u8 *)p + 0xC + idx * 8);
    if (idx >= 4) {
        func_02034714(d_021BABE0, (int)0, d_021BABE0);
    }
    a = func_021B6E00((int)idx);
    b = func_021B6E0C((int)idx);
    n = func_021B6E18(idx);
    switch (e->state) {
    case 1:
        v = e->v;
        if (e->dir == 0) {
            v += 0x80;
            if (v >= 0x1100) {
                v = 0x1000;
                e->dir ^= 1;
            }
        } else {
            v -= 0x80;
            if (v <= 0) {
                v = 0x100;
                e->dir ^= 1;
            }
        }
        e->v = v;
        for (i = 0; i < n; i++) {
            func_02021FD8((struct Chan02021FD8 *)(*(int *)p[1]), (int)idx, (u16)(a + i), (u16)1, v >> 8,
                          func_02021F3C(*(int *)p[1], idx, 1, b + i));
        }
        break;
    case 2:
        if (e->timer == 0) {
            e->timer = 3;
            if (e->v == 0) {
                e->v = 0x1000;
            } else {
                e->v = 0;
                e->cnt++;
                if (e->cnt > 1) {
                    func_021B6DB4(p, 0, idx);
                }
            }
            for (i = 0; i < n; i++) {
                func_02021FD8((struct Chan02021FD8 *)(*(int *)p[1]), (int)idx, (u16)(a + i), (u16)1, e->v >> 8,
                              func_02021F3C(*(int *)p[1], idx, 1, b + i));
            }
        } else {
            e->timer--;
        }
        break;
    }
}



void func_021B6DB4(int *p, int a, int idx)
{
    u8 *e;

    e = (u8 *)p + 0xC + idx * 8;
    func_02082BCC(e, 0, 8);
    e[2] = a;
    func_02021FD8((struct Chan02021FD8 *)(*(int *)p[1]), (int)idx, (u16)func_021B6E00(idx), (u16)func_021B6E18(idx), 0, 0);
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
void func_021B6E1C(Ctx_021B6E1C *a, Out_021B6E1C *b, int c, int x, int y, int w, int h, int g, void *ws)
{
    struct Param param = d_021BA82C;
    void *bmp;
    void *s;
    void *t;

    bmp = func_02043678(w, h, 0x20, 0x61);
    b->bmp = bmp;
    param.x = x - (w / 2) * 8;
    param.y = y - (h / 2) * 8;
    param.bmp = bmp;
    param.f8 = a->res[c].f4c;
    if (c == 0) {
        param.f14 = 0;
        param.f12 = 0;
    } else {
        param.f14 = 1;
        param.f12 = 1;
    }
    b->grid = func_020255A0(a->f2c, &param);
    s = func_02045EC0(a->f28, g);
    if (ws) {
        t = func_020457B0(0x80, 0x61);
        func_0201F250(ws, t, s);
        func_0201C6FC(a->f8, (u32)b->bmp, 0, 0, t, (u32)a->fc);
        func_02045808(t);
    } else {
        func_0201C6FC(a->f8, (u32)b->bmp, 0, 0, s, (u32)a->fc);
    }
    func_02045808(s);
    b->on = 1;
}






void func_021B6EEC(void **p) { func_0202570C(p[1]); func_020437AC(p[0]); p[1] = 0; p[0] = 0; }






int func_021B6F04(void **p, u8 *q) { if(q[8]==1) { if(func_0201C6C4(p[2], (void *)(*(unsigned *)&((struct Obj06183 *)q)->f0))==0) { func_020257D0(((struct Obj06183 *)q)->f4); q[8]=0; return 1; } } return 0; }





void *func_021B6F2C(u8 **p)
{
    u8 *q = *p;
    return (void *)func_021583EC(func_020120F4(((struct Obj13166 *)q)->f0), q[0x3c]);
}





void *func_021B6F40(u8 **p)
{
    u8 *q = *p;
    return (void *)func_021583CC(func_020120F4(((struct Obj13167 *)q)->f0), q[0x3c]);
}






/*
 * The flag is a u16 local assigned from a ternary over enum constants: every
 * int-constant spelling (ternary, if/else, e != 0) is folded to a boolean and
 * comes out with the opposite branch polarity (beq to 0, not bne to 1).
 * const on d lets both d[] loads go ahead of the stores into s.
 */
int func_021B6F54(struct P *p, u8 *q, int c, const int *d, int e)
{
    struct H4 s;
    int r;
    u16 flag;
    u8 *m;

    s = d_021BA844;
    flag = e == 0 ? B_FALSE : B_TRUE;
    s.a = d[0];
    s.b = d[1];
    m = q + 6;
    if (m[c] == 1) {
        s.c = 5;
    }
    r = (int)func_0204B294((void *)p->w[5], p->e[e].w[1], p->e[e].w[0], p->e[e].w[2], &s, flag, 0x61);
    if (m[c] == 0) {
        func_0204B3DC((struct Obj *)r, 0);
    }
    func_0204B92C((struct Obj *)r, 1);
    return r;
}



/*
 * Tail call to func_0204B3B4.
 */
void func_021B6FD8(void *p)
{
    func_0204B3B4(p);
}





void func_021B6FE0(void *p, u8 *q, int i) { Value v; if((q+i)[6]==1) v=V5; else if((q+i)[6]==2) v=V4; else {func_0204B3DC(p,0);return;} func_0204B3DC(p,1);func_0204B8A0(p,v); }






int func_021B7014(int *p, const int *pos, int flag)
{
    Rect r;
    int f;

    r = d_021BA854;
    f = 0;
    if (flag != 0)
        f = 1;
    r.a = pos[0];
    r.b = pos[1];
    return (int)func_0204B294((void *)p[0x14 / 4], *(int *)((char *)p + 0x44 + flag * 16), *(int *)((char *)p + 0x40 + flag * 16), *(int *)((char *)p + 0x48 + flag * 16), &r, (u16)f, 0x61);
}



void func_021B7068(void *p)
{
    func_0204B3B4(p);
}






void func_021B7070(int *p, int *out)
{
    Rect r;
    int h;

    r = d_021BA84C;
    h = (int)func_0204B294((void *)p[0x14 / 4], p[0x54 / 4], p[0x50 / 4], p[0x58 / 4], &r, 1, 0x61);
    func_0204B92C((struct Obj *)h, 1);
    *out = h;
}



/*
 * Unlabelled leaf thunk: loads *p then tail-calls the ARM9 ARM function
 * func_0204B3B4 with it.  It is the callee whose only image-wide callers are
 * the three ov071 offset-thunks (matched via this EXACT entry).
 */
void func_021B70B8(void **p)
{
    func_0204B3B4(*p);
}






void func_021B70C4(St *p)
{
    if (p->a == 1) {
        if (p->b % 5 == 0) {
            func_0204B6F4((struct Obj *)p->h, p->c, 1);
            p->c ^= 1;
            if (p->b / 5 == 3)
                p->a = 0;
        }
        p->b++;
    }
}






/*
 * Byte initialiser and its getter.
 */
void func_021B7108(void *p)
{
    ((struct Obj09886 *)p)->f4 = 1;
    ((struct Obj09886 *)p)->f5 = 0;
    ((struct Obj09886 *)p)->f6 = 1;
}






int func_021B7114(void *p)
{
    return ((struct Obj20689 *)p)->f4;
}






struct Obj *func_021B7118(int *p, int x, int y, int w)
{
    Rect r;
    struct Obj *h;

    r = d_021BA804;
    r.a = x;
    r.b = y;
    r.c = w;
    h = func_0204B294((void *)p[0x14 / 4], p[0x54 / 4], p[0x50 / 4], p[0x58 / 4], &r, 1, 0x61);
    func_0204B92C(h, 1);
    return h;
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





int func_021B7204(int a, int b, void *p, int *q) { func_02027974(p); if(func_020279E8(p)==1) { *q=func_02027A04(p)==0 ? 1 : 0;return 1;} return 0; }






void func_021B7234(void *a, int flag, int bg)
{
    Counts *c;
    u16 *buf;
    int y;
    int n, m;
    int left, right;
    int i;

    c = func_021B6F40(a);
    y = 0x14;
    if (flag) {
        y = 0xe;
    }
    n = c->n;
    m = c->m;
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






int func_021B730C(void *ctx, int *st, int *w)
{
    u8 *m;

    switch (st[0]) {
    case 0:
        m = func_0203159C(ctx, 0x84, 0x61);
        func_02082BCC(m, 0, 0x84);
        m[0x82] = 0;
        func_021B7880();
        func_021B78F4(w, (void *)w[1]);
        func_021B7924((void **)m, (void *)w[1]);
        func_021B7A68((S *)m, (int *)w);
        func_021B7B10(w, (char *)m);
        func_021B7BD8(w, (int)m);
        ((struct Obj13174 *)m)->f7C = func_021B7014((int *)w[1], (const int *)&d_021BA8A0[*(u8 *)w[2]], 1);
        st[0]++;
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





int func_021B739C(int a,int *state,C *c,D_021B6524 *d)
{
 u16 *dst;
 u16 *src;
 u8 *r;
 int keys,res,t;
 u32 i;
 u8 next;
 const u8 *row;
 r=(u8 *)func_02158344(func_02012138(*c->f0));
 func_021B7AC4((void **)d,c); func_021B7AE8((void **)d,*c->f8);func_021B7BB4((int *)c,(char *)d);func_021B7BF0(d);
 if(c->f2e==1 && *state==3) return 1;
 switch(*state) {
 case 0:
  if(r!=0 && func_02175B14(r+0x1ac)==1) func_021B7BFC((int *)c,(char *)d,1);
  *state=1;break;
 case 1:
  if(func_02158590(func_020120F4(*c->f0))==0) func_021B79A0((void **)d,(int *)c->f4,0x16);
  else func_021B79A0((void **)d,(int *)c->f4,0x12);
  ++*state;break;
 case 2:
  if(func_021B7A08((char *)c->f4,(char *)d)!=1) break;
  if(func_02035C60()==0 && (func_020362DC()&3)==0) break;
  func_021B7A14((void **)d);func_020061E4(0x547);
  if(func_02035C60()!=0) {d->f83=1;func_021B6B98(c,(int *)((u8 *)d+0x2c),1,0xff,3);}
  else {d->f83=0;func_021B6B98(c,(int *)((u8 *)d+0x2c),1,0,3);}
  if(d->f82==0) *state=3;else *state=4;
  break;
 case 3:
  keys=func_020362DC();res=func_02035C08(d_021BA87C);
  if(r!=0 && func_02175B14(r+0x1ac)==1) {func_021B7BFC((int *)c,(char *)d,1);d->f80=1;*state=4;break;}
  if(keys>0 && d->f83==1) {d->f83=0;func_021B6B98(c,(int *)((u8 *)d+0x2c),1,0,3);func_020061E4(0x548);break;}
  if(keys&0xf0) {
   next=0xff;
   for(i=0;(i<6)?1:0;i++) if(d_021BA85C[i]==*c->f8) break;
   i=*c->f8;
   if(keys&0x40) {row=d_021BA862[i];next=row[0];}
   else if(keys&0x80) {row=d_021BA862[i];next=row[1];}
   else if(keys&0x20) {row=d_021BA862[i];next=row[2];}
   else if(keys&0x10) {row=d_021BA862[i];next=row[3];}
   if(next!=0xff) i=next;
   *c->f8=i;func_020061E4(0x548);
  }
  if(res>=0 && res<6) {*c->f8=res;d->f83=1;func_021B6B98(c,(int *)((u8 *)d+0x2c),1,0xff,3);func_020061E4(0x548);break;}
  if(res==6 || (keys&1)) {
   func_020355D8(res==6);
   if(func_02158590(func_020120F4(*c->f0))==0) {
    t=d_021BAA4C[*c->f8];
    if(t!=2 && t!=1) {*state=9;break;}
   }
   func_021B6BEC(c,(int *)((u8 *)d+0x2c),1,0,3);func_020061E4(0x736);*state=5;
  } else if(res==7 || (keys&2)) {
   func_021B7108((u8 *)d+0x24);func_020355D8(res==7);func_020061E4(0x551);*state=11;
  }
  break;
 case 4: {
  int keys4,res4;
  keys4=func_020362DC();res4=func_02035C08(d_021BA87C);
  if(res4==7 || (keys4&2)) {func_020355D8x(res4==7);func_020061E4(0x551);*state=11;}
  break;}

 case 5:
  d->rec=*(Record *)(c->f4+0x60+d_021BAA4C[*c->f8]*24);
  d->f78=((u8 *)c->f0)[0x15];
  dst=d->text;
  src=(u16 *)((u8 *)c->f0+0x18);
  for(i=10;i!=0;i--) {*dst=*src;dst++;src++;}
  if(r!=0 && func_02173E2C((char *)r,(int)(&d->rec))!=1) break;
  *state=6;break;
 case 6:
  if(r==0) {*state=3;break;}
  t=func_021761EC((char *)(r+0x1ac));
  if(t==1) {func_021B79A0((void **)d,(int *)c->f4,0x10);*state=7;}
  else if(t==2) {func_021B79A0((void **)d,(int *)c->f4,0x11);*state=8;}
  else if(t==3) {func_021B79A0((void **)d,(int *)c->f4,0x15);*state=8;}
  else if(t==4) {func_021B79A0((void **)d,(int *)c->f4,0x14);*state=8;}
  break;
 case 7:case 8:
  if(func_021B7A08((char *)c->f4,(char *)d)!=1) break;
  if(*state==7) {
  } else if(*state==8) {
   if(func_02035C60()==0 && !(func_020362DC()&3)) break;
  } else break;
  if(*state==7 && r!=0 && func_02175B14(r+0x1ac)==0) break;
  func_021B7A14((void **)d);func_020061E4(0x547);
  if(*state==7) {if(r!=0) func_02175B4C(r,r+0x1ac);d->f81=1;*state=11;}
  else *state=11;
  break;
 case 9:func_021B79A0((void **)d,(int *)c->f4,0x17);++*state;break;
 case 10:
  if(func_021B7A08((char *)c->f4,(char *)d)==1 && (func_02035C60()!=0 || (func_020362DC()&3)!=0)) {func_021B7A14((void **)d);*state=3;}
  break;
 case 11:
  if(func_021B6C74(c,3)==2) break;
  if(func_021B7114((u8 *)d+0x24)!=0) break;
  if(d->f81==1) c->f2c=4;else c->f2c=0;
  return 1;
 }
 return 0;
}





#pragma opt_lifetimes reset





#pragma opt_common_subs reset






int func_021B7824(void *a, void *b, char *c, char *d)
{
    if (func_0201C6B4(((struct Obj20692 *)(*(char * *)&((struct Obj20691 *)c)->f4))->f8) == 0)
        return 0;
    func_020435F4(8);
    if (((struct Obj06184 *)d)->f8 != 0)
        func_0201CE48(((struct Obj06184 *)d)->f8);
    if (((struct Obj06184 *)d)->f4 != 0)
        func_02045808(((struct Obj06184 *)d)->f4);
    func_021B7068(((struct Obj06184 *)d)->f7C);
    func_021B7BE4(d);
    func_021B7B9C(d);
    func_021B7AAC((void **)d);
    func_021B7994(d);
    func_021B78D4();
    func_020315D4(a);
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





void func_021B78F4(void *p, void **q) {func_020498F4(q[12],6,6,0,0,1,0x61);func_021B7234(p,1,6);func_020409B4(6);}






void func_021B7924(void **p, void **q)
{
    func_0201F554(5, 1, 0, 0x61);
    func_020215EC(q[0], 5, func_0201F548(0), 0x61, 1, 0x20, 0xb0, 0);
    p[0] = (void *)func_020450F0(5, 1, 0x13, 0x1e, 4, 0xd, 1);
    func_02043B5C(func_02045770(p[0]), 0xff);
    func_02045374(p[0]);
    func_0201F73C(p[0], 0, 1, 0xb);
}



void func_021B7994(void *p)
{
    func_020452E8(((struct Obj20695 *)p)->f0);
}






void func_021B79A0(void **p, int *c, int idx)
{
    if (p[2] != 0)
        func_02034714(d_021BABF4, 0, d_021BABF4);
    func_0201DD78(1, 2, 15);
    p[1] = func_02045EC0((void *)c[0x28 / 4], idx);
    p[2] = func_0201CCE4(p[0], 0, 0, p[1], c[0xc / 4], func_02012FFC(), (void *)c[0x18 / 4], 10, 0x61, 15);
    func_02040588(5, 1);
}





int func_021B7A08(char *p, char *q) { return func_02028484((struct Blk *)(p + 0x38), (void *)(*(int *)(q + 8))); }






void func_021B7A14(void **p)
{
    void *h;

    h = func_02045770(p[0]);
    if (p[2] == 0)
        func_02034714(d_021BABF4, 0, d_021BABF4);
    func_0201CE48(p[2]);
    p[2] = 0;
    func_02045808(p[1]);
    p[1] = 0;
    func_02040588(5, 0);
    func_02043B5C(h, 0xff);
    func_02045334(p[0]);
    func_0201DD78(15, 2, 0);
}



void func_021B7A68(S *a, int *b)
{
    int i;
    int t = (int)func_021B6F40((u8 **)b);

    for (i = 0; i < 6; i++) {
        int r;
        unsigned u = d_021BAA4C[i];
        r = func_021B6F54((struct P *)b[1], (u8 *)t, i, (const int *)&d_021BA8A0[u], 1);
        a->v[i] = r;
    }
}










void func_021B7AAC(void **p) { int i; for(i=0;i<6;i++) func_021B6FD8(p[i+3]); }










void func_021B7AC4(void **p, void *q) { u8 *t;int i;t=func_021B6F40(q);for(i=0;i<6;i++)func_021B6FE0(p[i+3],t,i);}










void func_021B7AE8(void **p,int i) { u16 t[2];t[0]=d_021BA8A0[i].x;t[1]=d_021BA8A0[i].y;func_0204B404(p[31],(const struct Vec2 *)t,1);}











void func_021B7B10(int *a, char *b)
{
    func_021B6C54((char *)a);
    func_021B6A0C((Ctx_021B6A0C *)a[1], (Out_021B6A0C *)(b + 0x2c), 1, 1, 0x80, 0x90, 14, 0);
    if (func_020355C4() == 0) {
        func_021B6B98(a, (int *)(b + 0x2c), 1, 0, 3);
    } else {
        func_021B6B98(a, (int *)(b + 0x2c), 1, 0xff, 3);
        b[0x83] = 1;
    }
    func_021B6A0C((Ctx_021B6A0C *)a[1], (Out_021B6A0C *)(b + 0x3c), 1, 1, 0x80, 0x90, 15, 0);
    func_021B6B58((void **)(b + 0x3c), 0);
}










void func_021B7B9C(char *p) { int i; p += 0x2c; for (i=0;i<2;i++) func_021B6B38((void **)(p+i*16)); }










void func_021B7BB4(int *a,char *p) { int i; func_021B6C7C(a,3); p+=0x2c; for(i=0;i<2;i++) func_021B6B70((void **)a[1],(u8 *)(p+i*16)); }








/*
 * Tail call to func_021B7070(word at 0x4, a + 0x24).
 */
void func_021B7BD8(void *p, int a)
{
    func_021B7070(((struct Obj20703 *)p)->f4, (int *)(a + 0x24));
}








/*
 * Tail call to func_021B70B8 with the pointer advanced by 0x24.  The callee
 * is an unlabelled leaf in this overlay; it is reproduced in
 * src/matched/ov071_func_021B70B8.c, whose EXACT entry attests this pool-word
 * site (`matched`).
 */
void func_021B7BE4(void *p)
{
    func_021B70B8((void **)((char *)p + 0x24));
}








/*
 * Tail call to func_021B70C4((char *)p + 0x24).
 */
void func_021B7BF0(void *p)
{
    func_021B70C4((St *)((char *)p + 0x24));
}











void func_021B7BFC(int *a, char *p, unsigned char m)
{

    if (m == 0) {
        func_021B6B58((void **)(p + 0x2c), 1);
        func_021B6B58((void **)(p + 0x3c), 0);
    } else {
        *(unsigned char *)a[2] = 6;
        func_021B6B58((void **)(p + 0x2c), 0);
        func_021B6B58((void **)(p + 0x3c), 1);
    }
    ((struct Obj20705 *)p)->f82 = m;
}








int func_021B7C3C(struct Obj0203159C *a, int *b, C_021B7AAC *c)
{
    void *m;
    void *s;
    int h;

    switch (*b) {
    case 0:
        m = func_0203159C(a, 0x24, 0x61);
        func_02082BCC(m, 0, 0x24);
        func_021B7D6C();
        func_021B7DAC(c, (unsigned int *)c->f4);
        h = (int)func_021B6F2C((u8 **)c);
        s = func_020457B0(8, 0x61);
        func_02045994(s, func_020084F4((const void *)h), 8);
        func_0201EE0C((struct WordSet *)c->f4->f10, 0, s, func_02008550((const struct Sub0200852CObj *)h), 1, 2);
        func_02045808(s);
        func_021B6E1C((Ctx_021B6E1C *)c->f4, (Out_021B6E1C *)m, 0, 0x80, 0xc, 0x1e, 2, 0, (void *)c->f4->f10);
        func_021B7DE0((S *)m, (int *)c);
        *b = *b + 1;
        break;
    case 1:
        func_02040588(2, 1);
        func_020434DC(0x10, 1);
        return 1;
    }
    return 0;
}










int func_021B7D00(int a,int *p,char *c,void **d) { if((unsigned char)c[0x2d]==1) return 1; func_021B6F04(((struct Obj13176 *)c)->f4,(u8 *)d); func_021B7E3C(d,c); switch(*p) { case 0:return 0; default:return 0; } }










int func_021B7D34(void *a,int b,char *c,void **d) { if(func_0201C6B4(((struct Obj20710 *)(*(char * *)&((struct Obj20709 *)c)->f4))->f8)==0) return 0; func_02043534(8); func_021B7E24(d); func_021B6EEC(d); func_021B7D98(); func_020315D4(a); return 1; }









void func_021B7D6C(void) { func_0203FCA0(2,(const struct BgTemplate *)d_021BA928,0); func_02041300(2,0,0,0,0x20,0x20,0x11); }









void func_021B7D98(void) { func_02040588(2, 0); func_020403F4(2); }









void func_021B7DAC(void *a,unsigned *b) { func_020498F4((void *)b[12],11,2,0,0,1,0x61); func_021B7234(a,0,2); func_020409B4(2); }








void func_021B7DE0(S *a, int *b)
{
    int i;
    int t = (int)func_021B6F40((u8 **)b);

    for (i = 0; i < 6; i++) {
        int r;
        unsigned u = d_021BAA4C[i];
        r = func_021B6F54((struct P *)b[1], (u8 *)t, i, (const int *)(d_021BA948 + u * 8), 0);
        a->v[i] = r;
    }
}









void func_021B7E24(void **p) { int i; for(i=0;i<6;i++) func_021B6FD8(p[i+3]); }









void func_021B7E3C(void **a,void *p) { int i; unsigned char *t; t=func_021B6F40(p); for(i=0;i<6;i++) func_021B6FE0(a[i+3],t,i); }








int func_021B7E60(struct Obj0203159C *a, int unused, C_021B7E60 *c)
{
    void *h = func_020120F4(*(void **)c->q);
    W_021B7E60 *w = func_0203159C(a, 0x48, 0x61);

    func_02082BCC(w, 0, 0x48);
    if (func_020142E8((void *)func_0201296C(h), 0x980) == 0) {
        w->f32 = 2;
    } else if (c->q->f3d == 1) {
        w->f32 = 1;
    } else {
        w->f32 = 0;
    }
    func_021B8308();
    func_021B8350((W_021B7AAC *)w, c->f4);
    func_021B81A0((int *)c, (u8 *)w);
    func_021B82E4(c, (int)w);
    func_02043598(0x10, 1);
    return 1;
}










int func_021B7EE0(int a, int *state, C_021B7EE0 *c, D_021B7AAC *d)
{
    u8 *r;
    int res;
    u32 keys;
    int t;

    r = (u8 *)func_02158344(func_02012138(*c->f0));
    func_021B82A4((int *)c, (char *)d);
    func_021B82FC(d);
    if (c->f2e == 1) {
        return 1;
    }
    switch (*state) {
    case 0:
        res = func_02035C08(&d_021BA9F8[d->kind]);
        if (res != -1) {
            d->sel = res;
            d->res = d_021BA9C8[d->kind][res];
            func_020355D8(1);
            d->armed = 0;
            (*state)++;
            break;
        }
        keys = func_0203633C();
        t = func_020362DC();
        if (t > 0 && d->armed == 1) {
            func_020355D8(0);
            d->armed = 0;
            func_021B6B98(c, (int *)d, d_021BA978[d->kind], d->sel, 3);
            func_020061E4(0x548);
            break;
        }
        if (t & 1) {
            d->res = d_021BA9C8[d->kind][d->sel];
            (*state)++;
        } else if (t & 2) {
            d->res = 3;
            (*state)++;
        } else if (keys & 0x80) {
            d->sel++;
            if (d->sel >= d_021BA978[d->kind]) {
                d->sel = 0;
            }
            func_021B6B98(c, (int *)d, d_021BA978[d->kind], d->sel, 3);
            func_020061E4(0x548);
        } else if (keys & 0x40) {
            d->sel--;
            if (d->sel < 0) {
                d->sel = d_021BA978[d->kind] - 1;
            }
            func_021B6B98(c, (int *)d, d_021BA978[d->kind], d->sel, 3);
            func_020061E4(0x548);
        }
        break;
    case 1:
        if (d->res == 0) {
            if (((u8 *)c->f0)[0x3d] == 0) {
                (*state)--;
                break;
            }
            if (r != 0 && func_02175B14(r + 0x1ac) == 1) {
                func_020061E4(0x54c);
                func_021B83CC((W_021B83C0 *)d, (X *)c->f4, 4);
                *state = 3;
                break;
            }
        }
        if (d->res != 3) {
            func_021B6BEC(c, (int *)d, d_021BA978[d->kind], d->sel, 3);
            func_020061E4(0x54c);
        } else {
            func_021B7108(d->f34);
            func_020061E4(0x551);
        }
        (*state)++;
        break;
    case 2:
        if (d->res != 3) {
            if (func_021B6C74(c, 3) != 2) {
                c->f2c = d->res + 1;
                return 1;
            }
        } else {
            if (func_021B7114(d->f34) == 0) {
                c->f2c = d->res + 1;
                return 1;
            }
        }
        break;
    case 3:
        if (func_021B8434(c->f4, (u8 *)d) == 1) {
            if (func_02035C60() != 0 || (func_020362DC() & 3) != 0) {
                func_021B8440((W_021B83C0 *)d);
                func_020061E4(0x547);
                *state = 0;
            }
        }
        break;
    }
    return 0;
}








int func_021B8150(void *a, int unused, B *b, W_021B8150 *w)
{

    if (func_0201C6B4(b->f4->f8) == 0) {
        return 0;
    }
    func_020435F4(8);
    if (w->f40 != 0) {
        func_0201CE48(w->f40);
    }
    if (w->f44 != 0) {
        func_02045808(w->f44);
    }
    func_021B8270((unsigned char *)w);
    func_021B82F0(w);
    func_021B83C0(w);
    func_021B833C();
    func_020315D4(a);
    return 1;
}









void func_021B81A0(int *a, u8 *p)
{
    unsigned i;
    unsigned k;

    func_021B6C54((char *)a);
    for (i = 0; i < d_021BA978[p[0x32]]; i++) {
        k = p[0x32];
        if (k == 1) {
            func_021B6A0C((Ctx_021B6A0C *)a[1], (Out_021B6A0C *)(p + i * 16), 1, 1, 0x80, d_021BA9A4[k][i], i + 1, 0);
        } else if (k == 0) {
            func_021B6A0C((Ctx_021B6A0C *)a[1], (Out_021B6A0C *)(p + i * 16), 1, 1, 0x80, d_021BA9A4[k][i], i + 2, 0);
        } else if (k == 2) {
            func_021B6A0C((Ctx_021B6A0C *)a[1], (Out_021B6A0C *)(p + i * 16), 1, 1, 0x80, d_021BA9A4[k][i], i == 0 ? 1 : 3, 0);
        }
    }
    if (func_020355C4() == 0) {
        func_021B6B98(a, (int *)p, d_021BA978[p[0x32]], 0, 3);
        p[0x33] = 0;
    } else {
        p[0x33] = 1;
    }
}








void func_021B8270(unsigned char *p) { unsigned i; for(i=0;i<d_021BA978[p[0x32]];i++) func_021B6B38((void **)(p+i*16)); }







void func_021B82A4(int *a, char *p)
{
    unsigned i;

    func_021B6C7C(a, 3);
    for (i = 0; i < d_021BA978[((struct Obj20722 *)p)->f32]; i++) {
        func_021B6B70((void **)a[1], (u8 *)(p + i * 16));
    }
}







/*
 * Tail call to func_021B7070(word at 0x4, a + 0x34).
 */
void func_021B82E4(void *p, int a)
{
    func_021B7070(((struct Obj04337 *)p)->f4, (int *)(a + 0x34));
}







void func_021B82F0(void *p)
{
    func_021B70B8((void **)((char *)p + 0x34));
}







void func_021B82FC(void *p)
{
    func_021B70C4((St *)((char *)p + 0x34));
}








void func_021B8308(void) { func_0203FCA0(5,(const struct BgTemplate *)d_021BA984,0); func_02041300(5,0,0,0,0x20,0x20,0x11); func_02040588(5,0); }








void func_021B833C(void) { func_02040588(5, 0); func_020403F4(5); }







void func_021B8350(W_021B7AAC *w, int *b)
{

    func_0201F554(5, 1, 0, 0x61);
    func_020215EC((struct PalAnmSlot *)(*b), 5, func_0201F548(0), 0x61, 1, 0x20, 0xb0, 0);
    w->f3c = func_020450F0(5, 1, 0x13, 0x1e, 4, 0xd, 1);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)w->f3c)), 0xff);
    func_02045374((struct Cfg *)w->f3c);
    func_0201F73C((void *)w->f3c, 0, 1, 0xb);
}






/*
 * Tail call to func_020452E8 on the pointer loaded from offset 0x3c.
 */
void func_021B83C0(void *p)
{
    func_020452E8(((struct Obj20724 *)p)->f3C);
}






void func_021B83CC(W_021B83C0 *w, X *x, unsigned y)
{
    if (w->f40 != 0) {
        func_02034714(d_021BABF8, 0, d_021BABF8);
    }
    func_0201DD78(1, 2, 0xf);
    w->f44 = func_02045EC0(x->f28, y);
    w->f40 = func_0201CCE4(w->f3c, 0, 0, (void *)w->f44, x->fc, func_02012FFC(),
                           (void *)x->f18, 10, 0x61, 0xf);
    func_02040588(5, 1);
}








int func_021B8434(u8 *p, u8 *q)
{
    return func_02028484((struct Blk *)(p + 0x38), (void *)(((struct Obj20725 *)q)->f40));
}






void func_021B8440(W_021B83C0 *w)
{
    unsigned r = (unsigned)func_02045770(w->f3c);

    if (w->f40 == 0) {
        func_02034714(d_021BABF8, 0, d_021BABF8);
    }
    func_0201CE48(w->f40);
    w->f40 = 0;
    func_02045808(w->f44);
    w->f44 = 0;
    func_02040588(5, 0);
    func_02043B5C((struct CharBuf *)r, 0xff);
    func_02045334(w->f3c);
    func_0201DD78(0xf, 2, 0);
}






int func_021B8494(struct Obj0203159C *a, int *b, C_021B8494 *c, u8 *d)
{
    u8 *m;
    int busy;
    int i;

    switch (*b) {
    case 0:
        m = func_0203159C(a, 0x28, 0x61);
        func_02082BCC(m, 0, 0x28);
        func_021B8650();
        func_021B86BC((char *)c->f4);
        func_021B86E8((int)((Q_021B83C0 *)c->f4), (P_021B86E8 *)m);
        func_021B8764(c->f4, (char *)m);
        m[0x24] = 0xff;
        *b = *b + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 2; i++) {
            void *q = c->f4->f8;
            u8 *s = d + i * 8;
            if (s[0xc] != 0) {
                if (func_0201C6C4(q, (void *)((unsigned)func_02045770(((struct Obj06186 *)s)->f8))) == 0) {
                    func_02045334(((struct Obj06186 *)s)->f8);
                    s[0xc] = 0;
                }
            }
            if ((!s[0xc]) == 0) {
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
int func_021B855C(int a, int *p, C_021B855C *c, unsigned char *d)
{
    int r;
    int n;
    int i;

    r = func_02158344(func_02012138(*c->f0));
    n = 0;
    if (c->f2d == 1) {
        return 1;
    }
    func_021B6F04((void **)c->f4, d + 0x18);
    for (i = 0; i < 2; i++) {
        void *q = c->f4->f8;
        unsigned char *s = d + i * 8;
        if (s[0xc] != 0) {
            if (func_0201C6C4(q, (void *)((unsigned)func_02045770(((struct Obj06187 *)s)->f8))) == 0) {
                func_02045334(((struct Obj06187 *)s)->f8);
                s[0xc] = 0;
            }
        }
        if ((!s[0xc]) == 1) {
            n++;
        }
    }
    if (n == 2) {
        unsigned v = *c->f8;
        if (d[0x24] != v) {
            func_021B8798((u8 * *)c, (Q_021B8798 *)((Q_021B83C0 *)c->f4), (P_021B8798 *)d, (u8 *)r, v);
            d[0x24] = *c->f8;
        }
    }
    switch (*p) {
    case 0:
        return 0;
    default:
        return 0;
    }
}







int func_021B8618(void *a, void *b, char *c, void **d)
{
    if (func_0201C6B4(((struct Obj20734 *)(*(char * *)&((struct Obj20733 *)c)->f4))->f8) == 0) return 0;
    func_02043534(8);
    func_021B8750(d);
    func_021B869C();
    func_021B878C(d);
    func_020315D4(a);
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






void func_021B86BC(char *p) { func_020498F4((void *)(((struct Obj20735 *)p)->f30),12,2,0,0,1,0x61); func_020409B4(0); func_020409B4(2); }





void func_021B86E8(int unused, P_021B86E8 *p)
{
    int i;

    p->h[0] = func_020450F0(0, 2, 0, 0x1c, 3, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[0]);
    func_02045374((struct Cfg *)p->h[0]);
    p->h[1] = func_020450F0(0, 2, 5, 0x1c, 0x10, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[1]);
    func_02045374((struct Cfg *)p->h[1]);
    for (i = 0; i < 2; i++) {
        p->e[i].h = p->h[i];
        p->e[i].on = 0;
    }
    func_020409B4(0);
}






void func_021B8750(void **p) { func_020452E8(p[0]); func_020452E8(p[1]); }






void func_021B8764(void *p,char *q) { func_021B6E1C((Ctx_021B6E1C *)((Inner *)p), (Out_021B6E1C *)(q+0x18), 1, 0x80, 0xb4, 0x1c, 2, 0x13, 0); }





/*
 * Tail call to func_021B6EEC((char *)p + 0x18).
 */
void func_021B878C(void *p)
{
    func_021B6EEC((void **)((char *)p + 0x18));
}





/*
 * The `src + 0x18` is written in each arm (the compiler tail-merges the
 * adds at the join), the bitfield `y` is read into a local before the
 * first call, and `q->f8` goes through a local reassigned before each
 * draw call so it loads ahead of the nested call.
 */
void func_021B8798(u8 **c, Q_021B8798 *q, P_021B8798 *d, u8 *r, unsigned v)
{
    void *s;
    u8 *src;
    Obj *e;
    u32 y;
    void *t0;
    void *t1;
    void *w;

    s = func_020457B0(0x100, 0x61);
    func_02043B5C(func_02045770(d->h[0]), 0);
    func_02043B5C(func_02045770(d->h[1]), 0);
    if (v == 6 && r != 0 && func_02175B14(r + 0x1AC) == 1) {
        e = (Obj *)func_02175B34(r + 0x1AC);
        src = (u8 *)e + 0x18;
    } else {
        if (v > 6) {
            v = 0;
        }
        e = &q->ent[d_021BAA4C[v]];
        src = *c + 0x18;
    }
    y = e->b18;
    t0 = func_02045EC0(q->f1c, e->kind);
    t1 = func_02045EC0(q->f1c, y);
    func_021762D8(e, src, q->f10, 0x61);
    func_0201F250(q->f10, s, t1);
    w = q->f8;
    func_0201C6FC(w, (u32)func_02045770(d->e[0].h), 0, 4, t0, (u32)q->fc);
    d->e[0].on = 1;
    w = q->f8;
    func_0201C6FC(w, (u32)func_02045770(d->e[1].h), 0, 0, s, (u32)q->fc);
    d->e[1].on = 1;
    func_02045808(t0);
    func_02045808(t1);
    func_02045808(s);
}





/*
 * Twin of func_021B8494 (six handle slots at +0x18 instead of two at +8).
 */
int func_021B889C(struct Obj0203159C *a, int *b, C_021B889C *c, u8 *d)
{
    u8 *m;
    int busy;
    int i;

    switch (*b) {
    case 0:
        m = func_0203159C(a, 0x50, 0x61);
        func_02082BCC(m, 0, 0x50);
        func_021B8A70();
        func_021B8ADC((char *)c->f4);
        func_021B8B08((int)c->f4, (P_021B8B08 *)m);
        func_021B8EC4(c, (int)m);
        func_021B8C0C((C_021B8A70 *)c, (Q *)c->f4, (P_021B8C0C *)m);
        *b = *b + 1;
        break;
    case 1:
        busy = 0;
        for (i = 0; i < 6; i++) {
            void *q = c->f4->f8;
            u8 *s = d + i * 8;
            if (s[0x1c] != 0) {
                if (func_0201C6C4(q, (void *)((unsigned)func_02045770(((struct Obj06189 *)s)->f18))) == 0) {
                    func_02045334(((struct Obj06189 *)s)->f18);
                    s[0x1c] = 0;
                }
            }
            if ((!s[0x1c]) == 0) {
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
int func_021B8968(int a, int *b, C_021B8968 *c, u8 *d)
{
    int i;
    int t;

    if (c->f2e == 1) {
        return 1;
    }
    for (i = 0; i < 6; i++) {
        void *q = c->f4->f8;
        u8 *s = d + i * 8;
        if (s[0x1c] != 0) {
            if (func_0201C6C4(q, (void *)((unsigned)func_02045770(((struct Obj07702 *)s)->f18))) == 0) {
                func_02045334(((struct Obj07702 *)s)->f18);
                s[0x1c] = 0;
            }
        }
    }
    func_021B8EDC(d);
    switch (*b) {
    case 0:
        t = func_020362DC();
        if (func_02035C08(d_021BAAA4) != -1 || (t & 2) != 0) {
            func_021B7108(d + 0x48);
            if (t & 2) {
                func_020355D8(0);
            } else {
                func_020355D8(1);
            }
            func_020061E4(0x551);
            *b = *b + 1;
        }
        break;
    case 1:
        if (func_021B7114(d + 0x48) == 0) {
            c->f2c = 0;
            return 1;
        }
        break;
    }
    return 0;
}






int func_021B8A38(void *a, void *b, char *c, void **d)
{
    if (func_0201C6B4(((struct Obj20740 *)(*(char * *)&((struct Obj20739 *)c)->f4))->f8) == 0) return 0;
    func_020435F4(8);
    func_021B8ED0(d);
    func_021B8BF4(d);
    func_021B8ABC();
    func_020315D4(a);
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






void func_021B8ADC(char *p) { func_020498F4((void *)(((struct Obj20741 *)p)->f30),5,6,0,0,1,0x61); func_020409B4(6); func_020409B4(4); }




/*
 * Six-window twin of func_021B86E8.
 */
void func_021B8B08(int unused, P_021B8B08 *p)
{
    int i;

    p->h[0] = func_020450F0(4, 2, 0, 0x1e, 3, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[0]);
    func_02045374((struct Cfg *)p->h[0]);
    p->h[1] = func_020450F0(4, 2, 5, 0x1e, 2, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[1]);
    func_02045374((struct Cfg *)p->h[1]);
    p->h[2] = func_020450F0(4, 2, 8, 0x1e, 2, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[2]);
    func_02045374((struct Cfg *)p->h[2]);
    p->h[3] = func_020450F0(4, 2, 0xe, 0x1e, 4, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[3]);
    func_02045374((struct Cfg *)p->h[3]);
    p->h[4] = func_020450F0(4, 2, 0x10, 0x1e, 2, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[4]);
    func_02045374((struct Cfg *)p->h[4]);
    p->h[5] = func_020450F0(4, 2, 0x12, 0x1e, 2, 0xd, 1);
    func_02045334((struct Descriptor *)p->h[5]);
    func_02045374((struct Cfg *)p->h[5]);
    for (i = 0; i < 6; i++) {
        p->e[i].h = p->h[i];
        p->e[i].on = 0;
    }
    func_020409B4(4);
}






void func_021B8BF4(void **p) { int i; for (i=0;i<6;i++) func_020452E8(p[i]); }







static inline void Draw(Q *q, void *h, u32 x, u32 y, void *buf)
{
    void *w = q->f8;
    func_0201C6FC(w, (u32)func_02045770(h), x, y, buf, (u32)q->fc);
}







/*
 * Each window draw is a `static inline` whose `q->f8` local gets its own
 * spill slot per inlined copy (seven slots, 0x24 down to 0xc).
 */
void func_021B8C0C(C_021B8A70 *c, Q *q, P_021B8C0C *d)
{
    Counts *x;
    s64 v;
    u32 hours;
    u32 min;
    void *s0;
    void *s1;

    func_021B6F2C((u8 **)c);
    x = func_021B6F40((u8 **)c);
    s0 = func_020457B0(0x100, 0x61);
    s1 = func_020457B0(0x100, 0x61);

    func_02045CAC(q->f28, 0xd, s0);
    Draw(q, d->e[0].h, 0, 4, s0);
    d->e[0].on = 1;

    func_02045CAC(q->f28, 5, s0);
    func_0201EFA4(q->f10, 0, x->m + x->n, 5, 0, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[1].h, 0, 0, s1);
    d->e[1].on = 1;

    func_02045CAC(q->f28, 9, s0);
    func_0201EFA4(q->f10, 0, x->m, 4, 0, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[2].h, 0, 0, s1);
    d->e[2].on = 1;

    func_02045CAC(q->f28, 8, s0);
    func_0201EFA4(q->f10, 0, x->n, 4, 0, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[2].h, 0x78, 0, s1);
    d->e[2].on = 1;

    v = c->f0->f30;
    hours = v / 60 / 60;
    if (hours > 999) {
        hours = 999;
        min = 59;
    } else {
        v -= hours * 3600;
        min = v / 60;
    }
    func_02045CAC(q->f28, 0xb, s0);
    func_0201EFA4(q->f10, 0, hours, 3, 1, 1);
    func_0201EFA4(q->f10, 1, min, 2, 2, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[3].h, 0, 0, s1);
    d->e[3].on = 1;

    func_02045CAC(q->f28, 0xc, s0);
    func_0201EFA4(q->f10, 0, c->f0->f2c, 5, 0, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[4].h, 0, 0, s1);
    d->e[4].on = 1;

    func_02045CAC(q->f28, 0xa, s0);
    func_0201EFA4(q->f10, 0, func_0216FEAC(q->f34, func_021B6F40((u8 **)c), c->f0->f38), 4, 0, 1);
    func_0201F250(q->f10, s1, s0);
    Draw(q, d->e[5].h, 0, 0, s1);
    d->e[5].on = 1;

    func_02045808(s0);
    func_02045808(s1);
}




/*
 * Tail call to func_021B7070(word at 0x4, a + 0x48).
 */
void func_021B8EC4(void *p, int a)
{
    func_021B7070(((struct Obj06188 *)p)->f4, (int *)(a + 0x48));
}




/*
 * Tail call to func_021B70B8 with the pointer advanced by 0x48.  The callee
 * is an unlabelled leaf in this overlay; it is reproduced in
 * src/matched/ov071_func_021B70B8.c, whose EXACT entry attests this pool-word
 * site (`matched`).
 */
void func_021B8ED0(void *p)
{
    func_021B70B8((void **)((char *)p + 0x48));
}




/*
 * Tail call to func_021B70C4((char *)p + 0x48).
 */
void func_021B8EDC(void *p)
{
    func_021B70C4((St *)((char *)p + 0x48));
}







int func_021B8EE8(struct Obj0203159C *a, int *b, u8 *c, u8 *o)
{
    int busy;
    u32 t;
    Bool f;

    switch (*b) {
    case 0:
        o = func_0203159C(a, 0x314, 0x61);
        func_02082BCC(o, 0, 0x314);
        ((struct Obj01884 *)o)->f2D8 = 0x800;
        ((struct Obj01884 *)o)->f300 = 0xffff;
        ((struct Obj01884 *)o)->f2F8 = 0xffff;
        ((struct Obj01884 *)o)->f2FC = 0xffff;
        func_021B6C54((char *)c);
        ((struct Obj01884 *)o)->f20 = (int)func_02045B38(0, 2, 0xa0, 0x61);
        func_021B9560();
        func_021B95FC(o, ((struct Obj02123 *)c)->f4);
        func_021B96A4((char *)o, ((struct Obj02123 *)c)->f4);
        func_021BA11C((char *)o);
        func_021B9BB8((char *)c, (char *)o);
        func_021B9AE4(o, ((struct Obj02123 *)c)->f4);
        func_021B9B64((char *)c, (char *)o);
        func_021B9BE8((char *)c, (char *)o);
        func_021B9750((char *)c, (char *)o);
        ((struct Obj01884 *)o)->f30C = (int)func_021B7174(((struct Obj02123 *)c)->f4, 4, 0x61);
        (*(u8 **)(c + 8))[1] = 0x30;
        ((struct Obj01884 *)o)->f0 = func_020056A0((void (*)(void))func_021BA1B0, o, 3);
        func_021B9970((char **)c, (List *)o, (char *)((struct Obj02123 *)c)->f4);
        func_021B992C((char *)o);
        *b = *b + 1;
        break;
    case 1:
        if (func_021B9A40((char *)o, ((struct Obj02123 *)c)->f4) == 1) {
            func_021BA140(o);
            ((struct Obj01884 *)o)->f2F0 = 1;
            if (func_020355C4() == 0) {
                func_021B9F2C(o, 1, 0);
            } else {
                func_021B9F2C(o, 0xffff, 0);
            }
            *b = *b + 1;
        }
        break;
    case 2:
        busy = 0;
        t = (*(u32 **)(c + 4))[2];
        if (o[0x28c] != 0) {
            if (func_0201C6C4((struct PrintSys *)t, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj01884 *)o)->f288))) == 0) {
                func_02045334((struct Descriptor *)((struct Obj01884 *)o)->f288);
                o[0x28c] = 0;
            }
        }
        f = o[0x28c] == 0 ? B_TRUE : B_FALSE;
        if (f == B_FALSE) {
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
int func_021B9070(int unused,int *state,u8 *c,u8 *o)
{
    u32 initial,handle,mask,save;
    int active,result,off;
    unsigned short flip;
    initial=func_02158344(func_02012138((const struct Ctx *)*(u32 *)CP(0)));
    func_021B6C7C((int *)c,1); func_021B6C7C((int *)c,3);
    func_021B9BD8((char *)o); func_021B9BAC(CP(4),(u32)o);
    handle=*(u32 *)(CP(4)+8);
    if (o[0x28c]!=0 && func_0201C6C4((struct PrintSys *)handle,(void *)((u32)func_02045770((struct Descriptor *)W(0x288))))==0) {
        func_02045334((struct Descriptor *)W(0x288)); o[0x28c]=0;
    }
    if (c[0x2e]==1 && *state==4) return 1;
    switch (*state) {
    case 0: *state=1; break;
    case 1: func_021B9798((char *)o,(char *)CP(4),0x25); ++*state; break;
    case 2:
        if (func_021B98B4(CP(4),o)==1 && (func_02035C60()!=0 || (func_020362DC()&3))) {
            func_021B98C4((char *)o); func_020061E4(0x547);
            if (func_02035C60()==0) func_021B9F2C(o,1,0);
            else func_021B9F2C(o,0xffff,0);
            ++*state;
        } break;
    case 3:
        if (func_02035C38()==0 && !(func_0203630C()&3)) *state=4;
        break;
    case 4:
        mask=func_020362DC(); active=func_02035C08(d_021BAAFC);
        if (active==0 || (mask&2)) {
            func_021B7108(o+0x298);
            if (active==0) func_020355D8(TRUE);
            else func_020355D8(FALSE);
            func_020061E4(0x551); *state=17; break;
        }
        func_021B9C7C(c,o); func_021BA004((char *)o);
        off=0x2e0;
        if (func_021BA0CC(o,W(off)+W(off+4))==1) {
            func_021BA11C((char *)o); func_021BA140(o); W(off+16)=1;
        }
        func_021BA01C(c,o);
        if (W(0x2f4)==0xffff) { CP(8)[1]=0x30; }
        else {
            CP(8)[1]=*(u32 *)(o+(W(0x2f4)<<2)+0xec);
            CP(8)[2]=*(u32 *)(o+(W(0x2f4)<<2)+0x1b4);
            if (*(u32 *)(o+(W(0x2f4)<<2)+0x1b4)==0) {
                func_021B6B58((void **)(o+8),1); goto selected;
            }
        }
        func_021B6B58((void **)(o+8),0);
selected:
        if (W(0x300)!=0xffff) { func_020061E4(0x54c); *state=5; }
        break;
    case 5:
        if (func_021B6C74(c,1)!=2 && func_021B6C74(c,3)!=2) {
            func_021B9798((char *)o,(char *)CP(4),0x20); ++*state;
        } break;
    case 6:
        if (func_021B98B4(CP(4),o)==1) {
            if (W(0x310)!=0) func_02034714((const char *)d_021BABFC,0,(const char *)d_021BABFC);
            W(0x310)=(u32)func_021B7194((int *)CP(4),(void *)W(0x30c),0x61); ++*state;
        } break;
    case 7:
        if (func_021B7204(C_021B8A70(4),4,(void *)W(0x310),&result)==1) {
            func_021B71FC((void *)W(0x310)); W(0x310)=0; func_021B98C4((char *)o);
            if (result==1) *state=8;
            else { W(0x300)=0xffff; func_021B6C30((int *)c,1,1); func_021B6B98(c,(int *)(o+8),1,0xff,3); *state=4; }
        } break;
    case 8:
        if (func_021B6C74(c,1)!=2 && func_021B6C74(c,3)!=2) {
            func_0201F184((struct WordSet *)(*(u32 *)(CP(4)+0x10)),0,*(u32 *)(o+(W(0x300)<<2)+0xec));
            func_021B9818((char *)o,(char *)CP(4),0x23); *state=9;
        } break;
    case 9:
        if (initial==0) goto write10;
        if (func_02174660(CP(0)[0x3c])==1) { *state=10; break; }
        break;
write10:
        *state=10;
        break;
    case 10:
        if (func_021B98B4(CP(4),o)==1) { func_02005E30(6); ++*state; }
        break;
    case 11:
        if (func_02005E50()==0) { func_02005DE4((void *)1); func_02005E64(); ++*state; }
        break;
    case 12: func_02005D90(0x531,0xffff); ++*state; break;
    case 13:
        if (func_02005F38()==0) { func_02005E9C(); func_02005DE4(0); func_02005DF8(6); ++*state; }
        break;
    case 14: if (func_02005E50()==0) *state=15; break;
    case 15:
        if (func_02035C60()!=0 || (func_020362DC()&3)) {
            func_021B98C4((char *)o);
            func_0200BF08((struct Rec1B0 *)func_0200BE48(func_02012EBC(func_020120F4((const struct Ctx *)(*(u32 *)CP(0))))),*(u32 *)(o+(W(0x300)<<2)+0xec));
            save=func_02012138((const struct Ctx *)*(u32 *)CP(0));
            handle=C_021B8A70(0);
            func_020266AC(save,func_02012B58(func_020120F4((const struct Ctx *)(((struct Obj13181 *)handle)->f0))),((struct Obj13181 *)handle)->f3C);
            W(0x300)=0xffff; func_021B6C30((int *)c,1,1); func_021B6B98(c,(int *)(o+8),1,0xff,3);
            if (func_02035C60()!=0) *state=16;
            else *state=17;
        } break;
    case 16: if (func_02035C38()==0) *state=17; break;
    case 17:
        if (func_021B6C74(c,1)!=2 && func_021B6C74(c,3)!=2 && func_021B7114(o+0x298)==0) {
            c[0x2c]=0; return 1;
        } break;
    }
    func_021B9C30(o); return 0;
}







int func_021B94CC(void *a, void *b, char *c, char *d)
{
    if (func_0201C6B4(((struct Obj20747 *)(*(char * *)&((struct Obj20746 *)c)->f4))->f8) == 0)
        return 0;
    func_020435F4(8);
    func_02030EAC(((struct Obj03177 *)d)->f0);
    if (((struct Obj03177 *)d)->f294 != 0)
        func_0201CE48(((struct Obj03177 *)d)->f294);
    if (((struct Obj03177 *)d)->f290 != 0)
        func_02045808(((struct Obj03177 *)d)->f290);
    func_021B9A18(d);
    if (((struct Obj03177 *)d)->f310 != 0)
        func_021B71FC(((struct Obj03177 *)d)->f310);
    func_021B718C(((struct Obj03177 *)d)->f30C);
    func_021B9BA0(d);
    func_021B9B3C(d);
    func_021B9BC8(d);
    func_021B9C1C(d);
    func_021B9694((unsigned int *)d);
    func_021B9734(d);
    func_021B95CC();
    func_02045C04(((struct Obj03177 *)d)->f20);
    func_020315D4(a);
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







void func_021B95FC(void *a, void *b)
{
    char *d = (char *)a;
    char *r5 = (char *)b;
    void *h;

    func_020498F4(((struct Obj09895 *)r5)->f30, 7, 6, 0, 0, 1, 0x61);
    func_02049658(((struct Obj09895 *)r5)->f30, 0xe, 5, 0, 0, 1, 0x61);
    func_020498F4(((struct Obj09895 *)r5)->f30, 9, 5, 0, 0, 1, 0x61);
    h = func_020490F4(0x53, 0x61);
    ((struct Obj09894 *)d)->f4 = (void *)func_0203FA08(5, 0x80, 1);
    func_02049658(h, 0x1c, 5, (u32)(((struct Obj09894 *)d)->f4), 0x80, 0, 0x61);
    func_02027634(h, 5, 0x61, (int)(((struct Obj09894 *)d)->f4), 0xc);
    func_02049238(h);
    func_020409B4(5);
    func_020409B4(6);
}






void func_021B9694(unsigned int *p) { func_0203FB44(5, p[1], 0x80); }







void func_021B96A4(char *a, void **b)
{
    func_0201F554(4, 1, 0, 0x61);
    func_020215EC(*b, 5, func_0201F548(0), 0x61, 1, 0x20, 0xb0, 0);
    ((struct Obj04341 *)a)->f280 = (void *)func_020450F0(4, 1, 0x13, 0x1e, 4, 0xd, 1);
    func_02043B5C(func_02045770(((struct Obj04341 *)a)->f280), 0xff);
    ((struct Obj04341 *)a)->f284 = (void *)func_020450F0(4, 0, 0, 0x20, 3, 0xd, 1);
    func_02045374(((struct Obj04341 *)a)->f284);
    func_020409B4(4);
    ((struct Obj04341 *)a)->f288 = ((struct Obj04341 *)a)->f284;
    ((struct Obj04341 *)a)->f28C = 0;
}






void func_021B9734(char *p) { int i; for (i=0;i<2;i++) func_020452E8(*(void **)(p + 0x280 + i*4)); }





void func_021B9750(char *a, char *b)
{
    void *r6;
    char *r4;
    void *r7;

    r6 = func_02045EC0(((struct Obj20750 *)(*(char * *)&((struct Obj02123 *)a)->f4))->f28, 0x22);
    r4 = *(char * *)&((struct Obj02123 *)a)->f4;
    r7 = ((struct Obj13183 *)r4)->f8;
    func_0201C6FC(r7, (u32)func_02045770(((struct Obj13182 *)b)->f288), 0x18, 4, r6, (u32)(((struct Obj13183 *)r4)->fC));
    ((struct Obj13182 *)b)->f28C = 1;
    func_02045808(r6);
}





void func_021B9798(char *a, char *b, u32 c)
{
    if (((struct Obj00044 *)a)->f294 != 0)
        func_02034714(d_021BABFC, 0, d_021BABFC);
    func_0201DD78(1, 2, 0xf);
    ((struct Obj00044 *)a)->f290 = func_02045EC0(((struct Obj09896 *)b)->f28, c);
    ((struct Obj00044 *)a)->f294 = func_0201CCE4((void *)((struct Obj00044 *)a)->f280, 0, 0, (void *)((struct Obj00044 *)a)->f290, ((struct Obj09896 *)b)->fC, func_02012FFC(), (void *)((struct Obj09896 *)b)->f18, 0xa, 0x61, 0xf);
    func_02045374(((struct Obj00044 *)a)->f280);
    func_0201F73C(((struct Obj00044 *)a)->f280, 1, 1, 0xb);
}





void func_021B9818(char *a, char *b, u32 c)
{
    void *r6;

    if (((struct Obj00044 *)a)->f294 != 0)
        func_02034714(d_021BABFC, 0, d_021BABFC);
    func_0201DD78(1, 2, 0xf);
    r6 = func_02045EC0(((struct Obj07704 *)b)->f28, c);
    ((struct Obj00044 *)a)->f290 = func_020457B0(0x100, 0x61);
    func_0201F250(((struct Obj07704 *)b)->f10, ((struct Obj00044 *)a)->f290, r6);
    func_02045808(r6);
    ((struct Obj00044 *)a)->f294 = func_0201CCE4((void *)((struct Obj00044 *)a)->f280, 0, 0, (void *)((struct Obj00044 *)a)->f290, ((struct Obj07704 *)b)->fC, func_02012FFC(), (void *)((struct Obj07704 *)b)->f18, 0xa, 0x61, 0xf);
    func_02045374(((struct Obj00044 *)a)->f280);
    func_0201F73C(((struct Obj00044 *)a)->f280, 1, 1, 0xb);
}




/*
 * leaf: unlabelled tail stub called by func_021B9070; parent confirmed unowned.
 */
int func_021B98B4(u8 *a,u8 *b)
{
    return func_02028484((struct Blk *)(a+0x38),(void *)(((struct Obj20751 *)b)->f294));
}





void func_021B98C4(char *a)
{
    void *r6;

    r6 = func_02045770(((struct Obj00044 *)a)->f280);
    if (((struct Obj00044 *)a)->f294 == 0)
        func_02034714(d_021BABFC, 0, d_021BABFC);
    func_0201CE48(((struct Obj00044 *)a)->f294);
    ((struct Obj00044 *)a)->f294 = 0;
    func_02045808(((struct Obj00044 *)a)->f290);
    ((struct Obj00044 *)a)->f290 = 0;
    func_0201F7A8(((struct Obj00044 *)a)->f280, 0);
    func_02043B5C(r6, 0xff);
    func_02045334(((struct Obj00044 *)a)->f280);
    func_0201DD78(0xf, 2, 0);
}





void func_021B992C(char *a)
{
    int x;
    int t;

    x = ((struct Obj20752 *)a)->f27C;
    if (x - 2 < 7) {
        t = (x - 1) * 32 / 8;
        func_02041300(6, 0, 0, (u8)t, 0x20, 0x20 - t, 0x11);
        func_020409B4(6);
    }
}





void func_021B9970(char **a, List *l, char *c)
{
    Idx i = 0;
    int n;
    int r;
    void *pos;

    func_020120F4((const struct Ctx *)(**(char ** *)&((struct Obj04340 *)a)->f0));
    pos = func_021B6F40((u8 **)a);
    l->idx[0] = i;
    l->kind[0] = 1;
    l->obj[0] = func_02043678(0x17, 2, 0x20, 0x61);
    n = i + 1;
    for (; i < 0x30; i++) {
        r = func_0216FE2C(((struct Obj20753 *)c)->f34, i, pos, (u8 *)(*a + 0x38));
        if (r != 2) {
            l->idx[n] = i;
            l->kind[n] = r;
            l->obj[n] = func_02043678(0x17, 2, 0x20, 0x61);
            n++;
        }
    }
    l->idx[n] = 0;
    l->kind[n] = 1;
    l->obj[n] = func_02043678(0x17, 2, 0x20, 0x61);
    l->count = n + 1;
}




void func_021B9A18(char *p) { int i; for (i = 0; i < ((struct Obj20755 *)p)->f27C; i++) func_020437AC(*(void **)(p + i * 4 + 0x24)); }





int func_021B9A40(char *a, char *b)
{
    int j;
    int i;
    char *r6;
    void *buf;

    j = 0;
    buf = func_020457B0(0x20, 0x61);
    i = ((struct Obj03664 *)a)->f27D;
    if (i < ((struct Obj03664 *)a)->f27C) {
        do {
            if (i >= 1 && i < ((struct Obj03664 *)a)->f27C - 1) {
                r6 = a + i * 4;
                func_02045CAC((struct MsgBank *)(((struct Obj03664 *)a)->f20), ((struct Obj09897 *)r6)->fEC, buf);
                func_0201C7D0(((struct Obj09897 *)r6)->f24, 0, 0, buf, ((struct Obj20756 *)b)->fC,
                              d_021BAAF8[((struct Obj09897 *)r6)->f1B4]);
            }
            j++;
            if (j >= 3)
                break;
            i++;
        } while (i < ((struct Obj03664 *)a)->f27C);
    }
    func_02045808(buf);
    ((struct Obj03664 *)a)->f27D = i;
    return ((struct Obj03664 *)a)->f27D >= ((struct Obj03664 *)a)->f27C;
}
