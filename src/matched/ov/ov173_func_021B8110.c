/*
 * function: func_021B8110
 * address: 0x021B8110
 * packet: pkt_ov173_021B8110
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B98C 0x0204B98C arm
 *   func_02028230 0x02028230 thumb
 *   func_021B7EB0 0x021B7EB0 thumb ov173
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_0204B98C(void *);
extern int func_02028230(void *);
extern void func_021B7EB0(u8 *,int);
int func_021B8110(u8 *p)
{
    u8 *s;
    s=p+464;
    if(*(u16 *)(s+10)==0) {
        if(func_0204B98C(*(void **)(p+260+*(u16 *)(s+6)*4))==0) return *(u16 *)(s+8);
    } else if(*(u16 *)(s+10)==1) {
        if(func_02028230(*(void **)(p+544+*(u16 *)(s+6)*4))!=0) {
            func_021B7EB0(p,0);
            return *(u16 *)(s+8);
        }
    }
    return 13;
}
