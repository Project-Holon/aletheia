/*
 * function: BTL_CALC_MakeSickContFromKind
 * address:  0x021D7DC0
 * packet:   pkt_ov093_021D7DC0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CALC_MakeDefaultSickCont  0x021D7D18  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTLV_CORE_MakeSlotKind3  0x021E899C  thumb  ov093
 *   BTL_CALC_RandRange  0x021D7B8C  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1Empty  0x021E89C0  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u32 v; } Word;

extern Word BTL_CALC_MakeDefaultSickCont(int x);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern Word BTLV_CORE_MakeSlotKind3(u32 a);
extern u32 BTL_CALC_RandRange(u32 lo, u32 hi);
extern Word BTLV_CORE_MakeSlotKind2Index(u8 a);
extern Word BTLV_CORE_MakeSlotKind1Empty(void);

void BTL_CALC_MakeSickContFromKind(int a, int b, Word *out)
{
    u8 y;

    if (a < 6) {
        *out = BTL_CALC_MakeDefaultSickCont(a);
        return;
    }
    out->v = 0;
    switch (a) {
    case 7:
        *out = BTLV_CORE_MakeSlotKind3(BTL_POKEPARAM_GetPokeId((u8 *)b));
        break;
    case 6:
        y = BTL_CALC_RandRange(2, 5);
        *out = BTLV_CORE_MakeSlotKind2Index(y);
        break;
    default:
        *out = BTLV_CORE_MakeSlotKind1Empty();
        break;
    }
}
