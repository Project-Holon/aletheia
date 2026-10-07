/*
 * file:     monolith_tool_p08.c
 * unit:     yes
 * function: func_021B7AAC, func_021B7AC4, func_021B7AE8, func_021B7B10, func_021B7B9C
 * address:  0x021B7AAC
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B6FD8 0x021B6FD8 thumb ov071
 *   func_021B6F40 0x021B6F40 thumb ov071
 *   func_021B6FE0 0x021B6FE0 thumb ov071
 *   d_021BA8A0 0x021BA8A0 data a4
 *   func_0204B404 0x0204B404 arm
 *   func_021B6C54  0x021B6C54  thumb  ov071
 *   func_021B6A0C  0x021B6A0C  thumb  ov071
 *   func_020355C4  0x020355C4  arm
 *   func_021B6B98  0x021B6B98  thumb  ov071
 *   func_021B6B58  0x021B6B58  thumb  ov071
 *   func_021B6B38 0x021B6B38 thumb ov071
 */
struct Obj;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_021B6FD8(void *);
extern void *func_021B6F40(u8 **p);
extern void func_021B6FE0(void *,u8 *,int);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_021B6C54(char *p);
extern void func_021B6A0C(int a, void *b, int c, int d, int e, int f, int g, int h);
extern u8 func_020355C4(void);
extern void func_021B6B98(void *p, int *tbl, int n, int sel, int c);
extern void func_021B6B58(void **p, int v);
extern void func_021B6B38(void **p);
void func_021B7AAC(void **p);
void func_021B7AC4(void **p, void *q);
void func_021B7AE8(void **p,int i);
void func_021B7B10(int *a, char *b);
void func_021B7B9C(char *p);
extern const struct Pair { int x, y; } d_021BA8A0[];

void func_021B7AAC(void **p) { int i; for(i=0;i<6;i++) func_021B6FD8(p[i+3]); }

void func_021B7AC4(void **p, void *q) { u8 *t;int i;t=func_021B6F40(q);for(i=0;i<6;i++)func_021B6FE0(p[i+3],t,i);}

void func_021B7AE8(void **p,int i) { u16 t[2];t[0]=d_021BA8A0[i].x;t[1]=d_021BA8A0[i].y;func_0204B404(p[31],(const struct Vec2 *)t,1);}


void func_021B7B10(int *a, char *b)
{
    func_021B6C54((char *)a);
    func_021B6A0C(a[1], b + 0x2c, 1, 1, 0x80, 0x90, 14, 0);
    if (func_020355C4() == 0) {
        func_021B6B98(a, (int *)(b + 0x2c), 1, 0, 3);
    } else {
        func_021B6B98(a, (int *)(b + 0x2c), 1, 0xff, 3);
        b[0x83] = 1;
    }
    func_021B6A0C(a[1], b + 0x3c, 1, 1, 0x80, 0x90, 15, 0);
    func_021B6B58((void **)(b + 0x3c), 0);
}

void func_021B7B9C(char *p) { int i; p += 0x2c; for (i=0;i<2;i++) func_021B6B38((void **)(p+i*16)); }
