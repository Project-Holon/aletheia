/*
 * function: func_021E324C
 * address: 0x021E324C
 * packet: pkt_ov119_021E324C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02047E88 0x02047E88 arm
 *   func_02048A18 0x02048A18 arm
 *   func_0204779C 0x0204779C arm
 *   func_020477A4 0x020477A4 arm
 *   d_021E7B3C 0x021E7B3C data a4
 */
typedef unsigned short u16;
typedef struct {int a,b,c; u16 d,e;} Entry;
extern const Entry d_021E7B3C[];
extern u16 func_02047E88(void *,const Entry *);
extern void *func_02048A18(void *,u16);
extern int func_0204779C(int *p);
extern void func_020477A4(void *,u16);
void func_021E324C(char *p,int n) {
    void *q;
    int i,count;
    if(d_021E7B3C[n].d) *(u16 *)(p+0x824)=func_02047E88(*(void **)(p+0x820),&d_021E7B3C[n]);
    else *(u16 *)(p+0x824)=0xffff;
    if(*(u16 *)(p+0x824)!=0xffff) {
        q=func_02048A18(*(void **)(p+0x820),*(u16 *)(p+0x824));
        count=func_0204779C(q);
        for(i=0;i<count;i++) func_020477A4(q,i);
    }
    *(int *)(p+0x109c)=n;
}
