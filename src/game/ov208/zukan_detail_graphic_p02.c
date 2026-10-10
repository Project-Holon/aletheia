/*
 * file:     zukan_detail_graphic_p02.c
 * unit:     yes
 * function: func_021BD574, func_021BD634, func_021BD74C, func_021BD764, func_021BD7E4, func_021BD7F8, func_021BD7FC, func_021BD808, func_021BD814, func_021BD844, func_021BD848, func_021BD868, func_021BD878, func_021BD880, func_021BD89C, func_021BD8C0, func_021BD954, func_021BD974, func_021BDAAC, func_021BDAD0, func_021BDAD4, func_021BDAE8, func_021BDB08, func_021BDB54, func_021BDBA0, func_021BDBAC, func_021BDBB8, func_021BDBEC, func_021BDC14, func_021BDC2C, func_021BDC48, func_021BDC80, func_021BDCA4, func_021BDCDC, func_021BDCF8, func_021BDD24, func_021BDD48, func_021BDD98, func_021BDFA8, func_021BDFDC, func_021BE128, func_021BE16C, func_021BE170, func_021BE1BC, func_021BE20C, func_021BE300, func_021BE32C, func_021BE378, func_021BE3C4, func_021BE4DC, func_021BE504, func_021BE680, func_021BE6A8, func_021BE710, func_021BE778, func_021BE7A4, func_021BE82C, func_021BE840, func_021BE844, func_021BE854, func_021BE864, func_021BE868, func_021BE8FC, func_021BE920, func_021BE9C8, func_021BE9CC, func_021BEA00, func_021BEA04, func_021BEA90, func_021BEB18, func_021BEE70, func_021BEF9C, func_021BEFA0, func_021BF088, func_021BF1D0, func_021BF280
 * address:  0x021BD574
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
 *   func_0204A380  0x0204A380  arm
 *   func_02062B30  0x02062B30  arm
 *   func_0204169C  0x0204169C  arm
 *   func_0204162C  0x0204162C  arm
 *   func_020410D0  0x020410D0  arm
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020416D4  0x020416D4  arm
 *   func_021BD56C  0x021BD56C  thumb
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   data_021C8314  0x021C8314  data
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_02035D20 0x02035D20 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020362DC 0x020362DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_02030734 0x02030734 arm
 *   func_02040618 0x02040618 arm
 *   func_0204047C 0x0204047C arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_021BDCF8 0x021BDCF8 thumb ov208
 *   func_021BD358 0x021BD358 thumb ov208
 *   func_020056A0 0x020056A0 thumb
 *   d_021C8DE4 0x021C8DE4 data a1
 *   func_02030EAC 0x02030EAC arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_02040804 0x02040804 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_021BD23C 0x021BD23C thumb
 *   d_021C8388 0x021C8388 data a4
 *   d_021C8384 0x021C8384 data a1
 *   func_021BD2E0 0x021BD2E0 thumb ov208
 *   func_021BD308 0x021BD308 thumb ov208
 *   ov208_func_021BD360  0x021BD360  thumb
 *   ov208_func_021BD330  0x021BD330  thumb
 *   func_021BE170  0x021BE170  thumb
 *   func_021BD378  0x021BD378  thumb
 *   func_021BD3A4 0x021BD3A4  thumb  ov208
 *   func_021BD3B4 0x021BD3B4  thumb  ov208
 *   func_021BD35C  0x021BD35C  thumb
 *   func_021BDD98  0x021BDD98  thumb
 *   func_021BE3C4  0x021BE3C4  thumb
 *   func_021BE504  0x021BE504  thumb
 *   func_0204B53C 0x0204B53C arm
 *   func_0204B528 0x0204B528 arm
 *   func_020490F4  0x020490F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_021BD148  0x021BD148  thumb
 *   func_021BD3C0  0x021BD3C0  thumb
 *   func_021BD3CC  0x021BD3CC  thumb
 *   func_021BD368  0x021BD368  thumb
 *   func_021BE128  0x021BE128  thumb
 *   data_021C8440  0x021C8440  data
 *   data_021C83A4  0x021C83A4  data
 *   func_021BE1BC 0x021BE1BC thumb
 *   func_021BD208 0x021BD208 thumb
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0203633C 0x0203633C arm
 *   func_021BD388 0x021BD388 thumb
 *   func_021BD3F8 0x021BD3F8 thumb
 *   func_02049F34  0x02049F34  arm
 *   func_02082D44  0x02082D44  arm
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_02061CA4 0x02061CA4 arm
 *   tbl_020A1B38 0x020A1B38 data
 *   data_021C8390  0x021C8390  data
 *   func_021BD394  0x021BD394  thumb
 *   data_021C83C8  0x021C83C8  data
 *   func_021BE920 0x021BE920 thumb ov208
 *   func_021BE864 0x021BE864 thumb ov208
 *   func_0201C440 0x0201C440 thumb
 *   d_021C8DFC 0x021C8DFC data a1
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_021BE9CC 0x021BE9CC thumb ov208
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0204384C 0x0204384C arm
 *   func_020437EC 0x020437EC arm
 *   func_020437D4 0x020437D4 arm
 *   func_02040B58 0x02040B58 arm
 *   func_0204994C 0x0204994C arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049BDC        0x02049BDC  arm
 *   func_02043814        0x02043814  arm
 *   func_020437AC        0x020437AC  arm
 *   func_02045EC0        0x02045EC0  arm
 *   func_0201C724        0x0201C724  thumb
 *   func_02045808        0x02045808  arm
 *   data_021C84F4        0x021C84F4  data
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02040B1C  0x02040B1C  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02034AC4 0x02034AC4 arm
 *   ov067_id 0x00000043 data
 *   ov206_id 0x000000CE data
 *   func_021BC32C 0x021BC32C thumb
 *   func_021BC448 0x021BC448 thumb
 *   func_021BC518 0x021BC518 thumb
 *   func_021BC508 0x021BC508 thumb
 *   func_021BF63C 0x021BF63C thumb ov208
 *   func_021BF61C 0x021BF61C thumb ov208
 *   func_021BA2CC 0x021BA2CC thumb ov206
 *   func_021BF41C 0x021BF41C thumb ov208
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 *   func_021BC464 0x021BC464 thumb ov208
 *   func_021BC34C 0x021BC34C thumb ov208
 *   func_02034A5C 0x02034A5C arm
 *   func_021BC3B4 0x021BC3B4 thumb
 *   func_021BC3B8 0x021BC3B8 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_020414AC 0x020414AC arm
 *   func_021BDAD0 0x021BDAD0 thumb
 *   func_021BC3BC 0x021BC3BC thumb
 *   func_021BDAAC 0x021BDAAC thumb
 *   func_021BDAD4 0x021BDAD4 thumb
 *   func_021BDBB8 0x021BDBB8 thumb
 *   func_021BDC48 0x021BDC48 thumb
 *   func_021BC3A4 0x021BC3A4 thumb
 *   func_02012BF8 0x02012BF8 thumb
 *   func_021BE840 0x021BE840 thumb
 *   func_021BE82C 0x021BE82C thumb
 *   func_021BE844 0x021BE844 thumb
 *   func_021BF308 0x021BF308 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_021BC3A8 0x021BC3A8 thumb
 *   func_021BCF4C 0x021BCF4C thumb
 *   func_0200CA70 0x0200CA70 thumb
 *   func_021BF4FC 0x021BF4FC thumb
 *   func_021BC3B0 0x021BC3B0 thumb
 *   func_021B9E68 0x021B9E68 thumb ov206
 *   func_021BA7C8 0x021BA7C8 thumb ov206
 *   func_021BF4C4 0x021BF4C4 thumb
 *   func_021BF5B8 0x021BF5B8 thumb
 *   func_021BF620 0x021BF620 thumb
 *   func_021BC4D8 0x021BC4D8 thumb
 *   func_021BC4C8 0x021BC4C8 thumb
 *   func_021BDBA0 0x021BDBA0 thumb
 *   func_021BC4E4 0x021BC4E4 thumb
 *   func_021BE854 0x021BE854 thumb
 *   func_021BF450 0x021BF450 thumb
 *   func_021BA374 0x021BA374 thumb ov206
 *   func_021BF664 0x021BF664 thumb
 *   func_021BC46C 0x021BC46C thumb
 *   func_021BC3C0  0x021BC3C0  thumb  ov208
 *   func_021BC3CC  0x021BC3CC  thumb  ov208
 *   func_021BC40C  0x021BC40C  thumb  ov208
 *   func_02012BE0  0x02012BE0  thumb
 *   ov208_func_021BF280  0x021BF280  thumb  ov208
 *   func_020061E4  0x020061E4  thumb
 *   func_021BA550 0x021BA550 thumb ov206
 *   func_021BA6B0 0x021BA6B0 thumb ov206
 *   func_021BA814 0x021BA814 thumb ov206
 *   func_021BA64C 0x021BA64C thumb ov206
 */
#include "../../matched/include/Obj18236.h"
#include "../../matched/include/Obj03928.h"
#include "../../matched/include/Obj18238.h"
#include "../../matched/include/Obj03065.h"
#include "../../matched/include/Obj18242.h"
#include "../../matched/include/Obj05536.h"
#include "../../matched/include/Obj14647.h"
#include "../../matched/include/Obj18243.h"
#include "../../matched/include/Obj05866.h"
#include "../../matched/include/Obj12118.h"
#include "../../matched/include/Obj01080.h"
#include "../../matched/include/Obj02345.h"
#include "../../matched/include/Obj10895.h"
#include "../../matched/include/Obj14649.h"
#include "../../matched/include/Obj10896.h"
#include "../../matched/include/Obj14650.h"
#include "../../matched/include/Obj09200.h"
#include "../../matched/include/Obj07227.h"
#include "../../matched/include/Obj09201.h"
#include "../../matched/include/Obj01081.h"
#include "../../matched/include/Obj25442.h"
#include "../../matched/include/Obj14652.h"
#include "zukan_detail_types.h"
#include "../../matched/include/Obj03931.h"
#include "../../matched/include/Obj05867.h"
#include "../../matched/include/Obj03362.h"
#include "../../matched/include/Obj00442.h"

