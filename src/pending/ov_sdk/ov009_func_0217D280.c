/*
 * function: func_0217D280
 * address:  0x0217D280
 * packet:   pkt_ov009_0217D280
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      HexEncode16 (gsdebug.o)
 *
 * near miss: HexEncode16: 172 bytes. Only diff is a register swap: original aTextOutStream=r6, aChar=r7; 1.1p1 gives aChar=r6, aTextOutStream=r7 (8 instrs). Tried all declaration orders, initializers, block-scoped aChar, int aChar, several isprint forms, ternary stores.
 *
 * symbols:
 *   func_020923B0                  0x020923B0  arm
 *   func_02084F40                  0x02084F40  arm
 *   g_020A61DC                     0x020A61DC  data
 *   g_021A3710                     0x021A3710  data
 */

extern void *func_020923B0(void *p, int c, unsigned long n);
extern int func_02084F40(char *dst, char *fmt, ...);
extern unsigned short g_020A61DC[];
extern char g_021A3710[];

void func_0217D280(char *theInStream, char *theOutStream, unsigned int theInLen)
{
    char *aTextOutStream = theOutStream + 41;
    unsigned int aWriteBit = theInLen & 1;
    unsigned char aChar;

    func_020923B0(theOutStream, ' ', 64);
    while (theInLen--) {
        aChar = *theInStream++;
        func_02084F40(theOutStream, g_021A3710, aChar);
        theOutStream += 2;
        if ((aChar >= 0x80) ? 0 : (g_020A61DC[aChar] & 0x10))
            *aTextOutStream++ = aChar;
        else
            *aTextOutStream++ = '.';
        if ((theInLen & 1) == aWriteBit)
            *theOutStream++ = ' ';
    }
    *theOutStream = ' ';
    *aTextOutStream = 0;
}
