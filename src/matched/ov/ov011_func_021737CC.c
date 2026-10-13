/*
 * function: INTRUDE_COMM_RecvStatusRecord
 * address:  0x021737CC
 * packet:   pkt_ov011_021737CC
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   INTRUDE_COMM_ApplyPlayerBeacon  0x02174EAC  thumb  ov011
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 *   GFL_NET_IsParentAid  0x0203D378  arm
 */

typedef unsigned char u8;

typedef struct {
    int f0;
    int f4;
    u8 pad08[0x8fa];
    u8 n;
    u8 pad03[0x3c];
    u8 flag : 1;
} D;

typedef struct {
    u8 pad[0x4b];
    u8 lo : 6;
    u8 hit : 1;
} C;

extern unsigned int GAME_COMM_GetGameData(void *obj);
extern void INTRUDE_COMM_ApplyPlayerBeacon(u8 *p, int idx, u8 *q);
struct BigObj;
extern u8 GAME_DATA_GetExitMode(const struct BigObj *p);
typedef unsigned int   u32;
extern u32 GFL_NET_IsParentAid(void);

void INTRUDE_COMM_RecvStatusRecord(int a, int b, C *c, D *d)
{
    int h;

    h = GAME_COMM_GetGameData((void *)d->f4);
    if (a < d->n) {
        INTRUDE_COMM_ApplyPlayerBeacon((u8 *)d, a, (u8 *)c);
        if (a != GAME_DATA_GetExitMode((const struct BigObj *)h) && GFL_NET_IsParentAid() == 0 && a == 0 && c->hit == 1)
            d->flag = 1;
    }
}
