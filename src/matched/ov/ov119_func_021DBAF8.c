/*
 * function: func_021DBAF8
 * address: 0x021DBAF8
 * packet: pkt_ov119_021DBAF8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6558 0x021B6558 thumb ov067
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   func_021D8980 0x021D8980 thumb ov119
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021E4420 0x021E4420 thumb ov119
 *   func_021E6700 0x021E6700 thumb ov119
 *   func_021D8B38 0x021D8B38 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 */
#include "../include/Obj00001.h"
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern int func_021D8980(char *p);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021E4420(char *p);
extern void func_021E6700(void *);
extern void func_021D8B38(char *p);
extern void func_021D8E84(void *,int);
extern void func_021DBE70(char *p);
void func_021DBAF8(char *p)
{
    func_021B6558((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),8,0);
    func_021B6558((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),7,1);
    TOUCHBAR_SetButtonEnabled((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),7,1);
    func_021B6558((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),9,0);
    func_021D8980(p);
    func_0204B3DC((struct Obj *)*(int *)&((struct Obj00001 *)p)->fF04,1);
    func_021E4420(p);
    func_021E6700(p);
    ((struct Obj00001 *)p)->fF84=-1;
    ((struct Obj00001 *)p)->fF88=-1;
    func_021D8B38(p);
    func_021D8E84(p,(int)func_021DBE70);
}
