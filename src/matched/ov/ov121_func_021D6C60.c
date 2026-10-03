/*
 * function: func_021D6C60
 * address: 0x021D6C60
 * packet: pkt_ov121_021D6C60
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049F34 0x02049F34 arm
 *   func_0204ADEC 0x0204ADEC arm
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02049F34(int,int,void **,int);
extern void func_0204ADEC(void *,void *,int);
extern void func_020307B0(void *);
void func_021D6C60(u8 *p,int heap)
{
    void *out;
    void *raw;
    raw=func_02049F34(34,8,&out,heap);
    func_0204ADEC(*(void **)p,out,7);
    func_020307B0(raw);
}
