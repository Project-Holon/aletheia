/*
 * function: EVENT_MAPCHANGE_SwapCommOverlayEvent
 * address:  0x02184BF8
 * packet:   pkt_ov020_02184BF8
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
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   EVENT_MAPCHANGE_CreateChangeFieldEvent  0x02184360  thumb  ov020
 *   EVENT_DISAPPEAR_CreateSpinFade  0x021BFDD0  thumb  ov021
 *   ov011_id       0x0000000B  data  a1
 *   ov012_id       0x0000000C  data  a1
 */

extern char ov011_id[];
extern char ov012_id[];

typedef unsigned char  u8;
struct Evt;
void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
void func_02034A5C(int id);
int func_02034AC4(int id);
typedef unsigned short u16;
int SCRIPT_SYS_CallScriptEvent(void *p, u16 b, int c, int d, u16 e);
void *EVENT_MAPCHANGE_CreateChangeFieldEvent(u8 *p, int value);
void *EVENT_DISAPPEAR_CreateSpinFade(int a0, void *p, int a2, int a3);

int EVENT_MAPCHANGE_SwapCommOverlayEvent(void *ctx, int *st, int *p)
{
    int a = p[0];
    int b = p[2];
    int r;

    switch (*st) {
    case 0:
        r = (int)EVENT_DISAPPEAR_CreateSpinFade((int)ctx, (void *)a, b, 0);
    join:
        GAME_EVENT_CallEvent(ctx, (struct Evt **)r);
        (*st)++;
        break;
    case 1:
        r = (int)EVENT_MAPCHANGE_CreateChangeFieldEvent((u8 *)p, 0);
        goto join;
    case 2:
        func_02034A5C((int)ov012_id);
        func_02034AC4((int)ov011_id);
        SCRIPT_SYS_CallScriptEvent(ctx, 0x83A, 0, 0, 0x15);
        (*st)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
