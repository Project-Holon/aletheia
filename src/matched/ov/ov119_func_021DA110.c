/*
 * function: func_021DA110
 * address: 0x021DA110
 * packet: pkt_ov119_021DA110
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_021E0FF4 0x021E0FF4 thumb ov119
 *   func_021E4E64 0x021E4E64 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DA064 0x021DA064 thumb ov119
 */
#include "../include/Obj00001.h"

typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E0FF4(void *,int,int);
extern void func_021E4E64(int a, char *p, int b);
extern void func_021D8E84(void *,int);
extern void func_021DA064(char *p);
void func_021DA110(char *p)
{
    MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720), 0x8E, (void *)(*(int *)&((struct Obj00001 *)p)->f738));
    func_021E0FF4(p,1,0);
    ((struct Obj00001 *)p)->f1080 = -1;
    func_021E4E64(*(int *)&((struct Obj00001 *)p)->f828, p, 0);
    func_021D8E84(p, (int)func_021DA064);
}
