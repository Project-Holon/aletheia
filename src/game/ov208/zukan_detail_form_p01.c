/*
 * file:     zukan_detail_form_p01.c
 * unit:     yes
 * function: func_021C31CC, func_021C3208, func_021C3218, func_021C3268, func_021C3280, func_021C32FC, func_021C3318, func_021C3354, func_021C3374, func_021C3378, func_021C337C, func_021C3380, func_021C3480, func_021C34A4, func_021C3514, func_021C35DC, func_021C3638, func_021C3650, func_021C3678, func_021C36CC, func_021C3840, func_021C3A24, func_021C3AA8, func_021C3B14, ov208_func_021C3B6C, func_021C3C70, func_021C3D3C, func_021C4298, func_021C47A0, func_021C47B4, func_021C47C4, func_021C48CC, func_021C4A48, func_021C4AC4, func_021C4AF4, func_021C4B2C, ov208_func_021C4B60, ov208_func_021C4BB4, ov208_func_021C4D68, func_021C4E54, func_021C4EAC, func_021C4F30, func_021C4F78, func_021C4FDC, func_021C5000, func_021C5078, func_021C5090, func_021C50F8, func_021C5128, func_021C51A0, func_021C51C8, func_021C51D4, func_021C5200, func_021C5214, func_021C5248, func_021C526C, func_021C52F0, func_021C533C, func_021C535C, func_021C53E0
 * address:  0x021C31CC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02049B90 0x02049B90 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_021BC3C0 0x021BC3C0 thumb ov208
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_02045770 0x02045770 arm
 *   func_020437DC 0x020437DC arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   data_020A7370 0x020A7370 data a4
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020870D0 0x020870D0 arm
 *   _ll_udiv 0x0209C00C arm
 *   _s32_div_f 0x0209C0A4 arm
 *   ov208_func_021C3208 0x021C3208 thumb ov208
 *   ov208_func_021C337C 0x021C337C thumb ov208
 *   ov208_func_021C3378 0x021C3378 thumb ov208
 *   ov208_func_021C2DE0 0x021C2DE0 thumb ov208
 *   func_02006650  0x02006650  thumb
 *   func_020065D8  0x020065D8  thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021C2FEC 0x021C2FEC thumb ov208
 *   func_021C2E6C 0x021C2E6C thumb ov208
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035D20 0x02035D20 arm
 *   ov208_func_021BC3A4 0x021BC3A4 thumb ov208
 *   func_0200CA1C 0x0200CA1C thumb
 *   ov208_func_021BC3C0 0x021BC3C0 thumb ov208
 *   func_0200CC40 0x0200CC40 thumb
 *   func_02006984 0x02006984 thumb
 *   ov208_func_021C31CC 0x021C31CC thumb ov208
 *   func_02030734 0x02030734 arm
 *   func_02043678 0x02043678 arm
 *   data_021C8E28 0x021C8E28 data ov208 a1
 *   func_021C36CC 0x021C36CC thumb ov208
 *   func_02043AF4 0x02043AF4 arm
 *   func_020439A0 0x020439A0 arm
 *   ov208_func_021C3A24 0x021C3A24 thumb ov208
 *   func_02006B5C 0x02006B5C thumb
 *   func_02006B94 0x02006B94 thumb
 *   func_02006B3C 0x02006B3C thumb
 *   func_02006B78 0x02006B78 thumb
 *   func_02006B20 0x02006B20 thumb
 *   _ffltu 0x0209BE04 arm
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fadd 0x0209C95C arm
 *   _fmul 0x0209C77C arm
 *   _ffixu 0x0209C4C8 arm
 *   func_02045768 0x02045768 arm
 *   func_02041090 0x02041090 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021BC518 0x021BC518 thumb ov208
 *   ov208_func_021BC32C 0x021BC32C thumb ov208
 *   func_02082BCC 0x02082BCC arm
 *   ov208_func_021BC3A8 0x021BC3A8 thumb ov208
 *   ov208_func_021BCF4C 0x021BCF4C thumb ov208
 *   ov208_func_021BC3AC 0x021BC3AC thumb ov208
 *   func_020056A0 0x020056A0 thumb
 *   ov208_func_021C4AC4 0x021C4AC4 thumb ov208
 *   ov208_func_021BC448 0x021BC448 thumb ov208
 *   ov208_func_021BC518 0x021BC518 thumb ov208
 *   ov208_func_021BC508 0x021BC508 thumb ov208
 *   ov208_func_021BC610 0x021BC610 thumb ov208
 *   ov208_func_021BC3B4 0x021BC3B4 thumb ov208
 *   ov208_func_021BC97C 0x021BC97C thumb ov208
 *   ov208_func_021BCA54 0x021BCA54 thumb ov208
 *   ov208_func_021C66C8 0x021C66C8 thumb ov208
 *   ov208_func_021C53E0 0x021C53E0 thumb ov208
 *   ov208_func_021C533C 0x021C533C thumb ov208
 *   ov208_func_021C4A48 0x021C4A48 thumb ov208
 *   ov208_func_021BDCA4 0x021BDCA4 thumb ov208
 *   ov208_func_021BC61C 0x021BC61C thumb ov208
 *   ov208_func_021BC464 0x021BC464 thumb ov208
 *   ov208_func_021C4AF4 0x021C4AF4 thumb ov208
 *   func_02030EAC 0x02030EAC arm
 *   ov208_func_021BC34C 0x021BC34C thumb ov208
 *   ov208_func_021BC3B8  0x021BC3B8  thumb  ov208
 *   func_02040618  0x02040618  arm
 *   func_020414AC  0x020414AC  arm
 *   func_0204047C  0x0204047C  arm
 *   func_0207D4B0  0x0207D4B0  arm
 *   ov208_func_021BCF58  0x021BCF58  thumb  ov208
 *   ov208_func_021C625C  0x021C625C  thumb  ov208
 *   ov208_func_021C5664  0x021C5664  thumb  ov208
 *   ov208_func_021C580C  0x021C580C  thumb  ov208
 *   func_02015EA0  0x02015EA0  thumb
 *   func_02015F50  0x02015F50  thumb
 *   ov208_func_021BC9BC  0x021BC9BC  thumb  ov208
 *   ov208_func_021BC844  0x021BC844  thumb  ov208
 *   ov208_func_021BC758  0x021BC758  thumb  ov208
 *   ov208_func_021BC718  0x021BC718  thumb  ov208
 *   ov208_func_021BC4F4  0x021BC4F4  thumb  ov208
 *   ov208_func_021C7E74  0x021C7E74  thumb  ov208
 *   func_0201600C  0x0201600C  thumb
 *   ov208_func_021BC6D8  0x021BC6D8  thumb  ov208
 *   ov208_func_021BDAD0  0x021BDAD0  thumb  ov208
 *   ov208_func_021BC3BC  0x021BC3BC  thumb  ov208
 *   ov208_func_021BDAAC  0x021BDAAC  thumb  ov208
 *   ov208_func_021BDAD4  0x021BDAD4  thumb  ov208
 *   ov208_func_021BDBB8  0x021BDBB8  thumb  ov208
 *   ov208_func_021BDC48  0x021BDC48  thumb  ov208
 *   func_02012BF8  0x02012BF8  thumb
 *   ov208_func_021BDC14  0x021BDC14  thumb  ov208
 *   ov208_func_021BE840  0x021BE840  thumb  ov208
 *   ov208_func_021BE82C  0x021BE82C  thumb  ov208
 *   ov208_func_021BE844  0x021BE844  thumb  ov208
 *   func_02015EB0  0x02015EB0  thumb
 *   ov208_func_021BC6C8  0x021BC6C8  thumb  ov208
 *   ov208_func_021BDBA0  0x021BDBA0  thumb  ov208
 *   ov208_func_021C5D64  0x021C5D64  thumb  ov208
 *   ov208_func_021BC6F8  0x021BC6F8  thumb  ov208
 *   ov208_func_021BE854  0x021BE854  thumb  ov208
 *   ov208_func_021BDAE8  0x021BDAE8  thumb  ov208
 *   ov208_func_021C7EF8  0x021C7EF8  thumb  ov208
 *   ov208_func_021C51A0  0x021C51A0  thumb  ov208
 *   ov208_func_021C4FDC  0x021C4FDC  thumb  ov208
 *   ov208_func_021BCF6C  0x021BCF6C  thumb  ov208
 *   func_02030D28  0x02030D28  arm
 *   func_02014C08  0x02014C08  thumb
 *   ov208_func_021C692C  0x021C692C  thumb  ov208
 *   ov208_func_021C6E98  0x021C6E98  thumb  ov208
 *   ov208_func_021C6BB4  0x021C6BB4  thumb  ov208
 *   ov208_func_021C75FC  0x021C75FC  thumb  ov208
 *   ov208_func_021C7860  0x021C7860  thumb  ov208
 *   ov208_func_021BC99C  0x021BC99C  thumb  ov208
 *   ov208_func_021BC46C  0x021BC46C  thumb  ov208
 *   ov208_func_021BC678  0x021BC678  thumb  ov208
 *   ov208_func_021BC3CC 0x021BC3CC thumb ov208
 *   ov208_func_021BC40C 0x021BC40C thumb ov208
 *   ov208_func_021C53F4 0x021C53F4 thumb ov208
 *   ov208_func_021C5C64 0x021C5C64 thumb ov208
 *   ov208_func_021C5F34 0x021C5F34 thumb ov208
 *   ov208_func_021BDBEC 0x021BDBEC thumb ov208
 *   ov208_func_021BDC2C 0x021BDC2C thumb ov208
 *   func_02012BE0 0x02012BE0 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   func_02014D2C 0x02014D2C thumb
 *   func_021BC6BC  0x021BC6BC  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0201EE60  0x0201EE60  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0204A298  0x0204A298  arm
 *   data_021C8830  0x021C8830  data
 *   data_021C8794  0x021C8794  data
 *   func_020452E8 0x020452E8 arm
 *   func_02045C04 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_02041EE4  0x02041EE4  arm
 *   func_02014B08  0x02014B08  thumb
 *   func_02016020  0x02016020  thumb
 *   func_02015BF0  0x02015BF0  thumb
 *   func_0202D060  0x0202D060  thumb
 *   func_02014CB8  0x02014CB8  thumb
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_02014CEC  0x02014CEC  thumb
 *   data_021C8E64  0x021C8E64  data
 *   func_020172AC  0x020172AC  thumb
 *   func_02017168  0x02017168  thumb
 *   func_020159C8  0x020159C8  thumb
 *   func_02015FF0  0x02015FF0  thumb
 *   func_02015E04  0x02015E04  thumb
 *   func_02015CAC  0x02015CAC  thumb
 *   data_021C8804  0x021C8804  data
 *   func_02015F14  0x02015F14  thumb
 *   func_02015C78  0x02015C78  thumb
 *   _fgr  0x0209BBB0  arm
 *   _fsub  0x0209CB8C  arm
 *   _ffix  0x0209C494  arm
 *   func_02015C30  0x02015C30  thumb
 *   data_021C8E40  0x021C8E40  data
 *   func_02015EE8  0x02015EE8  thumb
 *   func_02063000  0x02063000  arm
 *   ov208_func_021C7F6C  0x021C7F6C  thumb
 *   func_02064CBC 0x02064CBC arm
 *   func_02015E4C 0x02015E4C thumb
 *   func_02016380  0x02016380  thumb
 *   func_021C595C 0x021C595C thumb ov208
 *   func_020490F4  0x020490F4  arm
 *   func_0201BC3C  0x0201BC3C  thumb
 *   func_0204ACEC  0x0204ACEC  arm
 *   func_0201BC78  0x0201BC78  thumb
 *   func_0201BCEC  0x0201BCEC  thumb
 *   func_0204AF28  0x0204AF28  arm
 *   func_0201BABC  0x0201BABC  thumb
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0201BB5C  0x0201BB5C  thumb
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_0204A8D4  0x0204A8D4  arm
 */
