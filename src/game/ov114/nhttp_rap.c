/*
 * file:     nhttp_rap.c
 * unit:     yes
 * function: func_021B95A0, func_021B95B0, func_021B95C0, func_021B95D4, func_021B973C, func_021B9748, func_021B9774, func_021B9790, func_021B97F4, func_021B9800, func_021B9838, func_021B984C, func_021B98A0, func_021B98D8, func_021B98F8, func_021B99B8, func_021B99DC, func_021B99F0, func_021B99F4, func_021B9A14, func_021B9A1C, func_021B9A64, func_021B9A8C, func_021B9A94, func_021B9AA8, func_021B9AF8, func_021B9B00, func_021B9B4C, func_021B9B58
 * address:  0x021B95A0
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWC_RAPCOMMON_Alloc  0x02156F5C  thumb  ov009
 *   DWC_RAPCOMMON_Free  0x02156FDC  thumb  ov009
 *   d_021CE2D4 0x021CE2D4 data a4
 *   d_021CE284 0x021CE284 data a4
 *   d_021CE280 0x021CE280 data a4
 *   func_021BE648 0x021BE648 arm ov114
 *   func_021BF04C 0x021BF04C arm ov114
 *   func_021BE9C8 0x021BE9C8 arm ov114
 *   func_021BE6BC 0x021BE6BC arm ov114
 *   func_021BE8E8 0x021BE8E8 arm ov114
 *   func_02034714 0x02034714 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0208D80C 0x0208D80C arm
 *   func_021BF308  0x021BF308  arm  ov114
 *   func_021BE698  0x021BE698  arm  ov114
 *   func_021BF184  0x021BF184  arm  ov114
 *   func_021BE880  0x021BE880  arm  ov114
 *   func_020307B0 0x020307B0 arm
 *   func_02082D44 0x02082D44 arm
 *   d_021CE31C 0x021CE31C data a2
 *   d_021CE320 0x021CE320 data a4
 *   d_021CE3B8 0x021CE3B8 data a4
 *   d_021CE3A0 0x021CE3A0 data a4
 *   func_02086028  0x02086028  arm
 *   GFL_NET_STATE_SetError  0x0203C9AC  arm  arm9
 *   GFL_NET_AllocAligned  0x0203D7C8  arm  arm9
 *   GFL_NET_FreeAligned  0x0203D7FC  arm  arm9
 */

#include "../../matched/include/Obj08035.h"
#include "../../matched/include/G_Pair.h"
#include "../../matched/include/Obj22570.h"
#include "../../matched/include/Obj22571.h"
#include "../../matched/include/Obj03763.h"
#include "../../matched/include/Obj03763.h"
#include "../../matched/include/Obj13848.h"
#include "../../matched/include/Obj03250.h"
#include "../../matched/include/Obj10328.h"
#include "../../matched/include/Obj10329.h"
#include "../../matched/include/Obj08036.h"
#include "../../matched/include/Obj22572.h"
#include "../../matched/include/Obj03764.h"

struct Sub0200852CObj;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct { u32 format,mode; } Pair;

typedef unsigned short u16;

typedef struct { char *buffer; int cursor; char *source; } Record_021B95A0;

typedef struct { u8 a,b,c,d; } Record_021B98F8;

