/*
 * file:     fldeff_splash.c
 * unit:     yes
 * function: func_021C48A0, func_021C4938, func_021C4954, func_021C4974, func_021C4978, func_021C49AC, func_021C49C0, func_021C4A00, func_021C4A10, func_021C4A3C, func_021C4AE8, func_021C4B04, func_021C4B24, func_021C4B28, func_021C4B50, func_021C4B64, func_021C4BC4, func_021C4BE0, func_021C4C0C, func_021C4C50, func_021C4C54, func_021C4CDC, func_021C4D14, func_021C4D7C, func_021C4DA8, func_021C4DC0, func_021C4DE4, func_021C4E08, func_021C4E20, func_021C4E34, func_021C4E6C, func_021C4F7C, func_021C51A0, func_021C5224, func_021C5334, func_021C5348, func_021C536C, func_021C5380, func_021C5394, func_021C53A0, func_021C5424, func_021C5440, func_021C54C8, func_021C553C, func_021C56F8, func_021C5768, func_021C576C, func_021C577C, func_021C5880, func_021C58CC, func_021C59A8, func_021C59BC, func_021C59F8, func_021C5A28, func_021C5A54, func_021C5AAC, func_021C5B58, func_021C5BD0, func_021C5C08, func_021C5C64, func_021C5D10, func_021C5DF4
 * address:  0x021C48A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_02050340  0x02050340  arm
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_02050804  0x02050804  arm
 *   func_0205082C  0x0205082C  arm
 *   func_020507F0  0x020507F0  arm
 *   d_021DE464     0x021DE464  data  a4
 *   func_021ABE14  0x021ABE14  thumb  ov021
 *   func_02188C90  0x02188C90  thumb  ov021
 *   d_021DE47C     0x021DE47C  data  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021ABE24  0x021ABE24  thumb  ov021
 *   func_02046E24  0x02046E24  arm
 *   func_021AC1F0  0x021AC1F0  thumb  ov021
 *   func_020500F0  0x020500F0  arm
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   d_021DAA2C     0x021DAA2C  data  ov021
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   d_021DE478     0x021DE478  data  a4
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021C6AE0  0x021C6AE0  thumb  ov021
 *   func_021C6AF0  0x021C6AF0  thumb  ov021
 *   func_021C6AF8  0x021C6AF8  thumb  ov021
 *   func_021C6AFC  0x021C6AFC  thumb  ov021
 *   func_021C6574  0x021C6574  thumb  ov021
 *   func_021C6590  0x021C6590  thumb  ov021
 *   func_021C67D8  0x021C67D8  thumb  ov021
 *   func_021C6628  0x021C6628  thumb  ov021
 *   func_021C6580  0x021C6580  thumb  ov021
 *   d_021DAA18     0x021DAA18  data  ov021
 *   func_0216E1A4  0x0216E1A4  thumb  ov010
 *   func_0216E1C4  0x0216E1C4  thumb  ov010
 *   func_0216DBE8  0x0216DBE8  thumb  ov010
 *   func_021C6658  0x021C6658  thumb  ov021
 *   func_021C6844  0x021C6844  thumb  ov021
 *   func_021C66EC  0x021C66EC  thumb  ov021
 *   func_021C6828  0x021C6828  thumb  ov021
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_021C67F4  0x021C67F4  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02012134  0x02012134  thumb
 *   func_0202B57C  0x0202B57C  thumb
 *   func_02030734  0x02030734  arm
 *   func_0202B928  0x0202B928  thumb
 *   func_0202B920  0x0202B920  thumb
 *   d_021DE48C     0x021DE48C  data  a4
 *   func_02011558  0x02011558  thumb
 *   func_0201160C  0x0201160C  thumb
 *   func_0202B934  0x0202B934  thumb
 *   _fdiv          0x0209CE10  arm
 *   _fflt          0x0209BDBC  arm
 *   _ffixu         0x0209C4C8  arm
 *   _fls           0x0209BC74  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   func_02011638  0x02011638  thumb
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_020520FC  0x020520FC  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414AC  0x020414AC  arm
 *   func_02040C14  0x02040C14  arm
 *   func_0204B100  0x0204B100  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_02045B38  0x02045B38  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C450  0x0201C450  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C40C  0x0200C40C  thumb
 *   func_02041B6C  0x02041B6C  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040618  0x02040618  arm
 *   func_02040588  0x02040588  arm
 *   d_021DE498     0x021DE498  data  ov021  a1
 *   d_021DAA60     0x021DAA60  data  a4
 *   d_021DAA54     0x021DAA54  data  a4
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_02040DA8  0x02040DA8  arm
 *   func_020403F4  0x020403F4  arm
 *   func_020061E4 0x020061E4 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020452E8  0x020452E8  arm
 *   func_020202FC  0x020202FC  thumb
 *   func_02020324  0x02020324  thumb
 *   func_020355D8 0x020355D8 arm
 *   func_020202EC 0x020202EC thumb
 *   func_02020350 0x02020350 thumb
 *   func_0203633C 0x0203633C arm
 *   func_020362DC 0x020362DC arm
 *   func_020200CC 0x020200CC thumb
 *   func_02020344 0x02020344 thumb
 *   func_0200C480 0x0200C480 thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02020314 0x02020314 thumb
 *   func_0200C468 0x0200C468 thumb
 *   func_0200C464 0x0200C464 thumb
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_0201FF30 0x0201FF30 thumb
 *   d_021DAA80    0x021DAA80 data  a4
 *   func_0202020C  0x0202020C  thumb
 *   func_0201F868  0x0201F868  thumb
 *   func_020146F8  0x020146F8  thumb
 *   func_02014728  0x02014728  thumb
 *   func_02012374  0x02012374  thumb
 *   abs_id_C2      0x000000C2  data
 *   d_021F5580     0x021F5580  data  ov194  a4
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0216BFD4  0x0216BFD4  thumb  ov010
 *   func_02017E40  0x02017E40  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_0216C0C0  0x0216C0C0  thumb  ov010
 *   ov171_id       0x000000AB  data  a1
 *   d_021DEA44    0x021DEA44  data  ov021  a1
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021A3364  0x021A3364  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_0218DAEC  0x0218DAEC  thumb
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB2E8  0x021AB2E8  thumb  ov021
 *   func_021AB3B0  0x021AB3B0  thumb
 *   func_02164208  0x02164208  thumb  ov010
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021A34EC  0x021A34EC  thumb  ov021
 *   func_021AA900  0x021AA900  thumb  ov021
 *   func_021AA180  0x021AA180  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_021A2F48  0x021A2F48  thumb  ov021
 *   func_021A2F54  0x021A2F54  thumb  ov021
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_021C5FA8  0x021C5FA8  thumb  ov021
 *   func_021C602C  0x021C602C  thumb  ov021
 *   func_02005728  0x02005728  thumb
 *   func_021C5FC0  0x021C5FC0  thumb  ov021
 *   func_021C5FEC  0x021C5FEC  thumb  ov021
 *   func_021C6018  0x021C6018  thumb  ov021
 *   func_021C6054  0x021C6054  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_021AA8EC  0x021AA8EC  thumb  ov021
 *   func_020130B4  0x020130B4  thumb
 *   func_0216E7C8  0x0216E7C8  thumb  ov010
 *   func_0201235C  0x0201235C  thumb
 */
#include "../../matched/include/Obj07561.h"
#include "../../matched/include/Obj06076.h"
#include "../../matched/include/Obj01507.h"
#include "../../matched/include/Obj12132.h"
#include "../../matched/include/Obj01666.h"
#include "../../matched/include/Obj00960.h"
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj01216.h"
#include "../../matched/include/Obj18304.h"
#include "../../matched/include/Obj07562.h"
#include "../../matched/include/Obj12940.h"
#include "../../matched/include/Obj12941.h"
#include "../../matched/include/Obj12942.h"
#include "../../matched/include/Obj00874.h"
#include "../../matched/include/Obj18305.h"
#include "../../matched/include/Obj04281.h"
#include "../../matched/include/Obj00523.h"
#include "../../matched/include/Obj02094.h"
#include "../../matched/include/Obj20207.h"
#include "../../matched/include/Obj04282.h"
#include "../../matched/include/Obj12133.h"
#include "../../matched/include/Obj09688.h"

