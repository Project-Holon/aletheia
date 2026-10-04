/*
 * function: func_021C143C
 * address: 0x021C143C
 * packet: pkt_ov099_021C143C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: bind the narrowed callee result before comparing the indexed field.
 * symbols:
 *   func_0203D378 0x0203D378 arm
 *   func_021C1154 0x021C1154 thumb ov099
 *   func_021BDD54 0x021BDD54 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02156A3C 0x02156A3C thumb ov009
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 */
#include "../include/Obj06359.h"
typedef unsigned short u16;
extern int func_0203D378(char *);
extern int func_021C1154(char *);
extern int func_021BDD54(char *, void *);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *, unsigned, unsigned);
extern int func_02156A3C(void);
extern void func_021BA874(char *, int);
extern void func_021BAAB8(char *, int, int);
int func_021C143C(char *p, int ret)
{
    int index = 0;
    u16 value;
    if (func_0203D378(p) != 0) index = 1;
    if (func_021C1154(p) == 0) {
        if (((u16 *)(p + 0x1f4))[index] != 0) {
            value = func_021BDD54(p, ((struct Obj06359 *)p)->f8);
            if (value == ((u16 *)(p + 0x1f4))[index]) {
                func_02039C68((struct Link *)func_020399A8(), 15, 10);
                ((struct Obj06359 *)p)->f1CC = 44;
            } else {
                func_021BA874(p, func_02156A3C());
                func_021BAAB8(p, 13, 0);
                ((struct Obj06359 *)p)->f1CC = 19;
            }
        }
    }
    return ret;
}
