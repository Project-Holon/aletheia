/*
 * file:     nhttp_rap_p05.c
 * unit:     yes
 * function: func_021B98F8, func_021B99B8, func_021B99DC, func_021B99F0, func_021B99F4, func_021B9A14, func_021B9A1C
 * address:  0x021B98F8
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
 *   func_021BE880  0x021BE880  arm  ov114
 */
#include "../../matched/include/Obj10329.h"
#include "../../matched/include/G_Pair.h"
#include "../../matched/include/Obj08036.h"
#include "../../matched/include/Obj22572.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct { u8 a,b,c,d; } Record;

extern unsigned int func_021B95A0(unsigned int, unsigned int);
extern void func_021B95B0(int);
extern int func_021B95C0(int, int, unsigned int *);
extern int func_021BE648(int a, int b, int c);
extern void *func_021BF04C(char *url_p, int method, char *buf_p, u32 len, int (*callback)(void *, int, void *), void *userParam_p);
extern u32 func_021BE6AC(void);
extern int func_021BE9C8(int a, int b, int c);
extern int func_021BE79C(void *handle, void *value_p, unsigned long length);
extern void func_02034714(const char *, u32, const char *);
extern void func_02082BCC(int, int, int);
extern char *func_0208CADC(char *, const char *);
extern void func_0203D7FC(void *);
extern int func_021BE880(int);
extern void *func_021B9AA8(int);
extern void func_021B9AF8(void *);
extern void func_021CAB1C(void *, void *, int);
extern int func_021CAA70(void *data_ptr, int data_len, void *sign_ptr, void *mod_ptr);
int func_021B98F8(u8 *p);
void func_021B99B8(u8 *p);
int func_021B99DC(u8 *p);
int func_021B99F0(u8 *p);
u32 func_021B99F4(u32 p,u32 i);
u8 *func_021B9A14(u8 *p,u32 i);
int func_021B9A1C(void *a, int b, int c, char *d, u16 e);
extern char d_021CE2D4[], d_021CE280[];
extern struct Pair d_021CE284;
extern u16 d_021CE31C;
extern unsigned int d_021CE320[];

int func_021B98F8(u8 *p)
{
    int h;
    if (p == 0) return 0;
    if (func_021BE648((int)func_021B95A0, (int)func_021B95B0, 12) != 0) {
        func_02034714(d_021CE2D4, 0, d_021CE2D4);
        return 0;
    }
    func_02082BCC((int)(p+0x410), 0, 4);
    func_0208CADC((char *)(p+0x410), (char *)((u32 *)&d_021CE284)[14]);
    h = (int)func_021BF04C((char *)((u32 *)&d_021CE284)[14], ((u32 *)&d_021CE284)[15], (char *)(p+0x10), 0x400, (int (*)(void *, int,  void *))func_021B95C0, 0);
    if (h == 0) {
        func_021BE6AC();
        if (h == 0) func_02034714(d_021CE2D4, 0, d_021CE2D4);
        return 0;
    }
    ((struct Obj10329 *)p)->fC = h;
    if (func_021BE9C8(h, (int)d_021CE280, 1) < 0) {
        func_02034714(d_021CE2D4, 0, d_021CE2D4);
        return 0;
    }
    func_021BE79C((void *)h, (void *)(((struct Obj10329 *)p)->f0), ((struct Obj10329 *)p)->f4);
    return 1;
}


void func_021B99B8(u8 *p)
{
    if (p != 0) {
        if (((struct Obj08036 *)p)->f0 != 0)
            func_0203D7FC((void *)((struct Obj08036 *)p)->f0);
        ((struct Obj08036 *)p)->f0 = 0;
        ((struct Obj08036 *)p)->f4 = 0;
    }
    *(u32 *)0x021CF960 = 0;
}


int func_021B99DC(u8 *p)
{
    if (p != 0)
        return func_021BE880(((struct Obj22572 *)p)->fC);
    return 0;
}

int func_021B99F0(u8 *p) { return *p; }

u32 func_021B99F4(u32 p,u32 i) { u32 q=p+1; return (((Record *)q)[i].a<<24)|(((Record *)q)[i].b<<16)|(((Record *)q)[i].c<<8)|((Record *)q)[i].d; }

u8 *func_021B9A14(u8 *p,u32 i) { return p+1+i*4; }

int func_021B9A1C(void *a, int b, int c, char *d, u16 e)
{
    int result;
    d_021CE31C = e;
    func_021CAB1C(func_021B9AA8, func_021B9AF8, 0);
    result = func_021CAA70((void *)a, b*c, (void *)d, d_021CE320);
    d_021CE31C = 0xffff;
    return result;
}
