/*
 * function: func_021DD500
 * address: 0x021DD500
 * packet: pkt_ov171_021DD500
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: larger followers 0x021DD51C and 0x021DD558 have separate files.
 * symbols:
 *   func_021DE080 0x021DE080 thumb ov171
 */
#include "../include/Obj00347.h"
typedef unsigned char  u8;
extern void func_021DE080(u8 *p, int i, int value);
int func_021DD500(char *p, int i, int n, int v)
{
    func_021DE080((u8 *)p, i, n);
    ((struct Obj00347 *)p)->fC64 = i;
    ((struct Obj00347 *)p)->fC68 = v;
    return 3;
}
