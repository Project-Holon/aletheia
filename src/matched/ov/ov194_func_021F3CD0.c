/*
 * function: func_021F3CD0
 * address: 0x021F3CD0
 * packet: pkt_ov194_021F3CD0
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_020457B0 0x020457B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
extern void func_02082BCC(unsigned char *,unsigned,unsigned);
extern int func_020457B0(int,unsigned short);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_0201F73C(int,int,int,int);
extern int func_02045770(int);
extern void func_02043B5C(int,unsigned char);
extern void func_02045334(int);
extern void func_02045374(int);
extern int func_02045730(int);
extern void func_020409B4(unsigned);
void func_021F3CD0(unsigned char *p,int a,int b,int c,int d,unsigned short e) {
    int window;
    func_02082BCC(p,0,0x24);
    *(unsigned short *)(p+32)=15;
    *(int *)(p+4)=a; *(int *)(p+24)=d; *(int *)p=b; *(int *)(p+16)=c;
    *(int *)(p+28)=func_020457B0(255,e);
    *(int *)(p+20)=func_020450F0(4,1,19,30,4,15,1);
    func_0201F73C(*(int *)(p+20),2,1,14);
    *(int *)(p+8)=*(int *)(p+20);
    *(unsigned char *)(p+12)=0;
    func_02043B5C(func_02045770(*(int *)(p+20)),*(unsigned short *)(p+32));
    window=*(int *)(p+20);
    func_02045334(window); func_02045374(window);
    func_020409B4(func_02045730(window));
}
