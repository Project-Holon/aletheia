/*
 * function: func_021B6294
 * address: 0x021B6294
 * packet: pkt_ov133_021B6294
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020355D8 0x020355D8 arm
 *   func_0200A6F8 0x0200A6F8 thumb
 *   func_02005D28 0x02005D28 thumb
 *   func_021B9BD0 0x021B9BD0 thumb ov133
 *   func_021B9F24 0x021B9F24 thumb ov133
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_021B7498 0x021B7498 thumb ov133
 *   func_021F5330 0x021F5330 thumb ov112
 *   func_021F51B0 0x021F51B0 thumb ov112
 *   func_02030EAC 0x02030EAC arm
 *   func_0204ED24 0x0204ED24 arm
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Big;struct Obj;struct Descriptor;struct Bank;struct Node;
extern void func_020355D8(u8);
extern void func_0200A6F8(struct Big *);
extern void func_02005D28(void);
extern void func_021B9BD0(char *);
extern void func_021B9F24(char *);
extern void func_0204B3B4(struct Obj *);
extern void func_0204ADA4(u32);
extern void func_0204A8D4(u32);
extern void func_0204AFD8(u32);
extern void func_020452E8(struct Descriptor *);
extern void func_0204B1CC(struct Bank *);
extern void func_0204A5AC(void);
extern void func_021B7498(char *);
extern void func_021F5330(int,int);
extern void func_021F51B0(int a);
extern void func_02030EAC(struct Node *);
extern void func_0204ED24(void *);
extern void func_02048AC4(void *);
extern void func_02046788(void);
extern void func_020403F4(u32);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020307B0(void *);
void func_021B6294(char *p)
{
    u8 i;
    func_020355D8(1);
    func_0200A6F8(*(struct Big **)(*(char **)(p+4)+8));
    func_02005D28();
    func_021B9BD0(p);
    func_021B9F24(p);
    func_0204B3B4(*(struct Obj **)(p+0x184c));
    func_0204B3B4(*(struct Obj **)(p+0x1850));
    func_0204B3B4(*(struct Obj **)(p+0x1854));
    for(i=0;i<=2;i++) func_0204ADA4(*(u32 *)(p+0x1858+i*4));
    for(i=3;i<=5;i++) func_0204A8D4(*(u32 *)(p+0x1858+i*4));
    for(i=6;i<=8;i++) func_0204AFD8(*(u32 *)(p+0x1858+i*4));
    if(*(struct Descriptor **)(p+0x18ec)) func_020452E8(*(struct Descriptor **)(p+0x18ec));
    func_0204B1CC(*(struct Bank **)(p+0x1848));
    func_0204A5AC();
    func_021B7498(p);
    func_021F5330(*(int *)(p+0x187c),*(int *)(p+0x1880));
    func_021F51B0(*(u32 *)(p+0x187c));
    func_02030EAC(*(struct Node **)(p+8));
    func_0204ED24(*(void **)(p+0x188c));
    func_02048AC4(*(void **)(p+0x1888));
    func_02046788();
    func_020403F4(0);func_020403F4(1);func_020403F4(2);func_020403F4(3);
    func_020403F4(4);func_020403F4(6);func_020403F4(5);func_020403F4(7);
    func_020450C8();
    func_0203F9B4();
    func_020307B0(p);
}
