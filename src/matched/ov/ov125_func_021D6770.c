/*
 * function: GDS_RAP_Exit
 * address: 0x021D6770
 * packet: pkt_ov125_021D6770
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NHTTP_RAP_FreePostData 0x021B99B8 thumb ov114
 *   NHTTP_RAP_Destroy 0x021B9838 thumb ov114
 *   GDS_SOCKET_Shutdown 0x021D85B4 arm ov125
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov114_id 0x00000072 data
 */
#include "../include/Obj03805.h"
typedef unsigned char  u8;
struct Rec;
struct U16Vec;
struct WordSet;
extern void NHTTP_RAP_FreePostData(u8 *p);
extern void NHTTP_RAP_Destroy(u8 *p);
extern void GDS_SOCKET_Shutdown(void);
extern void STRBUF_Delete(struct U16Vec *vec);
extern unsigned int func_0201ED04(struct WordSet *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void func_02034A5C(int);
extern char ov114_id[];
void GDS_RAP_Exit(char *p)
{
    if (((struct Obj03805 *)p)->f404) {
        NHTTP_RAP_FreePostData(((struct Obj03805 *)p)->f404);
        NHTTP_RAP_Destroy(((struct Obj03805 *)p)->f404);
    }
    GDS_SOCKET_Shutdown();
    ((struct Obj03805 *)p)->f3B4 = 0;
    STRBUF_Delete(((struct Obj03805 *)p)->f3EC);
    func_0201ED04(((struct Obj03805 *)p)->f3E8);
    MSGDATA_Delete(((struct Obj03805 *)p)->f3E4);
    func_020307B0(((struct Obj03805 *)p)->f3AC);
    func_02034A5C((int)ov114_id);
}
