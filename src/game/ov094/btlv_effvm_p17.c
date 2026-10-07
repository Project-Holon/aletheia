/*
 * file:     btlv_effvm_p17.c
 * unit:     yes
 * function: func_021F84B4, func_021F84D0, func_021F84E8, func_021F8504
 * address:  0x021F84B4
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
 *   func_021FF7B0  0x021FF7B0  thumb  ov094
 *   func_02209318 0x02209318 thumb ov094
 *   func_022094BC  0x022094BC  thumb  ov094
 */
typedef unsigned int u32;

typedef unsigned char  u8;

extern void func_021FF7B0(u32 obj, u32 a, u32 b);
extern void func_02209318(void *, int, int);
extern void func_022094BC(u8 *p, int i, int a, int b);
void func_021F84B4(u32 a, u32 b);
int func_021F84D0(int a);
void func_021F84E8(int a, int b);
void func_021F8504(u32 a, u32 b, u32 c);
extern char *d_0220AF20;


/*
 * Unlabelled leaf, filed as the blocker of ov093 callers (lane S15).
 */
void func_021F84B4(u32 a, u32 b)
{
    func_021FF7B0(*(u32 *)(d_0220AF20 + 0x190), a, b);
}


/*
 * Returns slot a-8 of the table at 0x1f8 of the global work block.
 */
int func_021F84D0(int a)
{
    return ((int *)(d_0220AF20 + 0x1f8))[a - 8];
}


/*
 * Tail call to func_02209318 with the handle at 0x1b0 of the global work block.
 */
void func_021F84E8(int a, int b)
{
    func_02209318(*(void **)(d_0220AF20 + 0x1b0), a, b);
}


void func_021F8504(u32 a, u32 b, u32 c)
{
    func_022094BC((u8 *)(*(u32 *)(d_0220AF20 + 0x1B0)), a, b, c);
}
