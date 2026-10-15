/*
 * function: func_021BAB78
 * address: 0x021BAB78
 * packet: pkt_ov223_021BAB78
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: cast the whole ternary to u16; declare col,row before index.
 * symbols:
 *   file 0x021BCB00 data
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern const char file[];
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void BG_SYS_DrawTile(unsigned,unsigned,unsigned,unsigned,u8,u8);
extern void func_02041B6C(unsigned);
void func_021BAB78(u16 *p)
{
    u8 col,row;
    u16 *buffer,index;
    buffer=func_02030734(*p,1536,1,file,0x951);
    index=0;
    for(row=0;row<24;row++) {
        for(col=0;col<32;col++) {
            u16 tile;
            tile=(u16)((row>=4 && row<20)?1:0);
            buffer[index]=tile|0xD000;
            index++;
        }
    }
    BG_SYS_DrawTile(2,(unsigned)buffer,0,0,32,24);
    func_02041B6C(2);
    func_020307B0(buffer);
}
