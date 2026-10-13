/*
 * function: FIELD_EVENT_CHECK_CheckStepEncount
 * address:  0x0218AC84
 * packet:   pkt_ov021_0218AC84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Runs EFFECT_ENCOUNT_TriggerSpot on the position's object; when it declines, calls
 * EFFECT_ENCOUNT_OnPlayerStep and returns 0.
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   FIELDMAP_GetEncount  0x02188CE8  thumb
 *   EFFECT_ENCOUNT_TriggerSpot  0x021AA944  thumb
 *   EFFECT_ENCOUNT_OnPlayerStep  0x021AA80C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Big;
struct Ctx;
struct Self;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u32 FIELDMAP_GetEncount(u8 *p);
extern int EFFECT_ENCOUNT_TriggerSpot(struct Self *self);
extern void EFFECT_ENCOUNT_OnPlayerStep(struct Ctx *ctx);

int FIELD_EVENT_CHECK_CheckStepEncount(u8 *pos, void *msg, void *sys)
{
    void *obj;
    int r;

    GAME_DATA_GetSaveControl(sys);
    obj = (void *)FIELDMAP_GetEncount(pos);
    r = EFFECT_ENCOUNT_TriggerSpot(obj);
    if (r == 0) {
        EFFECT_ENCOUNT_OnPlayerStep(obj);
        return 0;
    }
    return r;
}
