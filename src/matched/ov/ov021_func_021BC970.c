/*
 * function: func_021BC970
 * address:  0x021BC970
 * packet:   pkt_ov021_021BC970
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD138  0x021BD138  thumb  ov021
 *   func_021BD1CC  0x021BD1CC  thumb  ov021
 */

typedef unsigned char u8;

typedef struct {
    char pad[0xC8];
    void *fC8[0x20];
} Obj;

extern u8 func_021BD138(Obj *p);
extern void func_021BD1CC(void *a);

void func_021BC970(Obj *p)
{
    int n = func_021BD138(p);
    int i;

    for (i = 0; i < n; i++) {
        if (p->fC8[i] != 0) {
            func_021BD1CC(p->fC8[i]);
        }
    }
}