#include "../../matched/include/Obj09208.h"
#include "../../matched/include/Obj00146.h"
#include "../../matched/include/Obj09209.h"
#include "../../matched/include/Obj02256.h"
#include "../../matched/include/Obj06684.h"
#include "../../matched/include/Obj09210.h"
#include "../../matched/include/Obj01010.h"
#include "../../matched/include/Obj06685.h"
#include "../../matched/include/Obj02547.h"
#include "../../matched/include/Obj14660.h"
#include "../../matched/include/Obj25510.h"
#include "../../matched/include/Obj06686.h"
#include "../../matched/include/Obj10908.h"
#include "../../matched/include/Obj01179.h"
#include "../../matched/include/Obj14663.h"
#include "../../matched/include/Obj04897.h"
#include "../../matched/include/Obj00147.h"
#include "../../matched/include/Obj09213.h"

#define W(o) (*(u32 *)((u8 *)(u8 *)p + (o)))
#define PW(o) (*(void **)((u8 *)(u8 *)p + (o)))
#define OBJ(i) (*(u32 *)((u8 *)p + (i) * 0x44 + 0xc))
#define H(o) (*(u16 *)((u8 *)p + (o)))
#define FX_F32_TO_FX32(x) ((fx32)(((x) > 0) ? \
                                  ((x) * (1 << 12) + 0.5f) : \
                                  ((x) * (1 << 12) - 0.5f)))
struct Obj;
struct Vec2;
struct Pair;
struct Descriptor;
struct PrintSys;
struct MsgBank;
struct StrObj;
struct Bmp;
struct U16Vec;
struct Key;
struct CharBuf;
struct Cfg;
struct S_021C31CC;
struct Obj020437AC;
struct Actor;
struct Node;
struct Ctx;
struct McssFade;
struct McssSys;
struct WordSet;
struct Rec;
struct Sub02014CB8Obj;
struct Sub150;
struct Stats;
typedef unsigned int   u32;

typedef struct {
    char pad[0x60];
    unsigned int state;
} S_021C31CC;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned long long u64;

struct Ov208Scroll {
    u8 pad0[0x18];
    s16 a;
    s16 b;
    u8 pad1c[0x20 - 0x1c];
    struct Descriptor *desc;
    u8 pad24[0x2c - 0x24];
    struct Bmp *dst;
    s16 c;
    s16 d;
};

typedef signed char    s8;

typedef int            s32_021C31CC;

struct Ov208Sel {
    u16 next;
    u16 sel;
    u16 twos;
    u16 groups;
    u16 count;
};

struct Ov208WinTbl {
    u8 d[5][7];
};

typedef enum { YP_0 = 0, YP_MAX = 0x7fffffff } YPos;

typedef struct {
    int a;
    int b;
    int c;
    int d;
} T;

typedef signed int    fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec_021C5000;

struct Ov208MonArc {
    u8 d[0x24];
};

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec_021C5090;

typedef struct {
    int x;
    int y;
    int z;
} Vec_021C50F8;

struct Ov208Cam {
    u32 pad0[6];
    Vec_021C50F8 ofs;
};

typedef struct {
    float x;
    float y;
    float z;
} VecF;

struct Ov208Mdl {
    u32 obj;
    void *turn;
    VecF pos[5];
};

typedef struct {
    int w0;
    int w4;
    char b8;
    char pad[3];
    int wc;
} S_021C4E54;

struct Ov208Anm_021C51D4 { u8 pad0[8]; u8 f8; u8 pad9[3]; u32 fc; };

struct Ov208Slot { void *obj; struct Ov208Anm_021C51D4 *anm; };

struct Ov208AnmState {
    u32 f0;
    u32 f4;
    u32 f8;
    int active;
};

struct Ov208Anm_021C5214 {
    u32 obj;
    struct Ov208AnmState *state;
    u8 pad8[0x44 - 8];
};

struct Ov208Ent {
    u32 kind;
    u32 mode;
    u16 pad8;
    u8  forms;
    u8  padb;
    u16 species;
    u16 pade;
};

struct Ov208Form {
    u32 f0;
    u32 font;
    u32 cam;
    struct Ov208Anm_021C5214 item[4];
    void *mem;
    void *heap3d;
    u8  pad124[4];
    void *arc;
    u32 res[2];
    u32 j;
    u32 k;
    u32 obj[2];
    int cur;
    struct Ov208Ent ents[8];
    u8  pad1c8[0x548 - 0x1c8];
    u16 count;
    u16 pad54a[2];
    u16 sel;
    u16 sel2;
    u16 pad552;
    u32 win[5];
    u32 active[5];
    u32 print[5];
    u32 msg;
    u32 marc;
    u32 msg2;
    u32 str[6];
    u32 w5b4;
    u32 w5b8;
    u32 w5bc;
    u8  pad5c0[0x6b8 - 0x5c0];
    u32 state;
};

struct Ov208Turn {
    int side;
    u8 *scene;
    u8  count;
    u8  pad9[3];
    int done;
};

typedef signed int     s32_021C4E54;

typedef struct {
    s16 x;
    s16 y;
    u16 z;
    u8  b6;
    u8  b7;
} Ov208ObjPos;

extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B5AC(struct Obj *dst, struct Pair *src);
extern void func_02049B90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045334(struct Descriptor *);
extern void func_0201C6EC(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);
extern u16 func_021BC3C0(int key);
extern void *func_02045EC0(struct MsgBank *bank,u32 index);
extern u32 func_0201D304(struct StrObj *s,u32 a,u32 b);
extern void *func_02045770(struct Descriptor *p);
extern u16 func_020437DC(const struct Bmp *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *s);
extern void func_02043B5C(struct CharBuf *p, u8 v);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern u64 func_020870D0(void);
extern void ov208_func_021C3208(u16 *heap, struct Ov208Form *p, int key);
extern void ov208_func_021C337C(u16 *heap, struct Ov208Form *p, int key);
extern void ov208_func_021C3378(u16 *heap, struct Ov208Form *p, int key, int first, u16 second);
extern void ov208_func_021C2DE0(u16 *heap, u8 *p, int key, int first, u16 second);
extern int func_02006650(void);
extern void func_020065D8(void);
extern void func_0204B3DC(struct Obj *p,u32 v);
extern void func_021C2FEC(void *unused, struct S_021C31CC *p, u32 unused2, u32 i);
extern void func_021C2E6C(u16 *heap, u8 *p, int key, u32 slot);
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int ov208_func_021BC3A4(int key);
extern void *func_0200CA1C(void *a);
extern u16 ov208_func_021BC3C0(int key);
extern void func_0200CC40(u8 *p, u16 id, u32 *out1, u32 *out2, u32 *outForm, u16 a5);
extern u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern void ov208_func_021C31CC(u16 *heap, struct Ov208Form *p, int key);
extern void *func_02030734(u32 heap,u32 size,int clear,const char *file,u16 line);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_020307B0(void *p);
extern void func_021C36CC(u16 *heap, struct Ov208Form *p, int key);
extern void func_02043AF4(struct Bmp *p,u32 a,u32 b,u32 c,u32 d,u32 e);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y,
                          int sx, int sy, u32 w, u32 h, u32 key);
extern void ov208_func_021C3A24(u16 *heap, struct Ov208Form *p, int key);
extern u32 func_02006B5C(u32 i);
extern u32 func_02006B94(u32 i);
extern u32 func_02006B3C(u32 i);
extern u32 func_02006B78(u32 i);
extern s8 func_02006B20(u32 i);
extern u16 func_02045768(struct Descriptor *p);
extern void func_02041090(u32 index,u32 a,u32 b,u32 c,u8 d,u8 e);
extern void func_0204B688(struct Actor *p,u32 value);
extern void func_0207D63C(u32 reg,int p1,int p2,int ev1,int ev2);
extern void func_021BC518(int *p);
extern void *ov208_func_021BC32C(void *proc, u32 size, u32 heap);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *ov208_func_021BC3A8(int key);
extern void *ov208_func_021BCF4C(void *a);
extern void *ov208_func_021BC3AC(int key);
extern void *func_020056A0(void (*fn)(int, char *), void *p, u32 c);
extern void ov208_func_021C4AC4(u16 *heap, struct Ov208Form *p, int key);
extern void *ov208_func_021BC448(u32 heap);
extern void ov208_func_021BC518(void *a);
extern void ov208_func_021BC508(int flag, void *a);
extern void *ov208_func_021BC610(u32 heap);
extern void *ov208_func_021BC3B4(int key);
extern void ov208_func_021BC97C(u32 a);
extern void ov208_func_021BCA54(u32 a, u32 packed);
extern void ov208_func_021C66C8(u16 *heap, struct Ov208Form *p, int key);
extern void ov208_func_021C53E0(u32 res, u32 obj);
extern void ov208_func_021C533C(u16 *heap, struct Ov208Form *p, int key);
extern void ov208_func_021C4A48(u16 *heap, struct Ov208Form *p, int key);
extern void ov208_func_021BDCA4(void *s, u8 v);
extern void ov208_func_021BC61C(u32 a);
extern void ov208_func_021BC464(u32 a);
extern void ov208_func_021C4AF4(u16 *heap, struct Ov208Form *p, int key);
extern void func_02030EAC(struct Node *n);
extern void ov208_func_021BC34C(void *proc);
extern void *ov208_func_021BC3B8(int key);
extern void func_02040618(u32 bgId, u32 which, u32 value);
extern void func_020414AC(u32 bgId);
extern void func_0204047C(int idx, unsigned short val);
extern void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d);
extern void ov208_func_021BCF58(void *s, int x);
extern void ov208_func_021C625C(u16 *heap, struct Ov208Form *p, int key);
extern void ov208_func_021C5664(u16 *heap, struct Ov208Form *p, int key);
extern void ov208_func_021C580C(u16 *heap, struct Ov208Form *p, int key);
extern void func_02015EA0(void *p);
extern void func_02015F50(struct McssFade *w, u32 cur, u32 target, s32_021C31CC step, u32 e);
extern u32  ov208_func_021BC9BC(int skip, u16 heap, u8 layer, u8 count, u8 pal, u8 palOfs,
                                u32 arc, u32 chr, u32 scr, u32 cell, u32 chrOfs);
