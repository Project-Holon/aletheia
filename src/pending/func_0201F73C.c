/*
 * function: func_0201F73C
 * address:  0x0201F73C
 * packet:   pkt_0201F5BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 *
 * Unpacks five byte fields out of the descriptor in the first argument and
 * hands them, plus the caller's own last two arguments, to the seven-argument
 * worker at 0x0201F628; then dispatches on the second argument to one of two
 * ARM helpers keyed by the descriptor's id byte.
 *
 * Every field read is a call into a one-instruction ARM accessor
 * (`ldrb r0, [r0, #n]; bx lr`) rather than an inline load, which is why the
 * function spends 0x1c bytes of stack on nothing but the argument block: the
 * accessors clobber r0-r3, so each result has to be parked before the next
 * call and reloaded into place only once all five are in hand.
 *
 * Blocked on the `label` class: 0x0201F628 has exactly one caller image-wide,
 * the call in this function, so there is no witness outside the compared
 * range and no cut that creates one.  0x0201F628 is itself a documented near
 * miss (86 bytes of scheduler residue), see docs/notes/func_0201F628.c.txt;
 * this file graduates the day that function reaches EXACT.
 *
 * symbols:
 *   func_02045730  0x02045730  arm
 *   func_02045748  0x02045748  arm
 *   func_02045750  0x02045750  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0201F628  0x0201F628  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F73C.c \
 *       --func func_0201F73C --addr 0x0201F73C --cc 1.1p1 --thumb
 */
typedef unsigned char u8;
typedef unsigned int  u32;

extern u8   func_02045730(void *d);
extern u8   func_02045748(void *d);
extern u8   func_02045750(void *d);
extern u8   func_02045758(void *d);
extern u8   func_02045760(void *d);
extern void func_020409B4(u8 id);
extern void func_02041B6C(u8 id);
extern void func_0201F628(u8 id, u8 a, u8 b, u8 c, u8 d, u32 e, u32 f);

void func_0201F73C(void *desc, u32 kind, u32 p2, u32 p3)
{
    u8 id;
    u8 a;
    u8 b;
    u8 c;
    u8 d;

    id = func_02045730(desc);
    a = func_02045758(desc);
    b = func_02045760(desc);
    c = func_02045748(desc);
    d = func_02045750(desc);
    func_0201F628(id, a, b, c, d, p3, p2);
    if (kind == 0) {
        func_020409B4(id);
        return;
    }
    if (kind == 1) {
        func_02041B6C(id);
    }
}
