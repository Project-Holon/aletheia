/*
 * file:     zukan_detail_graphic_p07.c
 * unit:     yes
 * function: func_021C1E10, func_021C1F28, func_021C1F44, func_021C1F50, func_021C1FC4, func_021C1FE0, func_021C2090, func_021C20C0, func_021C21D0, func_021C2228, func_021C2234, func_021C2238, func_021C2304, func_021C231C, func_021C232C, func_021C239C, ov208_func_021C23BC, func_021C2430, func_021C2458, func_021C24A4, func_021C24F0, func_021C252C, func_021C255C, func_021C2560, func_021C2644, func_021C270C, func_021C2A70, func_021C2BA8, func_021C2BE0, func_021C2BF4, func_021C2C1C, func_021C2C44, func_021C2D88, func_021C2DE0, func_021C2E6C, func_021C2FEC, func_021C301C
 * address:  0x021C1E10
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
 *   func_021BC3B4  0x021BC3B4  thumb  ov208
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B8C4  0x0204B8C4  arm
 *   func_021BDC48  0x021BDC48  thumb  ov208
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021C0CCC  0x021C0CCC  thumb  ov208
 *   func_021C1D30  0x021C1D30  thumb  ov208
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201D304  0x0201D304  thumb
 *   func_020437DC  0x020437DC  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_021C0740  0x021C0740  thumb  ov208
 *   func_021C1920 0x021C1920  thumb  ov208
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_02045334 0x02045334 arm
 *   func_021C0C8C 0x021C0C8C thumb ov208
 *   sub_0201D304  0x0201D304  thumb
 *   sub_0201C724  0x0201C724  thumb
 *   func_021C0CC0  0x021C0CC0  thumb  ov208
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   data_021C8E14  0x021C8E14  data
 *   data_021C8E1A  0x021C8E1A  data
 *   func_0207D63C 0x0207D63C  arm
 *   func_021BC518 0x021BC518  thumb  ov208
 *   FX_SinCosTable_  0x020A1B38  data
 *   func_0204B688  0x0204B688  arm
 *   ov208_func_021BC518  0x021BC518  thumb  ov208
 *   func_021BC32C  0x021BC32C  thumb  ov208
 *   func_02082BCC  0x02082BCC  arm
 *   func_021BC3A8  0x021BC3A8  thumb  ov208
 *   func_021BC3AC  0x021BC3AC  thumb  ov208
 *   func_021BC3B0  0x021BC3B0  thumb  ov208
 *   ov208_func_021BCF4C  0x021BCF4C  thumb  ov208
 *   func_020056A0  0x020056A0  thumb
 *   func_021BC448  0x021BC448  thumb  ov208
 *   func_021BC508  0x021BC508  thumb  ov208
 *   func_021BC610  0x021BC610  thumb  ov208
 *   func_02006650  0x02006650  thumb
 *   func_020065D8  0x020065D8  thumb
 *   func_021C3638  0x021C3638  thumb  ov208
 *   func_021BC97C  0x021BC97C  thumb  ov208
 *   func_021BCA54  0x021BCA54  thumb  ov208
 *   func_021C32FC  0x021C32FC  thumb  ov208
 *   func_021C3268  0x021C3268  thumb  ov208
 *   func_021C337C  0x021C337C  thumb  ov208
 *   func_021C3374  0x021C3374  thumb  ov208
 *   func_021BC61C  0x021BC61C  thumb  ov208
 *   func_021BC464  0x021BC464  thumb  ov208
 *   func_02030EAC  0x02030EAC  arm
 *   func_021BC34C  0x021BC34C  thumb  ov208
 *   func_021BC3B8 0x021BC3B8 thumb ov208
 *   func_021BC3BC 0x021BC3BC thumb ov208
 *   func_021BC3A4 0x021BC3A4 thumb ov208
 *   func_021C3218 0x021C3218 thumb ov208
 *   func_021C3280 0x021C3280 thumb ov208
 *   func_021C3354 0x021C3354 thumb ov208
 *   func_021C3378 0x021C3378 thumb ov208
 *   func_021BC9BC 0x021BC9BC thumb ov208
 *   func_021BC844 0x021BC844 thumb ov208
 *   func_021C35DC 0x021C35DC thumb ov208
 *   func_021BC758 0x021BC758 thumb ov208
 *   func_021BC718 0x021BC718 thumb ov208
 *   func_021BC4F4 0x021BC4F4 thumb ov208
 *   func_021C3AA8 0x021C3AA8 thumb ov208
 *   func_021BC6D8 0x021BC6D8 thumb ov208
 *   func_021BDAD0 0x021BDAD0 thumb ov208
 *   func_021BDAAC 0x021BDAAC thumb ov208
 *   func_021BDAD4 0x021BDAD4 thumb ov208
 *   func_021BDBB8 0x021BDBB8 thumb ov208
 *   func_021BDC14 0x021BDC14 thumb ov208
 *   func_021BE840 0x021BE840 thumb ov208
 *   func_021BE82C 0x021BE82C thumb ov208
 *   func_021BE844 0x021BE844 thumb ov208
 *   func_021BC6C8 0x021BC6C8 thumb ov208
 *   func_021BDBA0 0x021BDBA0 thumb ov208
 *   func_021BC6F8 0x021BC6F8 thumb ov208
 *   func_021BE854 0x021BE854 thumb ov208
 *   func_021BDAE8 0x021BDAE8 thumb ov208
 *   func_021C3514 0x021C3514 thumb ov208
 *   func_021C3B14 0x021C3B14 thumb ov208
 *   func_021C3380 0x021C3380 thumb ov208
 *   func_021C3650 0x021C3650 thumb ov208
 *   func_021C301C 0x021C301C thumb ov208
 *   func_021C3318 0x021C3318 thumb ov208
 *   func_021BC99C 0x021BC99C thumb ov208
 *   func_021BC46C 0x021BC46C thumb ov208
 *   func_021BC678 0x021BC678 thumb ov208
 *   func_02040618 0x02040618 arm
 *   func_020414AC 0x020414AC arm
 *   func_0204047C 0x0204047C arm
 *   func_02012BF8 0x02012BF8 thumb
 *   func_021BC3C0  0x021BC3C0  thumb  ov208
 *   func_021BC3CC  0x021BC3CC  thumb  ov208
 *   func_021BC40C  0x021BC40C  thumb  ov208
 *   func_021C34A4  0x021C34A4  thumb  ov208
 *   func_021BDC2C  0x021BDC2C  thumb  ov208
 *   func_02012BE0  0x02012BE0  thumb
 *   func_020409B4  0x020409B4  arm
 *   func_021BC6BC  0x021BC6BC  thumb
 *   func_02005E30  0x02005E30  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   data_021C8704  0x021C8704  data
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B908 0x0204B908 arm
 *   data_021C86EC 0x021C86EC data ov208 a1
 *   func_021BC738 0x021BC738 thumb ov208
 *   func_0204B324 0x0204B324 arm
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_0202D81C 0x0202D81C thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 *   func_0202D060 0x0202D060 thumb
 *   func_0202D0D4 0x0202D0D4 thumb
 *   func_0204B454 0x0204B454 arm
 *   func_0204B5C0 0x0204B5C0 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B5AC 0x0204B5AC arm
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _fmul 0x0209C77C arm
 *   _ffix 0x0209C494 arm
 *   _fgr 0x0209BBB0 arm
 *   _fleq 0x0209BC0C arm
 *   _fgeq 0x0209BB54 arm
 */
