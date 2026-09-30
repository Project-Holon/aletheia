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
 * u21: the defining object gsdebug.o is .comment 4.0.0.1025. The upstream nitrocaster/GameSpy
 *      HexEncode16 spelling (const aRowWidth/aReplaceChar/aTextOffSet locals, aChar declared in the
 *      loop with its (unsigned char) cast, `*(aTextOutStream++) = (char)aChar`, isgraph through
 *      __ctype_mapC) reproduces the entire 172-byte object except the r6/r7 pair: the image gives
 *      the long-lived aTextOutStream r6 and the byte aChar r7, 1.1p1 the other way round. First
 *      divergence +001C image `add r6, sb, #0x29` | ours `add r7, sb, #0x29`; 9 bytes, all register
 *      numbers. ../2.0/sp1p2 reproduces our 9 B exactly, ../2.0/base 105 B.
 * u1: all six declaration orders compiled - aTextOutStream always takes r7 whenever it is declared before aChar (aChar first gives 11 B). ../2.0/sp1p2 reproduces our 9 B exactly, ../2.0/base 105 B. The vendor allocator hands the long-lived pointer the LOWER of the pair.
 *
 * u31: the vendor gsDebug.c source was re-spelled verbatim (const aRowWidth /
 * aReplaceChar / aTextOffSet, `unsigned char aChar = (unsigned char)(*theInStream++)`
 * block-scoped in the loop, memset through func_020923B0, and `theOutStream += 2`
 * AFTER the isgraph if/else instead of before): still 172 B with the same 9 B,
 * the aTextOutStream/aChar r6/r7 swap. Two declaration-order sweeps (incl. the
 * vendor order and aChar first, which gives 11 B) leave it unchanged, so this is
 * a colouring artefact of the 4.0.0.1025 front end, not a statement-order one.
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
