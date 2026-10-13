/*
 * function: DWCi_CheckDeadAIDBitmap
 * address:  0x0216F014
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Hard-closes every aid present now but absent from the given bitmap.
 *
 * symbols:
 *   DWC_GetAIDBitmap  0x0216B908  arm  ov009
 *   DWCi_CloseConnectionHard  0x0216BEA4  arm  ov009
 */

extern int DWC_GetAIDBitmap(void);
extern int DWCi_CloseConnectionHard(unsigned char aid);

void DWCi_CheckDeadAIDBitmap(unsigned int bitmap)
{
    unsigned int cur = DWC_GetAIDBitmap();
    unsigned int diff = cur & (cur ^ bitmap);
    unsigned char i;

    if (diff == 0) {
        return;
    }
    for (i = 0; i < 0x20; i++) {
        if (diff & (1 << i)) {
            DWCi_CloseConnectionHard(i);
        }
    }
}
