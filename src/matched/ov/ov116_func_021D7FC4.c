/*
 * function: func_021D7FC4
 * address: 0x021D7FC4
 * packet: pkt_ov116_021D7FC4
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FB44 0x0203FB44 arm
 *   func_02030EAC 0x02030EAC arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Node;
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void func_02030EAC(struct Node *n);
void func_021D7FC4(u8 *p) {
    u32 x=*(u32 *)(p+0x984);
    func_0203FB44(1,(u16)x,(u16)(x>>16));
    x=*(u32 *)(p+0x988);
    func_0203FB44(2,(u16)x,(u16)(x>>16));
    if(*(void **)(p+12)) {
        func_02030EAC(*(void **)(p+12));
        *(u32 *)(p+12)=0;
        *(u32 *)(p+16)=0;
    }
    *(u16 *)0x04000050=0;
}
