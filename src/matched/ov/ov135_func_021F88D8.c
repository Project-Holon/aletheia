/*
 * function: WORLDTRADE_ENTER_GetListRange
 * address:  0x021F88D8
 * packet:   pkt_021F88D8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
  *
  *
  *
 * symbols:
 *   tbl_02202F0C  0x02202F0C  data
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 start;
    u8 id;
} Range;

extern const Range tbl_02202F0C[];

int WORLDTRADE_ENTER_GetListRange(u32 id, u32 *start)
{
    int i;

    for (i = 0; i < 28; i++) {
        if (id == tbl_02202F0C[i].id) {
            *start = tbl_02202F0C[i].start;
            return tbl_02202F0C[i + 1].start - tbl_02202F0C[i].start;
        }
    }
    return 0;
}
