/*
 * function: func_021FD6D8
 * address: 0x021FD6D8
 * packet: pkt_ov186_021FD6D8
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021FD73C 0x021FD73C thumb ov186
 *   d_02200D5C 0x02200D5C data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void MI_CpuFill8(void *,int,int);
extern int *func_021FD73C(int *p, int v);
extern const char d_02200D5C[];
int *func_021FD6D8(int payload,int callback,u32 heap)
{
    int *p;
    p=func_02030734(heap,16,0,d_02200D5C,0x6a2);
    MI_CpuFill8(p,0,16);
    p[2]=payload;
    func_021FD73C(p,callback);
    return p;
}
