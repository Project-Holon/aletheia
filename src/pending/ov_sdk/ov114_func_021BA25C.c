/* NHTTPi_getUrlEncodedSize2 (nhttp_stdlib_ntr): near miss, 12 attempts.
 * Residue: original has "cmp r1,#0; mov r3,r2; ldrsb; cmpgt r1,#0; ble" at entry (one extra conditional cmp);
 * this draft emits "mov r3,r2; cmp r1,#0; ldrsb; ble". */
int func_021BA25C(char *p_p, int len)
{
    int i;
    int n;
    char c;

    for (i = 0, n = i, c = *p_p++; i < len; i++, c = *p_p++) {
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ') {
            n += 1;
        } else {
            n += 3;
        }
    }
    return n;
}
