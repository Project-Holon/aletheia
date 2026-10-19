/*
 * function: HAND_WAZA_RoostGroundFlyingType
 * address:  0x021E6994
 * packet:   pkt_ov093_021E6994
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SICKCONT_MakeKind2  0x021E896C  thumb  ov093
 *   BTL_SICKCONT_SetFlag  0x021E8BD0  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern int BTL_SICKCONT_MakeKind2(u32 a, u32 b);
union U;
extern void BTL_SICKCONT_SetFlag(union U *p, int v);

struct S { int w0; int w4; int w8; u8 bc; u8 bd; u8 be; u8 bf; };

void HAND_WAZA_RoostGroundFlyingType(int x, void *a, int c)
{
    struct S *p;
    int t = 2;
    int r;
    int *q;

    if (c == BTL_EVENT_GetVar(2)) {
        p = BTL_SERVER_FLOW_AllocCmdRecord(a, 12, c);
        p->bf = c;
        p->bd = 1;
        p->w4 = 0x18;
        r = BTL_SICKCONT_MakeKind2(1, t);
        q = &p->w8;
        *q = r;
        BTL_SICKCONT_SetFlag((union U *)q, 1);
        BTL_SERVER_FLOW_CommitCmdRecord(a, p);
    }
}
