/*
 * file:     startmenu_p01.c
 * unit:     yes
 * function: func_021B95A0, func_021B95CC, func_021B965C, func_021B9750, func_021B9874, func_021B98BC, func_021B9910, func_021B9928, func_021B9954, func_021B997C, func_021B99E0, func_021B99EC, func_021B9A14, func_021B9A1C, func_021B9BD4, func_021B9C08, func_021B9C2C, func_021B9DD0, func_021B9E54, func_021B9E7C, func_021B9EC4, func_021B9F68, func_021B9F70, func_021B9F94, func_021B9FE4, func_021BA014, func_021BA114, func_021BA1A0, func_021BA218, func_021BA230, func_021BA2C8, func_021BA338, func_021BA4A0, func_021BA540, func_021BA6B0, func_021BA7AC, func_021BA880, func_021BA990, func_021BA9B0, func_021BA9C8, func_021BA9D4, func_021BA9E8, func_021BAB20, func_021BAB64, func_021BAC24, func_021BAC64, func_021BAC74, func_021BACD8, func_021BAD08, func_021BB164, func_021BB184, func_021BB328, func_021BB380, func_021BB474, func_021BB484, func_021BB4B4, func_021BB544, func_021BB5C4, func_021BB5E0, func_021BB608, func_021BB798, func_021BB810, func_021BB840, func_021BB858, func_021BB890, func_021BB9DC, func_021BBA64
 * address:  0x021B95A0
 * region:   ov088
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204E720  0x0204E720  arm
 *   func_0204363C  0x0204363C  arm
 *   func_02040588  0x02040588  arm
 *   func_02043598  0x02043598  arm
 *   func_020434DC  0x020434DC  arm
 *   func_0201160C  0x0201160C  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_02006984  0x02006984  thumb
 *   func_02005E30  0x02005E30  thumb
 *   func_0204E804  0x0204E804  arm
 *   func_02005DAC  0x02005DAC  thumb
 *   func_02006BD0  0x02006BD0  thumb
 *   func_02005E50  0x02005E50  thumb
 *   func_02005D28  0x02005D28  thumb
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_020312F8  0x020312F8  arm
 *   d_021BD66C     0x021BD66C  data  a4
 *   d_021BD974     0x021BD974  data  a4
 *   d_02184904     0x02184904  data  a4  ov168
 *   ov088_id       0x00000058  data  a1
 *   ov168_id       0x000000A8  data  a1
 *   func_0207D534  0x0207D534  arm
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_020433E0  0x020433E0  arm
 *   func_0203FC28  0x0203FC28  arm
 *   d_021BD508     0x021BD508  data  a4  ov088
 *   d_021BD420     0x021BD420  data  a4  ov088
 *   func_0204A648  0x0204A648  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_02045088  0x02045088  arm
 *   func_02046440  0x02046440  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   func_0203101C  0x0203101C  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_0204361C  0x0204361C  arm
 *   func_020310C4  0x020310C4  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02031140  0x02031140  arm
 *   func_02046788  0x02046788  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02049624  0x02049624  arm
 *   func_0204989C  0x0204989C  arm
 *   func_02049B40  0x02049B40  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_02045334  0x02045334  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_0201C724  0x0201C724  thumb
 *   d_021BD470     0x021BD470  data  ov088  a4
 *   d_021BD490     0x021BD490  data  ov088  a4
 *   d_021BD430     0x021BD430  data  ov088  a4
 *   d_021BD450     0x021BD450  data  a4
 *   func_02041EE4  0x02041EE4  arm
 *   func_020111E8  0x020111E8  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_02047CFC  0x02047CFC  arm
 *   func_02047E88  0x02047E88  arm
 *   func_020489F4  0x020489F4  arm
 *   func_02048A18  0x02048A18  arm
 *   func_020477A4  0x020477A4  arm
 *   _ll_mul        0x0209C054  arm
 *   FX_Div         0x0207C768  arm
 *   func_02048A24  0x02048A24  arm
 *   func_02011510  0x02011510  thumb
 *   func_02048BC4  0x02048BC4  arm
 *   func_02048C58  0x02048C58  arm
 *   func_0204044C  0x0204044C  arm
 *   FX_SinCosTable_  0x020A1B38  data
 *   d_021BD410     0x021BD410  data  ov088  a4
 *   d_021BD3EC     0x021BD3EC  data  ov088  a4
 *   d_021BD3F8     0x021BD3F8  data  ov088  a4
 *   d_021BD404     0x021BD404  data  ov088  a4
 *   d_021BD3DC     0x021BD3DC  data  a4
 *   func_020115C0  0x020115C0  thumb
 *   func_02011B8C  0x02011B8C  thumb
 *   func_02048AD0  0x02048AD0  arm
 *   func_02047964  0x02047964  arm
 *   func_020479D8  0x020479D8  arm
 *   func_02047A60  0x02047A60  arm
 *   func_02047970  0x02047970  arm
 *   func_02047910  0x02047910  arm
 *   d_021BD538     0x021BD538  data  ov088  a4
 *   func_02011558  0x02011558  thumb
 *   func_02048AC4  0x02048AC4  arm
 *   func_02048C4C  0x02048C4C  arm
 *   func_020480E4  0x020480E4  arm
 *   func_02047E54  0x02047E54  arm
 *   func_020115EC  0x020115EC  thumb
 *   func_0204784C  0x0204784C  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B270  0x0204B270  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_02049238  0x02049238  arm
 *   d_020A1448     0x020A1448  data  a4
 *   func_0204A600  0x0204A600  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_020070A4  0x020070A4  thumb
 *   func_02008730  0x02008730  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02009210  0x02009210  thumb
 *   func_02012FE4  0x02012FE4  thumb
 *   d_021BD63C     0x021BD63C  data  ov088  a4
 *   func_020274C8  0x020274C8  thumb
 *   func_021BC114  0x021BC114  thumb  ov088
 *   func_021BC0FC  0x021BC0FC  thumb  ov088
 *   func_021BC0E4  0x021BC0E4  thumb  ov088
 *   func_02030734  0x02030734  arm
 *   d_021BDA00     0x021BDA00  data  ov088  a1
 *   d_021DF538     0x021DF538  data  ov121  a4
 *   d_02213C4C     0x02213C4C  data  a4
 *   d_0209DEF0     0x0209DEF0  data  a4
 *   d_021D77AC     0x021D77AC  data  ov016  a4
 *   d_021F6D78     0x021F6D78  data  ov107  a4
 *   d_021BD574     0x021BD574  data  a4
 *   ov121_id       0x00000079  data
 *   ov199_id       0x000000C7  data
 *   ov016_id       0x00000010  data
 *   ov107_id       0x0000006B  data
 *   func_02009448  0x02009448  thumb
 *   func_020092EC  0x020092EC  thumb
 *   func_0200C2F0  0x0200C2F0  thumb
 *   func_0203D210  0x0203D210  arm
 *   func_020221A4  0x020221A4  thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_021BC0C8  0x021BC0C8  thumb  ov088
 *   func_021BC054  0x021BC054  thumb  ov088
 *   func_0202EA40  0x0202EA40  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021BC0AC  0x021BC0AC  thumb  ov088
 *   func_021BC080  0x021BC080  thumb  ov088
 *   func_0203633C  0x0203633C  arm
 *   func_0202EB04  0x0202EB04  thumb
 *   func_020090E0  0x020090E0  thumb
 *   func_021BBF1C  0x021BBF1C  thumb  ov088
 *   func_021BBD80  0x021BBD80  thumb  ov088
 *   func_021BBFA8  0x021BBFA8  thumb  ov088
 *   func_0201FEBC  0x0201FEBC  thumb
 *   func_0202EB44  0x0202EB44  thumb
 *   func_021BBE3C  0x021BBE3C  thumb  ov088
 *   func_021BBF98  0x021BBF98  thumb  ov088
 *   func_021BC024  0x021BC024  thumb  ov088
 *   func_021BBBAC  0x021BBBAC  thumb  ov088
 *   func_021BBD10  0x021BBD10  thumb  ov088
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_021BBE48  0x021BBE48  thumb  ov088
 *   func_02040EBC  0x02040EBC  arm
 *   d_021BD784     0x021BD784  data  ov088  a4
 *   func_020419E4  0x020419E4  arm
 *   SDK_AUTOLOAD_DTCM_START 0x02FE0000 data
 *   func_0204335C  0x0204335C  arm
 *   d_021BD60C     0x021BD60C  data  ov088  a4
 *   d_021BD678     0x021BD678  data  a4
 *   d_021BD724     0x021BD724  data  a4
 *   d_021BD764     0x021BD764  data  a4
 *   d_021BD6C4     0x021BD6C4  data  a4
 *   d_021BD6E4     0x021BD6E4  data  a4
 *   d_021BD744     0x021BD744  data  a4
 *   d_021BD6A4     0x021BD6A4  data  a4
 *   d_021BD704     0x021BD704  data  a4
 *   func_020403F4  0x020403F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_0202E940  0x0202E940  thumb
 *   func_0202E9AC  0x0202E9AC  thumb
 *   func_0202EA20  0x0202EA20  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02028590  0x02028590  thumb
 *   func_02028604  0x02028604  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201F158  0x0201F158  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_020139B0  0x020139B0  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02008848  0x02008848  thumb
 *   func_0200890C  0x0200890C  thumb
 *   func_02013E4C  0x02013E4C  thumb
 *   func_02013A48  0x02013A48  thumb
 *   func_02008748  0x02008748  thumb
 *   func_0200864C  0x0200864C  thumb
 *   func_02008650  0x02008650  thumb
 *   func_0200CA10  0x0200CA10  thumb
 *   func_0200D0AC  0x0200D0AC  thumb
 *   func_0200C258  0x0200C258  thumb
 *   d_021BD7C4     0x021BD7C4  data  a1
 *   func_0204B3DC  0x0204B3DC  arm
 *   d_021BD688     0x021BD688  data  a4
 *   d_021BD5DC     0x021BD5DC  data  a4
 *   d_021BD5E4     0x021BD5E4  data  a4
 *   d_021BD5D4     0x021BD5D4  data  a4
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0202C9B4  0x0202C9B4  thumb
 *   func_0202CA3C  0x0202CA3C  thumb
 *   func_0202CEBC  0x0202CEBC  thumb
 *   d_021BD5EC     0x021BD5EC  data  a4
 *   func_0202CA0C  0x0202CA0C  thumb
 *   func_0207D63C  0x0207D63C  arm
 *   func_020071EC  0x020071EC  thumb
 *   func_0200C308  0x0200C308  thumb
 *   func_02049EF4  0x02049EF4  arm
 *   func_02082A60  0x02082A60  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0204B454  0x0204B454  arm
 *   func_0204B404  0x0204B404  arm
 *   func_020410D0  0x020410D0  arm
 *   func_0202CF84  0x0202CF84  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   d_021BD5EE     0x021BD5EE  data  ov088  a2
 *   func_020413B0  0x020413B0  arm
 *   _s32_div_f     0x0209C0A4  arm
 */
