/*
 * function: func_02210DA8
 * address: 0x02210DA8
 * packet: pkt_ov198_02210DA8
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Trailing 02210E1E halfword is zero alignment padding.
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02210F04 0x02210F04 thumb ov198
 *   func_02210F4C 0x02210F4C thumb ov198
 *   func_02210ED4 0x02210ED4 thumb ov198
 *   func_02210F98 0x02210F98 thumb ov198
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_022110D4(u8 *,int);
extern u32 func_02210F04(u32,u32);
extern int func_02210F4C(u8 *,int);
extern u8 func_02210ED4(u8 *);
extern int func_02210F98(u8 *,int);
int func_02210DA8(u8 *p)
{
    int index=func_022110D4(p,(*(u8 **)p)[32]);
    u8 *q=p+4+76*index;
    if(func_02210F04((u32)p,index)==1) return 1;
    if(*(u16 *)(q+16)==0) return 2;
    if(func_02210F4C(p,(*(u8 **)p)[32])==1) return 3;
    if(func_02210ED4(p)==1) return 5;
    if(func_02210F98(p,(*(u8 **)p)[32])==1) return 4;
    if(*(u16 *)(*(u8 **)p+38)!=0) return 6;
    return 0;
}
