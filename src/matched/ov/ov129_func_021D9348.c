/*
 * function: func_021D9348
 * address: 0x021D9348
 * packet: pkt_ov129_021D9348
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_021DA158 0x021DA158 thumb ov129
 *   func_0204B878 0x0204B878 arm
 *   func_0201F35C 0x0201F35C thumb
 *   func_02045AA8 0x02045AA8 arm
 *   func_02045808 0x02045808 arm
 *   func_021D8AF4 0x021D8AF4 thumb ov129
 */

extern void *func_020457B0(int,int);
extern unsigned func_021DA158(int,int);
extern void func_0204B878(int,unsigned short);
extern void func_0201F35C(void *,int,int,int,int);
extern void func_02045AA8(int,void *);
extern void func_02045808(void *);
extern void func_021D8AF4(char *,int);
void func_021D9348(char *p)  {
    int i;
    char *q;
    void *v=func_020457B0(100,50);
    *(int *)(p+0x1f8)=1;
    *(unsigned char *)(p+0x210)=0;
    for(i=0;i<*(int *)(p+0x23c);i++)  {
        q=p+i*28;
        if(*(int *)q==0)  {
            *(int *)q=1;
            func_0204B878(*(int *)(q+12),func_021DA158(1,*(int *)(q+8)));
        }
        func_0201F35C(v,*(int *)q-1,1,1,1);
        func_02045AA8(*(int *)(p+0x348),v);
    }
    func_02045808(v);
    func_021D8AF4(p,3);
}
