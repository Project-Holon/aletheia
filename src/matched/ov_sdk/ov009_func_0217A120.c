/*
 * function: DWCi_Http_FreeBuffer
 * address:  0x0217A120
 * packet:   pkt_ov009_0217A120
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Http_FreeBuffer (dwc_http.o)
 *
 * symbols:
 *   MI_CpuFill8  0x02082bcc  arm
 */

extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);

static void DWCi_Http_FreeBuffer(char *http, char *buf)
{
    void (*free)(unsigned long, void *, long) = *(void (**)(unsigned long, void *, long))(http + 0x1014);

    if (*(void **)buf != 0) {
        free(0, *(void **)buf, 0);
    }
    MI_CpuFill8(buf, 0, 0x10);
}
