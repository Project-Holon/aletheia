/*
 * file:     box2_ui.c
 * unit:     yes
 * function: func_021ED824, func_021ED888, func_021ED8A4, func_021ED904, func_021ED918, func_021ED9B4, func_021ED9C8, func_021EDA70, func_021EDAB0, func_021EDB1C, func_021EDB34, func_021EDB64, func_021EDB94, func_021EDBE8, func_021EDC0C, func_021EDD38, func_021EDECC, func_021EDF5C, func_021EDFC4, func_021EE008, func_021EE038, func_021EE0FC, func_021EE120, func_021EE200, func_021EE224, func_021EE234, func_021EE244, func_021EE26C, func_021EE2C4, func_021EE364, func_021EE3CC, func_021EE3E4, func_021EE408, func_021EE418, func_021EE42C, func_021EE43C, func_021EE454, func_021EE470, func_021EE474, func_021EE510, func_021EE520, func_021EE544, func_021EE57C, func_021EE64C, func_021EE65C, func_021EE72C, func_021EE744, func_021EE754, func_021EE7C4, func_021EE7F4, func_021EE850, func_021EE8A8, func_021EE944, func_021EE95C, func_021EE96C, func_021EE9C4, func_021EE9F4, func_021EEA48, func_021EEB18, func_021EEB30, func_021EEB40, func_021EEBDC, func_021EEBF4, func_021EEC04, func_021EEC1C, func_021EEC38, func_021EEC50, func_021EEC6C, func_021EECB0, func_021EECE4, func_021EEDB8, func_021EEDD0, func_021EEDE0, func_021EEE7C, func_021EEE94, func_021EEEA4, func_021EEF50, func_021EEF68, func_021EEF74, func_021EEFA4, func_021EF048, func_021EF0A8, func_021EF108, func_021EF170, func_021EF180, func_021EF194, func_021EF1A4, func_021EF1B4, func_021EF1C4, func_021EF1D4, func_021EF1FC, func_021EF224, func_021EF248, func_021EF264, func_021EF274, func_021EF310, func_021EF31C, func_021EF32C, func_021EF33C, func_021EF34C, func_021EF35C, func_021EF36C, func_021EF3A0, func_021EF3D8, func_021EF3EC, func_021EF400, func_021EF45C, func_021EF480, func_021EF4A4, func_021EF4C0, func_021EF4E4, func_021EF508, func_021EF534, func_021EF57C, func_021EF5C4, func_021EF5E8, func_021EF60C, func_021EF630, func_021EF660, func_021EF670, func_021EF680, func_021EF68C, func_021EF69C, func_021EF6A8, func_021EF6CC, func_021EF6E0, func_021EF738, func_021EF75C, func_021EF770
 * address:  0x021ED824
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021EFD1C 0x021EFD1C data a4
 *   func_021EBEE0 0x021EBEE0 thumb ov170
 *   func_021EC000  0x021EC000  thumb  ov170
 *   func_0202CF98 0x0202CF98 thumb
 *   func_021EC08C 0x021EC08C thumb ov170
 *   func_021EC0B0 0x021EC0B0 thumb ov170
 *   func_020258E8 0x020258E8 thumb
 *   func_0202590C 0x0202590C thumb
 *   func_021DEB14 0x021DEB14 thumb ov170
 *   func_021EB874 0x021EB874 thumb ov170
 *   func_02049E34 0x02049E34 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021DEDCC 0x021DEDCC thumb ov170
 *   g_021EFCEC  0x021EFCEC  data  ov170
 *   func_02007A18  0x02007A18  thumb
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_02082A48  0x02082A48  arm
 *   func_021EC01C 0x021EC01C thumb
 *   d_021EFCD8 0x021EFCD8 data a2
 *   func_02025774 0x02025774 thumb
 *   func_021EB85C  0x021EB85C  thumb  ov170
 *   func_021EBFCC 0x021EBFCC thumb
 *   func_02025538 0x02025538 thumb
 *   func_02043678 0x02043678 arm
 *   func_020255A0 0x020255A0 thumb
 *   func_020257C4  0x020257C4  thumb
 *   func_020355C4 0x020355C4 arm
 *   func_02025CD0 0x02025CD0 thumb
 *   func_02025D1C 0x02025D1C thumb
 *   func_021ED55C 0x021ED55C thumb ov170
 *   d_021F02F0 0x021F02F0 data a4
 *   func_020260F0 0x020260F0 thumb
 *   func_02025D14  0x02025D14  thumb
 *   func_0202616C 0x0202616C thumb
 *   func_021ECC1C  0x021ECC1C  thumb  ov170
 *   func_021DC9B4  0x021DC9B4  thumb  ov170
 *   func_021E066C  0x021E066C  thumb  ov170
 *   func_020260E0 0x020260E0 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_02025DE8 0x02025DE8 thumb
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   d_021F0188  0x021F0188  data
 *   d_021F0DCC  0x021F0DCC  data
 *   d_021F0370  0x021F0370  data
 *   func_0203633C 0x0203633C arm
 *   func_021DD238 0x021DD238 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_02030734 0x02030734 arm
 *   d_021F1418 0x021F1418 data a1
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021F0020 0x021F0020 data a4
 *   func_02035C08 0x02035C08 arm
 *   func_02035BA4 0x02035BA4 arm
 *   func_02035D40 0x02035D40 arm
 *   g_021F0DCC  0x021F0DCC  data  ov170
 *   d_021F0F40 0x021F0F40 data
 *   d_021F0040 0x021F0040 data
 *   func_02035CB8 0x02035CB8 arm
 *   d_021F0034 0x021F0034 data a1
 *   d_021F0024 0x021F0024 data a1
 *   d_021F002C 0x021F002C data a4
 *   d_021F0F58 0x021F0F58 data
 *   func_021EB744 0x021EB744 thumb ov170
 *   func_021EB79C 0x021EB79C thumb ov170
 *   func_021EB7C8 0x021EB7C8 thumb ov170
 *   func_021EB95C 0x021EB95C thumb ov170
 *   func_0202C9B4 0x0202C9B4 thumb
 *   func_0202CA3C 0x0202CA3C thumb
 *   func_0202CA0C  0x0202CA0C  thumb  ov170
 *   func_0202CDD4 0x0202CDD4 thumb
 *   func_021EC8E4 0x021EC8E4 thumb
 *   func_0202CC70 0x0202CC70 thumb
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CD64 0x0202CD64 thumb
 */
#include "box2_types.h"
#include "../../matched/include/Obj24023.h"
#include "../../matched/include/Obj24024.h"
#include "../../matched/include/Obj18524.h"
#include "../../matched/include/Obj24025.h"
#include "../../matched/include/Obj24026.h"
#include "../../matched/include/Obj09226.h"
#include "../../matched/include/Obj01419.h"
#include "../../matched/include/Obj18525.h"
#include "../../matched/include/Obj14282.h"
#include "../../matched/include/Obj24027.h"
#include "../../matched/include/Obj24028.h"
#include "../../matched/include/Obj24029.h"
#include "../../matched/include/Obj24030.h"
#include "../../matched/include/Obj24031.h"
#include "../../matched/include/Obj24032.h"
#include "../../matched/include/Obj24033.h"
#include "../../matched/include/Obj24034.h"
#include "../../matched/include/Obj24035.h"
#include "../../matched/include/Obj18526.h"
#include "../../matched/include/Obj18527.h"
#include "../../matched/include/Obj18528.h"
#include "../../matched/include/Obj24038.h"
#include "../../matched/include/Obj24039.h"
#include "../../matched/include/Obj24040.h"
#include "../../matched/include/Obj18531.h"
#include "../../matched/include/Obj18532.h"
#include "../../matched/include/Obj07241.h"
#include "../../matched/include/Obj12189.h"
#include "../../matched/include/Obj24042.h"
#include "../../matched/include/Obj24043.h"
#include "../../matched/include/Obj24044.h"
#include "../../matched/include/Obj24045.h"

struct WinMgr;
struct Grid;
struct Obj02025774;
struct Personal;
struct Sav;
struct Sub020079BCEntry;
struct Bmp;
struct Sys;
struct Obj020437AC;
struct Struct_02025D1C;
struct Struct_02025CD0;
struct Sound;
struct Ctx;
typedef struct { short x, y; int b, c, d, e; short f, g; } Desc;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short   s16;

typedef unsigned short u16;

typedef unsigned char  u8;

struct Param {void *bmp; short x,y; u32 f8,fc; u8 f10,f11; u16 f12;u32 f14;};

typedef struct { unsigned a, b; } Pair_021EE2C4;

typedef struct { unsigned a; unsigned b; } Pair_021EE364;

typedef struct { unsigned char a, b, pad[10]; } E;

typedef struct {
    int pad[9];
    int x24;
} Top;

typedef struct {
    unsigned char x,y,dx,dy;
    unsigned negx:1;
    unsigned negy:1;
    unsigned steps:30;
} Motion;

typedef struct { unsigned char a,b,c,d; } Bytes;

typedef struct { Bytes first, second; } Object;

