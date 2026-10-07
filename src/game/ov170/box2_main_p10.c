/*
 * file:     box2_main_p10.c
 * unit:     yes
 * function: func_021DEA3C, func_021DEA4C, func_021DEA6C, func_021DEAFC, func_021DEB08, func_021DEB14, func_021DEB40, func_021DEB70, func_021DEB90, func_021DEC64, func_021DEC98, func_021DED58, func_021DEDCC
 * address:  0x021DEA3C
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
 *   func_021DE8B4  0x021DE8B4  thumb  ov170
 *   func_021ED164 0x021ED164 thumb ov170
 *   func_021ED198 0x021ED198 thumb ov170
 *   func_021ED14C 0x021ED14C thumb ov170
 *   func_021ED310 0x021ED310 thumb ov170
 *   func_02049DB4  0x02049DB4  arm
 *   func_02040B1C  0x02040B1C  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049EB4 0x02049EB4 arm
 *   func_02041090 0x02041090 arm
 *   func_02041300 0x02041300 arm
 *   func_021EB7E8 0x021EB7E8 thumb
 *   func_021EE224 0x021EE224 thumb
 *   func_021EE234 0x021EE234 thumb
 *   func_021EE244 0x021EE244 thumb
 *   func_02021640 0x02021640 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_0200781C  0x0200781C  thumb  ov170
 */
#include "../../matched/include/Obj10648.h"
#include "../../matched/include/Obj12153.h"
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj14262.h"
#include "../../matched/include/Obj23854.h"
#include "../../matched/include/Obj23855.h"
#include "../../matched/include/Obj23856.h"
#include "../../matched/include/Obj23857.h"
#include "../../matched/include/Obj23858.h"
#include "../../matched/include/Obj23859.h"
#include "../../matched/include/Obj23860.h"
#include "../../matched/include/Obj18455.h"
#include "../../matched/include/Obj18456.h"

struct PalAnmSlot;
typedef struct {
    unsigned short index;
    unsigned short pad;
    int value, x, y, dx, dy;
    unsigned dirX:1;
    unsigned dirY:1;
    unsigned count:30;
} Motion;

typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef struct {
    char pad[0xA178];
    signed char box;
    unsigned char flip;
} Work;

