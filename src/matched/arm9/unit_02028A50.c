/*
 * unit:     yes
 * address:  0x02028A50
 * packet:   pkt_0202878C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: FIELD_SOUND_SYSTEM_Reset, func_02028A58, FIELD_SOUND_SYSTEM_StartRingtone, func_02028A70
 *
 * Four forwarding thunks in field_sound_system.c, each a pool word and a `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The last three first
 * chase a sub-object pointer out of the sound system object: the volume fader
 * at +0xA4 that src/matched/unit_0202878C.c drives, and the ringtone handle at
 * +0xA8.  Both offsets are past the Thumb `ldr` immediate's reach of 124 and
 * so cost an `adds r0, #0xa4` first, which is an encoding artefact and not a
 * second pointer
 * (docs/idioms/thumb-immediate-reach-costs-an-adds.md).
 *
 * UNLABELLED FOLLOWERS: none of these four saves `lr`, so `disasm.py` labels
 * none of them and `layout/function_starts.txt` has no seed for 0x02028A50,
 * 0x02028A64 or 0x02028A70 (it has one for 0x02028A58, sized 8 rather than
 * 12).  The witness for all four is this unit reproducing 0x02028A50..0x02028A7C
 * byte for byte, four sections of 8, 12, 12 and 12 bytes with no padding
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * ARITY: a thunk that moves no argument register says nothing about how many
 * arguments it forwards
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * func_02028A58 is written with the three parameters PLAYER_VOLUME_FADER_SetTarget takes,
 * because src/matched/unit_0202878C.c fixes that signature; the other three
 * are written with one argument each, which is the conservative reading and
 * compiles to the same bytes as any other arity.
 *
 * FIELD_SOUND_SYSTEM_Reset is why this file exists as its own unit: it is the only caller
 * of FIELD_SOUND_SYSTEM_DrainAndInit reachable from src/matched/unit_020298E0.c, whose third
 * state hands a resource off through it, and that file has no other witness
 * for 0x02028A50.
 *
 * symbols:
 *   PLAYER_VOLUME_FADER_SetTarget  0x02028794  thumb
 *   FIELD_SOUND_SYSTEM_DrainAndInit  0x02028D2C  thumb
 *   RINGTONE_SYS_Start  0x02029F54  thumb
 *   RINGTONE_SYS_Stop  0x02029F60  thumb
 *
 * Wave 26 closed it.  All four pool words are the only reference in the image
 * to their target, so the `label` class sees nothing and no cut helps; the way
 * through was to decompile the three targets that live outside this packet.
 * FIELD_SOUND_SYSTEM_DrainAndInit is now src/matched/FIELD_SOUND_SYSTEM_DrainAndInit.c (pkt_02028B50),
 * RINGTONE_SYS_Start and RINGTONE_SYS_Stop are src/matched/unit_02029F54.c and
 * src/matched/unit_02029F60.c (pkt_02029F4C), and all three resolve `matched`;
 * PLAYER_VOLUME_FADER_SetTarget resolves `matched` off src/matched/unit_0202878C.c.  That also
 * lifts the cap this file placed on src/pending/unit_020298E0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02028A50.c \
 *       --addr 0x02028A50 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

struct Fader;

struct SoundSys {
    u8            unk00[0xA4];
    struct Fader *fader;
    void         *ringtone;
};

struct Sys;
extern void FIELD_SOUND_SYSTEM_DrainAndInit(struct Sys *s, void *desc);
extern void PLAYER_VOLUME_FADER_SetTarget(struct Fader *s, u8 level, u16 frames);
extern void RINGTONE_SYS_Start(void *p);
extern void RINGTONE_SYS_Stop(void *p);

void FIELD_SOUND_SYSTEM_Reset(void *sys, void *res)
{
    FIELD_SOUND_SYSTEM_DrainAndInit(sys, res);
}

void func_02028A58(struct SoundSys *sys, u8 level, u16 frames)
{
    PLAYER_VOLUME_FADER_SetTarget(sys->fader, level, frames);
}

void FIELD_SOUND_SYSTEM_StartRingtone(struct SoundSys *sys)
{
    RINGTONE_SYS_Start(sys->ringtone);
}

void func_02028A70(struct SoundSys *sys)
{
    RINGTONE_SYS_Stop(sys->ringtone);
}
