/*
 * unit:     yes
 * function: FIELD_SOUND_SYSTEM_IsBusy
 * address:  0x020289B8
 * packet:   pkt_0202878C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * field_sound_system.c.  "Is the system busy": either the queue helper says so or the mode word is
 * non zero.  It is written as the negated conjunction rather than the
 * disjunction the semantics suggest, because the block the source puts inside
 * the `if` is the one emitted first and here that is the `return 0`
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_HasPendingRequest  0x02028DB8  thumb
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/FIELD_SOUND_SYSTEM_IsBusy.c  *       --addr 0x020289B8 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

struct Sys {
    u32 unk00;
    u32 unk04;
    u8  unk08[0x14];
    u32 unk1C;
    u32 unk20;
};

extern int FIELD_SOUND_SYSTEM_HasPendingRequest(void *obj);

u32 FIELD_SOUND_SYSTEM_IsBusy(struct Sys *s)
{
    if (FIELD_SOUND_SYSTEM_HasPendingRequest(s) == 0 && s->unk1C == 0) {
        return 0;
    }
    return 1;
}
