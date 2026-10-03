/*
 * function: func_021F882C
 * address: 0x021F882C
 * packet: pkt_ov135_021F882C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   tbl_0220301C 0x0220301C data a4
 *   tbl_02202FC4 0x02202FC4 data a4
 *   str_02203C18 0x02203C18 data a1
 */
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { u32 id; s16 x; s16 y; } Entry;
extern const Entry tbl_0220301C[], tbl_02202FC4[];
extern const char str_02203C18[];
extern void func_02034714(const char *expr, u32 line, const char *file);
void func_021F882C(u8 *dst, int i, int kind)
{
    const Entry *table;
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
