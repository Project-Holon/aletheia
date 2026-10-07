/*
 * file:     namein_graphic_p23.c
 * unit:     yes
 * function: func_021F4DBC, func_021F4DD0, func_021F4DD8, func_021F4DDC, func_021F4E18, func_021F4E58, func_021F4E98, func_021F4ED8, func_021F4F10, func_021F4F50, func_021F4F60, func_021F4F68, func_021F4F6C, func_021F4F7C, func_021F5004, func_021F513C, func_021F51A4, func_021F51E4
 * address:  0x021F4DBC
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201F41C 0x0201F41C thumb
 *   func_02045A98 0x02045A98 arm
 *   func_0204A1BC 0x0204A1BC arm
 *   func_020307B0 0x020307B0 arm
 *   func_021F4D20 0x021F4D20 thumb ov194
 *   func_021F4DA4 0x021F4DA4 thumb ov194
 *   func_021F4D9C 0x021F4D9C thumb ov194
 *   func_021F4DA0 0x021F4DA0 thumb ov194
 *   func_021F4D34 0x021F4D34 thumb ov194
 *   func_02082D44 0x02082D44 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049250 0x02049250 arm
 *   func_0206E964 0x0206E964 arm
 *   func_02030734 0x02030734 arm
 *   func_0204B7F0 0x0204B7F0 arm
 *   func_0204AA94 0x0204AA94 arm
 *   func_020862F0 0x020862F0 arm
 *   func_0204B764 0x0204B764 arm
 *   func_02063800 0x02063800 arm
 *   func_0207E51C 0x0207E51C arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_02049238 0x02049238 arm
 *   d_021F57A8 0x021F57A8 data ov194 a1
 */
#include "../../matched/include/Obj14518.h"
#include "../../matched/include/Obj14519.h"

struct ArcFile;
struct Struct20;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { int w[5]; } Palette;

extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern u32 func_020307B0(void *p);
extern void func_0201F41C(const u16 *,u16 *,u32);
extern unsigned short func_02045A98(void);
extern int func_021F4D20(u32 a, u32 b);
extern u32 func_021F4DA4(u8 *p, u16 a, u16 b);
extern u16 func_021F4D9C(const u16 *p);
extern u16 func_021F4DA0(const u16 *p);
extern void func_021F4D34(void *p);
extern void func_02082D44(const void *, void *, unsigned);
extern void *func_020490F4(unsigned,u16);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern u8 *func_0206E964(u8 *);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern u16 func_0204B7F0(u8 *);
extern void func_0204AA94(int,void *,u32,int,int);
extern void func_020862F0(void *,unsigned);
extern void func_0204B764(const char *src, struct Struct20 *dst);
extern int func_02063800(char *,int);
extern void func_0207E51C(void *,int,unsigned);
extern void func_0207E5D0(void *,int,unsigned);
extern void func_02049238(void *);
int func_021F4DBC(int a, int b);
void func_021F4DD0(void *p);
u16 func_021F4DD8(const u16 *p);
void func_021F4DDC(const char *p,int i,u16 *dst,u32 n,u8 *count);
int func_021F4E18(int p, int idx, unsigned short *tab, int val, unsigned char *out);
int func_021F4E58(int p, int idx, unsigned short *tab, int val, unsigned char *out);
int func_021F4E98(char *p, int index, unsigned short *table, unsigned n, unsigned char *out);
u16 func_021F4ED8(const char *p,const u16 *b);
int func_021F4F10(const unsigned short *a, const unsigned short *b);
int func_021F4F50(int a);
void func_021F4F60(void *p);
int func_021F4F68(const u16 *p);
unsigned short func_021F4F6C(char *base, int i, int j);
int func_021F4F7C(char *p, const unsigned short *key, unsigned short *out);
u32 func_021F5004(u16 *s, u32 x);
void func_021F513C(const char *src, int width, int x, int y, int w, int h, char *dst);
void func_021F51A4(const char *src, char *dst, unsigned *a, unsigned *b, unsigned n, unsigned step);
void func_021F51E4(u8 *dst,unsigned arc,u32 member,u32 index,u16 width,u16 height,int pos,int mode,u16 heap);
extern const char d_021F57A8[];


