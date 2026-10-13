/*
 * function: func_021B6B70
 * address: 0x021B6B70
 * packet: pkt_ov071_021B6B70
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6C4 0x0201C6C4 thumb
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 */
#include "../include/Obj07693.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct PrintSys;
struct Obj;
extern u32 func_0201C6C4(struct PrintSys *, void *);
extern void BMP_OAM_UploadChars(struct Obj *);
int func_021B6B70(void **p, u8 *q)
{
    if (q[12] == 1) {
        if (func_0201C6C4(p[2], ((struct Obj07693 *)q)->f8) == 0) {
            BMP_OAM_UploadChars(*(struct Obj * *)&((struct Obj07693 *)q)->f4);
            q[12] = 0;
            return 1;
        }
    }
    return 0;
}
