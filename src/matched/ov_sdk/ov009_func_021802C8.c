/*
 * function: UTF8ToUCS2StringAlloc
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
 *   strlen                  0x0209477C  arm
 *   UTF8ToUCS2StringAllocLen                  0x021802EC  arm ov009
 */

typedef unsigned char  u8;
extern int strlen(const u8 *s);
extern unsigned short *UTF8ToUCS2StringAllocLen(char *theUTF8String, int theUTF8StringLength);

unsigned short *UTF8ToUCS2StringAlloc(char *theUTF8String)
{
    if (theUTF8String == 0)
        return 0;
    return UTF8ToUCS2StringAllocLen(theUTF8String, strlen((const u8 *)theUTF8String));
}
