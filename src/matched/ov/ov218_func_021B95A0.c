/*
 * function: func_021B95A0
 * address: 0x021B95A0
 * packet: pkt_ov218_021B95A0
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9E48 0x021B9E48 thumb ov218
 *   func_021B7A64 0x021B7A64 thumb ov067
 */
#include "../include/Obj26039.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct S S;
extern char *func_021B9E48(void *,char *);
extern int func_021B7A64(struct S *p);
int func_021B95A0(void *owner,int *state,char *input,u8 *p)
{
    switch(*state){
    case 0:func_021B9E48(owner,input);++*state;break;
    case 1:if(func_021B7A64(*(S * *)&((struct Obj26039 *)p)->f2C)==0)return 1;break;
    }
    return 0;
}
