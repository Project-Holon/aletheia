/*
 * function: COMM_PLAYER_Update
 * address:  0x02167590
 * packet:   pkt_ov010_02167590
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   COMM_PLAYER_CreateSys  0x02167A74  thumb
 *   GAMESYSTEM_IsFieldMapExist  0x02012114  thumb
 *   FLDEFF_GYOE_IsFinished  0x021BB5C8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ent {
    u8 pad00[0x14];
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 f15[3];
    u32 f18;
} Ent;

typedef struct Work {
    void *sys;
    void *obj;
    Ent e[4];
} Work;

extern void COMM_PLAYER_CreateSys(int a0, int a1);
struct Ctx;
extern u32 GAMESYSTEM_IsFieldMapExist(const struct Ctx *p);
extern int FLDEFF_GYOE_IsFinished(u32 v);

void COMM_PLAYER_Update(void *a, Work *w)
{
    int i;

    COMM_PLAYER_CreateSys((int)a, (int)w);
    if (GAMESYSTEM_IsFieldMapExist(w->sys) == 1) {
        for (i = 0; i < 4; i++) {
            if (w->e[i].used == 1 && w->e[i].f18 != 0 && FLDEFF_GYOE_IsFinished(w->e[i].f18) == 1)
                w->e[i].f18 = 0;
        }
    }
}
