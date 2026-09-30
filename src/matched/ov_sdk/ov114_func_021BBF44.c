/*
 * function: func_021BBF44
 * address:  0x021BBF44
 * packet:   pkt_ov114_021BBF44
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_SaveBuf (libnhttp.TWL.HYB.a(nhttp_thread.o))
 *
 * Two spellings carry the whole 194 concrete bytes.
 *
 * `const` on srclen is the frame. The parameter is live across both calls and
 * the epilogue returns it, so it needs a home; spelled plain, 1.1p1 keeps the
 * incoming argument slot as the home and the function has no frame at all (176
 * B): the outgoing 5th argument of NHTTPi_SocSend lands at sp+0, on top of src_p's
 * incoming slot. Spelled const, the parameter gets a fresh frame slot at sp+4,
 * which is the `sub sp, sp, #8`, and the outgoing argument then sits at sp+0 of
 * the new frame where the object has it. DWARF records a plain int because a
 * top-level qualifier on a parameter is not part of its type, so this is
 * invisible from the object and behaviourally inert here: nothing writes it.
 *
 * The loop carries no `srclen > 0` guard either. `len` is assigned from srclen
 * and then decremented, so the two are equal at the first test and the object
 * tests the counter once (cmp r4,#0 / bgt at +0x0B4); the redundant guard emits
 * a second compare. Declaration order is sendbyte, len, n: that is the DWARF
 * order and it is what puts len in r4 and n in r5, the opposite of the order
 * the locals were first written in.
 *
 * symbols:
 *   DWCi_Ndi_memcpy  0x021BA100  arm  ov114
 *   func_021BA020    0x021BA020  arm  ov114
 */

typedef struct {
    int doCancel;
} Req;

extern void DWCi_Ndi_memcpy(void *dst_p, void *src_p, int size);
extern int func_021BA020(Req *req_p, int socket, char *buf_p, int len, int flags);

static int func_021BBF44(Req *req_p, char *commBuf_p, int socket, int *bufwp_p, char *src_p, const int srclen)
{
    int sendbyte;
    int len;
    int n;

    len = srclen;
    while (len > 0) {
        if (req_p->doCancel != 0)
            return -1;
        n = 0x4000 - *bufwp_p;
        if (len <= n)
            n = len;
        DWCi_Ndi_memcpy(commBuf_p + *bufwp_p, src_p, n);
        src_p += n;
        *bufwp_p += n;
        len -= n;
        if (*bufwp_p == 0x4000) {
            sendbyte = func_021BA020(req_p, socket, commBuf_p, 0x4000, 0);
            if (sendbyte <= 0)
                return sendbyte;
            *bufwp_p -= sendbyte;
        }
    }
    return srclen;
}
