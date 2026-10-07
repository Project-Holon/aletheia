/*
 * file:     worldtrade_box_p25.c
 * unit:     yes
 * function: func_021F882C, func_021F886C
 * address:  0x021F882C
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
 *   func_02034714 0x02034714 arm
 *   tbl_0220301C 0x0220301C data a4
 *   tbl_02202FC4 0x02202FC4 data a4
 *   str_02203C18 0x02203C18 data a1
 *   g_0220301C  0x0220301C  data
 *   g_02202FC4  0x02202FC4  data
 */
#include "../../matched/include/G_0220301C.h"

typedef unsigned char u8;

typedef signed short s16;

typedef unsigned int u32;

typedef struct { u32 id; s16 x; s16 y; } Entry_021F882C;

typedef unsigned short u16;

typedef signed int s32;

typedef struct { u32 unk; s16 key; s16 val; } Entry_021F886C;

extern void func_02034714(const char *expr, u32 line, const char *file);
void func_021F882C(u8 *dst, int i, int kind);
int func_021F886C(int key, int val, int which);
extern const Entry_021F882C tbl_0220301C[], tbl_02202FC4[];
extern const char str_02203C18[];
extern struct G_0220301C g_0220301C[12];
extern Entry_021F886C g_02202FC4[11];

void func_021F882C(u8 *dst, int i, int kind)
{
    const Entry_021F882C *table;
    if (kind == 0) {
        table = tbl_0220301C;
        if (i >= 12) func_02034714(str_02203C18, 0, str_02203C18);
    } else {
        table = tbl_02202FC4;
        if (i >= 11) func_02034714(str_02203C18, 0, str_02203C18);
    }
    dst[3] = table[i].x;
    dst[4] = table[i].y;
}


/*
 * Index of a key/value pair in one of two s16 tables.
 */
int func_021F886C(int key, int val, int which)
{
    int i;
    int n;
    Entry_021F886C *tab;

    if (which == 0) {
        tab = ((Entry_021F886C *)g_0220301C);
        n = 0xc;
    } else {
        tab = g_02202FC4;
        n = 0xb;
    }
    for (i = 0; i < n; i++) {
        if (tab[i].key == key && tab[i].val == val) {
            return i;
        }
    }
    return 0;
}
