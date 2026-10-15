/*
 * function: BEACON_VIEW_FreeResSet
 * address:  0x021F31A8
 * packet:   pkt_ov032_021F31A8
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   func_020307B0 0x020307B0 arm
 */

extern void CLACT_ReleaseCellAnim(unsigned);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleasePalette(unsigned);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

typedef struct {
    unsigned n0;
    unsigned *a0;
    unsigned n1;
    unsigned *a1;
    unsigned n2;
    unsigned *a2;
} T;

void BEACON_VIEW_FreeResSet(void *unused, T *p)
{
    unsigned i;
    int j;
    for (i = 0; i < p->n2; i++)
        CLACT_ReleaseCellAnim(p->a2[i]);
    for (i = 0; i < p->n1; i++)
        CLACT_ReleaseCharacter(p->a1[i]);
    for (i = 0; i < p->n0; i++)
        CLACT_ReleasePalette(p->a0[i]);
    for (j = 0; j < 3; j++) {
        if (((unsigned *)p)[j * 2 + 1] != 0)
            func_020307B0((void *)(((unsigned *)p)[j * 2 + 1]));
    }
}
