/*
 * function: func_02183D14
 * address:  0x02183D14
 * packet:   pkt_ov219_02183D14
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note:     2026-10-04 wave D3 lane 04: complete draft, same size (1884 bytes). The
 *           remaining residue is cross-jump (tail merge) direction only. In the original
 *           every "*state = X; SE(0x54C); break" tail (case 4 arms, case 9, case 17) jumps
 *           into the case 12 copy at 0x218400C, and the 0x551 tails jump into the case 9
 *           copy at 0x2183F8E. Natural C keeps the FIRST copy (case 4) instead. The draft
 *           uses gotos (n = X; goto snd54c / snd551) in case 4, which fixes case 4, but the
 *           case 9 0x54C tail still stays a full copy (case 12 then jumps to it); a goto in
 *           case 9 too lets the compiler thread the 0xA arm past the hop at 0x2183F8A.
 *           Tried: inner switch arm orders (case 0/default first, last, split), case 9 with
 *           SE in each arm, reversed outer case order (layout follows source, worse).
 *           Found and fixed: switch value u32 (compare tree, 0xFFFFFFFE case), switch on
 *           func_0201FEBC result cast to u32 in cases 6 and 15, case 19 written before
 *           case 18 (original block order), stack locals ids, count, tmp, old (int).
 *           d_02185xxx data words are sole references (MATCH at best once bytes agree).
 *           2026-10-05 wave D4 lane 08: still DIFF (84 lines, the draft above is unchanged). The original keeps
 *           ONE copy of `str r0,[r5]; ldr =0x54C; bl SE; b end` in case 12 (0x218400C) and every other 0x54C, 0x551,
 *           0x648, 0x649 tail jumps into it (case 17 to 0x218400E, 0x648/0x649 and case 9's 0x551 to the bl at
 *           0x2184010); case 9's arms join at a hop (0x2183F8A b 0x218400C), so case 9 had its own copy at threading
 *           time and lost it to cross-jumping later. Tried: case 9 arms `*state = X; goto se54c` (per arm, or one goto
 *           after the if) with a label on the SE call in case 12: case 12's label block then merges into case 17's
 *           copy instead (530 lines, worse). The survivor rule seems to drop the multi-predecessor label block.
 *
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   func_0203630C 0x0203630C arm
 *   func_02035BA4 0x02035BA4 arm
 *   func_02035CB8 0x02035CB8 arm
 *   func_02035C60 0x02035C60 arm
 *   func_02035D20 0x02035D20 arm
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02040588 0x02040588 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045770 0x02045770 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020200CC 0x020200CC thumb
 *   func_0201FDA0 0x0201FDA0 thumb
 *   func_0201FEBC 0x0201FEBC thumb
 *   func_02025BE8 0x02025BE8 thumb
 *   func_02025C44 0x02025C44 thumb
 *   func_02025B94 0x02025B94 thumb
 *   func_0200947C 0x0200947C thumb
 *   func_02027120 0x02027120 thumb
 *   func_02028230 0x02028230 thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_02183CBC 0x02183CBC thumb ov219
 *   func_02184734 0x02184734 thumb ov219
 *   func_02184798 0x02184798 thumb ov219
 *   func_021849A4 0x021849A4 thumb ov219
 *   func_02184C2C 0x02184C2C thumb ov219
 *   func_02184C8C 0x02184C8C thumb ov219
 *   func_02184CB0 0x02184CB0 thumb ov219
 *   func_02184D70 0x02184D70 thumb ov219
 *   func_02184EC0 0x02184EC0 thumb ov219
 *   func_02185074 0x02185074 thumb ov219
 *   func_021850EC 0x021850EC thumb ov219
 *   func_0218516C 0x0218516C thumb ov219
 *   func_0218519C 0x0218519C thumb ov219
 *   func_02185254 0x02185254 thumb ov219
 *   func_02185310 0x02185310 thumb ov219
 *   func_0218532C 0x0218532C thumb ov219
 *   func_0218544C 0x0218544C thumb ov219
 *   func_02185580 0x02185580 thumb ov219
 *   func_0218562C 0x0218562C thumb ov219
 *   func_021856CC 0x021856CC thumb ov219
 *   func_02185794 0x02185794 thumb ov219
 *   func_02185934 0x02185934 thumb ov219
 *   func_02185AC8 0x02185AC8 thumb ov219
 *   func_02185CF4 0x02185CF4 thumb ov219
 *   d_02185DE6 0x02185DE6 data ov219 a1
 *   d_02185DB6 0x02185DB6 data ov219 a1
 *   d_02185E98 0x02185E98 data ov219 a4
 *   d_02185E28 0x02185E28 data ov219 a4
 *   d_02185DB0 0x02185DB0 data ov219 a1
 *   d_02185DC4 0x02185DC4 data ov219 a1
 *   d_02185ECC 0x02185ECC data ov219 a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Src;
struct Descriptor;
struct CharBuf;

extern u32 func_020362DC(void);
extern u32 func_0203630C(void);
extern int func_02035BA4(const void *a);
extern int func_02035CB8(void *a, void *b);
extern int func_02035C60(void);
extern int func_02035D20(void *a, void *b);
extern void *func_02045B38(u32, u32, u16, u16);
extern void *func_020490F4(u32, u16);
extern void func_02049238(void *);
extern void func_02040588(unsigned, unsigned);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_02045334(struct Descriptor *);
extern void *func_02045770(struct Descriptor *);
extern void func_02045C04(void *);
extern void func_0202208C(int a, int b, int c, int d, int e, int f, u32 heap);
extern int func_020221A4(void);
extern int func_0201C6B4(void *a);
extern int func_0201C6C4(void *a, void *b);
extern int func_020200CC(void *a);
extern void *func_0201FDA0(const void *a, int b, int c, int d, u16 heap);
extern int func_0201FEBC(void *a);
extern void *func_02025BE8(void);
extern void func_02025C44(void *a, u8 **b, u32 *c);
extern u32 func_02025B94(void *a);
extern void func_0200947C(u32 a, u32 b, u32 c, u32 d);
extern void func_02027120(u8 a, u8 b);
extern int func_02028230(void *a);
extern void func_020061E4(u32 a);
extern void func_02183CBC(u8 *p, u32 i);
extern void func_02184734(u8 *p);
extern void func_02184798(u8 *p);
extern void func_021849A4(u8 *p, void *arc);
extern void func_02184C2C(u8 *p, int i);
extern void func_02184C8C(u8 *p, u32 i);
extern void func_02184CB0(u8 *p);
extern int func_02184D70(u8 *p, u32 message, int force);
extern void func_02184EC0(u8 *p, const u8 *d, const struct Src *s, const void *e);
extern void func_02185074(u8 *p, const u8 *a, u32 b, u32 c);
extern void func_021850EC(u8 *p, const u8 *d, const struct Src *cfg, unsigned file, const u8 *ids, unsigned count);
extern void func_0218516C(u8 *p);
extern void func_0218519C(u8 *p);
extern void func_02185254(u8 *p, unsigned key, unsigned member);
extern void func_02185310(u8 *p);
extern int func_0218532C(u8 *p, u32 *out);
extern void func_0218544C(u8 *p);
extern void func_02185580(u8 *p, void *arc);
extern void func_0218562C(u8 *p);
extern void func_021856CC(u8 *p);
extern void func_02185794(u8 *p);
extern int func_02185934(u8 *p, u32 key, u32 b);
extern int func_02185AC8(u8 *p);
extern int func_02185CF4(int i);

extern const u8 d_02185DE6[];
extern const u8 d_02185DB6[];
extern const struct Src d_02185E98;
extern const u8 d_02185E28[];
extern const u8 d_02185DB0[];
extern const u8 d_02185DC4[];
extern const u8 d_02185ECC[];

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))
#define B(o) (*(u8 *)(p + (o)))

static inline void close_win(u8 *p, int d, int f)
{
    void *win = *(void **)(p + 0xC080);
    if (B(f) != 0 && func_0201C6C4(win, func_02045770(*(struct Descriptor **)(p + d))) == 0) {
        func_02045334(*(struct Descriptor **)(p + d));
        B(f) = 0;
    }
}

int func_02183D14(u8 *p, int *state)
{
    int ret = 0;
    int n;
    void *arc;
    u32 r;
    u8 *ids;
    u32 count;
    u32 tmp;
    int old;
    u32 v;
    u32 w;

    W(0xC354) = func_020362DC();
    W(0xC358) = func_0203630C();
    if (func_02035BA4(d_02185DE6) != -1) {
        W(0xC360) = func_02035CB8(p + 0xC364, p + 0xC368);
    } else {
        W(0xC360) = 0;
    }
    if (W(0xC360) == 1) {
        W(0xC35C) = func_02035C60();
    } else {
        W(0xC35C) = func_02035D20(p + 0xC364, p + 0xC368);
    }
    switch (*state) {
    case 0:
        *(void **)(p + 0xC070) = func_02045B38(0, 2, 0xCF, W(0));
        arc = func_020490F4(0xC5, W(0));
        func_02185580(p, arc);
        func_021849A4(p, arc);
        func_02049238(arc);
        W(0xC314) = 0;
        func_0202208C(0, 1, 1, 0, 6, 1, W(0));
        func_02040588(6, 1);
        func_02040588(2, 1);
        func_02040588(7, 1);
        func_02040588(3, 1);
        *state = 1;
        break;
    case 1:
        if (func_020221A4() == 1) {
            *state = 2;
        }
        break;
    case 2:
        if (func_02184D70(p, 0, 1) == 1) {
            if (W(0xC33C) == 0) {
                *state = 3;
            } else {
                *state = 0x10;
            }
        }
        break;
    case 3:
        if (func_02184D70(p, 1, 1) == 1) {
            func_02184EC0(p, d_02185DB6, &d_02185E98, d_02185E28);
            *state = 4;
        }
        break;
    case 4:
        if (func_0201C6B4(*(void **)(p + 0xC080)) == 0) {
            break;
        }
        r = func_020200CC(*(void **)(p + 0xC04C));
        if (r == -1) {
            break;
        }
        func_0218516C(p);
        switch (r) {
        case 0:
        default:
            n = 0x10;
            goto snd54c;
        case 1:
            n = 5;
            goto snd54c;
        case 2:
        case 0xFFFFFFFE:
            n = 0x14;
            goto snd551;
        }
        break;
    case 5:
        if (func_02184D70(p, 2, 1) == 1) {
            *(void **)(p + 0xC054) = func_0201FDA0(d_02185DB0, 0x22, 7, 0, W(0));
            *state = 6;
        }
        break;
    case 6:
        switch ((u32)func_0201FEBC(*(void **)(p + 0xC054))) {
        case 0:
            if (W(0xC318) == 1) {
                *(void **)(p + 0xC344) = func_02025BE8();
                *state = 0xA;
            } else {
                *state = 7;
            }
            break;
        case 0xFFFFFFFE:
            *state = 3;
            break;
        }
        break;
    case 7:
        W(0xC344) = 0;
        func_02185074(p, d_02185DC4, (u32)d_02185ECC, 0xE7);
        *state = 8;
        break;
    case 8:
        if (func_02184D70(p, 3, 1) == 1) {
            *state = 9;
        }
        break;
    case 9:
        if (func_0201C6B4(*(void **)(p + 0xC080)) == 0) {
            break;
        }
        r = func_020200CC(*(void **)(p + 0xC04C));
        if (r == -1) {
            break;
        }
        func_0218516C(p);
        if (r != -2) {
            W(0xC344) = r;
            if (func_02185CF4(r) == 1) {
                *state = 0xA;
            } else {
                W(0xC348) = 0;
                *state = 0xD;
            }
            func_020061E4(0x54C);
        } else {
            n = 3;
        snd551:
            *state = n;
            func_020061E4(0x551);
        }
        break;
    case 10:
        W(0xC348) = 0;
        func_02025C44(*(void **)(p + 0xC344), &ids, &count);
        func_021850EC(p, d_02185DC4, (const struct Src *)d_02185ECC, func_02025B94(*(void **)(p + 0xC344)), ids, count);
        *state = 0xB;
        break;
    case 11:
        if (func_02184D70(p, 4, 1) == 1) {
            *state = 0xC;
        }
        break;
    case 12:
        if (func_0201C6B4(*(void **)(p + 0xC080)) == 0) {
            break;
        }
        r = func_020200CC(*(void **)(p + 0xC04C));
        if (r == -1) {
            break;
        }
        func_0218516C(p);
        if (r != -2) {
            W(0xC348) = r;
            n = 0xD;
        snd54c:
            *state = n;
            func_020061E4(0x54C);
        } else {
            func_020061E4(0x551);
            if (W(0xC318) == 1) {
                *state = 3;
            } else {
                *state = 7;
            }
        }
        break;
    case 13:
        func_02185254(p, W(0xC344), W(0xC348));
        *state = 0xE;
        break;
    case 14:
        if (func_02184D70(p, 5, 1) == 1) {
            *(void **)(p + 0xC054) = func_0201FDA0(d_02185DB0, 0x22, 7, 0, W(0));
            *state = 0xF;
        }
        break;
    case 15:
        switch ((u32)func_0201FEBC(*(void **)(p + 0xC054))) {
        case 0:
            func_02185310(p);
            func_0200947C(W(0x10), W(0xC), W(0xC344), W(0xC348));
            func_02027120(W(0xC344), W(0xC348));
            W(0xC33C) = W(0xC344);
            W(0xC340) = W(0xC348);
            *state = 0x10;
            break;
        case 0xFFFFFFFE:
            func_02185310(p);
            *state = 3;
            break;
        }
        break;
    case 16:
        if (W(0xC318) == 1 && W(0xC34C) == 0) {
            H(0xC31C) = 0;
        } else {
            H(0xC31C) = 1;
        }
        func_021856CC(p);
        func_02184734(p);
        func_02185794(p);
        func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0xC01C)), 0xF);
        func_02045334(*(struct Descriptor **)(p + 0xC01C));
        func_02184C2C(p, 1);
        if (W(0xC33C) != 0) {
            func_0218519C(p);
        }
        func_0218544C(p);
        W(0xC350) = 0;
        W(0xC310) = 1;
        *state = 0x11;
        break;
    case 17:
        old = H(0xC30C);
        if (func_0201C6B4(*(void **)(p + 0xC080)) == 0) {
            break;
        }
        func_02184798(p);
        if (func_0218532C(p, &tmp)) {
            func_02184C2C(p, 0);
        } else {
            func_02184C8C(p, 0);
        }
        v = W(0xC354);
        if ((v & 2) || ((w = W(0xC320)) & 2)) {
            func_02184C8C(p, 0);
            func_02183CBC(p, 1);
            func_020061E4(0x551);
            func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0xC01C)), 0xF);
            func_02045334(*(struct Descriptor **)(p + 0xC01C));
            *state = 0x13;
            break;
        }
        if (((v & 0x400) || (w & 0x400)) && W(0xC33C) == 0) {
            W(0xC33C) = 1;
            func_02183CBC(p, 0);
            func_0218544C(p);
            if (W(0xC33C) == 1) {
                func_020061E4(0x54C);
            }
            break;
        }
        if (((v & 0x403) || (w & 0x400)) && W(0xC33C) == 1) {
            W(0xC33C) = 0;
            func_0218544C(p);
            break;
        }
        if (func_02185934(p, v, W(0xC358)) == 1 && W(0xC350) == 1) {
            W(0xC350) = 0;
            func_0218544C(p);
        }
        if (old != H(0xC30C)) {
            *state = 0x12;
            if (H(0xC30C) == 0) {
                func_020061E4(0x649);
            } else {
                func_020061E4(0x648);
            }
        }
        break;
    case 19:
        if (func_02028230(*(void **)(p + 0xC060)) == 0) {
            break;
        }
        if (W(0xC33C) == 0) {
            W(0xC310) = 2;
            *state = 3;
        } else {
            func_02185310(p);
            *state = 0x14;
        }
        func_02184C8C(p, 1);
        break;
    case 18:
        if (func_02185AC8(p) == 1) {
            *state = 0x11;
        }
        break;
    case 20:
        W(0xC314) = 0;
        func_0202208C(0, 0, 0, 0, 6, 1, W(0));
        *state = 0x15;
        break;
    case 21:
        if (func_020221A4() == 1) {
            ret = 1;
            W(0xC310) = 1;
            func_02184CB0(p);
            func_0218562C(p);
            func_02045C04(*(void **)(p + 0xC070));
            *state = 0;
        }
        break;
    }
    close_win(p, 0xC078, 0xC07C);
    close_win(p, 0xC044, 0xC048);
    close_win(p, 0xC038, 0xC03C);
    close_win(p, 0xC02C, 0xC030);
    close_win(p, 0xC020, 0xC024);
    return ret;
}
