/*
 * function: func_020225B4
 * address:  0x020225B4
 * packet:   pkt_02022490
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  +000E THM_CALL func_02022490       -> unresolved: 02022490 (thumb, from name) has no witness outside 020225B4..020225D4
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;

extern void func_02022490(char *p, int a1, int a2, int a3);
struct Node;
extern void func_02030EAC(struct Node *n);
extern void func_020307B0(void *p);

void func_020225B4(void *a0, u32 *a1)
{
    func_02022490((void *)a1[0], (int)((void *)a1[1]), (int)((void *)a1[2]), (int)a1[3]);
    func_02030EAC(a0);
    func_020307B0(a1);
}
