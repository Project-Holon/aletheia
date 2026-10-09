/*
 * file:     ica_anime_p01.c
 * unit:     yes
 * function: func_02010D98, func_02010DB4, func_02010DCC, func_02010DF4, func_02010E14, func_02010EA0, sub_02010EB4, func_02010EC0, func_02010EEC, func_02010F18, func_02010F40, func_02010F50, func_02010F7C, func_02010F8C, func_02010F94, func_02010FA0, func_02010FAC, func_02010FB0, func_02010FF4, func_02011014, func_0201102C, func_0201104C, func_020110CC, func_02011168, func_0201119C, func_020111BC, func_020111E8, func_020111EC, func_0201121C, func_02011264, func_0201126C, func_0201127C, func_02011290, func_02011298, func_02011324, func_02011328, func_02011330, func_0201134C, func_0201137C, func_02011398, func_020113B0, func_020113B4, func_020113C4, func_020113D0, func_020113D8, func_020113F0, func_02011400, func_02011410, func_02011428, func_0201147C, func_020114D0, func_02011510, func_02011558, func_02011590, func_020115C0, func_020115EC, func_02011608, func_0201160C, func_02011610, func_02011638, func_02011660, func_02011688, func_020116C0, func_020116E0, func_02011770, func_020117D8, func_0201183C, func_02011B8C, func_02011CF0, func_02011D0C, func_02011D28, func_02011D34, func_02011D40, func_02011D60, func_02011D7C, func_02011D9C, func_02011EAC, func_02011EC0, func_02011EEC, func_02011F24, func_02011F28, func_02011F90, func_02011FB8, func_02011FCC, func_0201205C, func_02012088, func_0201209C, func_020120A4, func_020120B4, func_020120C0, func_020120D8, func_020120F0, func_020120F4, func_020120F8, func_02012104, func_02012108, func_0201210C, func_02012110, func_02012114, func_02012124, func_0201212C, func_02012134, func_02012138, func_0201213C, func_02012144, func_0201214C, func_02012158, func_02012164, func_020121CC, func_02012204, func_02012210, func_02012220, func_02012248, func_02012258, func_02012264, func_020122A4, func_020122B4, func_020122C0, func_02012304, func_02012314, func_0201232C, func_0201235C, func_02012374, func_02012380, func_020123C4, func_020123D8, func_0201240C, func_02012444, func_02012474, func_020124AC, func_020124E4, func_020124E8, func_020124EC, func_020124F0, func_020124F4, func_02012704, func_02012798, func_020127A4, func_020127AC, func_020127B8, func_020127C4, func_020127D0, func_020127E0, func_020127F0, func_02012800, func_0201281C, func_0201283C, func_02012844, func_0201284C, func_02012854, func_02012870, func_02012878, func_02012894, func_0201289C, func_020128B8, func_020128C0
 * address:  0x02010D98
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021461E8  0x021461E8  data
 *   g_02146228     0x02146228  data
 *   g_0214621C     0x0214621C  data
 *   g_0214622A     0x0214622A  data
 *   _u32_div_f   0x0209C2B0  arm
 *   func_02048F60  0x02048F60  arm
 *   func_020307B0  0x020307B0  arm
 *   g_02146208      0x02146208  data
 *   func_0201BA34  0x0201BA34  thumb
 *   func_0201AB08  0x0201AB08  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017D30  0x02017D30  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02017D70  0x02017D70  thumb
 *   func_0201C158  0x0201C158  thumb
 *   _ll_mul     0x0209C054  arm
 *   _ll_sdiv    0x0209BE5C  arm
 *   sub_02030734       0x02030734  arm
 *   MI_CpuFill8        0x02082BCC  arm
 *   unit_020111EC_File 0x020A7268  data
 *   func_0203F4CC  0x0203F4CC  arm
 *   tbl_0209DF24  0x0209DF24  data  a1
 *   tbl_0209DF10  0x0209DF10  data  a1
 *   func_02030734   0x02030734  arm
 *   func_02011770  0x02011770  thumb
 *   sIcaAnimeFile  0x020A7270  data
 *   func_02049238     0x02049238  arm
 *   g020A7270      0x020A7270  data
 *   _fgr           0x0209BBB0  arm
 *   _ffix          0x0209C494  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   data_020A7270  0x020A7270  data
 *   func_0204944C  0x0204944C  arm
 *   _fdiv          0x0209CE10  arm
 *   _fflt          0x0209BDBC  arm
 *   _ffixu         0x0209C4C8  arm
 *   _fls           0x0209BC74  arm
 *   data_0209DF84  0x0209DF84  data
 *   data_0209DF90  0x0209DF90  data
 *   func_02048AFC  0x02048AFC  arm
 *   func_02048B20  0x02048B20  arm
 *   func_02048B44  0x02048B44  arm
 *   func_020520FC  0x020520FC  arm
 *   func_0207B51C  0x0207B51C  arm
 *   func_0207C9D0  0x0207C9D0  arm
 *   func_0203F0A8  0x0203F0A8  arm
 *   sub_020056A0   0x020056A0  thumb
 *   g_02146248     0x02146248  data
 *   func_0203064C  0x0203064C  arm
 *   func_020306F0  0x020306F0  arm
 *   ov230_id       0x000000E6  data
 *   func_021882A0  0x021882A0  arm  ov230d
 *   func_02188354  0x02188354  arm  ov230d
 *   func_02188390  0x02188390  arm  ov230d
 *   func_0215FA00  0x0215FA00  thumb  ov010
 *   func_02012088     0x02012088  thumb
 *   func_020315D4     0x020315D4  arm
 *   func_02087BCC     0x02087BCC  arm
 *   func_02082BCC     0x02082BCC  arm
 *   func_02031324  0x02031324  arm
 *   func_020261E4  0x020261E4  thumb
 *   func_0202B4BC  0x0202B4BC  thumb
 *   func_020139B0  0x020139B0  thumb
 *   func_0202B4F0  0x0202B4F0  thumb
 *   func_02026250  0x02026250  thumb
 *   func_02013A48  0x02013A48  thumb
 *   func_020267BC     0x020267BC  thumb
 *   func_02021438     0x02021438  thumb
 *   func_02012A24  0x02012A24  thumb
 *   func_02035614  0x02035614  arm
 *   func_020129FC  0x020129FC  thumb
 *   func_0201205C  0x0201205C  thumb
 *   func_0202627C  0x0202627C  thumb
 *   func_02031330  0x02031330  arm
 *   func_02012A30  0x02012A30  thumb
 *   func_02028A14  0x02028A14  thumb
 *   func_0202B500  0x0202B500  thumb
 *   func_02021464  0x02021464  thumb
 *   func_0200F7B8  0x0200F7B8  thumb
 *   func_02188BE8     0x02188BE8  thumb  ov021
 *   func_0203133C  0x0203133C  arm
 *   func_02031348  0x02031348  arm
 *   ov021_id          0x00000015  data
 *   s0x021D359C       0x021D359C  data  ov021
 *   func_02012BB0  0x02012BB0  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D34  0x02013D34  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02158318  0x02158318  thumb  ov010
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   func_0200921C  0x0200921C  thumb
 *   func_020090E0  0x020090E0  thumb
 *   func_0203CD98     0x0203CD98  arm
 *   func_02026454     0x02026454  thumb
 *   func_020263D8     0x020263D8  thumb
 *   func_02035138  0x02035138  arm
 *   func_02035064  0x02035064  arm
 *   sub_020122C0_File   0x020A727C  data
 *   g_020A727C      0x020A727C  data
 *   sub_02012104   0x02012104  thumb
 *   sub_02012108   0x02012108  thumb
 *   sub_02012304   0x02012304  thumb
 *   sub_02012314   0x02012314  thumb
 *   func_020124E4     0x020124E4  thumb
 *   g_020A728C     0x020A728C  data
 *   func_020070A4  0x020070A4  thumb
 *   func_0202E888  0x0202E888  thumb
 *   func_02008854  0x02008854  thumb
 *   func_02008844  0x02008844  thumb
 *   func_02008848  0x02008848  thumb
 *   func_0200884C  0x0200884C  thumb
 *   func_02006E40  0x02006E40  thumb
 *   func_02012A60  0x02012A60  thumb
 *   func_02008468  0x02008468  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008730  0x02008730  thumb
 *   memcpy         0x02082D44  arm
 *   func_0216237C  0x0216237C  thumb  ov010
 *   func_021623DC  0x021623DC  thumb  ov010
 *   func_02012FE4  0x02012FE4  thumb
 *   func_02159B48  0x02159B48  thumb  ov010
 *   func_020071CC  0x020071CC  thumb
 *   func_0216CC58  0x0216CC58  thumb  ov010
 *   func_02028844  0x02028844  thumb
 *   func_02014428  0x02014428  thumb
 *   func_02008254  0x02008254  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02007AA4  0x02007AA4  thumb
 *   func_020097C4  0x020097C4  thumb
 *   func_0200BDE4  0x0200BDE4  thumb
 *   func_02161D98  0x02161D98  thumb  ov010
 *   func_0200857C  0x0200857C  thumb
 *   func_020071E4  0x020071E4  thumb
 *   func_0215E31C  0x0215E31C  thumb  ov010
 *   func_0202E43C  0x0202E43C  thumb
 *   func_02012C18  0x02012C18  thumb
 *   func_0202E770  0x0202E770  thumb
 *   func_0202751C  0x0202751C  thumb
 *   func_021647A0  0x021647A0  thumb  ov010
 *   func_021647D8   0x021647D8  thumb  ov010
 *   func_02027584   0x02027584  thumb
 *   func_0202E794   0x0202E794  thumb
 *   func_0215E334   0x0215E334  thumb  ov010
 *   func_02006E64   0x02006E64  thumb
 *   func_02007AC8   0x02007AC8  thumb
 *   func_0216CCB0   0x0216CCB0  thumb  ov010
 *   func_02159BBC   0x02159BBC  thumb  ov010
 *   func_021623BC   0x021623BC  thumb  ov010
 *   func_02014444   0x02014444  thumb
 *   func_0202889C   0x0202889C  thumb
 *   func_02161D64  0x02161D64  thumb  ov010
 *   func_02008850  0x02008850  thumb
 */
#include "../../matched/include/Obj15617.h"
#include "../../matched/include/Obj08965.h"
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj11244.h"
#include "../../matched/include/Obj11245.h"
#include "../../matched/include/Obj11246.h"
#include "../../matched/include/Obj00064.h"
#include "../../matched/include/Obj01458.h"
#include "../../matched/include/Obj00020.h"
#include "../../matched/include/Obj15622.h"
#include "../../matched/include/Obj15623.h"
#include "../../matched/include/Obj15624.h"
#include "../../matched/include/Obj01023.h"
#include "../../matched/include/Obj00054.h"
#include "../../matched/include/Obj01611.h"
#include "../../matched/include/Obj15627.h"
#include "../../matched/include/Obj15628.h"

struct S020314B8;
struct S020315D4;
struct Sav;
struct ScriptVm;
struct Stream;
struct RtcTime;
struct IcaAnime;
struct ArcFile;
struct Rec12;
struct Mtx33;
struct Obj0203159C;
struct Blk34;
struct Ctx;
struct IcaAnimeInst;
struct SaveBlock;
struct BigObj;
struct T;
struct Comm;
struct Rec44;
struct Sub02009210Obj;
struct Sub020090B0Obj;
struct S02012304;
struct Obj;
struct Desc;
struct Evt;
struct Sub02006E40Obj;
struct Sub02007084Ctrl;
struct Sub020071E4Ctrl;
struct Sub0200852CObj;
struct Sub02008700Obj;
struct Sub02008828Obj;
struct Sys;
struct Rec1B0;
struct Sub020071CCCtrl;
struct SoundSys;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef enum { SLOT_0 = 0, SLOT_MAX = 13 } Slot;

typedef unsigned short u16;

typedef struct {
    u8 pad0[0xa];
    u8 slot;
    u8 padB;
} Entry;

struct Rec02010F94 {
    unsigned char pad[10];
    unsigned char f;
    unsigned char pad2;
};

struct Rec02010FA0 {
    unsigned short a;
    unsigned short f;
    unsigned char pad[8];
};

typedef signed int     s32;

typedef signed long long s64;

typedef int (*ScriptCmdFn)(struct ScriptVm *vm, void *user);

typedef int (*ScriptWaitFn)(struct ScriptVm *vm, void *user);

typedef int (*ScriptHookFn)(struct ScriptVm *vm, void *user, void *arg, u32 op);

typedef struct ScriptVmParams {
    u16 stack_cap;
    u16 ring_cap;
    const ScriptCmdFn *cmds;
    u32 cmd_count;
} ScriptVmParams;

typedef struct ScriptVm {
    ScriptVmParams params;
    u8 depth;
    u8 state;
    u8 ring_depth;
    u8 pad_0f;
    ScriptWaitFn wait;
    u8 *pc;
    u32 *stack;
    u32 *ring;
    void *user;
    ScriptHookFn hook;
    void *hook_arg;
    void *data;
} ScriptVm;

struct Stream {
    u8 unk00[0x14];
    u8 *cursor;
};

struct Ring {
    u16 cap;
    u8  unk02[0xA];
    u8  count;
    u8  unk0D[0xB];
    u32 *buf;
};

struct Cur {
    u8  unk00[0x14];
    u32 unk14;
};

struct Vec3 { s32 x; s32 y; s32 z; };

struct IcaAnime {
    u16 f00;
    u16 f02;
    u32 f04;
    u32 f08;
    u32 f0c;
    s32 f10;
    s32 f14;
    s32 f18;
    struct Vec3 *f1c;
    struct Vec3 *f20;
    struct Vec3 *f24;
    u32 f28;
    u32 f2c;
    u32 f30;
    u32 f34;
};

typedef signed int     s32_02011610;

struct Rec12 {
    s32_02011610 a;
    s32_02011610 b;
    s32_02011610 c;
};

typedef int            s32_02011688;

typedef signed char s8;

typedef signed short s16;

struct G02146248 {
    void *unk00;
    u32 unk04;
    u32 f8;         /* +0x08 */
    struct Rec12 rec;   /* +0x0C */
    u16 f18;        /* +0x18 */
    u16 f1a;        /* +0x1A */
};

struct Ctx {
    u8    unk00[0xC];
    u32   unk0C;
    u8    unk10[8];
    u32   unk18;
    void *unk1C;
    void *unk20;
    u32   unk24;
    u32   unk28;
    u32   unk2C;
    u8    unk30;
    u8    unk31;
    u8    unk32;
    u8    unk33_0 : 1;
    u8    unk33_1 : 7;
};

struct IcaAnimeInst {
    u16   f00;
    u8    pad02[2];
    u32   f04;
    void *f08;
    u32   f0c;
    s32   f10;
    s32   f14;
    s32   f18;
    void *f1c;
    u32   f20;
    void *f24;
    u32   f28;
    void *f2c;
    u8    f30;
    u8    f31;
    u8    f32;
    u8    f33_0 : 1;
    u8    f33_1 : 7;
};

struct Desc {
    void *unk_00;
    void *unk_04;
    u32   unk_08;
    void *unk_0c;
    void *unk_10;
};

typedef int (*Fn02012304)(void *self, void *arg, u32 n);

struct S02012304 {
    unsigned char pad[4];
    Fn02012304 f04;
    unsigned char pad2[4];
    u32 f0c;
};

struct S0201235C {
    u32 f00;
    unsigned char pad[0xc];
    u32 f10;
};

struct Evt {
    u8    pad_00[0x10];
    void *unk_10;
};

struct Obj {
    void *unk_00;
    u32  unk_04;
    u32  unk_08;
    void *unk_0c;
    void *unk_10;
};

typedef struct S { u8 pad00[4]; int f04; } S;

struct SaveBlock {
    u8 pad_000[0x114];
    u8 unk_114[0xc0];
    u8 unk_1d4[1][0x10];
};

struct Rec1C {
    u32 v[7];
};

struct BigObj {
    u8  unk000[0x158];
    u32 unk158;
    u32 unk15C;
    struct Rec1C *unk160;
    struct Rec1C *unk164;
    struct Rec1C *unk168;
    struct Rec1C *unk16C;
    struct Rec1C unk170;
    u8  unk18C[0x14];
    u32 unk1A0;
};

