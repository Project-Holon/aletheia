/*
 * function: FIELD_WFBC_RemovePeople
 * address:  0x02193B20
 * packet:   pkt_02193B20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_WFBC_LoadSaveData  0x02193EB4  thumb  ov021
 *   FIELD_WFBC_FindPeople  0x02193EFC  thumb  ov021
 *   FIELD_WFBC_PEOPLE_Clear  0x02193F6C  thumb  ov021
 *   FIELD_WFBC_StoreSaveData  0x02193EE8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct V;
extern void FIELD_WFBC_LoadSaveData(struct V *v);
extern u32 FIELD_WFBC_StoreSaveData(u32);
struct E50;
struct V;
extern struct E50 *FIELD_WFBC_FindPeople(struct V *v, u32 key);
extern void FIELD_WFBC_PEOPLE_Clear(struct E50 *e);

int FIELD_WFBC_RemovePeople(u32 a, u32 b)
{
FIELD_WFBC_LoadSaveData((struct V *)a);
FIELD_WFBC_PEOPLE_Clear(FIELD_WFBC_FindPeople((struct V *)a, b));
return FIELD_WFBC_StoreSaveData(a);
}

