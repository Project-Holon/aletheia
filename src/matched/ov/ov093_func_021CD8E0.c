/*
 * function: BTL_CLIENT_Delete
 * address: 0x021CD8E0
 * packet: pkt_ov093_021CD8E0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_REC_DeleteBuffer 0x021EE600 thumb ov093
 *   func_02188080 0x02188080 thumb ov096
 *   func_020307B0 0x020307B0 arm
 *   BTL_ADAPTER_Delete 0x021EEAE0 thumb ov093
 */
#include "../include/Obj05197.h"
typedef unsigned char u8;
extern void BTL_REC_DeleteBuffer(void *);
extern void func_02188080(void *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void BTL_ADAPTER_Delete(void *);
void BTL_CLIENT_Delete(u8 *p) {
 if(*(void* *)&((struct Obj05197 *)p)->f10)BTL_REC_DeleteBuffer(*(void* *)&((struct Obj05197 *)p)->f10);
 if(*(void* *)&((struct Obj05197 *)p)->fF0)func_02188080(*(void* *)&((struct Obj05197 *)p)->fF0);
 func_020307B0(*(void* *)&((struct Obj05197 *)p)->f134);
 BTL_ADAPTER_Delete(*(void* *)&((struct Obj05197 *)p)->f50);
 func_020307B0(p);
}
