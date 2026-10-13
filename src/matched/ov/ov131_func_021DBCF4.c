/*
 * function: P_STA_OAM_TransferBitmap
 * address: 0x021DBCF4
 * packet: pkt_ov131_021DBCF4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note (2026-10-02): seg is assigned with if/else (a ternary makes it a temp below the named
 *   locals), and seg is declared before edge (last declared lowest).
 * symbols:
 *   BMP_GetPixels 0x020437D4 arm
 *   BMP_GetByteSize 0x020437EC arm
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   BMP_GetWidth 0x020437DC arm
 *   BMP_GetHeight 0x020437E4 arm
 *   CLACT_GetCharacterVramAddress 0x0204ABBC arm
 *   func_0207E780 0x0207E780 arm
 *   func_0207E804 0x0207E804 arm
 */
#include "../include/Obj02191.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
struct Bmp;
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern u32 BMP_GetByteSize(const struct Bmp *bmp);
extern void DWCi_ScreenDC_FlushRange(void *,int);
extern u16 BMP_GetWidth(const struct Bmp *bmp);
extern u16 BMP_GetHeight(const struct Bmp *bmp);
extern int CLACT_GetCharacterVramAddress(u32 idx, u32 flag);
extern void func_0207E780(void *,void *,u32);
extern void func_0207E804(void *,void *,u32);
void P_STA_OAM_TransferBitmap(u8 *p)
{
    u8 *dst0;
    int c,r;
    u32 off,seg,edge;
    int rem;
    u32 wt;
    u8 *src;
    u8 k;
    void (*fn)(void *,void *,u32);
    dst0=BMP_GetPixels(((struct Obj02191 *)p)->f0);
    DWCi_ScreenDC_FlushRange(dst0,BMP_GetByteSize(((struct Obj02191 *)p)->f0));
    if(((struct Obj02191 *)p)->f10==0) fn=func_0207E780; else fn=func_0207E804;
    wt=(u32)BMP_GetWidth(((struct Obj02191 *)p)->f0)>>3;
    rem=(u32)BMP_GetHeight(((struct Obj02191 *)p)->f0)>>3;
    rem=rem%4;
    edge=BMP_GetWidth(((struct Obj02191 *)p)->f0)%64/8*32;
    if(edge==0) edge=256;
    off=0;
    for(r=0;r<p[0x23];r++) {
        for(c=0;c<p[0x22];c++) {
            if(c==p[0x22]-1) seg=edge; else seg=256;
            src=(u8 *)CLACT_GetCharacterVramAddress((u32)(*(void **)(p+0x14+(c+r*p[0x22])*4)),((struct Obj02191 *)p)->f10);
            for(k=0;k<4;k++) {
                if(r==p[0x23]-1 && rem!=0 && k>=rem) continue;
                fn(dst0+(off+k*(wt*32)),src,seg);
                src+=256;
            }
            off+=seg;
        }
        off+=wt*32;
    }
}
