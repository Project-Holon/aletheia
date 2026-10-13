/*
 * function: FIELD_WFBC_ClearPeopleArrivalFlag
 * address:  0x02193BC4
 * packet:   pkt_02193BC4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Promoted from src/pending/: the blocker this file named is filed.
 * FIELD_WFBC_DATA_LOCAL_ClearArrivalFlag (0x02186764) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_WFBC_LoadSaveData  0x02193EB4  thumb  ov021
 *   FIELD_WFBC_FindPeople  0x02193EFC  thumb  ov021
 *   FIELD_WFBC_DATA_LOCAL_ClearArrivalFlag  0x02186764  thumb
 *   FIELD_WFBC_StoreSaveData  0x02193EE8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void FIELD_WFBC_DATA_LOCAL_ClearArrivalFlag(u8 *);
struct V;
extern void FIELD_WFBC_LoadSaveData(struct V *v);
extern void FIELD_WFBC_StoreSaveData(struct V *v);
extern u8 *FIELD_WFBC_FindPeople(void *, u32);

void FIELD_WFBC_ClearPeopleArrivalFlag(void *a, u32 b)
{
FIELD_WFBC_LoadSaveData(a);
FIELD_WFBC_DATA_LOCAL_ClearArrivalFlag((FIELD_WFBC_FindPeople(a, b) + 52));
FIELD_WFBC_StoreSaveData(a);
}

