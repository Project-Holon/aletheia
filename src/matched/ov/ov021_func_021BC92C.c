/*
 * function: func_021BC92C
 * address:  0x021BC92C
 * packet:   pkt_ov021_021BC92C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD1E4  0x021BD1E4  thumb  ov021
 */

typedef struct {
    char pad[0x50];
    void *f50[0x1E];
} Obj;

extern void func_021BD1E4(void *a, unsigned int b);

void func_021BC92C(Obj *p)
{
    int i;

    for (i = 0; i < 0x1E; i++) {
        func_021BD1E4(p->f50[i], 0);
    }
}
