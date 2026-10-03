/*
 * function: func_021D82D8
 * address: 0x021D82D8
 * packet: pkt_ov120_021D82D8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte zero alignment padding.
 * symbols:
 *   func_021D4F70 0x021D4F70 thumb ov120
 *   func_021D8118 0x021D8118 thumb ov120
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_021D4F70(void *,int);
extern void func_021D8118(char *,void *,int);
extern void func_02041B6C(int);
void func_021D82D8(char *p,void *q,int n)
{
    func_021D8118(p,func_021D4F70(q,n),0);
    func_02041B6C(6);
}
