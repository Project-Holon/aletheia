/*
 * unit: yes
 * function: func_021B630C,func_021B63BC,func_021B63C4,func_021B63CC
 * address: 0x021B630C
 * packet: pkt_ov101_021B630C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6494 0x021B6494 thumb ov101
 *   func_0203D378 0x0203D378 arm
 */
extern int func_021B6494(int *,int,int,int *);
extern int func_0203D378(void);
int func_021B630C(int *p,int value)
{
    int i;
    if(p[30]) return 1;
    switch(p[17]) {
    case 0:
        p[28]=0;
        if(func_021B6494(p,0xD00,4,&value)) p[17]=1;
        break;
    case 1:
        if(func_0203D378()) {
            for(i=0;i<2;i++) { if(value != p[26+i]) break; }
            if(i == 2) p[17]=2;
        } else p[17]=3;
        break;
    case 2:
        if(func_021B6494(p,0xD01,4,&value)) p[17]=4;
        break;
    case 3:
        if(p[28]) p[17]=4;
        break;
    case 4:
        p[17]=0;
        return 1;
    }
    return 0;
}
void func_021B63BC(int *p) { p[17]=0; }
void func_021B63C4(int *p) { p[15]=0; p[14]=0; }
void func_021B63CC(int *p,int n) { p[14]=n; }
