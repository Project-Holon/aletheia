/*
 * function: NNSi_G3dAnmObjMarkExistMap
 * address:  0x0206B63C
 * packet:   pkt_0206AF08
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Walks the same node list as src/matched/NNSi_G3dAnmBlendMat.c (count byte at
 * +0x19, u16 entry array at +0x1a, next at +0x10) and sets, in the caller's
 * bitmap, one bit per entry whose 0x100 flag is up.  `f19` is a u8 read into
 * an `int i` loop, which is what makes the bound tests the original's signed
 * `ble`/`blt`.
 *
 * 2.0/sp2 pin (docs/notes/pkt_0206AF08.c.txt): dsi/1.1p1 and 1.2 both
 * if-convert the flagged-bit store into asrne/ldrne/orrne/strne and land at
 * 100 bytes against the original's 104.  Callee of
 * src/matched/NNS_G3dDraw.c.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Node0206B63C Node0206B63C;
struct Node0206B63C {
    u8  pad00[0x10];
    Node0206B63C *f10;
    u8  pad14[0x19 - 0x14];
    u8  f19;
    u16 f1a[1];
};

void NNSi_G3dAnmObjMarkExistMap(u32 *bitmap, Node0206B63C *n)
{
    int i;

    while (n != 0) {
        for (i = 0; i < n->f19; i++) {
            if (n->f1a[i] & 0x100) {
                bitmap[i >> 5] |= 1 << (i & 0x1f);
            }
        }
        n = n->f10;
    }
}
