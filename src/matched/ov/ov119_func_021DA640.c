/*
 * function: func_021DA640
 * address: 0x021DA640
 * packet: pkt_ov119_021DA640
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DF7AC 0x021DF7AC thumb ov119
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021E1410 0x021E1410 thumb ov119
 *   func_021D8D4C 0x021D8D4C thumb ov119
 *   func_021E1E00 0x021E1E00 thumb ov119
 *   func_020307B0 0x020307B0 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021D8C84 0x021D8C84 thumb ov119
 *   func_021D8B38 0x021D8B38 thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   func_02027A08 0x02027A08 thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DA318 0x021DA318 thumb ov119
 *   d_021E7594 0x021E7594 data a4
 */
#include "../include/Obj02826.h"

typedef struct { int a,b; } Pair;
extern const Pair d_021E7594;
extern void func_021DF7AC(void *,int);
typedef unsigned int   u32;
struct TaskMenu;
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern void func_021E1410(void *,Pair *,int);
extern void *func_021D8D4C(void **a, int b, int c, char *p);
extern void func_021E1E00(char *p, int mode, void *mon);
extern void func_020307B0(void *p);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021D8C84(void *);
typedef unsigned char  u8;
extern void func_021D8B38(char *p);
extern u8 func_020355C4(void);
extern u32 func_02027A08(struct TaskMenu *tm, u32 arg);
extern void func_021D8E84(void *,int);
extern void func_021DA318(char *p);
void func_021DA640(char *p) {
    Pair t;
    int n;
    int zero=0;
    func_021DF7AC(p,0);
    func_021B6558((unsigned char *)(((struct Obj02826 *)p)->f9C0),1,0);
    func_021B6558((unsigned char *)(((struct Obj02826 *)p)->f9C0),7,0);
    func_021B6558((unsigned char *)(((struct Obj02826 *)p)->f9C0),9,1);
    t=d_021E7594;
    func_021E1410(p,&t,2);
    n=(int)func_021D8D4C(*(void ** *)&((struct Obj02826 *)p)->f828,((struct Obj02826 *)p)->fF98,((struct Obj02826 *)p)->fF94,p);
    ((struct Obj02826 *)p)->f10A0=zero;
    func_021E1E00(p,0,(void *)n);
    func_020307B0((void *)n);
    func_0204B3DC((struct Obj *)((struct Obj02826 *)p)->fF04,0);
    func_021D8C84(p);
    func_021D8B38(p);
    if(func_020355C4()) func_02027A08((struct TaskMenu *)(((struct Obj02826 *)p)->f64C),zero);
    else func_02027A08((struct TaskMenu *)(((struct Obj02826 *)p)->f64C),1);
    func_021D8E84(p,(int)func_021DA318);
}
