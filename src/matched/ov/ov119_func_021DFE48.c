/*
 * function: func_021DFE48
 * address: 0x021DFE48
 * packet: pkt_ov119_021DFE48
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Repeat the message call in each arm; an id local factors the argument loads and is 20 bytes short.
 * symbols:
 *   func_02005D90 0x02005D90 thumb
 *   func_02005DF8 0x02005DF8 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_021E0FF4 0x021E0FF4 thumb ov119
 *   func_021DFD30 0x021DFD30 thumb ov119
 *   func_02040588 0x02040588 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DFF40 0x021DFF40 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02005D90(int,int),func_02005DF8(int),func_02045CAC(int,int,int);
extern int func_021D8AA8(void *),func_0201F5DC(int,int,int,int);
extern void *func_021D8FA4(void *,int);
extern void func_0201EEF4(void *p, u32 i, void *mon),func_0201F02C(int,int,int),func_0201F250(int,int,int),func_021E0FF4(void *,int,int),func_021DFD30(u8 *,u32),func_02040588(int,int),func_021D8E84(void *,int),func_021DFF40(void *);
void func_021DFE48(char *p)
{
    void *mon;
    int z,state;
    if(*(int *)(p+0xf2c)<6) return;
    func_02005D90(0x518,0xffff);
    func_02005DF8(6);
    state=*(int *)(p+0x118c);
    if(state==7) func_02045CAC(*(int *)(p+0x720),153,*(int *)(p+0x73c));
    else if(state==8) func_02045CAC(*(int *)(p+0x720),156,*(int *)(p+0x73c));
    else if(*(u8 *)(p+0x11ee)) func_02045CAC(*(int *)(p+0x720),131,*(int *)(p+0x73c));
    else func_02045CAC(*(int *)(p+0x720),48,*(int *)(p+0x73c));
    if(func_021D8AA8(p)) mon=func_021D8FA4(p,0);
    else mon=func_021D8FA4(p,1);
    func_0201EEF4(*(void **)(p+0x724),1,mon);
    z=0;
    func_0201F02C(*(int *)(p+0x724),0,*(int *)(p+0x834));
    func_0201F250(*(int *)(p+0x724),*(int *)(p+0x738),*(int *)(p+0x73c));
    *(int *)(p+0x644)=func_0201F5DC(6,15,0,*(u16 *)(p+0x5f4));
    func_021E0FF4(p,1,0);
    func_021DFD30((u8 *)p,0);
    func_02040588(6,1);
    *(int *)(p+0xf2c)=z;
    func_021D8E84(p,(int)func_021DFF40);
}
