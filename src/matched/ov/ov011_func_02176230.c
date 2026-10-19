/*
 * function: INTRUDE_COMM_GetRequesterNetId
 * address: 0x02176230
 * packet: pkt_ov011_02176230
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two alignment bytes at 02176256.
 * interface: original +0x1A/+0x1C narrows the full-width call result;
 * the callee's filed u8 return removes this pair (r2: DIFF 9 bytes).
 * symbols:
 *   INTRUDE_COMM_IsSessionActive 0x02175B14 thumb ov011
 *   GAME_COMM_GetGameData 0x02026478 thumb
 *   GAME_DATA_GetOwnNetId 0x02012B58 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int INTRUDE_COMM_IsSessionActive(u8 *p);
extern u32 GAME_COMM_GetGameData(void *p);
struct BigObj;
extern u8 GAME_DATA_GetOwnNetId(const struct BigObj *p);
u8 INTRUDE_COMM_GetRequesterNetId(u8 *p, u8 *q)
{
    if (INTRUDE_COMM_IsSessionActive(q) == 0) {
        return (int)GAME_DATA_GetOwnNetId((const void *)GAME_COMM_GetGameData(((void **)p)[1]));
    }
    return q[0xa0];
}
