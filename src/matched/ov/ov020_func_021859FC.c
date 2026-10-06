/*
 * function: func_021859FC
 * address: 0x021859FC
 * packet: pkt_ov020_021859FC
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02186470 0x02186470 thumb ov020
 *   func_02013DD0 0x02013DD0 thumb
 *   func_02185928 0x02185928 thumb ov020
 *   func_02012B38 0x02012B38 thumb
 *   func_0201444C 0x0201444C thumb
 *   func_020127C4 0x020127C4 thumb
 *   func_021864DC 0x021864DC thumb ov020
 */
#include "../include/Obj19456.h"
typedef unsigned short u16;
extern void func_02186470(int a0);
extern int func_02013DD0(int id);
extern void func_02185928(int a, const short *p);
typedef unsigned int   u32;
struct BigObj;
struct Sub02014444Obj;
extern void *func_02012B38(const struct BigObj *p);
extern u32 func_0201444C(struct Sub02014444Obj *o);
extern void *func_020127C4(void *p);
typedef unsigned char  u8;
extern void func_021864DC(u8 *p);
void func_021859FC(void *p, const short *s)
{
    func_02186470((int)p);
    if (func_02013DD0(*(const u16 *)&((struct Obj19456 *)s)->f4) != 0) {
        func_02185928((int)p, s);
        if (func_0201444C(func_02012B38(p)) == 0) {
            func_021864DC(func_020127C4(p));
        }
    }
}
