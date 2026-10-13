/*
 * function: func_021E1B4C
 * address:  0x021E1B4C
 * packet:   pkt_ov093_021E1B4C
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
 *   BTL_POKEPARAM_GetMoveCount  0x021D5448  thumb  ov093
 *   BTL_POKEPARAM_GetMoveId  0x021D54C0  thumb  ov093
 *   BTL_POKEPARAM_GetMoveUsedFlag  0x021D54E0  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
struct QG;
extern void *func_021C7CF4(int *p, int i);
extern u8 BTL_POKEPARAM_GetMoveCount(struct QG *p);
extern u16 BTL_POKEPARAM_GetMoveId(u8 *p, int i);
extern u32 BTL_POKEPARAM_GetMoveUsedFlag(u8 *p, u32 i);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E1B4C(int a, void *p, int id)
{
    void *q;
    u8 n;
    u8 i;
    u8 cnt;
    int flag;
    if (id == BTL_EVENT_GetVar(2)) {
        q = func_021C7CF4(p, id);
        n = BTL_POKEPARAM_GetMoveCount(q);
        cnt = 0;
        flag = 0;
        for (i = 0; i < n; i++) {
            if (BTL_POKEPARAM_GetMoveId(q, i) == 0x183) {
                flag = 1;
            } else if (BTL_POKEPARAM_GetMoveUsedFlag(q, i)) {
                cnt++;
            }
        }
        if (flag == 0 || n < 2 || cnt < n - 1)
            BTL_EVENT_OverwriteVar(0x22, 0x1a);
    }
}
