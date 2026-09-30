/*
 * function: func_021B8734
 * address: 0x021B8734
 * packet: pkt_ov105_021B8734
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero padding before func_021B87E8
 * lever: u8 div and offset pin their home stores to the prologue
 * symbols:
 *   func_02061CA4 0x02061CA4 arm
 */
typedef unsigned char u8; typedef unsigned short u16;
extern void func_02061CA4(int,int,void *,int);
void func_021B8734(u16 *p,int n,u8 div,u8 offset,u8 index,u16 a,u16 b)
{
 u8 r,g,blue; int dr,dg,db;
 g=(a&0x3E0)>>5;
 r=a&31;
 blue=(a&0x7C00)>>10;
 db=((u8)((b&0x7C00)>>10)-blue)*n/div;
 dr=((u8)(b&31)-r)*n/div;
 dg=((u8)((b&0x3E0)>>5)-g)*n/div;
 *p=(u8)(r+dr)|((u8)(g+dg)<<5)|((u8)(blue+db)<<10);
 func_02061CA4(15,offset*32+index*2,p,2);
}