#include "../../matched/include/Obj20810.h"
#include "../../matched/include/Obj00462.h"
#include "../../matched/include/Obj07719.h"
#include "../../matched/include/Obj03674.h"
#include "../../matched/include/Obj07721.h"
#include "../../matched/include/Obj13230.h"
#include "../../matched/include/Obj09921.h"
#include "../../matched/include/Obj13231.h"
#include "../../matched/include/Obj13232.h"
#include "../../matched/include/Obj20813.h"
#include "../../matched/include/Obj01369.h"
#include "../../matched/include/Obj06203.h"
#include "../../matched/include/Obj00271.h"
#include "../../matched/include/Obj01228.h"
#include "../../matched/include/Obj00339.h"
#include "../../matched/include/Obj00263.h"
#include "../../matched/include/Obj02127.h"
#include "../../matched/include/Obj00014.h"
#include "../../matched/include/Obj20816.h"
#include "../../matched/include/Obj20817.h"
#include "../../matched/include/Obj20818.h"
#include "../../matched/include/Obj20819.h"
#include "../../matched/include/Obj20820.h"
#include "../../matched/include/Obj03675.h"

#define reg_G3X_DISP3DCNT (*(volatile u16 *)0x04000060)
#define REG_G3X_DISP3DCNT_GO_MASK  0x00002000
#define REG_G3X_DISP3DCNT_RO_MASK  0x00001000
#define REG_G3X_DISP3DCNT_AAE_MASK 0x00000010
#define REG_G3X_DISP3DCNT_ABE_MASK 0x00000008
#define REG_G3X_DISP3DCNT_ATE_MASK 0x00000004
#define ROWH(r) (*(u16 *)((char *)d_021BD5EE + (r) * 4))
struct Obj0203159C;
struct Obj11245;
struct S020315D4;
struct DispConfig;
struct DispVram;
struct Tcbl;
struct Node;
struct S02031140;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct GfFont;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct PrintSys;
struct Rec;
struct G3dSys;
struct LightSet;
struct LightSlot;
struct IcaAnime;
struct Light;
struct Arg;
struct Ctx;
struct AnmCtl;
struct Bank;
struct Obj;
struct Sub02007084Ctrl;
struct Sub0200852CObj;
struct Sub02009210Obj;
struct Sub020071CCCtrl;
struct Sub02009448Obj;
struct Blk34;
struct Menu;
struct Row;
struct CodeIn;
struct Sub020090B0Obj;
struct BgTemplate;
struct Obj0202EA20;
struct WordSet;
struct PlayTime;
struct Sub02008828Obj;
struct Blk37;
struct Sub02008828Rec;
struct WinMgr;
struct Sub020071E4Ctrl;
struct Actor;
struct PtS;
struct Vec2;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef unsigned char  u8;

typedef signed short   s16_021B99E0;

typedef struct {
    u32 win;
    u32 bmp;
    u32 win2;
    u8  fC;
    u8  padD[3];
    u32 f10;
    u32 font;
    u32 print;
    u32 f1C;
    u32 msg;
    u32 buf;
} Work_021B99E0;

typedef struct BgTemplate {
    u32 w[8];
} BgTemplate;

typedef short          s16_021B9C08;

typedef long long      s64;

typedef int            fx32;

typedef int            BOOL;

typedef struct { fx32 x, y, z; } VecFx32;

typedef struct {
    u32 f0;
    u16 f4;
    u16 pad6;
    u32 f8;
    u32 fC;
    void *f10;
} Work_021B9C08;

typedef struct {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
} Local;

typedef unsigned int   u32_021B9EC4;

typedef unsigned int   u32_021B9F70;

typedef unsigned int   u32_021B9F94;

typedef int (*StateFn)(char *);

typedef unsigned int u32_021BA014;

typedef unsigned int   u32_021BA114;

typedef unsigned int   u32_021BA1A0;

typedef unsigned int   u32_021BA218;

typedef unsigned int   u32_021BA2C8;

typedef unsigned int u32_021BA338;

typedef unsigned int   u32_021BA4A0;

typedef unsigned int u32_021BA540;

typedef unsigned int u32_021BA6B0;

typedef unsigned int u32_021BA7AC;

typedef unsigned int u32_021BA880;

typedef struct {
    u32_021BA880 mask;
    u32_021BA880 msg;
} MsgEnt;

typedef unsigned long u32_021BA990;

typedef struct A16 {
    u32 w[4];
} A16;

typedef struct B32 {
    u32 w[8];
} B32;

struct Ent6 {
    u8 a0, a1, a2, a3, a4, a5;
};

struct Slot {
    void *obj;
    u8 on;
};

struct Menu {
    void *f00;
    void *f04;
    u8 pad08[8];
    void *f10;
    u8 pad14[0x58 - 0x14];
    void *f58;
    void *f5c;
    void *f60;
    void *f64;
    void *f68;
    u8 pad6c[0x80 - 0x6c];
    struct Slot slot[14];
};

typedef struct T28 {
    u32 w[7];
} T28;

struct Ent {
    u16 f0;
    u16 f2;
};

typedef signed short s16_021BB5C4;

typedef struct {
    s16_021BB5C4 x;
    s16_021BB5C4 y;
} Pos;

typedef signed char s8;

typedef short s16_021BB798;

