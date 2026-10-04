/*
 * function: func_02177F48
 * address:  0x02177F48
 * packet:   pkt_ov014_02177F48
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A4     0x021797A4  data  ov014  a4
 *   d_02179678     0x02179678  data  a1
 *   func_02177AA8  0x02177AA8  thumb  ov014
 *   func_020056EC  0x020056EC  thumb
 *   func_0217778C  0x0217778C  thumb  ov014
 *   func_02179288  0x02179288  thumb  ov014
 *   func_0217727C  0x0217727C  thumb
 *   func_02177EFC  0x02177EFC  thumb
 */
#include "../include/Obj04956.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *g_021797A4;
extern u8 d_02179678[3];
int func_02177AA8(void);
u32 func_020056EC(u32 n);
void func_0217778C(void);
int func_02179288(int mode, u16 a, u16 b, u16 c);
void func_0217727C(u32 *p, u32 v);
void func_02177EFC(u8 *a);

void func_02177F48(u8 *a)
{
    u8 tab[3];
    if (func_02177AA8() != 0) {
        tab[0] = d_02179678[0];
        tab[1] = d_02179678[1];
        tab[2] = d_02179678[2];
        a[0xCF1] = func_020056EC(3);
        if (a[0xCF1] >= 3)
            a[0xCF1] = 0;
        func_0217778C();
        if (func_02179288(0, ((struct Obj04956 *)a)->fC68, tab[a[0xCF1]], 1) != 0) {
            a[0xCF2] = func_020056EC(0x98) + 0x3C;
            func_0217727C((u32 *)g_021797A4, (u32)func_02177EFC);
        }
    }
}
