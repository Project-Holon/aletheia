/*
 * file:     unit_021B23E0_p03.c
 * unit:     yes
 * function: func_021B2620, func_021B26DC, func_021B2724, func_021B275C
 * address:  0x021B2620
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021B60D8  0x021B60D8  data  ov013  a4
 *   d_021B4BD0  0x021B4BD0  data  ov013  a4
 *   func_021B25FC  0x021B25FC  arm  ov013
 *   func_02176E90  0x02176E90  arm  ov009
 *   d_021B4C0C  0x021B4C0C  data  ov013  a4
 *   func_021B2848  0x021B2848  arm  ov013
 *   func_020923B0 0x020923B0 arm
 */
#include "../../matched/include/G_Stat.h"
#include "../../matched/include/Obj09377.h"
#include "../../matched/include/G_Sess.h"

struct Msg;
typedef unsigned char u8;

typedef struct Ctx {
    u8 b0;
} Ctx;

typedef struct Stat Stat;

extern void func_021B25FC(u8 *a, u8 *b);
extern int func_02176E90(int i, u8 *p, int n);
extern int func_021B2848(u8 *o, struct Msg *p, int n);
extern void *func_020923B0(void *,int,unsigned int);
int func_021B2620(int *o, u8 *p);
void func_021B26DC(int x);
void func_021B2724(u8 *p,u8 v);
int func_021B275C(u8 *o, u8 *p);
extern Ctx d_021B60D8;
extern struct Stat d_021B4BD0;
extern char d_021B4C0C;


int func_021B2620(int *o, u8 *p)
{
    int cnt;
    u8 i;

    cnt = 0;
    func_021B25FC((u8 *)o, p);
    for (i = 0; i < 0x20; i++) {
        unsigned int m = (i != 0) ? (1 << i) : 1;
        if ((d_021B4BD0.mask & m) != 0 && i != d_021B60D8.b0) {
            p[9] = i;
            if (func_02176E90(i, p, 0x10) != 0)
                cnt++;
        }
    }
    if (p[10] == 1)
        o[2] = d_021B4BD0.mask;
    else if (p[10] == 0)
        o[2] = 0;
    return cnt == 0 ? -4 : 0;
}



void func_021B26DC(int x)
{
    u8 buf[16];

    buf[4] = 0xff;
    func_021B2848((u8 *)(&d_021B4C0C), (struct Msg *)buf, 4);
    buf[10] = x;
    func_021B2620((int *)(&d_021B4C0C), buf);
}


void func_021B2724(u8 *p,u8 v)
{
    func_020923B0(p,0,24);
    ((struct Obj09377 *)p)->f0=((int *)&d_021B60D8)[4];
    ((struct Obj09377 *)p)->fC=0;
    p[4]=v;
}



int func_021B275C(u8 *o, u8 *p)
{
    if (p[4] == 0xff && p[6] == 4) {
        func_021B2620((int *)o, p);
    } else if (func_02176E90(o[4], p, 0x10) == 0) {
        return 0;
    }
    return 1;
}
