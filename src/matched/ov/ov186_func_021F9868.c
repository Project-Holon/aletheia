/*
 * function: BR_PROC_SYS_LoadBattleRecord
 * address:  0x021F9868
 * packet:   pkt_021F9868
 * region:   ov186
 * status:   EXACT*
 * symbols:
 *   BR_PROC_SYS_LoadRecords  0x021F98F8  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   BATTLE_REC_Load  0x0200B570  thumb
 */
typedef struct Inner {
    int f0;
    int f4;
} Inner;

typedef struct Mid {
    int pad0;
    int pad4;
    int f8;
    Inner *p0c;
} Mid;

typedef struct Top {
    int w0;
    int w1;
    int w2;
    int w3;
    int w4;
    int w5;
    Mid *f18;
    int w7;
    int w8;
    int w9;
    int f28;
    int f2c;
} Top;

void BR_PROC_SYS_LoadRecords(char *p, int skip, void *sys, int heap);
struct Big;
void *GAME_DATA_GetSaveControl(struct Big *p);
typedef unsigned int   u32;
typedef unsigned short u16;
u32 BATTLE_REC_Load(void *a, u16 heap, u32 *dp, u32 id);

void BR_PROC_SYS_LoadBattleRecord(Top *p, Top *q)
{
    int buf[1];

    if (p->f28 == 0)
        return;
    BR_PROC_SYS_LoadRecords((char *)q->f18->f8 + 0x1748, 0, (void *)q->f18->p0c->f4, 0x5a);
    BATTLE_REC_Load((void *)((int)GAME_DATA_GetSaveControl((struct Big *)q->f18->p0c->f4)), 0x805a, (u32 *)buf, p->f2c);
}
