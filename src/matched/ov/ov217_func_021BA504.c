/*
 * function: func_021BA504
 * address: 0x021BA504
 * packet: pkt_ov217_021BA504
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 021BA55E..021BA560 zero alignment padding.
 * symbols:
 *   func_021BA8FC 0x021BA8FC thumb ov217
 *   func_021BA674 0x021BA674 thumb ov217
 *   func_021BA5E4 0x021BA5E4 thumb ov217
 *   func_021BA5B4 0x021BA5B4 thumb ov217
 *   func_021BA858 0x021BA858 thumb ov217
 *   func_021BA9E8 0x021BA9E8 thumb ov217
 *   func_021BAA40 0x021BAA40 thumb ov217
 *   func_021BAAC4 0x021BAAC4 thumb ov217
 */
#include "../include/Obj03376.h"
extern void func_021BA8FC(void *);
extern void func_021BA674(void *);
extern void func_021BA5E4(void *);
extern void func_021BA5B4(void *);
extern void func_021BA858(void *);
extern void func_021BA9E8(void *);
extern void func_021BAA40(void *);
extern void func_021BAAC4(void *);
void func_021BA504(char *p)
{
    ((struct Obj03376 *)p)->f80=0;((struct Obj03376 *)p)->f84=0;((struct Obj03376 *)p)->f88=0;
    ((struct Obj03376 *)p)->f18=0;((struct Obj03376 *)p)->f20=0;((struct Obj03376 *)p)->f24=0;
    ((struct Obj03376 *)p)->f28=0;((struct Obj03376 *)p)->f8C=2;((struct Obj03376 *)p)->f1C=0;
    func_021BA8FC(p);func_021BA674(p);func_021BA5E4(p);func_021BA5B4(p);
    func_021BA858(p);func_021BA9E8(p);func_021BAA40(p);func_021BAAC4(p);
}
