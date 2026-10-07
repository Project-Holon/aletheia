/*
 * file:     field_effect_p36.c
 * unit:     yes
 * function: func_021AB5F4, func_021AB624
 * address:  0x021AB5F4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DDFC8  0x021DDFC8  data  a4
 *   func_021AB650  0x021AB650  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */
typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
    int pad8[3];
    int f14;
    int f18;
    int pad1c;
} S;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef signed int     s32;

extern void *func_02030734(unsigned int heap, unsigned int size, int clear, const char *file, u16 line);
extern void func_021AB650(void *p);
extern u32 func_020307B0(void *p);
S *func_021AB5F4(int heap, int a, int b);
void func_021AB624(u8 *p);
extern char d_021DDFC8[];


S *func_021AB5F4(int heap, int a, int b)
{
    S *p = func_02030734((u16)heap, 0x20, 1, d_021DDFC8, 0x51);
    p->f0 = a;
    p->f4 = b;
    p->f14 = -1;
    p->f18 = 1;
    return p;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AB624(u8 *p)
{
    func_021AB650(p);
    func_020307B0(p);
}