extern u32  ov208_func_021BC844(u16 heap, u32 kind, u8 layer, u8 pal, u8 objPal);
extern void ov208_func_021BC758(u32 fade);
extern void ov208_func_021BC718(u32 fade);
extern void ov208_func_021BC4F4(int sub, u32 blend);
extern void ov208_func_021C7E74(u16 *heap, struct Ov208Form *p, int key);
extern int func_0201600C(void *p);
extern void ov208_func_021BC6D8(u32 fade);
extern int  ov208_func_021BDAD0(void *s);
extern u16  ov208_func_021BC3BC(char *p);
extern void ov208_func_021BDAAC(void *s, u32 mode, u32 kind, u32 flag);
extern void ov208_func_021BDAD4(void *s, int v);
extern void ov208_func_021BDBB8(void *s, u32 kind);
extern void ov208_func_021BDC48(void *s, u32 on);
extern int func_02012BF8(int a0, int a1);
extern void ov208_func_021BDC14(void *s, int b);
extern int  ov208_func_021BE840(void *icon);
extern void ov208_func_021BE82C(void *icon, int kind);
extern void ov208_func_021BE844(void *icon);
extern void func_02015EB0(void *p);
extern int  ov208_func_021BC6C8(u32 fade);
extern void ov208_func_021BDBA0(void *s);
extern void ov208_func_021C5D64(u16 *heap, struct Ov208Form *p, int key);
extern void ov208_func_021BC6F8(u32 fade);
extern void ov208_func_021BE854(void *icon);
extern void ov208_func_021BDAE8(void *s, int v);
extern void ov208_func_021C7EF8(u16 *heap, struct Ov208Form *p, int key);
extern void ov208_func_021C51A0(struct Ov208Anm_021C5214 *mdl, u32 sys);
extern void ov208_func_021C4FDC(u16 *heap, struct Ov208Form *p, int key);
extern void ov208_func_021BCF6C(void *s);
extern void func_02030D28(struct Ctx *c);
extern void func_02014C08(char *self);
extern void ov208_func_021C692C(u16 *heap, struct Ov208Form *p, int key);
extern void ov208_func_021C6E98(u16 *heap, struct Ov208Form *p, int key);
extern void ov208_func_021C6BB4(u16 *heap, struct Ov208Form *p, int key);
extern void ov208_func_021C75FC(u16 *heap, struct Ov208Form *p, int key);
extern void ov208_func_021C7860(u16 *heap, struct Ov208Form *p, int key);
extern void ov208_func_021BC99C(u32 win);
extern void ov208_func_021BC46C(u32 main, u32 sub);
extern void ov208_func_021BC678(u32 fade);
extern void ov208_func_021BC3CC(int key);
extern void ov208_func_021BC40C(int key);
extern void ov208_func_021C53F4(u16 *heap, int key, u8 *out, u16 *count, u16 *groups, u16 *twos, u16 *sel, u16 *next);
extern void ov208_func_021C5C64(u16 *heap, struct Ov208Form *p, int key);
extern void ov208_func_021C5F34(u16 *heap, struct Ov208Form *p, int key, int mode);
extern void ov208_func_021BDBEC(void *sys, int v);
extern int ov208_func_021BDC2C(void *sys);
extern void func_02012BE0(void *p, u32 a, u32 b);
extern void func_02014D2C(struct McssSys *sys);
extern void func_021BC6BC(char *p);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EE60(struct WordSet *p, u32 i, u16 v);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201ED04(struct WordSet *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_0204A298(int a0, int a1, int a2, int a3, u32 *out);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201C440(void *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0201EFA4(struct WordSet *ws, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void *func_02014B08(u32 id, void *heap);
extern void func_02016020(void *p, u32 v);
extern void func_02015BF0(void *obj);
extern int func_0202D060(void);
extern void func_02014CB8(struct Sub02014CB8Obj *o, u32 x);
extern u32  func_02030CB0(u32 n);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void func_02014CEC(u8 *p, u32 value);
extern void func_02014CD4(struct Sub02014CB8Obj *o);
extern void func_02014BA8(u8 *a0);
extern void func_02030DA4(int);
extern void func_020172AC(int a0, int a1);
extern void func_02017168(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, struct Stats *out, u32 a6);
extern struct Rec *func_020159C8(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);
extern void func_02015FF0(char *p, int v);
extern void func_02015E04(void *p);
extern void func_02015CAC(void *p, u32 *src);
extern void func_02015BA4(void *sys, void *obj);
extern s16 func_02015F14(void *p);
extern void func_02015C78(void *p, u32 *src);
extern void func_02015C30(void *p, u32 *out);
extern void *func_02015EE8(void *p);
extern void func_02063000(int p0, int p1, int p2, int p3);
extern void ov208_func_021C7F6C(VecF *pos, u32 species, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6,
                                u32 a7);
extern void func_02064CBC(struct Obj *x);
extern void func_02015E4C(void *p);
extern void func_02016380(void *o);
extern void func_021C595C(u16 *heap,struct Ov208Form *p,int key);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC78(void);
extern int func_0201BCEC(void);
extern s32_021C4E54 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_02049238(int);
extern u32  func_0201BABC(u32 species, u32 form, u32 gender, u32 isEgg);
extern s32_021C4E54 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern struct Obj *func_0204B294(void *owner, unsigned int res, unsigned int j, unsigned int k, const void *pos, unsigned short f, unsigned short heap);
extern void func_0204B92C(struct Obj *obj, u32 v);
extern u32  func_0201BB5C(u32 species, u32 form, u32 half, u32 isEgg);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
void func_021C31CC(int unused, char *q);
void func_021C3208(int unused, S_021C31CC *p);
void func_021C3218(u16 *heap,struct Ov208Form *p,int key);
void func_021C3268(void *unused, char *p, void *a2);
void func_021C3280(u16 *heap,struct Ov208Form *p,int key);
void func_021C32FC(u16 *heap, struct Ov208Form *p, int key);
void func_021C3318(u16 *heap, struct Ov208Form *p, int key);
void func_021C3354(unsigned short *p, void *a1, int a2);
void func_021C3374(void *a0, void *st, void *a2);
void func_021C3378(void *a0, void *a1, int a2, int a3, int a4);
void func_021C337C(void *a0, void *st, void *a2);
void ov208_func_021C3380(u16 *heap, struct Ov208Form *p, int key);
void func_021C3480(int unused, char *p, int key);
void func_021C34A4(u16 *heap,struct Ov208Form *p,int key);
void ov208_func_021C3514(u16 *heap, struct Ov208Form *p, int key);
void func_021C35DC(u16 *heap,struct Ov208Form *p,int key);
void func_021C3638(void *unused, char *p, void *a2);
void func_021C3650(u16 *heap, struct Ov208Form *p, int key);
void func_021C3678(u16 *heap,struct Ov208Form *p,int key);
void ov208_func_021C36CC(u16 *heap, struct Ov208Scroll *p, int key);
void ov208_func_021C3840(u16 *heap, struct Ov208Form *p, int key, u16 a, u16 b);
void func_021C3A24(u16 *heap,struct Ov208Form *p,int key);
void func_021C3AA8(void *unused, struct Ov208Form *p, int a2);
void func_021C3B14(void *unused, struct Ov208Form *p, int a2);
void func_021C3B68(u16 *p, u32 value);
int ov208_func_021C3B6C(void *proc, int *seq, u16 *heap, u8 *unused, int key);
int ov208_func_021C3C70(void *proc, int *seq, u16 *heap, struct Ov208Form *p, int key);
int ov208_func_021C3D3C(void *proc, int *seq, u16 *heap, struct Ov208Form *p, int key);
void ov208_func_021C4298(void *proc, int *seq, u16 *heap, struct Ov208Form *p, int key, int ev);
void func_021C47A0(u32 a, u32 b, u32 c, struct Ov208Form *p);
void ov208_func_021C47B4(int unused, char *p);
void ov208_func_021C47C4(u16 *heap, struct Ov208Form *p, int key, u32 *outStr, u32 *outB, int *outC, int *outD, u16 idx);
void ov208_func_021C48CC(u16 *heap, struct Ov208Form *p, int key);
void func_021C4A48(void *unused,struct Ov208Form *p);
void func_021C4AC4(u16 *heap, struct Ov208Form *p);
void func_021C4AF4(u16 *heap, struct Ov208Form *p);
void ov208_func_021C4B2C(void *a0, struct Ov208Form *p, int key);
void ov208_func_021C4B60(void *a0, struct Ov208Form *p, int a2, int i);
void ov208_func_021C4BB4(u16 *heap, struct Ov208Form *p, int key);
void ov208_func_021C4D68(u16 *heap, struct Ov208Form *p, int key, int i, u32 print, u32 win, u32 *active, u16 idx);
void ov208_func_021C4E54(u16 *heap, struct Ov208Form *p, int key);
void ov208_func_021C4EAC(u16 *heap, struct Ov208Form *p, int key);
void ov208_func_021C4F30(void *unused, struct Ov208Form *p);
void ov208_func_021C4F78(u16 *heap, struct Ov208Form *p, int key);
void func_021C4FDC(u16 *heap, struct Ov208Form *p, int key);
u32 ov208_func_021C5000(void *sys, u32 species, u32 gender, u32 side, u32 form, u32 shiny, u32 personality, u32 extra);
void func_021C5078(int a, int b);
void ov208_func_021C5090(u32 obj);
void ov208_func_021C50F8(u32 obj, Vec_021C50F8 *out);
void ov208_func_021C5128(struct Ov208Mdl *m, u32 heap, void *sys, u32 species, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9);
void func_021C51A0(struct Ov208Anm_021C5214 *p, int a);
void func_021C51C8(S_021C4E54 *p, int a, int b);
void func_021C51D4(struct Ov208Slot *s);
void func_021C5200(int *p);
void ov208_func_021C5214(struct Ov208Anm_021C5214 *p);
void ov208_func_021C5248(struct Ov208Turn *t);
void func_021C526C(u16 *heap,struct Ov208Form *p,int key);
void ov208_func_021C52F0(u16 *heap, struct Ov208Form *p, int key);
void func_021C533C(void *a, char *q);
u32 ov208_func_021C535C(u32 arc, u32 *res, u32 j, u32 k, u32 owner, u16 heap, u32 species, u32 form, u32 gender, u32 isEgg);
void func_021C53E0(int a, int b);
extern struct MsgBank *data_020A7370;
extern const char data_021C8E28[];
extern const struct Ov208WinTbl data_021C8830;
extern const u16 data_021C8794[6];
extern const char data_021C8E64[];
extern const Vec_021C5000 data_021C8804;
extern struct Ov208Cam data_021C8E40;





/*
 * Hands the element at +0x5C a 0x80 pair and a 0x1000 pair and marks +0x60.
 *
 * Blocker resolved: 0x0204B5AC was matched in arm9 (src/matched/
 * func_0204B5AC.c, shard pkt_0204B5AC), so the call at +0x30 attests as
 * `matched`.  All 58 concrete bytes equal (the 60-byte listing extent is 58
 * plus two padding bytes); the extent ran two bytes long because the follower
 * has no func_ label.
 */
void func_021C31CC(int unused, char *q)
{
    struct {
        unsigned int w[2];
        unsigned short h[2];
    } buf;

    buf.h[0] = 0x80;
    buf.h[1] = 0x80;
    buf.w[0] = 0x1000;
    buf.w[1] = 0x1000;
    func_0204B404((struct Obj *)(*(int *)(q + ((struct Obj09208 *)q)->f5C * 4 + 0x54)), (const struct Vec2 *)buf.h, 1);
    func_0204B5AC((struct Obj *)(*(int *)(q + ((struct Obj09208 *)q)->f5C * 4 + 0x54)), (struct Pair *)buf.w);
    ((struct Obj09208 *)q)->f60 = 1;
}





/*
 * Writes 3 to +0x60 when the word there, less one, is 0 or 1.
 */
void func_021C3208(int unused, S_021C31CC *p)
{
    unsigned int v = p->state;

    v -= 1;
    if (v <= 1)
        p->state = 3;
}




void func_021C3218(u16 *heap,struct Ov208Form *p,int key)
{
    func_02049B90(23,5,4,0,0,32,*heap);
    *(u32 *)&((struct Obj00146 *)p)->fC=func_020450F0(6,10,5,12,4,0,1);
    ((struct Obj00146 *)p)->f10=0;
    func_021C32FC(heap,p,key);
    func_02045334((struct Descriptor *)*(u32 *)&((struct Obj00146 *)p)->fC);
}





/*
 * Clears +0x10 and releases the two handles at +8 and +0xC.
 */
void func_021C3268(void *unused, char *p, void *a2)
{
    ((struct Obj09209 *)p)->f10 = 0;
    func_0201C6EC((struct PrintSys *)(((struct Obj09209 *)p)->f8));
    func_020452E8((struct Descriptor *)(((struct Obj09209 *)p)->fC));
}




void func_021C3280(u16 *heap,struct Ov208Form *p,int key)
{
    struct StrObj *text;
    u16 width;
    u16 available;
    text=func_02045EC0(data_020A7370,func_021BC3C0(key));
    width=func_0201D304(text,((struct Obj00146 *)p)->f4,0);
    available=func_020437DC(func_02045770(*(struct Descriptor * *)&((struct Obj00146 *)p)->fC));
    func_0201C724(((struct Obj00146 *)p)->f8,(u32)func_02045770(*(struct Descriptor * *)&((struct Obj00146 *)p)->fC),(s16)((u16)((available-width)/2)),(s16)1,(u32)text,((struct Obj00146 *)p)->f4,0x3c40);
    func_02045808((struct U16Vec *)text);
    ((struct Obj00146 *)p)->f10=1;
    func_021C3318(heap,p,(int)key);
}




void func_021C32FC(u16 *heap, struct Ov208Form *p, int key)
{
    ((struct Obj00146 *)p)->f10 = 0;
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj00146 *)p)->f8);
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00146 *)p)->fC), 0);
}