extern void func_0203064C(unsigned int a, unsigned int heap, unsigned int size);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void  func_02082BCC(void *p, int v, int n);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_0204363C(u32 swap);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020434DC(u32 mask, u32 enable);
extern u32 func_0201160C(struct Obj11245 *p);
extern u32   func_020362DC(void);
extern unsigned int func_0203630C(void);
extern u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern void func_02005E30(u32 a);
extern int  func_0204E804(void);
extern void func_02005DAC(void *arg);
extern u32  func_02006BD0(u32 a);
extern int  func_02005E50(void);
extern void func_02005D28(void);
extern void func_020315D4(struct S020315D4 *a);
extern void func_020306F0(unsigned int a);
extern void func_020312F8(u32 a1, u32 a2, u32 a3);
extern void func_0207D534(volatile u16 *reg, int brightness);
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0204A648(void);
extern void func_0203F8F4(int);
extern void func_02045088(int);
extern void func_02046440(int, int, int, int, int, int, int);
extern void func_0201DD60(void);
extern void *func_0203101C(int, int, int, int);
extern void *func_020056A0(void *, void *, int);
extern void func_0204361C(void);
void func_020310C4(struct Tcbl *p);
extern void func_02030EAC(struct Node *n);
extern void func_02031140(struct S02031140 *p);
extern void func_02046788(void);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02049624(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_0204989C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_020409B4(u32 layer);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02041300(u32 index, u32 a1, u8 a2, u8 a3, u8 a4, u8 a5, u32 a6);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern u32 func_020111E8(void);
extern void func_02045808(struct U16Vec *vec);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_020452E8(struct Descriptor *d);
extern u32   func_02047CFC(u32 a, u32 b, u32 heap);
extern u16   func_02047E88(u32 a, const void *b);
extern u32 func_020489F4(u8 *a0, int i);
extern u32   func_02048A18(u32 a, u16 b);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern fx32  FX_Div(fx32 numer, fx32 denom);
extern void *func_02048A24(int a, int s, int c, int d, int e, int f, int g, int h,
                           VecFx32 *pos, VecFx32 *up, VecFx32 *tgt, int heap);
extern void *func_02011510(u32 heap, u32 a1, u32 a2, u32 a3);
extern struct LightSlot *func_02048BC4(const struct LightSet *s, u32 heap);
extern void func_02048C58(struct LightSlot *slots);
extern void func_0204044C(u32 mode);
extern u32 func_020115C0(struct IcaAnime *p, s32 v);
extern void func_02011B8C(void *, void *);
extern void func_02048AD0(struct Light *l);
extern void func_02047964(void);
extern void func_020479D8(void);
extern void func_02047A60(void *a0, struct Arg *a1);
extern void func_02047970(void);
extern int func_02047910(void *a, int idx, int amount);
extern void func_02011558(struct IcaAnime *p);
extern u32 func_02048AC4(void *ptr);
extern void func_02048C4C(int);
extern void func_020480E4(struct Ctx *c, u32 i);
extern void func_02047E54(struct Rec *p);
extern void func_020115EC(struct IcaAnime *p, s32 v);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
extern void func_0204B270(struct Bank *bank);
extern int func_0204A6C8(void *, int, int, int, int);
extern int func_0204ABF0(void *, int, int, int, int);
extern s32 func_0204AF28(void *owner, u32_021B9EC4 first, u32_021B9EC4 second, u32_021B9EC4 mode);
extern int func_0204B294(int, int, int, int, Local *, int, int);
extern void func_0204B92C(struct Obj *p, u32_021B9EC4 v);
extern void func_02049238(void *);
void func_0204A600(void);
extern void func_0204A8D4(u32_021B9F70 i);
extern void func_0204ADA4(u32_021B9F70 i);
extern void func_0204AFD8(u32_021B9F70 i);
extern u32_021B9F70 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern struct Sub02007084Ctrl *func_020070A4(void);
extern struct Sub0200852CObj *func_02008730(void *sys);
extern void *func_0200C0F0(void *sys);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern void *func_02012FE4(struct Sub020071CCCtrl *a0);
extern void func_020274C8(void);
extern void func_021BC114(void);
extern void func_021BC0FC(void);
extern void func_021BC0E4(void);
extern void *func_02030734(u32_021BA014 heapId, u32_021BA014 size, int clear, const char *site, u16 tag);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern u8 func_020092EC(const struct Sub02009210Obj *obj);
extern void func_0200C2F0(struct Blk34 *p, u32_021BA114 i, u8 v);
extern u32_021BA1A0 func_0203D210(void);
extern u32_021BA218 func_020221A4(void);
extern u32_021BA2C8 func_0201C4E4(struct PrintSys *ps);
extern u32_021BA2C8 func_0201C6C4(struct PrintSys *p, void *v);
extern u32_021BA2C8 func_0201C6B4(const struct PrintSys *p);
extern int func_021BC0C8(char *p);
extern int func_021BC054(char *p, int v);
extern s32 func_0202EA40(struct Row *p);
extern void func_020061E4(u32_021BA338);
extern int func_021BC0AC(char *p, int v);
extern int func_021BC080(char *p, int v);
extern unsigned int func_0203633C(void);
extern void func_0202EB04(struct CodeIn *p);
extern u8 func_020090E0(const struct Sub020090B0Obj *obj);
extern void func_021BBF1C(char *p, u32_021BA540 a1);
extern void func_021BBD80(char *p);
extern int func_021BBFA8(char *p);
extern u32_021BA540 func_0201FEBC(u8 *);
extern int func_0202EB44(void);
extern void func_021BBE3C(char *p);
extern void func_021BBF98(char *p);
extern void func_021BC024(char *p);
extern void func_021BBBAC(char *p);
extern void func_021BBD10(char *p, int mode);
extern u32_021BA7AC func_0202EB0C(void);
extern void func_021BBE48(char *p);
extern void func_02040EBC(u32_021BA880 a0, u32_021BA880 a1);
extern void func_020419E4(void);
extern void func_0204335C(u32 keep);
extern void func_020403F4(u32 i);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern struct CodeIn *func_0202E940(u16 a0, u16 a1, u32 a2, u16 heap);
extern void func_0202E9AC(struct CodeIn *p, u8 *a1, u32 a2, u32 a3, u32 a4);
extern u32 func_0202EA20(struct Obj0202EA20 *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern u32 func_02028590(u32, u32, u32, u32);
extern int func_02028604(int a0);
extern unsigned int func_0201ED04(struct WordSet *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201F158(struct WordSet *p, u32 i, u32 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_020139B0(u32 heap);
extern u32 func_020142E8(void *bitmap, s32 id);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern u16 *func_02008848(void *);
extern void func_0200890C(void *sys, struct Sub02008828Rec *dest);
extern u32 func_02013E4C(u32 id);
extern void func_02013A48(void);
extern struct PlayTime *func_02008748(void *sys);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern void *func_0200CA10(void *);
extern u32 func_0200D0AC(struct Blk37 *p, u32 heap);
extern u32 func_0200C258(struct Blk34 *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);
extern void func_0202CA0C(struct WinMgr *mgr);
extern void func_0207D63C(void *reg, int a, int b, int c, int d);
extern u8 func_020071EC(const struct Sub020071E4Ctrl *ctrl);
extern u8 func_0200C308(struct Blk34 *p, u32 i);
extern void *func_02049EF4(void *o, u32 a, u32 b, void **out, u16 e);
extern void func_02082A60(void *srcp, void *destp, unsigned long size);
extern u32 func_020307B0(void *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_02041B6C(u32);
extern void func_020413B0(u32, u32, u8, u8, u8, u32);
int func_021B95A0(struct Obj0203159C *a0);
void func_021B95CC(char *p);
void func_021B965C(char *p);
int func_021B9750(int a0, int a1, int a2, char *p);
int func_021B9874(int a0, int a1, int a2, int *a3);
void func_021B98BC(void);
void func_021B9910(void);
void func_021B9928(unsigned char *p);
void func_021B9954(void *task, short *p);
void func_021B997C(int *p, int heap);
void func_021B99E0(int *p, int unused);
void func_021B99EC(int *p);
void func_021B9A14(unsigned short *p, unsigned short a, unsigned short b);
void func_021B9A1C(Work_021B99E0 *p, u32 heap);
void func_021B9BD4(int *p, int unused);
void func_021B9C08(int *p);
void func_021B9C2C(Work_021B9C08 *p, u32 heap);
void func_021B9DD0(int *p, int unused);
void func_021B9E54(int *p);
void func_021B9E7C(int *p, int x);
void func_021B9EC4(int *p, int heap);
void func_021B9F68(u8 *p, int unused);
void func_021B9F70(int *p);
int func_021B9F94(struct Obj0203159C *a);
int func_021B9FE4(int a0, int a1, int a2, char *p);
int func_021BA014(int a0, int a1, int a2, char *a3);
int func_021BA114(int *p);
int func_021BA1A0(char *p);
int func_021BA218(char *p);
int func_021BA230(char *p);
int func_021BA2C8(char *p);
int func_021BA338(char *p);
int func_021BA4A0(char *p);
int func_021BA540(char *p);
int func_021BA6B0(char *p);
int func_021BA7AC(char *p);
int func_021BA880(char *p);
int func_021BA984(char *p);
void func_021BA990(void);
void func_021BA9B0(int *p);
void func_021BA9C8(int *p);
void func_021BA9D4(void);
void func_021BA9E8(void);
void func_021BAB20(void);
void func_021BAB64(void);
void func_021BAC24(char *p);
void func_021BAC64(char *p);
void func_021BAC74(char *p);
void func_021BACD8(int *p);
void func_021BAD08(struct Menu *p);
void func_021BB164(char *p);
void func_021BB184(int *p);
void func_021BB328(char *p);
void func_021BB380(char *p);
void func_021BB474(char *p);
void func_021BB484(void);
void func_021BB4B4(char *p);
void func_021BB544(char *p);
void func_021BB5C4(char *p);
void func_021BB5E0(char *p, u32 idx, s16_021BB5C4 y);
void func_021BB608(char *p);
void func_021BB798(char *p, u32 i, u32 arg);
void func_021BB810(void *p, u8 row, int y, int pal);
int func_021BB840(char *p, int y);
void func_021BB858(char *p, int d);
int func_021BB890(char *p, int d);
void func_021BB9DC(char *p, int flag);
void func_021BBA64(u8 x, u8 y, u8 w, u8 h, u8 bg);
extern char d_021BD66C[];
extern char d_021BD974[];
extern char d_02184904[];
extern char ov088_id[];
extern char ov168_id[];
extern char d_021BD508[];
extern char d_021BD420[];
extern const BgTemplate d_021BD470;
extern const BgTemplate d_021BD490;
extern const BgTemplate d_021BD430;
extern const BgTemplate d_021BD450;
extern const s16_021B9C08 FX_SinCosTable_[];
extern const u32 d_021BD410[];
extern VecFx32 d_021BD3EC;
extern VecFx32 d_021BD3F8;
extern VecFx32 d_021BD404;
extern const u32 d_021BD3DC[];
extern char d_021BD538[];
extern char d_020A1448[];
extern StateFn d_021BD63C[];
extern char d_021BDA00[];
extern char d_021DF538[];
extern char d_02213C4C[];
extern char d_0209DEF0[];
extern char d_021D77AC[];
extern char d_021F6D78[];
extern char d_021BD574[];
extern char ov121_id[];
extern char ov199_id[];
extern char ov016_id[];
extern char ov107_id[];
extern const MsgEnt d_021BD784[8];
extern char SDK_AUTOLOAD_DTCM_START[];
extern char d_021BD60C[];
extern A16 d_021BD678;
extern B32 d_021BD724;
extern B32 d_021BD764;
extern B32 d_021BD6C4;
extern B32 d_021BD6E4;
extern B32 d_021BD744;
extern B32 d_021BD6A4;
extern B32 d_021BD704;
extern const struct Ent6 d_021BD7C4[];
extern T28 d_021BD688;
extern char d_021BD5DC[];
extern char d_021BD5E4[];
extern char d_021BD5D4[];
extern const struct Ent d_021BD5EC[];
extern u16 d_021BD5EE[];





int func_021B95A0(struct Obj0203159C *a0)
{
    char *p;

    func_0203064C(1, 0x16, 0x120000);
    p = func_0203159C(a0, 0x98, 0x16);
    func_02082BCC(p, 0, 0x98);
    ((struct Obj20810 *)p)->f2 = 0x16;
    return 1;
}





void func_021B95CC(char *p)
{
    if (((struct Obj00462 *)p)->f8C == 0x29A) {
        func_0204E720(12, 16, 0, 3);
        func_0204363C(1);
        func_02040588(6, 0);
        func_02043598(16, 0);
        func_020434DC(8, 0);
        ((struct Obj00462 *)p)->f94 = 1;
    }
    if (((struct Obj00462 *)p)->f94 == 2 && func_0201160C((struct Obj11245 *)(((struct Obj00462 *)p)->f4C)) == 0x015F3000)
        func_021B9E7C((int *)(p + 0x40), 0x14B5);
    ((struct Obj00462 *)p)->f8C += 1;
    if (((struct Obj00462 *)p)->f8C > 0x1248) {
        ((struct Obj00462 *)p)->f4 = 1;
        ((struct Obj00462 *)p)->f0 = 5;
    }
}





void func_021B965C(char *p)
{
    if ((func_020362DC() & 0xB) && ((struct Obj00462 *)p)->f94 == 1) {
        func_0204363C(0);
        func_02040588(6, 1);
        func_02040588(3, 1);
        func_02043598(0x10, 1);
        func_021B9E7C((int *)(p + 0x40), 0x14B5);
        ((struct Obj00462 *)p)->f94 = 2;
        return;
    }
    if (func_020362DC() & 9) {
        ((struct Obj00462 *)p)->f4 = 0;
        ((struct Obj00462 *)p)->f0 = 4;
        ((struct Obj00462 *)p)->f90 = (void *)func_02006984(0x283, 0, 0x40, 0, 0, 0, 0, 0);
        func_021B9E7C((int *)(p + 0x40), 0x1389);
        func_0204363C(0);
        func_02040588(6, 1);
        func_02043598(0x10, 0);
        func_0204E720(0xC, 0x10, 0, 3);
        func_02005E30(4);
        func_021B9A14((u16 *)(p + 8), 8, 8);
        return;
    }
    if (func_0203630C() == 0x46) {
        ((struct Obj00462 *)p)->f4 = 2;
        ((struct Obj00462 *)p)->f0 = 5;
    } else if (func_0203630C() == 0xC80) {
        ((struct Obj00462 *)p)->f4 = 3;
        ((struct Obj00462 *)p)->f0 = 5;
    }
}





int func_021B9750(int a0, int a1, int a2, char *p)
{
    switch (((struct Obj00462 *)p)->f0) {
    case 0:
        func_021B98BC();
        func_021B9910();
        ((struct Obj00462 *)p)->f0 = 1;
        break;
    case 1:
        func_021B997C((int *)(p + 8), ((struct Obj00462 *)p)->f2);
        func_021B9A1C((Work_021B99E0 *)(p + 0x14), ((struct Obj00462 *)p)->f2);
        func_021B9C2C((Work_021B9C08 *)(p + 0x40), ((struct Obj00462 *)p)->f2);
        func_021B9EC4((int *)(p + 0x54), ((struct Obj00462 *)p)->f2);
        func_0204E720(3, 0x10, 0, 2);
        ((struct Obj00462 *)p)->f8C = 0;
        ((struct Obj00462 *)p)->f0 = 2;
        func_02005DAC((void *)0x3EF);
        break;
    case 2:
        if (func_0204E804() == 0) {
            ((struct Obj00462 *)p)->f0 = 3;
        }
        func_021B9928((unsigned char *)p);
        break;
    case 3:
        func_021B9928((unsigned char *)p);
        func_021B965C(p);
        func_021B95CC(p);
        break;
    case 4:
        if (func_02006BD0(*(u32 *)&((struct Obj00462 *)p)->f90) == 0) {
            ((struct Obj00462 *)p)->f0 = 5;
        }
        func_021B9928((unsigned char *)p);
        break;
    case 5:
        func_0204E720(3, 0, 0x10, 2);
        ((struct Obj00462 *)p)->f0 = 6;
        func_021B9928((unsigned char *)p);
        func_02005E30(0x10);
        break;
    case 6:
        if (func_0204E804() == 0 && func_02005E50() == 0) {
            func_02005D28();
            ((struct Obj00462 *)p)->f0 = 7;
        }
        func_021B9928((unsigned char *)p);
        break;
    case 7:
        func_021B9F70((int *)(p + 0x54));
        func_021B9E54((int *)(p + 0x40));
        func_021B9C08((int *)(p + 0x14));
        func_021B99EC((int *)(p + 8));
        return 1;
    case 8:
        return 1;
    }
    return 0;
}





int func_021B9874(int a0, int a1, int a2, int *a3)
{
    int t = a3[1];

    func_020315D4((struct S020315D4 *)a0);
    func_020306F0(0x16);
    if (t == 0) {
        func_020312F8((u32)ov088_id, (u32)d_021BD66C, 0);
    } else if (t == 2) {
        func_020312F8((u32)ov088_id, (u32)d_021BD974, 0);
    } else if (t == 3) {
        func_020312F8((u32)ov168_id, (u32)d_02184904, 0);
    }
    return 1;
}





void func_021B98BC(void)
{
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_02043534(0);
    func_020435F4(0);
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
    *(u32 *)0x04000000 &= 0xFFFF1FFF;
    *(u32 *)0x04001000 &= 0xFFFF1FFF;
}





void func_021B9910(void)
{
    func_020433E0((const struct DispVram *)d_021BD508);
    func_0203FC28((struct DispConfig *)d_021BD420);
}





void func_021B9928(unsigned char *p)
{
    func_021B99E0((int *)(p + 0x08), ((struct Obj07719 *)p)->f2);
    func_021B9BD4((int *)(p + 0x14), ((struct Obj07719 *)p)->f2);
    func_021B9DD0((int *)(p + 0x40), ((struct Obj07719 *)p)->f2);
    func_021B9F68(p + 0x54, ((struct Obj07719 *)p)->f2);
}





void func_021B9954(void *task, short *p)
{
    func_0204A648();
    *(volatile unsigned int *)0x04000064 = p[4] | (0xC0330000 | (p[5] << 8));
}





void func_021B997C(int *p, int heap)
{
    func_0203F8F4(heap);
    func_02045088(heap);
    func_02046440(0, 2, 0, 2, 0x1000, heap, 0);
    func_0201DD60();
    p[0] = (int)func_0203101C(heap, heap, 4, 0x20);
    p[1] = (int)func_020056A0((void *)func_021B9954, p, 5);
    func_0204363C(0);
    func_0204361C();
    ((unsigned short *)p)[4] = 12;
    ((unsigned short *)p)[5] = 4;
}










void func_021B99E0(int *p, int unused)
{
    func_020310C4((struct Tcbl *)p[0]);
}










void func_021B99EC(int *p)
{
    func_0204363C(1);
    func_0204361C();
    func_02030EAC((struct Node *)p[1]);
    func_02031140((struct S02031140 *)p[0]);
    func_02046788();
    func_020450C8();
    func_0203F9B4();
}









void func_021B9A14(unsigned short *p, unsigned short a, unsigned short b)
{
    p[4] = a;
    p[5] = b;
}










void func_021B9A1C(Work_021B99E0 *p, u32 heap)
{
    int w;

    func_0203FCA0(3, &d_021BD470, 0);
    func_0203FCA0(5, &d_021BD490, 0);
    func_0203FCA0(7, &d_021BD430, 0);
    func_0203FCA0(6, &d_021BD450, 0);
    func_02049624(0x1A, 9, 3, 0, 0, 1, heap);
    func_0204989C(0x1A, 10, 3, 0, 0, 1, heap);
    func_02049B40(0x1A, 8, 0, 0, 0, heap);
    func_020409B4(3);
    func_02040588(3, 1);
    func_02049624(0x1A, 0, 7, 0, 0x8000, 1, heap);
    func_0204989C(0x1A, 1, 7, 0, 0, 1, heap);
    func_02049B40(0x1A, 2, 4, 0, 0, heap);
    func_020409B4(7);
    func_02040588(7, 1);
    func_0204989C(0x1A, 3, 6, 0, 0, 1, heap);
    func_02040588(6, 1);
    func_02040C14(5, 0, 1, 0);
    func_02041300(5, 0, 0, 0, 0x20, 0x20, 0x11);
    p->win = func_020450F0(5, 0, 0x13, 0x20, 2, 0xA, 0);
    p->bmp = (u32)func_02045770((struct Descriptor *)p->win);
    func_02043B5C((struct CharBuf *)p->bmp, 0);
    func_02045374((struct Cfg *)p->win);
    func_02045334((struct Descriptor *)p->win);
    p->fC = 0;
    p->win2 = p->win;
    func_020409B4(5);
    p->font = (u32)func_0201D7EC(0x17, 0, 0, 0, heap);
    p->print = func_0201C440((void *)heap);
    p->msg = (u32)func_02045B38(0, 2, 0xB5, heap);
    p->buf = (u32)func_020457B0(0x40, heap);
    func_02045CAC((struct MsgBank *)p->msg, 1, (void *)p->buf);
    w = func_0201D304((struct StrObj *)p->buf, p->font, 0);
    func_0201C724((void *)p->print, p->bmp, (s16_021B99E0)(0x80 - w / 2), (s16_021B99E0)0, p->buf, p->font, 0x440);
    p->f10 = 1;
}










void func_021B9BD4(int *p, int unused)
{
    func_02040588(5, 0);
    func_02041EE4(6, 0, p[10] / 2);
    if (func_020111E8() == 0x15) {
        p[10]++;
    } else {
        p[10]--;
    }
}










void func_021B9C08(int *p)
{
    func_02045808((struct U16Vec *)p[9]);
    func_02045C04((struct Rec *)p[8]);
    func_0201C4C0((struct PrintSys *)p[6]);
    func_0201D83C((void *)p[5]);
    func_020452E8((struct Descriptor *)p[0]);
}










static inline void G3X_AntiAlias(BOOL enable)
{
    if (enable) {
        reg_G3X_DISP3DCNT = (u16)(reg_G3X_DISP3DCNT &
                                  ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK) |
                                  REG_G3X_DISP3DCNT_AAE_MASK);
    } else {
        reg_G3X_DISP3DCNT &= (u16)~(REG_G3X_DISP3DCNT_AAE_MASK |
                                    REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
    }
}










static inline void G3X_AlphaTest(BOOL enable, int ref)
{
    if (enable) {
        reg_G3X_DISP3DCNT = (u16)(reg_G3X_DISP3DCNT &
                                  ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK) |
                                  REG_G3X_DISP3DCNT_ATE_MASK);
        *(volatile u16 *)0x04000340 = (u16)ref;
    } else {
        reg_G3X_DISP3DCNT &= (u16)~(REG_G3X_DISP3DCNT_ATE_MASK |
                                    REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
    }
}










static inline void G3X_AlphaBlend(BOOL enable)
{
    if (enable) {
        reg_G3X_DISP3DCNT = (u16)(reg_G3X_DISP3DCNT &
                                  ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK) |
                                  REG_G3X_DISP3DCNT_ABE_MASK);
    } else {
        reg_G3X_DISP3DCNT &= (u16)~(REG_G3X_DISP3DCNT_ABE_MASK |
                                    REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_GO_MASK);
    }
}










static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}










/*
 * Levers: the four ortho bounds bound to locals before the func_02048A24
 * call (inline in the argument list they evaluate in another order); the
 * sin/cos pair read as FX_SinCosTable_[0x2AA]/[0x2AB] (pool word base +
 * 0x540); d_021BD3DC without its ov088 token (contested hint).
 * volatile: 0x04000060 (DISP3DCNT) read-modify-written by the G3X_AntiAlias,
 *           G3X_AlphaTest and G3X_AlphaBlend inlines at 0x021B9D80-0x021B9D9C
 */
void func_021B9C2C(Work_021B9C08 *p, u32 heap)
{
    int base;
    fx32 s;
    fx32 c;
    fx32 t;
    fx32 top;
    fx32 bottom;
    fx32 left;
    fx32 right;

    p->f0 = func_02047CFC(7, 3, heap);
    p->f4 = func_02047E88(p->f0, d_021BD410);
    base = func_020489F4((u8 *)p->f0, p->f4);
    func_020477A4((struct G3dSys *)func_02048A18(p->f0, base), 0);
    func_020477A4((struct G3dSys *)func_02048A18(p->f0, base), 1);
    func_020477A4((struct G3dSys *)func_02048A18(p->f0, base + 1), 0);
    func_020477A4((struct G3dSys *)func_02048A18(p->f0, base + 2), 0);

    c = FX_SinCosTable_[0x2AB];
    s = FX_SinCosTable_[0x2AA];
    t = FX_Mul(s, 0x19A);
    top = FX_Div(t, c);
    bottom = -FX_Div(t, c);
    right = FX_Div(FX_Mul(FX_Div(0x223, 0x1000), s), c);
    left = -FX_Div(FX_Mul(FX_Div(0x223, 0x1000), s), c);
    p->f10 = func_02048A24(1, top, bottom, left, right,
                           0x19A, 0x800000, 0x19A,
                           &d_021BD3EC, &d_021BD3F8, &d_021BD404, heap);
    p->fC = (u32)func_02011510(heap, 0xA0, 0xE9, 0xA);
    p->f8 = (u32)func_02048BC4((const struct LightSet *)d_021BD3DC, heap);
    func_02048C58((struct LightSlot *)p->f8);
    func_0204044C(1);
    G3X_AntiAlias(1);
    G3X_AlphaTest(0, 0);
    G3X_AlphaBlend(1);
}









void func_021B9DD0(int *p, int unused)
{
    int base;
    unsigned i;
    void *h;
    base = func_020489F4((void *)p[0], ((struct Obj03674 *)p)->f4);
    func_020115C0((void *)p[3], 0x1000);
    func_02011B8C((void *)p[4], (void *)p[3]);
    func_02048AD0((void *)p[4]);
    func_02047964();
    func_020479D8();
    for (i = 0; i < 3; i++) {
        h = (void *)func_02048A18((u32)((void *)p[0]), (unsigned short)(base + i));
        func_02047A60(h, (struct Arg *)d_021BD538);
    }
    func_02047970();
    for (i = 0; i < 3; i++) {
        h = (void *)func_02048A18((u32)((void *)p[0]), (unsigned short)(base + i));
        func_02047910(h, 0, 0x1000);
        if (i == 0)
            func_02047910(h, 1, 0x1000);
    }
}









/*
 * note:     listing extent (40) runs 2 bytes past the compiled function (38);
 *           trailing alignment padding, no byte difference.
 */
void func_021B9E54(int *p)
{
    func_02011558((struct IcaAnime *)p[3]);
    func_02048AC4((void *)p[4]);
    func_02048C4C(p[2]);
    func_020480E4((struct Ctx *)p[0], ((unsigned short *)p)[2]);
    func_02047E54((struct Rec *)p[0]);
}









void func_021B9E7C(int *p, int x)
{
    int v;
    int base;
    unsigned i;
    void *h;
    v = x << 12;
    func_020115EC((void *)p[3], v);
    base = func_020489F4((void *)p[0], ((struct Obj07721 *)p)->f4);
    for (i = 0; i < 3; i++) {
        h = (void *)func_02048A18((u32)((void *)p[0]), (unsigned short)(base + i));
        func_0204784C(h, 0, &v);
        if (i == 0)
            func_0204784C(h, 1, &v);
    }
}








void func_021B9EC4(int *p, int heap)
{
    Local s;
    void *h;
    h = func_020490F4(0x1a, heap);
    func_0204A48C((const struct Cfg *)d_020A1448, (unsigned int)d_021BD508, heap);
    p[0] = (int)func_0204B100(0x40, 0, heap);
    func_0204B270((void *)p[0]);
    p[12] = func_0204A6C8(h, 5, 1, 1, heap);
    p[11] = func_0204ABF0(h, 4, 1, 0, heap);
    p[13] = func_0204AF28(h, 6, 7, heap);
    s.a = 0x80;
    s.b = 0x60;
    s.c = 0;
    s.e = 0;
    s.d = 0;
    p[1] = func_0204B294(p[0], p[12], p[11], p[13], &s, 1, heap);
    func_0204B92C((struct Obj *)p[1], 1);
    func_02043598(0x10, 1);
    func_02049238(h);
}








void func_021B9F68(u8 *p, int unused)
{
    func_0204A600();
}








void func_021B9F70(int *p)
{
    func_0204A8D4(p[12]);
    func_0204ADA4(p[11]);
    func_0204AFD8(p[13]);
    func_0204B1CC((struct Bank *)p[0]);
    func_0204A5AC();
}








int func_021B9F94(struct Obj0203159C *a)
{
    int *p;
    func_0203064C(1, 0xb, 0x80000);
    p = func_0203159C(a, 0x150, 0xb);
    func_02082BCC(p, 0, 0x150);
    p[0] = (int)func_020070A4();
    p[1] = (int)func_02008730((void *)p[0]);
    p[2] = (int)func_0200C0F0((void *)p[0]);
    p[3] = (int)func_02009210((void *)p[0]);
    p[4] = (int)func_02012FE4((struct Sub020071CCCtrl *)p[0]);
    return 1;
}








int func_021B9FE4(int a0, int a1, int a2, char *p)
{
    int s = d_021BD63C[*(int *)(p + 0x13c)](p);
    ((struct Obj13230 *)p)->f13C = s;
    if (s == 12) {
        return 1;
    }
    func_020310C4((struct Tcbl *)(((struct Obj13230 *)p)->f70));
    func_0204A600();
    return 0;
}








int func_021BA014(int a0, int a1, int a2, char *a3)
{
    u8 sel = ((struct Obj13231 *)a3)->f129;
    u8 flag = ((struct Obj13231 *)a3)->f12C;
    char *w;

    func_020315D4((struct S020315D4 *)a0);
    func_020306F0(0xb);
    switch (sel) {
    case 0:
        func_020274C8();
        if (flag == 0)
            func_021BC114();
        else
            func_021BC0FC();
        break;
    case 1:
        func_020274C8();
        func_021BC0E4();
        break;
    case 2:
        func_020312F8((int)ov121_id, (u32_021BA014)d_021DF538, 0);
        break;
    case 3:
        w = func_02030734(1, 0x14, 0, d_021BDA00, 0x200);
        func_02082BCC(w, 0, 0x14);
        ((struct Obj09921 *)w)->f8 = 0;
        ((struct Obj09921 *)w)->f10 = 1;
        func_020312F8((int)ov199_id, (u32_021BA014)d_02213C4C, (u32_021BA014)w);
        break;
    case 4:
        func_020312F8(-1, (u32_021BA014)d_0209DEF0, 0);
        break;
    case 5:
        func_020312F8((int)ov016_id, (u32_021BA014)d_021D77AC, 0);
        break;
    case 6:
        func_020312F8((int)ov168_id, (u32_021BA014)d_02184904, 0);
        break;
    case 7:
        w = func_02030734(1, 8, 1, d_021BDA00, 0x216);
        ((struct Obj09921 *)w)->f0 = 1;
        func_020312F8((int)ov107_id, (u32_021BA014)d_021F6D78, (u32_021BA014)w);
        break;
    default:
        func_020312F8((int)ov088_id, (u32_021BA014)d_021BD574, 0);
        break;
    }
    return 1;
}








int func_021BA114(int *p)
{
    unsigned short z;
    if (func_020092EC((const struct Sub02009210Obj *)func_02009448((void *)p[0])) == 1)
        func_0200C2F0((struct Blk34 *)p[2], 2, 2);
    z = 0;
    func_02043534(0);
    func_020435F4(0);
    *(unsigned short *)0x04000050 = z;
    *(unsigned short *)0x04001050 = z;
    func_0204363C(1);
    func_021BA9D4();
    func_021BA9E8();
    func_021BAB64();
    func_021BAC74((char *)p);
    func_021BB4B4((char *)p);
    func_021BB544((char *)p);
    func_021BAD08((struct Menu *)p);
    func_021BB184(p);
    func_021BB380((char *)p);
    func_021BB608((char *)p);
    func_021BAC24((char *)p);
    func_021BB484();
    func_021BA9B0(p);
    return 4;
}








int func_021BA1A0(char *p)
{
    unsigned s;
    s = ((struct Obj13232 *)p)->f12A;
    switch (s) {
    case 0:
        ((struct Obj13232 *)p)->f12A = s + 1;
    case 1:
        if (func_0203D210() != 0) {
            func_021BA9C8((int *)p);
            func_021BAC64(p);
            func_021BB474(p);
            func_021BB328(p);
            func_021BB164(p);
            func_021BB5C4(p);
            func_021BACD8((int *)p);
            func_021BAB20();
            *(unsigned short *)0x04000050 = 0;
            *(unsigned short *)0x04001050 = 0;
            func_02043534(0);
            func_020435F4(0);
            return 12;
        }
    }
    return 1;
}








int func_021BA218(char *p)
{
    if (func_020221A4() == 1) {
        return ((struct Obj20813 *)p)->f144;
    }
    return 2;
}








int func_021BA230(char *p)
{
    switch (((struct Obj01369 *)p)->f12D) {
    case 0:
    case 2:
        if (((struct Obj01369 *)p)->f12E == 0) {
            func_021BB810(p, *(unsigned char *)(p + ((struct Obj01369 *)p)->f128 + 0x120),
                          func_021BB840(p, ((struct Obj01369 *)p)->f12F), 3);
            ((struct Obj01369 *)p)->f12E = 4;
            ((struct Obj01369 *)p)->f12D = ((struct Obj01369 *)p)->f12D + 1;
        } else {
            ((struct Obj01369 *)p)->f12E -= 1;
        }
        break;
    case 1:
    case 3:
        if (((struct Obj01369 *)p)->f12E == 0) {
            func_021BB810(p, *(unsigned char *)(p + ((struct Obj01369 *)p)->f128 + 0x120),
                          func_021BB840(p, ((struct Obj01369 *)p)->f12F), 1);
            ((struct Obj01369 *)p)->f12E = 4;
            ((struct Obj01369 *)p)->f12D = ((struct Obj01369 *)p)->f12D + 1;
        } else {
            ((struct Obj01369 *)p)->f12E -= 1;
        }
        break;
    case 4:
        return ((struct Obj01369 *)p)->f140;
    }
    return 3;
}








/*
 * note:     listing extent (112) runs 2 bytes past the compiled function (110);
 *           trailing alignment padding, no byte difference.
 */
int func_021BA2C8(char *p)
{
    unsigned i;
    void *t;
    func_0201C4E4(((struct Obj06203 *)p)->f68);
    for (i = 0; i < 14; i++) {
        t = ((struct Obj06203 *)p)->f68;
        if (*(unsigned char *)(p + i * 8 + 0x84) != 0 && func_0201C6C4(t, func_02045770(*(void **)(p + i * 8 + 0x80))) == 0) {
            func_02045334(*(void **)(p + i * 8 + 0x80));
            *(unsigned char *)(p + i * 8 + 0x84) = 0;
        }
    }
    if (func_0201C6B4(((struct Obj06203 *)p)->f68) == 1) {
        if (func_021BC0C8(p) == 1)
            return 10;
        return func_021BC054(p, 5);
    }
    return 4;
}








int func_021BA338(char *p)
{
    func_0202EA40(((struct Obj00271 *)p)->f11C);
    if (func_020362DC() & 1) {
        func_020061E4(0x54c);
        switch (*(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120)) {
        case 0:
            ((struct Obj00271 *)p)->f129 = *(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120);
            return func_021BC0AC(p, 7);
        case 1:
            return func_021BC0AC(p, 8);
        case 2:
            ((struct Obj00271 *)p)->f129 = *(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120);
            return func_021BC0AC(p, 11);
        case 3:
            func_0200C2F0((struct Blk34 *)(((struct Obj00271 *)p)->f8), 1, 2);
            ((struct Obj00271 *)p)->f129 = *(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120);
            return func_021BC0AC(p, 11);
        case 4:
            func_0200C2F0((struct Blk34 *)(((struct Obj00271 *)p)->f8), 2, 2);
            ((struct Obj00271 *)p)->f129 = *(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120);
            return func_021BC0AC(p, 11);
        case 7:
            func_0200C2F0((struct Blk34 *)(((struct Obj00271 *)p)->f8), 3, 2);
            ((struct Obj00271 *)p)->f129 = *(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120);
            return func_021BC0AC(p, 11);
        case 5:
            return func_021BC0AC(p, 9);
        case 6:
            ((struct Obj00271 *)p)->f129 = *(u8 *)(p + ((struct Obj00271 *)p)->f128 + 0x120);
            return func_021BC0AC(p, 11);
        }
    }
    if (func_020362DC() & 2) {
        func_020061E4(0x551);
        ((struct Obj00271 *)p)->f129 = 8;
        return func_021BC080(p, 1);
    }
    if (func_0203633C() & 0x40) {
        if (func_021BB890(p, -1) == 1) {
            func_020061E4(0x548);
            return 6;
        }
    }
    if (func_0203633C() & 0x80) {
        if (func_021BB890(p, 1) == 1) {
            func_020061E4(0x548);
            return 6;
        }
    }
    return 5;
}








int func_021BA4A0(char *p)
{
    if (((struct Obj01228 *)p)->f134 == 3) {
        ((struct Obj01228 *)p)->f134 = 0;
        ((struct Obj01228 *)p)->f138 = 0;
        func_0202EB04((struct CodeIn *)(((struct Obj01228 *)p)->f11C));
        func_021BB810(p, *(unsigned char *)(p + ((struct Obj01228 *)p)->f128 + 0x120),
                      func_021BB840(p, ((struct Obj01228 *)p)->f12F), 2);
        return 5;
    }
    ((struct Obj01228 *)p)->f130 += ((struct Obj01228 *)p)->f138;
    if (((struct Obj01228 *)p)->f130 < 0)
        ((struct Obj01228 *)p)->f130 += 0x200;
    else if (((struct Obj01228 *)p)->f130 >= 0x200)
        ((struct Obj01228 *)p)->f130 -= 0x200;
    func_02041EE4(1, 3, ((struct Obj01228 *)p)->f130);
    func_02041EE4(2, 3, ((struct Obj01228 *)p)->f130);
    func_021BB858(p, -((struct Obj01228 *)p)->f138);
    ((struct Obj01228 *)p)->f134 = ((struct Obj01228 *)p)->f134 + 1;
    return 6;
}








/*
 * The two 0/-2 result tests are small switches: their compare chain puts
 * both bodies after a shared `b` to the tail, which the outer switch's
 * out-of-range `bhi` reuses. The countdown is `-= 1` (re-reads the byte).
 */
int func_021BA540(char *p)
{
    void *t;
    u32_021BA540 r;
    switch (((struct Obj00339 *)p)->f12A) {
    case 0:
        func_020434DC(6, 0);
        func_021BB9DC(p, 0);
        if (func_020090E0(((struct Obj00339 *)p)->fC) == 0) {
            ((struct Obj00339 *)p)->f12C = 1;
            ((struct Obj00339 *)p)->f12A = 0;
            return func_021BC080(p, 1);
        }
        ((struct Obj00339 *)p)->f12B = 8;
        ((struct Obj00339 *)p)->f12A = ((struct Obj00339 *)p)->f12A + 1;
        break;
    case 1:
        if (((struct Obj00339 *)p)->f12B != 0) {
            ((struct Obj00339 *)p)->f12B -= 1;
            break;
        }
        func_021BBF1C(p, 0x1a);
        func_021BBD80(p);
        ((struct Obj00339 *)p)->f12A = ((struct Obj00339 *)p)->f12A + 1;
        break;
    case 2:
        if (func_021BBFA8(p) == 0) {
            func_021BC024(p);
            ((struct Obj00339 *)p)->f12A = ((struct Obj00339 *)p)->f12A + 1;
        }
        break;
    case 3:
        r = func_0201FEBC(*(u8 * *)&((struct Obj00339 *)p)->f7C);
        switch (r) {
        case 0:
            if (func_0202EB44() == 0) {
                func_021BBF1C(p, 0x11);
                ((struct Obj00339 *)p)->f12A = 5;
            } else {
                ((struct Obj00339 *)p)->f12C = 0;
                ((struct Obj00339 *)p)->f12A = 4;
            }
            break;
        case (u32_021BA540)-2:
            func_021BBF1C(p, 0x1b);
            ((struct Obj00339 *)p)->f12A = 7;
            break;
        }
        break;
    case 4:
        func_021BBE3C(p);
        func_021BBF98(p);
        ((struct Obj00339 *)p)->f12A = 0;
        return func_021BC080(p, 1);
    case 5:
        if (func_021BBFA8(p) == 0)
            ((struct Obj00339 *)p)->f12A = ((struct Obj00339 *)p)->f12A + 1;
        break;
    case 6:
        if (func_020362DC() & 3) {
            ((struct Obj00339 *)p)->f12C = 1;
            ((struct Obj00339 *)p)->f12A = 4;
        }
        break;
    case 7:
        if (func_021BBFA8(p) == 0) {
            func_021BC024(p);
            ((struct Obj00339 *)p)->f12A = ((struct Obj00339 *)p)->f12A + 1;
        }
        break;
    case 8:
        r = func_0201FEBC(*(u8 * *)&((struct Obj00339 *)p)->f7C);
        switch (r) {
        case 0:
            ((struct Obj00339 *)p)->f12C = 1;
            ((struct Obj00339 *)p)->f12A = 4;
            break;
        case (u32_021BA540)-2:
            func_021BBF1C(p, 0x1a);
            ((struct Obj00339 *)p)->f12A = 2;
            break;
        }
        break;
    }
    func_0201C4E4(((struct Obj00339 *)p)->f68);
    t = ((struct Obj00339 *)p)->f68;
    if (((struct Obj00339 *)p)->fF4 != 0 && func_0201C6C4(t, func_02045770(((struct Obj00339 *)p)->fF0)) == 0) {
        func_02045334(((struct Obj00339 *)p)->fF0);
        ((struct Obj00339 *)p)->fF4 = 0;
    }
    return 7;
}








int func_021BA6B0(char *p)
{
    void *t;
    switch (((struct Obj00263 *)p)->f12A) {
    case 0:
        if (((struct Obj00263 *)p)->f120 == 1) {
            ((struct Obj00263 *)p)->f129 = 1;
            ((struct Obj00263 *)p)->f12A = 0;
            return func_021BC080(p, 1);
        }
        func_021BBBAC(p);
        ((struct Obj00263 *)p)->f12A = ((struct Obj00263 *)p)->f12A + 1;
        break;
    case 1:
        if (func_0201C6B4(((struct Obj00263 *)p)->f68) == 1)
            ((struct Obj00263 *)p)->f12A = ((struct Obj00263 *)p)->f12A + 1;
        break;
    case 2:
        if (func_020362DC() & 1) {
            func_020061E4(0x54c);
            func_021BBD10(p, 1);
            ((struct Obj00263 *)p)->f129 = 1;
            ((struct Obj00263 *)p)->f12A = 0;
            return func_021BC080(p, 1);
        }
        if (func_020362DC() & 2) {
            func_020061E4(0x551);
            func_021BBD10(p, 0);
            func_021BB810(p, *(u8 *)(p + ((struct Obj00263 *)p)->f128 + 0x120),
                          func_021BB840(p, ((struct Obj00263 *)p)->f12F), 2);
            ((struct Obj00263 *)p)->f12A = 0;
            return 5;
        }
        break;
    }
    func_0201C4E4(((struct Obj00263 *)p)->f68);
    t = ((struct Obj00263 *)p)->f68;
    if (((struct Obj00263 *)p)->fF4 != 0 && func_0201C6C4(t, func_02045770(((struct Obj00263 *)p)->fF0)) == 0) {
        func_02045334(((struct Obj00263 *)p)->fF0);
        ((struct Obj00263 *)p)->fF4 = 0;
    }
    return 8;
}








int func_021BA7AC(char *p)
{
    void *t;
    if (func_0202EB0C() == 1) {
        switch (((struct Obj00263 *)p)->f12A) {
        case 0:
            func_021BBE48(p);
            ((struct Obj00263 *)p)->f12A = ((struct Obj00263 *)p)->f12A + 1;
            break;
        case 1:
            if (func_0201C6B4(((struct Obj00263 *)p)->f68) == 1)
                ((struct Obj00263 *)p)->f12A = ((struct Obj00263 *)p)->f12A + 1;
            break;
        case 2:
            if (func_020362DC() & 3) {
                func_020061E4(0x54c);
                func_021BBD10(p, 0);
                func_021BB810(p, *(u8 *)(p + ((struct Obj00263 *)p)->f128 + 0x120),
                              func_021BB840(p, ((struct Obj00263 *)p)->f12F), 2);
                ((struct Obj00263 *)p)->f12A = 0;
                return 5;
            }
            break;
        }
        func_0201C4E4(((struct Obj00263 *)p)->f68);
        t = ((struct Obj00263 *)p)->f68;
        if (((struct Obj00263 *)p)->fF4 != 0 && func_0201C6C4(t, func_02045770(((struct Obj00263 *)p)->fF0)) == 0) {
            func_02045334(((struct Obj00263 *)p)->fF0);
            ((struct Obj00263 *)p)->fF4 = 0;
        }
        return 9;
    }
    ((struct Obj00263 *)p)->f129 = *(u8 *)(p + ((struct Obj00263 *)p)->f128 + 0x120);
    return 11;
}








/*
 * 0x021BA984 is an unlabelled tail-call stub (function_starts seed);
 * verified with tu over 0x021BA880..0x021BA990 (272 bytes).
 */
int func_021BA880(char *p)
{
    u32_021BA880 i;
    switch (((struct Obj02127 *)p)->f12A) {
    case 0:
        func_020434DC(0x1e, 0);
        func_02043598(0x17, 0);
        func_02040EBC(0, 0x7d8c);
        func_02040EBC(4, 0x7d8c);
        ((struct Obj02127 *)p)->f12A = ((struct Obj02127 *)p)->f12A + 1;
        return func_021BC054(p, 10);
    case 1:
        for (;;) {
            i = ((struct Obj02127 *)p)->f14C;
            if (i >= 8) {
                func_021BBF98(p);
                ((struct Obj02127 *)p)->f12A = 3;
                return func_021BC080(p, 10);
            }
            if ((d_021BD784[i].mask & ((struct Obj02127 *)p)->f148) == 0) {
                ((struct Obj02127 *)p)->f14C += 1;
                continue;
            }
            func_021BBF1C(p, d_021BD784[i].msg);
            ((struct Obj02127 *)p)->f14C += 1;
            ((struct Obj02127 *)p)->f12A = ((struct Obj02127 *)p)->f12A + 1;
            break;
        }
        break;
    case 2:
        if (func_021BBFA8(p) == 0 && (func_020362DC() & 3)) {
            func_020061E4(0x547);
            ((struct Obj02127 *)p)->f12A = 1;
        }
        break;
    case 3:
        func_020434DC(0x1e, 1);
        func_02043598(0x17, 1);
        ((struct Obj02127 *)p)->f12A = 0;
        return func_021BC054(p, 5);
    }
    return 10;
}








int func_021BA984(char *p)
{
    return func_021BC080(p, 1);
}








/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32_021BA990 *)((u32_021BA990)SDK_AUTOLOAD_DTCM_START + 0x3FF8))








void func_021BA990(void)
{
    func_020419E4();
    func_0204A648();
    OSi_IRQ_CHECK_FLAG |= 1;
}








void func_021BA9B0(int *p)
{
    p[5] = (int)func_020056A0((void *)func_021BA990, p, 0);
}








void func_021BA9C8(int *p)
{
    func_02030EAC((struct Node *)p[5]);
}







void func_021BA9D4(void)
{
    func_0204335C(0);
    func_020433E0((const struct DispVram *)d_021BD60C);
}







void func_021BA9E8(void)
{
    A16 a;
    B32 b0;
    B32 b1;
    B32 b2;
    B32 b3;
    B32 b4;
    B32 b5;
    B32 b6;

    func_0203F8F4(0xb);
    a = d_021BD678;
    func_0203FC28((struct DispConfig *)(&a));
    b0 = d_021BD724;
    func_0203FCA0(0, (const struct BgTemplate *)(&b0), 0);
    b1 = d_021BD764;
    func_0203FCA0(1, (const struct BgTemplate *)(&b1), 0);
    b2 = d_021BD6C4;
    func_0203FCA0(2, (const struct BgTemplate *)(&b2), 0);
    b3 = d_021BD6E4;
    func_0203FCA0(3, (const struct BgTemplate *)(&b3), 0);
    b4 = d_021BD744;
    func_0203FCA0(4, (const struct BgTemplate *)(&b4), 0);
    b5 = d_021BD6A4;
    func_0203FCA0(5, (const struct BgTemplate *)(&b5), 0);
    b6 = d_021BD704;
    func_0203FCA0(6, (const struct BgTemplate *)(&b6), 0);
    func_020434DC(0xf, 1);
    func_02043598(7, 1);
}







/*
 * EXACT*: inferred extent runs two bytes long; the follower at 0x021BAB62 is
 * an unlabelled leaf (no lr save) that disasm.py did not label.
 */
void func_021BAB20(void)
{
    func_020434DC(0xf, 0);
    func_02043598(7, 0);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_0203F9B4();
}







void func_021BAB64(void)
{
    void *h;
    h = func_020490F4(0x23, 0x800B);
    func_02049B68(h, 4, 0, 0, 0xc0, 0xb);
    func_02049658(h, 3, 2, 0, 0, 1, 0xb);
    func_020498F4(h, 2, 3, 0, 0, 1, 0xb);
    func_02049B68(h, 5, 4, 0, 0xc0, 0xb);
    func_02049658(h, 1, 5, 0, 0, 1, 0xb);
    func_020498F4(h, 0, 6, 0, 0, 1, 0xb);
    func_02049238(h);
    func_0201F5BC(0, 1, 0xe, 0, 0xb);
    func_02049B40(0x17, 5, 0, 0x1e0, 0x20, 0xb);
    func_02049B40(0x17, 5, 4, 0x1e0, 0x20, 0xb);
}







void func_021BAC24(char *p)
{
    void *h;
    h = func_020490F4(0x23, 0x800B);
    ((struct Obj00014 *)p)->f11C = (int)func_0202E940(0x20, 0x10, 2, 0xb);
    func_0202E9AC((struct CodeIn *)(((struct Obj00014 *)p)->f11C), h, 4, 0x20, 0x30);
    func_02049238(h);
}







void func_021BAC64(char *p)
{
    func_0202EA20((struct Obj0202EA20 *)(((struct Obj20816 *)p)->f11C));
}







void func_021BAC74(char *p)
{
    *(u32 *)&((struct Obj00014 *)p)->f5C = (u32)func_02045B38(0, 2, 0xb3, 0xb);
    *(u32 *)&((struct Obj00014 *)p)->f58 = (u32)func_0201D7EC(0x17, 0, 0, 0, 0xb);
    *(u32 *)&((struct Obj00014 *)p)->f60 = (u32)func_0201EC64(0xb);
    *(u32 *)&((struct Obj00014 *)p)->f68 = func_0201C440((void *)0xb);
    *(u32 *)&((struct Obj00014 *)p)->f64 = (u32)func_020457B0(0x400, 0xb);
    ((struct Obj00014 *)p)->f70 = (u32)func_0203101C(0xb, 0xb, 1, 4);
    ((struct Obj00014 *)p)->f74 = func_02028590(0xf, 1, 0, 0xb);
}







void func_021BACD8(int *p)
{
    func_02028604(p[0x74 / 4]);
    func_02031140((struct S02031140 *)p[0x70 / 4]);
    func_02045808((struct U16Vec *)p[0x64 / 4]);
    func_0201C4C0((struct PrintSys *)p[0x68 / 4]);
    func_0201ED04((struct WordSet *)p[0x60 / 4]);
    func_0201D83C((void *)p[0x58 / 4]);
    func_02045C04((struct Rec *)p[0x5c / 4]);
}







void func_021BAD08(struct Menu *p)
{
    u32 i;
    void *a;
    void *s;
    void *b;
    void *bg;
    u16 buf[14];

    func_02045088(11);
    for (i = 0; i < 14; i++) {
        p->slot[i].obj = (void *)func_020450F0(d_021BD7C4[i].a0, d_021BD7C4[i].a1, d_021BD7C4[i].a2,
                                       d_021BD7C4[i].a3, d_021BD7C4[i].a4, d_021BD7C4[i].a5, 1);
    }

    a = func_02045EC0(p->f5c, 0);
    bg = p->f68;
    func_0201C724(bg, (u32)func_02045770(p->slot[0].obj), 0, 4, (u32)a, (u32)p->f58, 0x440);
    p->slot[0].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 12);
    func_0201F02C(p->f60, 0, p->f04);
    func_0201F250(p->f60, p->f64, a);
    if (func_02008550(p->f04) == 0) {
        bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[1].obj), 0, 0, (u32)p->f64, (u32)p->f58, 0xC80);
        p->slot[1].on = 1;
    } else {
        bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[1].obj), 0, 0, (u32)p->f64, (u32)p->f58, 0x14C0);
        p->slot[1].on = 1;
    }
    func_02045808(a);

    a = func_02045EC0(p->f5c, 16);
    func_020139B0(0x800B);
    if (func_020142E8(p->f10, 0x966) == 1) {
        s = (void *)func_02013E4C(func_02008848(func_02008854(p->f00))[2]);
    } else {
        func_0200890C(p->f00, (struct Sub02008828Rec *)buf);
        s = (void *)func_02013E4C(buf[0]);
    }
    func_02013A48();
    func_0201F158(p->f60, 0, (u32)s);
    func_0201F250(p->f60, p->f64, a);
    bg = p->f68;
    func_0201C724(bg, (u32)func_02045770(p->slot[2].obj), 0, 0, (u32)p->f64, (u32)p->f58, 0x440);
    p->slot[2].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 9);
    b = func_02008748(p->f00);
    func_0201EFA4(p->f60, 0, func_0200864C(b), 3, 0, 1);
    func_0201EFA4(p->f60, 1, func_02008650(b), 2, 2, 1);
    func_0201F250(p->f60, p->f64, a);
    bg = p->f68;
    func_0201C724(bg, (u32)func_02045770(p->slot[3].obj), 0, 0, (u32)p->f64, (u32)p->f58, 0x440);
    p->slot[3].on = 1;
    func_02045808(a);

    if (func_020142E8(p->f10, 0x962) == 1) {
        a = func_02045EC0(p->f5c, 10);
        func_0201EFA4(p->f60, 0, func_0200D0AC(func_0200CA10(p->f00), 11), 3, 0, 1);
        func_0201F250(p->f60, p->f64, a);
        bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[4].obj), 0, 0, (u32)p->f64, (u32)p->f58, 0x440);
        p->slot[4].on = 1;
        func_02045808(a);
    }

    a = func_02045EC0(p->f5c, 11);
    func_0201EFA4(p->f60, 0, func_0200C258(func_0200C0F0(p->f00)), 2, 0, 1);
    func_0201F250(p->f60, p->f64, a);
    bg = p->f68;
    func_0201C724(bg, (u32)func_02045770(p->slot[5].obj), 0, 0, (u32)p->f64, (u32)p->f58, 0x440);
    p->slot[5].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 1);
    {
        void *bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[6].obj), 0, 4, (u32)a, (u32)p->f58, 0x440);
    }
    p->slot[6].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 2);
    {
        void *bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[7].obj), 0, 4, (u32)a, (u32)p->f58, 0x440);
    }
    p->slot[7].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 4);
    {
        void *bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[8].obj), 0, 4, (u32)a, (u32)p->f58, 0x440);
    }
    p->slot[8].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 5);
    {
        void *bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[9].obj), 0, 4, (u32)a, (u32)p->f58, 0x440);
    }
    p->slot[9].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 3);
    {
        void *bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[10].obj), 0, 4, (u32)a, (u32)p->f58, 0x440);
    }
    p->slot[10].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 7);
    {
        void *bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[11].obj), 0, 4, (u32)a, (u32)p->f58, 0x440);
    }
    p->slot[11].on = 1;
    func_02045808(a);

    a = func_02045EC0(p->f5c, 6);
    {
        void *bg = p->f68;
        func_0201C724(bg, (u32)func_02045770(p->slot[12].obj), 0, 4, (u32)a, (u32)p->f58, 0x440);
    }
    p->slot[12].on = 1;
    func_02045808(a);
}







