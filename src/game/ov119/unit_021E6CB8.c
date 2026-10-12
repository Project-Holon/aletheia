/*
 * file:     unit_021E6CB8.c
 * unit:     yes
 * function: func_021E6CB8, func_021E6DEC, func_021E6E7C, func_021E6F0C, func_021E6FC8, func_021E6FD4, func_021E7058, func_021E707C, func_021E7098, func_021E7160, func_021E71E0, func_021E71F0, func_021E7208, func_021E7220, func_021E7234, func_021E7248
 * address:  0x021E6CB8
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02043678 0x02043678 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02049238 0x02049238 arm
 *   d_021E7E64 0x021E7E64 data a2
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020437AC 0x020437AC arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ABBC 0x0204ABBC arm
 *   func_020437D4 0x020437D4 arm
 *   func_020437EC 0x020437EC arm
 *   func_020862F0 0x020862F0 arm
 *   func_0207E804 0x0207E804 arm
 *   d_021E7DD8 0x021E7DD8 data a1
 *   func_02049EF4 0x02049EF4 arm
 *   func_02041090 0x02041090 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0204047C 0x0204047C arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204BA00 0x0204BA00 arm
 *   func_02021518 0x02021518 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_02021FD8 0x02021FD8 thumb
 *   func_02021730 0x02021730 thumb
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E468 0x0207E468 arm
 *   func_0207E51C 0x0207E51C arm
 *   func_0207E3D0 0x0207E3D0 arm
 *   func_02082D44  0x02082D44  arm
 *   func_020056BC  0x020056BC  thumb
 *   func_02043534 0x02043534 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_020435F4 0x020435F4 arm
 */
#include "pokemontrade_types.h"

struct Bmp;
struct Obj;
struct Obj020437AC;
struct Actor;
struct Cmd;
struct Chan02021FD8;
struct PalAnmSlot;
struct Node;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { short x,y,z; u8 a,b; } Create;

typedef struct { short x,y; } Pt;

typedef struct { Pt pos[8]; } Table_021E6CB8;

typedef signed int     s32;

typedef struct { u8 v[8]; } Table_021E6E7C;

typedef struct { u32 f0, f4, size; u16 data[1]; } Pal;

typedef struct { short v; void *p; void (*fn)(void *); } Callback;

typedef struct { void *a, *b; u32 size, c, d; } Slot;

typedef struct
{
    int x;
    int y;
    int z;
} T;

typedef struct
{
    T f0;
    T f0c;
    T f18;
    T f24;
    T f30;
    int f3c;
    int f40;
} S;

extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_02049238(void *);
extern void func_0204B3B4(struct Obj *p);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_0204A8D4(unsigned int);
extern void func_0204ADA4(unsigned int);
extern void func_0204AFD8(unsigned int);
extern int func_0204ABBC(unsigned int idx, unsigned int flag);
extern void *func_020437D4(const struct Bmp *bmp);
extern u32 func_020437EC(const struct Bmp *bmp);
extern void func_020862F0(void *,int);
extern void func_0207E804(const void *,void *,unsigned int);
extern void *func_02049EF4(void *, u32, u32, void **, u16);
extern void func_02041090(u32, u32, u32, u32, u8, u8);
extern u32 func_020307B0(void *p);
extern void func_0204047C(int idx, unsigned short val);
extern void func_02041B6C(u32 bit);
extern void func_0204B92C(struct Obj *,unsigned int);
extern void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_02021FD8(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int func_02021730(char *,int);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern void func_0207E5D0(void *,u32,u32);
extern void func_0207E468(void *,u32,u32);
extern void func_0207E51C(void *,u32,u32);
extern void func_0207E3D0(void *,u32,u32);
extern void func_02082D44(void *dst, void *src, int n);
extern u32 func_020056BC(void);
extern void func_02030DA8(u32, void (*)(void), int, int);
extern void func_02043534(u32 planes);
extern void func_02030EAC(struct Node *n);
extern void func_020435F4(u32 planes);
void func_021E6CB8(char *p);
void func_021E6DEC(int p);
void func_021E6E7C(int p);
void func_021E6F0C(char *p, int side, void *mon);
void func_021E6FC8(char *p);
void func_021E6FD4(char *p, int x, int y);
void func_021E7058(void *p);
int func_021E707C(void *p);
void func_021E7098(char *p, int bank, int mask);
void func_021E7160(void *p, int a1, int a2, int a3);
void func_021E71E0(void *p, int a);
void func_021E71F0(void *p, int a);
void func_021E7208(void *p, int a);
void func_021E7220(void *p, int a);
void func_021E7234(void *p, int a);
void func_021E7248(S *d, T *a, T *b, T *c, T *dd, int e);
extern const Table_021E6CB8 d_021E7E64;
extern const Table_021E6E7C d_021E7DD8;

void func_021E6CB8(char *p)
{
    Table_021E6CB8 t = d_021E7E64;
    void *h = func_020490F4(0x66, ((TradeWork *)p)->f5F4);
    Create c;
    int i;
    (*(unsigned int *)&((TradeWork *)p)->f10EC) = func_0204AC18(h, 0, 1, 0x1c0, 0, 1, ((TradeWork *)p)->f5F4);
    ((TradeWork *)p)->f10F0 = func_0204AF28(h, 2, 1, ((TradeWork *)p)->f5F4);
    for (i = 0; i < 8; i++) {
        *(void **)(p + i * 4 + 0x10f4) = func_02043678(16, 6, 32, ((TradeWork *)p)->f5F4);
        *(u32 *)(p + i * 4 + 0x1114) = func_0204A6C8(h, 3, 0, 1, ((TradeWork *)p)->f5F4);
    }
    for (i = 0; i < 8; i++) {
        c.x = *(short *)((char *)&t + i * 4); c.y = *(short *)((char *)&t + i * 4 + 2); c.z = 0; c.a = 0; c.b = 1;
        *(int *)(p + i * 4 + 0x10cc) = (int)func_0204B294((void *)((TradeWork *)p)->f9C4, *(int *)(p + i * 4 + 0x1114), *(int *)(p + 0x10ec), *(int *)(p + 0x10f0), &c, 1, ((TradeWork *)p)->f5F4);
        func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x10cc), 1);
    }
    func_02049238(h);
}

