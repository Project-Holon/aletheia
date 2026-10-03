/*
 * function: func_021C0EB0
 * address: 0x021C0EB0
 * packet: pkt_ov110_021C0EB0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035CB8 0x02035CB8 arm
 *   func_0204B550 0x0204B550 arm
 *   func_021C0E3C 0x021C0E3C thumb ov110
 */
typedef unsigned int   u32;
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern void func_0204B550(void *,int,int);
extern void func_021C0E3C(unsigned,int,unsigned short *,short *);
int func_021C0EB0(char *p) {
    unsigned x,y;
    unsigned short index;
    short pos;
    if(!func_02035CB8(&x,&y)) {
        *(unsigned char *)(p+0x99)=(*(unsigned char *)(p+0x99)&~1);
        return 0;
    }
    func_021C0E3C(y,*(unsigned char *)(p+0x98),&index,&pos);
    func_0204B550(*(void **)(p+8),pos,1);
    if((unsigned short)index!=*(unsigned char *)(p+0x96)) {
        *(unsigned char *)(p+0x96)=index;
        return 1;
    }
    return 0;
}