int func_021F4DBC(int a, int b)
{
    return func_0204A1BC(0x77, a + 5, 0, b);
}

void func_021F4DD0(void *p) { func_020307B0(p); }

u16 func_021F4DD8(const u16 *p) { return *p; }

void func_021F4DDC(const char *p,int i,u16 *dst,u32 n,u8 *count) {func_0201F41C((const u16 *)(p+2+i*24),dst,n);if(count){*count=0;while(*count<3 && dst[*count]!=0x3000) ++*count;}}


int func_021F4E18(int p, int idx, unsigned short *tab, int val, unsigned char *out)
{
    unsigned char i;

    func_0201F41C((const u16 *)(p + 8 + 0x18 * idx), (u16 *)((int)tab), val);
    i = 0;
    while (i < 3 && tab[i] != 0x3000) {
        i++;
    }
    if (out != 0) {
        *out = (unsigned char)i;
    }
    return i != 0;
}


int func_021F4E58(int p, int idx, unsigned short *tab, int val, unsigned char *out)
{
    unsigned char i;

    func_0201F41C((const u16 *)(p + 0xe + 0x18 * idx), (u16 *)((int)tab), val);
    i = 0;
    while (i < 3 && tab[i] != 0x3000) {
        i++;
    }
    if (out != 0) {
        *out = (unsigned char)i;
    }
    return i != 0;
}

int func_021F4E98(char *p, int index, unsigned short *table, unsigned n, unsigned char *out)
{
    unsigned char i;
    func_0201F41C((const unsigned short *)(p + 0x14 + 0x18 * index), table, n);
    i = 0;
    while (i < 3 && table[i] != 0x3000) i++;
    if (out != 0) *out = i;
    return i != 0;
}

u16 func_021F4ED8(const char *p,const u16 *b) {int n=func_021F4DD8((const u16 *)p);int i;for(i=0;i<n;i++){if(func_021F4F10((const u16 *)(p+2+i*24),b))return i;}return 65535;}

int func_021F4F10(const unsigned short *a, const unsigned short *b)
{
    unsigned short sentinel = func_02045A98();
    int i;
    for (i = 0; i < 3; i++, a++, b++) {
        if (*a == 0x3000 && *b == sentinel) return 1;
        if (*a != *b) return 0;
        if (*b == sentinel) return 0;
    }
    return 1;
}


int func_021F4F50(int a)
{
    return func_0204A1BC(0x77, 8, 0, a);
}

void func_021F4F60(void *p) {func_020307B0(p);}

int func_021F4F68(const u16 *p) {return *p;}

unsigned short func_021F4F6C(char *base, int i, int j)
{
    return *(unsigned short *)(base + i * 6 + 2 + j * 2);
}

int func_021F4F7C(char *p, const unsigned short *key, unsigned short *out)
{
    int i, j;
    if (*key == 0x3000) return 0;
    for (i = 0; i < func_021F4F68((const u16 *)p); i++) {
        for (j = 0; j < 3; j++) {
            if (*key == func_021F4F6C(p, (unsigned short)i, (unsigned short)j)) {
                p += i * 6;
                do {
                    j = (j + 1) % 3;
                    *out = *(unsigned short *)(p + 2 + j * 2);
                } while (*out == 0x3000);
                return 1;
            }
        }
    }
    return 0;
}

/*
 * note (2026-10-05, wD4 lane09): EXACT. `j = 0;` before `p = bufs[k];` at the k-loop top, declaration
 *   order bufs, ret, h, j, idx, k, v, t, and func_021F4DA4 declared with u16 parameters (as its other
 *   callers do) so the call passes m and j uncast; the conversion temp then takes sp+0x20, not sp+0.
 */
