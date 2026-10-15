/*
 * function: UN_SELECT_SceneCreate
 * address: 0x021B95A0
 * packet: pkt_ov218_021B95A0
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   UN_SELECT_CreateSceneWork 0x021B9E48 thumb ov218
 *   FRAME_LIST_UpdateInit 0x021B7A64 thumb ov067
 */
#include "../include/Obj26039.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct S S;
extern char *UN_SELECT_CreateSceneWork(void *,char *);
extern int FRAME_LIST_UpdateInit(struct S *p);
int UN_SELECT_SceneCreate(void *owner,int *state,char *input,u8 *p)
{
    switch(*state){
    case 0:UN_SELECT_CreateSceneWork(owner,input);++*state;break;
    case 1:if(FRAME_LIST_UpdateInit(*(S * *)&((struct Obj26039 *)p)->f2C)==0)return 1;break;
    }
    return 0;
}