void func_021E6DEC(int p) {
    int i;
    for (i=0;i<8;i++) {
        if (*(int *)(p+i*4+0x10cc)) {
            func_0204B3B4((struct Obj *)(*(int *)(p+i*4+0x10cc)));
            *(int *)(p+i*4+0x10cc)=0;
            func_020437AC(*(void **)(p+i*4+0x10f4));
            *(int *)(p+i*4+0x10f4)=0;
            func_0204A8D4(*(int *)(p+i*4+0x1114));
            *(int *)(p+i*4+0x1114)=0;
        }
    }
    if (((TradeWork *)p)->f10EC) {func_0204ADA4(((TradeWork *)p)->f10EC);((TradeWork *)p)->f10EC=0;}
    if (((TradeWork *)p)->f10EC) {func_0204AFD8(((TradeWork *)p)->f111C);((TradeWork *)p)->f10EC=0;}
}

void func_021E6E7C(int p) {
    Table_021E6E7C t=d_021E7DD8;
    int i,j;
    char *dest,*source;
    for(i=0;i<8;i++) {
        dest=(char *)func_0204ABBC(*(int *)(p+i*4+0x1114),1);
        source=func_020437D4((const struct Bmp *)(*(int *)(p+i*4+0x10f4)));
        func_020862F0(source,func_020437EC((const struct Bmp *)(*(int *)(p+i*4+0x10f4))));
        for(j=0;j<8;j++) {func_0207E804(source+t.v[j]*256,dest,256);dest+=256;}
    }
}

void func_021E6F0C(char *p, int side, void *mon)
{
    void *h = func_020490F4(0x66, ((TradeWork *)p)->f5F4);
    void *f;
    Pal *pal;
    u16 *d;
    u32 i;
    if (side == 0)
        f = func_02049EF4(h, 5, 0, (void **)&pal, ((TradeWork *)p)->f5F4);
    else
        f = func_02049EF4(h, 6, 0, (void **)&pal, ((TradeWork *)p)->f5F4);
    d = pal->data;
    for (i = 0; i < pal->size / 2; i++)
        d[i] += (u16)((TradeWork *)p)->f86C;
    if (!side)
        func_02041090(1, (u32)d, 0, 0, 16, 24);
    else
        func_02041090(1, (u32)pal->data, 16, 0, 16, 24);
    func_020307B0(f);
    func_0204047C(3, 2);
    func_0204047C(2, 3);
    func_0204047C(1, 1);
    func_0204047C(0, 0);
    func_02049238(h);
    func_02041B6C(1);
}

void func_021E6FC8(char *p) { p[0x11f5]=1; }

