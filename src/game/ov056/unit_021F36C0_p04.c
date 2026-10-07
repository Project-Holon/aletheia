/*
 * file:     unit_021F36C0_p04.c
 * unit:     yes
 * function: func_021F3A14, func_021F3A78
 * address:  0x021F3A14
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_0218EC5C  0x0218EC5C  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0218ECD4  0x0218ECD4  thumb  ov021
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0218F1AC  0x0218F1AC  thumb  ov021
 *   func_0218ED14  0x0218ED14  thumb  ov021
 *   func_0218E17C  0x0218E17C  thumb  ov021
 *   func_0218F05C  0x0218F05C  thumb  ov021
 *   func_02048AC4  0x02048AC4  arm
 *   func_02011558  0x02011558  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02011608  0x02011608  thumb
 *   func_020115EC  0x020115EC  thumb
 *   func_021F3AB0  0x021F3AB0  thumb  ov056
 */
#include "../../matched/include/Obj01680.h"

struct IcaAnime;
struct Obj11244;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

extern int func_0218EC60(u32 a);
extern u32 func_0218EC5C(u8 *p);
extern void func_0218EC90(u32 a, u32 b);
extern void func_0218ECD4(u32 a, u32 b);
extern void func_0218E13C(u8 *a, u32 s);
extern void func_0218F1AC(u8 *p, u32 v);
extern void func_0218ED14(u8 *p, u32 q);
extern void func_0218E17C(u32 *p, u32 v);
extern void func_0218F05C(u8 *a);
extern u32 func_02048AC4(void *ptr);
extern void func_02011558(struct IcaAnime *p);
extern void func_02082BCC(void *, unsigned, unsigned);
extern u32 func_02011608(struct Obj11244 *p);
extern void func_020115EC(struct IcaAnime *p, s32 v);
extern void func_021F3AB0(u32 *p);
void func_021F3A14(u8 *p);
int func_021F3A78(u8 *p);


void func_021F3A14(u8 *p)
{
    func_0218EC60(*(u32 *)&((struct Obj01680 *)p)->f8);
    func_0218EC90(*(u32 *)&((struct Obj01680 *)p)->f8, func_0218EC5C(*(u8 * *)&((struct Obj01680 *)p)->f8));
    func_0218ECD4(*(u32 *)&((struct Obj01680 *)p)->f8, (u32)(p + 0x10));
    func_0218E13C((u8 *)(*(u32 *)&((struct Obj01680 *)p)->f8), ((struct Obj01680 *)p)->fC);
    func_0218F1AC(*(u8 * *)&((struct Obj01680 *)p)->f8, ((struct Obj01680 *)p)->fE);
    func_0218ED14((u8 *)(*(u32 *)&((struct Obj01680 *)p)->f8), (u32)(p + 0x1c));
    func_0218E17C(*(u32 * *)&((struct Obj01680 *)p)->f8, ((struct Obj01680 *)p)->f2C);
    func_0218F05C(*(u8 * *)&((struct Obj01680 *)p)->f8);
    func_02048AC4((void *)(((struct Obj01680 *)p)->f4));
    func_02011558((struct IcaAnime *)(((struct Obj01680 *)p)->f0));
    func_02082BCC(p, 0, 0x30);
}


/*
 * note:     twin of the head of func_021F40A0 (same clock read and clamp),
 *           with the frame counter at +0x28. EXACT* = 54 bytes of code plus
 *           2 bytes of alignment padding before matched func_021F3AB0.
 */
int func_021F3A78(u8 *p)
{
    int flag;
    s32 x = func_02011608((struct Obj11244 *)(*(struct IcaAnime **)(p + 0x0))) << 12;
    s32 y = *(s32 *)(p + 0x28) + 0x1000;

    if (x <= y) {
        flag = 1;
        *(s32 *)(p + 0x28) = x - 0x1000;
    } else {
        flag = 0;
        *(s32 *)(p + 0x28) = y;
    }
    func_020115EC(*(struct IcaAnime **)(p + 0x0), *(s32 *)(p + 0x28));
    func_021F3AB0((u32 *)p);
    return flag;
}
