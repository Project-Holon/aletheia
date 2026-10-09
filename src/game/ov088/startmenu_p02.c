/*
 * file:     startmenu_p02.c
 * unit:     yes
 * function: func_021BBB84, func_021BBBAC, func_021BBD10, func_021BBD80, func_021BBE3C, func_021BBE48, func_021BBF1C, func_021BBF98, func_021BBFA8, func_021BC024, func_021BC054, func_021BC080, func_021BC0AC, func_021BC0C8, func_021BC0E4
 * address:  0x021BBB84
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
 *   func_02041300  0x02041300  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045374  0x02045374  arm
 *   func_021BBA64  0x021BBA64  thumb  ov088
 *   func_02041EE4  0x02041EE4  arm
 *   func_021BB9DC  0x021BB9DC  thumb  ov088
 *   func_020452E8  0x020452E8  arm
 *   func_02041570  0x02041570  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045730  0x02045730  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020286C4  0x020286C4  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0203630C  0x0203630C  arm
 *   func_0201CE5C  0x0201CE5C  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201FDA0  0x0201FDA0  thumb
 *   func_0202208C  0x0202208C  thumb
 *   func_020071E8  0x020071E8  thumb
 *   func_020312F8  0x020312F8  arm
 *   d_021BD818     0x021BD818  data  a4
 *   ov088_id       0x00000058  data  a1
 */
#include "../../matched/include/Obj06204.h"
#include "../../matched/include/Obj13234.h"
#include "../../matched/include/Obj00263.h"
#include "../../matched/include/Obj06205.h"
#include "../../matched/include/Obj13235.h"
#include "../../matched/include/Obj20821.h"
#include "../../matched/include/Obj05167.h"
#include "../../matched/include/Obj02427.h"
#include "../../matched/include/Obj20822.h"
#include "../../matched/include/Obj01887.h"
#include "../../matched/include/Obj20823.h"
#include "../../matched/include/Obj20824.h"
#include "../../matched/include/Obj20825.h"
#include "../../matched/include/Obj00271.h"
#include "../../matched/include/Obj06203.h"

struct Cfg;
struct MsgBank;
struct U16Vec;
struct Descriptor;
struct Rec;
struct CharBuf;
struct Ctx;
struct Rec3;
struct Sub020071E4Ctrl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef struct Ov088Win {
    unsigned char f00;
    unsigned char f01;
    unsigned char f02;
    unsigned char f03;
    unsigned short f04;
} Ov088Win;

extern void func_02041300(u8, u32, u8, u8, u8, u8, u32);
extern void func_02041B6C(u32 bit);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045374(struct Cfg *cfg);
extern void func_021BBA64(u8 x, u8 y, u8 w, u8 h, u8 bg);
extern void func_02041EE4(u32, u32, u32);
extern void func_021BB9DC(char *, int);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02041570(int channel, u16 val);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_02043B5C(struct CharBuf *buf, unsigned char value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern signed char func_02012FFC(void);
extern u32 func_0201CCE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a5, u32 a6, u32 a7,
                         u32 a8, u16 a9, u16 a10);
