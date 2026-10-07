/*
 * file:     itemmenu_p15.c
 * unit:     yes
 * function: func_021B9EF4, func_021BA028
 * address:  0x021B9EF4
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02043678  0x02043678  arm
 *   func_02008550  0x02008550  thumb
 *   func_02049238  0x02049238  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_021BA6A4  0x021BA6A4  thumb  ov070
 */
#include "../../matched/include/Obj00963.h"
#include "../../matched/include/Obj00002.h"

struct Bmp;
struct Sub0200852CObj;
struct Obj;
typedef unsigned int u32;

typedef unsigned short u16;

typedef signed int     s32;

typedef unsigned char  u8;

typedef struct {
    short a, b, c;
    u8 d, e;
} Rect;

extern void *func_020490F4(u32 id, u32 heap);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_02049238(void *);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern void func_021BA6A4(char *);
void func_021B9EF4(char *p);
void func_021BA028(char *p);


/*
 * lever:    the loop's array slots are spelled `p + i * 4 + 0x614` (index
 *           before offset), which keeps `p + i*4` in one register across both
 *           calls; `p + 0x614 + i * 4` and `((int *)(p + 0x614))[i]` both DIFF.
 */
void func_021B9EF4(char *p)
{
    void *bg;
    int i;

    bg = func_020490F4(0x58, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f574 = func_0204AC18(bg, 0x20, 0, 0x1a0, 0, 1, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f578 = func_0204A6C8(bg, 0x1f, 0, 0, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f57C = func_0204AF28(bg, 0x1e, 0x1d, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f554 = func_0204AC18(bg, 0x1c, 0, 0x60, 0, 1, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f560 = func_0204A6C8(bg, 0x1b, 0, 0, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f568 = func_0204AF28(bg, 0x1a, 0x19, ((struct Obj00963 *)p)->f544);
    for (i = 0; i < 8; i++) {
        *(int *)(p + i * 4 + 0x614) = (int)func_02043678(0xc, 2, 0x20, ((struct Obj00963 *)p)->f544);
        *(int *)(p + i * 4 + 0x5F4) =func_0204A6C8(bg, 0x14, 0, 0, ((struct Obj00963 *)p)->f544);
    }
    func_02008550((const struct Sub0200852CObj *)(((struct Obj00963 *)p)->f8));
    ((struct Obj00963 *)p)->f588 = func_0204AC18(bg, 0x15, 0, 0, 0, 3, ((struct Obj00963 *)p)->f544);
    ((struct Obj00963 *)p)->f56C = func_0204AF28(bg, 0x13, 0x12, ((struct Obj00963 *)p)->f544);
    func_02049238(bg);
}


void func_021BA028(char *p)
{
    Rect r1;
    Rect r2;
    Rect r3;
    int i;

    r1.a = 0xf8;
    r1.b = 0x1a;
    r1.d = 1;
    r1.e = 2;
    r1.c = 0;
    *(int *)&((struct Obj00002 *)p)->f6A8 = (int)func_0204B294((void *)((struct Obj00002 *)p)->f69C, ((struct Obj00002 *)p)->f560, ((struct Obj00002 *)p)->f554, ((struct Obj00002 *)p)->f568, &r1, 0, ((struct Obj00002 *)p)->f544);
    func_0204B3DC((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 1);
    func_0204B92C((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A8, 1);
    func_021BA6A4(p);
    r2.a = 0x8c;
    r2.b = 0x30;
    r2.d = 1;
    r2.e = 2;
    r2.c = 1;
    *(int *)&((struct Obj00002 *)p)->f6A4 = (int)func_0204B294((void *)((struct Obj00002 *)p)->f69C, ((struct Obj00002 *)p)->f560, ((struct Obj00002 *)p)->f554, ((struct Obj00002 *)p)->f568, &r2, 0, ((struct Obj00002 *)p)->f544);
    func_0204B3DC((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A4, 1);
    func_0204B92C((struct Obj *)*(int *)&((struct Obj00002 *)p)->f6A4, 1);
    for (i = 0; i < 8; i++) {
        r3.a = 0x8c;
        r3.b = i * 0x18;
        r3.d = 0xa;
        r3.e = 3;
        r3.c = 0;
        *(int *)(p + i * 4 + 0x634) = (int)func_0204B294((void *)((struct Obj00002 *)p)->f69C, *(int *)(p + i * 4 + 0x5F4), ((struct Obj00002 *)p)->f588, ((struct Obj00002 *)p)->f56C, &r3, 0, ((struct Obj00002 *)p)->f544);
        r3.a -= 0x18;
        r3.c = 1;
        *(int *)(p + i * 4 + 0x674) = (int)func_0204B294((void *)((struct Obj00002 *)p)->f69C, ((struct Obj00002 *)p)->f578, ((struct Obj00002 *)p)->f574, ((struct Obj00002 *)p)->f57C, &r3, 0, ((struct Obj00002 *)p)->f544);
        func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x634), 0);
        func_0204B3DC((struct Obj *)*(int *)(p + i * 4 + 0x674), 0);
    }
}
