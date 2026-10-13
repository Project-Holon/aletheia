/*
 * function: FIELD_WFBC_ApplyGiftMood
 * address:  0x02193B40
 * packet:   pkt_ov021_02193B40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_WFBC_DATA_LOCAL_ApplyGiftMoodBonus  0x02186748  thumb  ov020
 *   FIELD_WFBC_LoadSaveData  0x02193EB4  thumb  ov021
 *   FIELD_WFBC_StoreSaveData  0x02193EE8  thumb  ov021
 *   FIELD_WFBC_FindPeople  0x02193EFC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct E50 {
    u16 f00;
    u8  pad02[0x32];
    u8  f34[0x1C];
} E50;

typedef struct E18 {
    u8 b[0x18];
} E18;

typedef struct Tbl {
    u8  hdr[8];
    E18 e[10];
} Tbl;

typedef struct V {
    u8   f00;
    u8   f01;
    u8   pad02[2];
    E50 *f04;
    Tbl *f08;
} V;

extern void FIELD_WFBC_LoadSaveData(V *v);
extern E50 *FIELD_WFBC_FindPeople(V *v, u32 key);
struct State;
extern void FIELD_WFBC_DATA_LOCAL_ApplyGiftMoodBonus(struct State *p);
extern void FIELD_WFBC_StoreSaveData(V *v);

void FIELD_WFBC_ApplyGiftMood(V *v, u32 key)
{
    E50 *e;

    FIELD_WFBC_LoadSaveData(v);
    e = FIELD_WFBC_FindPeople(v, key);
    if (v->f01 == 0) {
        FIELD_WFBC_DATA_LOCAL_ApplyGiftMoodBonus((struct State *)e->f34);
        FIELD_WFBC_StoreSaveData(v);
    }
}
