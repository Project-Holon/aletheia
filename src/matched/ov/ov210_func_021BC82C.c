/*
 * function: func_021BC82C
 * address: 0x021BC82C
 * packet: pkt_ov210_021BC82C
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020056BC 0x020056BC thumb
 *   PALANM_RequestFade 0x0202173C thumb
 */
#include "../include/Obj01779.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct PalAnmObj;
typedef unsigned int   u32;
extern u32 func_020056BC(void);
extern int PALANM_RequestFade(struct PalAnmObj *,u16,u16,s16,u8,u8,u16,void *);
void func_021BC82C(char *p,u8 b,u8 c)
{
    PALANM_RequestFade(*(struct PalAnmObj * *)&((struct Obj01779 *)p)->fC,1,0xbfff,-14,b,c,0,(void *)func_020056BC());
    PALANM_RequestFade(*(struct PalAnmObj * *)&((struct Obj01779 *)p)->fC,2,0x7fef,-14,b,c,0,(void *)func_020056BC());
    PALANM_RequestFade(*(struct PalAnmObj * *)&((struct Obj01779 *)p)->fC,4,0xfe1f,-14,b,c,0,(void *)func_020056BC());
    PALANM_RequestFade(*(struct PalAnmObj * *)&((struct Obj01779 *)p)->fC,8,0xbfff,-14,b,c,0,(void *)func_020056BC());
}
