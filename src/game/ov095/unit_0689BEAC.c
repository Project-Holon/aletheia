/*
 * file:     unit_0689BEAC.c
 * function: func_0689BEAC
 * address:  0x0689BEAC
 * packet:   pkt_ov095_0689BEAC
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb
 *   BTL_POKEPARAM_GetMovePPById  0x021D55A0  thumb
 *   BTL_POKEPARAM_GetSickContRaw  0x021D6314  thumb
 *   BTLV_CORE_GetSlotValue  0x021E8B80  thumb
 */

typedef unsigned char u8;

typedef struct Rec {
    u8 pad[4];
    int f04;
    u8 f08;
    u8 pad2[11];
    u8 f14;
} Rec;

extern int BTL_POKEPARAM_GetSickContRaw(void *, int);
extern int BTLV_CORE_GetSlotValue(int);
extern int BTL_POKEPARAM_GetMovePPById(void *, int);
extern Rec *BTL_SERVER_FLOW_AllocCmdRecord(void *, int, int);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, Rec *);

void func_0689BEAC(void *a, void *b, int c)
{
    Rec *r;
    int t;

    t = BTL_POKEPARAM_GetSickContRaw(b, 0x17);
    if (BTL_POKEPARAM_GetMovePPById(b, BTLV_CORE_GetSlotValue(t)) == 0) {
        r = BTL_SERVER_FLOW_AllocCmdRecord(a, 0xb, c);
        r->f04 = 0x17;
        r->f08 = c;
        r->f14 = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(a, r);
    }
}
