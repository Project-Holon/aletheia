/*
 * file:     zukan_info_p04.c
 * unit:     yes
 * function: func_021BA934, func_021BA960, func_021BAA08, func_021BAA4C, func_021BACB0, func_021BAF50, func_021BAF7C, func_021BAFC4, func_021BB0E4, func_021BB0FC, func_021BB13C, func_021BB160, func_021BB184, func_021BB214
 * address:  0x021BA934
 * region:   ov206
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02045770 0x02045770 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_020437DC 0x020437DC arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201AF80 0x0201AF80 thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   d_020A7370 0x020A7370 data
 *   d_021BC110 0x021BC110 data a2
 *   d_021BC11C 0x021BC11C data a2
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020437AC  0x020437AC  arm
 *   func_0204384C  0x0204384C  arm
 *   func_020439A0  0x020439A0  arm
 *   func_020450F0  0x020450F0  arm
 *   func_021BB23C 0x021BB23C thumb
 *   func_021BB2D4 0x021BB2D4 thumb
 *   func_021BB2C4 0x021BB2C4 thumb
 *   func_0202D81C 0x0202D81C thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
#include "../../matched/include/Obj00173.h"
#include "../../matched/include/Obj00031.h"
#include "../../matched/include/Obj14637.h"
#include "../../matched/include/Obj25402.h"
#include "../../matched/include/Obj08388.h"
#include "../../matched/include/Obj25403.h"
#include "../../matched/include/Obj10886.h"
#include "../../matched/include/Obj00790.h"
#include "../../matched/include/Obj10887.h"

#define H(o) (*(unsigned short *)(p + (o)))
#define W(o) (*(int *)(p + (o)))
struct Descriptor;
struct PrintSys;
struct Bmp;
struct StrObj;
struct U16Vec;
struct WordSet;
struct MsgBank;
struct CharBuf;
struct Cfg;
struct Obj020437AC;
typedef unsigned int   u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef enum { ZERO } Zero;

typedef struct {
    unsigned short f0;
    char pad2[0x4d - 2];
    unsigned char f4d;
    char pad4e[0x8c - 0x4e];
    int f8c;
    int f90;
} Ent;

extern void func_0201C6EC(struct PrintSys *p);
extern unsigned int func_020452E8(struct Descriptor *d);
extern u32 func_020307B0(void *p);
extern void *func_02045770(struct Descriptor *);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u16 *func_0201AF80(u32 heap, u16 *countOut);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern unsigned int func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern struct Bmp *func_0204384C(u32 arc, u32 member, u32 heap2, u32 heap);
extern int func_020450F0(int, int, int, int, int, int, int);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_021BB23C(char *p, int x, int y, int index);
extern void func_021BB2D4(char *p);
extern void func_021BB2C4(char *, int);
extern int func_0202D81C(int,int,int,int,int,int,int,int,int,unsigned short);
extern int func_0202D7D8(int,int,int,int,int,int,int,int,unsigned short,unsigned short);
extern int func_0202D898(int,int,int,int,int,int,int,int,unsigned short);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
void func_021BA934(char *p);
void func_021BA960(int heap,int window,void *printer,int font,int input,unsigned short right,unsigned short y,unsigned short color,int alignment,int expansion);
void func_021BAA08(int heap,int window,struct MsgBank *bank,void *printer,int font,int message,unsigned short x,unsigned short y,unsigned short color,int alignment,int expansion);
void func_021BAA4C(char *p);
void func_021BACB0(char *p, int idx);
void func_021BAF50(char *p);
void func_021BAF7C(char *p);
void func_021BAFC4(Ent *e);
void func_021BB0E4(char *p);
void func_021BB0FC(void *obj);
void func_021BB13C(void *a0, void *a1, void *a2, void *a3);
void func_021BB160(char *p, int i);
void func_021BB184(char *p,int index);
void func_021BB214(char *p, int i);
extern void *d_020A7370;
extern const unsigned short d_021BC110[];
extern const unsigned short d_021BC11C[];

void func_021BA934(char *p)
{
    int i;
    func_0201C6EC(((struct Obj00173 *)p)->f2C);
    for(i=0;i<4;i++){
        *(int *)(p+i*4+124)=1;
        func_020452E8(*(void **)(p+i*4+108));
    }
    func_020307B0(((struct Obj00173 *)p)->f2B0);
}

void func_021BA960(int heap,int window,void *printer,int font,int input,unsigned short right,unsigned short y,unsigned short color,int alignment,int expansion)
{
    int buffer=(int)func_02045770((struct Descriptor *)window);
    unsigned short x;
    int text;
    if(expansion) {
        text=(int)func_020457B0(128,heap);
        func_0201F250((struct WordSet *)expansion,(void *)text,(void *)input);
    } else text=input;
    switch(alignment) {
    case 0: x=right; break;
    case 1: {
        unsigned short width=func_0201D304((struct StrObj *)text,font,0);
        x=right-width;
        break;
    }
    case 2: {
        unsigned short width=func_0201D304((struct StrObj *)text,font,0);
        x=(func_020437DC((const struct Bmp *)buffer)-width)/2;
        break;
    }
    }
    func_0201C724(printer,(int)buffer,(short)x,(short)y,(int)text,(int)font,color);
    if(expansion) func_02045808((struct U16Vec *)text);
}

void func_021BAA08(int heap,int window,struct MsgBank *bank,void *printer,int font,int message,unsigned short x,unsigned short y,unsigned short color,int alignment,int expansion)
{
    int text=(int)func_02045EC0(bank,message);
    func_021BA960(heap,window,printer,font,text,x,y,color,alignment,expansion);
    func_02045808((struct U16Vec *)text);
}

/*
 * note: *(p+0x1e0) is read first into a local, so 0x1e0 is the first constant built and the
 *   0x1e4..0x1f0 and 0x2b0 offsets derive from it. The last loop stores the constant 0 (a copy of k's 0).
 */
