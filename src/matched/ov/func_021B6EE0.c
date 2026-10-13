/*
 * function: SCRCMD_POKEMON_FLD_CreateGiftMon
 * address:  0x021B6EE0
 * packet:   pkt_021B6EE0
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
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   MYSTERY_GIFT_CreateMon  0x02157E9C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct GiftMon;
extern void *MYSTERY_GIFT_CreateMon(const struct GiftMon *g, int heap, void *save);
extern u16 SCRCMD_WORK_GetHeapId(void *a0);
extern void *SCRCMD_WORK_GetGameData(void *a0);

int SCRCMD_POKEMON_FLD_CreateGiftMon(u32 a, u32 b)
{
return (int)MYSTERY_GIFT_CreateMon((const struct GiftMon *)b, SCRCMD_WORK_GetHeapId((void *)a), SCRCMD_WORK_GetGameData((void *)a));
}

