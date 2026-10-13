/*
 * function: HAND_WAZA_RetaliateOnDecideTarget
 * address:  0x021E1A2C
 * packet:   pkt_ov093_021E1A2C
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
 *   HAND_WAZA_FindRetaliateHit  0x021E1AE4  thumb  ov093
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke  0x021C7D00  thumb  ov093
 *   BTL_SERVER_FLOW_GetPosTableEntryForPoke  0x021C7D44  thumb  ov093
 *   BTL_SERVER_FLOW_DecideMoveTarget  0x021C8030  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct Ent { u16 a; u16 b; u8 c; u8 d; u8 e; u8 f; } Ent;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int HAND_WAZA_FindRetaliateHit(void *m, int x, Ent *out);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(u8 *p, int b);
extern int BTL_SERVER_FLOW_GetPosTableEntryForPoke(char *p, int i);
extern int BTL_SERVER_FLOW_DecideMoveTarget(u8 *p, int v, u16 k);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_RetaliateOnDecideTarget(void *p, int id, int u, int x)
{
    Ent e;
    int t;
    int r;
    if (id == BTL_EVENT_GetVar(3)) {
        if (HAND_WAZA_FindRetaliateHit(BTL_SERVER_FLOW_GetPokeParam(p, id), x, &e)) {
            t = e.d;
            if (BTL_SERVER_FLOW_GetFrontPosOfPoke(p, t) == 6) {
                r = e.e;
                t = 0x1f;
                if (r != 6)
                    t = BTL_SERVER_FLOW_GetPosTableEntryForPoke(p, r);
                if (t == 0x1f) {
                    r = BTL_SERVER_FLOW_DecideMoveTarget(p, id, 1);
                    if (r != 6)
                        t = BTL_SERVER_FLOW_GetPosTableEntryForPoke(p, r);
                    if (t == 0x1f)
                        t = e.d;
                }
            }
            BTL_EVENT_OverwriteVar(4, t);
        }
    }
}
