/*
 * function: func_021D42A0
 * address: 0x021D42A0
 * packet: pkt_ov124_021D42A0
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: existing follower 021D43F0 remains in its separately verified file.
 * symbols:
 *   func_021D48A4 0x021D48A4 thumb ov124
 *   func_021D49C8 0x021D49C8 thumb ov124
 *   func_020362DC 0x020362DC arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0204A600 0x0204A600 arm
 *   func_02045334 0x02045334 arm
 *   func_02040618 0x02040618 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern u32 func_020221A4(void);
struct Descriptor;
struct Obj;
struct PrintSys;
extern u32 func_02028230(u8 *p);
extern void func_021D48A4(char *);
extern u32 func_020362DC(void);
extern void func_02041B6C(u32 bit);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void func_0204A600(void);
extern void func_02028178(u8 *p);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_02045334(struct Descriptor *d);
extern void func_021D49C8(char *,u32);
extern void func_020282A4(struct Obj *obj);
extern void func_0202843C(u8 *p);
extern void func_02028454(u8 *p);
extern void func_02040618(u32 layer, u32 a, u32 b);
int func_021D42A0(char *p)
{
    switch(*(u32 *)(p+16)) {
    case 0:
        func_0202208C((void *)4,1,1,0,6,1,*(u16 *)p);
        *(u32 *)(p+16)=1;
        break;
    case 1:
        if(func_020221A4()==1) *(u32 *)(p+16)=4;
        break;
    case 2:
        if(func_02028230(*(void **)(p+0x40))==1) {
            func_0202208C((void *)4,0,0,0,6,1,*(u16 *)p);
            *(u32 *)(p+16)=3;
        }
        break;
    case 3:
        if(func_020221A4()==1) return 1;
        break;
    case 4:
        if(!*(u32 *)(p+0x1c)) func_021D48A4(p);
        if(func_020362DC()&4) func_02041B6C(4);
        break;
    }
    func_0201C4E4(*(void **)(p+0x30));
    func_0204A600();
    if(*(void **)(p+0x3c)) func_02028178(*(void **)(p+0x3c));
    if(*(void **)(p+0x38)) func_02028178(*(void **)(p+0x38));
    func_02028178(*(void **)(p+0x40));
    if(*(u32 *)(p+0x1c)==1 && func_0201C6B4(*(void **)(p+0x30))==1 &&
       (func_02028230(*(void **)(p+0x3c))==1 || func_02028230(*(void **)(p+0x38))==1 || *(u32 *)(p+12)==1)) {
        func_02045334(*(void **)(p+0x20));
        func_02045334(*(void **)(p+0x24));
        *(u32 *)(p+0x1c)=0;
        *(u32 *)(p+12)=0;
        func_021D49C8(p,*(u8 *)(p+0x18));
        if(*(u8 *)(p+0x18)==11) {
            func_020282A4(*(void **)(p+0x3c));
            func_0202843C(*(void **)(p+0x3c));
        } else {
            func_02028454(*(void **)(p+0x3c));
            func_020282A4(*(void **)(p+0x3c));
        }
        if(*(u8 *)(p+0x18)==0) {
            func_020282A4(*(void **)(p+0x38));
            func_0202843C(*(void **)(p+0x38));
        } else {
            func_02028454(*(void **)(p+0x38));
            func_020282A4(*(void **)(p+0x38));
        }
    }
    func_02040618(7,5,1);
    return 0;
}
