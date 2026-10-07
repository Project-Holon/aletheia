/*
 * file:     zukan_detail_graphic_p12.c
 * unit:     yes
 * function: func_021BDB08, func_021BDB54, func_021BDBA0, func_021BDBAC, func_021BDBB8, func_021BDBEC, func_021BDC14, func_021BDC2C, func_021BDC48, func_021BDC80, func_021BDCA4, func_021BDCDC, func_021BDCF8, func_021BDD24
 * address:  0x021BDB08
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BD2E0 0x021BD2E0 thumb ov208
 *   func_021BD308 0x021BD308 thumb ov208
 *   ov208_func_021BD360  0x021BD360  thumb
 *   ov208_func_021BD330  0x021BD330  thumb
 *   ov208_func_021BE1BC  0x021BE1BC  thumb
 *   func_021BE170  0x021BE170  thumb
 *   func_021BD378  0x021BD378  thumb
 *   func_021BD3A4 0x021BD3A4  thumb  ov208
 *   func_021BD3B4 0x021BD3B4  thumb  ov208
 *   func_021BD35C  0x021BD35C  thumb
 *   func_021BD358  0x021BD358  thumb
 *   func_021BDD98  0x021BDD98  thumb
 *   func_021BE3C4  0x021BE3C4  thumb
 *   func_021BE504  0x021BE504  thumb
 *   func_021BDFA8 0x021BDFA8  thumb  ov208
 *   func_021BE4DC 0x021BE4DC  thumb  ov208
 *   func_021BE680 0x021BE680  thumb  ov208
 */
#include "../../matched/include/Obj10895.h"
#include "../../matched/include/Obj14649.h"
#include "../../matched/include/Obj10896.h"
#include "../../matched/include/Obj14650.h"
#include "../../matched/include/Obj02345.h"
#include "../../matched/include/Obj09200.h"
#include "../../matched/include/Obj07227.h"
#include "../../matched/include/Obj09201.h"
#include "../../matched/include/Obj01081.h"

struct Ov208Mgr;
struct Ov208Eff;
struct State { char pad[0x68]; unsigned char count; };

typedef unsigned int u32;

struct Ov208Scene_021BDBA0 {
    u32 pad0[12];
    void *mgr;
};

struct Ov208Scene_021BDBAC {
    u32 pad0[12];
    void *mgr;
};

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

struct Ov208ActDesc {
    int f0;
    s16 x;
    s16 y;
    u16 h8;
    u16 ha;
    u16 hc;
    u16 he;
    u16 h10;
    u16 h12;
    u16 h14;
    u16 h16;
    u32 f18;
    u32 f1c;
};

struct Ov208ActList {
    struct Ov208ActDesc *descs;
    u32 count;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
};

struct Ov208ActSrc {
    int id;
    u16 x;
    u16 y;
    u16 h8;
    u16 pad;
    u32 fc;
    u32 f10;
};

struct Ov208Slot {
    struct Ov208ActSrc *src;
    u32 obj;
};

struct Ov208Scene_021BDBB8 {
    u16 heap;
    u16 pad2;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 mgr;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
    u32 f50;
    u32 f54;
    u32 f58;
    u32 f5c;
    u32 f60;
    u32 f64;
    u8  count;
    u8  pad69[3];
    struct Ov208Slot slots[10];
};

struct Ov208Scene_021BDBEC {
    u32 pad0[4];
    u32 f10;
    u32 pad14[7];
    u32 mgr;
    u32 pad34[16];
    int *keyA;
    u32 pad78;
    int *keyB;
};

struct Ov208Scene_021BDC48 {
    u32 pad0[2];
    u32 f8;
    u32 pad0c[9];
    void *mgr;
    u32 f34;
};

struct Ov208Scene_021BDCF8 {
    u16 heap;
    u16 pad2;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 mgr;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
    u32 f50;
    u32 f54;
    u32 f58;
    u32 f5c;
    u32 f60;
    u32 f64;
    u8  count;
    u8  pad69[3];
    struct Ov208Slot slots[10];
};

