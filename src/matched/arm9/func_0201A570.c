/*
 * function: POKE_REGULATION_DeleteText
 * address:  0x0201A570
 * packet:   pkt_02019D58
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT* note: the 42 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A59A before the next labelled function at 0x0201A59C.
 *
 * symbols:
 *   STRBUF_Delete   0x02045808  arm
 *   MSGDATA_Delete   0x02045C04  arm
 *   func_020307B0   0x020307B0  arm
 *
 * Six records of 0x20 bytes, each with a pair of ARM calls at +4 and +0x1C,
 * then the object's first word through the ARM at 0x02045C04 and the object
 * itself through 0x020307B0.  The loop index is a signed int, so the bound
 * test is `blt` and no truncation appears.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/POKE_REGULATION_DeleteText.c \
 *       --func POKE_REGULATION_DeleteText --addr 0x0201A570 --cc 1.1p1 --thumb
 */
#include "../include/Obj15719.h"

typedef unsigned int u32;

struct Rec;
struct U16Vec;
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 func_020307B0(void *p);

void POKE_REGULATION_DeleteText(void *a0)
{
    int i;

    for (i = 0; i < 6; i++) {
        STRBUF_Delete((struct U16Vec *)(*(u32 *)((char *)a0 + i * 4 + 4)));
        STRBUF_Delete((struct U16Vec *)(*(u32 *)((char *)a0 + i * 4 + 0x1C)));
    }
    MSGDATA_Delete((struct Rec *)(((struct Obj15719 *)a0)->f0));
    func_020307B0(a0);
}
