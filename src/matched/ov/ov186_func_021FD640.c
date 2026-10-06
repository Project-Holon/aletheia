/*
 * function: func_021FD640
 * address: 0x021FD640
 * packet: pkt_ov186_021FD640
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_021FC734 0x021FC734 thumb ov186
 *   func_0202DC08 0x0202DC08 thumb
 *   func_021FBDA4 0x021FBDA4 thumb ov186
 *   func_020307B0 0x020307B0 arm
 *   func_020409B4 0x020409B4 arm
 */
struct Obj;
extern void func_0204B3B4(struct Obj *p);
typedef unsigned int   u32;
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
typedef unsigned char  u8;
extern void func_021FC734(u8 *p);
extern void func_0202DC08(struct Obj *p);
extern void func_021FBDA4(int a, unsigned mode);
extern u32 func_020307B0(void *p);
extern void func_020409B4(u32 index);
void func_021FD640(int *p)
{
    int i;
    if(p[10]) {func_0204B3B4((struct Obj *)p[10]);func_0204ADA4(p[14]);func_0204A8D4(p[15]);func_0204AFD8(p[16]);}
    if(p[9]) {func_0204B3B4((struct Obj *)p[9]);func_0204ADA4(p[11]);func_0204A8D4(p[12]);func_0204AFD8(p[13]);}
    for(i=0;i<7;i++) if(p[i]) {func_021FC734((void *)p[i]);p[i]=0;}
    func_0202DC08((struct Obj *)p[8]);func_021FBDA4(p[7],8);func_020307B0(p);func_020409B4(1);
}
