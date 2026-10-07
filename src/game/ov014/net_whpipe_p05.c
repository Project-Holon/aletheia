/*
 * file:     net_whpipe_p05.c
 * unit:     yes
 * function: func_0217758C, func_021775AC, func_021775BC, func_02177614
 * address:  0x0217758C
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
 *   g_021797A4 0x021797A4 data a4
 *   func_02177560  0x02177560  thumb  ov014
 *   func_0217933C  0x0217933C  thumb  ov014
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   func_021785B4  0x021785B4  thumb  ov014
 *   func_021773E0  0x021773E0  thumb  ov014
 *   func_02179498  0x02179498  thumb  ov014
 *   func_0217727C  0x0217727C  thumb  ov014
 *   func_02177660  0x02177660  thumb  ov014
 */
#include "../../matched/include/G_W.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_02177560(void);
extern void func_0217933C(void *cb);
extern int func_02178E4C(void);
extern int func_021785B4(u32 a, u16 *b, u32 c);
extern int func_021773E0(u8 *p);
extern int func_02179498(void);
extern void func_0217727C(u32 *p, u32 v);
extern void func_02177660(u8 *p);
void func_0217758C(u8 *p);
int func_021775AC(int a, int b, int c);
int func_021775BC(int arg);
void func_02177614(u8 *p);
extern struct W *g_021797A4;

void func_0217758C(u8 *p)
{
    p[0xCEA] = 0;
    p[0xCEF] = 0;
    p[0xCEB] = 0;
    p[0xCEC] = 0;
    p[0xCE9] = 0;
    p[0xCE8] = 0;
}

/*
 * interface: original preserves incoming r0-r2 and spends r3 on the
 * indirect callback target; legacy void(void) callers omit those inputs.
 * void(void) callback spelling changes the target register to r0 (run 2).
 */
int func_021775AC(int a, int b, int c)
{
    return (*(int (**)(int, int, int))(((u8 *)g_021797A4) + 4))(a,b,c);
}


int func_021775BC(int arg)
{
    u8 *w = ((u8 *)g_021797A4);

    if (w == 0)
        return 0;
    func_0217758C(w);
    if (arg != 0)
        func_02177560();
    func_0217933C(func_021775AC);
    w[0xCE8] = 1;
    if (func_02178E4C() == 1 && func_021785B4((u32)func_021773E0, 0, 0) != 0)
        return 1;
    return 0;
}


void func_02177614(u8 *p)
{
    if (func_02178E4C() == 1 && func_02179498() != 0) {
        p[0xCF5] = 0xFF;
        func_0217727C((u32 *)((u8 *)g_021797A4), (u32)func_02177660);
    }
    if (func_02178E4C() == 9) {
        p[0xCF5] = 0xFF;
        func_0217727C((u32 *)((u8 *)g_021797A4), (u32)func_02177660);
    }
}