void func_021BAA4C(char *p)
{
    int l2c = ((struct Obj00031 *)p)->f1E0;
    int l28 = ((struct Obj00031 *)p)->f1E4;
    int l24 = ((struct Obj00031 *)p)->f1E8;
    int l20 = ((struct Obj00031 *)p)->f1EC;
    int l1c = ((struct Obj00031 *)p)->f1F0;
    u16 t = ((struct Obj00031 *)p)->fC;
    u16 i = 0;
    u32 h2;
    u16 r7;
    u16 r6;
    u16 m;
    void *name;
    u8 k;
    if (((struct Obj00031 *)p)->fE != 0) {
        u16 *arr = *(u16 * *)&((struct Obj00031 *)p)->f2B0;
        do {
            t = arr[t];
            if (t == 0) break;
            i = (u16)(i + 1);
        } while (i != ((struct Obj00031 *)p)->fE);
    }
    if (t == 0) t = ((struct Obj00031 *)p)->fC;
    if (((struct Obj00031 *)p)->f18 != 2) {
        func_021BAA08(((struct Obj00031 *)p)->f0, ((struct Obj00031 *)p)->f6C, (struct MsgBank *)l2c, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, 0x90, 0, 5, 0x3c40, 2, 0);
    }
    r7 = ((struct Obj00031 *)p)->fC;
    if (((struct Obj00031 *)p)->f4 == 0) {
        u16 *tab = func_0201AF80(((struct Obj00031 *)p)->f0, 0);
        r7 = tab[((struct Obj00031 *)p)->fC];
        func_020307B0(tab);
    }
    if (r7 != 0x3e7) {
        h2 = (u32)func_0201EC64(((struct Obj00031 *)p)->f0);
        func_0201EFA4((struct WordSet *)h2, 0, r7, 3, 2, 1);
        func_021BA960(((struct Obj00031 *)p)->f0, *(int *)&((struct Obj00031 *)p)->f70, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, ((struct Obj00031 *)p)->f270, 8, 5, 0x3e7 + 0x59, 0, h2);
        func_0201ED04((struct WordSet *)h2);
    } else {
        func_021BA960(((struct Obj00031 *)p)->f0, *(int *)&((struct Obj00031 *)p)->f70, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, ((struct Obj00031 *)p)->f274, 8, 5, 0x3e7 + 0x59, 0, 0);
    }
    name = func_02045EC0(d_020A7370, ((struct Obj00031 *)p)->fC);
    func_0201C724((void *)(((struct Obj00031 *)p)->f2C), (u32)func_02045770(((struct Obj00031 *)p)->f70), 0x30, 5, (u32)name, ((struct Obj00031 *)p)->f28, 0x440);
    func_02045808(name);
    m = 0;
    if (((struct Obj00031 *)p)->f8 != 0) m = ((struct Obj00031 *)p)->fC;
    func_021BAA08(((struct Obj00031 *)p)->f0, *(int *)&((struct Obj00031 *)p)->f70, (struct MsgBank *)l28, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, m, 0, 0x16, 0x440, 2, 0);
    func_021BA960(((struct Obj00031 *)p)->f0, ((struct Obj00031 *)p)->f74, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, ((struct Obj00031 *)p)->f278, 0, 4, 0x440, 0, 0);
    func_021BA960(((struct Obj00031 *)p)->f0, ((struct Obj00031 *)p)->f74, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, ((struct Obj00031 *)p)->f27C, 0, 0x14, 0x440, 0, 0);
    r6 = 0;
    if (((struct Obj00031 *)p)->f8 != 0) r6 = t;
    func_021BAA08(((struct Obj00031 *)p)->f0, ((struct Obj00031 *)p)->f74, (struct MsgBank *)l24, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, r6, 0x65, 4, 0x440, 1, 0);
    r6 = 0;
    if (((struct Obj00031 *)p)->f8 != 0) r6 = t;
    func_021BAA08(((struct Obj00031 *)p)->f0, ((struct Obj00031 *)p)->f74, (struct MsgBank *)l20, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, r6, 0x66, 0x14, 0x440, 1, 0);
    t = 0;
    if (((struct Obj00031 *)p)->f8 != 0) t = ((struct Obj00031 *)p)->fC;
    func_021BAA08(((struct Obj00031 *)p)->f0, ((struct Obj00031 *)p)->f78, (struct MsgBank *)l1c, (void *)(((struct Obj00031 *)p)->f2C), ((struct Obj00031 *)p)->f28, t, 4, 5, 0x3c40, 0, 0);
    for (k = 0; k < 4; k++) {
        *(int *)(p + k * 4 + 0x7c) = 0;
    }
    func_021BAF7C(p);
}


