/*
 * function: func_021BE324
 * address: 0x021BE324
 * packet: pkt_ov210_021BE324
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021BE366..021BE368 is zero alignment padding.
 * proof: 071CC forwards to 0319A4, which forwards fixed r1=0x36 to
 *        033B68; their full matched bodies use no incoming r2/r3.
 * ABI: 02012BF8's full 20-byte body preserves r1 across EC0/C404 and
 *      supplies only r0/r1 to C44C. EC0 reads only r0; C404 forwards r0
 *      through C40C/071CC with fixed r1=0x36. C44C reads r0/r1 only.
 *      Legacy trailing a2/a3 are omitted; all original visible inputs remain.
 * symbols:
 *   func_02012BF8 0x02012BF8 thumb
 *   func_02012BE0 0x02012BE0 thumb
 *   func_021BEDB8 0x021BEDB8 thumb ov210
 */
typedef unsigned char u8;
extern int func_02012BF8(void *, unsigned);
extern void func_02012BE0(void *, unsigned, unsigned);
extern void func_021BEDB8(void *, int, int);
void func_021BE324(u8 *p)
{
    if (func_02012BF8(**(void ***)p, 16) == 1) {
        func_02012BE0(**(void ***)p, 16, 0);
        func_021BEDB8(p, 4, 6);
    } else {
        func_02012BE0(**(void ***)p, 16, 1);
        func_021BEDB8(p, 4, 7);
    }
}
