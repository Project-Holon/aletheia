/*
 * file:     box2_seq_p15.c
 * unit:     yes
 * function: func_021E65E4, func_021E695C
 * address:  0x021E65E4
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
 *   func_021E8F50 0x021E8F50 thumb
 *   func_020362DC 0x020362DC arm
 *   func_021DD238 0x021DD238 thumb
 *   func_021EF1A4 0x021EF1A4 thumb
 *   func_020260F4 0x020260F4 thumb
 *   func_021DD25C 0x021DD25C thumb
 *   func_021DEFEC 0x021DEFEC thumb
 *   func_021EC000 0x021EC000 thumb
 *   func_021EA39C 0x021EA39C thumb
 *   func_021DF040 0x021DF040 thumb
 *   func_020260E4 0x020260E4 thumb
 *   func_021EF170 0x021EF170 thumb
 *   func_021EE96C 0x021EE96C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021EE3E4 0x021EE3E4 thumb
 *   func_021DF0BC 0x021DF0BC thumb
 *   func_021ECC1C 0x021ECC1C thumb
 *   func_021E9C94 0x021E9C94 thumb
 *   func_021E9CE0 0x021E9CE0 thumb
 *   func_021E954C 0x021E954C thumb
 *   func_021EA514 0x021EA514 thumb
 *   func_020260E0 0x020260E0 thumb
 *   func_021E8FE0 0x021E8FE0 thumb
 *   func_021E8FD0 0x021E8FD0 thumb
 *   func_021EA458 0x021EA458 thumb
 *   func_021EF3A0 0x021EF3A0 thumb ov170
 *   func_021ED888 0x021ED888 thumb ov170
 *   func_021ECB20 0x021ECB20 thumb ov170
 *   func_021EF3EC 0x021EF3EC thumb ov170
 *   func_021E8FC0 0x021E8FC0 thumb ov170
 *   func_021E01B0 0x021E01B0 thumb ov170
 *   func_021ED544 0x021ED544 thumb ov170
 *   func_021ED508 0x021ED508 thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 *   func_021EE364 0x021EE364 thumb ov170
 *   func_021EF670 0x021EF670 thumb ov170
 *   func_021EF68C 0x021EF68C thumb ov170
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23905.h"
#include "../../matched/include/Obj23906.h"
#include "../../matched/include/Obj23907.h"
#include "../../matched/include/Obj23908.h"
#include "../../matched/include/Obj23909.h"
#include "../../matched/include/Obj23910.h"
#include "../../matched/include/Obj23911.h"

#define OBJ(p) (*(void **)((p)->work + 0x70))
struct Sound;
struct Struct_02025CD0;
struct WinMgr;
typedef unsigned int u32;

typedef struct {
    void *top;
    unsigned char pad4[0x13 - 4];
    unsigned char b13;
    unsigned char b14;
    unsigned char b15;
    unsigned char b16;
    unsigned char b17;
    unsigned char b18;
    unsigned char b19;
    unsigned char b1A;
    unsigned char b1B;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char b1D;
    unsigned char pad1E[0x28 - 0x1E];
    int x28;
    char *work;
} Obj;

typedef unsigned char  u8;

extern int func_021E8F50(char *p, int v);
extern u32 func_020362DC(void);
extern void func_021DD238(char *p);
extern unsigned func_021EF1A4(void);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
extern void func_021DEFEC(char *p, int b);
extern void func_021EC000(char *p, int i, int v);
extern int func_021EA39C(Obj *p, unsigned i);
extern void func_021DF040(char *p);
extern void func_020260E4(struct Sound *obj, u8 sel);
extern unsigned func_021EF170(void);
extern unsigned func_021EE96C(char *p);
extern void func_020061E4(unsigned se);
extern void func_021EE3E4(char **p, unsigned idx);
extern void func_021DF0BC(unsigned char *p);
extern void func_021ECC1C(unsigned char *p);
extern int func_021E9C94(char *p, int a, int n);
extern int func_021E9CE0(char *p, int a, int n);
extern int func_021E954C(Obj *p, int id, int lo, int arg);
extern int func_021EA514(Obj *p, unsigned i);
extern u8 func_020260E0(struct Sound *obj);
extern int func_021E8FE0(char *p, int v);
extern int func_021E8FD0(char *p, int a);
extern int func_021EA458(Obj *p, unsigned i);
extern void func_021EF3A0(struct WinMgr *mgr);
extern void func_021ED888(char *, int);
extern void func_021ECB20(char *p, int f, int c);
extern void func_021EF3EC(struct WinMgr *mgr);
extern int func_021E8FC0(char *p, int a, int b);
extern int func_021E01B0(u8 *);
extern void func_021ED544(char *p, int b);
extern void func_021ED508(u8 *, int, int);
extern void func_021EE038(char *p, int a, int b, int c);
extern void func_021EE364(char **, int, int);
extern void func_021EF670(char *);
extern void func_021EF68C(char *);
int func_021E65E4(Obj *p);
int func_021E695C(u8 *p);


/*
 * Sibling of src/matched/ov170_func_021E3E84.c.
 */