void func_021C3318(u16 *heap, struct Ov208Form *p, int key)
{
    struct Descriptor *d;
    if (((struct Obj00146 *)p)->f10 != 0) {
        if (func_0201C6C4(*(struct PrintSys * *)&((struct Obj00146 *)p)->f8, func_02045770(*(struct Descriptor * *)&((struct Obj00146 *)p)->fC)) == 0) {
            d = *(struct Descriptor * *)&((struct Obj00146 *)p)->fC;
            func_02045334(d);
            func_02045374((struct Cfg *)d);
            func_02041B6C(func_02045730(d));
            ((struct Obj00146 *)p)->f10 = 0;
        }
    }
}





/*
 * Posts message 0x17 with the halfword at +0 as its last argument.
 */
void func_021C3354(unsigned short *p, void *a1, int a2)
{
    func_02049B90(0x17, 5, 0, 0, 0x20, 0x20, *p);
}




/*
 * Empty stub; the listing pads it with two zero bytes.
 */
void func_021C3374(void *a0, void *st, void *a2)
{
}




void func_021C3378(void *a0, void *a1, int a2, int a3, int a4)
{
}




void func_021C337C(void *a0, void *st, void *a2)
{
}





void ov208_func_021C3380(u16 *heap, struct Ov208Form *p, int key)
{
    u64 now;
    u64 start;
    u64 diff;
    u64 ms;
    u16 cur;
    u16 secs;
    u16 rem;
    u16 hund;
    if (((struct Obj02256 *)p)->f68 != 0) {
        now = func_020870D0();
        start = *(u64 *)((u8 *)p + 0x6c);
        if (now >= start)
            diff = now - start;
        else
            diff = now + (0xFFFFFFFFFFFFFFFFULL - start);
        ms = (diff * 64) / 33514;
        if (ms > 9990)
            ms = 9990;
        ((struct Obj02256 *)p)->f74 = (u16)ms;
        if (((struct Obj02256 *)p)->f74 >= ((struct Obj02256 *)p)->f38) {
            ((struct Obj02256 *)p)->f74 = ((struct Obj02256 *)p)->f38;
            ((struct Obj02256 *)p)->f68 = 0;
            ov208_func_021C3208(heap, p, key);
        }
    }
    cur = ((struct Obj02256 *)p)->f74;
    if (cur != ((struct Obj02256 *)p)->f76) {
        secs = cur / 1000;
        rem = cur % 1000;
        hund = rem / 10 + ((rem % 10) >= 5 ? 1 : 0);
        ov208_func_021C337C(heap, p, key);
        ov208_func_021C3378(heap, p, key, secs, hund);
        ov208_func_021C2DE0(heap, (u8 *)p, key, secs, hund);
        ((struct Obj02256 *)p)->f76 = ((struct Obj02256 *)p)->f74;
    }
}





/*
 * BLOCKED.  Unverifiable: func_020065D8 resolves only through the `matched` class and layout/matched/ov093 holds func_021B911C in two shards, which aborts every manifest load.
 */
void func_021C3480(int unused, char *p, int key)
{
    int v;

    if (((struct Obj00146 *)p)->f68 != 0) {
        v = func_02006650();
        if (v != 0)
            func_020065D8();
        ((struct Obj00146 *)p)->f68 = 0;
    }
    ((struct Obj00146 *)p)->f74 = 0;
}




void func_021C34A4(u16 *heap,struct Ov208Form *p,int key)
{
    if(*(struct Obj **)((u8 *)p+((struct Obj00146 *)p)->f5C*4+0x54))
        func_0204B3DC(*(struct Obj **)((u8 *)p+((struct Obj00146 *)p)->f5C*4+0x54),0);
    ((struct Obj00146 *)p)->f5C=(((struct Obj00146 *)p)->f5C+1)%2;
    func_021C32FC(heap,p,key);
    func_021C2FEC(heap,(struct S_021C31CC *)p,key,((struct Obj00146 *)p)->f5C);
    func_021C2E6C(heap,(u8 *)p,key,((struct Obj00146 *)p)->f5C);
    func_021C3280(heap,p,key);
    func_021C3480((int)heap,(char *)p,key);
    func_021C3678(heap,p,key);
}





void ov208_func_021C3514(u16 *heap, struct Ov208Form *p, int key)
{
    u32 hit;
    u16 species;
    u32 x;
    u32 y;
    u32 form;
    u32 o1;
    u32 o2;
    void *pd;
    hit = 0;
    if (((struct Obj06684 *)p)->fD0 != 0) {
        if (func_020362DC() & 1) {
            func_020355D8(0);
            hit = 1;
        } else if (func_02035D20(&x, &y) != 0) {
            if (x < 0x100 && y < 0xa8) {
                hit = 1;
                func_020355D8(1);
            }
        }
    }
    if (hit != 0) {
        pd = func_0200CA1C((void *)ov208_func_021BC3A4(key));
        species = ov208_func_021BC3C0(key);
        func_0200CC40(pd, species, &o1, &o2, &form, *heap);
        ((struct Obj06684 *)p)->f64 = func_02006984(species, form, 0x40, 0, 0, 0, 0, 0);
        ((struct Obj06684 *)p)->f74 = 0;
        *(u64 *)((u8 *)p + 0x6c) = func_020870D0();
        ((struct Obj06684 *)p)->f68 = 1;
        ov208_func_021C3840(heap, p, key, species, form);
        ov208_func_021C31CC(heap, p, key);
    }
}




void func_021C35DC(u16 *heap,struct Ov208Form *p,int key)
{
    ((struct Obj00146 *)p)->f14=func_02030734(*heap,0x3a2,1,data_021C8E28,0x8a1);
    *(u32 *)&((struct Obj00146 *)p)->f20=func_020450F0(3,1,2,31,15,1,1);
    func_021C3678(heap,p,key);
    *(struct Bmp * *)&((struct Obj00146 *)p)->f2C=func_02043678(121,15,32,*heap);
}





/*
 * Releases the three handles at +0x2C, +0x20 and +0x14.
 */
void func_021C3638(void *unused, char *p, void *a2)
{
    func_020437AC((struct Obj020437AC *)(((struct Obj09210 *)p)->f2C));
    func_020452E8((struct Descriptor *)(((struct Obj09210 *)p)->f20));
    func_020307B0((void *)(((struct Obj09210 *)p)->f14));
}




void func_021C3650(u16 *heap, struct Ov208Form *p, int key)
{
    if (((u8 *)p)[0x24] != 0) {
        ((u8 *)p)[0x24]--;
        return;
    }
    func_021C36CC(heap, p, key);
    ((u8 *)p)[0x24] = 0;
}




