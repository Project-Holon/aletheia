/*
 * function: func_021DA064
 * address: 0x021DA064
 * packet: pkt_ov119_021DA064
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 *   func_021E4E64 0x021E4E64 thumb ov119
 */
#include "../include/Obj00001.h"

typedef unsigned int u32;

typedef unsigned char  u8;
extern int func_021E12AC(char *p);
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern int TOUCHPANEL_GetTrg(void);
extern void func_021E1098(char *p);
extern void func_021D8E84(void *,int);
extern void func_021DBE70(char *p);
extern void func_021E4E64(int a, char *p, int b);
void func_021DA064(char *p) {
    int v;
    if (func_021E12AC(p)) {
        v=func_020362DC();
        if(v) func_020355D8(0);
        if(!v) {
            v=TOUCHPANEL_GetTrg();
            if(v) func_020355D8(1);
            if(!v) return;
        }
        ((struct Obj00001 *)p)->fF80=-1;
        ((struct Obj00001 *)p)->fF7C=-1;
        func_021E1098(p);
        func_021D8E84(p,(int)func_021DBE70);
        ((struct Obj00001 *)p)->f1080=-1;
        func_021E4E64(*(int *)&((struct Obj00001 *)p)->f828,p,1);
    }
}
