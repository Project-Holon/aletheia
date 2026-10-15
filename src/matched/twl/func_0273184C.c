/*
 * function: SHA1_HMAC_UpdateData
 * address:  0x0273184C
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SHA1_HMAC_Update  0x02731760  thumb
 */

#pragma thumb on
extern void SHA1_HMAC_Update(void *a, void *b, void *c);
#pragma thumb reset

void SHA1_HMAC_UpdateData(void *a, void *b, void *c)
{
    if (a != 0 && c != 0 && b != 0) {
        SHA1_HMAC_Update(a, b, c);
    }
}
