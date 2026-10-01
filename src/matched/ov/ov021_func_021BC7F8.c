/*
 * function: func_021BC7F8
 * address:  0x021BC7F8
 * packet:   pkt_ov021_021BC7F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD184  0x021BD184  thumb  ov021
 */

typedef struct {
    char pad[0x50];
    void *f50[0x1E];
} Obj;

extern void func_021BD184(void *a);

void func_021BC7F8(Obj *p)
{
    int i;

    for (i = 0; i < 0x1E; i++) {
        func_021BD184(p->f50[i]);
    }
}