extern void *func_021EBEE0(char *, const Desc *);
extern void func_021EC000(char *, int, int);
extern void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern void func_021EC0B0(char *, int, short *, short *, unsigned short);
extern void func_020258E8(struct Obj02025774 *p, s16 *out_x, s16 *out_y);
extern void func_0202590C(struct Grid *g, s16 x, s16 y);
extern unsigned char func_021DEB14(unsigned char *p, int a);
extern void func_021EB874(char **, unsigned, int);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02082D44(const void *, void *, unsigned);
extern u32 func_020307B0(void *p);
extern int func_021DEDCC(char *p, int box);
extern u16 func_0204B7F0(u8 *p);
extern void func_0204AA94(int a, void *b, u32 c, int d, int e);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void *func_0201ADE4(u32 a, int b, u32 c);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern void func_02082A48(u32 value, void *dest, u32 size);
extern u32 func_021EC01C(char *p, int i);
extern void func_02025774(u8 *g, u32 a);
extern void func_021EB85C(unsigned char *p, int i);
extern void func_021EBFCC(char *p, int i, int v);
extern void *func_02025538(u32,void *);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
extern void func_0202570C(struct Grid *g);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02025588(void *p);
extern int func_020257C4(const int *p);
extern u8 func_020355C4(void);
extern struct Struct_02025CD0 *func_02025CD0(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 heapId);
extern void func_02025D1C(struct Struct_02025D1C *obj);
extern void func_021ED55C(char **, int);
extern u32 func_020260F0(struct Sound *obj);
extern void func_02025D14(void);
extern void *func_0202616C(void **obj, u32 idx);
extern void func_021ECC1C(unsigned char *p);
extern void func_021DC9B4(char *p, int v);
extern int func_021E066C(char *p);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern u8 func_020260E0(struct Sound *obj);
extern int func_02025DE8(struct Sound *obj);
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern unsigned int func_0203633C(void);
extern void func_021DD238(char *p);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02035C08(const void *);
extern int func_02035BA4(const void *);
extern u32 func_02035D40(struct Ctx *ctx, u32 a, u32 b);
extern unsigned func_02035CB8(unsigned *outA, unsigned *outB);
extern struct WinMgr *func_0202C9B4(u32 a0, u32 a1, u32 heap);
extern void func_0202CA3C(struct WinMgr *mgr, u32 idx, u32 bg, u32 w, u32 h);
extern void func_021EB744(char *);
extern void func_021EB79C(unsigned char *p);
extern void func_021EB7C8(char *);
extern void func_021EB95C(char *);
extern void func_0202CA0C(struct WinMgr *mgr);
extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern u32 func_0202CDD4(struct WinMgr *mgr, u32 idx);
extern void func_021EC8E4(char *p);
extern void func_0202CC70(struct WinMgr *mgr, u32 idx);
extern u32 func_0204162C(int channel);
extern void func_0202CAC4(struct WinMgr *mgr, u32 idx, const void *src);
void func_021ED824(char *p);
void func_021ED888(char *p, int a);
void func_021ED8A4(char *p);
void func_021ED904(unsigned char *p);
void func_021ED918(char *p, int d);
void func_021ED9B4(int a);
void func_021ED9C8(char *p);
void func_021EDA70(int a0, int a1, short *a2, short *a3);
void func_021EDAB0(char *p, int i);
void func_021EDB1C(int p);
void func_021EDB34(char *p, int a);
void func_021EDB64(char *p, int a, int i);
void func_021EDB94(char *p, int a, int b);
void func_021EDBE8(int x0, unsigned char *a, unsigned c, unsigned char d, unsigned n);
void func_021EDC0C(int **a, int box, u8 *dest);
void func_021EDD38(char *p, int d);
void func_021EDECC(unsigned char *p, int d);
void func_021EDF5C(unsigned char *p);
void func_021EDFC4(char *p, int i);
void func_021EE008(char *p, int a, int b);
void func_021EE038(char *p, int a, int b, int c);
void func_021EE0FC(char *p);
void func_021EE120(char *p);
void func_021EE200(char *p);
void func_021EE224(char *p, int i, int v);
int func_021EE234(int *a, int i);
void func_021EE244(char *p, int i, int flag);
void func_021EE26C(char *p, int d);
void func_021EE2C4(char **p);
void func_021EE364(char **p, int idx, int v);
void func_021EE3CC(int *p);
void func_021EE3E4(char **p, unsigned idx);
void func_021EE408(char *p, int v);
void func_021EE418(char *p, int v);
void func_021EE42C(char *p);
void func_021EE43C(char *p, int a, int b);
void func_021EE454(char *p, unsigned int a);
void func_021EE470(void);
unsigned func_021EE474(char *p);
void func_021EE510(void *a, int tag);
void func_021EE520(char *p, unsigned idx);
void func_021EE544(char *p, unsigned int i);
unsigned func_021EE57C(char *p);
void func_021EE64C(void *a, int tag);
unsigned func_021EE65C(char *p);
void func_021EE72C(char *p, int a, int b);
void func_021EE744(void *a, int tag);
void func_021EE754(unsigned char *p, unsigned r);
void func_021EE7C4(char *p, int a, int b);
void func_021EE7F4(char *p, unsigned r);
unsigned func_021EE850(char *p);
unsigned func_021EE8A8(char *p);
void func_021EE944(char *p, int a, int b);
void func_021EE95C(void *a, int tag);
unsigned func_021EE96C(char *p);
void func_021EE9C4(char *p, int a, int b);
void func_021EE9F4(char *p, unsigned r);
unsigned func_021EEA48(char *p);
void func_021EEB18(char *p, int a, int b);
void func_021EEB30(void *a, int tag);
unsigned func_021EEB40(char *p);
void func_021EEBDC(char *p, int a, int b);
void func_021EEBF4(void *a, int tag);
void func_021EEC04(char *p, int a, int b);
void func_021EEC1C(char *p, unsigned int a);
void func_021EEC38(char *p, int a, int b);
void func_021EEC50(char *p, unsigned int a);
void func_021EEC6C(char *p, int k, int v);
void func_021EECB0(char *p, int a);
unsigned func_021EECE4(char *p);
void func_021EEDB8(char *p, int a, int b);
void func_021EEDD0(void *a, int tag);
unsigned func_021EEDE0(char *p);
void func_021EEE7C(char *p, int a, int b);
void func_021EEE94(void *a, int tag);
unsigned func_021EEEA4(char *p);
void func_021EEF50(char *p, int a, int b);
void func_021EEF68(char *a, int b);
void func_021EEF74(char *q, int a, int b);
void func_021EEFA4(char *p, unsigned char x, unsigned char y, unsigned char tx, unsigned char ty);
int func_021EF048(const char *p, unsigned n);
int func_021EF0A8(const char *p, unsigned n);
int func_021EF108(const char *p, unsigned n, int a, int b);
u32 func_021EF170(void);
int func_021EF180(int a, int b);
u32 func_021EF194(void);
u32 func_021EF1A4(void);
int func_021EF1B4(void);
int func_021EF1C4(void);
int func_021EF1D4(unsigned *a, unsigned *b);
int func_021EF1FC(unsigned*a,unsigned*b);
int func_021EF224(int a, int b);
int func_021EF248(void);
int func_021EF264(void);
void func_021EF274(char *p);
void func_021EF310(char *p);
void func_021EF31C(struct WinMgr *mgr, int a1, int a2);
void func_021EF32C(struct WinMgr *mgr);
void func_021EF33C(struct WinMgr *mgr);
void func_021EF34C(struct WinMgr *mgr);
void func_021EF35C(struct WinMgr *mgr);
void func_021EF36C(struct WinMgr *mgr);
void func_021EF3A0(struct WinMgr *mgr);
void func_021EF3D8(struct WinMgr *mgr);
void func_021EF3EC(struct WinMgr *mgr);
int func_021EF400(unsigned char *p);
int func_021EF45C(struct WinMgr *mgr);
int func_021EF480(struct WinMgr *mgr);
int func_021EF4A4(struct WinMgr *mgr);
void func_021EF4C0(struct WinMgr *mgr);
void func_021EF4E4(struct WinMgr *mgr);
void func_021EF508(struct WinMgr *mgr);
void func_021EF534(struct WinMgr *mgr);
void func_021EF57C(struct WinMgr *mgr);
int func_021EF5C4(struct WinMgr *mgr);
int func_021EF5E8(struct WinMgr *mgr);
int func_021EF60C(struct WinMgr *mgr);
void func_021EF630(char *p);
void func_021EF660(struct WinMgr *mgr);
void func_021EF670(char *p);
void func_021EF680(char *p);
void func_021EF68C(char *p);
void func_021EF69C(char *p);
void func_021EF6A8(struct WinMgr *mgr);
void func_021EF6CC(struct WinMgr *mgr);
unsigned func_021EF6E0(char *p);
void func_021EF738(struct WinMgr *mgr);
void func_021EF75C(struct WinMgr *mgr);
extern const Desc d_021EFD1C;
extern const unsigned char g_021EFCEC[];
extern const short d_021EFCD8[];
extern const Pair_021EE2C4 d_021F02F0[];
extern const unsigned char d_021F0188[];
extern E d_021F0DCC[];
extern E d_021F0370[];
extern const char d_021F1418[];
extern const Bytes d_021F0020;
extern const unsigned char d_021F0F40[];
extern const unsigned char d_021F0040[];
extern const unsigned char d_021F0034[];
extern const u8 d_021F0024[];
extern const unsigned char d_021F002C[];
extern const unsigned char d_021F0F58[];






