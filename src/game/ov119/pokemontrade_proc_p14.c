/*
 * file:     pokemontrade_proc_p14.c
 * unit:     yes
 * function: func_021DBB6C, func_021DBBD0, func_021DBC3C, func_021DBC98
 * address:  0x021DBB6C
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
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021DD2F4 0x021DD2F4 thumb ov119
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021B6548 0x021B6548 thumb ov067
 *   func_021D8980 0x021D8980 thumb ov119
 *   func_021D8B38 0x021D8B38 thumb ov119
 *   func_021DF7AC 0x021DF7AC thumb ov119
 *   func_02082BCC 0x02082BCC arm
 *   func_021D8C84 0x021D8C84 thumb ov119
 *   func_02027858 0x02027858 thumb
 *   func_021E4420 0x021E4420 thumb ov119
 *   func_021E6700 0x021E6700 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021DD5B4 0x021DD5B4 thumb ov119
 *   func_021DB0A0 0x021DB0A0 thumb ov119
 *   func_021DD3D4 0x021DD3D4 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 */
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj08057.h"

struct Obj;
typedef unsigned short u16;

extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern int func_021DD2F4(char *p);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern int func_021B6548(unsigned char *p, unsigned int id, int v);
extern int func_021D8980(char *p);
extern void func_021D8B38(char *p);
extern void func_021DF7AC(void *,int);
extern void func_02082BCC(void *,int,int);
extern void func_021D8C84(void *);
extern void func_02027858(int);
extern void func_021E4420(void *);
extern void func_021E6700(void *);
extern void func_021D8E84(void *,int);
extern void func_021DBE70(void);
extern int func_021D8AA8(void *);
extern int func_021DD5B4(char *p, int a, int b);
extern int func_021DB0A0(char *p);
extern int func_021DD3D4(void *,int,int,int);
extern void *func_020399A8(void);
extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);
void func_021DBB6C(char *p);
void func_021DBBD0(char *p);
void func_021DBC3C(char *p);
void func_021DBC98(char *p);

void func_021DBB6C(char *p)
{
    func_0204B3DC((struct Obj *)*(int *)&((struct Obj00001 *)p)->fF04,1);
    func_021B6558((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),8,func_021DD2F4(p));
    func_021B6548((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),8,func_021DD2F4(p));
    func_021B6558((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),7,1);
    func_021B6548((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),7,1);
    func_021B6558((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),9,0);
    func_021D8980(p);
    func_021D8B38(p);
}

void func_021DBBD0(char *p) { func_021DF7AC(p,1); func_02082BCC(p+0xca0,0,0x78); func_02082BCC(p+0xd18,0,0x3c); func_02082BCC(p+0xd54,0,0x3c); func_021D8C84(p); if(*(int *)&((struct Obj00001 *)p)->f64C) {func_02027858(*(int *)&((struct Obj00001 *)p)->f64C); *(int *)&((struct Obj00001 *)p)->f64C=0;} func_021E4420(p);func_021E6700(p);func_021DBB6C(p);func_021D8E84(p,(int)func_021DBE70);}

void func_021DBC3C(char *p) {
 if(func_021D8AA8(p)) { if(func_021DD5B4(p,((struct Obj00001 *)p)->fF84,((struct Obj00001 *)p)->fF88)==0) return; }
 else { if(func_021DB0A0(p)==0) return; }
 ((struct Obj00001 *)p)->fF98=-1; ((struct Obj00001 *)p)->fF94=-1;
 ((struct Obj00001 *)p)->fF7C=-1; ((struct Obj00001 *)p)->fF80=-1;
 func_021D8B38(p); func_021D8E84(p,(int)func_021DBE70);
}

void func_021DBC98(char *p) {int same=0;if(((struct Obj08057 *)p)->fF88==((struct Obj08057 *)p)->f630)same=1;if(func_021D8AA8(p)) {int n=func_021DD3D4(p,0,((struct Obj08057 *)p)->fF84,((struct Obj08057 *)p)->fF88);if(n!=-1) {if(func_0203D3A8(func_020399A8(),n+0xc13,1,&same)) {func_021D8E84(p,(int)func_021DBC3C);return;}} else {func_021D8E84(p,(int)func_021DBC3C);return;}} else {if(func_0203D3A8(func_020399A8(),0xc16,1,&same))func_021D8E84(p,(int)func_021DBC3C);}}
