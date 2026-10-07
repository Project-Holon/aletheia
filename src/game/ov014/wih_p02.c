/*
 * file:     wih_p02.c
 * unit:     yes
 * function: func_02177CE4, func_02177D0C, func_02177D58
 * address:  0x02177CE4
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
 *   g_021797A4 0x021797A4 data ov014 a4
 *   func_02178E4C 0x02178E4C thumb ov014
 *   func_02178E84 0x02178E84 thumb ov014
 *   func_0217727C 0x0217727C thumb ov014
 *   func_02177C4C 0x02177C4C thumb ov014
 *   func_0217933C  0x0217933C  thumb  ov014
 *   func_021775AC  0x021775AC  thumb  ov014
 *   func_0203D798  0x0203D798  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_020862F0  0x020862F0  arm
 *   func_02178E28  0x02178E28  thumb  ov014
 *   func_021795D4  0x021795D4  thumb  ov014
 */
#include "../../matched/include/Obj12469.h"
#include "../../matched/include/Obj19335.h"
#include "../../matched/include/Obj19336.h"
#include "../../matched/include/Obj19337.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern int func_02178E4C(void);
extern int func_02178E84(void);
extern void func_0217727C(unsigned int *p, unsigned int v);
extern void func_02177C4C(unsigned char *p);
void func_0217933C(void *fn);
int func_021775AC(int a, int b, int c);
void *func_0203D798(void);
u16 func_0203F1FC(const u8 *src, u32 len);
void func_020862F0(void *p, u32 n);
void func_02178E28(void *p, u32 n);
void func_021795D4(int a, int b, int c, int d);
void func_02177CE4(void);
int func_02177D0C(int a);
void func_02177D58(u8 *buf, u32 len);
extern unsigned char *g_021797A4;

void func_02177CE4(void) { if (func_02178E4C() == 1 && func_02178E84() != 0) func_0217727C((unsigned int *)g_021797A4, (unsigned int)func_02177C4C); }


int func_02177D0C(int a)
{
    u8 *p = g_021797A4;
    if (((struct Obj12469 *)p)->f0 != 0)
        return 0;
    if (a != 0)
        p[0xCE6] = 0xff;
    func_0217933C(func_021775AC);
    g_021797A4[0xCE8] = 1;
    func_0217727C((u32 *)g_021797A4, (u32)func_02177CE4);
    return 1;
}


void func_02177D58(u8 *buf, u32 len)
{
    u8 *p = g_021797A4;
    u8 *st = func_0203D798();
    if (p != 0 && st != 0) {
        ((struct Obj19335 *)buf)->f0 = func_0203F1FC(buf + 2, len - 2);
        func_020862F0(buf, len);
        if (func_02178E4C() == 1) {
            func_02178E28(buf, (u16)len);
            return;
        }
        func_021795D4((int)buf, len, ((struct Obj19336 *)st)->f50, ((struct Obj19337 *)p)->fC68);
    }
}
