/*
 * function: func_021F3A14
 * address:  0x021F3A14
 * packet:   pkt_ov056_021F3A14
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
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
 */
#include "../include/Obj01680.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0218EC60(u32 a);
extern u32 func_0218EC5C(u8 *p);
extern void func_0218EC90(u32 a, u32 b);
extern void func_0218ECD4(u32 a, u32 b);
struct IcaAnime;
extern void func_0218E13C(u8 *a, u32 s);
extern void func_0218F1AC(u8 *p, u32 v);
extern void func_0218ED14(u8 *p, u32 q);
extern void func_0218E17C(u32 *p, u32 v);
extern void func_0218F05C(u8 *a);
extern void func_02048AC4(void *ptr);
extern void func_02011558(struct IcaAnime *p);
extern void func_02082BCC(void *, unsigned, unsigned);

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
