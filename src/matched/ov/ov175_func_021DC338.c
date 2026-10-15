/*
 * function: func_021DC338
 * address: 0x021DC338
 * packet: pkt_ov175_021DC338
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * lever: case-local repeated error call+break reproduces merged error block and long-branch layout; tail goto displaced it.
 * extent: unlabelled28-byte zero-word test021DC5AC filed separately.
 * symbols:
 *   DWC_NdInitAsync 0x021C5928 arm ov114
 *   DWC_NdSetAttr 0x021C5C04 arm ov114
 *   DWC_NdGetFileListAsync 0x021C5C38 arm ov114
 *   DWC_NdGetFileAsync 0x021C5CFC arm ov114
 *   DWC_NdCleanupAsync 0x021C5B80 arm ov114
 *   DWC_NdProcess 0x021C5AB8 arm ov114
 *   DWC_NdGetProgress 0x021C5E14 arm ov114
 *   func_021DC680 0x021DC680 thumb ov175
 *   func_021DC5AC 0x021DC5AC thumb ov175
 *   func_021DC6A4 0x021DC6A4 thumb ov175
 *   func_021DC6D0 0x021DC6D0 thumb ov175
 *   func_021DC6FC 0x021DC6FC thumb ov175
 *   GFL_NET_STATE_SetError 0x0203C9AC arm
 *   func_0200FA84 0x0200FA84 thumb
 *   REGULATION_Card_IsCrcValid 0x0200B1A8 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021E4B80 0x021E4B80 data a4
 *   d_021E2FA8 0x021E2FA8 data a4
 *   d_021E2FB0 0x021E2FB0 data a4
 *   d_021E2FC4 0x021E2FC4 data a4
 *   d_021E2EF8 0x021E2EF8 data a4
 */
#include "../include/Obj00841.h"
typedef unsigned char u8;
typedef unsigned long u32;
extern int DWC_NdInitAsync(void (*callback)(int, int, int), char *gamecd, char *passwd);
extern int DWC_NdSetAttr(char *,char *,char *);
extern int DWC_NdGetFileListAsync(void *,unsigned int,unsigned int);
extern int DWC_NdGetFileAsync(void *,char *,unsigned int);
extern int DWC_NdCleanupAsync(void);
extern void DWC_NdProcess(void);
extern int DWC_NdGetProgress(u32 *,u32 *);
extern void func_021DC680(u8 *,int);
extern int func_021DC5AC(const unsigned int *,unsigned int);
extern void func_021DC6A4(u8 *,int);
extern void func_021DC6D0(u8 *,int);
extern void func_021DC6FC(void *p, u32 kind);
extern void GFL_NET_STATE_SetError(int,u32,u32,u32);
extern void func_0200FA84(void);
struct Reg2;
extern unsigned int REGULATION_Card_IsCrcValid(struct Reg2 *);
extern u32 _u32_div_f(u32,u32);
extern u8 d_021E4B80[];
extern char d_021E2FA8[],d_021E2FB0[],d_021E2FC4[],d_021E2EF8[];
int func_021DC338(u8 *p)
{
    u32 count,percent;
    switch(((struct Obj00841 *)p)->f12C) {
    case 0:
        if(DWC_NdInitAsync((void (*)(int,  int,  int))func_021DC6FC,d_021E2FA8,d_021E2FB0)==0)return 3;
        ((struct Obj00841 *)p)->f1458=1;
        func_021DC680(p,1);break;
    case 1:
        if(DWC_NdSetAttr(d_021E2FC4,(char *)(p+0x144c),d_021E2EF8)==0){func_021DC6A4(p,8);break;}
        ((struct Obj00841 *)p)->f12C=2;break;
    case 2:
        if(DWC_NdGetFileListAsync(p+0x1390,0,1)==0){func_021DC6A4(p,8);break;}
        func_021DC680(p,3);break;
    case 3:
        count=0xb0;
        if(func_021DC5AC((const unsigned int *)(p+0x1390),0xb0)==0) {
            count+=0xb0;
            if(DWC_NdGetFileAsync(p+0x1390,(char *)(p+0x1230),count)==0){func_021DC6A4(p,8);break;}
            d_021E4B80[0]=0;*(u32 *)(d_021E4B80+4)=0;
            ((struct Obj00841 *)p)->f12C=4;
        } else {
            if(DWC_NdCleanupAsync()==0) {((struct Obj00841 *)p)->f1458=0;return 2;}
            func_021DC680(p,7);
        }
        break;
    case 4:
        DWC_NdProcess();
        if((((struct Obj00841 *)p)->f1A0)++>7200) {GFL_NET_STATE_SetError(0,0,0,0x3f7);func_021DC6D0(p,8);}
        if(d_021E4B80[0]==0) {
            if(DWC_NdGetProgress((u32 *)(p+0x1444),(u32 *)(p+0x1448))==1) {
                percent=_u32_div_f(((struct Obj00841 *)p)->f1444*100,((struct Obj00841 *)p)->f1448);
                if(((struct Obj00841 *)p)->f1440!=percent)((struct Obj00841 *)p)->f1440=percent;
            }
        } else {
            if(*(u32 *)(d_021E4B80+4)!=0) {
                if(*(u32 *)(d_021E4B80+4)==8)func_0200FA84();
                else func_021DC6A4(p,8);
            } else {
                if(DWC_NdCleanupAsync()==0) {((struct Obj00841 *)p)->f1458=0;return 3;}
                func_021DC680(p,5);
            }
        }
        break;
    case 5:((struct Obj00841 *)p)->f12C=6;break;
    case 6:
        if(REGULATION_Card_IsCrcValid((struct Reg2 *)(p+0x1230))!=0) {((struct Obj00841 *)p)->f1458=0;return 1;}
        ((struct Obj00841 *)p)->f1458=0;return 2;
    case 7:((struct Obj00841 *)p)->f1458=0;return 2;
    case 8:((struct Obj00841 *)p)->f1458=0;return 3;
    case 100:
        DWC_NdProcess();
        if((((struct Obj00841 *)p)->f1A0)++>7200) {GFL_NET_STATE_SetError(0,0,0,0x3f7);func_021DC6D0(p,8);}
        if(*(u32 *)(d_021E4B80+4)!=0) {
            if(*(u32 *)(d_021E4B80+4)==8)func_0200FA84();
            else func_021DC6A4(p,8);
        }
        if(d_021E4B80[0]!=0) {
            d_021E4B80[0]=0;
            if(*(u32 *)(d_021E4B80+4)==0)((struct Obj00841 *)p)->f12C=((struct Obj00841 *)p)->f130;
        }
        break;
    case 200:
        DWC_NdProcess();
        if(d_021E4B80[1]!=0) {d_021E4B80[1]=0;((struct Obj00841 *)p)->f12C=((struct Obj00841 *)p)->f130;}
        break;
    case 300:
        DWC_NdProcess();
        if(d_021E4B80[0]!=0) {d_021E4B80[0]=0;func_021DC6A4(p,((struct Obj00841 *)p)->f130);}
        break;
    }
    return 0;
}
