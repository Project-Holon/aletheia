/*
 * function: func_021E0A64
 * address: 0x021E0A64
 * packet: pkt_ov119_021E0A64
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Repeat callback calls, then goto the shared teardown; callback local shifts the join by two bytes.
 * symbols:
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   GAME_DATA_GetSeason 0x02012984 thumb
 *   SHINKA_CHECK_CheckEvolution 0x0201B2B0 thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9434 0x021D9434 thumb ov119
 *   func_021DFD64 0x021DFD64 thumb ov119
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_021E0BA4 0x021E0BA4 thumb ov119
 *   func_021E0C78 0x021E0C78 thumb ov119
 *   func_021DFD3C 0x021DFD3C thumb ov119
 */
#include "../include/Obj00906.h"
#include "../include/Obj22766.h"
#include "../include/Obj22767.h"
#include "../include/Obj22768.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D8AA8(void *);
extern void *func_021D8FA4(void *,int);
struct BigObj;
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern u32 SHINKA_CHECK_CheckEvolution(void *party, void *mon, u32 context, u32 param, u8 timezone, u32 *methodOut, u16 heap);
struct MsgBank;
extern void func_021D8E84(void *,int);
extern void func_021D9434(void *);
extern void func_021DFD64(void *);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *);
extern void func_021E1030(char *p);
extern void func_021E0BA4(void *);
extern void func_021E0C78(char *p);
extern void func_021DFD3C(void *);
void func_021E0A64(char *p)
{
    void *a,*b;
    u32 out,result;
    if(*(int *)&((struct Obj00906 *)p)->f82C==0) {
        func_021D8E84(p,(int)func_021E0C78);
        goto exit;
    }
    else {
    if(*(int *)&((struct Obj00906 *)p)->f8!=0) {
        if(func_021D8AA8(p)) {a=func_021D8FA4(p,0);b=func_021D8FA4(p,1);}
        else {a=func_021D8FA4(p,1);b=func_021D8FA4(p,0);}
        result=SHINKA_CHECK_CheckEvolution(0,a,1,(u32)b,GAME_DATA_GetSeason(((struct Obj00906 *)p)->f82C),&out,((struct Obj00906 *)p)->f5F4);
        if(result) {
            ((struct Obj22766 *)(*(char * *)&((struct Obj00906 *)p)->f8))->f8=1;
            ((struct Obj22767 *)(*(char * *)&((struct Obj00906 *)p)->f8))->fC=result;
            ((struct Obj22768 *)(*(char * *)&((struct Obj00906 *)p)->f8))->f10=out;
            func_021D8E84(p,(int)func_021D9434);
            func_021DFD64(p);
            return;
        }
    }
    MSGDATA_ReadString((struct MsgBank *)(((struct Obj00906 *)p)->f720),50,(void *)(((struct Obj00906 *)p)->f738));
    func_021E1024(p);func_021E1030(p);
    func_021D8E84(p,(int)func_021E0BA4);
    }
exit:
    func_021DFD3C(p);
}
