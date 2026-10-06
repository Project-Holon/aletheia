/*
 * function: func_0217C0A8
 * address:  0x0217C0A8
 * packet:   pkt_ov018_0217C0A8
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02012B80  0x02012B80  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02012950  0x02012950  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 */
#include "../include/Obj19353.h"

typedef unsigned char u8;
typedef unsigned short u16;

extern int func_02026478();
struct BigObj;
extern int func_02012B70(const struct BigObj *p);
extern u8 func_02012B80(const struct BigObj *p);
extern u8 func_02012B58(const struct BigObj *p);
extern int func_02026454();
extern u8 *func_02026474();
typedef unsigned int   u32;
extern u32 func_02013D5C(u32 id);
extern u8 *func_02012950();
extern u8 *func_02012944(void *p);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);

u8 func_0217C0A8(int a0)
{
    int h;
    u8 *q;
    u8 *obj;

    h = func_02026478(a0);
    if (func_02012B70((const struct BigObj *)h) == 0) {
        obj = func_02012944((void *)h);
    } else if (func_02012B80((const struct BigObj *)h) == func_02012B58((const struct BigObj *)h)) {
        obj = func_02012944((void *)h);
    } else {
        q = 0;
        if (func_02026454(a0) == 2 && func_02026474(a0) != 0)
            q = func_02026474(a0);
        if (q == 0) {
            obj = func_02012944((void *)h);
        } else if (func_02013D5C(((struct Obj19353 *)q)->f84) == 1) {
            obj = func_02012944((void *)h);
        } else {
            obj = func_02012950(h, func_02012B80((const struct BigObj *)h));
        }
    }
    return func_02008550((const struct Sub0200852CObj *)obj);
}
