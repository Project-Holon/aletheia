/*
 * file:     zonedata_p03.c
 * unit:     yes
 * function: func_02013C70, func_02013C80
 * address:  0x02013C70
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
 *   tbl_0209E010  0x0209E010  data
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef signed char s8;

typedef signed int     s32;

extern u32 func_02013B10(u32 id, const u16 *table, s32 count);
int func_02013C70(u32 a);
int func_02013C80(int a0);
extern u8   tbl_0209E010[];


/*
 *           pool word inside this eight-byte range, so the `literal`
 *           class has no outside witness and no cut moves one there.
 *           Same finding as src/matched/unit_02013C10.c's header.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02013C70.c \
 *       --func func_02013C70 --addr 0x02013C70 --cc 1.1p1 --thumb
 */
int func_02013C70(u32 a)
{
    return func_02013B10(a, (const u16 *)tbl_0209E010, 0xb);
}

int func_02013C80(int a0){ int t0, t1; t0 = func_02013A94(a0); t1 = func_02013C9C((int)t0); if ((unsigned int)(t1) != (unsigned int)(~0)) {  return 1; } else {  return 0; } }
