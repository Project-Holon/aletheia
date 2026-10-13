/*
 * function: PARTY_SELECT_LIST_SetStatusIconsVisible
 * address:  0x021CCE48
 * packet:   pkt_ov021_021CCE48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 */

typedef unsigned char u8;

typedef unsigned int   u32;
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);

void PARTY_SELECT_LIST_SetStatusIconsVisible(u8 *s, int flag)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (*(void **)(s + i * 4 + 0x4c) != 0)
            func_0204B3DC(*(void **)(s + i * 4 + 0x4c), 0);
        if (*(void **)(s + i * 4 + 0x64) != 0)
            func_0204B3DC(*(void **)(s + i * 4 + 0x64), 0);
    }
    if (flag == 0) {
        for (i = 0; i < 6; i++) {
            if (*(void **)(s + i * 4 + 0x4c) != 0)
                func_0204B3DC(*(void **)(s + i * 4 + 0x4c), 1);
        }
    } else if (flag == 1) {
        for (i = 0; i < 6; i++) {
            if (*(void **)(s + i * 4 + 0x64) != 0)
                func_0204B3DC(*(void **)(s + i * 4 + 0x64), 1);
        }
    }
}
