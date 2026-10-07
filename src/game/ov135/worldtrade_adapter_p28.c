/*
 * file:     worldtrade_adapter_p28.c
 * unit:     yes
 * function: func_022004F0, func_0220052C, func_0220053C, func_022005EC
 * address:  0x022004F0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_022009A4 0x022009A4 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_0204B92C 0x0204B92C arm
 *   func_021F4F90 0x021F4F90 thumb ov135
 *   g_022038EC  0x022038EC  data  ov135
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021F4ED4 0x021F4ED4 thumb ov135
 *   func_02200A10 0x02200A10 thumb ov135
 *   func_020061E4  0x020061E4  thumb
 *   func_021F4FF4  0x021F4FF4  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B878  0x0204B878  arm
 *   func_020355D8  0x020355D8  arm
 *   func_020362DC  0x020362DC  arm
 *   func_020355C4  0x020355C4  arm
 *   func_0204B9A0  0x0204B9A0  arm
 *   tbl_022038E0   0x022038E0  data  a2
 */
#include "../../matched/include/Obj02863.h"
#include "../../matched/include/Obj01749.h"

struct Obj;
struct Actor;
typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed char s8;

typedef signed short s16;

typedef struct {
    u16 x;
    u16 y;
} Pos;

typedef struct {
    u8 pad0[0x28];
    int state;
    u8 pad2C[0xC0 - 0x2C];
    u16 sel;
    u8 padC2[0xBF4 - 0xC2];
    u32 cursor;
} Work;

extern void func_022009A4(u8 *p, u32 n, int a2, int a3, int a4);
extern void func_021F4E98(void *,unsigned,unsigned);
extern void func_0204B92C(struct Obj *,unsigned);
extern void func_021F4F90(void *);
extern int func_02035C08(const void *key);
extern void func_021F4EC0(u8 *, u32, u32);
extern int func_021F4ED4(void);
extern void func_02200A10(u8 *, int, int, int, int);
extern void func_020061E4(u32 a);
extern void func_021F4FF4(u32 a, u32 b, u32 c);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
extern u8 func_020355C4(void);
extern void func_0204B9A0(struct Actor *a);
int func_022004F0(unsigned char *p);
int func_0220052C(void);
void func_0220053C(u8 *p, int mode);
int func_022005EC(Work *p);
extern char g_022038EC[];
extern const Pos tbl_022038E0[];

int func_022004F0(unsigned char *p) {func_022009A4(p,4,1,0,0xf0f);func_021F4E98(p,10,6);func_0204B92C(*(struct Obj * *)&((struct Obj02863 *)p)->fBF4,1);func_021F4F90(p);return 2;}


/*
 * Tail call into func_02035C08 with the overlay's own state object.
 */
int func_0220052C(void)
{
    return func_02035C08(g_022038EC);
}

void func_0220053C(u8 *p, int mode)
{
    switch (mode) {
    case 0:
        if (((struct Obj01749 *)p)->f32 == 0) {
            func_021F4EC0(p, 5, 5);
            ((struct Obj01749 *)p)->f28 = 9;
        } else if (((struct Obj01749 *)p)->f36 == 0) {
            func_021F4EC0(p, 7, 11);
            ((struct Obj01749 *)p)->f18 = 2;
            ((struct Obj01749 *)p)->f28 = 9;
            ((struct Obj01749 *)p)->f36 = 0xE10;
        } else {
            func_022009A4(p, 40, 1, 0, 0xF0F);
            func_021F4E98(p, 11, 5);
            func_020061E4(0x557);
            ((struct Obj01749 *)p)->fDFC = 0;
        }
        break;
    case 1:
        ((struct Obj01749 *)p)->fE1A = 0;
        func_021F4EC0(p, 4, 13);
        ((struct Obj01749 *)p)->f28 = 9;
        break;
    case 2:
        func_02200A10(p, 7, func_021F4ED4(), 0, 0xF0F);
        func_021F4E98(p, 10, 12);
        break;
    }
}


int func_022005EC(Work *p)
{
    int r;

    r = func_0220052C();
    if (r != -1) {
        p->sel = r;
        func_020061E4(0x548);
        func_021F4FF4(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_0204B878((struct Obj *)p->cursor, 1);
        p->state = 0xE;
        func_020355D8(1);
        if (p->sel == 2) {
            func_020061E4(0x551);
        } else {
            func_020061E4(0x54C);
        }
        return 2;
    }
    if (func_020362DC() != 0 && func_020355C4() == 1) {
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_020355D8(0);
        func_020061E4(0x548);
        return 2;
    }
    if (func_020362DC() & 2) {
        p->sel = 2;
        func_021F4FF4(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_0204B878((struct Obj *)p->cursor, 1);
        p->state = 0xE;
        func_020061E4(0x551);
    } else if (func_020362DC() & 1) {
        func_0204B3DC((struct Obj *)p->cursor, 1);
        func_0204B878((struct Obj *)p->cursor, 1);
        p->state = 0xE;
        func_020061E4(0x54C);
    } else if (func_020362DC() & 0x40) {
        if (p->sel != 0) {
            p->sel--;
            func_020061E4(0x548);
            func_0204B3DC((struct Obj *)p->cursor, 1);
            func_0204B9A0((struct Actor *)p->cursor);
            func_021F4FF4(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        }
    } else if (func_020362DC() & 0x80) {
        if (p->sel < 2) {
            p->sel++;
            func_020061E4(0x548);
            func_0204B3DC((struct Obj *)p->cursor, 1);
            func_0204B9A0((struct Actor *)p->cursor);
            func_021F4FF4(p->cursor, tbl_022038E0[p->sel].x, tbl_022038E0[p->sel].y);
        }
    }
    return 2;
}
