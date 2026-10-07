/*
 * file:     unit_021DC860_p04.c
 * unit:     yes
 * function: func_021DE368, func_021DE388, func_021DE5F4, func_021DE608, func_021DE684
 * address:  0x021DE368
 * region:   ov171
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DE34C 0x021DE34C thumb ov171
 *   func_0204B1CC 0x0204B1CC arm
 *   func_021DE064 0x021DE064 thumb ov171
 *   func_021DE290 0x021DE290 thumb ov171
 *   func_021DE1F8 0x021DE1F8 thumb ov171
 *   func_021DE218 0x021DE218 thumb ov171
 *   func_021DE238 0x021DE238 thumb ov171
 *   func_0202D7C8 0x0202D7C8 thumb
 *   func_0202D81C 0x0202D81C thumb
 *   func_0202D7D8 0x0202D7D8 thumb
 *   func_0202D898 0x0202D898 thumb
 *   func_02017ED8 0x02017ED8 thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_02049238 0x02049238 arm
 *   d_021DEC04 0x021DEC04 data a4
 *   d_021DEC94 0x021DEC94 data a4
 *   func_0203F6D8 0x0203F6D8 arm
 *   func_0203F684 0x0203F684 arm
 *   func_021DE0C0 0x021DE0C0 thumb ov171
 *   _ll_mul 0x0209C054 arm
 *   func_021DE0E4 0x021DE0E4 thumb ov171
 *   func_0204B800 0x0204B800 arm
 */
#include "../../matched/include/Obj08252.h"
#include "../../matched/include/Obj24059.h"
#include "../../matched/include/Obj10661.h"

struct Bank;
struct PalAnmSlot;
struct Obj;
struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

struct E { u32 w[6]; };

struct Ent { u32 f0; u32 f4; u32 f8; u32 fc; u16 f10; u8 f12; u8 a : 6; u8 b : 2; };

typedef signed short s16;

typedef signed int s32;

