/*
 * function: func_02197AAC
 * address:  0x02197AAC
 * packet:   pkt_ov021_02197AAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201283C  0x0201283C  thumb
 *   func_0201058C  0x0201058C  thumb
 *   func_02027974  0x02027974  thumb
 *   func_02028178  0x02028178  thumb
 *   func_02040618  0x02040618  arm
 *   func_020310C4  0x020310C4  arm
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0204A600  0x0204A600  arm
 *   func_02155A90  0x02155A90  thumb  ov010
 *   func_020121CC  0x020121CC  thumb
 *   func_020221A4  0x020221A4  thumb
 *   func_02012204  0x02012204  thumb
 *   func_0202223C  0x0202223C  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01495.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BigObj;
struct Ctx;
struct IcaAnime;
struct PrintSys;
struct Tcbl;
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_0201058C(void *key);
extern void func_02027974(u32);
extern void func_02028178(u8 *p);
extern void func_02040618(u32, u32, u32);
extern void func_020310C4(struct Tcbl *p);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0204A600(void);
extern u32 func_02155A90(u8 *p);
extern u32 func_020121CC(struct IcaAnime *p);
extern u32 func_020221A4(void);
extern u32 func_02012204(const struct Ctx *p);
extern void func_0202223C(u32, u32);

u32 func_02197AAC(u32 r0, u32 r1, u32 r2, u8 *a)
{
    u32 ret;
    void (*cb)(u8 *);

    cb = *(void (**)(u8 *))a;
    ret = 1;
    func_0201058C((void *)func_0201283C((const struct BigObj *)(((struct Obj01495 *)a)->f30)));
    if (cb != 0) {
        cb(a);
        ret = 0;
    }
    if (((struct Obj01495 *)a)->f2C0 != 0) {
        func_02027974(((struct Obj01495 *)a)->f2C0);
    }
    if (((struct Obj01495 *)a)->f2E0 != 0) {
        func_02028178((u8 *)(((struct Obj01495 *)a)->f2E0));
    }
    func_02040618(4, 3, ((struct Obj01495 *)a)->f2AC);
    ((struct Obj01495 *)a)->f2AC = ((struct Obj01495 *)a)->f2AC - 1;
    func_020310C4((struct Tcbl *)(((struct Obj01495 *)a)->f2B8));
    func_0201C4E4((struct PrintSys *)(((struct Obj01495 *)a)->f2BC));
    func_0204A600();
    if (((struct Obj01495 *)a)->f306 == 0) {
        func_020121CC((struct IcaAnime *)func_02155A90((u8 *)(((struct Obj01495 *)a)->f2E4)));
    }
    if (func_020221A4() != 0) {
        if (func_02012204((const struct Ctx *)func_02155A90((u8 *)(((struct Obj01495 *)a)->f2E4))) != 0) {
            ((struct Obj01495 *)a)->f8 = 12;
            ret = 1;
            func_0202223C(0, 0);
            func_0202223C(1, 0);
        }
    }
    return ret;
}
