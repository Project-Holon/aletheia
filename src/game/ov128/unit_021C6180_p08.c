/*
 * file:     unit_021C6180_p08.c
 * unit:     yes
 * function: func_021C7E0C, func_021C7E48, func_021C7E78, func_021C7F14, func_021C8100, func_021C81C8, func_021C81FC, func_021C8240, func_021C8354, func_021C8388, func_021C83B0, func_021C83DC
 * address:  0x021C7E0C
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C6ADC 0x021C6ADC thumb ov128
 *   func_02041B6C 0x02041B6C arm
 *   func_021C85A4 0x021C85A4 thumb ov128
 *   func_021C6B38 0x021C6B38 thumb ov128
 *   func_021C89C4 0x021C89C4 thumb ov128
 *   func_021CA3A0 0x021CA3A0 thumb ov128
 *   func_021CA3C4 0x021CA3C4 thumb ov128
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_020355D8 0x020355D8 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021CA2C4 0x021CA2C4 thumb ov128
 *   func_02035C08 0x02035C08 arm
 *   func_021CA294 0x021CA294 thumb ov128
 *   d_021CA5FC 0x021CA5FC data a1
 *   func_0204B09C 0x0204B09C arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_021C8A50 0x021C8A50 thumb ov128
 *   func_021C860C 0x021C860C thumb ov128
 *   d_021CA7C0 0x021CA7C0 data a4
 *   cb_021CA7C0 0x021CA7C0 data a4
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_021CA4B4 0x021CA4B4 thumb ov128
 *   func_0201283C 0x0201283C thumb
 *   func_021C87A0 0x021C87A0 thumb ov128
 *   func_020099C8 0x020099C8 thumb
 *   func_020598C4 0x020598C4 arm
 *   func_021C6BCC 0x021C6BCC thumb ov128
 *   func_021C867C 0x021C867C thumb ov128
 */
#include "../../matched/include/Obj00179.h"
#include "../../matched/include/Obj23080.h"
#include "../../matched/include/Obj03810.h"
#include "../../matched/include/Obj10484.h"
#include "../../matched/include/Obj23081.h"
#include "../../matched/include/Obj23082.h"
#include "../../matched/include/Obj10485.h"
#include "../../matched/include/Obj08130.h"

struct PrintSys;
struct BigObj;
struct Sub020097BCObj;
struct Sub020097BCFriend;
struct TaskMenu;
struct TaskMenuTmpl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed char s8;

typedef struct { s16 x, y; } Pair;

typedef void (*Callback)(u8 *, u8 *, int, int);

typedef struct { Callback cb[4]; Pair pos; } Config;

typedef unsigned long long u64;

typedef struct TextConfig {int heap; u8 count; u8 pad[3]; void *entries; int mode; u8 x,y,a,b;} TextConfig;

extern void func_021C6ADC(u8 *,u8 *,unsigned);
extern void func_02041B6C(u32);
extern void func_021C85A4(u8 *,u8 *,u8 *,int,int,int,u16);
extern void func_021C6B38(u8 *);
extern void func_021C89C4(char *,void *,void *);
extern void func_020061E4(u32 a);
extern void func_021CA3A0(char *p);
extern void func_021CA3C4(char *p);
extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
extern void func_020355D8(u8 v);
extern void func_021CA2C4(u8 *,int,int);
extern int func_02035C08(const void *);
extern void func_021CA294(u8 *p, int a);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_0204B09C(void *, int, Pair *);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_021C8A50(char *p, int unused);
extern void func_021C860C(u8 *, u8 *, u8 *, int, int, u16);
extern void func_021CA4B4(char *);
extern u32 func_0201283C(const struct BigObj *);
extern int func_021C87A0(s16 *);
extern struct Sub020097BCFriend *func_020099C8(struct Sub020097BCObj *,int);
extern unsigned long long func_020598C4(void *);
extern void func_021C6BCC(u8 *,u8 *,int,unsigned);
extern void func_021C867C(u8 *p, u8 *a, int n, int heap);
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
void func_021C7E0C(u8 *p,u8 *q,u8 *r,u16 heap);
void func_021C7E48(u8 *p,void *q,u8 *r);
int func_021C7E78(s16 *p, u8 *a, void *b, int n);
int func_021C7F14(s16 *p, u8 *a, u8 *ctx);
int func_021C8100(s16 *p, void *a, void *b, int *changed);
int func_021C81C8(s16 *p,u8 *q,u8 *r);
void func_021C81FC(u8 *p, void *a, u8 *b, u16 c);
int func_021C8240(u8 *p, u8 *a, u8 *b, u16 h);
int func_021C8354(u8 *p,u8 *q);
unsigned long long func_021C8388(s16 *p,u8 *q);
void func_021C83B0(s16 *p,u8 *q,u8 *r,u16 heap);
void func_021C83DC(u8 *p, u8 *a, void *unused, int heap);
extern const unsigned char d_021CA5FC[];
extern Config d_021CA7C0;
extern Callback cb_021CA7C0[];

