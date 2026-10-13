/*
 * function: func_021E0DC4
 * address:  0x021E0DC4
 * packet:   pkt_ov093_021E0DC4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C88C8(void *a, void *b);

void func_021E0DC4(int a, void *q, int id)
{
    unsigned char *r;

    if (id != BTL_EVENT_GetVar(3))
        return;
    r = (unsigned char *)func_021C88A4(q, 4, id);
    func_021C8838(r + 4, 1, 102);
    func_021C88C8(q, r);
}
