/*
 * function: func_021DD5AC
 * address: 0x021DD5AC
 * packet: pkt_ov137_021DD5AC
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_0204B294 0x0204B294 arm
 * func_0204B92C 0x0204B92C arm
 * func_0204B878 0x0204B878 arm
 * func_0204B3DC 0x0204B3DC arm
 * func_020434DC 0x020434DC arm
 * func_02043598 0x02043598 arm
 * d_021E1B08 0x021E1B08 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u16 d_021E1B08[];
extern u32 func_0204B294(u32,u32,u32,u32,const void *,u16,u16);
struct Obj;
extern void func_0204B92C(struct Obj *,unsigned int);
extern void func_0204B878(u32,int),func_0204B3DC(u32,int),func_020434DC(int,int),func_02043598(int,int);
void func_021DD5AC(u8 *p)
{
    struct { u16 a,b,c; u8 d,e; } s;
    long i;
    s.e=1; s.d=0; s.c=0;
    for(i=0;i<5;i++) {
        s.a=d_021E1B08[i*2+2]; s.b=d_021E1B08[i*2+3];
        *(u32 *)(p+i*4+156)=func_0204B294(*(u32 *)(p+104),*(u32 *)(p+i*4+128),*(u32 *)(p+i*4+108),*(u32 *)(p+148),&s,0,114);
        func_0204B92C((struct Obj *)*(u32 *)(p+i*4+156),1);
        func_0204B878(*(u32 *)(p+i*4+156),0);
        func_0204B3DC(*(u32 *)(p+i*4+156),0);
    }
    func_020434DC(16,1); func_02043598(16,0);
}
