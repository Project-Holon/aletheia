/*
 * function: func_021FA3A8
 * address: 0x021FA3A8
 * packet: pkt_ov132_021FA3A8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * ABI: 41300 caller truncates tile to u16 and coordinates to u8 before each call.
 * symbols:
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   table 0x021FDC16 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 table[];
extern void func_02041300(u32,u16,u8,u8,u8,u8,u8);
extern void func_02041B6C(u32);
void func_021FA3A8(char *p,u8 *rec,unsigned type)
{
    u16 tile;
    int reverse=0;
    u8 row,col,x;
    u32 t;
    switch(type) {
    case 3: reverse=1; tile=*(u16 *)((u32)table+rec[2]*2)+0x400; break;
    case 2: reverse=1; tile=*(u16 *)((u32)table+rec[2]*2)+0x404; break;
    case 1: tile=*(u16 *)((u32)table+rec[2]*2)+4; break;
    case 0: tile=*(u16 *)((u32)table+rec[2]*2); break;
    }
    for(row=0;row<4;row++) {
        for(col=0;col<4;col++) {
            if(reverse==1) x=3-col+rec[6]*4;
            else x=col+rec[6]*4;
            t=tile+col+row*32;
            func_02041300(4,tile+col+row*32,x,row+rec[7]*4+2,1,1,0);
            func_02041300(6,t,x,row+rec[7]*4+5,1,1,0);
        }
    }
    func_02041B6C(4);
    func_02041B6C(6);
}