struct Obj;
struct Actor;
struct Bank;
struct Ov208Scene;
struct Node;
struct Ov208Mgr;
struct State;
struct Ov208Gfx;
struct PrintSys;
struct Bmp;
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct Obj020437AC;
struct Rec;
struct U16Vec;
struct Ov208Buf;
struct Ov208Blend;
struct Blk37;
struct GfFont;
struct S;
struct Ov208Cur;
struct Ov208Main;
struct Ov208Heap;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Scrn {
    u8  pad0[0xc];
    u16 data[1];
};

typedef signed short   s16;

struct Ov208ActKind {
    u16 a;
    u16 b;
    u16 c;
    u16 d;
    u32 e;
    u32 f;
};

struct Ov208Pos {
    s16 x;
    s16 y;
    u16 h4;
    u8  b6;
    u8  b7;
};

typedef signed int     s32;

typedef signed short   s16_021BDAAC;

struct State { char pad[0x68]; unsigned char count; };

struct Pt { u16 x,y; };

struct Actor { char pad[0xc]; struct Pt pos; };

struct Ov208Pltt {
    u32 pad0[3];
    u8 *data;
};

typedef signed short   s16_021BE1BC;

typedef short s16_021BE20C;

typedef signed short   s16_021BE3C4;

struct Ov208Icon_021BE710 { u16 heap,pad2; unsigned f4,f8; int fc; unsigned pad10[2],f18,f1c,f20,f24,f28,f2c,f30; };

struct Ov208Icon_021BE7A4 { u16 heap,pad2; unsigned f4,f8; int fc; unsigned char count,pad11[7]; unsigned f18,f1c,f20,f24,f28,f2c,f30; };

struct Ov208Icon_021BE82C {
    u32 pad0[3];
    int fc;
};

struct Ov208Icon_021BE840 {
    u32 f0;
    u32 f4;
    int state;
    int fc;
    u8  step;
};

struct Ov208Icon_021BE844 {
    u32 f0;
    u32 f4;
    int state;
    int fc;
    u8  step;
};

struct Ov208Icon_021BE854 {
    u32 f0;
    u32 f4;
    int state;
    int fc;
    u8  step;
};

struct Ov208Gfx { u16 heap; u16 pad; int f4; int f8; int fc; int f10; u32 f14; void *f18; int f1c; int f20; int f24; };

struct Ov208Icon {
    u16 heap;
    u16 pad2;
    u32 f4;
    u32 f8;
    int fc;
    u32 pad10[2];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
};

struct Ov208PalTbl {
    u32 v[5];
};

struct Ov208Main {
    int task;
    int f4; int f8;
    void *fc;
    void *f10;
    int f14; int f18;
    char pad[0x94 - 0x1c];
    int f94; int f98;
    char pad2[0x10c - 0x9c];
    int f10c;
};

struct Ov208Scn {
    u16 pad0; u16 pad2;
    void *f4; void *f8;
    struct Ov208Blend *fc; struct Ov208Blend *f10;
    int f14; int f18;
    char pad1c[0x94 - 0x1c];
    int f94;
    int f98;
    char pad9c[0xa8 - 0x9c];
    u16 srcA[0x10];
    u16 srcB[0x10];
    u16 dst[0x10];
    int f108;
    int f10c;
    void *font; void *msg0; void *msg1; void *msg2;
};

struct Ov208Heap { u16 heap; };

struct S_021BEE70 {
    u8 pad0[0x14];
    u32 f14;
    u32 f18;
};

struct E {
    u8 pad0[0x1c];
    int h1c;
    u8 x0;
    u8 y0;
    u8 w;
    u8 h;
    u8 pad24[2];
    u16 f26;
    u8 pad28[4];
    u32 f2c;
    u8 pad30[4];
};

struct S_021BEFA0 {
    u8 pad0[0x94];
    u32 cur;
    u32 prev;
};

struct Params {u16 a,b,c,d; unsigned x,y,arr[6];};

extern void func_021BDC48(struct Ov208Scene *s, u32 on);
extern void *func_0204A380(void *a0, u32 a1, u32 a2, u32 a3);
extern int func_02062B30(void *file, void **out);
extern u8 func_0204169C(int channel);
extern u32 func_0204162C(int channel);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u8 channel);
extern u32 func_020307B0(void *p);
extern void func_02082BCC(void *p, u32 v, u32 n);
extern u8   func_020416D4(u32 layer);
extern int func_021BD56C(int *p, int i);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3B4(struct Obj *p);
extern u32 func_0204B3F4(struct Obj *p);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_020061E4(u32 a);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02040618(unsigned,unsigned,unsigned);
extern void func_0204047C(int,u16);
extern struct Bank *func_0204B100(int,unsigned char,unsigned);
extern void func_0204B270(struct Bank *);
extern void func_021BDCF8(struct Ov208Scene *);
extern void func_021BD358(struct Ov208Mgr *p, int v);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern void func_02030EAC(struct Node *n);
extern unsigned int func_0204B1CC(struct Bank *bank);
extern u32 func_02040804(u32 layer);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_021BD23C(struct Ov208Mgr *p);
extern int func_021BD2E0(char *);
extern int func_021BD308(struct Ov208Mgr *m);
extern void ov208_func_021BD360(void *mgr);
extern void ov208_func_021BD330(void *mgr, int v);
extern void func_021BE170(struct Ov208Scene *p);
extern void func_021BD378(struct Ov208Mgr *a, int b, int c);
extern void func_021BD3A4(struct Ov208Mgr *a, int b, int c);
extern int func_021BD3B4(struct Ov208Mgr *mgr, int key);
extern int func_021BD35C(struct Ov208Mgr *p);
extern void func_0204B84C(int, int);
extern void func_021BDD98(struct Ov208Scene *p);
extern void func_021BE3C4(struct Ov208Scene *p);
extern void func_021BE504(struct Ov208Scene *p);
extern void func_0204B53C(const struct Actor *,struct Pt *);
extern void func_0204B528(struct Actor *,const struct Pt *);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern struct Ov208Mgr *func_021BD148(struct Ov208ActList *list, u32 heap);
extern int func_021BD3C0(struct Ov208Mgr *mgr, int key);
extern void func_021BD3CC(struct Ov208Mgr *mgr, int key, u16 *pos);
extern void func_021BD368(struct Ov208Mgr *a, int b, int c);
extern void func_021BE128(struct Ov208Scene *p);
extern void func_021BE1BC(struct Ov208Scene *e);
extern void func_021BD208(struct Ov208Mgr *m);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0203633C(void);
extern int func_021BD388(struct Ov208Mgr *mgr, int key);
extern void func_021BD3F8(struct Ov208Mgr *mgr, int key);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(void *src, void *dst, u32 size);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void func_021BD394(struct Ov208Mgr *a, int b, int c);
extern void func_021BE920(struct Ov208Icon_021BE710 *);
extern void func_021BE864(void *);
extern unsigned func_0201C440(void *);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_021BE9CC(struct Ov208Icon_021BE7A4 *);
extern unsigned func_0201C4E4(struct PrintSys *);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *a);
extern struct Bmp *func_0204384C(u32 arc, u32 member, u32 heap2, u32 heap);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_02040B58(u32 index, const void *src, u32 size);
extern u32 func_0204994C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned int func_02045C04(struct Rec *rec);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02043814(struct Bmp *dst, const struct Bmp *src);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_02041B6C(u32 layer);
extern int func_02034AC4(s32 handle);
extern void *func_021BC32C(struct Ov208Buf *p, u32 size, u32 heap);
extern void *func_021BC448(u32 heap);
extern void func_021BC518(int *p);
extern void func_021BC508(int flag, int *p);
extern void func_021BF63C(int,char *,unsigned);
extern void func_021BF61C(int,char *,unsigned);
extern void func_021BA2CC(char *);
extern void func_021BF41C(int,char *,unsigned);
extern u32 func_0201D83C(void *ptr);
extern void func_021BC464(void *);
extern void func_021BC34C(char *);
extern void func_02034A5C(int);
extern int func_021BC3B4(int *p);
extern int func_021BC3B8(char *p);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_020414AC(u8 a);
extern int func_021BDAD0(void *s);
extern u16 func_021BC3BC(int *ctx);
extern void func_021BDAAC(void *s, u32 a, u32 b, u32 c);
extern void func_021BDAD4(void *s, int a);
extern void func_021BDBB8(void *s, u32 a);
extern int func_021BC3A4(int *ctx);
extern int func_02012BF8(int a, int b);
extern int func_021BE840(void *s);
extern void func_021BE82C(void *s, int a);
extern void func_021BE844(void *s);
extern void func_021BF308(u16 *heap, char *p, int key);
extern void *func_0200CA1C(void *a);
extern int func_021BC3A8(int *ctx);
extern int func_021BCF4C(char *p);
extern u32 func_0200CA70(struct Blk37 *p);
extern void func_021BF4FC(const u16 *heap, u8 *p, int *key, u16 *out1, u16 *out2, u16 *out3, u16 *out4, u32 *out5, u32 *out6, u32 *out7);
extern int func_021BC3B0(int *ctx);
extern void *func_021B9E68(u32 heap, u16 a1, u16 a2, u16 a3, u16 a4, u32 a5, u32 a6, u32 a7, u32 a8, u32 a9, u8 a10, u32 a11, u32 a12, u32 a13, u32 a14, u32 a15, u32 a16);
extern void func_021BA7C8(void *p);
extern void func_021BF4C4(int unused, char *q, int c, int *tbl);
extern void func_021BF5B8(u16 *heap, u8 *p, int *ctx);
extern void func_021BF620(struct Ov208Heap *unused, int *p, int *ctx);
extern void func_021BC4D8(struct Ov208Blend *b);
extern int func_021BC4C8(struct Ov208Blend *b);
extern void func_021BDBA0(void *s);
extern void func_021BC4E4(struct Ov208Blend *b);
extern void func_021BE854(void *s);
extern void func_021BF450(void *unused, char *p, int key);
extern void func_021BA374(char *p);
extern void func_021BF664(struct Ov208Heap *h, struct Ov208Scn *p, int *ctx);
extern void func_021BC46C(struct Ov208Blend *a, struct Ov208Blend *b);
extern u16 func_021BC3C0(void *p);
extern void func_021BC3CC(char *p);
extern void func_021BC40C(struct Ov208Cur *p);
extern void func_02012BE0(void *p, u32 a, u32 b);
extern void ov208_func_021BF280(void *first, char *q, void *third, int next);
extern void func_021BA550(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6);
extern void func_021BA6B0(char *p, u16 a1, u16 a2, u16 a3, u16 a4, int a5, int a6, int a7);
extern void func_021BA814(void *);
extern void func_021BA64C(char *p, int mode);
void ov208_func_021BD574(void *a0, u32 a1, u32 channel, u32 add, u8 a4, u8 a5, u8 a6, u8 a7, u8 x, u8 y, u8 w, u8 h, u8 pal, u32 a13, u16 heap);
void ov208_func_021BD634(struct Ov208Rec *p, u32 owner, const int *res, struct Ov208ActDesc *desc, u32 prio, u16 mode);
void func_021BD74C(char *p);
int func_021BD764(char *p);
int func_021BD7E4(int *p);
int func_021BD7F8(char *p);
void func_021BD7FC(struct Obj **p, unsigned int v);
unsigned func_021BD808(int *p);
void func_021BD814(char *p, int v);
void func_021BD844(char *p, int v);
void func_021BD848(char *p, int which);
int func_021BD868(const void *p);
void func_021BD878(char *p);
void func_021BD880(char *p);
void func_021BD89C(char *p);
char *func_021BD8C0(u16 heap,unsigned arg);
void func_021BD954(struct Ov208Scene *m);
void func_021BD974(struct Ov208Scene *m);
void ov208_func_021BDAAC(struct Ov208Scene *p, u32 mode, u32 kind, u32 flag);
int ov208_func_021BDAD0(struct Ov208Scene *p);
void ov208_func_021BDAD4(struct Ov208Scene *p, int v);
void func_021BDAE8(struct Ov208Scene *p, int v);
unsigned func_021BDB08(const struct State *p);
unsigned func_021BDB54(const struct State *p);
void ov208_func_021BDBA0(struct Ov208Scene *p);
void ov208_func_021BDBAC(struct Ov208Scene *p, int v);
void ov208_func_021BDBB8(struct Ov208Scene *p, u32 kind);
void ov208_func_021BDBEC(struct Ov208Scene *p, int v);
void func_021BDC14(struct Ov208Scene *p, int b);
int func_021BDC2C(char *p);
int func_021BDC80(char *p);
void func_021BDCA4(char *p, unsigned char v);
void func_021BDCDC(int unused, char *p);
void ov208_func_021BDCF8(struct Ov208Scene *p);
void func_021BDD24(char *p);
void func_021BDD48(char *p,short offset);
void ov208_func_021BDD98(struct Ov208Scene *p);
void func_021BDFA8(struct Ov208Scene *e);
void func_021BDFDC(struct Ov208Scene *m);
void ov208_func_021BE128(u8 *p);
void func_021BE16C(struct Ov208Scene *e);
void ov208_func_021BE170(struct Ov208Scene *p);
void ov208_func_021BE1BC(struct Ov208Scene *p);
s32 func_021BE20C(struct Ov208Scene *m);
int func_021BE300(int kind);
unsigned func_021BE32C(unsigned n);
unsigned func_021BE378(unsigned n);
void ov208_func_021BE3C4(struct Ov208Scene *p);
void func_021BE4DC(struct Ov208Scene *e);
void ov208_func_021BE504(struct Ov208Scene *p);
void func_021BE680(char *p);
void func_021BE6A8(char *p);
struct Ov208Icon_021BE710 *func_021BE710(u16 heap,unsigned arg);
void func_021BE778(struct Ov208Scene *m);
void func_021BE7A4(struct Ov208Icon_021BE7A4 *p);
void ov208_func_021BE82C(struct Ov208Icon_021BE82C *p, int kind);
int ov208_func_021BE840(struct Ov208Icon_021BE840 *p);
void ov208_func_021BE844(struct Ov208Icon_021BE844 *p);
void ov208_func_021BE854(struct Ov208Icon_021BE854 *p);
void ov208_func_021BE864(void *p);
void func_021BE868(struct Ov208Gfx *g);
void func_021BE8FC(char *p);
void ov208_func_021BE920(struct Ov208Icon *p);
void func_021BE9C8();
void ov208_func_021BE9CC(struct Ov208Icon *p);
void ov208_func_021BEA00(u16 *p, u16 v);
int func_021BEA04(void *owner, int unused, u16 *heap);
int func_021BEA90(char *first,unsigned unused,int owner,char *q,unsigned heap);
int func_021BEB18(void *unused, int *state, struct Ov208Heap *h, struct Ov208Scn *p, int *ctx);
void func_021BEE70(void *a0, void *a1, void *heap, struct S_021BEE70 *st, int *obj, int key);
void func_021BEF9C(void *p);
int func_021BEFA0(void *a0, struct S_021BEFA0 *st, int *obj);
int func_021BF088(void *first,char *p,int key);
void func_021BF1D0(void *first,char *q,void *third);
void func_021BF280(void *first,char *q,void *third,int next);
extern const struct Ov208ActKind data_021C8314[];
extern const char d_021C8DE4[];
extern const int d_021C8388[];
extern const u8 d_021C8384[];
extern struct Ov208ActSrc data_021C8440[];
extern u16 data_021C83A4[][2];
extern s16_021BE20C tbl_020A1B38[];
extern struct Ov208ActSrc data_021C8390[];
extern struct Ov208ActSrc data_021C83C8[];
extern const char d_021C8DFC[];
extern const struct Ov208PalTbl data_021C84F4;
extern const char ov067_id[];
extern const char ov206_id[];









