/*
 * function: func_021DBFD4
 * address:  0x021DBFD4
 * packet:   pkt_ov093_021DBFD4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C1BC  0x0201C1BC  thumb
 *   func_0201BD28  0x0201BD28  thumb
 *   func_0201C020  0x0201C020  thumb
 *   func_0201C0BC  0x0201C0BC  thumb
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u32 func_0201C1BC(u16 id);
extern u32 func_0201BD28(u16 id, u32 field);
extern u8 func_0201C020(u16 id);
extern u8 func_0201C0BC(u16 id, u32 idx, s32 *out);

int func_021DBFD4(u16 id)
{
    u32 t = func_0201C1BC(id);
    if (func_0201BD28(id, 10) != 0) {
        return 1;
    }
    switch (t) {
    case 4:
        if (func_0201BD28(id, 11) == 8) {
            return 0;
        }
    case 6:
        return 1;
    case 7: {
        u32 n;
        u32 i;
        s32 out;
        n = func_0201C020(id);
        for (i = 0; i < n; i++) {
            func_0201C0BC(id, i, &out);
            if (out < 0) {
                return 0;
            }
        }
        return 1;
    }
    default:
        if (id == 0x122) {
            return 1;
        }
        return 0;
    }
}
