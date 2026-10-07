/*
 * file:     dup_fitting_item_p07.c
 * unit:     yes
 * function: func_021B8AC8, func_021B8B78, func_021B8BB4, func_021B8C6C, func_021B8FA8, func_021B8FF4
 * address:  0x021B8AC8
 * region:   ov133
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B765C 0x021B765C thumb ov133
 *   func_021F50F4 0x021F50F4 thumb ov112
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA258 0x021BA258 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   func_021F4AF0 0x021F4AF0 thumb ov112
 *   func_021F5450 0x021F5450 thumb ov112
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _ffix 0x0209C494 arm
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA250 0x021BA250 thumb ov133
 *   func_021BA238 0x021BA238 thumb ov133
 *   func_021BA228 0x021BA228 thumb ov133
 *   func_021BA240 0x021BA240 thumb ov133
 *   func_021BA24C 0x021BA24C thumb ov133
 *   func_021BA148 0x021BA148 thumb ov133
 *   func_021BA1D8 0x021BA1D8 thumb ov133
 *   func_021BA22C 0x021BA22C thumb ov133
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_021F4EA4 0x021F4EA4 thumb ov112
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   func_021BA20C 0x021BA20C thumb ov133
 *   func_021F4E6C 0x021F4E6C thumb ov112
 *   func_021F4E2C 0x021F4E2C thumb ov112
 *   _fmul 0x0209C77C arm
 */
#include "../../matched/include/Obj00004.h"
#include "../../matched/include/Obj23314.h"
#include "../../matched/include/Obj06499.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef enum { I_ZERO = 0, I_LIMIT = 9 } Index;

typedef unsigned int u32;

typedef struct { int x, y, z; } Vec;

struct O {
    u8 pad0[0x1820];
    void *f1820;
    void *f1824;
    void *f1828;
    u8 pad1[0x1884 - 0x182c];
    void *f1884;
};

extern void *func_021B765C(u8 *p, u16 base, s16 speed, u16 rx, u16 ry);
extern int func_021F50F4(unsigned int);
extern unsigned char *func_021BA184(void *);
extern int func_021BA258(unsigned char *);
extern unsigned char *func_021BA208(unsigned char *);
extern int func_021F4AF0(u8 *p, int index);
extern u8 *func_021F5450(u8 *, int);
extern u32 func_021BA218(u8 *p);
extern u16 func_021BA250(char *p);
extern u8 *func_021BA238(u8 *p);
extern u8 *func_021BA228(u8 *p);
extern u32 func_021BA240(u8 *);
extern void func_021BA24C(char *p, u32 v);
extern void func_021BA148(u8 *p, u8 *q);
extern void func_021BA1D8(u8 *p, u8 *q);
extern void func_021BA22C(u8 *p, const u8 *src);
extern void func_021F4EB4(u32 unused, u32 p, s16 a, s16 b);
extern void func_021F4EA4(u32 unused, u32 p, u32 q);
extern void func_021F4E8C(int, int, Vec *);
extern u32 func_021BA20C(u8 *p);
extern void func_021F4E6C(u8 *p, u8 *e, u32 value);
extern void func_021F4E2C(void *unused, u8 *s, u8 *d);
void func_021B8AC8(u8 *p);
int func_021B8B78(unsigned char *p,unsigned int id);
int func_021B8BB4(u8 *p, void *manager, const int *pos, u16 *limit);
void func_021B8C6C(struct O *p);
void func_021B8FA8(u8 *p);
int func_021B8FF4(int x,int y,int radius,float scale);

void func_021B8AC8(u8 *p)
{
    int n = ((struct Obj00004 *)p)->f182E;
    if (n < 0) n = -n;
    if (n < 48 && (((struct Obj00004 *)p)->f1838 != 0 || ((struct Obj00004 *)p)->f183A != 0)) {
        ((struct Obj00004 *)p)->f1838 += ((struct Obj00004 *)p)->f183A;
        if (((struct Obj00004 *)p)->f1838 > 0) {
            if (((struct Obj00004 *)p)->f183A > 0) ((struct Obj00004 *)p)->f183A -= 128;
            else ((struct Obj00004 *)p)->f183A -= 42;
        } else if (((struct Obj00004 *)p)->f1838 < 0) {
            if (((struct Obj00004 *)p)->f183A < 0) ((struct Obj00004 *)p)->f183A += 128;
            else ((struct Obj00004 *)p)->f183A += 42;
        }
        n = ((struct Obj00004 *)p)->f1838;
        if (n < 0) n = -n;
        if (n < 512) {
            n = ((struct Obj00004 *)p)->f183A;
            if (n < 0) n = -n;
            if (n < 512) {
                ((struct Obj00004 *)p)->f183A = 0;
                ((struct Obj00004 *)p)->f1838 = 0;
            }
        }
        func_021B765C(p, ((struct Obj00004 *)p)->f182C, 0, 72, 48);
    }
}

int func_021B8B78(unsigned char *p,unsigned int id) {int key=func_021F50F4(id);unsigned char *q=func_021BA184(((struct Obj23314 *)p)->f1824);while(q){if(key==func_021F50F4(func_021BA258(q)))return 1;q=func_021BA208(q);}return 0;}

static inline int coordinate(int value, Index offset)
{
    return (int)((float)value / 4096.0f) - offset;
}

/*
 * lever: Inline coordinate conversion with an enum offset keeps the zero subtract and matching spill homes.
 */
