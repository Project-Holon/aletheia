/*
 * function: BTL_HANDLER_ITEM_WhiteHerbRestoreStats
 * address:  0x021DE2A0
 * packet:   pkt_ov093_021DE2A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
struct QQ;
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);

void BTL_HANDLER_ITEM_WhiteHerbRestoreStats(void *a, void *b, int c, u8 *a3)
{
    u8 *m;
    u8 *n;

    if (c == BTL_EVENT_GetVar(2)) {
        m = (u8 *)func_021C88A4(b, 0x12, c);
        m[4] = c;
        func_021C88C8(b, m);
        n = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(n + 4, 2, 0x3f2);
        func_021C8860((struct S *)(n + 4), c);
        func_021C8860((struct S *)(n + 4), BTL_EVENT_GetFactorKey(a));
        func_021C88C8(b, n);
    }
}