/*
 * Releases the fourteen 8-byte-stride handles at +0x80 created by
 * func_021BAD08, then the shared resource.
 */
void func_021BB164(char *p)
{
    unsigned i;
    for (i = 0; i < 14; i++)
        func_020452E8(*(void **)(p + 0x80 + i * 8));
    func_020450C8();
}






void func_021BB184(int *p)
{
    T28 t;
    void *h;
    u32 i;

    t = d_021BD688;
    func_0204A48C((const struct Cfg *)(&t), (u32)d_021BD60C, 0xb);
    h = func_020490F4(0x1f, 0x800b);
    if (func_02008550((const struct Sub0200852CObj *)p[1]) == 0) {
        p[13] = func_0204A6C8(h, 5, 0, 0, 0xb);
        p[16] = func_0204ABF0(h, 4, 0, 0, 0xb);
        p[19] = func_0204AF28(h, 0, 1, 0xb);
    } else {
        p[13] = func_0204A6C8(h, 7, 0, 0, 0xb);
        p[16] = func_0204ABF0(h, 6, 0, 0, 0xb);
        p[19] = func_0204AF28(h, 2, 3, 0xb);
    }
    func_02049238(h);
    h = func_020490F4(0x23, 0x800b);
    p[14] = func_0204A6C8(h, 8, 1, 0, 0xb);
    p[17] = func_0204ABF0(h, 9, 0, 0x20, 0xb);
    p[20] = func_0204AF28(h, 0xa, 0xb, 0xb);
    p[15] = func_0204A6C8(h, 0xc, 1, 0, 0xb);
    p[18] = func_0204ABF0(h, 0xd, 0, 0x40, 0xb);
    p[21] = func_0204AF28(h, 0xe, 0xf, 0xb);
    func_02049238(h);
    p[6] = (int)func_0204B100(6, 0, 0xb);
    p[7] = (int)(struct Obj *)func_0204B294((int)((void *)p[6]), p[13], p[16], p[19], (Local *)d_021BD5DC, 0, 0xb);
    func_0204B3DC((void *)p[7], 0);
    for (i = 1; i <= 4; i++) {
        p[7 + i] = (int)(struct Obj *)func_0204B294((int)((void *)p[6]), p[14], p[17], p[20], (Local *)d_021BD5E4, 0, 0xb);
        func_0204B92C((struct Obj *)p[7 + i], 1);
        func_0204B3DC((void *)p[7 + i], 0);
    }
    p[12] = (int)(struct Obj *)func_0204B294((int)((void *)p[6]), p[15], p[18], p[21], (Local *)d_021BD5D4, 0, 0xb);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}






