/*
 * function: func_021A145C
 * address: 0x021A145C
 * packet: pkt_ov021_021A145C
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
 *   func_021F2344 0x021F2344 thumb ov032
 */

typedef struct { unsigned char pad[0x20]; void *f20; } Obj_021A145C;
extern int func_021F2344(void *p);
int func_021A145C(Obj_021A145C *p);

int func_021A145C(Obj_021A145C *p) { return func_021F2344(p->f20); }
