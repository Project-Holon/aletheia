/*
 * function: func_021C5300
 * address: 0x021C5300
 * packet: pkt_ov127_021C5300
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C49A4 0x021C49A4 thumb ov127
 *   func_021C4A00 0x021C4A00 thumb ov127
 */
typedef unsigned char u8;
extern int func_021C49A4(u8 *,unsigned);
extern void func_021C4A00(void *,int,int);
int func_021C5300(u8 *p)
{
 int a=func_021C49A4(p,8), b=func_021C49A4(p,9);
 if(a<b) { func_021C4A00(p,8,a+1); if(a+1<b) return 0; }
 return 1;
}