extern int func_021BD2E0(char *);
extern int func_021BD308(struct Ov208Mgr *m);
extern void ov208_func_021BD360(void *mgr);
extern void ov208_func_021BD330(void *mgr, int v);
extern void ov208_func_021BE1BC(struct Ov208Scene_021BDBB8 *p);
extern void func_021BE170(struct Ov208Scene_021BDBB8 *p);
extern void func_021BD378(int a, int b, int c);
extern void func_021BD3A4(int a, int b, int c);
extern int func_021BD3B4(void *mgr, int key);
extern int func_021BD35C(char *p);
extern void func_021BD358(char *p, int v);
extern void func_0204B84C(int, int);
extern void func_0204047C(int idx, unsigned short val);
extern void func_021BDD98(struct Ov208Scene_021BDCF8 *p);
extern void func_021BE3C4(struct Ov208Scene_021BDCF8 *p);
extern void func_021BE504(struct Ov208Scene_021BDCF8 *p);
extern void func_021BDFA8(struct Ov208Eff *e);
extern void func_021BE4DC(struct Ov208Eff *e);
extern void func_021BE680(char *);
unsigned func_021BDB08(const struct State *p);
unsigned func_021BDB54(const struct State *p);
void ov208_func_021BDBA0(struct Ov208Scene_021BDBA0 *p);
void ov208_func_021BDBAC(struct Ov208Scene_021BDBAC *p, int v);
void ov208_func_021BDBB8(struct Ov208Scene_021BDBB8 *p, u32 kind);
void ov208_func_021BDBEC(struct Ov208Scene_021BDBEC *p, int v);
void func_021BDC14(char *p, int b);
int func_021BDC2C(char *p);
void ov208_func_021BDC48(struct Ov208Scene_021BDC48 *p, u32 on);
int func_021BDC80(char *p);
void func_021BDCA4(char *p, unsigned char v);
void func_021BDCDC(int unused, char *p);
void ov208_func_021BDCF8(struct Ov208Scene_021BDCF8 *p);
void func_021BDD24(char *p);

unsigned func_021BDB08(const struct State *p)
{
    int key=func_021BD2E0(*(char * *)&((struct Obj10895 *)p)->f30);
    unsigned result=0;
    unsigned char i;
    unsigned count;
    char *entry;
    if(key!=-1) {
        switch(((struct Obj10895 *)p)->f10) {
        case 0: case 1: case 2:
            i=0;
            count=p->count;
            for(;i<count;i++) {
                entry=*(char **)((char *)p+i*8+0x6c);
                if(key==((struct Obj14649 *)entry)->f0) { result=((struct Obj14649 *)entry)->fC; break; }
            }
            break;
        }
    }
    return result;
}

/*
 * trailing: 021BDB9E..021BDBA0 is two-byte zero alignment padding.
 * matching: initialize the byte counter before reading the bound.
 */
unsigned func_021BDB54(const struct State *p)
{
    int key=func_021BD308((struct Ov208Mgr *)(*(char * *)&((struct Obj10896 *)p)->f30));
    unsigned result=0;
    unsigned char i;
    unsigned count;
    char *entry;
    if(key!=-1) {
        switch(((struct Obj10896 *)p)->f10) {
        case 0: case 1: case 2:
            i=0;
            count=p->count;
            for(;i<count;i++) {
                entry=*(char **)((char *)p+i*8+0x6c);
                if(key==((struct Obj14650 *)entry)->f0) { result=((struct Obj14650 *)entry)->f10; break; }
            }
            break;
        }
    }
    return result;
}


void ov208_func_021BDBA0(struct Ov208Scene_021BDBA0 *p)
{
    ov208_func_021BD360(p->mgr);
}


