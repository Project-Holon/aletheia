/*
 * file:     unit_021C4CB4_p01.c
 * unit:     yes
 * function: func_021C4CB4, func_021C4CE4, func_021C4D34, func_021C4D98, func_021C4E2C, func_021C4EC0
 * address:  0x021C4CB4
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C49A4 0x021C49A4 thumb ov127
 *   func_021C5334 0x021C5334 thumb ov127
 *   d_021C604C 0x021C604C data a4
 *   func_021C4B7C 0x021C4B7C thumb ov127
 *   func_021C4B90 0x021C4B90 thumb ov127
 *   func_021C4A00 0x021C4A00 thumb ov127
 *   func_021C52CC 0x021C52CC thumb ov127
 */
#include "../../matched/include/Obj00535.h"

typedef unsigned char u8;

typedef unsigned short u16;

struct pair { u16 a, b; };

extern int func_021C49A4(u8 *,unsigned);
extern void func_021C5334(char *);
extern void func_021C4B7C(char *, struct pair);
extern void func_021C4B90(char *, struct pair);
extern void func_021C4A00(void *, int, int);
extern struct pair func_021C52CC(struct pair, int);
void func_021C4CB4(u8 *p);
void func_021C4CE4(char *p, struct pair v, int n);
void func_021C4D34(char *p, struct pair v, int n);
void func_021C4D98(char *p, struct pair v, int n);
void func_021C4E2C(char *p, struct pair v, int n);
void func_021C4EC0(char *p, struct pair v, int n);

extern int (*d_021C604C)(u8 *);

void func_021C4CB4(u8 *p)
{
 int i=func_021C49A4(p,5); int r=(*(int (**)(u8 *))((unsigned)&d_021C604C+i*4))(p);
 (((struct Obj00535 *)p)->f16)++;
 if(r==1) {func_021C5334((char *)p); ((struct Obj00535 *)p)->f16=0;}
}

/*
 * extent: next larger wrapper starts at 0x021C4D34, its initial push
 *         is included by the stale label extent; filed separately.
 */
void func_021C4CE4(char *p, struct pair v, int n)
{
    func_021C4B7C(p, v);
    func_021C4B90(p, v);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 0);
}

/*
 * start: corrected from second label at initial push plus two bytes.
 */
void func_021C4D34(char *p, struct pair v, int n)
{
    func_021C4B7C(p, v);
    func_021C4B90(p, v);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 1);
    func_021C4A00(p, 8, 0);
    func_021C4A00(p, 9, 2);
}

void func_021C4D98(char *p, struct pair v, int n)
{
    struct pair x = func_021C52CC(v, n);
    func_021C4B90(p, v);
    func_021C4B7C(p, x);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 2);
    func_021C4A00(p, 8, 0);
    func_021C4A00(p, 9, 8);
}

void func_021C4E2C(char *p, struct pair v, int n)
{
    struct pair x = func_021C52CC(v, n);
    func_021C4B90(p, v);
    func_021C4B7C(p, x);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 3);
    func_021C4A00(p, 8, 0);
    func_021C4A00(p, 9, 4);
}

void func_021C4EC0(char *p, struct pair v, int n)
{
    func_021C4B7C(p, v);
    func_021C4B90(p, v);
    func_021C4A00(p, 6, n);
    func_021C4A00(p, 5, 4);
}
