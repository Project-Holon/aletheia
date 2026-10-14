/*
 * function: GURU2_MAIN_SendAngles
 * address: 0x021DF2E0
 * packet: pkt_ov137_021DF2E0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_IsAngleInRangeList 0x021E1830 thumb ov137
 *   GURU2_COMM_Send 0x021DCBC4 thumb ov137
 */
#include "../include/Obj02497.h"
#include "../include/Obj14225.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0x60]; u16 angles[5]; } Obj;
extern int GURU2_MAIN_IsAngleInRangeList(char *p, int angle, int index);
extern int GURU2_COMM_Send(void *, int, void *, int);
int GURU2_MAIN_SendAngles(Obj *obj)
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
        if (GURU2_MAIN_IsAngleInRangeList((char *)p, angle << 12, ((struct Obj02497 *)p)->f30) == 1)
            ((struct Obj02497 *)p)->f1C |= 1 << ((struct Obj14225 *)q)->fC;
        }
    }
    buf.mask = ((struct Obj02497 *)p)->f1C;
    if (GURU2_COMM_Send(((struct Obj02497 *)p)->fDC, 10252, &buf, 16) == 1) ((struct Obj02497 *)p)->f0 = 35;
    return 0;
}
