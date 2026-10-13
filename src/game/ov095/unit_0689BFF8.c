/*
 * file:     unit_0689BFF8.c
 * function: func_0689BFF8
 * address:  0x0689BFF8
 * packet:   pkt_ov095_0689BFF8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb
 *   func_021D62A8  0x021D62A8  thumb
 *   BTL_CALC_RandRange  0x021D7B8C  thumb
 *   BTLV_CORE_MakeSlotKind2Index  0x021E8940  thumb
 */

typedef unsigned char u8;

typedef struct Rec {
    int f00;
    int f04;
    int f08;
    u8 f0c;
    u8 f0d;
    u8 f0e;
    u8 f0f;
} Rec;

extern int BTL_CALC_RandRange(int, int);
extern int func_021D62A8(void *);
extern int BTL_POKEPARAM_GetPokeId(void *);
extern Rec *BTL_SERVER_FLOW_AllocCmdRecord(void *, int, int);
extern int BTLV_CORE_MakeSlotKind2Index(u8);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *, Rec *);

void func_0689BFF8(void *a, void *b)
{
    int n;
    int k;
    Rec *r;

    n = BTL_CALC_RandRange(2, 4);
    if (n > 0) {
        if (func_021D62A8(b) == 0) {
            k = BTL_POKEPARAM_GetPokeId(b);
            r = BTL_SERVER_FLOW_AllocCmdRecord(a, 0xc, k);
            r->f0c = 1;
            r->f04 = 2;
            r->f08 = BTLV_CORE_MakeSlotKind2Index(n);
            r->f0f = k;
            BTL_SERVER_FLOW_CommitCmdRecord(a, r);
        }
    }
}
