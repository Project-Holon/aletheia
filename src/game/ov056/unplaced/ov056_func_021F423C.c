/*
 * function: func_021F423C
 * address:  0x021F423C
 * packet:   pkt_ov056_021F423C
 * region:   ov056
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02006148  0x02006148  thumb
 *   func_020061F8  0x020061F8  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

/* Same layout as FkSoundAnime in ov056/unit_021F36C0_types.h (a file in unplaced/ cannot reach that header). */
typedef struct FkSoundAnime {
    u32 anime;
    int frame;
    u16 soundId[9];
} FkSoundAnime;

extern int func_02006148(u32 seId);
extern void func_020061F8(int seSlot);

/* Stops the sound effect of a channel, if it has one (the stop twin of func_021F4224). */
void func_021F423C(FkSoundAnime *sound, u32 channel)
{
    u16 seId = sound->soundId[channel];

    if (seId != 0xffff) {
        func_020061F8(func_02006148(seId));
    }
}
