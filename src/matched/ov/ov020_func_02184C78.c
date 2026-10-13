/*
 * function: EVENT_MAPCHANGE_RunFixedZoneEvent
 * address:  0x02184C78
 * packet:   pkt_ov020_02184C78
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   func_02034A5C  0x02034A5C  arm
 *   func_02034AC4  0x02034AC4  arm
 *   EVENT_FIELD_PROCLINK_CreateAnimEvent  0x02161824  thumb  ov010
 *   UNION_MAIN_StartComm  0x02173744  thumb  ov012
 *   EVENT_MAPCHANGE_CreateChangeFieldEvent  0x02184360  thumb  ov020
 *   EVENT_APPEAR_CreateMoveAnime  0x021BF66C  thumb  ov021
 *   ov011_id       0x0000000B  data  a1
 *   ov012_id       0x0000000C  data  a1
 */

extern char ov011_id[];
extern char ov012_id[];

typedef unsigned char  u8;
struct Evt;
void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
void func_02034A5C(int id);
int func_02034AC4(signed int id);
void *EVENT_FIELD_PROCLINK_CreateAnimEvent(void *a, void *b);
void UNION_MAIN_StartComm(int a);
void *EVENT_MAPCHANGE_CreateChangeFieldEvent(u8 *p, int value);
void *EVENT_APPEAR_CreateMoveAnime(int a0, void *p, int a2);

int EVENT_MAPCHANGE_RunFixedZoneEvent(void *ctx, int *st, int *p)
{
    int a = p[0];
    int b = p[2];

    switch (*st) {
    case 0:
        GAME_EVENT_CallEvent(ctx, EVENT_FIELD_PROCLINK_CreateAnimEvent((void *)a, (void *)b));
        (*st)++;
        break;
    case 1:
        func_02034A5C((int)ov011_id);
        func_02034AC4((int)ov012_id);
        GAME_EVENT_CallEvent(ctx, EVENT_MAPCHANGE_CreateChangeFieldEvent((u8 *)p, 4));
        (*st)++;
        break;
    case 2:
        UNION_MAIN_StartComm(a);
        (*st)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(ctx, EVENT_APPEAR_CreateMoveAnime((int)ctx, (void *)a, b));
        (*st)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}
