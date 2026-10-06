/*
 * function: func_021802C8
 * address:  0x021802C8
 * packet:   pkt_ov009_021802C8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      UTF8ToUCS2StringAlloc (gsstringutil.o)
 *
 * symbols:
 *   func_0209477C                  0x0209477C  arm
 *   func_021802EC                  0x021802EC  arm ov009
 */

typedef unsigned char  u8;
extern int func_0209477C(const u8 *s);
extern unsigned short *func_021802EC(char *theUTF8String, int theUTF8StringLength);

unsigned short *func_021802C8(char *theUTF8String)
{
    if (theUTF8String == 0)
        return 0;
    return func_021802EC(theUTF8String, func_0209477C((const u8 *)theUTF8String));
}