struct BbActDesc;
struct BbActSys;
struct BbActRec;
struct X;
struct Actor;
struct VecFx32;
struct Res_021C48A0;
struct IcaAnime;
struct Obj11245;
struct Rec12;
struct Mtx33;
struct Big;
struct BgTemplate;
struct Bank;
struct GfFont;
struct MsgBank;
struct Obj;
struct PrintSys;
struct Rec;
struct Node;
struct Descriptor;
struct Cfg;
struct Slot;
struct Src;
struct PtS;
struct Vec2;
struct Desc;
struct Evt;
struct BigObj;
struct Ctx;
struct Sub02008C20Obj;
struct Obj00020;
struct Self;
struct S0201235C;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int x, y, z; } V3;

typedef struct {
    u16 slot;
    u16 v12;
    u16 v14;
    u8 k;
    u8 pad;
    u32 flag;
    u32 w;
    V3 pos;
    void (*f1c)(void);
    u32 f20;
} Desc;

typedef struct Src { u32 f0; V3 v; } Src;

typedef struct Res_021C48A0 {
    u32 f0;
    u16 h4;
    u16 h6;
} Res_021C48A0;

typedef struct Head { u8 pad[4]; u32 f4; u16 h8; } Head;

typedef struct {
    u32 *p;
    u16 id;
} S_021C4938;

typedef struct {
    void *owner;
    u32 obj;
    u32 f8;
} R_021C4978;

typedef signed int     s32;

typedef struct P_021C49C0 { u32 f0; u32 f4; u16 f8; } P_021C49C0;

typedef struct {
    u32 f0;
    u32 obj;
    u16 id;
} S_021C4A00;

typedef struct S_021C49C0 { u32 w0; u8 b4, b5, b6, b7; u32 w8; } S_021C49C0;

typedef struct {
    u32 a;
    u32 b;
} P2_021C4A10;

typedef struct Pair { u32 f0; u32 f4; } Pair;

typedef struct Res_021C4A3C { Pair p; u16 h8; } Res_021C4A3C;

typedef struct {
    u32 *p;
    u32 f4;
    u16 id;
} S_021C4AE8;

typedef struct {
    void *owner;
    u32 f4;
} R_021C4B28;


typedef struct {
    u32 owner;
    u16 h4;
    u16 h6;
} S_021C4BC4;

typedef struct { int a; int b; } S_021C4C0C;

typedef struct {
    u32 *owner;
    u32 f4;
    u32 f8;
    u32 fC;
    u16 id;
} S_021C4CDC;

typedef signed short   s16_021C48A0;

typedef signed char    s8;

typedef struct {
    u16 heap;
    u16 pad;
    void *owner;
    u32 f8;
    u32 fC;
    u32 task;
    V3 *pos;
} R_021C4E08;

typedef int            s32_021C4E6C;

typedef struct { u16 x; u16 y; u16 z; u8 a; u8 b; } Pos;

typedef signed int     s32_021C4F7C;

typedef struct {
    u32 f0;
    void *msg;
    u8 pad8[0x1C];
    u32 f24;
    u32 h[3];
    u16 h34;
    u16 pad36;
    u8 pad38[8];
    u32 f40;
} S_021C5440;

typedef struct {
    void *arr;
    void *cb04;
    void *cb08;
    u32 w0c;
    u16 count;
    u16 rows;
    u8 f14[8];
    void *w1c;
    u16 h20;
    u16 h22;
    u32 w24;
    void *w28;
    u32 w2c;
    u32 w30;
} Tmpl;

typedef signed short   s16_021C59A8;

typedef short s16_021C59F8;

typedef struct {
    s16_021C59F8 x;
    s16_021C59F8 y;
} P2_021C59F8;

struct Work_021C5AAC {
    void *a;
    void *f04;
    int *f08;
    int f0C;
    int f10;
    int f14;
};

typedef struct {
    void *owner;
    void *f4;
    u32 f8;
    u16 hC;
    u16 pad;
    u32 f10;
} W;

typedef struct {
    int f0;
    int f4;
    u16 f8[3];
    u16 fE;
    u16 *f10;
} Arg;

typedef short s16_021C577C;

typedef int fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct {
    void *f0;
    void *f4;
    u8 *f8;
    void *fC;
    u32 f10;
    void *f14;
    void *f18;
    void *f1C;
    s16_021C577C f20[3];
    u16 pad26;
    u32 f28;
    u8 pad2C[8];
    VecFx32 f34;
    VecFx32 f40;
    u8 pad4C[0xC];
    u8 f58;
    u8 f59;
    u16 f5A;
    u8 pad5C[8];
    void *f64;
} Work_021C5D10;

typedef struct {
    void *f0;
    void *f4;
    u8 *f8;
    void *fC;
    u32 f10;
    void *f14;
    u32 f18;
    u32 f1C;
    u8 pad20[0x39];
    u8 f59;
    u16 f5A;
    u32 f5C;
    u32 f60;
    void *f64;
} Work_021C5DF4;

