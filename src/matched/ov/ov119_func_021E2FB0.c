/*
 * function: func_021E2FB0
 * address: 0x021E2FB0
 * packet: pkt_ov119_021E2FB0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0205121C 0x0205121C arm
 *   func_02087A3C 0x02087A3C arm
 *   func_020056BC 0x020056BC thumb
 *   func_02051360 0x02051360 arm
 */
typedef unsigned short u16;
extern void *func_0205121C(int,int,u16);
extern void *func_02087A3C(int,int);
extern int func_020056BC(void *);
extern void func_02051360(void *,void *,int,int);
void func_021E2FB0(char *p) {
    int i;
    *(void **)(p+0xb4)=func_0205121C(0x67,0x35,(*(u16 *)(p+0xba)&0x7fff)|0x8000);
    for(i=0;i<4;i++) {
        int x=func_020056BC(func_02087A3C(1,1));
        func_02051360(((void **)p)[i],*(void **)(p+0xb4),1,x);
    }
}
