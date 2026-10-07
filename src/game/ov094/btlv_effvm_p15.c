/*
 * file:     btlv_effvm_p15.c
 * unit:     yes
 * function: func_021F821C, func_021F823C, func_021F8260, func_021F827C
 * address:  0x021F821C
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
 *   func_02208958 0x02208958 thumb ov094
 *   func_02208DAC  0x02208DAC  thumb  ov094
 *   func_02209068 0x02209068 thumb ov094
 *   func_022090A4 0x022090A4 thumb ov094
 */
typedef unsigned short u16;

typedef unsigned int u32;

extern void func_02208958(void *, int, int, int);
extern u32 func_02208DAC(u32 *p, u32 v);
extern void func_02209068(void *);
extern int func_022090A4(int *);
void func_021F821C(int a, int b, int c);
void func_021F823C(u32 *p);
void func_021F8260(u32 i);
int func_021F827C(u32 i);
extern char *d_0220AF20;


/*
 * Forwards three arguments to func_02208958 with the handle at 0x1a4 of the global work block.
 */
void func_021F821C(int a, int b, int c)
{
    func_02208958(*(void **)(d_0220AF20 + 0x1a4), a, b, c);
}


void func_021F823C(u32 *p)
{
    u32 r = func_02208DAC(p, *(u16 *)(d_0220AF20 + 0x1F0));

    *(u32 *)(d_0220AF20 + p[0] * 4 + 0x1A8) = r;
}

/*
 * Leaf blocking ov093 func_021EB870.
 */
void func_021F8260(u32 i)
{
    func_02209068(*(void **)(d_0220AF20 + i * 4 + 0x1a8));
}

int func_021F827C(u32 i)
{
    return func_022090A4(*(int **)(d_0220AF20 + i * 4 + 0x1a8));
}
