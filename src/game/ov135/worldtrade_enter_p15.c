/*
 * file:     worldtrade_enter_p15.c
 * unit:     yes
 * function: func_021FAAD4, func_021FAB70, func_021FAC50, func_021FAC84, func_021FAC8C, func_021FAD08
 * address:  0x021FAAD4
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
 *   func_0202CAE4 0x0202CAE4 thumb
 *   func_0202CF84 0x0202CF84 thumb
 *   func_021F9260 0x021F9260 thumb ov135
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_021FBEB8 0x021FBEB8 thumb ov135
 *   func_0202CB4C 0x0202CB4C thumb
 *   func_0202CC58 0x0202CC58 thumb
 *   func_0202CD64 0x0202CD64 thumb
 *   func_021F87E0 0x021F87E0 thumb ov135
 *   func_021FB2F0 0x021FB2F0 thumb ov135
 *   func_021F9EEC 0x021F9EEC thumb ov135
 *   func_021FBF04 0x021FBF04 thumb ov135
 *   func_0204B878 0x0204B878 arm
 *   func_021F4FF4 0x021F4FF4 thumb ov135
 *   tbl_02203220 0x02203220 data a1
 *   func_022028C8  0x022028C8  thumb
 *   func_02045334  0x02045334  arm
 *   func_0202CEBC  0x0202CEBC  thumb
 *   func_0202CE40 0x0202CE40 thumb
 *   func_020355C4 0x020355C4 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 */
#include "../../matched/include/Obj03296.h"
#include "../../matched/include/Obj00474.h"
#include "../../matched/include/Obj01745.h"
#include "../../matched/include/Obj09234.h"

struct WinMgr;
struct MsgBank;
struct U16Vec;
struct Obj;
struct Descriptor;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef struct { u8 x; u8 y; } CurPos;

typedef signed int s32;

extern void func_0202CAE4(struct WinMgr *mgr, u32 idx, u32 arc, u32 member, u32 alloc);
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern void func_021F9260(void *, u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045808(struct U16Vec *vec);
extern void func_021FBEB8(void *, void *, void *, u32, void *);
extern void func_0202CB4C(struct WinMgr *mgr, u32 idx, s8 x, s8 y);
extern void func_0202CC58(struct WinMgr *mgr, u32 idx);
extern void func_0202CD64(struct WinMgr *mgr, u32 idx, s8 dx, s8 dy, u8 frames);
extern int func_021F87E0(void **, void *, int);
extern void func_021FB2F0(void *, int, int);
extern u32 func_021F9EEC(u8 *p, u32 n);
extern void func_021FBF04(void *, void *, void *, int, u32);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021F4FF4(u32, u32, u32);
extern u32 func_022028C8(void *win, u32 z, void *str, u32 x, u32 y, u32 z2, u16 color, void *g);
extern void func_02045334(struct Descriptor *d);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);
extern u32 func_0202CE40(struct WinMgr *mgr, u32 idx);
extern u8 func_020355C4(void);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
void func_021FAAD4(u8 *p);
void func_021FAB70(u8 *p);
void func_021FAC50(void *mgr, void *win, void *str, u32 x, u16 color, void *g);
int func_021FAC84(void);
int func_021FAC8C(u8 *p);
int func_021FAD08(u8 *p);
extern const CurPos tbl_02203220[];

void func_021FAAD4(u8 *p)
{
    int i;
    void *str;
    func_0202CAE4(((struct Obj03296 *)p)->f18, 0, 96, 25, 1);
    func_0202CF84(((struct Obj03296 *)p)->f18, 0);
    func_021F9260(p, 1);
    for (i = 0; i < 3; i++) {
        str = func_02045EC0(((struct Obj03296 *)p)->f20, i + 130);
        func_021FAC50(((struct Obj03296 *)p)->f18, (*(void ***)p)[i], str, 2, 0x3dc2, p + 124);
        func_02045808(str);
    }
    func_021FBEB8(((struct Obj03296 *)p)->f18, ((struct Obj03296 *)p)->f20, (*(void ***)p)[14], 74, p + 124);
    func_0202CB4C(((struct Obj03296 *)p)->f18, 0, 32, 0);
    func_0202CC58(((struct Obj03296 *)p)->f18, 0);
    func_0202CD64(((struct Obj03296 *)p)->f18, 0, -4, 0, 4);
}

