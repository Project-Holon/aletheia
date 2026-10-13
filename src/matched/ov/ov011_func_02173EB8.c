/*
 * function: INTRUDE_CMD_RecvGroupRecord
 * address: 0x02173EB8
 * packet: pkt_ov011_02173EB8
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02026478 0x02026478 thumb
 *   GAME_DATA_GetMyPlayerWork 0x020127A4 thumb
 *   GAME_DATA_GetPlayerZoneId 0x02012AC8 thumb
 *   INTRUDE_COMM_StoreSessionRequest 0x02175954 thumb ov011
 */
#include "../include/Obj12417.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct SaveBlock;
struct Rec44;
u32 func_02026478(void *obj);
void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *a);
unsigned short GAME_DATA_GetPlayerZoneId(const struct Rec44 *a);
typedef struct Rec {
    u32 lo : 15;
    u32 a : 7;
    u32 b : 10;
    u8 pad04[0x28];
    u8 f2c;
    u8 pad2d[7];
} Rec;
int INTRUDE_COMM_StoreSessionRequest(void *unused, u8 *o, Rec *src);

void INTRUDE_CMD_RecvGroupRecord(int a, int b, void *c, u8 *d)
{
    GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork((struct SaveBlock *)func_02026478(((struct Obj12417 *)d)->f4)));
    if (INTRUDE_COMM_StoreSessionRequest(d, d + 0x1ac, c) == 1) d[0x90d] = 1;
}
