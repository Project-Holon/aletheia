/*
 * function: FIELD_EVENT_CHECK_CheckEggHatch
 * address:  0x0218AB50
 * packet:   pkt_ov021_0218AB50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Step hook: updates SODATEYA_AddStep, advances the party step counter
 * (FIELD_EVENT_CHECK_UpdateEggStepCounter) and, when an egg is ready (FIELD_EVENT_CHECK_IsEggReadyToHatch), shows message
 * 0x8CA.
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   FIELDMAP_GetSodateya  0x02188D50  thumb
 *   SODATEYA_AddStep  0x021C3378  thumb
 *   FIELD_EVENT_CHECK_UpdateEggStepCounter  0x0218AAD0  thumb
 *   FIELD_EVENT_CHECK_IsEggReadyToHatch  0x0218AB0C  thumb
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u16 FIELDMAP_GetHeapId(u8 *p);
struct BigObj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *FIELDMAP_GetSodateya(u8 *p);
extern int SODATEYA_AddStep(void **p);
extern void FIELD_EVENT_CHECK_UpdateEggStepCounter(void *sys, void *party);
extern int FIELD_EVENT_CHECK_IsEggReadyToHatch(void *party);
struct Desc;
extern struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);

int FIELD_EVENT_CHECK_CheckEggHatch(void *p, u8 *pos, void *msg, void *sys)
{
    u16 v = FIELDMAP_GetHeapId(pos);
    void *party = GAME_DATA_GetMyParty(sys);

    SODATEYA_AddStep(FIELDMAP_GetSodateya(pos));
    FIELD_EVENT_CHECK_UpdateEggStepCounter(sys, party);
    if (FIELD_EVENT_CHECK_IsEggReadyToHatch(party))
        return (int)SCRIPT_SYS_CreateScriptEventSimple((int)msg, 0x8CA, 0, v);
    return 0;
}
