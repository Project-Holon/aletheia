/* NHTTPi_SaveBuf (nhttp_thread.o): near miss, ~10 attempts.
 * Residue: original has an 8-byte frame (sub sp,#8) and spills the incoming srclen to [sp+4] right after
 * loading it (mov r0,r4; str r4,[sp,#4]; return reloads it); this draft has no frame and reloads the incoming
 * stack slot. Counter/n registers (r4/r5) and all instructions after the prologue are otherwise the same shape.
 * Tried decl permutations, srclen vs len as counter, while/for/do-while. Declaring the counter as the parameter
 * and returning a saved copy gets the frame but moves the counter to r5. */
typedef struct {
    int doCancel;
} Req;

extern void func_021BA100(void *dst_p, void *src_p, int size);
extern int func_021BA020(Req *req_p, int socket, char *buf_p, int len, int flags);

int func_021BBF44(Req *req_p, char *commBuf_p, int socket, int *bufwp_p, char *src_p, int srclen)
{
    int n;
    int len;
    int sendbyte;

    len = srclen;
    if (len > 0) {
        do {
            if (req_p->doCancel != 0) {
                return -1;
            }
            n = 0x4000 - *bufwp_p;
            if (len <= n) {
                n = len;
            }
            func_021BA100(commBuf_p + *bufwp_p, src_p, n);
            src_p += n;
            *bufwp_p += n;
            len -= n;
            if (*bufwp_p == 0x4000) {
                sendbyte = func_021BA020(req_p, socket, commBuf_p, 0x4000, 0);
                if (sendbyte <= 0) {
                    return sendbyte;
                }
                *bufwp_p -= sendbyte;
            }
        } while (len > 0);
    }
    return srclen;
}
