/*
 * function: func_021C098C
 * address: 0x021C098C
 * packet: pkt_ov110_021C098C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C088C 0x021C088C thumb ov110
 *   data_021C39E0 0x021C39E0 data a4
 */
extern void func_021C088C(void *,void *,void *,int);
extern unsigned short data_021C39E0[];
void func_021C098C(char *p) {
    int v;
    if (*(int *)(p+0x1c)) {
        v=1;
        if (*(unsigned char *)(p+0x20)<16) {
            v=(*(unsigned char *)(p+0x20)/4)%2;
            (*(unsigned char *)(p+0x20))++;
        }
        if(v) *(unsigned short *)(p+0xc)=0xfc00;
        else *(unsigned short *)(p+0xc)=0x7c00;
    }
    func_021C088C(p+0xc,p+0xe,data_021C39E0,3);
}
