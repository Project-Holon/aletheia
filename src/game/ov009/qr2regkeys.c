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
 *   g_021A7C90  0x021A7C90  data
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   g_021A8088  0x021A8088  data
 *   g_021A80A0  0x021A80A0  data
 *   g_021A80CC  0x021A80CC  data
 */
extern int strcmp(const char *a, const char *b);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
int qr2_internal_is_master_only_key(char *keyname);
void qr2_register_keyA(int keyid, char *key);
extern char *g_021A7C90[254];
extern char g_021A8088[];
extern char g_021A80A0[];
extern char g_021A80CC[];


/*
 * sdk:      qr2_internal_is_master_only_key (qr2regkeys.o)
 */
int qr2_internal_is_master_only_key(char *keyname)
{
    if (strcmp(keyname, g_021A7C90[31]) == 0 || strcmp(keyname, g_021A7C90[32]) == 0)
        return 1;
    return 0;
}


/*
 * sdk:      qr2_register_keyA (qr2regkeys.o)
 */
void qr2_register_keyA(int keyid, char *key)
{
    gsDebugFormat(3, (char *)4, 0x40, g_021A8088);
    if (keyid < 0x32 || keyid > 0xfe) {
        gsDebugFormat(3, (char *)4, 2, g_021A80A0, keyid, key);
        return;
    }
    gsDebugFormat(3, (char *)4, 0x10, g_021A80CC, keyid, key);
    g_021A7C90[keyid] = key;
}
