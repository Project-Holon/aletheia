/*
 * function: func_0220B4B8
 * address: 0x0220B4B8
 * packet: pkt_ov197_0220B4B8
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: assign the doubled index after the flag branch; the flag is unsigned byte evidence.
 * symbols:
 *   func_0220B31C 0x0220B31C thumb ov197
 *   func_0220B3EC 0x0220B3EC thumb ov197
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_0220B31C(char *p, u32 i, int id, int w, int unused, int unused2);
extern void func_0220B3EC(char *p, u32 i, int id, int w, int unused, int y, int unused2);
void func_0220B4B8(char *p,u16 i)
{
    int base=*(short *)(*(char **)p+((u8 *)p)[0x533]*2+0x38)*6;
    int row=5;
    int twice;
    if(((u8 *)p)[0x141]!=0)row=0x11;
    twice=i*2;
    func_0220B31C(p,i+base,i,row+twice,0,0);
    func_0220B3EC(p,i+base,i,row+1+twice,0,4,0);
}