void func_021C7E0C(u8 *p,u8 *q,u8 *r,u16 heap) {func_021C6ADC(r,r+12,5);func_02041B6C(0);func_021C85A4(p,q,r,((struct Obj00179 *)p)->f0,((struct Obj00179 *)p)->f4,0,heap);}

void func_021C7E48(u8 *p,void *q,u8 *r) {int i;func_021C6B38(r);for(i=0;i<3;i++)func_021C89C4((char *)(p+12+i*76),r,r+364);func_02041B6C(0);}

int func_021C7E78(s16 *p, u8 *a, void *b, int n)
{
    if (n == 0) {
        func_020061E4(0x551); func_021CA3A0(b); return 3;
    }
    if (n == 6) {
        func_020061E4(0x556); func_021CA3C4(b); return 4;
    }
    if (n == 5) {
        if (p[2] == 8) { func_020061E4(0x551); func_021CA3A0(b); return 3; }
        if (p[2] == 9) { func_020061E4(0x556); func_021CA3C4(b); return 4; }
        if (((struct Obj23080 *)a)->f10 <= (unsigned int)(p[2] + p[0] * 8)) return 0;
        func_020061E4(0x54c);
        p[4] = 0;
        return 5;
    }
    if (n == 1) return 1;
    return n == 2 ? 2 : 0;
}

int func_021C7F14(s16 *p, u8 *a, u8 *ctx)
{
    u16 old;
    int moved;
    int page;
    int dir;
    if(func_020362DC() & 2) {
        func_020355D8(0);
        ((struct Obj03810 *)a)->f0=0;
        return func_021C7E78(p,a,ctx,0);
    }
    if(func_020362DC() & 1024) {
        func_020355D8(0);
        ((struct Obj03810 *)a)->f0=0;
        return func_021C7E78(p,a,ctx,6);
    }
    if(((struct Obj03810 *)a)->f0==1) {
        if(func_020362DC() & 0xcf3) {
            func_020061E4(0x548);
            func_021CA2C4(ctx,p[2],p[2]);
            func_020355D8(0);
            ((struct Obj03810 *)a)->f0=0;
        }
        return 0;
    }
    if(func_020362DC() & 1) return func_021C7E78(p,a,ctx,5);
    old=p[2];
    moved=0;
    page=0;
    if(func_0203633C() & 64) {
        if(p[2]==0) p[2]=3;
        else if(p[2]==4) p[2]=7;
        else --p[2];
        moved=1;
    } else if(func_0203633C() & 128) {
        if(p[2]==3) p[2]=0;
        else if(p[2]==7) p[2]=4;
        else ++p[2];
        moved=1;
    } else if(func_0203633C() & 32) {
        if(p[2]<4) {
            p[2]+=4;
            page=1;
            dir=0;
        } else p[2]-=4;
        moved=1;
    } else if(func_0203633C() & 16) {
        if(p[2]<4) p[2]+=4;
        else {
            p[2]-=4;
            page=1;
            dir=1;
        }
        moved=1;
    } else if(a[14]) {
        if(a[14] && (func_0203633C() & 512)) {
            page=1;
            dir=0;
        } else if(a[14] && (func_0203633C() & 256)) {
            page=1;
            dir=1;
        }
    }
    if(page==1) {
        if(dir) {
            p[1]=p[0];
            p[0]=(p[0]+1)%4;
            return func_021C7E78(p,a,ctx,2);
        } else {
            p[1]=p[0];
            --p[0];
            if(p[0]<0) p[0]+=4;
            return func_021C7E78(p,a,ctx,1);
        }
    }
    if(moved==1) {
        func_020061E4(0x548);
        func_021CA2C4(ctx,p[2],old);
        p[3]=old;
    }
    return 0;
}

int func_021C8100(s16 *p, void *a, void *b, int *changed)
{
    u32 v = func_02035C08(d_021CA5FC);
    s8 delta;
    if (v == (u32)-1) return 0;
    if (v <= 7) {
        *changed = 1;
        func_021CA294(b, p[2]);
        p[2] = v;
        return func_021C7E78(p, a, b, 5);
    }
    if (v == 8) {
        *changed = 1;
        p[2] = v;
        return func_021C7E78(p, a, b, 5);
    }
    if (v == 9) {
        *changed = 1;
        p[2] = v;
        return func_021C7E78(p, a, b, 5);
    }
    delta = (v - 10) - p[0];
    if (delta != 0) {
        *changed = 1;
        p[1] = p[0];
        p[0] += delta;
        if (delta >= 0) {
            p[0] %= 4;
            return func_021C7E78(p, a, b, 2);
        } else {
            if (p[0] < 0) p[0] += 4;
            return func_021C7E78(p, a, b, 1);
        }
    }
    return 0;
}

