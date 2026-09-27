/*
 * function: func_020069D4
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
 *   func_02006768  0x02006768  thumb
 *   func_02006948  0x02006948  thumb
 *   func_020067E0  0x020067E0  thumb
 *   func_02006BE0  0x02006BE0  thumb
 *   g_02140504     0x02140504  data
 *   g_02140488     0x02140488  data
 *
 * Eight arguments: four in r0..r3 and four on the stack at [sp+0x30]..
 * [sp+0x3c], which is what makes the frame 0x1c: four words of outgoing
 * stack-argument area at sp+0..sp+0xc plus three locals at sp+0x10, sp+0x14
 * and sp+0x18.
 *
 * a1 is spilled to the [sp+0x10] slot because it is live across the first
 * 3-argument indirect call; the index comes back from func_02006768 and is
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

typedef unsigned char u8;

extern char g_02140504[];
extern char g_02140488[];

extern int func_02006768(void);
extern void func_02006948(char *e);
extern void func_020067E0(char *e, int v);
extern void func_02006BE0(int a, int b);

int func_020069D4(int a0, int a1, int a2, int a3, int a5, int a6, int a7, int a8)
{
    int buf;
    int idx;
    char *e;

    (*(void (**)(int, int, int *))(g_02140504 + 0x24))(a0, a1, &buf);
    idx = func_02006768();
    e = (char *)(g_02140488 + idx * 0x34);
    if (*(int *)e == 1)
        func_02006948(e);
    if ((*(int (**)(int, int, int, char *, char *, char *, char *, char *))(
             g_02140504 + 0x28))(a0, a1, a8, e + 0x10, e + 8, e + 0xc, e + 0x20, e + 0x1c) == 0)
        func_020067E0(e, buf);
    if (a7 != 0)
        func_02006BE0(*(int *)(e + 0x10), *(int *)(e + 8));
    e[0x28] = (u8)a2;
    *(int *)(e + 0x2c) = a3;
    e[0x1d] = (u8)a5;
    *(int *)(e + 0x24) = a6;
    return idx;
}
