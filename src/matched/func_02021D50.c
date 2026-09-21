/*
 * function: func_02021D50
 * address:  0x02021D50
 * packet:   pkt_02021D50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_020862F0   0x020862F0  arm
 *   func_0207E3D0   0x0207E3D0  arm
 *   func_0207E468   0x0207E468  arm
 *   func_0207E51C   0x0207E51C  arm
 *   func_0207E5D0   0x0207E5D0  arm
 *   func_0207F308   0x0207F308  arm
 *   func_0207F394   0x0207F394  arm
 *   func_0207F428   0x0207F428  arm
 *   func_0207F47C   0x0207F47C  arm
 *   func_0207F4C4   0x0207F4C4  arm
 *   func_0207F560   0x0207F560  arm
 *   func_0207F5B0   0x0207F5B0  arm
 *   func_0207F5C8   0x0207F5C8  arm
 *   func_0207F65C   0x0207F65C  arm
 *   func_0207F6A8   0x0207F6A8  arm
 *   func_0207F6C0   0x0207F6C0  arm
 *   func_0207F754   0x0207F754  arm
 *   func_02021930   0x02021930  thumb
 *
 * The apply pass of the slot object: walks the 14 channel records and pushes
 * each one's current value out through the graphics-engine setter that the
 * channel index selects (a dense 14-entry halfword switch table at
 * 0x02021DBA). Runs only when the +0x11A field's top bit is set or the
 * +0x118 field's mode is 1.
 *
 * Two types are load-bearing. `i` must be u32 for the switch's own range
 * guard to come out `cmp #0xd; bhi` (signed makes it a `bgt`/`bhi` pair),
 * but the loop's own bound must be compared signed -- `(int)i < 14` -- or
 * the back edge is `bhs` where the original has `bge`. And the bit index
 * handed to func_02021930 is truncated, `(u16)i`, which is the
 * `lsls #0x10 / lsrs #0x10` pair at +0x3E.
 *
 * The final `if` re-reads p->b_lo out of memory rather than reusing the
 * value just stored; testing p->a_big instead loses the reload.
 *
 * EXACT* only: 392 bytes compiled and correct throughout. The listing's
 * 532-byte extent runs past the literal pool at 0x02021ED0 into a run of
 * unlabelled leaf accessors starting at 0x02021EE4 (none saves lr, so
 * disasm.py never labelled them; the first is
 * `movs r1,#0x46; lsls r1,#2; ldrh r0,[r0,r1]; lsls #0x10; lsrs #0xc;
 * bx lr`). Worth seeding into layout/function_starts.txt; reported rather
 * than edited here.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Chan {
    u32 f0;
    void *f4;
    u32 f8;
    u32 fc;
    u32 f10;
};

struct S02021D50 {
    struct Chan ch[14];
    u16 a_mode : 2;
    u16 a_big  : 14;
    u16 b_lo : 14;
    u16 b_x  : 1;
    u16 b_hi : 1;
};

extern int func_02021930(u32 mask, u32 bit);
extern void func_020862F0(void *a, u32 b);
extern void func_0207E3D0(void *a, u32 b, u32 c);
extern void func_0207E468(void *a, u32 b, u32 c);
extern void func_0207E51C(void *a, u32 b, u32 c);
extern void func_0207E5D0(void *a, u32 b, u32 c);
extern void func_0207F308(void);
extern void func_0207F394(void *a, u32 b, u32 c);
extern void func_0207F428(void);
extern void func_0207F47C(void);
extern void func_0207F4C4(void *a, u32 b, u32 c);
extern void func_0207F560(void);
extern void func_0207F5B0(void);
extern void func_0207F5C8(void *a, u32 b, u32 c);
extern void func_0207F65C(void);
extern void func_0207F6A8(void);
extern void func_0207F6C0(void *a, u32 b, u32 c);
extern void func_0207F754(void);

void func_02021D50(struct S02021D50 *p)
{
    struct Chan *c;
    u32 k;
    u32 i;

    if (p->b_hi == 0 && p->a_mode != 1) {
        return;
    }

    k = 0x2000;
    for (i = 0; (int)i < 14; i++) {
        if (p->b_hi == 0) {
            if (p->ch[i].f4 == 0) {
                continue;
            }
            if (func_02021930(p->b_lo, (u16)i) == 0) {
                continue;
            }
        }
        c = &p->ch[i];
        func_020862F0(c->f4, c->f8);
        switch (i) {
        case 0:
            func_0207E3D0(c->f4, 0, c->f8);
            break;
        case 1:
            func_0207E468(c->f4, 0, c->f8);
            break;
        case 2:
            func_0207E51C(c->f4, 0, c->f8);
            break;
        case 3:
            func_0207E5D0(c->f4, 0, c->f8);
            break;
        case 4:
            func_0207F308();
            func_0207F394(c->f4, 0, c->f8);
            func_0207F428();
            break;
        case 5:
            func_0207F308();
            func_0207F394(c->f4, k, c->f8);
            func_0207F428();
            break;
        case 6:
            func_0207F308();
            func_0207F394(c->f4, 0x4000, c->f8);
            func_0207F428();
            break;
        case 7:
            func_0207F308();
            func_0207F394(c->f4, 0x6000, c->f8);
            func_0207F428();
            break;
        case 8:
            func_0207F5B0();
            func_0207F5C8(c->f4, 0, c->f8);
            func_0207F65C();
            break;
        case 9:
            func_0207F5B0();
            func_0207F5C8(c->f4, k, c->f8);
            func_0207F65C();
            break;
        case 10:
            func_0207F5B0();
            func_0207F5C8(c->f4, 0x4000, c->f8);
            func_0207F65C();
            break;
        case 11:
            func_0207F5B0();
            func_0207F5C8(c->f4, 0x6000, c->f8);
            func_0207F65C();
            break;
        case 12:
            func_0207F47C();
            func_0207F4C4(c->f4, 0, c->f8);
            func_0207F560();
            break;
        case 13:
            func_0207F6A8();
            func_0207F6C0(c->f4, 0, c->f8);
            func_0207F754();
            break;
        }
    }

    p->b_lo = p->a_big;
    if (p->b_lo == 0) {
        p->a_mode = 0;
    }
}
