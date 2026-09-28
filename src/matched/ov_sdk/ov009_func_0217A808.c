/*
 * function: DWCi_Http_DestroyResult
 * address:  0x0217A808
 * packet:   pkt_ov009_0217A808
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * A one-record-per-iteration struct index makes the compiler keep the base
 * in r8 and use [r8, i, lsl #3] every time; hand-rolled byte offsets CSE into
 * an extra address register and cost 4 bytes.
 *
 * sdk:      DWCi_Http_DestroyResult (dwc_http.o)
 *
 * symbols:
 *   (none)
 */

typedef struct {
    char *label;
    char *value;
} DWCHttpLabelValue;

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
