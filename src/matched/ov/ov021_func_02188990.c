/*
 * function: func_02188990
 * address:  0x02188990
 * packet:   pkt_ov021_02188990
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CF480  0x021CF480  thumb  ov021
 *   func_021C1C04  0x021C1C04  thumb  ov021
 *   func_021C1AD0  0x021C1AD0  thumb  ov021
 *   func_0201209C  0x0201209C  thumb
 *   func_021A2EB8  0x021A2EB8  thumb  ov021
 *   func_021BB90C  0x021BB90C  thumb  ov021
 *   func_02012138  0x02012138  thumb
 *   func_020263B0  0x020263B0  thumb
 *   func_021BC424  0x021BC424  thumb  ov021
 *   func_021BE218  0x021BE218  thumb  ov021
 *   func_021BE2E0  0x021BE2E0  thumb  ov021
 *   func_021A9F28  0x021A9F28  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_021A0D44  0x021A0D44  thumb  ov021
 *   func_020129B8  0x020129B8  thumb
 *   func_021ABDE8  0x021ABDE8  thumb  ov021
 *   func_0217F8EC  0x0217F8EC  thumb  ov019
 *   func_021A1AAC  0x021A1AAC  thumb  ov021
 *   func_021A0448  0x021A0448  thumb  ov021
 *   func_021A02F4  0x021A02F4  thumb  ov021
 *   func_021A0138  0x021A0138  thumb  ov021
 *   func_021D33E0  0x021D33E0  thumb  ov021
 *   func_021BB240  0x021BB240  thumb  ov021
 *   func_021AB81C  0x021AB81C  thumb  ov021
 *   func_021AB624  0x021AB624  thumb  ov021
 *   func_0218E0E4  0x0218E0E4  thumb  ov021
 *   func_021895DC  0x021895DC  thumb  ov021
 *   func_021892B4  0x021892B4  thumb  ov021
 *   func_021A2E90  0x021A2E90  thumb  ov021
 *   func_0218D05C  0x0218D05C  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_021902BC  0x021902BC  thumb  ov021
 *   func_020129DC  0x020129DC  thumb
 *   func_02035660  0x02035660  arm
 *   func_021C31FC  0x021C31FC  thumb  ov021
 *   func_021C7F9C  0x021C7F9C  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00401.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BigObj;
struct Obj;
extern int func_021CF480(u32 a);
extern void func_021C1C04(u32 *p);
extern void func_021C1AD0(u32 a);
extern void func_0201209C(void *o, u32 v1, u32 v2);
extern void func_021A2EB8(u32 *a);
extern void func_021BB90C(u32 a);
struct Ctx;
extern u32 func_02012138(const struct Ctx *a);
extern void func_020263B0(struct Obj *p, u32 a);
extern void func_021BC424(u32 a);
extern void func_021BE218(void *arg);
extern void func_021BE2E0(u32 a);
extern void func_021A9F28(u32 a);
extern void *func_020120F4(const struct Ctx *p);
extern u8 func_021A0D44(u32 *p);
extern void func_020129B8(struct BigObj *p, u32 v);
extern void func_021ABDE8(u32 a);
extern void func_0217F8EC(char *p);
extern void func_021A1AAC(u8 *p);
extern void func_021A0448(u8 *p);
extern int func_021A02F4(u32 a);
extern void func_021A0138(u32 a);
extern void func_021D33E0(u32 *p);
extern int func_021BB240(u32 a);
extern void func_021AB81C(u32 a);
extern void func_021AB624(u8 *p);
extern void func_0218E0E4(u8 *a);
extern int func_021895DC(u32 a);
extern void func_021892B4(u8 *p);
extern void func_021A2E90(u32 a);
extern void func_0218D05C(char *p);
extern int func_02190728(u32 a);
extern void func_021902BC(struct Obj *o);
extern void func_020129DC(struct BigObj *p, u8 v);
extern void func_02035660(u32 a);
extern void func_021C31FC(u32 a);
extern void func_021C7F9C(u8 *p);

int func_02188990(void *a, u8 *p)
{
    func_021CF480(((struct Obj00401 *)p)->f13C);
    func_021C1C04((u32 *)(((struct Obj00401 *)p)->f124));
    func_021C1AD0(((struct Obj00401 *)p)->f120);
    func_0201209C(a, 0, 0);
    func_021A2EB8((u32 *)(((struct Obj00401 *)p)->f8C));
    func_021BB90C(((struct Obj00401 *)p)->fBC);
    func_020263B0((void *)func_02012138(a), (u32)p);
    if (((struct Obj00401 *)p)->f30 != 0)
        func_021BC424(((struct Obj00401 *)p)->f30);
    func_021BE218(p);
    func_021BE2E0(((struct Obj00401 *)p)->f34);
    func_021A9F28(((struct Obj00401 *)p)->f90);
    func_020129B8(func_020120F4(a), func_021A0D44((u32 *)(((struct Obj00401 *)p)->f24)));
    func_021ABDE8(((struct Obj00401 *)p)->f94);
    if (((struct Obj00401 *)p)->f98 != 0) {
        func_0217F8EC((char *)(((struct Obj00401 *)p)->f98));
        ((struct Obj00401 *)p)->f98 = 0;
    }
    func_021A1AAC((u8 *)(((struct Obj00401 *)p)->f20));
    ((struct Obj00401 *)p)->f20 = 0;
    func_021A0448((u8 *)(((struct Obj00401 *)p)->f14));
    func_021A02F4(((struct Obj00401 *)p)->f1C);
    func_021A0138(((struct Obj00401 *)p)->f18);
    func_021D33E0((u32 *)(((struct Obj00401 *)p)->f9C));
    func_021BB240(((struct Obj00401 *)p)->f3C);
    func_021AB81C(((struct Obj00401 *)p)->f44);
    func_021AB624((u8 *)(((struct Obj00401 *)p)->f40));
    func_0218E0E4((u8 *)(((struct Obj00401 *)p)->f10));
    (*(void (**)(u8 *))(*(u8 **)(p + 0x108) + 0xC))(p);
    func_021895DC((u32)p);
    func_021892B4(p);
    func_021A2E90(((struct Obj00401 *)p)->f8C);
    func_0218D05C((char *)(((struct Obj00401 *)p)->f48));
    if (((struct Obj00401 *)p)->f2C != 0)
        func_02190728(((struct Obj00401 *)p)->f2C);
    if (((struct Obj00401 *)p)->f28 != 0)
        func_021902BC((struct Obj *)(((struct Obj00401 *)p)->f28));
    func_020129DC(func_020120F4(a), 0);
    func_02035660(0x3C);
    func_021C31FC(((struct Obj00401 *)p)->f128);
    func_021C7F9C((u8 *)(((struct Obj00401 *)p)->fA0));
    return 1;
}
