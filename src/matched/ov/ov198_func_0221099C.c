/*
 * function: func_0221099C
 * address: 0x0221099C
 * packet: pkt_ov198_0221099C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * remainder: two-byte alignment padding at 02210A4A.
 * symbols:
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_022107A8 0x022107A8 thumb ov198
 */
#include "../include/Obj04603.h"
#include "../include/Obj25259.h"
#include "../include/Obj25260.h"
#include "../include/Obj25261.h"
#include "../include/Obj25262.h"
#include "../include/Obj25263.h"
#include "../include/Obj25264.h"
#include "../include/Obj25265.h"
typedef unsigned char u8;
extern unsigned func_0201AA18(void *);
extern void *func_0201AB28(void *,unsigned);
struct Summary;
extern void func_022107A8(void *unused, void *mon, struct Summary *p);
void func_0221099C(u8 *p)
{
    unsigned i;
    if (((struct Obj25259 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f18==0) {
        for (i=0;i<6;i++) {
            if (i<func_0201AA18(((struct Obj25260 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f4))
                func_022107A8(p,func_0201AB28(((struct Obj25261 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f4,i),(struct Summary *)(p+4+i*76));
            else func_022107A8(p,0,(struct Summary *)(p+4+i*76));
        }
    } else {
        for (i=0;i<3;i++) {
            if (i<func_0201AA18(((struct Obj25262 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f4))
                func_022107A8(p,func_0201AB28(((struct Obj25263 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f4,i),(struct Summary *)(p+4+i*76));
            else func_022107A8(p,0,(struct Summary *)(p+4+i*76));
            if (i<func_0201AA18(((struct Obj25264 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f8))
                func_022107A8(p,func_0201AB28(((struct Obj25265 *)(*(u8 * *)&((struct Obj04603 *)p)->f0))->f8,i),(struct Summary *)(p+4+(i+3)*76));
            else func_022107A8(p,0,(struct Summary *)(p+4+(i+3)*76));
        }
    }
}