void ov208_func_021BD574(void *a0, u32 a1, u32 channel, u32 add, u8 a4, u8 a5, u8 a6,
                         u8 a7, u8 x, u8 y, u8 w, u8 h, u8 pal, u32 a13, u16 heap)
{
    struct Scrn *scr;
    u32 file;
    int i;
    u16 *d;

    file = (u32)func_0204A380(a0, a1, a13, (u16)((heap & 0x7fff) | 0x8000));
    func_02062B30((void *)file, (void **)(&scr));
    if (add != 0 && func_0204169C((u8)channel) == 0) {
        d = scr->data;
        for (i = 0; i < a6 * a7; i++)
            d[i] += (u16)add;
    }
    if ((int)func_0204162C((u8)channel) != 0) {
        func_020410D0((u8)channel, x, y, w, h, (u32)scr->data, a4, a5, a6, a7);
        func_020413B0(channel, x, y, w, h, pal);
        func_020409B4(channel);
    }
    func_020307B0((void *)file);
}









void ov208_func_021BD634(struct Ov208Rec *p, u32 owner, const int *res, struct Ov208ActDesc *desc,
                         u32 prio, u16 mode)
{
    struct Ov208Pos pos;
    u32 i;
    u32 j;
    u32 k;
    int n;

    func_02082BCC(p, 0, 0x38);
    p->desc = *desc;
    p->f4 = 1;
    p->f34 = 0;
    func_02082BCC(&pos, 0, 8);
    pos.b7 = func_020416D4((u8)res[3]);
    pos.x = desc->x;
    pos.y = desc->y;
    if (desc->f0 >= 7) {
        i = desc->ha;
        j = desc->hc;
        k = desc->he;
        p->f10 = 0;
    } else {
        i = func_021BD56C((int *)res, 1);
        j = func_021BD56C((int *)res, 0);
        k = func_021BD56C((int *)res, 2);
        n = desc->f0;
        p->desc.h10 = data_021C8314[n].a;
        p->desc.h12 = data_021C8314[n].b;
        p->desc.h14 = data_021C8314[n].c;
        p->desc.f18 = data_021C8314[n].e;
        p->desc.f1c = data_021C8314[n].d;
        p->f10 = data_021C8314[n].f;
    }
    p->f8 = p->desc.h10;
    pos.h4 = p->desc.h10;
    p->f0 = (u32)func_0204B294((void *)owner, i, j, k, &pos, prio, mode);
    func_0204B92C((struct Obj *)p->f0, 1);
    switch (p->f10) {
    case 0:
        p->fc = (void (*)(void))func_021BD880;
        break;
    case 1:
        p->fc = (void (*)(void))func_021BD89C;
        break;
    }
}









/*
 * Releases +0 and clears 0x38 bytes of the object.
 */
void func_021BD74C(char *p)
{
    func_0204B3B4((struct Obj *)(((struct Obj18236 *)p)->f0));
    func_02082BCC(p, 0, 0x38);
}








int func_021BD764(char *p)
{
    unsigned x,y;
    int hit=0;
    if(func_0204B3F4(((struct Obj03928 *)p)->f0)&((struct Obj03928 *)p)->f4) {
        if(func_02035D20(&x,&y) && x-((struct Obj03928 *)p)->f18<=((struct Obj03928 *)p)->f1C && y-((struct Obj03928 *)p)->f1A<=24) {
            hit=1;
            func_020355D8(1);
        }
        if(((struct Obj03928 *)p)->f2C && (func_020362DC()&((struct Obj03928 *)p)->f2C)) {
            func_020355D8(0);
            hit=1;
        }
        if(((struct Obj03928 *)p)->f34) {
            func_020355D8(0);
            hit=1;
        }
        if(hit) {
            (*(void (**)(char *))(p+0xc))(p);
            return 1;
        }
    }
    return 0;
}









/*
 * Returns 1 when the ARM9 call at 0x0204B98C on the word at [p] comes back zero.
 */
int func_021BD7E4(int *p)
{
    return func_0204B98C((struct Actor *)(*p)) == 0;
}










