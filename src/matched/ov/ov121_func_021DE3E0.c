/*
 * unit: yes
 * function: func_021DE3E0, func_021DE4D8
 * address: 0x021DE3E0
 * packet: pkt_ov121_021DE3E0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DEEAC 0x021DEEAC thumb ov121
 *   func_021DE618 0x021DE618 thumb ov121
 *   func_021DE61C 0x021DE61C thumb ov121
 *   func_021DE6F8 0x021DE6F8 thumb ov121
 *   func_021DE690 0x021DE690 thumb ov121
 *   func_021DE958 0x021DE958 thumb ov121
 *   func_021DEDC8 0x021DEDC8 thumb ov121
 *   func_021DE70C 0x021DE70C thumb ov121
 *   func_021DE7FC 0x021DE7FC thumb ov121
 *   func_021DE7BC 0x021DE7BC thumb ov121
 *   func_021DE830 0x021DE830 thumb ov121
 *   func_021DE910 0x021DE910 thumb ov121
 *   func_021DE8D0 0x021DE8D0 thumb ov121
 */
#include "../include/Obj22913.h"
extern int func_021DEEAC(int *p, int value);
extern void func_021DE618(void);
extern void func_021DE61C(void *, int *, char *);
extern void func_021DE6F8(int, int, char *);
extern void func_021DE690(void *, int *, char *), func_021DE958(void *, int *, char *), func_021DEDC8(void *, int *, char *);
extern void func_021DE70C(void *, int *, char *);
extern void func_021DE7FC(void *a, int b, char *p);
extern void func_021DE7BC(void *, int *, char *);
extern void func_021DE830(void *, int *, char *), func_021DE910(void *, int *, char *), func_021DE8D0(void *, int *, char *);
int func_021DE3E0(void *p)
{
    if (func_021DEEAC(p, (int)func_021DE618)) return 0;
    if (func_021DEEAC(p, (int)func_021DE61C)) return 1;
    if (func_021DEEAC(p, (int)func_021DE6F8)) return 2;
    if (func_021DEEAC(p, (int)func_021DE690)) return 3;
    if (func_021DEEAC(p, (int)func_021DE958)) return 4;
    if (func_021DEEAC(p, (int)func_021DEDC8)) return 6;
    if (func_021DEEAC(p, (int)func_021DE70C)) return 7;
    if (func_021DEEAC(p, (int)func_021DE7FC)) return 8;
    if (func_021DEEAC(p, (int)func_021DE7BC)) return 9;
    if (func_021DEEAC(p, (int)func_021DE830)) return 10;
    if (func_021DEEAC(p, (int)func_021DE910)) return 11;
    if (func_021DEEAC(p, (int)func_021DE8D0)) return 12;
    return 0;
}
void *func_021DE4D8(char *p)
{
    return ((struct Obj22913 *)p)->f54;
}
