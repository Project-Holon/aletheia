/*
 * function: func_021F2FCC
 * address:  0x021F2FCC
 * packet:   pkt_ov032_021F2FCC
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F2FCC 0x021F2FCC thumb
 *   func_02043598 0x02043598 arm
 *   func_021F34C8 0x021F34C8 thumb ov032
 *   func_021F32D4 0x021F32D4 thumb ov032
 *   func_02025588 0x02025588 thumb
 *   func_0204B084 0x0204B084 arm
 *   func_0204B1CC 0x0204B1CC arm
 */
#include "../include/Obj00812.h"

extern void func_02043598(unsigned, unsigned);
extern void func_021F34C8(char *, int);
extern void func_021F32D4(char *);
struct Bank;
extern void func_02025588(void *p);
extern void func_0204B084(int);
typedef unsigned int   u32;
extern u32 func_0204B1CC(struct Bank *bank);

void func_021F2FCC(char *p)
{
    int i;

    func_02043598(0x10, 0);
    for (i = 0; i < 5; i++) {
        func_021F34C8(p, (unsigned char)i);
    }
    func_021F32D4(p);
    func_02025588((void *)(((struct Obj00812 *)p)->f124));
    func_0204B084(((struct Obj00812 *)p)->f12C);
    func_0204B1CC((struct Bank *)(((struct Obj00812 *)p)->f128));
}
