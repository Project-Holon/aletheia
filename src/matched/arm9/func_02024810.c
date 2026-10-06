/*
 * function: func_02024810
 * address:  0x02024810
 * packet:   pkt_02024768
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

extern int func_020248D8(unsigned int v, unsigned int *a1, unsigned int *a2);
typedef unsigned int   u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
void func_02024810(char *p, int a1, int a2)
{
    int x, y;
    func_020248D8(a1, (unsigned int *)(&x), (unsigned int *)(&y));
    func_02045CAC((struct MsgBank *)(*(int *)(p + 4 + x * 4)), y, (void *)a2);
}
