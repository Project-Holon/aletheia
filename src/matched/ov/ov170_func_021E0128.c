/*
 * function: func_021E0128
 * address:  0x021E0128
 * packet:   pkt_ov170_021E0128
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021ED55C 0x021ED55C thumb
 *   func_021EF770 0x021EF770 thumb
 *   func_021EDF5C 0x021EDF5C thumb
 *   func_02041EE4 0x02041EE4 arm
 *   func_021EC804 0x021EC804 thumb
 *   func_021EE26C 0x021EE26C thumb
 *   func_021EF5C4 0x021EF5C4 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj23873.h"
#include "../include/Obj23874.h"
#include "../include/Obj23875.h"
#include "../include/Obj23876.h"
#include "../include/Obj23877.h"

struct WinMgr;
extern void func_021ED55C(char *p, int flag);
extern int func_021EF770(struct WinMgr *mgr);
extern void func_021EDF5C(char *p);
extern void func_02041EE4(unsigned index, unsigned a, unsigned b);
extern void func_021EC804(char *p, short dx);
extern void func_021EE26C(char *p, int d);
extern int func_021EF5C4(struct WinMgr *mgr);

int func_021E0128(char *p)
{
    if (((struct Obj23873 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f66 == 0x17) {
        func_021ED55C(p, 1);
        if (func_021EF770(*(struct WinMgr * *)&((struct Obj23874 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74) == 1)
            func_021EDF5C(p);
        ((struct Obj23875 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f66 = 0;
        return 0;
    }
    func_02041EE4(3, 1, 8);
    func_021EC804(p, -8);
    func_021EE26C(*(char * *)&((struct Obj00000 *)p)->f2C, -8);
    func_021EF5C4(*(struct WinMgr * *)&((struct Obj23876 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f74);
    (((struct Obj23877 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f66)++;
    return 1;
}
