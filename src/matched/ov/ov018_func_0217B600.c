/*
 * function: func_0217B600
 * address:  0x0217B600
 * packet:   pkt_ov018_0217B600
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct (528 of 528 bytes).  Sole blocker: the THM_CALL at +0x13C to
 * 0x02012798, an unlabelled arm9 leaf that disasm.py prints as .word data in
 * pool_02012794 (asm/arm9/main.s), after the pop at 0x02012790 and before
 * func_020127A4; no listing labels it and this call is its only witness, so
 * every class refuses it.  Verified EXACT at 0x02012798 (arm9, thumb, 10 B):
 *
 *     u8 *func_02012798(u8 *p, int i) { return p + 4 + i * 0x44; }
 *
 * It is the Rec44 indexer that belongs beside func_02012950 in
 * src/matched/arm9/unit_02012924.c; once it is labelled or matched this file
 * should verify EXACT unchanged.  The 12-byte scratch is a cast u8 buffer
 * (docs/idioms/a-declared-struct-local-folds-to-sp-relative-a-cast-buffer-does-not.md):
 * the stores go through r7, which a declared struct folds to sp.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012798  0x02012798  thumb
 *   func_02012A90  0x02012A90  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0217C658  0x0217C658  thumb
 *   func_0217C688  0x0217C688  thumb
 *   func_02185214  0x02185214  thumb
 *   func_02188BE8  0x02188BE8  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_021907A8  0x021907A8  thumb  ov021
 *   func_02190740  0x02190740  thumb  ov021
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_021909BC  0x021909BC  thumb
 *   func_02190BE4  0x02190BE4  thumb
 *   func_02190C78  0x02190C78  thumb
 *   func_02190E40  0x02190E40  thumb
 *   func_02190E74  0x02190E74  thumb
 *   func_02190EF0  0x02190EF0  thumb
 *   func_02190F64  0x02190F64  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_021A3238  0x021A3238  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int x, y, z;
} V12;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    u8 f10[0x18];
    u16 f28;
} Obj;


extern int func_020124E4();
extern int func_0201210C();
extern int func_02012138();
extern int func_020120F4();
extern int func_02012798();
extern void func_02012A90();
extern void func_02012374();
extern int func_0200FB24();
extern int func_02026454();
extern void func_02026400();
extern void func_02045C04();
extern int func_0216D3CC();
extern void func_0216D410();
extern int func_0216D480();
extern void func_0216D9A0();
extern void func_0216D9E4();
extern void func_0217C658();
extern int func_0217C688();
extern int func_02185214();
extern int func_02188BE8();
extern int func_02188C7C();
extern int func_02188C54();
extern int func_02188CB4();
extern int func_021904B0();
extern int func_021907A8();
extern void func_02190740();
extern int func_0219077C();
extern void func_02190728();
extern void func_021909BC();
extern int func_02190BE4();
extern int func_02190C78();
extern void func_02190E40();
extern void func_02190E74();
extern int func_02190EF0();
extern int func_02190F64();
extern int func_021A3074();
extern int func_021A3238();

int func_0217B600(int a0, int *state, Obj *o)
{
    int w;
    int g;
    int h;
    int t;
    int r;
    int ctx;
    int i;
    u8 v[12];
    V12 *pv;

    w = func_020124E4(a0);
    g = func_0201210C(w);
    h = func_02012138(w);
    switch (*state) {
    case 0:
        func_0216D9A0(func_02188C7C(g));
        t = func_02188C54(g);
        o->f0 = func_021904B0(t, 0x2D);
        o->f8 = func_02190F64(t, o->f0);
        func_02190E74(o->f8, 0, 0, 0x54);
        *state += 1;
        break;
    case 1:
        if (func_02190EF0(o->f8) == 1) {
            o->fc = func_02190BE4(func_02188C54(g), 0);
            *state += 1;
        }
        break;
    case 2:
        r = func_02190C78(o->fc);
        if (r != 2) {
            func_021909BC(o->fc);
            func_02190E40(o->f8);
            o->fc = 0;
            o->f8 = 0;
            if (r == 0)
                *state = 3;
            else
                *state = 11;
        }
        break;
    case 3:
        if (func_0200FB24() == 0 && func_02026454(h) == 2) {
            func_02026400(h);
            o->f4 = func_021907A8(func_02188C54(g), o->f0);
            func_02190740(o->f4, 0, 0, 0x14);
        }
        *state += 1;
        break;
    case 4:
        if (o->f4 == 0 || func_0219077C(o->f4) == 1)
            *state += 1;
        break;
    case 5:
        o->f28++;
        if (o->f4 != 0 && o->f28 <= 0x3C)
            break;
        if (func_02026454(h) == 2)
            break;
        ctx = func_020120F4(w);
        pv = (V12 *)v;
        pv->x = 0;
        pv->y = 0;
        pv->z = 0;
        for (i = 0; i < 3; i++)
            func_02012A90(func_02012798(ctx, i), pv);
        *state += 1;
        break;
    case 6:
        if (o->f4 != 0)
            func_02190728(o->f4);
        func_02045C04(o->f0);
        *state += 1;
        break;
    case 7:
        g = func_0201210C(w);
        if (func_02188BE8(g) != 1)
            break;
        if (func_021A3238(func_02188CB4(g)) == 0) {
            func_0217C658(o->f10, w, g, 0, 0, 0);
            *state += 1;
        } else {
            *state = 9;
        }
        break;
    case 8:
        if (func_0217C688(o->f10, 0) == 1)
            *state += 1;
        break;
    case 9:
        func_02012374(a0, func_02185214(w));
        *state += 1;
        break;
    case 10:
        *state = 14;
        break;
    case 11:
        func_02045C04(o->f0);
        *state = 12;
        break;
    case 12:
        t = func_021A3074(func_02188CB4(g));
        if (func_0216D3CC(t) == 1) {
            func_0216D410(t, 8);
            *state += 1;
        }
        break;
    case 13:
        if (func_0216D480(func_021A3074(func_02188CB4(g))) == 1)
            *state = 14;
        break;
    case 14:
        func_0216D9E4(func_02188C7C(g));
        return 1;
    }
    return 0;
}
