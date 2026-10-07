/*
 * file:     gsync_state_p15.c
 * unit:     yes
 * function: func_021D79A4, func_021D7A18, func_021D7A5C, func_021D7B68
 * address:  0x021D79A4
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021D7960 0x021D7960 thumb ov123
 *   func_021D5C2C 0x021D5C2C thumb ov123
 *   func_021D5C0C 0x021D5C0C thumb ov123
 *   func_021D5C9C 0x021D5C9C thumb ov123
 *   func_021D5D8C 0x021D5D8C thumb ov123
 *   func_021D5CF8 0x021D5CF8 thumb ov123
 *   func_021D5C64 0x021D5C64 thumb ov123
 *   d_021DAB88 0x021DAB88 data a1
 *   d_021DAB90 0x021DAB90 data a1
 *   d_021DAB9C 0x021DAB9C data a1
 *   func_0200C6E4 0x0200C6E4 thumb
 *   func_021D5B10 0x021D5B10 thumb ov123
 *   func_021D5BD4 0x021D5BD4 thumb ov123
 */
#include "../../matched/include/Obj05365.h"
#include "../../matched/include/Obj13989.h"
#include "../../matched/include/Obj01934.h"
#include "../../matched/include/Obj03271.h"

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

extern int func_021D5C2C(char *p);
extern int func_021D5C0C(char *p);
extern void *func_021D5D8C(u8 *p);
extern void func_021D5C9C(char *p);
extern void func_021D6FF0(char *p);
extern void func_021D7960(int a);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern int func_021D5CF8(char *p);
extern int func_021D5C64(char *p, void *arg, int value);
extern u32 func_0200C6E4(void);
extern u32 func_0200E8B0(void);
extern char *func_021D5B10(int heap, int size);
extern int func_021D5BD4(char *p);
void func_021D79A4(int a);
void func_021D7A18(int a);
void func_021D7A5C(u8 *p);
void func_021D7B68(char *p);
extern const char d_021DAB88[], d_021DAB90[], d_021DAB9C[];

void func_021D79A4(int a)
{
    if(func_021D5C2C((char *)(((struct Obj05365 *)a)->f8))) {
        ((struct Obj05365 *)a)->f80=0xfff0;
        func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x3fe);
        return;
    }
    if(func_021D5C0C((char *)(((struct Obj05365 *)a)->f8))) {
        if(func_021D5D8C((u8 *)(((struct Obj05365 *)a)->f8))==0) {
            ((struct Obj05365 *)a)->f80=0xfff0;
            func_021D6EE0((u8 *)a,(int)func_021D6FF0,0x407);
            return;
        }
        func_021D5C9C((char *)(((struct Obj05365 *)a)->f8));
        func_021D6EE0((u8 *)a,(int)func_021D7960,0x40d);
    }
}

void func_021D7A18(int a)
{
    if (func_021D5CF8((char *)(((struct Obj13989 *)a)->f8))) {
        func_021D6EE0((u8 *)a, (int)func_021D79A4, 0x415);
        return;
    }
    ((struct Obj13989 *)a)->f80 = 0xfff0;
    func_021D6EE0((u8 *)a, (int)func_021D6FF0, 0x419);
}

void func_021D7A5C(u8 *p)
{
    if (func_021D5C0C(((struct Obj01934 *)p)->f8)) {
        if (func_021D5C2C(((struct Obj01934 *)p)->f8)) {
            ((struct Obj01934 *)p)->f80 = 0xfff0;
            func_021D6EE0(p, (int)func_021D6FF0, 0x424);
            return;
        }
        switch (p[0xa7]) {
        case 0:
            if (func_021D5C64(((struct Obj01934 *)p)->f8, (void *)d_021DAB88, p[0xa5])) {
                func_021D6EE0(p, (int)func_021D7A18, 0x42b);
                return;
            }
            ((struct Obj01934 *)p)->f80 = 0xfff0;
            func_021D6EE0(p, (int)func_021D6FF0, 0x42f);
            return;
        case 1:
            if (func_021D5C64(((struct Obj01934 *)p)->f8, (void *)d_021DAB90, p[0xa4])) {
                func_021D6EE0(p, (int)func_021D7A18, 0x434);
                return;
            }
            ((struct Obj01934 *)p)->f80 = 0xfff0;
            func_021D6EE0(p, (int)func_021D6FF0, 0x438);
            return;
        case 2:
            if (func_021D5C64(((struct Obj01934 *)p)->f8, (void *)d_021DAB9C, p[0xa6])) {
                func_021D6EE0(p, (int)func_021D7A18, 0x43d);
                return;
            }
            ((struct Obj01934 *)p)->f80 = 0xfff0;
            func_021D6EE0(p, (int)func_021D6FF0, 0x441);
            return;
        }
    }
}

void func_021D7B68(char *p)
{
    switch (((struct Obj03271 *)p)->fA7) {
    case 0: ((struct Obj03271 *)p)->f8 = func_021D5B10(((struct Obj03271 *)p)->f0, func_0200C6E4() + 4); break;
    case 1: ((struct Obj03271 *)p)->f8 = func_021D5B10(((struct Obj03271 *)p)->f0, 0x20000); break;
    case 2: ((struct Obj03271 *)p)->f8 = func_021D5B10(((struct Obj03271 *)p)->f0, func_0200E8B0() + 4); break;
    }
    if (func_021D5BD4(((struct Obj03271 *)p)->f8)) {
        func_021D6EE0((u8 *)p, (int)func_021D7A5C, 0x458);
        return;
    }
    ((struct Obj03271 *)p)->f80 = 0xfff0;
    func_021D6EE0((u8 *)p, (int)func_021D6FF0, 0x45c);
}
