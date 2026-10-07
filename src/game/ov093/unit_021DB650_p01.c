/*
 * file:     unit_021DB650_p01.c
 * unit:     yes
 * function: func_021DB650, func_021DB6A4, func_021DB6C0, func_021DB6E4, func_021DB6FC, func_021DB734
 * address:  0x021DB650
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D70AC  0x021D70AC  thumb  ov093
 *   d_021F0B78     0x021F0B78  data   a2
 *   func_021D7320 0x021D7320 thumb ov093
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7324   0x021D7324  thumb
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
#include "../../matched/include/Obj13478.h"

struct Unk021D62A8;
struct QS;
struct QI;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern void *func_021C7CF4(int *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern unsigned char func_021D70AC(unsigned char *p);
extern void func_021D7320(struct QS *p, u32 v);
extern int func_021D775C(int);
extern u16 func_021D5B40(struct QI *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *,void *);
extern int func_021D76BC(int key, u32 val);
int func_021DB650(int a, int b, int c, int d, int e, u8 g);
void func_021DB6A4(void *a, int b, int c, int *d);
void func_021DB6C0(void *a,int b,int c,int *d);
/* 021DB6E4 shape F3: gate on func_021D775C(2) then func_021D7324 */ void func_021DB6E4(int a, int b, int c);
void func_021DB6FC(int a,void *b,int c);
void func_021DB734(int a, int b, int c, int d);
extern const u16 d_021F0B78[];


int func_021DB650(int a, int b, int c, int d, int e, u8 g)
{
    u32 i;

    if (func_021D62C4(func_021C7CF4((int *)b, g), 0x10) != 0)
        return 0;
    if (c == 5 && g == func_021D70AC((unsigned char *)a)) {
        for (i = 0; i < 13; i++) {
            if (e == d_021F0B78[i])
                return 0;
        }
        return 1;
    }
    return 0;
}


void func_021DB6A4(void *a, int b, int c, int *d)
{
    if (*d == 0) {
        func_021D7320(a, (u32)func_021DB650);
        *d = 1;
    }
}

void func_021DB6C0(void *a,int b,int c,int *d) { if(c==func_021D775C(2)) func_021DB6A4(a,b,c,d); }


/* 021DB6E4  shape F3: gate on func_021D775C(2) then func_021D7324 */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r3, r4, r5, lr}; adds r5, r0, #0; movs r0, #2; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021DB6FA; adds r0, r5, #0; bl func_021D7324; pop {r3, r4, r5, pc}.
 */
void func_021DB6E4(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D7324(a);
}

void func_021DB6FC(int a,void *b,int c) { unsigned char *p; if(c==func_021D775C(2) && func_021D5B40(func_021C7CF4(b,c))) { p=func_021C88A4(b,0x21,c); p[4]=c; func_021C88C8(b,p); } }


void func_021DB734(int a, int b, int c, int d)
{
    if (c == func_021D775C(2)) {
        unsigned short t = (unsigned short)func_021D775C(0x12);
        ((struct Obj13478 *)d)->f8 = 0;
        if (t == 0x16b && c == func_021D775C(2))
            ((struct Obj13478 *)d)->f8 = func_021D76BC(0x22, 0x13);
    }
}
