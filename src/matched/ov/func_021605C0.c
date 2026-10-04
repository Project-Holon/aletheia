/*
 * function: func_021605C0
 * address:  0x021605C0
 * packet:   pkt_021605C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040588  0x02040588  arm
 *   func_02188C54  0x02188C54  thumb
 *   func_02190344  0x02190344  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012C0C  0x02012C0C  thumb
 *   func_021C4F7C  0x021C4F7C  thumb
 */
#include "../include/Obj00020.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02040588();
extern int func_02188C54();
extern int func_02190344();
struct Ctx;
struct BigObj;

extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012C0C(struct BigObj *p);
extern char *func_021C4F7C(void *a0, int mode, const unsigned short *a2, unsigned short a3, unsigned short heap);

void func_021605C0(int a0, int a1, int a2, int a3)
{
    unsigned char fr[4];
    int t4;
    int t5;
    void *t6;
    u8 *name;
    char *res;
    int o4;
t4 = a1 + 0;
t5 = a0 + 0;
a0 = *(int *)&((struct Obj00020 *)t4)->fC;
    if (a0 != 0) goto loc_02160608;
loc_021605CE:
a0 = ((struct Obj00020 *)t4)->f18;
    if (a0 != 0) goto loc_02160608;
loc_021605D4:
a0 = 1;
a1 = 0;
    a0 = func_02040588(a0, a1);
loc_021605DC:
a0 = *(int *)&((struct Obj00020 *)t4)->f8;
    a0 = func_02188C54(a0);
loc_021605E2:
    if (a0 == 0) goto loc_021605EA;
loc_021605E6:
    a0 = func_02190344(a0);
loc_021605EA:
a0 = *(int *)&((struct Obj00020 *)t4)->f4;
    t6 = func_020120F4((const struct Ctx *)a0);
loc_021605F0:
    name = func_02012C0C((struct BigObj *)t6);
loc_021605F6:
a0 = 0x15;
    o4 = a0;
a1 = t5 + 0;
a3 = 0x50;
    res = func_021C4F7C(t6, a1, (const unsigned short *)name, a3, o4);
loc_02160606:
*(char * *)&((struct Obj00020 *)t4)->fC = res;
loc_02160608:
    return;
}