void func_021C3678(u16 *heap,struct Ov208Form *p,int key)
{
    struct Bmp *bmp;
    ((u8 *)p)[0x24] = 0;
    ((struct Obj00146 *)p)->f18 = 0;
    ((struct Obj00146 *)p)->f1A = 0;
    ((struct Obj00146 *)p)->f26 = 0;
    ((struct Obj00146 *)p)->f28 = 0;
    ((struct Obj00146 *)p)->f30 = 0;
    ((struct Obj00146 *)p)->f32 = *(s16 *)&((struct Obj00146 *)p)->f30;
    ((struct Obj00146 *)p)->f38 = 0;
    bmp = func_02045770(*(struct Descriptor * *)&((struct Obj00146 *)p)->f20);
    func_02043B5C((struct CharBuf *)bmp,0);
    func_02043AF4(bmp,0,0x37,0xee,1,0xf);
    func_021C3A24(heap,p,key);
}





void ov208_func_021C36CC(u16 *heap, struct Ov208Scroll *p, int key)
{
    s16 *qd;
    struct Bmp *bmp;
    s16 x;
    s16 *qa;
    s16 n;
    bmp = func_02045770(p->desc);
    x = (s16)(((s16)(p->a + (p->b << 3)) + 0xee) % 0xf8);
    n = 0;
    qa = &p->a;
    p->a = *qa + 2;
    while (p->a >= 8) {
        func_02043AF4(bmp, (s16)(p->b << 3), 0, 8, 0x78, 0);
        p->b = (p->b + 1) % 0x1f;
        *qa = *qa - 8;
    }
    if (p->a > 0)
        func_02043AF4(bmp, (s16)(p->b << 3), 0, (u16)p->a, 0x78, 0);
    qd = &p->d;
    while (n < 2) {
        s16 end;
        s16 d;
        int w;
        d = p->c - p->d;
        end = (s16)(x + 2 - n);
        if (d <= 0)
            break;
        if (end > 0xf8)
            end = 0xf8;
        if (end - x > d)
            end = (s16)(x + d);
        w = end - x;
        func_020439A0(p->dst, bmp, p->d, 0, x, 0, w, 0x78, 0xffff);
        n = (s16)(n + (s16)w);
        x = (s16)(end % 0xf8);
        *qd = *qd + n;
    }
    while (n < 2) {
        s16 end;
        int w;
        end = (s16)(x + 2 - n);
        if (end > 0xf8)
            end = 0xf8;
        w = end - x;
        func_02043AF4(bmp, x, 0x37, (u16)w, 1, 0xf);
        n = (s16)(n + (s16)w);
        x = (s16)(end % 0xf8);
    }
    ov208_func_021C3A24(heap, (struct Ov208Form *)p, key);
}





void ov208_func_021C3840(u16 *heap, struct Ov208Form *p, int key, u16 a, u16 b)
{
    u32 ca;
    u32 cb;
    u32 k;
    u32 i;
    u32 end;
    int lo;
    int hi;
    int v;
    s16 w;
    int t;
    *(s8 * *)&((struct Obj01010 *)p)->f34 = (s8 *)func_02006B5C(((struct Obj01010 *)p)->f64);
    ((struct Obj01010 *)p)->f32 = 0;
    if (a == ((struct Obj01010 *)p)->f26 && b == ((struct Obj01010 *)p)->f28)
        return;
    ((struct Obj01010 *)p)->f26 = a;
    ((struct Obj01010 *)p)->f28 = b;
    ca = func_02006B94(((struct Obj01010 *)p)->f64);
    cb = func_02006B3C(((struct Obj01010 *)p)->f64);
    ((struct Obj01010 *)p)->f38 = (u32)(1000.0f * (32768.0f * (float)func_02006B78(((struct Obj01010 *)p)->f64)
                                           / (float)(int)ca
                                           / (float)(int)cb) + 0.5f);
    func_02043B5C((struct CharBuf *)(*(struct Bmp * *)&((struct Obj01010 *)p)->f2C), 0);
    k = 0;
    i = 0;
    while (i < func_02006B78(((struct Obj01010 *)p)->f64)) {
        cb = func_02006B3C(((struct Obj01010 *)p)->f64);
        ca = func_02006B94(((struct Obj01010 *)p)->f64);
        end = (u32)((float)(k + 1) * ((float)(int)ca * (float)(int)cb / 32768.0f / 60.0f / 2.0f));
        if (end > func_02006B78(((struct Obj01010 *)p)->f64))
            end = func_02006B78(((struct Obj01010 *)p)->f64);
        if (k < 0x3c0) {
            lo = 500;
            hi = -500;
            for (; i < end; i++) {
                t = (*(s8 **)((u8 *)p + 0x34))[i] * 0x2f * func_02006B20(((struct Obj01010 *)p)->f64) / 128;
                v = (s16)(t / 128);
                if (v > 500)
                    v = 500;
                else if (v < -500)
                    v = -500;
                w = v;
                if (w < lo)
                    lo = w;
                if (w > hi)
                    hi = w;
            }
            if (lo <= hi) {
                if (lo < -55)
                    lo = -55;
                if (hi > 0x37)
                    hi = 0x37;
                func_02043AF4(*(struct Bmp * *)&((struct Obj01010 *)p)->f2C, (s16)k, (s16)(0x37 - hi), 1, (u16)(hi - lo + 1), 0xf);
            }
        }
        k++;
        i = end + 1;
    }
    if (k > 0x3c0)
        k = 0x3c0;
    ((struct Obj01010 *)p)->f30 = k;
}




void func_021C3A24(u16 *heap,struct Ov208Form *p,int key)
{
    u16 tile;
    u16 row;
    u16 index;
    u16 col;
    int base;
    tile=func_02045768(*(struct Descriptor * *)&((struct Obj06685 *)p)->f20);
    index=0;
    for(row=0;row<15;row++) {
        base=tile+row*31;
        for(col=0;col<31;col++) {
            (*(u16 **)((u8 *)p+0x14))[index]=(u16)(base+(col+((struct Obj06685 *)p)->f1A)%31)|0x1000;
            index++;
        }
    }
    func_02041090(3,((struct Obj06685 *)p)->f14,1,2,31,15);
    ((struct Obj06685 *)p)->f1C=1;
    func_02045334(*(struct Descriptor * *)&((struct Obj06685 *)p)->f20);
}




void func_021C3AA8(void *unused, struct Ov208Form *p, int a2)
{
    u8 i;
    for(i=0;i<2;i++) {
        if(*(struct Actor **)((u8 *)p+i*4+0x54))
            func_0204B688(*(struct Actor **)((u8 *)p+i*4+0x54),0);
    }
    for(i=0;i<6;i++)
        func_0204B688(*(struct Actor **)((u8 *)p+i*4+0x9c),0);
    func_0207D63C(0x04000050,4,0x3f,0x10,8);
    func_0207D63C(0x04001050,0,0x3f,0xc,4);
}




void func_021C3B14(void *unused, struct Ov208Form *p, int a2)
{
    u8 i;
    for (i = 0; i < 2; i++) {
        if (*(struct Actor **)((u8 *)p + i * 4 + 0x54))
            func_0204B688(*(struct Actor **)((u8 *)p + i * 4 + 0x54), 1);
    }
    for (i = 0; i < 6; i++)
        func_0204B688(*(struct Actor **)((u8 *)p + i * 4 + 0x9c), 1);
    func_021BC518(*(int * *)&((struct Obj00146 *)p)->fC0);
    func_021BC518(*(int * *)&((struct Obj00146 *)p)->fC4);
}




void func_021C3B68(u16 *p, u32 value)
{
    *p = value;
}




int ov208_func_021C3B6C(void *proc, int *seq, u16 *heap, u8 *unused, int key)
{
    struct Ov208Form *p;
    u8 i;
    p = ov208_func_021BC32C(proc, 0x6e4, *heap);
    i = 0;
    func_02082BCC(p, 0, 0x6e4);
    PW(0) = ov208_func_021BCF4C(ov208_func_021BC3A8(key));
    PW(4) = ov208_func_021BC3AC(key);
    for (i = 0; i < 4; i++) {
        *(u32 *)((u8 *)p + i * 0x44 + 0xc) = 0;
        *(u32 *)((u8 *)p + i * 0x44 + 0x10) = 0;
    }
    for (i = 0; i < 2; i++)
        *(u32 *)((u8 *)p + 0x13c + i * 4) = 0;
    W(0x144) = 0;
    W(0x124) = 1;
    PW(0x6a0) = func_020056A0(ov208_func_021C47B4, p, 1);
    ov208_func_021C4AC4(heap, p, key);
    PW(0x6a4) = ov208_func_021BC448(*heap);
    PW(0x6a8) = ov208_func_021BC448(*heap);
    ov208_func_021BC518(PW(0x6a4));
    ov208_func_021BC518(PW(0x6a8));
    ov208_func_021BC508(0, PW(0x6a4));
    ov208_func_021BC508(1, PW(0x6a8));
    PW(0x6ac) = ov208_func_021BC610(*heap);
    W(0x6b0) = 0;
    W(0x6b4) = 1;
    W(0x6b8) = 0;
    W(0x6d4) = 0;
    W(0x6d8) = 0;
    W(0x6dc) = 1;
    W(0x6e0) = 1;
    return 1;
}








int ov208_func_021C3C70(void *proc, int *seq, u16 *heap, struct Ov208Form *p, int key)
{
    void *sys;
    u8 i;
    sys = ov208_func_021BC3B4(key);
    ov208_func_021BC97C(((struct Obj02547 *)p)->f5BC);
    ov208_func_021BC97C(((struct Obj02547 *)p)->f5B8);
    ov208_func_021BCA54(7, ((struct Obj02547 *)p)->f5B4);
    ov208_func_021C66C8(heap, p, key);
    for (i = 0; i < 2; i++) {
        if (((struct Ov208Form *)p)->obj[i] != 0)
            ov208_func_021C53E0(((struct Ov208Form *)p)->res[i], ((struct Ov208Form *)p)->obj[i]);
        ((struct Ov208Form *)p)->obj[i] = 0;
    }
    ov208_func_021C533C(heap, p, key);
    ov208_func_021C4A48(heap, p, key);
    ov208_func_021BDCA4(sys, 0);
    ov208_func_021BC61C(((struct Obj02547 *)p)->f6AC);
    ov208_func_021BC464(((struct Obj02547 *)p)->f6A8);
    ov208_func_021BC464(((struct Obj02547 *)p)->f6A4);
    ov208_func_021C4AF4(heap, p, key);
    func_02030EAC((struct Node *)(((struct Obj02547 *)p)->f6A0));
    ov208_func_021BC34C(proc);
    return 1;
}