void func_021BACB0(char *p, int idx)
{
    int t0 = W(0x1e0);
    int a30 = ((int *)(p + (idx + 5) * 4))[0x78];
    int a2c = ((int *)(p + (idx + 0xb) * 4))[0x78];
    int a28 = ((int *)(p + (idx + 0x11) * 4))[0x78];
    int a24 = ((int *)(p + (idx + 0x17) * 4))[0x78];
    int a20 = ((int *)(p + (idx + 0x1d) * 4))[0x78];
    unsigned short cur = H(0xc);
    unsigned short c;
    int h;
    int fl;
    unsigned char i;

    if (cur == 0x1e7 && H(0xe) != 0) {
        cur = 0x1ee;
    } else if (cur == 0x1ec && H(0xe) != 0) {
        cur = 0x1ef;
    }
    if (W(0x18) != 2) {
        func_021BAA08(H(0), W(0x6c), (struct MsgBank *)t0, (void *)W(0x2c), W(0x28), 0x90, 0, 5, 0x3c40, 2, 0);
    }
    c = H(0xc);
    if (W(4) == 0) {
        unsigned short *tab = func_0201AF80(H(0), 0);
        c = tab[H(0xc)];
        func_020307B0(tab);
    }
    if (c != 0x3e7) {
        h = (int)func_0201EC64(H(0));
        if (idx == 0) {
            func_0201EFA4((struct WordSet *)h, 0, c, 3, 2, 0);
        } else {
            func_0201EFA4((struct WordSet *)h, 0, c, 3, 2, 1);
        }
        func_021BA960(H(0), W(0x70), (void *)W(0x2c), W(0x28), W(0x270), 8, 5, 0x440, 0, h);
        func_0201ED04((struct WordSet *)h);
    } else {
        func_021BA960(H(0), W(0x70), (void *)W(0x2c), W(0x28), W(0x274), 8, 5, 0x440, 0, 0);
    }
    c = 0;
    func_021BAA08(H(0), W(0x70), (struct MsgBank *)a20, (void *)W(0x2c), W(0x28), H(0xc), 0x30, 5, 0x440, 0, 0);
    if (W(8) != 0) c = H(0xc);
    func_021BAA08(H(0), W(0x70), (struct MsgBank *)a30, (void *)W(0x2c), W(0x28), c, 0, 0x16, 0x440, 2, 0);
    func_021BA960(H(0), W(0x74), (void *)W(0x2c), W(0x28), ((int *)(p + (idx + 4) * 4))[0x9c], 0, 4, 0x440, 0, 0);
    func_021BA960(H(0), W(0x74), (void *)W(0x2c), W(0x28), ((int *)(p + (idx + 0xa) * 4))[0x9c], 0, 0x14, 0x440, 0, 0);
    c = 0;
    if (W(8) != 0) c = cur;
    func_021BAA08(H(0), W(0x74), (struct MsgBank *)a2c, (void *)W(0x2c), W(0x28), c, d_021BC110[idx], 4, 0x440, 1, 0);
    c = 0;
    if (W(8) != 0) c = cur;
    func_021BAA08(H(0), W(0x74), (struct MsgBank *)a28, (void *)W(0x2c), W(0x28), c, d_021BC11C[idx], 0x14, 0x440, 1, 0);
    c = 0;
    if (W(8) != 0) c = H(0xc);
    func_021BAA08(H(0), W(0x78), (struct MsgBank *)a24, (void *)W(0x2c), W(0x28), c, 4, 5, 0x3c40, 0, 0);
    for (i = 0; i < 4; i++) {
        ((int *)(p + i * 4))[0x1f] = 0;
    }
    func_021BAF7C(p);
}

