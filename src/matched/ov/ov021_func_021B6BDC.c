/*
 * function: SCRCMD_POKEMON_FLD_HandleMysteryGift
 * address:  0x021B6BDC
 * packet:   pkt_ov021_021B6BDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MYSTERY_DATA_Create  0x0200A300  thumb
 *   MYSTERY_DATA_Delete  0x0200A338  thumb
 *   PDW_POSTMAN_FindMysteryCard  0x021B7834  thumb  ov021
 *   PDW_POSTMAN_GetMysteryGiftType  0x021B7864  thumb  ov021
 *   PDW_POSTMAN_SetMysteryReceived  0x021B785C  thumb  ov021
 *   SCRCMD_POKEMON_FLD_CheckGiftCanReceive  0x021B6D0C  thumb  ov021
 *   SCRCMD_POKEMON_FLD_PrepareGiftReceiveMessage  0x021B6D30  thumb  ov021
 *   SCRCMD_POKEMON_FLD_PrepareGiftFollowUpMessage  0x021B6D64  thumb  ov021
 *   SCRCMD_POKEMON_FLD_ReceiveGift  0x021B6D98  thumb  ov021
 *   SCRCMD_POKEMON_FLD_GetGiftReceiveType  0x021B6DC0  thumb  ov021
 *   SCRCMD_POKEMON_FLD_GetDeliveryNpcId  0x021B6DE4  thumb  ov021
 *   SCRCMD_POKEMON_FLD_CheckDeliveryNpcLoaded  0x021B6E0C  thumb  ov021
 *   SCRCMD_POKEMON_FLD_IsLibertyPassGift  0x021B6EB0  thumb  ov021
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   FIELD_G3D_MAP_StoreBeaconTrainerKey  0x0216BF74  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   d_021D9970     0x021D9970  data   ov021  a4
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Ent {
    int id;
    u32 f4[5];
} Ent;

extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void *SCRCMD_WORK_GetGameData(void *a0);
struct Big;
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MYSTERY_DATA_Create(void *a0, void *a1, void *a2);
extern void MYSTERY_DATA_Delete(void *h);
extern void *PDW_POSTMAN_FindMysteryCard(void *a, int *out, void *buf);
struct Ctx;
extern u8 PDW_POSTMAN_GetMysteryGiftType(void *a);
extern void PDW_POSTMAN_SetMysteryReceived(u8 *p, u32 i);
extern int SCRCMD_POKEMON_FLD_CheckGiftCanReceive(int idx, void *x, void *y, void *z);
extern int SCRCMD_POKEMON_FLD_PrepareGiftReceiveMessage(int idx, void *x, void *c);
extern int SCRCMD_POKEMON_FLD_PrepareGiftFollowUpMessage(int idx, void *x, void *c);
extern int SCRCMD_POKEMON_FLD_ReceiveGift(int idx, void *x, void *y, void *z);
extern int SCRCMD_POKEMON_FLD_GetGiftReceiveType(int idx, void *x, void *y, void *z);
extern u16 SCRCMD_POKEMON_FLD_GetDeliveryNpcId(void *a, void *sv);
extern u16 SCRCMD_POKEMON_FLD_CheckDeliveryNpcLoaded(void *a);
extern int SCRCMD_POKEMON_FLD_IsLibertyPassGift(u32 *o, int k);
extern void *GAME_DATA_GetMiscSave(int *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void FIELD_G3D_MAP_StoreBeaconTrainerKey(void *a, int i, void *b);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern Ent d_021D9970[];

int SCRCMD_POKEMON_FLD_HandleMysteryGift(u32 a, u32 b)
{
    int mode;
    u16 *out;
    void *sv;
    void *h;
    u32 heap;
    u8 *p;
    int k;
    u8 buf[0xcc];
    u32 x;

    mode = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    out = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    sv = SCRCMD_WORK_GetGameData((void *)b);
    heap = SCRCMD_WORK_GetHeapId((void *)b);
    h = MYSTERY_DATA_Create(GAME_DATA_GetSaveControl(sv), 0, (void *)heap);
    p = PDW_POSTMAN_FindMysteryCard(h, (int *)(&x), buf);
    k = PDW_POSTMAN_GetMysteryGiftType(h);
    if (k != d_021D9970[k].id) {
        MYSTERY_DATA_Delete(h);
        return 0;
    }
    switch (mode) {
    case 0:
        if (k != 0) {
            *out = 1;
        } else {
            *out = 0;
        }
        break;
    case 1:
        *out = SCRCMD_POKEMON_FLD_CheckGiftCanReceive(k, (void *)b, sv, p);
        break;
    case 2:
        *out = SCRCMD_POKEMON_FLD_PrepareGiftReceiveMessage(k, p, (void *)b);
        break;
    case 3:
        *out = SCRCMD_POKEMON_FLD_PrepareGiftFollowUpMessage(k, p, (void *)b);
        break;
    case 4:
        if (SCRCMD_POKEMON_FLD_ReceiveGift(k, (void *)b, sv, p) == 1) {
            PDW_POSTMAN_SetMysteryReceived(h, x);
            if (SCRCMD_POKEMON_FLD_IsLibertyPassGift((u32 *)p, k) == 1) {
                FIELD_G3D_MAP_StoreBeaconTrainerKey(GAME_DATA_GetMiscSave(sv), 1, GAME_DATA_GetMyStatus(sv));
            }
        }
        *out = 0;
        break;
    case 5:
        *out = SCRCMD_POKEMON_FLD_GetDeliveryNpcId(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b)), sv);
        break;
    case 6:
        *out = SCRCMD_POKEMON_FLD_CheckDeliveryNpcLoaded(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b)));
        break;
    case 7:
        *out = SCRCMD_POKEMON_FLD_GetGiftReceiveType(k, (void *)b, sv, p);
        break;
    }
    MYSTERY_DATA_Delete(h);
    return 0;
}
