/*
 * function: func_0220B260
 * address: 0x0220B260
 * packet: pkt_ov207_0220B260
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020414EC 0x020414EC arm
 *   func_0204047C 0x0204047C arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned short u16;
extern void func_020414EC(int);
extern void func_0204047C(int,int);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049B68(void *,int,int,int,int,unsigned);
extern unsigned func_02049740(void *,int,int,int,int,unsigned);
extern void func_020498F4(void *,int,int,u16,int,int,unsigned);
extern void func_02049238(void *);
extern void func_020409B4(int);
void func_0220B260(unsigned *p)
{
    void *r;
    p[11]=1;
    func_020414EC(3);
    func_0204047C(1,3);
    func_0204047C(3,0);
    r=func_020490F4(159,*(u16 *)p);
    func_02049B68(r,7,0,0,32,*(u16 *)p);
    p[12]=func_02049740(r,17,1,2048,0,*(u16 *)p);
    func_020498F4(r,39,1,p[12],1536,0,*(u16 *)p);
    func_02049238(r);
    func_020409B4(1);
}
