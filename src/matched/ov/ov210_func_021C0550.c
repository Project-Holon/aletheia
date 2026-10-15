/*
 * function: ZKNSEARCH_RESULT_DeleteFrameList
 * address:  0x021C0550
 * packet:   pkt_ov210_021C0550
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FRAME_LIST_Delete 0x021B796C thumb ov067
 *   STRBUF_Delete 0x02045808 arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14683.h"

struct S;
struct U16Vec;
extern void FRAME_LIST_Delete(struct S *s);
extern void STRBUF_Delete(struct U16Vec *vec);

void ZKNSEARCH_RESULT_DeleteFrameList(int p)
{
    unsigned i;

    FRAME_LIST_Delete((struct S *)(((struct Obj14683 *)p)->f1E0));
    ((struct Obj14683 *)p)->f1E0 = 0;
    for (i = 0; i < 0x32; i++) {
        int *q = (int *)(p + i * 4);

        if (q[0x79] != 0) {
            STRBUF_Delete((struct U16Vec *)q[0x79]);
            q[0x79] = 0;
        }
    }
}
