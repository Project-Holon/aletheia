/*
 * function: func_021DF5D8
 * address: 0x021DF5D8
 * packet: pkt_ov119_021DF5D8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DF59C 0x021DF59C thumb ov119
 *   func_021E26AC 0x021E26AC thumb ov119
 */
#include "../include/Obj10366.h"
typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern void func_021D8E84(void *, int);
extern void func_021DF59C(void *);
extern void func_021E26AC(void *);
void func_021DF5D8(char *p)
{
    MSGDATA_ReadString(((struct Obj10366 *)p)->f720, 0x87, ((struct Obj10366 *)p)->f738);
    func_021E1024(p);
    TOUCHBAR_SetButtonEnabled(((struct Obj10366 *)p)->f9C0, 1, 0);
    func_021D8E84(p, (int)func_021DF59C);
    func_021E26AC(p);
}
