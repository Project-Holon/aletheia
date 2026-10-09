/*
 * file:     union_subdisp.c
 * unit:     yes
 * function: func_021EFEC0, func_021EFFE8, func_021F0054, func_021F00D4, func_021F01F0, func_021F022C, func_021F0250, func_021F0348, func_021F0378, func_021F0420, func_021F0430, func_021F0478, func_021F0490, func_021F04D4, func_021F04EC, func_021F056C, func_021F0584, func_021F0628
 * address:  0x021EFEC0
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02030734  0x02030734  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   func_0202DB0C  0x0202DB0C  thumb
 *   func_0202DE5C  0x0202DE5C  thumb
 *   func_02026474  0x02026474  thumb
 *   func_02173940  0x02173940  thumb  ov012
 *   func_021F09A0  0x021F09A0  thumb  ov031
 *   func_0204B6F4  0x0204B6F4  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_02037174  0x02037174  arm
 *   str_021F10C0   0x021F10C0  data  ov031  a1
 *   d_021F1038     0x021F1038  data  ov031  a1
 *   func_0202DC08  0x0202DC08  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02037190  0x02037190  arm
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0202DBC4  0x0202DBC4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02026454  0x02026454  thumb
 *   func_021BBA70  0x021BBA70  thumb  ov021
 *   func_021F0680  0x021F0680  thumb  ov031
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021736C8  0x021736C8  thumb  ov012
 *   func_021F0B98  0x021F0B98  thumb  ov031
 *   func_021F0D64  0x021F0D64  thumb  ov031
 *   func_021F0FE0  0x021F0FE0  thumb  ov031
 *   func_021F0C34  0x021F0C34  thumb  ov031
 *   func_021F0DB0  0x021F0DB0  thumb  ov031
 *   func_021F0EF4  0x021F0EF4  thumb  ov031
 *   func_02173934  0x02173934  thumb  ov012
 *   func_0204B100 0x0204B100 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_0204162C  0x0204162C  arm
 *   func_02049EF4  0x02049EF4  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02040588  0x02040588  arm
 *   d_021F1050     0x021F1050  data  ov031  a4
 *   d_021F1070     0x021F1070  data  ov031  a4
 *   d_021F1090     0x021F1090  data  ov031  a4
 *   func_020403F4 0x020403F4 arm
 *   func_0203FA08  0x0203FA08  arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_020450F0  0x020450F0  arm
 *   func_020452E8 0x020452E8 arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B294  0x0204B294  arm
 *   d_021F1048     0x021F1048  data  a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02035D20  0x02035D20  arm
 *   func_0204B454  0x0204B454  arm
 *   func_020061E4  0x020061E4  thumb
 */
#include "../../matched/include/Obj01128.h"
#include "../../matched/include/Obj07628.h"
#include "../../matched/include/Obj07624.h"
#include "../../matched/include/Obj06132.h"
#include "../../matched/include/Obj20404.h"
#include "../../matched/include/Obj09791.h"
#include "../../matched/include/Obj09792.h"
#include "../../matched/include/Obj06133.h"

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_WINOUT_SUB     (*(volatile u16 *)0x0400104A)
#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)0x04001050)
struct Ctx;
struct PmsDraw;
struct Obj_021EFEC0;
struct PrintSys;
struct Descriptor;
struct Src;
struct Bank;
struct GfFont;
struct MsgBank;
struct Rec;
struct BgTemplate;
struct Actor;
struct PtS;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Slot {
    u32 h;
    u8  f;
    u8  pad[3];
};

struct Obj_021EFEC0 {
    u32 w0;
    char pad0[0x40 - 4];
    u32 w40;
    char pad1[0x58 - 0x44];
    u32 b[3];
    struct Slot s[3];
    u32 w7c;
};

struct Obj_021F0420 {
    char pad0[0x4C];
    u32 a[3];
    char pad1[0x64 - 0x58];
    struct Slot s[3];
};

typedef signed int     s32;

typedef struct { u16 a, b, c, d; } Rect;

typedef signed short   s16;

typedef struct { s16 x, y; } Pt;