int func_021BD7F8(char *p)
{
    return ((struct Obj18238 *)p)->f14;
}









/*
 * Loads the word at [p] and tail-calls the function at 0x0204B3DC with it and
 * the second argument.
 */
void func_021BD7FC(struct Obj **p, unsigned int v)
{
    func_0204B3DC(*p, v);
}









unsigned func_021BD808(int *p)
{
    return func_0204B3F4((struct Obj *)(*p));
}









void func_021BD814(char *p, int v)
{
    ((struct Obj03065 *)p)->f4 = v;
    if (v != 0) {
        if (((struct Obj03065 *)p)->f8 == ((struct Obj03065 *)p)->f28)
            ((struct Obj03065 *)p)->f8 = ((struct Obj03065 *)p)->f24;
        func_0204B878((struct Obj *)(((struct Obj03065 *)p)->f0), (unsigned short)((struct Obj03065 *)p)->f8);
    } else {
        func_0204B878((struct Obj *)(((struct Obj03065 *)p)->f0), ((struct Obj03065 *)p)->f26);
    }
}









void func_021BD844(char *p, int v)
{
    ((struct Obj18242 *)p)->f2C = v;
}








void func_021BD848(char *p, int which)
{
    if (which != 0)
    {
        ((struct Obj05536 *)p)->f8 = ((struct Obj05536 *)p)->f28;
    }
    else
    {
        ((struct Obj05536 *)p)->f8 = ((struct Obj05536 *)p)->f24;
    }
    func_0204B878(((struct Obj05536 *)p)->f0, (unsigned short)((struct Obj05536 *)p)->f8);
}








int func_021BD868(const void *p)
{
    u32 r1 = ((struct Obj14647 *)p)->f8;
    u32 r0 = ((struct Obj14647 *)p)->f28;
    return r1 == r0;
}









/*
 * Clears the word at +0x34.
 */
void func_021BD878(char *p)
{
    ((struct Obj18243 *)p)->f34 = 0;
}








/*
 * Re-verified 2026-09-27 (DIFF fixer lane): the +8 store in the image is a
 * full word, `str r1,[r4,#8]`, not `strh`: the zero-extended u16 is written
 * through an int lvalue.  With `*(int *)(p + 8) = h;` the whole function
 * reproduces, including `ldrh r1,[r4,#0x28]; ldr r0,[r4]; str r1,[r4,#8]`.
 * EXACT*: the inferred extent runs 2 bytes past `pop` (an unlabelled
 * follower/alignment word), never a byte difference.
 */
void func_021BD880(char *p)
{
    unsigned short h = ((struct Obj05866 *)p)->f28;
    int v = ((struct Obj05866 *)p)->f0;

    ((struct Obj05866 *)p)->f8 = h;
    func_0204B878((struct Obj *)v, h);
    if (((struct Obj05866 *)p)->f30 != 0)
        func_020061E4(((struct Obj05866 *)p)->f30);
}








void func_021BD89C(char *p)
{
    int f = func_021BD868(p) == 0;

    func_021BD848(p, f);
    if (((struct Obj12118 *)p)->f30 != 0)
        func_020061E4(((struct Obj12118 *)p)->f30);
}







char *func_021BD8C0(u16 heap,unsigned arg)
{
    char *p=func_02030734(heap,0x11c,1,d_021C8DE4,0x148);
    ((struct Obj01080 *)p)->f0=heap;((struct Obj01080 *)p)->f4=arg;
    ((struct Obj01080 *)p)->f8=0;((struct Obj01080 *)p)->fC=0;((struct Obj01080 *)p)->f10=0;
    ((struct Obj01080 *)p)->f14=1;((struct Obj01080 *)p)->f18=0;((struct Obj01080 *)p)->f1C=0;((struct Obj01080 *)p)->f20=0;
    func_02040618(1,3,-24);func_0204047C(1,0);
    p[0x38]=0;((struct Obj01080 *)p)->f3C=0;
    *(struct Bank * *)&((struct Obj01080 *)p)->f28=func_0204B100(16,0,((struct Obj01080 *)p)->f0);
    func_0204B270(*(struct Bank * *)&((struct Obj01080 *)p)->f28);
    *(unsigned *)&((struct Obj01080 *)p)->f30=0;func_021BDCF8((struct Ov208Scene *)p);
    func_021BD358(((struct Obj01080 *)p)->f30,0);
    ((struct Obj01080 *)p)->fB4=24;func_021BDD48(p,((struct Obj01080 *)p)->fB4);
    ((struct Obj01080 *)p)->f2C=func_020056A0((unsigned)func_021BDCDC,(unsigned)p,1);
    return p;
}







/*
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
void func_021BD954(struct Ov208Scene *m)
{
    func_02030EAC((struct Node *)m->f2c);
    func_021BDD24((char *)m);
    func_0204B1CC((struct Bank *)m->f28);
    func_020307B0(m);
}







void func_021BD974(struct Ov208Scene *m)
{
    int v;
    switch (m->state) {
    case 0:
    case 2:
        break;
    case 1:
        if (m->step == 0) {
            if ((int)func_02040804((int)1) >= 0) {
                func_02041EE4(1, 3, 0);
                m->pos = 0;
                func_021BDD48((char *)m, m->pos);
                m->state = 2;
                if (m->f34 != 0)
                    func_021BD358(m->mgr, 1);
                break;
            }
            func_02041EE4(1, 4, d_021C8388[m->idx]);
            m->pos = m->pos - (short)d_021C8388[m->idx];
            func_021BDD48((char *)m, m->pos);
            m->step = d_021C8384[m->idx];
        } else {
            m->step--;
        }
        break;
    case 3:
        if (m->step == 0) {
            if ((int)func_02040804((int)1) <= -24) {
                func_02041EE4(1, 3, -24);
                m->pos = 24;
                func_021BDD48((char *)m, m->pos);
                m->state = 0;
            } else {
                func_02041EE4(1, 5, d_021C8388[m->idx]);
                m->pos = m->pos + (short)d_021C8388[m->idx];
                func_021BDD48((char *)m, m->pos);
                m->step = d_021C8384[m->idx];
            }
        } else {
            m->step--;
        }
        break;
    }
    func_021BD23C(m->mgr);
    if (m->mode == 0) {
        func_021BDFDC((struct Ov208Scene *)m);
        func_021BE20C((struct Ov208Scene *)m);
    } else if (m->mode == 2) {
        func_021BE6A8((char *)m);
    }
}








void ov208_func_021BDAAC(struct Ov208Scene *p, u32 mode, u32 kind, u32 flag)
{
    p->fc = p->mode;
    p->mode = mode;
    p->f14 = p->f18;
    p->f18 = kind;
    p->f40 = flag;
    func_021BDD24((char *)p);
    p->f1c = p->f18;
    func_021BDCF8(p);
}








int ov208_func_021BDAD0(struct Ov208Scene *p)
{
    return p->state;
}








void ov208_func_021BDAD4(struct Ov208Scene *p, int v)
{
    p->idx = v;
    if (p->state != 2) {
        p->state = 1;
        p->step = 0;
    }
}








/*
 * Stores the argument at +0x20 and, when +8 is set, restarts it at state 3.
 */
void func_021BDAE8(struct Ov208Scene *p, int v)
{
    p->idx = v;
    if (p->state != 0) {
        p->state = 3;
        p->step = 0;
        func_021BD358(p->mgr, 0);
    }
}






unsigned func_021BDB08(const struct State *p)
{
    int key=func_021BD2E0(*(char * *)&((struct Obj10895 *)p)->f30);
    unsigned result=0;
    unsigned char i;
    unsigned count;
    char *entry;
    if(key!=-1) {
        switch(((struct Obj10895 *)p)->f10) {
        case 0: case 1: case 2:
            i=0;
            count=p->count;
            for(;i<count;i++) {
                entry=*(char **)((char *)p+i*8+0x6c);
                if(key==((struct Obj14649 *)entry)->f0) { result=((struct Obj14649 *)entry)->fC; break; }
            }
            break;
        }
    }
    return result;
}






/*
 * trailing: 021BDB9E..021BDBA0 is two-byte zero alignment padding.
 * matching: initialize the byte counter before reading the bound.
 */
unsigned func_021BDB54(const struct State *p)
{
    int key=func_021BD308((struct Ov208Mgr *)(*(char * *)&((struct Obj10896 *)p)->f30));
    unsigned result=0;
    unsigned char i;
    unsigned count;
    char *entry;
    if(key!=-1) {
        switch(((struct Obj10896 *)p)->f10) {
        case 0: case 1: case 2:
            i=0;
            count=p->count;
            for(;i<count;i++) {
                entry=*(char **)((char *)p+i*8+0x6c);
                if(key==((struct Obj14650 *)entry)->f0) { result=((struct Obj14650 *)entry)->f10; break; }
            }
            break;
        }
    }
    return result;
}







void ov208_func_021BDBA0(struct Ov208Scene *p)
{
    ov208_func_021BD360(p->mgr);
}







void ov208_func_021BDBAC(struct Ov208Scene *p, int v)
{
    ov208_func_021BD330(p->mgr, v);
}







void ov208_func_021BDBB8(struct Ov208Scene *p, u32 kind)
{
    u32 saved;
    int restore;

    if (p->mode == 0) {
        restore = 0;
        p->f14 = p->f18;
        p->f18 = kind;
        if (kind == p->f1c) {
            saved = p->f1c;
            restore = 1;
            p->f1c = 4;
        }
        ov208_func_021BE1BC(p);
        func_021BE170(p);
        if (restore)
            p->f1c = saved;
    }
}







void ov208_func_021BDBEC(struct Ov208Scene *p, int v)
{
    if (p->mode == 2) {
        func_021BD378(p->mgr, p->slots[1].src->id, v);
        func_021BD378(p->mgr, p->slots[2].src->id, v);
    }
}







/*
 * Calls func_021BD3A4 with two fields and the second argument while +0x10 is clear.
 */
void func_021BDC14(struct Ov208Scene *p, int b)
{
    if (p->mode == 0)
        func_021BD3A4(p->mgr, p->slots[2].src->id, b);
}







