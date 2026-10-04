/*
 * unit: yes
 * function: func_021BAA54, func_021BAA84, func_021BAA98, func_021BAAA4, func_021BAAB0, func_021BAABC
 * address: 0x021BAA54
 * packet: pkt_ov181_021BAA54
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA594 0x021BA594 thumb ov181
 */
#include "../include/Obj10725.h"
#include "../include/Obj14414.h"
#include "../include/Obj24511.h"
#include "../include/Obj24512.h"
#include "../include/Obj24513.h"
extern void func_021BA594(char *, unsigned char *);
int func_021BAA54(char *p, unsigned char *q)
{
    if (((struct Obj10725 *)p)->f2EC == 0) {
        ((struct Obj10725 *)p)->f2CD = q[7];
        ((struct Obj10725 *)p)->f2EC = 2;
    }
    func_021BA594(p, q);
    if (q[0x16] != 1)
        return 1;
    return 0;
}
int func_021BAA84(char *p, unsigned char *q)
{
    ((struct Obj14414 *)p)->f2CD = q[7];
    ((struct Obj14414 *)p)->f2EC = 3;
    return 1;
}
int func_021BAA98(char *p)
{
    ((struct Obj24511 *)p)->f2E0 = 1;
    return 0;
}
int func_021BAAA4(char *p)
{
    ((struct Obj24512 *)p)->f2E0 = 0;
    return 0;
}
int func_021BAAB0(char *p)
{
    ((struct Obj24513 *)p)->f2EC = 5;
    return 1;
}
int func_021BAABC(void)
{
    return 1;
}
