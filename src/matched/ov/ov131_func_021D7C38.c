/*
 * function: func_021D7C38
 * address: 0x021D7C38
 * packet: pkt_ov131_021D7C38
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_020450F0 0x020450F0 arm
 *   d_021DC288 0x021DC288 data a1
 *   func_021D7F04 0x021D7F04 thumb ov131
 *   func_021D8288 0x021D8288 thumb ov131
 */

extern void *func_021D6064(void *);
extern void *func_020450F0(unsigned int,unsigned int,unsigned int,unsigned int,unsigned char,unsigned char,unsigned char);
extern const unsigned char d_021DC288[];
extern void func_021D7F04(void *,unsigned char *,void *);
extern void func_021D8288(void *,unsigned char *,void *);
void func_021D7C38(void *a, unsigned char *p)
{
    void *arc=func_021D6064(a);
    unsigned char i;
    for(i=0;i<10;i++) {
        unsigned int offset=i*4;
        *(void **)(p+offset+0xc)=func_020450F0(1,d_021DC288[offset],d_021DC288[offset+1],d_021DC288[offset+2],d_021DC288[offset+3],14,1);
    }
    *(void **)(p+0x34)=func_020450F0(4,4,5,24,20,14,1);
    func_021D7F04(a,p,arc);
    func_021D8288(a,p,arc);
    *(int *)(p+4)=1;
}
