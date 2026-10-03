/*
 * function: func_021BC338
 * address: 0x021BC338
 * packet: pkt_ov217_021BC338
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BC3D4 0x021BC3D4 thumb ov217
 *   func_021BC3E0 0x021BC3E0 thumb ov217
 *   func_02041EE4 0x02041EE4 arm
 */
typedef unsigned char u8;
typedef unsigned int   u32;
extern u32 func_021BC3D4(void);
extern u32 func_021BC3E0(void);
extern void func_02041EE4(unsigned layer,unsigned mode,unsigned value);
void func_021BC338(u8 *p)
{
    int position;
    int low;
    int high;
    position=*(int *)(p+0x34);
    low=func_021BC3D4();
    high=func_021BC3E0();
    if(position<low) {
        position-=24;
        func_02041EE4(2,3,position);
        func_02041EE4(3,3,position);
    } else if(high<position) {
        position-=168;
        func_02041EE4(2,3,position);
        func_02041EE4(3,3,position);
    }
}
