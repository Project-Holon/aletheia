/*
 * function: func_021BFFE0
 * address: 0x021BFFE0
 * packet: pkt_ov099_021BFFE0
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B97F4 0x021B97F4 thumb ov099
 *   func_021BE2A8 0x021BE2A8 thumb ov099
 *   func_021B9AE0 0x021B9AE0 thumb ov099
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   GFL_NET_STATE_WifiDisconnect 0x0203C554 arm
 *   func_021BDD0C 0x021BDD0C thumb ov099
 *   func_021B96CC 0x021B96CC thumb ov099
 *   func_021BE4F0 0x021BE4F0 thumb ov099
 *   func_021C19A8 0x021C19A8 thumb ov099
 *   func_021BAEDC 0x021BAEDC thumb ov099
 *   func_021C2408 0x021C2408 thumb ov099
 */
#include "../include/Obj00008.h"
extern int func_021B97F4(char *);
extern void *func_021BE2A8(char *,int);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021B9AE0(void *w, u8 *s);
extern void func_021BA8EC(char *);
extern void func_021C18C8(char *p, int kind, int value);
extern void GFL_NET_STATE_WifiDisconnect(u32 a);
extern void func_021BDD0C(void *p, int on);
extern int func_021B96CC(int *p);
extern int func_021BE4F0(char *,int);
extern void func_021C19A8(char *);
extern void func_021BAEDC(char *);
extern void func_021C2408(char *);
int func_021BFFE0(char *p,int ret) {
    if(++((struct Obj00008 *)p)->f1E0<=240)return ret;
    func_021B9AE0(p+0x274,func_021BE2A8(p,func_021B97F4(p+0x274)));
    func_021BA8EC(p);
    func_021C18C8(p,1,2);
    GFL_NET_STATE_WifiDisconnect(1);
    func_021BDD0C(p,0);
    if(!func_021B96CC((int *)(p+0x274))){
        ((struct Obj00008 *)p)->f1CC=func_021BE4F0(p,0);
    } else {
        func_021C19A8(p);
        func_021BAEDC(p);
        ((struct Obj00008 *)p)->f1F0=-1;
        ((struct Obj00008 *)p)->f1CC=11;
        func_021C2408(p);
    }
    return ret;
}
