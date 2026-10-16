/*
 * function: BTL_SERVER_FLOW_ItemEffectRevive
 * address:  0x021CC008
 * packet:   pkt_ov093_021CC008
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The switch stores into w+6 in every arm (as BTL_SERVER_FLOW_ItemEffectRecoverHp does), which
 * lays the arms out as the original has them; the default arm calls
 * BTL_CALC_GetMonParamWithHeap again. s is narrow: as u32 (or a pointer, as the sibling
 * handlers BTL_SERVER_FLOW_ItemEffectRecoverHp/CC178/CC214 declare it) its `ldr r0,[sp]` reload
 * is hoisted above `strb r7,[r4,#4]`; u16 and u8 both keep it below.
 * Nothing in the image fixes the width; u16 chosen. The function sits in
 * the handler table at 0x021EFE28.
 *
 * symbols:
 *   BTL_POKEPARAM_IsFainted  0x021D5B68  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_CALC_GetMonParamWithHeap  0x021D805C  thumb  ov093
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_CALC_DivideMaxHpMin1  0x021D7B74  thumb  ov093
 *   BTL_SERVER_FLOW_InitMsgRecord  0x021C8838  thumb  ov093
 *   BTL_SERVER_FLOW_AppendMsgRecordArg  0x021C8860  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTL_SERVER_FLOW_AddSeenPokeThunk  0x021C84E0  thumb  ov093
 */
#include "../include/Obj06229.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_POKEPARAM_IsFainted(void *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *p, int a, int b);
extern u32 BTL_CALC_GetMonParamWithHeap(void *p, u32 n);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern int BTL_CALC_DivideMaxHpMin1(u8 *p, u32 k);
extern void BTL_SERVER_FLOW_InitMsgRecord(void *p, int a, int b);
struct S;
extern void BTL_SERVER_FLOW_AppendMsgRecordArg(struct S *p, u32 val);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *a, void *b);
extern void BTL_SERVER_FLOW_AddSeenPokeThunk(unsigned char *p, unsigned int v);

int BTL_SERVER_FLOW_ItemEffectRevive(u8 *p, u8 *q, u16 s)
{
    int id;
    u8 *w;
    u32 r;
    if (BTL_POKEPARAM_IsFainted(q)) {
        id = BTL_POKEPARAM_GetPokeId(q);
        w = BTL_SERVER_FLOW_AllocCmdRecord((char *)p, 0x2c, id);
        w[4] = id;
        r = BTL_CALC_GetMonParamWithHeap((void *)s, 0x3a);
        switch (r) {
        case 0xff:
            ((struct Obj06229 *)w)->f6 = BTL_POKEPARAM_GetValue(q, 0xe);
            break;
        case 0xfe:
            ((struct Obj06229 *)w)->f6 = BTL_CALC_DivideMaxHpMin1(q, 2);
            break;
        case 0xfd:
            ((struct Obj06229 *)w)->f6 = BTL_CALC_DivideMaxHpMin1(q, 4);
            break;
        default:
            ((struct Obj06229 *)w)->f6 = BTL_CALC_GetMonParamWithHeap((void *)s, 0x3a);
            break;
        }
        BTL_SERVER_FLOW_InitMsgRecord(w + 8, 2, 3);
        BTL_SERVER_FLOW_AppendMsgRecordArg((struct S *)(w + 8), id);
        BTL_SERVER_FLOW_CommitCmdRecord(p, w);
        BTL_SERVER_FLOW_AddSeenPokeThunk(p, id);
        return 1;
    }
    return 0;
}
