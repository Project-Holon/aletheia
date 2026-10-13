/*
 * function: func_021DDB90
 * address: 0x021DDB90
 * packet: pkt_ov119_021DDB90
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DDB64 0x021DDB64 thumb ov119
 */
#include "../include/Obj00001.h"

typedef unsigned int u32;

typedef unsigned char  u8;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int func_021E12AC(char *p);
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern int TOUCHPANEL_GetTrg(void);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *);
extern void func_021E1030(char *p);
extern void func_021D8E84(void *,int);
extern void func_021DDB64(unsigned char *p);

void func_021DDB90(unsigned char *p)
{
    int v;GFL_NET_HANDLE_GetCurrentHandle();if(func_021E12AC((char *)p)){v=func_020362DC();if(v)func_020355D8(0);if(v==0){v=TOUCHPANEL_GetTrg();if(v)func_020355D8(1);if(v==0)return;}MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),0x88,(void *)(*(int *)&((struct Obj00001 *)p)->f738));func_021E1024(p);func_021E1030((char *)p);func_021D8E84(p,(int)func_021DDB64);}
}
