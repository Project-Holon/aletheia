/*
 * function: HAND_WAZA_GravityAddFieldEffect
 * address:  0x021E0628
 * packet:   pkt_ov093_021E0628
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_FIELD_GetStaticSlotObject  0x021EF948  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SICKCONT_MakeKind2Index  0x021E8940  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_PushCmdRecord  0x021C88B4  thumb  ov093
 */
typedef unsigned short u16;
extern int BTL_EVENT_GetVar(int key);
extern int BTL_FIELD_GetStaticSlotObject(int k);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
typedef unsigned int   u32;
extern int BTL_SICKCONT_MakeKind2Index(u32 a);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_PushCmdRecord(void *a, int k, int b);

struct S {
    int f0;
    int f4;
    int f8;
    int fC;
    u16 f10;
    u16 f12;
};

void HAND_WAZA_GravityAddFieldEffect(int a, void *b, int c)
{
    struct S *p;

    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_FIELD_GetStaticSlotObject(2) == 0) {
            p = BTL_SERVER_FLOW_AllocCmdRecord(b, 0x1b, c);
            p->f4 = 2;
            p->f8 = BTL_SICKCONT_MakeKind2Index(5);
            p->f12 = (p->f12 & ~0xff) | 1;
            p->f10 = 0x75;
            BTL_SERVER_FLOW_CommitCmdRecord(b, p);
            BTL_SERVER_FLOW_PushCmdRecord(b, 0x35, c);
        }
    }
}
