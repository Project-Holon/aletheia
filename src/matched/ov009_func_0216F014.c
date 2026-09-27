/*
 * function: func_0216F014
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
 *   func_0216B908  0x0216B908  arm  ov009
 *   func_0216BEA4  0x0216BEA4  arm  ov009
 */

extern unsigned int func_0216B908(void);
extern int func_0216BEA4(unsigned char aid);

void func_0216F014(unsigned int bitmap)
{
    unsigned int cur = func_0216B908();
    unsigned int diff = cur & (cur ^ bitmap);
    unsigned char i;

    if (diff == 0) {
        return;
    }
    for (i = 0; i < 0x20; i++) {
        if (diff & (1 << i)) {
            func_0216BEA4(i);
        }
    }
}
