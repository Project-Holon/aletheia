/*
 * function: func_021BA168
 * address:  0x021BA168
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Scans the 0x30 records of 0x1C bytes at +0x30 and returns the address of the
 * first whose leading word is zero, else 0.  Two earlier lanes read the
 * product/address register pair as allocator taste; it is the two address
 * spellings.  With both written field-constant-first the compiler homes the
 * `i * 0x1C` product in r2 and prints `adds r3, r0, r2`, which is not what the
 * image has.  Writing the load field-last (`p + i * 0x1C + 0x30`, giving
 * `adds r2, r0, r3 ; ldr r2, [r2, #0x30]`) and the exit field-first
 * (`(u8 *)(p + 0x30) + i * 0x1C`, giving `adds r0, #0x30 ; adds r0, r0, r3`)
 * is what reproduces the image exactly.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed short   s16;
typedef int BOOL;

u8 *func_021BA168(u8 *p)
{
    int i;

    for (i = 0; i < 0x30; i++) {
        if (*(u32 *)(p + i * 0x1C + 0x30) == 0) {
            return (u8 *)(p + 0x30) + i * 0x1C;
        }
    }
    return 0;
}
