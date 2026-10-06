/*
 * function: func_021DF2E0
 * address: 0x021DF2E0
 * packet: pkt_ov137_021DF2E0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E1830 0x021E1830 thumb ov137
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 */
#include "../include/Obj02497.h"
#include "../include/Obj14225.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0x60]; u16 angles[5]; } Obj;
extern int func_021E1830(char *p, int angle, int index);
extern int func_021DCBC4(void *, int, void *, int);
int func_021DF2E0(Obj *obj)
{
    u8 *p = (u8 *)obj;
    struct { u16 angle, mask, entries[6]; } buf;
    int i;
    u8 *q;
    buf.angle = ((struct Obj02497 *)p)->f58 / 4096;
    ((struct Obj02497 *)p)->f1C = 0;
    for (i = 0; i < ((struct Obj02497 *)p)->f30; i++) {
        q = p + 0x2e0 + i * 180;
        {
        int angle;
        angle = obj->angles[i];
        buf.entries[((struct Obj14225 *)q)->f10] = angle;
        if (func_021E1830((char *)p, angle << 12, ((struct Obj02497 *)p)->f30) == 1)
            ((struct Obj02497 *)p)->f1C |= 1 << ((struct Obj14225 *)q)->fC;
        }
    }
    buf.mask = ((struct Obj02497 *)p)->f1C;
    if (func_021DCBC4(((struct Obj02497 *)p)->fDC, 10252, &buf, 16) == 1) ((struct Obj02497 *)p)->f0 = 35;
    return 0;
}