int func_021BDC2C(char *p)
{
    if (((struct Obj09200 *)p)->f10 == 0)
        return func_021BD3B4((void *)(((struct Obj09200 *)p)->f30),
                             *(int *)*(int * *)&((struct Obj09200 *)p)->f7C);
    return 0;
}







void func_021BDC48(struct Ov208Scene *p, u32 on)
{
    p->f34 = on;
    if (on != 0) {
        if (func_021BD35C(p->mgr) == 0 && p->state == 2)
            func_021BD358(p->mgr, 1);
    } else {
        if (func_021BD35C(p->mgr) != 0)
            func_021BD358(p->mgr, 0);
    }
}








int func_021BDC80(char *p)
{
    switch (((struct Obj07227 *)p)->f10) {
    case 0:
        return ((struct Obj07227 *)p)->f44;
    case 1:
        return ((struct Obj07227 *)p)->f50;
    case 2:
        return ((struct Obj07227 *)p)->f5C;
    }
    return -1;
}







/*
 * Stores the mode at +0x38, arms +0x3C and hands the mode to every +0x70 handle.
 */
void func_021BDCA4(char *p, unsigned char v)
{
    unsigned char i;

    ((struct Obj02345 *)p)->f38 = v;
    ((struct Obj02345 *)p)->f3C = 1;
    for (i = 0; i < ((struct Obj02345 *)p)->f68; i++)
        func_0204B84C(*(int *)(p + i * 8 + 0x70), v);
}







/*
 * BLOCKED.  MATCH: the call at +0x10 targets 0204047C, an ARM address with no label and no pool witness outside the compared range, so the site stays wildcarded.
 */
void func_021BDCDC(int unused, char *p)
{
    if (((struct Obj09201 *)p)->f3C != 0) {
        func_0204047C(1, ((struct Obj09201 *)p)->f38);
        ((struct Obj09201 *)p)->f3C = 0;
    }
}







void ov208_func_021BDCF8(struct Ov208Scene *p)
{
    switch (p->mode) {
    case 0:
        func_021BDD98(p);
        break;
    case 1:
        func_021BE3C4(p);
        break;
    case 2:
        func_021BE504(p);
        break;
    }
    p->f34 = 1;
}







void func_021BDD24(char *p)
{
    switch (((struct Obj01081 *)p)->fC) {
    case 0:
        func_021BDFA8((struct Ov208Scene *)p);
        break;
    case 1:
        func_021BE4DC((struct Ov208Scene *)p);
        break;
    case 2:
        func_021BE680(p);
        break;
    }
}






void func_021BDD48(char *p,short offset)
{
    unsigned char i;
    struct Pt pt;
    for(i=0;i<((struct Obj25442 *)p)->f68;i++) {
        func_0204B53C(*(struct Actor **)(p+i*8+0x70),&pt);
        pt.y=*(short *)(*(char **)(p+i*8+0x6c)+6);
        pt.y=(short)pt.y+offset;
        func_0204B528(*(struct Actor **)(p+i*8+0x70),&pt);
    }
}







void ov208_func_021BDD98(struct Ov208Scene *p)
{
    struct Ov208ActList list;
    struct Ov208ActDesc descs[9];
    void *h;
    u8 i;
    int v;

    h = func_020490F4(0x9f, p->heap);
    p->f44 = func_0204AC18(h, 3, 0, 0x160, 0, 3, p->heap);
    p->f48 = func_0204A6C8(h, 0xd, 0, 0, p->heap);
    p->f4c = func_0204AF28(h, 0x1b, 0x2c, p->heap);
    func_02049238(h);
    p->count = 9;
    for (i = 0; i < p->count; i++)
        p->slots[i].src = &data_021C8440[i];
    for (i = 0; i < p->count; i++) {
        descs[i].f0 = p->slots[i].src->id;
        descs[i].x = p->slots[i].src->x;
        descs[i].y = p->slots[i].src->y;
        descs[i].h8 = p->slots[i].src->h8;
    }
    descs[3].ha = p->f48;
    descs[3].hc = p->f44;
    descs[3].he = p->f4c;
    descs[3].h10 = 3;
    descs[3].h12 = 3;
    descs[3].h14 = 7;
    descs[3].f18 = 0;
    descs[3].f1c = 0x54a;
    descs[4].ha = p->f48;
    descs[4].hc = p->f44;
    descs[4].he = p->f4c;
    descs[4].h10 = 2;
    descs[4].h12 = 2;
    descs[4].h14 = 6;
    descs[4].f18 = 0;
    descs[4].f1c = 0x54a;
    descs[5].ha = p->f48;
    descs[5].hc = p->f44;
    descs[5].he = p->f4c;
    descs[5].h10 = 1;
    descs[5].h12 = 1;
    descs[5].h14 = 5;
    descs[5].f18 = 0;
    descs[5].f1c = 0x54a;
    descs[6].ha = p->f48;
    descs[6].hc = p->f44;
    descs[6].he = p->f4c;
    descs[6].h10 = 0;
    descs[6].h12 = 0;
    descs[6].h14 = 4;
    descs[6].f18 = 0;
    descs[6].f1c = 0x54a;
    func_02082BCC(&list, 0, sizeof(list));
    list.descs = descs;
    list.count = 9;
    list.owner = p->f28;
    list.channel = 1;
    list.pal = 0xd;
    list.objPal = 8;
    list.kind = 2;
    p->mgr = func_021BD148(&list, p->heap);
    for (i = 0; i < p->count; i++)
        p->slots[i].obj = func_021BD3C0((void *)p->mgr, p->slots[i].src->id);
    if (p->f4 == 0) {
        for (i = 0; i < 9; i++)
            func_021BD3CC(p->mgr, p->slots[i].src->id, data_021C83A4[i]);
        func_021BD378(p->mgr, p->slots[3].src->id, 0);
    }
    v = func_021BE300(p->f18);
    if (v != 9)
        func_021BD368(p->mgr, p->slots[v].src->id, 0);
    func_021BE128(p);
    func_021BE170((struct Ov208Scene *)p);
    if (p->f40 == 0) {
        func_021BD378(p->mgr, p->slots[8].src->id, 0);
        func_021BD378(p->mgr, p->slots[7].src->id, 0);
    }
}






void func_021BDFA8(struct Ov208Scene *e)
{
    if (e->mgr != 0) {
        func_021BE1BC(e);
        func_021BE16C(e);
        func_021BD208(e->mgr);
        func_0204ADA4((u32)e->f44);
        func_0204A8D4((u32)e->f48);
        func_0204AFD8((u32)e->f4c);
    }
    e->mgr = 0;
}






void func_021BDFDC(struct Ov208Scene *m)
{
    u32 sel = 9;
    u32 trg = func_020362DC();
    u32 held = func_0203633C();
    u32 a;
    u32 b;
    u32 c;
    volatile u32 d; /* volatile on purpose: image spills it to the stack and re-reads it */
    u8 i;
    if (held & 0x20) {
        switch (m->f18) {
        case 0:
            if (func_021BD388(m->mgr, m->slots[3].src->id))
                sel = 3;
            else
                sel = 4;
            break;
        case 1:
            sel = 6;
            break;
        case 2:
            sel = 5;
            break;
        case 3:
            sel = 4;
            break;
        }
    } else if (held & 0x10) {
        switch (m->f18) {
        case 0:
            sel = 5;
            break;
        case 1:
            sel = 4;
            break;
        case 2:
            if (func_021BD388(m->mgr, m->slots[3].src->id))
                sel = 3;
            else
                sel = 6;
            break;
        case 3:
            sel = 6;
            break;
        }
    }
    if (sel != 9)
        func_021BD3F8(m->mgr, m->slots[sel].src->id);
    if ((trg & 0xc0) == 0) {
        if (held & 0x40)
            func_021BD3F8(m->mgr, m->slots[8].src->id);
        else if (held & 0x80)
            func_021BD3F8(m->mgr, m->slots[7].src->id);
    }
    a = func_021BDB08((const struct State *)m);
    b = func_021BDB54((const struct State *)m);
    if (a != 0) {
        c = func_021BE32C(a);
        d = func_021BE378(a);
        if (c != 9 && d != 4) {
            for (i = 3; i <= 6; i++)
                func_021BD368(m->mgr, m->slots[i].src->id, i != c);
            m->f1c = d;
            func_021BE170((struct Ov208Scene *)((struct Ov208Scene *)m));
        }
    }
    if (b != 0) {
        switch (b) {
        case 15:
        case 16:
        case 17:
        case 18:
            func_021BE1BC((struct Ov208Scene *)m);
            break;
        }
    }
}







void ov208_func_021BE128(u8 *p)
{
    struct Ov208Pltt *pltt;
    u32 file;
    u8 *data;

    file = (u32)func_02049F34(0x9f, 3, (u32)(&pltt), ((struct Obj14652 *)p)->f0);
    data = pltt->data;
    func_02082D44(data + 0x20, p + 0xb6, 0x20);
    func_02082D44(data + 0x60, p + 0xd6, 0x20);
    func_020307B0((void *)file);
    ((struct Obj14652 *)p)->f118 = 0;
}







/*
 * Empty stub; the listing pads it with two zero bytes.
 */
void func_021BE16C(struct Ov208Scene *e)
{
}





void ov208_func_021BE170(struct Ov208Scene *p)
{
    u32 idx = 9;

    switch (p->f1c) {
    case 0:
        idx = 6;
        break;
    case 1:
        idx = 5;
        break;
    case 2:
        idx = 4;
        break;
    case 3:
        idx = 3;
        break;
    }
    if (idx != 9)
        func_0204B6F4((struct Obj *)func_021BD3C0(p->mgr, p->slots[idx].src->id), 2, 0);
}





void ov208_func_021BE1BC(struct Ov208Scene *p)
{
    int slot = 9;

    switch (p->f1c) {
    case 0:
        slot = 6;
        break;
    case 1:
        slot = 5;
        break;
    case 2:
        slot = 4;
        break;
    case 3:
        slot = 3;
        break;
    }
    if (slot != 9) {
        func_0204B6F4((struct Obj *)func_021BD3C0(p->mgr, p->slots[slot].src->id), 0, 0);
        p->f1c = 4;
    }
}