int ov208_func_021C3D3C(void *proc, int *seq, u16 *heap, struct Ov208Form *p, int key)
{
    void *res;
    void *scene;
    void *icon;
    u8 i;
    int done;
    int settled;
    int ready;
    int idle;

    res = ov208_func_021BC3A8(key);
    scene = ov208_func_021BC3B4(key);
    icon = ov208_func_021BC3B8(key);
    switch (*seq) {
    case 0:
        *seq = 1;
        for (i = 0; i <= 7; i++) {
            if (i != 1 && i != 5) {
                func_02040618(i, 0, 0);
                func_02040618(i, 3, 0);
                func_020414AC(i);
            }
        }
        func_0204047C(0, 0);
        func_0204047C(2, 2);
        func_0204047C(3, 3);
        func_0204047C(6, 1);
        func_0204047C(4, 3);
        func_0204047C(7, 2);
        ov208_func_021BDCA4(scene, 2);
        func_0207D4B0(1, 0, 1);
        ov208_func_021BCF58(res, *heap);
        ov208_func_021C4F78(heap, p, key);
        ov208_func_021C48CC((u16 *)heap, (struct Ov208Form *)p, key);
        ov208_func_021C625C(heap, p, key);
        ov208_func_021C5664(heap, p, key);
        ov208_func_021C52F0(heap, p, key);
        ov208_func_021C580C(heap, p, key);
        func_0204B688((struct Actor *)(*(u32 *)((u8 *)p + W(0x144) * 4 + 0x13c)), 1);
        func_02015EA0((void *)W(0xc));
        func_02015F50((struct McssFade *)W(0xc), 16, 16, 0, 0);
        if (W(0x94) != 0) {
            func_02015EA0((void *)W(0x94));
            func_02015F50((struct McssFade *)W(0x94), 16, 16, 0, 0);
        }
        W(0x5b4) = ov208_func_021BC9BC(0, *heap, 7, 1, 1, 0, 0x9f, 2, 12, 0x23, 0);
        W(0x5b8) = ov208_func_021BC844(*heap, 3, 3, 1, 2);
        W(0x5bc) = ov208_func_021BC844(*heap, 3, 4, 2, 3);
        ov208_func_021BC758(W(0x6ac));
        ov208_func_021BC718(W(0x6ac));
        break;
    case 1:
        *seq = 2;
        ov208_func_021BC4F4(0, W(0x6a4));
        ov208_func_021BC4F4(1, W(0x6a8));
        ov208_func_021C7E74(heap, p, key);
        break;
    case 2:
        *seq = 3;
        break;
    case 3:
        done = 1;
        if (func_0201600C((void *)W(0xc)) != 0)
            done = 0;
        if (W(0x94) != 0 && func_0201600C((void *)W(0x94)) != 0)
            done = 0;
        if (done) {
            *seq = 4;
            ov208_func_021BC6D8(W(0x6ac));
            if (ov208_func_021BDAD0(scene) != 2) {
                ov208_func_021BDAAC(scene, 0, 3, ov208_func_021BC3BC((char *)key) > 1);
                ov208_func_021BDAD4(scene, 0);
            } else {
                ov208_func_021BDBB8(scene, 3);
            }
            ov208_func_021BDC48(scene, 0);
            ov208_func_021BDC14(scene, func_02012BF8(ov208_func_021BC3A4(key), 20));
            if (ov208_func_021BE840(icon) != 2) {
                ov208_func_021BE82C(icon, 3);
                ov208_func_021BE844(icon);
            }
            func_02015EB0((void *)W(0xc));
            func_02015F50((struct McssFade *)W(0xc), 16, 0, -2, 0);
            if (W(0x94) != 0) {
                func_02015EB0((void *)W(0x94));
                func_02015F50((struct McssFade *)W(0x94), 16, 0, -2, 0);
            }
        }
        break;
    case 4:
        done = 1;
        if (func_0201600C((void *)W(0xc)) != 0)
            done = 0;
        if (W(0x94) != 0 && func_0201600C((void *)W(0x94)) != 0)
            done = 0;
        if (ov208_func_021BC6C8(W(0x6ac)) == 0 && ov208_func_021BDAD0(scene) == 2
            && ov208_func_021BE840(icon) == 2 && done) {
            ov208_func_021BDBA0(scene);
            ov208_func_021BDC48(scene, 1);
            *seq = 5;
        }
        break;
    case 5:
        if (W(0x6b0) != 0) {
            *seq = 6;
            for (i = 0; i < 4; i++) {
                if (OBJ(i) != 0)
                    func_02015F50((struct McssFade *)OBJ(i), 0, 0, 0, 0);
            }
        } else {
            ov208_func_021C5D64(heap, p, key);
        }
        break;
    case 6:
        settled = 1;
        for (i = 0; i < 4; i++) {
            if (OBJ(i) != 0 && func_0201600C((void *)OBJ(i)) != 0) {
                settled = 0;
                break;
            }
        }
        if (settled) {
            *seq = 7;
            ov208_func_021BC6F8(W(0x6ac));
            ov208_func_021BE854(icon);
            if (W(0x6b0) == 2)
                ov208_func_021BDAE8(scene, 0);
            for (i = 0; i < 4; i++) {
                if (OBJ(i) != 0)
                    func_02015F50((struct McssFade *)OBJ(i), 0, 16, -2, 0);
            }
        }
        break;
    case 7:
        ready = 0;
        idle = 1;
        for (i = 0; i < 4; i++) {
            if (OBJ(i) != 0 && func_0201600C((void *)OBJ(i)) != 0) {
                idle = 0;
                break;
            }
        }
        if (ov208_func_021BC6C8(W(0x6ac)) == 0 && ov208_func_021BE840(icon) == 0 && idle) {
            if (W(0x6b0) == 2) {
                if (ov208_func_021BDAD0(scene) == 0)
                    ready = 1;
            } else {
                ready = 1;
            }
        }
        if (ready)
            *seq = 8;
        break;
    case 8:
        *seq = 9;
        ov208_func_021C7EF8(heap, p, key);
        ov208_func_021BC508(0, PW(0x6a4));
        ov208_func_021BC508(1, PW(0x6a8));
        break;
    case 9:
        for (i = 0; i < 4; i++)
            ov208_func_021C51A0(&p->item[i], W(8));
        ov208_func_021C4FDC(heap, p, key);
        ov208_func_021BCF6C(res);
        func_0207D4B0(1, 0, 0);
        return 1;
    }
    if (W(8) != 0) {
        func_02030D28((struct Ctx *)W(0x120));
        func_02014C08((char *)W(8));
        for (i = 0; i < 4; i++)
            ov208_func_021C5214(&p->item[i]);
    }
    if (*seq >= 3) {
        ov208_func_021C692C(heap, p, key);
        ov208_func_021C6E98(heap, p, key);
        ov208_func_021C6BB4(heap, p, key);
        ov208_func_021C75FC(heap, p, key);
        ov208_func_021C7860(heap, p, key);
        ov208_func_021BC99C(W(0x5b8));
        ov208_func_021BC99C(W(0x5bc));
    }
    ov208_func_021BC46C(W(0x6a4), W(0x6a8));
    ov208_func_021BC678(W(0x6ac));
    ov208_func_021C4B2C(heap, (struct Ov208Form *)p, key);
    return 0;
}








void ov208_func_021C4298(void *proc, int *seq, u16 *heap, struct Ov208Form *p, int key, int ev)
{
    u8 bufA[0x400];
    u8 bufB[0x400];
    struct Ov208Sel sA;
    struct Ov208Sel sB;
    u32 id;
    void *sys;
    int flag;
    u32 cur;
    u32 id2;
    u32 n;
    u32 k;
    if (p == 0)
        return;
    sys = ov208_func_021BC3B4(key);
    flag = 0;
    W(0x698) = flag;
    W(0x6d4) = flag;
    switch (ev) {
    case 0xa: case 0xb: case 0xc: case 0xd: case 0xe: case 0xf: case 0x10: case 0x11:
    case 0x1c: case 0x1d: case 0x1e: case 0x1f: case 0x20:
        W(0x6b4) = flag;
        break;
    }
    switch (ev) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
    case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a:
        flag = 1;
        W(0x6b4) = 1;
        break;
    }
    switch (ev) {
    case 0xc:
    case 0x1e:
        if (W(0x6b8) == 0) {
            id = ov208_func_021BC3C0(key);
            ov208_func_021BC3CC(key);
            if (id != ov208_func_021BC3C0(key))
                ov208_func_021C580C(heap, p, key);
        } else if (W(0x6b8) == 4) {
            id = ov208_func_021BC3C0(key);
            ov208_func_021BC3CC(key);
            cur = ov208_func_021BC3C0(key);
            while (id != cur) {
                ov208_func_021C53F4(heap, key, bufA, &sA.count, &sA.groups, &sA.twos, &sA.sel, &sA.next);
                if (sA.count >= 2)
                    break;
                ov208_func_021BC3CC(key);
                cur = ov208_func_021BC3C0(key);
            }
            if (id != cur) {
                ov208_func_021C580C(heap, p, key);
                if (sA.count >= 3)
                    ov208_func_021BDBEC(sys, 1);
                else
                    ov208_func_021BDBEC(sys, 0);
            }
        }
        break;
    case 0xd:
    case 0x1f:
        if (W(0x6b8) == 0) {
            id = ov208_func_021BC3C0(key);
            ov208_func_021BC40C(key);
            if (id != ov208_func_021BC3C0(key))
                ov208_func_021C580C(heap, p, key);
        } else if (W(0x6b8) == 4) {
            id = ov208_func_021BC3C0(key);
            ov208_func_021BC40C(key);
            id2 = ov208_func_021BC3C0(key);
            while (id != id2) {
                ov208_func_021C53F4(heap, key, bufB, &sB.count, &sB.groups, &sB.twos, &sB.sel, &sB.next);
                if (sB.count >= 2)
                    break;
                ov208_func_021BC40C(key);
                id2 = ov208_func_021BC3C0(key);
            }
            if (id != id2) {
                ov208_func_021C580C(heap, p, key);
                if (sB.count >= 3)
                    ov208_func_021BDBEC(sys, 1);
                else
                    ov208_func_021BDBEC(sys, 0);
            }
        }
        break;
    case 0x1c:
        k = 0x548;
        n = H(k);
        if (n >= 3) {
            H(k + 8)++;
            H(k + 8) = H(k + 8) % n;
            if (H(k + 6) == H(k + 8)) {
                H(k + 8)++;
                n = H(k);
                H(k + 8) = H(k + 8) % n;
            }
            ov208_func_021C5C64(heap, p, key);
            W(0x698) = 1;
            W(0x6d4) = 1;
        }
        break;
    case 0x1d:
        k = 0x548;
        n = H(k);
        if (n >= 3) {
            H(k + 8) += (u16)(n - 1);
            H(k + 8) = H(k + 8) % n;
            if (H(k + 6) == H(k + 8)) {
                H(k + 8) += (u16)(H(k) - 1);
                H(k + 8) = H(k + 8) % (u32)H(k);
            }
            ov208_func_021C5C64(heap, p, key);
            W(0x698) = 1;
            W(0x6d4) = 1;
        }
        break;
    case 0x20:
        if (H(0x548) >= 2) {
            ov208_func_021C5F34(heap, p, key, 5);
            W(0x6d8) = 1;
            W(0x6dc) = 0;
            W(0x6e0) = 0;
        } else {
            W(0x6d8) = 1;
            W(0x6dc) = 1;
            W(0x6e0) = 0;
        }
        break;
    }
    switch (ev) {
    case 0:
        break;
    case 1:
    case 2:
        W(0x6b0) = 2;
        return;
    case 6:
    case 7:
    case 8:
        W(0x6b0) = 1;
        return;
    case 3:
    case 24:
        ov208_func_021BDBA0(sys);
        return;
    case 4:
    case 25:
        ov208_func_021BDBA0(sys);
        return;
    case 5:
        func_02012BE0((void *)ov208_func_021BC3A4(key), 0x14, ov208_func_021BDC2C(sys));
        ov208_func_021BDBA0(sys);
        return;
    case 22:
        ov208_func_021BDBA0(sys);
        return;
    case 23:
        ov208_func_021BDBA0(sys);
        return;
    case 21:
        if (W(0x6b8) == 4)
            ov208_func_021C5F34(heap, p, key, 6);
        return;
    case 26:
        if (W(0x6d8) != 0) {
            W(0x6e0) = 1;
            if (W(0x6dc) != 0) {
                W(0x6d8) = 0;
                ov208_func_021BDBA0(sys);
                return;
            }
        }
        return;
    default:
        if (flag != 0)
            ov208_func_021BDBA0(sys);
        return;
    }
}







