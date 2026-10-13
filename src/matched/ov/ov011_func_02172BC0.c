/*
 * function: INTRUDE_COMM_Create
 * address:  0x02172BC0
 * packet:   pkt_ov011_02172BC0
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The call to arm9 0x02008494 (an unlabelled 32-byte copy leaf) is attested
 * by its own EXACT shard, pkt_02008494.
 *
 * symbols:
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   INTRUDE_COMM_HasUnlockFlags  0x02158590  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   str_02177000   0x02177000  data  ov011  a1
 *   COMM_PLAYER_Create  0x02167518  thumb  ov010
 *   INTRUDE_COMM_InitRequest  0x0217538C  thumb  ov011
 *   INTRUDE_COMM_InitSession  0x0217576C  thumb  ov011
 *   INTRUDE_COMM_InitBeacon  0x02173590  thumb  ov011
 *   EVENT_FIELD_PROCLINK_InitReturnSlotsWithAid  0x02161F54  thumb  ov010
 *   STRBUF_Create  0x020457B0  arm
 *   GAME_DATA_SetExitMode  0x02012B64  thumb
 *   GAME_DATA_SetIntrudeId  0x02012B8C  thumb
 *   GAME_DATA_SetEnterMode  0x02012B4C  thumb
 *   GAME_DATA_GetPlayerStatus  0x02012950  thumb
 *   MYSTATUS_Copy  0x02008494  thumb
 *
 * evidence: 0x02008494 is an unlabelled ARM9 thunk ("ldr r3, =func_02082D44; movs r2, #0x20; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov018 0x0217FDEC, ov021 0x021CD548, ov088 0x021BC32A and more), so the call
 * attests as `label`.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Param {
    u32   field00;
    void *field04;
    u8    pad08[6];
    u8    field0e;
} Param;

typedef struct Work {
    u32   field000;
    void *field004;
    void *field008;
    u8    pad00c[0x8fd - 0x00c];
    u8    field8fd;
    u8    pad8fe[3];
    u8    field901;
    u8    field902;
    u8    pad903[0x928 - 0x903];
    void *field928[2];
    u8    pad930[0x94c - 0x930];
} Work;

extern char  str_02177000[];
extern u32 GAME_COMM_GetGameData(void *obj);
struct BigObj;
struct Rec44;
struct Sub24;
struct U16Vec;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern int   INTRUDE_COMM_HasUnlockFlags(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *COMM_PLAYER_Create(int a, void *b, u16 heap, int c);
extern void INTRUDE_COMM_InitRequest(u8 *p, int a);
extern void INTRUDE_COMM_InitSession(u8 *p);
extern void  INTRUDE_COMM_InitBeacon(void *a, void *b, u32 c);
extern int EVENT_FIELD_PROCLINK_InitReturnSlotsWithAid(int a0);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void GAME_DATA_SetExitMode(struct BigObj *p, u8 v);
extern void GAME_DATA_SetIntrudeId(struct BigObj *p, u32 v);
extern void GAME_DATA_SetEnterMode(struct BigObj *p, u8 v);
extern struct Rec44 *GAME_DATA_GetPlayerStatus(struct Sub24 *p, u32 i);
extern void  MYSTATUS_Copy(void *a, void *b);

Work *INTRUDE_COMM_Create(void *unused, Param *p)
{
    void *sv;
    void *bag;
    u32 mode;
    Work *w;
    int i;
    u8 j;

    sv = (void *)GAME_COMM_GetGameData(p->field04);
    bag = GAME_DATA_GetMyStatus(sv);
    mode = 3;
    if (p->field0e == 1 && INTRUDE_COMM_HasUnlockFlags(sv) == 0) {
        mode = 2;
    }
    w = func_02030734(5, sizeof(Work), 1, str_02177000, 0x9a);
    w->field000 = p->field00;
    w->field004 = p->field04;
    w->field8fd = 1;
    w->field008 = COMM_PLAYER_Create(3, (void *)p->field00, 5, 0);
    w->field902 = 1;
    w->field901 = 1;
    INTRUDE_COMM_InitRequest((u8 *)w, 4);
    INTRUDE_COMM_InitSession((u8 *)w + 0x1ac);
    INTRUDE_COMM_InitBeacon(sv, (u8 *)w + 0xc, mode);
    EVENT_FIELD_PROCLINK_InitReturnSlotsWithAid((int)((u8 *)w + 0x35c));
    for (i = 0; i < 2; i++) {
        w->field928[i] = STRBUF_Create(8, 5);
    }
    GAME_DATA_SetExitMode(sv, 0);
    GAME_DATA_SetIntrudeId(sv, 0);
    GAME_DATA_SetEnterMode(sv, 1);
    for (j = 0; j < 3; j++) {
        MYSTATUS_Copy(bag, GAME_DATA_GetPlayerStatus(sv, j));
    }
    return w;
}