extern int func_021AC1AC(u32 a);
extern void func_021AC1CC(int a, int *v);
extern u16 func_02050340(struct BbActSys *o, u16 base, const struct BbActDesc *d, u32 count, u32 mode);
extern void func_021AC154(u32 a);
extern void func_02050804(void *p, int idx, u32 v, u16 h);
extern void func_0205082C(void *p, int idx, u32 h);
extern void func_020507F0(void *p, int idx, u32 v);
extern void func_02050468(struct BbActSys *o, u16 first, u32 count);
extern u32 func_020508EC(u8 *p, int i, u16 *out);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021ABE14(u8 *p);
extern u32 func_02188C90(u8 *p);
extern u32 func_020307B0(void *p);
extern u32 func_021ABE24(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern void func_021AC1F0(struct X *x, void *b);
extern u16 func_020500F0(struct BbActSys *o, const struct BbActRec *recs, u32 n);
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(void *a, void *fn, u32 c, u32 d, P2_021C4A10 *e, u32 f);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern u32 func_021ABE18(unsigned char *p);
extern void func_021C6AE0(u32 a);
extern int func_021C6AF0(u32 a, u32 b, u32 c);
extern void func_021C6AF8(u32 *a, u32 b);
extern void func_021C6AFC(u32 *a, u32 b);
extern int func_021C6574(u32 a, u32 b, u32 c);
extern u16 func_021C6590(u32 a, u32 b, u32 c, u32 d);
extern void func_021C67D8(u32 a, u32 b, u32 c);
extern void func_021C6628(u32 o, u16 v);
extern void func_021C6580(u8 *p, int i);
extern int func_0216E1A4(int a0, int a1);
extern int func_0216E1C4(int a0, int a1);
extern int func_0216DBE8(void *a0);
extern int func_021C6658(u32 a, u32 b);
extern int func_021C6844(int a, int b);
extern int func_021C66EC(u32 *a, int idx, int v);
extern void func_021C6828(int a, int b, int c);
extern void func_021AC1B8(void *a, V3 *v);
extern void func_021C67F4(u32 o, u16 id);
extern u16 func_02188C84(u8 *p);
extern void *func_02188C80(void *p);
extern u32 func_02012134(u32 *p);
extern u32 func_0202B57C(void *obj);
extern int func_0202B928(int a, int b);
extern void func_0202B920(void *m, int i, int a, int b);
extern void func_02011558(struct IcaAnime *p);
extern void *func_02011510(u32 heap, u32 a1, u32 a2, u32 a3);
extern u32 func_02011590(struct IcaAnime *p, s32 v);
extern void func_020115EC(struct IcaAnime *p, s32 v);
extern u32 func_0201160C(struct Obj11245 *p);
extern u32 func_02011610(struct IcaAnime *t, struct Rec12 *v);
extern void func_0202B934(u32 a, u32 b, V3 *v);
extern u32 func_02011638(struct IcaAnime *ctx, struct Rec12 *hsv);
extern void func_0207ADC4(void *p);
extern void func_020520FC(int h, int s, int v, struct Mtx33 *out);
extern u32 func_02082BCC(void *p, int v, int n);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414AC(int);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern s32_021C4F7C func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32_021C4F7C func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021C4F7C func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02049238(void *);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, u16, u16);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B92C(struct Obj *obj, unsigned int v);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void *func_0201C450(u16 n, u32 heap);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C40C(void *sys);
extern void func_02041B6C(u32 bit);
extern void func_0207D63C(int, int, int, int, int);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0204B3B4(struct Obj *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern void func_020061E4(u32 se);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void func_02030EAC(struct Node *n);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern unsigned char func_02045730(struct Descriptor *d);
extern void func_020409B4(unsigned int index);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_02020350(struct Obj *obj, u32 what);
extern void func_020202FC(struct Obj *obj, u16 *a, u16 *b);
extern u16 func_02020324(struct Obj *obj, u32 n);
extern void func_020355D8(u8 v);
extern void func_020202EC(struct Obj *obj, u16 *out);
extern unsigned int func_0203633C(void);
extern u32 func_020362DC(void);
extern s32 func_020200CC(struct Obj *o);
extern u32 func_02020344(struct Obj *obj, u32 n);
extern u8 func_0200C480(u8 *a, int id, u8 pos);
extern void *func_02045770(struct Descriptor *p);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern u16 func_02020314(struct Obj *obj);
extern u16 func_0200C468(const u8 *a);
extern u8 func_0200C464(const u8 *a, u32 i);
extern void *func_0201F81C(int n, u32 heap);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern struct Obj *func_0201FF30(struct Src *src, u16 a, u16 b, u32 heap);
extern u32 func_0201F868(void *p);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
extern void *func_020146F8(char *a0, int a1, int a2, int a3, int a4);
extern void *func_02014728(char *a0, int a1, int a2, int a3, int a4);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *a);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void *func_0200C0F0(void *a);
extern u32 func_02017E1C(void *a, u32 b, u32 c);
extern int *func_0216BFD4(int a, int b, int c, int d, int e, int f, void *g);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern int func_0216C0C0(int a0);
extern u32 func_02188C98(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern u16 func_0216D5F8(void *p);
extern void func_021A3364(u32 *a, int b, int *out);
extern u32 func_02188CFC(u8 *p);
extern int func_0218DAEC(u32 a, int *b, u32 *out);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB2E8(int id);
extern int func_021AB3B0(u16 id);
extern void func_02164208(int dir, int *p, int amt);
extern u32 func_02188CE8(u8 *p);
extern void *func_02188C7C(u8 *q);
extern void func_021A3038(unsigned char *id, struct VecFx32 *out);
extern int func_021A34EC(u8 *p);
extern int func_021AA900(struct Self *self, short *pos);
/* Retain the mode used to store f59 for the helper's second argument. */
extern struct Obj *func_021AA180(struct Ctx *ctx, int mode);
extern void func_0216D9A0(void *o);
extern void func_021A2F48(u8 *p, u32 a1);
extern int func_021A2F54(u8 *p);
extern void func_0216D674(void *p, u16 v);
extern int func_021C5FA8(Work_021C5DF4 *w, u32 n);
extern void func_021C602C(u8 *p);
extern u32 func_02005728(u32 v);
extern int func_021C5FC0(u8 *p, u32 lim);
extern void func_021C5FEC(u8 *p);
extern void func_021C6018(u32 *p);
extern void func_021C6054(u32 *p);
extern int func_02158780(void *p, u16 b, int c, int d, u16 e);
extern void func_021AA8EC(u8 *p);
extern int func_020130B4(int a0);
extern int func_0216E7C8(int a0, int a1, int a2, int a3, int a4);
extern void func_0201235C(struct S0201235C *o, u32 *out);
void func_021C48A0(u32 a, Res_021C48A0 *r);
void func_021C4938(void *a, S_021C4938 *s);
void func_021C4954(void *a, S_021C4938 *s);
void func_021C4974(void);
R_021C4978 *func_021C4978(u8 *owner, u32 heap);
void func_021C49AC(u32 a, u8 *p);
void func_021C49C0(P_021C49C0 *p);
void func_021C4A00(S_021C4A00 *s);
void func_021C4A10(void *a, u32 b);
void func_021C4A3C(u32 a, Res_021C4A3C *r);
void func_021C4AE8(void *a, S_021C4AE8 *s);
void func_021C4B04(void *a, S_021C4AE8 *s);
void func_021C4B24(void);
R_021C4B28 *func_021C4B28(void *owner, u32 heap);
void func_021C4B50(u32 a, u8 *p);
void func_021C4B64(Res_021C48A0 *p);
void func_021C4BC4(S_021C4BC4 *s);
void func_021C4BE0(void *a, u32 b);
void func_021C4C0C(int a, int *b);
void func_021C4C50(void);
void func_021C4C54(int a, int *b);
void func_021C4CDC(void *a, S_021C4CDC *s);
void *func_021C4D14(int a, int b, int c, int d, int e);
R_021C4E08 *func_021C4D7C(void *owner, u32 v);
int func_021C4DA8(void *a);
void func_021C4DC0(R_021C4E08 *r, u32 a, u32 b, u32 c);
u32 func_021C4DE4(R_021C4E08 *r, s32 dv);
void func_021C4E08(R_021C4E08 *r, s32 frame);
u32 func_021C4E20(R_021C4E08 *r);
void func_021C4E34(R_021C4E08 *r);
void func_021C4E6C(char *p);
char *func_021C4F7C(void *a0, int mode, const u16 *a2, u16 a3, u16 heap);
void func_021C51A0(int *a);
void func_021C5224(char *p);
int func_021C5334(u32 a);
void func_021C5348(u8 *p);
void func_021C536C(u8 *p);
int func_021C5380(u8 *p);
u32 func_021C5394(u8 *p, u32 *out);
void func_021C53A0(int *a, const u16 *b, u32 c, u32 d, u32 e, u32 f, int *g, u16 h);
int func_021C5424(u32 a, u32 b);
void func_021C5440(S_021C5440 *p, int mode, u32 c, u32 *done);
void func_021C54C8(int *a, int b, int c, int *d);
void func_021C553C(char *p);
int func_021C56F8(int *a);
int func_021C5768(char *p);
void func_021C576C(void *a);
void func_021C577C(void *list, int a0, int a1);
void func_021C5880(u16 *a, u16 *b, u16 c);
void func_021C58CC(char *p, u16 a, u16 b, u32 heap);
int func_021C59A8(u32 a, u32 b, u32 c);
void func_021C59BC(void *a, u8 *p);
void func_021C59F8(S_021C5440 *p, int v);
void *func_021C5A28(void *a, u32 b, u32 c, u32 d);
int func_021C5A54(int a, int *st, int *c);
int func_021C5AAC(void *a, int b, int c, int d);
int func_021C5B58(int a, int *st, int *c);
void *func_021C5BD0(void *a, u32 b, u32 c);
int func_021C5C08(void *a, int *st, Arg *p);
int func_021C5C64(u32 unused, u32 a, u32 *out);
void *func_021C5D10(struct Obj00020 *a, void *b);
int func_021C5DF4(void *task, int *state, Work_021C5DF4 *w);
extern u8 d_021DE464[];
extern char d_021DE47C[];
extern char d_021DAA2C[];
extern u8 d_021DE478[];
extern char d_021DAA18[];
extern char d_021DE48C[];
extern char d_021DE498[];
extern const u32 d_021DAA60[];
extern const u32 d_021DAA54[];
extern const Tmpl d_021DAA80;
extern char d_021F5580;
extern unsigned char abs_id_C2[];
extern char d_021DEA44[];
extern char ov171_id[];









/*
 * func_0205082C and func_020507F0 are witnessed by
 * src/matched/arm9/func_0205082C.c and src/matched/arm9/func_020507F0.c.
 */
void func_021C48A0(u32 a, Res_021C48A0 *r)
{
    Src *s = (Src *)func_021AC1AC(a);
    Head *h;
    u32 t, k;
    Desc d;

    r->f0 = s->f0;
    func_021AC1CC(a, (int *)&s->v);
    h = (Head *)r->f0;
    t = h->f4;
    d.slot = h->h8;
    d.v12 = 0x1000;
    d.v14 = 0x1000;
    d.k = 0x1f;
    d.flag = 1;
    d.w = 1;
    d.pos = s->v;
    d.f1c = 0;
    d.f20 = (u32)r;
    r->h4 = func_02050340((struct BbActSys *)t, 0, (const struct BbActDesc *)(&d), 1, 3);
    if (r->h4 == 0xFFFF) {
        func_021AC154(a);
        return;
    }
    func_02050804((void *)t, r->h4, (u32)d_021DE464, 1);
    k = r->h4;
    func_0205082C((void *)t, k, 0);
    func_020507F0((void *)t, k, 1);
}










/*
 * Sets flag 1 on the field object unless the id is 0xFFFF.
 */
void func_021C4938(void *a, S_021C4938 *s)
{
    u32 x = s->p[1];

    if (s->id != 0xFFFF)
        func_02050468((struct BbActSys *)x, s->id, 1);
}










void func_021C4954(void *a, S_021C4938 *s)
{
    u32 tmp;

    if (func_020508EC((u8 *)s->p[1], s->id, (u16 *)(&tmp)) != 0)
        func_021AC154((u32)a);
}








void func_021C4974(void) {}








/*
 * Allocates the 0xC-byte field-object record (second kind) and initialises
 * it.
 */
R_021C4978 *func_021C4978(u8 *owner, u32 heap)
{
    R_021C4978 *r = func_02030734(heap, 0xC, 1, d_021DE47C, 0x7D);

    r->owner = owner;
    r->obj = func_02188C90((u8 *)func_021ABE14(owner));
    func_021C49C0((P_021C49C0 *)r);
    return r;
}








/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021C49AC(u32 a, u8 *p)
{
    func_021C4A00((S_021C4A00 *)p);
    func_020307B0(p);
}













void func_021C49C0(P_021C49C0 *p)
{
    S_021C49C0 s;
    u32 x = func_021ABE24((u8 *)p->f0);

    s.b4 = 2;
    s.b5 = 0x13;
    s.b6 = 0x10;
    s.b7 = 0x10;
    s.w8 = 1;
    s.w0 = (u32)func_02046E24(x, 0x2d);
    func_021AC1F0((struct X *)p->f0, (void *)s.w0);
    p->f8 = func_020500F0((struct BbActSys *)p->f4, (const struct BbActRec *)(&s), 1);
}













void func_021C4A00(S_021C4A00 *s)
{
    func_02050278((struct BbActSys *)s->obj, s->id, 1);
}













/*
 * Queues callback d_021DAA2C with a two-word argument block.
 */
void func_021C4A10(void *a, u32 b)
{
    P2_021C4A10 t;

    t.a = func_021ABEA0((u32)a, 8);
    t.b = b;
    func_021ABFA8(a, d_021DAA2C, 0, 0, &t, 0);
}













/*
 * Spawns the field effect object above the owner's position and starts it.
 */
void func_021C4A3C(u32 a, Res_021C4A3C *r)
{
    Pair *s = (Pair *)func_021AC1AC(a);
    Head *h;
    u32 t, k;
    V3 pos;
    Desc d;

    r->p = *s;
    func_0216D88C((const struct Actor *)r->p.f4, (struct VecFx32 *)&pos);
    h = (Head *)r->p.f0;
    t = h->f4;
    pos.y -= 0xE000;
    pos.z -= 0xA000;
    d.slot = h->h8;
    d.v12 = 0x1000;
    d.v14 = 0x1000;
    d.k = 0x1f;
    d.flag = 1;
    d.w = 1;
    d.pos = pos;
    d.f1c = 0;
    d.f20 = (u32)r;
    r->h8 = func_02050340((struct BbActSys *)t, 0, (const struct BbActDesc *)(&d), 1, 3);
    if (r->h8 == 0xFFFF) {
        func_021AC154(a);
        return;
    }
    func_02050804((void *)t, r->h8, (u32)d_021DE478, 1);
    k = r->h8;
    func_0205082C((void *)t, k, 0);
    func_020507F0((void *)t, k, 1);
}













/*
 * Sets flag 1 on the field object unless the id is 0xFFFF.
 */
void func_021C4AE8(void *a, S_021C4AE8 *s)
{
    u32 x = s->p[1];

    if (s->id != 0xFFFF)
        func_02050468((struct BbActSys *)x, s->id, 1);
}











/*
 * Notifies the owner when the field-object query succeeds (EXACT*:
 * follower).
 */
void func_021C4B04(void *a, S_021C4AE8 *s)
{
    u32 tmp;

    if (func_020508EC((u8 *)s->p[1], s->id, (u16 *)(&tmp)) != 0)
        func_021AC154((u32)a);
}










void func_021C4B24(void) {}










/*
 * Allocates the 8-byte record and initialises it.
 */
R_021C4B28 *func_021C4B28(void *owner, u32 heap)
{
    R_021C4B28 *r = func_02030734(heap, 8, 1, d_021DE47C, 0x163);

    r->owner = owner;
    func_021C4B64((Res_021C48A0 *)((struct Res_021C48A0 *)r));
    return r;
}











/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021C4B50(u32 a, u8 *p)
{
    func_021C4BC4((S_021C4BC4 *)p);
    func_020307B0(p);
}











void func_021C4B64(Res_021C48A0 *p)
{
    u32 buf[9];
    u32 x = func_021ABE18((unsigned char *)p->f0);
    u32 y = func_021ABE24((u8 *)p->f0);

    func_021C6AE0((u32)buf);
    func_021C6AF0((u32)buf, y, 0x5f);
    func_021C6AF8(buf, y);
    func_021C6AFC(buf, 0x6a);
    p->h4 = func_021C6574(x, (u32)buf, 0);
    p->h6 = func_021C6590(x, p->h4, 0, 0);
    func_021C67D8(x, p->h6, 1);
}









/*
 * Applies the record's two parameters to the owner's map object.
 */
void func_021C4BC4(S_021C4BC4 *s)
{
    u32 o = func_021ABE18((unsigned char *)s->owner);

    func_021C6628(o, s->h6);
    func_021C6580((u8 *)o, s->h4);
}









/*
 * Queues callback d_021DAA18 with a two-word argument block.
 */
void func_021C4BE0(void *a, u32 b)
{
    P2_021C4A10 t;

    t.a = func_021ABEA0((u32)a, 0x11);
    t.b = b;
    func_021ABFA8(a, d_021DAA18, 0, 0, &t, 0);
}









void func_021C4C0C(int a, int *b)
{
    int v[3];
    int *p = (int *)func_021AC1AC(a);

    *(S_021C4C0C *)b = *(S_021C4C0C *)p;
    func_0216E1A4(b[1], (int)(b + 2));
    func_0216D88C((const struct Actor *)b[1], (struct VecFx32 *)v);
    v[2] += 0x8000;
    func_021AC1CC(a, v);
    ((struct Obj07561 *)b)->f10 = *(u16 *)(b[0] + 6);
}







void func_021C4C50(void) {}







void func_021C4C54(int a, int *b)
{
    int v[3];
    int h;
    int r;

    if (func_0216E1C4(b[1], (int)(b + 2)) == 0) {
        func_021AC154(a);
        return;
    }
    if (func_0216DBE8((void *)b[1]) == 0) {
        func_021AC154(a);
        return;
    }
    h = ((struct Obj06076 *)b)->f10;
    r = func_021ABE18((u8 *)(*(int *)b[0]));
    func_021C6658(r, h);
    if (func_021C6844(r, h) == 0) {
        func_021C66EC((u32 *)r, h, 0x1000);
        func_021C6828(r, h, 1);
    }
    func_0216D88C((const struct Actor *)b[1], (struct VecFx32 *)v);
    v[2] += 0x8000;
    func_021AC1CC(a, v);
}







/*
 * Copies the owner's current position into map-object slot id.
 */
void func_021C4CDC(void *a, S_021C4CDC *s)
{
    u16 id = s->id;
    u32 o = func_021ABE18((u8 *)(*s->owner));
    V3 *dst = (V3 *)func_021C6658(o, id);
    V3 t;

    func_021AC1B8(a, &t);
    *dst = t;
    func_021C67F4(o, id);
}






void *func_021C4D14(int a, int b, int c, int d, int e)
{
    int n = func_02188C84((u8 *)a);
    int r;
    int *p;

    r = func_0202B57C((void *)func_02012134((u32 *)func_02188C80((void *)a)));
    p = (int *)func_02030734(n, 0x18, 0, d_021DE48C, 0x3c);
    ((struct Obj01507 *)p)->f0 = n;
    p[1] = a;
    p[2] = r;
    p[3] = c;
    p[4] = 0;
    p[5] = b;
    if (func_0202B928(r, c) == 0) {
        func_0202B920((void *)r, c, d, e);
    }
    return p;
}






/*
 * Allocates the 0x18-byte script-runner record.
 */
R_021C4E08 *func_021C4D7C(void *owner, u32 v)
{
    u32 heap = func_02188C84(owner);
    R_021C4E08 *r = func_02030734(heap, 0x18, 0, d_021DE48C, 0x61);

    r->heap = heap;
    r->owner = owner;
    r->f8 = 0;
    r->task = 0;
    r->pos = (V3 *)v;
    return r;
}







int func_021C4DA8(void *a)
{
if (((struct Obj12132 *)((u8 *)(a)))->f10 != 0) {
    func_02011558((struct IcaAnime *)(((struct Obj12132 *)((u8 *)(a)))->f10));
}
return func_020307B0(a);
}







/*
 * Restarts the record's task with new arguments.
 */
void func_021C4DC0(R_021C4E08 *r, u32 a, u32 b, u32 c)
{
    if (r->task != 0)
        func_02011558((struct IcaAnime *)r->task);
    r->task = (u32)func_02011510(r->heap, a, b, c);
}





u32 func_021C4DE4(R_021C4E08 *r, s32 dv)
{
    u32 v;

    if (r->task == 0)
        return 0;
    v = func_02011590((struct IcaAnime *)r->task, dv);
    func_021C4E34(r);
    func_021C4E6C((char *)r);
    return v;
}









/*
 * Stops the record's task and syncs the final position (EXACT*: pad).
 */
void func_021C4E08(R_021C4E08 *r, s32 frame)
{
    if (r->task != 0) {
        func_020115EC((struct IcaAnime *)r->task, frame);
        func_021C4E34(r);
    }
}










/*
 * Returns the task's status word, 0 without a task (EXACT*: pad).
 */
u32 func_021C4E20(R_021C4E08 *r)
{
    if (r->task == 0)
        return 0;
    return func_0201160C((struct Obj11245 *)r->task);
}










static inline void V3_Set(V3 *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}










/*
 * Syncs the task's current position into the target and its map object.
 */
void func_021C4E34(R_021C4E08 *r)
{
    V3 t;

    if (r->task != 0 && func_02011610((struct IcaAnime *)r->task, (struct Rec12 *)&t) == 1) {
        V3_Set(r->pos, t.x, t.y, t.z);
        if (r->f8 != 0)
            func_0202B934(r->f8, r->fC, &t);
    }
}










/*
 * Same HSV-to-RGB shape as arm9 func_02011B8C: three 4.12 channels from
 * func_02011638, wrapped into [0,360), rescaled to 0..65535, handed to
 * func_020520FC.
 */
void func_021C4E6C(char *p)
{
    s32_021C4E6C hsv[3];
    u16 ch;
    u16 cs;
    u16 cv;
    float h;
    float s;
    float v;

    if (((struct Obj01666 *)p)->f10 == 0) {
        return;
    }
    if (func_02011638(((struct Obj01666 *)p)->f10, (struct Rec12 *)hsv) != 1) {
        return;
    }

    h = hsv[0] / 4096.0f;
    s = hsv[1] / 4096.0f;
    v = hsv[2] / 4096.0f;

    while (h < 0.0f) {
        h += 360.0f;
    }
    while (s < 0.0f) {
        s += 360.0f;
    }
    while (v < 0.0f) {
        v += 360.0f;
    }

    ch = (u16)(u32)(65535.0f * (h / 360.0f));
    cs = (u16)(u32)(65535.0f * (s / 360.0f));
    cv = (u16)(u32)(65535.0f * (v / 360.0f));
    func_0207ADC4(*(char * *)&((struct Obj01666 *)p)->f14 + 0x18);
    func_020520FC(ch, cs, cv, (struct Mtx33 *)(*(char * *)&((struct Obj01666 *)p)->f14 + 0x18));
}










/*
 * The heap id is a u16 stack parameter, and the callees it feeds take a u16
 * heap too (docs/idioms/narrow-stack-parameters-and-callee-prototype-free-
 * the-narrow-home-store.md): only then does the u16 a3's home store
 * `str r3, [sp, #0x18]` lead the prologue. With u32 heap it sank below
 * `ldr r7, [sp, #0x40]; str r0, [sp, #0x10]` (6 bytes). pos.y = 0x60 is
 * written once before the loop, and the element address is spelled
 * p + i * 4 + 0x58 (r6 = p + i*4 shared with the table index).
 */
char *func_021C4F7C(void *a0, int mode, const u16 *a2, u16 a3, u16 heap)
{
    Pos pos;
    int x;
    char *p;
    void *arc;
    int i;

    i = 0;
    p = func_02030734(heap, 0x88, 0, d_021DE498, 0xFC);
    func_02082BCC(p, 0, 0x88);
    ((struct Obj00960 *)p)->f74 = 0;
    ((struct Obj00960 *)p)->f78 = 25;
    *(const u16 * *)&((struct Obj00960 *)p)->f7C = a2;
    func_0203FCA0(1, (const struct BgTemplate *)d_021DAA60, 0);
    func_020414AC(1);
    func_02040C14(1, 0, 1, 0);
    ((struct Obj00960 *)p)->f4C = (u32)func_0204B100(8, 0, heap);
    x = 0x80;
    arc = func_020490F4(0x80, heap);
    func_02049B68(arc, 0, 0, x + 0xE0, 0x40, heap);
    ((struct Obj00960 *)p)->f50 = func_0204ABF0(arc, 4, 0, 0x40, heap);
    ((struct Obj00960 *)p)->f52 = func_0204A6C8(arc, 3, 0, 0, heap);
    ((struct Obj00960 *)p)->f54 = func_0204AF28(arc, 2, 1, heap);
    x += 0xC0;
    func_02049B68(arc, 6, 0, x, 0x20, heap);
    func_02049658(arc, 5, 1, 0, 0, 0, heap);
    func_020498F4(arc, 7, 1, 0, 0, 0, heap);
    func_020413B0(1, 0, 11, 32, 1, 10);
    func_02049238(arc);
    func_02082BCC(&pos, 0, 8);
    pos.y = 0x60;
    for (i = 0; i < 3; i++) {
        pos.z = i;
        pos.x = d_021DAA54[i];
        *(u32 *)(p + i * 4 + 0x58) = (u32)func_0204B294((void *)((struct Obj00960 *)p)->f4C, ((struct Obj00960 *)p)->f52,
            ((struct Obj00960 *)p)->f50, ((struct Obj00960 *)p)->f54, &pos, 0, heap);
        func_0204B3DC((struct Obj *)*(u32 *)(p + i * 4 + 0x58), 0);
        func_0204B92C((struct Obj *)*(u32 *)(p + i * 4 + 0x58), 1);
    }
    ((struct Obj00960 *)p)->f64 = (u32)func_02045B38(0, 2, 0xAD, heap);
    ((struct Obj00960 *)p)->f68 = (u32)func_0201D7EC(0x17, 0, 0, 0, a3);
    ((struct Obj00960 *)p)->f6C = (u32)func_0201C450(0x1000, heap);
    func_021C53A0((int *)p, *(const u16 * *)&((struct Obj00960 *)p)->f7C, ((struct Obj00960 *)p)->f64, ((struct Obj00960 *)p)->f68,
        ((struct Obj00960 *)p)->f6C, (u32)func_0200C40C(func_02012EBC(a0)), (int *)(p + 0x58), a3);
    func_02041B6C(1);
    func_0207D63C(0x04000050, 2, 1, 12, 4);
    switch (mode) {
    case 0:
        func_02040618(1, 3, -0xC0);
        func_02040588(1, 0);
        ((struct Obj00960 *)p)->f70 = 0;
        break;
    case 1:
        func_02040618(1, 3, 0);
        func_02040588(1, 1);
        ((struct Obj00960 *)p)->f70 = 3;
        break;
    }
    return p;
}









void func_021C51A0(int *a)
{
    int i = 0;

    *(volatile u16 *)0x04000050 = 0;
    func_02040588(1, 0);
    func_021C5424((int)a, a[0x7c / 4]);
    for (i = 0; i < 3; i++) {
        func_0204B3B4((struct Obj *)a[0x58 / 4 + i]);
    }
    func_0201C6EC((struct PrintSys *)a[0x6c / 4]);
    func_0201C4C0((struct PrintSys *)a[0x6c / 4]);
    func_0201D83C((void *)a[0x68 / 4]);
    func_02045C04((struct Rec *)a[0x64 / 4]);
    func_0204ADA4(((struct Obj00020 *)a)->f50);
    func_0204A8D4(((struct Obj00020 *)a)->f52);
    func_0204AFD8(((struct Obj00020 *)a)->f54);
    func_0204B1CC((struct Bank *)a[0x4c / 4]);
    func_02040DA8(1, 1, 0);
    func_020403F4(1);
    func_020307B0((void *)((int)a));
}









void func_021C5224(char *p)
{
    int r;
    int i;

    if (func_021C5334((u32)p) == 0) {
        return;
    }
    switch (((struct Obj01216 *)p)->f70) {
    case 0:
        break;
    case 1:
        func_020061E4(0x54C);
        ((struct Obj01216 *)p)->f72 = 0;
        ((struct Obj01216 *)p)->f80 = 0;
        ((struct Obj01216 *)p)->f84 = func_020056A0((void *)func_021C59BC, p, 0);
        ((struct Obj01216 *)p)->f70 = 2;
        break;
    case 2:
        if (((struct Obj01216 *)p)->f80 != 0) {
            func_02030EAC(((struct Obj01216 *)p)->f84);
            ((struct Obj01216 *)p)->f70 = 3;
        }
        break;
    case 3:
        func_021C553C(p);
        r = func_021C5768(p);
        switch (r) {
        case -1:
            ((struct Obj01216 *)p)->f74 = 0;
            break;
        case -2:
            ((struct Obj01216 *)p)->f74 = 2;
            break;
        default:
            ((struct Obj01216 *)p)->f74 = 1;
            ((struct Obj01216 *)p)->f78 = r;
            break;
        }
        break;
    case 4:
        for (i = 0; i < 3; i++) {
            func_0204B3DC((struct Obj *)*(u32 *)(p + 0x58 + i * 4), 0);
        }
        ((struct Obj01216 *)p)->f72 = 4;
        ((struct Obj01216 *)p)->f70 = 5;
        break;
    case 5:
        func_02040618(1, 3, ((struct Obj01216 *)p)->f72 * 0xC0 / 4 - 0xC0);
        if ((((struct Obj01216 *)p)->f72)-- == 0) {
            ((struct Obj01216 *)p)->f70 = 0;
        }
        break;
    }
}









int func_021C5334(u32 a)
{
func_0201C4E4((struct PrintSys *)(((struct Obj18304 *)((u8 *)(a)))->f6C));
return func_021C56F8((int *)a);
}









/*
 * Starts the fade sequence once (state 0 to 1).
 */
void func_021C5348(u8 *p)
{
    if (((struct Obj07562 *)p)->f70 == 0) {
        ((struct Obj07562 *)p)->f74 = 0;
        ((struct Obj07562 *)p)->f78 = 0x19;
        func_02040588(1, 1);
        ((struct Obj07562 *)p)->f70 = 1;
    }
}









/*
 * Advances the sequence from state 3 to 4 (EXACT*: pad).
 */
void func_021C536C(u8 *p)
{
    if (((struct Obj12940 *)p)->f70 == 3)
        ((struct Obj12940 *)p)->f70 = 4;
}









/*
 * Returns 1 in states 2 and 5.
 */
int func_021C5380(u8 *p)
{
    int r = 1;

    if (((struct Obj12941 *)p)->f70 != 2 && ((struct Obj12941 *)p)->f70 != 5)
        r = 0;
    return r;
}









/*
 * Returns the result word and optionally its argument.
 */
u32 func_021C5394(u8 *p, u32 *out)
{
    if (out != 0)
        *out = ((struct Obj12942 *)p)->f78;
    return ((struct Obj12942 *)p)->f74;
}







void func_021C53A0(int *a, const u16 *b, u32 c, u32 d, u32 e, u32 f, int *g, u16 h)
{
    int i = 0;
    int r;

    func_02082BCC(a, 0, 0x4c);
    a[3] = e;
    a[8] = f;
    ((struct Obj00874 *)a)->f34 = h;
    a[0xe] = c;
    a[0xf] = d;
    for (i = 0; i < 3; i++) {
        a[0xa + i] = g[i];
    }
    r = func_020450F0(1, 1, 0xc, 0x1e, 0xc, 0xb, 1);
    a[2] = r;
    func_02045334((struct Descriptor *)r);
    func_02045374((struct Cfg *)r);
    func_020409B4(func_02045730((struct Descriptor *)r));
    a[4] = a[2];
    ((struct Obj00874 *)a)->f14 = 0;
    func_021C58CC((char *)a, b[0], b[1], h);
}







/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C5424(u32 a, u32 b)
{
func_021C59A8(a, b, (b + 2));
func_020452E8((struct Descriptor *)(((struct Obj18305 *)((u8 *)(a)))->f8));
return func_02082BCC((void *)a, 0, 76);
}







/*
 * Message-window step: opens the window and plays SE 0x548, or scrolls to
 * the cursor line. Load-bearing: int-typed line count (stops (c-1)-(n-1)
 * folding) and the u16 local for the line index.
 */
void func_021C5440(S_021C5440 *p, int mode, u32 c, u32 *done)
{
    int n;
    u16 tmp;
    u16 h;

    if (mode == 0) {
        n = func_02020350(p->msg, 3);
        func_021C59A8((u32)p, 0, 0);
        func_021C58CC((char *)p, (c - 1) - (n - 1), n - 1, p->h34);
        if (p->f24 == 1)
            p->f40 = 1;
        func_020061E4(0x548);
        *done = 1;
    } else if (p->f40 == 1 && p->f24 == 1) {
        func_020202FC(p->msg, 0, &tmp);
        h = func_02020324(p->msg, tmp) >> 3;
        func_021C59F8(p, (h + 0xC) * 8);
        p->f40 = 0;
        *done = 1;
    }
}






void func_021C54C8(int *a, int b, int c, int *d)
{
    u16 v;
    u16 w;

    if (b == c - 1) {
        if (a[9] == 1) {
            func_020202FC((struct Obj *)a[1], 0, &v);
            w = func_02020324((struct Obj *)a[1], (u16)(v + 1)) >> 3;
            func_021C59F8((S_021C5440 *)a, (w + 0xc) << 3);
            a[16] ^= 1;
        }
        if (a[16] == 0) {
            func_021C59A8((u32)a, 0, 0);
            func_021C58CC((char *)a, 0, 0, ((struct Obj04281 *)a)->f34);
        }
        func_020061E4(0x548);
        *d = 1;
        return;
    }
    a[16] = 0;
}






void func_021C553C(char *p)
{
    int flag;
    u16 c[2];
    u16 b[2];
    u16 a[2];
    int redraw;
    int sel;
    u32 n;
    int i;

    sel = -1;
    redraw = 0;
    flag = 0;
    func_020355D8(0);
    func_020202EC(((struct Obj00523 *)p)->f4, &c[1]);
    n = func_02020350(((struct Obj00523 *)p)->f4, 2);
    if (func_0203633C() & 0x40) {
        func_021C5440((S_021C5440 *)p, c[1], n, (u32 *)&flag);
    } else if (func_0203633C() & 0x80) {
        func_021C54C8((int *)p, c[1], n, &flag);
    }
    if (flag == 0) {
        sel = func_020200CC(((struct Obj00523 *)p)->f4);
    }
    if (sel == -1) {
        if (func_020362DC() & 0x400) {
            sel = -2;
            func_020061E4(0x551);
        } else if (func_020362DC() & 0x800) {
            func_020202EC(((struct Obj00523 *)p)->f4, &c[0]);
            sel = func_02020344(((struct Obj00523 *)p)->f4, c[0]);
            func_020061E4(0x54C);
        } else if ((func_020362DC() & 4) && ((struct Obj00523 *)p)->f24 == 1) {
            func_020202EC(((struct Obj00523 *)p)->f4, &b[1]);
            sel = func_02020344(((struct Obj00523 *)p)->f4, b[1]);
            func_020061E4(0x54C);
        }
    }
    if (((struct Obj00523 *)p)->f24 == 0) {
        ((struct Obj00523 *)p)->f18 = sel;
    } else if (((struct Obj00523 *)p)->f24 == 1) {
        if (sel == -2) {
            redraw = 1;
        } else if (sel != -1) {
            sel = func_02020344(((struct Obj00523 *)p)->f4, (u16)(((struct Obj00523 *)p)->f1C + ((struct Obj00523 *)p)->f1E));
            func_020202EC(((struct Obj00523 *)p)->f4, &b[0]);
            if (((struct Obj00523 *)p)->f40 != 0) {
                sel = func_0200C480(((struct Obj00523 *)p)->f20, sel, 0xFF);
            } else {
                sel = func_0200C480(((struct Obj00523 *)p)->f20, sel, b[0]);
            }
            func_021C59A8((u32)p, (u32)(&a[0]), (u32)(&a[1]));
            if (b[0] - 1 == sel) {
                a[1]--;
            }
            func_021C58CC(p, a[0], a[1], ((struct Obj00523 *)p)->f34);
            redraw = 1;
        }
    }
    if ((func_020362DC() & 4) && ((struct Obj00523 *)p)->f24 == 0 && func_02020350(((struct Obj00523 *)p)->f4, 2) > 1) {
        func_020061E4(0x54C);
        redraw = 1;
    }
    if (redraw) {
        ((struct Obj00523 *)p)->f24 ^= 1;
        if (((struct Obj00523 *)p)->f24 == 0) {
            ((struct Obj00523 *)p)->f40 = 0;
            for (i = 0; i < 3; i++) {
                func_0204B3DC((struct Obj *)*(u32 *)(p + 0x28 + i * 4), 0);
            }
            func_021C577C(((struct Obj00523 *)p)->f4, 0, 0);
            return;
        }
        if (((struct Obj00523 *)p)->f24 == 1) {
            func_020202FC(((struct Obj00523 *)p)->f4, (u16 *)(p + 0x1C), (u16 *)(p + 0x1E));
            ((struct Obj00523 *)p)->f48 = 1;
        }
    }
}





int func_021C56F8(int *a)
{
    int r4 = a[3];
    int i;
    int r7;

    if (((struct Obj02094 *)a)->f14 != 0) {
        if (func_0201C6C4((struct PrintSys *)r4, (void *)((int)func_02045770((struct Descriptor *)a[4]))) == 0) {
            func_02045334((struct Descriptor *)a[4]);
            ((struct Obj02094 *)a)->f14 = 0;
        }
    }
    r7 = 1;
    if (((struct Obj02094 *)a)->f14 != 0) {
        r7 = 0;
    }
    if (r7 != 0) {
        if (a[0x11] != 0) {
            func_021C577C((void *)a[1], 0, 0);
            a[0x11] = 0;
        }
        if (a[0x12] != 0) {
            for (i = 0; i < 3; i++) {
                func_0204B3DC((struct Obj *)a[0xa + i], 1);
            }
            a[0x12] = 0;
        }
    }
    return r7;
}






/*
 * Unlabelled leaf (no lr save): returns the selection func_021C553C
 * stores at +0x18. Called from func_021C5224.
 */
int func_021C5768(char *p)
{
    return ((struct Obj20207 *)p)->f18;
}






/*
 * Raises the done flag on map object 0x13 (EXACT*: pad).
 */
void func_021C576C(void *a)
{
    *(u32 *)(func_02020350(a, 0x13) + 0x44) = 1;
}




void func_021C577C(void *list, int a0, int a1)
{
    u16 v[2];
    char *w;
    u16 x;
    u32 y;
    u32 s;
    u32 t;
    u32 d;
    u16 a;

    w = (char *)func_02020350(list, 0x13);
    x = func_02020314(list) >> 3;
    y = func_02020350(list, 9) >> 3;
    if (((struct Obj04282 *)w)->f24 == 0) {
        func_020413B0(1, 1, 12, 30, 12, 11);
        func_020413B0(1, 1, x + 12, 30, y, 12);
        func_020413B0(1, 0, 11, 32, 1, 10);
        func_02041B6C(1);
    } else if (((struct Obj04282 *)w)->f24 == 1) {
        func_020413B0(1, 1, 12, 30, 12, 11);
        func_020202FC(list, &v[1], &v[0]);
        s = func_02020350(list, 8);
        t = func_02020350(list, 9);
        d = ((struct Obj04282 *)w)->f1E + ((struct Obj04282 *)w)->f1C - v[1];
        s = s + d * t;
        func_020413B0(1, 1, (s >> 3) + 12, 30, y, 12);
        func_020413B0(1, 0, 11, 32, 1, 10);
        func_02041B6C(1);
    }
    if (((struct Obj04282 *)w)->f40 == 1) {
        a = func_02020350(((struct Obj04282 *)w)->f4, 3);
        a = func_02020324(((struct Obj04282 *)w)->f4, a) >> 3;
        func_021C59F8((S_021C5440 *)w, (a + 12) << 3);
    } else {
        func_021C59F8((S_021C5440 *)w, (x + 12) << 3);
    }
}




void func_021C5880(u16 *a, u16 *b, u16 c)
{
    int s = *a + *b;

    if (c <= 5) {
        *b = s;
        *a = 0;
        return;
    }
    if (s <= 3) {
        *b = s;
        *a = 0;
        return;
    }
    if (s <= (int)c - 2 && s > 3) {
        *a = s - 3;
        *b = 3;
        return;
    }
    if (s == (int)c - 1) {
        *a = s - 4;
        *b = 4;
    }
}




void func_021C58CC(char *p, u16 a, u16 b, u32 heap)
{
    Tmpl t;
    u32 n;
    u32 i;

    n = func_0200C468(((struct Obj00874 *)p)->f20);
    ((struct Obj00874 *)p)->f0 = func_0201F81C(n, heap);
    for (i = 0; i < n; i++) {
        u8 v = func_0200C464(((struct Obj00874 *)p)->f20, (u8)i);
        func_0201F878(((struct Obj00874 *)p)->f0, ((struct Obj00874 *)p)->f38, (int)v, (int)v, heap);
    }
    while (b + a >= n) {
        if (b != 0) {
            b--;
        } else if (a != 0) {
            a--;
        }
    }
    func_021C5880(&a, &b, n);
    t = d_021DAA80;
    t.arr = ((struct Obj00874 *)p)->f0;
    t.count = n;
    t.cb04 = (void *)func_021C576C;
    t.cb08 = 0;
    t.w0c = *(u32 *)&((struct Obj00874 *)p)->f8;
    t.w1c = p;
    t.w24 = ((struct Obj00874 *)p)->f38;
    t.w28 = p + 0x10;
    t.w2c = ((struct Obj00874 *)p)->fC;
    t.w30 = ((struct Obj00874 *)p)->f3C;
    ((struct Obj00874 *)p)->f4 = func_0201FF30((struct Src *)(&t), a, b, heap);
}





/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C59A8(u32 a, u32 b, u32 c)
{
func_0202020C((struct Obj *)(((struct Obj12133 *)((u8 *)(a)))->f4), (u16 *)b, (u16 *)c);
return func_0201F868((void *)(((struct Obj12133 *)((u8 *)(a)))->f0));
}





/*
 * Scroll step: slides the BG by 0xC0/4 per frame and flags the end after 4.
 */
void func_021C59BC(void *a, u8 *p)
{
    u16 n = ((struct Obj09688 *)p)->f72;
    int v = n * 0xC0 / 4 - 0xC0;

    (((struct Obj09688 *)p)->f72)++;
    if (n >= 4) {
        v = 0;
        ((struct Obj09688 *)p)->f80 = 1;
    }
    func_02040618(1, 3, v);
}





/*
 * Sets the y offset of the three sprite handles (EXACT*: pad). The split i =
 * 0; y = v; ordering is what schedules the zero before the sign extension.
 */
void func_021C59F8(S_021C5440 *p, int v)
{
    s16_021C59F8 y;
    int i;
    P2_021C59F8 t;

    i = 0;
    y = v;
    for (; i < 3; i++) {
        func_0204B454((struct Actor *)p->h[i], (struct PtS *)&t, 0);
        t.y = y;
        func_0204B404((struct Obj *)p->h[i], (const struct Vec2 *)(&t), 0);
    }
}





/*
 * Spawns the func_021C5A54 task with a four-word work area.
 */
void *func_021C5A28(void *a, u32 b, u32 c, u32 d)
{
    void *t = func_020122C0(a, 0, func_021C5A54, 0x10);
    u32 *w = func_020124E8(t);

    w[0] = (u32)a;
    w[1] = b;
    w[2] = c;
    w[3] = d;
    return t;
}





/*
 * Blocked (MATCH, every concrete byte right): the pooled word 0x000000C2 is a
 * pooled small constant (abs_id_C2, R_ARM_ABS32) passed as the third argument
 * to func_020146F8 / func_02014728, neither of which is in match.py's
 * OVERLAY_ID_CONSUMERS, and no other pool word image-wide holds 0x000000C2,
 * so no evidence class attests it.  d_021F5580 resolves with the ov194 token (0xC2 is ov194; its proc table init/main/exit sits at 0x021F5580).
 */
int func_021C5A54(int a, int *st, int *c)
{
    int r;

    switch (*st) {
    case 0:
        if (c[3] != 0) {
            r = (int)func_020146F8((char *)c[0], c[1], (int)abs_id_C2, (int)(&d_021F5580), c[2]);
        } else {
            r = (int)func_02014728((char *)c[0], c[1], (int)abs_id_C2, (int)(&d_021F5580), c[2]);
        }
        func_02012374((struct Evt *)a, (struct Evt **)r);
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}





int func_021C5AAC(void *a, int b, int c, int d)
{
    int h;
    struct Work_021C5AAC *p;
    int e;
    void *r6;
    int x;
    int y;

    if ((int)func_0201AA18(func_02012934(func_020120F4(a))) <= c) {
        c = 0;
    }
    h = (int)func_020122C0(a, 0, (void *)func_021C5B58, 0x18);
    p = func_020124E8((struct Obj *)h);
    p->a = a;
    p->f04 = func_0201210C(a);
    p->f10 = b;
    p->f14 = d;
    r6 = func_020120F4(p->a);
    e = (int)func_0201AB28(func_02012934(r6), c);
    r6 = func_0200C0F0(func_02012EBC(r6));
    x = func_02017E1C((void *)e, 5, 0);
    y = func_02017E1C((void *)e, 0x6f, 0) | (func_02017E1C((void *)e, 0x6e, 0) << 8);
    p->f08 = func_0216BFD4(4, 1, x, y, 0xa, 0, r6);
    p->f0C = e;
    return h;
}





int func_021C5B58(int a, int *st, int *c)
{
    int *q;
    int f;

    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, func_021C5A28((void *)c[0], c[1], c[2], c[5]));
        (*st)++;
        break;
    case 1:
        q = (int *)c[2];
        if (q[7] != 1) {
            func_02017E40((void *)c[3], 0x73, q[8]);
        }
        f = 1;
        if (((int *)c[2])[7] == 1) {
            f = 0;
        }
        *(u16 *)c[4] = f;
        if (*(u16 *)c[4] == 1) {
            func_02008DF0(func_02012F2C(func_020120F4((const struct Ctx *)c[0])), 0x1e);
        }
        func_0216C0C0(c[2]);
        return 1;
    }
    return 0;
}





