/*
 * function: func_021D82F8
 * address: 0x021D82F8
 * packet: pkt_ov120_021D82F8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 021D8356.
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   func_02045760 0x02045760 arm
 *   func_02045788 0x02045788 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct Cfg;
struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
extern u8 func_02045760(struct Descriptor *p);
extern void func_02045788(struct Descriptor *p, u8 v);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021D82F8(char *p)
{
    int i;
    char *t;
    if(*(void **)(p+0x80)) {func_020452E8(*(void **)(p+0x80));*(void **)(p+0x80)=0;}
    for(i=0;i<6;i++) {
        t=p+4*i;
        if(*(void **)(t+0x6c)) {
            func_02045788(*(void **)(t+0x6c),func_02045760(*(void **)(t+0x6c))+6);
            func_02045374(*(void **)(t+0x6c));
        }
    }
    func_02041B6C(6);
    for(i=5;i>0;i--) *(void **)(p+0x6c+4*i)=*(void **)(p+0x68+4*i);
    *(void **)(p+0x6c)=0;
}
