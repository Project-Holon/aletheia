/*
 * function: func_02013284
 * address:  0x02013284
 * packet:   pkt_02013284
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012984   0x02012984  thumb
 *   func_02013234   0x02013234  thumb
 *   func_0201A920   0x0201A920  thumb
 *   func_0202A3FC   0x0202A3FC  thumb
 *   func_0202A440   0x0202A440  thumb
 *   func_0202A4B4   0x0202A4B4  thumb
 *   func_0216AAE4   0x0216AAE4  thumb
 *
 * btl_setup.c.  The sub-block filler, and the most-called function of the
 * family: every builder in the range (func_02013610, func_02013644,
 * func_02013678, func_020136AC, func_020136E0, func_02013734, func_02013810,
 * all EXACT) calls it once or three times.  It lazily fills two slots - the
 * caller's own out-pointer and the object's +0x48 array entry - then, only if
 * the value argument is non-zero, binds them together and picks the object's
 * +0x1a code from a twelve-way switch.
 *
 * This closes the near miss in docs/notes/pkt_02013284.c.txt, which sat at 48
 * concrete bytes out with the size already exact.  Two things closed it.
 *
 * (1) THE ARITY IS SIX, NOT SEVEN.  The note gave it seven parameters
 * (a0..a6).  The six-parameter form is fixed from outside this function by
 * the matched callers, every one of which passes exactly six
 * (o, a1, n, dst, v, h).  Re-spelling the signature that way took the
 * residue from 48 concrete bytes out to 15 and halved the permuter's
 * instruction score, 525 -> 280, with the size unchanged at 184.
 *
 * (2) THE +0x48 SLOT IS REGISTER-OFFSET ADDRESSED, so its base and its
 * scaled index have to be two separate live values.  The image loads it with
 * `ldr r0, [r7, r6]` where r7 is o+0x48 and r6 is n*4; writing the access as
 * a single pointer, `slot = (u32 *)(o + 0x48 + n * 4)`, folds the two into
 * one value and the allocator then has one fewer value to colour, which is
 * what produced the r5/r6/r7 rotation the permuter reported.  Splitting it
 * into a `u8 *base` and a separate `u32 off`, and indexing as
 * `*(u32 *)(base + off)`, keeps both values live and gives the original
 * registers and the original `lsls` / `adds` order.  A `u32 *` base with a
 * divided index (`base[off / 4]`) does NOT work: the compiler folds the
 * scaling back out and the rotation returns.
 *
 * The permuter was the diagnostic here rather than the fix.  `--explain` on
 * the seven-parameter source printed a clean three-way register rotation
 * (r7->r6, r6->r7, r5->...), which is what said the residue was an allocation
 * tie and not a mistranslation, and on the six-parameter source it printed
 * the same rotation at 15 bytes out with every instruction aligned - which
 * localised the fix to the one value that was missing.  Its own best results
 * were rejected on both passes: hill found temp(tmp=*slot) at 11 bytes out
 * but with the instruction score RISING 280 -> 460, the signature of a
 * coincidental byte alignment rather than a real fix.
 *
 * The switch is dense from 2 to 11 with 0, 1, 5 and 10 falling to the
 * default, which is what makes the PC-relative halfword table exist; the
 * `cmp r0, #0xb / bhi` pair is the table's range check.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013284.c \
 *       --func func_02013284 --addr 0x02013284 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BigObj;
struct Out;
struct Party;
extern struct Party *func_0201A920(u32 heap);
extern void *func_02013234(u32 heap);
extern void func_0202A440(u32 id, struct Out *out, u32 heap);
extern void func_0202A4B4(u32 a, u32 b, u32 c);
extern u8 func_02012984(const struct BigObj *p);
extern void func_0216AAE4(u32 a, u32 b, u32 c);
extern u8 func_0202A3FC(u32 key);

void func_02013284(u8 *o, u32 *a1, u32 n, u32 *dst, u32 v, u32 h)
{
    u8 *base;
    u32 off;

    if (*dst == 0) {
        *dst = (u32)func_0201A920(h);
    }
    off = n * 4;
    base = o + 0x48;
    if (*(u32 *)(base + off) == 0) {
        *(u32 *)(base + off) = (u32)func_02013234(h);
    }
    if (v == 0) {
        return;
    }
    func_0202A440(v, (struct Out *)(*(u32 *)(base + off)), h);
    func_0202A4B4(v, *dst, h);
    func_0216AAE4((u32)a1, *dst, func_02012984((const struct BigObj *)((u32)a1)));
    switch (func_0202A3FC(*(u32 *)(*(u32 *)(base + off) + 4))) {
    case 2:
    case 3:
        *(u16 *)(o + 0x1a) = 0x47e;
        break;
    case 7:
    case 8:
        *(u16 *)(o + 0x1a) = 0x47f;
        break;
    case 4:
    case 11:
        *(u16 *)(o + 0x1a) = 0x480;
        break;
    case 6:
    case 9:
        *(u16 *)(o + 0x1a) = 0x491;
        break;
    default:
        *(u16 *)(o + 0x1a) = 0x47d;
        break;
    }
}
