/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F36E8, func_021F3724, func_021F3768
 * address:  0x021F36C0
 * region:   ov037
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_020127A4 0x020127A4 thumb
 *   func_0200B3A8  0x0200B3A8  thumb
 *   d_021F3840     0x021F3840  data ov037 a1
 *   d_021F3834     0x021F3834  data a1
 */
#include "../../matched/include/Obj13080.h"

struct Big;
struct Ctx;
struct Rec94;
struct SaveBlock;
typedef unsigned char  u8;

typedef signed int     s32;

typedef unsigned int   u32;

extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void *func_020127A4(struct SaveBlock *p);
extern u8 *func_0200B3A8(struct Rec94 *p, u32 a1);
void func_021F36C0(unsigned int a0, int a1, int a2);
void func_021F36E8(void *a, int v);
void func_021F3724(unsigned int a0, int a1);
void func_021F3768(unsigned int a0, unsigned short **a1);
extern signed char d_021F3840[][2];
extern unsigned char d_021F3834[][2];


void func_021F36C0(unsigned int a0, int a1, int a2)
{
    char *p = (char *)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((const struct Ctx *)a0)), 2);

    if (a1)
        ((struct Obj13080 *)p)->f14 = 1;
    if (a2)
        ((struct Obj13080 *)p)->f16 = 1;
}

void func_021F36E8(void *a, int v)
{
    void *save;
    int *p;
    save = func_020120F4(a);
    p = func_0200B3A4((struct Rec94 *)func_02012EC4(save), 3);
    func_020127A4(save);
    if (v) p[0] = 1;
    else p[0] = 0;
    if (p[0]) *((unsigned char *)p + 4) = 1;
    else *((unsigned char *)p + 4) = 0;
}


void func_021F3724(unsigned int a0, int a1)
{
    unsigned char *p = (unsigned char *)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((const struct Ctx *)a0)), 4);
    unsigned char i;

    for (i = 0; i < 3; i++)
        p[i] = 0;
    if (a1 & 1)
        p[0] = 1;
    if ((a1 >> 1) & 1)
        p[1] = 1;
    if ((a1 >> 2) & 1)
        p[2] = 1;
}


void func_021F3768(unsigned int a0, unsigned short **a1)
{
    unsigned int t = (unsigned int)func_02012EC4(func_020120F4((const struct Ctx *)a0));
    int *p = func_0200B3A4((struct Rec94 *)t, 6);
    unsigned short *q = (short unsigned int *)func_0200B3A8((struct Rec94 *)t, 6);
    int i;
    int j;
    int k;

    for (i = 0; i < 8; i++) {
        if (q[i] != 0) {
            p[i] = 1;
            *a1[i] = 1;
            for (j = 0; j < 2; j++) {
                k = d_021F3840[i][j];
                if (k != -1)
                    p[8 + k] = 1;
            }
        }
    }
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 2; j++) {
            if (p[8 + d_021F3834[i][j]] == 0)
                break;
        }
        if (j == 2)
            p[18 + i] = 1;
    }
    p[24] = 1;
}
