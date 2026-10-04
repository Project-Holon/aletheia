/*
 * function: func_021B9A94
 * address: 0x021B9A94
 * packet: pkt_ov205_021B9A94
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012F2C 0x02012F2C thumb
 *   func_02012FCC 0x02012FCC thumb
 *   func_0200864C 0x0200864C thumb
 *   func_02008650 0x02008650 thumb
 *   func_02008654 0x02008654 thumb
 *   func_02008D1C 0x02008D1C thumb
 */
#include "../include/Obj14631.h"
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct PlayTime;
struct Sub02008C20Obj;
extern void *func_02012F2C(int *p);
extern int func_02012FCC(int p0);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern u8 func_02008654(const struct PlayTime *p);
extern u32 func_02008D1C(struct Sub02008C20Obj *obj, int i, u32 value);
void func_021B9A94(char *p)
{
    void *counter,*date;
    unsigned year,month,day;
    counter=func_02012F2C(((struct Obj14631 *)p)->f4);
    date=(void *)func_02012FCC((int)(((struct Obj14631 *)p)->f4));
    year=func_0200864C(date);
    month=func_02008650(date);
    day=func_02008654(date);
    func_02008D1C(counter,2,day+(year*10000+month*100));
}
