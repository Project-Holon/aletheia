/*
 * function: func_021731C8
 * address:  0x021731C8
 * packet:   pkt_ov011_021731C8
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 2026-10-05 (D8 lane19): re-verified, MATCH; unresolved relocations are arm9 0x02026680 and ov010 0x02161F68 (leaf witnesses in the note). Needs label seeds. Source is byte-correct; no C change possible.
 *
 * Byte-correct (416/416), 29 of 31 relocations resolved. The two
 * unresolved sites are leaves whose only caller image-wide is this
 * function (tu --suggest-split: not cuttable):
 *   +0076 func_02161F68 (ov010, unlabelled 12-byte memset stub)
 *   +0168 func_02026680 (arm9, unlabelled; Ilias's)
 * Because an arm9 leaf is among the blockers, the ov010 leaf is not filed.
 * Levers from the DIFF note (wave 82): the `b` to the next instruction at
 * +0x136 is the shared func_02012B4C(h, 1) call written in both arms of the
 * func_02012B70(h) == 0 test (cross-jumped, see
 * docs/idioms/an-if-else-storing-to-one-target-keeps-the-empty-else-branch-to-next.md);
 * the register permutation disappeared once every callee took its matched
 * prototype (h a u32 cast at each call, me a u8, o a void ** parameter).
 *
 * blocker:
 *   0x02026680 arm9 thumb, verified EXACT with
 *     `one --thumb --lang c99` (no --region):
 *     typedef unsigned char u8;
 *     typedef struct { u8 b0 : 1; u8 rest : 7; u8 pad[0xb]; } E;
 *     void func_02026680(u8 *p)
 *     {
 *         int i;
 *         for (i = 0; i < 6; i++) {
 *             ((E *)(p + 0x3f))[i].b0 = 0;
 *         }
 *         p[0x85] = 0;
 *         p[0x84] = 0;
 *     }
 *   0x02161F68 ov010 thumb (overlay leaf, not filed while the arm9 leaf
 *     blocks), verified EXACT with `one --thumb --region ov010 --lang c99`:
 *     symbols: func_02082BCC 0x02082BCC arm
 *     extern void func_02082BCC(void *p, u32 v, u32 n);
 *     void func_02161F68(void *p) { func_02082BCC(p, 0, 0x48); }
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_02012B70  0x02012B70  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02012114  0x02012114  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02161F68  0x02161F68  thumb  ov010
 *   func_0201281C  0x0201281C  thumb
 *   func_0216754C  0x0216754C  thumb  ov010
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02175DA8  0x02175DA8  thumb  ov011
 *   func_02175E90  0x02175E90  thumb  ov011
 *   func_02175BCC  0x02175BCC  thumb  ov011
 *   func_02012B58  0x02012B58  thumb
 *   func_02026480  0x02026480  thumb
 *   func_02012B64  0x02012B64  thumb
 *   func_02012B8C  0x02012B8C  thumb
 *   func_02012B4C  0x02012B4C  thumb
 *   func_02012124  0x02012124  thumb
 *   func_02026680  0x02026680  thumb
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Bits;

struct Ctx;
struct BigObj;
struct SaveBlock;
struct Rec44;
struct O;
struct U16Vec;

extern u32 func_02026478(void *obj);
extern u8 func_02012E40(const u8 *o);
extern int func_0203CDBC(void);
extern int func_02012B70(const struct BigObj *p);
extern void func_0200FBA0(void);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern u32 func_02013D5C(u32 id);
extern u32 func_02012114(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188BE8(void *a);
extern void func_02161F68(void *p);
extern void func_0201281C(u8 *obj);
extern void func_0216754C(int a, struct O *o);
extern u32 func_0200FB24(void);
extern int func_02175DA8(u8 *p);
extern int func_02175E90(void *p, u8 *q);
extern u8 *func_02175BCC(u8 *p);
extern u8 func_02012B58(const struct BigObj *p);
extern void func_02026480(void *obj, u32 value);
extern void func_02012B64(struct BigObj *p, u8 v);
extern void func_02012B8C(struct BigObj *p, u32 v);
extern void func_02012B4C(struct BigObj *p, u8 v);
extern void func_02012124(struct Ctx *p, u32 v);
extern void func_02026680(u8 *p);
extern void func_02045808(struct U16Vec *vec);
extern void func_020307B0(void *p);

int func_021731C8(int a0, void **o, u8 *s)
{
    void *ctx;
    int ok;
    u32 h;
    u8 *pt;
    u8 me;
    int i;

    ctx = o[1];
    h = func_02026478(ctx);
    ok = 0;
    if (func_02012E40((const u8 *)h) == 1) {
        return ok;
    }
    if (s[0x8fd] == 10 || func_0203CDBC() == 1) {
        if (func_02012B70((struct BigObj *)h) == 0) {
            func_0200FBA0();
            ok = 1;
        } else if (func_02013D5C(func_02012AC8(func_020127A4((struct SaveBlock *)h))) == 1
                   && func_02012114(o[0]) == 1
                   && func_02188BE8(func_0201210C(o[0])) == 1) {
            ok = 1;
        }
    }
    if (ok == 1) {
        func_02161F68(s + 0x35c);
        func_0201281C((u8 *)h);
        func_0216754C((int)o[0], *(struct O **)(s + 8));
        if (((Bits *)(s + 0x93f))->b1 == 1 || func_0200FB24() != 0) {
            func_02026480(ctx, 5);
        } else if (func_02175DA8(s + 0x1ac) == 1) {
            if (((Bits *)(s + 0x904))->b0 == 1) {
                func_02026480(ctx, 4);
            } else if (func_02175E90(s, s + 0x1ac) == 1) {
                func_02026480(ctx, 2);
            } else {
                pt = func_02175BCC(s + 0x1ac);
                me = func_02012B58((struct BigObj *)h);
                for (i = 0; i < 3; i++) {
                    if (pt[0x34 + i] != 4 && me != pt[0x34 + i]) {
                        break;
                    }
                }
                if (i < 3) {
                    func_02026480(ctx, 3);
                } else {
                    func_02026480(ctx, 4);
                }
            }
        } else if (s[0x8fb] > 1) {
            func_02026480(ctx, 1);
        }
        if (func_02012B70((struct BigObj *)h) == 0) {
            func_02012B64((struct BigObj *)h, 0);
            func_02012B8C((struct BigObj *)h, 0);
            func_02012B4C((struct BigObj *)h, 1);
        } else {
            func_02012B4C((struct BigObj *)h, 1);
        }
        if ((((Bits *)(s + 0x93f))->b1 == 1 || func_0200FB24() != 0) && func_02012B70((struct BigObj *)h) == 1) {
            func_02012124(o[0], 1);
        }
        func_02026680(ctx);
        for (i = 0; i < 2; i++) {
            func_02045808(*(struct U16Vec **)(s + 0x928 + i * 4));
        }
        func_020307B0(s);
        func_020307B0(o);
        return 1;
    }
    return 0;
}