extern unsigned int func_02012138(const struct Ctx *);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049238(void *h);
extern struct PmsDraw *func_0202DB0C(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
extern void func_0202DE5C(struct PmsDraw *p, u8 v);
extern u32 func_02026474(void *obj);
extern u8 func_02173940(u8 *p);
extern void func_021F09A0(void *a, char *b);
extern void func_0204B6F4(struct Obj_021EFEC0 *o, u32 v, u32 flag);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02037174(void);
extern void func_0202DC08(struct Obj_021EFEC0 *p);
extern u32 func_020307B0(void *p);
extern void func_02037190(void);
extern void G2x_SetBlendBrightness_(volatile u16 *reg, int plane, int brightness);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0202DBC4(u8 *p);
extern void *func_02045770(struct Descriptor *a);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *a);
extern u32 func_02026454(void *obj);
extern void func_021BBA70(struct Ctx *ctx, struct Src *src, u16 *v, u8 kind);
extern void func_021F0680(char *p, u8 *b);
extern void func_0204B3DC(struct Obj_021EFEC0 *, unsigned int);
extern void func_021736C8(u8 *a, int v);
extern int func_021F0B98(char *o);
extern int func_021F0D64(char *p);
extern void func_021F0FE0(char *p, u8 *q);
extern void func_021F0C34(char *a, unsigned char *b);
extern int func_021F0DB0(u8 *a0, char *a1, u8 *a2);
extern void func_021F0EF4(char *p, u8 *q);
extern void func_02173934(u8 *p, int v);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern u32 func_0201C440(void *p);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern unsigned int func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 func_0204162C(int channel);
extern void *func_02049EF4(void *p, u32 a, u32 b, void **out, u16 d);
extern void func_02082D44(void *src, void *dst, int n);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(unsigned int);
extern u32 func_0203FA08(u32 a, u32 b, u32 c);
extern void func_0203FB44(u32, u32, u32);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_020452E8(struct Descriptor *d);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern struct Obj_021F0420 *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3B4(struct Obj_021F0420 *p);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_020061E4(u32 se);
u32 *func_021EFEC0(void *a);
void func_021EFFE8(u32 *p);
void func_021F0054(struct Obj_021EFEC0 *p, int mode);
void func_021F00D4(char *p, int mode);
void func_021F01F0(u32 *p);
void func_021F022C(char *p);
void func_021F0250(void *p, u32 h);
void func_021F0348(void *p);
void func_021F0378(u32 *p);
void func_021F0420(char *p);
void func_021F0430(struct Obj_021F0420 *p);
void func_021F0478(char *p);
void func_021F0490(char *p, u32 heap);
void func_021F04D4(char *p);
void func_021F04EC(int *p, void *h);
void func_021F056C(char *p);
int func_021F0584(int *p, u8 *flag);
void func_021F0628(char *p, int sel);
extern char str_021F10C0[];
extern u8 d_021F1038[];
extern const u8 d_021F1050[];
extern const u8 d_021F1070[];
extern const u8 d_021F1090[];
extern const Rect d_021F1048;



u32 *func_021EFEC0(void *a)
{
    void *s;
    u32 *w;
    void *h;
    u8 *q;
    u32 i;
    u32 tmp;

    s = (void *)func_02012138(a);
    w = func_02030734(0x15, 0x80, 1, str_021F10C0, 0x10F);
    w[0] = (u32)a;
    h = func_020490F4(0x59, 0x15);
    func_021F01F0(w);
    func_021F0250(w, (u32)h);
    func_021F0430((struct Obj_021F0420 *)((struct Obj_021EFEC0 *)w));
    func_021F0490((char *)w, (u32)h);
    func_021F04EC((int *)w, h);
    func_021F0378(w);
    func_02049238(h);
    w[0x1F] = (u32)func_0202DB0C(w[5], 1, w[0x10], w[0x11], 9, 3, 0x15);
    func_0202DE5C((void *)w[0x1F], 0);
    q = (u8 *)func_02026474(s);
    if (q != 0) {
        *((u8 *)w + 0x30) = func_02173940(q);
        func_021F09A0(w, (char *)(q + 0x30E0));
        if (*((u8 *)w + 0x30) != 0) {
            for (i = 0; (i < 5) ? 1 : 0; i++) {
                if (d_021F1038[i] == *((u8 *)w + 0x30)) {
                    func_0204B6F4((struct Obj_021EFEC0 *)(*(u32 *)((u8 *)w + 0x18 + i * 4)), 1, 1);
                    break;
                }
            }
        }
    }
    func_0203D34C(0, 0x15);
    func_02037174();
    REG_WINOUT_SUB = (u16)((REG_WINOUT_SUB & ~0x3F00) | (0x1F << 8));
    tmp = (REG_WINOUT_SUB & ~0x3F) | 0x1F;
    tmp |= 0x20;
    REG_WINOUT_SUB = (u16)tmp;
    REG_DB_DISPCNT_SUB = (REG_DB_DISPCNT_SUB & ~0xE000) | 0x8000;
    return w;
}



