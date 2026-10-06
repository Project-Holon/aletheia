/*
 * function: func_02193748
 * address:  0x02193748
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * gpiEncodeString: seed the shared RNG with the constant 0x79707367 ("gspy"),
 * XOR each plaintext byte with a random byte, then hand the temporary to
 * func_0217FA90 with mode 1.
 *
 * symbols:
 *   func_0209477C  0x0209477C  arm
 *   func_0217F790  0x0217F790  arm  ov009
 *   func_0217F7AC  0x0217F7AC  arm  ov009
 *   func_0217FA90  0x0217FA90  arm  ov009
 */

typedef unsigned char  u8;
extern int func_0209477C(const u8 *s);
extern void func_0217F790(unsigned int v);
extern unsigned int func_0217F7AC(unsigned int min, unsigned int max);
extern void func_0217FA90(const char *input, char *output, int inlen, int encodingType);

void func_02193748(const char *plaintext, char *encoded)
{
    char temp[0x20];
    unsigned int i;
    unsigned int len;

    len = func_0209477C((const u8 *)plaintext);
    func_0217F790(0x79707367);
    for (i = 0; i < len; i++)
        temp[i] = plaintext[i] ^ (char)func_0217F7AC(0, 0xff);
    temp[i] = 0;
    func_0217FA90(temp, encoded, len, 1);
}
