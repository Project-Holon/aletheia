/*
 * function: FIELD_BUILDMODEL_FreeModel
 * address:  0x0218BF84
 * packet:   pkt_ov021_0218BF84
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */

typedef struct {
    int f0;
    void *f4;
    void *arr[4];
} S;

typedef unsigned int   u32;
u32 func_020307B0(void *p);

void FIELD_BUILDMODEL_FreeModel(S *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (p->arr[i] != 0) {
            func_020307B0(p->arr[i]);
            p->arr[i] = 0;
        }
    }
    if (p->f4 != 0) {
        func_020307B0(p->f4);
        p->f4 = 0;
    }
}
