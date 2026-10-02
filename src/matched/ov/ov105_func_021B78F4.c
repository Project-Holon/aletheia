/*
 * function: func_021B78F4
 * address: 0x021B78F4
 * packet: pkt_ov105_021B78F4
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: contested89B8 hint dropped after original7A30 word confirmed.
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02040C14 0x02040C14 arm
 *   func_02049740 0x02049740 arm
 *   func_02049238 0x02049238 arm
 *   d_021B8964 0x021B8964 data ov105 a4
 *   d_021B89B8 0x021B89B8 data a4
 *   d_021B8A08 0x021B8A08 data ov105 a4
 *   d_021B8998 0x021B8998 data ov105 a4
 */
typedef unsigned char u8;
extern void func_0203F8F4(int);
extern void func_02045088(int);
extern void func_0203FC28(const void *);
extern void func_0203FCA0(u8,const void *,u8);
extern void func_020414AC(u8);
extern void func_02040588(u8,int);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *,int,int,int,int,int);
extern void func_02049658(void *,int,int,int,int,int,int);
extern void func_020498F4(void *,int,int,int,int,int,int);
extern void func_02040C14(int,int,int,int);
extern void *func_02049740(void *,int,int,int,int,int);
extern void func_02049238(void *);
extern const u8 d_021B8964[],d_021B8A08[];
extern const int d_021B89B8[],d_021B8998[];
void func_021B78F4(void **p,int heap)
{
    int i,id;
    void *archive;
    func_0203F8F4(heap); func_02045088(heap); func_0203FC28(d_021B8964);
    for(i=0;i<8;++i) {
        id=d_021B89B8[i];
        func_0203FCA0((u8)id,d_021B8A08+i*32,(u8)d_021B8998[i]);
        func_020414AC((u8)id); func_02040588((u8)id,1);
    }
    archive=func_020490F4(0x5e,heap);
    func_02049B68(archive,16,0,0,0,heap);
    func_02049B68(archive,16,4,0,0,heap);
    func_02049658(archive,0,2,0,0,0,heap);
    func_02049658(archive,0,6,0,0,0,heap);
    func_02049658(archive,48,4,0,0,0,heap);
    func_02049658(archive,13,1,0,0,0,heap);
    func_020498F4(archive,4,2,0,0,0,heap);
    func_020498F4(archive,4,6,0,0,0,heap);
    func_020498F4(archive,46,4,0,0,0,heap);
    func_020498F4(archive,14,1,0,0,0,heap);
    func_02040C14(5,0,1,0);
    *p=func_02049740(archive,49,5,0,0,heap);
    func_02049238(archive);
}
