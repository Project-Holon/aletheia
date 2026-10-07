/*
 * file:     nhttp_rap_p06.c
 * unit:     yes
 * function: func_021B9A64, func_021B9A8C, func_021B9A94
 * address:  0x021B9A64
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02082D44 0x02082D44 arm
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02082BCC(int, int, int);
extern u32 func_020307B0(void *p);
extern void func_02082D44(int,int,int);
u8 *func_021B9A64(int a, int b, int c);
void func_021B9A8C(void *buf);
void func_021B9A94(int p, int a, u32 b, int n);


/*
 * Allocates and zeroes an a*b byte scratch block from tag 0xb9.
 */
u8 *func_021B9A64(int a, int b, int c)
{
    int n = b * a;
    u8 *p = func_02030734(c, n, 0, (const char *)0x021CE3A0, 0xb9);

    func_02082BCC((int)p, 0, n);
    return p;
}

void func_021B9A8C(void *buf)
{
    func_020307B0(buf);
}

void func_021B9A94(int p, int a, u32 b, int n) { func_02082D44(a,p+b*n,b); }
