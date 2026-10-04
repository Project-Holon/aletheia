/*
 * function: func_021DE910
 * address: 0x021DE910
 * packet: pkt_ov121_021DE910
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02157E78 0x02157E78 thumb ov010
 *   func_02157E6C 0x02157E6C thumb ov010
 *   func_021DEEA4 0x021DEEA4 thumb ov121
 *   func_021DE8D0 0x021DE8D0 thumb ov121
 */
#include "../include/Obj08102.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_02157E78(u8 *p);
extern unsigned char func_02157E6C(char *p);
extern void func_021DEEA4(u32 *p, void *f);
extern void func_021DE8D0(void *, int *, char *);
void func_021DE910(void *a, int *state, char *p)
{
    int result;
    func_02157E78(((struct Obj08102 *)p)->f79C);
    result = func_02157E6C(((struct Obj08102 *)p)->f79C);
    if (result != 0) {
        switch (result) {
        case 1: ((struct Obj08102 *)p)->f17A4 = 1; break;
        case 2:
        case 3: ((struct Obj08102 *)p)->f17A4 = 2; break;
        }
        func_021DEEA4(a, func_021DE8D0);
    }
}
