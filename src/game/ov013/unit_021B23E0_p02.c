/*
 * file:     unit_021B23E0_p02.c
 * unit:     yes
 * function: func_021B26DC, func_021B2724, func_021B275C
 * address:  0x021B26DC
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
 *   d_021B4C0C  0x021B4C0C  data  ov013  a4
 *   func_021B2848  0x021B2848  arm  ov013
 *   func_021B2620  0x021B2620  arm  ov013
 *   d_021B60D8 0x021B60D8 data a4
 *   func_020923B0 0x020923B0 arm
 *   func_02176E90  0x02176E90  arm  ov009
 */
#include "../../matched/include/Obj09377.h"
#include "../../matched/include/G_Sess.h"

struct Msg;
typedef unsigned char u8;

extern int func_021B2848(u8 *o, struct Msg *p, int n);
extern int func_021B2620(int *o, u8 *p);
extern void *func_020923B0(void *,int,unsigned int);
extern int func_02176E90(int i, u8 *p, int n);
void func_021B26DC(int x);
void func_021B2724(u8 *p,u8 v);
int func_021B275C(u8 *o, u8 *p);
extern char d_021B4C0C;
extern struct Sess d_021B60D8;


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