void func_021ED824(char *p)
{
    Desc t;
    Desc base = d_021EFD1C;
    unsigned i;
    for (i = 0; i < 6; i++) {
        t = base;
        t.y += (short)(i * 0x22);
        t.c = i + 0x39;
        *(void **)(p + i * 4 + 0x9f28) = func_021EBEE0(p, &t);
    }
}






/*
 * Release slots 0 and 1 of the 0x9E74 array.
 */
void func_021ED888(char *p, int a)
{
    func_021EC000(p, 0, a);
    func_021EC000(p, 1, a);
}






void func_021ED8A4(char *p)
{
    signed char t[2];
    unsigned i;
    short x, y;
    func_0202CF98(*(struct WinMgr * *)&((struct Obj24023 *)(*(char * *)&((BoxTask *)p)->f2C))->f74, 7, &t[1], &t[0]);
    i = 0;
    y = t[0] * 8 + 8;
    x = t[1] * 8 + 0x17;
    for (; i < 6; i++)
        func_021EC08C(*(char * *)&((BoxTask *)p)->f2C, i + 0xd, (short)(x + (i % 2) * 0x20), (short)(y + (i / 2) * 0x18), (short)0);
}






/*
 * Seat one entry, then re-sort.
 */
void func_021ED904(unsigned char *p)
{
    func_021EDAB0((char *)p, p[0x14]);
    func_021ED9C8((char *)p);
}






/*
 * extent: Two trailing zero bytes at 0x021ED9B2 are alignment padding.
 */
void func_021ED918(char *p, int d)
{
    short t[2];
    int i = 0;
    func_021EC0B0(*(char * *)&((BoxTask *)p)->f2C, 2, &t[1], &t[0], 0);
    func_021EC08C(*(char * *)&((BoxTask *)p)->f2C, 2, (short)(t[1] - d), (short)t[0], (short)0);
    for (; i < 6u; i++) {
        func_021EC0B0(*(char * *)&((BoxTask *)p)->f2C, i + 0x2d, &t[1], &t[0], 0);
        func_021EC08C(*(char * *)&((BoxTask *)p)->f2C, i + 0x2d, (short)(t[1] - d), (short)t[0], (short)0);
        func_020258E8(*(void **)(*(char * *)&((BoxTask *)p)->f2C + i * 8 + 0xc), &t[1], &t[0]);
        func_0202590C(*(void **)(*(char * *)&((BoxTask *)p)->f2C + i * 8 + 0xc), t[1] - d, t[0]);
    }
}






/*
 * One range call with fixed arguments.
 */
void func_021ED9B4(int a)
{
    func_021EC08C((char *)a, 2, 0x4b * 4, 0x22, 0);
}






void func_021ED9C8(char *p)
{
    Desc t;
    Desc base = d_021EFD1C;
    short i;
    int a, y;
    for (i = 0; i < 6; i++) {
        a = func_021DEB14((unsigned char *)p, (signed char)(i - 1));
        t = base;
        y = i * 0x22;
        t.y += (short)y;
        func_021EC08C(*(char * *)&((BoxTask *)p)->f2C, i + 0x2d, t.x, t.y, 0);
        func_021EDB64(p, a, i + 0x2d);
        func_0202590C(*(void **)(*(char * *)&((BoxTask *)p)->f2C + i * 8 + 0xc), 0x13c, y + 2);
        func_021EB874((char **)p, a, i + 1);
    }
}






/*
 * Scan six 0x2d-spaced panel rows for the (a1+1)*0x22 key and clear
 *   both shorts when nothing matched.  The key must be written as an
 *   ASSIGNMENT TO THE PARAMETER,
 *       a1 = (a1 + 1) * 0x22;
 *   then tested as `if (a1 == a3[0])`.  A separate `int k = ...` local
 *   loses the image's two-instruction parameter home (r6 = a1, r1 =
 *   r6+1, r6 = r1, muls r6) and swaps a2/a3 between r6 and r7.
 */
void func_021EDA70(int a0, int a1, short *a2, short *a3)
{
    unsigned i;
    a1 = (a1 + 1) * 0x22;
    for (i = 0; i < 6; i++) {
        func_021EC0B0((char *)a0, i + 0x2d, a2, a3, 0);
        if (a1 == a3[0])
            return;
    }
    *a2 = 0;
    *a3 = 0;
}






void func_021EDAB0(char *p, int i)
{
    void *t;
    void *q = func_02049E34(0x74, 0x47, 1, (u32)(&t), 0x4c);
    func_02082D44(((struct Obj24024 *)t)->f14, *(char * *)&((BoxTask *)p)->f2C + 0x3e70 + i * 0x400, 0x400);
    func_020307B0(q);
    func_021EDBE8((int)p, (unsigned char *)(*(char * *)&((BoxTask *)p)->f2C + 0x3e70 + i * 0x400), func_021DEDCC((char *)p, i), 8, 0x400);
    func_021EDC0C((int **)p, i, (unsigned char *)(*(char * *)&((BoxTask *)p)->f2C + 0x3e70 + i * 0x400));
}






/*
 * Clear all 24 entries.
 */
void func_021EDB1C(int p)
{
    unsigned i;
    for (i = 0; i < 24; i++)
        func_021EDAB0((char *)p, i);
}






/*
 * Scan channels -1..4 for the one that reports a; on a hit run the
 *   sub-range call with the channel index.  The compared result must live in a
 *   LOCAL, or mwccarm emits `cmp r5,r0` where the image has `cmp r0,r5`.
 */
void func_021EDB34(char *p, int a)
{
    short i;
    for (i = 0; i < 6; i++) {
        unsigned char c = func_021DEB14((unsigned char *)p, (signed char)(i - 1));
        if (c != a)
            continue;
        func_021EDB94(p, a, i);
        return;
    }
}






/*
 * Detach slot i then hand the a*0x400 span of the 0x3E70 pool to
 *   the 0x400/0/0 emitter.
 */
void func_021EDB64(char *p, int a, int i)
{
    int q = ((struct Obj18524 *)p)->f2C;
    int x = func_0204B7F0((u8 *)(*(int *)(q + i * 4 + 0x9E74)));
    func_0204AA94(x, (void *)(q + 0x3E70 + a * 0x400), 0x400, 0, 0);
}






/*
 * extent: Two trailing zero bytes at 0x021EDBE6 are alignment padding.
 */
void func_021EDB94(char *p, int a, int b)
{
    short t[2];
    int i = 0;
    b *= 0x22;
    for (; i < 6u; i++) {
        func_021EC0B0(*(char * *)&((BoxTask *)p)->f2C, i + 0x2d, &t[1], &t[0], 0);
        if (b == t[0]) {
            func_021EDB64(p, a, i + 0x2d);
            func_021EB874((char **)p, a, i + 1);
            return;
        }
    }
}






void func_021EDBE8(int x0, unsigned char *a, unsigned c, unsigned char d, unsigned n)
{
    unsigned i;
    for (i = 0; i < n; i++)
        if (a[i] == d)
            a[i] = g_021EFCEC[c];
}







/*
 * lever: the u16 fill value reuses the colour-index local t (t = (u16)((t << 8) | t));
 *   a separate v local takes the spill slot above ty instead of below it.
 */
void func_021EDC0C(int **a, int box, u8 *dest)
{
    void *e;
    u32 sv;
    u8 y, x, tx, ty;
    u8 i;
    u32 sp, t;
    u16 form;
    for (ty = 11, y = 0; y < 5; ty += 2, y++) {
        tx = 10;
        for (x = 0; x < 6; tx += 2, x++) {
            e = func_02007A18((void *)(*a)[1], box, x + y * 6);
            sv = func_02017DBC(e);
            sp = func_02017E88(e, 5, 0);
            if (func_02017E88(e, 0xa9, 0)) {
                if (func_02017E88(e, 0x4c, 0) == 0) {
                    void *pd;
                    form = func_02017E88(e, 0x6f, 0);
                    pd = func_0201ADE4((u16)sp, form, 0x4c);
                    t = (u16)func_0201AE1C(pd, 0x21);
                    func_0201AE14(pd);
                } else {
                    t = (sp == 490) ? 1 : 8;
                }
                t = (u16)(t + 16);
                t = (u16)((t << 8) | t);
                for (i = ty; i < ty + 2; i++)
                    func_02082A48(t, dest + ((((i & 7) << 3) + ((((i >> 3) << 2) + (tx >> 3)) << 6)) + (tx & 7)), 2);
            }
            func_02017DE4(e, sv);
        }
    }
}