#include "../../matched/include/Obj00081.h"
#include "../../matched/include/Obj18287.h"
#include "../../matched/include/Obj18288.h"
#include "../../matched/include/Obj14657.h"
#include "../../matched/include/Obj10905.h"
#include "../../matched/include/Obj03934.h"
#include "../../matched/include/Obj08403.h"
#include "../../matched/include/Obj25506.h"
#include "../../matched/include/Obj00146.h"
#include "../../matched/include/Obj05541.h"
#include "../../matched/include/Obj10906.h"

#define REG32(a) (*(volatile u32 *)(a))
#define REG16(a) (*(volatile u16 *)(a))
#define H(o) (*(u16 *)(p + (o)))
struct Obj;
struct PrintSys;
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct Bmp;
struct StrObj;
struct U16Vec;
struct Ov208Scene;
struct Actor;
struct Ov208Buf;
struct S_021C23BC;
struct Node;
struct Ov208Win;
struct Ov208PalFade;
struct Ov208Fade;
struct Ov208Icon;
struct Ov208Blend;
struct Key;
struct Ov208Cur;
struct Blk37;
struct Ov208Gfx;
struct PtS;
struct Vec2;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u8 f0;
    u8 f1;
    u8 rest[0x3c];
} Entry_021C1E10;

typedef short          s16_021C1E10;

typedef signed short   s16_021C2090;

typedef signed int     s32_021C2090;

typedef signed short   s16_021C20C0;

typedef signed int     s32_021C20C0;

typedef short          s16_021C2228;

typedef int            s32_021C2228;

typedef int            s32_021C1E10;

typedef struct {
    u8 f0;
    u8 f1;
    u8 b[0x3c];
} Entry_021C2234;

typedef int BOOL;

typedef signed short   s16_021C2430;

typedef signed int     s32_021C2430;

typedef enum { ONE = 1 } One;

typedef int            s32_021C2458;

typedef signed short   s16_021C23BC;

typedef signed int     s32_021C2560;

struct S_021C23BC {
    u32 f0;
    u32 f4;
    u32 f8;
    u8 pad0c[0x10];
    u32 f1c;
    u8 pad20[0x34];
    u32 a54[2];
    u32 f5c;
    u8 pad60[8];
    u32 f68;
    u8 pad6c[8];
    u16 f74;
    u16 f76;
    u8 pad78[0x40];
    u32 fb8;
    u32 fbc;
    u32 fc0;
    u32 fc4;
    u32 fc8;
    u32 fcc;
    u32 fd0;
};

typedef signed int     s32_021C23BC;

struct S_021C2A70 {
    u8 pad0[0xcc];
    u32 fcc;
    u32 fd0;
};

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} ObjPos;

struct S_021C2C44 {
    u32 f0;
    u8 pad4[0x80];
    int a84[6];
    u32 a9c[7];
};

struct Indices { u8 v[4]; };

struct Tail {u32 s0,s1,s2,s3,s4;u16 key,pad;};

struct Args {u32 w0,w1,w2,w3;u16 key,pad;};

struct Desc {u16 x,y,z;u8 a,b;u16 c,d;u32 sx,sy;u16 e,f;};

struct S_021C2FEC {
    u8 pad[0x3c];
    u32 a3c[2];
    u32 a44[2];
    u32 a4c[2];
    u32 a54[2];
};

struct Pos { s16_021C23BC x; s16_021C23BC y; };

struct Pair { int x; int y; };