void func_021BAF50(char *p)
{
    int i;
    func_0201C6EC((struct PrintSys *)(((struct Obj25402 *)p)->f2C));
    for (i = 0; i < 4; i++) {
        char *slot = p + i * 4;
        ((struct Obj14637 *)slot)->f7C = 1;
        func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)((struct Obj14637 *)slot)->f6C)), 0);
    }
}

void func_021BAF7C(char *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        char *slot = p + i * 4;
        if (((struct Obj08388 *)slot)->f7C == 0 && func_0201C6C4((struct PrintSys *)(((struct Obj25403 *)p)->f2C), (void *)func_02045770((struct Descriptor *)((struct Obj08388 *)slot)->f6C)) == 0) {
            int window = ((struct Obj08388 *)slot)->f6C;
            func_02045334((struct Descriptor *)window);
            func_02045374((struct Cfg *)window);
            func_02041B6C(func_02045730((struct Descriptor *)window));
            ((struct Obj08388 *)slot)->f7C = 1;
        }
    }
}


void func_021BAFC4(Ent *e)
{
    Zero z = ZERO;
    int s = (int)func_0204384C(0x9f, 0x19, z, e->f0);
    int q;

    e->f8c = func_020450F0(e->f4d, 0xc, 4, 4, 3, z, z);
    q = (int)func_02045770((struct Descriptor *)e->f8c);
    func_020439A0((struct Bmp *)s, (struct Bmp *)q, 8, 0, z, z, 0x20, 0x18, z);

    e->f90 = func_020450F0(e->f4d, 0xc, 4, 4, 3, z, z);
    q = (int)func_02045770((struct Descriptor *)e->f90);
    func_020439A0((struct Bmp *)s, (struct Bmp *)q, 0xa8, 8, z, z, 0x20, 8, z);

    q = (int)func_02045770((struct Descriptor *)e->f90);
    func_020439A0((struct Bmp *)s, (struct Bmp *)q, 0xf8, 8, z, 8, 8, 8, z);

    q = (int)func_02045770((struct Descriptor *)e->f90);
    func_020439A0((struct Bmp *)s, (struct Bmp *)q, 0x28, 0x10, 8, 8, 0x18, 8, z);

    q = (int)func_02045770((struct Descriptor *)e->f90);
    func_020439A0((struct Bmp *)s, (struct Bmp *)q, 0x80, z, 0, 0x10, 8, 8, 0);

    q = (int)func_02045770((struct Descriptor *)e->f90);
    func_020439A0((struct Bmp *)s, (struct Bmp *)q, 0x58, 0x10, 8, 0x10, 0x18, 8, z);

    func_020437AC((struct Obj020437AC *)s);
}

