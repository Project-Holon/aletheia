/*
 * function: func_021CF89C
 * address: 0x021CF89C
 * packet: pkt_ov093_021CF89C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EFCE4 0x021EFCE4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 */
#include "../include/Obj01894.h"
typedef unsigned char u8;
extern void *func_021EFCE4(char *, int);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int func_021D59B4(u8 *p, int k);
int func_021CF89C(u8 *p, void *q)
{
    if (func_021EFCE4(*(char * *)&((struct Obj01894 *)p)->f34, 7)) return 0;
    if (BTL_POKEPARAM_HasSick(q, 19)) return 0;
    if (func_021D59B4(q, 17) != 103) return 1;
    return 0;
}
