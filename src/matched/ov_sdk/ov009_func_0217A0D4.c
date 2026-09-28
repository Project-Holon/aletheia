/*
 * function: DWCi_Http_AllocBuffer
 * address:  0x0217A0D4
 * packet:   pkt_ov009_0217A0D4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Http_AllocBuffer (dwc_http.o)
 *
 * symbols:
 *   (none)
 */

static int DWCi_Http_AllocBuffer(char *http, char *buf, unsigned long size)
{
    void *(*alloc)(unsigned long, long) = *(void *(**)(unsigned long, long))(http + 0x1010);
    void *p;

    if (size == 0)
        return 0;

    p = alloc(0, size);
    *(void **)(buf + 0) = p;
    if (p == 0)
        return 0;

    *(void **)(buf + 4) = p;
    *(void **)(buf + 8) = (char *)p + size;
    *(unsigned long *)(buf + 0xc) = size;
    return 1;
}
