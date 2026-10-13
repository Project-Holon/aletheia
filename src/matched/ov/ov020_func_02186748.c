/*
 * function: FIELD_WFBC_DATA_LOCAL_ApplyGiftMoodBonus
 * address: 0x02186748
 * packet: pkt_ov020_02186748
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: raw-byte flag test, then bitfield assignment for the bics clear.
 * symbols:
 *   FIELD_WFBC_DATA_LOCAL_AddMood 0x02186BB8 thumb ov020
 */

typedef unsigned char u8;
struct State { u8 pad[3]; u8 low:2; u8 flag:1; u8 high:5; };
extern int FIELD_WFBC_DATA_LOCAL_AddMood(u8 *p, int delta);
void FIELD_WFBC_DATA_LOCAL_ApplyGiftMoodBonus(struct State *p) { if (((u8 *)p)[3] & 4) { FIELD_WFBC_DATA_LOCAL_AddMood((u8 *)p, 10); p->flag = 0; } }
