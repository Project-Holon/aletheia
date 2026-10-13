/*
 * function: GIMMICK39_IsCartBeforeSwitchLimit
 * address: 0x021F4894
 * packet: pkt_ov039_021F4894
 * region: ov039
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GIMMICK39_GetAnimeFrame 0x021F3DE4 thumb ov039
 *   sSwitchFrameLimits 0x021F4BE4 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GIMMICK39_GetAnimeFrame(void *p, u16 delta, u16 i);
extern const u16 sSwitchFrameLimits[];
int GIMMICK39_IsCartBeforeSwitchLimit(void *p, int i, u8 j) { if (GIMMICK39_GetAnimeFrame(p, (u8)i, j + 1) <= (int)(sSwitchFrameLimits[i] << 12)) return 1; return 0; }
