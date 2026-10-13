/*
 * function: func_021DF404
 * address: 0x021DF404
 * packet: pkt_ov119_021DF404
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DF37C 0x021DF37C thumb ov119
 */
#include "../include/Obj10364.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E1024(void *);
extern void func_021E1030(char *p);
extern void func_021D8E84(void *, int);
extern void func_021DF37C(u8 *p);
void func_021DF404(char *p)
{
    MSGDATA_ReadString(((struct Obj10364 *)p)->f720, 0x88, ((struct Obj10364 *)p)->f738);
    func_021E1024(p);
    func_021E1030(p);
    ((struct Obj10364 *)p)->f11F1 = 0x78;
    func_021D8E84(p, (int)func_021DF37C);
}