void func_021EDD38(char *p, int d)
{
    short t[4];
    int step;
    int i;
    short x, y;
    int k;
    step = ((d < 0 ? -d : d) == 5) ? 2 : 8;
    if (d < 0)
        step *= -1;
    for (i = 0; i < 6u; i++) {
        func_021EC0B0(*(char * *)&((BoxTask *)p)->f2C, i + 0x2D, &t[3], &t[2], 0);
        x = t[2] + step;
        func_021EC08C(*(char * *)&((BoxTask *)p)->f2C, i + 0x2D, (short)t[3], (short)x, (short)0);
        func_020258E8(*(void **)(*(char * *)&((BoxTask *)p)->f2C + i * 8 + 0xC), &t[1], &t[0]);
        y = t[0] + step;
        func_0202590C(*(void **)(*(char * *)&((BoxTask *)p)->f2C + i * 8 + 0xC), t[1], y);
        if (x < -0x10) {
            k = func_021DEB14((unsigned char *)p, 4);
            func_021EDB64(p, k, i + 0x2D);
            func_021EC08C(*(char * *)&((BoxTask *)p)->f2C, i + 0x2D, (short)t[3], (short)(x + 0xCC), (short)0);
            func_021EB874((char **)p, k, i + 1);
            func_0202590C(*(void **)(*(char * *)&((BoxTask *)p)->f2C + i * 8 + 0xC), t[1], y + 0xCC);
        } else if (x >= 0xBA) {
            k = func_021DEB14((unsigned char *)p, -1);
            func_021EDB64(p, k, i + 0x2D);
            func_021EC08C(*(char * *)&((BoxTask *)p)->f2C, i + 0x2D, (short)t[3], (short)(x - 0xCC), (short)0);
            func_021EB874((char **)p, k, i + 1);
            func_0202590C(*(void **)(*(char * *)&((BoxTask *)p)->f2C + i * 8 + 0xC), t[1], y - 0xCC);
        }
    }
    if (func_021EC01C(*(char * *)&((BoxTask *)p)->f2C, 2) == 1) {
        func_021EC0B0(*(char * *)&((BoxTask *)p)->f2C, 2, &t[3], &t[2], 0);
        func_021EC08C(*(char * *)&((BoxTask *)p)->f2C, 2, (short)t[3], (short)(t[2] + step), (short)0);
    }
}






void func_021EDECC(unsigned char *p, int d)
{
    short t[2];
    if (d < 0 && p[0x14] == func_021DEB14(p, -1)) {
        func_021EC0B0(*(char * *)&((BoxTask *)p)->f2C, 2, &t[1], &t[0], 0);
        func_021EC08C(*(char * *)&((BoxTask *)p)->f2C, 2, t[1], -0x22, 0);
        func_021EC000(*(char * *)&((BoxTask *)p)->f2C, 2, 1);
        return;
    }
    if (d > 0 && p[0x14] == func_021DEB14(p, 4)) {
        func_021EC0B0(*(char * *)&((BoxTask *)p)->f2C, 2, &t[1], &t[0], 0);
        func_021EC08C(*(char * *)&((BoxTask *)p)->f2C, 2, t[1], 0xcc, 0);
        func_021EC000(*(char * *)&((BoxTask *)p)->f2C, 2, 1);
    }
}







void func_021EDF5C(unsigned char *p)
{
    unsigned i;
    short xy[2];
    for (i = 0; i < 6; i++) {
        if (p[0x14] == func_021DEB14(p, (signed char)(i - 1))) {
            func_021EC0B0(*(char * *)&((BoxTask *)p)->f2C, 2, &xy[1], &xy[0], 0);
            func_021EC08C(*(char * *)&((BoxTask *)p)->f2C, 2, (short)xy[1], (short)(i * 0x22), (short)0);
            func_021EC000(*(char * *)&((BoxTask *)p)->f2C, 2, 1);
            return;
        }
    }
    func_021EC000(*(char * *)&((BoxTask *)p)->f2C, 2, 0);
}






void func_021EDFC4(char *p, int i)
{
    short y = d_021EFCD8[i];
    func_021EC08C(*(char * *)&((BoxTask *)p)->f2C, 3, 0xce, y, 0);
    func_021EC000(*(char * *)&((BoxTask *)p)->f2C, 3, 1);
    func_0202590C(((struct Obj24025 *)(*(char * *)&((BoxTask *)p)->f2C))->f4, 0x9e, y - 8);
    func_02025774(((struct Obj24026 *)(*(char * *)&((BoxTask *)p)->f2C))->f4, 1);
}






/*
 * Two-way: with flag 1 run the pair update, otherwise release slot 3
 *   and post 0 to the p+0x2c+4 object.
 */
void func_021EE008(char *p, int a, int b)
{
    if (b == 1) {
        func_021EB85C((unsigned char *)p, a);
        func_021EDFC4(p, a);
        return;
    }
    func_021EC000((char *)(*(int *)&((BoxTask *)p)->f2C), 3, 0);
    func_02025774((u8 *)(*(int *)(*(int *)&((BoxTask *)p)->f2C + 4)), 0);
}







void func_021EE038(char *p, int a, int b, int c)
{
    p[0x1F] = a;
    p[0x20] = b;
    p[0x21] = c;
    if (a == 0) {
        func_021EC000(*(char * *)&((BoxTask *)p)->f2C, 6, 1);
        func_021EBFCC(*(char * *)&((BoxTask *)p)->f2C, 6, 1);
    } else if (a == 1) {
        func_021EC000(*(char * *)&((BoxTask *)p)->f2C, 6, 0);
    } else {
        func_021EC000(*(char * *)&((BoxTask *)p)->f2C, 6, 1);
        func_021EBFCC(*(char * *)&((BoxTask *)p)->f2C, 6, 0xF);
    }
    if (b == 0) {
        func_021EC000(*(char * *)&((BoxTask *)p)->f2C, 7, 1);
        func_021EBFCC(*(char * *)&((BoxTask *)p)->f2C, 7, 0);
    } else if (b == 1) {
        func_021EC000(*(char * *)&((BoxTask *)p)->f2C, 7, 0);
    } else {
        func_021EC000(*(char * *)&((BoxTask *)p)->f2C, 7, 1);
        func_021EBFCC(*(char * *)&((BoxTask *)p)->f2C, 7, 0xE);
    }
    if (c == 0) {
        func_021EC000(*(char * *)&((BoxTask *)p)->f2C, 8, 1);
        func_021EBFCC(*(char * *)&((BoxTask *)p)->f2C, 8, 0);
    } else if (c == 1) {
        func_021EC000(*(char * *)&((BoxTask *)p)->f2C, 8, 0);
    } else {
        func_021EC000(*(char * *)&((BoxTask *)p)->f2C, 8, 1);
        func_021EBFCC(*(char * *)&((BoxTask *)p)->f2C, 8, 2);
    }
}






/*
 * Release slots 6, 7 and 8 of the 0x9E74 array.
 */
void func_021EE0FC(char *p)
{
    func_021EC000((char *)(((struct Obj09226 *)p)->f2C), 6, 0);
    func_021EC000((char *)(((struct Obj09226 *)p)->f2C), 7, 0);
    func_021EC000((char *)(((struct Obj09226 *)p)->f2C), 8, 0);
}






void func_021EE120(char *p)
{
    struct Param s;
    u32 i;
    ((BoxWork *)p)->f0=func_02025538(76,((struct Obj01419 *)p)->f9E70);
    ((BoxWork *)p)->f8=func_02043678(12,2,32,76);
    s.bmp=((BoxWork *)p)->f8;s.x=0;s.y=0;
    s.f8=((BoxWork *)p)->fA120;s.fc=0;
    s.f10=4;s.f11=1;s.f12=65535;s.f14=0;
    ((BoxWork *)p)->f4=func_020255A0(((BoxWork *)p)->f0,&s);
    func_02025774(((BoxWork *)p)->f4,0);
    for (i=7;i<=8;i++) {
        ((void **)(p+4))[i*2+1]=func_02043678(12,2,32,76);
        s.bmp=((void **)(p+4))[i*2+1];s.x=36;s.y=20;s.f11=3;
        ((void **)(p+4))[i*2]=func_020255A0(((BoxWork *)p)->f0,&s);
    }
    for (i=0;i<6;i++) {
        ((void **)(p+4))[(i+1)*2+1]=func_02043678(2,1,32,76);
        s.bmp=((void **)(p+4))[(i+1)*2+1];s.x=316;s.y=i*34+2;s.f11=1;
        ((void **)(p+4))[(i+1)*2]=func_020255A0(((BoxWork *)p)->f0,&s);
    }
}





void func_021EE200(char *p)
{
    unsigned i;
    for (i = 0; i < 9; i++) {
        func_0202570C((struct Grid *)(*(int *)(p + i * 8 + 4)));
        func_020437AC((struct Obj020437AC *)(*(int *)(p + i * 8 + 8)));
    }
    func_02025588((void *)(((struct Obj18525 *)p)->f0));
}






void func_021EE224(char *p, int i, int v)
{
    func_02025774((u8 *)(*(int *)(p + i * 8 + 4)), v);
}






