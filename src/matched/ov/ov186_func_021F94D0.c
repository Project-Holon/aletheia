/*
 * function: func_021F94D0
 * address: 0x021F94D0
 * packet: pkt_ov186_021F94D0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov186/br_proc_sys.c and filed here.
 */

typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { struct { u16 id; u16 x; } e[6]; int n; } Stk_021F94D0;
typedef struct { u8 pad[0x24]; Stk_021F94D0 *s; } Obj_021F94D0;
void func_021F94D0(Obj_021F94D0 *o);

void func_021F94D0(Obj_021F94D0 *o) { Stk_021F94D0 *s = o->s; int i = s->n - 1; if (s->e[(u16)i].id == 8) s->n = i; }
