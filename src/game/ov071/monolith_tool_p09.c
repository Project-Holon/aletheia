/*
 * file:     monolith_tool_p09.c
 * unit:     yes
 * function: func_021B7BB4, func_021B7BD8, func_021B7BE4, func_021B7BF0, func_021B7BFC, func_021B7C3C, func_021B7D00, func_021B7D34
 * address:  0x021B7BB4
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
 *   func_021B6C7C 0x021B6C7C thumb ov071
 *   func_021B6B70 0x021B6B70 thumb ov071
 *   func_021B7070  0x021B7070  thumb  ov071
 *   func_021B70B8  0x021B70B8  thumb  ov071
 *   func_021B70C4  0x021B70C4  thumb  ov071
 *   func_021B6B58  0x021B6B58  thumb  ov071
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_021B7D6C  0x021B7D6C  thumb  ov071
 *   func_021B7DAC  0x021B7DAC  thumb  ov071
 *   func_021B6F2C  0x021B6F2C  thumb  ov071
 *   func_020457B0  0x020457B0  arm
 *   func_020084F4  0x020084F4  thumb
 *   func_02045994  0x02045994  arm
 *   func_02008550  0x02008550  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02045808  0x02045808  arm
 *   func_021B6E1C  0x021B6E1C  thumb  ov071
 *   func_021B7DE0  0x021B7DE0  thumb  ov071
 *   func_02040588  0x02040588  arm
 *   func_020434DC  0x020434DC  arm
 *   func_021B6F04 0x021B6F04 thumb ov071
 *   func_021B7E3C 0x021B7E3C thumb ov071
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_02043534 0x02043534 arm
 *   func_021B7E24 0x021B7E24 thumb ov071
 *   func_021B6EEC 0x021B6EEC thumb ov071
 *   func_021B7D98 0x021B7D98 thumb ov071
 *   func_020315D4 0x020315D4 arm
 */
#include "../../matched/include/Obj20703.h"
#include "../../matched/include/Obj20705.h"
#include "../../matched/include/Obj13176.h"
#include "../../matched/include/Obj20709.h"
#include "../../matched/include/Obj20710.h"

struct Strbuf;
struct U16Vec;
struct Sub0200852CObj;
struct WordSet;
struct Obj0203159C;
struct PrintSys;
struct S020315D4;
typedef unsigned char  u8;

typedef struct {
    char pad[0x10];
    int f10;
} Inner;

typedef struct {
    int f0;
    Inner *f4;
} C;

typedef unsigned short u16;

typedef unsigned int   u32;

extern void func_021B6C7C(int *p, int idx);
extern int func_021B6B70(void **p, u8 *q);
extern int func_021B6F04(void **p, u8 *q);
extern void func_021B7E3C(void **,void *);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_02043534(unsigned);
extern void func_021B7E24(void **);
extern void func_021B6EEC(void **p);
extern void func_021B7D98(void);
extern void func_020315D4(struct S020315D4 *p);
void func_021B7BB4(int *a,char *p);
void func_021B7BD8(void *p, int a);
void func_021B7BE4(void *p);
void func_021B7BF0(void *p);
void func_021B7BFC(int *a, char *p, unsigned char m);
int func_021B7C3C(struct Obj0203159C *a, int *b, C *c);
int func_021B7D00(int a,int *p,char *c,void **d);
int func_021B7D34(void *a,int b,char *c,void **d);

void func_021B7BB4(int *a,char *p) { int i; func_021B6C7C(a,3); p+=0x2c; for(i=0;i<2;i++) func_021B6B70((void **)a[1],(u8 *)(p+i*16)); }


/*
 * Tail call to func_021B7070(word at 0x4, a + 0x24).
 */
void func_021B7BD8(void *p, int a)
{
    void func_021B7070(int *p, int *out);
    func_021B7070(((struct Obj20703 *)p)->f4, (int *)(a + 0x24));
}

/*
 * Tail call to func_021B70B8 with the pointer advanced by 0x24.  The callee
 * is an unlabelled leaf in this overlay; it is reproduced in
 * src/matched/ov071_func_021B70B8.c, whose EXACT entry attests this pool-word
 * site (`matched`).
 */
void func_021B7BE4(void *p)
{
    void func_021B70B8(void **p);
    func_021B70B8((void **)((char *)p + 0x24));
}

/*
 * Tail call to func_021B70C4((char *)p + 0x24).
 */
void func_021B7BF0(void *p)
{
    void func_021B70C4(void *);
    func_021B70C4((char *)p + 0x24);
}


void func_021B7BFC(int *a, char *p, unsigned char m)
{
    void func_021B6B58(void **p, int v);

    if (m == 0) {
        func_021B6B58((void **)(p + 0x2c), 1);
        func_021B6B58((void **)(p + 0x3c), 0);
    } else {
        *(unsigned char *)a[2] = 6;
        func_021B6B58((void **)(p + 0x2c), 0);
        func_021B6B58((void **)(p + 0x3c), 1);
    }
    ((struct Obj20705 *)p)->f82 = m;
}

int func_021B7C3C(struct Obj0203159C *a, int *b, C *c)
{
    extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
    extern void func_02082BCC(void *, int, int);
    extern void func_021B7D6C(void);
    extern void func_021B7DAC(void *a, unsigned *b);
    extern void *func_021B6F2C(u8 **p);
    extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
    extern const void *func_020084F4(const void *p);
    extern void func_02045994(struct Strbuf *o, const u16 *src, u32 len);
    extern u8 func_02008550(const struct Sub0200852CObj *obj);
    extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
    extern void func_02045808(struct U16Vec *vec);
    extern void func_021B6E1C(Inner *, void *, int, int, int, int, int, int, int);
    extern void func_021B7DE0(void *, C *);
    extern void func_02040588(unsigned char which, unsigned char enable);
    extern void func_020434DC(u32 mask, u32 enable);
    void *m;
    void *s;
    int h;

    switch (*b) {
    case 0:
        m = func_0203159C(a, 0x24, 0x61);
        func_02082BCC(m, 0, 0x24);
        func_021B7D6C();
        func_021B7DAC(c, (unsigned int *)c->f4);
        h = (int)func_021B6F2C((u8 **)c);
        s = func_020457B0(8, 0x61);
        func_02045994(s, func_020084F4((const void *)h), 8);
        func_0201EE0C((struct WordSet *)c->f4->f10, 0, s, func_02008550((const struct Sub0200852CObj *)h), 1, 2);
        func_02045808(s);
        func_021B6E1C(c->f4, m, 0, 0x80, 0xc, 0x1e, 2, 0, c->f4->f10);
        func_021B7DE0(m, c);
        *b = *b + 1;
        break;
    case 1:
        func_02040588(2, 1);
        func_020434DC(0x10, 1);
        return 1;
    }
    return 0;
}

int func_021B7D00(int a,int *p,char *c,void **d) { if((unsigned char)c[0x2d]==1) return 1; func_021B6F04(((struct Obj13176 *)c)->f4,(u8 *)d); func_021B7E3C(d,c); switch(*p) { case 0:return 0; default:return 0; } }

int func_021B7D34(void *a,int b,char *c,void **d) { if(func_0201C6B4(((struct Obj20710 *)(*(char * *)&((struct Obj20709 *)c)->f4))->f8)==0) return 0; func_02043534(8); func_021B7E24(d); func_021B6EEC(d); func_021B7D98(); func_020315D4(a); return 1; }