void func_021BB0E4(char *p)
{
    func_020452E8(((struct Obj00173 *)p)->f8C);
    func_020452E8(((struct Obj00173 *)p)->f90);
}


void func_021BB0FC(void *obj)
{
    int p;

    if (((struct Obj10886 *)obj)->f8 != 0) {
        p = ((struct Obj10886 *)obj)->f8C;
        func_02045334((struct Descriptor *)p);
        func_02045374((struct Cfg *)p);
        func_02041B6C(func_02045730((struct Descriptor *)p));
        return;
    }
    p = ((struct Obj10886 *)obj)->f90;
    func_02045334((struct Descriptor *)p);
    func_02045374((struct Cfg *)p);
    func_02041B6C(func_02045730((struct Descriptor *)p));
}


void func_021BB13C(void *a0, void *a1, void *a2, void *a3)
{
    func_021BB184(a0, (int)a3);
    func_021BB23C(a0, (int)a1, (int)a2, (int)a3);
    func_021BB2D4(a0);
}

void func_021BB160(char *p, int i)
{
    void **slot = (void **)(p + 0xac) + i;
    if (*slot != 0) {
        func_021BB2C4(p, i);
        func_021BB214(p, i);
        *slot = 0;
    }
}

void func_021BB184(char *p,int index)
{
    int flag=0;
    int handle;
    if (((struct Obj00790 *)p)->f1C) flag=1;
    handle=((struct Obj00790 *)p)->f1D4;
    *(int *)(p+0x94+index*4)=func_0202D81C(handle,((struct Obj00790 *)p)->fC,((struct Obj00790 *)p)->fE,((struct Obj00790 *)p)->f10,((struct Obj00790 *)p)->f12,0,0,((struct Obj00790 *)p)->f14,flag,((struct Obj00790 *)p)->f0);
    *(int *)(p+0x9c+index*4)=func_0202D7D8(handle,((struct Obj00790 *)p)->fC,((struct Obj00790 *)p)->fE,((struct Obj00790 *)p)->f10,((struct Obj00790 *)p)->f12,0,0,flag,index<<5,((struct Obj00790 *)p)->f0);
    *(int *)(p+0xa4+index*4)=func_0202D898(((struct Obj00790 *)p)->fC,((struct Obj00790 *)p)->fE,((struct Obj00790 *)p)->f10,((struct Obj00790 *)p)->f12,0,0,2,flag,((struct Obj00790 *)p)->f0);
}

void func_021BB214(char *p, int i)
{
    char *s = p + i * 4;
    func_0204ADA4((u32)(((struct Obj10887 *)s)->f9C));
    func_0204A8D4((u32)(((struct Obj10887 *)s)->f94));
    func_0204AFD8((u32)(((struct Obj10887 *)s)->fA4));
}
