/*
 * function: func_021C7FF0
 * address:  0x021C7FF0
 * packet:   pkt_021C7FF0
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * TwlDWC libdwcgsgp gpipeer.o: frees the buffer the message owns and clears
 * the message's pointer (gsifree is func_021C7DE0 here).
 *
 * symbols:
 *   func_021C7DE0  0x021C7DE0  thumb
 */

typedef unsigned int u32;

extern void func_021C7DE0(void *p);

void func_021C7FF0(void *msg)
{
    func_021C7DE0(*(void **)msg);
    *(u32 *)msg = 0;
}
