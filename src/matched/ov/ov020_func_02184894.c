/*
 * function: func_02184894
 * address:  0x02184894
 * packet:   pkt_ov020_02184894
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012A30  0x02012A30  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02029D44  0x02029D44  thumb
 *   func_02029D7C  0x02029D7C  thumb
 *   func_0218403C  0x0218403C  thumb  ov020
 *   func_02184360  0x02184360  thumb  ov020
 *   func_02185F48  0x02185F48  thumb  ov020
 *   func_02161824  0x02161824  thumb  ov010
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC550  0x021BC550  thumb  ov021
 *   func_021BF5E8  0x021BF5E8  thumb  ov021
 *   func_021BFDA0  0x021BFDA0  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;

typedef struct Obj {
    int f00;
    int f04;
    int f08;
    char pad0c[0x14 - 0x0c];
    s16 f14;
    char pad16[0x44 - 0x16];
    int f44;
    u16 f48;
    u16 f4a;
} Obj;

typedef unsigned int   u32;
struct BigObj;
u32 func_02012A30(const struct BigObj *p);
struct Evt;
void func_02012374(struct Evt *evt, struct Evt **out);
void func_02029D44(u32 a, u32 b, u16 c, u8 d);
void func_02029D7C(int a, int b);
void func_0218403C(u8 *p);
void *func_02184360(u8 *p, int value);
void func_02185F48(void *p);
void *func_02161824(void *a, void *b);
u32 func_02188D20(u8 *p);
void func_021BC550(void *p, int v);
u32 func_021BF5E8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
void *func_021BFDA0(int a0, void *p, int a2, int a3);

int func_02184894(void *a, int *state, Obj *o)
{
    int f0 = o->f00;
    int f4 = o->f04;
    int f8 = o->f08;
    int h = func_02012A30((const void *)f4);

    switch (*state) {
    case 0:
        func_0218403C((u8 *)o);
        func_02012374(a, func_02161824((void *)f0, (void *)f8));
        (*state)++;
        break;
    case 1:
        func_02012374(a, func_021BFDA0((int)a, (void *)f0, f8, o->f44));
        (*state)++;
        break;
    case 2:
        func_02185F48((void *)f4);
        func_02029D44((int)h, (int)f4, (u16)o->f14, (u8)o->f4a);
        func_02029D7C(h, f4);
        (*state)++;
        break;
    case 3:
        func_02012374(a, func_02184360((u8 *)o, 2));
        (*state)++;
        break;
    case 4:
        func_02012374(a, (struct Evt **)func_021BF5E8((u32)a, f0, f8, o->f44, o->f48, o->f4a));
        (*state)++;
        break;
    case 5:
        func_021BC550((void *)func_02188D20((u8 *)f8), o->f14);
        return 1;
    }
    return 0;
}