/*
 *   func_020257C4 (0x020257C4) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
int func_021EE234(int *a, int i)
{
    return func_020257C4((const int *)(*(int *)((char *)a + i * 8 + 4)));
}






void func_021EE244(char *p, int i, int flag)
{
    if (flag == 0)
        func_0202590C(*(void **)(p + i * 8 + 4), -0x94, 0x14);
    else
        func_0202590C(*(void **)(p + i * 8 + 4), 0xDC, 0x14);
}






void func_021EE26C(char *p, int d)
{
    unsigned i;
    short x;
    short y;
    for (i = 7; i <= 8; i++) {
        char *e = p + i * 8;
        func_020258E8(((struct Obj14282 *)e)->f4, &x, &y);
        func_0202590C(((struct Obj14282 *)e)->f4, x + d, y);
        if (x + d == -0x94 || x + d == 0xDC)
            func_021EE224(p, i, 0);
    }
}





void func_021EE2C4(char **p)
{
    int f;
    int i;
    f = func_020355C4() == 1 ? 0 : 1;
    switch (((struct Obj24027 *)(p[0]))->f24) {
    case 0: i = 0; break;
    case 1: i = 2; break;
    case 2: i = 3; break;
    case 3: i = 7; break;
    case 4: i = 13; break;
    case 5: i = 15; break;
    }
    func_021EE3CC((int *)p);
    ((struct Obj24028 *)(p[11]))->f70 = func_02025CD0(d_021F02F0[i].a, d_021F02F0[i].b, (u32)p, f, ((unsigned *)p)[9], 0x4c);
    func_02025D1C(((struct Obj24029 *)(p[11]))->f70);
    func_021EE408((char *)p, ((int *)p)[9]);
    func_021ED55C(p, f);
    ((struct Obj24030 *)(p[11]))->fA168 = ((int *)p)[9];
}






void func_021EE364(char **p, int idx, int v)
{
    int r = func_020260F0(((struct Obj24031 *)(p[11]))->f70);
    func_021EE3CC((int *)p);
    ((struct Obj24032 *)(p[11]))->f70 = func_02025CD0(d_021F02F0[idx].a, d_021F02F0[idx].b, (u32)p, r, v, 0x4C);
    func_02025D1C(((struct Obj24033 *)(p[11]))->f70);
    func_021EE408((char *)p, v);
    func_021ED55C(p, r);
    ((struct Obj24034 *)(p[11]))->fA168 = v;
}






/*
 *   func_02025D14 (0x02025D14) stays wildcarded because the target is an
 *   unlabelled leaf emitted inside a .word run -- no traced func_ start,
 *   no branch outside this range, no literal pool word elsewhere, so
 *   `label` and `sole-ref/code` both refuse.  Evidence class: label /
 *   sole-ref/code (target not a traced function start).
 */
void func_021EE3CC(int *p)
{
    if (*(int *)(*(int *)&((BoxTask *)p)->f2C + 0x70)) {
        func_02025D14();
        *(int *)(*(int *)&((BoxTask *)p)->f2C + 0x70) = 0;
    }
}





void func_021EE3E4(char **p, unsigned idx)
{
    unsigned char *c = func_0202616C(((struct Obj24035 *)(p[11]))->f70, idx);
    func_021EC08C(p[11], 4, c[0], c[1], 0);
}




/*
 * Update the sub-object, then rebuild the panel.
 */
void func_021EE408(char *p, int v)
{
    func_021EE3E4((char **)p, v);
    func_021ECC1C((unsigned char *)p);
}


/*
 * Run the frame update, then release slot 4 with force 1.
 */
void func_021EE418(char *p, int v)
{
    func_021EE408(p, v);
    func_021EC000((char *)(((struct Obj18526 *)p)->f2C), 4, 1);
}


void func_021EE42C(char *p)
{
    func_021EC000((char *)(((struct Obj18526 *)p)->f2C), 4, 0);
}




/*
 * Release the child at +0x2c and reset its field +0x5c to the handler.
 */
void func_021EE43C(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((BoxTask *)p)->f2C, a, b);
    func_021DC9B4(((BoxTask *)p)->f2C, (int)((void *)&func_021E066C));
}



/*
 * Twin of func_021EEC1C.
 */
void func_021EE454(char *p, unsigned int a)
{
    func_020260E4((struct Sound *)(*(int *)(((struct Obj18527 *)p)->f2C + 0x70)), (unsigned char)a);
    func_021EE408(p, a);
}



void func_021EE470(void) {}




#define OBJ(p) (*(void **)(WORK(p) + 0x70))





#define WORK(p) (*(char **)((p) + 0x2C))







unsigned func_021EE474(char *p)
{
    unsigned char sel = func_020260E0(*(void **)(WORK(p) + 0x70));
    unsigned r = func_02025DE8(*(void **)(WORK(p) + 0x70));

    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r >= 8 && r <= 12) {
            func_020260E4(*(void **)(WORK(p) + 0x70), sel);
            func_021EE408(p, sel);
            return -1;
        }
        if (func_020362DC() & 0x400) {
            func_020355D8(0);
            return 6;
        }
        if (r == 6) {
            func_020355D8(1);
            return 6;
        }
        if (r == 7) {
            func_020260E4(*(void **)(WORK(p) + 0x70), sel);
            return 7;
        }
    } else if (r - 6 <= 1) {
        func_020260E4(*(void **)(WORK(p) + 0x70), sel);
        func_021EE408(p, sel);
        return -1;
    }
    return r;
}








/*
 * Ignore the two known tags, otherwise run the update.
 */
void func_021EE510(void *a, int tag)
{
    if (tag != 0x6 && tag != 0x7)
        func_021EE408(a, tag);
}







/*
 * Hand the two tag bytes of the p+0x2c+0x70 object to the 0x54/0x10
 * emitter.
 */
void func_021EE520(char *p, unsigned idx)
{
    unsigned char *q = func_0202616C(*(void ** *)&((struct Obj18528 *)(*(char * *)&((BoxTask *)p)->f2C))->f70, idx);
    func_021EEFA4((char *)(*(int *)&((BoxTask *)p)->f2C), 0x54, 0x10, q[0], q[1]);
}






void func_021EE544(char *p, unsigned int i)
{
    E *e; const unsigned char *g = d_021F0188;
    if (i < 0x1e) { e = &d_021F0DCC[i]; } else { e = &d_021F0370[i - 0x1e]; }
    func_021EEFA4(*(char **)(p + 0x2c), e->a, e->b, g[0], g[1]);
}







unsigned func_021EE57C(char *p)
{
    unsigned char sel = func_020260E0(OBJ(p));
    unsigned r = func_02025DE8(OBJ(p));
    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r >= 0x23 && r <= 0x27) {
            func_020260E4(OBJ(p), sel);
            func_021EE408(p, sel);
            return -1;
        }
        if (func_020362DC() & 0x400) {
            func_020355D8(0);
            return 0x21;
        }
        if (r == 0x21) {
            func_020355D8(1);
            return 0x21;
        }
        if (r == 0x22) {
            func_020260E4(OBJ(p), sel);
            return 0x22;
        }
    } else if (r - 0x21 <= 1) {
        func_020260E4(OBJ(p), sel);
        func_021EE408(p, sel);
        return -1;
    }
    if (r == -1) {
        if (func_0203633C() & 0x200) {
            func_021DD238(p);
            return 0x1F;
        }
        if (func_0203633C() & 0x100) {
            func_021DD238(p);
            return 0x20;
        }
    }
    return r;
}







void func_021EE64C(void *a, int tag)
{
    if (tag != 0x21 && tag != 0x22)
        func_021EE408(a, tag);
}







unsigned func_021EE65C(char *p)
{
    unsigned char sel = func_020260E0(OBJ(p));
    unsigned r = func_02025DE8(OBJ(p));
    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r >= 0x24 && r <= 0x29) {
            func_020260E4(OBJ(p), sel);
            func_021EE408(p, sel);
            return -1;
        }
        if (func_020362DC() & 0x400) {
            func_020355D8(0);
            return 0x22;
        }
        if (r == 0x22) {
            func_020355D8(1);
            return 0x22;
        }
        if (r == 0x23) {
            func_020260E4(OBJ(p), sel);
            return 0x23;
        }
    } else if (r - 0x21 <= 2) {
        func_020260E4(OBJ(p), sel);
        func_021EE408(p, sel);
        return -1;
    }
    if (r == -1) {
        if (func_0203633C() & 0x200) {
            func_021DD238(p);
            return 0x1F;
        }
        if (func_0203633C() & 0x100) {
            func_021DD238(p);
            return 0x20;
        }
    }
    return r;
}







void func_021EE72C(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((BoxTask *)p)->f2C, a, b);
    func_021DC9B4(((BoxTask *)p)->f2C, (int)((void *)&func_021E066C));
}







void func_021EE744(void *a, int tag)
{
    if (tag != 0x22 && tag != 0x23)
        func_021EE408(a, tag);
}







void func_021EE754(unsigned char *p, unsigned r)
{
    int a = 0;
    int f = 0;
    if (p[0x18] == 1) {
        a = 2;
        if ((*(Top * *)&((BoxTask *)p)->f0)->x24 == 3)
            f = 1;
    } else if ((*(Top * *)&((BoxTask *)p)->f0)->x24 == 3) {
        f = 1;
    } else if (r >= 0x1E) {
        if (func_021EF45C(*(struct WinMgr * *)&((struct Obj24038 *)(*(char * *)&((BoxTask *)p)->f2C))->f74) == 0 || func_021DD25C((void ***)p, r, p[0x14], 0xA9, a) == 0)
            f = 2;
    } else {
        if (func_021DD25C((void ***)p, r, p[0x14], 0xA9, a) == 0)
            f = 2;
    }
    func_021EE038((char *)p, a, 1, f);
}






/*
 * Stage the pair, forward it, re-key the queue with the
 *   0x021E066D selector and record the first argument at 0xA168.
 */
