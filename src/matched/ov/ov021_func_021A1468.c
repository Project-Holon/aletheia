/*
 * function: func_021A1468
 * address: 0x021A1468
 * packet: pkt_ov021_021A1468
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
 *   func_021F23F8 0x021F23F8 thumb ov032
 */

typedef struct { unsigned char pad[0x20]; void *f20; } Obj_021A1468;
extern int func_021F23F8(void *p);
int func_021A1468(Obj_021A1468 *p);

int func_021A1468(Obj_021A1468 *p) { return func_021F23F8(p->f20); }
