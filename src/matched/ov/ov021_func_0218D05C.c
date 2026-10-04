/*
 * function: func_0218D05C
 * address:  0x0218D05C
 * packet:   pkt_ov021_0218D05C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021693CC  0x021693CC  thumb ov010
 *   func_021693BC  0x021693BC  thumb ov010
 *   func_021693A0  0x021693A0  thumb ov010
 *   func_0216928C  0x0216928C  thumb ov010
 *   func_0218DD38  0x0218DD38  thumb ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021A73C0  0x021A73C0  thumb ov021
 *   func_0218D13C  0x0218D13C  thumb ov021
 */
#include "../include/Obj01208.h"

typedef unsigned short u16;

extern void func_021693CC(char *p);
extern void func_021693BC(char *p);
extern void func_021693A0(int o);
extern void func_0216928C(void *p);
extern void func_0218DD38(void *p);
extern void func_020307B0(void *p);
extern void func_021A73C0(int p);
extern void func_0218D13C(void *p);

void func_0218D05C(char *p)
{
    int i;

    if (*(int *)&((struct Obj01208 *)p)->f24 != 0) {
        for (i = 0; i < ((struct Obj01208 *)p)->f2E; i++) {
            int off = i * 0x28;
            func_021693CC((char *)(*(int *)(*(char * *)&((struct Obj01208 *)p)->f24 + off)));
            func_021693BC((char *)(*(int *)(*(char * *)&((struct Obj01208 *)p)->f24 + off)));
            func_021693A0(*(int *)(*(char * *)&((struct Obj01208 *)p)->f24 + off));
            func_0216928C((void *)(*(int *)(*(char * *)&((struct Obj01208 *)p)->f24 + off)));
            func_0218DD38(*(char * *)&((struct Obj01208 *)p)->f24 + off + 4);
        }
        func_020307B0(((struct Obj01208 *)p)->f24);
        func_020307B0(((struct Obj01208 *)p)->f28);
        func_020307B0(((struct Obj01208 *)p)->f44);
        *(int *)&((struct Obj01208 *)p)->f28 = 0;
        *(int *)&((struct Obj01208 *)p)->f24 = 0;
        *(int *)&((struct Obj01208 *)p)->f44 = 0;
        ((struct Obj01208 *)p)->f2E = 0;
    }
    if (((struct Obj01208 *)p)->f68 != 0) {
        func_021A73C0(((struct Obj01208 *)p)->f68);
        ((struct Obj01208 *)p)->f68 = 0;
    }
    func_0218D13C(p);
}