extern unsigned int DWC_RAPCOMMON_Alloc(unsigned int, unsigned int, unsigned int);
extern void DWC_RAPCOMMON_Free(u32 a, void *p, int b);
extern int func_021BE648(int a, int b, int c);
extern void *func_021BF04C(char *url_p, int method, char *buf_p, u32 len, int (*callback)(void *, int, void *), void *userParam_p);
extern int func_021BE9C8(int a, int b, int c);
extern int func_021BE6BC(int,const char *,const char *);
extern int func_021BE8E8(void *handle, char *username_p, char *password_p);
extern void func_02034714(const char *,u32,const char *);
extern void func_02082BCC(void *,int,unsigned);
extern int func_0208D80C(char *,int,const char *,...);
extern int func_021BF308(int);
extern void GFL_NET_STATE_SetError(int a, u32 b, u32 c, u32 d);
extern int func_021BF184(int a);
extern void func_021BE698(void);
extern int func_021BF488(int a);
extern int func_021BF4B0(u32, int *, int *);
extern int func_021BE838(void *handle, char **value_pp);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void *GFL_NET_AllocAligned(unsigned int a, unsigned int size, const char *c, unsigned short d);
extern void func_02082D44(int, int, int);
extern u32 func_021BE6AC(void);
extern int func_021BE79C(void *handle, void *value_p, unsigned long length);
extern char *func_0208CADC(char *, const char *);
extern void GFL_NET_FreeAligned(void *);
extern int func_021BE880(int);
extern void func_021CAB1C(void *, void *, int);
extern int func_021CAA70(void *data_ptr, int data_len, void *sign_ptr, void *mod_ptr);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern const void *func_020084F4(const void *p);
extern void func_0201F41C(const u16 *src, u16 *dst, u32 n);
unsigned int func_021B95A0(unsigned int a, unsigned int b);
void func_021B95B0(int a);
int func_021B95C0(int a, int b, unsigned int *p);
int func_021B95D4(int index,u8 *p);
int func_021B973C(char *p);
int func_021B9748(u8 *p);
void func_021B9774(u8 *p);
int func_021B9790(u8 *p);
u8 *func_021B97F4(u8 *p);
u8 *func_021B9800(int a, int b, int c);
void func_021B9838(u8 *p);
void func_021B984C(Record_021B95A0 *p, int x);
void func_021B98A0(u8 *p, int a, int b, int c);
void func_021B98D8(u8 *p, int a, int n);
int func_021B98F8(u8 *p);
void func_021B99B8(u8 *p);
int func_021B99DC(u8 *p);
int func_021B99F0(u8 *p);
u32 func_021B99F4(u32 p,u32 i);
u8 *func_021B9A14(u8 *p,u32 i);
int func_021B9A1C(void *a, int b, int c, char *d, u16 e);
u8 *func_021B9A64(int a, int b, int c);
void func_021B9A8C(void *buf);
void func_021B9A94(int p, int a, u32 b, int n);
void *func_021B9AA8(int n);
void func_021B9AF8(void *p);
void func_021B9B00(u8 *p, int a);
extern char d_021CE2D4[],d_021CE280[];
extern struct Pair d_021CE284[];
extern u16 d_021CE31C;
extern unsigned int d_021CE320[];
extern char d_021CE3B8[], d_021CE3A0[];








unsigned int func_021B95A0(unsigned int a, unsigned int b)
{
    return DWC_RAPCOMMON_Alloc(13, a, b);
}








void func_021B95B0(int a)
{
    DWC_RAPCOMMON_Free(13, (void *)a, 0);
}








int func_021B95C0(int a, int b, unsigned int *p)
{
    switch (b) {
    case 1: break;
    case 2:
    case 3: p[2] = 0; break;
    }
    return 0;
}








