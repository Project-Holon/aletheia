/*
 * file:     net_whpipe_p07.c
 * unit:     yes
 * function: func_02177888, func_0217796C
 * address:  0x02177888
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021797A4     0x021797A4  data  a4
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   func_02177AEC  0x02177AEC  thumb  ov014
 *   func_021777FC  0x021777FC  thumb  ov014
 *   func_021795A4  0x021795A4  thumb  ov014
 *   func_02177ACC  0x02177ACC  thumb  ov014
 *   func_02178E68  0x02178E68  thumb  ov014
 *   func_02177704  0x02177704  thumb  ov014
 *   func_02179570  0x02179570  thumb  ov014
 *   func_0203D720  0x0203D720  arm
 *   func_0203D754  0x0203D754  arm
 *   func_02177C1C  0x02177C1C  thumb
 *   func_02177744  0x02177744  thumb
 *   func_02179664  0x02179664  thumb
 *   func_021793F8  0x021793F8  thumb
 */
#include "../../matched/include/Obj02358.h"
#include "../../matched/include/G_W.h"

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef struct Head Head;

struct Head {
    void (*fn)(Head *);
};

int func_02178E4C(void);
int func_02177AEC(void);
void func_021777FC(void);
unsigned short func_021795A4(void);
unsigned int func_02177ACC(void);
int func_02178E68(void);
void func_02177704(void);
int func_02179570(void (*cb)(int));
void func_0203D720(u32 a);
void func_0203D754(u32 a);
int func_02177C1C(void);
void func_02177744(void);
void func_02179664(unsigned char v);
void func_021793F8(void);
void func_02177888(u32 arg);
void func_0217796C(u32 arg);
extern struct W *g_021797A4;


void func_02177888(u32 arg)
{
    int mode = func_02178E4C();
    u8 *base = ((u8 *)g_021797A4);

    if (func_02177AEC() == 0)
        func_021777FC();
    if (((struct Obj02358 *)base)->fC6A == 0xFFFF)
        ((struct Obj02358 *)base)->fC6A = arg;
    if (base[0xCEC] != 0) {
        if (func_021795A4() == 0 && func_02177ACC() == 0)
            base[0xCEB] = 1;
        if (((struct Obj02358 *)base)->fC6A > arg)
            base[0xCEB] = 1;
    }
    if (func_02178E68() == 0x19)
        func_0203D720(0);
    switch (mode) {
    case 0:
        if (base[0xCE7] == 1)
            func_02177704();
        break;
    case 1:
        if (base[0xCE7] == 1 && func_02179570(0) != 0)
            return;
        if (base[0xCE7] == 2 && func_02179570(0) != 0)
            return;
        break;
    case 8:
    case 9:
        if (base != 0) {
            if (base[0xCEB] == 0)
                func_0203D754(func_02178E68());
            base[0xCEB] = 1;
        }
        break;
    }
}


void func_0217796C(u32 arg)
{
    Head *p = (Head *)*(u32 *)0x021797A4;
    if (p != 0 && p->fn != 0)
        p->fn(p);
    if (*(u32 *)0x021797A4 != 0)
        func_02177888(arg);
    if (*(u32 *)0x021797A4 != 0) {
        if (func_02177C1C() != 0)
            func_02177744();
    }
    if (*(u32 *)0x021797A4 != 0) {
        if (*(u16 *)((u8 *)*(u32 *)0x021797A4 + 0xC6C) != 0) {
            func_02179664(1);
            ((u8 *)*(u32 *)0x021797A4)[0xCF3] = 1;
            if (((u8 *)*(u32 *)0x021797A4)[0xCF4] == 0)
                *(u16 *)((u8 *)*(u32 *)0x021797A4 + 0xC6C) -= 1;
        } else {
            func_02179664(0);
            ((u8 *)*(u32 *)0x021797A4)[0xCF3] = 0;
        }
    }
    func_021793F8();
}
