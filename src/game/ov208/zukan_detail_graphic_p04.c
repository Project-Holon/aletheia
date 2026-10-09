/*
 * file:     zukan_detail_graphic_p04.c
 * unit:     yes
 * function: func_021BD574, func_021BD634, func_021BD74C, func_021BD764, func_021BD7E4, func_021BD7F8, func_021BD7FC, func_021BD808, func_021BD814, func_021BD844, func_021BD848, func_021BD868, func_021BD878, func_021BD880, func_021BD89C, func_021BD8C0, func_021BD954, func_021BD974, func_021BDAAC, func_021BDAD0, func_021BDAD4, func_021BDAE8, func_021BDB08, func_021BDB54, func_021BDBA0, func_021BDBAC, func_021BDBB8, func_021BDBEC, func_021BDC14, func_021BDC2C, func_021BDC48, func_021BDC80, func_021BDCA4, func_021BDCDC, func_021BDCF8, func_021BDD24, func_021BDD48, func_021BDD98, func_021BDFA8, func_021BDFDC, func_021BE128, func_021BE16C
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
 *   func_021BE20C 0x021BE20C thumb
 *   func_021BE6A8 0x021BE6A8 thumb
 *   d_021C8388 0x021C8388 data a4
 *   d_021C8384 0x021C8384 data a1
 *   func_021BD2E0 0x021BD2E0 thumb ov208
 *   func_021BD308 0x021BD308 thumb ov208
 *   ov208_func_021BD360  0x021BD360  thumb
 *   ov208_func_021BD330  0x021BD330  thumb
 *   ov208_func_021BE1BC  0x021BE1BC  thumb
 *   func_021BE170  0x021BE170  thumb
 *   func_021BD378  0x021BD378  thumb
 *   func_021BD3A4 0x021BD3A4  thumb  ov208
 *   func_021BD3B4 0x021BD3B4  thumb  ov208
 *   func_021BD35C  0x021BD35C  thumb
 *   func_021BDD98  0x021BDD98  thumb
 *   func_021BE3C4  0x021BE3C4  thumb
 *   func_021BE504  0x021BE504  thumb
 *   func_021BE4DC 0x021BE4DC  thumb  ov208
 *   func_021BE680 0x021BE680  thumb  ov208
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
 *   func_021BE300  0x021BE300  thumb
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
 *   func_021BE32C 0x021BE32C thumb
 *   func_021BE378 0x021BE378 thumb
 *   func_02049F34  0x02049F34  arm
 *   func_02082D44  0x02082D44  arm
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

struct Obj;
struct Actor;
struct Bank;
struct Ov208Scene_021BD574;
struct Node;
struct Ov208Menu;
struct Ov208Pal;
struct Ov208Mgr;
struct Ov208Eff;
struct State;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Scrn {
    u8  pad0[0xc];
    u16 data[1];
};

typedef signed short   s16;

struct Ov208ActDesc_021BD574 {
    int f0;
    s16 x;
    s16 y;
    u16 h8;
    u16 ha;
    u16 hc;
    u16 he;
    u16 h10;
    u16 h12;
    u16 h14;
    u16 h16;
    u32 f18;
    u32 f1c;
};

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

struct Ov208ActObj {
    u32 f0;
    u32 f4;
    u32 f8;
    void (*fc)(void);
    u32 f10;
    struct Ov208ActDesc_021BD574 desc;
    u32 f34;
};

struct Ov208Mgr { char pad[0x28]; void *f28; void *f2c; };

typedef short s16_021BD974;

struct Ov208Fade_021BD974 {
    int f0; int f4; int state; int fc; int mode; int f14; int f18; int f1c;
    int idx;
    u8 cnt;
    char pad25[0x0b];
    void *f30; int f34; char pad38[0x7c];
    s16_021BD974 pos;
};

typedef signed int     s32;

typedef signed short   s16_021BDAAC;

struct Ov208ActDesc_021BD844 {
    int f0;
    s16_021BDAAC x;
    s16_021BDAAC y;
    u16 h8;
    u16 ha;
    u16 hc;
    u16 he;
    u16 h10;
    u16 h12;
    u16 h14;
    u16 h16;
    u32 f18;
    u32 f1c;
};

struct Ov208ActList_021BD574 {
    struct Ov208ActDesc_021BD844 *descs;
    u32 count;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
};

struct Ov208ActSrc {
    int id;
    u16 x;
    u16 y;
    u16 h8;
    u16 pad;
    u32 fc;
    u32 f10;
};

struct Ov208Slot {
    struct Ov208ActSrc *src;
    u32 obj;
};

struct Ov208Scene_021BD574 {
    u16 heap;
    u16 pad2;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 mgr;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
    u32 f50;
    u32 f54;
    u32 f58;
    u32 f5c;
    u32 f60;
    u32 f64;
    u8  count;
    u8  pad69[3];
    struct Ov208Slot slots[10];
};

struct Ov208Fade_021BDAD0 {
    u32 f0;
    u32 f4;
    int state;
};

struct Ov208Fade_021BDAD4 {
    u32 f0;
    u32 f4;
    int state;
    u32 pad[5];
    int arg;
    u8  step;
};

struct State { char pad[0x68]; unsigned char count; };

struct Ov208Scene_021BDBA0 {
    u32 pad0[12];
    void *mgr;
};

struct Ov208Scene_021BDBAC {
    u32 pad0[12];
    void *mgr;
};

struct Ov208ActDesc {
    int f0;
    s16 x;
    s16 y;
    u16 h8;
    u16 ha;
    u16 hc;
    u16 he;
    u16 h10;
    u16 h12;
    u16 h14;
    u16 h16;
    u32 f18;
    u32 f1c;
};

struct Ov208ActList_021BDB08 {
    struct Ov208ActDesc *descs;
    u32 count;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
};

struct Ov208Scene_021BDBB8 {
    u16 heap;
    u16 pad2;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 mgr;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
    u32 f50;
    u32 f54;
    u32 f58;
    u32 f5c;
    u32 f60;
    u32 f64;
    u8  count;
    u8  pad69[3];
    struct Ov208Slot slots[10];
};

struct Ov208Scene_021BDBEC {
    u32 pad0[4];
    u32 f10;
    u32 pad14[7];
    u32 mgr;
    u32 pad34[16];
    int *keyA;
    u32 pad78;
    int *keyB;
};

struct Ov208Scene_021BDC48 {
    u32 pad0[2];
    u32 f8;
    u32 pad0c[9];
    void *mgr;
    u32 f34;
};

struct Ov208Scene_021BDCF8 {
    u16 heap;
    u16 pad2;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 mgr;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
    u32 f50;
    u32 f54;
    u32 f58;
    u32 f5c;
    u32 f60;
    u32 f64;
    u8  count;
    u8  pad69[3];
    struct Ov208Slot slots[10];
};

struct Pt { u16 x,y; };

struct Actor { char pad[0xc]; struct Pt pos; };

struct Ov208ActList {
    struct Ov208ActDesc *descs;
    u32 count;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
};

struct Ov208Slot_021BDD48 {
    struct Ov208ActSrc *src;
    u32 obj;
};

struct Ov208Scene_021BDD48 {
    u16 heap;
    u16 pad2;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 mgr;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
    u32 f50;
    u32 f54;
    u32 f58;
    u32 f5c;
    u32 f60;
    u32 f64;
    u8  count;
    u8  pad69[3];
    struct Ov208Slot_021BDD48 slots[10];
};

struct Ov208Eff { char pad[0x30]; struct Ov208Mgr *mgr; char pad2[0x10]; void *f44; void *f48; void *f4c; };

struct Ov208Slot_021BDFDC { int *p; int q; };

struct Ov208Menu {
    char pad0[0x18];
    int mode;
    int f1c;
    char pad20[0x10];
    void *f30;
    char pad34[0x38];
    struct Ov208Slot_021BDFDC tab[9];
};

struct Ov208Pltt {
    u32 pad0[3];
    u8 *data;
};

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
extern void func_021BDCF8(struct Ov208Scene_021BD574 *);
extern void func_021BD358(char *p, int v);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern void func_02030EAC(struct Node *n);
extern unsigned int func_0204B1CC(struct Bank *bank);
extern u32 func_02040804(u32 layer);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_021BD23C(char *p);
extern s32 func_021BE20C(struct Ov208Pal *m);
extern void func_021BE6A8(char *p);
extern int func_021BD2E0(char *);
extern int func_021BD308(struct Ov208Mgr *m);
extern void ov208_func_021BD360(void *mgr);
extern void ov208_func_021BD330(void *mgr, int v);
extern void ov208_func_021BE1BC(struct Ov208Scene_021BDBB8 *p);
extern void func_021BE170(struct Ov208Scene_021BDBB8 *p);
extern void func_021BD378(int a, int b, int c);
extern void func_021BD3A4(int a, int b, int c);
extern int func_021BD3B4(void *mgr, int key);
extern int func_021BD35C(char *p);
extern void func_0204B84C(int, int);
extern void func_021BDD98(struct Ov208Scene_021BDCF8 *p);
extern void func_021BE3C4(struct Ov208Scene_021BDCF8 *p);
extern void func_021BE504(struct Ov208Scene_021BDCF8 *p);
extern void func_021BE4DC(struct Ov208Eff *e);
extern void func_021BE680(char *);
extern void func_0204B53C(const struct Actor *,struct Pt *);
extern void func_0204B528(struct Actor *,const struct Pt *);
extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern u32  func_021BD148(struct Ov208ActList *list, u32 heap);
extern int func_021BD3C0(void *mgr, int key);
extern void func_021BD3CC(u32 mgr, int key, u16 *pos);
extern void func_021BD368(int a, int b, int c);
extern int func_021BE300(int kind);
extern void func_021BE128(struct Ov208Scene_021BDD48 *p);
extern void func_021BE1BC(struct Ov208Eff *e);
extern void func_021BD208(struct Ov208Mgr *m);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0203633C(void);
extern int func_021BD388(void *a, int b);
extern void func_021BD3F8(void *a, int b);
extern u32 func_021BE32C(u32 v);
extern u32 func_021BE378(u32 v);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(void *src, void *dst, u32 size);
void ov208_func_021BD574(u32 a0, u32 a1, u32 channel, u32 add, u8 a4, u8 a5, u8 a6, u8 a7, u8 x, u8 y, u8 w, u8 h, u8 pal, u32 a13, u16 heap);
void ov208_func_021BD634(struct Ov208ActObj *p, u32 owner, const int *res, struct Ov208ActDesc_021BD574 *desc, u32 prio, u16 mode);
void func_021BD74C(char *p);
int func_021BD764(char *p);
int func_021BD7E4(int *p);
int func_021BD7F8(char *p);
void func_021BD7FC(struct Obj **p, unsigned int v);
void func_021BD808(int *p);
void func_021BD814(char *p, int v);
void func_021BD844(char *p, int v);
void func_021BD848(char *p, int which);
int func_021BD868(const void *p);
void func_021BD878(char *p);
void func_021BD880(char *p);
void func_021BD89C(char *p);
char *func_021BD8C0(u16 heap,unsigned arg);
void func_021BD954(struct Ov208Mgr *m);
void func_021BD974(struct Ov208Fade_021BD974 *m);
void ov208_func_021BDAAC(struct Ov208Scene_021BD574 *p, u32 mode, u32 kind, u32 flag);
int ov208_func_021BDAD0(struct Ov208Fade_021BDAD0 *p);
void ov208_func_021BDAD4(struct Ov208Fade_021BDAD4 *p, int v);
void func_021BDAE8(char *p, int v);
unsigned func_021BDB08(const struct State *p);
unsigned func_021BDB54(const struct State *p);
void ov208_func_021BDBA0(struct Ov208Scene_021BDBA0 *p);
void ov208_func_021BDBAC(struct Ov208Scene_021BDBAC *p, int v);
void ov208_func_021BDBB8(struct Ov208Scene_021BDBB8 *p, u32 kind);
void ov208_func_021BDBEC(struct Ov208Scene_021BDBEC *p, int v);
void func_021BDC14(char *p, int b);
int func_021BDC2C(char *p);
void ov208_func_021BDC48(struct Ov208Scene_021BDC48 *p, u32 on);
int func_021BDC80(char *p);
void func_021BDCA4(char *p, unsigned char v);
void func_021BDCDC(int unused, char *p);
void ov208_func_021BDCF8(struct Ov208Scene_021BDCF8 *p);
void func_021BDD24(char *p);
void func_021BDD48(char *p,short offset);
void ov208_func_021BDD98(struct Ov208Scene_021BDD48 *p);
void func_021BDFA8(struct Ov208Eff *e);
void func_021BDFDC(struct Ov208Menu *m);
void ov208_func_021BE128(u8 *p);
void func_021BE16C(struct Ov208Eff *e);
extern const struct Ov208ActKind data_021C8314[];
extern const char d_021C8DE4[];
extern const int d_021C8388[];
extern const u8 d_021C8384[];
extern struct Ov208ActSrc data_021C8440[];
extern u16 data_021C83A4[][2];






void ov208_func_021BD574(u32 a0, u32 a1, u32 channel, u32 add, u8 a4, u8 a5, u8 a6,
                         u8 a7, u8 x, u8 y, u8 w, u8 h, u8 pal, u32 a13, u16 heap)
{
    struct Scrn *scr;
    u32 file;
    int i;
    u16 *d;

    file = (u32)func_0204A380((void *)a0, a1, a13, (u16)((heap & 0x7fff) | 0x8000));
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






void ov208_func_021BD634(struct Ov208ActObj *p, u32 owner, const int *res, struct Ov208ActDesc_021BD574 *desc,
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






void func_021BD808(int *p)
{
    func_0204B3F4((struct Obj *)(*p));
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
    *(unsigned *)&((struct Obj01080 *)p)->f30=0;func_021BDCF8((struct Ov208Scene_021BD574 *)p);
    func_021BD358(((struct Obj01080 *)p)->f30,0);
    ((struct Obj01080 *)p)->fB4=24;func_021BDD48(p,((struct Obj01080 *)p)->fB4);
    ((struct Obj01080 *)p)->f2C=func_020056A0((unsigned)func_021BDCDC,(unsigned)p,1);
    return p;
}




/*
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
void func_021BD954(struct Ov208Mgr *m)
{
    func_02030EAC(m->f2c);
    func_021BDD24((char *)m);
    func_0204B1CC(m->f28);
    func_020307B0(m);
}




void func_021BD974(struct Ov208Fade_021BD974 *m)
{
    int v;
    switch (m->state) {
    case 0:
    case 2:
        break;
    case 1:
        if (m->cnt == 0) {
            if ((int)func_02040804((int)1) >= 0) {
                func_02041EE4(1, 3, 0);
                m->pos = 0;
                func_021BDD48((char *)m, m->pos);
                m->state = 2;
                if (m->f34 != 0)
                    func_021BD358(m->f30, 1);
                break;
            }
            func_02041EE4(1, 4, d_021C8388[m->idx]);
            m->pos = m->pos - (s16_021BD974)d_021C8388[m->idx];
            func_021BDD48((char *)m, m->pos);
            m->cnt = d_021C8384[m->idx];
        } else {
            m->cnt--;
        }
        break;
    case 3:
        if (m->cnt == 0) {
            if ((int)func_02040804((int)1) <= -24) {
                func_02041EE4(1, 3, -24);
                m->pos = 24;
                func_021BDD48((char *)m, m->pos);
                m->state = 0;
            } else {
                func_02041EE4(1, 5, d_021C8388[m->idx]);
                m->pos = m->pos + (s16_021BD974)d_021C8388[m->idx];
                func_021BDD48((char *)m, m->pos);
                m->cnt = d_021C8384[m->idx];
            }
        } else {
            m->cnt--;
        }
        break;
    }
    func_021BD23C(m->f30);
    if (m->mode == 0) {
        func_021BDFDC((struct Ov208Menu *)m);
        func_021BE20C((struct Ov208Pal *)m);
    } else if (m->mode == 2) {
        func_021BE6A8((char *)m);
    }
}





void ov208_func_021BDAAC(struct Ov208Scene_021BD574 *p, u32 mode, u32 kind, u32 flag)
{
    p->fc = p->f10;
    p->f10 = mode;
    p->f14 = p->f18;
    p->f18 = kind;
    p->f40 = flag;
    func_021BDD24((char *)p);
    p->f1c = p->f18;
    func_021BDCF8(p);
}





int ov208_func_021BDAD0(struct Ov208Fade_021BDAD0 *p)
{
    return p->state;
}





void ov208_func_021BDAD4(struct Ov208Fade_021BDAD4 *p, int v)
{
    p->arg = v;
    if (p->state != 2) {
        p->state = 1;
        p->step = 0;
    }
}





/*
 * Stores the argument at +0x20 and, when +8 is set, restarts it at state 3.
 */