void func_021E6FD4(char *p, int x, int y) {
    Callback cb;
    Create c;
    c.x=x+12;c.y=y+12;c.z=24;c.a=0;c.b=0;
    func_021E7058(p);
    ((TradeWork *)p)->fF24=(int)func_0204B294((void *)((TradeWork *)p)->f9C4,((TradeWork *)p)->f894,((TradeWork *)p)->f880,((TradeWork *)p)->f8B0,&c,1,((TradeWork *)p)->f5F4);
    func_0204B3DC((struct Obj *)((TradeWork *)p)->fF24,1);
    func_0204B92C((struct Obj *)((TradeWork *)p)->fF24,1);
    p[0x11f5]=0;
    cb.v=0;cb.p=p;cb.fn=(void (*)(void *))func_021E6FC8;
    func_0204BA00((struct Actor *)(((TradeWork *)p)->fF24),(const struct Cmd *)(&cb));
}


void func_021E7058(void *p)
{
    if (((TradeWork *)p)->fF24) {
        func_0204B3B4((struct Obj *)(((TradeWork *)p)->fF24));
        ((TradeWork *)p)->fF24 = 0;
        *((char *)p + 0x11f5) = 0;
    }
}


int func_021E707C(void *p)
{
    if (*((unsigned char *)p + 0x11f5)) {
        func_021E7058(p);
        return 0;
    }
    return 1;
}

/*
 * interface: 02021540 forwards live r0 to 020307B0, so caller passes s.
 */
void func_021E7098(char *p, int bank, int mask)
{
    Slot *s;
    char *buf;
    int i;
    int off;
    s=func_02021518(((TradeWork *)p)->f5F4);
    func_0202155C((struct PalAnmSlot *)s,bank,0x200,((TradeWork *)p)->f5F4);
    func_020216D4((struct PalAnmSlot *)s,bank,0,0x200);
    func_02021FD8((struct Chan02021FD8 *)s,bank,0,0x100,6,0);
    buf=(char *)func_02021730((char *)s,bank);
    for(i=0;i<16;i++) {
        if(mask & (1<<i)) {
            off=i*32;
            func_020862F0(buf+off,32);
            switch(bank) {
            case 3: func_0207E5D0(buf+off,off,32); break;
            case 1: func_0207E468(buf+off,off,32); break;
            case 2: func_0207E51C(buf+off,off,32); break;
            case 0: func_0207E3D0(buf+off,off,32); break;
            }
        }
    }
    func_020215A0((struct PalAnmSlot *)s,bank);
    func_02021540(s);
}


void func_021E7160(void *p, int a1, int a2, int a3)
{
    if (a1 != 0) {
        if (a2 == 3)
            func_02082D44((void *)0x05000600, ((TradeWork *)p)->f10A4,
                          0x200);
        else if (a2 == 1)
            func_02082D44((void *)0x05000400, ((TradeWork *)p)->f10A8,
                          0x200);
        func_021E7098(p, a2, a3);
        return;
    }
    if (a2 == 3) {
        func_020862F0(((TradeWork *)p)->f10A4, 0x200);
        func_0207E5D0(((TradeWork *)p)->f10A4, 0, 0x200);
        return;
    }
    if (a2 == 1) {
        func_020862F0(((TradeWork *)p)->f10A8, 0x200);
        func_0207E468(((TradeWork *)p)->f10A8, 0, 0x200);
    }
}


void func_021E71E0(void *p, int a)
{
    func_021E7160(p, a, 3, 0xfffe);
}


/*
 * func_020056BC (ARM9, unlabelled Thumb leaf) was filed EXACT by the
 * dependency-tree lane and now attests this call through `matched`.
 *
 * Addresses are Black-image addresses.
 */
void func_021E71F0(void *p, int a)
{
    func_02030DA8(func_020056BC(), (void (*)(void))func_021E7220, a, 0xa);
}


void func_021E7208(void *p, int a)
{
    func_02030DA8(func_020056BC(), (void (*)(void))func_021E7234, a, 0xa);
}


void func_021E7220(void *p, int a)
{
    func_02043534(a);
    func_02030EAC(p);
}


void func_021E7234(void *p, int a)
{
    func_020435F4(a);
    func_02030EAC(p);
}


void func_021E7248(S *d, T *a, T *b, T *c, T *dd, int e)
{
    d->f0 = *a;
    d->f0c = *a;
    d->f18 = *b;
    d->f24 = *c;
    d->f30 = *dd;
    d->f3c = 0;
    d->f40 = e;
}
