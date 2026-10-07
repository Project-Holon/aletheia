/*
 * file:     mb_comm_sys_p15.c
 * unit:     yes
 * function: func_021F116C, func_021F1174, func_021F1184, func_021F11BC, func_021F11C4
 * address:  0x021F116C
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203E758 0x0203E758 arm
 *   func_020173E8  0x020173E8  thumb
 *   func_02017550  0x02017550  thumb
 */
#include "../../matched/include/Obj22296.h"

struct Sav;
typedef struct {
    unsigned short b00 : 1;
    unsigned short b01 : 1;
    unsigned short b02 : 1;
    unsigned short b03 : 1;
    unsigned short b04 : 1;
    unsigned short b05 : 1;
    unsigned short b06 : 1;
    unsigned short b07 : 1;
    unsigned short b08 : 1;
    unsigned short b09 : 1;
    unsigned short b10 : 1;
    unsigned short b11 : 1;
    unsigned short b12 : 1;
    unsigned short b13 : 1;
    unsigned short b14 : 1;
    unsigned short b15 : 1;
} Ov107Flags_021F116C;

typedef struct {
    unsigned char pad00[0xC];
    void *f0C;
    unsigned char pad10[8];
    Ov107Flags_021F116C f18;
    Ov107Flags_021F116C f1A;
    unsigned char pad1C[8];
    unsigned int f24;
} Ov107Ctx_021F116C;

typedef struct {
    unsigned char f00;
    unsigned char pad01;
    unsigned short f02;
} Ov107List;

typedef struct {
    unsigned short b0 : 1;
    unsigned short b1 : 1;
    unsigned short b2 : 1;
    unsigned short rest : 13;
} Ov107Flags_021F1184;

typedef struct {
    unsigned char pad00[0x10];
    Ov107List *f10;
    unsigned char pad14[4];
    Ov107Flags_021F1184 f18;
} Ov107Ctx_021F1184;

typedef unsigned int   u32;

typedef struct {
    unsigned short b00 : 1;
    unsigned short b01 : 1;
    unsigned short b02 : 1;
    unsigned short b03 : 1;
    unsigned short b04 : 1;
    unsigned short b05 : 1;
    unsigned short b06 : 1;
    unsigned short b07 : 1;
    unsigned short b08 : 1;
    unsigned short b09 : 1;
    unsigned short b10 : 1;
    unsigned short b11 : 1;
    unsigned short b12 : 1;
    unsigned short b13 : 1;
    unsigned short b14 : 1;
    unsigned short b15 : 1;
} Ov107Flags_021F11BC;

typedef struct {
    unsigned char pad00[0xC];
    void *f0C;
    unsigned char pad10[8];
    Ov107Flags_021F11BC f18;
    Ov107Flags_021F11BC f1A;
    unsigned char pad1C[8];
    unsigned int f24;
} Ov107Ctx_021F11BC;

typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern void func_0203E758(int,int,int,int);
u32 func_020173E8(void);
void func_02017550(struct Sav *);
int func_021F116C(Ov107Ctx_021F116C *p);
void func_021F1174(int a,int b,int c);
void func_021F1184(Ov107Ctx_021F1184 *p);
int func_021F11BC(Ov107Ctx_021F11BC *p);
u8 func_021F11C4(u8 *p);


int func_021F116C(Ov107Ctx_021F116C *p)
{
    return p->f1A.b01;
}

void func_021F1174(int a,int b,int c) { func_0203E758(b,c,2,1); }


void func_021F1184(Ov107Ctx_021F1184 *p)
{
    Ov107List *list;
    unsigned char i;

    list = p->f10;
    list->f00 = 0;
    list->f02 = 0;
    for (i = 0; i < 6; i++) {
        func_02017550((struct Sav *)((unsigned char *)p->f10 + i * func_020173E8() + 4));
    }
    p->f18.b1 = 0;
    p->f18.b2 = 0;
}


int func_021F11BC(Ov107Ctx_021F11BC *p)
{
    return p->f18.b01;
}


u8 func_021F11C4(u8 *p) { return *(u8 *)(((struct Obj22296 *)p)->f10); }
