/*
 * function: func_02189204
 * address:  0x02189204
 * packet:   pkt_ov021_02189204
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216CCDC  0x0216CCDC  thumb  ov010
 *   func_0219C554  0x0219C554  thumb
 *   func_0219C680  0x0219C680  thumb
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_02012138  0x02012138  thumb
 *   func_0217C0A8  0x0217C0A8  thumb  ov018
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_021A31A4  0x021A31A4  thumb
 *   func_0219C658  0x0219C658  thumb
 *   func_0219D448  0x0219D448  thumb
 *   func_0218ED50  0x0218ED50  thumb
 *   func_0216CDB8  0x0216CDB8  thumb  ov010
 *   func_0216D2F8  0x0216D2F8  thumb  ov010
 *   func_02189AE8  0x02189AE8  thumb
 *   func_0216D974  0x0216D974  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00571.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;
struct BigObj;
struct Ctx;
struct Sub0200852CObj;

extern void *func_020120F4(const struct Ctx *p);
extern u32 func_02012964(const struct BigObj *p);
extern void func_0216CCDC(char *a, int b, int c, int d, int e, int f);
extern void func_0219C554(u32 a, u32 b, u32 c);
extern void func_0219C680(u32 a);
extern u32 func_02013CC8(u32 a);
extern u32 func_02013CE0(u32 a);
extern u32 func_02012138(const struct Ctx *p);
extern u8 func_0217C0A8(int a0);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *p);
extern int func_021A31A4(int i, int v);
extern void func_0219C658(u32 a, u32 b);
extern void func_0219D448(int a, int b);
extern u8 *func_0218ED50(u8 *p);
extern void func_0216CDB8(u8 *p, u32 v);
extern void func_0216D2F8(u32 a);
extern int func_02189AE8(int a);
extern void func_0216D974(unsigned int *p, unsigned int v);

void func_02189204(u8 *a)
{
    u32 h;
    u32 x;
    u32 r;
    u32 t;

    h = (u32)func_020120F4((const struct Ctx *)(((struct Obj00571 *)a)->f4));
    r = func_02012964((const struct BigObj *)h);
    ((struct Obj00571 *)a)->f38 = r;
    func_0216CCDC((char *)r, ((struct Obj00571 *)a)->f0, h, (int)a, *(u32 *)&((struct Obj00571 *)a)->f48, ((struct Obj00571 *)a)->f3C);
    func_0219C554(((struct Obj00571 *)a)->f38, ((struct Obj00571 *)a)->fB0, 0x20);
    func_0219C680(((struct Obj00571 *)a)->f38);
    x = ((struct Obj00571 *)a)->fD8;
    if (func_02013CC8(x) == 0 && func_02013CE0(x) == 0) {
        t = func_0217C0A8((int)((void *)func_02012138((const struct Ctx *)((struct Obj00571 *)a)->f4)));
    } else {
        t = func_02008550((const struct Sub0200852CObj *)func_02012944((void *)h));
    }
    func_0219C658(r, func_021A31A4(t, 0));
    func_0219D448(((struct Obj00571 *)a)->f38, ((struct Obj00571 *)a)->f130);
    func_0216CDB8((u8 *)(((struct Obj00571 *)a)->f38), (u32)func_0218ED50((u8 *)(((struct Obj00571 *)a)->f10)));
    func_0216D2F8(((struct Obj00571 *)a)->f38);
    func_0216D974((unsigned int *)r, func_02189AE8(((struct Obj00571 *)a)->fD0));
}
