/*
 * function: func_021BB164
 * address:  0x021BB164
 * packet:   pkt_ov088_021BB164
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Releases the fourteen 8-byte-stride handles at +0x80 created by
 * func_021BAD08, then the shared resource.
 *
 * symbols:
 *   func_020452E8  0x020452E8  arm
 *   func_020450C8  0x020450C8  arm
 */

struct Descriptor;
typedef unsigned int   u32;
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);

void func_021BB164(char *p)
{
    unsigned i;
    for (i = 0; i < 14; i++)
        func_020452E8(*(void **)(p + 0x80 + i * 8));
    func_020450C8();
}
