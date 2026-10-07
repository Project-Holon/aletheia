/*
 * file:     zukan_detail_graphic_p27.c
 * unit:     yes
 * function: func_021C1F28, func_021C1F44
 * address:  0x021C1F28
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned int   u32;

extern void *func_0204A39C(void *narc, int fileId, int decompress, u32 heapId, u32 *out_size);
extern u32 func_020307B0(void *p);
void *func_021C1F28(int a, int b, int c);
void func_021C1F44(int a);


/*
 * Forwards to func_0204A39C with the first argument less one and an out slot.
 */
void *func_021C1F28(int a, int b, int c)
{
    int out;

    return func_0204A39C((void *)c, a - 1, 0, b, (u32 *)(&out));
}


void func_021C1F44(int a)
{
    if (a != 0)
        func_020307B0((void *)a);
}
