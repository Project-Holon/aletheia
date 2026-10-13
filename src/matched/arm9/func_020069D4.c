/*
 * function: PM_VOICE_Prepare
 * address:  0x020069D4
 * packet:   pkt_020069D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PM_VOICE_NextSlot  0x02006768  thumb
 *   PM_VOICE_Stop  0x02006948  thumb
 *   PM_VOICE_LoadWave  0x020067E0  thumb
 *   PM_VOICE_ReverseBytes  0x02006BE0  thumb
 *   g_02140504     0x02140504  data
 *   g_02140488     0x02140488  data
 *
 * Eight arguments: four in r0..r3 and four on the stack at [sp+0x30]..
 * [sp+0x3c], which is what makes the frame 0x1c: four words of outgoing
 * stack-argument area at sp+0..sp+0xc plus three locals at sp+0x10, sp+0x14
 * and sp+0x18.
 *
 * a1 is spilled to the [sp+0x10] slot because it is live across the first
 * 3-argument indirect call; the index comes back from PM_VOICE_NextSlot and is
 * spilled to [sp+0x14] because it is the return value.
 *
 * The struct at 0x02140504 is used twice off the same pool word: its +0x24
 * slot is the three-argument prologue call and its +0x28 slot the
 * eight-argument one whose last four arguments are the four pointers
 * e+8, e+0xc, e+0x20, e+0x1c, written to the outgoing area in that order.
 *
 * Both data addresses are declared as extern ARRAYS, not as numeric
 * constants: spelled `(int *)(0x02140504)` the pair is folded into one
 * base plus `subs #0xa0`, which costs a callee-saved register, a dead
 * `push {r3}` and four bytes of frame.
 */
#include "../include/Obj01457.h"

typedef unsigned char u8;

extern char g_02140504[];
extern char g_02140488[];

typedef unsigned short u16;
extern u16 PM_VOICE_NextSlot(void);
struct Sub02006948;
extern void PM_VOICE_Stop(struct Sub02006948 *e);
struct Sub02006544Entry;
extern int PM_VOICE_LoadWave(struct Sub02006544Entry *e, unsigned int v);
extern void PM_VOICE_ReverseBytes(u8 *a, unsigned int b);

int PM_VOICE_Prepare(int a0, int a1, int a2, int a3, int a5, int a6, int a7, int a8)
{
    int buf;
    int idx;
    char *e;

    (*(void (**)(int, int, int *))(g_02140504 + 0x24))(a0, a1, &buf);
    idx = PM_VOICE_NextSlot();
    e = (char *)(g_02140488 + idx * 0x34);
    if (*(int *)&((struct Obj01457 *)e)->f0 == 1)
        PM_VOICE_Stop((struct Sub02006948 *)e);
    if ((*(int (**)(int, int, int, char *, char *, char *, char *, char *))(
             g_02140504 + 0x28))(a0, a1, a8, e + 0x10, e + 8, e + 0xc, e + 0x20, e + 0x1c) == 0)
        PM_VOICE_LoadWave((struct Sub02006544Entry *)e, (unsigned int)buf);
    if (a7 != 0)
        PM_VOICE_ReverseBytes(*(u8 * *)&((struct Obj01457 *)e)->f10, ((struct Obj01457 *)e)->f8);
    e[0x28] = (u8)a2;
    *(int *)&((struct Obj01457 *)e)->f2C = a3;
    e[0x1d] = (u8)a5;
    ((struct Obj01457 *)e)->f24 = a6;
    return idx;
}
