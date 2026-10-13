/*
 * unit: yes
 * function: func_021B97F4, func_021B995C
 * address: 0x021B97F4
 * packet: pkt_ov220_021B97F4
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * follower: 021B995C is the unlabelled bx-lr stub in the handed extent; final two zero bytes are alignment.
 * prototype: 02005E64/E9C legacy four parameters are never read or forwarded at entry; both first call the argless 02005FBC.
 * symbols:
 * GFL_USE_IsBgmFading 0x02005E50 thumb
 * GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 * GFL_USE_PushBgm 0x02005E64 thumb
 * GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 * FADE_Start 0x0204E720 arm
 * FADE_IsActive 0x0204E804 arm
 * GFL_USE_IsBgmPlaying 0x02005F38 thumb
 * GFL_USE_PopBgm 0x02005E9C thumb
 * GFL_USE_FadeInBgmFull 0x02005DF8 thumb
 * KEY_GetTrg 0x020362DC arm
 * func_020355D8 0x020355D8 arm
 * TOUCHPANEL_GetPointTrg 0x02035D20 arm
 * PRINTSYS_QUE_Main 0x0201C4E4 thumb
 * BMP_WIN_TransferChars 0x02045334 arm
 * BMP_WIN_MakeScreen 0x02045374 arm
 * BMP_WIN_GetBgLayer 0x02045730 arm
 * func_02041B6C 0x02041B6C arm
 * func_021BA01C 0x021BA01C thumb ov220
 * func_021BA1CC 0x021BA1CC thumb ov220
 * sounds 0x021BA3B0 data a4
 */
#include "../include/Obj03379.h"
#include "../include/Obj26059.h"
#include "../include/Obj26060.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u32 sounds[];
extern int GFL_USE_IsBgmFading(void),GFL_USE_PushBgm(void),GFL_USE_PopBgm(void),GFL_USE_IsBgmPlaying(void),FADE_IsActive(void);
extern void GFL_USE_SetBgmPlayerParam(void*),GFL_USE_CancelChangeAndPlayBgm(u32,u16),GFL_USE_FadeInBgmFull(u32);
extern void FADE_Start(u32,int,int,int);
struct Cfg;
struct Obj;
struct PrintSys;
extern u32 KEY_GetTrg(void);
extern u32 TOUCHPANEL_GetPointTrg(u32*,u32*);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
struct Descriptor;
extern void func_020355D8(u8);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_021BA01C(struct Obj *o);
extern void func_021BA1CC(char*);
int func_021B97F4(void *unused, u32 *state, void *unused2, char *p)
{
    u32 x,y;
    u8 i;
    int flag;
    switch (*state) {
    case 0:
        flag=1;
        if (((struct Obj26059 *)(*(char * *)&((struct Obj03379 *)p)->f4))->fC && ((struct Obj03379 *)p)->fB0!=7) {
            if (GFL_USE_IsBgmFading()) flag=0;
            else {
                GFL_USE_SetBgmPlayerParam((void *)1);
                GFL_USE_PushBgm();
                GFL_USE_CancelChangeAndPlayBgm(*(const u32 *)((u32)sounds+((struct Obj03379 *)p)->fB0*12),0xFFFF);
            }
        }
        if (flag) {FADE_Start(3,16,0,0);*state=1;}
        break;
    case 1:
        if (!FADE_IsActive()) {
            if (((struct Obj26060 *)(*(char * *)&((struct Obj03379 *)p)->f4))->fC && ((struct Obj03379 *)p)->fB0!=7) *state=2;
            else *state=3;
        }
        break;
    case 2:
        if (!GFL_USE_IsBgmPlaying()) {
            GFL_USE_PopBgm();GFL_USE_SetBgmPlayerParam(0);GFL_USE_FadeInBgmFull(6);*state=3;
        }
        break;
    case 3:
        flag=0;
        if (KEY_GetTrg()&3) {func_020355D8(0);flag=1;}
        else if (TOUCHPANEL_GetPointTrg(&x,&y)) {func_020355D8(1);flag=1;}
        if (flag) {*state=4;FADE_Start(3,0,16,0);}
        break;
    case 4:
        if (!FADE_IsActive()) *state=5;
        break;
    case 5:return 1;
    }
    if (PRINTSYS_QUE_Main(((struct Obj03379 *)p)->f10) && !((struct Obj03379 *)p)->f80) {
        for (i=1;i<4;i++) {
            void *v=*(void **)((u32)p+(u32)i*4+0x60);
            BMP_WIN_TransferChars(v);BMP_WIN_MakeScreen(v);func_02041B6C(BMP_WIN_GetBgLayer(v));
        }
        ((struct Obj03379 *)p)->f80=1;
    }
    func_021BA01C((struct Obj *)p);
    func_021BA1CC(*(char * *)&((struct Obj03379 *)p)->f8);
    return 0;
}
void func_021B995C(void) {}
