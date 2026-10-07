/*
 * file:     shinka_demo_p08.c
 * unit:     yes
 * function: func_02205580, func_022055BC, func_02205620, func_022056E8, func_02205844, func_02205854
 * address:  0x02205580
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B709C 0x021B709C thumb ov067
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201EE84 0x0201EE84 thumb
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201EF34 0x0201EF34 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   d_020A7370 0x020A7370 data a4
 *   d_02208F40 0x02208F40 data a4
 *   func_0201292C 0x0201292C thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AA14 0x0201AA14 thumb
 *   func_02007F68 0x02007F68 thumb
 *   func_02007F1C 0x02007F1C thumb
 *   func_020173EC 0x020173EC thumb
 *   func_02019CE0 0x02019CE0 thumb
 *   func_020178D8 0x020178D8 thumb
 *   func_02017E40 0x02017E40 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02008F08 0x02008F08 thumb
 *   func_0201A98C 0x0201A98C thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200CFA0 0x0200CFA0 thumb
 *   func_0200CDE0 0x0200CDE0 thumb
 *   func_02012F2C 0x02012F2C thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   d_02208CCC 0x02208CCC data a4
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 */
#include "../../matched/include/Obj04595.h"
#include "../../matched/include/Obj03903.h"
#include "../../matched/include/Obj06644.h"
#include "../../matched/include/Obj24950.h"

#define REG_BG0CNT     (*(volatile u16 *)0x04000008)
#define REG_DISP3DCNT  (*(volatile u16 *)0x04000060)
#define REG_VIEWPORT   (*(volatile u32 *)0x04000580)
struct Rec;
struct U16Vec;
struct MsgBank;
struct WordSet;
struct BigObj;
struct Blk37;
struct RecDC;
struct Sub02008C20Obj;
struct Party;
struct PartyMon;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    u32 kind;
    u32 val;
} Param;

