/*
 * function: func_021B963C
 * address:  0x021B963C
 * packet:   pkt_ov227_021B963C
 * region:   ov227
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-04 (wave D1 lane 14): DIFF, 195 of 676 bytes differ. Structure is right
 * (5-state switch on *state, same frame 0x38, same callee order).
 * Open residue: (1) func_02031348 args 0xcf and 0xc2 are loaded from the literal
 * pool in the original (ldr r1,[pc]) but compile to movs; the value is probably an
 * extern symbol address or a wider-typed constant. (2) case 1 and case 2 early
 * `return 0` blocks sit after the switch in the original (beq to a late epilogue);
 * here they are inline. (3) g->f08 = fl ? 0 : 1 compiles with inverted branch
 * layout; fl=0 is stored sharing r1 with the literal 0 argument of func_0202F190
 * (hoisted here). Tried: break vs return, int/u32 for the compare (int is right),
 * ternary vs if for the 0xb0/0xb1 argument (ternary with != 0 ? 0xb1 : 0xb0).
 *
 * 2026-10-04 (wD2 lane04): residue (1) solved: the pool words 0xCF and 0xC2 are overlay ids; written
 * as `(u32)ov207_id` / `(u32)ov194_id` with `ov207_id 0x000000CF data` and `ov194_id 0x000000C2 data`
 * symbols lines (lever from wave D1). The original pool holds CF, 0220BAB0, C2, 021F5580 in that order
 * at 021B9894..021B98A0. The draft is now 608 bytes (original pool included, 676 listed). Residues (2) and (3)
 * above are unchanged: late shared `return 0` (original epilogue at 021B9888, `return 1` at 021B9882 for the
 * default arm) and the inverted fl branch layout.
 *
 * symbols:
 *   func_020074D8  0x020074D8  thumb
 *   func_02007698  0x02007698  thumb
 *   func_020076D0  0x020076D0  thumb
 *   func_02008500  0x02008500  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_0200CED4  0x0200CED4  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02013E4C  0x02013E4C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020185F0  0x020185F0  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_0201AA14  0x0201AA14  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0202F190  0x0202F190  thumb
 *   func_02031330  0x02031330  arm
 *   func_02031348  0x02031348  arm
 *   ov207_id  0x000000CF  data
 *   ov194_id  0x000000C2  data
 *   func_02045B38  0x02045B38  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_0216C0A4  0x0216C0A4  thumb  ov010
 *   func_0216C0C0  0x0216C0C0  thumb  ov010
 *   func_0216C0D4  0x0216C0D4  thumb  ov010
 *   func_0216C0E4  0x0216C0E4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0, f1, f2;
} Ctx;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u16 f30;
    u16 pad32;
    u32 f34;
} G;

extern u32 func_02031330(u32 a);
extern unsigned char ov207_id[];
extern unsigned char ov194_id[];
extern u32 func_02031348(u32 a, u32 b, u32 c, void *d);
extern u32 func_02012934(u32 a);
extern u32 func_02012944(u32 a);
extern u32 func_0200CA1C(u32 a);
extern u32 func_0201293C(u32 a);
extern u32 func_02012F2C(u32 a);
extern void func_02008DF0(u32 a, u32 b);
extern void func_02008500(u32 a, u32 b);
extern void func_02017E40(u32 a, u32 b, u32 c);
extern int func_0201AA18(u32 a);
extern int func_0201AA14(u32 a);
extern u32 func_02007698(u32 a);
extern void func_020076D0(u32 a, u32 *b, u32 *c);
extern u32 func_02045B38(u32 a, u32 b, u32 c, u32 d);
extern u32 func_0201296C(u32 a);
extern u32 func_020142E8(u32 a, u32 b);
extern u32 func_02045EC0(u32 a, u32 b);
extern void func_02045C04(u32 a);
extern u32 func_020127A4(u32 a);
extern u32 func_02012AC8(u32 a);
extern u32 func_02013E4C(u32 a);
extern void func_0202F190(u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_0200CA38(u32 a);
extern u32 func_02017E1C(u32 a, u32 b, u32 c);
extern u32 func_0200CED4(u32 a, u32 b);
extern void func_0200CFA0(u32 a, u32 b);
extern void func_0200CDE0(u32 a, u32 b);
extern u32 func_02012EBC(u32 a);
extern u32 func_0200C0F0(u32 a);
extern u32 func_0216C0A4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern u32 func_0216C0E4(u32 a);
extern void func_0216C0D4(u32 a, u32 b);
extern void func_0216C0C0(u32 a);
extern void func_0201A98C(u32 a, u32 b);
extern u32 func_020185F0(u32 a);
extern void func_020074D8(u32 a, u32 b);

u32 func_021B963C(u32 a0, u32 *state, Ctx *c, G *g)
{
    u32 r, x30, x20, x24, x1c, x28, x18, h, r7;
    int x2c, fl;

    r = func_02031330(g->f34);
    if (r == 1) {
        return 0;
    }
    switch (*state) {
    case 0:
        x24 = func_02012934(c->f0);
        x20 = func_02012944(c->f0);
        r7 = func_0200CA1C(c->f0);
        x1c = func_0201293C(c->f0);
        if (c->f1 == 1) {
            x28 = func_02012F2C(c->f0);
            func_02008DF0(x28, 7);
            func_02008DF0(x28, 0x54);
            func_02008500(x20, g->f04);
            func_02017E40(c->f2, 0x8d, g->f04);
            x2c = func_0201AA18(x24);
            if (x2c >= func_0201AA14(x24)) {
                u32 a, b;
                a = func_02007698(x1c);
                b = 0;
                func_020076D0(x1c, &a, &b);
                g->f2c = a;
                h = func_02045B38(0, 2, 0xea, 0x8b);
                g->f28 = func_02045EC0(h, func_020142E8(func_0201296C(c->f0), 0x96d) != 0 ? 0xb1 : 0xb0);
                func_02045C04(h);
            }
            x30 = func_02013E4C(func_02012AC8(func_020127A4(c->f0)));
            func_0202F190(c->f2, (fl = 0), x20, x30, g->f30);
            x18 = func_0200CA38(r7);
            if (func_0200CED4(r7, (u16)func_02017E1C(c->f2, 5, 0)) == 0) {
                fl = 1;
            }
            func_0200CFA0(r7, c->f2);
            func_0200CDE0(r7, c->f2);
            g->f0c = c->f2;
            g->f10 = x18;
            g->f14 = g->f28;
            g->f18 = x1c;
            g->f1c = g->f2c;
            g->f20 = c->f0;
            g->f08 = (fl == 0) ? 1 : 0;
            func_02031348(g->f34, (u32)ov207_id, 0x0220BAB0, &g->f08);
            (*state)++;
            break;
        }
        if (c->f1 == 2) {
            func_0200CFA0(r7, c->f2);
        }
        *state = 4;
        break;
    case 1:
        if (r == 1) {
            return 0;
        }
        r7 = func_0201293C(c->f0);
        if (g->f24 == 1) {
            g->f00 = func_0216C0A4(g->f30, c->f2, 0xa, 0, g->f28, r7, g->f2c, func_0200C0F0(func_02012EBC(c->f0)));
            func_02031348(g->f34, (u32)ov194_id, 0x021F5580, (void *)g->f00);
            (*state)++;
            break;
        }
        *state = 3;
        break;
    case 2:
        if (r == 1) {
            return 0;
        }
        if (func_0216C0E4(g->f00) == 0) {
            func_0216C0D4(g->f00, g->f04);
            func_02017E40(c->f2, 0x73, g->f04);
            func_02008DF0(func_02012F2C(c->f0), 0x1e);
        }
        func_0216C0C0(g->f00);
        g->f00 = 0;
        (*state)++;
        break;
    case 3:
        x24 = func_02012934(c->f0);
        if (g->f28 == 0) {
            func_0201A98C(x24, c->f2);
        } else {
            r7 = func_0201293C(c->f0);
            func_020074D8(r7, func_020185F0(c->f2));
        }
        (*state)++;
        break;
    case 4:
    default:
        return 1;
    }
    return 0;
}
