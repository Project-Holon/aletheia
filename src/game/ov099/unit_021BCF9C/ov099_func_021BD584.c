/*
 * function: func_021BD584
 * address: 0x021BD584
 * packet: pkt_ov099_021BD584
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_0203D378 0x0203D378 arm
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 */
#include "../../../matched/include/Obj00008.h"
typedef unsigned short u16;
extern int func_021BA928(void *);
typedef unsigned int   u32;
extern u32 func_0203D378(void);
extern void func_021BA874(void *, int);
extern void func_021BAAB8(char *, int, int);
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern void func_02039C68(struct Link *p, unsigned int lo, unsigned int hi);
int func_021BD584(char *p, int v)
{
    int t;
    t = func_021BA928(p);
    if (t == 0) return v;
    if (func_0203D378() == 0) {
        func_021BA874(p, ((struct Obj00008 *)p)->f242 - 1);
        func_021BAAB8(p, 0x77, 0);
        ((struct Obj00008 *)p)->f1CC = 0x6f;
    } else {
        func_02039C68((struct Link *)func_020399A8(), 0x1b, 10);
        ((struct Obj00008 *)p)->f1CC = 0x49;
    }
    return v;
}
