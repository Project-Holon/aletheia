/*
 * function: func_021D7038
 * address: 0x021D7038
 * packet: pkt_ov116_021D7038
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   NHTTP_RAP_FreePostData 0x021B99B8 thumb ov114
 *   NHTTP_RAP_Destroy 0x021B9838 thumb ov114
 */
#include "../include/Obj08046.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void DWC_RAP_SetErrorCallback(int, int);
extern void NHTTP_RAP_FreePostData(u8 *);
extern void NHTTP_RAP_Destroy(u8 *);
void func_021D7038(u8 *p)
{
    if (*(u8 * *)&((struct Obj08046 *)p)->f168) {
        DWC_RAP_SetErrorCallback(0, 0);
        NHTTP_RAP_FreePostData(*(u8 * *)&((struct Obj08046 *)p)->f168);
        NHTTP_RAP_Destroy(*(u8 * *)&((struct Obj08046 *)p)->f168);
        *(u8 * *)&((struct Obj08046 *)p)->f168 = 0;
    }
}
