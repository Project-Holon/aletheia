/*
 * unit:     yes
 * address:  0x02012BE0
 * packet:   pkt_02012924
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: GAME_DATA_SetSaveFlag
 *
 * symbols:
 *   RECENT_ID_LIST_SAVEDATA_GetBlock  0x0200C40C  thumb
 *   RECENT_ID_LIST_SAVEDATA_SetId  0x0200C418  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *
 * One function, 24 bytes, because the function immediately after it is a near
 * miss and the one after that is src/matched/unit_02012C0C.c.
 *
 * 0x02012BF8, 20 bytes, is the twin of this one and reproduces every concrete
 * byte:
 *
 *     void GAME_DATA_CheckSaveFlag(void *p, u32 a)
 *     {
 *         RECENT_ID_LIST_SAVEDATA_ContainsId(RECENT_ID_LIST_SAVEDATA_GetBlockFromSys(GAME_DATA_GetSaveControlWork(p)), a);
 *     }
 *
 * with `RECENT_ID_LIST_SAVEDATA_GetBlockFromSys 0x0200C404 thumb`, `RECENT_ID_LIST_SAVEDATA_ContainsId 0x0200C44C thumb` and
 * `GAME_DATA_GetSaveControlWork 0x02012EC0 thumb`.  It caps at MATCH because the `bl` at
 * 0x02012C06 is the only branch to RECENT_ID_LIST_SAVEDATA_ContainsId anywhere in the image, so the
 * `label` class has no witness outside the range and, this being the only
 * caller, no cut can create one.  Evidence class: label, 0 witnesses outside.
 * The other five call targets here all have witnesses elsewhere.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02012BE0.c \
 *       --addr 0x02012BE0 --thumb
 */

typedef unsigned int u32;

extern void *RECENT_ID_LIST_SAVEDATA_GetBlock(void *p);
typedef unsigned char  u8;
extern void RECENT_ID_LIST_SAVEDATA_SetId(u8 *a, u32 id, u32 on);
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);

void GAME_DATA_SetSaveFlag(void *p, u32 a, u32 b)
{
    RECENT_ID_LIST_SAVEDATA_SetId(RECENT_ID_LIST_SAVEDATA_GetBlock(GAME_DATA_GetSaveControl(p)), a, b);
}