void func_021EE7C4(char *p, int a, int b)
{
    func_021EE754((unsigned char *)p, a);
    func_021EEF74((char *)(*(int *)&((BoxTask *)p)->f2C), a, b);
    func_021DC9B4((char *)(*(int *)&((BoxTask *)p)->f2C), 0x021E066D);
    *(int *)(*(int *)&((BoxTask *)p)->f2C + 0xA168) = a;
}




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2c))





void func_021EE7F4(char *p, unsigned r)
{
    if (r - 0x1f <= 1) {
        func_020260E4(*(void **)(WORK(p) + 0x70), 0x1e);
        r = 0x1e;
    } else if (r == 0x21 || r == 0x26 || r - 0x28 <= 2) {
        func_020260E4(*(void **)(WORK(p) + 0x70), *(unsigned *)(WORK(p) + 0xa168));
        r = *(unsigned *)(WORK(p) + 0xa168);
    } else {
        func_021EE408(p, r);
    }
    func_021EE754((unsigned char *)p, r);
    *(unsigned *)(WORK(p) + 0xa168) = r;
}






unsigned func_021EE850(char *p)
{
    unsigned r = func_02025DE8(((struct Obj24039 *)(*(char * *)&((BoxTask *)p)->f2C))->f70);
    if (r == -1) {
        if (func_020362DC() & 0x800) {
            func_021DD238(p);
            return 0x28;
        }
        if (func_0203633C() & 0x200) {
            func_021DD238(p);
            return 0x1F;
        }
        if (func_0203633C() & 0x100) {
            func_021DD238(p);
            return 0x20;
        }
    }
    return r;
}





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))






unsigned func_021EE8A8(char *p)
{
    unsigned char sel = func_020260E0(*(void **)(WORK(p) + 0x70));
    unsigned r = func_02025DE8(*(void **)(WORK(p) + 0x70));

    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r >= 9 && r <= 14) {
            func_020260E4(*(void **)(WORK(p) + 0x70), sel);
            func_021EE408(p, sel);
            return -1;
        }
        if (func_020362DC() & 0x400) {
            func_020355D8(0);
            return 7;
        }
        if (r == 7) {
            func_020355D8(1);
            return 7;
        }
        if (r == 8) {
            func_020260E4(*(void **)(WORK(p) + 0x70), sel);
            return 8;
        }
    } else if (r - 6 <= 2) {
        func_020260E4(*(void **)(WORK(p) + 0x70), sel);
        func_021EE408(p, sel);
        return -1;
    }
    return r;
}






void func_021EE944(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((BoxTask *)p)->f2C, a, b);
    func_021DC9B4(((BoxTask *)p)->f2C, (int)((void *)&func_021E066C));
}






void func_021EE95C(void *a, int tag)
{
    if (tag != 0x7 && tag != 0x8)
        func_021EE408(a, tag);
}






unsigned func_021EE96C(char *p)
{
    unsigned r = func_02025DE8(((struct Obj24040 *)(*(char * *)&((BoxTask *)p)->f2C))->f70);
    if (r == -1) {
        if (func_020362DC() & 0x800) {
            func_021DD238(p);
            return 0x28;
        }
        if (func_0203633C() & 0x200) {
            func_021DD238(p);
            return 0x25;
        }
        if (func_0203633C() & 0x100) {
            func_021DD238(p);
            return 0x26;
        }
    }
    return r;
}





/*
 * Twin of func_021EE7C4 with the same selector and target word.
 */
void func_021EE9C4(char *p, int a, int b)
{
    func_021EE754((unsigned char *)p, a);
    func_021EEF74((char *)(*(int *)&((BoxTask *)p)->f2C), a, b);
    func_021DC9B4((char *)(*(int *)&((BoxTask *)p)->f2C), 0x021E066D);
    *(int *)(*(int *)&((BoxTask *)p)->f2C + 0xA168) = a;
}





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK
#define WORK(p) (*(char **)((p) + 0x2c))





void func_021EE9F4(char *p, unsigned r)
{
    if (r - 0x25 <= 1) {
        func_020260E4(*(void **)(WORK(p) + 0x70), 0x24);
        r = 0x24;
    } else if (r - 0x28 <= 2) {
        func_020260E4(*(void **)(WORK(p) + 0x70), *(unsigned *)(WORK(p) + 0xa168));
        r = *(unsigned *)(WORK(p) + 0xa168);
    } else {
        func_021EE408(p, r);
    }
    func_021EE754((unsigned char *)p, r);
    *(unsigned *)(WORK(p) + 0xa168) = r;
}





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))






unsigned func_021EEA48(char *p)
{
    unsigned char sel = func_020260E0(OBJ(p));
    unsigned r = func_02025DE8(OBJ(p));
    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r - 0x24 <= 2) {
            func_020260E4(OBJ(p), sel);
            func_021EE408(p, sel);
            return -1;
        }
        if (func_020362DC() & 0x400) {
            func_020355D8(0);
            return 0x22;
        }
        if (r == 0x22) {
            func_020355D8(1);
            return 0x22;
        }
        if (r == 0x23) {
            func_020260E4(OBJ(p), sel);
            return 0x23;
        }
    } else if (r - 0x21 <= 2) {
        func_020260E4(OBJ(p), sel);
        func_021EE408(p, sel);
        return -1;
    }
    if (r == -1) {
        if (func_0203633C() & 0x200) {
            func_021DD238(p);
            return 0x1F;
        }
        if (func_0203633C() & 0x100) {
            func_021DD238(p);
            return 0x20;
        }
    }
    return r;
}






void func_021EEB18(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((BoxTask *)p)->f2C, a, b);
    func_021DC9B4(((BoxTask *)p)->f2C, (int)((void *)&func_021E066C));
}






void func_021EEB30(void *a, int tag)
{
    if (tag != 0x22 && tag != 0x23)
        func_021EE408(a, tag);
}





#undef WORK




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))






/*
 * Twin of src/matched/ov170_func_021EE8A8.c.  The image tests the first
 * range as subs/cmp #2, which only the `r - 9 <= 2` spelling gives; the
 * two-compare form r >= 9 && r <= 11 keeps two branches.
 */
unsigned func_021EEB40(char *p)
{
    unsigned char sel = func_020260E0(*(void **)(WORK(p) + 0x70));
    unsigned r = func_02025DE8(*(void **)(WORK(p) + 0x70));

    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r - 9 <= 2) {
            func_020260E4(*(void **)(WORK(p) + 0x70), sel);
            func_021EE408(p, sel);
            return -1;
        }
        if (func_020362DC() & 0x400) {
            func_020355D8(0);
            return 7;
        }
        if (r == 7) {
            func_020355D8(1);
            return 7;
        }
        if (r == 8) {
            func_020260E4(*(void **)(WORK(p) + 0x70), sel);
            return 8;
        }
    } else if (r - 6 <= 2) {
        func_020260E4(*(void **)(WORK(p) + 0x70), sel);
        func_021EE408(p, sel);
        return -1;
    }
    return r;
}






void func_021EEBDC(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((BoxTask *)p)->f2C, a, b);
    func_021DC9B4(((BoxTask *)p)->f2C, (int)((void *)&func_021E066C));
}






void func_021EEBF4(void *a, int tag)
{
    if (tag != 0x7 && tag != 0x8)
        func_021EE408(a, tag);
}






void func_021EEC04(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((BoxTask *)p)->f2C, a, b);
    func_021DC9B4(((BoxTask *)p)->f2C, (int)((void *)&func_021E066C));
}





/*
 * Queue the byte-narrowed index, then re-run the frame update.
 */
void func_021EEC1C(char *p, unsigned int a)
{
    func_020260E4((struct Sound *)(*(int *)(((struct Obj18531 *)p)->f2C + 0x70)), (unsigned char)a);
    func_021EE408(p, a);
}





void func_021EEC38(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((BoxTask *)p)->f2C, a, b);
    func_021DC9B4(((BoxTask *)p)->f2C, (int)((void *)&func_021E066C));
}




void func_021EEC50(char *p, unsigned int a)
{
    func_020260E4((struct Sound *)(*(int *)(((struct Obj18532 *)p)->f2C + 0x70)), (unsigned char)a);
    func_021EE408(p, a);
}



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p)+0x2c))




void func_021EEC6C(char *p, int k, int v)
{
    if (k >= 1 && k <= 4) func_021EE008(p, k-1, 1);
    else func_021EE008(p, 0, 0);
    func_021EEF74(WORK(p), k, v);
    func_021DC9B4(WORK(p), (int)func_021E066C);
    *(int *)(WORK(p)+0xa168) = k;
}




void func_021EECB0(char *p, int a)
{
    int v;
    if (a == 0 || (unsigned)(a - 5) <= 1) {
        func_020260E4((struct Sound *)(*(int *)(((struct Obj07241 *)p)->f2C + 0x70)),
                      *(int *)(((struct Obj07241 *)p)->f2C + 0xA168) & 0xff);
        v = *(int *)(((struct Obj07241 *)p)->f2C + 0xA168);
    } else {
        func_021EE408(p, a);
        v = a;
    }
    *(int *)(((struct Obj07241 *)p)->f2C + 0xA168) = v;
}




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))



#undef OBJ


#undef OBJ

#undef OBJ

#define OBJ(p) (*(void **)(WORK(p) + 0x70))





