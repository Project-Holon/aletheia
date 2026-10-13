/*
 * function: func_021FCF54
 * address: 0x021FCF54
 * packet: pkt_ov186_021FCF54
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 80-byte scrolling follower filed as ov186_func_021FCF90.c.
 * lever: width-first multiply preserves the stack load and register order.
 * symbols:
 *   BMP_GetPixels 0x020437D4 arm
 *   MIi_CpuCopy32 0x02082A90 arm
 */
struct Bmp;
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern void MIi_CpuCopy32(void *,const void *,unsigned);
void func_021FCF54(int dest,int src,int dx,int dy,unsigned short sx,unsigned short sy,unsigned short width,unsigned short height)
{
    char *d,*s;
    int doff,soff;
    d=BMP_GetPixels((const struct Bmp *)dest);s=BMP_GetPixels((const struct Bmp *)src);
    doff=width*dy+dx;
    soff=width*sy+sx;
    MIi_CpuCopy32(d+doff*32,s+soff*32,width*height*32);
}