void func_021EFFE8(u32 *p)
{
    u8 *q;

    q = (u8 *)func_02026474((void *)func_02012138((const struct Ctx *)p[0]));
    if (q != 0)
        q[0x282E] = 0;
    func_0202DC08((struct Obj_021EFEC0 *)((void *)p[0x1F]));
    func_021F0420((char *)p);
    func_021F056C((char *)p);
    func_021F04D4((char *)p);
    func_021F0478((char *)p);
    func_021F0348(p);
    func_021F022C((char *)p);
    func_020307B0(p);
    REG_DB_BLDCNT_SUB = 0;
    func_02037190();
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
}



void func_021F0054(struct Obj_021EFEC0 *p, int mode)
{
    int i;

    func_02026474((void *)func_02012138((const struct Ctx *)p->w0));
    func_02037174();
    if (mode == 1)
        REG_DB_BLDCNT_SUB = 0;
    else
        G2x_SetBlendBrightness_(&REG_DB_BLDCNT_SUB, 0x3F, -8);
    func_0201C4E4((struct PrintSys *)p->w40);
    func_0202DBC4((void *)p->w7c);
    for (i = 0; i < 3; i++) {
        if (p->b[i] == 1) {
            u32 q = p->w40;
            if (p->s[i].f != 0) {
                if (func_0201C6C4((struct PrintSys *)q, (void *)((u32)func_02045770((struct Descriptor *)p->s[i].h))) == 0) {
                    func_02045334((struct Descriptor *)p->s[i].h);
                    p->s[i].f = 0;
                }
            }
        }
    }
}



void func_021F00D4(char *p, int mode)
{
    void *s;
    u8 *q;
    u8 *r;
    int res;

    s = (void *)func_02012138(((struct Obj01128 *)p)->f0);
    q = (u8 *)func_02026474(s);
    if (q != 0) {
        r = q + 0x2830;
        if (r[0xe] == 1) {
            func_021BBA70((struct Ctx *)q, 0, (u16 *)(r + 4), r[0xf]);
            r[0xe] = 0;
        }
        func_021F0680(p, q + 0x30E0);
        if (((struct Obj07628 *)q)->f351C >= 3)
            func_0204B3DC((struct Obj_021EFEC0 *)((struct Obj01128 *)p)->f2C, 1);
    }
    if (mode == 1) {
        res = func_021F0584((int *)p, q);
        if (q != 0 && res == 1) {
            switch (((struct Obj01128 *)p)->f30) {
            case 0:
                break;
            case 1:
                func_021736C8(q, 2);
                break;
            case 2:
                func_021736C8(q, 3);
                break;
            case 3:
                break;
            case 4:
                func_021736C8(q, 4);
                break;
            case 5:
                func_021736C8(q, 5);
                break;
            }
        }
        ((struct Obj01128 *)p)->f31 = func_021F0B98(p);
        if (((struct Obj01128 *)p)->f31 == 0)
            ((struct Obj01128 *)p)->f31 = func_021F0D64(p);
        if (((struct Obj01128 *)p)->f31 == 0 && q != 0)
            func_021F0FE0(p, q);
    }
    if (q != 0) {
        func_021F0C34((char *)q, (unsigned char *)p);
        if (mode == 1)
            func_021F0DB0(q, p, q + 0x30E0);
        func_021F0EF4(p, q + 0x30E0);
    }
    if (func_02026454(s) == 3 && q != 0)
        func_02173934(q, ((struct Obj01128 *)p)->f30);
}


