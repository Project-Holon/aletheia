/*
 * function: func_021E1A28
 * address:  0x021E1A28
 * packet:   pkt_ov170_021E1A28
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020260E0 0x020260E0 thumb
 *   func_021EE008 0x021EE008 thumb
 *   func_021EDF5C 0x021EDF5C thumb
 *   func_021EDD38 0x021EDD38 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj23882.h"

typedef struct {
    unsigned char pad[0xE];
    unsigned short fE;
} Blk;

typedef unsigned char  u8;
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern void func_021EE008(char *p, int a, int b);
extern void func_021EDF5C(unsigned char *p);
extern void func_021EDD38(char *p, int d);

int func_021E1A28(char *p)
{
    Blk *b = (Blk *)(*(char * *)&((struct Obj00000 *)p)->f2C + 0x58);
    if (b->fE == 5) {
        unsigned r = func_020260E0(((struct Obj23882 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70);
        if (r >= 0x22 && r <= 0x25)
            func_021EE008(p, r - 0x22, 1);
        else
            func_021EE008(p, 0, 0);
        func_021EDF5C((unsigned char *)p);
        b->fE = 0;
        return 0;
    }
    b->fE++;
    func_021EDD38(p, (short)b->fE);
    return 1;
}
