/*
 * function: func_021BFC24
 * address: 0x021BFC24
 * packet: pkt_ov204_021BFC24
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02050B80 0x02050B80 arm
 *   func_02030734 0x02030734 arm
 *   func_02050C04 0x02050C04 arm
 *   func_02051758 0x02051758 arm
 *   func_02051648 0x02051648 arm
 *   func_0205121C 0x0205121C arm
 *   func_02051230 0x02051230 arm
 *   d_021C0B30 0x021C0B30 data a1
 *   d_021C0B18 0x021C0B18 data a4
 *   d_021C0B0C 0x021C0B0C data a4
 *   d_021C0B24 0x021C0B24 data a4
 */
typedef unsigned short u16;
typedef struct { int a,b,c,d,e,f,g,h; } Config;
extern void func_02050B80(unsigned);
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02050C04(int a, int b, int c, int d);
extern int func_02051758(int a0);
extern void func_02051648(void *,void *,u16,int *,int *,int *,unsigned);
extern int func_0205121C(unsigned,unsigned,unsigned);
extern void func_02051230(void *,unsigned,unsigned,unsigned);
extern const char d_021C0B30[];
extern int d_021C0B18[];
extern int d_021C0B0C[],d_021C0B24[];
char *func_021BFC24(void *owner,unsigned heap)
{
    Config config;
    char *p;
    func_02050B80(heap);
    p=func_02030734(heap,18444,1,d_021C0B30,86);
    *(void **)(p+8)=(void *)func_02050C04((int)(p+12),18432,1,heap);
    *(void **)(p+4)=owner;
    *(u16 *)p=heap;
    config.a=2;
    config.b=16384;
    config.c=-16384;
    config.d=-12288;
    config.e=12288;
    config.f=4096;
    config.g=4194304;
    config.h=4096;
    func_02051758((int)(*(void **)(p+8)));
    func_02051648(*(void **)(p+8),&config,8192,d_021C0B18,d_021C0B0C,d_021C0B24,*(u16 *)p);
    func_02051230(*(void **)(p+8),func_0205121C(6,6,*(u16 *)p),1,0);
    return p;
}
