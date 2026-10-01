/*
 * function: func_021DA3FC
 * address: 0x021DA3FC
 * packet: pkt_ov131_021DA3FC
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding at 0x021DA486.
 * symbols:
 *   func_021D60A4 0x021D60A4 thumb ov131
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202D034 0x0202D034 thumb
 *   func_0202D01C 0x0202D01C thumb
 *   func_02045770 0x02045770 arm
 *   func_02043AF4 0x02043AF4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_021D60A4(u8 *);
extern int func_02017E1C(void *,int,int);
extern int func_0202D034(u16,u16);
extern int func_0202D01C(u16,u16,int);
extern void *func_02045770(void *);
extern void func_02043AF4(void *,int,int,int,int,int);
void func_021DA3FC(u8 *a,u8 *b) {
    void *p,*bmp;
    u16 x,y;
    int kind,value,first,last;
    p=func_021D60A4(a);
    x=func_02017E1C(p,161,0);
    y=func_02017E1C(p,160,0);
    kind=func_0202D034(y,x);
    value=func_0202D01C(y,x,48);
    bmp=func_02045770(*(void **)(b+96));
    if((u8)(kind+254)<=1) {first=7;last=8;}
    else if(kind==1) {first=9;last=10;}
    else {first=5;last=6;}
    func_02043AF4(bmp,0,3,value,1,first);
    func_02043AF4(bmp,0,4,value,1,last);
}
