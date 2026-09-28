/*
 * function: func_02176164
 * address:  0x02176164
 * packet:   pkt_ov009_02176164
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      DWCi_NodeInfoList_RemoveAID (dwc_match.o)
 *
 * Extra open callee of DWCi_DeleteAID (0x0216BCA4).
 *
 * Near miss: every instruction above is reproduced; the shift-down record
 * copy loop (orig 0x80-0xD4) differs only in register assignment and in
 * instruction scheduling (the original holds the two 0x28 strides in r5/r6
 * and emits two `mla`s, and hoists both func_02175F3C calls ahead of the
 * address arithmetic).  This spelling compiles to 236 B vs the original's
 * 240 B.  Blocker: codegen (loop induction-variable scheduling), no
 * evidence class involved.  The first loop and all relocations are right.
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 */

extern char *func_02175F3C(void);

struct NodeRec { int w[10]; };

int func_02176164(unsigned char aid)
{
    int removeAidIndex;
    int i;
    struct NodeRec *d;
    struct NodeRec *s;

    if (*(int *)(func_02175F3C() + 0x50) == 0) return 0;
    for (removeAidIndex = 0; removeAidIndex < *(int *)(func_02175F3C() + 0x50);
         removeAidIndex++) {
        if (aid == *(unsigned char *)(func_02175F3C() + removeAidIndex * 0x28 + 0x6a))
            break;
    }
    if (removeAidIndex == *(int *)(func_02175F3C() + 0x50)) return 0;
    for (i = removeAidIndex; i < *(int *)(func_02175F3C() + 0x50) - 1; ) {
        d = (struct NodeRec *)(func_02175F3C() + i * 0x28 + 0x54);
        i++;
        s = (struct NodeRec *)(func_02175F3C() + i * 0x28 + 0x54);
        *d = *s;
    }
    *(int *)(func_02175F3C() + 0x50) -= 1;
    return 1;
}