extern void func_02045334(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern u32 func_0201CE30(void *p);
extern unsigned int func_0203630C(void);
extern void func_0201CE5C(struct Rec *p, s32 v);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);
extern void func_0201CE38(void *);
extern void func_0201CE48(struct Rec3 *p);
extern void *func_0201FDA0(Ov088Win *win, int base, int pal, int pos, int heap);
extern void func_0202208C(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern u32 func_020071E8(const struct Sub020071E4Ctrl *ctrl);
extern void func_020312F8(u32 a1, u32 a2, u32 a3);
void func_021BBB84(u8 x, u8 y, u8 w, u8 h, u8 bg);
void func_021BBBAC(char *p);
void func_021BBD10(char *p, int mode);
void func_021BBD80(char *p);
void func_021BBE3C(char *p);
void func_021BBE48(char *p);
void func_021BBF1C(char *p, u32 a1);
void func_021BBF98(char *p);
int func_021BBFA8(char *p);
void func_021BC024(char *p);
int func_021BC054(char *p, int v);
int func_021BC080(char *p, int v);
int func_021BC0AC(char *p, int v);
int func_021BC0C8(char *p);
void func_021BC0E4(void);
extern char d_021BD818[];
extern char ov088_id[];


void func_021BBB84(u8 x, u8 y, u8 w, u8 h, u8 bg)
{
    func_02041300(bg, 0, x, y, w, h, 0);
    func_02041B6C(bg);
}



static inline void print_line(char *p, u32 id, u32 y, u16 color)
{
    u32 s = (u32)func_02045EC0((struct MsgBank *)(((struct Obj06204 *)p)->f5C), id);
    u32 a = ((struct Obj06204 *)p)->f68;
    func_0201C724((void *)a, (u32)func_02045770((struct Descriptor *)((struct Obj06204 *)p)->fF0), 0, y, s, ((struct Obj06204 *)p)->f58, color);
    ((struct Obj06204 *)p)->fF4 = 1;
    func_02045808((struct U16Vec *)s);
}



/*
 * Four identical print blocks are one static inline helper: it loads
 * p+0x68 before the bitmap call and keeps 0x440 rematerialised per site.
 */
void func_021BBBAC(char *p)
{
    ((struct Obj13234 *)p)->fF0 = func_020450F0(0, 2, 2, 0x1e, 0x14, 5, 1);
    print_line(p, 0x16, 0, 0x14c0);
    print_line(p, 0x17, 0x18, 0x440);
    print_line(p, 0x18, 0x80, 0x440);
    print_line(p, 0x19, 0x90, 0x440);

    func_02045374((struct Cfg *)(((struct Obj13234 *)p)->fF0));
    func_02041B6C(0);
    func_021BBA64(0x20, 1, 0x20, 0x16, 2);
    func_02041EE4(1, 0, 0x100);
    func_02041EE4(1, 3, 0);
    func_02041EE4(2, 0, 0x100);
    func_02041EE4(2, 3, 0);
    func_021BB9DC(p, 0);
}



void func_021BBD10(char *p, int mode)
{
    func_020452E8(((struct Obj00263 *)p)->fF0);
    if (mode != 1) {
        func_021BBB84(0x20, 1, 0x20, 0x16, 2);
        func_02041570(0, 0);
        func_02041EE4(1, 0, 0);
        func_02041EE4(1, 3, ((struct Obj00263 *)p)->f130);
        func_02041EE4(2, 0, 0);
        func_02041EE4(2, 3, ((struct Obj00263 *)p)->f130);
        if (((struct Obj00263 *)p)->f120 == 0)
            func_021BB9DC(p, 1);
    }
}



void func_021BBD80(char *p)
{
    ((struct Obj13235 *)p)->fF0 = func_020450F0(4, 2, 3, 0x1e, 0x13, 5, 1);
    print_line(p, 0x14, 0, 0x14c0);
    print_line(p, 0x15, 0x18, 0x440);
    func_02045374((struct Cfg *)(((struct Obj13235 *)p)->fF0));
    func_02041B6C(4);
    func_021BBA64(0, 1, 0x20, 0x16, 5);
}



/*
 * 0x021BBE3C is an unlabelled tail-call stub (function_starts seed).
 * Twin of func_021BBBAC (same print_line inline).
 */
void func_021BBE3C(char *p)
{
    func_020452E8(((struct Obj20821 *)p)->fF0);
}



void func_021BBE48(char *p)
{
    u32 msg = (u32)func_02045B38(0, 2, 0xe8, 0x800b);
    u32 s;
    u32 a;

    ((struct Obj05167 *)p)->fF0 = func_020450F0(0, 2, 2, 0x1e, 0x14, 5, 1);
    s = (u32)func_02045EC0((struct MsgBank *)msg, 0x20);
    a = ((struct Obj05167 *)p)->f68;
    func_0201C724((void *)a, (u32)func_02045770((struct Descriptor *)((struct Obj05167 *)p)->fF0), 0, 0, s, ((struct Obj05167 *)p)->f58, 0x440);
    ((struct Obj05167 *)p)->fF4 = 1;
    func_02045808((struct U16Vec *)s);
    func_02045C04((struct Rec *)msg);

    func_02045374((struct Cfg *)(((struct Obj05167 *)p)->fF0));
    func_02041B6C(0);
    func_021BBA64(0x20, 1, 0x20, 0x16, 2);
    func_02041EE4(1, 0, 0x100);
    func_02041EE4(1, 3, 0);
    func_02041EE4(2, 0, 0x100);
    func_02041EE4(2, 3, 0);
    func_021BB9DC(p, 0);
}



void func_021BBF1C(char *p, u32 a1)
{
    void *h;
    func_02045CAC((struct MsgBank *)(((struct Obj02427 *)p)->f5C), a1, (void *)(((struct Obj02427 *)p)->f64));
    func_02043B5C((struct CharBuf *)func_02045770((struct Descriptor *)*(u32 *)&((struct Obj02427 *)p)->fE8), 0xf);
    func_0201F73C(((struct Obj02427 *)p)->fE8, 2, 1, 0xe);
    ((struct Obj02427 *)p)->f6C = func_0201CCE4(*(u32 *)&((struct Obj02427 *)p)->fE8, 0, 0, ((struct Obj02427 *)p)->f64,
                                       ((struct Obj02427 *)p)->f58, func_02012FFC(),
                                       ((struct Obj02427 *)p)->f70, 0xa, 0xb, 0xf);
    ((struct Obj02427 *)p)->f78 = 0;
    h = ((struct Obj02427 *)p)->fE8;
    func_02045334(h);
    func_02045374(h);
    func_02041B6C(func_02045730(h));
}



void func_021BBF98(char *p)
{
    func_0201F7A8(((struct Obj20822 *)p)->fE8, 1);
}



int func_021BBFA8(char *p)
{
    if (((struct Obj01887 *)p)->f6C == 0)
        return 0;
    func_020286C4(((struct Obj01887 *)p)->f74, ((struct Obj01887 *)p)->f6C, ((struct Obj01887 *)p)->fE8);
    switch (func_0201CE30(((struct Obj01887 *)p)->f6C)) {
    case 0:
        if (func_0203630C() & 3)
            func_0201CE5C(((struct Obj01887 *)p)->f6C, 0);
        ((struct Obj01887 *)p)->f78 = 0;
        break;
    case 1:
        if (((struct Obj01887 *)p)->f78 == 0) {
            if (func_020362DC() & 3) {
                func_020061E4(0x547);
                func_0201CE38(((struct Obj01887 *)p)->f6C);
                ((struct Obj01887 *)p)->f78 = 1;
            }
        }
        break;
    case 2:
        func_0201CE48(((struct Obj01887 *)p)->f6C);
        *(int *)&((struct Obj01887 *)p)->f6C = 0;
        ((struct Obj01887 *)p)->f78 = 0;
        return 0;
    }
    return 1;
}



/*
 * note:     listing extent runs 2 bytes past the compiled function;
 *           trailing alignment padding, no byte difference.
 */
void func_021BC024(char *p)
{
    Ov088Win win;

    win.f00 = 0;
    win.f01 = 0x18;
    win.f02 = 0xD;
    win.f03 = 0xF;
    win.f04 = 0;
    ((struct Obj20823 *)p)->f7C = func_0201FDA0(&win, 1, 0xE, 0, 0xB);
}



int func_021BC054(char *p, int v)
{
    func_0202208C(0, 1, 1, 0, 6, 1, 0xb);
    ((struct Obj20824 *)p)->f144 = v;
    return 2;
}



/*
 * EXACT*: extent runs long; the follower at 0x021BC0AC is an unlabelled leaf
 * (function_starts seed).
 */
int func_021BC080(char *p, int v)
{
    func_0202208C(0, 0, 0, 0, 6, 1, 0xb);
    ((struct Obj20825 *)p)->f144 = v;
    return 2;
}



int func_021BC0AC(char *p, int v)
{
    ((struct Obj00271 *)p)->f12E = 0;
    ((struct Obj00271 *)p)->f12D = 0;
    ((struct Obj00271 *)p)->f140 = v;
    return 3;
}



int func_021BC0C8(char *p)
{
    int r = func_020071E8(((struct Obj06203 *)p)->f0);
    ((struct Obj06203 *)p)->f148 = r;
    return r != 0;
}



void func_021BC0E4(void)
{
    func_020312F8((u32)ov088_id, (u32)d_021BD818, 0);
}
