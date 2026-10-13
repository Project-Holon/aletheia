/*
 * function: func_021DE3E8
 * address: 0x021DE3E8
 * packet: pkt_ov119_021DE3E8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 02035C08 return is consumed in r0; full 02035BBC forwarding body returns int, as in matched 021D98AC.
 * symbols:
 *   func_02040588 0x02040588 arm
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfPressing 0x021B6470 thumb ov067
 *   WIPE_SYS_Start 0x0202208C thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DE2C4 0x021DE2C4 thumb ov119
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_021E80C4 0x021E80C4 data a4
 *   func_020355D8 0x020355D8 arm
 *   func_021E68F4 0x021E68F4 thumb ov119
 *   func_021DE1B4 0x021DE1B4 thumb ov119
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   func_021DE3BC 0x021DE3BC thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   KEY_GetTrg 0x020362DC arm
 *   func_021DE208 0x021DE208 thumb ov119
 */
#include "../include/Obj00251.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct S S;
typedef struct { char pad[0xfd8]; int obj[2][3]; } State;
extern void func_02040588(unsigned char which, unsigned char enable);
extern unsigned WIPE_SYS_EndCheck(void);
extern void TOUCHBAR_Update(struct S *p);
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *),TOUCHBAR_GetPressedButtonIdIfPressing(u8 *);
extern void WIPE_SYS_Start(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern void func_021D8E84(void *,int);
extern void func_021DE2C4(char *);
extern void func_021DE3BC(char *p);
extern int TOUCHPANEL_HitTrg(const void *);
extern const char d_021E80C4[];
extern void func_020355D8(u8);
extern void func_021E68F4(int,int);
extern void func_021DE1B4(State *,int);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern u8 func_020355C4(void);
extern u32 KEY_GetTrg(void);
extern int func_021DE208(char *);
static inline int poll(void) { int v=KEY_GetTrg(); if(v)func_020355D8(0); return v; }
void func_021DE3E8(char *p)
{
    int idx;
    func_02040588(3,1);
    if(WIPE_SYS_EndCheck()) {
        TOUCHBAR_Update(*(S * *)&((struct Obj00251 *)p)->f9C0);
        if(TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((struct Obj00251 *)p)->f9C0)==1) {
            WIPE_SYS_Start((void *)3,0,0,0,6,1,((struct Obj00251 *)p)->f5F4);
            func_021D8E84(p,(int)func_021DE2C4);
            return;
        }
        if(TOUCHBAR_GetPressedButtonIdIfPressing(*(u8 * *)&((struct Obj00251 *)p)->f9C0)==-1) {
            idx=TOUCHPANEL_HitTrg(d_021E80C4);
            if(idx!=-1) {
                func_020355D8(1);
                ((struct Obj00251 *)p)->f10A0=idx;
                func_021E68F4((int)p,-1);
                func_021DE1B4((State *)p,((struct Obj00251 *)p)->f10A0);
                GFL_USE_PlaySeDefaultVolume(0x548);
                ((struct Obj00251 *)p)->fF2C=0;
                func_021D8E84(p,(int)func_021DE3BC);
                return;
            }
            if(func_020355C4() && poll()) {
                func_020355D8(0);
                func_021E68F4((int)p,((struct Obj00251 *)p)->f10A0);
                GFL_USE_PlaySeDefaultVolume(0x548);
                ((struct Obj00251 *)p)->fF2C=0;
                func_021D8E84(p,(int)func_021DE3BC);
                return;
            }
            if(func_021DE208(p)) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                func_021E68F4((int)p,((struct Obj00251 *)p)->f10A0);
                func_021DE1B4((State *)p,((struct Obj00251 *)p)->f10A0);
                ((struct Obj00251 *)p)->fF2C=0;
                func_021D8E84(p,(int)func_021DE3BC);
            }
        }
    }
}
