/*
 * function: DWCi_Http_ReallocBuffer
 * address:  0x0217A15C
 * packet:   pkt_ov009_0217A15C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Http_ReallocBuffer (dwc_http.o)
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 */

typedef struct {
    char *base;
    char *cur;
    char *end;
    int cap;
} Buf;
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);

int DWCi_Http_ReallocBuffer(char *http, Buf *buf, int size)
{
    void *(*alloc)(unsigned long, long);
    void (*free)(unsigned long, void *, long);
    char *newptr;

    alloc = *(void *(**)(unsigned long, long))(http + 0x1010);
    free = *(void (**)(unsigned long, void *, long))(http + 0x1014);
    if (size <= 0) {
        return 0;
    }
    newptr = alloc(0, buf->cap + size);
    if (newptr == 0) {
        return 0;
    }
    MI_CpuCopy8(buf->base, newptr, buf->cap);
    free(0, buf->base, 0);
    if (newptr == 0) {
        return 0;
    }
    buf->cur = buf->cur + (newptr - buf->base);
    buf->cap = buf->cap + size;
    buf->base = newptr;
    buf->end = newptr + buf->cap;
    return 1;
}
