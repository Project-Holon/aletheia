/*
 * unit: yes
 * function: func_021F3A08, func_021F3A4C
 * address: 0x021F3A08
 * packet: pkt_ov112_021F3A08
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: tail stub at 0x021F3A4C; function_starts seed.
 * symbols:
 *   func_021F3C50 0x021F3C50 thumb ov112
 *   func_021F4350 0x021F4350 thumb ov112
 *   func_021F44E8 0x021F44E8 thumb ov112
 *   func_0204A600 0x0204A600 arm
 *   func_0204A648 0x0204A648 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021F3C50(u8 *);
typedef unsigned int   u32;
extern void func_021F4350(u8 *p);
extern int func_021F44E8(u32 *p);
extern void func_0204A600(void);
extern void func_0204A648(void);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
int func_021F3A08(int a,int b,int c,u8 *p)
{
    func_021F3C50(*(u8 **)(p+0xc));
    func_021F4350(*(void **)(p+0x10));
    func_0204A600();
    if(func_021F44E8(*(void **)(p+0x10))==1) {
        func_0202208C(0,0,0,0,6,1,*(u16 *)p);
        return 1;
    }
    return 0;
}
void func_021F3A4C(void) { func_0204A648(); }