u32 func_021F5004(u16 *s, u32 x)
{
    u8 *bufs[4];
    u32 ret;
    u8 *h;
    int j, idx, k;
    u32 v;
    int t;
    int i, m;
    u32 found;
    u8 *p;
    v = (x & 0x7FFF) | 0x8000;
    for (i = 0; i < 4; i++) bufs[i] = (u8 *)func_021F4D20(i, (u16)v);
    h = (u8 *)func_021F4F50(v & 0xFFFF);
    ret = 1;
    idx = 0;
    while (s[idx] != func_02045A98()) {
        found = 0;
        for (k = 0; (u32)k < 4; k++) {
            j = 0;
            p = bufs[k];
            for (; j < (int)func_021F4DA0((const u16 *)p) && found == 0; j++) {
                for (m = 0; m < (int)func_021F4D9C((const u16 *)p) && found == 0; m++) {
                    if (s[idx] == func_021F4DA4(p, m, j)) found = 1;
                }
            }
        }
        for (t = 0; t < func_021F4F68((const u16 *)h); t++) {
            for (m = 0; m < 3; m++) {
                if (s[idx] == func_021F4F6C((char *)h, (u16)t, (u16)m)) found = 1;
            }
        }
        if (found == 0) {
            ret = 0;
            break;
        }
        idx++;
    }
    func_021F4F60(h);
    for (i = 0; i < 4; i++) func_021F4D34(bufs[i]);
    return ret;
}

void func_021F513C(const char *src, int width, int x, int y, int w, int h, char *dst)
{
    unsigned inOffset;
    unsigned outOffset;
    int i, j;
    unsigned step;
    unsigned target;
    step = width * 4;
    target = (unsigned)dst;
    outOffset = 0;
    for (j = y; j < y + h; j++) {
        for (i = x; i < x + w; i++) {
            inOffset = i * 4 + j * step * 8;
            func_021F51A4(src, (char *)target, &inOffset, &outOffset, 4, step);
        }
    }
}

/*
 * Padding: two zero bytes at 0x021F51E2, then a function prologue.
 */
void func_021F51A4(const char *src, char *dst, unsigned *a, unsigned *b, unsigned n, unsigned step)
{
    int i;
    for (i = 0; i < 8; i++) {
        func_02082D44(src + *a, dst + *b, n);
        *a += step;
        *b += n;
    }
}

static inline u8 *entry(u8 *p,u32 i) {
    if(p) {
        u8 *q=p+0x3c;
        if(q && i<((struct Obj14518 *)p)->f3D) {
                u16 off=((struct Obj14518 *)p)->f42;
                u16 stride=*(u16 *)(q+off);
                return q+off+4+stride*i;
        } else return 0;
    }
    return 0;
}

void func_021F51E4(u8 *dst,unsigned arc,u32 member,u32 index,u16 width,u16 height,int pos,int mode,u16 heap)
{
    Palette pal;
    u32 size=width*height*32;
    void *archive=func_020490F4(arc,heap);
    u8 *raw=func_02049250(archive,member,heap);
    u8 *tex=func_0206E964(raw);
    u8 *pixels;
    u32 offset;
    offset=(*(u32 *)entry(tex,index)&0xffff)*8;
    pixels=tex+((struct Obj14519 *)tex)->f14;
    void *buf=func_02030734((u16)((heap&0x7fff)|0x8000),size,0,d_021F57A8,95);
    func_021F513C((const char *)(pixels+offset),width,0,0,width,height,buf);
    func_0204AA94(func_0204B7F0(dst),buf,size,pos,mode);
    func_020307B0(buf);
    u32 poff=((struct Obj14519 *)tex)->f38;
    func_020862F0(tex+poff,32);
    func_0204B764((const char *)dst,(struct Struct20 *)(&pal));
    if(mode==0 || mode==2) func_0207E51C(tex+poff,func_02063800((char *)&pal,1),32);
    if(mode==1 || mode==2) func_0207E5D0(tex+poff,func_02063800((char *)&pal,2),32);
    func_020307B0(raw);
    func_02049238(archive);
}