int func_021E65E4(Obj *p)
{
    unsigned r;
    if (p->hi == 1) {
        p->lo = 0;
        p->hi = 0;
        return func_021E8F50((char *)p, 0x41);
    }
    if ((func_020362DC() & 4) && p->lo != 0 && p->b18 == 0) {
        func_021DD238((char *)p);
        p->lo = 0;
        return func_021E8F50((char *)p, 0x41);
    }
    if (p->b18 == 0) {
        r = func_021EF1A4();
        if (r != -1) {
            func_020260F4(OBJ(p), 0);
            if (func_021DD25C((void ***)p, r + 0x1E, p->b14, 0xA9, 0)) {
                func_021DEFEC((char *)p, (int)r + 0x1E);
                func_021EC000(p->work, 4, 0);
                return func_021EA39C(p, r + 0x1E);
            }
            func_021DF040((char *)p);
            func_020260E4(OBJ(p), r + 0x1E);
            return 0x40;
        }
        r = func_021EF170();
        if (r != -1) {
            func_020260F4(OBJ(p), 0);
            if (func_021DD25C((void ***)p, r, p->b14, 0xA9, 0)) {
                func_021DEFEC((char *)p, r);
                func_021EC000(p->work, 4, 0);
                return func_021EA39C(p, r);
            }
            func_021DF040((char *)p);
            func_020260E4(OBJ(p), r);
            return 0x40;
        }
    }
    r = func_021EE96C((char *)p);
    switch (r) {
    case 0x24:
        if (p->b18 != 0)
            break;
        func_020061E4(0x54C);
        func_021DF040((char *)p);
        return func_021E8F50((char *)p, 0x5D);
    case 0x25:
        func_020061E4(0x548);
        func_020260E4(OBJ(p), 0x24);
        func_021EE3E4((char **)p, 0x24);
        if (p->b18 == 0)
            func_021DF0BC((unsigned char *)p);
        else
            func_021ECC1C((unsigned char *)p);
        return func_021E9C94((char *)p, 0, 0x40);
    case 0x26:
        func_020061E4(0x548);
        func_020260E4(OBJ(p), 0x24);
        func_021EE3E4((char **)p, 0x24);
        if (p->b18 == 0)
            func_021DF0BC((unsigned char *)p);
        else
            func_021ECC1C((unsigned char *)p);
        return func_021E9CE0((char *)p, 0, 0x40);
    case 0x29:
        if (p->b18 != 0)
            break;
        func_020061E4(0x551);
        p->lo = 0;
        return func_021E954C(p, 6, 9, func_021E8F50((char *)p, 0x41));
    case 0x2A:
        if (p->lo == 0 || p->b18 != 0)
            break;
        p->lo = 0;
        return func_021E8F50((char *)p, 0x41);
    case -2:
        if (p->b18 == 1)
            return func_021EA514(p, 0xFF);
        func_020061E4(0x551);
        p->lo = 0;
        return func_021E954C(p, 6, 9, func_021E8F50((char *)p, 0x41));
    case -6:
        if (func_020260E0(OBJ(p)) != 0x24)
            break;
        func_020061E4(0x548);
        return func_021E9C94((char *)p, 0, 0x40);
    case -5:
        if (func_020260E0(OBJ(p)) != 0x24)
            break;
        func_020061E4(0x548);
        return func_021E9CE0((char *)p, 0, 0x40);
    case -4:
        func_020061E4(0x548);
        break;
    case -3:
        func_020061E4(0x548);
        if (p->b18 == 0) {
            unsigned char v = func_020260E0(OBJ(p));
            if (v < 0x24)
                func_021DEFEC((char *)p, v);
            else
                func_021DF040((char *)p);
        }
        return func_021E8FD0((char *)p, func_021E8FE0((char *)p, 0x40));
    case -1:
    case -7:
    case -8:
    case 0x27:
    case 0x28:
        break;
    default:
        if (p->b18 == 1)
            return func_021EA514(p, r);
        return func_021EA458(p, r);
    }
    return 0x40;
}

int func_021E695C(u8 *p)
{
    u8 index;
    u8 selection;
    switch (((struct Obj23905 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA194) {
    case 0:
        func_021DF040((char *)p);
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 4, 0);
        if (p[30] == 0) {
            func_021EF3A0(*(struct WinMgr * *)&((struct Obj23906 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f74);
        } else {
            func_021ED888(*(char * *)&((struct Obj00000 *)p)->f2C, 0);
            func_021ECB20((char *)p, 1, 1);
            func_021EF3EC(*(struct WinMgr * *)&((struct Obj23907 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f74);
        }
        func_020061E4(0x669);
        (((struct Obj23908 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA194)++;
        return func_021E8FC0((char *)p, (int)func_021E01B0, 65);
    case 1:
        ((struct Obj23909 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->fA194 = 0;
        func_021ED544((char *)p, 6);
        func_021ED508(p, 14, 1);
        func_021EE038((char *)p, 0, 0, 1);
        if (p[30] == 0) {
            index = func_020260E0(((struct Obj23910 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f70);
            if (index >= 36)
                index = 0;
            else if (index >= 30)
                index = 0;
            func_021EE364((char **)p, 7, index);
            func_021DEFEC((char *)p, index);
            func_021EF670(*(char * *)&((struct Obj00000 *)p)->f2C);
            return 57;
        } else {
            index = func_020260E0(((struct Obj23911 *)(*(u8 * *)&((struct Obj00000 *)p)->f2C))->f70);
            selection = 0;
            if (index < 36 && index >= 30)
                selection = index - 30;
            func_021EE364((char **)p, 8, selection);
            func_021DEFEC((char *)p, selection + 30);
            func_021EF68C(*(char * *)&((struct Obj00000 *)p)->f2C);
            return 70;
        }
    }
    return 65;
}
