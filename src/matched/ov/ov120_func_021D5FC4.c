/*
 * function: func_021D5FC4
 * address: 0x021D5FC4
 * packet: pkt_ov120_021D5FC4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: original narrows both func_0203FB44 payloads to halfwords.
 * interface: original narrows func_020403F4 layer argument to one byte.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021D698C 0x021D698C thumb ov120
 *   func_021D6ED8 0x021D6ED8 thumb ov120
 *   func_021D6C64 0x021D6C64 thumb ov120
 *   func_020307B0 0x020307B0 arm
 *   func_021D6B5C 0x021D6B5C thumb ov120
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_0202EA20 0x0202EA20 thumb
 *   func_0203FB44 0x0203FB44 arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_02040588 0x02040588 arm
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov_id 0x00000043 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 ov_id[];
struct Bank;
struct Node;
struct Obj;
struct Obj0202EA20;
extern void func_0204B3B4(struct Obj *p);
extern void func_021D698C(u8 *);
extern void func_021D6ED8(u8 *);
extern void func_021D6C64(u8 *);
extern void func_020307B0(void *);
extern void func_021D6B5C(u8 *);
extern void func_0204ADA4(void *);
extern void func_0204A8D4(void *);
extern void func_0204AFD8(void *);
extern void func_02030EAC(struct Node *n);
extern void func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0202EA20(struct Obj0202EA20 *p);
extern void func_0203FB44(u32,u16,u16);
extern void func_02040DA8(u32,u32,u32);
extern void func_02040588(u32,u32);
extern void func_020403F4(u8);
extern void func_0203F9B4(void);
extern void func_02034A5C(int handle);
void func_021D5FC4(u8 *p)
{
    int i;
    func_0204B3B4(*(void **)(p+0x134));
    func_021D698C(p);
    func_021D6ED8(p);
    func_021D6C64(p);
    func_020307B0(*(void **)(p+0x124));
    func_020307B0(*(void **)(p+0x128));
    func_021D6B5C(p);
    func_0204ADA4(*(void **)(p+0x18));
    func_0204ADA4(*(void **)(p+0x1c));
    func_0204A8D4(*(void **)(p+0x28));
    func_0204A8D4(*(void **)(p+0x2c));
    func_0204AFD8(*(void **)(p+0x74));
    func_0204AFD8(*(void **)(p+0x78));
    func_0204ADA4(*(void **)(p+0x24));
    func_0204A8D4(*(void **)(p+0x70));
    func_0204AFD8(*(void **)(p+0xbc));
    func_0204ADA4(*(void **)(p+0x20));
    for(i=0;i<16;i++) {
        func_0204A8D4(*(void **)(p+i*4+0x30));
        func_0204AFD8(*(void **)(p+i*4+0x7c));
    }
    func_02030EAC(*(void **)(p+0x14));
    func_0204B1CC(*(void **)(p+0x10));
    func_0204A5AC();
    func_0202EA20(*(void **)(p+0xf8));
    func_0202EA20(*(void **)(p+0xfc));
    func_0203FB44(7,*(u32 *)(p+8),*(u32 *)(p+8)>>16);
    func_0203FB44(4,*(u32 *)p,*(u32 *)p>>16);
    func_0203FB44(0,*(u32 *)(p+4),*(u32 *)(p+4)>>16);
    func_02040DA8(1,1,0);
    func_02040DA8(5,1,0);
    func_02040DA8(6,1,0);
    func_02040588(5,0);
    for(i=0;i<=7;i++) func_020403F4(i);
    func_0203F9B4();
    func_020307B0(p);
    func_02034A5C((int)ov_id);
}
