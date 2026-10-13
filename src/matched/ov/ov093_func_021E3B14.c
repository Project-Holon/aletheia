/*
 * function: func_021E3B14
 * address:  0x021E3B14
 * packet:   pkt_ov093_021E3B14
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetLastUsedMoveId  0x021D67A8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F284C     0x021F284C  data   a2
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern int BTL_EVENT_GetVar(int);
struct QL;
extern void *func_021C7CF4(int *p, int i);
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct QL *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *p);
extern const u16 d_021F284C[];

void func_021E3B14(int u, void *a, int c)
{
    unsigned i;
    int r;
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        r = BTL_POKEPARAM_GetLastUsedMoveId(func_021C7CF4(a, c));
        for (i = 0; i < 5; i++) {
            if (r == d_021F284C[i])
                return;
        }
        p = func_021C88A4(a, 0x26, c);
        p[4] = c;
        p[5] = 3;
        p[6] = 0;
        func_021C88C8(a, p);
    }
}
