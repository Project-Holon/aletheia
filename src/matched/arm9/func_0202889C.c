/*
 * unit:     yes
 * function: FIELD_SOUND_SYSTEM_Delete
 * address:  0x0202889C
 * packet:   pkt_0202878C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * field_sound_system.c.  The destructor: it drops the frame callback, tears down the ringtone handle
 * at +0xA8 and the volume fader at +0xA4, and frees the object.
 *
 * symbols:
 *   GFL_USE_SetSeqStartFilter  0x02005D08  thumb
 *   PLAYER_VOLUME_FADER_Delete  0x02028784  thumb
 *   RINGTONE_SYS_Delete  0x02029F44  thumb
 *   func_020307B0  0x020307B0  arm
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/FIELD_SOUND_SYSTEM_Delete.c  *       --addr 0x0202889C --thumb
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

struct SoundSys {
    u8    unk00[0xA4];
    void *fader;
    void *ringtone;
};

extern void GFL_USE_SetSeqStartFilter(void *fn);
extern void RINGTONE_SYS_Delete(void *p);
extern void PLAYER_VOLUME_FADER_Delete(void *p);
extern u32 func_020307B0(void *p);

void FIELD_SOUND_SYSTEM_Delete(struct SoundSys *s)
{
    GFL_USE_SetSeqStartFilter(0);
    RINGTONE_SYS_Delete(s->ringtone);
    PLAYER_VOLUME_FADER_Delete(s->fader);
    func_020307B0(s);
}
