/*
 * function: func_021E09E0
 * address: 0x021E09E0
 * packet: pkt_ov170_021E09E0
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021ED544 0x021ED544 thumb ov170
 *   func_021DE428 0x021DE428 thumb ov170
 *   func_021DDAE8 0x021DDAE8 thumb ov170
 *   func_021DE66C 0x021DE66C thumb ov170
 *   func_020061E4 0x020061E4 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj08234.h"
#include "../include/Obj23878.h"
extern void func_021ED544(char *p, int a);
extern void func_021DE428(unsigned char *p, unsigned a, unsigned b);
extern int func_021DDAE8(unsigned char *p);
extern void func_021DE66C(char *p, void *a);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
int func_021E09E0(char *p)
{
    char *s;
    s = *(char * *)&((struct Obj00000 *)p)->f2C + 0x58;
    switch (((struct Obj08234 *)s)->fC) {
    case 0:
        func_021ED544(p, 7);
        func_021DE428((unsigned char *)p, ((struct Obj00000 *)p)->f16, ((struct Obj23878 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA17E);
        ((struct Obj08234 *)s)->fC = 1;
        break;
    case 1:
        if (func_021DDAE8((unsigned char *)p) == 0) {
            func_021DE66C(p, ((struct Obj08234 *)s)->f8);
            func_021ED544(p, 6);
            func_020061E4(0x667);
            ((struct Obj08234 *)s)->fC = 0;
            return 0;
        }
        break;
    }
    return 1;
}
