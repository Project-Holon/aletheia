/*
 * file:     unit_02184C78_p08.c
 * unit:     yes
 * function: func_02185B88, func_02185B9C, func_02185BFC
 * address:  0x02185B88
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188CB4 0x02188CB4 thumb ov021
 *   func_021A3074 0x021A3074 thumb ov021
 *   func_0216DAC8 0x0216DAC8 thumb ov010
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B37C  0x0200B37C  thumb
 *   func_0200B394  0x0200B394  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02049250  0x02049250  arm
 *   func_020493D4  0x020493D4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02185D38  0x02185D38  thumb  ov020
 */
#include "../../matched/include/Obj05969.h"

struct Obj00020;
struct Big;
struct Rec94;
struct Struct_0200B37C;
struct ArcFile;
struct Desc;
struct Obj;
struct Ctx;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct { int id; u16 v; u16 pad; } Ent;

typedef signed int     s32;

typedef unsigned int   u32;

typedef struct { int f[7]; } S7;

extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern void func_0216DAC8(unsigned int *, unsigned int);
u8 *func_02012EC4(struct Big *p);
void func_0200B37C(struct Struct_0200B37C *p);
s32 *func_0200B394(struct Rec94 *p, s32 value);
void *func_020490F4(unsigned int id, unsigned int heap);
void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
u32 func_020493D4(struct ArcFile *arc, u32 member);
u32 func_020307B0(void *p);
void func_02049238(void *h);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
void *func_020120F4(const struct Ctx *p);
void func_02185D38(void);
void func_02185B88(void *p, unsigned int v);
void func_02185B9C(int a0, int id);
void *func_02185BFC(void *p, int a1, S7 *a2, int a3, int a4);

void func_02185B88(void *p, unsigned int v)
{
    func_0216DAC8(func_021A3074(func_02188CB4(p)), v);
}


void func_02185B9C(int a0, int id)
{
    unsigned n, i;
    int r0 = (int)func_02012EC4((struct Big *)a0);
    void *h;
    int c = 0x8001;
    Ent *e;

    func_0200B37C((struct Struct_0200B37C *)r0);
    h = func_020490F4(0x65, c);
    e = func_02049250(h, 0, c);
    n = func_020493D4(h, 0) >> 3;
    for (i = 0; i < n; i++) {
        if (id == e[i].id) {
            func_0200B394((struct Rec94 *)r0, e[i].v);
            break;
        }
    }
    func_020307B0(e);
    func_02049238(h);
}


/*
 * Allocator with callback, copies a seven-word record then fills link fields.
 */
void *func_02185BFC(void *p, int a1, S7 *a2, int a3, int a4)
{
    void *r0v = func_020122C0(p, 0, func_02185D38, 0x30);
    char *r4 = func_020124E8(r0v);

    *(S7 *)r4 = *a2;
    ((struct Obj05969 *)r4)->f1C = (int)p;
    ((struct Obj05969 *)r4)->f20 = (int)func_020120F4(p);
    ((struct Obj05969 *)r4)->f24 = a1;
    ((struct Obj05969 *)r4)->f28 = a3;
    ((struct Obj05969 *)r4)->f2C = a4;
    return r0v;
}
