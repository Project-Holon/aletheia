/*
 * function: func_021A14B4
 * address: 0x021A14B4
 * packet: pkt_ov021_021A14B4
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
 *   func_021F0174 0x021F0174 thumb ov033
 */

typedef struct { unsigned char pad[0x20]; void *f20; } Obj_021A14B4;
extern int func_021F0174(void *p);
int func_021A14B4(Obj_021A14B4 *p);

int func_021A14B4(Obj_021A14B4 *p) { return func_021F0174(p->f20); }
