/*
 * function: func_021FD12C
 * address: 0x021FD12C
 * packet: pkt_ov186_021FD12C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021FB964(int,int,u16);
extern void *func_021FC6A4(u16,u32,u16,u16,u8,u8,void *,u16);
void *func_021FD12C(int a,void *owner,u16 heap)
{
    u8 *p;
    func_021FB964(a,2,heap);
    p=func_021FC6A4(0,1,19,30,4,2,owner,heap);
    *(u16 *)(p+20)=12;
    return p;
}
