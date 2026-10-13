/*
 * function: ENCEFF_SelectEffectAndBgmForTrainer
 * address:  0x021CF748
 * packet:   pkt_ov021_021CF748
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Picks a value pair from two small tables, or a state code from the field
 * state when the index is out of range.
 *
 * symbols:
 *   func_0202A230  0x0202A230  thumb
 *   func_0202A3FC  0x0202A3FC  thumb
 *   func_0202A3D8  0x0202A3D8  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetNowAttribute  0x021A30C8  thumb  ov021
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb  ov021
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   MAP_ATTR_IsSandVariant  0x021AB37C  thumb  ov021
 *   FIELDMAP_GetAreaData  0x02188D58  thumb  ov021
 *   ZONEDATA_GetAreaInnerOuter  0x020140D8  thumb
 *   d_021DB7E0     0x021DB7E0  data  ov021  a2
 *   d_021DB7F6     0x021DB7F6  data  ov021  a1
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern const u16 d_021DB7E0[];
extern const u8  d_021DB7F6[];

struct Sub020140BCObj;
extern u32 func_0202A230(void *a, u32 idx);
extern u8 func_0202A3FC(u32 key);
extern u8 func_0202A3D8(u32 key);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u32 FIELD_PLAYER_GetNowAttribute(void **ctx);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern int MAP_ATTR_IsSandVariant(u32 id);
extern u32 FIELDMAP_GetAreaData(u8 *p);
extern u8 ZONEDATA_GetAreaInnerOuter(struct Sub020140BCObj *p);

void ENCEFF_SelectEffectAndBgmForTrainer(u32 a, u32 x, int *out, u16 *out2)
{
    int flag = 1;
    u32 t = func_0202A230((void *)a, 1);
    u32 k = func_0202A3FC(t);
    u32 m = func_0202A3D8(t);
    int code;

    if (k < 0xb) {
        *out2 = d_021DB7E0[k];
        *out = d_021DB7F6[m];
        return;
    }
    {
        u32 y = FIELD_PLAYER_GetNowAttribute(FIELDMAP_GetFieldPlayer((void *)x));
        u32 z = MAP_ATTR_GetTerrainId(y);

        if (MAP_ATTR_GetFlags(y) & 2) {
            code = 6;
        } else if (MAP_ATTR_IsSandVariant(z) != 0) {
            code = 8;
        } else {
            if (ZONEDATA_GetAreaInnerOuter((struct Sub020140BCObj *)FIELDMAP_GetAreaData((u8 *)x)) == 0) {
                flag = 0;
            }
            code = 5;
            if (flag == 0) {
                code = 7;
            }
        }
    }
    *out2 = 0x46a;
    *out = code;
}
