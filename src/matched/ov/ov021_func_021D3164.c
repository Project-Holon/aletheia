/*
 * function: EVENT_GAME_MANUAL_SetResult
 * address:  0x021D3164
 * packet:   pkt_ov021_021D3164
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void EVENT_GAME_MANUAL_SetResult(u32 *p)
{
    if (((u32 *)p[2])[1] == 0) {
        *(u16 *)p[3] = 0;
    } else {
        *(u16 *)p[3] = 1;
    }
}
