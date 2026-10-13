/*
 * function: func_02200FF4
 * address: 0x02200FF4
 * packet: pkt_ov135_02200FF4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02019CE0 0x02019CE0 thumb
 *   func_02025C1C 0x02025C1C thumb
 *   func_02025C30 0x02025C30 thumb
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   NHTTP_RAP_Create 0x021B9800 thumb ov114
 *   NHTTP_RAP_AllocPostData 0x021B98A0 thumb ov114
 *   NHTTP_RAP_AppendPostData 0x021B98D8 thumb ov114
 *   NHTTP_RAP_CreatePostRequest 0x021B98F8 thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   func_02034714 0x02034714 arm
 *   str_02203F58 0x02203F58 data a1
 */
#include "../include/Obj01411.h"
#include "../include/Obj23442.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct RecDC;
extern void func_02019CE0(const struct RecDC *, struct RecDC *);
extern u32 func_02025C1C(u32, u32, u32);
extern u32 func_02025C30(u32, u32, u32);
struct Sub0200852CObj;
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern u8 *NHTTP_RAP_Create(int, int, int);
extern void NHTTP_RAP_AllocPostData(u8 *, int, int, int);
extern void NHTTP_RAP_AppendPostData(u8 *, int, int);
extern int NHTTP_RAP_CreatePostRequest(u8 *);
extern int NHTTP_RAP_StartConnection(u8 *);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char str_02203F58[];
int func_02200FF4(u8 *p)
{
    u8 *mon=p+0xE4;
    int ready;
    func_02019CE0((const struct RecDC *)mon, *(struct RecDC * *)&((struct Obj01411 *)p)->fEA8);
    p[0x204]=func_02025C1C(p[0x204],p[0x205],p[0x209]);
    p[0x205]=func_02025C30(p[0x204],p[0x205],p[0x209]);
    *(u8 * *)&((struct Obj01411 *)p)->f10E0=NHTTP_RAP_Create(0x48,func_0200853C(((struct Obj23442 *)(*(u8 * *)&((struct Obj01411 *)p)->f0))->f1C),(int)(p+0x116C));
    NHTTP_RAP_AllocPostData(*(u8 * *)&((struct Obj01411 *)p)->f10E0,0x48,POKE_TOOL_GetPartyParamSize(),1);
    NHTTP_RAP_AppendPostData(*(u8 * *)&((struct Obj01411 *)p)->f10E0,(int)mon,POKE_TOOL_GetPartyParamSize());
    if(NHTTP_RAP_CreatePostRequest(*(u8 * *)&((struct Obj01411 *)p)->f10E0)==0) func_02034714(str_02203F58,0,str_02203F58);
    ready=NHTTP_RAP_StartConnection(*(u8 **)(p+0x10E0))==0;
    if(ready==0) func_02034714(str_02203F58,0,str_02203F58);
    ((struct Obj01411 *)p)->f28=3;
    return 2;
}
