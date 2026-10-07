/*
 * file:     unit_021BB954_p04.c
 * unit:     yes
 * function: func_021BBE50, func_021BBE7C, func_021BBEB4, func_021BC06C
 * address:  0x021BBE50
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   unit_0204B92C  0x0204B92C  arm
 *   unit_0204B3DC  0x0204B3DC  arm
 *   data_021C3B30 0x021C3B30 data a4
 *   data_021C39F0 0x021C39F0 data a4
 *   func_021BAC24 0x021BAC24 thumb ov099
 *   func_02020D10 0x02020D10 thumb
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045374 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_0201A4D4 0x0201A4D4 thumb
 *   func_0200AE3C 0x0200AE3C thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045334 0x02045334 arm
 *   func_0201A570 0x0201A570 thumb
 */
#include "../../matched/include/Obj00976.h"
#include "../../matched/include/Obj04412.h"

struct Obj;
struct Desc;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Reg;
struct U16Vec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32_021BBE50;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef struct {
    char pad[0x150];
    void *arr[12];
} S;

typedef unsigned int u32_021BBE7C;

struct Pair { u32_021BBE7C a, b; };

typedef unsigned int u32_021BBEB4;

struct O {
    u8 p0[0xdc];
    void *fdc, *fe0, *fe4, *fe8, *fec, *ff0, *ff4;
    u8 pf8[0x19c - 0xf8];
    void *f19c;
    u8 p1a0[0x1334 - 0x1a0];
    u32_021BBEB4 f1334;
    u8 p1338[0x1344 - 0x1338];
    void **f1344;
    void **f1348;
};

extern void unit_0204B92C(struct Obj *p, unsigned int v);
extern void unit_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021BAC24(char *, struct Desc *, struct Pair *, int, int, u32_021BBE7C);
extern void func_02020D10(u8 *p, u32_021BBE7C v);
extern int func_021BA8BC(void *);
extern u32_021BBEB4 func_020450F0(u32_021BBEB4 layer, u32_021BBEB4 a, u32_021BBEB4 b, u32_021BBEB4 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern void func_020456F8(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern void func_0201F73C(void *,int,int,int);
extern void func_0201DD68(void);
extern u8 *func_0201A4D4(u8 *a0, u32_021BBEB4 a1, u16 a2, u32_021BBEB4 a3);
extern void *func_0200AE3C(struct Reg *p, u32_021BBEB4 heap);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045CAC(struct MsgBank *,u32_021BBEB4,void *);
extern void func_0201C7D0(void *,int,s16,void *,void *,u32_021BBEB4);
extern void func_02045334(struct Descriptor *);
extern void func_0201A570(void *);
void func_021BBE50(S *s);
void func_021BBE7C(char *p);
void func_021BBEB4(struct O *p, int mask, u32_021BBEB4 a, int mode);
void func_021BC06C(char *p);
extern char data_021C3B30[];
extern struct Pair data_021C39F0[];


void func_021BBE50(S *s)
{
    int i;

    for (i = 0; i < 12; i++) {
        if (s->arr[i] != 0) {
            unit_0204B92C(s->arr[i], 0);
            unit_0204B3DC(s->arr[i], 0);
        }
    }
}

void func_021BBE7C(char *p)
{
    *(u16 *)(data_021C3B30 + 0x14) = 2;
    *(u16 *)(data_021C3B30 + 0x16) = 2;
    func_021BAC24(p, (struct Desc *)(data_021C3B30 + 4), data_021C39F0, 2, 5, 18);
    func_02020D10(*(u8 * *)&((struct Obj00976 *)p)->fBC, 1);
}

void func_021BBEB4(struct O *p, int mask, u32_021BBEB4 a, int mode)
{
    int base;
    int i;
    u32_021BBEB4 flags;
    void *t;
    u32_021BBEB4 w;
    base = 4;
    a = (a == 1) ? 1 : 0;
    p->f19c = (void *)func_021BA8BC(p->f19c);

    if (mode == 1) p->f19c = (void *)func_020450F0(2, 2, 5, 26, 12, 15, 1); else p->f19c = (void *)func_020450F0(2, 2, 5, 26, 16, 15, 1);
    func_02043B5C(func_02045770(p->f19c), 255);
    func_020456F8(p->f19c);
    func_02045374(p->f19c);
    func_0201F73C(p->f19c, 1, (u16)p->f1334, 14);
    func_0201DD68();
    p->f1344 = (void **)func_0201A4D4((u8 *)p->f1348, (u32_021BBEB4)p->fdc, 33, a);
    if (mode == 0) {
        t = func_0200AE3C((struct Reg *)p->f1348, 33);
        func_0201C7A4(func_02045770(p->f19c), 0, 0, t, p->fe8);
        func_02045808(t);
    } else if (mode != 1) {
        func_02045CAC(p->fe0, (mode == 2) ? 0x66 : 0x67, p->ff0);
        func_0201C7A4(func_02045770(p->f19c), 0, 0, p->ff0, p->fe8);
    }
    if (mode == 1) base = 0;
    for (i = 0; i < 6; i++) {
        if (mask & (1 << i)) flags = 0x41; else flags = 0x11;
        flags <<= 6;
        func_0201C7D0(func_02045770(p->f19c), 0, (s16)((base + i * 2) * 8), p->f1344[i + 1], p->fe8, flags);
        func_0201C7D0(func_02045770(p->f19c), 0x70, (s16)((base + i * 2) * 8), p->f1344[i + 7], p->fe8, flags);
    }
    func_02045334(p->f19c);
}

void func_021BC06C(char *p)
{
    func_0201A570(((struct Obj04412 *)p)->f1344);
    *(int *)&((struct Obj04412 *)p)->f1344 = 0;
    *(int *)&((struct Obj04412 *)p)->f19C = func_021BA8BC(((struct Obj04412 *)p)->f19C);
}
