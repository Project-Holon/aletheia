/*
 * file:     field_effect_p44.c
 * unit:     yes
 * function: func_021ABB54, func_021ABB78, func_021ABBA0, func_021ABBF0
 * address:  0x021ABB54
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
 *   func_021AB760  0x021AB760  thumb
 *   func_0218F0D4  0x0218F0D4  thumb
 *   func_021ABABC  0x021ABABC  thumb
 *   func_0218F05C  0x0218F05C  thumb
 *   func_021ABC5C  0x021ABC5C  thumb  ov021
 *   func_021ABD08  0x021ABD08  thumb  ov021
 */
typedef struct {
    int pad[7];
    int f1c;
} S;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct { int x; int y; int z; } V;

typedef signed short   s16;

typedef signed char    s8;

extern u32 func_021AB760(u8 *p);
extern void func_0218F0D4(u8 *a, int b);
extern void func_021ABABC(int a0, const u16 *p, void *q);
extern void func_0218F05C(unsigned char *a);
extern void func_021ABC5C(u8 *a0, char *p, void *q);
extern u32 func_021ABD08(u32, u32, u32);
void func_021ABB54(int a, S *s, int c);
void func_021ABB78(int a, S *s, int c);
void func_021ABBA0(u16 *r, V *v, int *o1, int *o2);
int func_021ABBF0(u8 *a, u32 b, u32 c, u32 d);


void func_021ABB54(int a, S *s, int c)
{
    int h = func_021AB760((u8 *)a);
    if (s->f1c != 0) {
        func_0218F0D4((u8 *)h, s->f1c);
    }
    func_021ABABC(a, (const u16 *)s, (void *)c);
}


void func_021ABB78(int a, S *s, int c)
{
    int h = func_021AB760((u8 *)a);
    func_021ABABC(a, (const u16 *)s, (void *)c);
    if (s->f1c != 0) {
        func_0218F05C((unsigned char *)h);
    }
}


void func_021ABBA0(u16 *r, V *v, int *o1, int *o2)
{
    V t = *v;

    t.x -= 0x8000;
    t.z -= 0x8000;
    *o1 = r[4] << 16;
    if (r[2] == 1)
        *o2 = t.x - (r[0] << 16);
    else
        *o2 = t.z - (r[1] << 16);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021ABBF0(u8 *a, u32 b, u32 c, u32 d)
{
func_021ABABC((int)a, (const u16 *)b, (void *)c);
func_021ABC5C(a, (char *)b, (void *)c);
return func_021ABD08((u32)a, b, c);
}
