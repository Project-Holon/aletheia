/*
 * function: func_021BAC70
 * address: 0x021BAC70
 * packet: pkt_ov223_021BAC70
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: shared loop roles plus the bounded permuter's n/x declaration exchange fixes the remaining register allocation.
 * symbols:
 *   site 0x021BCB00 data a4
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern const char site[];
extern void *func_02030734(u32,u32,int,const char *,u16);
extern u32 func_020307B0(void *p);
extern void BG_SYS_DrawTile(u32,u32,u32,u32,u8,u8);
extern void func_02041B6C(u32);
void func_021BAC70(const u16 *p)
{
    u16 *buffer;
    u8 x;
    u16 v;
    u8 y;
    u16 n;
    buffer=func_02030734(*p,1536,1,site,2463);
    n=0;
    for(y=0;y<24;y++)for(x=0;x<32;x++) {
        v=(y>=17&&y<23)?1:0;
        buffer[n]=v|0xd000;
        n++;
    }
    BG_SYS_DrawTile(2,(u32)buffer,0,0,32,24);
    func_02041B6C(2);func_020307B0(buffer);
    buffer=func_02030734(*p,1536,1,site,2488);
    n=0;
    for(x=0;x<24;x++)for(y=0;y<32;y++) {
        v=(x>=17&&x<23)?1:0;
        buffer[n]=v;
        n++;
    }
    BG_SYS_DrawTile(6,(u32)buffer,0,0,32,24);
    func_02041B6C(6);func_020307B0(buffer);
}
