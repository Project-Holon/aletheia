/*
 * function: func_021D73D8
 * address: 0x021D73D8
 * packet: pkt_ov123_021D73D8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   NHTTP_RAP_CreateRequest 0x021B95D4 thumb ov114
 *   NHTTP_RAP_GetConnection 0x021B973C thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   NHTTP_AddPostDataRaw 0x021BE79C arm ov114
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D7390 0x021D7390 thumb ov123
 */
#include "../include/Obj04500.h"
extern int GFL_NET_GetRunState(void);
typedef unsigned char  u8;
extern int NHTTP_RAP_CreateRequest(int index, u8 *p);
extern int NHTTP_RAP_GetConnection(char *p);
extern int NHTTP_RAP_StartConnection(u8 *p);
extern int NHTTP_AddPostDataRaw(void *handle, void *value_p, unsigned long length);
typedef unsigned int   u32;
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D7390(char *);
void func_021D73D8(char *p)
{
    if (((struct Obj04500 *)p)->f78) {
        --((struct Obj04500 *)p)->f78;
        return;
    }
    if (GFL_NET_GetRunState()) {
        if (NHTTP_RAP_CreateRequest(8,((struct Obj04500 *)p)->f10)) {
            p[2]=1;
            p[3]=0;
            NHTTP_AddPostDataRaw((void *)NHTTP_RAP_GetConnection(((struct Obj04500 *)p)->f10),(void *)((unsigned int)(p+2)),4);
            if (NHTTP_RAP_StartConnection(((struct Obj04500 *)p)->f10)==0)
                func_021D6EE0((u8 *)p,(int)func_021D7390,0x2cd);
        }
    }
}
