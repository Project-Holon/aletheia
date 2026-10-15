/*
 * function: qr2_internal_is_master_only_key
 * address:  0x0219D114
 * packet:   pkt_ov009_0219D114
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr2_internal_is_master_only_key (qr2regkeys.o)
 *
 * symbols:
 *   strcmp  0x020948E0  arm
 *   gQr2RegKeys  0x021A7C90  data
 */

extern char *gQr2RegKeys[254];
extern int strcmp(const char *a, const char *b);

int qr2_internal_is_master_only_key(char *keyname)
{
    if (strcmp(keyname, gQr2RegKeys[31]) == 0 || strcmp(keyname, gQr2RegKeys[32]) == 0)
        return 1;
    return 0;
}
