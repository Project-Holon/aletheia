/*
 * file:     startmenu_p05.c
 * unit:     yes
 * function: func_021B9EC4, func_021B9F68, func_021B9F70, func_021B9F94, func_021B9FE4, func_021BA014, func_021BA114, func_021BA1A0, func_021BA218, func_021BA230, func_021BA2C8, func_021BA338, func_021BA4A0, func_021BA540, func_021BA6B0, func_021BA7AC, func_021BA880, func_021BA990, func_021BA9B0, func_021BA9C8
 * address:  0x021B9EC4
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
 *   func_020490F4  0x020490F4  arm
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B270  0x0204B270  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_02043598  0x02043598  arm
 *   func_02049238  0x02049238  arm
 *   d_020A1448     0x020A1448  data  a4
 *   d_021BD508     0x021BD508  data  ov088  a4
 *   func_0204A600  0x0204A600  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_020070A4  0x020070A4  thumb
 *   func_02008730  0x02008730  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_02009210  0x02009210  thumb
 *   func_02012FE4  0x02012FE4  thumb
 *   func_020310C4  0x020310C4  arm
 *   d_021BD63C     0x021BD63C  data  ov088  a4
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_020274C8  0x020274C8  thumb
 *   func_021BC114  0x021BC114  thumb  ov088
 *   func_021BC0FC  0x021BC0FC  thumb  ov088
 *   func_021BC0E4  0x021BC0E4  thumb  ov088
 *   func_02030734  0x02030734  arm
 *   func_020312F8  0x020312F8  arm
 *   d_021BDA00     0x021BDA00  data  ov088  a1
 *   d_021DF538     0x021DF538  data  ov121  a4
 *   d_02213C4C     0x02213C4C  data  a4
 *   d_0209DEF0     0x0209DEF0  data  a4
 *   d_021D77AC     0x021D77AC  data  ov016  a4
 *   d_02184904     0x02184904  data  ov168  a4
 *   d_021F6D78     0x021F6D78  data  ov107  a4
 *   d_021BD574     0x021BD574  data  a4
 *   ov121_id       0x00000079  data
 *   ov199_id       0x000000C7  data
 *   ov016_id       0x00000010  data
 *   ov168_id       0x000000A8  data
 *   ov107_id       0x0000006B  data
 *   ov088_id       0x00000058  data
 *   func_02009448  0x02009448  thumb
 *   func_020092EC  0x020092EC  thumb
 *   func_0200C2F0  0x0200C2F0  thumb
 *   func_02043534  0x02043534  arm
 *   func_020435F4  0x020435F4  arm
 *   func_0204363C  0x0204363C  arm
 *   func_021BA9D4  0x021BA9D4  thumb  ov088
 *   func_021BA9E8  0x021BA9E8  thumb  ov088
 *   func_021BAB64  0x021BAB64  thumb  ov088
 *   func_021BAC74  0x021BAC74  thumb  ov088
 *   func_021BB4B4  0x021BB4B4  thumb  ov088
 *   func_021BB544  0x021BB544  thumb  ov088
 *   func_021BAD08  0x021BAD08  thumb  ov088
 *   func_021BB184  0x021BB184  thumb  ov088
 *   func_021BB380  0x021BB380  thumb  ov088
 *   func_021BB608  0x021BB608  thumb  ov088
 *   func_021BAC24  0x021BAC24  thumb  ov088
 *   func_021BB484  0x021BB484  thumb  ov088
 *   func_0203D210  0x0203D210  arm
 *   func_021BAC64  0x021BAC64  thumb  ov088
 *   func_021BB474  0x021BB474  thumb  ov088
 *   func_021BB328  0x021BB328  thumb  ov088
 *   func_021BB164  0x021BB164  thumb  ov088
 *   func_021BB5C4  0x021BB5C4  thumb  ov088
 *   func_021BACD8  0x021BACD8  thumb  ov088
 *   func_021BAB20  0x021BAB20  thumb  ov088
 *   func_020221A4  0x020221A4  thumb
 *   func_021BB840  0x021BB840  thumb  ov088
 *   func_021BB810  0x021BB810  thumb  ov088
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_021BC0C8  0x021BC0C8  thumb  ov088
 *   func_021BC054  0x021BC054  thumb  ov088
 *   func_0202EA40  0x0202EA40  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021BC0AC  0x021BC0AC  thumb  ov088
 *   func_021BC080  0x021BC080  thumb  ov088
 *   func_0203633C  0x0203633C  arm
 *   func_021BB890  0x021BB890  thumb  ov088
 *   func_0202EB04  0x0202EB04  thumb
 *   func_02041EE4  0x02041EE4  arm
 *   func_021BB858  0x021BB858  thumb  ov088
 *   func_020434DC  0x020434DC  arm
 *   func_021BB9DC  0x021BB9DC  thumb  ov088
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
 *   func_0204A648  0x0204A648  arm
 *   SDK_AUTOLOAD_DTCM_START 0x02FE0000 data
 *   func_020056A0  0x020056A0  thumb
 *   func_02030EAC  0x02030EAC  arm
 */
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

struct Bank;
struct Cfg;
struct Obj;
struct Obj0203159C;
struct Sub02007084Ctrl;
struct Sub0200852CObj;
struct Sub02009210Obj;
struct Sub020071CCCtrl;
struct Tcbl;
struct S020315D4;
struct Sub02009448Obj;
struct Blk34;
struct Menu;
struct Descriptor;
struct PrintSys;
struct Row;
struct CodeIn;
struct Sub020090B0Obj;
struct Node;
typedef struct {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned char d;
    unsigned char e;
} Local;

typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned int   u32_021B9EC4;

typedef unsigned int   u32_021B9F70;

typedef unsigned int   u32_021B9F94;

typedef int (*StateFn)(char *);

typedef unsigned int u32_021BA014;

typedef unsigned short u16;

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

extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_0204A48C(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *func_0204B100(int count, u8 flag, unsigned int heapId);
extern void func_0204B270(struct Bank *bank);
extern int func_0204A6C8(void *, int, int, int, int);
extern int func_0204ABF0(void *, int, int, int, int);
extern s32 func_0204AF28(void *owner, u32_021B9EC4 first, u32_021B9EC4 second, u32_021B9EC4 mode);
extern int func_0204B294(int, int, int, int, Local *, int, int);
extern void func_0204B92C(struct Obj *p, u32_021B9EC4 v);
extern void func_02043598(u32_021B9EC4 mask, u32_021B9EC4 enable);
extern void func_02049238(void *);
void func_0204A600(void);
extern void func_0204A8D4(u32_021B9F70 i);
extern void func_0204ADA4(u32_021B9F70 i);
extern void func_0204AFD8(u32_021B9F70 i);
extern u32_021B9F70 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0203064C(unsigned int, unsigned int, unsigned int);
extern void *func_0203159C(struct Obj0203159C *obj, u32_021B9F94 size, u32_021B9F94 heap);
extern void func_02082BCC(void *, int, int);
extern struct Sub02007084Ctrl *func_020070A4(void);
extern struct Sub0200852CObj *func_02008730(void *sys);
extern void *func_0200C0F0(void *sys);
extern struct Sub02009210Obj *func_02009210(void *sys);
extern void *func_02012FE4(struct Sub020071CCCtrl *a0);
extern void func_020310C4(struct Tcbl *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void func_020274C8(void);
extern void func_021BC114(void);
extern void func_021BC0FC(void);
extern void func_021BC0E4(void);
extern void *func_02030734(u32_021BA014 heapId, u32_021BA014 size, int clear, const char *site, u16 tag);
extern void func_020312F8(u32_021BA014 a1, u32_021BA014 a2, u32_021BA014 a3);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern u8 func_020092EC(const struct Sub02009210Obj *obj);
extern void func_0200C2F0(struct Blk34 *p, u32_021BA114 i, u8 v);
extern void func_02043534(u32_021BA114 planes);
extern void func_020435F4(u32_021BA114 planes);
extern void func_0204363C(u32_021BA114 swap);
extern void func_021BA9D4(void);
extern void func_021BA9E8(void);
extern void func_021BAB64(void);
extern void func_021BAC74(char *p);
extern void func_021BB4B4(char *p);
extern void func_021BB544(char *p);
extern void func_021BAD08(struct Menu *p);
extern void func_021BB184(int *p);
extern void func_021BB380(char *p);
extern void func_021BB608(char *p);
extern void func_021BAC24(char *p);
extern void func_021BB484(void);
extern u32_021BA1A0 func_0203D210(void);
extern void func_021BAC64(char *p);
extern void func_021BB474(char *p);
extern void func_021BB328(char *p);
extern void func_021BB164(char *p);
extern void func_021BB5C4(char *p);
extern void func_021BACD8(int *p);
extern void func_021BAB20(void);
extern u32_021BA218 func_020221A4(void);
extern int func_021BB840(char *p, int y);
extern void func_021BB810(void *p, u8 row, int y, int pal);
extern u32_021BA2C8 func_0201C4E4(struct PrintSys *ps);
extern void *func_02045770(struct Descriptor *p);
extern u32_021BA2C8 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern u32_021BA2C8 func_0201C6B4(const struct PrintSys *p);
extern int func_021BC0C8(char *p);
extern int func_021BC054(char *p, int v);
extern s32 func_0202EA40(struct Row *p);
extern u32_021BA338 func_020362DC(void);
extern void func_020061E4(u32_021BA338);
extern int func_021BC0AC(char *p, int v);
extern int func_021BC080(char *p, int v);
extern unsigned int func_0203633C(void);
extern int func_021BB890(char *p, int d);
extern void func_0202EB04(struct CodeIn *p);
extern void func_02041EE4(u32_021BA4A0 index, u32_021BA4A0 a, u32_021BA4A0 b);
extern void func_021BB858(char *p, int d);
extern void func_020434DC(u32_021BA540 mask, u32_021BA540 enable);
extern void func_021BB9DC(char *, int);
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
extern void func_0204A648(void);
extern int func_020056A0(void (*fn)(void), void *arg, int c);
void func_02030EAC(struct Node *n);
void func_021B9EC4(int *p, int heap);
void func_021B9F68(void);
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
extern char d_020A1448[];
extern char d_021BD508[];
extern StateFn d_021BD63C[];
extern char d_021BDA00[];
extern char d_021DF538[];
extern char d_02213C4C[];
extern char d_0209DEF0[];
extern char d_021D77AC[];
extern char d_02184904[];
extern char d_021F6D78[];
extern char d_021BD574[];
extern char ov121_id[];
extern char ov199_id[];
extern char ov016_id[];
extern char ov168_id[];
extern char ov107_id[];
extern char ov088_id[];
extern const MsgEnt d_021BD784[8];
extern char SDK_AUTOLOAD_DTCM_START[];


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


void func_021B9F68(void)
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
    p[5] = func_020056A0(func_021BA990, p, 0);
}


void func_021BA9C8(int *p)
{
    func_02030EAC((struct Node *)p[5]);
}
