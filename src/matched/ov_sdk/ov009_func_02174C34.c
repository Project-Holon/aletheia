/*
 * function: func_02174C34
 * address:  0x02174C34
 * packet:   pkt_ov009_02174C34
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      DWCi_QR2KeyListCallback (dwc_match.o)
 *
 * symbols:
 *   func_0219B5EC  0x0219B5EC  arm  ov009
 *   g_021AAA40     0x021AAA40  data
 */

struct gamekey_s {
    unsigned char keyID;
    unsigned char pad[11];
};

extern struct gamekey_s g_021AAA40[];
extern void func_0219B5EC(void *keybuffer, int keyid);

void func_02174C34(int keytype, void *keybuffer)
{
    int i;

    switch (keytype) {
    case 0:
        func_0219B5EC(keybuffer, 8);
        func_0219B5EC(keybuffer, 10);
        func_0219B5EC(keybuffer, 0x32);
        func_0219B5EC(keybuffer, 0x33);
        func_0219B5EC(keybuffer, 0x34);
        func_0219B5EC(keybuffer, 0x35);
        func_0219B5EC(keybuffer, 0x36);
        func_0219B5EC(keybuffer, 0x37);
        func_0219B5EC(keybuffer, 0x38);
        for (i = 0; i < 154; i++) {
            if (g_021AAA40[i].keyID != 0)
                func_0219B5EC(keybuffer, g_021AAA40[i].keyID);
        }
        break;
    case 1:
        break;
    case 2:
        break;
    }
}
