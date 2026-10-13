/*
 * function: func_021BFDD0
 * address: 0x021BFDD0
 * packet: pkt_ov099_021BFDD0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   GFL_NET_HANDLE_GetNegotiationNum 0x020399EC arm
 *   DWC_RAP_StopVchat 0x021563D0 thumb ov009
 *   func_021C24A4 0x021C24A4 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   func_02039C68 0x02039C68 arm
 */
#include "../include/Obj07958.h"
struct Entry;
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern unsigned func_02039CB4(struct Link *,unsigned,unsigned);
extern int GFL_NET_HANDLE_GetNegotiationNum(void);
extern void DWC_RAP_StopVchat(void);
extern void func_021C24A4(char *,int);
extern void func_021BA8EC(char *);
extern void func_021C18C8(char *p, int kind, int value);
typedef unsigned char  u8;
extern void GFL_NET_SetAutoExit(u8 a0);
extern void GFL_NET_SetLoginOption(u8 a0);
extern void func_02039C68(struct Link *,unsigned,unsigned);
int func_021BFDD0(char *p,int ret) {
    ((struct Obj07958 *)p)->f1355=0;
    if(func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),18,10) || GFL_NET_HANDLE_GetNegotiationNum()!=2) {
        if((unsigned)(((struct Obj07958 *)p)->f135C-3)<=1){
            DWC_RAP_StopVchat();
            func_021C24A4(p,127);
            func_021BA8EC(p);
            func_021C18C8(p,3,3);
            ((struct Obj07958 *)p)->f1CC=154;
        } else {
            func_021C18C8(p,1,2);
            GFL_NET_SetAutoExit(0); GFL_NET_SetLoginOption(0);
            func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),21,10);
            ((struct Obj07958 *)p)->f1CC=159;
        }
    }
    return ret;
}
