/*
 * unit:     yes
 * function: HAND_WAZA_SmellingSaltOnDamageEnd, HAND_WAZA_AddPresent
 * address:  0x021E2BF4
 * packet:   pkt_ov093_021E2BF4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   gPresentHandlers     0x021F2CC0  data  a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct Msg {
    u8 f0[4];
    u32 f4;
    u8 f8;
    u8 f9[11];
    u8 f14;
} Msg;

extern int BTL_EVENT_GetVar(int key);
struct Unk021D62A8;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern u8 gPresentHandlers[];

void HAND_WAZA_SmellingSaltOnDamageEnd(int u, void *p, int k)
{
    u8 t;
    Msg *m;
    if (k == BTL_EVENT_GetVar(3)) {
        t = BTL_EVENT_GetVar(6);
        if (t != 0x1f) {
            if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(p, t), 1) != 0) {
                m = BTL_SERVER_FLOW_AllocCmdRecord(p, 0xb, k);
                m->f8 = t;
                m->f14 = 1;
                m->f4 = 1;
                BTL_SERVER_FLOW_CommitCmdRecord(p, m);
            }
        }
    }
}

u8 *HAND_WAZA_AddPresent(int *p)
{
    *p = 3;
    return gPresentHandlers;
}
