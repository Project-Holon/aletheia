/*
 * function: func_0219D2CC
 * address:  0x0219D2CC
 * packet:   pkt_ov021_0219D2CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct; capped at MATCH by the callee 0x0216D4F8, an unlabelled ARM
 * leaf in ov009 (disasm emits no func_ label there because its prologue saves
 * nothing) with no outside branch, so the blx stays wildcarded.  The wrapper
 * 0x0216D4F8 is real code in ov009 and data in ov010, so the region hint is
 * applied but cannot supply a `label` without a traced start; `sole-ref/code`
 * declines for the same reason.  Witness class: none; needs a function_starts
 * seed at 0x0216D4F8.
 *
 * symbols:
 *   func_0216D4F8  0x0216D4F8  arm  ov009
 *   d_021DDD70     0x021DDD70  data ov021 a4
 */

extern int func_0216D4F8(int);
extern void *func_02030734(int, int, int, void *, int);
extern unsigned char d_021DDD70[];
void func_0219D2CC(int *obj)
{
    *(int *)((char *)obj + 0x20) =
        (int)func_02030734(func_0216D4F8(obj[4]), 0x30, 1, d_021DDD70, 0x979);
}
