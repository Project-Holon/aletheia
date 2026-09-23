/*
 * function: func_02075968
 * address:  0x02075968
 * packet:   pkt_02075968
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Release the object's attached cell (+0x154: clear what it points at, then
 * the pointer) and clear flag bits 0, 2 and 1 of the word at +0x118, in that
 * order.  The +0x118 word is the signed one-bit bitfield set its callers
 * 0x02075A2C and 0x02075994 test with lsl/asrs (docs/notes/pkt_02075794.c.txt).
 *
 * Front end: ../2.0/sp2.  The tell is the first clear writing a FRESH
 * register (`bic r2, r1, #1` then `bic r1, r2, #4`): 1.1p1 coalesces it
 * (`bic r1, r1, #1`, 2 bytes out under every spelling and a 2000-compile
 * anneal); ../2.0/sp2 and sp2p2 give the image's allocation for both the
 * bitfield and the three-statement mask spelling.
 */
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;

typedef struct {
    u8  unk000[0x118];
    s32  b0 : 1;
    s32  b1 : 1;
    s32  b2 : 1;
    s32  rest : 29;
    u8  unk11c[0x154 - 0x11c];
    u32 *unk154;
} Obj02075968;

void func_02075968(Obj02075968 *o)
{
    if (o->unk154 != 0) {
        *o->unk154 = 0;
        o->unk154 = 0;
    }
    o->b0 = 0;
    o->b2 = 0;
    o->b1 = 0;
}