s32 func_021BE20C(struct Ov208Scene *m)
{
    s16_021BE20C t;
    u8 i;
    if (m->phase + 0x400 >= 0x10000)
        m->phase -= 0xfc00;
    else
        m->phase += 0x400;
    t = (tbl_020A1B38[2 * (m->phase >> 4) + 1] + 0x1000) / 2;
    for (i = 0; i < 16; i++) {
        u16 c1 = m->palA[i];
        u16 c2 = m->palB[i];
        u8 r1 = c1 & 0x1f;
        u8 g1 = (c1 & 0x3e0) >> 5;
        u8 b1 = (c1 & 0x7c00) >> 10;
        u8 r2 = c2 & 0x1f;
        u8 g2 = (c2 & 0x3e0) >> 5;
        u8 b2 = (c2 & 0x7c00) >> 10;
        u8 r = r1 + ((r2 - r1) * t >> 12);
        u8 g = g1 + ((g2 - g1) * t >> 12);
        u8 b = b1 + ((b2 - b1) * t >> 12);
        m->palOut[i] = r | g << 5 | b << 10;
    }
    return func_02061CA4((void *)14, 0x1a0, (u32)m->palOut, 0x20);
}




/*
 * Returns 6, 5, 4 or 3 for the four known kinds and 9 for anything else.
 */
int func_021BE300(int kind)
{
    switch (kind) {
    case 0:
        return 6;
    case 1:
        return 5;
    case 2:
        return 4;
    case 3:
        return 3;
    }
    return 9;
}




/*
 * trailing: 021BE376..021BE378 is two-byte zero alignment padding.
 */
unsigned func_021BE32C(unsigned n)
{
    switch(n) {
    case 0: break;
    case 6: case 15: return 6;
    case 7: case 16: return 5;
    case 8: case 17: return 4;
    case 9: case 18: return 3;
    default: break;
    }
    return 9;
}




/*
 * trailing: 021BE3C2..021BE3C4 is two-byte zero alignment padding.
 */
unsigned func_021BE378(unsigned n)
{
    switch(n) {
    case 0: break;
    case 6: case 15: return 0;
    case 7: case 16: return 1;
    case 8: case 17: return 2;
    case 9: case 18: return 3;
    default: break;
    }
    return 4;
}





void ov208_func_021BE3C4(struct Ov208Scene *p)
{
    struct Ov208ActList list;
    struct Ov208ActDesc descs[1];
    void *h;
    u8 i;

    h = func_020490F4(0x55, p->heap);
    p->f50 = func_0204AC18(h, 2, 0, 0x160, 2, 3, p->heap);
    p->f54 = func_0204A6C8(h, 8, 0, 0, p->heap);
    p->f58 = func_0204AF28(h, 0xc, 0x13, p->heap);
    func_02049238(h);
    p->count = 1;
    for (i = 0; i < p->count; i++)
        p->slots[i].src = &data_021C8390[i];
    for (i = 0; i < p->count; i++) {
        descs[i].f0 = p->slots[i].src->id;
        descs[i].x = p->slots[i].src->x;
        descs[i].y = p->slots[i].src->y;
        descs[i].h8 = p->slots[i].src->h8;
    }
    func_02082BCC(&list, 0, sizeof(list));
    list.descs = descs;
    list.count = 1;
    list.owner = p->f28;
    list.channel = 1;
    list.pal = 0xd;
    list.objPal = 8;
    list.kind = 2;
    p->mgr = func_021BD148(&list, p->heap);
    for (i = 0; i < p->count; i++)
        p->slots[i].obj = func_021BD3C0(p->mgr, p->slots[i].src->id);
}



void func_021BE4DC(struct Ov208Scene *e)
{
    if (e->mgr != 0) {
        func_021BD208(e->mgr);
        func_0204ADA4((u32)e->f50);
        func_0204A8D4((u32)e->f54);
        func_0204AFD8((u32)e->f58);
    }
    e->mgr = 0;
}




void ov208_func_021BE504(struct Ov208Scene *p)
{
    struct Ov208ActList list;
    struct Ov208ActDesc descs[6];
    struct Ov208ActDesc *d;
    void *h;
    u8 i;

    h = func_020490F4(0x9f, p->heap);
    p->f5c = func_0204AC18(h, 3, 0, 0x160, 0, 3, p->heap);
    p->f60 = func_0204A6C8(h, 0xd, 0, 0, p->heap);
    p->f64 = func_0204AF28(h, 0x1b, 0x2c, p->heap);
    func_02049238(h);
    p->count = 6;
    for (i = 0; i < p->count; i++)
        p->slots[i].src = &data_021C83C8[i];
    for (i = 0; i < p->count; i++) {
        descs[i].f0 = p->slots[i].src->id;
        descs[i].x = p->slots[i].src->x;
        descs[i].y = p->slots[i].src->y;
        descs[i].h8 = p->slots[i].src->h8;
    }
    d = &descs[3];
    d->ha = p->f60;
    d->hc = p->f5c;
    d->he = p->f64;
    d->h10 = 0xe;
    d->h12 = 0xe;
    d->h14 = 0x14;
    d->f18 = 1;
    d->f1c = 0x54c;
    func_02082BCC(&list, 0, sizeof(list));
    list.descs = descs;
    list.count = 6;
    list.owner = p->f28;
    list.channel = 1;
    list.pal = 0xd;
    list.objPal = 8;
    list.kind = 2;
    p->mgr = func_021BD148(&list, p->heap);
    for (i = 0; i < p->count; i++)
        p->slots[i].obj = func_021BD3C0(p->mgr, p->slots[i].src->id);
    func_021BD394(p->mgr, p->slots[1].src->id, 0x110);
    func_021BD394(p->mgr, p->slots[2].src->id, 0x220);
    if (p->f40 == 0) {
        func_021BD378(p->mgr, p->slots[5].src->id, 0);
        func_021BD378(p->mgr, p->slots[4].src->id, 0);
    }
}




void func_021BE680(char *p)
{
    if (*(int *)&((struct Obj01081 *)p)->f30 != 0) {
        func_021BD208((struct Ov208Mgr *)(*(int *)&((struct Obj01081 *)p)->f30));
        func_0204ADA4(((struct Obj01081 *)p)->f5C);
        func_0204A8D4(((struct Obj01081 *)p)->f60);
        func_0204AFD8(((struct Obj01081 *)p)->f64);
    }
    *(int *)&((struct Obj01081 *)p)->f30 = 0;
}



void func_021BE6A8(char *p)
{
    unsigned held=func_020362DC();
    unsigned keys=func_0203633C();
    if(!(held&0x3f0)) {
        if(keys&0x40) func_021BD3F8(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f94);
        else if(keys&0x80) func_021BD3F8(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f8C);
        else if(keys&0x220) func_021BD3F8(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f7C);
        else if(keys&0x110) func_021BD3F8(((struct Obj03931 *)p)->f30,**(int * *)&((struct Obj03931 *)p)->f74);
    }
}



struct Ov208Icon_021BE710 *func_021BE710(u16 heap,unsigned arg)
{
    struct Ov208Icon_021BE710 *p=func_02030734(heap,0x34,1,d_021C8DFC,120);
    p->heap=heap;p->f4=arg;p->f8=0;p->fc=5;
    func_02040618(5,3,24);
    func_0204047C(5,0);
    func_021BE868((struct Ov208Gfx *)p);
    func_021BE920(p);
    p->f28=(unsigned)func_020056A0((unsigned)func_021BE864,(unsigned)p,1);
    p->f2c=func_0201C440((void *)(unsigned)p->heap);
    p->f30=0;
    return p;
}



/*
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
void func_021BE778(struct Ov208Scene *m)
{
    func_0201C6EC((void *)m->f2c);
    func_0201C4C0((struct PrintSys *)m->f2c);
    func_02030EAC((struct Node *)m->f28);
    func_021BE9C8(m);
    func_021BE8FC((char *)m);
    func_020307B0(m);
}



/*
 * matching: direct byte field access avoids a persistent extracted pointer register.
 */
void func_021BE7A4(struct Ov208Icon_021BE7A4 *p)
{
    switch(p->f8) {
    case 0: case 2: break;
    case 1:
        if(p->count==0) {
            if((int)func_02040804(5)<=0) {
                func_02041EE4(5,3,0);p->f8=2;
            } else {func_02041EE4(5,5,3);p->count=0;}
        } else --p->count;
        break;
    case 3:
        if(p->count==0) {
            if((int)func_02040804(5)>=24) {
                func_02041EE4(5,3,24);p->f8=0;
            } else {func_02041EE4(5,4,3);p->count=0;}
        } else --p->count;
        break;
    }
    func_021BE9CC(p);
    func_0201C4E4((struct PrintSys *)p->f2c);
}





void ov208_func_021BE82C(struct Ov208Icon_021BE82C *p, int kind)
{
    p->fc = kind;
    func_021BE9C8();
    ov208_func_021BE920((struct Ov208Icon *)p);
}





int ov208_func_021BE840(struct Ov208Icon_021BE840 *p)
{
    return p->state;
}





void ov208_func_021BE844(struct Ov208Icon_021BE844 *p)
{
    if (p->state != 2) {
        p->state = 1;
        p->step = 0;
    }
}





void ov208_func_021BE854(struct Ov208Icon_021BE854 *p)
{
    if (p->state != 0) {
        p->state = 3;
        p->step = 0;
    }
}




void ov208_func_021BE864(void *p)
{
}




