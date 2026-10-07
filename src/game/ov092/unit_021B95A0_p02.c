/*
 * file:     unit_021B95A0_p02.c
 * unit:     yes
 * function: func_021B9AA0, func_021B9BD8, func_021B9C34, func_021B9C80, func_021B9CA4
 * address:  0x021B9AA0
 * region:   ov092
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021B9D44 0x021B9D44 data a1
 *   d_021B9D6E 0x021B9D6E data ov092 a2
 *   d_021B9D58 0x021B9D58 data ov092 a2
 *   d_021B9D4D 0x021B9D4D data ov092 a1
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017F9C  0x02017F9C  thumb
 *   func_0216E62C  0x0216E62C  thumb  ov010
 *   func_02048F60 0x02048F60 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 */
#include "../../matched/include/Obj13264.h"

struct Blk37;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct S {
    u32 f00;
    u8 *f04;
};

extern u32 func_0201AA18(void *);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *,u32,u32);
extern void func_02017E40(void *,u32,u32);
extern u32 func_020056EC(u32);
extern void func_02017F9C(void *mon, u32 v);
extern void func_0216E62C(int a, int p, int id);
extern void *func_02048F60(u32 archive_id, u32 member, u32 heap);
extern u32 func_020307B0(void *p);
extern void *func_0200CA1C(void *a);
extern void func_0200CFA0(struct Blk37 *p, void *m);
void func_021B9AA0(void *party);
void func_021B9BD8(void *party);
void func_021B9C34(struct S *s, void *party, int c);
u32 func_021B9C80(u32 p, u32 heap);
void func_021B9CA4(struct S *s, void *party);
extern const u8 d_021B9D44[];
extern const u16 d_021B9D6E[];
extern const u16 d_021B9D58[];
extern const u8 d_021B9D4D[];

void func_021B9AA0(void *party)
{
    int i;
    void *mon;
    u16 species,item;
    int ability;
    int random;
    int j;
    u8 tier;
    int threshold;
    int index;
    for (i=0;i<(int)func_0201AA18(party);i++) {
        mon = func_0201AB28(party,i);
        species = func_02017E1C(mon,0xab,0);
        item = func_02017E1C(mon,6,0);
        ability = (u8)func_02017E1C(mon,0xa,0);
        if (ability == 0x35 && species != 0 && species != 0x28a && item == 0 && func_020056EC(10) == 0) {
            random = func_020056EC(100);
            tier = (func_02017E1C(mon,0x9e,0)-1)/10u;
            if (tier >= 10) tier=9;
            for (j=0;j<9;j++) {
                if (d_021B9D44[j] > random) {
                    func_02017E40(mon,6,d_021B9D6E[tier+j]);
                    break;
                } else if (random >= 98 && random <= 99) {
                    func_02017E40(mon,6,d_021B9D58[tier+(99-random)]);
                    break;
                }
            }
        }
        if (ability == 0x76 && species != 0 && species != 0x28a && item == 0) {
            index=0;
            threshold=10;
            ability=(u8)func_02017E1C(mon,0x9e,0);
            while (threshold < ability) {
                threshold+=10;
                index++;
            }
            if (func_020056EC(100) < d_021B9D4D[index]) func_02017E40(mon,6,0x5e);
        }
    }
}


void func_021B9BD8(void *party)
{
    int i;
    void *mon;
    u16 a;
    u8 b;

    for (i = 0; i < (int)func_0201AA18(party); i++) {
        mon = func_0201AB28(party, i);
        a = func_02017E1C(mon, 0xab, 0);
        b = func_02017E1C(mon, 0xa, 0);
        if (b == 0x1e && a != 0 && a != 0x28a) {
            func_02017F9C(mon, 0);
        }
    }
}


void func_021B9C34(struct S *s, void *party, int c)
{
    int i;

    if (*(u32 *)s->f04 - 2 > 1) {
        for (i = 0; i < (int)func_0201AA18(party); i++) {
            if (s->f04[0xc2 + i] != 0) {
                func_0216E62C(s->f00, (int)func_0201AB28(party, i), c);
            }
        }
    }
}

u32 func_021B9C80(u32 p, u32 heap)
{
    void *data;
    u32 result;
    u8 *record;
    data = func_02048F60(0x98, 0, heap);
    record = (u8 *)data + ((struct Obj13264 *)p)->f0 * 0x24;
    result = *(record + ((struct Obj13264 *)p)->f4 + 0x13);
    func_020307B0(data);
    return result;
}


void func_021B9CA4(struct S *s, void *party)
{
    int i;
    void *mon;
    u32 t;

    t = *(u32 *)s->f04;
    switch (t) {
    case 0:
    case 1:
        for (i = 0; i < (int)func_0201AA18(party); i++) {
            if (s->f04[0xc2 + i] != 0) {
                mon = func_0201AB28(party, i);
                if (func_02017E1C(mon, 5, 0) == 0x1ec) {
                    func_0200CFA0(func_0200CA1C((void *)s->f00), mon);
                }
            }
        }
        break;
    }
}
