/*
 * function: func_020225B4
 * address:  0x020225B4
 * packet:   pkt_02022490
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  02022490 label
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;

extern void func_02022490(void *p, void *a1, void *a2, int idx);
extern void func_02030EAC(void *p);
extern void func_020307B0(void *p);

void func_020225B4(void *a0, u32 *a1)
{
    func_02022490((void *)a1[0], (void *)a1[1], (void *)a1[2], (int)a1[3]);
    func_02030EAC(a0);
    func_020307B0(a1);
}
