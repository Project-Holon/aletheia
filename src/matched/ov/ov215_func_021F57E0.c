/*
 * function: func_021F57E0
 * address: 0x021F57E0
 * packet: pkt_ov215_021F57E0
 * region: ov215
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021F5C20 0x021F5C20 thumb ov215
 *   func_021F5EB8 0x021F5EB8 thumb ov215
 *   func_0204E720 0x0204E720 arm
 *   func_02031324 0x02031324 arm
 *   func_0203D34C 0x0203D34C arm
 * Legacy void allocator/31324 returns consumed; preserve visible heap input.
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void func_0203064C(u32,u32,u32);
extern char *func_0203159C(void *,u32,u32);
extern void func_02082BCC(void *,u32,u32);
extern void func_021F5C20(int a, char *p);
extern int func_021F5EB8(int,char *);
extern void func_0204E720(u32,int,int,int);
extern u32 func_02031324(u32);
extern void func_0203D34C(u32,u32);
int func_021F57E0(void *a,int unused,u32 c)
{
    char *p;
    func_0203064C(1,143,5<<16);
    p=func_0203159C(a,140,143);
    func_02082BCC(p,0,140);
    *(u16 *)p=143;
    *(u32 *)(p+16)=0;
    p[20]=5;
    *(u32 *)(p+24)=0;
    *(u32 *)(p+28)=0;
    *(u32 *)(p+32)=0;
    func_021F5C20(c,p);
    func_021F5EB8(c,p);
    func_0204E720(3,16,16,0);
    *(u32 *)(p+136)=func_02031324(*(u16 *)p);
    func_0203D34C(0,*(u16 *)p);
    return 1;
}