extern int func_021BC3B4(int *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0204B878(u32 obj, u32 anim);
extern void func_0204B92C(struct Obj *obj, u32 v);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_021BDC48(struct Ov208Scene *s, u32 on);
extern void func_0204B3DC(struct Obj *obj, unsigned int on);
extern void func_021C0CCC(u16 *heap, u8 *p, int key);
extern void func_021C1D30(u16 *heap, u8 *p, int key);
extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern u32 func_020307B0(void *p);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_021C0740(u16 *heap, u8 *p, int key, u8 i);
extern void func_021C1920(u16 *heap, u8 *p, int key, int mode);
extern unsigned func_0204B3F4(struct Obj *);
extern void func_02045334(struct Descriptor *);
extern void func_021C0C8C(u16 *, u8 *, int, int);
extern u32 sub_0201D304(struct StrObj *s, u32 a, u32 b);
extern void sub_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern int func_021C0CC0(void *a0, u8 *st, void *a2);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);
extern void func_0207D63C(volatile void *, int, int, int, int);
extern void func_021BC518(int *p);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void ov208_func_021BC518(u32 blend);
extern void *func_021BC32C(struct Ov208Buf *p, u32 size, u32 heap);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern int func_021BC3A8(int *p);
extern int func_021BC3AC(int *p);
extern int func_021BC3B0(int *p);
extern u32 ov208_func_021BCF4C(int v);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern void *func_021BC448(u32 heap);
extern void func_021BC508(int flag, int *p);
extern void *func_021BC610(u32 heap);
extern int func_02006650(void);
extern void func_020065D8(void);
extern void func_021C3638(void *unused, char *p, void *a2);
extern void func_021BC97C(char *p);
extern void func_021BCA54(u32 a, u32 packed);
extern void func_021C32FC(u16 *heap, u8 *p, int key);
extern void func_021C3268(void *unused, char *p, void *a2);
extern void func_021C337C(void *a0, void *st, void *a2);
extern void func_021C3374(void *a0, void *st, void *a2);
extern void func_021BC61C(char *p);
extern void func_021BC464(void *a0);
extern void func_02030EAC(struct Node *n);
extern void func_021BC34C(char *p);
extern int func_021BC3B8(char *p);
extern u16 func_021BC3BC(char *);
extern int func_021BC3A4(int *p);
extern void func_02040618(u32,u32,u32);
extern void func_020414AC(u8);
extern void func_0204047C(int,u16);
extern int func_02012BF8(int,int);
extern void func_021C3218(u16 *,u8 *,int);
extern void func_021C3280(u16 *,u8 *,struct Key *);
extern void func_021C3354(unsigned short *p, void *a1, int a2);
extern void func_021C3378(void *a0, void *a1, int a2, int a3, int a4);
extern u32 func_021BC9BC(int,u16,u8,u8,u8,u8,u32,u32,u32,u32,u32);
extern struct Ov208Win *func_021BC844(u16,u32,u8,u8,u8);
extern void func_021C35DC(u16 *,u8 *,int);
extern void func_021BC758(struct Ov208PalFade *);
extern void func_021BC718(char *p);
extern void func_021BC4F4(int flag, int *p);
extern void func_021C3AA8(void *,u8 *,int);
extern void func_021BC6D8(char *p);
extern int func_021BDAD0(struct Ov208Fade *);
extern void func_021BDAAC(struct Ov208Scene *,u32,u32,u32);
extern void func_021BDAD4(struct Ov208Fade *,int);
extern void func_021BDBB8(struct Ov208Scene *,u32);
extern void func_021BDC14(char *p, int b);
extern int func_021BE840(struct Ov208Icon *);
extern void func_021BE82C(struct Ov208Icon *,int);
extern void func_021BE844(struct Ov208Icon *);
extern int func_021BC6C8(char *p);
extern void func_021BDBA0(struct Ov208Scene *);
extern void func_021BC6F8(char *p);
extern void func_021BE854(struct Ov208Icon *);
extern void func_021BDAE8(char *p, int v);
extern void func_021C3514(u16 *,u8 *,int);
extern void func_021C3B14(void *,u8 *,int);
extern void func_021C3380(u16 *,u8 *,int);
extern void func_021C3650(u16 *,u8 *,int);
extern void func_021C301C(u16 *,u8 *,int);
extern void func_021C3318(u16 *,u8 *,int);
extern void func_021BC99C(char *p);
extern void func_021BC46C(struct Ov208Blend *,struct Ov208Blend *);
extern void func_021BC678(char *p);
extern u16 func_021BC3C0(void *p);
extern void func_021BC3CC(char *p);
extern void func_021BC40C(struct Ov208Cur *p);
extern void func_021C34A4(u16 *heap, u8 *p, int key);
extern int func_021BDC2C(char *p);
extern void func_02012BE0(void *p, u32 a, u32 b);
extern void func_020409B4(u32 index);
extern void func_021BC6BC(char *p);
extern void func_02005E30(u32 v);
extern int func_02005E9C(void);
extern void func_02005DE4(void *p);
extern void func_02005DF8(u32 a);
extern int func_02005E50(void);
extern int func_02005E64(void);
extern void *func_020490F4(u32 id, u32 heap);
extern s32_021C23BC func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32_021C23BC func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32_021C23BC func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(int a);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204B908(int a0, int a1);
extern void *func_0200CA1C(void *a);
extern void func_0200CC40(void *,u32,u32 *,u32 *,u32 *,u16);
extern u32 func_0200D288(struct Blk37 *p, u32 which);
extern int func_0202D7C8(int a0);
extern u32 func_0202D81C(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern int func_0202D7D8(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned short a8, unsigned short a9);
extern u32 func_0202D898(u32,u32,u32,u32,u32,u32,u32,u32,u16);
extern int func_0202D060(void);
extern s32_021C23BC func_0202D0D4(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern void func_021BC738(struct Ov208Gfx *p, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f, u16 g);
extern struct Obj *func_0204B324(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B5C0(const struct Obj *o, struct Pair *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B5AC(struct Obj *dst, struct Pair *src);
void func_021C1E10(u16 *heap, u8 *p, int key, int dir, int touch);
void *func_021C1F28(int a, int b, int c);
void func_021C1F44(int a);
void func_021C1F50(u16 *heap, u8 *p, int key);
void func_021C1FC4(void *a, char *b, int c);
void func_021C1FE0(u16 *heap, u8 *p, int key);
void func_021C2090(void *unused, u8 *p);
void func_021C20C0(void *a0, u8 *st, void *a2);
void func_021C21D0(void *unused, char *p, int key);
void ov208_func_021C2228(u16 *heap, u8 *p, int key);
void ov208_func_021C2234(u16 *heap, u8 *p, int key);
void func_021C2238(u16 *heap, u8 *p, int key);
void func_021C2304(char *a0);
void func_021C231C(char *p);
void func_021C232C(char *p);
void func_021C239C(char *p);
void ov208_func_021C23BC(u8 *p);
void func_021C2430(u8 *p);
void ov208_func_021C2458(u16 *heap, u8 *p, int key);
void ov208_func_021C24A4(u16 *heap, u8 *p, int key);
void ov208_func_021C24F0(u16 *heap, u8 *p, int key);
void ov208_func_021C252C(u16 *heap, u8 *p, int key);
void func_021C255C(u16 *dst, u16 value);
u32 func_021C2560(void *a0, u32 a1, u16 *desc, u32 a3, int *obj);
u32 func_021C2644(void *a0, u32 a1, void *a2, u8 *st, void *a4);
int func_021C270C(void *unused,int *seq,u16 *heap,u8 *p,int key);
void func_021C2A70(void *a0, void *a1, void *heap, struct S_021C2A70 *st, int *obj, int key);
void func_021C2BA8(void *unused, u8 *p);
void func_021C2BE0(void *unused, u8 *p, void *a2);
void func_021C2BF4(void *unused, char *p, void *a2);
void func_021C2C1C(int unused, char *p, int a2);
void func_021C2C44(u16 *heap, struct S_021C2C44 *st, int a2);
void func_021C2D88(void *unused, u8 *p, void *a2);
void func_021C2DE0(void *unused,u8 *p,void *unused2,int first,u16 second);
void func_021C2E6C(u16 *heap,u8 *p,int key,u32 slot);
void func_021C2FEC(void *unused, struct S_021C2FEC *p, u32 unused2, u32 i);
void ov208_func_021C301C(u16 *heap, u8 *p, int key);
extern const u8 data_021C8E14[3][2];
extern u8 data_021C8E1A[3][4];
extern s16_021C23BC FX_SinCosTable_[];
extern const u8 data_021C8704[7][9];
extern const struct Indices data_021C86EC;


#define W(o) (*(u32 *)(p + (o)))

#define OBJ(i) (((u32 *)(p + 0xbc))[i])






void func_021C1E10(u16 *heap, u8 *p, int key, int dir, int touch)
{
    void *s;
    int other;
    u32 anim;

    s = (void *)func_021BC3B4((int *)key);
    if (W(0x8c) == 0)
        W(0x90) = ((Entry_021C1E10 *)W(0x94))[0].f1 == 0;
    else
        W(0x90) = ((Entry_021C1E10 *)W(0x94))[p[0x78]].f1 == 0;
    W(0x2c) = 0;
    func_0201C6EC((struct PrintSys *)W(0x3c));
    func_02043B5C(func_02045770((struct Descriptor *)W(0x1c)), 0);
    func_021C1F50(heap, p, key);
    if (dir) {
        p[0xd8] = 2;
        anim = 3;
        other = 1;
    } else {
        p[0xd8] = 1;
        anim = 5;
        other = 2;
    }
    func_0204B878(OBJ(p[0xd8]), anim);
    func_0204B92C((struct Obj *)OBJ(other), 0);
    func_0204B8C4((struct Obj *)OBJ(other), 0);
    func_021BDC48((struct Ov208Scene *)s, 0);
    if (touch == 1) {
        func_0204B3DC((struct Obj *)W(0xcc), 0);
    } else if (W(0x6c) == 5 && W(0x90) == 1) {
        func_021C0CCC(heap, p, key);
        func_021C1D30(heap, p, key);
    }
    func_021C1FC4(heap, (char *)p, key);
    func_021C2238(heap, p, key);
}







/*
 * Forwards to func_0204A39C with the first argument less one and an out slot.
 */
void *func_021C1F28(int a, int b, int c)
{
    int out;

    return func_0204A39C((void *)c, a - 1, 0, b, (u32 *)(&out));
}







void func_021C1F44(int a)
{
    if (a != 0)
        func_020307B0((void *)a);
}






void func_021C1F50(u16 *heap, u8 *p, int key)
{
    void *str;
    u16 tw;
    u32 w;

    str = func_02045EC0((struct MsgBank *)W(0xc), p[0x78] + 0xbe);
    tw = func_0201D304(str, W(4), 0);
    w = func_020437DC(func_02045770((struct Descriptor *)W(0x1c)));
    func_0201C724((void *)W(0x3c), (u32)func_02045770((struct Descriptor *)W(0x1c)), (s16_021C1E10)((u16)((int)(w - tw) / 2)), (s16_021C1E10)1, (u32)str, W(4), 0x3c40);
    func_02045808(str);
    W(0x2c) = 1;
    func_021C0740(heap, p, key, 2);
}






/*
 * Dispatches on the word at +0x6C: state 0 hands a 3, state 5 hands an 8 to func_021C1920.
 */
void func_021C1FC4(void *a, char *b, int c)
{
    int s = ((struct Obj00081 *)b)->f6C;

    if (s == 0) {
        func_021C1920(a, (u8 *)b, c, 3);
        return;
    }
    if (s == 5) {
        func_021C1920(a, (u8 *)b, c, 8);
    }
}





void func_021C1FE0(u16 *heap, u8 *p, int key)
{
    u8 i;
    if (func_0204B3F4(*(struct Obj * *)&((struct Obj00081 *)p)->fC8)) {
        if (((struct Obj00081 *)p)->f90 == 1) {
            ((struct Obj00081 *)p)->f30 = 0;
            func_0201C6EC(*(struct PrintSys * *)&((struct Obj00081 *)p)->f40);
            func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20), 0);
            func_02045334(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fC8, 0);
        }
    } else {
        for (i = 0; i < 61; i++) func_0204B3DC(*(struct Obj **)(p + i * 4 + 0xdc), 0);
        if (((struct Obj00081 *)p)->f90 == 0) {
            func_021C0C8C(heap, p, key, 0);
            p[0x79] = 255;
            func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fCC, 0);
            func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fD0, 0);
            func_021C1D30(heap, p, key);
            func_021C2238(heap, p, key);
        }
    }
}





