/*
 * function: func_021F4D14
 * address: 0x021F4D14
 * packet: pkt_ov135_021F4D14
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_021F5060 0x021F5060 thumb ov135
 */
#include "../include/Obj00045.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02027974(void *);
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *);
extern void func_021F5060(void);
int func_021F4D14(char *p) { int result; result=0; if(((struct Obj00045 *)p)->fE08) { func_02027974(((struct Obj00045 *)p)->fE08); if(func_020279E8(((struct Obj00045 *)p)->fE08)) { result=func_02027A04(((struct Obj00045 *)p)->fE08); if(result==0) result=1; else if(result==1) result=2; func_021F5060(); } } return result; }