/*
 * Spawns the func_021C5C08 task with a 0x14-byte work area.
 */
void *func_021C5BD0(void *a, u32 b, u32 c)
{
    void *t = func_020122C0(a, 0, func_021C5C08, 0x14);
    W *w = func_020124E8(t);

    w->owner = a;
    w->f4 = func_0201210C(a);
    w->f10 = c;
    w->f8 = (u32)func_020120F4(a);
    w->hC = b;
    return t;
}





/*
 *           func_020146F8 (0x020146F8), which is not in match.py
 *           OVERLAY_ID_CONSUMERS, so the ABS32 has no witness (literal class
 *           refuses the range's own pool word).  Every concrete byte matches.
 */
int func_021C5C08(void *a, int *st, Arg *p)
{
    int v;

    switch (*st) {
    case 0:
        func_02012374(a, func_020146F8((char *)p->f0, p->f4, (int)ov171_id, (int)d_021DEA44, (int)p->f8));
        *st = *st + 1;
        break;
    case 1:
        switch (p->fE) {
        case 0:
            v = 0;
            *p->f10 = v;
            break;
        case 1:
            v = 1;
            *p->f10 = v;
            break;
        }
        return 1;
    }
    return 0;
}





int func_021C5C64(u32 unused, u32 a, u32 *out)
{
    int v[3];
    u32 w[4];
    void *h1;
    u32 r;
    u8 s;

    r = func_02188C98((u8 *)a);
    h1 = func_02188CB4((void *)a);
    s = func_0216D5F8(func_021A3074((void *)h1));
    func_021A3364(h1, s, v);
    if (func_02188CFC((u8 *)a) == 1)
        return 0;
    if (func_0218DAEC(r, v, w) == 0)
        return 0;
    if (func_021AB2E8(func_021AB0F0(w[2])) == 1) {
        func_02164208(s, v, 0x10000);
        if (func_0218DAEC(r, v, w) == 0)
            return 0;
    }
    if (func_021AB3B0(func_021AB0F0(w[2])) == 0)
        return 0;
    if (out != 0) {
        out[0] = v[0];
        out[1] = w[3];
        out[2] = v[2];
    }
    return 1;
}





