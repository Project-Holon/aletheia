/*
 * function: func_021DB3F0
 * address: 0x021DB3F0
 * packet: pkt_ov131_021DB3F0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_020362DC 0x020362DC arm
 *   func_020061E4 0x020061E4 thumb
 *   func_02017E88 0x02017E88 thumb
 *   func_021DB468 0x021DB468 thumb ov131
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021D6064(u8 *);
extern u32 func_020362DC(void);
extern void func_020061E4(u32 a);
extern unsigned func_02017E88(void *,unsigned,unsigned);
extern void func_021DB468(u8 *,u8 *,u8,int);
void func_021DB3F0(u8 *a,u8 *b) {
    void *p;
    int i,step;
    unsigned v;
    p=func_021D6064(a);
    i=b[41];
    if(func_020362DC()==64) step=-1;else step=1;
    func_020061E4(1352);
    do {
        i+=step;
        if(i<0) i=b[43]-1;
        else if(i>b[43]-1) i=0;
        if(i<4) v=(u16)func_02017E88(p,i+54,0);
        else v=*(u16 *)(*(u8 **)(a+8)+20);
    } while(v==0);
    func_021DB468(a,b,i,0);
}