void func_021C47A0(u32 a, u32 b, u32 c, struct Ov208Form *p)
{
    if (p != 0 && *(struct McssSys * *)&((struct Obj14660 *)p)->f8 != 0)
        func_02014D2C(*(struct McssSys * *)&((struct Obj14660 *)p)->f8);
}








void ov208_func_021C47B4(int unused, char *p)
{
    func_021BC6BC(*(char * *)&((struct Obj25510 *)p)->f6AC);
}







void ov208_func_021C47C4(u16 *heap, struct Ov208Form *p, int key, u32 *outStr, u32 *outB, int *outC, int *outD,
                         u16 idx)
{
    u32 str = 0;
    u32 b = 0;
    int c = 0;
    int d = 0;
    u16 k;
    u32 ws;
    u32 src;
    u16 n;
    u16 i;

    k = func_021BC3C0(key);
    switch (*(u32 *)((u8 *)p + 0x148 + idx * 16)) {
    case 0:
        ws = (u32)func_0201EC64(*heap);
        src = ((struct Obj06686 *)p)->f5A4;
        str = (u32)func_020457B0(0x40, *heap);
        func_0201EE60((struct WordSet *)ws, 0, k);
        func_0201F250((struct WordSet *)ws, (void *)str, (void *)src);
        func_0201ED04((struct WordSet *)ws);
        c = 1;
        break;
    case 1:
        switch (*(u16 *)((u8 *)p + 0x150 + idx * 16)) {
        case 0:
            str = ((struct Obj06686 *)p)->f5A8;
            break;
        case 1:
            str = ((struct Obj06686 *)p)->f5AC;
            break;
        }
        break;
    case 2:
        n = *(u16 *)((u8 *)p + 0x150 + idx * 16);
        for (i = 0; i != n; i++) {
            k = (*(u16 **)((u8 *)p + 0x594))[k];
            if (k == 0)
                break;
        }
        str = (u32)func_02045EC0((struct MsgBank *)(((struct Obj06686 *)p)->f598), k);
        c = 1;
        break;
    }
    switch (*(u32 *)((u8 *)p + 0x14c + idx * 16)) {
    case 0:
    case 1:
        break;
    case 2:
        b = ((struct Obj06686 *)p)->f5B0;
        d = 0;
        break;
    }
    *outStr = str;
    *outB = b;
    *outC = c;
    *outD = d;
}







void ov208_func_021C48CC(u16 *heap, struct Ov208Form *p, int key)
{
    struct Ov208WinTbl t;
    u32 size;
    u32 bmp;
    u32 s;
    u8 i;

    t = data_021C8830;
    func_02049B90(0x17, 5, 4, 0, 0, 0x20, *heap);
    func_02049B90(0x17, 5, 0, 0, 0, 0x20, *heap);
    for (i = 0; i < 5; i++) {
        p->win[i] = func_020450F0(t.d[i][0], t.d[i][1], t.d[i][2], t.d[i][3], t.d[i][4],
                                  t.d[i][5], t.d[i][6]);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 0);
        func_02045334((struct Descriptor *)p->win[i]);
    }
    p->msg = (u32)func_02045B38(0, 2, 0xea, *heap);
    p->msg2 = (u32)func_02045B38(0, 2, 0xf4, *heap);
    p->marc = (u32)func_0204A298(0x62, 0, 0, *heap, &size);
    bmp = (u32)func_02045770((struct Descriptor *)p->win[2]);
    s = (u32)func_02045EC0((struct MsgBank *)p->msg, 0xb8);
    func_0201C724((void *)p->print[2], bmp, 0, 1, s, p->font, 0x3c40);
    func_02045808((struct U16Vec *)s);
    s = (u32)func_02045EC0((struct MsgBank *)p->msg, 0xb9);
    func_0201C724((void *)p->print[2], bmp, 0, 0x11, s, p->font, 0x3c40);
    func_02045808((struct U16Vec *)s);
    p->active[2] = 1;
    ov208_func_021C4B60(heap, (struct Ov208Form *)p, key, 2);
    for (i = 0; i < 6; i++)
        p->str[i] = (u32)func_02045EC0((struct MsgBank *)p->msg, data_021C8794[i]);
}






void func_021C4A48(void *unused,struct Ov208Form *p)
{
    u8 i;
    for(i=0;i<5;i++) {
        *(u32 *)((u8 *)p+i*4+0x568)=0;
        func_0201C6EC(*(struct PrintSys **)((u8 *)p+i*4+0x57c));
        func_020452E8(*(struct Descriptor **)((u8 *)p+i*4+0x554));
    }
    for(i=0;i<6;i++)func_02045808(*(struct U16Vec **)((u8 *)p+i*4+0x59c));
    func_02045C04(*(struct Rec * *)&((struct Obj10908 *)p)->f590);
    func_02045C04(*(struct Rec * *)&((struct Obj10908 *)p)->f598);
    func_020307B0(((struct Obj10908 *)p)->f594);
}





void func_021C4AC4(u16 *heap, struct Ov208Form *p)
{
    u8 i;
    for (i = 0; i < 5; i++) {
        p->print[i] = func_0201C440((void *)(*heap));
        p->active[i] = 0;
    }
}





void func_021C4AF4(u16 *heap, struct Ov208Form *p)
{
    u8 i;
    for (i = 0; i < 5; i++) {
        p->active[i] = 0;
        func_0201C6EC((struct PrintSys *)p->print[i]);
        func_0201C4C0((struct PrintSys *)p->print[i]);
    }
}






void ov208_func_021C4B2C(void *a0, struct Ov208Form *p, int key)
{
    u8 i;

    for (i = 0; i < 5; i++) {
        func_0201C4E4((struct PrintSys *)p->print[i]);
        ov208_func_021C4B60((u16 *)a0, (struct Ov208Form *)((struct Ov208Form *)p), key, i);
    }
}






void ov208_func_021C4B60(void *a0, struct Ov208Form *p, int a2, int i)
{
    u32 w;

    if (p->active[i] != 0 && func_0201C6C4((struct PrintSys *)p->print[i], (void *)((u32)func_02045770((struct Descriptor *)p->win[i]))) == 0) {
        w = p->win[i];
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_02041B6C(func_02045730((struct Descriptor *)w));
        p->active[i] = 0;
    }
}






void ov208_func_021C4BB4(u16 *heap, struct Ov208Form *p, int key)
{
    u8 i;
    u16 species;
    u16 width;
    struct Bmp *bmp;
    struct Bmp *bmp2;
    struct StrObj *text;
    struct WordSet *ws;
    struct WordSet *ws2;
    struct U16Vec *str;
    void *src;
    void *src2;
    for (i = 0; i <= 1; i++) {
        p->active[i] = 0;
        func_0201C6EC((struct PrintSys *)p->print[i]);
        func_02043B5C(func_02045770((struct Descriptor *)p->win[i]), 0);
    }
    species = ov208_func_021BC3C0(key);
    bmp = func_02045770((struct Descriptor *)p->win[0]);
    text = func_02045EC0(data_020A7370, species);
    width = func_0201D304(text, p->font, 0);
    func_0201C724((void *)p->print[0], (u32)bmp, (s16)((u16)((func_020437DC(bmp) - width) / 2)), (s16)1, (u32)text, p->font, 0x3c40);
    p->active[0] = 1;
    func_02045808((struct U16Vec *)text);
    bmp2 = func_02045770((struct Descriptor *)p->win[1]);
    ws = func_0201EC64(*heap);
    src = ((struct Obj01179 *)p)->f59C;
    str = func_020457B0(8, *heap);
    func_0201EFA4(ws, 0, ((struct Obj01179 *)p)->f54A, 2, 1, 1);
    func_0201F250(ws, str, src);
    func_0201C724((void *)p->print[1], (u32)bmp2, (s16)0, (s16)1, (u32)str, p->font, 0x3c40);
    func_02045808(str);
    func_0201ED04(ws);
    ws2 = func_0201EC64(*heap);
    src2 = ((struct Obj01179 *)p)->f5A0;
    str = func_020457B0(8, *heap);
    func_0201EFA4(ws2, 0, ((struct Obj01179 *)p)->f54C, 2, 1, 1);
    func_0201F250(ws2, str, src2);
    func_0201C724((void *)p->print[1], (u32)bmp2, (s16)0, (s16)0x11, (u32)str, p->font, 0x3c40);
    func_02045808(str);
    func_0201ED04(ws2);
    p->active[1] = 1;
    for (i = 0; i <= 1; i++)
        ov208_func_021C4B60(heap, (struct Ov208Form *)p, key, i);
}





