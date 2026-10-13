/*
 * unit:     yes
 * function: HAND_WAZA_JudgmentOnWazaTypeCheck, HAND_WAZA_AddTechnoBlast
 * address:  0x021E3190
 * packet:   pkt_ov093_021E3190
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_CanUseHeldItem  0x021C824C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gTechnoBlastHandlers  0x021F271C  data   a4
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_CanUseHeldItem(u8 *p, int v);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern u8 gTechnoBlastHandlers[];

void HAND_WAZA_JudgmentOnWazaTypeCheck(int u, void *p, int key)
{
    int two = 2;
    if (key == BTL_EVENT_GetVar(two)) {
        if (BTL_SERVER_FLOW_CanUseHeldItem(p, key) != 0) {
            u16 x = (u16)(int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(p, key));
            int v = 0;
            switch (x) {
            case 0x12a: v = 9; break;
            case 0x12b: v = 10; break;
            case 0x12c: v = 12; break;
            case 0x12d: v = 11; break;
            case 0x12e: v = 14; break;
            case 0x12f: v = 1; break;
            case 0x130: v = 3; break;
            case 0x131: v = 4; break;
            case 0x132: v = two; break;
            case 0x133: v = 13; break;
            case 0x134: v = 6; break;
            case 0x135: v = 5; break;
            case 0x136: v = 7; break;
            case 0x137: v = 15; break;
            case 0x138: v = 16; break;
            case 0x139: v = 8; break;
            }
            BTL_EVENT_OverwriteVar(0x16, v);
        }
    }
}

u8 *HAND_WAZA_AddTechnoBlast(u32 *out)
{
    *out = 1;
    return gTechnoBlastHandlers;
}
