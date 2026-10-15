/*
 * function: DWC_Http_Destroy
 * address:  0x02179CF4
 * packet:   pkt_ov009_02179CF4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Http_Destroy (dwc_http.o)
 *
 * symbols:
 *   func_0217A808  0x0217A808  arm  ov009
 *   func_0217A120  0x0217A120  arm  ov009
 *   MI_CpuFill8    0x02082BCC  arm
 */

extern void func_0217A808(char *http, void *array_entry, int array_len);
extern void func_0217A120(char *http, void *buf);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);

void DWC_Http_Destroy(char *http)
{
    void (*free)(unsigned long, void *, long) =
        *(void (**)(unsigned long, void *, long))(http + 0x1014);

    if (http == 0) {
        return;
    }
    func_0217A808(http, http + 0x1a74, 0x20);
    func_0217A120(http, http + 0x1a44);
    func_0217A120(http, http + 0x1a34);
    if (*(void **)(http + 0x1a08) != 0) {
        free(0, *(void **)(http + 0x1a08), 0);
        *(void **)(http + 0x1a08) = 0;
    }
    if (*(void **)(http + 0x1a0c) != 0) {
        free(0, *(void **)(http + 0x1a0c), 0);
        *(void **)(http + 0x1a0c) = 0;
    }
    MI_CpuFill8(http, 0, 0x1c50);
}
