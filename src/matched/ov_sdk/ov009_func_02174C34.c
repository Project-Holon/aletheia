/*
 * function: DWCi_QR2KeyListCallback
 * address:  0x02174C34
 * packet:   pkt_ov009_02174C34
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_QR2KeyListCallback (dwc_match.o)
 *
 * symbols:
 *   qr2_keybuffer_add  0x0219B5EC  arm  ov009
 *   g_021AAA40     0x021AAA40  data
 */

struct gamekey_s {
    unsigned char keyID;
    unsigned char pad[11];
};

extern struct gamekey_s g_021AAA40[];
extern int qr2_keybuffer_add(char *p, int v);

void DWCi_QR2KeyListCallback(int keytype, void *keybuffer)
{
    int i;

    switch (keytype) {
    case 0:
        qr2_keybuffer_add(keybuffer, 8);
        qr2_keybuffer_add(keybuffer, 10);
        qr2_keybuffer_add(keybuffer, 0x32);
        qr2_keybuffer_add(keybuffer, 0x33);
        qr2_keybuffer_add(keybuffer, 0x34);
        qr2_keybuffer_add(keybuffer, 0x35);
        qr2_keybuffer_add(keybuffer, 0x36);
        qr2_keybuffer_add(keybuffer, 0x37);
        qr2_keybuffer_add(keybuffer, 0x38);
        for (i = 0; i < 154; i++) {
            if (g_021AAA40[i].keyID != 0)
                qr2_keybuffer_add(keybuffer, g_021AAA40[i].keyID);
        }
        break;
    case 1:
        break;
    case 2:
        break;
    }
}
