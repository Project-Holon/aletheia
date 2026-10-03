/*
 * function: func_021E0DE8
 * address: 0x021E0DE8
 * packet: pkt_ov137_021E0DE8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021E0DC0 0x021E0DC0 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx; struct Node;
extern void func_02082BCC(void *,int,u32);
extern struct Node *func_02030DA8(struct Ctx *,u32,u32,u32);
extern void func_021E0DC0(void *,char *);
void func_021E0DE8(char *p) { func_02082BCC(p+2808,0,160); *(struct Node **)(p+3452)=func_02030DA8(*(struct Ctx **)(p+0xd98),(u32)func_021E0DC0,(u32)p,256); }
