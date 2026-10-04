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
    func_0203115C((struct Tcbl *)(*(u32 *)(p+244))); func_02031140((struct S02031140 *)(*(u32 *)(p+244)));
    func_0201C6EC((struct PrintSys *)(*(u32 *)(p+236))); func_0201C4C0((struct PrintSys *)(*(u32 *)(p+236)));
    func_021DD570(p); func_021DD3B0(func_021DD760(p));
    func_02045C04((struct Rec *)(*(u32 *)(p+64))); func_0201ED04((struct WordSet *)(*(u32 *)(p+60))); func_0201D83C((void *)(*(u32 *)(p+56)));
    *(volatile u16 *)0x04000304 |= 0x8000;
    func_02030EAC((struct Node *)(*(u32 *)(p+48)));
    *(u32 *)(*(u8 **)(p+12)+16)=*(u32 *)(p+8);
    *(u32 *)(*(u8 **)(p+12)+8)=func_021DE354(p);
    *(u32 *)(*(u8 **)(p+12)+12)=func_021DE37C(p);
    func_021DD380(p); func_020315D4(a); func_020306F0(114);
    return 1;
}
