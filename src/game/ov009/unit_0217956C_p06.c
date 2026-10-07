/*
 * file:     unit_0217956C_p06.c
 * unit:     yes
 * function: func_0217A728, func_0217A77C, func_0217A7C8, func_0217A808
 * address:  0x0217A728
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   strcmp  0x020948e0  arm
 *   strlen              0x0209477c  arm
 *   DWC_Base64Decode    0x02059cbc  arm
 *   strcpy              0x02094798  arm
 */
typedef struct {
    char *label;
    char *value;
} DWCHttpLabelValue;

extern int strcmp(const char *s1, const char *s2);
extern unsigned long strlen(const char *s);
extern int DWC_Base64Decode(char *src, unsigned long srclen, char *dst, unsigned long dstlen);
extern char *strcpy(char *dst, const char *src);
char *DWC_Http_GetResult(char *http, char *label);
int DWC_Http_GetBase64DecodedResult(char *http, char *label, char *buffer, unsigned long buffer_len);
int DWC_Http_GetRawResult(char *http, char *label, char *buffer, int buffer_len);


char *DWC_Http_GetResult(char *http, char *label)
{
    int i;

    for (i = 0; i < 0x20; i++) {
        if (*(char **)(http + 0x1a74 + i * 8) == 0)
            break;
        if (strcmp(label, *(char **)(http + 0x1a74 + i * 8)) == 0)
            return *(char **)(http + 0x1a78 + i * 8);
    }
    return 0;
}


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


static void DWCi_Http_DestroyResult(char *http, DWCHttpLabelValue *array_entry, int array_len)
{
    void (*free)(unsigned long, void *, long) = *(void (**)(unsigned long, void *, long))(http + 0x1014);
    int i;

    for (i = 0; i < array_len; i++) {
        if (array_entry[i].label != 0) {
            free(0, array_entry[i].label, 0);
            array_entry[i].label = 0;
        }
        if (array_entry[i].value != 0) {
            free(0, array_entry[i].value, 0);
            array_entry[i].value = 0;
        }
    }
}
