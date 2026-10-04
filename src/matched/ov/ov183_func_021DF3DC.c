/*
 * function: func_021DF3DC
 * address: 0x021DF3DC
 * packet: pkt_ov183_021DF3DC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 0x021DF41A
 * symbols:
 *   func_021FCE0C 0x021FCE0C thumb ov186
 *   func_021FCD0C 0x021FCD0C thumb ov186
 *   func_021DF620 0x021DF620 thumb ov183
 */
#include "../include/Obj00786.h"
typedef signed char s8;
extern int func_021FCE0C(char *p, unsigned field);
extern void func_021FCD0C(char *p);
extern void func_021DF620(char *, unsigned int, s8, int);
void func_021DF3DC(char *p, int a)
{
    unsigned int old, current;
    s8 direction;
    old = func_021FCE0C(((struct Obj00786 *)p)->f4, 1);
    func_021FCD0C(((struct Obj00786 *)p)->f4);
    current = func_021FCE0C(((struct Obj00786 *)p)->f4, 1);
    direction = func_021FCE0C(((struct Obj00786 *)p)->f4, 2);
    if (direction != 0 && old != current) func_021DF620(p, current, direction, a);
}
