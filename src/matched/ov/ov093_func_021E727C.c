/*
 * function: func_021E727C
 * address:  0x021E727C
 * packet:   pkt_ov093_021E727C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetHistoryList  0x021C8130  thumb  ov093
 *   func_021E72D4  0x021E72D4  thumb  ov093
 *   func_021E72E4  0x021E72E4  thumb  ov093
 *   BTL_MAIN_IsPokeSamePair  0x021B9A24  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern u8 *BTL_SERVER_FLOW_GetHistoryList(u8 *p);
extern int func_021E72D4(int a, int b);
extern int func_021E72E4(int a, int b, int c);
extern int BTL_MAIN_IsPokeSamePair(unsigned int a, unsigned int b);
extern void BTL_EVENT_MultiplyVar(int key, int m);

void func_021E727C(int a, int b, int c)
{
    int x;
    u32 n;
    u8 i;

    if (c == BTL_EVENT_GetVar(3)) {
        x = (int)BTL_SERVER_FLOW_GetHistoryList((u8 *)b);
        n = func_021E72D4(x, 1);
        for (i = 0; i < n; i++) {
            if (BTL_MAIN_IsPokeSamePair(c, func_021E72E4(x, 1, i)) != 0) {
                BTL_EVENT_MultiplyVar(0x31, 0x2000);
                return;
            }
        }
    }
}
