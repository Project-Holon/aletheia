/*
 * file:     worldtrade_box_p23.c
 * unit:     yes
 * function: func_021F8498, func_021F84BC
 * address:  0x021F8498
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204A298  0x0204A298  arm
 *   func_02034714  0x02034714  arm
 *   tbl_0220307C   0x0220307C  data
 */
typedef signed char s8;

typedef signed short s16;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern int func_0204A298(int a0, int a1, int a2, int a3, u32 *out);
extern void func_02034714(const char *expr, u32 line, const char *file);
u16 *func_021F8498(u32 heap, u32 unused, u32 *count);
void func_021F84BC(u32 i, int *start, int *end);
extern const int tbl_0220307C[];


u16 *func_021F8498(u32 heap, u32 unused, u32 *count)
{
    u32 size;
    u16 *list;

    list = (u16 *)func_0204A298(0x62, 5, 0, (u16)heap, &size);
    *count = size / 2;
    return list;
}


void func_021F84BC(u32 i, int *start, int *end)
{
    if (i >= 0x1B) {
        func_02034714((void *)0x02203C18, 0, (void *)0x02203C18);
    }
    *start = tbl_0220307C[i];
    *end = tbl_0220307C[i + 1];
}