void func_021C2090(void *unused, u8 *p)
{
    if (func_0204B3F4((struct Obj *)(*(int *)&((struct Obj00081 *)p)->fC8)) == 0) {
        if (*(int *)&((struct Obj00081 *)p)->f90 == 0) {
            p[0x414] = 1;
        } else {
            p[0x414] = 2;
        }
    }
}





void func_021C20C0(void *a0, u8 *st, void *a2)
{
    int res = func_0204B3F4((struct Obj *)(*(int *)&((struct Obj00081 *)st)->fC8));

    if (((struct Obj00081 *)st)->f90 == 0) {
        if (res == 0) {
            void *msg;
            u32 w;
            int d;
            int h;
            u32 t;

            msg = func_02045EC0(((struct Obj00081 *)st)->fC, 0x80);
            w = (u16)sub_0201D304(msg, ((struct Obj00081 *)st)->f4, 0);
            h = func_020437DC((const struct Bmp *)((u32)func_02045770(((struct Obj00081 *)st)->f20)));
            t = (u32)func_02045770(((struct Obj00081 *)st)->f20);
            d = h - w;
            sub_0201C724(((struct Obj00081 *)st)->f40, t, (s16_021C20C0)(u16)(d / 2), 1, (u32)msg, ((struct Obj00081 *)st)->f4, 0x3c40);
            func_02045808(msg);
            ((struct Obj00081 *)st)->f30 = 1;
            func_021C0740((u16 *)a0, st, (int)a2, 3);
            func_0204B3DC((struct Obj *)*(int *)&((struct Obj00081 *)st)->fC8, 1);
        }
    } else {
        u8 i;
        u8 v;
        u8 *tbl;

        v = ((struct Obj00081 *)st)->f8C == 0 ? 0 : st[0x78];
        for (i = 0; i < 0x3d; i++) {
            tbl = *(u8 * *)&((struct Obj00081 *)st)->f94;
            if (tbl[v * 0x3e + st[0x3cc + i] + 2] != 0 && *(u32 *)(st + 0x1e0 + i * 8) != 1) {
                func_0204B3DC((struct Obj *)*(int *)(st + 0xdc + i * 4), 1);
            }
        }
        if (func_021C0CC0(a0, st, a2) == 0) {
            func_021C0C8C((u16 *)a0, st, (int)a2, 1);
        }
    }
}




