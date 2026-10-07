/*
 * function: func_02197BB8
 * address:  0x02197BB8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call on three fields of the object.
 *
 * symbols:
 *   func_02197BD4  0x02197BD4  arm  ov009
 */

struct Sock;
extern int func_02197BD4(struct Sock *sock, unsigned int ip, unsigned short port);

int func_02197BB8(int *p)
{
    return func_02197BD4((struct Sock *)p[2], p[0], *(unsigned short *)((char *)p + 4));
}