void func_021BB328(char *p)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        func_0204B3B4(*(void **)(p + 0x1c + i * 4));
    func_0204B1CC(((struct Obj20817 *)p)->f18);
    for (i = 0; i < 3; i++)
        func_0204A8D4((u32)(*(void **)(p + 0x34 + i * 4)));
    for (i = 0; i < 3; i++)
        func_0204ADA4((u32)(*(void **)(p + 0x40 + i * 4)));
    for (i = 0; i < 3; i++)
        func_0204AFD8((u32)(*(void **)(p + 0x4c + i * 4)));
    func_0204A5AC();
}






/*
 * Builds an 8-window bgwinfrm manager at +0x118, initialises each window
 * from a 4-byte table (height from its halfword at +2), then binds the
 * thirteen resources at +0x80..+0xe0 (stride 8) to windows 0,0,0,0,0,0,1..7.
 */
void func_021BB380(char *p)
{
    u32 i;

    ((struct Obj00014 *)p)->f118 = func_0202C9B4(0, 8, 0xb);
    for (i = 0; i < 8; i++)
        func_0202CA3C(((struct Obj00014 *)p)->f118, i, 1, 0x1a, d_021BD5EC[i].f2);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 0, ((struct Obj00014 *)p)->f80);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 0, ((struct Obj00014 *)p)->f88);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 0, ((struct Obj00014 *)p)->f90);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 0, ((struct Obj00014 *)p)->f98);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 0, ((struct Obj00014 *)p)->fA0);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 0, ((struct Obj00014 *)p)->fA8);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 1, ((struct Obj00014 *)p)->fB0);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 2, ((struct Obj00014 *)p)->fB8);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 3, ((struct Obj00014 *)p)->fC0);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 4, ((struct Obj00014 *)p)->fC8);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 5, ((struct Obj00014 *)p)->fD0);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 6, ((struct Obj00014 *)p)->fD8);
    func_0202CEBC(((struct Obj00014 *)p)->f118, 7, ((struct Obj00014 *)p)->fE0);
}






