/*
 * file:     unit_021542C0.c
 * unit:     yes
 * function: func_021542C0, func_02154668
 * address:  0x021542C0
 * region:   ov000
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   func_02005C44  0x02005C44  thumb
 *   func_02005C18  0x02005C18  thumb
 *   func_02005B24  0x02005B24  thumb
 *   func_02005D90  0x02005D90  thumb
 *   func_02005DF8  0x02005DF8  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_02005E9C  0x02005E9C  thumb
 *   func_02005DE4  0x02005DE4  thumb
 *   func_02005E64  0x02005E64  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009448  0x02009448  thumb
 *   func_02009304  0x02009304  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_02012944  0x02012944  thumb
 *   func_020079A0  0x020079A0  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_02012444  0x02012444  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0200FB38  0x0200FB38  thumb
 *   func_0200F7B8  0x0200F7B8  thumb
 *   func_020121CC  0x020121CC  thumb
 *   ov123_id       0x0000007B  data   a1
 *   ov016_id       0x00000010  data   a1
 *   ov115_id       0x00000073  data   a1
 *   ov170_id       0x000000AA  data   a1
 *   d_021DA674     0x021DA674  data   ov123  a4
 *   d_021DA838     0x021DA838  data   ov123  a4
 *   d_021D77B8     0x021D77B8  data   ov016  a4
 *   d_021D6338     0x021D6338  data   ov115  a4
 *   d_021D654C     0x021D654C  data   ov115  a4
 *   d_021EF78C     0x021EF78C  data   ov170  a4
 *   func_02154670  0x02154670  thumb ov000
 */
#define F(o)  (*(u32 *)(args + (o)))
#define H(o)  (*(u16 *)(args + (o)))
#define B(o)  (*(u8 *)(args + (o)))
struct Big;
struct BigObj;
struct Ctx;
struct Evt;
struct IcaAnime;
struct Obj;
struct Sub02008700Obj;
struct Sub02009210Obj;
struct Sub02009448Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef volatile u16   vu16;

extern void *func_0201210C(const struct Ctx *p);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020144DC(int a0, int a1);
extern void  func_02082BCC(void *p, int c, int n);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern u16 func_02005C44(void);
extern void  func_02005C18(void);
extern void  func_02005B24(void);
extern void  func_02005D90(u32 a0, u32 a1);
extern void func_02005DF8(u32 a);
extern void *func_020145CC(void *a0);
extern int func_02005E9C(void);
extern void func_02005DE4(void *p);
extern int func_02005E64(void);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern u8 func_02009304(const struct Sub02009210Obj *obj);
extern u32 func_0201293C(const struct BigObj *p);
extern void *func_02012934(const struct BigObj *p);
extern void *func_0201292C(const struct BigObj *p);
extern u8 *func_02012944(void *p);
extern int func_020079A0(void *save);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern u32 func_0200FB24(void);
extern void  func_0200FB38(void);
extern u32 func_0200F7B8(u32 a0);
extern u32 func_020121CC(struct IcaAnime *p);
extern void *func_02154670(void *p);
u32 func_021542C0(void *obj, u32 *mode, char *args);
void *func_02154668(void *p);
extern char ov123_id[];
extern char ov016_id[];
extern char ov115_id[];
extern char ov170_id[];
extern char d_021DA674[];
extern char d_021DA838[];
extern char d_021D77B8[];
extern char d_021D6338[];
extern char d_021D654C[];
extern char d_021EF78C[];


