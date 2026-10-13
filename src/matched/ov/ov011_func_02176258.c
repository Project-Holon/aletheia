/*
 * function: INTRUDE_COMM_IsRequestFromSelf
 * address: 0x02176258
 * packet: pkt_ov011_02176258
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two alignment bytes at 0217627E.
 * symbols:
 *   INTRUDE_COMM_IsRequestFromNetId 0x0217620C thumb ov011
 *   func_02026478 0x02026478 thumb
 *   GAME_DATA_GetExitMode 0x02012B58 thumb
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int INTRUDE_COMM_IsRequestFromNetId(u8 *p, int key);
extern u32 func_02026478(void *p);
struct BigObj;
extern u8 GAME_DATA_GetExitMode(const struct BigObj *p);
int INTRUDE_COMM_IsRequestFromSelf(u8 *p)
{
    if (INTRUDE_COMM_IsRequestFromNetId(p + 0x1ac, GAME_DATA_GetExitMode((const void *)func_02026478(((void **)p)[1]))) == 1) return 1;
    return 0;
}
