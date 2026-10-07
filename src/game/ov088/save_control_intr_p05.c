/*
 * file:     save_control_intr_p05.c
 * unit:     yes
 * function: func_021BD118, func_021BD188, func_021BD1EC, func_021BD21C, func_021BD23C, func_021BD25C, func_021BD29C
 * address:  0x021BD118
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
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02013080  0x02013080  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020310C4  0x020310C4  arm
 *   func_020286C4  0x020286C4  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0201FDA0  0x0201FDA0  thumb
 *   func_0202208C  0x0202208C  thumb
 *   func_02030734  0x02030734  arm
 *   func_020071EC  0x020071EC  thumb
 *   func_020351F8  0x020351F8  arm
 *   d_021BDA0C     0x021BDA0C  data  ov088  a4
 *   d_021BD3B9     0x021BD3B9  data  ov088  a1
 *   func_020307B0  0x020307B0  arm
 */
#include "../../matched/include/Obj00578.h"
#include "../../matched/include/Obj13237.h"

struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Ctx;
struct Rec3;
struct Tcbl;
struct Sub020071E4Ctrl;
typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef unsigned char  u8;

typedef struct {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
    unsigned short e;
} Rect6;

extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern signed char func_02013080(u32 idx);
extern int func_0201CCE4(u32 a0, u32 a1, u32 a2, u32 a3, u32 a5, u32 a6, u32 a7,
                          u32 a8, u16 a9, u16 a10);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void func_020310C4(struct Tcbl *p);
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
extern u32 func_0201CE30(void *p);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);
extern void func_0201CE38(void *);
extern void func_0201CE48(struct Rec3 *p);
extern void *func_0201FDA0(Rect6 *, int, int, int, int);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern unsigned char func_020071EC(const struct Sub020071E4Ctrl *);
extern void func_020351F8(u32 a, u32 b);
extern u32 func_020307B0(void *p);
void func_021BD118(int *p, u32 mode);
int func_021BD188(char *p);
void func_021BD1EC(unsigned char *p);
void func_021BD21C(void);
void func_021BD23C(void);
void *func_021BD25C(int a, int b);
void func_021BD29C(void *p);


void func_021BD118(int *p, u32 mode)
{
    int t;

    func_02045CAC((struct MsgBank *)p[2], mode, (void *)p[4]);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)p[7])), 15);
    func_0201F73C((void *)p[7], 2, 1, 14);
    p[5] = func_0201CCE4(p[7], 0, 0, p[4], p[1], func_02013080(0), p[6], 10, 0x81, 15);
    p[10] = 0;
    t = p[7];
    func_02045334((struct Descriptor *)t);
    func_02045374((struct Cfg *)t);
    func_02041B6C(func_02045730((struct Descriptor *)t));
}


int func_021BD188(char *p)
{
    func_020310C4(((struct Obj00578 *)p)->f18);
    func_020286C4(((struct Obj00578 *)p)->f24, ((struct Obj00578 *)p)->f14, ((struct Obj00578 *)p)->f1C);
    switch (func_0201CE30(((struct Obj00578 *)p)->f14)) {
    case 0:
        ((struct Obj00578 *)p)->f28 = 0;
        break;
    case 1:
        if (((struct Obj00578 *)p)->f28 == 0) {
            if (func_020362DC() & 3) {
                func_020061E4(0x547);
                func_0201CE38(((struct Obj00578 *)p)->f14);
                ((struct Obj00578 *)p)->f28 = 1;
            }
        }
        break;
    case 2:
        func_0201CE48(((struct Obj00578 *)p)->f14);
        ((struct Obj00578 *)p)->f28 = 0;
        return 0;
    }
    return 1;
}


void func_021BD1EC(unsigned char *p)
{
    Rect6 r;
    r.a = 0;
    r.b = 0x18;
    r.c = 0x0D;
    r.d = 0x0F;
    r.e = 0;
    ((struct Obj00578 *)p)->f20 = func_0201FDA0(&r, 1, 0x0E, 1, 0x81);
}


void func_021BD21C(void)
{
    func_0202208C(0, 1, 1, 0, 6, 1, 0x81);
}


void func_021BD23C(void)
{
    func_0202208C(0, 0, 0, 0, 6, 1, 0x81);
}


/*
 * func_020351F8 (arm) resolves through the matched entry
 * src/matched/arm9/sub_020351F8.c.
 */
void *func_021BD25C(int a, int b)
{
    char *r4 = (char *)func_02030734(a, 0x10, 1, (const char *)0x021BDA0C, 0x45);
    ((struct Obj13237 *)r4)->f0 = b;
    if (func_020071EC((const struct Sub020071E4Ctrl *)b) == 1) {
        r4[7] = 1;
    } else {
        func_020351F8(0x021BD3B9, (int)r4);
    }
    return r4;
}


void func_021BD29C(void *p)
{
    func_020351F8(0, 0);
    func_020307B0(p);
}
