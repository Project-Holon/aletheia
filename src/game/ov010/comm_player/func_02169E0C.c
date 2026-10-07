/*
 * function: func_02169E0C
 * address:  0x02169E0C
 * packet:   pkt_02169E0C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216A128  0x0216A128  thumb  ov010
 *   func_02169E98  0x02169E98  thumb  ov010
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02028604  0x02028604  thumb
 *   func_02031140  0x02031140  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_020307B0  0x020307B0  arm
 */
#include "../../../matched/include/Obj00029.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216A128();
extern int func_02169E98(char *p);
extern int func_0201C4C0();
extern int func_02028604(int a0);
extern int func_02031140();
extern int func_02045808();
extern int func_02045C04();
extern u32 func_020307B0(void *p);

int func_02169E0C(char *a0)
{
    int t4;

t4 = (int)(a0 + 0);
    a0 = (char *)func_0216A128(a0);
loc_02169E14:
a0 = (char *)(t4 + 0);
    a0 = (char *)func_02169E98(a0);
loc_02169E1A:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(((struct Obj00029 *)a0)->f14);
    a0 = (char *)func_0201C4C0(a0);
loc_02169E22:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(((struct Obj00029 *)a0)->f1C);
    a0 = (char *)func_02028604((int)a0);
loc_02169E2A:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(*(int *)&((struct Obj00029 *)((char *)a0))->f0);
    a0 = (char *)func_02031140(a0);
loc_02169E32:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(*(int *)&((struct Obj00029 *)a0)->f18);
    a0 = (char *)func_02045808(a0);
loc_02169E3A:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
a0 = (char *)(*(int *)&((struct Obj00029 *)a0)->f4);
    a0 = (char *)func_02045C04(a0);
loc_02169E42:
a0 = (char *)(*(int *)&((struct Obj00029 *)t4)->f18);
    a0 = (char *)func_020307B0(a0);
loc_02169E48:
    return (int)a0;}