void func_021C21D0(void *unused, char *p, int key)
{
    u8 i;
    if (func_0204B3F4(*(struct Obj * *)&((struct Obj00081 *)p)->fC8)) {
        ((struct Obj00081 *)p)->f30 = 0;
        func_0201C6EC(*(struct PrintSys * *)&((struct Obj00081 *)p)->f40);
        func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20), 0);
        func_02045334(*(struct Descriptor * *)&((struct Obj00081 *)p)->f20);
        func_0204B3DC(*(struct Obj * *)&((struct Obj00081 *)p)->fC8, 0);
    } else {
        for (i = 0; i < 61; i++) func_0204B3DC(*(struct Obj **)(p + i * 4 + 0xdc), 0);
    }
}





void ov208_func_021C2228(u16 *heap, u8 *p, int key)
{
    p[0x414] = 3;
}




void ov208_func_021C2234(u16 *heap, u8 *p, int key)
{
}




/*
 * note: 2026-10-05 (D6-04): closed by declaring data_021C8E1A non-const; the
 *   image keeps the x0 table load below the stack argument stores (a plain
 *   extern cannot move past them).
 */
void func_021C2238(u16 *heap, u8 *p, int key)
{
    u8 on[3] = {0, 0, 0};
    u8 idx, k, i;

    if (W(0x90) == 1 && p[0x79] != 0xff) {
        idx = W(0x8c) != 0 ? p[0x78] : 0;
        k = (p + p[0x79])[0x3cc];
        if ((*(Entry_021C2234 **)(p + 0x94))[idx].b[k] & 7)
            on[0] = 1;
        if ((*(Entry_021C2234 **)(p + 0x94))[idx].b[k] & 0x18)
            on[1] = 1;
        if ((*(Entry_021C2234 **)(p + 0x94))[idx].b[k] & 0x60)
            on[2] = 1;
    }
    for (i = 0; i < 3; i++)
        func_020413B0(7, data_021C8E1A[i][0], data_021C8E1A[i][1], data_021C8E1A[i][2],
                      data_021C8E1A[i][3], data_021C8E14[i][on[i]]);
    func_02041B6C(7);
}




/*
 * Writes 4 on the stack and calls the SDK function at 0x0207D63C with
 * (0x04000050, 0, 0x3F, 0xC, 4).
 *
 * Promoted from MATCH by the recursive-unblocker lane: 0x0207D63C is the ARM
 * SDK symbol G2x_SetBlendAlpha_, and the `sdk` class attests the call once
 * the symbols block declares `arm`.  The old `thumb` declaration fought the
 * image's ISA and suppressed the witness.  Verified EXACT, 24 bytes.
 */
void func_021C2304(char *a0)
{
    func_0207D63C((volatile void *)0x04000050, 0, 0x3f, 0xc, 4);
}




/*
 * Loads the word at +0x418 and tail-calls func_021BC518 with it.
 */
void func_021C231C(char *p)
{
    func_021BC518((int *)(((struct Obj18287 *)p)->f418));
}



static inline void GX_SetVisibleWnd(int window)
{
    REG32(0x04000000) = (u32)((REG32(0x04000000) & ~0xe000) | (window << 13));
}



static inline void G2_SetWnd0Position(int x1, int y1, int x2, int y2)
{
    REG16(0x04000040) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000044) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}



static inline void G2_SetWnd1Position(int x1, int y1, int x2, int y2)
{
    REG16(0x04000042) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000046) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}



static inline void G2_SetWnd0InsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (REG16(0x04000048) & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    REG16(0x04000048) = (u16)tmp;
}



static inline void G2_SetWnd1InsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (REG16(0x04000048) & ~0x3f00) | ((u32)wnd << 8);
    if (effect) tmp |= 0x2000;
    REG16(0x04000048) = (u16)tmp;
}



static inline void G2_SetWndOutsidePlane(int wnd, BOOL effect)
{
    u32 tmp = (REG16(0x0400004a) & ~0x3f) | (u32)wnd;
    if (effect) tmp |= 0x20;
    REG16(0x0400004a) = (u16)tmp;
}



void func_021C232C(char *p)
{
    GX_SetVisibleWnd(3);
    G2_SetWnd0Position(0, 0, 160, 168);
    G2_SetWnd1Position(160, 0, 0, 168);
    G2_SetWnd0InsidePlane(31, 1);
    G2_SetWnd1InsidePlane(31, 1);
    G2_SetWndOutsidePlane(31, 0);
    func_021C2430((u8 *)p);
}




/*
 * Masks 0x04000000 with 0xFFFF1FFF, then tail-calls func_021BC518 on the word at +0x418.
 */
void func_021C239C(char *p)
{
    *(volatile unsigned int *)0x04000000 &= 0xffff1fff;
    func_021BC518((int *)(((struct Obj18288 *)p)->f418));
}

#undef OBJ
#define OBJ(p) (*(void **)((p) + *(int *)((p) + 0x5c) * 4 + 0x54))

#undef W




#define W(o) (*(u32 *)(p + (o)))







void ov208_func_021C23BC(u8 *p)
{
    func_0207D63C((volatile void *)0x04000050, 0, 0x3f, W(0x1d8), 16 - W(0x1d8));
    if (H(0x1dc) + 0x400u >= 0x10000)
        H(0x1dc) = H(0x1dc) - 0xfc00;
    else
        H(0x1dc) += 0x400;
    W(0x1d8) = ((s16_021C23BC)((FX_SinCosTable_[(H(0x1dc) >> 4) * 2 + 1] + 0x1000) / 2) * 14 >> 12) + 1;
}








void func_021C2430(u8 *p)
{
    One one = ONE;
    ((struct Obj14657 *)p)->f1D8 = one;
    ((struct Obj14657 *)p)->f1DC = one << 15;
    func_0207D63C((volatile void *)0x04000050, 0, 0x3f, one, 16 - one);
}








