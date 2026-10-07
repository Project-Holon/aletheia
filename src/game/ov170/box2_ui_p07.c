/*
 * file:     box2_ui_p07.c
 * unit:     yes
 * function: func_021EE7F4, func_021EE850, func_021EE8A8, func_021EE944, func_021EE95C, func_021EE96C, func_021EE9C4, func_021EE9F4, func_021EEA48, func_021EEB18, func_021EEB30, func_021EEB40, func_021EEBDC, func_021EEBF4, func_021EEC04, func_021EEC1C
 * address:  0x021EE7F4
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
 *   func_020260E4 0x020260E4 thumb
 *   func_021EE408 0x021EE408 thumb ov170
 *   func_021EE754 0x021EE754 thumb ov170
 *   func_02025DE8 0x02025DE8 thumb
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   func_021DD238 0x021DD238 thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_021EF5E8 0x021EF5E8 thumb
 *   func_020355D8 0x020355D8 arm
 *   func_021EEF74  0x021EEF74  thumb  ov170
 *   func_021DC9B4  0x021DC9B4  thumb  ov170
 *   func_021E066C  0x021E066C  thumb  ov170
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj24039.h"
#include "../../matched/include/Obj12180.h"
#include "../../matched/include/Obj24040.h"
#include "../../matched/include/Obj12181.h"
#include "../../matched/include/Obj12183.h"
#include "../../matched/include/Obj12184.h"
#include "../../matched/include/Obj18531.h"

#define OBJ(p) (*(void **)(WORK(p) + 0x70))
struct Sound;
struct WinMgr;
typedef unsigned char  u8;

typedef unsigned int u32;

extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE408(char *, int);
extern void func_021EE754(unsigned char *, unsigned);
extern int func_02025DE8(struct Sound *obj);
extern u32 func_020362DC(void);
extern unsigned int func_0203633C(void);
extern void func_021DD238(char *p);
extern u8 func_020260E0(struct Sound *obj);
extern int func_021EF5E8(struct WinMgr *mgr);
extern void func_020355D8(u8 v);
extern void func_021EEF74(char *q, int a, int b);
extern void func_021DC9B4(char *p, int v);
extern int func_021E066C(char *p);
void func_021EE7F4(char *p, unsigned r);
unsigned func_021EE850(char *p);
unsigned func_021EE8A8(char *p);
void func_021EE944(char *p, int a, int b);
void func_021EE95C(void *a, int tag);
unsigned func_021EE96C(char *p);
void func_021EE9C4(char *p, int a, int b);
void func_021EE9F4(char *p, unsigned r);
unsigned func_021EEA48(char *p);
void func_021EEB18(char *p, int a, int b);
void func_021EEB30(void *a, int tag);
unsigned func_021EEB40(char *p);
void func_021EEBDC(char *p, int a, int b);
void func_021EEBF4(void *a, int tag);
void func_021EEC04(char *p, int a, int b);
void func_021EEC1C(char *p, unsigned int a);

#define WORK(p) (*(char **)((p) + 0x2c))

void func_021EE7F4(char *p, unsigned r)
{
    if (r - 0x1f <= 1) {
        func_020260E4(*(void **)(WORK(p) + 0x70), 0x1e);
        r = 0x1e;
    } else if (r == 0x21 || r == 0x26 || r - 0x28 <= 2) {
        func_020260E4(*(void **)(WORK(p) + 0x70), *(unsigned *)(WORK(p) + 0xa168));
        r = *(unsigned *)(WORK(p) + 0xa168);
    } else {
        func_021EE408(p, r);
    }
    func_021EE754((unsigned char *)p, r);
    *(unsigned *)(WORK(p) + 0xa168) = r;
}


unsigned func_021EE850(char *p)
{
    unsigned r = func_02025DE8(((struct Obj24039 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70);
    if (r == -1) {
        if (func_020362DC() & 0x800) {
            func_021DD238(p);
            return 0x28;
        }
        if (func_0203633C() & 0x200) {
            func_021DD238(p);
            return 0x1F;
        }
        if (func_0203633C() & 0x100) {
            func_021DD238(p);
            return 0x20;
        }
    }
    return r;
}

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))


unsigned func_021EE8A8(char *p)
{
    unsigned char sel = func_020260E0(*(void **)(WORK(p) + 0x70));
    unsigned r = func_02025DE8(*(void **)(WORK(p) + 0x70));

    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r >= 9 && r <= 14) {
            func_020260E4(*(void **)(WORK(p) + 0x70), sel);
            func_021EE408(p, sel);
            return -1;
        }
        if (func_020362DC() & 0x400) {
            func_020355D8(0);
            return 7;
        }
        if (r == 7) {
            func_020355D8(1);
            return 7;
        }
        if (r == 8) {
            func_020260E4(*(void **)(WORK(p) + 0x70), sel);
            return 8;
        }
    } else if (r - 6 <= 2) {
        func_020260E4(*(void **)(WORK(p) + 0x70), sel);
        func_021EE408(p, sel);
        return -1;
    }
    return r;
}


/*
 * Release the child at +0x2c and reset its field +0x5c to the handler.
 */
void func_021EE944(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((struct Obj12180 *)p)->f2C, a, b);
    func_021DC9B4(((struct Obj12180 *)p)->f2C, (int)((void *)&func_021E066C));
}


