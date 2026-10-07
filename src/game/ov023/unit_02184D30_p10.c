/*
 * file:     unit_02184D30_p10.c
 * unit:     yes
 * function: func_02186708, func_021867C4, func_02186860, func_02186878, func_02186888
 * address:  0x02186708
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_0203996C  0x0203996C  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_020399A8  0x020399A8  arm
 */
#include "../../matched/include/Obj03626.h"
#include "../../matched/include/Obj06120.h"
#include "../../matched/include/Obj01674.h"
#include "../../matched/include/Obj20371.h"
#include "../../matched/include/Obj07611.h"

struct PrintSys;
struct Descriptor;
struct Entry;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

typedef signed int     s32;

typedef struct {
    u8 b[4];
    u8 lo : 3;
    u8 mid : 3;
    u8 hi : 2;
    u8 pad;
} Rec;

extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_02045770(struct Descriptor *a);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *a);
extern struct Entry *func_0203996C(s32 idx);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern struct Entry *func_020399A8(void);
void func_02186708(char *p);
void func_021867C4(char *p);
void func_02186860(char *p, int x, int y);
int func_02186878(char *p);
void func_02186888(char *p);


void func_02186708(char *p)
{
    int i;
    u32 h;

    func_0201C4E4((struct PrintSys *)(((struct Obj03626 *)p)->f164));
    func_0201C4E4((struct PrintSys *)(((struct Obj03626 *)p)->f168));
    for (i = 0; i < 5; i++) {
        h = ((struct Obj03626 *)p)->f164;
        if (*(u8 *)(p + i * 8 + 0x130) != 0) {
            if (func_0201C6C4((struct PrintSys *)h, (void *)((u32)func_02045770((struct Descriptor *)*(u32 *)(p + i * 8 + 0x12C)))) == 0) {
                func_02045334((struct Descriptor *)*(u32 *)(p + i * 8 + 0x12C));
                *(u8 *)(p + i * 8 + 0x130) = 0;
            }
        }
    }
    h = ((struct Obj03626 *)p)->f168;
    if (((struct Obj03626 *)p)->f160 != 0) {
        if (func_0201C6C4((struct PrintSys *)h, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj03626 *)p)->f15C))) == 0) {
            func_02045334((struct Descriptor *)((struct Obj03626 *)p)->f15C);
            ((struct Obj03626 *)p)->f160 = 0;
        }
    }
}


void func_021867C4(char *p)
{
    switch (((struct Obj06120 *)p)->f9270) {
    case 0x2903:
        if (func_0203D3A8(func_0203996C(0xFF), 0x2903, 1, (u32)(p + 0x9274)) != 0) {
            ((struct Obj06120 *)p)->f9270 = 0;
        }
        break;
    case 0x2904:
        if (func_0203D3A8(func_0203996C(0xFF), 0x2904, 0, 0) != 0) {
            ((struct Obj06120 *)p)->f9270 = 0;
        }
        break;
    case 0x2905:
        if (func_0203D3A8(func_0203996C(0xFF), 0x2905, 4, (u32)(p + 0x9278)) != 0) {
            ((struct Obj06120 *)p)->f9270 = 0;
        }
        break;
    case 0x2906:
        break;
    case 0x2907:
        if (func_0203D3A8(func_020399A8(), 0x2907, 0, 0) != 0) {
            ((struct Obj06120 *)p)->f9270 = 0;
        }
        break;
    }
}

void func_02186860(char *p, int x, int y)
{
    if (((struct Obj01674 *)p)->f9270 == 0) {
        ((struct Obj01674 *)p)->f9270 = x;
        ((struct Obj01674 *)p)->f9274 = y;
    }
}

int func_02186878(char *p)
{
    int i = ((struct Obj20371 *)p)->fBBC - 1;
    if (i < 0) i = 99;
    return i;
}


void func_02186888(char *p)
{
    if (((Rec *)(p + ((struct Obj07611 *)p)->fBBC * 30))->mid != 0
        || ((Rec *)(p + func_02186878(p) * 30))->mid != 0) {
        ((struct Obj07611 *)p)->fBBC += 1;
        if (((struct Obj07611 *)p)->fBBC >= 100) {
            ((struct Obj07611 *)p)->fBBC = 0;
        }
    }
}
