/*
 * unit:     yes
 * function: FIELD_SOUND_SYSTEM_DrainAndInit
 * address:  0x02028D2C
 * packet:   pkt_02028B50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * field_sound_system.c: drain and re-arm.  Runs FIELD_SOUND_SYSTEM_PopBgm until the
 * pending counter at +0x20 falls to zero, closes the frame with
 * GFL_USE_CancelChangeAndStopBgm, and then re-initialises the system from the descriptor the
 * caller passed, through the same FIELD_SOUND_SYSTEM_Init the constructor uses.
 *
 * Nothing branches to this function anywhere in the image; its only reference
 * is the pool word of the forwarder at 0x02028A50, so the `label` class
 * cannot see it and src/matched/FIELD_SOUND_SYSTEM_Reset.c is EXACT only because this
 * file is a `matched` witness for it.
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_PopBgm  0x020293D8  thumb
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb
 *   FIELD_SOUND_SYSTEM_Init  0x02028CD4  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/FIELD_SOUND_SYSTEM_DrainAndInit.c \
 *       --func FIELD_SOUND_SYSTEM_DrainAndInit --addr 0x02028D2C --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Sys {
    u8  pad_00[0x20];
    u32 pending;   /* 0x20 */
};

struct T;
extern void FIELD_SOUND_SYSTEM_PopBgm(struct T *p);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void FIELD_SOUND_SYSTEM_Init(u8 *p, u32 v);

void FIELD_SOUND_SYSTEM_DrainAndInit(struct Sys *s, void *desc)
{
    while (s->pending != 0) {
        FIELD_SOUND_SYSTEM_PopBgm((struct T *)s);
    }
    GFL_USE_CancelChangeAndStopBgm();
    FIELD_SOUND_SYSTEM_Init((u8 *)s, (u32)desc);
}