unsigned func_021EECE4(char *p)
{
    unsigned char sel = func_020260E0(OBJ(p));
    unsigned r = func_02025DE8(OBJ(p));
    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r >= 0x24 && r <= 0x27) {
            func_020260E4(OBJ(p), sel);
            func_021EE408(p, sel);
            return -1;
        }
        if (func_020362DC() & 0x400) {
            func_020355D8(0);
            return 0x22;
        }
        if (r == 0x22) {
            func_020355D8(1);
            return 0x22;
        }
        if (r == 0x23) {
            func_020260E4(OBJ(p), sel);
            return 0x23;
        }
    } else if (r == 0x1E || r - 0x21 <= 2) {
        func_020260E4(OBJ(p), sel);
        func_021EE408(p, sel);
        return -1;
    }
    if (r == -1) {
        if (func_0203633C() & 0x200) {
            func_021DD238(p);
            return 0x1F;
        }
        if (func_0203633C() & 0x100) {
            func_021DD238(p);
            return 0x20;
        }
    }
    return r;
}





void func_021EEDB8(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((BoxTask *)p)->f2C, a, b);
    func_021DC9B4(((BoxTask *)p)->f2C, (int)((void *)&func_021E066C));
}





void func_021EEDD0(void *a, int tag)
{
    if (tag != 0x22 && tag != 0x23)
        func_021EE408(a, tag);
}




#undef WORK



#undef WORK


#undef WORK

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))





unsigned func_021EEDE0(char *p)
{
    unsigned char sel = func_020260E0(*(void **)(WORK(p) + 0x70));
    unsigned r = func_02025DE8(*(void **)(WORK(p) + 0x70));

    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r >= 9 && r <= 12) {
            func_020260E4(*(void **)(WORK(p) + 0x70), sel);
            func_021EE408(p, sel);
            return -1;
        }
        if (func_020362DC() & 0x400) {
            func_020355D8(0);
            return 7;
        }
        if (r == 7) {
            func_020355D8(1);
            return 7;
        }
        if (r == 8) {
            func_020260E4(*(void **)(WORK(p) + 0x70), sel);
            return 8;
        }
    } else if (r - 6 <= 2) {
        func_020260E4(*(void **)(WORK(p) + 0x70), sel);
        func_021EE408(p, sel);
        return -1;
    }
    return r;
}




/*
 * Detach the sub-object and seat the reset handler.
 */
void func_021EEE7C(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((BoxTask *)p)->f2C, a, b);
    func_021DC9B4(*(char * *)&((BoxTask *)p)->f2C, (int)func_021E066C);
}





void func_021EEE94(void *a, int tag)
{
    if (tag != 0x7 && tag != 0x8)
        func_021EE408(a, tag);
}




#undef WORK



#undef WORK


#undef WORK

#undef WORK
#define WORK(p) (*(char **)((p)+0x2c))




#undef OBJ



#undef OBJ


#undef OBJ

#undef OBJ
#define OBJ(p) (*(void **)(WORK(p)+0x70))




unsigned func_021EEEA4(char *p)
{
    unsigned char sel=func_020260E0(OBJ(p));
    unsigned r=func_02025DE8(OBJ(p));
    if(func_021EF5E8(*(struct WinMgr **)(WORK(p)+0x74))==0) {
        if(r>=0x22 && r<=0x23) {
            func_020260E4(OBJ(p),sel);
            func_021EE408(p,sel);
            return -1;
        }
        if(r==0x21) {
            func_020260E4(OBJ(p),sel);
            return 0x21;
        }
    } else if(r==0x1e || r==0x21) {
        func_020260E4(OBJ(p),sel);
        func_021EE408(p,sel);
        return -1;
    }
    if(r==-1) {
        if(func_0203633C()&0x200) { func_021DD238(p); return 0x1f; }
        if(func_0203633C()&0x100) { func_021DD238(p); return 0x20; }
    }
    return r;
}




void func_021EEF50(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((BoxTask *)p)->f2C, a, b);
    func_021DC9B4(*(char * *)&((BoxTask *)p)->f2C, (int)func_021E066C);
}




/*
 * Run the attached handler unless the key is 0x21.
 */
void func_021EEF68(char *a, int b)
{
    if (b != 0x21)
        func_021EE408(a, b);
}




/*
 * Pull the two tag records through the p+0x70 lookup and hand both
 * pairs to the 0x54/0x10 emitter.
 */
void func_021EEF74(char *q, int a, int b)
{
    unsigned char *x = func_0202616C((void **)(((struct Obj12189 *)q)->f70), a);
    unsigned char *y = func_0202616C((void **)(((struct Obj12189 *)q)->f70), b);
    func_021EEFA4(q, x[0], x[1], y[0], y[1]);
}




void func_021EEFA4(char *p, unsigned char x, unsigned char y, unsigned char tx, unsigned char ty)
{
    Motion *s;
    s=func_02030734(0x4c,8,0,d_021F1418,0x98f);
    s->steps=4;
    s->x=x;
    s->y=y;
    if(x>=tx) { s->dx=x-tx; s->negx=0; }
    else { s->dx=tx-x; s->negx=1; }
    if(y>=ty) { s->dy=y-ty; s->negy=0; }
    else { s->dy=ty-y; s->negy=1; }
    s->dx=((unsigned)(s->dx<<8)/(unsigned)s->steps)>>8;
    s->dy=((unsigned)(s->dy<<8)/(unsigned)s->steps)>>8;
    *(Motion * *)&((BoxWork *)p)->f60=s;
}




int func_021EF048(const char *p, unsigned n)
{
    Object obj;
    unsigned i;
    obj.second=d_021F0020;
    for(i=0;i<n;i++) {
        obj.first=*(Bytes *)(p+i*12+8);
        if(func_02035C08(&obj)!=-1) return i;
    }
    return -1;
}




int func_021EF0A8(const char *p, unsigned n)
{
    Object obj;
    unsigned i;
    obj.second=d_021F0020;
    for(i=0;i<n;i++) {
        obj.first=*(Bytes *)(p+i*12+8);
        if(func_02035BA4(&obj)!=-1) return i;
    }
    return -1;
}




int func_021EF108(const char *p, unsigned n, int a, int b)
{
    Object obj;
    unsigned i;
    obj.second=d_021F0020;
    for(i=0;i<n;i++) {
        obj.first=*(Bytes *)(p+i*12+8);
        if(func_02035D40((struct Ctx *)(&obj),a,b)!=-1) return i;
    }
    return -1;
}




/*
 * Register a table with the loader.
 */
u32 func_021EF170(void)
{
    return func_021EF048((void *)0x021F0DCC, 0x1e);
}




int func_021EF180(int a, int b)
{
    return func_021EF108((char *)0x021F0DCC, 0x1e, a, b);
}




u32 func_021EF194(void)
{
    return func_021EF048((void *)0x021F0574, 6);
}




u32 func_021EF1A4(void)
{
    return func_021EF048((void *)0x021F1354, 6);
}





int func_021EF1B4(void)
{
    return func_021EF0A8((const char *)d_021F0F40, 2);
}





int func_021EF1C4(void)
{
    return func_02035BA4(d_021F0040);
}





int func_021EF1D4(unsigned *a, unsigned *b)
{
    if (func_02035BA4(d_021F0034) != -1) {
        func_02035CB8(a, b);
        return 1;
    }
    return 0;
}




int func_021EF1FC(unsigned*a,unsigned*b){if(func_02035BA4(d_021F0024)!=-1){func_02035CB8(a,b);return 1;}return 0;}




/*
 * Query the 0x021F1174 table with index 4; -1 becomes 0xff,
 *   otherwise the answer plus 0x24.  The -1 arm must be the branch target.
 */
int func_021EF224(int a, int b)
{
    int v = func_021EF108((char *)0x021F1174, 4, a, b);
    if (v != -1)
        return v + 0x24;
    return 0xff;
}





int func_021EF248(void)
{
    if (func_02035BA4(d_021F002C) != -1)
        return 1;
    return 0;
}





int func_021EF264(void)
{
    return func_021EF0A8((const char *)d_021F0F58, 1);
}




#define MGR(w) (*(struct WinMgr **)((w)+0x74))




/*
 * trailing: two zero alignment bytes at 0x021EF30E.
 */
void func_021EF274(char *p)
{
    char *w=*(char * *)&((BoxTask *)p)->f2C;
    MGR(w)=func_0202C9B4(2,12,0x4c);
    func_021EB744(w);
    func_021EF630(p);
    func_021EB79C((unsigned char *)p);
    func_021EB7C8(p);
    func_0202CA3C(MGR(w),8,1,11,15);
    if(((struct Obj24042 *)(*(char * *)&((BoxTask *)p)->f0))->f24==4) func_021EF31C(MGR(w),8,8);
    else func_021EF31C(MGR(w),8,9);
    func_0202CA3C(MGR(w),7,1,11,15);
    func_021EF31C(MGR(w),7,10);
    func_021EB95C(p);
    func_0202CA3C(MGR(w),9,1,11,21);
    func_021EF31C(MGR(w),9,11);
    func_021EF4C0(MGR(w));
}





/*
 * Forward the word at +0x74.
 */
void func_021EF310(char *p)
{
    func_0202CA0C(*(struct WinMgr * *)&((BoxWork *)p)->f74);
}





