/*
 * function: func_021CE4D0
 * address: 0x021CE4D0
 * packet: pkt_ov093_021CE4D0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note 2026-10-05 (wave P26 lane 2): byte-identical to the original except that two call
 * relocations have no witness in the current index: func_021E979C and func_021E9954. Both
 * leaves are now filed (src/matched/ov/ov093_func_021E979C.c, ov093_func_021E9954.c, EXACT);
 * the verdict becomes EXACT once the integrator regenerates the index. The original extent is
 * 772 B: 756 B of C plus the 16 B linker veneer at 021CE7C4 (not C, resolved as a veneer witness).
 * Two changes closed the 253 B residue of the older draft: (1) no shared increment label and
 * no goto: each arm writes ++*st; break; so the compiler builds the single shared state store
 * and one epilogue (756 to 748 B, branch layout); (2) the countdown loop reads the index byte
 * through a struct field (struct L at 0x11D and 0x1A6) instead of a count pointer local, so
 * mwcc hoists three separate address computations (count pointer in r5, a copy in r6, a
 * stack copy for the loop test) as in the original.
 * Not tried again from the older note: unsigned-long state pointer, full-word countdown.
 * symbols:
 *   func_021B990C 0x021B990C thumb ov093
 *   func_021D8434 0x021D8434 thumb ov093
 *   func_021CF470 0x021CF470 thumb ov093
 *   func_021CE150 0x021CE150 thumb ov093
 *   func_021CE8F0 0x021CE8F0 thumb ov093
 *   func_021CE0F8 0x021CE0F8 thumb ov093
 *   func_021EA65C 0x021EA65C thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_021E9760 0x021E9760 thumb ov093
 *   func_021CE0BC 0x021CE0BC thumb ov093
 *   func_021E979C 0x021E979C thumb ov093
 *   func_021E97A4 0x021E97A4 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021E9964 0x021E9964 thumb ov093
 *   func_021CF430 0x021CF430 thumb ov093
 *   func_021BA1EC 0x021BA1EC thumb ov093
 *   func_021B86E4 0x021B86E4 thumb ov093
 *   func_021CF43C 0x021CF43C thumb ov093
 *   func_021D8454 0x021D8454 thumb ov093
 *   func_021CE7C4 0x021CE7C4 thumb ov093
 *   func_021CF3B8 0x021CF3B8 thumb ov093
 *   func_021E9974 0x021E9974 thumb ov093
 *   func_021E9954 0x021E9954 thumb ov093
 *   func_021EAF18 0x021EAF18 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021EAF50 0x021EAF50 thumb ov093
 *   func_021CE3B4 0x021CE3B4 thumb ov093
 *   func_021CF220 0x021CF220 thumb ov093
 *   func_021CE7D4 0x021CE7D4 thumb ov093
 *   func_021CE3C8 0x021CE3C8 thumb ov093
 *   func_021CEDC0 0x021CEDC0 thumb ov093
 *   func_021CEA94 0x021CEA94 thumb ov093
 *   func_021CEEB8 0x021CEEB8 thumb ov093
 *   func_021CF078 0x021CF078 thumb ov093
 * proof: full unsigned state dispatch <=8; byte selectors0..255; countdown assigned before reads; byte/state additions wrap at their original widths; fixed veneer is omitted from C.
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct H;
struct L;
struct Unk021D62A8;
extern void *func_021B990C(char *p, unsigned int i, unsigned int j);
extern void func_021D8434(u32 *p);
extern u32 func_021CF470(u8 *, void *, u8 *);
extern void func_021CE150(u8 *p, void *q);
typedef unsigned short u16;
extern u32 func_021CE8F0(const u8 *p, u16 *out);
extern void func_021CE0F8(u8 *, u8 *, u8 *);
extern void func_021EA65C(char *p, struct H *h);
extern int func_021EA710(u32 *p);
extern void func_021E9760(char *, u8 *, int, int);
extern int func_021CE0BC(u8 *p, void *q);
extern void func_021E979C(char *p);
extern int func_021E97A4(char *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021E9964(u32);
extern void func_021CF430(u8 *, u32, u32);
extern int func_021BA1EC(char **p);
extern int func_021B86E4(unsigned int **p);
extern u8 func_021CF43C(u8 *, u32);
extern u32 func_021D8454(u32 *);
extern void func_021CE7C4(u8 *);
extern void func_021CF3B8(u8 *, u32);
extern int func_021E9974(u32);
extern void func_021E9954(void *);
extern void func_021EAF18(struct L *p, int kind, int id);
extern u8 func_021D5440(u8 *p);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021CE3B4(u8 *p, void *q);
extern u32 func_021CF220(u8 *p, int *st);
extern u32 func_021CE7D4(u8 *p, int *st);
extern int func_021CE3C8(u8 *p, int *state);
extern u32 func_021CEDC0(u8 *p, int *st);
extern int func_021CEA94(u8 *p, u32 *state);
extern u32 func_021CEEB8(u8 *p, int *st);
extern u32 func_021CF078(u8 *p, u32 *st);
struct L { u8 pad[0x11D]; u8 idx; u8 pad2[0x1A6-0x11E]; u8 sel; };
#define Q ((struct L *)p)
#define W(o) (*(u32 *)(p+(o)))
#define P(o) (*(void **)(p+(o)))
int func_021CE4D0(u8 *p, u32 *st)
{
    u32 result;
    switch (*st) {
    case 0:
        P(8) = func_021B990C(P(4), p[0x1A6], p[0x11D]);
        P(12) = p + 0x124 + p[0x11D] * 4;
        p[0x1AF] = 0;
        func_021D8434(P(12));
        if (func_021CF470(p, P(8), P(12))) {
            func_021CE150(p, (void *)((u32)func_021CF220));
            break;
        }
        if (func_021CE8F0(p, (unsigned short *)(p + 0x19E)) == 1) {
            func_021CE150(p, (void *)((u32)func_021CE7D4));
            break;
        }
        ++*st; break;
    case 1:
        if (*(signed char *)(p + 0x11E) != p[0x11D] || p[0x120]) {
            func_021CE0F8(p, P(8), p + 0x58);
            func_021EA65C(P(0x54), (struct H *)(p + 0x58));
            p[0x120] = 0;
            p[0x11E] = p[0x11D];
            ++*st; break;
        }
        *st += 2U;
        break;
    case 2:
        if (!func_021EA710(P(0x54))) return 0;
        ++*st;
        /* falls through */
    case 3:
        func_021E9760(P(0x54), P(8), p[0x11D] > p[0x11F], (int)P(12));
        ++*st; break;
    case 4:
        if (func_021CE0BC(p, (void *)((u32)func_021CE3C8))) {
            func_021E979C(P(0x54));
            return 0;
        }
        result = func_021E97A4(P(0x54));
        switch (result) {
        case 3:
            if (func_021D62C4(P(8), 0x21)) {
                func_021E9964(W(0x54));
                *st = 6;
            } else {
                func_021CF430(p, p[0x11D], 0);
                func_021CE150(p, (void *)((u32)func_021CEDC0));
            }
            break;
        case 1:
            func_021CF430(p, p[0x11D], 0);
            func_021CE150(p, (void *)((u32)func_021CEA94));
            break;
        case 2:
            if (func_021D62C4(P(8), 0x21)) *st = 6;
            else if (p[0x1AA] == 1 && !func_021BA1EC(P(0))) {
                func_021E9964(W(0x54));
                *st = 5;
            } else func_021CE150(p, (void *)((u32)func_021CEEB8));
            break;
        case 4:
            if (p[0x11D] == p[0x11F]) {
                if (func_021D62C4(P(8), 0x21) && func_021B86E4(P(0)) != 2) *st = 6;
                else {
                    func_021CF430(p, p[0x11D], 0);
                    func_021CE150(p, (void *)((u32)func_021CF078));
                }
                break;
            }
            if (p[0x11D] == 0) break;
            do {
                --Q->idx;
                if (!func_021CF470(p, func_021B990C(P(4), Q->sel, Q->idx), 0)) {
                    p[0x1AB] += func_021CF43C(p, p[0x11D]);
                    if (func_021D8454((u32 *)(p + 0x124 + p[0x11D] * 4)) == 3)
                        func_021CE7C4(p + 0x190);
                    if (func_021D8454((u32 *)(p + 0x124 + p[0x11D] * 4)) == 2)
                        func_021CF3B8(p, p[0x11D]);
                    func_021CE150(p, (void *)((u32)func_021CE4D0));
                    return 0;
                }
            } while (Q->idx != 0);
            break;
        }
        break;
    case 5:
        if (func_021E9974(W(0x54))) *st = 3;
        break;
    case 6:
        func_021E9954(P(0x54));
        ++*st; break;
    case 7:
        if (!func_021E9974(W(0x54))) break;
        func_021EAF18((struct L *)(p + 0x58), 1, 0xC5);
        func_021EAF50((struct L *)(p + 0x58), func_021D5440(P(8)));
        func_021CE3B4(p, p + 0x58);
        ++*st; break;
    case 8:
        if (func_021EA710(P(0x54))) *st = 1;
        break;
    }
    return 0;
}
