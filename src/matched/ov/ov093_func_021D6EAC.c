/*
 * function: BTL_EVENT_InitFactorList
 * address:  0x021D6EAC
 * packet:   pkt_ov093_021D6EAC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BTL_EVENT_ClearFactor  0x021D74BC  thumb  ov093
 *   BTL_EVENT_ResetVarStack  0x021D74C8  thumb  ov093
 *   gBtlEventFactorStorage  0x021F4470  data  a4
 *   gBtlEventFactorFreePool  0x021F3CBC  data  a4
 *   gBtlEventFactorList  0x021F3CB0  data  a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 b[0x3c]; } Node;
extern Node gBtlEventFactorStorage[0x84];
extern Node *gBtlEventFactorFreePool[0x84];
extern struct { u32 a; u32 b; u32 c; } gBtlEventFactorList;
extern void BTL_EVENT_ClearFactor(int a);
extern void BTL_EVENT_ResetVarStack(void);
void BTL_EVENT_InitFactorList(void)
{
    u32 i;
    for (i = 0; i < 0x84; i++) {
        Node *n = &gBtlEventFactorStorage[i];
        BTL_EVENT_ClearFactor((int)n);
        gBtlEventFactorFreePool[i] = n;
    }
    gBtlEventFactorList.b = 0;
    gBtlEventFactorList.c = 0;
    gBtlEventFactorList.a = 0;
    BTL_EVENT_ResetVarStack();
}