void ov208_func_021C2458(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 7; i++) {
        if (i != 3)
            func_0204B688((struct Actor *)(*(u32 *)(p + i * 4 + 0xbc)), 0);
    }
    for (i = 0; i < 0x3d; i++) {
        if (*(u32 *)(p + i * 8 + 0x1e0) == 2)
            func_0204B688((struct Actor *)(*(u32 *)(p + i * 8 + 0x1e4)), 0);
    }
}







void ov208_func_021C24A4(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 7; i++) {
        if (i != 3)
            func_0204B688((struct Actor *)(*(u32 *)(p + i * 4 + 0xbc)), 1);
    }
    for (i = 0; i < 0x3d; i++) {
        if (*(u32 *)(p + i * 8 + 0x1e0) == 2)
            func_0204B688((struct Actor *)(*(u32 *)(p + i * 8 + 0x1e4)), 1);
    }
}







void ov208_func_021C24F0(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (((u32 *)(p + 0x5c))[i] != 0)
            func_0204B688((struct Actor *)(((u32 *)(p + 0x5c))[i]), 0);
    }
    func_0207D63C((volatile void *)0x04001050, 8, 0x3f, 12, 4);
}







void ov208_func_021C252C(u16 *heap, u8 *p, int key)
{
    u8 i;

    for (i = 0; i < 2; i++) {
        if (((u32 *)(p + 0x5c))[i] != 0)
            func_0204B688((struct Actor *)(((u32 *)(p + 0x5c))[i]), 1);
    }
    ov208_func_021BC518(((struct Obj10905 *)p)->f41C);
}







void func_021C255C(u16 *dst, u16 value)
{
    *dst = value;
}




#undef W



#undef W


#undef W

#undef W

#define W(o) (*(u32 *)(p+(o)))






u32 func_021C2560(void *a0, u32 a1, u16 *desc, u32 a3, int *obj)
{
    struct S_021C23BC *st;
    u8 i;

    st = func_021BC32C(a0, 0xd4, *desc);
    func_02082BCC(st, 0, 0xd4);
    i = 0;
    st->f0 = ov208_func_021BCF4C(func_021BC3A8(obj));
    st->f4 = func_021BC3AC(obj);
    st->f8 = func_021BC3B0(obj);
    st->f1c = 0;
    st->f68 = 0;
    st->f74 = 0;
    st->f76 = 1;
    st->fb8 = 0;
    func_021C2BE0(desc, (u8 *)st, obj);
    st->fbc = (u32)func_020056A0((unsigned)func_021C2BA8, (unsigned)st, 1);
    st->fc0 = (u32)func_021BC448(*desc);
    st->fc4 = (u32)func_021BC448(*desc);
    func_021BC518((int *)st->fc0);
    func_021BC518((int *)st->fc4);
    func_021BC508(0, (int *)st->fc0);
    func_021BC508(1, (int *)st->fc4);
    st->fc8 = (u32)func_021BC610(*desc);
    st->fcc = 0;
    st->fd0 = 1;
    for (i = 0; i < 2; i++) {
        st->a54[i] = 0;
    }
    st->f5c = 0;
    return 1;
}






u32 func_021C2644(void *a0, u32 a1, void *a2, u8 *st, void *a4)
{
    u8 i;

    if (func_02006650() != 0) {
        func_020065D8();
    }
    func_021C3638(a2, (char *)st, a4);
    func_021BC97C(*(char * *)&((struct Obj03934 *)st)->f80);
    func_021BC97C(*(char * *)&((struct Obj03934 *)st)->f7C);
    func_021BCA54(2, ((struct Obj03934 *)st)->f78);
    for (i = 0; i < 2; i++) {
        func_021C2FEC(a2, (struct S_021C2FEC *)((struct S_021C23BC *)st), (u32)a4, i);
    }
    func_021C32FC(a2, st, (int)a4);
    func_021C3268(a2, (char *)st, a4);
    func_021C337C(a2, st, a4);
    func_021C3374(a2, st, a4);
    func_021C2D88(a2, st, a4);
    func_021BC61C(*(char * *)&((struct Obj03934 *)st)->fC8);
    func_021BC464(*(char * *)&((struct Obj03934 *)st)->fC4);
    func_021BC464(*(char * *)&((struct Obj03934 *)st)->fC0);
    if (((struct Obj03934 *)st)->fB8 != 3) {
        func_021C2BF4(a2, (char *)st, a4);
    }
    func_02030EAC(((struct Obj03934 *)st)->fBC);
    func_021BC34C((char *)a0);
    return 1;
}





