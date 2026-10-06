/*
 * function: func_021DD5B4
 * address: 0x021DD5B4
 * packet: pkt_ov119_021DD5B4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_021D8D4C 0x021D8D4C thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021DD428 0x021DD428 thumb ov119
 *   func_021DF9E8 0x021DF9E8 thumb ov119
 *   func_021DD4F4 0x021DD4F4 thumb ov119
 *   func_020307B0 0x020307B0 arm
 *   func_020173EC 0x020173EC thumb
 *   func_021E6334 0x021E6334 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned int   u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern void *func_021D8D4C(void **a, int b, int c, char *p);
extern int func_021D8A24(void *);
struct S119DD4F4;
struct State;
extern int func_021DD428(struct State *p, int side, int a, int b, void *value);
extern int func_021DF9E8(char *,void *,int);
extern void func_021DD4F4(struct S119DD4F4 *p, int i, int j);
extern void func_020307B0(void *);
extern u32 func_020173EC(void);
extern void func_021E6334(char *p, int i, int j, void *mon, int selected, u32 visible);
int func_021DD5B4(char *p,int a,int b)
{
    int value,slot;
    unsigned i;
    func_020399A8();
    value=(int)func_021D8D4C(*(void ** *)&((struct Obj00001 *)p)->f828,((struct Obj00001 *)p)->fF88,((struct Obj00001 *)p)->fF84,p);
    if(func_021D8A24(p)) {
        i=0;
        slot=func_021DD428((struct State *)p,0,a,b,(void *)value);
        if(slot!=-1) {
            if(func_021DF9E8(p,*(void **)(p+slot*4+0xfd8),slot+0xc07)==0) {
                func_021DD4F4((struct S119DD4F4 *)p,0,slot);
                func_020307B0((void *)value);
                return 0;
            }
            for(i=0;i<(unsigned)func_020173EC();i++) {}
        }
    } else {
        slot=func_021DD428((struct State *)p,0,a,b,(void *)value);
    }
    if(slot==-1) {func_020307B0((void *)value);return 1;}
    func_021E6334(p,0,slot,(void *)value,1,0);
    func_020307B0((void *)value);
    return 1;
}
