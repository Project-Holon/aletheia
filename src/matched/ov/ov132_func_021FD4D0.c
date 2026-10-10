/*
 * function: func_021FD4D0
 * address: 0x021FD4D0
 * packet: pkt_ov132_021FD4D0
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
struct Record { int f0; int flag; char pad8[0x14]; char *data; char pad20[0x10]; };

#pragma opt_common_subs off
#pragma opt_common_subs reset
#pragma opt_loop_invariants off
#pragma opt_loop_invariants reset

/* Clears the flag of the four records, clears the word at +0x15C and returns the buffer pointer. */
typedef struct { char pad0[0x60]; struct Record rec[4]; char pad120[8]; char *buffer; char pad12c[0x30]; u32 tail; } Owner_021FD4D0;

char *func_021FD4D0(int a, Owner_021FD4D0 *p)
{
    u8 i;
    for (i = 0; i < 4; i++)
        p->rec[i].flag = 0;
    p->tail = 0;
    return p->buffer;
}
