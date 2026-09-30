/*
 * function: func_021E08E8
 * address: 0x021E08E8
 * packet: pkt_ov119_021E08E8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Explicit unsigned range tests avoid the dense switch table.
 * symbols:
 *   func_021E36D8 0x021E36D8 thumb ov119
 *   func_021DFD3C 0x021DFD3C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9434 0x021D9434 thumb ov119
 *   func_021E0054 0x021E0054 thumb ov119
 *   func_021E0980 0x021E0980 thumb ov119
 */
extern void func_021E36D8(void *,int);
extern void func_021DFD3C(void *);
extern void func_021D8E84(void *,int);
extern void func_021D9434(void *);
extern void func_021E0054(void *);
extern void func_021E0980(void *);
void func_021E08E8(char *p)
{
    int state;
    func_021E36D8(p,0);func_021E36D8(p,1);
    func_021E36D8(p,2);func_021E36D8(p,3);
    state=*(int *)(p+0x118c);
    if(state==4 || (unsigned)(state-7)<=1) {
        *(int *)(*(char **)(p+8)+8)=3;
        func_021DFD3C(p);
        func_021D8E84(p,(int)func_021D9434);
        return;
    }
    if((unsigned)(state-1)<=2) {
        func_021D8E84(p,(int)func_021E0054);
        return;
    } else {
        func_021D8E84(p,(int)func_021E0980);
        return;
    }
}