int func_021C81C8(s16 *p,u8 *q,u8 *r) {int changed=0;int ret=func_021C8100(p,q,r,&changed);if(changed) {func_020355D8(1);((struct Obj03810 *)q)->f0=1;return ret;}return func_021C7F14(p,q,r);}

void func_021C81FC(u8 *p, void *a, u8 *b, u16 c)
{
    int n = ((struct Obj00179 *)p)->f102 == 2 ? 2 : 1;
    func_021C85A4(p, a, b, ((struct Obj00179 *)p)->f0, ((struct Obj00179 *)p)->f4, n, c);
    func_021CA294(b, ((struct Obj00179 *)p)->f4);
    func_020061E4(0x548);
}

/*
 * lever: Two names reproduce the duplicate 0x021CA7C0 pool words; the
 * mutable config declaration preserves sequential halfword loads/stores.
 */
int func_021C8240(u8 *p, u8 *a, u8 *b, u16 h)
{
    Pair pos;
    int delta;
    Callback cb;
    int mode;
    if (func_0201C6B4(((struct Obj10484 *)b)->f34) == 0) return 0;
    if (((struct Obj00179 *)p)->f100 > 24) {
        pos.x = d_021CA7C0.pos.x;
        pos.y = d_021CA7C0.pos.y;
        func_0204B09C(((struct Obj10484 *)b)->f140, 0, &pos);
        mode = ((struct Obj00179 *)p)->f102 == 2 ? 2 : 1;
        func_021C8A50((char *)(p + 12 + mode * 76), (int)b);
        func_021C860C(p, a, b, ((struct Obj00179 *)p)->f0, ((struct Obj00179 *)p)->f4, h);
        return 1;
    }
    delta = (((struct Obj00179 *)p)->f100 * 256) / 24;
    if (((struct Obj00179 *)p)->f102 == 2) delta = -delta;
    func_02041EE4(2, 0, delta);
    func_02041EE4(3, 0, delta);
    pos.x = d_021CA7C0.pos.x;
    pos.y = d_021CA7C0.pos.y;
    pos.x += (s16)delta;
    func_0204B09C(((struct Obj10484 *)b)->f140, 0, &pos);
    mode = ((struct Obj00179 *)p)->f100;
    if (mode % 6 != 0) {
        cb = cb_021CA7C0[mode / 6];
        if (cb != 0) cb(p, b, ((struct Obj00179 *)p)->f0, *(s16 *)&((struct Obj00179 *)p)->f2);
    }
    (((struct Obj00179 *)p)->f100)++;
    return 0;
}

/*
 * extent: two zero alignment bytes follow the compiled function.
 */
int func_021C8354(u8 *p,u8 *q) {if(func_0201C6B4(*(const struct PrintSys * *)&((struct Obj23082 *)q)->f34)==1) {func_02041EE4(2,0,0);func_02041EE4(3,0,0);func_021CA4B4(**(char ** *)&((struct Obj23081 *)p)->f14);return 1;}return 0;}

unsigned long long func_021C8388(s16 *p,u8 *q) {u32 base;base=func_0201283C(*(const struct BigObj * *)&((struct Obj10485 *)q)->f4);return func_020598C4(func_020099C8((struct Sub020097BCObj *)base,*(u8 *)(q+24+func_021C87A0(p))));}

void func_021C83B0(s16 *p,u8 *q,u8 *r,u16 heap) {func_021C6BCC(r,q,*(u8 *)(q+24+func_021C87A0(p)),heap);func_021C867C((u8 *)p,r,12,heap);}

void func_021C83DC(u8 *p, u8 *a, void *unused, int heap)
{
    TextConfig config;
    void *q = (void *)func_0201283C(((struct Obj10485 *)a)->f4);
    int result = func_02009864(q, (a + func_021C87A0((s16 *)p))[24], 9);
    config.heap = heap;
    config.count = 4;
    if (result == 2) {
        config.entries = p + (func_021C8388((s16 *)p, a) != 0 ? 0x148 : 0x118);
        ((struct Obj08130 *)p)->f198 = 1;
    } else {
        config.entries = p + 0x118;
        ((struct Obj08130 *)p)->f198 = 0;
    }
    config.mode = 1;
    config.x = 32; config.y = 24; config.a = 17; config.b = 3;
    ((struct Obj08130 *)p)->f194 = func_02027778((struct TaskMenuTmpl *)(&config), ((struct Obj08130 *)p)->f190);
}
