/*
 * function: func_021DD16C
 * address:  0x021DD16C
 * packet:   pkt_ov170_021DD16C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EBFA8 0x021EBFA8 thumb
 *   func_021EC35C 0x021EC35C thumb
 *   func_021DEDCC 0x021DEDCC thumb
 *   func_021DEC98 0x021DEC98 thumb
 */
#include "../include/Obj00000.h"

extern void func_021EBFA8(char *p, int i, int v);
extern void func_021EC35C(char **p, int box);
extern int func_021DEDCC(char *p, int box);
extern void func_021DEC98(char *p, void *a, int dir);

void func_021DD16C(unsigned char *p, int dir)
{
    if (dir == 0) {
        p[0x14] = p[0x14] == 0 ? p[0x15] - 1 : p[0x14] - 1;
        func_021EBFA8(*(char * *)&((struct Obj00000 *)p)->f2C, 0, 2);
    } else {
        p[0x14] = p[0x14] == p[0x15] - 1 ? 0 : p[0x14] + 1;
        func_021EBFA8(*(char * *)&((struct Obj00000 *)p)->f2C, 1, 4);
    }
    func_021EC35C((char **)p, p[0x14]);
    func_021DEC98((char *)p, (void *)func_021DEDCC((char *)p, p[0x14]), dir);
}
