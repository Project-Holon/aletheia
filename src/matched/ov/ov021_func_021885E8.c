/*
 * function: func_021885E8
 * address:  0x021885E8
 * packet:   pkt_ov021_021885E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218CA78  0x0218CA78  thumb  ov021
 *   func_0216CD64  0x0216CD64  thumb  ov010
 *   func_0219C624  0x0219C624  thumb  ov021
 *   func_0219C630  0x0219C630  thumb  ov021
 *   func_021A1B50  0x021A1B50  thumb  ov021
 *   func_021A1AF4  0x021A1AF4  thumb  ov021
 *   func_02189004  0x02189004  thumb  ov021
 *   func_02189084  0x02189084  thumb  ov021
 *   func_021890AC  0x021890AC  thumb  ov021
 *   func_0204A600  0x0204A600  arm
 *   func_021903E0  0x021903E0  thumb  ov021
 *   func_021ABE04  0x021ABE04  thumb  ov021
 *   func_021BB948  0x021BB948  thumb  ov021
 *   func_02012B38  0x02012B38  thumb
 *   func_02014460  0x02014460  thumb
 *   func_02189B04  0x02189B04  thumb  ov021
 *   func_02005C64  0x02005C64  thumb
 *   func_02014458  0x02014458  thumb
 *   func_02158AC8  0x02158AC8  thumb  ov010
 *   func_02014454  0x02014454  thumb
 *   func_02158AD4  0x02158AD4  thumb  ov010
 *   func_0201445C  0x0201445C  thumb
 *   func_02013CC8  0x02013CC8  thumb
 *   func_02013CE0  0x02013CE0  thumb
 *   func_02188CF0  0x02188CF0  thumb  ov021
 *   func_0201209C  0x0201209C  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020129DC  0x020129DC  thumb
 *   func_0218A0E4  0x0218A0E4  thumb  ov021
 *   func_0218A240  0x0218A240  thumb  ov021
 *   func_0218A4BC  0x0218A4BC  thumb  ov021
 *   func_0218A074  0x0218A074  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00611.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct BigObj;
struct Obj;
extern void func_0218CA78(char *p);
extern int func_0216CD64(int a0);
extern int func_0219C624(void *p);
extern int func_0219C630(void *p);
extern int func_021A1B50(u32 a);
extern void func_021A1AF4(u8 *p, int x);
extern void func_02189004(u8 *p);
extern void func_02189084(u8 *p);
extern void func_021890AC(u8 *p);
extern void func_0204A600(void);
extern void func_021903E0(struct Obj *o);
extern void func_021ABE04(u32 a);
extern void func_021BB948(u8 *p);
extern void *func_02012B38(const struct BigObj *p);
extern u8 func_02014460(void *o);
extern int func_02189B04(int x);
extern int func_02005C64(void);
extern u8 func_02014458(void *o);
extern void func_02158AC8(int a, int b);
extern void func_02014454(void *o, u8 v);
extern void func_02158AD4(int a, int b);
extern void func_0201445C(void *o, u8 v);
extern u32 func_02013CC8(u32 id);
extern u32 func_02013CE0(u32 id);
extern int func_02188CF0(u32 a);
extern void func_0201209C(void *o, u32 v1, u32 v2);
extern void *func_020120F4(void *o);
extern void func_020129DC(struct BigObj *p, u8 v);
extern int func_0218A0E4(void *sys, u8 *pos);
extern int func_0218A240(void *p, unsigned char *pos);
extern int func_0218A4BC(u32 a, u32 b, u32 c, u32 d);
extern int func_0218A074(void *a, int b);

int func_021885E8(void *a, u8 *p)
{
    switch (p[0xC8]) {
    case 0:
        func_0218CA78((char *)(((struct Obj00611 *)p)->f48));
        if (((struct Obj00611 *)p)->f38 != 0) {
            do {
                func_0216CD64(((struct Obj00611 *)p)->f38);
                func_0219C624((void *)(((struct Obj00611 *)p)->f38));
            } while (func_0219C630((void *)(((struct Obj00611 *)p)->f38)) == 1);
        }
        while (func_021A1B50(((struct Obj00611 *)p)->f20) != 0)
            func_021A1AF4((u8 *)(((struct Obj00611 *)p)->f20), 0x92);
        func_02189004(p);
        func_02189084(p);
        func_021890AC(p);
        func_0204A600();
        if (((struct Obj00611 *)p)->f28 != 0)
            func_021903E0((struct Obj *)(((struct Obj00611 *)p)->f28));
        func_021ABE04(((struct Obj00611 *)p)->f94);
        func_021BB948((u8 *)(((struct Obj00611 *)p)->fBC));
        p[0xC8]++;
    case 1:
        if (func_02014460(func_02012B38((const struct BigObj *)(((struct Obj00611 *)p)->f8))) == 1
            && func_02189B04(((struct Obj00611 *)p)->fD0) == 1
            && func_02005C64() != 0)
            return 0;
        if (func_02014458(func_02012B38((const struct BigObj *)(((struct Obj00611 *)p)->f8))) != 0) {
            func_02158AC8(((struct Obj00611 *)p)->f4, ((struct Obj00611 *)p)->f0);
            func_02014454(func_02012B38((const struct BigObj *)(((struct Obj00611 *)p)->f8)), 0);
        } else {
            func_02158AD4(((struct Obj00611 *)p)->f4, ((struct Obj00611 *)p)->f0);
        }
        func_0201445C(func_02012B38((const struct BigObj *)(((struct Obj00611 *)p)->f8)), 0);
        func_0218CA78((char *)(((struct Obj00611 *)p)->f48));
        if (func_02013CC8(((struct Obj00611 *)p)->fD0) == 1 || func_02013CE0(((struct Obj00611 *)p)->fD0) == 1)
            func_0201209C(a, (u32)func_0218A0E4, (u32)p);
        else if (func_02188CF0((u32)p) == 1)
            func_0201209C(a, (u32)func_0218A240, (u32)p);
        else if (func_02188CF0((u32)p) == 2)
            func_0201209C(a, (u32)func_0218A4BC, (u32)p);
        else
            func_0201209C(a, (u32)func_0218A074, (u32)p);
        ((struct Obj00611 *)p)->fC0 = 1;
        func_020129DC(func_020120F4(a), 1);
        break;
    }
    return 1;
}