void ov208_func_021BDBAC(struct Ov208Scene_021BDBAC *p, int v)
{
    ov208_func_021BD330(p->mgr, v);
}


void ov208_func_021BDBB8(struct Ov208Scene_021BDBB8 *p, u32 kind)
{
    u32 saved;
    int restore;

    if (p->f10 == 0) {
        restore = 0;
        p->f14 = p->f18;
        p->f18 = kind;
        if (kind == p->f1c) {
            saved = p->f1c;
            restore = 1;
            p->f1c = 4;
        }
        ov208_func_021BE1BC(p);
        func_021BE170(p);
        if (restore)
            p->f1c = saved;
    }
}


void ov208_func_021BDBEC(struct Ov208Scene_021BDBEC *p, int v)
{
    if (p->f10 == 2) {
        func_021BD378(p->mgr, *p->keyA, v);
        func_021BD378(p->mgr, *p->keyB, v);
    }
}


/*
 * Calls func_021BD3A4 with two fields and the second argument while +0x10 is clear.
 */
void func_021BDC14(char *p, int b)
{
    if (((struct Obj02345 *)p)->f10 == 0)
        func_021BD3A4(*(int *)&((struct Obj02345 *)p)->f30, *(int *)*(int * *)&((struct Obj02345 *)p)->f7C, b);
}


int func_021BDC2C(char *p)
{
    if (((struct Obj09200 *)p)->f10 == 0)
        return func_021BD3B4((void *)(((struct Obj09200 *)p)->f30),
                             *(int *)*(int * *)&((struct Obj09200 *)p)->f7C);
    return 0;
}


void ov208_func_021BDC48(struct Ov208Scene_021BDC48 *p, u32 on)
{
    p->f34 = on;
    if (on != 0) {
        if (func_021BD35C(p->mgr) == 0 && p->f8 == 2)
            func_021BD358(p->mgr, 1);
    } else {
        if (func_021BD35C(p->mgr) != 0)
            func_021BD358(p->mgr, 0);
    }
}



int func_021BDC80(char *p)
{
    switch (((struct Obj07227 *)p)->f10) {
    case 0:
        return ((struct Obj07227 *)p)->f44;
    case 1:
        return ((struct Obj07227 *)p)->f50;
    case 2:
        return ((struct Obj07227 *)p)->f5C;
    }
    return -1;
}


/*
 * Stores the mode at +0x38, arms +0x3C and hands the mode to every +0x70 handle.
 */
void func_021BDCA4(char *p, unsigned char v)
{
    unsigned char i;

    ((struct Obj02345 *)p)->f38 = v;
    ((struct Obj02345 *)p)->f3C = 1;
    for (i = 0; i < ((struct Obj02345 *)p)->f68; i++)
        func_0204B84C(*(int *)(p + i * 8 + 0x70), v);
}


/*
 * BLOCKED.  MATCH: the call at +0x10 targets 0204047C, an ARM address with no label and no pool witness outside the compared range, so the site stays wildcarded.
 */
void func_021BDCDC(int unused, char *p)
{
    if (((struct Obj09201 *)p)->f3C != 0) {
        func_0204047C(1, ((struct Obj09201 *)p)->f38);
        ((struct Obj09201 *)p)->f3C = 0;
    }
}


void ov208_func_021BDCF8(struct Ov208Scene_021BDCF8 *p)
{
    switch (p->f10) {
    case 0:
        func_021BDD98(p);
        break;
    case 1:
        func_021BE3C4(p);
        break;
    case 2:
        func_021BE504(p);
        break;
    }
    p->f34 = 1;
}


void func_021BDD24(char *p)
{
    switch (((struct Obj01081 *)p)->fC) {
    case 0:
        func_021BDFA8((struct Ov208Eff *)p);
        break;
    case 1:
        func_021BE4DC((struct Ov208Eff *)p);
        break;
    case 2:
        func_021BE680(p);
        break;
    }
}
