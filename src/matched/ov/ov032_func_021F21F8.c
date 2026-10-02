/*
 * function: func_021F21F8
 * address: 0x021F21F8
 * packet: pkt_ov032_021F21F8
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020257D0 0x020257D0 thumb
 *   func_02031194 0x02031194 arm
 */

typedef unsigned int u32;
extern u32 func_0201C6C4(u32 a, u32 b);
extern void func_020257D0(u32 a);
extern void func_02031194(void *task);
void func_021F21F8(void *task, char *q)
{
    int *r;
    if (func_0201C6C4(*(u32 *)(*(char **)(q + 8) + 0xb4), (*(u32 **)(q + 4))[1]) == 0) {
        func_020257D0(**(u32 **)(q + 4));
        r = *(int **)(q + 0xc);
        if (r != 0)
            (*r)--;
        *(u32 *)(*(char **)q + 0x2c) = 0;
        func_02031194(task);
    }
}
