/*
 * function: BTL_TOKUSEI_MoldBreaker_ShowAbilityMessage
 * address:  0x021DB134
 * packet:   pkt_ov093_021DB134
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88B4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);

void BTL_TOKUSEI_MoldBreaker_ShowAbilityMessage(void *p, void *a, int id)
{
    u8 *r;
    int k;

    if (id == BTL_EVENT_GetVar(2)) {
        switch (BTL_EVENT_GetFactorKey(p)) {
        case 0xa3:
            k = 0x1f9;
            break;
        case 0xa4:
            k = 0x1f6;
            break;
        default:
            k = 0x1ba;
            break;
        }
        func_021C88B4(a, 2, id);
        r = (u8 *)func_021C88A4(a, 4, id);
        func_021C8838(r + 4, 2, k);
        func_021C8860((struct S *)(r + 4), id);
        func_021C88C8(a, r);
        func_021C88B4(a, 3, id);
    }
}
