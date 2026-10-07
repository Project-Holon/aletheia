/*
 * file:     startmenu_p04.c
 * unit:     yes
 * function: func_021B9DD0, func_021B9E54, func_021B9E7C
 * address:  0x021B9DD0
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020489F4  0x020489F4  arm
 *   func_020115C0  0x020115C0  thumb
 *   func_02011B8C  0x02011B8C  thumb
 *   func_02048AD0  0x02048AD0  arm
 *   func_02047964  0x02047964  arm
 *   func_020479D8  0x020479D8  arm
 *   func_02048A18  0x02048A18  arm
 *   func_02047A60  0x02047A60  arm
 *   func_02047970  0x02047970  arm
 *   func_02047910  0x02047910  arm
 *   d_021BD538     0x021BD538  data  ov088  a4
 *   func_02011558  0x02011558  thumb
 *   func_02048AC4  0x02048AC4  arm
 *   func_02048C4C  0x02048C4C  arm
 *   func_020480E4  0x020480E4  arm
 *   func_02047E54  0x02047E54  arm
 *   func_020115EC  0x020115EC  thumb
 *   func_0204784C  0x0204784C  arm
 */
#include "../../matched/include/Obj03674.h"
#include "../../matched/include/Obj07721.h"

struct IcaAnime;
struct Light;
struct Arg;
struct Ctx;
struct Rec;
struct AnmCtl;
typedef signed int     s32;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

extern u32 func_020489F4(u8 *a0, int i);
extern u32 func_020115C0(struct IcaAnime *p, s32 v);
extern void func_02011B8C(void *, void *);
extern void func_02048AD0(struct Light *l);
extern void func_02047964(void);
extern void func_020479D8(void);
extern u32 func_02048A18(u8 *a0, int i);
extern void func_02047A60(void *a0, struct Arg *a1);
extern void func_02047970(void);
extern int func_02047910(void *a, int idx, int amount);
extern void func_02011558(struct IcaAnime *p);
extern u32 func_02048AC4(void *ptr);
extern void func_02048C4C(int);
extern void func_020480E4(struct Ctx *c, u32 i);
extern void func_02047E54(struct Rec *p);
extern void func_020115EC(struct IcaAnime *p, s32 v);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
void func_021B9DD0(int *p);
void func_021B9E54(int *p);
void func_021B9E7C(int *p, int x);
extern char d_021BD538[];


void func_021B9DD0(int *p)
{
    int base;
    unsigned i;
    void *h;
    base = func_020489F4((void *)p[0], ((struct Obj03674 *)p)->f4);
    func_020115C0((void *)p[3], 0x1000);
    func_02011B8C((void *)p[4], (void *)p[3]);
    func_02048AD0((void *)p[4]);
    func_02047964();
    func_020479D8();
    for (i = 0; i < 3; i++) {
        h = (void *)func_02048A18((void *)p[0], (unsigned short)(base + i));
        func_02047A60(h, (struct Arg *)d_021BD538);
    }
    func_02047970();
    for (i = 0; i < 3; i++) {
        h = (void *)func_02048A18((void *)p[0], (unsigned short)(base + i));
        func_02047910(h, 0, 0x1000);
        if (i == 0)
            func_02047910(h, 1, 0x1000);
    }
}


/*
 * note:     listing extent (40) runs 2 bytes past the compiled function (38);
 *           trailing alignment padding, no byte difference.
 */
void func_021B9E54(int *p)
{
    func_02011558((struct IcaAnime *)p[3]);
    func_02048AC4((void *)p[4]);
    func_02048C4C(p[2]);
    func_020480E4((struct Ctx *)p[0], ((unsigned short *)p)[2]);
    func_02047E54((struct Rec *)p[0]);
}


void func_021B9E7C(int *p, int x)
{
    int v;
    int base;
    unsigned i;
    void *h;
    v = x << 12;
    func_020115EC((void *)p[3], v);
    base = func_020489F4((void *)p[0], ((struct Obj07721 *)p)->f4);
    for (i = 0; i < 3; i++) {
        h = (void *)func_02048A18((void *)p[0], (unsigned short)(base + i));
        func_0204784C(h, 0, &v);
        if (i == 0)
            func_0204784C(h, 1, &v);
    }
}
