/*
 * function: func_021DD0B8
 * address: 0x021DD0B8
 * packet: pkt_ov137_021DD0B8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021DD10A reads and 021DD110 writes hardware register 0x04000304
 * symbols:
 * func_0203115C 0x0203115C arm
 * func_02031140 0x02031140 arm
 * func_021DD570 0x021DD570 thumb ov137
 * func_021DD760 0x021DD760 thumb ov137
 * func_021DD3B0 0x021DD3B0 thumb ov137
 * func_02045C04 0x02045C04 arm
 * func_02030EAC 0x02030EAC arm
 * func_021DE354 0x021DE354 thumb ov137
 * func_021DE37C 0x021DE37C thumb ov137
 * func_021DD380 0x021DD380 thumb ov137
 * func_020315D4 0x020315D4 arm
 * func_020306F0 0x020306F0 arm
 */
#include "../include/Obj02207.h"
#include "../include/Obj23709.h"
#include "../include/Obj23710.h"
#include "../include/Obj23711.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
struct Node;
struct PrintSys;
struct Rec;
struct S02031140;
struct Tcbl;
struct WordSet;
extern void func_0203115C(struct Tcbl *p);
extern void func_02031140(struct S02031140 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_021DD570(u8 *p);
extern u32 func_021DD760(void *);
extern void func_021DD3B0(u32);
extern void func_02045C04(struct Rec *rec);
extern void func_0201ED04(struct WordSet *p);
extern void func_0201D83C(void *ptr);
extern void func_02030EAC(struct Node *n);
extern u32 func_021DE354(void *),func_021DE37C(void *);
extern void func_021DD380(void *),func_020315D4(void *),func_020306F0(unsigned int);
int func_021DD0B8(void *a,int b,void *c,u8 *p)
{
    func_0203115C((struct Tcbl *)(((struct Obj02207 *)p)->fF4)); func_02031140((struct S02031140 *)(((struct Obj02207 *)p)->fF4));
    func_0201C6EC((struct PrintSys *)(((struct Obj02207 *)p)->fEC)); func_0201C4C0((struct PrintSys *)(((struct Obj02207 *)p)->fEC));
    func_021DD570(p); func_021DD3B0(func_021DD760(p));
    func_02045C04((struct Rec *)(((struct Obj02207 *)p)->f40)); func_0201ED04((struct WordSet *)(((struct Obj02207 *)p)->f3C)); func_0201D83C((void *)(((struct Obj02207 *)p)->f38));
    *(volatile u16 *)0x04000304 |= 0x8000;
    func_02030EAC((struct Node *)(((struct Obj02207 *)p)->f30));
    ((struct Obj23709 *)(*(u8 * *)&((struct Obj02207 *)p)->fC))->f10=((struct Obj02207 *)p)->f8;
    ((struct Obj23710 *)(*(u8 * *)&((struct Obj02207 *)p)->fC))->f8=func_021DE354(p);
    ((struct Obj23711 *)(*(u8 * *)&((struct Obj02207 *)p)->fC))->fC=func_021DE37C(p);
    func_021DD380(p); func_020315D4(a); func_020306F0(114);
    return 1;
}
