/*
 * function: func_021C9E10
 * address: 0x021C9E10
 * packet: pkt_ov128_021C9E10
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02049EF4 0x02049EF4 arm
 *   d_021CA648 0x021CA648 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u16 d_021CA648[4];
extern void *func_02049EF4(void *, u32, u32, void **, u16);
void func_021C9E10(u8 *p,u8 *q,u16 heap)
{
    u16 ids[4];
    int i;
    ids[0]=d_021CA648[0]; ids[1]=d_021CA648[1];
    ids[2]=d_021CA648[2]; ids[3]=d_021CA648[3];
    for(i=0;i<4;i++) {
        *(void **)p=func_02049EF4(*(void **)(q+8),ids[i],0,(void **)(p+4),heap);
        p+=8;
    }
}
