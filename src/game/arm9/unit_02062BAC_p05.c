/*
 * file:     unit_02062BAC_p05.c
 * unit:     yes
 * function: func_02062F78
 * address:  0x02062F78
 * packet:   pkt_0206296C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * *
 * Zeroes a 14-byte animation-playback sub-state: three u32 words and a
 * trailing halfword. Written as four stores rather than a memset.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02062F78.c  *       --func func_02062F78 --addr 0x02062F78 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct AnimState {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u16 unk0C;
};

void func_02062F78(struct AnimState *state)
{
    state->unk00 = 0;
    state->unk04 = 0;
    state->unk08 = 0;
    state->unk0C = 0;
}
