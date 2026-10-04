/*
 * function: func_0220B6C4
 * address: 0x0220B6C4
 * packet: pkt_ov197_0220B6C4
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0220B1D4 0x0220B1D4 thumb ov197
 */
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(int,int);
extern void func_02045334(struct Descriptor *);
extern void func_0220B1D4(char *,int,int,int,unsigned short);
void func_0220B6C4(char *p)
{
    func_02043B5C((int)func_02045770((struct Descriptor *)*(int *)(p+0x110)),0);
    if(*(int *)(*(char **)p+8)!=1) {
        switch(((unsigned char *)p)[0x533]) {
        case 0:func_0220B1D4(p,29,22,4,0x3c40);func_0220B1D4(p,29,23,20,0x3c40);break;
        case 1:func_0220B1D4(p,29,24,4,0x3c40);func_0220B1D4(p,29,25,20,0x3c40);break;
        case 2:func_0220B1D4(p,29,26,12,0x3c40);break;
        case 3:func_0220B1D4(p,29,27,12,0x3c40);break;
        }
    } else func_02045334((struct Descriptor *)*(int *)(p+0x110));
}
