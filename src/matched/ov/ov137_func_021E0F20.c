/*
 * function: func_021E0F20
 * address: 0x021E0F20
 * packet: pkt_ov137_021E0F20
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021E0EFC 0x021E0EFC thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx; struct Node;
extern void func_02082BCC(void *,int,u32);
extern struct Node *func_02030DA8(struct Ctx *,u32,u32,u32);
extern void func_021E0EFC(void *,char *);
void func_021E0F20(char *p) { func_02082BCC(p+2968,0,100); *(struct Node **)(p+3456)=func_02030DA8(*(struct Ctx **)(p+0xd98),(u32)func_021E0EFC,(u32)p,257); }
