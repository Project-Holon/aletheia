/*
 * function: func_021DEC98
 * address:  0x021DEC98
 * packet:   pkt_ov170_021DEC98
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DEC64 0x021DEC64 thumb
 *   func_021EB7E8 0x021EB7E8 thumb
 *   func_021EE224 0x021EE224 thumb
 *   func_021EE234 0x021EE234 thumb
 *   func_021EE244 0x021EE244 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj14262.h"
#include "../include/Obj23854.h"
#include "../include/Obj23855.h"
#include "../include/Obj23856.h"
#include "../include/Obj23857.h"
#include "../include/Obj23858.h"
#include "../include/Obj23859.h"
#include "../include/Obj23860.h"

extern void func_021DEC64(void *a, void *b, int c, void *d, int e);
extern void func_021EB7E8(char **p, unsigned box, int i);
extern void func_021EE224(char *p, int i, int v);
extern int func_021EE234(int *a, int i);
extern void func_021EE244(char *p, int i, int flag);

void func_021DEC98(char *p, void *a, int dir)
{
    int d, e, i;
    char *q;
    if (dir == 0) {
        ((struct Obj23854 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178 -= 0x17;
        if (((struct Obj23855 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178 < 0)
            ((struct Obj23856 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178 += 0x40;
    } else if (dir == 1) {
        ((struct Obj23857 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178 += 0x17;
        if (((struct Obj23858 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178 >= 0x40)
            ((struct Obj23859 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178 -= 0x40;
    }
    q = *(char * *)&((struct Obj00000 *)p)->f2C;
    if (((struct Obj14262 *)q)->fA179 == 0) {
        d = 0x25C;
        e = 0xE;
    } else {
        d = 0xB8;
        e = 0xF;
    }
    ((struct Obj14262 *)q)->fA179 ^= 1;
    func_021DEC64((void *)p, a, ((struct Obj23860 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178, (void *)d, e);
    if (dir == 2) {
        func_021EB7E8((char **)p, (unsigned char)p[0x14], 7);
        func_021EE224(*(char * *)&((struct Obj00000 *)p)->f2C, 8, 0);
        return;
    }
    i = 7;
    if (func_021EE234((int *)(*(char * *)&((struct Obj00000 *)p)->f2C), 7) == 1)
        i = 8;
    func_021EB7E8((char **)p, (unsigned char)p[0x14], i);
    func_021EE244(*(char * *)&((struct Obj00000 *)p)->f2C, i, dir);
    func_021EE224(*(char * *)&((struct Obj00000 *)p)->f2C, i, 1);
}
