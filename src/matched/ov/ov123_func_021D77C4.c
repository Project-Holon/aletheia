/*
 * function: GSYNC_STATE_StateMusicalSaveCreate
 * address: 0x021D77C4
 * packet: pkt_ov123_021D77C4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GSYNC_DOWNLOAD_GetFileBuffer 0x021D5BA0 thumb ov123
 *   GSYNC_STATE_ChangeState 0x021D6EE0 thumb ov123
 *   GSYNC_STATE_StateErrorMessage 0x021D6FF0 thumb ov123
 *   GSYNC_STATE_StateMusicalSaveApply 0x021D7798 thumb ov123
 *   GF_STANDARD_CalcCrc16 0x0203F1FC arm
 *   MUSICAL_DIST_SAVE_CreateFromData  0x0200C5C8  thumb  arm9
 */
#include "../include/Obj02837.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int GSYNC_DOWNLOAD_GetFileBuffer(char *p);
typedef unsigned int   u32;
extern u16 GF_STANDARD_CalcCrc16(const u8 *src, u32 len);
struct MusicalDist;
extern struct MusicalDist *MUSICAL_DIST_SAVE_CreateFromData(void *sys, const void *src, u32 size, u32 heap);
extern void GSYNC_STATE_ChangeState(u8 *p, u32 v, int unused);
extern void GSYNC_STATE_StateErrorMessage(char *p);
extern void GSYNC_STATE_StateMusicalSaveApply(u8 *p);
void GSYNC_STATE_StateMusicalSaveCreate(int a,int n)
{
    u8 *p;
    int h;
    u16 checksum;
    ((struct Obj02837 *)a)->fA4=0;
    p=(u8 *)GSYNC_DOWNLOAD_GetFileBuffer((char *)(((struct Obj02837 *)a)->f8));
    h=n/2;
    if(n>0x1fc0e) {
        ((struct Obj02837 *)a)->f80=0xfff0;
        GSYNC_STATE_ChangeState((u8 *)a,(int)GSYNC_STATE_StateErrorMessage,0x39d);
        return;
    }
    checksum=GF_STANDARD_CalcCrc16(p,n);
    if(checksum!=*(u16 *)(p+h*2)) {
        ((struct Obj02837 *)a)->f80=0xfff0;
        GSYNC_STATE_ChangeState((u8 *)a,(int)GSYNC_STATE_StateErrorMessage,0x3a3);
        return;
    }
    ((struct Obj02837 *)a)->fAE=1;
    ((struct Obj02837 *)a)->f30=(int)MUSICAL_DIST_SAVE_CreateFromData((void *)(((struct Obj02837 *)a)->f2C),p,n,((struct Obj02837 *)a)->f0);
    GSYNC_STATE_ChangeState((u8 *)a,(int)GSYNC_STATE_StateMusicalSaveApply,0x3a9);
}
