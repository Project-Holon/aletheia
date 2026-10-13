/*
 * function: BTL_CALC_MakeSickContFromSpec
 * address:  0x021D7C70
 * packet:   pkt_ov093_021D7C70
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTLV_CORE_MakeSlotKind3  0x021E899C  thumb  ov093
 *   BTL_CALC_RandRange  0x021D7B8C  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb  ov093
 *   BTLV_CORE_MakeSlotKind1  0x021E89F8  thumb  ov093
 *   BTLV_CORE_MakeSlotKind4  0x021E8A28  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

typedef struct { u32 v; } Word;
struct Sel { u16 kind : 4; u16 lo : 6; u16 hi : 6; };

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern Word BTLV_CORE_MakeSlotKind3(u32 a);
extern u32 BTL_CALC_RandRange(u32 lo, u32 hi);
extern Word BTLV_CORE_MakeSlotKind2Index(u8 a);
extern Word BTLV_CORE_MakeSlotKind1(u8 a, u32 b);
extern Word BTLV_CORE_MakeSlotKind4(u32 a, u8 b);

void BTL_CALC_MakeSickContFromSpec(struct Sel s, int m, Word *out)
{
    u8 x;
    u8 y;

    switch (s.kind) {
    case 3:
        *out = BTLV_CORE_MakeSlotKind3(BTL_POKEPARAM_GetPokeId((u8 *)m));
        break;
    case 2:
        y = BTL_CALC_RandRange(s.lo, s.hi);
        *out = BTLV_CORE_MakeSlotKind2Index(y);
        break;
    case 1:
        *out = BTLV_CORE_MakeSlotKind1(s.hi, s.lo);
        break;
    case 4:
        x = BTL_POKEPARAM_GetPokeId((u8 *)m);
        y = BTL_CALC_RandRange(s.lo, s.hi);
        *out = BTLV_CORE_MakeSlotKind4(x, y);
        break;
    case 0:
    default:
        break;
    }
}
