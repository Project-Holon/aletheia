/*
 * function: func_021FD208
 * address: 0x021FD208
 * packet: pkt_ov132_021FD208
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov132/script_command.c and filed here.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 w[12]; } E;
typedef struct { u8 pad[0x60]; E e[4]; } T;
void func_021FD208(int i, int b, int c, T *p);

#pragma opt_common_subs off
#pragma opt_common_subs reset
#pragma opt_loop_invariants off
#pragma opt_loop_invariants reset

void func_021FD208(int i, int b, int c, T *p) { p->e[i].w[2] = 1; p->e[i].w[0] = 1; }
