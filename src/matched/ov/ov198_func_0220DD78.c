/*
 * function: func_0220DD78
 * address: 0x0220DD78
 * packet: pkt_ov198_0220DD78
 * region: ov198
 * status: EXACT
 * symbols:
 *   d_02211B20 0x02211B20 data a1
 *   d_02211B3C 0x02211B3C data a4
 *   func_0220BDA0 0x0220BDA0 thumb ov198
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0220BEB8 0x0220BEB8 thumb ov198
 *   func_0220C5AC 0x0220C5AC thumb ov198
 *   func_0220C4DC 0x0220C4DC thumb ov198
 *   func_0220D034 0x0220D034 thumb ov198
 *   func_0220D090 0x0220D090 thumb ov198
 *   func_0220D1BC 0x0220D1BC thumb ov198
 *   func_0220D218 0x0220D218 thumb ov198
 *   func_0220D348 0x0220D348 thumb ov198
 *   func_0220D3B4 0x0220D3B4 thumb ov198
 *   func_0220D418 0x0220D418 thumb ov198
 *   func_0220D494 0x0220D494 thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 d_02211B20[];
extern const int d_02211B3C[];
extern void func_0220BDA0(char *);
extern int func_022110D4(u8 *,int);
extern void func_0220BEB8(char *,int,int,u8,u8);
extern void func_0220C5AC(char *,int,u16,u16);
extern void func_0220C4DC(char *,int,int,int,u16,short,unsigned);
extern void func_0220D034(char *,int),func_0220D090(char *,int,int);
extern void func_0220D1BC(char *,int),func_0220D218(char *,int,unsigned);
extern void func_0220D348(char *,int,int),func_0220D3B4(char *,int);
extern void func_0220D418(char *,int,int),func_0220D494(char *,int,int,int);
void func_0220DD78(char *p) {
    u8 *owner;
    char *base,*rec;
    unsigned offset;
    *(u8 **)(p+0x253c)=d_02211B20;
    func_0220BDA0(p);
    owner=*(u8 **)p;
    base=p+0x30+func_022110D4((u8 *)p,owner[32])*76;
    offset=owner[0x4b]*8;
    rec=base+offset;
    func_0220BEB8(p,6,owner[32],0,0);
    func_0220C5AC(p,7,0,0);
    func_0220C4DC(p,*(u16 *)(base+offset),0,d_02211B3C[(*(u8 **)p)[0x4b]],0,0,0x3dc0);
    func_0220D034(p,8);
    func_0220D090(p,2,(u8)rec[6]);
    func_0220D1BC(p,9);
    func_0220D218(p,3,(u8)rec[7]);
    func_0220D348(p,4,*(u16 *)(base+offset));
    func_0220D3B4(p,10);
    func_0220D418(p,5,(u8)rec[5]);
    func_0220D494(p,1,(u8)rec[2],(u8)rec[3]);
}
