/*
 * function: DWC_Http_GetRawResult
 * address:  0x0217A7C8
 * packet:   pkt_ov009_0217A7C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_Http_GetRawResult (dwc_http.o)
 *
 * symbols:
 *   DWC_Http_GetResult  0x0217a728  arm
 *   strlen              0x0209477c  arm
 *   strcpy              0x02094798  arm
 */

extern char *DWC_Http_GetResult(char *http, char *label);
extern unsigned long strlen(const char *s);
extern char *strcpy(char *dst, const char *src);

int DWC_Http_GetRawResult(char *http, char *label, char *buffer, int buffer_len)
{
    char *value = DWC_Http_GetResult(http, label);
    int value_len;

    if (value == 0)
        return 0;

    value_len = strlen(value);
    if (value_len >= buffer_len)
        return 0;
    strcpy(buffer, value);
    return 1;
}
