/*
 * function: qr2_register_keyA
 * address:  0x0219D158
 * packet:   pkt_ov009_0219D158
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr2_register_keyA (qr2regkeys.o)
 *
 * symbols:
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   gQr2RegKeysDebugRegister  0x021A8088  data
 *   gQr2RegKeysDebugInvalid  0x021A80A0  data
 *   gQr2RegKeysDebugRegistered  0x021A80CC  data
 *   gQr2RegKeys  0x021A7C90  data
 */

extern char gQr2RegKeysDebugRegister[];
extern char gQr2RegKeysDebugInvalid[];
extern char gQr2RegKeysDebugRegistered[];
extern char *gQr2RegKeys[254];
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);

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
