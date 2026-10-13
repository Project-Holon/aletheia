/*
 * function: FLD_FACEUP_EndEvent
 * address:  0x021649E8
 * packet:   pkt_ov010_021649E8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two-step state machine on *st: step 0 starts a request, step 1 finishes.
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FLD_FACEUP_StartClose  0x021F5550  thumb  ov082
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 *   func_02034A5C  0x02034A5C  arm
 *   ov_id_52       0x00000052  data
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Evt;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void *FLD_FACEUP_StartClose(void *p);
extern void SCRIPT_WORK_ResetCheckFlag(int n);
extern void func_02034A5C(int a);
extern u8 ov_id_52[];

int FLD_FACEUP_EndEvent(void *a, int *st)
{
    int r = (int)GAME_EVENT_GetGameSystem(a);
    switch (*st) {
    case 0:
        GAME_EVENT_CallEvent(a, FLD_FACEUP_StartClose((void *)r));
        (*st)++;
        break;
    case 1:
        SCRIPT_WORK_ResetCheckFlag(7);
        func_02034A5C((int)ov_id_52);
        return 1;
    }
    return 0;
}
