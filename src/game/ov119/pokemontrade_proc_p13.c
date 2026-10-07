/*
 * file:     pokemontrade_proc_p13.c
 * unit:     yes
 * function: func_021DBA38, func_021DBA80, func_021DBAF8
 * address:  0x021DBA38
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D94A0 0x021D94A0 thumb ov119
 *   func_021D8E80 0x021D8E80 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021D8C84 0x021D8C84 thumb ov119
 *   func_021DF7AC 0x021DF7AC thumb ov119
 *   func_02027858 0x02027858 thumb
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021B6548 0x021B6548 thumb ov067
 *   func_021D8980 0x021D8980 thumb ov119
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021E4420 0x021E4420 thumb ov119
 *   func_021E6700 0x021E6700 thumb ov119
 *   func_021D8B38 0x021D8B38 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 */
#include "../../matched/include/Obj00001.h"

struct Entry;
struct TaskMenu;
struct Obj;
typedef unsigned short u16;

typedef unsigned int   u32;

extern int func_021D8A24(void *);
extern void func_021D94A0(void *,int);
extern void func_021D8E80(void *);
extern void func_021D8E84(void *,int);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_02082BCC(void *,int,int);
extern void func_021D8C84(void *);
extern void func_021DF7AC(void *,int);
extern void func_02027858(struct TaskMenu *m);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern int func_021B6548(unsigned char *p, unsigned int id, int v);
extern int func_021D8980(char *p);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021E4420(char *p);
extern void func_021E6700(void *);
extern void func_021D8B38(char *p);
extern void func_021DBE70(char *p);
void func_021DBA38(void *p);
void func_021DBA80(char *p);
void func_021DBAF8(char *p);

void func_021DBA38(void *p)
{
    if (func_021D8A24(p)==0) {
        func_021D94A0(p,1);
        func_021D8E80(p);
        func_021D8E84(p,(int)func_021DBAF8);
        return;
    }
    if (func_0203D3A8(func_020399A8(),0xc06,0,0)!=0)
        func_021D8E84(p,(int)func_021DBAF8);
}

void func_021DBA80(char *p)
{
    ((struct Obj00001 *)p)->f1088=0;
    ((struct Obj00001 *)p)->f1078=0;
    ((struct Obj00001 *)p)->f107A=0;
    func_02082BCC(p+0xca0,0,0x78);
    func_02082BCC(p+0xd18,0,0x3c);
    func_02082BCC(p+0xd54,0,0x3c);
    func_021D8C84(p);
    func_021DF7AC(p,1);
    if(*(int *)&((struct Obj00001 *)p)->f64C) {
        func_02027858((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C));
        *(int *)&((struct Obj00001 *)p)->f64C=0;
    }
    func_021D94A0(p,0);
    func_021D8E84(p,(int)func_021DBA38);
}

void func_021DBAF8(char *p)
{
    func_021B6558((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),8,0);
    func_021B6558((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),7,1);
    func_021B6548((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),7,1);
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
