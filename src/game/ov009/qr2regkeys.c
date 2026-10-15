/*
 * file:     qr2regkeys.c
 * unit:     yes
 * function: qr2_internal_is_master_only_key, qr2_register_keyA
 * address:  0x0219D114
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
 *   strcmp  0x020948E0  arm
 *   gQr2RegKeys  0x021A7C90  data
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   gQr2RegKeysDebugRegister  0x021A8088  data
 *   gQr2RegKeysDebugInvalid  0x021A80A0  data
 *   gQr2RegKeysDebugRegistered  0x021A80CC  data
 */
extern int strcmp(const char *a, const char *b);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
int qr2_internal_is_master_only_key(char *keyname);
void qr2_register_keyA(int keyid, char *key);
extern char *gQr2RegKeys[254];
extern char gQr2RegKeysDebugRegister[];
extern char gQr2RegKeysDebugInvalid[];
extern char gQr2RegKeysDebugRegistered[];


/*
 * sdk:      qr2_internal_is_master_only_key (qr2regkeys.o)
 */
int qr2_internal_is_master_only_key(char *keyname)
{
    if (strcmp(keyname, gQr2RegKeys[31]) == 0 || strcmp(keyname, gQr2RegKeys[32]) == 0)
        return 1;
    return 0;
}


/*
 * sdk:      qr2_register_keyA (qr2regkeys.o)
 */
void qr2_register_keyA(int keyid, char *key)
{
    gsDebugFormat(3, (char *)4, 0x40, gQr2RegKeysDebugRegister);
    if (keyid < 0x32 || keyid > 0xfe) {
        gsDebugFormat(3, (char *)4, 2, gQr2RegKeysDebugInvalid, keyid, key);
        return;
    }
    gsDebugFormat(3, (char *)4, 0x10, gQr2RegKeysDebugRegistered, keyid, key);
    gQr2RegKeys[keyid] = key;
}
