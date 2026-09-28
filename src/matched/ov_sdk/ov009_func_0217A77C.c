/*
 * function: DWC_Http_GetBase64DecodedResult
 * address:  0x0217A77C
 * packet:   pkt_ov009_0217A77C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Http_GetBase64DecodedResult (dwc_http.o)
 *
 * symbols:
 *   DWC_Http_GetResult  0x0217a728  arm
 *   strlen              0x0209477c  arm
 *   DWC_Base64Decode    0x02059cbc  arm
 */

extern char *DWC_Http_GetResult(char *http, char *label);
extern unsigned long strlen(const char *s);
extern int DWC_Base64Decode(char *src, unsigned long srclen, char *dst, unsigned long dstlen);

int DWC_Http_GetBase64DecodedResult(char *http, char *label, char *buffer, unsigned long buffer_len)
{
    char *value = DWC_Http_GetResult(http, label);
    int result_len;

    if (value == 0)
        return 0;

    result_len = DWC_Base64Decode(value, strlen(value), buffer, buffer_len);
    if (result_len == -1)
        return result_len;
    if (result_len < buffer_len)
        buffer[result_len] = 0;
    return result_len;
}