/*
 * extent: trailing two-byte zero alignment padding.
 */
void func_021F01F0(u32 *p)
{
    ((struct Obj07624 *)p)->f14 = func_0204B100(12, 5, 21);
    ((struct Obj07624 *)p)->f40 = func_0201C440((void *)21);
    ((struct Obj07624 *)p)->f44 = func_0201D7EC(23, 0, 0, 0, 21);
    ((struct Obj07624 *)p)->f48 = func_02045B38(0, 2, 201, 21);
}


void func_021F022C(char *p)
{
    func_02045C04(((struct Obj06132 *)p)->f48);
    func_0201D83C(((struct Obj06132 *)p)->f44);
    func_0201C6EC(((struct Obj06132 *)p)->f40);
    func_0201C4C0(((struct Obj06132 *)p)->f40);
    func_0204B1CC(((struct Obj06132 *)p)->f14);
}



/*
 * volatile: 0x021F0288 ldr / 0x021F028E str of 0x04001000 (REG_DB_DISPCNT_SUB read-modify-write); 0x021F0294 strh to 0x04001050 (hardware registers)
 */
void func_021F0250(void *p, u32 h)
{
    u16 *pal;
    u8 *out;
    void *res;

    func_0203FCA0(5, (const struct BgTemplate *)d_021F1050, 0);
    func_0203FCA0(6, (const struct BgTemplate *)d_021F1070, 0);
    func_0203FCA0(7, (const struct BgTemplate *)d_021F1090, 0);
    func_02082A7C(0, (void *)0x06200000, 0x20000);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
    REG_DB_BLDCNT_SUB = 0;
    func_02049658((void *)h, 0xF, 7, 0, 0, 0, 0x15);
    func_020498F4((void *)h, 0x11, 7, 0, 0x800, 0, 0x15);
    pal = (u16 *)func_0204162C(6);
    res = func_02049EF4((void *)h, 0x12, 0, (void **)&out, 0x15);
    func_02082D44(out + 0xC, pal, 0x1C0);
    func_020307B0(res);
    func_02049B68((void *)h, 0x10, 4, 0, 0xA0, 0x15);
    func_02049B40(0x17, 5, 4, 0x1E0, 0x20, 0x15);
    func_02040588(4, 0);
    func_02040588(7, 1);
    func_02040588(6, 1);
    func_02040588(5, 1);
}


void func_021F0348(void *p)
{
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02040588(7, 0);
    func_020403F4(5);
    func_020403F4(6);
    func_020403F4(7);
}



/*
 * Both copy pointers are u16 element offsets (+0x2A0), not byte offsets:
 * `(u16 *)(out + 0xC) + 0x2A0` keeps the +0xC add apart, so the 0x540 byte
 * offset is built as `lsls rN, r7, #6` off the register holding 0x15
 * instead of folding with 0xC into a pooled 0x54C.
 */
void func_021F0378(u32 *p)
{
    void *h;
    u32 r;
    u16 *pal;
    void *res;
    u8 *out;
    int i;

    h = func_020490F4(0x53, 0x15);
    r = func_0203FA08(5, 0x80, 1);
    p[1] = r;
    func_02049658(h, 0x1C, 5, r, 0x80, 0, 0x15);
    pal = (u16 *)func_0204162C(5);
    res = func_02049EF4(h, 0x1D, 0, (void **)&out, 0x15);
    func_02082D44((u16 *)(out + 0xC) + 0x2A0, pal + 0x2A0, 0xC0);
    func_020307B0(res);
    for (i = 0; i < 0x60; i++)
        pal[0x2A0 + i] = (pal[0x2A0 + i] & 0xFFF) + r + 0xD000;
    func_02049B68(h, 0x1B, 4, 0x1A0, 0x20, 0x15);
    func_02049238(h);
}


void func_021F0420(char *p)
{
    func_0203FB44(5, ((struct Obj20404 *)p)->f4, 128);
}