/*
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
void func_021BE868(struct Ov208Gfx *g)
{
    g->f14 = func_020450F0(5, 0, 0, 0x10, 1, 13, 0);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)g->f14)), 0);
    func_02045334((struct Descriptor *)g->f14);
    g->f18 = func_0204384C(0x9f, 14, 0, g->heap);
    g->f20 = func_020437EC(g->f18);
    g->f1c = func_02040B58(5, func_020437D4(g->f18), g->f20);
    func_0204994C(0x9f, 0x25, 5, 0, g->f1c, 0xc0, 0, g->heap);
    func_020413B0(5, 0, 0, 0x20, 0x18, 13);
    g->f24 = (int)func_02045B38(0, 2, 0xea, g->heap);
}





void func_021BE8FC(char *p)
{
    func_02045C04((struct Rec *)(((struct Obj05867 *)p)->f24));
    func_0203FB44(5, ((struct Obj05867 *)p)->f1C, ((struct Obj05867 *)p)->f20);
    func_020437AC((struct Obj020437AC *)(((struct Obj05867 *)p)->f18));
    func_020452E8((struct Descriptor *)(((struct Obj05867 *)p)->f14));
}






void ov208_func_021BE920(struct Ov208Icon *p)
{
    struct Ov208PalTbl pal;
    void *h;
    u32 s;

    if (p->fc < 0 || p->fc >= 5)
        return;
    h = func_020490F4(0x9f, p->heap);
    pal = data_021C84F4;
    func_02049BDC(h, 4, 4, pal.v[p->fc] << 5, 0x1a0, 0x20, p->heap);
    func_02049238(h);
    h = func_0204384C(0x9f, 0xe, 0, p->heap);
    func_02043814(h, (const struct Bmp *)p->f18);
    func_020437AC(h);
    s = (u32)func_02045EC0((struct MsgBank *)p->f24, p->fc + 0xb2);
    func_0201C724((void *)p->f2c, p->f18, 0x18, 5, s, p->f4, 0x3dc0);
    func_02045808((struct U16Vec *)s);
    p->f30 = 1;
    ov208_func_021BE9CC(p);
}





void func_021BE9C8()
{
}






void ov208_func_021BE9CC(struct Ov208Icon *p)
{
    if (p->f30 != 0 && func_0201C6C4((struct PrintSys *)p->f2c, (void *)p->f18) == 0) {
        func_02040B1C(5, func_020437D4((const struct Bmp *)p->f18), p->f20, p->f1c);
        func_02041B6C(5);
        p->f30 = 0;
    }
}






void ov208_func_021BEA00(u16 *p, u16 v)
{
    *p = v;
}





/*
 * 2026-10-04 (D2-16): callback func_021BEF9C filed EXACT as src/matched/ov/ov208_func_021BEF9C.c (empty void function, bx lr). Still MATCH only
 * because no shard witnesses it yet; the integrator manifest run should make this EXACT. Symbols line now carries the ov208 hint.
 * 2026-10-02: only func_021BEF9C (task callback, no witness yet) blocks EXACT; bytes match.
 */
int func_021BEA04(void *owner, int unused, u16 *heap)
{
    struct Ov208Main *s;
    func_02034AC4((u32)ov067_id);
    func_02034AC4((u32)ov206_id);
    s = func_021BC32C(owner, 0x120, *heap);
    func_02082BCC(s, 0, 0x120);
    s->task = (int)func_020056A0((unsigned)func_021BEF9C, (unsigned)s, 1);
    s->f94 = 6;
    s->f98 = 6;
    s->f10c = 0;
    s->fc = func_021BC448(*heap);
    s->f10 = func_021BC448(*heap);
    func_021BC518(s->fc);
    func_021BC518(s->f10);
    func_021BC508(0, s->fc);
    func_021BC508(1, s->f10);
    s->f14 = 0;
    s->f18 = 1;
    return 1;
}





/*
 * matching: full-width stack argument reloads; small pool operands are overlay ID symbols.
 * Caller visibly supplies third arguments to helpers and a live r0 to BC464.
 */
int func_021BEA90(char *first,unsigned unused,int owner,char *q,unsigned heap)
{
    func_021BF63C(owner,q,heap);func_021BF61C(owner,q,heap);
    func_021BA2CC(*(char * *)&((struct Obj03362 *)q)->f8);func_021BA2CC(*(char * *)&((struct Obj03362 *)q)->f4);
    func_021BF41C(owner,q,heap);
    func_0201D83C(((struct Obj03362 *)q)->f110);
    func_02045C04(*(struct Rec * *)&((struct Obj03362 *)q)->f11C);
    func_02045C04(*(struct Rec * *)&((struct Obj03362 *)q)->f118);
    func_02045C04(*(struct Rec * *)&((struct Obj03362 *)q)->f114);
    func_021BC464(((struct Obj03362 *)q)->f10);func_021BC464(((struct Obj03362 *)q)->fC);
    func_02030EAC(*(struct Node * *)&((struct Obj03362 *)q)->f0);func_021BC34C(first);
    func_02034A5C((int)ov206_id);func_02034A5C((int)ov067_id);return 1;
}




/*
 * 2026-10-05 (wD8 lane04): EXACT. The three "ov093" callees are in ov206 (matched there, co-resident with
 *   ov208 as in the matched siblings 021BEA04/021BEA90); the region token on their symbols lines is ov206.
 * 2026-10-05 (D5-03): MATCH. Byte-correct except the five calls to the ov093 callees 0x021B9E68,
 *   0x021BA7C8, 0x021BA374 (no witness label; ov093 below 0x021D4000, pengy). Fixes: the colour loop
 *   calls are func_02040618(i, 0, 0) and (i, 3, 0) (the draft passed i; the image keeps the 0 in r7, which
 *   is why ctx left r7), the first 9E68 call passes (2, 0, 1), locals v54 before v50 before w, the
 *   021BDAD0 test written `!= 2` first, and case 4 writes `*state = 5` in both arms.
 * 2026-10-04 (wD2 lane19): also tried ctx as a one-field struct by value and as u32 with casts: no change (frame 0x74/0x78 vs 0x70,
 *   ctx still in r7). Residue unchanged: image stores ctx back to [sp,#0x88] at entry and keeps state at [sp,#0x34], r7 free.
 * 2026-10-05 (wave D4 lane 02): frame layout check: image has v40 at sp+0x40, v44 0x44, w 0x48, v50 0x50,
 *   v54 0x54, tbl 0x58 (frame 0x70). Ours puts two spilled constant temps (0x17+0xfd and 0xf5+0x27, the
 *   msg field offsets) at 0x40/0x44 because ctx holds r7, so everything shifts by 8 (frame 0x78). Tried:
 *   both state and ctx `*volatile` (882 bytes, worse). Root residue is still ctx kept in r7 instead of its
 *   home slot. Also blocked: func_021B9E68, func_021BA7C8, func_021BA374 have no label (ov093 low, pengy).
 * 2026-10-02 (lane C2-01): control flow, callees and frame layout recovered (tbl[6] at sp+0x58 gives the 0x70 frame);
 * the six-state task body is complete. Still DIFF in register allocation: the image keeps the stack argument ctx in
 * its home slot [sp,#0x88] (reloaded at every use, stored back once at entry) and state in [sp,#0x34], leaving r7
 * free for hoisted constants (0x17 and 0xf5 bases in the font/message setup). Here ctx lands in r7 and the setup
 * spills those constants. Tried: int *volatile ctx (state then takes r7).
 * Also unresolved: func_021B9E68, func_021BA7C8, func_021BA374 (ov093 below 0x021D4000, not ours).
 */
int func_021BEB18(void *unused, int *state, struct Ov208Heap *h, struct Ov208Scn *p, int *ctx)
{
    void *scn = (void *)func_021BC3B4(ctx);
    void *icon = (void *)func_021BC3B8((char *)ctx);
    int v40;
    int v44;
    u32 v54;
    u32 v50;
    u16 w[4];
    u32 tbl[6];
    u8 i;
    int t;
    switch (*state) {
    case 0:
        *state = 1;
        p->font = func_0201D7EC(0x17, 0, 1, 0, h->heap);
        p->msg0 = func_02045B38(1, 2, 0x104, h->heap);
        p->msg1 = func_02045B38(1, 2, 0xf5, h->heap);
        p->msg2 = func_02045B38(1, 2, 0x10c, h->heap);
        for (i = 0; i <= 7; i++) {
            if (i != 1 && i != 5) {
                func_02040618(i, 0, 0);
                func_02040618(i, 3, 0);
                func_020414AC(i);
            }
        }
        if (func_021BDAD0(scn) != 2) {
            func_021BDAAC(scn, 0, 0, func_021BC3BC(ctx) > 1);
            func_021BDAD4(scn, 0);
        } else {
            func_021BDBB8(scn, 0);
        }
        func_021BDC48(scn, 0);
        func_021BDC14(scn, func_02012BF8(func_021BC3A4(ctx), 0x11));
        if (func_021BE840(icon) != 2) {
            func_021BE82C(icon, 0);
            func_021BE844(icon);
        }
        func_021BF308((u16 *)h, (char *)p, (int)ctx);
        t = (int)func_0200CA1C((void *)func_021BC3A4(ctx));
        v40 = func_021BCF4C((char *)func_021BC3A8(ctx));
        v44 = func_0200CA70((void *)t);
        func_021BF4FC((const u16 *)h, (u8 *)p, (int *)ctx, &w[3], &w[2], &w[1], &w[0], &v54, &v50, tbl);
        p->f4 = func_021B9E68(h->heap, w[3], w[2], w[1], w[0], v54, v44, v50, 2, 0, 1, v40, (u32)p->font, func_021BC3B0(ctx), (u32)p->msg0, (u32)p->msg1, (u32)p->msg2);
        p->f8 = func_021B9E68(h->heap, w[3], w[2], w[1], w[0], v54, v44, v50, 2, 1, 1, v40, (u32)p->font, func_021BC3B0(ctx), (u32)p->msg0, (u32)p->msg1, (u32)p->msg2);
        func_021BA7C8(p->f8);
        func_021BF4C4((int)h, (char *)p, (int)ctx, (int *)tbl);
        func_021BF5B8((u16 *)h, (u8 *)p, ctx);
        func_021BF620(h, (int *)p, ctx);
        break;
    case 1:
        *state = 2;
        func_021BC4D8(p->fc);
        func_021BC4D8(p->f10);
        break;
    case 2:
        if (func_021BC4C8(p->fc) == 0 && func_021BDAD0(scn) == 2 && func_021BE840(icon) == 2) {
            func_021BDBA0(scn);
            func_021BDC48(scn, 1);
            *state = 3;
        }
        break;
    case 3:
        if (p->f14 != 0) {
            *state = 4;
            func_021BC4E4(p->fc);
            func_021BC4E4(p->f10);
            func_021BE854(icon);
            if (p->f14 == 2)
                func_021BDAE8(scn, 0);
        } else if (p->f18 != 0) {
            if (func_021BEFA0(h, (struct S_021BEFA0 *)((struct S *)p), ctx) == 0)
                func_021BF088(h, (char *)p, (int)ctx);
        }
        break;
    case 4:
        if (func_021BC4C8(p->fc) == 0 && func_021BC4C8(p->f10) == 0 && func_021BE840(icon) == 0) {
            if (p->f14 == 2) {
                if (func_021BDAD0(scn) == 0)
                    *state = 5;
            } else {
                *state = 5;
            }
        }
        break;
    case 5:
        return 1;
    }
    if (*state >= 2) {
        func_021BF450(h, (char *)p, (int)ctx);
        func_021BA374(p->f4);
        func_021BA374(p->f8);
        if (p->f94 == 6)
            func_021BF664(h, p, ctx);
    }
    func_021BC46C(p->fc, p->f10);
    return 0;
}







