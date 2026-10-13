/*
 * function: BTLV_CORE_EventQueueMoveNotice
 * address:  0x021E8804
 * packet:   pkt_ov093_021E8804
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_IsSemiInvulnerable  0x021D5C30  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct UtilWork;
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_IsSemiInvulnerable(struct UtilWork *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *l, int a, int b);
struct S;
extern void func_021C8860(struct S *l, u32 v);
extern void func_021C88C8(void *a, void *b);

void BTLV_CORE_EventQueueMoveNotice(int u, void *a, int b, int d)
{
    u8 *p;
    int z;

    z = 2;
    if (b == BTL_EVENT_GetVar(2)) {
        if (BTL_POKEPARAM_IsSemiInvulnerable(func_021C7CF4(a, b)) == 0) {
            p = func_021C88A4(a, 4, b);
            func_021C8838(p + 4, z, 0x2fc);
            func_021C8860((struct S *)(p + 4), b);
            func_021C8860((struct S *)(p + 4), BTL_EVENT_GetVar(0x12));
            func_021C88C8(a, p);
        }
    }
}