/* Explicit caller r2 loads preserve trailing arguments on setup/update helpers. */
int func_021C270C(void *unused,int *seq,u16 *heap,u8 *p,int key)
{
    void *scene;
    struct Ov208Icon *icon;
    u8 i;
    int ready;
    scene=(void *)func_021BC3B4((int *)key);
    icon=(struct Ov208Icon *)func_021BC3B8((char *)key);
    switch(*seq){
    case 0:
        *seq=1;
        for(i=0;i<=7;i++){
            if(i!=1 && i!=5){
                func_02040618(i,0,0);
                func_02040618(i,3,0);
                func_020414AC(i);
            }
        }
        func_0204047C(2,1);
        func_0204047C(3,2);
        func_0204047C(0,3);
        func_0204047C(6,1);
        func_0204047C(4,3);
        func_021C2C44(heap, (struct S_021C2C44 *)((struct S_021C23BC *)p), key);
        func_021C2E6C(heap,p,key,W(0x5c));
        func_0204B688((struct Actor *)(*(u32 *)((p+W(0x5c)*4)+0x54)),1);
        func_021C3218(heap,p,key);
        func_021C3280(heap,p,(struct Key *)key);
        func_021C3354(heap,p,key);
        func_021C3378(heap,p,key,0,0);
        W(0x78)=func_021BC9BC(0,*heap,2,1,0,5,0x9f,1,0xb,0x2a,0);
        W(0x7c)=(u32)func_021BC844(*heap,2,0,2,3);
        W(0x80)=(u32)func_021BC844(*heap,2,4,1,2);
        func_021C2DE0(heap,p,(void *)key,0,0);
        func_021C35DC(heap,p,key);
        func_021BC758((struct Ov208PalFade *)W(0xc8));
        func_021BC718((char *)W(0xc8));
        break;
    case 1:
        *seq=2;
        func_021BC4F4(0,(int *)W(0xc0));
        func_021BC4F4(1,(int *)W(0xc4));
        func_021C3AA8(heap,p,key);
        break;
    case 2:
        *seq=3;
        func_021BC6D8((char *)W(0xc8));
        if(func_021BDAD0(scene)!=2){
            func_021BDAAC(scene,0,2,func_021BC3BC((char *)key)>1);
            func_021BDAD4(scene,0);
        }else func_021BDBB8(scene,2);
        func_021BDC48(scene,0);
        func_021BDC14(scene,func_02012BF8(func_021BC3A4((int *)key),0x13));
        if(func_021BE840(icon)!=2){
            func_021BE82C(icon,2);
            func_021BE844(icon);
        }
        break;
    case 3:
        if(func_021BC6C8((char *)W(0xc8))==0 && func_021BDAD0(scene)==2 && func_021BE840(icon)==2){
            func_021BDBA0(scene);
            func_021BDC48(scene,1);
            *seq=4;
        }
        break;
    case 4:
        if(W(0xcc)!=0){
            *seq=5;
            func_021BC6F8((char *)W(0xc8));
            func_021BE854(icon);
            if(W(0xcc)==2)func_021BDAE8(scene,0);
            func_021C2BF4(heap,(char *)p,(void *)key);
        }else func_021C3514(heap,p,key);
        break;
    case 5:
        ready=0;
        if(func_021BC6C8((char *)W(0xc8))==0 && func_021BE840(icon)==0){
            if(W(0xcc)==2){
                if(func_021BDAD0(scene)==0)ready=1;
            }else ready=1;
        }
        if(ready)*seq=6;
        break;
    case 6:
        *seq=7;
        func_021C3B14(heap,p,key);
        func_021BC508(0,(int *)W(0xc0));
        func_021BC508(1,(int *)W(0xc4));
        break;
    case 7:
        return 1;
    }
    if(*seq>=3){
        func_021C3380(heap,p,key);
        func_021C3650(heap,p,key);
        func_021C301C(heap,p,key);
    }
    if(*seq>=2){
        func_021C3318(heap,p,key);
        func_021BC99C((char *)W(0x7c));
        func_021BC99C((char *)W(0x80));
    }
    func_021BC46C((struct Ov208Blend *)W(0xc0),(struct Ov208Blend *)W(0xc4));
    func_021BC678((char *)W(0xc8));
    func_021C2C1C((int)heap,(char *)p,key);
    return 0;
}





