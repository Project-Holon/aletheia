/*
 * function: IRC_RANKING_RowDraw
 * address: 0x021B8A28
 * packet: pkt_ov106_021B8A28
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes follow the return, before 0x021B8A6C.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   IRC_RANKING_CopyBmpTiles 0x021B9298 thumb ov106
 *   IRC_RANKING_WriteRowScreen 0x021B8B5C thumb ov106
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
struct Bmp;
extern void IRC_RANKING_CopyBmpTiles(const struct Bmp *a, const struct Bmp *b, int x, int y, u16 sx, u16 sy, u16 w, u16 h);
extern void IRC_RANKING_WriteRowScreen(u8 *,u32,int,u8);
void IRC_RANKING_RowDraw(u32 *p,u32 a,u32 b,u16 c) {
    IRC_RANKING_CopyBmpTiles((const struct Bmp *)p[1],(const struct Bmp *)((u32)BMP_WIN_GetBmp((struct Descriptor *)a)),0,0,0,c,32,3);
    IRC_RANKING_WriteRowScreen((u8 *)p[7],b,c,(*(u32 *)(p[0]+4)<<7)>>24);
}