int func_021B95D4(int index,u8 *p)
{
    int h;
    if(func_021BE648((int)func_021B95A0,(int)func_021B95B0,12)!=0) {
        func_02034714(d_021CE2D4,0,d_021CE2D4);
        return 0;
    }
    if(p==0) return 0;
    func_02082BCC(p+0x410,0,4);
    if(index==4) func_0208D80C((char *)(p+0x410),400,(char *)d_021CE284[index].format,((struct Obj08035 *)p)->f8+69);
    else func_0208D80C((char *)(p+0x410),400,(char *)d_021CE284[index].format,((struct Obj08035 *)p)->f5A4,21,2,1,((struct Obj08035 *)p)->f8+69);
    h=(int)func_021BF04C((char *)((u32)(p+0x410)),d_021CE284[index].mode,(char *)(p+0x10),1024,(int (*)(void *, int,  void *))func_021B95C0,(void *)((int)p));
    if(h==0) func_02034714(d_021CE2D4,0,d_021CE2D4);
    if(h==0) return 0;
    ((struct Obj08035 *)p)->fC=h;
    if(func_021BE9C8(h,(int)d_021CE280,1)<0) {
        func_02034714(d_021CE2D4,0,d_021CE2D4);
        return 0;
    }
    if(func_021BE6BC(h,d_021CE2D4+4,d_021CE2D4+12)!=0) {
        func_02034714(d_021CE2D4,0,d_021CE2D4);
        return 0;
    }
    if(func_021BE6BC(h,d_021CE2D4+16,d_021CE2D4+28)!=0) {
        func_02034714(d_021CE2D4,0,d_021CE2D4);
        return 0;
    }
    if(func_021BE8E8((void *)h,d_021CE2D4+40,d_021CE2D4+48)!=0) {
        func_02034714(d_021CE2D4,0,d_021CE2D4);
        return 0;
    }
    return 1;
}








/*
 * extent: the following labelled function is func_021B9748.
 */
int func_021B973C(char *p)
{
    if (p) return ((struct Obj22570 *)p)->fC;
    return 0;
}









int func_021B9748(u8 *p)
{
    int h;

    if (p != 0) {
        h = func_021BF308(((struct Obj22571 *)p)->fC);
        if (h != 0) {
            GFL_NET_STATE_SetError(h, 2, h, 0x3f6);
            return h;
        }
        return 0;
    }
    return 1;
}









void func_021B9774(u8 *p)
{
    if (p == 0)
        return;
    if (((struct Obj03763 *)p)->fC == 0)
        return;
    func_021BF184(((struct Obj03763 *)p)->fC);
    ((struct Obj03763 *)p)->fC = 0;
    func_021BE698();
}







/*
 * func_021BF488 0x021BF488 arm ov114
 * func_021BF4B0 0x021BF4B0 arm ov114
 * func_021BE838 0x021BE838 arm ov114
 * func_021B9774 0x021B9774 thumb ov114
 * GFL_NET_STATE_SetError 0x0203C9AC arm
 */
int func_021B9790(u8 *p)
{
    int a,b,c;
    int result;
    if (p == 0) return -1;
    if (((struct Obj03763 *)p)->fC == 0) return 0;
    result = func_021BF488(((struct Obj03763 *)p)->fC);
    if (result == 15) {
        func_021BF4B0(((struct Obj03763 *)p)->fC, &a, &b);
    } else {
        int x = func_021BF488(((struct Obj03763 *)p)->fC);
        if (x == 0) func_021BE838((void *)(((struct Obj03763 *)p)->fC), (char **)(&c));
        else GFL_NET_STATE_SetError(x, 2, x, 0x3f6);
        func_021B9774(p);
        return result;
    }
    return result;
}







u8 *func_021B97F4(u8 *p) { if(p==0) return 0; return p+0x10; }








u8 *func_021B9800(int a, int b, int c)
{
    u8 *p = func_02030734(a, 0x5a8, 1, (const char *)0x021CE310, 0x1aa);

    *(u32 *)0x021CF960 = (u32)p;
    ((struct Obj13848 *)p)->f5A4 = b;
    ((struct Obj13848 *)p)->f8 = c;
    return p;
}







/*
 * Frees the record's buffer, then the record itself.
 */
void func_021B9838(u8 *p)
{
    if (p == 0)
        return;
    func_021B99B8(p);
    func_020307B0(p);
}






void func_021B984C(Record_021B95A0 *p, int x)
{
    char c;
    x = (u16)x;
    if (p) {
        p->cursor = 0;
        while ((c = (p->source + p->cursor)[0x45]) != 0) {
            p->buffer[p->cursor] = c;
            p->cursor++;
        }
        p->buffer[p->cursor++] = 0;
        p->buffer[p->cursor++] = x >> 8;
        p->buffer[p->cursor++] = x;
    }
}






