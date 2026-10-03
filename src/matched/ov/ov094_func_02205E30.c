/*
 * function: func_02205E30
 * address:  0x02205E30
 * packet:   pkt_ov094_02205E30
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 */
struct Obj;
extern void func_0204B3B4(struct Obj *p);

void func_02205E30(char *o)
{
    int i;
    int j;
    int off;
    char *p;

    i = 0;
    off = 0x11c;
    off = 0x14c;
    for (; i < 2; i++) {
        if (i != 0) {
            p = o + off;
        } else {
            p = o + 0x47 * 4;
        }
        for (j = 0; j < 6; j++) {
            if (*(void **)(p + j * 8) != 0) {
                func_0204B3B4(*(void **)(p + j * 8));
                *(void **)(p + j * 8) = 0;
            }
        }
    }
}
