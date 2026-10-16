/*
 * function: HAND_WAZA_RestCheckFail
 * address:  0x021E4408
 * packet:   pkt_021B75A8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   HAND_WAZA_RestCheckFail   0x021E4408  thumb ov093
 *   BTL_EVENT_GetVar   0x021D775C  thumb ov093
 *   BTL_EVENT_OverwriteVar   0x021D76BC  thumb ov093
 *   BTL_SERVER_FLOW_GetPokeParam   0x021C7CF4  thumb ov093
 *   BTL_POKEPARAM_HasSick   0x021D62C4  thumb ov093
 *   BTL_POKEPARAM_IsHpFull   0x021D5B48  thumb ov093
 *   BTL_POKEPARAM_GetValue   0x021D59B4  thumb ov093
 *
 * Two-key gate on BTL_EVENT_GetVar(2) / BTL_EVENT_GetVar(0x22), then classify the
 * BTL_SERVER_FLOW_GetPokeParam(b, c) record: the first matching predicate decides which
 * BTL_EVENT_OverwriteVar(0x22, code) event fires, and only the fall-through case
 * looks at the 16-bit BTL_POKEPARAM_GetValue(u, 0x11) result.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_EVENT_GetVar(int a);
struct Unk021D62A8;
int BTL_EVENT_OverwriteVar(int key, u32 val);
void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int BTL_POKEPARAM_IsHpFull(u8 *p);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
void HAND_WAZA_RestCheckFail(void *a, int b, int c)
{
    u16 v;
    void *u;

    if (c != BTL_EVENT_GetVar(2))
        return;
    if (BTL_EVENT_GetVar(0x22) != 0)
        return;
    u = BTL_SERVER_FLOW_GetPokeParam((int *)b, c);
    if (BTL_POKEPARAM_HasSick(u, 2) != 0) {
        BTL_EVENT_OverwriteVar(0x22, 0x1a);
        return;
    }
    if (BTL_POKEPARAM_HasSick(u, 0xf) != 0) {
        BTL_EVENT_OverwriteVar(0x22, 0xd);
        return;
    }
    if (BTL_POKEPARAM_IsHpFull(u) != 0) {
        BTL_EVENT_OverwriteVar(0x22, 0xe);
        return;
    }
    v = BTL_POKEPARAM_GetValue(u, 0x11);
    if (v == 0xf || v == 0x48)
        BTL_EVENT_OverwriteVar(0x22, 0xf);
}
