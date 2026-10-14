/*
 * function: BTLV_EFFVM_IsAllIdle
 * address: 0x021FC744
 * packet: pkt_ov094_021FC744
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * witness: arm9 PARTICLE_GetEffectCount filed as src/matched/arm9/PARTICLE_GetEffectCount.c.
 * followers: 021FC9D0 countdown <=0; 021FC9E4 !flags bit7;
 *   021FC9F4 !flags bit16 (filed as their own packets).
 * lever: enum loop counters retain entry guards; flag bitfields retain
 *   shift-pair tests (raw unsigned mask expressions added 16 bytes).
 * symbols:
 *   BTLV_EFFECT_GetCamera 0x021F8684 thumb ov094
 *   BTLV_CAMERA_IsMoving 0x021F722C thumb ov094
 *   BTLV_EFFECT_GetMcss 0x021F8694 thumb ov094
 *   BTLV_MCSS_EnableOrthoMode 0x021FF16C thumb ov094
 *   BTLV_MCSS_IsSpriteBusy 0x021FFCB0 thumb ov094
 *   BTLV_MCSS_IsSpriteLoaded 0x021FFD9C thumb ov094
 *   BTLV_MCSS_IsAnimPending 0x02200494 thumb ov094
 *   BTLV_EFFECT_GetBg 0x021F8700 thumb ov094
 *   BTLV_BG_IsScrolling 0x0220985C thumb ov094
 *   PARTICLE_GetEffectCount 0x02051614 arm
 *   BTLV_EFFECT_IsStageFieldBusy 0x021F8324 thumb ov094
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 *   GFL_USE_IsSeSlotBusy 0x02006224 thumb
 *   PM_VOICE_IsActive 0x02006BD0 thumb
 */
typedef enum { SLOT_ZERO, SLOT_LAST = 14 } Slot;
typedef union {
    unsigned word;
    struct {
        unsigned b0 : 1;
        unsigned b1 : 1;
        unsigned b2 : 1;
        unsigned b3 : 1;
        unsigned gap4 : 3;
        unsigned b7 : 1;
        unsigned b8 : 1;
        unsigned gap9 : 2;
        unsigned b11 : 1;
        unsigned gap12 : 4;
        unsigned b16 : 1;
    } bit;
} Flags;
typedef struct {
    Flags flags;
    char pad[8];
    void *objects[16];
    char pad2[0x240 - 0x4c];
    unsigned mode;
    int f244;
    char pad3[0x26c - 0x248];
    int slots[6];
} State;
extern int BTLV_EFFECT_GetCamera(void);
extern int BTLV_CAMERA_IsMoving(char *p);
extern int BTLV_EFFECT_GetMcss(void);
extern void BTLV_MCSS_EnableOrthoMode(void *);
extern int BTLV_MCSS_IsSpriteBusy(void *, int);
typedef unsigned int   u32;
extern int BTLV_MCSS_IsSpriteLoaded(char *p, int key);
extern int BTLV_MCSS_IsAnimPending(char *p, int key);
extern int BTLV_EFFECT_GetBg(void);
extern int BTLV_BG_IsScrolling(void *);
extern int PARTICLE_GetEffectCount(int **p);
extern int BTLV_EFFECT_IsStageFieldBusy(unsigned);
extern int GFL_USE_IsAnySeBusy(void);
extern int GFL_USE_IsSeSlotBusy(unsigned);
extern u32 PM_VOICE_IsActive(u32 i);

int BTLV_EFFVM_IsAllIdle(int a, State *s)
{
    int i;
    Slot j;

    if (s->mode <= 1) {
        if (BTLV_CAMERA_IsMoving((char *)BTLV_EFFECT_GetCamera()) == 1) return 0;
        if (s->flags.bit.b1) {
            s->flags.bit.b1 = 0;
            s->f244 = 1;
            BTLV_MCSS_EnableOrthoMode((void *)BTLV_EFFECT_GetMcss());
        }
    }
    if (s->mode == 0 || s->mode == 3) {
        for (j = 0; j < 14; j++) {
            if (BTLV_MCSS_IsSpriteBusy((void *)BTLV_EFFECT_GetMcss(), j) == 1) return 0;
        }
    }
    if (s->mode == 4) {
        for (j = 8; j < 14; j++) {
            if (BTLV_MCSS_IsSpriteLoaded((char *)BTLV_EFFECT_GetMcss(), j)) {
                if (BTLV_MCSS_IsAnimPending((char *)BTLV_EFFECT_GetMcss(), j) == 1) return 0;
            }
        }
    }
    if (s->mode == 0 || s->mode == 5) {
        if (BTLV_BG_IsScrolling((void *)BTLV_EFFECT_GetBg()) == 1) return 0;
    }
    if (s->mode == 0 || s->mode == 2) {
        for (i = 0; i < 16; i++) {
            if (s->objects[i] != 0) {
                if (PARTICLE_GetEffectCount(s->objects[i]) != 0) return 0;
            }
        }
    }
    if (s->mode == 0 || s->mode == 6 || s->mode == 8) {
        if (BTLV_EFFECT_IsStageFieldBusy(0) != 0) return 0;
    }
    if (s->mode == 0 || s->mode == 7 || s->mode == 8) {
        if (BTLV_EFFECT_IsStageFieldBusy(1) != 0) return 0;
    }
    if (s->mode == 0 || s->mode == 9) {
        if (BTLV_EFFECT_IsStageFieldBusy(3) != 0) return 0;
    }
    if (s->mode == 10) {
        if (GFL_USE_IsAnySeBusy() != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 11) {
        if (GFL_USE_IsSeSlotBusy(1) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 12) {
        if (GFL_USE_IsSeSlotBusy(2) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 13) {
        if (GFL_USE_IsSeSlotBusy(4) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 14) {
        if (GFL_USE_IsSeSlotBusy(3) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 15) {
        if (GFL_USE_IsSeSlotBusy(0) != 0 || s->flags.bit.b2 || s->flags.bit.b3) return 0;
    }
    if (s->mode == 16) {
        if (s->flags.bit.b11) return 0;
        for (i = 0; i < 6; i++) {
            if (s->slots[i] != -1) {
                if (PM_VOICE_IsActive(s->slots[i]) != 0) return 0;
                s->slots[i] = -1;
            }
        }
    }
    if (s->mode == 0 || s->mode == 17) {
        if (s->flags.bit.b8) return 0;
    }
    return 1;
}