void func_021BEE70(void *a0, void *a1, void *heap, struct S_021BEE70 *st, int *obj, int key)
{
    int sc;
    u32 flag;

    if (st == 0) {
        return;
    }
    sc = func_021BC3B4(obj);
    flag = 0;
    switch (key) {
    case 15:
        break;
    case 10: case 11: case 12: case 13: case 14: case 16: case 17: case 18:
        st->f18 = flag;
        break;
    }
    switch (key) {
    case 1: case 2: case 3: case 4: case 5: case 7: case 8: case 9:
        flag = 1;
        st->f18 = flag;
        break;
    }
    switch (key) {
    case 12: {
        u16 old = func_021BC3C0(obj);
        func_021BC3CC((char *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021BF1D0(heap, (char *)st, obj);
        }
        break;
    }
    case 13: {
        u16 old = func_021BC3C0(obj);
        func_021BC40C((struct Ov208Cur *)obj);
        if (old != func_021BC3C0(obj)) {
            func_021BF1D0(heap, (char *)st, obj);
        }
        break;
    }
    }
    switch (key) {
    case 0:
        break;
    case 1: case 2:
        st->f14 = 2;
        return;
    case 7: case 8: case 9:
        st->f14 = 1;
        return;
    case 3:
        func_021BDBA0((void *)sc);
        return;
    case 4:
        func_021BDBA0((void *)sc);
        return;
    case 5:
        func_02012BE0((void *)func_021BC3A4(obj), 0x11, func_021BDC2C((char *)sc));
        func_021BDBA0((void *)sc);
        return;
    default:
        if (flag != 0) {
            func_021BDBA0((void *)sc);
        }
        break;
    }
}






void func_021BEF9C(void *p)
{
}






/*
 * note (2026-10-05, integrator): EXACT. The rect bytes are read through a byte pointer with the offset in a local (k = 0x20, c[k] .. c[k + 3]), as in ov208 021C6760; the byte loads then come before x.
 * 2026-10-04 (D2-16): also tried positive forms `x0 <= x && x < x0+w` (13 bytes out, shape changes) and `x0 > x` with u32 or int casts and
 * no locals (13 to 15 bytes out). With `x0 > x` the compare order is right but x0 lands in r0 and x in r1 (the image has x0 in r1);
 * with `x < x0` the registers are right and the compare order flips. The residue is one register colour pair.
 * note:     2026-10-04 (D1-08): f2c store fixed by raw `*(u32 *)((u8 *)st + st->cur * 0x14 + 0x2c) = 1`. Now 4 bytes: the two
 *            bounds tests are `cmp x0,x; bhi` in the image (x0 in r1, x in r0) and `cmp x,x0; blo` here (same registers). Writing
 *            `e->x0 > x` instead flips the registers (x0 in r0) but keeps the compare order; neither gives the image.
 * note:     2026-10-02 lane C2-02: two compare directions (image: cmp x0,x then bhi) and the f2c store constant order differ; tried x0<=x, !(x0>x), locals.
 *
 * 2026-10-05 (D4-18): still 4 bytes. Tried: positive form x >= x0 && x < x0 + w (4 bytes, same as now), !(e->x0 > x || ...) (13 bytes: x0 lands in r0), int-cast compares (17 bytes, bgt). The compare order of the image needs x0 in r1 with the unsigned-greater test; every spelling that gives that order puts x0 in r0.
 */
int func_021BEFA0(void *a0, struct S_021BEFA0 *st, int *obj)
{
    int sc;
    int res;
    u32 x;
    u32 y;
    u8 i;
    struct E *e;
    u8 *c;
    int k;

    sc = func_021BC3B4(obj);
    res = 0;
    if (st->cur == 6 && func_02035D20(&x, &y) != 0) {
        for (i = 0; i < 6; i++) {
            e = (struct E *)((u8 *)st + i * 0x14);
            c = (u8 *)e;
            k = 0x20;
            if (func_0204B3F4((struct Obj *)e->h1c) != 0
                && (u32)c[k] <= x && x < (u32)c[k] + c[k + 2]
                && (u32)c[k + 1] <= y && y < (u32)c[k + 1] + c[k + 3]) {
                if (st->prev == i) break;
                st->cur = i;
                res = 1;
                break;
            }
        }
    }
    if (res != 0) {
        ov208_func_021BF280(a0, (char *)st, obj, st->cur);
        *(u32 *)((u8 *)st + st->cur * 0x14 + 0x2c) = 1;
        e = (struct E *)((u8 *)st + st->cur * 0x14);
        func_0204B878((struct Obj *)e->h1c, e->f26);
        func_020061E4(0x54a);
        func_020355D8(1);
        func_021BDC48((void *)sc, 0);
    }
    return res;
}




int func_021BF088(void *first,char *p,int key)
{
    void *scene;
    int changed;
    u32 buttons,press;
    u8 i,next;
    scene=(void *)func_021BC3B4((int *)key);
    changed=0;
    if(((struct Obj00442 *)p)->f94==6) {
        buttons=func_0203633C();
        press=func_020362DC();
        if(((struct Obj00442 *)p)->f98==6) {
            if((buttons&0x300)||(press&1)) {
                for(i=0;i<6;i++) {
                    if(func_0204B3F4(*(struct Obj **)((u32)p+(u32)i*20+0x1c))!=0) {
                        ((struct Obj00442 *)p)->f94=i; changed=1; break;
                    }
                }
            }
        } else if((buttons&0x100)||(press&1)) {
            for(i=1;i<6;i++) {
                next=(((struct Obj00442 *)p)->f98+i)%6;
                if(func_0204B3F4(*(struct Obj **)((u32)p+(u32)next*20+0x1c))!=0) {
                    ((struct Obj00442 *)p)->f94=next; changed=1; break;
                }
            }
        } else if(buttons&0x200) {
            for(i=1;i<6;i++) {
                next=(((struct Obj00442 *)p)->f98+6-i)%6;
                if(func_0204B3F4(*(struct Obj **)((u32)p+(u32)next*20+0x1c))!=0) {
                    ((struct Obj00442 *)p)->f94=next; changed=1; break;
                }
            }
        }
    }
    if(changed!=0) {
        func_021BF280(first,p,(void *)key,((struct Obj00442 *)p)->f94);
        *(u32 *)((u32)p+*(u32 *)&((struct Obj00442 *)p)->f94*20+0x2c)=1;
        func_0204B878(*(struct Obj **)((u32)p+*(u32 *)&((struct Obj00442 *)p)->f94*20+0x1c),*(u16 *)((u32)p+*(u32 *)&((struct Obj00442 *)p)->f94*20+0x26));
        func_020061E4(0x54a);
        func_020355D8(0);
        func_021BDC48((void *)((int)scene), 0);
    }
    return changed;
}




/*
 * matching: initialize the flag after the output-producing call to keep its zero-cost schedule.
 * Third helper arguments are explicitly live in the original caller.
 */
void func_021BF1D0(void *first,char *q,void *third)
{
    struct Params p;
    int okay,index;
    func_021BF4FC(first,(u8 *)q,(int *)third,&p.d,&p.c,&p.b,&p.a,&p.y,&p.x,p.arr);
    okay=1;
    func_021BA550(((struct Obj00442 *)q)->f4,p.d,p.c,p.b,p.a,p.y,p.x);
    index=((struct Obj00442 *)q)->f98;
    if(index!=6) {
        if(p.arr[index]!=0) okay=0;
        else {func_021BF63C((int)first, q, (unsigned)third);((struct Obj00442 *)q)->f98=6;}
    }
    if(okay) func_021BA7C8(((struct Obj00442 *)q)->f8);
    else func_021BA6B0(((struct Obj00442 *)q)->f8,p.d,p.c,p.b,p.a,p.y,p.x,((struct Obj00442 *)q)->f98);
    func_021BF4C4((int)first,q,(int)third,(int *)p.arr);
}




void func_021BF280(void *first,char *q,void *third,int next)
{
    struct Params p;
    int current=((struct Obj00442 *)q)->f98;
    if(current!=next) {
        if(current==6) {
            func_021BF4FC(first,(u8 *)q,(int *)third,&p.d,&p.c,&p.b,&p.a,&p.y,&p.x,p.arr);
            func_021BA6B0(((struct Obj00442 *)q)->f8,p.d,p.c,p.b,p.a,p.y,p.x,next);
            func_021BA814(((struct Obj00442 *)q)->f8);
        } else func_021BA64C(((struct Obj00442 *)q)->f8,next);
        func_021BF63C((int)first, q, (unsigned)third);((struct Obj00442 *)q)->f98=next;
        func_021BF620(first,(int *)q,third);
    }
}
