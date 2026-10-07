/*
 * file:     intrude_field_p10.c
 * unit:     yes
 * function: func_0217C658, func_0217C688
 * address:  0x0217C658
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_020061E4  0x020061E4  thumb
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_0217BCDC  0x0217BCDC  thumb  ov018
 *   func_0216D410  0x0216D410  thumb  ov010
 *   d_021836A0     0x021836A0  data  a1
 */
struct Ctx;
struct Obj00020;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef struct {
    void *f0;
    int f4;
    s16 f8, fA;
    u16 fC;
    u8 fE, fF, f10, f11, f12, f13;
    int f14;
} Rec_0217C658;

typedef unsigned int u32;

typedef struct {
    void *f0;
    unsigned char *f4;
    s16 f8;
    s16 fA;
    u16 fC;
    u8 fE;
    u8 fF;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    int f14;
} Rec_0217C688;

extern void func_02082BCC(void *, int, int);
extern void func_020061E4(u32 a);
extern int func_02188BE8(void *);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(unsigned char *p);
extern int func_0216D3CC(int a0);
extern void *func_020120F4(const struct Ctx *p);
extern void func_0217BCDC(u8 *p, void *a1, int id, u8 kind, u8 flag);
extern void func_0216D410(void *a0, u16 a1);
void func_0217C658(Rec_0217C658 *p, void *a, int b, u16 c, u8 d, u8 e);
int func_0217C688(Rec_0217C688 *r, void *a1);
extern const u8 d_021836A0[4];

/*
 * extent: two alignment bytes at 0x0217C686.
 */
void func_0217C658(Rec_0217C658 *p, void *a, int b, u16 c, u8 d, u8 e)
{
    func_02082BCC(p, 0, sizeof(Rec_0217C658));
    p->f0 = a;
    p->f4 = b;
    p->fC = c;
    p->fE = d;
    p->fF = e;
    p->fA = 15;
    p->f8 = p->fA;
}


/*
 * Per-frame step of the 0x18-byte record func_0217C758 initialises.
 */
int func_0217C688(Rec_0217C688 *r, void *a1)
{
    void *obj;
    s16 v;

    switch (r->f10) {
    case 0:
        r->fA = 15;
        r->f8 = r->fA;
        func_020061E4(0x738);
        r->f10++;
        break;
    case 1:
        if (func_02188BE8(r->f4) == 1) {
            obj = func_021A3074(func_02188CB4((struct Obj00020 *)r->f4));
            if (func_0216D3CC((int)obj) == 1) {
                if (r->fA >= 15 && r->f12 != 0 && d_021836A0[r->f11] == 1) {
                    r->f10++;
                    break;
                }
                r->f11 = (r->f11 + 1) & 3;
                v = r->fA;
                r->f8 = v;
                if (r->f12 == 0) {
                    r->fA--;
                    if (r->fA <= 1) {
                        func_020120F4(r->f0);
                        func_0217BCDC(a1, r->f0, r->fC, r->fE, r->fF);
                        r->f12++;
                    }
                } else if (v < 15) {
                    r->fA++;
                }
                func_0216D410(obj, d_021836A0[r->f11]);
            }
        }
        break;
    default:
        return 1;
    }
    return 0;
}
