/*
 * file:     btlv_effvm_p14.c
 * unit:     yes
 * function: func_021F8198, func_021F81B4
 * address:  0x021F8198
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
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_02207CC4 0x02207CC4 thumb ov094
 *   func_02207D04  0x02207D04  thumb  ov094
 */
struct O;
typedef unsigned int u32;

extern void func_02207CC4(struct O *obj, int a, int c);
extern void func_02207D04(struct O *obj, int a, int idx);
void func_021F8198(int a, int b);
void func_021F81B4(u32 a, u32 b);
extern char *d_0220AF20;


/*
 * Tail call to func_02207CC4 with the handle at 0x1a4 of the global work block.
 */
void func_021F8198(int a, int b)
{
    func_02207CC4(*(void **)(d_0220AF20 + 0x1a4), a, b);
}


void func_021F81B4(u32 a, u32 b)
{
    func_02207D04((struct O *)(*(u32 *)(d_0220AF20 + 0x1A4)), a, b);
}
