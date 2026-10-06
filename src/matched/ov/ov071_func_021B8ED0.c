/*
 * function: func_021B8ED0
 * address:  0x021B8ED0
 * packet:   pkt_ov071_021B8ED0
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to func_021B70B8 with the pointer advanced by 0x48.  The callee
 * is an unlabelled leaf in this overlay; it is reproduced in
 * src/matched/ov071_func_021B70B8.c, whose EXACT entry attests this pool-word
 * site (`matched`).
 *
 * symbols:
 *   func_021B70B8  0x021B70B8  thumb  ov071
 */

void func_021B8ED0(void *p)
{
    void func_021B70B8(void **p);
    func_021B70B8((void **)((char *)p + 0x48));
}