void *func_021C5D10(struct Obj00020 *a, void *b)
{
    void *task;
    Work_021C5D10 *w;
    int mode;

    task = func_020122C0(b, 0, func_021C5DF4, sizeof(Work_021C5D10));
    w = func_020124E8(task);
    func_02082BCC(w, 0, sizeof(Work_021C5D10));
    w->f0 = b;
    w->f8 = (u8 *)a;
    w->f4 = func_020120F4(b);
    w->fC = (void *)func_02188CE8(w->f8);
    w->f10 = (u32)func_02012F2C(w->f4);
    w->f14 = func_02188C7C(w->f8);
    w->f18 = func_02188CB4(a);
    w->f1C = func_021A3074(w->f18);
    w->f58 = func_0216D5F8(w->f1C);
    func_021A3038(w->f18, (struct VecFx32 *)&w->f34);
    w->f28 = func_021A34EC(w->f18);
    if (func_021C5C64((u32)w->f4, (u32)w->f8, (u32 *)(&w->f40)) == 0)
        w->f5A = 1;
    w->f20[0] = (w->f40.x >> 4) / 4096;
    w->f20[1] = (w->f40.y >> 4) / 4096;
    w->f20[2] = (w->f40.z >> 4) / 4096;
    if (func_021AA900(w->fC, w->f20))
        w->f59 = mode = 1;
    else
        w->f59 = mode = 0;
    w->f64 = func_021AA180(w->fC, mode);
    func_0216D9A0(w->f14);
    return task;
}