extern void func_021DE34C(char *,int);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_021DE064(int *p, int i, int a);
extern struct Obj *func_021DE290(char *p, const char *q);
extern void func_021DE1F8(char *, int);
extern void func_021DE218(char *, int);
extern void func_021DE238(char *, int);
extern int func_0202D7C8(int a0);
extern u32 func_0202D81C(u32, u32, u32, u32, u32, u32, u32, u32, u32, u16);
extern u32 func_0202D7D8(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern u32 func_0202D898(u32, u32, u32, u32, u32, u32, u32, u32, u16);
extern u32 func_02017ED8(u32, u32);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_02049238(u32);
extern s16 func_0203F6D8(s32 x);
extern short func_0203F684(unsigned short x);
extern void func_021DE0C0(u8 *p, int i, int x, int y);
extern void func_021DE0E4(u8 *,int,s16 *,s16 *);
extern void func_0204B800(struct Node *node, u32 val);
void func_021DE368(char *p);
void func_021DE388(char *p);
int func_021DE5F4(char *p);
void func_021DE608(char *p, int i, int angle);
void func_021DE684(u8 *p);
extern const struct E d_021DEC04[];
extern const struct E d_021DEC94[];

void func_021DE368(char *p) { u32 i; for(i=0;i<16;i++) func_021DE34C(p,i); func_0204B1CC(((struct Obj08252 *)p)->fB70); }

void func_021DE388(char *p) {
    u32 i;
    u32 h;
    char *rec;
    u32 *slot;
    u32 v;
    struct Ent *r;
    u32 x;
    struct E e;
    for (i = 0; i <= 11; i++) func_021DE064((int *)p, i, 0);
    rec = p + 0xc + (s8)p[0xC5E] * 0xbc;
    h = func_0202D7C8(0x808C);
    {
        for (i = 0; i < *(u16 *)(rec + 0xb8); i++) {
            e = d_021DEC04[i];
            r = (struct Ent *)(rec + i * 0x1c);
            x = func_02017ED8(r->fc, r->f8);
            if (*(u8 *)(p + 0xC60) == 1) {
                e.w[2] += 6;
                e.w[3] += 6;
                e.w[4] += 6;
                v = (u16)(i + 6);
                slot = (u32 *)(p + 0xB74 + v * 4);
            } else {
                v = (u16)i;
                slot = (u32 *)(p + 0xB74 + v * 4);
            }
            *(u32 *)(p + e.w[2] * 4 + 0xBB4) = func_0202D81C(h, r->f10, r->a, r->b, x, 0, 0, r->f8, 0, 0x8c);
            *(u32 *)(p + e.w[3] * 4 + 0xBE8) = func_0202D7D8(h, r->f10, r->a, r->b, x, 0, 0, 0, (u16)(v << 5), 0x8c);
            *(u32 *)(p + e.w[4] * 4 + 0xC1C) = func_0202D898(r->f10, r->a, r->b, x, 0, 0, 2, 0, 0x8c);
            *slot = (u32)func_021DE290(p, (const char *)(&e));
            func_021DE608(p, v, *(u16 *)((char *)d_021DEC94 + *(u16 *)(rec + 0xb8) * 0x18 + i * 4 - 0x18));
            *(u16 *)(p + i * 2 + 0xB10) = *(u16 *)((char *)d_021DEC94 + *(u16 *)(rec + 0xb8) * 0x18 + i * 4 - 0x18);
        }
    }
    func_020216D4(*(void **)(p + 0xB30), 2, 0, 0x200);
    func_02049238(h);
    if (*(u8 *)(p + 0xC60) == 1) {
        for (i = 0; i <= 5; i++) func_021DE34C(p, i);
        for (i = 0; i <= 5; i++) func_021DE1F8(p, i);
        for (i = 0; i <= 5; i++) func_021DE218(p, i);
        for (i = 0; i <= 5; i++) func_021DE238(p, i);
    } else {
        for (i = 6; i <= 11; i++) func_021DE34C(p, i);
        for (i = 6; i <= 11; i++) func_021DE1F8(p, i);
        for (i = 6; i <= 11; i++) func_021DE218(p, i);
        for (i = 6; i <= 11; i++) func_021DE238(p, i);
    }
    *(u8 *)(p + 0xC60) ^= 1;
    func_021DE684((u8 *)p);
}


int func_021DE5F4(char *p)
{
    if (((struct Obj24059 *)p)->fC60 == 0)
        return 6;
    return 0;
}

/*
 * lever: mask each translated fixed point coordinate before shifting and narrowing.
 */
void func_021DE608(char *p, int i, int angle)
{
    int x, y;
    x = (int)(((long long)func_0203F6D8((u16)angle) * 0x64000 + 0x800) >> 12);
    y = (int)(((long long)func_0203F684((u16)angle) * 0x2c000 + 0x800) >> 12);
    x += 0x80000;
    y += 0x58000;
    func_021DE0C0((u8 *)p, i, (short)((x & 0x7ffff000) >> 12),
        (short)((y & 0x7ffff000) >> 12));
}

void func_021DE684(u8 *p)
{
    u8 order[6];
    s16 a[2],b[2];
    int start=func_021DE5F4((char *)p);
    u8 i,j,t;
    void *r;
    for(i=0;i<6;i++) order[i]=start+i;
    for(i=0;i<*(u16 *)(p+((struct Obj10661 *)p)->fC5E*0xbc+0xc4)-1;i++) {
        func_021DE0E4(p,order[i],&a[1],&a[0]);
        for(j=i+1;j<*(u16 *)(p+((struct Obj10661 *)p)->fC5E*0xbc+0xc4);j++) {
            func_021DE0E4(p,order[j],&b[1],&b[0]);
            if(a[0]<b[0]) {t=order[i];order[i]=order[j];order[j]=t;a[0]=b[0];}
        }
    }
    for(i=0;i<*(u16 *)(p+((struct Obj10661 *)p)->fC5E*0xbc+0xc4);i++) {
        r=*(void **)(p+order[i]*4+0xb74);
        if(r) func_0204B800(r,i);
    }
}
