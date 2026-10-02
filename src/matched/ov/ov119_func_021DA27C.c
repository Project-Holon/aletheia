/*
 * function: func_021DA27C
 * address: 0x021DA27C
 * packet: pkt_ov119_021DA27C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DD3D4 0x021DD3D4 thumb ov119
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DA254 0x021DA254 thumb ov119
 */

typedef unsigned short u16;
extern int func_021DD3D4(void *,int,int,int);
extern unsigned func_020399A8(void);
extern int func_0203D3A8(void *a, unsigned int b, unsigned int c, void *d);
extern void func_021D8E84(void *,int);
extern void func_021DA254(void *);
void func_021DA27C(char *p) {
    int v=0;
    int n;
    if(*(int *)(p+0xF88)==*(int *)(p+0x630)) v=1;
    n=func_021DD3D4(p,0,*(int *)(p+0xF84),*(int *)(p+0xF88));
    if(n!=-1) {
        if(func_0203D3A8(func_020399A8(),n+0xC13,1,&v)) {
            func_021D8E84(p,(int)func_021DA254);
            return;
        }
    } else func_021D8E84(p,(int)func_021DA254);
}