void ov208_func_021C4D68(u16 *heap, struct Ov208Form *p, int key, int i, u32 print, u32 win,
                         u32 *active, u16 idx)
{
    u32 bmp;
    u16 width;
    u32 strA;
    u32 strB;
    int freeA;
    int freeB;
    int y;
    YPos y2;
    u16 w;

    bmp = (u32)func_02045770((struct Descriptor *)win);
    width = func_020437DC((const struct Bmp *)bmp);
    ov208_func_021C47C4((u16 *)heap, p, key, (u32 *)&strA, (u32 *)&strB, (int *)&freeA, (int *)&freeB, idx);
    y = 1;
    y2 = 0x11;
    if (strB == 0)
        y = 9;
    w = func_0201D304((struct StrObj *)strA, p->font, 0);
    func_0201C724((void *)print, bmp, (s16)((u16)((width - w) / 2)), (s16)y, strA, p->font, 0x3c40);
    if (strB != 0) {
        w = func_0201D304((struct StrObj *)strB, p->font, 0);
        func_0201C724((void *)print, bmp, (s16)((u16)((width - w) / 2)), (s16)y2, strB, p->font, 0x3c40);
    }
    if (strA != 0 && freeA != 0)
        func_02045808((struct U16Vec *)strA);
    if (strB != 0 && freeB != 0)
        func_02045808((struct U16Vec *)strB);
    *active = 1;
    ov208_func_021C4B60(heap, (struct Ov208Form *)p, key, i);
}





void ov208_func_021C4E54(u16 *heap, struct Ov208Form *p, int key)
{
    p->active[3] = 0;
    func_0201C6EC((struct PrintSys *)p->print[3]);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[3])), 0);
    ov208_func_021C4D68(heap, p, key, 3, p->print[3], p->win[3], &p->active[3], p->sel);
}





void ov208_func_021C4EAC(u16 *heap, struct Ov208Form *p, int key)
{
    p->active[4] = 0;
    func_0201C6EC((struct PrintSys *)p->print[4]);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[4])), 0);
    switch (p->state) {
    case 0:
        func_02045334((struct Descriptor *)p->win[4]);
        break;
    case 4:
        if (p->count >= 2)
            ov208_func_021C4D68(heap, p, key, 4, p->print[4], p->win[4], &p->active[4], p->sel2);
        break;
    }
}





void ov208_func_021C4F30(void *unused, struct Ov208Form *p)
{
    switch (((struct Obj14663 *)p)->f6B8) {
    case 0:
        func_02041EE4(2, 0, -0x40);
        break;
    case 4:
        if (((struct Obj14663 *)p)->f548 >= 2)
            func_02041EE4(2, 0, 0);
        else
            func_02041EE4(2, 0, -0x40);
        break;
    }
}





void ov208_func_021C4F78(u16 *heap, struct Ov208Form *p, int key)
{
    p->cam = (u32)func_02014B08(4, (void *)(*heap));
    func_02016020((void *)p->cam, 0);
    func_02015BF0((void *)p->cam);
    func_02014CB8((struct Sub02014CB8Obj *)p->cam, func_0202D060());
    p->mem = func_02030734(*heap, func_02030CB0(4), 0, data_021C8E64, 0xa53);
    p->heap3d = func_02030CBC(4, p->mem);
    func_02014CEC((u8 *)p->cam, (u32)p->heap3d);
}





/*
 * Releases the file and the two allocations held in the 0x10-byte records.
 */
void func_021C4FDC(u16 *heap, struct Ov208Form *p, int key)
{
    func_02014CD4((struct Sub02014CB8Obj *)p->cam);
    func_02014BA8((u8 *)p->cam);
    func_02030DA4((int)p->heap3d);
    func_020307B0(p->mem);
}





u32 ov208_func_021C5000(void *sys, u32 species, u32 gender, u32 side, u32 form, u32 shiny,
                        u32 personality, u32 extra)
{
    Vec_021C5000 scale;
    struct Ov208MonArc arc;
    u32 obj;

    scale = data_021C8804;
    if (species == 0x147)
        func_020172AC((int)sys, extra);
    func_02017168(species, gender, side, form, shiny, (struct Stats *)(&arc), personality);
    obj = (u32)func_020159C8(sys, 0, 0, 0, (const struct Sub150 *)(&arc));
    func_02015FF0((char *)obj, 1);
    func_02015E04((void *)obj);
    func_02015CAC((void *)obj, (u32 *)(&scale));
    ov208_func_021C5090(obj);
    return obj;
}





/*
 * BLOCKED.  MATCH: the call at +0x08 targets 02015EA0, an ARM address with no label and no pool witness outside the compared range, so the site stays wildcarded.
 */
void func_021C5078(int a, int b)
{
    func_02015EA0((void *)b);
    func_02015BA4((void *)a, (void *)b);
}





void ov208_func_021C5090(u32 obj)
{
    Vec_021C5090 v;
    float y;

    y = 0.25f * -(float)func_02015F14((void *)obj);
    v.x = FX_F32_TO_FX32(y);
    v.y = 0;
    v.z = 0;
    func_02015C78((void *)obj, (u32 *)(&v));
}





void ov208_func_021C50F8(u32 obj, Vec_021C50F8 *out)
{
    Vec_021C50F8 v;

    func_02015C30((void *)obj, (u32 *)(&v));
    out->x = v.x + data_021C8E40.ofs.x;
    out->y = v.y + data_021C8E40.ofs.y;
    out->z = v.z + data_021C8E40.ofs.z;
}




void ov208_func_021C5128(struct Ov208Mdl *m, u32 heap, void *sys, u32 species, u32 a4, u32 a5,
                         u32 a6, u32 a7, u32 a8, u32 a9)
{
    m->obj = ov208_func_021C5000(sys, species, a4, a5, a6, a7, a8, a9);
    m->turn = func_02030734(heap, 0x10, 1, data_021C8E64, 0xab1);
    func_02063000((int)func_02015EE8((void *)m->obj), 1, (int)m->turn, (int)ov208_func_021C5248);
    ov208_func_021C7F6C(m->pos, species, a4, a5, a6, a7, a8, a9);
}




void func_021C51A0(struct Ov208Anm_021C5214 *p, int a)
{
    if (((struct Obj04897 *)p)->f0 != 0)
        func_021C5078(a, ((struct Obj04897 *)p)->f0);
    ((struct Obj04897 *)p)->f0 = 0;
    if (((struct Obj04897 *)p)->f4 != 0)
        func_020307B0((void *)(((struct Obj04897 *)p)->f4));
    ((struct Obj04897 *)p)->f4 = 0;
}




void func_021C51C8(S_021C4E54 *p, int a, int b)
{
    p->w0 = a;
    p->w4 = b;
    p->b8 = 0;
    p->wc = 0;
}



void func_021C51D4(struct Ov208Slot *s)
{
    if (s->obj != 0 && s->anm != 0) {
        void *r = func_02015EE8(s->obj);
        s->anm->f8 = 0;
        s->anm->fc = 0;
        func_02064CBC(r);
        func_02015E4C(s->obj);
    }
}



void func_021C5200(int *p)
{
    if (p[0] == 0)
        return;
    if (p[1] == 0)
        return;
    *(int *)(p[1] + 0xc) = 1;
}




void ov208_func_021C5214(struct Ov208Anm_021C5214 *p)
{
    void *anm;

    if (p->obj != 0 && p->state != 0) {
        anm = func_02015EE8((void *)p->obj);
        if (p->state->active != 0) {
            func_02015E04((void *)p->obj);
            func_02064CBC(anm);
            p->state->active = 0;
        }
    }
}




void ov208_func_021C5248(struct Ov208Turn *t)
{
    u8 *scene = t->scene;

    t->count++;
    if (t->count >= 2)
        t->done = 1;
    func_02016380((void *)(*(u32 *)(scene + t->side * 0x44 + 0xc)));
}



void func_021C526C(u16 *heap,struct Ov208Form *p,int key)
{
    if(*(int *)&((struct Obj00147 *)p)->f124) {
        func_02015EA0(((struct Obj00147 *)p)->fC);
        if(((struct Obj00147 *)p)->f94)func_02015EA0(((struct Obj00147 *)p)->f94);
        *(int *)&((struct Obj00147 *)p)->f124=0;
    } else {
        func_02015EA0(((struct Obj00147 *)p)->f50);
        if(((struct Obj00147 *)p)->fD8)func_02015EA0(((struct Obj00147 *)p)->fD8);
        *(int *)&((struct Obj00147 *)p)->f124=1;
    }
    func_021C595C(heap,p,key);
    if(*(int *)&((struct Obj00147 *)p)->f124) {
        func_02015EB0(((struct Obj00147 *)p)->fC);
        if(((struct Obj00147 *)p)->f94)func_02015EB0(((struct Obj00147 *)p)->f94);
    } else {
        func_02015EB0(((struct Obj00147 *)p)->f50);
        if(((struct Obj00147 *)p)->fD8)func_02015EB0(((struct Obj00147 *)p)->fD8);
    }
}




void ov208_func_021C52F0(u16 *heap, struct Ov208Form *p, int key)
{
    p->arc = func_020490F4(7, *heap);
    p->j = func_0204ACEC(p->arc, func_0201BC3C(), 1, 0, *heap);
    p->k = func_0204AF28(p->arc, func_0201BC78(), func_0201BCEC(), *heap);
}




/*
 * Calls 0x0204AFD8 on +0x138, 0x0204ADA4 on +0x134 and 0x02049238 on +0x128 of the second argument.
 */
void func_021C533C(void *a, char *q)
{
    func_0204AFD8(((struct Obj09213 *)q)->f138);
    func_0204ADA4(((struct Obj09213 *)q)->f134);
    func_02049238(((struct Obj09213 *)q)->f128);
}




u32 ov208_func_021C535C(u32 arc, u32 *res, u32 j, u32 k, u32 owner, u16 heap, u32 species,
                        u32 form, u32 gender, u32 isEgg)
{
    Ov208ObjPos pos;
    u32 obj;

    pos.x = 0x80;
    pos.y = 0x80;
    pos.z = 1;
    pos.b6 = 1;
    pos.b7 = 0;
    *res = func_0204A6C8((void *)arc, func_0201BABC(species, form, gender, isEgg), 0, 1, heap);
    obj = (u32)func_0204B294((void *)owner, *res, j, k, &pos, 1, heap);
    func_0204B92C((struct Obj *)obj, 0);
    func_0204B6F4((struct Obj *)obj, func_0201BB5C(species, form, gender, isEgg), 0);
    func_0204B688((struct Actor *)obj, 0);
    return obj;
}




/*
 * Forwards its second argument to func_0204B3B4 and then the first to
 * func_0204A8D4.
 */
void func_021C53E0(int a, int b)
{
    func_0204B3B4((struct Obj *)b);
    func_0204A8D4(a);
}
