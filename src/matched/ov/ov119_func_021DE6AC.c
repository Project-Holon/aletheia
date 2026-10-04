/*
 * function: func_021DE6AC
 * address: 0x021DE6AC
 * packet: pkt_ov119_021DE6AC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_020173EC 0x020173EC thumb
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DE66C 0x021DE66C thumb ov119
 */
#include "../include/Obj10361.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u8 pad[0x11fb]; u8 state:4; u8 other:4; } Flags;
extern int func_021D8A24(void *);
struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned int   u32;
extern u32 func_020173EC(void);
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
extern void func_021D8E84(void *,int);
extern void func_021DE66C(char *p);
void func_021DE6AC(char *p)
{
    unsigned id;
    if(((Flags *)p)->state==1) return;
    if(func_021D8A24(p)!=0) {
        id=(unsigned)func_020399A8();
        if(!func_0203D3A8((void *)id,0xc01,func_020173EC(),(u32)(((struct Obj10361 *)p)->f106C))) return;
    }
    p[0x11fb]=((u8)p[0x11fb]&~15)|1;
    func_021D8E84(p,(int)func_021DE66C);
}
