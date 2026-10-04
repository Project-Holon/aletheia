/*
 * function: func_021BA2B0
 * address: 0x021BA2B0
 * packet: pkt_ov225_021BA2B0
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
#include "../include/Obj04652.h"
#include "../include/Obj26154.h"
#include "../include/Obj26155.h"
#include "../include/Obj26156.h"
#include "../include/Obj26157.h"
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
void func_021BA2B0(char *p)
{
    void *s;
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj26154 *)(*(char * *)&((struct Obj04652 *)p)->f0))->f18);
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj04652 *)p)->f14),0);
    s=func_02045EC0(*(struct MsgBank * *)&((struct Obj26155 *)(*(char * *)&((struct Obj04652 *)p)->f0))->f1C,2);
    func_0201C724(((struct Obj26156 *)(*(char * *)&((struct Obj04652 *)p)->f0))->f18,(unsigned)func_02045770(*(struct Descriptor * *)&((struct Obj04652 *)p)->f14),0,4,(unsigned)s,((struct Obj26157 *)(*(char * *)&((struct Obj04652 *)p)->f0))->fC,0x3c40);
    func_02045808(s);((struct Obj04652 *)p)->f1C=1;func_021BA240(p);
}
