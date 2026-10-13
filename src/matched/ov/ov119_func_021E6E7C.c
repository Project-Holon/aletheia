/*
 * function: func_021E6E7C
 * address: 0x021E6E7C
 * packet: pkt_ov119_021E6E7C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetCharacterVramAddress 0x0204ABBC arm
 *   BMP_GetPixels 0x020437D4 arm
 *   BMP_GetByteSize 0x020437EC arm
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_0207E804 0x0207E804 arm
 *   d_021E7DD8 0x021E7DD8 data a1
 */
typedef unsigned char u8;
typedef struct { u8 v[8]; } Table;
extern const Table d_021E7DD8;
extern int CLACT_GetCharacterVramAddress(unsigned int idx, unsigned int flag);
typedef unsigned int   u32;
struct Bmp;
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern u32 BMP_GetByteSize(const struct Bmp *bmp);
extern void DWCi_ScreenDC_FlushRange(void *,int);
extern void func_0207E804(const void *,void *,unsigned int);
void func_021E6E7C(int p) {
    Table t=d_021E7DD8;
    int i,j;
    char *dest,*source;
    for(i=0;i<8;i++) {
        dest=(char *)CLACT_GetCharacterVramAddress(*(int *)(p+i*4+0x1114),1);
        source=BMP_GetPixels((const struct Bmp *)(*(int *)(p+i*4+0x10f4)));
        DWCi_ScreenDC_FlushRange(source,BMP_GetByteSize((const struct Bmp *)(*(int *)(p+i*4+0x10f4))));
        for(j=0;j<8;j++) {func_0207E804(source+t.v[j]*256,dest,256);dest+=256;}
    }
}
