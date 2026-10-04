/*
 * function: func_021B72A8
 * address: 0x021B72A8
 * packet: pkt_ov101_021B72A8
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_02028148 0x02028148 thumb
 * func_02045B38 0x02045B38 arm
 * func_02082BCC 0x02082BCC arm
 * func_02045EC0 0x02045EC0 arm
 * func_02027FEC 0x02027FEC thumb
 * func_02045808 0x02045808 arm
 * func_02045C04 0x02045C04 arm
 */
#include "../include/Obj03228.h"
typedef unsigned short u16;
typedef struct { unsigned data; u16 tag,pad; unsigned flag; } Desc;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct MsgBank;
struct Rec;
struct U16Vec;
extern void func_02028148(u8 *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02082BCC(void *,int,unsigned);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern unsigned func_02027FEC(unsigned,Desc *,unsigned,unsigned,unsigned,unsigned);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045C04(struct Rec *rec);
void func_021B72A8(unsigned *p,unsigned b) {
 unsigned q;
 Desc t;
 if(b==p[21]) return;
 func_02028148((u8 *)p[0]);
 q=(unsigned int)func_02045B38(0,2,0x31,((struct Obj03228 *)p)->f58);
 func_02082BCC(&t,0,12);
 t.tag=0x39e3;
 t.data=(unsigned int)func_02045EC0((struct MsgBank *)q,b+8);
 t.flag=1;
 p[0]=func_02027FEC(p[1],&t,0x13,0x15,0xd,((struct Obj03228 *)p)->f58);
 func_02045808((struct U16Vec *)t.data);
 func_02045C04((struct Rec *)q);
 p[21]=b; p[20]=0; p[17]=-1;
}