void func_021B98A0(u8 *p, int a, int b, int c)
{
    void *q;

    if (p == 0)
        return;
    q = GFL_NET_AllocAligned(a, b + 0x130, (const char *)0x021CE310, 0x1f5);
    ((struct Obj03250 *)p)->f0 = (u32)q;
    func_02082BCC((void *)((int)q), 0, b + 0x130);
    func_021B984C((Record_021B95A0 *)p, c);
}






/*
 * Appends `n` bytes at the write cursor and advances it.
 */
void func_021B98D8(u8 *p, int a, int n)
{
    if (p == 0)
        return;
    func_02082D44(a, ((struct Obj10328 *)p)->f0 + ((struct Obj10328 *)p)->f4, n);
    ((struct Obj10328 *)p)->f4 += n;
}




int func_021B98F8(u8 *p)
{
    int h;
    if (p == 0) return 0;
    if (func_021BE648((int)func_021B95A0, (int)func_021B95B0, 12) != 0) {
        func_02034714(d_021CE2D4, 0, d_021CE2D4);
        return 0;
    }
    func_02082BCC((void *)((int)(p+0x410)), 0, 4);
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
            GFL_NET_FreeAligned((void *)((struct Obj08036 *)p)->f0);
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




u32 func_021B99F4(u32 p,u32 i) { u32 q=p+1; return (((Record_021B98F8 *)q)[i].a<<24)|(((Record_021B98F8 *)q)[i].b<<16)|(((Record_021B98F8 *)q)[i].c<<8)|((Record_021B98F8 *)q)[i].d; }




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




/*
 * Allocates and zeroes an a*b byte scratch block from tag 0xb9.
 */
u8 *func_021B9A64(int a, int b, int c)
{
    int n = b * a;
    u8 *p = func_02030734(c, n, 0, (const char *)0x021CE3A0, 0xb9);

    func_02082BCC((void *)((int)p), 0, n);
    return p;
}



void func_021B9A8C(void *buf)
{
    func_020307B0(buf);
}



void func_021B9A94(int p, int a, u32 b, int n) { func_02082D44(a,p+b*n,b); }


void *func_021B9AA8(int n)
{
    void *p;
    if (d_021CE31C == 0xffff)
        func_02034714(d_021CE3B8, 0, d_021CE3B8);
    p = func_02030734(d_021CE31C, n, 0, d_021CE3A0, 0xe9);
    if (p == 0)
        func_02034714(d_021CE3B8, 0, d_021CE3B8);
    return p;
}


void func_021B9AF8(void *p)
{
    func_020307B0(p);
}



void func_021B9B00(u8 *p, int a)
{
    func_02082BCC((void *)((int)p), 0, 0x64);
    p[0] = 0x15;
    p[1] = 2;
    p[2] = func_0200856C((const struct Sub0200852CObj *)a);
    p[3] = func_02008570((const struct Sub0200852CObj *)a);
    ((struct Obj03764 *)p)->f4 = func_02008530((const struct Sub0200852CObj *)a);
    func_0201F41C((const u16 *)func_020084F4((const void *)a), (u16 *)(p + 8), 8);
    ((struct Obj03764 *)p)->f18 = 0;
    ((struct Obj03764 *)p)->f24 = 0;
    ((struct Obj03764 *)p)->f5C = 0;
}

#pragma thumb off

typedef unsigned char u8;

typedef unsigned int u32;

extern void func_02086004(void);
extern void func_02086028(void);
void func_021B9B4C(int *mutex_p);
void func_021B9B58(void);


void func_021B9B4C(int *mutex_p)
{
    func_02086004();
}


/*
 * ARM linker veneer / far tail call: ldr ip,[pc,#0]; bx ip; .word
 * 0x02086028, printed as a .word run by disasm.py at 0x021B9B58 in ov114.
 * Blocker target of func_021BEFCC (pkt_021B9500).
 */
void func_021B9B58(void)
{
    func_02086028();
}
