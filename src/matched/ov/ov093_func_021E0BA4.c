/*
 * function: func_021E0BA4
 * address:  0x021E0BA4
 * packet:   pkt_ov093_021E0BA4
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
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);

void func_021E0BA4(int unused, void *q, int id, int *f)
{
    u8 *m;

    if (id == BTL_EVENT_GetVar(3)) {
        m = (u8 *)func_021C88A4(q, 4, id);
        func_021C8838(m + 4, 2, 0x29e);
        func_021C8860((struct S *)(m + 4), id);
        func_021C88C8(q, m);
        f[6] = 1;
    }
}