void func_021EE95C(void *a, int tag)
{
    if (tag != 0x7 && tag != 0x8)
        func_021EE408(a, tag);
}


unsigned func_021EE96C(char *p)
{
    unsigned r = func_02025DE8(((struct Obj24040 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70);
    if (r == -1) {
        if (func_020362DC() & 0x800) {
            func_021DD238(p);
            return 0x28;
        }
        if (func_0203633C() & 0x200) {
            func_021DD238(p);
            return 0x25;
        }
        if (func_0203633C() & 0x100) {
            func_021DD238(p);
            return 0x26;
        }
    }
    return r;
}

/*
 * Twin of func_021EE7C4 with the same selector and target word.
 */
void func_021EE9C4(char *p, int a, int b)
{
    func_021EE754((unsigned char *)p, a);
    func_021EEF74((char *)(*(int *)&((struct Obj00000 *)p)->f2C), a, b);
    func_021DC9B4((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 0x021E066D);
    *(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0xA168) = a;
}

#undef WORK
#define WORK(p) (*(char **)((p) + 0x2c))

void func_021EE9F4(char *p, unsigned r)
{
    if (r - 0x25 <= 1) {
        func_020260E4(*(void **)(WORK(p) + 0x70), 0x24);
        r = 0x24;
    } else if (r - 0x28 <= 2) {
        func_020260E4(*(void **)(WORK(p) + 0x70), *(unsigned *)(WORK(p) + 0xa168));
        r = *(unsigned *)(WORK(p) + 0xa168);
    } else {
        func_021EE408(p, r);
    }
    func_021EE754((unsigned char *)p, r);
    *(unsigned *)(WORK(p) + 0xa168) = r;
}

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))


unsigned func_021EEA48(char *p)
{
    unsigned char sel = func_020260E0(OBJ(p));
    unsigned r = func_02025DE8(OBJ(p));
    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r - 0x24 <= 2) {
            func_020260E4(OBJ(p), sel);
            func_021EE408(p, sel);
            return -1;
        }
        if (func_020362DC() & 0x400) {
            func_020355D8(0);
            return 0x22;
        }
        if (r == 0x22) {
            func_020355D8(1);
            return 0x22;
        }
        if (r == 0x23) {
            func_020260E4(OBJ(p), sel);
            return 0x23;
        }
    } else if (r - 0x21 <= 2) {
        func_020260E4(OBJ(p), sel);
        func_021EE408(p, sel);
        return -1;
    }
    if (r == -1) {
        if (func_0203633C() & 0x200) {
            func_021DD238(p);
            return 0x1F;
        }
        if (func_0203633C() & 0x100) {
            func_021DD238(p);
            return 0x20;
        }
    }
    return r;
}


void func_021EEB18(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((struct Obj12181 *)p)->f2C, a, b);
    func_021DC9B4(((struct Obj12181 *)p)->f2C, (int)((void *)&func_021E066C));
}


/*
 * Ignore the two known tags, otherwise run the update.
 */
void func_021EEB30(void *a, int tag)
{
    if (tag != 0x22 && tag != 0x23)
        func_021EE408(a, tag);
}

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))


/*
 * Twin of src/matched/ov170_func_021EE8A8.c.  The image tests the first
 * range as subs/cmp #2, which only the `r - 9 <= 2` spelling gives; the
 * two-compare form r >= 9 && r <= 11 keeps two branches.
 */
unsigned func_021EEB40(char *p)
{
    unsigned char sel = func_020260E0(*(void **)(WORK(p) + 0x70));
    unsigned r = func_02025DE8(*(void **)(WORK(p) + 0x70));

    if (func_021EF5E8(*(struct WinMgr **)(WORK(p) + 0x74)) == 0) {
        if (r - 9 <= 2) {
            func_020260E4(*(void **)(WORK(p) + 0x70), sel);
            func_021EE408(p, sel);
            return -1;
        }
        if (func_020362DC() & 0x400) {
            func_020355D8(0);
            return 7;
        }
        if (r == 7) {
            func_020355D8(1);
            return 7;
        }
        if (r == 8) {
            func_020260E4(*(void **)(WORK(p) + 0x70), sel);
            return 8;
        }
    } else if (r - 6 <= 2) {
        func_020260E4(*(void **)(WORK(p) + 0x70), sel);
        func_021EE408(p, sel);
        return -1;
    }
    return r;
}


void func_021EEBDC(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((struct Obj12183 *)p)->f2C, a, b);
    func_021DC9B4(((struct Obj12183 *)p)->f2C, (int)((void *)&func_021E066C));
}


void func_021EEBF4(void *a, int tag)
{
    if (tag != 0x7 && tag != 0x8)
        func_021EE408(a, tag);
}


void func_021EEC04(char *p, int a, int b)
{
    func_021EEF74(*(char * *)&((struct Obj12184 *)p)->f2C, a, b);
    func_021DC9B4(((struct Obj12184 *)p)->f2C, (int)((void *)&func_021E066C));
}

/*
 * Queue the byte-narrowed index, then re-run the frame update.
 */
void func_021EEC1C(char *p, unsigned int a)
{
    func_020260E4((struct Sound *)(*(int *)(((struct Obj18531 *)p)->f2C + 0x70)), (unsigned char)a);
    func_021EE408(p, a);
}