extern void func_021B709C(u8 *);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201EF34(struct WordSet *p, u32 i, u32 v);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_0201ED04(struct WordSet *p);
extern void *func_0201292C(const struct BigObj *p);
extern u32 func_0201AA18(void *);
extern u32 func_0201AA14(void *p);
extern u32 func_02007F68(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_02007F1C(u8 *base, u16 id, u16 qty, u16 d);
extern u32 func_020173EC(void);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
extern void func_020178D8(void *p, u32 a);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_02017E1C(void *, u32, u32);
extern void *func_02008F08(int a0);
extern u32 func_020307B0(void *p);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void *func_0200CA1C(void *a);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern void *func_02012F2C(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0207DC44(int, int, int, int);
extern void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(u32 a, u32 b);
void func_02205580(void *unused,char *p);
void func_022055BC(char *a, u32 a1, u32 a2, u32 k0, u32 v0, u32 k1, u32 v1, u32 b1, u32 b2, u32 m0, u32 w0, u32 m1, u32 w1);
u32 func_02205620(u32 heap, u32 a, u32 b, u32 k0, u32 v0, u32 k1, u32 v1);
void func_022056E8(u32 *a, char *b);
void func_02205844(int a, char *b);
void func_02205854(void);
extern u32 d_020A7370;
extern u32 d_02208F40[];
extern u8 d_02208CCC[];

void func_02205580(void *unused,char *p) {func_021B709C(*(u8 * *)&((struct Obj04595 *)p)->f9C);*(u32 *)&((struct Obj04595 *)p)->f9C=0;if(((struct Obj04595 *)p)->f94)func_02045808((struct U16Vec *)(((struct Obj04595 *)p)->f94));if(((struct Obj04595 *)p)->f98)func_02045808((struct U16Vec *)(((struct Obj04595 *)p)->f98));func_02045C04(*(struct Rec * *)&((struct Obj04595 *)p)->f90);}


void func_022055BC(char *a, u32 a1, u32 a2, u32 k0, u32 v0, u32 k1, u32 v1,
                   u32 b1, u32 b2, u32 m0, u32 w0, u32 m1, u32 w1)
{
    if (((struct Obj03903 *)a)->f94 != 0)
        func_02045808((struct U16Vec *)(((struct Obj03903 *)a)->f94));
    if (((struct Obj03903 *)a)->f98 != 0)
        func_02045808((struct U16Vec *)(((struct Obj03903 *)a)->f98));
    ((struct Obj03903 *)a)->f94 = func_02205620(((struct Obj03903 *)a)->f2, a1, a2, k0, v0, k1, v1);
    ((struct Obj03903 *)a)->f98 = func_02205620(((struct Obj03903 *)a)->f2, b1, b2, m0, w0, m1, w1);
}


u32 func_02205620(u32 heap, u32 a, u32 b, u32 k0, u32 v0, u32 k1, u32 v1)
{
    Param p[2];
    u32 src, w, r, i;
    int z;

    if (k0 == 4 && k1 == 4) {
        r = (u32)func_02045EC0((struct MsgBank *)a, b);
    } else {
        src = (u32)func_02045EC0((struct MsgBank *)a, b);
        w = (u32)func_0201EC64(heap);
        p[0].kind = k0;
        p[0].val = v0;
        p[1].kind = k1;
        p[1].val = v1;
        for (i = 0, z = i; i < 2; i++) {
            switch (p[i].kind) {
            case 0:
                func_0201EE0C((struct WordSet *)w, i, (const void *)p[i].val, z, 1, z);
                break;
            case 1:
                func_0201EE84((void *)w, i, (void *)p[i].val);
                break;
            case 2:
                func_0201EEF4((void *)w, i, (void *)p[i].val);
                break;
            case 3:
                func_0201EF34((struct WordSet *)w, i, *(u16 *)p[i].val);
                break;
            }
        }
        r = (u32)func_020457B0(0x100, heap);
        func_0201F250((struct WordSet *)w, (void *)r, (void *)src);
        func_02045808((struct U16Vec *)src);
        func_0201ED04((struct WordSet *)w);
    }
    return r;
}


void func_022056E8(u32 *a, char *b)
{
    void *save;
    u32 p, q, v;
    int i;

    save = func_0201292C((const struct BigObj *)a[0]);
    if ((int)func_0201AA18((void *)a[1]) >= (int)func_0201AA14((void *)a[1]))
        return;
    if (func_02007F68(save, 4, 1, ((struct Obj06644 *)b)->f0) == 0)
        return;
    p = (u32)func_02030734(((struct Obj06644 *)b)->f0, func_020173EC(), 1, (const char *)d_02208F40, 0xaf5);
    func_02019CE0((const struct RecDC *)(((struct Obj06644 *)b)->f10), (struct RecDC *)p);
    func_020178D8((void *)p, 0x124);
    func_02017E40((void *)p, 0x98, 4);
    func_02017E40((void *)p, 6, 0);
    func_02017E40((void *)p, 0xb, 0);
    for (i = 0x19; i < 0x36; i++)
        func_02017E40((void *)p, i, 0);
    for (i = 0x4d; i < 0x6d; i++)
        func_02017E40((void *)p, i, 0);
    for (i = 0x78; i < 0x8d; i++)
        func_02017E40((void *)p, i, 0);
    v = (u32)func_02045EC0((struct MsgBank *)d_020A7370, func_02017E1C((void *)p, 5, 0));
    func_02017E40((void *)p, 0x73, v);
    func_02045808((struct U16Vec *)v);
    func_02017E40((void *)p, 0x9d, 0);
    v = (u32)func_02008F08(((struct Obj06644 *)b)->f0);
    func_02017E40((void *)p, 0xa7, v);
    func_020307B0((void *)v);
    func_02017E40((void *)p, 0x9f, 0);
    func_0201A98C((void *)a[1], (void *)p);
    func_02007F1C(save, 4, 1, ((struct Obj06644 *)b)->f0);
    func_020307B0((void *)p);
    q = (u32)func_0200CA1C((void *)a[0]);
    func_0200CFA0((struct Blk37 *)q, (void *)p);
    func_0200CDE0((struct Blk37 *)q, (void *)p);
    q = (u32)func_02012F2C((int *)a[0]);
    func_02008DF0((struct Sub02008C20Obj *)q, 10);
    func_02008DF0((struct Sub02008C20Obj *)q, 0x58);
}


void func_02205844(int a, char *b)
{
    func_02017E40((void *)(((struct Obj24950 *)b)->f10), 6, 0);
}


void func_02205854(void)
{
    u32 i;

    func_020434DC(1, 1);
    REG_BG0CNT = REG_BG0CNT & ~3;
    REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3002) | 2;
    REG_DISP3DCNT &= ~0x3010;
    REG_DISP3DCNT &= ~0x3004;
    REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3000) | 8;
    REG_DISP3DCNT &= ~0x3020;
    func_0207DC44(0, 0, 0, 0);
    i = 0;
    func_0207DD24(0, 0, 0x7fff, 0x3f, i);
    REG_VIEWPORT = 0xbfff0000;
    for (; i < 4; i++)
        func_02046A94((u8)i, (const u16 *)(d_02208CCC + i * 8));
    func_02046BE0(1, 0);
}