/*
 * Re-reading the just-stored p->a[i] as the source of the second store
 * (instead of a local or a chained assignment) is what makes the compiler
 * form &p->a[i] before the call in a callee-saved register, which in turn
 * leaves room for only the first stack constant (7) to be hoisted.
 */
void func_021F0430(struct Obj_021F0420 *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        p->a[i] = func_020450F0(5, 1, (u8)(i * 0x38 / 8), 0x1D, 7, 0xF, 1);
        p->s[i].h = p->a[i];
        p->s[i].f = 0;
    }
}


void func_021F0478(char *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        func_020452E8(*(void **)(p + 0x4c + i * 4));
    }
}



void func_021F0490(char *p, u32 heap)
{
    ((struct Obj09791 *)p)->fC = func_0204AC18((void *)heap, 0x13, 1, 0, 0, 3, 0x15);
    ((struct Obj09791 *)p)->f8 = func_0204A6C8((void *)heap, 0xE, 0, 1, 0x15);
    ((struct Obj09791 *)p)->f10 = func_0204AF28((void *)heap, 0xC, 0xD, 0x15);
}


void func_021F04D4(char *p)
{
    func_0204ADA4(((struct Obj09792 *)p)->fC);
    func_0204A8D4(((struct Obj09792 *)p)->f8);
    func_0204AFD8(((struct Obj09792 *)p)->f10);
}



void func_021F04EC(int *p, void *h)
{
    Rect r;
    int i;

    r = d_021F1048;
    for (i = 0; i <= 4; i++) {
        r.a = i * 0x30 + 0x20;
        r.c = i;
        p[6 + i] = (int)(struct Obj *)func_0204B294((void *)p[5], p[2], p[3], p[4], &r, 1, 0x15);
    }
    r.c = 5;
    r.a = 0xF4;
    r.b = 0x9C;
    p[0xB] = (int)(struct Obj *)func_0204B294((void *)p[5], p[2], p[3], p[4], &r, 1, 0x15);
    func_0204B3DC((struct Obj_021EFEC0 *)((struct Obj_021F0420 *)p[0xB]), 0);
}


void func_021F056C(char *p) { int i; for (i=0;i<6;i++) func_0204B3B4((struct Obj_021F0420 *)(*(unsigned *)(p+i*4+0x18))); }



int func_021F0584(int *p, u8 *flag)
{
    u32 w;
    u32 h;
    Pt t;
    int i;
    s16 x0;
    s16 x1;
    s16 y0;
    s16 y1;

    if (func_02035D20(&w, &h) == 0)
        return 0;
    for (i = 0; i <= 4; i++) {
        func_0204B454((struct Actor *)p[6 + i], (struct PtS *)&t, 1);
        y0 = t.y - 10;
        y1 = t.y + 10;
        x1 = t.x + 10;
        x0 = t.x - 10;
        if (x0 < w && x1 > w && y0 < h && y1 > h) {
            if (i == 0 && flag != 0) {
                flag[0x282E] = 1;
                return 0;
            }
            func_021F0628((char *)p, i);
            func_020061E4(0x54B);
            return 1;
        }
    }
    return 0;
}



/*
 * The store to +0x30 is written in both arms of an if/else (keeps the
 * empty `b` to the next instruction), and the loop condition is a
 * `? 1 : 0` ternary (keeps the entry branch to the bottom test).
 */
void func_021F0628(char *p, int sel)
{
    int i;
    int v;

    v = d_021F1038[sel];
    if (v == ((struct Obj06133 *)p)->f30)
        ((struct Obj06133 *)p)->f30 = 0;
    else
        ((struct Obj06133 *)p)->f30 = v;
    for (i = 0; (i <= 4) ? 1 : 0; i++) {
        if (i == sel && ((struct Obj06133 *)p)->f30 != 0)
            func_0204B6F4((struct Obj_021EFEC0 *)((struct Obj_021F0420 *)(*(u32 *)(p + 0x18 + i * 4))), 1, 1);
        else
            func_0204B6F4((struct Obj_021EFEC0 *)((struct Obj_021F0420 *)(*(u32 *)(p + 0x18 + i * 4))), 0, 1);
    }
}