extern void func_0203133C(struct S020314B8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_02082BCC(void *dst, u32 v, u32 size);
extern u32 _u32_div_f(u32 a, u32 b);
extern void *func_02048F60(u32 arc, u32 member, u32 heap);
extern u32 func_020307B0(void *p);
extern void func_0201BA34(void *p);
extern u32 func_0201AB08(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern u8 func_0201C158(u16 move, u32 ppUp);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern void func_0203F4CC(struct RtcTime *time);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02011770(u8 *p, int n);
extern void func_02049238(u32 h);
extern void *sub_020490F4(unsigned int id, unsigned int heap);
extern void sub_0204944C(struct ArcFile *a, u32 b, u32 c, u32 d, void *e);
extern void  func_0204944C(struct ArcFile *a, u32 b, u32 ofs, u32 size, void *dst);
extern void func_02048AFC(void *dst, struct Vec3 *v);
extern void func_02048B20(void *dst, struct Vec3 *v);
extern void func_02048B44(void *dst, struct Vec3 *v);
extern void func_020520FC(int h, int s, int v, struct Mtx33 *out);
extern void func_0207B51C(struct Vec3 *a, struct Vec3 *b, struct Vec3 *out);
extern void func_0207C9D0(struct Vec3 *a, struct Vec3 *b, struct Vec3 *out);
extern u32 func_0203F0A8(void);
extern void *sub_020056A0(u32 a, u32 b, u32 c);
extern void func_0203064C(unsigned int a, unsigned int b, unsigned int c);
extern void func_020306F0(unsigned int a);
extern int func_02034AC4(int id);
extern u32   func_021882A0(void (*a)(void), void (*b)(void), u32 c);
extern u32   func_02188354(void (*a)(void), void (*b)(void), u32 c);
extern u32   func_02188390(void (*a)(void), void (*b)(void), u32 c);
//P
extern void  func_02034A5C(s32 id);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern u32   func_0215FA00(void *p, u32 a);
extern void *func_02012F08(int *p);
extern u32 func_0200C258(struct Blk34 *p);
extern void func_02012088(struct IcaAnimeInst *p);
extern void func_02087BCC(u32 v);
extern void *func_02031324(int a0);
extern void *func_020261E4(unsigned int id, void *res);
extern void *func_0202B4BC(struct SaveBlock *a, unsigned int id);
extern void func_020139B0(u32 heap);
extern void func_0202B4F0(unsigned char *p);
extern void func_02026250(void *obj);
extern void func_02013A48(void);
extern void func_020267BC(u32 v);
extern void func_02021438(void);
extern unsigned char func_02012A24(const struct BigObj *p);
extern void func_02035614(int v);
extern unsigned char func_020129FC(struct BigObj *h);
extern void func_0201205C(struct IcaAnimeInst *p);
extern void func_0202627C(struct Comm *p);
extern unsigned int func_02031330(void *p);
extern unsigned int func_02012A30(const struct BigObj *p);
extern void func_02028A14(struct T *p);
extern void func_0202B500(unsigned char *p);
extern void func_02021464(unsigned char *p);
extern u32 func_0200F7B8(u32 a0);
extern void func_02031348(void *h, u32 id, void *a, void *b);
extern u32 func_02012BB0(const struct BigObj *p);
extern void func_02012BC8(unsigned char *p, int on);
extern u16   func_02012AC8(const struct Rec44 *h);
extern u32 func_02013D34(u32 id);
extern u32   func_0200FB24(void);
extern int func_02158318(int a0);
extern u32   func_02035390(void);
extern int func_020353B0(void);
extern struct Sub02009210Obj *func_0200921C(void *p);
extern u8 func_020090E0(const struct Sub020090B0Obj *obj);
extern int func_0203CD98(void);
extern u32 func_02026454(void *obj);
extern void func_020263D8(struct Comm *p, u32 a1, u32 a2);
extern void func_02035138(void *fn, u32 arg);
extern void func_02035064(const void *fn, u32 arg);
extern unsigned int sub_02012104(const struct Ctx *p);
extern void sub_02012108(struct Ctx *p, u32 v);
extern int sub_02012304(struct S02012304 *o);
extern void sub_02012314(char *p);
extern void *func_020124E4(struct Obj *p);
extern struct Sub02007084Ctrl *func_020070A4(void);
extern u8    func_0202E888(void);
extern struct Sub02008828Obj *func_02008854(void *sys);
extern u32   func_02008844(u32 a);
extern void *func_02008848(struct Sub02008828Obj *obj);
extern void *func_0200884C(struct Sub02008828Obj *obj);
extern struct Sub02006E40Obj *func_02006E40(u32 heap);
extern void func_02012A60(struct Rec44 *p);
extern int func_02008468(void);
extern u8 *func_02012944(void *p);
extern struct Sub0200852CObj *func_02008730(void *sys);
extern void *memcpy(void *dst, const void *src, u32 n);
extern int func_0216237C(int a);
extern void func_021623DC(char *p);
extern void *func_02012FE4(struct Sub020071CCCtrl *a0);
extern u16 *func_02159B48(int a);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern char *func_0216CC58(int a, int b, int c);
extern struct Sys *func_02028844(void *desc, u32 heap);
extern u32   func_02014428(int heap);
extern void *func_02008254(u32 heap);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern u32 *func_02007AA4(u32 heap, u32 value);
extern void *func_020097C4(int a0);
extern void func_0200BDE4(struct Rec1B0 *p);
extern void  func_02161D98(char *p);
extern void *func_0200857C(u32 heap);
extern u8 func_020071E4(const struct Sub020071E4Ctrl *ctrl);
extern void *func_0215E31C(u32 heap);
extern void  func_0202E43C(void *p);
extern void func_02012C18(u8 *p);
extern void *func_0202E770(void *heap);
extern u32   func_0202751C(int heap, u32 n);
extern u8 *func_021647A0(void *a, u32 b);
extern int func_021647D8(int a0);
extern void func_02027584(u8 *p);
extern void func_0202E794(void *p);
extern void func_0215E334(void *ptr);
extern void func_02006E64(struct Sub02006E40Obj *obj);
extern void func_02007AC8(void *p);
extern int func_0216CCB0(int a0);
extern void func_02159BBC(void *ptr);
extern int func_021623BC(int a0);
extern void func_02014444(u32 p);
extern void func_0202889C(struct SoundSys *s);
extern void func_02082D44(void *dst, const void *src, u32 n);
extern int func_02161D64(int a0);
extern u16 *func_02008850(void *p);
int func_02010D98(int a0, int a1, int a2, int a3);
void func_02010DB4(void);
void func_02010DCC(void);
void func_02010DF4(void);
void sub_02010E14(int slot, u8 *rec, int select);
u8 sub_02010EA0(int slot, u8 *rec);
u8 sub_02010EB4(int k);
u32 func_02010EC0(u32 i);
int func_02010EEC(void);
u8 func_02010F18(void);
void func_02010F40(int idx, Entry *tbl);
void func_02010F50(int idx);
void *func_02010F7C(u32 heap);
void func_02010F8C(void *p);
unsigned int func_02010F94(struct Rec02010F94 *p, int idx);
unsigned int func_02010FA0(struct Rec02010FA0 *p, int idx);
void sub_02010FAC(void);
u32 func_02010FB0(u32 v);
u32 func_02010FF4(u32 v);
int func_02011014(int a0);
u32 func_0201102C(u32 v);
u32 func_0201104C(void *box);
u32 func_020110CC(void *box);
u32 func_02011168(u32 v);
u32 func_0201119C(u32 v);
s32 func_020111BC(s32 v);
u32 func_020111E8(void);
void func_020111EC(ScriptVm *vm);
ScriptVm *func_0201121C(u32 heapId, const ScriptVmParams *params);
void func_02011264(void *ptr);
void func_0201126C(ScriptVm *vm, void *user);
void func_0201127C(ScriptVm *vm, u8 *pc);
ScriptVm *sub_02011290(ScriptVm *vm);
int func_02011298(ScriptVm *vm);
void *sub_02011324(ScriptVm *vm);
void sub_02011328(ScriptVm *vm, ScriptHookFn hook, void *arg);
u16 func_02011330(struct Stream *s);
u32 func_0201134C(struct Stream *s);
void func_0201137C(struct Ring *r, u32 v);
u32 func_02011398(struct Ring *r);
void func_020113B0(struct Cur *c, u32 v);
void func_020113B4(struct Ring *r, u32 v);
u32 func_020113C4(struct Ring *r);
void func_020113D0(char *p, int val);
u32 func_020113D8(u32 row);
int func_020113F0(int row, int col);
u8 func_02011400(int row, int col);
u32 func_02011410(u32 tz);
void *func_02011428(u32 heap, u32 a1, u32 a2, u32 a3, u32 a4);
void *func_0201147C(u32 heap, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5);
void *func_020114D0(u32 heap, u32 a1, u32 a2);
void *func_02011510(u32 heap, u32 a1, u32 a2, u32 a3);
void func_02011558(struct IcaAnime *p);
u32 func_02011590(struct IcaAnime *p, s32 v);
u32 func_020115C0(struct IcaAnime *p, s32 v);
void func_020115EC(struct IcaAnime *p, s32 v);
u32 func_02011608(struct Obj11244 *p);
u32 func_0201160C(struct Obj11245 *p);
u32 func_02011610(struct IcaAnime *p, struct Rec12 *dst);
u32 func_02011638(struct IcaAnime *p, struct Rec12 *dst);
u32 func_02011660(struct IcaAnime *p, struct Rec12 *dst);
u32 func_02011688(struct IcaAnime *p, struct Rec12 *dst, u32 idx);
void func_020116C0(struct IcaAnime *p);
void func_020116E0(u8 *p, u32 a1, u32 a2, u32 a3);
void sub_02011770(u8 *p, int n);
int func_020117D8(u8 *a0, int a1, u8 *a2, int a3);
void func_0201183C(struct IcaAnime *s, s32 q);
void func_02011B8C(void *dst, void *ctx);
void func_02011CF0(void *a0, void *a1);
void func_02011D0C(void *a0, void *a1);
u32 func_02011D28(u32 (*fn)(void));
void func_02011D34(void);
void func_02011D40(void);
void func_02011D60(void);
void func_02011D7C(void);
u32 func_02011D9C(void *a0, u32 a1, u32 a2);
u32 func_02011EAC(u32 a0, u32 a1, u32 a2, u32 a3);
u32 func_02011EC0(u32 a0, u32 a1, u32 a2, u32 a3);
void *func_02011EEC(u32 a0, u16 a1, struct Rec12 *a2, int a3);
u32 func_02011F24(void);
void func_02011F28(struct IcaAnimeInst *p, u16 id, u32 a2);
void func_02011F90(u32 *o);
void func_02011FB8(struct IcaAnimeInst *p, u16 id, u32 a2);
int func_02011FCC(char *p);
void sub_0201209C(void *o, u32 v1, u32 v2);
void func_020120A4(char *p);
void func_020120B4(struct IcaAnimeInst *p, u32 id, void *a, void *b);
void func_020120C0(struct IcaAnimeInst *p);
int func_020120D8(char *p);
u32 func_020120F0(const struct Ctx *p);
void *func_020120F4(const struct Ctx *p);
u8 *func_020120F8(const struct Ctx *p);
u32 func_02012104(const struct Ctx *p);
void func_02012108(struct Ctx *p, u32 v);
void *func_0201210C(const struct Ctx *p);
void func_02012110(struct Ctx *p, void *v);
u32 func_02012114(const struct Ctx *p);
void func_02012124(struct Ctx *p, u32 v);
u8 func_0201212C(const struct Ctx *p);
u32 func_02012134(const struct Ctx *p);
u32 func_02012138(const struct Ctx *p);
void func_0201213C(struct Ctx *p, u32 v);
u8 func_02012144(const struct Ctx *p);
u32 func_0201214C(const struct Ctx *p);
void func_02012158(char *p, unsigned int v);
u32 func_02012164(struct IcaAnimeInst *p);
u32 func_020121CC(struct IcaAnimeInst *p);
u32 func_02012204(const struct Ctx *p);
void func_02012210(struct Ctx *p);
void func_02012220(struct IcaAnimeInst *p);
void func_02012248(struct IcaAnimeInst *p);
void func_02012258(void *o);
int func_02012264(int a0, int a1, int a2, int a3);
void func_020122A4(u32 arg);
void func_020122B4(void *o);
struct Desc *sub_020122C0(void *owner, void *a, void *b, u32 size);
int func_02012304(struct S02012304 *o);
void func_02012314(char *p);
void func_0201232C(char *p, int a1, int a2);
void func_0201235C(struct S0201235C *o, u32 *out);
void func_02012374(struct Evt *evt, struct Evt **out);
int func_02012380(void *p);
int func_020123C4(void *a0);
int func_020123D8(void *o, u32 (*fn)(void *, void *), void *a2);
int func_0201240C(void *o, u32 *state, u32 *item);
void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
int func_02012474(void *a0, u32 *a1, u32 *a2);
struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
void *sub_020124E4(struct Obj *p);
void *sub_020124E8(struct Obj *p);
u32 *sub_020124EC(struct Obj *p);
void *sub_020124F0(struct Obj *p);
void *func_020124F4(u16 heap);
void func_02012704(u8 *p);
u8 *func_02012798(u8 *p, int i);
void *func_020127A4(struct SaveBlock *p);
void *func_020127AC(struct SaveBlock *p, u32 idx);
void *func_020127B8(void *p);
u8 *func_020127C4(void *p);
u8 *sub_020127D0(u8 *o, u32 idx);
int func_020127E0(int a0);
int func_020127F0(int a0);
void func_02012800(u8 *obj, void *dst);
void func_0201281C(u8 *obj);
u32 func_0201283C(const struct BigObj *p);
u32 func_02012844(const struct BigObj *p);
struct Rec1C *func_0201284C(const struct BigObj *p);
void func_02012854(struct BigObj *p, const struct Rec1C *src);
struct Rec1C *func_02012870(const struct BigObj *p);
void func_02012878(struct BigObj *p, const struct Rec1C *src);
struct Rec1C *func_02012894(const struct BigObj *p);
void func_0201289C(struct BigObj *p, const struct Rec1C *src);
struct Rec1C *func_020128B8(const struct BigObj *p);
void func_020128C0(struct BigObj *p, const struct Rec1C *src);
struct Rec1C *func_020128DC(struct BigObj *p);
void func_020128E4(struct BigObj *p, const struct Rec1C *src);
void func_02012900(const struct BigObj *p, u16 v);
extern u32 g_021461E8[];
extern u8   g_02146228[];
extern u8  g_0214621C[];
extern u8  g_0214622A[];
extern u8 g_02146208[];
extern const char unit_020111EC_File[];
extern const u8 tbl_0209DF24[][0x18];
extern const u8 tbl_0209DF10[][5];
extern u8    sIcaAnimeFile;
extern u8    g020A7270[];
extern u8    data_020A7270;
extern struct Vec3 data_0209DF84;
extern struct Vec3 data_0209DF90;
extern struct G02146248 g_02146248;
extern u8 ov230_id[];
extern u8 ov021_id[];
extern u8 s0x021D359C;
extern const char sub_020122C0_File[];
extern char g_020A727C[];
extern char  g_020A728C[];


int func_02010D98(int a0, int a1, int a2, int a3){ func_0203133C((struct S020314B8 *)((struct Obj15617 *)((char *)(a3)))->f8); func_020315D4((struct S020315D4 *)((a0 + 0) + 0)); func_020306F0((int)0x5b); return 1; }


/*
 * Zeroes the 0x60-byte array and reinitialises it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010DB4.c \
 *       --func func_02010DB4 --addr 0x02010DB4 --thumb --cc 1.1p1
 */
void func_02010DB4(void)
{
    func_02082BCC(g_021461E8, 0, 0x60);
    func_02010DF4();
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010DCC.c \
 *       --func func_02010DCC --addr 0x02010DCC --cc 1.1p1 --thumb
 *
 * net_save.c: decrement every counter above 1, then tail-call the empty
 * placeholder sub_02010FAC (pool word 0x02010FAD, `matched`).  The counter
 * is an enum, which keeps the unfolded pre-loop guard with a plain
 * increment; see func_02010DF4.c and docs/notes/pkt_02010DCC.c.txt.
 */
void func_02010DCC(void)
{
    Slot i;

    for (i = 0; i < SLOT_MAX; i++) {
        if (g_021461E8[i] > 1) {
            g_021461E8[i]--;
        }
    }
    sub_02010FAC();
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010DF4.c \
 *       --func func_02010DF4 --addr 0x02010DF4 --cc 1.1p1 --thumb
 *
 * net_save.c: clear all thirteen counter slots, then deselect (+0x1c = 0xd,
 * the "none" slot).  Wave 14 closed the residue of
 * docs/notes/pkt_02010DCC.c.txt (unfolded pre-loop guard plus a plain
 * increment, "no C type gives both"): the counter is an ENUM.  With
 * -enum int an enum counter keeps the `cmp r4, #0xd; bge` entry guard
 * (mwcc does not fold the first test for an enum-typed induction variable)
 * and increments without a truncation pair.  The slot count is an enum
 * constant; 13 is a content constant (docs/families/net_save.h).
 */
void func_02010DF4(void)
{
    Slot i;

    for (i = 0; i < SLOT_MAX; i++) {
        func_02010F50(i);
    }
    g_02146228[0x1c] = SLOT_MAX;
}



/*
 * Records one play-time entry.  `rec` is an array of 0xc-byte records; the
 * record's +0xa byte is the SLOT (0..0xc) and +0xb is a count of hours, which
 * is stored as SECONDS in g_021461E8[slot] (0xe10 = 3600).  The +8 halfword
 * goes into the parallel halfword table at g_0214622A, and the selected-slot
 * byte g_02146228[0x1c] is cleared to 0xd when it named this slot and set to
 * this slot when `select` is 1.
 *
 * The four-case switch is emitted as a comparison TREE, not a table, because
 * the cases (0, 1, 7, 8) are not dense; the pairs are each other's partner
 * (slot 0 clears slot 1 and vice versa, slot 7 clears slot 8 and vice versa).
 *
 * EXACT* : the listing's extent runs to 0x02010EC0 because the two leaf
 * accessors that follow at 0x02010EA0 and 0x02010EB4 save no lr and so carry
 * no label (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * Both should be seeded into layout/function_starts.txt.
 *
 * Addresses are Black-image addresses; 0x30 (the record-count bound) and 0xd
 * (the slot count) are content constants.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02010E14.c \
 *       --func sub_02010E14 --addr 0x02010E14 --cc 1.1p1 --thumb
 */
void sub_02010E14(int slot, u8 *rec, int select)
{
    int k;

    if (slot >= 0x30) {
        return;
    }
    rec = rec + slot * 0xc;
    k = rec[0xa];
    g_0214621C[k] = (u8)slot;
    g_021461E8[k] = rec[0xb] * 0xe10;
    *(u16 *)(g_0214622A + k * 2) = ((struct Obj08965 *)rec)->f8;
    if (g_02146228[0x1c] == k) {
        g_02146228[0x1c] = 0xd;
    }
    if (select == 1) {
        g_02146228[0x1c] = (u8)k;
    }
    switch (k) {
    case 0:
        func_02010F50(1);
        break;
    case 1:
        func_02010F50(0);
        break;
    case 7:
        func_02010F50(8);
        break;
    case 8:
        func_02010F50(7);
        break;
    }
}



/*
 * The second unlabelled leaf after sub_02010E14 (it saves no lr, so
 * disasm.py never labels it; see docs/idioms/unlabelled-leaf-functions-hide-
 * in-word-runs.md).  It reads the state byte for the record `rec[slot]`
 * names, using the same 0xc-byte record stride and +0xa slot field that
 * sub_02010E14 writes with.
 *
 * The pointer must be ADVANCED into its own value first: writing the whole
 * thing as one subscript, `g_0214621C[rec[slot * 0xc + 0xa]]`, folds the
 * +0xa into the scaled index and gives `adds r2, #0xa; ldrb r1, [r1, r2]`
 * where the original has `adds r0, r1, r2; ldrb r1, [r0, #0xa]` - four bytes
 * in the same place, same size, and the only difference in the function.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02010EA0.c \
 *       --func sub_02010EA0 --addr 0x02010EA0 --cc 1.1p1 --thumb
 */
u8 sub_02010EA0(int slot, u8 *rec)
{
    rec = rec + slot * 0xc;
    return g_0214621C[rec[0xa]];
}


/*
 * One of the two leaf accessors that follow sub_02010E14 and carry no label
 * because they save no lr (docs/idioms/unlabelled-leaf-functions-hide-in-
 * word-runs.md).  It reads the state byte of one slot straight out of the
 * thirteen-entry byte table; see docs/families/net_save.h section 4.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02010EB4.c \
 *       --func sub_02010EB4 --addr 0x02010EB4 --cc 1.1p1 --thumb
 */
u8 sub_02010EB4(int k)
{
    return g_0214621C[k];
}


/*
 * Returns 0 for a 0x30 entry, otherwise the counter divided by 0x3c (or 1).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010EC0.c \
 *       --func func_02010EC0 --addr 0x02010EC0 --thumb --cc 1.1p1
 */
u32 func_02010EC0(u32 i)
{
    u32 r;

    if (g_0214621C[i] == 0x30) {
        return 0;
    }
    r = ((u32 *)g_021461E8)[i] / 0x3c;
    return r != 0 ? r : 1;
}


/*
 * Index g_02146228[0x1c] selects one of thirteen u32 counters in g_021461E8;
 * 0xd means "none" and answers 0, otherwise the counter is divided by 60 and
 * a zero quotient is lifted to 1.  The divide is unsigned (`_u32_div_f`), so the
 * counter is read as u32.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010EEC.c \
 *       --func func_02010EEC --addr 0x02010EEC --cc 1.1p1 --thumb
 */
int func_02010EEC(void)
{
    u8 idx = g_02146228[0x1c];
    u32 v;

    if (idx == 0xd) {
        return 0;
    }
    v = g_021461E8[idx] / 0x3c;
    if (v == 0) {
        v = 1;
    }
    return v;
}



/*
 * Returns the byte-table entry g_0214621C of the first of the thirteen counter slots whose value is 1,
 * or 0x30 when none is. The loop index is the Slot enum (as in func_02010DF4): an int index lets
 * mwcc fold the constant entry guard away.
 *
 * Addresses are Black-image addresses.
 */
u8 func_02010F18(void)
{
    Slot i;

    for (i = 0; i < SLOT_MAX; i++) {
        if (g_021461E8[i] == 1)
            return g_0214621C[i];
    }
    return 0x30;
}



/*
 * Clears the counter slot named by byte 0xA of entry idx in a 12-byte-entry table.
 *
 * Addresses are Black-image addresses.
 */
void func_02010F40(int idx, Entry *tbl)
{
    func_02010F50(tbl[idx].slot);
}



/*
 * Clears slot `idx` of the same thirteen-entry counter table and marks the byte
 * table g_0214621C; if the slot was the selected one (g_02146228[0x1c]) the
 * selection is reset to 0xd.  The bound test is SIGNED (`bge`, not `bhs`): the
 * index is an int.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010F50.c \
 *       --func func_02010F50 --addr 0x02010F50 --cc 1.1p1 --thumb
 */
void func_02010F50(int idx)
{
    if (idx >= 0xd) {
        return;
    }
    g_0214621C[idx] = 0x30;
    g_021461E8[idx] = 0;
    if (g_02146228[0x1c] == idx) {
        g_02146228[0x1c] = 0xd;
    }
}



/*
 * Loads archive 0x26 member 0 on the given heap.
 *
 * Addresses are Black-image addresses.
 */
void *func_02010F7C(u32 heap)
{
    return func_02048F60(0x26, 0, heap);
}



/*
 * Frees a buffer from func_02010F7C.
 *
 * Addresses are Black-image addresses.
 */
void func_02010F8C(void *p)
{
    func_020307B0(p);
}



/*
 * Unlabelled Thumb leaf: byte at +0xa of the 12-byte record idx.
 */
unsigned int func_02010F94(struct Rec02010F94 *p, int idx)
{
    return p[idx].f;
}



/*
 * Unlabelled Thumb leaf: halfword at +0x2 of the 12-byte record idx.
 */
unsigned int func_02010FA0(struct Rec02010FA0 *p, int idx)
{
    return p[idx].f;
}




/*
 * An empty function: a pool word in the image holds 0x02010FAD (Thumb), so
 * this two-byte `bx lr` is a real entry point, a placeholder callback that
 * disasm.py could not label because it saves nothing.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02010FAC.c \
 *       --func sub_02010FAC --addr 0x02010FAC --cc 1.1p1 --thumb
 */
void sub_02010FAC(void)
{
}



/*
 * Two mode bytes (+0x14, +0x15) and two scales (+2, +4), each arm clamped to 100
 * (`if (v > 100) v = 100;`) after the unsigned scale divide.  The two arms end
 * at one shared `pop`, which is why the compiler tail-merged them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010FB0.c \
 *       --func func_02010FB0 --addr 0x02010FB0 --cc 1.1p1 --thumb
 */
u32 func_02010FB0(u32 v)
{
    if (g_02146208[0x14] != 0x30) {
        v = *(u16 *)(g_02146228 + 2) * v / 100;
        if (v > 100) v = 100;
        return v;
    }
    if (g_02146208[0x15] != 0x30) {
        v = *(u16 *)(g_02146228 + 4) * v / 100;
        if (v > 100) v = 100;
    }
    return v;
}



/*
 * Scale by the u16 at +6 of g_02146228 unless the mode byte at +0x16 of
 * g_02146208 is 0x30.  The divide is unsigned (`_u32_div_f`, which the runtime
 * table at 0x0209C2B0 calls `_div_by_zero_check`: mwcc's own symbol name for
 * the site is the `_u32_div_f` one, see docs/notes/pkt_0202EC44.c.txt), and the
 * multiply is spelled table-value-first: `x * v`, not `v * x`, or the result
 * register comes out r1 and the function is four bytes too long.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010FF4.c \
 *       --func func_02010FF4 --addr 0x02010FF4 --cc 1.1p1 --thumb
 */
u32 func_02010FF4(u32 v)
{
    if (g_02146208[0x16] != 0x30)
        v = *(u16 *)(g_02146228 + 6) * v / 100;
    return v;
}


int func_02011014(int a0)
{
    if (g_02146208[0x17] != 0x30)
        a0 += *(unsigned short *)(g_02146228 + 8);
    return a0;
}



/*
 * Same shape as func_02010FF4, mode byte +0x18, scale +0xa.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201102C.c \
 *       --func func_0201102C --addr 0x0201102C --cc 1.1p1 --thumb
 */
u32 func_0201102C(u32 v)
{
    if (g_02146208[0x18] != 0x30)
        v = *(u16 *)(g_02146228 + 0xa) * v / 100;
    return v;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201104C.c  *       --func func_0201104C --addr 0x0201104C --cc 1.1p1 --thumb
 *
 * net_save.c, gated on mode byte +0x19 (slot 5): unless the +0xc factor
 * is 999, pick the record func_0201AB08(box) names inside the box
 * (func_0201AB28: box + 8 + idx * 0xdc), and add the +0xc factor to its
 * field 0xa0 clamped to field 0xa1, inside the func_02017D30 /
 * func_02017D70 access bracket; then clear slot 5.  Returns the index, or
 * 0xff when the mode byte is '0'.
 *
 * Wave 14 closed the entry residue shared with func_020110CC and
 * func_020111BC (pool word loaded into r1 before the parameter copy):
 * it was ARITY, not order.  func_0201BA34, func_0201AB08 (a tail-call
 * forwarder that passes r0 through) and func_02017D30 all take the box
 * or record pointer, so r0 stays live across the guards.  The record is
 * a separate local from the box parameter (reassigning the parameter
 * swaps r4/r5).
 */
u32 func_0201104C(void *box)
{
    void *p;
    u32 idx;
    u32 h;
    int max;
    int n;

    if (g_02146208[0x19] != 0x30) {
        if (*(u16 *)(g_02146228 + 0xc) == 999) {
            func_0201BA34(box);
            idx = 0;
        } else {
            idx = func_0201AB08(box);
            p = func_0201AB28(box, idx);
            h = func_02017D30(p);
            max = func_02017E1C(p, 0xa1, 0);
            n = func_02017E1C(p, 0xa0, 0);
            n = n + *(u16 *)(g_02146228 + 0xc);
            if (n > max) {
                n = max;
            }
            func_02017E40(p, 0xa0, n);
            func_02017D70(p, h);
        }
        func_02010F50(5);
        return idx;
    }
    return 0xff;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020110CC.c  *       --func func_020110CC --addr 0x020110CC --cc 1.1p1 --thumb
 *
 * net_save.c, gated on mode byte +0x1a (slot 6): for each of the record's
 * four slots whose field 0x36+i is set, add the +0xe factor to field
 * 0x3a+i, clamped to func_0201C158(field 0x36+i, field 0x3e+i); inside the
 * func_02017D30 / func_02017D70 access bracket; then clear slot 6.  Same
 * declarations as func_0201104C.c (the callees take the box / record
 * pointer, the record is its own local), which is what closed the
 * entry-order residue of docs/notes/pkt_0201104C.sub_020110CC.c.txt.
 */
u32 func_020110CC(void *box)
{
    void *p;
    u32 idx;
    u32 h;
    u32 i;
    u32 move;
    u32 max;
    u32 v;

    if (g_02146208[0x1a] != 0x30) {
        idx = func_0201AB08(box);
        p = func_0201AB28(box, idx);
        h = func_02017D30(p);
        for (i = 0; i < 4; i++) {
            move = func_02017E1C(p, (int)(0x36 + i), (int)0);
            if (move != 0) {
                max = (u32)func_0201C158(move, (u8)func_02017E1C(p, (int)(0x3e + i), (int)0));
                v = func_02017E1C(p, (int)(0x3a + i), (int)0);
                v += *(u16 *)(g_02146228 + 0xe);
                if (v > max) {
                    v = max;
                }
                func_02017E40(p, (int)(0x3a + i), v);
            }
        }
        func_02017D70(p, h);
        func_02010F50(6);
        return idx;
    }
    return 0xff;
}



/*
 * Two mode bytes (+0x1b, +0x1c) and two scales (+0x10, +0x12) on the same two
 * tables; the first arm returns early, the second falls into the shared exit.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011168.c \
 *       --func func_02011168 --addr 0x02011168 --cc 1.1p1 --thumb
 */
u32 func_02011168(u32 v)
{
    if (g_02146208[0x1b] != 0x30)
        return *(u16 *)(g_02146228 + 0x10) * v / 100;
    if (g_02146208[0x1c] != 0x30)
        v = *(u16 *)(g_02146228 + 0x12) * v / 100;
    return v;
}



/*
 * Same shape as func_02010FF4, mode byte +0x1d, scale +0x14.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201119C.c \
 *       --func func_0201119C --addr 0x0201119C --cc 1.1p1 --thumb
 */
u32 func_0201119C(u32 v)
{
    if (g_02146208[0x1d] != 0x30)
        v = *(u16 *)(g_02146228 + 0x14) * v / 100;
    return v;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020111BC.c
 *       --func func_020111BC --addr 0x020111BC --cc 1.1p1
 *
 * Scales v by the rate at +0x16 of the second record (v * rate / 100 in
 * 64 bits) unless the mode byte at +0x1e of the first is 0x30.  The 0x30
 * path has no return statement: the original falls off the end and hands
 * back v, still in r0.  Any written `return v;` makes the compiler join
 * the two paths through a copy (48 bytes); an s64 return type keeps the
 * size but colours the mode load in r3 (r1 is the high half of the
 * result).  See docs/idioms/a-missing-return-hands-back-the-parameter.md.
 */
s32 func_020111BC(s32 v)
{
    if (g_02146208[0x1e] != 0x30) {
        return (s64)*(u16 *)(g_02146228 + 0x16) * v / 100;
    }
}



/*
 * Four bytes, `movs r0, #0x15; bx lr`: a constant getter, isolated between
 * two large unmatched functions, the same situation documented for
 * src/matched/unit_02011F24.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020111E8.c \
 *       --func func_020111E8 --addr 0x020111E8 --cc 1.1p1
 */
u32 func_020111E8(void)
{
    return 0x15;
}



/*
 * The bottom two functions of the game's script virtual machine ("vm.c", the
 * __FILE__ string this unit's allocation site passes, at 0x020A7268, fixed by
 * the terminator of "net_save.c" at 0x020A725C).
 *
 * func_0201121C is the constructor: it takes a heap id and a 12-byte
 * descriptor { u16 stack_cap; u16 ring_cap; const ScriptCmdFn *cmds;
 * u32 cmd_count; }, allocates the 0x30-byte context plus both arrays behind
 * it in one block, copies the descriptor into the head of the context (12
 * bytes, so the copy is an inlined ldm/stm triple,
 * docs/idioms/aggregate-assignment-is-ldm-stm.md), and points +0x1c at the
 * first array and +0x18 one ring_cap past it.  Both capacities are read back
 * out of the caller's descriptor, not out of the context that was just
 * written, which is why the second ldrh addresses r5 and not r7.
 *
 * func_020111EC is the reset: program counter, both stack depths, the state
 * byte, the wait callback and the pre-dispatch hook all cleared, and both
 * arrays filled with zero at their declared capacities.  It is the shared
 * prologue of the two entry points in the next unit (func_0201126C and
 * func_0201127C, 0x0201126C and 0x0201127C).
 *
 * The 0x30-byte context is:
 *   +0x00 u16 stack_cap      (0x100 for the field script system)
 *   +0x02 u16 ring_cap       (0x40)
 *   +0x04 const ScriptCmdFn *cmds
 *   +0x08 u32 cmd_count
 *   +0x0c u8  stack depth
 *   +0x0d u8  state (0 stopped, 1 running, 2 waiting on the callback)
 *   +0x0e u8  ring depth
 *   +0x10 wait callback
 *   +0x14 u8 *pc
 *   +0x18 u32 *stack
 *   +0x1c u32 *ring
 *   +0x20 user object
 *   +0x24 pre-dispatch hook, +0x28 its argument
 *   +0x2c owner-defined word (the loaded script file, for the field system)
 *
 * The unit stops one word short of the Thumb-to-ARM veneer at 0x02011264
 * (`ldr r3,[pc,#0]; bx r3; .word 0x020307B0`), which no tu range may span
 * (docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020111EC.c \
 *       --addr 0x020111EC --thumb --cc 1.1p1
 */
void func_020111EC(ScriptVm *vm)
{
    vm->pc = 0;
    vm->ring_depth = 0;
    vm->state = 0;
    vm->wait = 0;
    vm->depth = 0;
    MI_CpuFill8(vm->stack, 0, vm->params.stack_cap * 4);
    MI_CpuFill8(vm->ring, 0, vm->params.ring_cap * 4);
    vm->hook = 0;
    vm->hook_arg = 0;
}



ScriptVm *func_0201121C(u32 heapId, const ScriptVmParams *params)
{
    u32 size;
    ScriptVm *vm;

    size = params->ring_cap * 4 + sizeof(ScriptVm) + params->stack_cap * 4;
    vm = (ScriptVm *)sub_02030734(heapId, size, 0, unit_020111EC_File, 96);
    MI_CpuFill8(vm, 0, size);
    vm->params = *params;
    vm->ring = (u32 *)(vm + 1);
    vm->stack = vm->ring + params->ring_cap;
    return vm;
}



void func_02011264(void *ptr)
{
    func_020307B0(ptr);
}



/*
 *           sub_02011324, sub_02011328
 *
 * The step function of the game's script virtual machine ("vm.c"), plus the
 * four small entry points around it.  The context layout and the
 * constructor are in src/matched/unit_020111EC.c.
 *
 * func_02011298 is the interpreter core, called once per frame by the owner
 * of the context:
 *
 *   state 0  stopped, nothing to do
 *   state 1  running: fetch a u16 opcode with func_02011330 (the cursor read
 *            that advances +0x14 by two), bounds-check it against +0x08, run
 *            the optional pre-dispatch hook at +0x24, then call
 *            cmds[opcode](vm, user).  A handler returning 1 yields for this
 *            frame; returning 0 continues straight into the next opcode, so
 *            the whole loop is one frame's worth of script.
 *   state 2  waiting: call the callback at +0x10 with (vm, user) every frame
 *            until it returns 1, then clear it and go back to running.  A
 *            null callback in this state is treated as "done waiting".
 *
 * Every abnormal exit (null pc, opcode past the table, hook veto) stops the
 * machine by writing 0 to +0x0d and returning 0, and every yield returns 1;
 * the default arm's `state = 0; return 1` and the handler's `return 1` share
 * one tail (docs/idioms/switch-arms-tail-merge.md).
 *
 * Two shapes in the switch are load-bearing and neither is optional.  The
 * arms are written in the order 0, 2, 1, default: state 2 falls through into
 * state 1 once its callback is gone, which is what puts the wait block
 * physically before the loop and lets the fall-through reach the loop head
 * with no branch.  And the interpreter loop leaves through `break` twice
 * over (out of the `for`, then out of the switch) rather than by returning
 * in place, so that the yield and the default arm's stop share one
 * `movs r0, #1; pop` tail; writing `return 1` at either site splits that
 * tail and costs four bytes
 * (docs/idioms/switch-arms-tail-merge.md,
 * docs/idioms/an-empty-switch-arm-breaks-to-the-last-epilogue-not-the-nearest.md).
 *
 * The wait callback has to be bound to a local: the original loads +0x10
 * once and both tests and calls that register, which a re-read of the field
 * across the call would not reproduce.
 *
 * sub_02011290, sub_02011324 and sub_02011328 carry no label in the
 * generated listing: none of the three saves `lr`, so disasm.py's prologue
 * sweep never fires and their bytes print as a `.word` run
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * The field script system instantiates this VM in overlay 10 at
 * func_02158BFC with a 609-entry command table at 0x0217062C; see the
 * "Script virtual machine" section of docs/ASSETS.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201126C.c \
 *       --addr 0x0201126C --thumb --cc 1.1p1
 */
void func_0201126C(ScriptVm *vm, void *user)
{
    func_020111EC(vm);
    vm->user = user;
}



void func_0201127C(ScriptVm *vm, u8 *pc)
{
    func_020111EC(vm);
    vm->pc = pc;
    vm->state = 1;
}



ScriptVm *sub_02011290(ScriptVm *vm)
{
    vm->state = 0;
    vm->pc = 0;
    return vm;
}



int func_02011298(ScriptVm *vm)
{
    u32 op;
    ScriptWaitFn wait;

    switch (vm->state) {
    case 0:
        return 0;
    case 2:
        wait = vm->wait;
        if (wait != 0) {
            if (wait(vm, vm->user) == 1) {
                vm->wait = 0;
                vm->state = 1;
            }
            return 1;
        }
        vm->state = 1;
        /* fall through */
    case 1:
        for (;;) {
            if (vm->pc == 0) {
                vm->state = 0;
                return 0;
            }
            op = func_02011330((struct Stream *)vm);
            if (op >= vm->params.cmd_count) {
                vm->state = 0;
                return 0;
            }
            if (vm->hook != 0) {
                if (vm->hook(vm, vm->user, vm->hook_arg, op) == 0) {
                    vm->state = 0;
                    return 0;
                }
            }
            if (vm->params.cmds[op](vm, vm->user) == 1) {
                break;
            }
        }
        break;
    default:
        vm->state = 0;
        break;
    }

    return 1;
}



void *sub_02011324(ScriptVm *vm)
{
    return vm->user;
}



void sub_02011328(ScriptVm *vm, ScriptHookFn hook, void *arg)
{
    vm->hook = hook;
    vm->hook_arg = arg;
}



/*
 *           func_020113B0, func_020113B4, func_020113C4
 *
 * Seven functions, no external calls at all, over two small structs read and
 * written by cursor.  Two of the seven carry no label in the generated
 * listing at all: func_0201134C and func_020113B0, both leaves whose
 * prologue (or total absence of one) saves no `lr`
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * func_020113B0 is four bytes, `str r1, [r0, #0x14]; bx lr`: the plain
 * setter of the +0x14 field that func_020113B4 and func_020113C4 reach only
 * through a history ring.
 *
 * func_02011330 and func_0201134C are a matched pair, a little-endian u16
 * and u32 read off a byte cursor at +0x14, advancing it by 2 and by 4.
 * func_0201134C carries no label in the generated listing: it opens with
 * `push {r4, r5}`, which saves no `lr`, so disasm.py's prologue sweep never
 * fires on it and its 48 bytes print as a `.word` run between func_02011330
 * and func_0201137C (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * Its four byte reads are built MSB-first through a Horner chain
 * (((0 + b3) << 8 + b2) << 8 + b1) << 8 + b0, which is what the register
 * allocator does with a `for` loop counting down; the two-byte version is
 * small enough that the same loop unrolls into the flat expression used
 * below.
 *
 * func_0201137C and func_02011398 are a fixed-capacity ring: a byte count at
 * +0xC bounded by a halfword capacity at +0x0, backed by a `u32` array
 * pointed to by +0x18.  func_0201137C pushes if there is room and returns
 * whether it did; func_02011398 pops the oldest entry, or 0 if the ring is
 * empty (and leaves the count at 0 rather than going negative).
 *
 * func_020113B4 and func_020113C4 are a different struct's accessors for a
 * plain u32 field at +0x14, the same offset func_020113B0 sets directly:
 * func_020113B4 pushes the field's old value onto a func_0201137C ring
 * before overwriting it with the new one, and func_020113C4 pops a
 * func_02011398 ring back into the field.  Both take the ring struct
 * pointer as the same first argument as the field's owner, so the two
 * structs are declared distinctly here (Ring and Cur) even though nothing
 * in this file proves they are not the same struct in the original; only
 * the offsets that are read are declared.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011330.c \
 *       --addr 0x02011330 --thumb
 */
u16 func_02011330(struct Stream *s)
{
    u8  b0, b1;
    u16 t;

    b0 = *s->cursor;
    s->cursor = s->cursor + 1;
    b1 = *s->cursor;
    s->cursor = s->cursor + 1;
    t = (u16)(b1 << 8);
    return b0 + t;
}


u32 func_0201134C(struct Stream *s)
{
    u8  b0, b1, b2, b3;
    u32 v;

    b0 = *s->cursor;
    s->cursor = s->cursor + 1;
    b1 = *s->cursor;
    s->cursor = s->cursor + 1;
    b2 = *s->cursor;
    s->cursor = s->cursor + 1;
    b3 = *s->cursor;
    s->cursor = s->cursor + 1;

    v = 0;
    v = v + b3;
    v = v << 8;
    v = v + b2;
    v = v << 8;
    v = v + b1;
    v = v << 8;
    v = v + b0;
    return v;
}



void func_0201137C(struct Ring *r, u32 v)
{
    if (r->count + 1 < r->cap) {
        r->buf[r->count] = v;
        r->count = r->count + 1;
    }
}


u32 func_02011398(struct Ring *r)
{
    if (r->count == 0) {
        return 0;
    }
    r->count = r->count - 1;
    return r->buf[r->count];
}



void func_020113B0(struct Cur *c, u32 v)
{
    c->unk14 = v;
}


void func_020113B4(struct Ring *r, u32 v)
{
    struct Cur *c = (struct Cur *)r;
    u32 old = c->unk14;
    func_0201137C(r, old);
    c->unk14 = v;
}


u32 func_020113C4(struct Ring *r)
{
    struct Cur *c = (struct Cur *)r;
    c->unk14 = func_02011398(r);
    return c->unk14;
}



void func_020113D0(char *p, int val)
{
    p[0xd] = 2;
    *(int *)&((struct Obj00005 *)p)->f10 = val;
}



/*
 * Fills a 12-byte buffer through func_0203F4CC and tail-hands its own
 * argument and the buffer's first word to func_020113F0, a table lookup
 * that is a documented near miss (src/matched/sub_02011410.c's header has
 * the details) and so is declared here only, not defined.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020113D8.c \
 *       --func func_020113D8 --addr 0x020113D8 --cc 1.1p1 --lang c99 --thumb
 */
u32 func_020113D8(u32 row)
{
    u32 buf[3];

    func_0203F4CC((struct RtcTime *)buf);
    return func_020113F0(row, buf[0]);
}



/*
 * vm.c, 0x020113F0..0x02011410: two byte lookups in constant 2D tables,
 * rows of 0x18 and 5 bytes.  Plain subscripts `tbl[row][col]` give the
 * image's `base + row * stride` then `ldrb [col, base]`; the old pending
 * park (byte-offset arithmetic, docs/notes/pkt_020113F0.c.txt) was capped on
 * the two single-pool rodata tables, which sole-ref/self now carries.
 */
int func_020113F0(int row, int col)
{
    return tbl_0209DF24[row][col];
}



u8 func_02011400(int row, int col)
{
    return tbl_0209DF10[row][col];
}



/*
 * ica_anime.c: is the animation in one of the two "finished" states.  Both
 * arms return the same 1, which is why the original reaches one epilogue
 * from both compares - it is a single disjunction, not two ifs.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011410.c \
 *       --addr 0x02011410 --thumb
 *   (tu, not one: the last two bytes of the extent are the linker's
 *    alignment padding up to the next function, which `one` reports as a
 *    size mismatch and would mark EXACT*.  The code itself is 54/22 bytes.)
 */
u32 func_02011410(u32 tz)
{
    switch (func_020113D8(tz)) {
    case 3:
    case 4:
        return 1;
    default:
        return 0;
    }
}




/*
 * ica_anime.c's 0x38-byte-object constructor: allocate, shared init, the
 * class-specific initialiser, then the load call.  Only the load call's
 * result is tested, so the failure path is the plain `return 0` and the
 * success path stores through the sibling and returns the object.  The
 * +0x0c field is re-read after func_020116E0 because the callee sets it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011428.c \
 *       --func func_02011428 --addr 0x02011428 --cc 1.1p1 --thumb
 */
void *func_02011428(u32 heap, u32 a1, u32 a2, u32 a3, u32 a4)
{
    struct IcaAnime *p = func_02030734(heap, 0x38, 0, (const char *)&sIcaAnimeFile, 0x54);

    func_020116C0(p);
    func_020116E0((u8 *)p, a1, a2, heap);
    if (func_020117D8((u8 *)p, p->f0c, (u8 *)a3, a4) == 0) {
        return 0;
    }
    func_0201183C(p, 0);
    return p;
}




/*
 * The 0x74-byte sibling of func_02011428 in the same original file: same
 * allocation, shared init and class initialiser, but the load call forwards
 * the two stacked arguments rather than a field.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201147C.c \
 *       --func func_0201147C --addr 0x0201147C --cc 1.1p1 --thumb
 */
void *func_0201147C(u32 heap, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5)
{
    struct IcaAnime *p = func_02030734(heap, 0x38, 0, (const char *)&sIcaAnimeFile, 0x74);

    func_020116C0(p);
    func_020116E0((u8 *)p, a1, a2, heap);
    if (func_020117D8((u8 *)p, a3, (u8 *)a4, a5) == 0) {
        return 0;
    }
    func_0201183C(p, 0);
    return p;
}


/*
 * ica_anime.c: the third constructor (line 0x90 of "ica_anime.c").  The
 * object is 0x38 bytes and the four-argument initialiser gets the heap back
 * as its last argument, which is where r3 = r5 comes from.  func_020116C0 gets
 * the object straight from the allocator, which is why no move precedes it.
 *
 * The tail is the pair every one of these constructors ends with -
 * func_02011770(p, p->f0c) and func_0201183C(p, 0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020114D0.c \
 *       --func func_020114D0 --addr 0x020114D0 --cc 1.1p1 --thumb
 */
void *func_020114D0(u32 heap, u32 a1, u32 a2)
{
    struct IcaAnime *p;

    p = func_02030734(heap, 0x38, 0, (const char *)&sIcaAnimeFile, 0x90);
    func_020116C0(p);
    func_020116E0((u8 *)p, a1, a2, heap);
    func_02011770((u8 *)p, p->f0c);
    func_0201183C(p, 0);
    return p;
}



/*
 * ica_anime.c, the third constructor of the group: same prologue, same
 * 0x38-byte allocation (a different source line), but the class
 * initialiser is func_02011770 and the result is not tested - it always
 * runs the shared teardown initialiser and returns the object.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011510.c \
 *       --func func_02011510 --addr 0x02011510 --cc 1.1p1 --thumb
 */
void *func_02011510(u32 heap, u32 a1, u32 a2, u32 a3)
{
    struct IcaAnime *p = func_02030734(heap, 0x38, 0, (const char *)&sIcaAnimeFile, 0xae);

    func_020116C0(p);
    func_020116E0((u8 *)p, a1, a2, heap);
    func_02011770((u8 *)p, a3);
    func_0201183C(p, 0);
    return p;
}



/*
 * ica_anime.c: destroy.  The one field that is a plain pointer (+0x04) goes
 * through the archive/handle call first, and the three heap buffers at
 * +0x1C, +0x20 and +0x24 are released only when the 0x34 flag says they were
 * allocated - all four calls are the same free function, including the last
 * one on the object itself.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011558.c \
 *       --addr 0x02011558 --thumb
 *   (tu, not one: the last two bytes of the extent are the linker's
 *    alignment padding up to the next function, which `one` reports as a
 *    size mismatch and would mark EXACT*.  The code itself is 54/22 bytes.)
 */
void func_02011558(struct IcaAnime *p)
{
    func_02049238(p->f04);
    if (p->f34 != 0) {
        if (p->f1c != 0)
            func_020307B0((void *)p->f1c);
        if (p->f20 != 0)
            func_020307B0((void *)p->f20);
        if (p->f24 != 0)
            func_020307B0((void *)p->f24);
    }
    func_020307B0(p);
}



/*
 * ica_anime.c, 0x02011590..0x02011610: the frame-clock advance and its two
 * neighbours, plus the two four-byte getters that sit between them (they
 * carry no label because they have no prologue, so they are written here as
 * what they are).
 *
 *   func_02011590   advance the clock, reset it if the frame count is
 *                   reached, and poke the animation when the new frame falls
 *                   outside [f14, f14 + f18)
 *   func_020115C0   the same advance but returning "already finished" when
 *                   the frame at entry is past the count
 *   func_020115EC   set the clock outright
 *   (0x02011608)    getter: +0x0C
 *   (0x0201160C)    getter: +0x10
 *
 * The range check is one disjunction in every case: the original reaches the
 * single `bl func_0201183C` from both compares.
 *
 * Signedness: the frame is `f10 >> 12` with an arithmetic shift (asrs), but
 * the compare against f0c is unsigned (bhi/bhs), so f0c is a u32 field while
 * the clock and the frame bounds are s32.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011590.c \
 *       --addr 0x02011590 --thumb
 */
u32 func_02011590(struct IcaAnime *p, s32 v)
{
    s32 f;
    u32 r = 0;

    p->f10 = p->f10 + v;
    f = p->f10 >> 12;
    if (p->f0c <= (u32)f) {
        p->f10 = 0;
        f = 0;
        r = 1;
    }
    if (f < p->f14 || (p->f14 + p->f18) <= f)
        func_0201183C(p, p->f10);
    return r;
}


u32 func_020115C0(struct IcaAnime *p, s32 v)
{
    s32 f = p->f10 >> 12;

    if ((u32)f < p->f0c) {
        p->f10 = p->f10 + v;
        f = p->f10 >> 12;
        if (f < p->f14 || (p->f14 + p->f18) <= f)
            func_0201183C(p, p->f10);
        return 0;
    }
    return 1;
}


void func_020115EC(struct IcaAnime *p, s32 v)
{
    s32 f = v >> 12;

    p->f10 = v;
    if (f < p->f14 || (p->f14 + p->f18) <= f)
        func_0201183C(p, v);
}



u32 func_02011608(struct Obj11244 *p)
{
    return p->fC;
}



u32 func_0201160C(struct Obj11245 *p)
{
    return p->f10;
}



/*
 * ica_anime.c, 0x02011610..0x02011688: three copies of one accessor on three
 * parallel field pairs, each of which copies a twelve-byte record out of a
 * table indexed by the current frame.
 *
 *   func_02011610   guard +0x28, table +0x1C
 *   func_02011638   guard +0x2C, table +0x20
 *   (0x02011660)    guard +0x30, table +0x24 - unlabelled in the listing
 *                   (no prologue: the function saves nothing), written here
 *                   as the third copy
 *
 * The index is `(f10 >> 12) - f14`, which is why the original does an asrs
 * by twelve and then a subtract before the multiply by twelve, and the copy
 * itself is one twelve-byte struct assignment (ldm/stm pair plus the third
 * word).  Returning 0 when the table pointer is null is what makes the two
 * epilogues.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011610.c \
 *       --addr 0x02011610 --thumb
 */
u32 func_02011610(struct IcaAnime *p, struct Rec12 *dst)
{
    if (p->f28 != 0) {
        dst[0] = ((struct Rec12 *)p->f1c)[(p->f10 >> 12) - p->f14];
        return 1;
    }
    return 0;
}


u32 func_02011638(struct IcaAnime *p, struct Rec12 *dst)
{
    if (p->f2c != 0) {
        dst[0] = ((struct Rec12 *)p->f20)[(p->f10 >> 12) - p->f14];
        return 1;
    }
    return 0;
}


u32 func_02011660(struct IcaAnime *p, struct Rec12 *dst)
{
    if (p->f30 != 0) {
        dst[0] = ((struct Rec12 *)p->f24)[(p->f10 >> 12) - p->f14];
        return 1;
    }
    return 0;
}



/*
 * Copy frame `idx % count` of the f1c Rec12 table out to dst when the table
 * length at +0x18 equals the count at +0x0C; returns 1, else 0.  EXACT* because
 * the listing extent (56) includes the 2-byte `movs r0, r0` pad after the
 * second epilogue; the 54 code bytes are exact.
 *
 * Load-bearing (wave 20, after five waves at 14 to 26 out):
 *  - `idx %= n;` writes the remainder back into the PARAMETER, which homes it
 *    in r2 (`adds r2, r1, #0` before the compare).  A named local coalesces
 *    with the helper's r1 return instead.
 *  - the table base as an integer: `u32 base = (u32)p->f1c;` with a u32 byte
 *    offset `off = idx * 12`, the first field read at base + off and the
 *    cursor advanced in place (`base += off`) for +4 and +8.  With the base as
 *    an integer the multiply goes into a copy of idx (`adds r3, r2, #0;
 *    muls r3, r0, r3`) and the base is loaded after 12, as in the image;
 *    every pointer spelling (&p->f1c[idx], t[idx], a struct cursor) multiplies
 *    idx in place.  Same family as
 *    docs/idioms/a-region-symbol-cast-to-u32-keeps-the-bound-an-add.md.
 *  - the two-return shape `if (==) { ...; return 1; } return 0;` gives the
 *    image's fall-through body and its two epilogues.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011688.c \
 *       --func func_02011688 --addr 0x02011688 --cc 1.1p1 --thumb
 */
u32 func_02011688(struct IcaAnime *p, struct Rec12 *dst, u32 idx)
{
    u32 n = p->f0c;

    idx %= n;
    if (p->f18 == n) {
        u32 off = idx * 12;
        u32 base = (u32)p->f1c;
        dst->a = *(s32_02011688 *)(base + off);
        base += off;
        dst->b = ((struct Obj11246 *)base)->f4;
        dst->c = ((struct Obj11246 *)base)->f8;
        return 1;
    }
    return 0;
}



void func_020116C0(struct IcaAnime *p)
{
    unsigned char *p0 = (unsigned char *)p;

    ((struct Obj00064 *)p0)->f0 = (unsigned short)0;
    *(int *)&((struct Obj00064 *)p0)->f4 = (int)0;
    *(int *)&((struct Obj00064 *)p0)->f8 = (int)0;
    *(int *)&((struct Obj00064 *)p0)->fC = (int)0;
    ((struct Obj00064 *)p0)->f10 = (int)0;
    ((struct Obj00064 *)p0)->f14 = (int)0;
    ((struct Obj00064 *)p0)->f18 = (int)0;
    *(int *)&((struct Obj00064 *)p0)->f1C = (int)0;
    *(int *)&((struct Obj00064 *)p0)->f20 = (int)0;
    *(int *)&((struct Obj00064 *)p0)->f24 = (int)0;
    *(int *)&((struct Obj00064 *)p0)->f28 = (int)0;
    *(int *)&((struct Obj00064 *)p0)->f2C = (int)0;
    *(int *)&((struct Obj00064 *)p0)->f30 = (int)0;
    *(int *)&((struct Obj00064 *)p0)->f34 = (int)0;
}



/*
 * Open four channels: a halfword tag at +0, a handset object at +4, a peer
 * object at +8, and then sub_0204944C(p->f04, p->f08, id, len, dest) for
 * ids 0, 4, 5 and 6 -- the last three writing one byte each into buf[2],
 * buf[1] and buf[0], i.e. backwards from the end of the four-byte buffer.
 *
 * `v = 1;` is a SEPARATE statement after the four calls, not the
 * declaration initialiser.  As `u32 v = 1;` at the top of the body the
 * assignment is hoisted to the function entry (r6 = 1 before the first
 * call, the zero constant landing in r4), and the result is a diff of two
 * instructions at the end: the original keeps 1 in r4 (the register the
 * dead a2 parameter was homed to) and the 0 in r6, and the guard stores
 * `r4 = r6` on the equal arm instead of `r6 = r4`.  Sinking the assignment
 * to its own statement after the last call reproduces the original
 * allocation exactly.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020116E0.c \
 *       --func func_020116E0 --addr 0x020116E0 --cc 1.1p1 --thumb
 */
void func_020116E0(u8 *p, u32 a1, u32 a2, u32 a3)
{
    u8 buf[4];
    u32 v;

    ((struct Obj00064 *)p)->f0 = (u16)a3;
    ((struct Obj00064 *)p)->f4 = sub_020490F4(a1, a3);
    ((struct Obj00064 *)p)->f8 = a2;
    sub_0204944C((struct ArcFile *)*(u32 *)&((struct Obj00064 *)p)->f4, a2, 0, 4, p + 0xc);
    sub_0204944C((struct ArcFile *)*(u32 *)&((struct Obj00064 *)p)->f4, ((struct Obj00064 *)p)->f8, 4, 1, buf + 2);
    sub_0204944C((struct ArcFile *)*(u32 *)&((struct Obj00064 *)p)->f4, ((struct Obj00064 *)p)->f8, 5, 1, buf + 1);
    sub_0204944C((struct ArcFile *)*(u32 *)&((struct Obj00064 *)p)->f4, ((struct Obj00064 *)p)->f8, 6, 1, buf);
    v = 1;
    if (buf[2] == 0) {
        v = 0;
    }
    ((struct Obj00064 *)p)->f30 = v;
    ((struct Obj00064 *)p)->f2C = (buf[1] != 0);
    ((struct Obj00064 *)p)->f28 = (buf[0] != 0);
}



void sub_02011770(u8 *p, int n)
{
    *(u32 *)&((struct Obj00064 *)p)->f18 = (u32)n;
    if (((struct Obj00064 *)p)->f28 != 0) {
        *(u32 *)&((struct Obj00064 *)p)->f1C = (u32)func_02030734((u32)((struct Obj00064 *)p)->f0, n * 0xc,
                                                  0, (const char *)g020A7270, 0x25c);
    }
    if (((struct Obj00064 *)p)->f2C != 0) {
        *(u32 *)&((struct Obj00064 *)p)->f20 = (u32)func_02030734((u32)((struct Obj00064 *)p)->f0, n * 0xc,
                                                  0, (const char *)g020A7270, 0x260);
    }
    if (((struct Obj00064 *)p)->f30 != 0) {
        *(u32 *)&((struct Obj00064 *)p)->f24 = (u32)func_02030734((u32)((struct Obj00064 *)p)->f0, n * 0xc,
                                                  0, (const char *)g020A7270, 0x264);
    }
    ((struct Obj00064 *)p)->f34 = 1;
}



/*
 * Lay out `a1` rows of `a2` bytes each at stride a1*0xc into the three
 * buffers the record declares at +0x1c, +0x20 and +0x24, but only where the
 * matching flag word at +0x28, +0x2c and +0x30 is set.  a3 is the caller's
 * byte budget: if it is smaller than a1*0xc times the number of live flags
 * nothing is written and the call answers 0.  +0x18 records the row count.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020117D8.c \
 *       --func func_020117D8 --addr 0x020117D8 --cc 1.1p1 --thumb
 */
int func_020117D8(u8 *a0, int a1, u8 *a2, int a3)
{
    int total;
    int step;
    int k;

    total = 0;
    step = a1 * 0xc;
    k = 0;
    if (((struct Obj00064 *)a0)->f28 != 0) {
        total += step;
    }
    if (((struct Obj00064 *)a0)->f2C != 0) {
        total += step;
    }
    if (((struct Obj00064 *)a0)->f30 != 0) {
        total += step;
    }
    if (a3 < total) {
        return 0;
    }
    if (((struct Obj00064 *)a0)->f28 != 0) {
        *(u8 * *)&((struct Obj00064 *)a0)->f1C = a2;
        k++;
    }
    if (((struct Obj00064 *)a0)->f2C != 0) {
        *(u8 * *)&((struct Obj00064 *)a0)->f20 = a2 + step * k;
        k++;
    }
    if (((struct Obj00064 *)a0)->f30 != 0) {
        *(u8 * *)&((struct Obj00064 *)a0)->f24 = a2 + step * k;
        k++;
    }
    *(u32 *)&((struct Obj00064 *)a0)->f18 = a1;
    return 1;
}



#define FX_F32_TO_FX32(x) ((s32)(((x) > 0) ? ((x) * 4096.0f + .5f) : ((x) * 4096.0f - .5f)))



/*
 * Load one frame of an ICA animation: the frame index is (q >> 12) modulo
 * the frame count s->f0c; the file offset is 8 + 12 * index per enabled
 * channel and the read size 12 * s->f18 per enabled channel.  The floats are
 * read into a scratch buffer (func_0204944C, fifth argument = destination),
 * converted with the TwlSDK FX_F32_TO_FX32 macro into the three Vec3 tables
 * (f30 gates f24, f2c gates f20, f28 gates f1c), then freed; s->f14 = q >> 12.
 *
 * Levers (wave 10), each measured; together 631 bytes out -> EXACT:
 *  - 0x0209C95C is _fadd and 0x0209CB8C is _fsub (layout/runtime_arm9.txt
 *    had them swapped until 2026-09-28).  With them declared that way the
 *    plain SDK macro `x > 0 ? x*4096.0f + .5f : x*4096.0f - .5f` reproduces
 *    both arms, including the (0.5, prod) / (prod, 0.5) argument orders.
 *  - the conversion is a MACRO over `f[k + j]`, not an inline function, and
 *    the buffer is `volatile float *`: the element is then loaded for the
 *    compare and again in the taken arm, off a byte offset that gets its own
 *    stack slot per site (the image's nine slots sp+0x18..0x38).
 *  - func_0204944C takes five arguments; the fifth is the buffer ([sp]).
 *  - `q >> 12` is written twice (the modulo and the final store) and never
 *    named: its CSE temporary takes the lowest spill slot (sp+4).  A named
 *    `frame` local lands above the i*12 temporaries (14 bytes out).
 *  - `i = 0` sits between the alloc and the fill call (the image stores it
 *    there, sharing the alloc's zero), and the loop is `for (; i < ...)`.
 *  - declaration order i, k, f, size, ofs, n.
 */
void func_0201183C(struct IcaAnime *s, s32 q)
{
    s32 i;
    s32 k;
    volatile float *f;
    u32 size;
    u32 ofs;
    u32 n;

    n = (q >> 12) % s->f0c;

    ofs = 8;
    size = 0;
    if (s->f30 != 0) ofs += n * 0xc;
    if (s->f2c != 0) ofs += n * 0xc;
    if (s->f28 != 0) ofs += n * 0xc;
    if (s->f30 != 0) size += s->f18 * 0xc;
    if (s->f2c != 0) size += s->f18 * 0xc;
    if (s->f28 != 0) size += s->f18 * 0xc;

    f = (volatile float *)func_02030734((u16)((s->f00 & 0x7fff) | 0x8000), size, 0, (const char *)&data_020A7270, 0x2bd);
    i = 0;
    func_0204944C((struct ArcFile *)s->f04, s->f08, ofs, size, (void *)f);

    k = 0;
    for (; i < s->f18; i++) {
        if (s->f30 != 0) {
            s->f24[i].x = FX_F32_TO_FX32(f[k]);
            s->f24[i].y = FX_F32_TO_FX32(f[k + 1]);
            s->f24[i].z = FX_F32_TO_FX32(f[k + 2]);
            k += 3;
        }
        if (s->f2c != 0) {
            s->f20[i].x = FX_F32_TO_FX32(f[k]);
            s->f20[i].y = FX_F32_TO_FX32(f[k + 1]);
            s->f20[i].z = FX_F32_TO_FX32(f[k + 2]);
            k += 3;
        }
        if (s->f28 != 0) {
            s->f1c[i].x = FX_F32_TO_FX32(f[k]);
            s->f1c[i].y = FX_F32_TO_FX32(f[k + 1]);
            s->f1c[i].z = FX_F32_TO_FX32(f[k + 2]);
            k += 3;
        }
    }
    func_020307B0((void *)f);
    s->f14 = q >> 12;
}



/*
 * Applies an HSV tint to a camera/light pair.  func_02011638 reports
 * the three fixed-point 4.12 HSV channels for the current scene; each
 * is converted to float, wrapped into range by repeated subtraction,
 * rescaled to the 0..65535 range func_020520FC wants, and turned back
 * into RGB.  The resulting colour is combined with the two constant
 * vectors at 0x0209DF84 and 0x0209DF90 (copied in as whole 12-byte
 * aggregates, ldm/stm), the scene's own basis is fetched by
 * func_02011610, and the three results are installed on the target.
 *
 * PARKED AT MATCH, not EXACT.  All 356 bytes are byte-correct and 33 of
 * the 35 relocation sites resolve; the two that do not are the ABS32
 * pool words at +0x150 and +0x154:
 *
 *   0209DF84   witnesses image wide: 1, of them inside this range: 1
 *   0209DF90   witnesses image wide: 1, of them inside this range: 1
 *
 * Blocking evidence class: `literal', and there is none.  Each address
 * appears in exactly one literal pool in the whole image (0x02011CDC
 * and 0x02011CE0), which is this function's own pool, so the only
 * witness for each is inside the compared range and attest() refuses
 * it.  `--suggest-split' confirms no cut helps: the range is one
 * function, and it reports "0 piece(s), 1 function(s) left out".
 * Nothing in the C is in question -- this unsticks the moment some
 * other function referencing 0x0209DF84 or 0x0209DF90 is filed EXACT,
 * or the two objects gain a `matched' witness of their own.
 *
 * Shape notes that cost real time and are worth keeping:
 *   - the three channel values must be bound to named `u16' locals
 *     before the func_020520FC call.  Written inline as
 *     `(u16)(u32)(65535.0f * (h / 360.0f))' the lsls/lsrs #0x10 pair
 *     after each _ffixu disappears (about 10 bytes short).
 *   - the scratch the two func_0207B51C calls share is 36 bytes, not
 *     12: `struct Vec3 rgb[3]'.  With a plain `struct Vec3' the whole
 *     frame comes out `sub sp, #0x68' instead of `sub sp, #0x80' and
 *     nothing else differs, so the 24 extra bytes are real declared
 *     storage above 0x5c that this function never reads back.
 *   - the wrap-around is `h += 360.0f': 0x0209C95C is the soft-float
 *     add.  `h = h + 360.0f' puts the constant first (see docs/idioms/
 *     a-soft-float-add-puts-the-constant-first-unless-it-is-a-compound-
 *     assignment.md) and no longer matches.
 *   - declaration order is stack order: rgb highest, then hsv, a, b,
 *     basis, out, t0, t1.  Any other order shifts every sp offset.
 */
void func_02011B8C(void *dst, void *ctx)
{
    struct Vec3 rgb[3];
    s32 hsv[3];
    struct Vec3 a;
    struct Vec3 b;
    struct Vec3 basis;
    struct Vec3 out;
    struct Vec3 t0;
    struct Vec3 t1;
    u16 ch;
    u16 cs;
    u16 cv;
    float h;
    float s;
    float v;

    a = data_0209DF84;
    b = data_0209DF90;

    func_02011638(ctx, (struct Rec12 *)hsv);

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
    func_020520FC(ch, cs, cv, (struct Mtx33 *)rgb);

    func_0207B51C(&a, rgb, &t0);
    func_0207B51C(&b, rgb, &t1);

    func_02011610(ctx, (struct Rec12 *)&basis);
    func_0207C9D0(&basis, &t0, &out);

    func_02048AFC(dst, &basis);
    func_02048B44(dst, &out);
    func_02048B20(dst, &t1);
}



/*
 * Twelve bytes of stack filled by func_02011610 from the *second* argument
 * (the first word handed to it is r1, not r0), then the buffer goes to the ARM
 * function func_02048AFC together with the original first argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011CF0.c \
 *       --func func_02011CF0 --addr 0x02011CF0 --cc 1.1p1 --thumb
 */
void func_02011CF0(void *a0, void *a1)
{
    u8 buf[0xc];

    func_02011610(a1, (struct Rec12 *)buf);
    func_02048AFC(a0, (struct Vec3 *)buf);
}



/*
 * Identical to func_02011CF0 except for the second callee, func_02048B44.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011D0C.c \
 *       --func func_02011D0C --addr 0x02011D0C --cc 1.1p1 --thumb
 */
void func_02011D0C(void *a0, void *a1)
{
    u8 buf[0xc];

    func_02011610(a1, (struct Rec12 *)buf);
    func_02048B44(a0, (struct Vec3 *)buf);
}



/*
 * func_02011D28 calls its argument, if not null, purely for effect: the
 * call falls straight through into `mvns r0, r4` with no branch around it,
 * so the return value is always the bitwise complement of the function
 * pointer itself, never whatever the call returned.
 *
 * func_02011D34 calls func_0203F0A8 twice and returns nothing, a debug
 * marker pair (begin/end) around nothing in between.
 *
 * func_02011D40 and func_02011D7C, on either side of the function between
 * this pair, were a documented register-swap near miss on their single
 * `struct.unk04 += 1`; now EXACT (src/matched/func_02011D40.c and
 * src/matched/func_02011D7C.c). The fix was declaring the global as a
 * real struct and using field syntax (`g_02146248.unk04 += 1`) instead
 * of raw pointer-plus-offset arithmetic; not merged into this unit
 * because func_02011D60 between them stays out of the manifest (see
 * below).
 *
 * The function between them, func_02011D60, reproduces every byte the
 * comparison covers, but is left out of the manifest: the listing's extent
 * runs two bytes long across the `00 00` alignment pad in front of
 * func_02011D7C, an `EXACT*` this territory's policy does not accept
 * because the follower carries a real label rather than being the
 * unlabelled-follower case `EXACT*` is meant for.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011D28.c \
 *       --addr 0x02011D28 --thumb
 */
u32 func_02011D28(u32 (*fn)(void))
{
    if (fn != 0) {
        fn();
    }
    return ~(u32)fn;
}



void func_02011D34(void)
{
    func_0203F0A8();
    func_0203F0A8();
}



/*
 * Allocates 0x7F bytes off heap 0 through sub_020056A0.c's allocator
 * wrapper, tagged with func_02011D34's own address (the SDK debug-tag
 * convention: the tag is the calling site, here literally the sibling
 * debug-marker function's address), discards the result, and bumps
 * g_02146248's +4 counter. See unit_02011D28.c's header for the sibling
 * func_02011D7C and the documented near miss on this increment.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02011D40.c \
 *       --func func_02011D40 --addr 0x02011D40 --cc 1.1p1 --thumb
 */
void func_02011D40(void)
{
    sub_020056A0((u32)func_02011D34, 0, 0x7f);
    g_02146248.unk04 += 1;
}


void func_02011D60(void)
{
    func_0203064C(9, 5, 5 << 10);
    func_02011F24();
    func_020306F0(5);
}


/*
 * Allocates 0x7F bytes off heap 0 through sub_020056A0.c's allocator
 * wrapper, tagged with func_02011D34's own address (the SDK debug-tag
 * convention: the tag is the calling site, here literally the sibling
 * debug-marker function's address), discards the result, and bumps
 * g_02146248's +4 counter. See unit_02011D28.c's header for the sibling
 * func_02011D40 (src/matched/func_02011D40.c, converted to EXACT
 * alongside this one) and the formerly-documented near miss on this
 * increment: the `struct.unk04 += 1` register swap resolves when the
 * global is declared as a real struct (`g_02146248.unk04 += 1`) rather
 * than accessed through raw pointer-plus-offset arithmetic.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02011D7C.c \
 *       --func func_02011D7C --addr 0x02011D7C --cc 1.1p1 --thumb
 */
void func_02011D7C(void)
{
    sub_020056A0((u32)func_02011D34, 0, 0x7f);
    g_02146248.unk04 += 1;
}


/*
 * promoted: wave 21 lane T, EXACT (match.py one, 25 of 25 relocations)
 *           once the ov230d token let the probe targets resolve
 *
 * ica_anime.c: scene bring-up.  Loads overlay 230, runs three checksum
 * probes over this family's own code (func_02011D28 to func_02011D40,
 * func_02011D60, func_02011D7C; each result compared with the complement of
 * the end address), creates three heaps through func_0203064C, allocates
 * the work block and publishes it to g_02146248, then, when the probe
 * results do not add up to a multiple of 0x12AF, runs a func_0200C258-counted
 * loop of func_02011D40.
 *
 * Byte-correct: 272 of 272 bytes, 0 concrete bytes out (match.py one,
 * dsi/1.1p1, 2026-09-24 wave 21 lane H).  The lever that closed it after
 * eight waves at 8 out: the probes' shared start address is held in a u32
 * local (`start = (u32)func_02011D28;`) and cast back at each call
 * (docs/idioms/an-address-held-in-a-u32-local-is-reloaded-at-every-site.md).
 * The local's web spans the second heap call, so the argument 4 there is
 * rematerialised (`movs r2,#4 ... movs r1,#4; lsls r2,r2,#14`) instead of
 * being common-subexpression-eliminated into r1, which is what the image
 * does; the single-call shape `off = 0; if (flag == 0) off = 0x191;` is the
 * right control flow once that holds.
 *
 * Probe targets (wave 21 lanes H2 and T): 0x021882A0, 0x02188354 and
 * 0x02188390 are slots 0, 3 and 4 of the six ARM thunk slots ov230's first
 * static initialiser (func_02188408) decrypts in place when this function
 * loads the overlay.  The ROM bytes there are ciphertext, so ov230's ROM
 * listing never labels them; tools/ovcrypt.py replays ov230's own
 * decryptor (every range checked to be a clean ARM function ending in a
 * return) and asm/ov230d/ov230d.s lists the result.  With the `ov230d`
 * token on the three symbols: lines they resolve as sole-ref/code against
 * that listing: 25 of 25 sites (ov230_id as overlay_id, func_0215FA00
 * sole-ref/code with the ov010 hint).
 */
u32 func_02011D9C(void *a0, u32 a1, u32 a2)
{
    u32 size;
    u32 base;
    u32 flag;
    u32 off;
    void *p;
    s32 n;
    s32 i;
    u32 start;

    size = func_02011F24();
    start = (u32)func_02011D28;
    base = 0xc35ffb;
    func_02034AC4((int)ov230_id);
    flag = 0;
    if (func_021882A0((void (*)(void))start, func_02011D40, 0) == ~(u32)func_02011D40)
        flag = 1;
    base += flag * 0x47;
    func_0203064C(1, 3, 0xa << 12);
    flag = 1;
    if (func_02188354((void (*)(void))start, func_02011D60, 0) != ~(u32)func_02011D60)
        flag = 0;
    off = 0;
    if (flag == 0)
        off = 0x191;
    func_0203064C(1, 4, 4 << 14);
    func_02188390((void (*)(void))start, func_02011D7C, 0);
    func_0203064C(9, 5, 5 << 10);
    func_02034A5C((s32)ov230_id);
    p = func_0203159C(a0, size, 3);
    func_02082BCC(p, 0, size);
    g_02146248.unk00 = p;
    func_02011FB8(p, 3, a2);
    func_02012108(p, func_0215FA00(p, a2));
    if ((base + off) % 0x12af != 0) {
        n = func_0200C258(func_02012F08(func_020120F4(p)));
        for (i = 0; i < n; i++)
            func_02011D40();
    }
    return 1;
}



/*
 * Only the fourth parameter is used, and it is moved straight out of r3 into
 * r0 at entry - a one-argument wrapper whose first three arguments are the
 * caller's leftovers (r0..r2 are untouched, which is what the prologue's
 * `adds r0, r3, #0` says).
 *
 *           call inside this function (checked: `label` finds no outside
 *           branch, and no EXACT manifest entry covers 0x02011FCC, so
 *           `matched` does not reach it either).  No cut helps - shrinking
 *           the range to this function keeps the call inside it.  Writing
 *           0x02011FCC (144 bytes, packet pkt_02011F28) as an EXACT entry
 *           would close this one; nothing else will.
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02011EAC.c \
 *       --func func_02011EAC --addr 0x02011EAC --cc 1.1p1 --thumb
 */
u32 func_02011EAC(u32 a0, u32 a1, u32 a2, u32 a3)
{
    if (func_02011FCC((char *)a3) != 0)
        return 1;
    return 0;
}



/*
 * Promoted from src/pending/ in the second 0-64 byte band pass (lane 1).  It
 * was parked there on the call to 0x02012088 only; func_02012088 now has an
 * EXACT entry of its own, so the site resolves through the `matched` class and
 * the file needs no change.  The fourth parameter is moved out of r3 at entry
 * and passed first; then the first parameter; the three func_020306F0 calls
 * with consecutive ids 3, 4, 5 and a final func_02087BCC(0).  Returns 1.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011EC0.c \
 *       --func func_02011EC0 --addr 0x02011EC0 --cc 1.1p1 --thumb
 */
u32 func_02011EC0(u32 a0, u32 a1, u32 a2, u32 a3)
{
    func_02012088((struct IcaAnimeInst *)a3);
    func_020315D4((struct S020315D4 *)a0);
    func_020306F0(3);
    func_020306F0(4);
    func_020306F0(5);
    func_02087BCC(0);
    return 1;
}



/*
 * The object at 0x02146248, seen through its +0x08 field: the pool words are
 * 0x02146250 (the address of +0x08, used both for the 0x14-byte clear and
 * for the return value), 0x02146248 and 0x02146254 (= +0x0C, the destination
 * of the twelve-byte record copy).  So the struct is
 * `{ pad[8]; u32 f8; Rec12 rec; u16 f18; u16 f1a; }` and the function
 * clears +0x08..+0x1C, stores two scalars, copies the record in and stores
 * one more scalar.
 *
 * The scalar store to +0x08 goes through the +0x08 pointer, the two
 * halfwords go through the +0x00 base, and the copy is one twelve-byte
 * aggregate assignment (the ldm/stm pair plus the third word).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011EEC.c \
 *       --func func_02011EEC --addr 0x02011EEC --cc 1.1p1 --thumb
 */
void *func_02011EEC(u32 a0, u16 a1, struct Rec12 *a2, int a3)
{
    func_02082BCC(&g_02146248.f8, 0, 0x14);
    g_02146248.f8 = a0;
    g_02146248.f18 = a1;
    g_02146248.rec = *a2;
    g_02146248.f1a = a3;
    return &g_02146248.f8;
}



/*
 * Four bytes, `movs r0, #0x34; bx lr`: the sizeof getter of the context record
 * whose accessors are src/matched/unit_020120F0.c and
 * src/matched/unit_02012204.c.  It is what pins that struct's size, and the
 * declaration here is the same one those two files carry, so the three check
 * each other.  It is a file of its own because the functions on either side of
 * it are not matched yet.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02011F24.c  *       --addr 0x02011F24 --thumb
 */
u32 func_02011F24(void)
{
    return sizeof(struct Ctx);
}



/*
 * Initialise an ica_anime record (struct IcaAnime, docs/families/ica_anime.h)
 * for resource id `id`: open the handle (+0x08), clear the clock words,
 * load the table (+0x1c) and build its companion (+0x24) and the +0x2c
 * object from it, clear +0x32 and bit 0 of +0x33, then reset and start.
 *
 * The note's 8-byte r0/r1 "tie" (docs/notes/pkt_02011F28.c.txt) was a
 * misread arity: func_020261E4 takes TWO arguments (its own matched file
 * reads r1), and the second is the table just stored at +0x1c, passed as
 * `p->f1c` -- which the compiler forwards from the register, hence the
 * `adds r1, r0, #0` the image has before the id reload.  Written as a
 * struct, not raw pointer casts.  EXACT* only because the 2-byte pad at
 * 0x02011F8E runs the extent to 0x02011F90.
 */
void func_02011F28(struct IcaAnimeInst *p, u16 id, u32 a2)
{
    p->f00 = id;
    p->f04 = a2;
    p->f08 = func_02031324(p->f00);
    p->f0c = 0;
    p->f10 = 0;
    p->f14 = 0;
    p->f18 = 0;
    p->f1c = func_020124F4(p->f00);
    p->f20 = 0;
    p->f24 = func_020261E4(p->f00, p->f1c);
    p->f28 = 0;
    p->f2c = func_0202B4BC(p->f1c, id);
    p->f32 = 0;
    p->f33_0 = 0;
    func_02012248(p);
    func_020122A4((unsigned int)p);
    func_020139B0(id);
}



/*
 * Teardown: two calls on the object itself, then three on its words at +0x2c,
 * +0x1c and +0x24, then a final no-argument call.  Every callee resolves on its
 * own manifest entry or on a label outside the range, so the file is EXACT up to
 * the two bytes of section padding after the pop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011F90.c \
 *       --func func_02011F90 --addr 0x02011F90 --cc 1.1p1 --thumb
 */
void func_02011F90(u32 *o)
{
    func_020122B4(o);
    func_02012258(o);
    func_0202B4F0((unsigned char *)o[0xb]);
    func_02012704((unsigned char *)o[7]);
    func_02026250((void *)o[9]);
    func_02013A48();
}



/*
 * The object goes through func_02011F28 with r0-r2 untouched, then one field
 * destructor and a global call.
 *
 *           (its only caller in the image is this function) and 0x020267BC at
 *           +0x0A.  Both are byte-correct here; the range cannot be cut to
 *           free them because the call is inside the only function that makes
 *           it.  Folding 0x02011F28 into the same unit would take the packet
 *           to 0x02011F28.. and is possible - see the note in
 *           docs/notes/pkt_02011F28.c.txt.
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02011FB8.c \
 *       --func func_02011FB8 --addr 0x02011FB8 --cc 1.1p1 --thumb
 */
void func_02011FB8(struct IcaAnimeInst *p, u16 id, u32 a2)
{
    func_02011F28(p, id, a2);
    func_020267BC((u32)p->f1c);
    func_02021438();
}



/*
 * Byte-correct, MATCH-capped: all 144 concrete bytes reproduce, the four
 * remaining wildcards are call sites whose targets live in OTHER PACKETS and
 * have no witness outside this range:
 *
 *   +0034  bl func_02012380   -> pkt_02012380
 *   +003A  bl func_0202627C   -> pkt_0202627C
 *   +0052  bl func_0202B500   -> pkt_0202B500
 *   +0058  bl func_02021464   -> pkt_02021464
 *
 * Each reports `no witness outside 02011FCC..02012060`, i.e. the only branch
 * anywhere in the image reaching them is the call in this function, so the
 * `label` class cannot attest them and no cut frees them.  Blocking class:
 * label.  Nothing in this C changes when those packets are filed -- the file
 * graduates for free.
 *
 * Two spellings this function pinned down:
 *
 *  - The last guard is ONE conjunction, `a == 0 && b == 0 -> return 1`.  The
 *    equivalent disjunction (`a != 0 || b != 0 -> return 0`) makes mwcc pick
 *    the other arm as the fall-through and comes out four bytes of wrong
 *    layout: `bne #0x2012054` + `beq` + the two `movs r0` swapped, where the
 *    original branches BOTH tests to a shared out-of-line `movs r0,#0; pop`
 *    and falls through to `movs r0,#1`.
 *  - The state word at +0x0c is re-read from memory at each use rather than
 *    cached in a register, so it is spelled as the field every time.
 */
int func_02011FCC(char *p)
{
    func_020120A4(p);
    if (func_02012A24((const struct BigObj *)((struct Obj01458 *)p)->f1C) != 0)
        func_02035614(0x1e);
    if (func_020129FC((struct BigObj *)((struct Obj01458 *)p)->f1C) == 0) {
        func_020123D8(p, (unsigned int (*)(void *, void *))((struct Obj01458 *)p)->f10, (void *)((struct Obj01458 *)p)->f14);
        func_0201205C((struct IcaAnimeInst *)p);
        func_02012380(p);
        func_0202627C((struct Comm *)((struct Obj01458 *)p)->f24);
    }
    ((struct Obj01458 *)p)->fC = func_02031330((void *)((struct Obj01458 *)p)->f8);
    func_02028A14((struct T *)func_02012A30((const struct BigObj *)((struct Obj01458 *)p)->f1C));
    func_0202B500((unsigned char *)((struct Obj01458 *)p)->f2C);
    func_02021464((unsigned char *)((struct Obj01458 *)p)->f1C);
    if (func_02012A24((const struct BigObj *)((struct Obj01458 *)p)->f1C) != 0)
        func_02035614(0x3c);
    if (((struct Obj01458 *)p)->fC == 2 || ((struct Obj01458 *)p)->fC == 0)
        func_0200F7B8(0);
    if (((struct Obj01458 *)p)->fC == 0 && ((struct Obj01458 *)p)->f18 == 0)
        return 1;
    return 0;
}


extern int func_02188BE8(void *v);   /* overlay-resident */
extern u32 func_020121CC(struct IcaAnimeInst *p);

/*
 * Three nested tests sharing one epilogue: the object is driven through
 * func_020121CC only when func_020120D8 returns 0, func_02012114 returns 1
 * and the overlay call returns 1 as well.  That last call's argument is
 * func_0201210C(p)'s result - r0 is not reloaded in between, which is what
 * the source's nesting says.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201205C.c \
 *       --func func_0201205C --addr 0x0201205C --cc 1.1p1 --thumb
 */
void func_0201205C(struct IcaAnimeInst *p)
{
    if (func_020120D8((char *)p) == 0) {
        if (func_02012114((const struct Ctx *)p) == 1) {
            if (func_02188BE8(func_0201210C((const struct Ctx *)p)) == 1)
                func_020121CC(p);
        }
    }
}


/*
 * The tail of the packet's small table walkers: two loads off the
 * g_02146228 pair and one store, 18 bytes, every relocation a label outside
 * the range.  It re-verified EXACT after func_02010F50 and func_02010EEC were
 * filed in pkt_02010EEC (the same two tables), so the entry is a chain payoff.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012088.c \
 *       --func func_02012088 --addr 0x02012088 --cc 1.1p1 --thumb
 */
void func_02012088(struct IcaAnimeInst *p)
{
    func_0203133C((struct S020314B8 *)p->f08);
    func_02011F90((u32 *)p);
}




/*
 * The word pair setter that follows func_02012088's epilogue at 0x0201209A:
 * two words at +0x10 and +0x14, no prologue, no label.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0201209C.c \
 *       --func sub_0201209C --addr 0x0201209C --cc 1.1p1 --thumb
 */
void sub_0201209C(void *o, u32 v1, u32 v2)
{
    *(u32 *)&((struct Obj00020 *)o)->f10 = v1;
    ((struct Obj00020 *)o)->f14 = v2;
}


void func_020120A4(char *p)
{
    ((struct Obj15622 *)p)->f31 = (unsigned char)func_020123C4(p);
}



/*
 * ica_anime.c.  Forwards the +0x08 handle and the caller's other three
 * arguments to the ARM routine at 0x02031348.  The frame
 * (push {r3,lr} / blx / pop {r3,pc}) where every one-argument spelling gets
 * a pool-word-and-bx sibling call (26 spellings in
 * docs/notes/pkt_020120B4.c.txt) is the tail-call-cannot-pass-a-fourth-
 * argument idiom: r1-r3 are passed through untouched, so they cost no
 * instruction, and r3 being live blocks the sibling call.  The arity is
 * independently evidenced by the only caller, func_020120C0, which sets up
 * r1, r2 and r3 (r3 = r0) before the bl.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020120B4.c \
 *       --func func_020120B4 --addr 0x020120B4 --cc 1.1p1 --thumb
 */
void func_020120B4(struct IcaAnimeInst *p, u32 id, void *a, void *b)
{
    func_02031348(p->f08, id, a, b);
}



/*
 * note:     wave 17 (overlay_id class): EXACT. The pooled overlay-id site
 *           ov021_id (21) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 * evidence: s0x021D359C lies in the windows of ov021 (data) and ov114 (bss),
 *           so the ov021 hint needs outside support.  The same call passes
 *           ov021_id (0x15, attested `overlay_id`) and this pointer to the
 *           proc system: func_020120B4 -> func_02031348 -> func_020314F4 ->
 *           func_02031538 stores the id at Proc+4 and the pointer at Proc+0
 *           (ProcData), and func_020315F0 loads overlay Proc+4
 *           (func_02034AC4) before it calls any ProcData callback.  So ov021
 *           is resident whenever the pointer is dereferenced.  Independently,
 *           ov021's bytes at 0x021D359C are three Thumb pointers
 *           0x02187F01/0x02187FD1/0x02187FE9, each a func_ label in
 *           ov021's own listing (init/main/end), while ov114 holds bss there.
 *           With the hint the site attests as `data_table` from ov021's bytes.
 *
 * Four arguments, and the first is the same object twice: the pool words are
 * a small constant 0x15 (an absolute linker symbol, not a literal - see
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md, 21 is
 * an overlay id) and the overlay-space address 0x021D359C.  func_020120B4
 * itself only reads r0, which is why its ten-byte body says nothing about
 * this call's arity.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020120C0.c \
 *       --func func_020120C0 --addr 0x020120C0 --cc 1.1p1 --thumb
 */
void func_020120C0(struct IcaAnimeInst *p)
{
    func_020120B4(p, (u32)ov021_id, &s0x021D359C, p);
}


int func_020120D8(char *p)
{
    if (func_020123C4(p))
        return 1;
    return ((struct Obj15623 *)p)->f31;
}



/*
 *           func_02012108, func_0201210C, func_02012110, func_02012114,
 *           func_02012124, func_0201212C, func_02012134, func_02012138,
 *           func_0201213C, func_02012144, func_0201214C
 *
 * 104 bytes, 0x020120F0..0x02012158, 15 functions, none of which carries a
 * label: every one of them is a two- or three-instruction accessor on a
 * 0x34-byte context record, and the whole run arrives in the listing as .word
 * data between two literal pools.
 *
 * The size of the record is not a guess: func_02011F24 is
 * `movs r0, #0x34; bx lr`, its sizeof getter, and it is matched in
 * src/matched/unit_02011F24.c against the same declaration.  The two byte
 * fields at +0x30 and +0x32 cost an `adds r0, #0x30` each because the Thumb
 * `strb` immediate only reaches +31, which is
 * docs/idioms/thumb-immediate-reach-costs-an-adds.md and not a pointer in the
 * source.
 *
 * func_020120F8 and func_0201214C are tail calls through pool words: the
 * first hands +0x1C to func_020127A4 and the second to func_02012BB0, and
 * both are ABS32 against a Thumb target, so the pool word is odd.
 *
 * 0x02012158, 12 bytes, is a third tail call of the same shape and is a near
 * miss.  Its pool word holds 0x02012BC9, and func_02012BC8 has no label in the
 * listing (it has no register-saving prologue) and no other reference anywhere
 * in the image, so neither the `label` nor the `literal` class has a witness
 * outside the twelve bytes under test.  Every concrete byte reproduces from
 *
 *     void func_02012158(const struct Ctx *p, u32 v)
 *     {
 *         func_02012BC8(p->unk1C, v);
 *     }
 *
 * that closes 0x02012BC8 itself; see src/matched/unit_02012AE4.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020120F0.c \
 *       --addr 0x020120F0 --thumb
 */
u32 func_020120F0(const struct Ctx *p)
{
    return p->unk0C;
}


void *func_020120F4(const struct Ctx *p)
{
    return p->unk1C;
}


u8 *func_020120F8(const struct Ctx *p)
{
    return func_020127A4(p->unk1C);
}


u32 func_02012104(const struct Ctx *p)
{
    return p->unk18;
}


void func_02012108(struct Ctx *p, u32 v)
{
    p->unk18 = v;
}


void *func_0201210C(const struct Ctx *p)
{
    return p->unk20;
}


void func_02012110(struct Ctx *p, void *v)
{
    p->unk20 = v;
}


u32 func_02012114(const struct Ctx *p)
{
    if (p->unk20 != 0) {
        return 1;
    }
    return 0;
}


void func_02012124(struct Ctx *p, u32 v)
{
    p->unk30 = v;
}


u8 func_0201212C(const struct Ctx *p)
{
    return p->unk30;
}


u32 func_02012134(const struct Ctx *p)
{
    return p->unk2C;
}


u32 func_02012138(const struct Ctx *p)
{
    return p->unk24;
}


void func_0201213C(struct Ctx *p, u32 v)
{
    p->unk32 = v;
}


u8 func_02012144(const struct Ctx *p)
{
    return p->unk32;
}


u32 func_0201214C(const struct Ctx *p)
{
    return func_02012BB0(p->unk1C);
}


void func_02012158(char *p, unsigned int v)
{
    func_02012BC8((unsigned char *)((struct Obj15624 *)p)->f1C, v);
}


/*
 *           listing but its only caller in the whole image is the bl at
 *           +0x38 inside this range, so `label` has no outside witness and
 *           sole-ref/code does not consider overlay starts.  Every concrete
 *           byte is right (MATCH*: the extent runs over the 2-byte pad).
 *
 * The note's 4-byte r0/r1 "tie" (docs/notes/pkt_02012164.c.txt) was a
 * misread arity: func_02012AC8 is `ldrh r0, [r0]; bx lr`, a getter taking
 * the pointer func_020120F8 returns, and func_02013D34 takes that u16 in
 * r0 -- so the image keeps it in r0 across the p->f32 test and reads the
 * byte through r1.  `id = func_02012AC8(func_020120F8(p))` then
 * `func_02013D34(id)` closes it.
 */
u32 func_02012164(struct IcaAnimeInst *p)
{
    u16 id;

    func_02012138((const struct Ctx *)p);
    id = func_02012AC8((const struct Rec44 *)func_020120F8((const struct Ctx *)p));
    if (p->f32 == 0
     && func_02013D34(id) == 0
     && func_0200FB24() == 0
     && func_0201214C((const struct Ctx *)p) == 1
     && func_02158318((int)p) == 1
     && !(func_02035390() == 1 && func_020353B0() == 1)) {
        if (func_020090E0((const struct Sub020090B0Obj *)func_0200921C(p->f1c)) != 0) {
            return 1;
        }
    }
    return 0;
}



/*
 * Three tests, one epilogue: the handle returned by func_02012138(p) is
 * checked with two externals (both called with it - r0 is not reloaded), then
 * the object is driven through func_02012164 and only a result of exactly 1
 * reaches func_020263D8(handle, 1, p).  The nested ifs are what give all
 * three the same `return 0` at the end.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020121CC.c \
 *       --func func_020121CC --addr 0x020121CC --cc 1.1p1 --thumb
 */
u32 func_020121CC(struct IcaAnimeInst *p)
{
    u32 h = func_02012138((const struct Ctx *)p);

    if (func_0203CD98() == 0) {
        if (func_02026454((void *)h) == 0) {
            if (func_02012164(p) == 1) {
                func_020263D8((struct Comm *)h, 1, (u32)p);
                return 1;
            }
        }
    }
    return 0;
}



/*
 * The getter and the clearer of bit 0 of the byte at +0x33 of the same
 * 0x34-byte context record src/matched/unit_020120F0.c describes.  The
 * `lsls #0x1f` / `lsrs #0x1f` pair is a one bit field, not a cast: 32 - 31 is
 * not an integer width, which is
 * docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md, and the
 * clearer's `movs r1, #1` / `bics` is what `p->unk33_0 = 0;` compiles to
 * because Thumb has no immediate bic.  Neither function has a relocation.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012204.c  *       --addr 0x02012204 --thumb
 */
u32 func_02012204(const struct Ctx *p)
{
    return p->unk33_0;
}


void func_02012210(struct Ctx *p)
{
    p->unk33_0 = 0;
}



/*
 * ica_anime.c: when func_0201214C(p) says yes, stop the playback
 * (func_02012158(p, 0), which is the tail call in the pending file
 * src/pending/func_02012158.c) and set bit 0 of the byte at +0x33.
 *
 * The bit update is one expression, `(f & ~1) | 1`: the original loads the
 * byte once, clears with `bics` and sets with `orrs` - two statements would
 * be two loads and two stores (see
 * docs/idioms/an-and-not-is-what-emits-bic.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012220.c \
 *       --func func_02012220 --addr 0x02012220 --cc 1.1p1 --thumb
 */
void func_02012220(struct IcaAnimeInst *p)
{
    if (func_0201214C((const struct Ctx *)p) != 0) {
        func_02012158((char *)p, 0);
        p->f33_0 = 1;
    }
}



/*
 * Promoted from src/pending/func_02012248.c.  The C never changed; the ISA
 * on the second symbols line did.  The tail call goes through the pool word
 * 0x02035138, i.e. an ARM target with no Thumb bit - the parked copy
 * declared it `thumb`, so the word match.py looked for was 0x02035139 and
 * the second pool holding 0x02035138 (at 0x02012260, in the next function,
 * outside this range) could not be seen.  Declared `arm`, the `literal`
 * class resolves the site and the entry is EXACT.  A `bx r3` tail call
 * always has a pool word, and the pool word's low bit is the only place the
 * callee's ISA shows up - a wrong declaration hides the witness silently.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012248.c \
 *       --func func_02012248 --addr 0x02012248 --cc 1.1p1 --thumb
 */
void func_02012248(struct IcaAnimeInst *p)
{
    func_02035138((void *)func_02012220, (u32)p);
}


void func_02012258(void *o)
{
    func_02035138(0, 0);
}



int func_02012264(int a0, int a1, int a2, int a3){ int t0, t1, t2, t3, t4; t0 = func_02012138((const struct Ctx *)a0); t1 = func_02026454((void *)t0); if ((unsigned int)(t1) != (unsigned int)(0)) { return 1; } else { t2 = func_0203DA4C((int)t1); if ((unsigned int)(t2) != (unsigned int)(0)) { return 1; } else { t3 = func_020353B0(); if ((unsigned int)(t3) != (unsigned int)(0)) { return 0; } else { t4 = func_0201214C((const struct Ctx *)((a0 + 0) + 0)); if ((unsigned int)(t4) != (unsigned int)(0)) { return 1; } else { return 0; } } } } }



/*
 * Two instructions and a two word pool: the first argument is the address of
 * func_02012264 tagged as a Thumb function pointer (the pool word is 0x02012265,
 * odd), the second is the caller's own argument, and the tail call is
 * `func_02035064(fn, arg)` with func_02035064 an ARM function.  Declaring the
 * pointer as `func_02012264` rather than writing the literal 0x02012265 is what
 * gets the odd word out of the compiler; func_02012264's own manifest entry is
 * what attests it (`matched x1`).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020122A4.c \
 *       --func func_020122A4 --addr 0x020122A4 --cc 1.1p1 --thumb
 */
void func_020122A4(u32 arg)
{
    func_02035064((const void *)func_02012264, arg);
}


void func_020122B4(void *o)
{
    func_02035064(0, 0);
}



/*
 * Constructor for a five-word descriptor: allocate the 0x14-byte header off
 * heap 4, fill it with the caller's two handles and a zeroed counter,
 * allocate the caller-sized payload off the same heap and hang it at +0xc,
 * and record the owner at +0x10.
 *
 * Both allocations go through sub_02030734, whose last two arguments are
 * the file/line debug site pair (see src/matched/sub_02030734.c).  The file
 * pointer is one pool word loaded twice, so it is a single ABS32 into the
 * packed string area and has to be declared as an extern pinned by address
 * (docs/idioms/file-string-is-an-abs32-into-the-string-area.md), never as a
 * literal __FILE__.  The two line numbers, 55 and 59, are four apart but
 * each is its own `movs`: they are not consecutive arguments of one call,
 * so the add-chain form does not apply
 * (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md).
 *
 * The owner pointer and the payload size arrive in r0 and r3 and are both
 * live across the first call, so r5 takes the owner and the size is spilled
 * to [sp,#4] rather than costing a sixth callee-saved register.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020122C0.c \
 *       --func sub_020122C0 --addr 0x020122C0 --cc 1.1p1 --thumb
 */
struct Desc *sub_020122C0(void *owner, void *a, void *b, u32 size)
{
    struct Desc *d;

    d = sub_02030734(4, sizeof(struct Desc), 1, sub_020122C0_File, 55);
    d->unk_00 = a;
    d->unk_04 = b;
    d->unk_08 = 0;
    d->unk_0c = sub_02030734(4, size, 1, sub_020122C0_File, 59);
    d->unk_10 = owner;
    return d;
}



/*
 * Virtual call: the target is the object's own word at +4, the first argument is
 * the object, the second is the object + 8, the third is the object's word at
 * +0xc.  The call is a register `blx r3`, so there is no relocation to attest
 * and the file is EXACT up to the two bytes of section padding after the pop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012304.c \
 *       --func func_02012304 --addr 0x02012304 --cc 1.1p1 --thumb
 */
int func_02012304(struct S02012304 *o)
{
    return o->f04(o, (unsigned char *)o + 8, o->f0c);
}


void func_02012314(char *p)
{
    void *q = ((struct Obj01023 *)p)->fC;
    if (q) func_020307B0(q);
    func_020307B0(p);
}


void func_0201232C(char *p, int a1, int a2)
{
    void *q;
    *(int *)&((struct Obj01023 *)p)->f8 = 0;
    q = ((struct Obj01023 *)p)->fC;
    *(int *)&((struct Obj01023 *)p)->f4 = a1;
    if (q)
        func_020307B0(q);
    ((struct Obj01023 *)p)->fC = func_02030734(4, a2, 1, g_020A727C, 0x60);
}



/*
 * Reads the object's +0x10 word into a register first, then copies its +0 word
 * out through the caller's pointer and hands that same value to
 * func_02012314, then passes the +0x10 word and the pointer to func_02012108.
 * Order matters: the +0x10 load is hoisted above the store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201235C.c \
 *       --func func_0201235C --addr 0x0201235C --cc 1.1p1 --thumb
 */
void func_0201235C(struct S0201235C *o, u32 *out)
{
    u32 t = o->f10;
    u32 v = o->f00;

    *out = v;
    func_02012314((char *)o);
    func_02012108((struct Ctx *)t, (u32)out);
}



/*
 * Publish the object through the caller's out parameter and tail-call the
 * setter on its +0x10 member, which stores `out` (still in r1) as that
 * context's current event at +0x18.  Eight bytes of code and the pool word the
 * tail call needs (docs/idioms/tail-call-is-a-pool-word-and-bx.md); the
 * pool word carries the Thumb bit, so the target is Thumb code and the
 * transfer is a plain `bx`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012374.c \
 *       --func func_02012374 --addr 0x02012374 --cc 1.1p1 --thumb
 */
void func_02012374(struct Evt *evt, struct Evt **out)
{
    *out = evt;
    func_02012108(evt->unk_10, (u32)out);
}



/*
 * game_event.c: run the event queue until it drains, stalls or finishes.
 * The dangling `cmp r0, #0x21` followed by an unconditional branch back to
 * the loop head is a SWITCH whose case 0x21 lands where the default does:
 * the compare chain keeps the compare and drops the branch.  An if chain
 * (docs/notes/pkt_02012380.c.txt, 38 out) never emits it.
 */
int func_02012380(void *p)
{
    void *v;
    int x;

    for (;;) {
        v = (void *)sub_02012104(p);
        if (v == 0)
            return 0;
        switch (sub_02012304(v)) {
        case 0:
            return 0;
        case 1:
            x = (int)sub_020124F0(v);
            sub_02012314(v);
            sub_02012108(p, x);
            if (x == 0)
                return 1;
            break;
        case 0x21:
            break;
        }
    }
}



int func_020123C4(void *a0){ unsigned int t0; t0 = func_02012104(a0); if ((unsigned int)(t0) != (unsigned int)(0)) {  return 1; } else {  return 0; } }



/*
 * The packet's driver: reject when func_02012104 says the object is busy,
 * reject a null callback, run the callback with the object and the second
 * argument, reject a zero result, hand a non-zero result to func_02012108 and
 * report 1.
 *
 * The two spellings differ by four bytes of layout.  Written with the
 * "invert the guard" shape
 *
 *     if (func_02012104(o) != 0) return 0;
 *     if (fn == 0) return 0;
 *     r = fn(o, a2);
 *     if (r != 0) { func_02012108(o, r); return 1; }
 *     return 0;
 *
 * mwccarm lays the two `movs r0, #0; pop` arms inline and falls through into
 * the success arm, which is what the original does.  Swapping the last pair to
 * `if (r == 0) return 0; else { ... return 1; }` makes it test `bne` and move
 * the success arm out of line (+0x24 onward), and a `goto fail` spelling
 * reproduces only 44 of the 52 bytes: the goto drops the `adds r1, r0, #0`
 * copy that keeps the callback result live for func_02012108 and reorders the
 * callback call.  The reachable spelling is the plain one.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020123D8.c \
 *       --func func_020123D8 --addr 0x020123D8 --cc 1.1p1 --thumb
 */
int func_020123D8(void *o, u32 (*fn)(void *, void *), void *a2)
{
    u32 r;

    if (func_02012104(o) != 0)
        return 0;
    if (fn == 0)
        return 0;
    r = fn(o, a2);
    if (r != 0) {
        func_02012108(o, r);
        return 1;
    }
    return 0;
}



/*
 * A three-state driver.  func_020124E4's result is bound before the switch and
 * is still live in r0 at the case-0 call, which is why the two loads of the
 * state go to r1 (not r0) and the callee's argument registers are r1, r2, r3
 * with r0 carrying the earlier call's result.  Both arms leave through the
 * shared `return 0` tail, so neither may be written as a `return`: writing
 * `return 0` in case 0 makes mwccarm duplicate `movs r0, #0` inline instead of
 * branching to +0x34, and the function comes out six bytes long with the last
 * two arms shifted.  `!= 0` / `== 0` in case 1 makes no difference.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201240C.c \
 *       --func func_0201240C --addr 0x0201240C --cc 1.1p1 --thumb
 */
int func_0201240C(void *o, u32 *state, u32 *item)
{
    u32 v = (u32)func_020124E4(o);

    switch (*state) {
    case 0:
        func_020120B4((struct IcaAnimeInst *)v, item[0], (void *)item[1], (void *)item[2]);
        *state = *state + 1;
        break;
    case 1:
        if (func_020120F0((void *)v) == 0)
            return 1;
        break;
    }
    return 0;
}



/*
 * Promoted from src/pending/ in the second 0-64 byte band pass (lane 1).  It
 * sat at MATCH on the pool word at +0x2C, which holds 0x0201240D - the state
 * machine at 0x0201240C with its Thumb bit, handed to sub_020122C0 as a
 * callback.  That word is the only one in the image naming 0x0201240D, and no
 * branch reaches 0x0201240C from outside this range either, so the site needed
 * 0x0201240C to be an EXACT entry of its own; now that it is, the site
 * resolves through the `matched` class and this file needs no change.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012444.c \
 *       --func func_02012444 --addr 0x02012444 --cc 1.1p1 --thumb
 */
void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3)
{
    struct Desc *d;
    u32 *p;

    d = sub_020122C0(obj->unk_10, 0, func_0201240C, 0xc);
    p = sub_020124E8((struct Obj *)d);
    p[0] = a1;
    p[1] = a2;
    p[2] = a3;
    func_02012374((struct Evt *)obj, (struct Evt **)d);
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012474.c \
 *       --func func_02012474 --addr 0x02012474 --cc 1.1p1 --thumb
 */
int func_02012474(void *a0, u32 *a1, u32 *a2)
{
    sub_020124E4(a0);
    switch (*a1) {
    case 0:
        func_02012374(a0, (void *)a2[1]);
        (*a1)++;
        break;
    case 1:
        func_02034A5C((int)a2[0]);
        return 1;
    }
    return 0;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020124AC.c \
 *       --func func_020124AC --addr 0x020124AC --cc 1.1p1 --thumb
 */
struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3)
{
    struct Desc *d;
    u32 *p;

    d = sub_020122C0(a0, 0, func_02012474, 0x10);
    p = sub_020124E8((struct Obj *)d);
    p[0] = a1;
    func_02034AC4(a1);
    p[1] = fn(a0, a3);
    return d;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * Four two-byte leaf accessors in a row on the same object.  None of them
 * saves lr, so disasm.py labels none of them and the whole run prints as a
 * `.byte` blob between two pools; they are only reachable by sweeping
 * addresses.  sub_020124EC returns the address of the embedded sub-object
 * at +8 rather than a stored pointer.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020124E4.c \
 *       --addr 0x020124E4 --thumb
 */
void *sub_020124E4(struct Obj *p)
{
    return p->unk_10;
}


void *sub_020124E8(struct Obj *p)
{
    return p->unk_0c;
}


u32 *sub_020124EC(struct Obj *p)
{
    return &p->unk_08;
}


void *sub_020124F0(struct Obj *p)
{
    return p->unk_00;
}



/*
 *           have exactly ONE branch anywhere in the image and it is the `bl`
 *           inside this function (0x020125AA, 0x020125E0, 0x02012698,
 *           0x020126DC), so the `label` class has no outside witness.  Two
 *           overlays (ov009, ov010) hold each address, so even with the
 *           `ov010` region hint on the symbols: line the witness condition
 *           still fails.  `sole-ref/code` cannot carry them either: it reads
 *           `evidence().labels`, which is the ARM9 listing only, so an
 *           overlay-resident function start is outside its index.
 *           `tu --suggest-split` confirms no cut helps ("best partition:
 *           0 piece(s), 1 function(s) left out") -- the only witnesses are
 *           the calls that need them.  Same wall as src/pending/func_02012704.c
 *           (the matching destructor), which is blocked on five siblings of
 *           these same overlay addresses.
 *           Every one of the 528 concrete bytes is correct; only the four
 *           relocation FIELDS stay wildcarded.
 * The constructor of the big game_data object destroyed by func_02012704.
 * 0x6B0 bytes from func_02030734(heap, 0x6B0, 1, "game_data.c", 0xAD); the
 * field offsets are the destructor's, read through a u8 * so the compiler
 * derives them all from the two pooled/scaled bases 0x1C4 (= 0x71 << 2),
 * 0x158 (= 0x56 << 2) and 0x6AC.
 *
 * THE TWO LEVERS (both found this wave; 528 bytes size-exact on the first
 * write, then 176 concrete-byte mismatches down to 0 in two changes):
 *
 * 1. THE HEAP PARAMETER IS `u16`, NOT `int`.  With `int` the seven prologue
 *    instructions are the right seven in the wrong order: mwcc emits the
 *    `str r0, [sp, #4]` spill LAST, after `movs r1,#0xad / str r1,[sp] /
 *    movs r1,#0x6b / ldr r3,pool / lsls r1,r1,#4 / movs r2,#1`, while the
 *    original emits it FIRST.  A `u16` parameter has a narrowed stack home
 *    the marshaller must establish before it builds the other arguments,
 *    which is exactly the original's order.  No spelling of the body moves
 *    it: `int heap = a0;` as the first local, as the last local, hoisting
 *    0x6B0 into a named `size`, and 300 single mutations of the permuter in
 *    --mode hill ("no single mutation improves") all leave the same seven.
 *    The permuter's --mode anneal found it as `type:p(a0:int->u16)` in 286
 *    compiles; the sibling caller src/matched/func_020082EC.c independently
 *    corroborates it, passing `(unsigned short)a0` to the same allocator.
 *
 * 2. THE memcpy ARGUMENTS ARE EVALUATED THROUGH TWO NAMED LOCALS, in the
 *    original's order: `n = func_02008468(); src = func_02012944(p);` and
 *    only then `memcpy(func_02008730(*(u32 *)p), src, n)`.  Written as one
 *    nested expression mwcc schedules func_02008730 first and the whole
 *    tail of the function reallocates: that alone was 169 of the 176
 *    mismatches.  (docs/idioms/an-inline-call-argument-is-scheduled-per-site-
 *    a-local-is-not.md)
 *
 * Verified with:
 *   python3 tools/match.py one --src src/pending/func_020124F4.c \
 *       --func func_020124F4 --addr 0x020124F4 --cc 1.1p1 --thumb
 */
void *func_020124F4(u16 heap)
{
    u8 *p;
    int i;
    u32 n;
    void *src;
    void *obj;

    p = func_02030734(heap, 0x6B0, 1, g_020A728C, 0xAD);
    *(u32 *)&((struct Obj00054 *)p)->f0 = (u32)func_020070A4();
    ((struct Obj00054 *)p)->f1C4 = func_0202E888();
    ((struct Obj00054 *)p)->f1C6 = 0;

    ((struct Obj00054 *)p)->f15C = (u32)func_02008854((void *)(*(u32 *)&((struct Obj00054 *)p)->f0));
    *(u32 *)&((struct Obj00054 *)p)->f160 = func_02008844(((struct Obj00054 *)p)->f15C);
    *(u32 *)&((struct Obj00054 *)p)->f164 = func_02008844(((struct Obj00054 *)p)->f15C);
    *(u32 *)&((struct Obj00054 *)p)->f168 = (u32)func_02008848((struct Sub02008828Obj *)(((struct Obj00054 *)p)->f15C));
    *(u32 *)&((struct Obj00054 *)p)->f16C = (u32)func_0200884C((struct Sub02008828Obj *)(((struct Obj00054 *)p)->f15C));

    ((struct Obj00054 *)p)->f1A4 = (u32)func_02006E40(heap);

    for (i = 0; i < 5; i++) {
        func_02012A60((struct Rec44 *)(p + 4 + i * 0x44));
    }

    n = func_02008468();
    src = func_02012944(p);
    memcpy(func_02008730((void *)(*(u32 *)&((struct Obj00054 *)p)->f0)), src, n);

    ((struct Obj00054 *)p)->f158 = obj = (void *)func_0216237C(heap);
    func_021623DC(obj);
    ((struct Obj00054 *)p)->f1AC = (unsigned int)func_02012FE4((struct Sub020071CCCtrl *)(*(u32 *)&((struct Obj00054 *)p)->f0));
    ((struct Obj00054 *)p)->f1B0 = (u32)func_02159B48(heap);
    ((struct Obj00054 *)p)->f1A8 = (u32)func_0216CC58(heap, 0x40, (u32)func_020071CC((struct Sub020071CCCtrl *)*(u32 *)&((struct Obj00054 *)p)->f0, 0x33));
    ((struct Obj00054 *)p)->f1B4 = (u32)func_02028844(p, heap);
    *(u32 *)&((struct Obj00054 *)p)->f1B8 = func_02014428(heap);
    ((struct Obj00054 *)p)->f18C = (u32)func_02008254(heap);
    *(u32 *)&((struct Obj00054 *)p)->f190 = (u32)func_020071CC((struct Sub020071CCCtrl *)*(u32 *)&((struct Obj00054 *)p)->f0, 0x19);
    *(u32 *)&((struct Obj00054 *)p)->f194 = (u32)func_020071CC((struct Sub020071CCCtrl *)*(u32 *)&((struct Obj00054 *)p)->f0, 0x1A);
    ((struct Obj00054 *)p)->f198 = (u32)func_0200873C((void *)(*(u32 *)&((struct Obj00054 *)p)->f0));
    ((struct Obj00054 *)p)->f19C = (u32)func_02007AA4(heap, *(u32 *)&((struct Obj00054 *)p)->f0);
    ((struct Obj00054 *)p)->f1A0 = (u32)func_020097C4(heap);

    for (i = 0; i < 4; i++) {
        func_0200BDE4((struct Rec1B0 *)(p + 0x1D4 + i * 0x10));
    }

    for (i = 0; i < 2; i++) {
        func_02161D98((char *)(p + 0x214 + i * 0x1E8));
    }

    ((struct Obj00054 *)p)->f6AC = (u32)func_0200857C(heap);
    ((struct Obj00054 *)p)->f1C0 = 0;
    func_020071E4((const struct Sub020071E4Ctrl *)(*(u32 *)&((struct Obj00054 *)p)->f0));

    ((struct Obj00054 *)p)->f5E4 = (u32)func_0215E31C(heap);
    func_0202E43C(p + 0x5E8);
    func_02012C18(p);
    ((struct Obj00054 *)p)->f680 = 0;
    *(u32 *)&((struct Obj00054 *)p)->f688 = 0;
    ((struct Obj00054 *)p)->f684 = (u32)func_0202E770((void *)heap);
    ((struct Obj00054 *)p)->f68C = func_0202751C(heap, 0x8001);
    ((struct Obj00054 *)p)->f690 = (u32)func_021647A0(p, heap);
    ((struct Obj00054 *)p)->f6A4 = 0;
    ((struct Obj00054 *)p)->f6A8 = 0;

    return p;
}



/*
 * note:     wave 16: promoted.  0x0215E334 and 0x02159BBC are unlabelled ov010
 *           ENV_SetResourceSet thunks matched in src/matched/func_0215E334.c and
 *           func_02159BBC.c (`matched, overlay`); 0x021647D8, 0x0216CCB0 and
 *           0x021623BC resolve as sole-ref/code (overlay).
 * A destructor: fifteen pointer fields of one big object handed to fifteen
 * different release functions, then the object itself to the base deleter
 * 0x020307B0 (the ARM `blx` target, called three times).
 *
 * The literal 0x6AC is pooled once and every other offset is derived from it
 * with `adds`/`subs` (0x690, 0x68C, 0x684, 0x5E4), which is why the second
 * group starts from 0x69 << 2: the offsets are the source's array indices
 * scaled by four, and the field reads are `p[0x1AB]`, `p[0x1A4]`, ... in a
 * `u32 *`.  Writing the fields as byte offsets through a `u8 *` reproduces
 * the same derived-constant chain.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012704.c \
 *       --func func_02012704 --addr 0x02012704 --cc 1.1p1 --thumb
 */
void func_02012704(u8 *p)
{
    func_020307B0((void *)(((struct Obj01611 *)p)->f6AC));
    func_021647D8(((struct Obj01611 *)p)->f690);
    func_02027584((u8 *)(((struct Obj01611 *)p)->f68C));
    func_0202E794((void *)(((struct Obj01611 *)p)->f684));
    func_0215E334((void *)(((struct Obj01611 *)p)->f5E4));
    func_02006E64((struct Sub02006E40Obj *)(((struct Obj01611 *)p)->f1A4));
    func_020307B0((void *)(((struct Obj01611 *)p)->f1A0));
    func_02007AC8((void *)(((struct Obj01611 *)p)->f19C));
    func_020307B0((void *)(((struct Obj01611 *)p)->f18C));
    func_0216CCB0(((struct Obj01611 *)p)->f1A8);
    func_02159BBC((void *)(((struct Obj01611 *)p)->f1B0));
    func_021623BC(((struct Obj01611 *)p)->f158);
    func_02014444(((struct Obj01611 *)p)->f1B8);
    func_0202889C((struct SoundSys *)(((struct Obj01611 *)p)->f1B4));
    func_020307B0((void *)((u32)p));
}



u8 *func_02012798(u8 *p, int i)
{
    return p + 4 + i * 0x44;
}



/*
 * Two address-of-member accessors on the same save-data block, neither of
 * which saves lr, so neither carries a label
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md) and the pair
 * has to be worked as one unit.
 *
 * Both offsets are out of Thumb immediate range and are built as
 * `movs #n / lsls #2`, which is why 0x114 appears as 0x45 and 0x1d4 as 0x75.
 * The second takes an index into a 16-byte array that starts at +0x1d4.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020127A4.c \
 *       --addr 0x020127A4 --thumb
 */
void *func_020127A4(struct SaveBlock *p)
{
    return p->unk_114;
}


void *func_020127AC(struct SaveBlock *p, u32 idx)
{
    return p->unk_1d4[idx];
}



/*
 * Promoted from src/pending/func_020127B8.c (was MATCH, blocker 0x020127AC,
 * declared by the naming convention, which defaults to ARM).  The pool word
 * is 0x020127AD, so the target is Thumb; declared `thumb` the `matched`
 * class fires on the EXACT unit entry for 0x020127AC
 * (src/matched/unit_020127A4.c, which names it as a member function) and
 * the site resolves with no change to the C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020127B8.c \
 *       --func func_020127B8 --addr 0x020127B8 --cc 1.1p1 --thumb
 */
void *func_020127B8(void *p)
{
    return func_020127AC(p, 3);
}



/*
 * Promoted from src/pending/func_020127C4.c (was MATCH, blocker 0x020127D0,
 * declared by the naming convention, i.e. ARM).  Two things had to happen:
 * the pool word is 0x020127D1 so the target is Thumb, and
 * src/matched/sub_020127D0.c has to exist as an EXACT entry for the
 * `matched` class to reach it - both done, and the C never changed.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020127C4.c \
 *       --func func_020127C4 --addr 0x020127C4 --cc 1.1p1 --thumb
 */
u8 *func_020127C4(void *p)
{
    return sub_020127D0(p, 1);
}




/*
 * Address-of-element on a 0x1E8-byte record array at +0x214: the pair of
 * constants 0x214 and 0x1E8 differ by 0x2c, so the compiler materialises the
 * larger one from a pool-free `movs`/`lsls` pair and derives the stride with
 * a `subs` (see docs/idioms/a-constant-pair-...).  Entry attested by the
 * pool word 0x020127D1 that func_020127C4 loads.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020127D0.c \
 *       --func sub_020127D0 --addr 0x020127D0 --cc 1.1p1 --thumb
 */
u8 *sub_020127D0(u8 *o, u32 idx)
{
    return o + 0x214 + idx * 0x1E8;
}



int func_020127E0(int a0){ int t0, t1; t0 = func_0200A864((int)((struct Obj15627 *)((char *)(a0)))->f0); t1 = func_0200A890((int)t0); return t1; }



int func_020127F0(int a0){ int t0, t1; t0 = func_0200A864((int)((struct Obj15628 *)((char *)(a0)))->f0); t1 = func_0200A898((int)t0); return t1; }



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02012800.c \
 *       --func func_02012800 --addr 0x02012800 --cc 1.1p1 --thumb
 */
void func_02012800(u8 *obj, void *dst)
{
    func_02082D44(dst, obj + 0x214, 0x1e8);
    func_02161D64((int)(obj + 0x214));
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201281C.c \
 *       --func func_0201281C --addr 0x0201281C --cc 1.1p1 --thumb
 */
void func_0201281C(u8 *obj)
{
    func_02082BCC(obj + 0x214, 0, 0x1e8);
    func_02161D64((int)(obj + 0x3fc));
}



/*
 *           func_02012870, func_02012878, func_02012894, func_0201289C,
 *           func_020128B8, func_020128C0, func_020128DC, func_020128E4,
 *           func_02012900
 *
 * 214 bytes, 0x0201283C..0x02012914, 13 functions, five of them labelled.  It
 * abuts src/matched/unit_02012924.c at the far end, across the one function
 * the cut below moved out.
 *
 * Four pointer fields at +0x160, +0x164, +0x168 and +0x16C and one inline
 * record at +0x170 all hold the same 28-byte thing, and each has a getter and
 * a setter.  28 bytes is three `ldm`/`stm` pairs plus a trailing `ldr`/`str`,
 * which is docs/idioms/aggregate-assignment-is-ldm-stm.md; the record has to
 * be declared four-aligned (u32 v[7], not u8 v[28]) or the copy becomes a
 * byte loop.  The four pointer setters write through the pointer
 * (`*p->unk160 = *src`) and the fifth writes the inline record
 * (`p->unk170 = *src`), which is the difference between the `ldr r2, [r0, r1]`
 * and the `adds r2, r0, r1` that opens each.
 *
 * The file is cut at 0x02012914 rather than at 0x02012924, which is where the
 * next file starts, because func_02012900 and func_02012914 are the only two
 * callers of func_02008850 in the image: one range holding both leaves the
 * `label` class no witness and the whole unit reads MATCH with every concrete
 * byte right.  Split, each is the other's outside witness and both are EXACT.
 * That is docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md, and
 * the other half is src/matched/unit_02012914.c.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201283C.c \
 *       --addr 0x0201283C --thumb
 */
u32 func_0201283C(const struct BigObj *p)
{
    return p->unk1A0;
}


u32 func_02012844(const struct BigObj *p)
{
    return p->unk158;
}


struct Rec1C *func_0201284C(const struct BigObj *p)
{
    return p->unk160;
}


void func_02012854(struct BigObj *p, const struct Rec1C *src)
{
    *p->unk160 = *src;
}


struct Rec1C *func_02012870(const struct BigObj *p)
{
    return p->unk164;
}


void func_02012878(struct BigObj *p, const struct Rec1C *src)
{
    *p->unk164 = *src;
}


struct Rec1C *func_02012894(const struct BigObj *p)
{
    return p->unk168;
}


void func_0201289C(struct BigObj *p, const struct Rec1C *src)
{
    *p->unk168 = *src;
}


struct Rec1C *func_020128B8(const struct BigObj *p)
{
    return p->unk16C;
}


void func_020128C0(struct BigObj *p, const struct Rec1C *src)
{
    *p->unk16C = *src;
}


struct Rec1C *func_020128DC(struct BigObj *p)
{
    return &p->unk170;
}


void func_020128E4(struct BigObj *p, const struct Rec1C *src)
{
    p->unk170 = *src;
}


void func_02012900(const struct BigObj *p, u16 v)
{
    *func_02008850((void *)p->unk15C) = v;
}