extern void func_021DE8B4(unsigned char *p, int slot, unsigned idx, int mode, int flag);
extern void func_021ED164(char *w, int i, int v);
extern void func_021ED198(char *w, int i, int v);
extern void func_021ED14C(int a, int b, int c);
extern void func_021ED310(char *w);
extern void *func_02049DB4(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern u32 func_020307B0(void *p);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02049EB4(u32,u32,u32,u32,u16);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_02041300(u32,int,u8,int,u8,u8,u8);
extern void func_02041B6C(u32 bit);
extern void func_021EB7E8(char **p, unsigned box, int i);
extern void func_021EE224(char *p, int i, int v);
extern int func_021EE234(int *a, int i);
extern void func_021EE244(char *p, int i, int flag);
extern void func_02021640(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern unsigned char func_0200781C(int save, unsigned int box);
void func_021DEA3C(int a, int b, int c, int d);
void func_021DEA4C(char *p, int a, int b);
int func_021DEA6C(char *p, int a);
int func_021DEAFC(int a);
int func_021DEB08(unsigned char *p);
unsigned char func_021DEB14(unsigned char *p, int a);
void func_021DEB40(u32 a, int b, void *c);
void func_021DEB70(int a, int b, int c);
void func_021DEB90(void *unused, void *unused2, int x, u32 base, u32 pal);
void func_021DEC64(void *a, void *b, int c, void *d, int e);
void func_021DEC98(char *p, void *a, int dir);
void func_021DED58(char *p, int a);
int func_021DEDCC(char *p, int box);

/*
 * Same call with the fifth argument fixed to 1.
 */
void func_021DEA3C(int a, int b, int c, int d)
{
    func_021DE8B4((unsigned char *)a, b, c, d, 1);
}

void func_021DEA4C(char *p, int a, int b)
{
    func_021DE8B4((unsigned char *)p, *(unsigned char *)(*(int *)&((struct Obj10648 *)p)->f2C + 0xA17E), a, b, 0);
}

#define WORK(p) (*(char **)((p) + 0x2C))

/*
 * extent: final two bytes are zero alignment padding.
 */
int func_021DEA6C(char *p, int a)
{
    Motion *m;
    m = *(Motion **)(WORK(p) + 0x60);
    if (m->count == 8) {
        if (m->index != 255) {
            if (a == 1)
                func_021ED164(WORK(p), m->index, m->value);
            else
                func_021ED198(WORK(p), m->index, m->value);
        }
        func_021ED310(WORK(p));
        return 0;
    }
    if (m->dirX == 0)
        m->x += m->dx;
    else
        m->x -= m->dx;
    if (m->dirY == 0)
        m->y += m->dy;
    else
        m->y -= m->dy;
    func_021ED14C((int)WORK(p), (short)(m->x >> 8), (short)(m->y >> 8));
    func_021ED310(WORK(p));
    m->count++;
    return 1;
}


/*
 * Set the flag on the object.
 */
int func_021DEAFC(int a)
{
    return func_021DEA6C((char *)a, 1);
}


/*
 * Steps the object with mode 0 (sibling of func_021DEAFC, which passes 1).
 */
int func_021DEB08(unsigned char *p)
{
    return func_021DEA6C((char *)p, 0);
}

/*
 * Add the 3rd/4th parameter to the signed byte at +0x19 and fold the
 * +0x15 field in: add it when negative (signed), subtract it when the
 * result is at or above the unsigned byte.
 */
unsigned char func_021DEB14(unsigned char *p, int a)
{
    signed char v = (signed char)p[0x19] + a;
    if (v < 0)
        v = v + (signed char)p[0x15];
    else if (v >= p[0x15])
        v = v - (signed char)p[0x15];
    return v;
}


void func_021DEB40(u32 a, int b, void *c)
{
    void *out;
    void *r;

    r = func_02049DB4(0x74, b + 0xe, 1, (u32)(&out), 0x4c);
    func_02040B1C(3, (const void *)(((struct Obj12153 *)out)->f14), ((struct Obj12153 *)out)->f10, (u32)c);
    func_020307B0(r);
}

/*
 * Tail wrapper: builds the 6-argument NitroSystem call with the
 *   two stack words 0x20 and 0x4c; third argument shifted left 5.
 */
void func_021DEB70(int a, int b, int c)
{
    func_02049B40(0x74, b + 0x26, 0, c << 5, 0x20, 0x4c);
}

/*
 * abi: Original truncates the tile column into r2 before both call kinds, so their column parameters are u8.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment
 * (`data=(u32)sheet;` before `data=(u32)sheet+12;`). Game code has no line
 * table, so these were stand-ins. The plain single assignment gives EXACT in
 * --lang c99 and --lang c: the output bytes do not change. Older text in
 * this header that asks for the double assignment is superseded.
 */
void func_021DEB90(void *unused, void *unused2, int x, u32 base, u32 pal)
{
    u8 *sheet;
    void *handle;
    u16 value;
    u32 data;
    u8 row,yn;
    u16 *src;
    u32 cur,high;
    u8 col;
    handle=func_02049EB4(116,13,1,(u32)&sheet,76);
    data=(u32)sheet+12;
    row=0;
    high=pal<<12;
    do{
        src=(u16 *)data+row*21;
        cur=x;
        col=0;
        yn=row+1;
        do{
            value=(src[col]&4095)+high+base;
            func_02041090(3,(u32)&value,(u8)cur,yn,1,1);
            ++cur;if(cur>=64)cur=0;
            ++col;
        }while(col<21);
        ++row;
    }while(row<20);
    func_020307B0(handle);
    func_02041300(3,0xe287,cur,0,2,20,17);
    func_02041300(3,0xe2b0,cur,5,2,1,17);
}

void func_021DEC64(void *a, void *b, int c, void *d, int e)
{
    func_021DEB40((int)a, (int)b, d);
    func_021DEB70((int)a, (int)b, e);
    func_021DEB90(a, b, c, (unsigned int)d, e);
    func_02041B6C(3);
}


void func_021DEC98(char *p, void *a, int dir)
{
    int d, e, i;
    char *q;
    if (dir == 0) {
        ((struct Obj23854 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178 -= 0x17;
        if (((struct Obj23855 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178 < 0)
            ((struct Obj23856 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178 += 0x40;
    } else if (dir == 1) {
        ((struct Obj23857 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178 += 0x17;
        if (((struct Obj23858 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178 >= 0x40)
            ((struct Obj23859 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178 -= 0x40;
    }
    q = *(char * *)&((struct Obj00000 *)p)->f2C;
    if (((struct Obj14262 *)q)->fA179 == 0) {
        d = 0x25C;
        e = 0xE;
    } else {
        d = 0xB8;
        e = 0xF;
    }
    ((struct Obj14262 *)q)->fA179 ^= 1;
    func_021DEC64((void *)p, a, ((struct Obj23860 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA178, (void *)d, e);
    if (dir == 2) {
        func_021EB7E8((char **)p, (unsigned char)p[0x14], 7);
        func_021EE224(*(char * *)&((struct Obj00000 *)p)->f2C, 8, 0);
        return;
    }
    i = 7;
    if (func_021EE234((int *)(*(char * *)&((struct Obj00000 *)p)->f2C), 7) == 1)
        i = 8;
    func_021EB7E8((char **)p, (unsigned char)p[0x14], i);
    func_021EE244(*(char * *)&((struct Obj00000 *)p)->f2C, i, dir);
    func_021EE224(*(char * *)&((struct Obj00000 *)p)->f2C, i, 1);
}

#undef WORK
#define WORK(p) (*(Work **)((p) + 0x2C))

void func_021DED58(char *p, int a)
{
    int offset;
    int bank;
    if (WORK(p)->flip == 0) {
        offset = 0x25C;
        bank = 14;
    } else {
        offset = 0xB8;
        bank = 15;
    }
    WORK(p)->flip ^= 1;
    func_021DEB40((unsigned int)p, a, (void *)offset);
    func_02021640(*(void **)((char *)WORK(p) + 0x6C), 0x74, a + 0x26, 0x4C, 0, 0x20, bank << 4);
    func_021DEB90(p, (void *)a, WORK(p)->box, offset, bank);
    func_02041B6C(3);
}


/*
 * Forward the second word of the head object.
 */
int func_021DEDCC(char *p, int box)
{
    return func_0200781C(((struct Obj18456 *)(*(char * *)&((struct Obj18455 *)p)->f0))->f4, box);
}
