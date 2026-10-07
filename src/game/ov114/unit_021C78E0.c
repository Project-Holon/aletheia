/*
 * file:     unit_021C78E0.c
 * unit:     yes
 * function: func_021C78E0, func_021C78F4, func_021C7908
 * address:  0x021C78E0
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021CF248  0x021CF248  data
 *   g_021D3C20  0x021D3C20  data
 *   g_021D3B9C  0x021D3B9C  data
 *   g_021CF7AC  0x021CF7AC  data
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern void func_02086028(void *);
extern void func_02086078(void *);
extern void func_02086004(void *);
void func_021C78E0(void);
void func_021C78F4(void);
int func_021C7908(void);
extern u8 g_021D3C20[];
extern u8 g_021D3B9C[];


/*
 * Tail call of func_02086028 on the 0x021D3C38 block.
 */
void func_021C78E0(void)
{
    func_02086028((void *)0x021D3C38);
}


void func_021C78F4(void)
{
    func_02086078((void *)0x021D3C38);
}


int func_021C7908(void)
{
    func_02086004(g_021D3C20);
    *(u32 *)(g_021D3B9C + 0x20) = 0;
    return 1;
}
