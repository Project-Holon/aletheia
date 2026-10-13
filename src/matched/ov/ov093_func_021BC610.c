/*
 * function: BTL_SERVER_FLOW_BuildActionOrder
 * address:  0x021BC610
 * packet:   pkt_ov093_021BC610
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note 2026-10-05 (final push G10L7): closed. The first-loop colour swap (q r6, slot counter
 * r5 in the original) came from the shared tail: `r5++` is written in the case 3 arm and in the
 * default arm (statement per branch) instead of `goto inc`. Cross-jumping still merges the two
 * increments into one tail, but the counter then carries the extra weight and takes the lower
 * register (probes: any extra counter reference flipped the pair). The final or-chain is written
 * (k & m) | ((m + 1) | (slot part | sub part)). The second e[l].b.kind read is a real reload in
 * the original: it comes out only through a second 16-byte struct view E2 ((E2 *)e)[l] (a plain
 * r->b.kind merges, 600 B). Block-scope declarations come first in each block so the file
 * also compiles with --lang c. History: waves P4 to R17 reached 612 B with 18 B differing.
 *
 * symbols:
 *   BTL_SERVER_GetClientChecked  0x021BB85C  thumb  ov093
 *   BTL_SERVER_GetActionTableValue  0x021BB8A8  thumb  ov093
 *   BTL_SERVER_GetActionTableEntry  0x021BB8B0  thumb  ov093
 *   BTL_ACTION_IsChangeDepleted  0x021D83E0  thumb  ov093
 *   BTL_CALC_ActionGetKind  0x021D8454  thumb  ov093
 *   BTL_SLOT_GetRotateSrcIndex  0x021B9AB0  thumb  ov093
 *   BTL_SLOT_GetPoke  0x021B9BF0  thumb  ov093
 *   BTL_MAIN_GetCompetitor  0x021B86B8  thumb  ov093
 *   BTL_SERVER_FLOW_CalcMovePriority  0x021BC8EC  thumb  ov093
 *   BTL_SERVER_FLOW_CalcPokeSpeed  0x021BC948  thumb  ov093
 *   BTL_SERVER_FLOW_BeginHandExScope  0x021CC8D8  thumb  ov093
 *   BTL_SERVER_FLOW_EndHandExScope  0x021CC95C  thumb  ov093
 *   BTL_SERVER_FLOW_SortActionOrder  0x021BC874  thumb  ov093
 *   BTL_SERVER_FLOW_QueryActionAllowedEvent  0x021C6350  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct { u32 kind : 4; u32 sub : 3; u32 id : 16; u32 rest : 9; } B;
typedef struct { u32 lo : 13; u32 f : 3; u32 g : 6; u32 h : 3; u32 rest : 7; } C;
typedef struct { u8 *a; B b; u32 c; u8 d; u8 e; u8 f; } E;
typedef struct { u32 x; void *m; } Q;
typedef struct { u8 *a; B b; u32 c; u8 d; u8 e; u8 f; } E2;
typedef struct { u8 pad[0x782]; u8 n; u8 pad2[0x5d]; E e[6]; } S;

struct S2;
extern u8 *BTL_SERVER_GetClientChecked(u8 *p, unsigned int i);
extern u8 BTL_SERVER_GetActionTableValue(u8 *p, u8 i);
extern B BTL_SERVER_GetActionTableEntry(u8 *p, u8 i, u8 j);
extern int BTL_ACTION_IsChangeDepleted(B *p);
extern u32 BTL_CALC_ActionGetKind(B *p);
extern u8 BTL_SLOT_GetRotateSrcIndex(u8 k);
extern u32 BTL_SLOT_GetPoke(struct S2 *p, u32 i);
extern void *BTL_MAIN_GetCompetitor(void ***p);
extern int BTL_SERVER_FLOW_CalcMovePriority(u8 *p, u32 x, u8 *a);
extern u16 BTL_SERVER_FLOW_CalcPokeSpeed(u8 *p, u8 *x, int flag);
extern u32 BTL_SERVER_FLOW_BeginHandExScope(void *lock, int line);
extern void BTL_SERVER_FLOW_EndHandExScope(u32 *p, u32 v, int line);
extern void BTL_SERVER_FLOW_SortActionOrder(E *e, u32 n);
extern u8 BTL_SERVER_FLOW_QueryActionAllowedEvent(u8 *p, u8 *a);

u8 BTL_SERVER_FLOW_BuildActionOrder(S *p, u8 *o, E *e)
{
    u8 cnt;
    u32 k;
    u8 *a;
    u32 lock;
    u8 i;
    u8 j;
    u8 n;
    u32 flag;
    u8 l;
    Q *q;
    E *r;

    flag = 0;
    for (i = 0, cnt = 0; i < 4; i++) {
        q = (Q *)BTL_SERVER_GetClientChecked((u8 *)(*(u32 *)p), i);
        if (q != 0) {
            u8 r5;
            n = BTL_SERVER_GetActionTableValue(o, i);
            r5 = 0;
            for (j = 0; j < n; j++) {
                u32 t;
                r = &e[cnt];
                r->b = BTL_SERVER_GetActionTableEntry(o, i, j);
                if (BTL_ACTION_IsChangeDepleted(&r->b) != 0)
                    break;
                t = BTL_CALC_ActionGetKind(&r->b) & 0xff;
                switch (t) {
                case 6:
                    r5 = BTL_SLOT_GetRotateSrcIndex(r->b.sub);
                    r->a = (u8 *)BTL_SLOT_GetPoke(q->m, (u8)r5);
                    flag = 1;
                    break;
                case 3:
                    r->a = (u8 *)BTL_SLOT_GetPoke(q->m, (u8)r->b.sub);
                    r5++;
                    break;
                default:
                    r->a = (u8 *)BTL_SLOT_GetPoke(q->m, (u8)r5);
                    r5++;
                    break;
                }
                r->d = i;
                r->e = 0;
                r->f = 0;
                cnt++;
            }
        }
    }
    for (l = 0; l < cnt; l++) {
        u32 m = 0x1FFF;
        u8 r5;
        u32 sub;
        lock = BTL_SERVER_FLOW_BeginHandExScope((u8 *)p + 0x1d74, 0x678 - 0x38);
        r = &e[l];
        a = e[l].a;
        switch (r->b.kind) {
        case 4:
            if (BTL_MAIN_GetCompetitor(*(void **)((u8 *)p + 4)) == 0 && r->d == 1) {
                r5 = 0;
            } else {
                r5 = 4;
            }
            break;
        case 3:
            r5 = 3;
            break;
        case 2:
            r5 = 2;
            break;
        case 6:
            r5 = 1;
            break;
        case 7:
            r5 = 0;
            break;
        case 5:
            r5 = 0;
            break;
        case 1:
            r5 = 0;
            break;
        case 0:
            *(u32 *)&r->c = 0x01002000;
            continue;
        case 8:
            continue;
        default:
            r5 = 0;
            break;
        }
        if (r->b.kind == 1) {
            u16 id;
            if (((E2 *)e)[l].b.kind == 1)
                id = ((E2 *)e)[l].b.id;
            else
                id = 0;
            sub = BTL_SERVER_FLOW_CalcMovePriority((u8 *)p, id, a);
        } else if (r->b.kind == 5 || r->b.kind == 7) {
            sub = 7;
        } else {
            sub = 0;
        }
        k = BTL_SERVER_FLOW_CalcPokeSpeed((u8 *)p, a, 1);
        BTL_SERVER_FLOW_EndHandExScope((u32 *)((u8 *)p + 0x1d74), lock, 0x678);
        r->c = (k & m) | ((m + 1) | (((r5 & 7) << 22) | ((sub & 0x3f) << 16)));
    }
    BTL_SERVER_FLOW_SortActionOrder(e, cnt);
    if (flag == 0) {
        for (i = 0; i < cnt; i++) {
            r = &e[i];
            if (r->b.kind == 1 || r->b.kind == 5) {
                u32 lock = BTL_SERVER_FLOW_BeginHandExScope((u8 *)p + 0x1d74, 0x68A);
                u32 v = BTL_SERVER_FLOW_QueryActionAllowedEvent((u8 *)p, r->a);
                r->c = (r->c & 0xFFFF1FFF) | ((v & 7) << 13);
                BTL_SERVER_FLOW_EndHandExScope((u32 *)((u8 *)p + 0x1d74), lock, 0x68A + 3);
            }
        }
        BTL_SERVER_FLOW_SortActionOrder(e, cnt);
    }
    return cnt;
}
