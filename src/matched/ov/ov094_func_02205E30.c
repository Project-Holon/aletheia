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
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`off = 0x11c;` before `off = 0x14c;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT* in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 */
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void func_02205E30(char *o)
{
    int i;
    int j;
    int off;
    char *p;

    i = 0;
    off = 0x14c;
    for (; i < 2; i++) {
        if (i != 0) {
            p = o + off;
        } else {
            p = o + 0x47 * 4;
        }
        for (j = 0; j < 6; j++) {
            if (*(void **)(p + j * 8) != 0) {
                CLACT_DeleteActor(*(void **)(p + j * 8));
                *(void **)(p + j * 8) = 0;
            }
        }
    }
}
