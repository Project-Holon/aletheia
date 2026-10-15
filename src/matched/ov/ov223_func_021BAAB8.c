/*
 * function: func_021BAAB8
 * address: 0x021BAAB8
 * packet: pkt_ov223_021BAAB8
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   file 0x021BCB00 data
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_LoadPltt 0x02040E78 arm
 *   BMP_Create 0x02043678 arm
 *   BMP_FillRect 0x02043AF4 arm
 *   BMP_GetPixels 0x020437D4 arm
 *   BMP_GetByteSize 0x020437EC arm
 *   BG_SYS_LoadTileData 0x02040B1C arm
 *   BMP_Delete 0x020437AC arm
 */
typedef unsigned short u16;
extern const char file[];
typedef unsigned int   u32;
struct Bmp;
struct Obj020437AC;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void BG_SYS_LoadPltt(unsigned,void *,unsigned,unsigned);
extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);
extern void BMP_FillRect(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern u32 BMP_GetByteSize(const struct Bmp *bmp);
extern void BG_SYS_LoadTileData(int index, const void *src, u32 size, u32 tile);
extern void BMP_Delete(struct Obj020437AC *p);
void func_021BAAB8(u16 *p)
{
    u16 *buffer;
    void *bmp,*data;
    unsigned size;
    buffer=func_02030734(*p,32,1,file,0x92B);
    buffer[0]=0;buffer[1]=0;buffer[2]=0x7FFF;
    BG_SYS_LoadPltt(2,buffer,32,0x1A0);
    BG_SYS_LoadPltt(6,buffer,32,0);
    func_020307B0(buffer);
    bmp=BMP_Create(2,1,32,*p);
    BMP_FillRect(bmp,0,0,8,8,0);
    BMP_FillRect(bmp,8,0,8,8,1);
    data=BMP_GetPixels(bmp);size=BMP_GetByteSize(bmp);
    BG_SYS_LoadTileData(2,data,size,0);
    data=BMP_GetPixels(bmp);size=BMP_GetByteSize(bmp);
    BG_SYS_LoadTileData(6,data,size,0);
    BMP_Delete(bmp);
}
