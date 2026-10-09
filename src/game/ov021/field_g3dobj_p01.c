/*
 * file:     field_g3dobj_p01.c
 * unit:     yes
 * function: func_021C5FA8, func_021C5FC0, func_021C5FEC, func_021C6018, func_021C602C, func_021C6054
 * address:  0x021C5FA8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_021BB528  0x021BB528  thumb  ov021
 *   func_021AE01C  0x021AE01C  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_021ADF94  0x021ADF94  thumb  ov021
 */
#include "../../matched/include/Obj07564.h"
#include "../../matched/include/Obj06080.h"
#include "../../matched/include/Obj06081.h"

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct {
    u8 pad0[0x60];
    u32 f60;
} Work;

typedef unsigned short u16;

extern u32 func_020362DC(void);
extern u32 func_02188CD0(u8 *p);
extern void func_0216D674(void *p, unsigned short v);
extern u32 func_021BB528(u32 a, u32 b, u32 c, u32 d);
extern void func_021AE01C(u32 a, u16 v);
extern void func_021AC154(u32 a);
extern u32 func_021ADF94(u32 a, void *b, u32 c, int d);
int func_021C5FA8(Work *w, u32 n);
int func_021C5FC0(u8 *p, u32 lim);
void func_021C5FEC(u8 *p);
void func_021C6018(u32 *p);
void func_021C602C(u8 *p);
void func_021C6054(u32 *p);



int func_021C5FA8(Work *w, u32 n)
{
    if (w->f60++ < n)
        return 0;
    w->f60 = 0;
    return 1;
}



/*
 * Wait step: 1 on a key press, 2 on timeout, otherwise 0.
 */
int func_021C5FC0(u8 *p, u32 lim)
{
    u32 n = ((struct Obj07564 *)p)->f60;

    ((struct Obj07564 *)p)->f60 = n + 1;
    if (n < lim) {
        if (func_020362DC() & 1) {
            ((struct Obj07564 *)p)->f60 = 0;
            return 1;
        }
    } else {
        ((struct Obj07564 *)p)->f60 = 0;
        return 2;
    }
    return 0;
}



/*
 * Switches the window to mode 2 and opens the message box.
 */
void func_021C5FEC(u8 *p)
{
    u32 o = func_02188CD0((u8 *)(((struct Obj06080 *)p)->f8));

    func_0216D674((void *)(((struct Obj06080 *)p)->f1C), 2);
    ((struct Obj06080 *)p)->f2C = func_021BB528(o, ((struct Obj06080 *)p)->f1C, 0, 1);
    func_021AE01C(((struct Obj06080 *)p)->f30, 1);
}


void func_021C6018(u32 *p)
{
    if (p[11] != 0) {
        func_021AC154(p[11]);
        p[11] = 0;
    }
}


void func_021C602C(u8 *p)
{
    ((struct Obj06081 *)p)->f30 = func_021ADF94(func_02188CD0((u8 *)(((struct Obj06081 *)p)->f8)), p + 0x40, ((struct Obj06081 *)p)->f58, ((struct Obj06081 *)p)->f44 == ((struct Obj06081 *)p)->f38);
}

void func_021C6054(u32 *p)
{
    if (p[12] != 0) {
        func_021AC154(p[12]);
        p[12] = 0;
    }
}
