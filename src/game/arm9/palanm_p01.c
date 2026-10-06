/*
 * file:     palanm_p01.c
 * unit:     yes
 * function: func_020213C0, func_020213E0, func_020213F8, func_0202142C, func_02021438
 * address:  0x020213C0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   sub_0209E968_Map  0x0209E968  data
 *   sub_0209E904_Tbl  0x0209E904  data
 *   g_02146788  0x02146788  data
 */
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char  u8;

int func_020213C0(u32 a);
u32 func_020213E0(u16 v);
u16 func_020213F8(int a, int b);
unsigned short func_0202142C(int a0);
void func_02021438(void);
extern u16 sub_0209E968_Map[];
extern u16 sub_0209E904_Tbl[][2];
extern u32 g_02146788;



int func_020213C0(u32 a)
{
    u32 i;

    for (i = 0; i < 0x40; i++)
        if (sub_0209E968_Map[i] == a)
            return 1;
    return 0;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020213E0.c  *       --func func_020213E0 --addr 0x020213E0 --cc 1.1p1 --thumb
 */
u32 func_020213E0(u16 v)
{
    if ((u16)(v + 0xFE14) > 8) {
        return 1;
    }
    return 0;
}



u16 func_020213F8(int a, int b)
{
    u32 i;

    for (i = 0; i < 0x19; i++)
        if (sub_0209E904_Tbl[i][b] == a)
            return sub_0209E904_Tbl[i][b ^ 1];
    return 0;
}



unsigned short func_0202142C(int a0)
{
    return func_020213F8(a0, 0);
}


/*
 * Clears the one word at 0x02146788.  Four bytes of code and its pool word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021438.c \
 *       --func func_02021438 --addr 0x02021438 --cc 1.1p1 --thumb
 */
void func_02021438(void)
{
    g_02146788 = 0;
}
