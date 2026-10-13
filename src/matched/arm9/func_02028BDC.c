/*
 * function: FIELD_SOUND_SYSTEM_ResumeSlots
 * address:  0x02028BDC
 * packet:   pkt_02028BDC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_PlaySeWithVolume  0x020061F0  thumb
 *
 * field_sound_system.c: drop the bits of mask from the pending set at
 * +0xB4 and, when the set empties, replay the two stored sounds.  The
 * 4-byte residue of docs/notes/pkt_02028BDC.c.txt ("a dead-after-use scaled
 * index") was the callee arity: both callees take the sound id (and
 * GFL_USE_PlaySeWithVolume the second id), so the index is not dead; the image passes
 * the loaded halfwords on in r0/r1.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern void GFL_USE_PlaySeWithVolume(u32 id, u32 sub);

struct S { u8 pad[0xac]; u16 lo[2]; u16 hi[2]; u32 mask; };

void FIELD_SOUND_SYSTEM_ResumeSlots(struct S *s, u32 mask)
{
    int i;

    if ((s->mask & mask) == 0)
        return;

    s->mask = s->mask & ~mask;

    if (s->mask != 0)
        return;

    for (i = 0; i < 2; i++) {
        if (s->lo[i] != 0xffff) {
            if (s->hi[i] == 0xffff)
                GFL_USE_PlaySeDefaultVolume(s->lo[i]);
            else
                GFL_USE_PlaySeWithVolume(s->lo[i], s->hi[i]);
        }
    }
}
