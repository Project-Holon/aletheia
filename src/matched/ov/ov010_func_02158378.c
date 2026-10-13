/*
 * unit:     yes
 * function: INTRUDE_COMM_GetPlayerNetId, INTRUDE_COMM_TogglePeerFlags
 * address:  0x02158378
 * packet:   pkt_ov010_02158378
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GAME_DATA_GetExitMode  0x02012B58  thumb
 */

typedef unsigned char u8;

typedef struct { u8 a : 4; u8 f : 2; u8 b : 2; } Fl;

struct BigObj;
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
typedef unsigned int   u32;
extern u32 GAME_COMM_GetGameData(void *obj);
extern u8 GAME_DATA_GetExitMode(const struct BigObj *p);

int INTRUDE_COMM_GetPlayerNetId(void *p)
{
    u8 *q = (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)p);
    if (q == 0) {
        return GAME_DATA_GetExitMode((const struct BigObj *)GAME_COMM_GetGameData(p));
    }
    return q[0x911];
}

int INTRUDE_COMM_TogglePeerFlags(u8 *p, int m, int a2)
{
    Fl *s = (Fl *)(p + 0x93F);
    u8 t = s->f;
    if (m & t) {
        s->f ^= 1;
        return 1;
    }
    return 0;
}
