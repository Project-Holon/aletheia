/*
 * function: FIELD_GIMMICK_CART_LANES_IsCartBeforeSwitchLimit
 * address: 0x021F4894
 * packet: pkt_ov039_021F4894
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELD_GIMMICK_CART_LANES_GetAnimeFrame 0x021F3DE4 thumb ov039
 *   sSwitchFrameLimits 0x021F4BE4 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int FIELD_GIMMICK_CART_LANES_GetAnimeFrame(void *p, u16 delta, u16 i);
extern const u16 sSwitchFrameLimits[];
int FIELD_GIMMICK_CART_LANES_IsCartBeforeSwitchLimit(void *p, int i, u8 j) { if (FIELD_GIMMICK_CART_LANES_GetAnimeFrame(p, (u8)i, j + 1) <= (int)(sSwitchFrameLimits[i] << 12)) return 1; return 0; }
