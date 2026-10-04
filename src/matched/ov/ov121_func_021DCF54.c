/*
 * function: func_021DCF54
 * address: 0x021DCF54
 * packet: pkt_ov121_021DCF54
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02082BCC(void *,int,int);
typedef unsigned int   u32;
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *,void *,int);
extern void func_020307B0(void *);
void func_021DCF54(char *p,void *arc,int id,int index,u8 other,u16 heap)
{
    void *res;
    void *allocation;
    char *data;
    func_02082BCC(p,0,0x60);
    allocation=func_02049F78(arc,id,(u32)(&res),heap);
    data=*(char **)((char *)res+0xc);
    func_02082D44(data+index*32,p+0x40,32);
    func_02082D44(data+other*32,p+0x20,32);
    func_020307B0(allocation);
}
