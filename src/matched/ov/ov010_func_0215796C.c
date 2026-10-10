/*
 * function: func_0215796C
 * address: 0x0215796C
 * packet: pkt_ov010_0215796C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov010/script_work_p01.c and filed here.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct { u32 a; u16 b; } S;
typedef struct { u8 pad[0x668]; u32 a; u8 pad2[6]; u16 b; } D_0215796C;
void func_0215796C(int x, int y, S *s, D_0215796C *d);

void func_0215796C(int x, int y, S *s, D_0215796C *d) { d->b = s->b; d->a = s->a; }
