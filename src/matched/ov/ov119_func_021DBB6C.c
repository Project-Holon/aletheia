/*
 * function: func_021DBB6C
 * address: 0x021DBB6C
 * packet: pkt_ov119_021DBB6C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021DD2F4 0x021DD2F4 thumb ov119
 *   func_021B6558 0x021B6558 thumb ov067
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   func_021D8980 0x021D8980 thumb ov119
 *   func_021D8B38 0x021D8B38 thumb ov119
 */
#include "../include/Obj00001.h"
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern int func_021DD2F4(char *p);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern int func_021D8980(char *p);
extern void func_021D8B38(char *p);
void func_021DBB6C(char *p)
{
    func_0204B3DC((struct Obj *)*(int *)&((struct Obj00001 *)p)->fF04,1);
    func_021B6558((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),8,func_021DD2F4(p));
    TOUCHBAR_SetButtonEnabled((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),8,func_021DD2F4(p));
    func_021B6558((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),7,1);
    TOUCHBAR_SetButtonEnabled((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),7,1);
    func_021B6558((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),9,0);
    func_021D8980(p);
    func_021D8B38(p);
}
