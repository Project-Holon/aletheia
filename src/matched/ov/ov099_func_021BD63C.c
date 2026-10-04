/*
 * function: func_021BD63C
 * address: 0x021BD63C
 * packet: pkt_ov099_021BD63C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 */
#include "../include/Obj07950.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BA928(void *);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *, unsigned int, unsigned int);
int func_021BD63C(char *p, int v)
{
    int state;
    func_021BA928(p);
    if (func_02039CB4((struct Link *)func_020399A8(), 0x1a, 10) != 0) {
        state = ((struct Obj07950 *)p)->f1357;
        if (state != 0) ((struct Obj07950 *)p)->f1CC = state;
        else ((struct Obj07950 *)p)->f1CC = 0x15;
        ((struct Obj07950 *)p)->f1357 = 0;
    }
    return v;
}