u32 func_021542C0(void *obj, u32 *mode, char *args)
{
    u32 h = F(0x0);
    u32 v = (u32)func_0201210C((const struct Ctx *)h);
    int r;

    switch (*mode) {
    case 0:
        func_02012374(obj, (struct Evt **)func_021BE8D4((void *)h, v, 0, 0));
        (*mode)++;
        break;
    case 1:
        func_02012374(obj, (struct Evt **)func_020144DC(h, v));
        F(0x2c8) = 0;
        *mode = 2;
        break;
    case 2:
        func_02082BCC(args + 0xc, 0, 0x44);
        F(0x50) = 0;
        func_020120B4((struct IcaAnime *)h, (u32)ov123_id, d_021DA674, args);
        (*mode)++;
        break;
    case 3:
        if (func_020120F0((const struct Ctx *)h) == 0) {
            if (F(0x1c8) == 2)
                *mode = 16;
            else if (F(0x1c8) == 3)
                *mode = 5;
            else
                *mode = 10;
        }
        break;
    case 5:
        (*mode)++;
        break;
    case 6:
        F(0x1d4) = func_02005C44();
        func_02005C18();
        func_020120B4((struct IcaAnime *)h, (u32)ov016_id, d_021D77B8, args);
        (*mode)++;
        break;
    case 7:
        if (func_020120F0((const struct Ctx *)h) == 0)
            *mode = 14;
        break;
    case 14:
        {
            vu16 *ime = (vu16 *)0x04000208;
            u16 old = *ime;
            *ime = 1;
            (void)old;
        }
        func_02005B24();
        func_02005D90(F(0x1d4), 0xFFFF);
        func_02005DF8(0x3C);
        *mode = 15;
        break;
    case 15:
        F(0x2c8) = 1;
        *mode = 2;
        break;
    case 10:
        func_02012374(obj, func_020145CC((void *)h));
        (*mode)++;
        break;
    case 11:
        func_02012374(obj, (struct Evt **)func_021BE92C((void *)h, v, 0, 0, 1, 0, 0));
        (*mode)++;
        break;
    case 12:
        if (F(0x1cc)) {
            func_02005E9C();
            func_02005DE4(0);
            func_02005DF8(0x3C);
            F(0x1cc) = 0;
        }
        (*mode)++;
        break;
    case 13:
        return 1;
    case 16:
        r = func_02009304((const struct Sub02009210Obj *)func_02009448(func_02012EBC(func_020120F4((const struct Ctx *)h))));
        if (func_020079A0((void *)func_0201293C(func_020120F4((const struct Ctx *)h))) == 0 && r == 0) {
            F(0x1c8) = 4;
            *mode = 19;
        } else {
            F(0x26c) = 0;
            func_02005DE4((void *)1);
            func_02005E64();
            F(0x1cc) = 1;
            (*mode)++;
        }
        break;
    case 17:
        F(0x268) = (u32)(args + 0x54);
        func_020120B4((struct IcaAnime *)h, (u32)ov115_id, d_021D6338, args + 0x258);
        (*mode)++;
        break;
    case 18:
        if (func_020120F0((const struct Ctx *)h) == 0) {
            if (F(0x274) == 1) {
                *mode = 10;
            } else {
                if (func_02009304((const struct Sub02009210Obj *)func_02009448((void *)F(0x8))) == 0) {
                    F(0x1c8) = 3;
                    *mode = 19;
                } else {
                    F(0x1c8) = 0;
                    *mode = 19;
                }
            }
        }
        break;
    case 19:
        func_020120B4((struct IcaAnime *)h, (u32)ov123_id, d_021DA838, args);
        (*mode)++;
        break;
    case 20:
        if (func_020120F0((const struct Ctx *)h) == 0) {
            if (F(0x1c8) == 1) {
                F(0x2c8) = 0;
                *mode = 2;
            } else if (F(0x1c8) == 5) {
                *mode = 21;
            } else if (F(0x1c8) == 4) {
                *mode = 21;
            } else if (F(0x1c8) == 7) {
                F(0x26c) = 1;
                *mode = 17;
            } else {
                *mode = 23;
            }
        }
        break;
    case 21:
        F(0x29c) = (u32)func_020120F4((const struct Ctx *)h);
        F(0x2a0) = func_0201293C((const struct BigObj *)F(0x29c));
        F(0x2a4) = (u32)func_02012934((const struct BigObj *)F(0x29c));
        F(0x2a8) = (u32)func_0201292C((const struct BigObj *)F(0x29c));
        F(0x2ac) = (u32)func_02012944((void *)F(0x29c));
        F(0x2b4) = (u32)func_0200873C(func_02012EBC((struct Big *)F(0x29c)));
        F(0x2bc) = (u32)(args + 0x1d8);
        F(0x2b8) = 0;
        F(0x2c0) = 5;
        func_02012444(obj, (u32)ov170_id, (u32)d_021EF78C, (u32)(args + 0x29c));
        (*mode)++;
        break;
    case 22:
        if (func_0200FB24()) {
            func_0200FB38();
            func_0200F7B8(0);
            F(0x26c) = 1;
            *mode = 17;
        } else {
            u8 a, b;
            a = B(0x2c6);
            H(0x1d0) = a;
            b = B(0x2c7);
            H(0x1d2) = b;
            if (a == 0xff && b == 0xff) {
                *mode = 23;
            } else {
                if (F(0x1c8) == 4)
                    F(0x1c8) = 2;
                else
                    F(0x1c8) = 1;
                *mode = 19;
            }
        }
        break;
    case 23:
        F(0x280) = (u32)func_020120F4((const struct Ctx *)h);
        F(0x284) = 1;
        F(0x288) = 0;
        func_020120B4((struct IcaAnime *)h, (u32)ov115_id, d_021D654C, args + 0x280);
        (*mode)++;
        break;
    case 24:
        if (func_020120F0((const struct Ctx *)h) == 0) {
            func_020121CC((struct IcaAnime *)h);
            *(vu16 *)0x04000304 |= 0x8000;
            F(0x2c8) = 0;
            *mode = 2;
            if (F(0x1cc)) {
                func_02005E9C();
                func_02005DE4(0);
                func_02005DF8(0x3C);
                F(0x1cc) = 0;
            }
        }
        break;
    }
    return 0;
}


/*
 * Thumb tail call through r3 (ldr r3, =target; bx r3). Labelled in wave D8.
 */
void *func_02154668(void *p)
{
    return func_02154670(p);
}
