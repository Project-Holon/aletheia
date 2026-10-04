/*
 * function: func_021FF648
 * address: 0x021FF648
 * packet: pkt_ov186_021FF648
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FFB70 0x021FFB70 thumb ov186
 *   func_021FF8E0 0x021FF8E0 thumb ov186
 */
#include "../include/Obj24855.h"
extern int func_021FFB70(int *,int);
extern void func_021FF8E0(void);
int func_021FF648(char *p)
{
    return func_021FFB70(*(int * *)&((struct Obj24855 *)p)->f5AC,(int)func_021FF8E0);
}
