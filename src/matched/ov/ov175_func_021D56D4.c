/*
 * function: func_021D56D4
 * address: 0x021D56D4
 * packet: pkt_ov175_021D56D4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   func_02012DAC 0x02012DAC thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021DBC04 0x021DBC04 thumb ov175
 *   func_021DBDAC 0x021DBDAC thumb ov175
 *   func_021D9F04 0x021D9F04 thumb ov175
 *   func_021DA36C 0x021DA36C thumb ov175
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021D61CC 0x021D61CC thumb ov175
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 * The original loads p[12] before the otherwise parameterless DA36C.
 */
#include "../include/Obj08273.h"
typedef unsigned char u8;
extern void func_021E8738(int *, int, int, int);
extern void func_021E8AB4(unsigned, unsigned);
extern int func_02012DAC(int);
extern int func_02012DD0(u8 *);
extern void func_021DBC04(char *, unsigned, int);
extern int func_021DBDAC(char *);
extern int func_021D9F04(char *, void *, void *);
extern void func_021DA36C(int);
extern void func_021E8AA0(int *, int);
extern void func_021D61CC(void *, unsigned **, char *);
extern int func_021E8844(const int *);
extern void func_021E8AB8(unsigned);
void func_021D56D4(unsigned sys, int *state, int *p)
{
    char *q = (char *)p[16];
    switch (*state) {
    case 0:
        func_021E8738((int *)p[9], p[4], 40, 2);
        func_021E8AB4(sys, 1);
        *state = 7;
        break;
    case 1:
        func_02012DAC(**(int * *)&((struct Obj08273 *)q)->f8);
        *state = 2;
        break;
    case 2:
        if (func_02012DD0((u8 *)**(int * *)&((struct Obj08273 *)q)->f8) == 2) *state = 3;
        break;
    case 3:
        func_021E8738((int *)p[9], p[4], 37, 2);
        *state = 7;
        func_021E8AB4(sys, 4);
        break;
    case 4:
        if (**(int * *)&((struct Obj08273 *)q)->f20 == 0) {
            func_021DBC04((char *)p[12], 2, 0);
            *state = 5;
        }
        break;
    case 5:
        if (func_021DBDAC((char *)p[12])) {
            **(int **)((char *)p[16] + 0x20) = 0x708;
            *state = 6;
            func_021D9F04((char *)p[12], (void *)1, 0);
        }
        break;
    case 6:
        func_021DA36C(p[12]);
        ((struct Obj08273 *)q)->f4 = 0;
        func_021E8AA0((int *)sys, (int)func_021D61CC);
        break;
    case 7:
        if (func_021E8844((int *)p[9])) func_021E8AB8(sys);
        break;
    }
}