/*
 * Tail-calls the release of the handle kept at +0x118.
 */
void func_021BB474(char *p)
{
    func_0202CA0C(((struct Obj20818 *)p)->f118);
}






void func_021BB484(void)
{
    func_0207D63C((void *)0x04000050, 4, 8, 16, 3);
    func_0207D63C((void *)0x04001050, 2, 4, 16, 3);
}




void func_021BB4B4(char *p)
{
    unsigned i = 0;
    if (func_020071EC(((struct Obj00014 *)p)->f0) == 1) {
        p[0x120] = 0;
        i++;
    }
    (p + i)[0x120] = 1;
    (p + i)[0x121] = 2;
    i += 2;
    if (func_0200C308(((struct Obj00014 *)p)->f8, 1)) {
        (p + i)[0x120] = 3;
        i++;
    }
    if (func_0200C308(((struct Obj00014 *)p)->f8, 2)) {
        (p + i)[0x120] = 4;
        i++;
    }
    (p + i)[0x120] = 5;
    (p + i)[0x121] = 6;
    i += 2;
    if (func_0200C308(((struct Obj00014 *)p)->f8, 3)) {
        (p + i)[0x120] = 7;
        i++;
    }
    while (i < 8) {
        (p + i)[0x120] = 8;
        i++;
    }
}




