/*
 * function: BTL_SERVER_FLOW_QueryMovePPCostEvent
 * address:  0x021C07D4
 * packet:   pkt_ov093_021C07D4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * c and d are narrow parameters: their home stores (`str r2,[sp]` first,
 * `str r3,[sp,#4]` after `adds r7,r1`) sit where the narrow-parameter idiom
 * puts them; as u32 both sink below `ldr r5`. u8 and u16 compile the same
 * (any mix of the two); nothing in the image fixes the width, u16 chosen.
 * func_021C0868/0878/0888 are `bx pc` ARM veneers declared as thumb externs.
 * `i = 0;` as its own statement before the func_021C0868 call puts
 * `movs r4,#0` between `adds r0,r5` and that bl.
 *
 * symbols:
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   func_021C0868  0x021C0868  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   func_021C0878  0x021C0878  thumb  ov093
 *   func_021C0888  0x021C0888  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVar  0x021D75A8  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void BTL_EVENT_PushVarFrame(int line);
extern u32 func_021C0868(int e);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern u8 *func_021C0878(int e, int i);
extern u8 *func_021C0888(int e, int i);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVar(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

int BTL_SERVER_FLOW_QueryMovePPCostEvent(u8 *p, u8 *a, u16 c, u16 d, int e)
{
    int i;
    u8 *r;
    int res;
    BTL_EVENT_PushVarFrame(0x16ef);
    i = 0;
    BTL_EVENT_SetVarReadOnly(5, func_021C0868(e));
    r = func_021C0878(e, 0);
    if (r != 0) {
        do {
            BTL_EVENT_SetVarReadOnly(i + 6, BTL_POKEPARAM_GetPokeId(r));
            i++;
            r = func_021C0888(e, i);
        } while (r != 0);
    }
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, d);
    BTL_EVENT_SetVarReadOnly(0x17, c);
    BTL_EVENT_SetVar(0x20, 1);
    BTL_EVENT_DispatchEventChecked(p, 0x4e);
    res = BTL_EVENT_GetVar(0x20);
    BTL_EVENT_PopVarFrame(0x1704);
    return res;
}
