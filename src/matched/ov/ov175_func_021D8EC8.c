/*
 * function: WIFIBATTLEMATCH_NET_CompStepK
 * address: 0x021D8EC8
 * packet: pkt_ov175_021D8EC8
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E8738 0x021E8738 thumb ov177
 *   func_021E8AB4 0x021E8AB4 thumb ov177
 *   GAME_DATA_SaveStart 0x02012DAC thumb
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   WIFIBATTLEMATCH_NET_SetupGdbUpload 0x021DBC04 thumb ov175
 *   WIFIBATTLEMATCH_NET_GdbUpdateRecord 0x021DBDAC thumb ov175
 *   WIFIBATTLEMATCH_NET_HandleNetError 0x021D9F04 thumb ov175
 *   func_021E8AA0 0x021E8AA0 thumb ov177
 *   func_021E8844 0x021E8844 thumb ov177
 *   func_021E8AB8 0x021E8AB8 thumb ov177
 *   WIFIBATTLEMATCH_NET_CompExit 0x021D905C thumb ov175
 */
#include "../include/Obj02886.h"
#include "../include/Obj10683.h"
#include "../include/Obj24281.h"
typedef unsigned long u32;
extern void func_021E8738(int *p, int a, int b, int c);
extern void func_021E8AB4(u32,u32);
extern int GAME_DATA_SaveStart(int a0);
typedef unsigned char  u8;
struct Record;
extern int GAME_DATA_SaveMain(u8 *p);
extern void WIFIBATTLEMATCH_NET_SetupGdbUpload(u8 *p, u32 mode, struct Record *src);
extern int WIFIBATTLEMATCH_NET_GdbUpdateRecord(char *p);
extern int WIFIBATTLEMATCH_NET_HandleNetError(char *,void *,void *);
extern void func_021E8AA0(int *p, int v);
extern void func_021E8AB8(u32);
extern void WIFIBATTLEMATCH_NET_CompExit(u32 sys);
extern int func_021E8844(const int *p);
void WIFIBATTLEMATCH_NET_CompStepK(u32 sys,int *state,char *p)
{
    char *q=*(char * *)&((struct Obj02886 *)p)->f104;
    switch(*state) {
    case 0:func_021E8738((int *)(((struct Obj02886 *)p)->f2C),((struct Obj02886 *)p)->f14,40,2);
        func_021E8AB4(sys,1);*state=7;break;
    case 1:GAME_DATA_SaveStart((int)(**(void ** *)&((struct Obj10683 *)q)->f8));*state=2;break;
    case 2:if(GAME_DATA_SaveMain(**(void ** *)&((struct Obj10683 *)q)->f8)==2) *state=3;break;
    case 3:func_021E8738((int *)(((struct Obj02886 *)p)->f2C),((struct Obj02886 *)p)->f14,37,2);
        func_021E8AB4(sys,4);*state=7;break;
    case 4:if(**(u32 * *)&((struct Obj10683 *)q)->f20==0) {WIFIBATTLEMATCH_NET_SetupGdbUpload(((struct Obj02886 *)p)->f34,2,0);*state=5;}break;
    case 5:if(WIFIBATTLEMATCH_NET_GdbUpdateRecord(((struct Obj02886 *)p)->f34)) {
        **(u32 * *)&((struct Obj24281 *)(*(char * *)&((struct Obj02886 *)p)->f104))->f20=1800;*state=6;
        WIFIBATTLEMATCH_NET_HandleNetError(*(char * *)&((struct Obj02886 *)p)->f34,(void *)1,0);
    }break;
    case 6:func_021E8AA0((int *)sys,(int)WIFIBATTLEMATCH_NET_CompExit);break;
    case 7:if(func_021E8844((const int *)(((struct Obj02886 *)p)->f2C))) func_021E8AB8(sys);break;
    }
}