void func_021BB544(char *p)
{
    void *h = func_020490F4(0x23, 0x800B);
    u32 i;
    for (i = 0; i < 8; i++) {
        u32 sz = d_021BD5EC[i].f2 * 0x34;
        void *out;
        void *r;
        *(u32 *)(p + i * 4 + 0xf8) = (u32)func_02030734(0xb, sz, 0, d_021BDA00, 0x7e9);
        r = func_02049EF4(h, d_021BD5EC[i].f0, 1, &out, 0xb);
        func_02082A60((char *)out + 0xc, *(void **)(p + i * 4 + 0xf8), sz);
        func_020307B0(r);
    }
    func_02049238(h);
}





/*
 * Frees the eight row buffers at +0xF8 allocated by func_021BB544.
 */
void func_021BB5C4(char *p)
{
    unsigned i;
    for (i = 0; i < 8; i++)
        func_020307B0(*(void **)(p + 0xf8 + i * 4));
}





void func_021BB5E0(char *p, u32 idx, s16_021BB5C4 y)
{
    Pos pos;
    func_0204B454(((void **)(p + 0x1c))[idx], (struct PtS *)&pos, 0);
    pos.y = y;
    func_0204B404(((void **)(p + 0x1c))[idx], (const struct Vec2 *)(&pos), 0);
}





