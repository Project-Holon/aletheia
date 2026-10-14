/*
 * function: MB_SEQ_CollectMails
 * address: 0x021C5B40
 * packet: pkt_ov136_021C5B40
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02009050 0x02009050 thumb
 *   func_02008EF8 0x02008EF8 thumb
 */
#include "../include/Obj04534.h"
#include "../include/Obj08202.h"
#include "../include/Obj23526.h"
#include "../include/Obj23527.h"
#include "../include/Obj23528.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Sub02008F80Obj;
extern struct Sub02008F80Obj *func_02009050(struct Sub02008F80Obj *arr, u32 unused, int i, u32 heap);
extern int func_02008EF8(const struct Sub02008F80Obj *obj);
void MB_SEQ_CollectMails(u8 *p)
{
    unsigned i;
    u8 *q;
    ((struct Obj23526 *)(*(u8 * *)&((struct Obj04534 *)p)->f8))->f2FC=0;
    for(i=0;i<20;i++) {
        (*(u8 **)(p+8))[0x2e8+i]=255;
        *(void **)(*(u8 * *)&((struct Obj04534 *)p)->f8+0x298+i*4)=func_02009050(((struct Obj04534 *)p)->f0,0,i,102);
        if(func_02008EF8(*(void **)(*(u8 * *)&((struct Obj04534 *)p)->f8+0x298+i*4))==1) {
            (*(u8 **)(p+8))[0x2e8+((struct Obj23527 *)(*(u8 * *)&((struct Obj04534 *)p)->f8))->f2FC]=i;
            ++((struct Obj23528 *)(*(u8 * *)&((struct Obj04534 *)p)->f8))->f2FC;
        }
    }
    q=*(u8 * *)&((struct Obj04534 *)p)->f8;
    if(((struct Obj08202 *)q)->f2FC==0) ((struct Obj08202 *)q)->f2FE=0;
    else ((struct Obj08202 *)q)->f2FE=(((struct Obj08202 *)q)->f2FC-1)/10;
}
