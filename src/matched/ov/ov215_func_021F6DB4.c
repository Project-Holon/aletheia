/*
 * function: func_021F6DB4
 * address: 0x021F6DB4
 * packet: pkt_ov215_021F6DB4
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02050B80 0x02050B80 arm
 *   func_02050C04 0x02050C04 arm
 *   func_0205121C 0x0205121C arm
 *   func_02051B04 0x02051B04 arm
 *   func_02051230 0x02051230 arm
 *   d_021F73F4 0x021F73F4 data a4
 *   d_021F7300 0x021F7300 data a4
 */
typedef unsigned short u16;
struct Pair { unsigned archive,member; };
extern const char d_021F73F4[];
extern const unsigned long long d_021F7300;
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_02050B80(unsigned);
extern int func_02050C04(int,int,int,int);
extern int func_0205121C(unsigned,unsigned,unsigned);
extern u16 func_02051B04(void *);
extern void func_02051230(void *,unsigned,unsigned,unsigned);
char *func_021F6DB4(unsigned heap,unsigned count,const void *table)
{
    char *p;
    unsigned zero[3]={0};
    unsigned long long config;
    int resource;
    p=func_02030734(heap,0x481C,1,d_021F73F4,0x502);
    *(u16 *)p=0;
    *(u16 *)(p+2)=0;
    *(u16 *)(p+4)=count;
    *(const void **)(p+8)=table;
    *(int *)(p+0x4814)=0;
    *(int *)(p+0x4818)=-1;
    func_02050B80(heap);
    *(int *)(p+0x480C)=func_02050C04((int)(p+12),0x4800,1,heap);
    config=d_021F7300;
    resource=func_0205121C((unsigned)config,(unsigned)(config>>32),heap);
    *(unsigned char *)(p+0x4810)=func_02051B04((void *)resource);
    func_02051230(*(void **)(p+0x480C),resource,1,0);
    return p;
}
