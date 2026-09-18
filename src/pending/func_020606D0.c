/*
 * function: func_020606D0
 * address:  0x020606D0
 * packet:   pkt_020606D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   func_02060468   0x02060468  arm
 *   func_020604AC   0x020604AC  arm
 *   func_020606A8   0x020606A8  arm
 *   g_02146B60      0x02146B60  data
 *   g_02146B64      0x02146B64  data
 *
 * Initialises the renderer's ring buffer at +0x0C with the caller's four
 * fields, packs the fifth (stack) argument into the low byte of the word at
 * +0x20, and once per image also initialises the second ring buffer at
 * 0x02146B64 before flipping the guard word at 0x02146B60.  The last statement
 * forwards func_020606A8's result as func_020604AC's first argument, which is
 * why r0 is never reloaded for that call.
 *
 * Residue, twelve bytes / three instructions: the packed byte at +0x20.  The
 * original builds it as a bitfield word -- `mov ip, #0`, `bic r1, ip, #0xff`,
 * `and r0, d, #0xff`, `orr r2, r1, r0` -- rather than as a plain mask, so the
 * packed value is constructed from a zero base instead of being ANDed on its
 * own.  Three spellings were compiled (`d & 0xff`, `(u32)(u8)d`, and an
 * explicit zero local with `(v & ~0xff) | (d & 0xff)`), all 112 compiled
 * against 124 original; the field is very likely a bitfield declaration in
 * the original struct.  The other difference is that the guard word at
 * 0x02146B60 is re-read rather than cached across the two ring-buffer
 * initialisations.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020606D0.c \
 *       --func func_020606D0 --addr 0x020606D0 --arm --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj020606D0 {
    u32 unk_00;     /* +0x00 */
    u8  ring_04[8];
    u32 ring_0c[8]; /* +0x0C, the ring head/tail block */
    u32 unk_2c_unused;
    u32 unk_18;     /* +0x18 */
    u32 unk_1c;     /* +0x1C */
    u32 unk_20;     /* +0x20 */
    u8  pad_24[0x18];
};

extern u32 g_02146B60;
extern u32 g_02146B64[];

extern void func_02060468(void *buf, u16 size);
extern u32  func_020606A8(struct Obj020606D0 *o);
extern void func_020604AC(void *buf, void *data);

void func_020606D0(struct Obj020606D0 *o, u32 a, u32 b, u32 c, u16 d)
{
    o->unk_00 = a;
    o->unk_18 = b;
    o->unk_1c = c;
    o->unk_20 = d & 0xff;

    func_02060468(&o->ring_0c, 4);

    if (g_02146B60 == 0) {
        func_02060468(g_02146B64, 4);
        g_02146B60 = 1;
    }

    func_020604AC((void *)func_020606A8(o), o);
}
