/*
 * function: func_021E0818
 * address:  0x021E0818
 * packet:   pkt_ov093_021E0818
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_SetFactorSkipCheck  0x021D7320  thumb  ov093
 *   func_021E0900  0x021E0900  thumb  ov093
 */

extern int BTL_EVENT_GetVar(int key);
typedef unsigned int   u32;
struct QS;
extern void BTL_EVENT_SetFactorSkipCheck(struct QS *p, u32 v);
extern int func_021E0900(int, int, int, int, unsigned short);

void func_021E0818(char *a, int b, int c)
{
    if (c == BTL_EVENT_GetVar(3))
        BTL_EVENT_SetFactorSkipCheck((struct QS *)a, (u32)func_021E0900);
}
