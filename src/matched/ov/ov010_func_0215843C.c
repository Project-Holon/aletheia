/*
 * function: INTRUDE_COMM_GetAreaOwnerVersion
 * address: 0x0215843C
 * packet: pkt_ov010_0215843C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes at 0x02158466 precede 0x02158468.
 * lever: A named u8 id truncates the result in r0 before preparing r1.
 * symbols:
 *   GAME_COMM_GetGameData 0x02026478 thumb
 *   GAME_DATA_GetIntrudeCount 0x02012B70 thumb
 *   GAME_DATA_GetIntrudeId 0x02012B80 thumb
 *   GAME_DATA_GetMyStatusByNetId 0x021583EC thumb ov010
 *   func_0200855C 0x0200855C thumb
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 GAME_COMM_GetGameData(void *obj);
struct BigObj;
struct Sub0200852CObj;
extern int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
extern u8 GAME_DATA_GetIntrudeId(const struct BigObj *p);
extern int GAME_DATA_GetMyStatusByNetId(void *a0, int a1);
extern u8 func_0200855C(const struct Sub0200852CObj *obj);
int INTRUDE_COMM_GetAreaOwnerVersion(void *p)
{
    void *q = (void *)GAME_COMM_GetGameData(p);
    u8 id;
    if (GAME_DATA_GetIntrudeCount(q) == 0)
        return 21;
    id = (int)GAME_DATA_GetIntrudeId(q);
    return func_0200855C((const struct Sub0200852CObj *)GAME_DATA_GetMyStatusByNetId(q, id));
}
