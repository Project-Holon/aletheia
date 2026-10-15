/*
 * function: MUS_COMM_FUNC_ReceiveBoxData
 * address: 0x021FD2B8
 * packet: pkt_ov132_021FD2B8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: loop leaf filed as ov132_func_021FD328.c.
 * symbols:
 *   POKE_TOOL_GetBoxParamSize 0x020173E8 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   MYSTATUS_GetSize  0x02008468  thumb  arm9
 */
#include "../include/Obj08175.h"
#include "../include/Obj14128.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 POKE_TOOL_GetBoxParamSize(void);
typedef unsigned short u16;
extern int MYSTATUS_GetSize(void);
extern int func_020084BC(const u16 *values);
extern void MI_CpuCopy8(void *,void *,u32);
void MUS_COMM_FUNC_ReceiveBoxData(int a,int b,int c,char *p)
{
    u8 i;
    int n;
    u32 m,k;
    char *q,*s;
    int flag;
    for(i=0;i<4;i++) {
        m=MYSTATUS_GetSize();
        n=POKE_TOOL_GetBoxParamSize();
        q=*(char * *)&((struct Obj14128 *)p)->f13C;
        k=i*(m+4+n);
        m=MYSTATUS_GetSize();
        n=m+4+POKE_TOOL_GetBoxParamSize();
        s=p+i*0x30;
        MI_CpuCopy8(q+k,((struct Obj08175 *)s)->f8C,n);
        flag=func_020084BC(((struct Obj08175 *)s)->f84)==0 ? 1 : 0;
        ((struct Obj08175 *)s)->f60=flag;
        ((struct Obj08175 *)s)->f68=flag;
    }
    ((struct Obj14128 *)p)->f158=1;
}
