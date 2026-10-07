/*
 * file:     unit_02179CAC_p01.c
 * unit:     yes
 * function: func_02179CAC, func_02179CE4, func_02179D14
 * address:  0x02179CAC
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0217AB80  0x0217AB80  data  ov015
 *   d_0217ABA0  0x0217ABA0  data  ov015
 *   func_02179D3C  0x02179D3C  thumb  ov015
 *   func_0217A014 0x0217A014 arm ov015
 *   func_0217A5A4 0x0217A5A4 arm ov015
 */
#include "../../matched/include/G_s_aba0.h"
#include "../../matched/include/G_State.h"

typedef unsigned char u8;

extern int func_02179D3C(void);
extern unsigned int func_0217A014(void);
extern unsigned int func_0217A5A4(void);
int func_02179CAC(void);
void func_02179CE4(void);
void func_02179D14(void);
extern struct State d_0217AB80;
extern struct s_aba0 d_0217ABA0;


int func_02179CAC(void)
{
    if (((unsigned char *)&d_0217AB80)[0xc] == 0)
        return 0;
    if (((unsigned char *)&d_0217ABA0)[5] != 0)
        return 1;
    if (((unsigned char *)&d_0217AB80)[0x1d] == 1) {
        if (func_02179D3C() == 0)
            return 1;
    }
    return 0;
}

void func_02179CE4(void) { d_0217AB80.f28 = func_0217A014(); ((u8 *)&d_0217ABA0)[7] = func_0217A5A4(); d_0217AB80.f29 = 1; ((u8 *)&d_0217ABA0)[2] = 0; ((u8 *)&d_0217ABA0)[3] = 14; if (d_0217AB80.f28 != 1) d_0217AB80.f14 = 1; }

void func_02179D14(void) { ((u8 *)&d_0217AB80)[0x1c] = func_0217A014(); ((u8 *)&d_0217ABA0)[7] = func_0217A5A4(); }
