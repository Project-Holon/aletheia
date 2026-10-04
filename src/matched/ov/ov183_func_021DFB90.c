/*
 * function: func_021DFB90
 * address: 0x021DFB90
 * packet: pkt_ov183_021DFB90
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   func_021FD170 0x021FD170 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   d_021E3734 0x021E3734 data a2
 *   d_021E3740 0x021E3740 data a4
 */
#include "../include/Obj05477.h"
#include "../include/Obj05478.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Request { u16 x,y,id; u8 flag,pad; };
struct Rec6 { u8 x,y,id,pad; u16 file; };
struct Rec8 { u8 a,b,c,d; void *value; };
struct Triple { int a,b,c; };
extern const struct Rec6 d_021E3734[];
extern const struct Rec8 d_021E3740[];
extern int func_021FC20C(char *),func_021FC214(char *);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern int func_021FC124(int,int,struct Triple *);
extern void *func_021FB378(void *,int,int,int,int,int,int,int,void *,u16);
extern void *func_021FC6A4(u16,unsigned,u16,u16,u8,u8,void *,u16);
extern void func_021FC754(char *,void *,void *,void *,u16);
extern void func_021FD170(char *p, char *q, void *text);
extern void func_02082BCC(void *,int,int);
int func_021DFB90(char *p,char *q)
{
    int first,second,i;
    struct Request req;
    struct Triple triple;
    const struct Rec6 *r;
    const struct Rec8 *s;
    first=func_021FC20C(*(char * *)&((struct Obj05478 *)q)->f8);
    second=func_021FC214(*(char * *)&((struct Obj05478 *)q)->f8);
    func_021FB964((void *)(*(int *)&((struct Obj05478 *)q)->f8),26,((struct Obj05477 *)p)->f54);
    func_02082BCC(&req,0,8);
    func_021FC124(*(int *)&((struct Obj05478 *)q)->f8,6,&triple);
    for(i=0;i<2;i++) {
        r=&d_021E3734[i];
        req.x=r->x; req.y=r->y; req.id=r->id; req.flag=1;
        *(void **)(p+0xc+i*4)=func_021FB378(&req,r->file,0x60,1,((struct Obj05478 *)q)->f4,((struct Obj05477 *)p)->f44,first,second,&triple,((struct Obj05477 *)p)->f54);
    }
    for(i=0;i<3;i++) {
        s=&d_021E3740[i];
        *(void **)(p+i*4)=func_021FC6A4(4,s->a,s->b,s->c,s->d,14,((struct Obj05477 *)p)->f48,((struct Obj05477 *)p)->f54);
        func_021FC754(*(char **)(p+i*4),(void *)second,s->value,(void *)first,0x3da0);
    }
    func_021FD170(((struct Obj05477 *)p)->f38,(char *)(*(int *)&((struct Obj05478 *)q)->f8),(void *)107);
    return 1;
}
