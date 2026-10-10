/*
 * function: func_021A1584
 * address: 0x021A1584
 * packet: pkt_ov021_021A1584
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/field_3dbg.c and filed here.
 *
 * symbols:
 *   func_021EFF3C 0x021EFF3C thumb ov035
 */

typedef struct { unsigned char pad[0x20]; void *f20; } Obj_021A1584;
extern int func_021EFF3C(void *p);
int func_021A1584(Obj_021A1584 *p);

int func_021A1584(Obj_021A1584 *p) { return func_021EFF3C(p->f20); }