int func_021B8BB4(u8 *p, void *manager, const int *pos, u16 *limit)
{
    u16 distance;
    int best;
    int x;
    Index i;
    int enabled, y, dx, dy, n;
    u8 *q;
    distance = *limit * *limit;
    best = 10;
    for (i = I_ZERO; i < I_LIMIT; i++) {
        if (manager == 0) enabled = 1;
        else enabled = func_021F4AF0(manager, i);
        q = func_021F5450(*(u8 * *)&((struct Obj00004 *)p)->f1880, i);
        if (((struct Obj06499 *)q)->f0 == 1 && enabled == 1) {
            x = coordinate(((struct Obj06499 *)q)->f4 + ((struct Obj06499 *)q)->f10, I_ZERO);
            y = coordinate(((struct Obj06499 *)q)->f8 + ((struct Obj06499 *)q)->f14, (Index)16);
            dx = pos[0] - x;
            dy = pos[1] - y;
            n = dx * dx + dy * dy;
            if (n < distance) { distance = n; best = i; }
        }
    }
    *limit = distance;
    return best;
}

void func_021B8C6C(struct O *p)
{
    Vec v1;
    Vec v2;
    Vec v3;
    u32 cnt0;
    u8 *cur;
    int *A;
    int *B;
    int s;
    int flag;
    int n2;
    int *A2;
    int a0;
    int w;
    int a1;
    int a0b;
    int wb;
    int a1b;
    u8 *e;
    u32 data;
    u32 cnt;
    int n;
    int x;
    int d;
    s16 sx;
    int *B2;
    u32 data2;
    e = func_021BA184(p->f1828);
    if (e) {
        do {
            cur = e;
            data = (u32)func_021BA218(e);
            cnt = func_021BA250((char *)e);
            A = (int *)func_021BA238(e);
            B = (int *)func_021BA228(e);
            s = (s16)func_021BA240(e);
            e = (u8 *)func_021BA208(e);
            n = (u16)(cnt - 1);
            if (n != 0) {
                x = s + ((0x1000 - s) * n) / 10;
                sx = x;
                func_021F4EB4((u32)p->f1884, data, sx, sx);
                func_021F4EA4((int)p->f1884, data, (u32)(&v1));
                w = 10 - (u16)n;
                a0 = A[0];
                x = B[0] - a0;
                x *= w;
                x = a0 + x / 10;
                if (x > 0) v1.x = (int)(0.5f + (float)(x << 12));
                else v1.x = (int)((float)(x << 12) - 0.5f);
                a1 = A[1];
                x = B[1] - a1;
                x *= w;
                x = a1 + x / 10;
                if (x > 0) v1.y = (int)(0.5f + (float)(x << 12));
                else v1.y = (int)((float)(x << 12) - 0.5f);
                v1.z = 0x46000;
                func_021F4E8C((int)p->f1884, data, &v1);
                func_021BA24C((char *)cur, n);
            } else {
                func_021BA148(p->f1828, cur);
                func_021BA1D8(cur, p->f1884);
            }
        } while (e);
    }
    flag = 0;
    e = func_021BA184(p->f1820);
    if (e == 0) {
        flag = 1;
        e = func_021BA184(p->f1824);
    }
    if (e) {
        do {
            cnt0 = func_021BA250((char *)e);
            if (cnt0 != 0) {
                data2 = (u32)func_021BA218(e);
                A2 = (int *)func_021BA238(e);
                B2 = (int *)func_021BA228(e);
                n2 = (u16)(cnt0 - 1);
                if (n2 != 0) {
                    func_021F4EA4((int)p->f1884, data2, (u32)(&v2));
                    wb = 10 - n2;
                    a0b = A2[0];
                    x = B2[0] - a0b;
                    x *= wb;
                    x = a0b + x / 10;
                    if (x > 0) v2.x = (int)(0.5f + (float)(x << 12));
                    else v2.x = (int)((float)(x << 12) - 0.5f);
                    a1b = A2[1];
                    x = B2[1] - a1b;
                    x *= wb;
                    x = a1b + x / 10;
                    if (x > 0) v2.y = (int)(0.5f + (float)(x << 12));
                    else v2.y = (int)((float)(x << 12) - 0.5f);
                    func_021F4E8C((int)p->f1884, data2, &v2);
                } else {
                    func_021F4EA4((int)p->f1884, data2, (u32)(&v3));
                    if (B2[0] > 0) v3.x = (int)(0.5f + (float)(B2[0] << 12));
                    else v3.x = (int)((float)(B2[0] << 12) - 0.5f);
                    if (B2[1] > 0) v3.y = (int)(0.5f + (float)(B2[1] << 12));
                    else v3.y = (int)((float)(B2[1] << 12) - 0.5f);
                    func_021F4E8C((int)p->f1884, data2, &v3);
                    func_021BA22C(e, (const u8 *)B2);
                }
                func_021BA24C((char *)e, n2);
            }
            e = (u8 *)func_021BA208(e);
            if (e == 0 && flag == 0) {
                flag = 1;
                e = func_021BA184(p->f1824);
            }
        } while (e);
    }
}

void func_021B8FA8(u8 *p)
{
    if (*(u8 * *)&((struct Obj00004 *)p)->f38 == 0) {
        func_021F4E6C(((struct Obj00004 *)p)->f1884, ((struct Obj00004 *)p)->f4C, 0);
        return;
    }
    if (((struct Obj00004 *)p)->f50 == *(u16 *)func_021BA20C(*(u8 * *)&((struct Obj00004 *)p)->f38)) {
        func_021F4E6C(((struct Obj00004 *)p)->f1884, ((struct Obj00004 *)p)->f4C, 1);
        func_021F4E2C(((struct Obj00004 *)p)->f1884, (u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38), ((struct Obj00004 *)p)->f4C);
    }
}

int func_021B8FF4(int x,int y,int radius,float scale) {short k=(short)((float)x*scale);if(k*k+y*y<radius*radius)return 1;return 0;}
