/*
 * function: func_021BA30C
 * address: 0x021BA30C
 * packet: pkt_ov225_021BA30C
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_021BA240 0x021BA240 thumb ov225
 */
#include "../include/Obj04653.h"
#include "../include/Obj26158.h"
#include "../include/Obj26159.h"
#include "../include/Obj26160.h"
#include "../include/Obj26161.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct PrintSys;struct Descriptor;struct CharBuf;struct MsgBank;struct U16Vec;
extern void func_0201C6EC(struct PrintSys *);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern void *func_02045EC0(struct MsgBank *,unsigned);
extern void func_0201C724(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_02045808(struct U16Vec *);
extern void func_021BA240(char *);
void func_021BA30C(char *p)
{
    void *s;
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj26158 *)(*(char * *)&((struct Obj04653 *)p)->f0))->f18);
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj04653 *)p)->f14),0);
    s=func_02045EC0(*(struct MsgBank * *)&((struct Obj26159 *)(*(char * *)&((struct Obj04653 *)p)->f0))->f1C,3);
    func_0201C724(((struct Obj26160 *)(*(char * *)&((struct Obj04653 *)p)->f0))->f18,(unsigned)func_02045770(*(struct Descriptor * *)&((struct Obj04653 *)p)->f14),0,4,(unsigned)s,((struct Obj26161 *)(*(char * *)&((struct Obj04653 *)p)->f0))->fC,0x3c40);
    func_02045808(s);((struct Obj04653 *)p)->f1C=1;func_021BA240(p);
}
