/*
 * file:     btl_server_p07.c
 * unit:     yes
 * function: func_021B9EF0, func_021B9F70
 * address:  0x021B9EF0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045A00  0x02045A00  arm
 *   func_02082D44  0x02082D44  arm
 *   func_02024570  0x02024570  thumb
 *   func_0202428C  0x0202428C  thumb
 */
struct Buf;
struct U16Vec;
struct Rec8;
typedef unsigned short u16;

struct H {
    u16 a, b, c, d;
};

struct A {
    int vt;
    int q;
    u16 h8;
    u16 ha;
    int c;
    u16 h[4];
    struct H s18;
    struct H s20;
};

struct B {
    int f0;
    int f4;
    int f8;
    char b[8];
    int f14;
    struct H s18;
    struct H s20;
    char pad[0x68 - 0x28];
    int f68;
};

typedef unsigned int   u32;

typedef unsigned char u8;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045A00(struct Buf *buf, const void *src, u32 n);
extern void func_02082D44(const void *, void *, int);
extern void func_02024570(struct Rec8 *dst, const struct Rec8 *src);
extern void func_0202428C(void *obj);
void func_021B9EF0(struct A *p, const struct B *src);
/* 021B9F70 movs r2,#0x28; muls r2,r1,r2; adds r0,r0,r2; ldr r0,[r0,#0x20] */ int func_021B9F70(u8 *p, int i);


void func_021B9EF0(struct A *p, const struct B *src)
{
    unsigned int i;
    int t, u;

    p->vt = 0;
    if (src) {
        p->ha = src->f0;
        p->h8 = src->f4;
        t = (int)func_020457B0(0x20, 0x12);
        u = src->f68 + 1;
        p->q = t;
        func_02045A00((struct Buf *)t, (char *)src + 0x28, u);
        p->c = src->f8;
        func_02082D44(src->b, p->h, 8);
        func_02024570((struct Rec8 *)(&p->s18), (const struct Rec8 *)(&src->s18));
        func_02024570((struct Rec8 *)(&p->s20), (const struct Rec8 *)(&src->s20));
    } else {
        p->ha = 0;
        p->h8 = 0;
        p->q = 0;
        for (i = 0; i < 4; i++) {
            p->h[i] = 0;
        }
        func_0202428C(&p->s18);
        func_0202428C(&p->s20);
    }
}


/* 021B9F70  movs r2,#0x28; muls r2,r1,r2; adds r0,r0,r2; ldr r0,[r0,#0x20] */
int func_021B9F70(u8 *p, int i) { return *(u32 *)(p + i * 0x28 + 0x20) == 0; }
