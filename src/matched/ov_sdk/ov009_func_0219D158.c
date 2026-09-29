/*
 * function: func_0219D158
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
 *   func_0217D254  0x0217D254  arm  ov009
 *   g_021A8088  0x021A8088  data
 *   g_021A80A0  0x021A80A0  data
 *   g_021A80CC  0x021A80CC  data
 *   g_021A7C90  0x021A7C90  data
 */

extern char g_021A8088[];
extern char g_021A80A0[];
extern char g_021A80CC[];
extern char *g_021A7C90[254];
extern void func_0217D254(int cat, int type, int level, const char *fmt, ...);

void func_0219D158(int keyid, char *key)
{
    func_0217D254(3, 4, 0x40, g_021A8088);
    if (keyid < 0x32 || keyid > 0xfe) {
        func_0217D254(3, 4, 2, g_021A80A0, keyid, key);
        return;
    }
    func_0217D254(3, 4, 0x10, g_021A80CC, keyid, key);
    g_021A7C90[keyid] = key;
}