void func_021BDAE8(char *p, int v)
{
    ((struct Obj02345 *)p)->f20 = v;
    if (((struct Obj02345 *)p)->f8 != 0) {
        ((struct Obj02345 *)p)->f8 = 3;
        p[0x24] = 0;
        func_021BD358(*(char * *)&((struct Obj02345 *)p)->f30, 0);
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




void ov208_func_021BDBA0(struct Ov208Scene_021BDBA0 *p)
{
    ov208_func_021BD360(p->mgr);
}




void ov208_func_021BDBAC(struct Ov208Scene_021BDBAC *p, int v)
{
    ov208_func_021BD330(p->mgr, v);
}




void ov208_func_021BDBB8(struct Ov208Scene_021BDBB8 *p, u32 kind)
{
    u32 saved;
    int restore;

    if (p->f10 == 0) {
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




void ov208_func_021BDBEC(struct Ov208Scene_021BDBEC *p, int v)
{
    if (p->f10 == 2) {
        func_021BD378(p->mgr, *p->keyA, v);
        func_021BD378(p->mgr, *p->keyB, v);
    }
}




/*
 * Calls func_021BD3A4 with two fields and the second argument while +0x10 is clear.
 */
void func_021BDC14(char *p, int b)
{
    if (((struct Obj02345 *)p)->f10 == 0)
        func_021BD3A4(*(int *)&((struct Obj02345 *)p)->f30, *(int *)*(int * *)&((struct Obj02345 *)p)->f7C, b);
}




int func_021BDC2C(char *p)
{
    if (((struct Obj09200 *)p)->f10 == 0)
        return func_021BD3B4((void *)(((struct Obj09200 *)p)->f30),
                             *(int *)*(int * *)&((struct Obj09200 *)p)->f7C);
    return 0;
}




void ov208_func_021BDC48(struct Ov208Scene_021BDC48 *p, u32 on)
{
    p->f34 = on;
    if (on != 0) {
        if (func_021BD35C(p->mgr) == 0 && p->f8 == 2)
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




void ov208_func_021BDCF8(struct Ov208Scene_021BDCF8 *p)
{
    switch (p->f10) {
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
        func_021BDFA8((struct Ov208Eff *)p);
        break;
    case 1:
        func_021BE4DC((struct Ov208Eff *)p);
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




void ov208_func_021BDD98(struct Ov208Scene_021BDD48 *p)
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
    list.f8 = p->f28;
    list.fc = 1;
    list.f10 = 0xd;
    list.f14 = 8;
    list.f18 = 2;
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
    func_021BE170((struct Ov208Scene_021BDBB8 *)p);
    if (p->f40 == 0) {
        func_021BD378(p->mgr, p->slots[8].src->id, 0);
        func_021BD378(p->mgr, p->slots[7].src->id, 0);
    }
}



void func_021BDFA8(struct Ov208Eff *e)
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



void func_021BDFDC(struct Ov208Menu *m)
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
        switch (m->mode) {
        case 0:
            if (func_021BD388(m->f30, *m->tab[3].p))
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
        switch (m->mode) {
        case 0:
            sel = 5;
            break;
        case 1:
            sel = 4;
            break;
        case 2:
            if (func_021BD388(m->f30, *m->tab[3].p))
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
        func_021BD3F8(m->f30, *m->tab[sel].p);
    if ((trg & 0xc0) == 0) {
        if (held & 0x40)
            func_021BD3F8(m->f30, *m->tab[8].p);
        else if (held & 0x80)
            func_021BD3F8(m->f30, *m->tab[7].p);
    }
    a = func_021BDB08((const struct State *)m);
    b = func_021BDB54((const struct State *)m);
    if (a != 0) {
        c = func_021BE32C(a);
        d = func_021BE378(a);
        if (c != 9 && d != 4) {
            for (i = 3; i <= 6; i++)
                func_021BD368((int)m->f30, *m->tab[i].p, i != c);
            m->f1c = d;
            func_021BE170((struct Ov208Scene_021BDBB8 *)((struct Ov208Scene_021BDD48 *)m));
        }
    }
    if (b != 0) {
        switch (b) {
        case 15:
        case 16:
        case 17:
        case 18:
            func_021BE1BC((struct Ov208Eff *)m);
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
void func_021BE16C(struct Ov208Eff *e)
{
}
