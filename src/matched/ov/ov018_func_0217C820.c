/*
 * function: func_0217C820
 * address:  0x0217C820
 * packet:   pkt_ov018_0217C820
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-frame step of the 0x18-byte record (same layout as func_0217C688's).
 *
 * symbols:
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_021F37B8  0x021F37B8  thumb  ov060
 *   func_020061E4  0x020061E4  thumb
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_021F37D8  0x021F37D8  thumb  ov060
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
    s16 fA;
    u16 fC;
    u8 fE;
    u8 fF;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    void *f14;
} Rec;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

extern void *func_02188CB4(unsigned char *p);
extern void *func_021A3074(unsigned char *p);
extern void func_0216D410(void *, u16);
extern void func_021A3038(unsigned char *, Vec *);
extern void func_021F37B8(int, Vec *);
extern void func_020061E4(u32 a);
extern void func_0216DAC8(unsigned int *, unsigned int);
extern int func_021F37D8(void *);
extern int func_0216D454(int);
extern int func_0216D480(char *p);
extern void func_0216CF2C(int);

int func_0217C820(Rec *r)
{
    void *fld;
    void *obj;
    u16 anim;
    Vec v;

    fld = func_02188CB4(r->f4);
    obj = func_021A3074((void *)fld);
    switch (r->f10) {
    case 0:
        anim = r->f13 == 3 ? 7 : 6;
        func_0216D410(obj, anim);
        if (r->f14 != 0)
            func_0216D410(r->f14, anim);
        func_021A3038(fld, &v);
        if (r->f13 == 3)
            v.x += 0x8000;
        else
            v.x -= 0x8000;
        func_021F37B8((int)r->f4, &v);
        func_020061E4(0x774);
        r->f10++;
        break;
    case 1:
        r->fA--;
        if (r->fA <= 0) {
            if (r->f14 != 0) {
                func_0216DAC8(obj, 0);
                func_0216DAC8(r->f14, 1);
            }
            r->f10++;
        }
        break;
    case 2:
        if (func_021F37D8(r->f4) == 0 && func_0216D454((int)obj) == 1) {
            func_0216D480(obj);
            if (r->f14 != 0)
                func_0216D480(r->f14);
            r->f10++;
        }
        break;
    case 3:
        if (r->f14 != 0) {
            func_0216CF2C((int)r->f14);
            r->f14 = 0;
        }
        return 1;
    }
    return 0;
}