int func_021C5DF4(void *task, int *state, Work_021C5DF4 *w)
{
    int r;

    switch (*state) {
    case 0:
        if (w->f5A != 0) {
            *state = 8;
            break;
        }
        func_021A2F48((u8 *)w->f18, 0x200);
        (*state)++;
    case 1:
        if (func_021A2F54((u8 *)w->f18) != 1)
            break;
        func_0216D674((void *)w->f1C, 0);
        func_020061E4(0x684);
        (*state)++;
        break;
    case 2:
        if (func_021C5FA8(w, 15) == 0)
            break;
        func_021C602C((u8 *)w);
        if (w->f64 == 0) {
            *state = 5;
            break;
        }
        w->f5C = func_02005728(0x5a) + 0x1e;
        (*state)++;
        break;
    case 3:
        r = func_021C5FC0((u8 *)w, w->f5C);
        if (r == 1) {
            *state = 6;
            break;
        }
        if (r != 2)
            break;
        func_021C5FEC((u8 *)w);
        (*state)++;
        break;
    case 4:
        r = func_021C5FC0((u8 *)w, 0x1e);
        if (r == 0)
            break;
        func_021C6018((u32 *)w);
        if (r == 1) {
            func_021C6054((u32 *)w);
            func_0216D674((void *)w->f1C, 3);
            func_02158780(task, (u16)0x2796, (u32)0, (u32)0, (u32)0x15);
            *state = 10;
            break;
        }
        if (r != 2)
            break;
        func_02008DF0((struct Sub02008C20Obj *)w->f10, 0x50);
        *state = 7;
        break;
    case 5:
        r = func_021C5FC0((u8 *)w, 0x78);
        if (r != 2) {
            if (r == 1)
                *state = 6;
            break;
        }
    case 6:
    case 7:
        func_021C6054((u32 *)w);
        if (w->f64 != 0) {
            if (w->f59 == 1)
                func_021AA8EC(w->fC);
            func_020130B4((int)w->f64);
        }
        func_0216D674((void *)w->f1C, 1);
        func_02158780(task, (u16)(*state + 0x2792), (u32)0, (u32)0, (u32)0x15);
        *state = 8;
        break;
    case 8:
        func_021A2F48((u8 *)w->f18, 8);
        *state = 9;
    case 9:
        if (func_021A2F54((u8 *)w->f18) == 1)
            return 1;
        break;
    case 10:
        func_02008DF0((struct Sub02008C20Obj *)w->f10, 8);
        func_0201235C(task, (u32 *)func_0216E7C8((int)w->f0, (int)w->f8, (int)w->f64, 0, (u8)(w->f59 == 1 ? 1 : 4)));
        return 0;
    }
    return 0;
}
