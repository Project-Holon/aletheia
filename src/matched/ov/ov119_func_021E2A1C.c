/*
 * function: func_021E2A1C
 * address: 0x021E2A1C
 * packet: pkt_ov119_021E2A1C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021DD2F4 0x021DD2F4 thumb ov119
 *   func_021B6558 0x021B6558 thumb ov067
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj00001.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern int func_021DD2F4(char *);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void func_02041B6C(u32 bit);
void func_021E2A1C(char *p,int a,int b) {
    if (!func_0201C6B4(((struct Obj00001 *)p)->f740)) func_0201C6EC(((struct Obj00001 *)p)->f740);
    if(a) func_0204B3DC(((struct Obj00001 *)p)->fF04,1);
    if(b) func_021B6558((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),8,func_021DD2F4(p));
    if(((struct Obj00001 *)p)->f648) {
        APP_TASKMENU_WIN_Delete(((struct Obj00001 *)p)->f648);
        ((struct Obj00001 *)p)->f648=0;
        func_02041B6C(6);
    }
}