/*
 * Forward the three arguments with a literal third argument, in place of the fourth.
 */
void func_021EF31C(struct WinMgr *mgr, int a1, int a2)
{
    func_0202CAE4(mgr, a1, 0x74, a2, 1);
}





/*
 * Forward a plus constants to func_0202CB4C.
 */
void func_021EF32C(struct WinMgr *mgr)
{
    func_0202CB4C(mgr, 8, 2, 6);
}





void func_021EF33C(struct WinMgr *mgr)
{
    func_0202CB4C(mgr, 8, 0x15, 6);
}





void func_021EF34C(struct WinMgr *mgr)
{
    func_0202CB4C(mgr, 8, 2, 0x18);
}





void func_021EF35C(struct WinMgr *mgr)
{
    func_0202CB4C(mgr, 8, 0x15, 0x18);
}




/*
 * Probe the 8-byte tag; unless the tag byte is 6, patch the row
 *   with (tag - 6) through channel 8.
 */
void func_021EF36C(struct WinMgr *mgr)
{
    s8 buf[4];
    func_0202CF98(mgr, 8, buf + 1, buf);
    if ((signed char)buf[0] != 6)
        func_0202CD64(mgr, 8, 0, -1, (unsigned char)(buf[0] - 6));
}




/*
 * Probe the 8-byte tag; unless the tag byte is 0x18, patch the row
 *   with (0x18 - tag) as a flagged close.
 */
void func_021EF3A0(struct WinMgr *mgr)
{
    s8 buf[4];
    func_0202CF98(mgr, 8, buf + 1, buf);
    if ((signed char)buf[0] != 0x18)
        func_0202CD64(mgr, 8, 0, 1, (unsigned char)(0x18 - buf[0]));
}





/*
 * Forward a plus constants to func_0202CD64.
 */
void func_021EF3D8(struct WinMgr *mgr)
{
    func_0202CD64(mgr, 8, 1, 0, 0x13);
}





void func_021EF3EC(struct WinMgr *mgr)
{
    func_0202CD64(mgr, 8, -1, 0, 0x13);
}





int func_021EF400(unsigned char *p)
{
    signed char a[2];
    signed char b[2];
    unsigned r;
    func_0202CF98(*(struct WinMgr * *)&((struct Obj24043 *)(*(char * *)&((BoxTask *)p)->f2C))->f74, 8, &a[1], &a[0]);
    r = func_0202CDD4(*(struct WinMgr * *)&((struct Obj24044 *)(*(char * *)&((BoxTask *)p)->f2C))->f74, 8);
    func_0202CF98(*(struct WinMgr * *)&((struct Obj24045 *)(*(char * *)&((BoxTask *)p)->f2C))->f74, 8, &b[1], &b[0]);
    if (a[1] != b[1] || a[0] != b[0])
        func_021EC8E4((char *)p);
    {
        int ret = 0;
        if (r != 0)
            ret = 1;
        return ret;
    }
}




/*
 * Read the 8-byte tag at the top of the frame; 1 when byte 1 is
 *   0x15 and byte 0 is 6.
 */
int func_021EF45C(struct WinMgr *mgr)
{
    s8 buf[4];
    func_0202CF98(mgr, 8, buf + 1, buf);
    return buf[1] == 0x15 && buf[0] == 6;
}




/*
 * Same probe as func_021EF45C with tag byte 1 compared to 2.
 */
int func_021EF480(struct WinMgr *mgr)
{
    s8 buf[4];
    func_0202CF98(mgr, 8, buf + 1, buf);
    return buf[1] == 0x2 && buf[0] == 6;
}




/*
 * Probe the 8-byte tag at the top of the frame; 1 when its first
 *   byte is 6.
 */
int func_021EF4A4(struct WinMgr *mgr)
{
    s8 buf[4];
    func_0202CF98(mgr, 8, buf + 1, buf);
    return buf[0] == 6;
}




/*
 * Push tag rows 0x20 for six entries; element (i*3+2) is a
 *   signed char.  The counter is UNSIGNED or the image's blo becomes blt.
 */
void func_021EF4C0(struct WinMgr *mgr)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        func_0202CB4C(mgr, i, 0x20, (signed char)(i * 3 + 2));
}




void func_021EF4E4(struct WinMgr *mgr)
{
    unsigned i;
    for (i = 0; i < 6; i++)
        func_0202CB4C(mgr, i, 0x15, (signed char)(i * 3 + 2));
}





void func_021EF508(struct WinMgr *mgr)
{
    unsigned i;
    for (i = 0; i < 6; i++) {
        func_0202CC70(mgr, i);
        func_0202CB4C(mgr, i, 0x20, i * 3 + 2);
    }
}





void func_021EF534(struct WinMgr *mgr)
{
    signed char buf[2];
    unsigned short i = 0;
    func_0202CF98(mgr, 0, &buf[1], &buf[0]);
    if (buf[1] == 0x15)
        return;
    for (; i < 6; i++)
        func_0202CD64(mgr, i, -1, 0, buf[1] - 0x15);
}





void func_021EF57C(struct WinMgr *mgr)
{
    signed char buf[2];
    unsigned short i = 0;
    func_0202CF98(mgr, 0, &buf[1], &buf[0]);
    if (buf[1] == 0x20)
        return;
    for (; i < 6; i++)
        func_0202CD64(mgr, i, 1, 0, 0x20 - buf[1]);
}




/*
 * 1 when probe 1..6 reports 1.
 */
int func_021EF5C4(struct WinMgr *mgr)
{
    unsigned i;
    int found = 0;
    for (i = 0; i < 6; i++) {
        if (func_0202CDD4(mgr, i) == 1)
            found = 1;
    }
    return found;
}




int func_021EF5E8(struct WinMgr *mgr)
{
    s8 buf[4];
    func_0202CF98(mgr, 0, buf + 1, buf);
    return buf[1] != 0x20;
}




/*
 * 1 when the tag's byte 1 is 0x15.
 */
int func_021EF60C(struct WinMgr *mgr)
{
    s8 buf[4];
    func_0202CF98(mgr, 0, buf + 1, buf);
    return buf[1] == 0x15;
}




/*
 * Spin up the 0x0204162C resource, arm channel 6 with tag 0x20,
 *   then hand row 6 of the 0x540 span.
 */
void func_021EF630(char *p)
{
    int x = func_0204162C(0);
    func_0202CA3C(*(struct WinMgr **)(*(int *)&((BoxTask *)p)->f2C + 0x74), 6, 0, 0x20, 3);
    func_0202CAC4(*(struct WinMgr **)(*(int *)&((BoxTask *)p)->f2C + 0x74), 6, (const void *)(x + 0x540));
}





void func_021EF660(struct WinMgr *mgr)
{
    func_0202CB4C(mgr, 6, 0, 0x15);
}





/*
 * Forward the word at +0x74 plus constants to func_0202CB4C.
 */
void func_021EF670(char *p)
{
    func_0202CB4C(*(struct WinMgr * *)&((BoxWork *)p)->f74, 0xa, 0, 0x15);
}





/*
 * Forward the word at +0x74 with index 10.
 */
void func_021EF680(char *p)
{
    func_0202CC70(*(struct WinMgr * *)&((BoxWork *)p)->f74, 0xa);
}





void func_021EF68C(char *p)
{
    func_0202CB4C(*(struct WinMgr * *)&((BoxWork *)p)->f74, 0xb, 0, 0x15);
}





/*
 * Forward the word at +0x74 with index 11.
 */
void func_021EF69C(char *p)
{
    func_0202CC70(*(struct WinMgr * *)&((BoxWork *)p)->f74, 0xb);
}




void func_021EF6A8(struct WinMgr *mgr)
{
    func_0202CB4C(mgr, 7, 0x15, 0x18);
    func_0202CD64(mgr, 7, 0, -1, 0x13);
}





void func_021EF6CC(struct WinMgr *mgr)
{
    func_0202CD64(mgr, 7, 0, 1, 0x13);
}




#undef MGR



#undef MGR


#undef MGR

#undef MGR
#define MGR(p) (*(struct WinMgr **)(*(char **)((p)+0x2c)+0x74))




/*
 * trailing: two zero alignment bytes at 0x021EF736.
 */
unsigned func_021EF6E0(char *p)
{
    signed char a[2], b[2];
    unsigned r;
    func_0202CF98(MGR(p),7,&a[1],&a[0]);
    r=func_0202CDD4(MGR(p),7);
    func_0202CF98(MGR(p),7,&b[1],&b[0]);
    if(a[1]!=b[1] || a[0]!=b[0]) func_021ED8A4(p);
    return r;
}




/*
 * Stage row 0x20 at channel 9 then patch with -1.
 */
void func_021EF738(struct WinMgr *mgr)
{
    func_0202CB4C(mgr, 9, 0x20, 0);
    func_0202CD64(mgr, 9, -1, 0, 0xb);
}





void func_021EF75C(struct WinMgr *mgr)
{
    func_0202CD64(mgr, 9, 1, 0, 0xb);
}

int func_021EF770(struct WinMgr *mgr)
{
    s8 buf[2];
    func_0202CF98(mgr, 9, &buf[1], &buf[0]);
    if (buf[1] == 0x15) {
        return 1;
    }
    return 0;
}