void func_021FAB70(u8 *p)
{
    func_0202CAE4(((struct Obj00474 *)p)->f18, 0, 96, 29, 1);
    func_0202CF84(((struct Obj00474 *)p)->f18, 0);
    func_021F9260(p, 2);
    if (((struct Obj00474 *)p)->f5C == 1)
        ((struct Obj00474 *)p)->f58 = func_021F87E0((void **)(p + 48), ((struct Obj00474 *)p)->f20, 1);
    else if (((struct Obj00474 *)p)->f5C == 0)
        ((struct Obj00474 *)p)->f58 = func_021F87E0((void **)(p + 48), ((struct Obj00474 *)p)->f20, 0);
    func_021FB2F0(p, 0, ((struct Obj00474 *)p)->f58);
    ((struct Obj00474 *)p)->f56 = 0;
    func_021FBF04(((struct Obj00474 *)p)->f18, ((struct Obj00474 *)p)->f34, (*(void ***)p)[4], ((struct Obj00474 *)p)->f56, func_021F9EEC((u8 *)(((struct Obj00474 *)p)->f58), 4));
    func_021FBEB8(((struct Obj00474 *)p)->f18, ((struct Obj00474 *)p)->f20, (*(void ***)p)[14], 74, p + 124);
    func_0202CB4C(((struct Obj00474 *)p)->f18, 0, 32, 0);
    func_0204B878((struct Obj *)(((struct Obj00474 *)p)->f8), 6);
    ((struct Obj00474 *)p)->f7A = 0;
    *(int *)&((struct Obj00474 *)p)->f44 = 0;
    func_021F4FF4(((struct Obj00474 *)p)->f8, tbl_02203220[*(int *)(p + 68)].x, tbl_02203220[*(int *)(p + 68)].y);
    func_0202CC58(((struct Obj00474 *)p)->f18, 0);
    func_0202CD64(((struct Obj00474 *)p)->f18, 0, -4, 0, 4);
    *(int *)&((struct Obj00474 *)p)->f48 = 34;
}


void func_021FAC50(void *mgr, void *win, void *str, u32 x, u16 color, void *g)
{
    func_022028C8(win, 0, str, x, 0, 0, color, g);
    func_02045334(win);
    func_0202CEBC(mgr, 0, win);
}

int func_021FAC84(void)
{
    return -1;
}

/*
 * lever: explicit if/else calls preserve the flag argument's scheduling.
 */
int func_021FAC8C(u8 *p)
{
    if (!func_0202CE40(*(struct WinMgr * *)&((struct Obj01745 *)p)->f18, 0)) {
        if (func_020355C4() == 1)
            func_0204B3DC(((struct Obj01745 *)p)->f8, 0);
        else
            func_0204B3DC(((struct Obj01745 *)p)->f8, 1);
        if (((struct Obj01745 *)p)->f54 == 2) {
            func_0204B92C(((struct Obj01745 *)p)->fC, 0);
            func_0204B92C(((struct Obj01745 *)p)->f10, 0);
            func_0204B878(((struct Obj01745 *)p)->fC, 38);
            func_0204B878(((struct Obj01745 *)p)->f10, 39);
            func_021F4FF4(*(u32 *)&((struct Obj01745 *)p)->fC, 228, 120);
            func_021F4FF4(*(u32 *)&((struct Obj01745 *)p)->f10, 154, 120);
            func_0204B3DC(((struct Obj01745 *)p)->fC, 1);
            func_0204B3DC(((struct Obj01745 *)p)->f10, 1);
        }
        ((struct Obj01745 *)p)->f48 = ((struct Obj01745 *)p)->f4C;
    }
    return -1;
}


/*
 * Flush the queued value when the probe reports empty, then answer -1.
 */
int func_021FAD08(u8 *p)
{
    if (func_0202CE40(*(struct WinMgr * *)&((struct Obj09234 *)p)->f18, 0) == 0) {
        ((struct Obj09234 *)p)->f48 = ((struct Obj09234 *)p)->f4C;
    }
    return -1;
}
