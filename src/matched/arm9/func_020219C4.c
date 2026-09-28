/*
 * function: func_020219C4
 * address:  0x020219C4
 * packet:   pkt_02021984
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Seven-argument initialiser for one 8-byte animation slot (the `+0xc`
 * sub-object of the 0x14-byte per-channel record; both callers, 0x0202173E
 * and 0x0202184A, pass `p + idx*0x14 + 0xc`). Arguments 5..7 arrive on the
 * caller's stack (visible as `add r5,sp,#0x10` with a bare `push {r4-r7}`
 * and no frame). Argument 7 is never read.
 *
 * Halfword layout of the slot:
 *   +0x00  u16 f0            (= arg2, stored whole)
 *   +0x02  lo:6, mid:5, hi:5
 *   +0x04  val:15, flag:1
 *   +0x06  step:5, copy:6, pad:5
 *
 * The narrow parameter types are load-bearing, not cosmetic. Args 5 and 6
 * are read with `ldrb [r5]` / `ldrh [r5,#4]` off the stack-arg area, which
 * only happens when they are declared u8 / u16; and arg 4 must be u8 (not
 * u32 or u16), or the 5-bit bitfield store costs an extra u16-truncation
 * shift pair -- 8 bytes over 192, and the whole tail shifts with it.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed   int   s32;

struct S020219C4 {
    u16 f0;
    u16 lo  : 6;
    u16 mid : 5;
    u16 hi  : 5;
    u16 val  : 15;
    u16 flag : 1;
    u16 step : 5;
    u16 copy : 6;
    u16 pad6 : 5;
};

void func_020219C4(struct S020219C4 *s, u16 f0, s32 a, u8 b,
                   u8 c, u16 d, u32 e)
{
    u8 n;

    if (a < 0) {
        n = (u8)((a < 0 ? -a : a) + 2);
        if (n > 0x10) {
            n = 0x10;
        }
        s->step = n;
        s->lo = 0;
    } else {
        s->step = 2;
        s->lo = (u16)a;
    }

    s->f0 = f0;
    s->mid = b;
    s->hi = c;
    s->val = d;
    s->copy = s->lo;

    if (b < c) {
        s->flag = 0;
    } else {
        s->flag = 1;
    }
}
