/*
 * file:     box2_main_p03.c
 * unit:     yes
 * function: func_021DD684, func_021DD694, func_021DD6E8, func_021DD718, func_021DD810, func_021DD8A8
 * address:  0x021DD684
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_020179B8  0x020179B8  thumb
 *   func_0201747C  0x0201747C  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02017E88 0x02017E88 thumb
 *   func_02019CF8 0x02019CF8 thumb
 *   func_02019D00 0x02019D00 thumb
 *   func_021DD25C 0x021DD25C thumb ov170
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_021EC48C 0x021EC48C thumb ov170
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_02017D30  0x02017D30  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_02017D70  0x02017D70  thumb
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj18451.h"

struct Blk37;
struct Mon;
struct Sav;
typedef unsigned int u32;

typedef unsigned short u16;

extern unsigned func_0201AA18(void *party);
extern void *func_0201AB28(void *party, unsigned i);
extern unsigned func_02017E1C(void *p, unsigned id, unsigned v);
extern int func_020179B8(int a0, int a1);
extern void *func_0201747C(struct Mon *p, u32 heap);
extern void *func_0200CA1C(void *a);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern u32 func_020307B0(void *p);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern u16 func_02019CF8(u32 item);
extern u32 func_02019D00(u32 item);
extern unsigned func_021DD25C(void ***,unsigned short,unsigned short,unsigned,unsigned);
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern void func_021EC48C(unsigned char *p, int box, int pos, int win);
extern void func_021DEFEC(char *p, int b);
extern u32 func_02017D30(struct Sav *p);
extern void func_020185C4(void *p);
extern u32 func_02017D70(struct Sav *p, u32 f);
int func_021DD684(unsigned char *p, unsigned i);
int func_021DD694(void ***p, unsigned skip);
void func_021DD6E8(void **pp, void *a, u32 b);
int func_021DD718(void **pp, void *mon);
void func_021DD810(unsigned char *p,unsigned a,unsigned b,unsigned box);
void func_021DD8A8(void **pp, u32 idx);

int func_021DD684(unsigned char *p, unsigned i)
{
    unsigned v = i + p[0x19];
    if (v >= p[0x15])
        v -= p[0x15];
    return v;
}


int func_021DD694(void ***p, unsigned skip)
{
    unsigned i;
    for (i = 0; i < func_0201AA18((*p)[2]); i++) {
        if (i != skip) {
            void *m = func_0201AB28((*p)[2], i);
            if (func_02017E1C(m, 0x4C, 0) == 0 && func_02017E1C(m, 0xA0, 0) != 0)
                return 1;
        }
    }
    return 0;
}


void func_021DD6E8(void **pp, void *a, u32 b)
{
    void *r;

    func_020179B8((int)a, b);
    r = func_0201747C(a, 0x4c);
    func_0200CFA0(func_0200CA1C((void *)(*(u32 *)*pp)), r);
    func_020307B0(r);
}


/*
 * 2026-10-04 (wD2 lane 02): witness filed: src/matched/arm9/func_02019CF8.c (EXACT, Thumb forwarder to func_02019BBC).
 * Expected EXACT after the integrator's manifest refresh.
 *
 * Re-derives the form of a species whose form follows its held item
 * (0x1ED by plate, 0x289 by drive, 0x1E7 by the item 0x70) and applies it;
 * returns 1 when the form changed.
 *
 * Blocker (MATCH): the call to 0x02019CF8 has no witness.  0x02019CF8 is an
 * 8-byte Thumb tail-call thunk (ldr r3, =0x02019BBD; bx r3) that the arm9
 * listing decodes as ARM and nothing else calls; seeding it as a Thumb
 * function start promotes this file to EXACT.
 */
int func_021DD718(void **pp, void *mon)
{
    u16 species = func_02017E88(mon, 5, 0);
    if (species == 0x1ED) {
        u16 item = func_02017E88(mon, 6, 0);
        u16 form = func_02017E88(mon, 0x6F, 0);
        u16 want = func_02019CF8(item);
        if (form != want)
            func_021DD6E8(pp, mon, want);
        if (form != want)
            return 1;
    } else if (species == 0x289) {
        u16 item = func_02017E88(mon, 6, 0);
        u16 form = func_02017E88(mon, 0x6F, 0);
        u16 want = func_02019D00(item);
        if (form != want)
            func_021DD6E8(pp, mon, want);
        if (form != want)
            return 1;
    } else if (species == 0x1E7) {
        u16 item = func_02017E88(mon, 6, 0);
        u16 old = func_02017E88(mon, 0x6F, 0);
        u16 form = old;
        if (old == 0) {
            if (item == 0x70) {
                func_021DD6E8(pp, mon, 1);
                form = 1;
            }
        } else if (item != 0x70) {
            func_021DD6E8(pp, mon, 0);
            form = 0;
        }
        if (old != form)
            return 1;
    }
    return 0;
}

/*
 * lever: the repeated third-argument truncations require a u16 extern parameter.
 */
void func_021DD810(unsigned char *p,unsigned a,unsigned b,unsigned box)
{
    if(a<30 && b<30) return;
    if(a>=30 && b>=30) return;
    if(a>=30) a=b;
    if(func_021DD25C((void ***)p,a,box,5,0)!=492) return;
    if(func_021DD25C((void ***)p,a,box,0x6f,0)==0) return;
    func_021DD6E8((void **)p,(void *)func_021DD2D0((void ***)p,box,a),0);
    func_021DD8A8((void **)p,a);
    if(box==p[0x14])
        func_021EC48C(p,box,a,*(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C+a+0x3dd2));
    if(p[0x16]==a) func_021DEFEC((char *)p,a);
}


void func_021DD8A8(void **pp, u32 idx)
{
    void *h;
    u32 v;

    if (idx < 0x1e)
        return;
    h = func_0201AB28(((struct Obj18451 *)((char *)*pp))->f8, idx - 0x1e);
    v = func_02017D30(h);
    func_020185C4(h);
    func_02017D70(h, v);
}
