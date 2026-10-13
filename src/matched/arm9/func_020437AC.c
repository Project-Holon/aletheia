/*
 * function: BMP_Delete
 * address:  0x020437AC
 * packet:   pkt_0204361C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Destructor: release the owned buffer at +0x00 first, but only when the
 * halfword count at +0x0a is zero, then release the object itself.  The
 * guard is inverted in the original (`bne` over the first release), which
 * is the source order of a plain `if (p->unk0a == 0)` with no else.
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_Delete.c \
 *       --func BMP_Delete --addr 0x020437AC --cc 1.1p1 --arm
 */

typedef unsigned short u16;

struct Obj020437AC {
    void *buffer; /* 0x00 */
    u16   pad04[3];
    u16   unk0a;  /* 0x0a */
};

typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void BMP_Delete(struct Obj020437AC *p)
{
    if (p->unk0a == 0)
        func_020307B0(p->buffer);

    func_020307B0(p);
}
