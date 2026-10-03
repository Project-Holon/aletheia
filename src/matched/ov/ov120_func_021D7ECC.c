/*
 * function: func_021D7ECC
 * address: 0x021D7ECC
 * packet: pkt_ov120_021D7ECC
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern int func_0201D304(void *,int,int);
extern void *func_0202800C(void *,void *,u8,u8,u8,u8,int,int,u16);
extern void func_02045808(struct U16Vec *vec);
void *func_021D7ECC(char *p,u16 n)
{
    int width;
    void *result;
    void *text;
    text=func_020457B0(100,*(u16 *)(p+0xc8));
    *(void **)(p+0xa8)=text;
    func_02045CAC(*(void **)(p+0xc),n,text);
    *(u16 *)(p+0xac)=0x39e3;
    *(int *)(p+0xb0)=0;
    width=(func_0201D304(*(void **)(p+0xa8),*(int *)(p+0x14),0)+32)/16;
    result=func_0202800C(*(void **)(p+0xc0),p+0xa8,16-width,21,width*2,3,0,1,*(u16 *)(p+0xc8));
    func_02045808(*(void **)(p+0xa8));
    return result;
}
