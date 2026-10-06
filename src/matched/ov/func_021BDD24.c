/*
 * function: func_021BDD24
 * address:  0x021BDD24
 * packet:   pkt_021BDD24
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BDFA8 0x021BDFA8  thumb  ov208
 *   func_021BE4DC 0x021BE4DC  thumb  ov208
 *   func_021BE680 0x021BE680  thumb  ov208

 */
#include "../include/Obj01081.h"

struct Ov208Eff;
extern void func_021BDFA8(struct Ov208Eff *e);
extern void func_021BE4DC(struct Ov208Eff *e);
extern void func_021BE680(char *);

void func_021BDD24(char *p)
{
    switch (((struct Obj01081 *)p)->fC) {
    case 0:
        func_021BDFA8((struct Ov208Eff *)p);
        break;
    case 1:
        func_021BE4DC((struct Ov208Eff *)p);
        break;
    case 2:
        func_021BE680(p);
        break;
    }
}

