/*
 * function: func_021C97A0
 * address: 0x021C97A0
 * packet: pkt_ov128_021C97A0
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 heap keeps its word spill before the first indexed load.
 * symbols:
 *   func_021C6BCC 0x021C6BCC thumb ov128
 *   func_021C6ADC 0x021C6ADC thumb ov128
 *   func_02041090 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021C991C 0x021C991C thumb ov128
 *   func_021C9BEC 0x021C9BEC thumb ov128
 *   func_021C9D88 0x021C9D88 thumb ov128
 *   func_021C6E18 0x021C6E18 thumb ov128
 *   func_021C6DD8 0x021C6DD8 thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021C6BCC(u8 *,u8 *,int,unsigned);
extern void func_021C6ADC(u8 *,u8 *,unsigned);
extern void func_02041090(u32,void *,u32,u32,u8,u8);
extern void func_02041B6C(u32);
extern void func_021C991C(u8 *,u8 *,u8 *,unsigned);
extern void func_021C9BEC(u8 *,void *,void *,int,s16,int);
extern int func_021C9D88(u8 *,int);
extern void func_021C6E18(void *,int,int);
extern void func_021C6DD8(void *,int);
void func_021C97A0(u8 *p,u8 *q,u8 *r,u16 heap)
{
    u16 *t;
    func_021C6BCC(r,(u8 *)q,(q+*(signed char *)(q+11))[24],heap);
    func_021C6ADC(r,r+12,13);
    t=*(u16 **)(p+0xfc);
    func_02041090(0,(u8 *)t+12,0,0,(u32)t[0]>>3,(u32)t[1]>>3);
    func_02041B6C(0);
    t=*(u16 **)(p+0x104);
    func_02041090(2,(u8 *)t+12,0,0,(u32)t[0]>>3,(u32)t[1]>>3);
    func_02041B6C(2);
    func_021C991C(p,(u8 *)q,r,heap);
    func_021C9BEC(p,(u8 *)q,r,0,*(s16 *)p,heap);
    if(func_021C9D88((u8 *)q,0)==1) {
        func_021C6E18(r,1,3);
        func_021C6E18(r,0,2);
    } else {
        func_021C6E18(r,1,17);
        func_021C6E18(r,0,16);
    }
    func_021C6DD8(r,1);
}
