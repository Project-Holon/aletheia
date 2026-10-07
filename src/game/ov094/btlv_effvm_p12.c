/*
 * file:     btlv_effvm_p12.c
 * unit:     yes
 * function: func_021F80E4, func_021F80FC
 * address:  0x021F80E4
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094
 *   func_02207960  0x02207960  thumb  ov094
 *   func_02207B4C  0x02207B4C  thumb  ov094
 */
typedef unsigned int u32;

extern void func_02207960(char *p, int i);
extern void func_02207B4C(char *p, int i, int n);
void func_021F80E4(u32 a);
void func_021F80FC(u32 a, u32 b);
extern char *d_0220AF20;


/*
 * Unlabelled leaf, filed as the blocker of ov093 callers (lane S17).
 */
void func_021F80E4(u32 a)
{
    func_02207960((char *)(*(u32 *)(d_0220AF20 + 0x1a4)), a);
}


void func_021F80FC(u32 a, u32 b)
{
    func_02207B4C((char *)(*(u32 *)(d_0220AF20 + 0x1a4)), a, b);
}
