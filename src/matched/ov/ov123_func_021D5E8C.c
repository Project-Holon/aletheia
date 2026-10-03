/*
 * function: func_021D5E8C
 * address: 0x021D5E8C
 * packet: pkt_ov123_021D5E8C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D63E4 0x021D63E4 thumb ov123
 *   func_020307B0 0x020307B0 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_02040588 0x02040588 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov_id 0x00000043 data
 */
typedef unsigned char u8;
typedef enum { C0 = 0 } Counter;
extern unsigned char ov_id[];
extern void func_021D63E4(u8 *);
extern void func_020307B0(void *);
typedef unsigned int   u32;
struct Bank;
struct Node;
struct Obj;
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(void *);
extern void func_0204A8D4(void *);
extern void func_0204AFD8(void *);
extern void func_02030EAC(struct Node *n);
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(u32 i);
extern void func_02040588(unsigned int,unsigned int);
extern void func_0203F9B4(void);
extern void func_02034A5C(int);
void func_021D5E8C(u8 *p)
{
    Counter i;
    func_021D63E4(p);
    func_020307B0(*(void **)(p+0x1c));
    func_0204B3B4(*(void **)(p+0xb4));
    func_0204B3B4(*(void **)(p+0xb8));
    i=0;
    do { if(*(void **)(p+i*4+0x20)) func_0204ADA4(*(void **)(p+i*4+0x20)); i++; } while(i<6);
    for(;i<13;i++) if(*(void **)(p+i*4+0x20)) func_0204A8D4(*(void **)(p+i*4+0x20));
    for(;i<20;i++) if(*(void **)(p+i*4+0x20)) func_0204AFD8(*(void **)(p+i*4+0x20));
    if(*(void **)(p+0x14)) func_02030EAC(*(void **)(p+0x14));
    func_02030EAC(*(void **)(p+0x10));
    func_0204B1CC(*(void **)(p+0xc));
    func_0204A5AC();
    func_02040DA8(1,1,0); func_02040DA8(6,1,0);
    func_020403F4(5); func_020403F4(4);
    func_02040588(5,0); func_0203F9B4(); func_020307B0(p);
    func_02034A5C((int)ov_id);
}
