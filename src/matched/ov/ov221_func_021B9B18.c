/*
 * unit: yes
 * function: CHIHOU_ZUKAN_AWARD_FlushWindows, CHIHOU_ZUKAN_AWARD_IsWindowsReady
 * address: 0x021B9B18
 * packet: pkt_ov221_021B9B18
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj02558.h"
#include "../include/Obj08453.h"
struct Descriptor; struct Cfg; struct PrintSys;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern unsigned PRINTSYS_QUE_IsExistTarget(struct PrintSys *,void *);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern unsigned char BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_02041B6C(unsigned);
void CHIHOU_ZUKAN_AWARD_FlushWindows(unsigned char *p)
{
    unsigned char i;
    unsigned char *row;
    struct Descriptor *resource;
    for(i=0;i<5;i++) {
        row=p+4*i;
        if(((struct Obj08453 *)row)->f30==0 && PRINTSYS_QUE_IsExistTarget(*(struct PrintSys * *)&((struct Obj02558 *)p)->f10,BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj08453 *)row)->f1C))==0) {
            resource=*(struct Descriptor * *)&((struct Obj08453 *)row)->f1C;
            BMP_WIN_TransferChars(resource);
            BMP_WIN_MakeScreen((struct Cfg *)resource);
            func_02041B6C(BMP_WIN_GetBgLayer(resource));
            ((struct Obj08453 *)row)->f30=1;
        }
    }
}
int CHIHOU_ZUKAN_AWARD_IsWindowsReady(unsigned char *p)
{
    unsigned char i;
    for(i=0;i<5;i++) if(*(int *)(p+0x30+4*i)==0) return 0;
    return 1;
}