/*
 * Lays out the up-to-eight menu rows listed at +0x120 (8 terminates),
 * stacking them by the heights in d_021BD5EC and positioning the row
 * sprites.  Row order is filled in by ov088_func_021BB4B4.c.
 */
void func_021BB608(char *p)
{
    u32 i;
    s8 y;
    u8 v;
    void *obj;

    i = 0;
    p[0x128] = 0;
    ((struct Obj00014 *)p)->f130 = 0;
    y = 2;
    p[0x12f] = 2;
    for (i = 0; i < 8; i++) {
        if ((u8)(p + i)[0x120] == 8)
            break;
        func_021BB798(p, (u8)(p + i)[0x120], y);
        v = (p + i)[0x120];
        if (v == 0) {
            obj = ((struct Obj00014 *)p)->f1C;
        } else if (v == 5) {
            func_021BB5E0(p, 5, y * 8 + d_021BD5EC[v].f2 * 8 / 2);
            obj = ((struct Obj00014 *)p)->f30;
        } else if (v == 3) {
            if (func_0200C308(((struct Obj00014 *)p)->f8, 1) != 1)
                goto next;
            func_021BB5E0(p, 2, y * 8 + d_021BD5EC[(u8)(p + i)[0x120]].f2 * 8 / 2);
            obj = ((struct Obj00014 *)p)->f24;
        } else if (v == 4) {
            if (func_0200C308(((struct Obj00014 *)p)->f8, 2) != 1)
                goto next;
            func_021BB5E0(p, 3, y * 8 + d_021BD5EC[(u8)(p + i)[0x120]].f2 * 8 / 2);
            obj = ((struct Obj00014 *)p)->f28;
        } else if (v == 7) {
            if (func_0200C308(((struct Obj00014 *)p)->f8, 3) != 1)
                goto next;
            func_021BB5E0(p, 4, y * 8 + d_021BD5EC[(u8)(p + i)[0x120]].f2 * 8 / 2);
            obj = ((struct Obj00014 *)p)->f2C;
        } else {
            goto next;
        }
        func_0204B3DC(obj, 1);
    next:
        y += (s8)d_021BD5EC[(u8)(p + i)[0x120]].f2;
    }
    func_021BB5E0(p, 0, 0x40);
    func_021BB810(p, (u8)p[0x120], (s8)p[0x12f], 2);
}





void func_021BB798(char *p, u32 i, u32 arg)
{
    u8 v = arg;
    u16 x = *(u16 *)((char *)d_021BD5EE + i * 4);
    u32 h;
    func_020410D0(2, 3, v, 0x1a, x, (u32)(*(void **)(p + i * 4 + 0xf8)), 0, 0, 0x1a, x);
    h = func_0202CF84(((struct Obj20819 *)p)->f118, i);
    func_020410D0(1, 3, v, 0x1a, x, (u32)((void *)h), 0, 0, 0x1a, x);
    func_02041B6C(1);
    func_02041B6C(2);
}





/*
 * Redraws menu row `row` (height from the row table d_021BD5EE) at tile
 * row y on bg layer 2 with palette pal, then commits the layer.
 */
void func_021BB810(void *p, u8 row, int y, int pal)
{
    func_020413B0(2, 3, y, 0x1a, *(u16 *)((char *)d_021BD5EE + row * 4), pal);
    func_02041B6C(2);
}





int func_021BB840(char *p, int y)
{
    return (s8)(y + ((struct Obj20820 *)p)->f130 / 8);
}




/*
 * Shifts the six sprites at +0x1c..+0x30 vertically by d.
 */
void func_021BB858(char *p, int d)
{
    u32 i;
    Pos pos;
    for (i = 0; i < 6; i++) {
        func_0204B454((struct Actor *)*(int *)((p + i * 4) + 0x1c), (struct PtS *)&pos, 0);
        pos.y += (s16_021BB798)d;
        func_0204B404((struct Obj *)(*(int *)((p + i * 4) + 0x1c)), (const struct Vec2 *)(&pos), 0);
    }
}





int func_021BB890(char *p, int d)
{
    u8 old;
    u16 h;
    s8 y;
    u8 nv;
    s8 n;
    u8 cur;

    cur = p[0x128];
    old = (p + cur)[0x120];
    ((struct Obj00271 *)p)->f134 = 0;
    if (d < 0) {
        if (cur == 0)
            return 0;
        n = cur + d;
        h = ROWH((u8)(p + n)[0x120]);
        y = (s8)p[0x12f] - h;
        func_021BB810(p, old, func_021BB840(p, (s8)p[0x12f]), 1);
        if ((u8)p[0x120] == 0) {
            if (y < 2) {
                if (n == 0) {
                    ((struct Obj00271 *)p)->f138 = -(((h - ((s8)p[0x12f] - 2)) / 3) * 8);
                    p[0x12f] = 2;
                } else {
                    ((struct Obj00271 *)p)->f138 = -((h / 3) * 8);
                }
            } else {
                p[0x12f] = y;
            }
        } else {
            p[0x12f] = y;
        }
    } else {
        if (cur + d >= 8)
            return 0;
        if ((u8)(p + (cur + d))[0x120] == 8)
            return 0;
        nv = (p + (s8)(cur + d))[0x120];
        y = (s8)p[0x12f] + ROWH(old);
        func_021BB810(p, old, func_021BB840(p, (s8)p[0x12f]), 1);
        if ((u8)p[0x120] == 0) {
            if (y == 0x18) {
                ((struct Obj00271 *)p)->f138 = (ROWH(nv) / 3) * 8;
            } else if (y + ROWH(nv) > 0x18) {
                ((struct Obj00271 *)p)->f138 = (ROWH(nv) / 3) * 8;
            } else {
                p[0x12f] = y;
            }
        } else {
            p[0x12f] = y;
        }
    }
    ((struct Obj00271 *)p)->f128 += (u8)d;
    return 1;
}




void func_021BB9DC(char *p, int flag)
{
    unsigned i;
    if (flag == 0) {
        for (i = 0; i <= 5; i++)
            func_0204B3DC(*(void **)(p + 0x1c + i * 4), flag);
        return;
    }
    func_0204B3DC(((struct Obj03675 *)p)->f1C, 1);
    for (i = 0; i < 8; i++) {
        u8 c = *(u8 *)(p + 0x120 + i);
        if (c == 8)
            return;
        if (c == 3) {
            if (func_0200C308(((struct Obj03675 *)p)->f8, 1) == 1)
                func_0204B3DC(((struct Obj03675 *)p)->f24, 1);
        } else if (c == 4) {
            if (func_0200C308(((struct Obj03675 *)p)->f8, 2) == 1)
                func_0204B3DC(((struct Obj03675 *)p)->f28, 1);
        } else if (c == 7) {
            if (func_0200C308(((struct Obj03675 *)p)->f8, 3) == 1)
                func_0204B3DC(((struct Obj03675 *)p)->f2C, 1);
        } else if (c == 5) {
            func_0204B3DC(((struct Obj03675 *)p)->f30, 1);
        }
    }
}




void func_021BBA64(u8 x, u8 y, u8 w, u8 h, u8 bg)
{
    u32 layer = *(u32 *)&bg;

    func_02041300(layer, 1, x, y, 1, 1, 1);
    func_02041300(layer, 3, x + w - 1, y, 1, 1, 1);
    func_02041300(layer, 7, x, y + h - 1, 1, 1, 1);
    func_02041300(layer, 9, x + w - 1, y + h - 1, 1, 1, 1);
    func_02041300(layer, 2, x + 1, y, w - 2, 1, 1);
    func_02041300(layer, 8, x + 1, y + h - 1, w - 2, 1, 1);
    func_02041300(layer, 4, x, y + 1, 1, h - 2, 1);
    func_02041300(layer, 6, x + w - 1, y + 1, 1, h - 2, 1);
    func_02041300(layer, 5, x + 1, y + 1, w - 2, h - 2, 1);
    func_02041B6C(layer);
}
