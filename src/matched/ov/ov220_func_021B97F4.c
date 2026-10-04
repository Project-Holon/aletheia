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
 * func_02005E50 0x02005E50 thumb
 * func_02005DE4 0x02005DE4 thumb
 * func_02005E64 0x02005E64 thumb
 * func_02005D90 0x02005D90 thumb
 * func_0204E720 0x0204E720 arm
 * func_0204E804 0x0204E804 arm
 * func_02005F38 0x02005F38 thumb
 * func_02005E9C 0x02005E9C thumb
 * func_02005DF8 0x02005DF8 thumb
 * func_020362DC 0x020362DC arm
 * func_020355D8 0x020355D8 arm
 * func_02035D20 0x02035D20 arm
 * func_0201C4E4 0x0201C4E4 thumb
 * func_02045334 0x02045334 arm
 * func_02045374 0x02045374 arm
 * func_02045730 0x02045730 arm
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
extern int func_02005E50(void),func_02005E64(void),func_02005E9C(void),func_02005F38(void),func_0204E804(void);
extern void func_02005DE4(void*),func_02005D90(u32,u16),func_02005DF8(u32);
extern void func_0204E720(u32,int,int,int);
extern u32 func_020362DC(void),func_02035D20(u32*,u32*),func_0201C4E4(void*);
struct Descriptor;
extern void func_020355D8(u8),func_02045334(struct Descriptor *),func_02045374(void*),func_02041B6C(u32);
extern u8 func_02045730(struct Descriptor *p);
extern void func_021BA01C(void*),func_021BA1CC(char*);
int func_021B97F4(void *unused, u32 *state, void *unused2, char *p)
{
    u32 x,y;
    u8 i;
    int flag;
    switch (*state) {
    case 0:
        flag=1;
        if (((struct Obj26059 *)(*(char * *)&((struct Obj03379 *)p)->f4))->fC && ((struct Obj03379 *)p)->fB0!=7) {
            if (func_02005E50()) flag=0;
            else {
                func_02005DE4((void *)1);
                func_02005E64();
                func_02005D90(*(const u32 *)((u32)sounds+((struct Obj03379 *)p)->fB0*12),0xFFFF);
            }
        }
        if (flag) {func_0204E720(3,16,0,0);*state=1;}
        break;
    case 1:
        if (!func_0204E804()) {
            if (((struct Obj26060 *)(*(char * *)&((struct Obj03379 *)p)->f4))->fC && ((struct Obj03379 *)p)->fB0!=7) *state=2;
            else *state=3;
        }
        break;
    case 2:
        if (!func_02005F38()) {
            func_02005E9C();func_02005DE4(0);func_02005DF8(6);*state=3;
        }
        break;
    case 3:
        flag=0;
        if (func_020362DC()&3) {func_020355D8(0);flag=1;}
        else if (func_02035D20(&x,&y)) {func_020355D8(1);flag=1;}
        if (flag) {*state=4;func_0204E720(3,0,16,0);}
        break;
    case 4:
        if (!func_0204E804()) *state=5;
        break;
    case 5:return 1;
    }
    if (func_0201C4E4(((struct Obj03379 *)p)->f10) && !((struct Obj03379 *)p)->f80) {
        for (i=1;i<4;i++) {
            void *v=*(void **)((u32)p+(u32)i*4+0x60);
            func_02045334(v);func_02045374(v);func_02041B6C(func_02045730(v));
        }
        ((struct Obj03379 *)p)->f80=1;
    }
    func_021BA01C(p);
    func_021BA1CC(*(char * *)&((struct Obj03379 *)p)->f8);
    return 0;
}
void func_021B995C(void) {}
