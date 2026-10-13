/*
 * function: BTL_HANDLER_ITEM_ShowResistBerryMessage
 * address:  0x021DDD38
 * packet:   pkt_ov093_021DDD38
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021E85F8(int id);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *l, int a, int b);
struct S;
extern void func_021C8860(struct S *l, u32 v);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void func_021C88C8(void *a, void *b);

void BTL_HANDLER_ITEM_ShowResistBerryMessage(void *a, u8 *b, int c, int *d)
{
    u8 *p;
    if (*d != 0 && func_021E85F8(c) != 0) {
        p = func_021C88A4((char *)b, 0x23, c);
        func_021C8838(p + 8, 2, 219);
        func_021C8860((struct S *)(p + 8), c);
        func_021C8860((struct S *)(p + 8), BTL_EVENT_GetFactorKey(a));
        func_021C88C8(b, p);
    }
}