void func_021C2A70(void *a0, void *a1, void *heap, struct S_021C2A70 *st, int *obj, int key)
{
    int sc;
    u32 flag;

    if (st == 0) {
        return;
    }
    sc = func_021BC3B4(obj);
    flag = 0;
    switch (key) {
    case 17:
        break;
    case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 18:
        st->fd0 = flag;
        break;
    }
    switch (key) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 9:
        flag = 1;
        st->fd0 = flag;
        break;
    }
    switch (key) {
    case 12: {
        u16 old = func_021BC3C0(obj);
        func_021BC3CC((char *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021C34A4(heap, (u8 *)st, (int)obj);
        }
        break;
    }
    case 13: {
        u16 old = func_021BC3C0(obj);
        func_021BC40C((struct Ov208Cur *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021C34A4(heap, (u8 *)st, (int)obj);
        }
        break;
    }
    }
    switch (key) {
    case 0:
        break;
    case 1: case 2:
        st->fcc = 2;
        return;
    case 6: case 7: case 9:
        st->fcc = 1;
        return;
    case 3:
        func_021BDBA0((struct Ov208Scene *)sc);
        return;
    case 4:
        func_021BDBA0((struct Ov208Scene *)sc);
        return;
    case 5:
        func_02012BE0((void *)func_021BC3A4(obj), 0x13, func_021BDC2C((char *)sc));
        func_021BDBA0((struct Ov208Scene *)sc);
        return;
    default:
        if (flag != 0) {
            func_021BDBA0((struct Ov208Scene *)sc);
        }
        break;
    }
}





void func_021C2BA8(void *unused, u8 *p)
{
    if (((struct Obj08403 *)p)->f1C != 0) {
        func_02040618(3, 0, ((struct Obj08403 *)p)->f18 - 1);
        func_02040618(3, 3, 0);
        func_020409B4(3);
        ((struct Obj08403 *)p)->f1C = 0;
    }
    func_021BC6BC(*(char * *)&((struct Obj08403 *)p)->fC8);
}





void func_021C2BE0(void *unused, u8 *p, void *a2)
{
    func_02005E30(0x1e);
    ((struct Obj25506 *)p)->fB8 = 1;
}





/*
 * Leaves state 2 and moves the object at +0xB8 to state 3.
 */
void func_021C2BF4(void *unused, char *p, void *a2)
{
    if (((struct Obj00146 *)p)->fB8 == 2) {
        func_02005E9C();
        func_02005DE4(0);
    }
    func_02005DF8(0x3c);
    ((struct Obj00146 *)p)->fB8 = 3;
}




/*
 * Moves the object at +0xB8 from state 1 to state 2.
 */
void func_021C2C1C(int unused, char *p, int a2)
{
    if (((struct Obj00146 *)p)->fB8 == 1) {
        if (func_02005E50() == 0) {
            func_02005DE4((void *)1);
            func_02005E64();
            ((struct Obj00146 *)p)->fB8 = 2;
        }
    }
}




/*
 * note: 2026-10-05 (wave D4 lane 02): the loop back edge in the image goes to the memset call,
 *         so the memset is the first statement of the loop body. The loop-invariant &pos
 *         (add r7, sp, #0x10) is then hoisted into the preheader, before the call.
 */
void func_021C2C44(u16 *heap, struct S_021C2C44 *st, int a2)
{
    int arc;
    u8 i;
    ObjPos pos;

    arc = (int)func_020490F4(0x9f, *heap);
    i = 0;
    st->a84[1] = func_0204AC18((void *)arc, 3, 0, 0, 0, 4, *heap);
    st->a84[0] = func_0204A6C8((void *)arc, 0xd, 0, 0, *heap);
    st->a84[2] = func_0204AF28((void *)arc, 0x1b, 0x2c, *heap);
    st->a84[4] = func_0204AC18((void *)arc, 8, 1, 0x40, 0, 1, *heap);
    st->a84[3] = func_0204A6C8((void *)arc, 0x18, 0, 1, *heap);
    st->a84[5] = func_0204AF28((void *)arc, 0x1e, 0x2f, *heap);
    func_02049238(arc);
    do {
        const u8 *e;
        func_02082BCC(&pos, 0, 8);
        e = data_021C8704[i];
        pos.a = e[0];
        pos.b = e[1];
        pos.c = e[2];
        pos.d = e[3];
        pos.e = e[4];
        st->a9c[i] = (u32)func_0204B294((void *)st->f0, st->a84[e[5]], st->a84[e[6]], st->a84[e[7]], &pos, e[8], *heap);
        func_0204B3DC((struct Obj *)st->a9c[i], 1);
        func_0204B688((struct Actor *)st->a9c[i], 1);
        i++;
    } while (i < 7);
    func_0204B92C((struct Obj *)st->a9c[6], 1);
}



void func_021C2D88(void *unused, u8 *p, void *a2)
{
    u8 i;
    for (i = 0; i < 7; i++)
        func_0204B3B4(*(struct Obj **)(p + i * 4 + 0x9c));
    func_0204ADA4(((struct Obj05541 *)p)->f88);
    func_0204A8D4(((struct Obj05541 *)p)->f84);
    func_0204AFD8(((struct Obj05541 *)p)->f8C);
    func_0204ADA4(((struct Obj05541 *)p)->f94);
    func_0204A8D4(((struct Obj05541 *)p)->f90);
    func_0204AFD8(((struct Obj05541 *)p)->f98);
}



void func_021C2DE0(void *unused,u8 *p,void *unused2,int first,u16 second)
{
    struct Indices ids;
    u16 digits[4];
    u8 i;
    ids=data_021C86EC;
    digits[0]=first/10;
    if(digits[0]>9)digits[0]=9;
    digits[1]=first%10;
    digits[2]=second/10;
    if(digits[2]>9)digits[2]=9;
    digits[3]=second%10;
    for(i=0;i<4;i++)
        func_0204B908((int)(*(struct Obj **)(p+ids.v[i]*4+0x9c)),digits[i]);
}



void func_021C2E6C(u16 *heap,u8 *p,int key,u32 slot)
{
    struct Desc desc;
    u32 form,b,a;
    u32 arc,special,species;
    void *ctx;
    species=func_021BC3C0((void *)key);
    special=0;
    ctx=func_0200CA1C((void *)func_021BC3A4((int *)key));
    func_0200CC40(ctx,species,&form,&b,&a,*heap);
    if(species==327)special=func_0200D288(ctx,special);
    arc=func_0202D7C8(*heap);
    *(u32 *)((u32)p+0x44+slot*4)=func_0202D81C(arc,species,a,form,b,0,0,special,1,*heap);
    *(u32 *)((u32)p+0x3c+slot*4)=func_0202D7D8(arc,species,a,form,b,0,0,1,(u16)(slot<<5),*heap);
    *(u32 *)((u32)p+0x4c+slot*4)=func_0202D898(species,a,form,b,0,0,2,1,*heap);
    func_021BC738(((struct Obj00146 *)p)->fC8,arc,func_0202D0D4(func_0202D060(),species,a,form,b,0,0),*heap,3,32,(u16)(slot<<4),0);
    func_02049238(arc);
    func_02082BCC(&desc,0,24);
    desc.x=128;desc.y=128;desc.z=0;desc.a=0;desc.b=0;desc.c=0;desc.d=0;
    desc.sx=4096;desc.sy=4096;desc.e=0;desc.f=2;
    *(u32 *)((u32)p+0x54+slot*4)=(u32)func_0204B324(((struct Obj00146 *)p)->f0,*(u32 *)((u32)p+0x44+slot*4),*(u32 *)((u32)p+0x3c+slot*4),*(u32 *)((u32)p+0x4c+slot*4),(u32)(&desc),1,*heap);
    func_0204B688((struct Actor *)(*(u32 *)((u32)p+0x54+slot*4)),0);
    ((struct Obj00146 *)p)->f60=0;
}




void func_021C2FEC(void *unused, struct S_021C2FEC *p, u32 unused2, u32 i)
{
    if (p->a54[i] != 0) {
        func_0204B3B4((struct Obj *)p->a54[i]);
        p->a54[i] = 0;
        func_0204ADA4(p->a3c[i]);
        func_0204A8D4(p->a44[i]);
        func_0204AFD8(p->a4c[i]);
    }
}




void ov208_func_021C301C(u16 *heap, u8 *p, int key)
{
    struct Pos pos;
    struct Pair sc;
    float f;
    switch (((struct Obj10906 *)p)->f60) {
    case 0:
    case 2:
        break;
    case 1:
        func_0204B454(OBJ(p), (struct PtS *)&pos, 1);
        func_0204B5C0(OBJ(p), &sc);
        f = (float)sc.y / 4096.0f;
        f += 0.01f;
        if (f >= 1.1f) {
            f = 1.1f;
            ((struct Obj10906 *)p)->f60 = 2;
        }
        pos.y = 0x80 - (int)(96.0f * (f - 1.0f) / 2.0f);
        if (f > 0.0f)
            sc.y = (int)(4096.0f * f + 0.5f);
        else
            sc.y = (int)(4096.0f * f - 0.5f);
        func_0204B404(OBJ(p), (const struct Vec2 *)(&pos), 1);
        func_0204B5AC(OBJ(p), &sc);
        break;
    case 3:
        func_0204B454(OBJ(p), (struct PtS *)&pos, 1);
        func_0204B5C0(OBJ(p), &sc);
        f = (float)sc.y / 4096.0f - 0.01f;
        if (f <= 1.0f) {
            f = 1.0f;
            ((struct Obj10906 *)p)->f60 = 0;
            pos.y = 0x80;
        } else {
            pos.y = 0x80 - (int)(96.0f * (f - 1.0f) / 2.0f);
        }
        if (f > 0.0f)
            sc.y = (int)(4096.0f * f + 0.5f);
        else
            sc.y = (int)(4096.0f * f - 0.5f);
        func_0204B404(OBJ(p), (const struct Vec2 *)(&pos), 1);
        func_0204B5AC(OBJ(p), &sc);
        break;
    }
}
