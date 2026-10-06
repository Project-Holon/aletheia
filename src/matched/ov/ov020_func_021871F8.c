/*
 * function: func_021871F8
 * address:  0x021871F8
 * packet:   pkt_ov020_021871F8
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The step callback func_021870C4 registers (func_020122C0's third
 * argument) for the 0x58-byte work block it fills.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_021620A0  0x021620A0  thumb  ov010
 *   func_02162048  0x02162048  thumb  ov010
 *   func_0216208C  0x0216208C  thumb  ov010
 *   func_0216209C  0x0216209C  thumb  ov010
 *   func_0218741C  0x0218741C  thumb  ov020
 *   func_02186278  0x02186278  thumb  ov020
 *   func_02161E4C  0x02161E4C  thumb  ov010
 *   func_0218748C  0x0218748C  thumb  ov020
 *   func_0204E720  0x0204E720  arm
 *   func_0204E804  0x0204E804  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02161F90  0x02161F90  thumb  ov010
 *   func_02193B20  0x02193B20  thumb  ov021
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_02187508  0x02187508  thumb  ov020
 *   func_021875B8  0x021875B8  thumb  ov020
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0201ED04  0x0201ED04  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;

struct Ctx;
unsigned int func_02012138(const struct Ctx *p);
int func_02158344(int a0);
int func_021620A0(int a0);
typedef signed int     s32;
typedef unsigned int   u32;
struct Ctx;
struct Rec;
struct U16Vec;
struct WordSet;
void func_02162048(u16 *a, int b, int c);
int func_0216208C(char *p, int unused);
u16 func_0216209C(char *p);
void func_0218741C(char *p, int a1, int *out, int a3);
int func_02186278(char *p, int which);
int func_02161E4C(void *a0, int id, unsigned mode);
void func_0218748C(char *p, int a1, int *out, int a3, u16 a4);
void func_0204E720(u32 a, s32 b, s32 c, s32 d);
int func_0204E804(void);
void *func_020120F4(const struct Ctx *p);
u8 *func_02012944(void *p);
void func_02161F90(int unused, u16 *x, char *y, int z, u16 w, u16 v);
int func_02193B20(u32 a, u32 b);
void func_0216CF2C(void *a);
int func_02187508(char *p);
int func_021875B8(char *p);
void func_02045808(struct U16Vec *vec);
void func_02045C04(struct Rec *rec);
void func_0201ED04(struct WordSet *p);

#define P(o)  (*(void **)(o))
#define P18   (*(void **)(o + 0x18))
#define P1C   (*(void **)(o + 0x1c))
#define P20   (*(void **)(o + 0x20))
#define P24   (*(void **)(o + 0x24))
#define P28   (*(void **)(o + 0x28))
#define P30   (*(void **)(o + 0x30))
#define P40   (*(void **)(o + 0x40))
#define P44   (*(void **)(o + 0x44))
#define P48   (*(void **)(o + 0x48))
#define H08   (*(u16 *)(o + 0x08))
#define H4C   (*(u16 *)(o + 0x4c))
#define H4E   (*(u16 *)(o + 0x4e))
#define H50   (*(u16 *)(o + 0x50))
#define B54   (*(u8 *)(o + 0x54))
#define B56   (*(u8 *)(o + 0x56))

int func_021871F8(void *a, int *st, char *o)
{
    if (func_02158344((int)((void *)func_02012138(P(o)))) == 0 && B56 != 0)
        *st = 0x11;

    switch (*st) {
    case 0:
        func_021620A0((int)P40);
        func_02162048(P40, H4C, 0);
        *st = 1;
        break;
    case 1:
        if (func_0216208C(P40, H4C) == 0)
            break;
        if (func_0216209C(P40) == 0)
            *st = 3;
        else
            *st = 2;
        break;
    case 2:
        func_0218741C(o, 0, st, 0x11);
        break;
    case 3:
        if (((u16 *)P44)[1] != ((u16 *)P48)[1])
            *st = 5;
        else
            *st = 4;
        break;
    case 4:
        func_0218741C(o, 1, st, 0x11);
        break;
    case 5:
        if ((unsigned int)func_02186278(P44, 0) >= 10) {
            *st = 6;
            break;
        }
        if (func_02161E4C(P44, H4C, 2) != 0)
            *st = 6;
        else
            *st = 7;
        break;
    case 6:
        func_0218741C(o, 2, st, 0x11);
        break;
    case 7:
        func_0218748C(o, 3, st, 9, 8);
        break;
    case 8:
        func_0218741C(o, 4, st, 0x11);
        break;
    case 9:
        func_021620A0((int)P40);
        func_02162048(P40, H4C, 1);
        *st = 10;
        break;
    case 10:
        if (func_0216208C(P40, H4C) == 0)
            break;
        if (func_0216209C(P40) == 2)
            *st = 12;
        else
            *st = 11;
        break;
    case 11:
        B56 = 0;
        func_0218741C(o, 5, st, 0x11);
        break;
    case 12:
        func_0218741C(o, 7, st, 0xd);
        func_021620A0((int)P40);
        func_02162048(P40, H4C, 2);
        B56 = 0;
        break;
    case 13:
        func_0204E720(1, 0, 0x10, 0);
        *st = 14;
        break;
    case 14:
        if (func_0204E804() != 0)
            break;
        func_02161F90((int)P40, P44, P48, (int)func_02012944(func_020120F4(P(o))), H4C, H08);
        func_02193B20((u32)P28, H4C);
        func_0216CF2C(P30);
        func_0204E720(1, 0x10, 0, 0);
        *st = 15;
        break;
    case 15:
        if (func_0204E804() != 0)
            break;
        *st = 0x11;
        break;
    case 16:
        if (func_02187508(o) == 0)
            break;
        if (B54)
            *st = H4E;
        else
            *st = H50;
        break;
    case 17:
        if (func_021875B8(o) == 0)
            break;
        func_02045808(P20);
        func_02045808(P24);
        func_02045C04(P18);
        func_0201ED04(P1C);
        return 1;
    }
    return 0;
}
