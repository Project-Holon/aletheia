/*
 * function: func_02167A74
 * address:  0x02167A74
 * packet:   pkt_02167A74
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_02188BE8  0x02188BE8  thumb
 *   func_02188C7C  0x02188C7C  thumb
 *   func_02194284  0x02194284  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern int func_02188BE8(void *a);
extern void *func_02188C7C(unsigned char *p);
extern void *func_02194284(int a, void *b, int heap, int c);

void func_02167A74(int a0, int a1)
{
    int a2;
    int a3;
    int t4;
    void *res;
    void *v0;
    void *v1;

t4 = a1 + 0;
a1 = *(int *)((char *)t4 + 4);
    if (a1 != 0) goto loc_02167AAE;
loc_02167A7E:
    v0 = func_0201210C((void *)a0);
loc_02167A82:
    if (v0 == 0) goto loc_02167AAE;
loc_02167A86:
    a0 = func_02188BE8(v0);
loc_02167A8A:
    if (a0 == 0) goto loc_02167AAE;
loc_02167A8E:
    v1 = func_02188C7C(v0);
loc_02167A94:
a0 = t4 + 0;
a2 = t4 + 0;
a3 = t4 + 0;
a0 = a0 + 0x8e;
a2 = a2 + 0x8c;
a3 = a3 + 0x90;
a0 = *(u8 *)((char *)a0);
a2 = *(u16 *)((char *)a2);
a3 = *(u8 *)((char *)a3);
    res = func_02194284(a0, v1, a2, a3);
loc_02167AAC:
*(void **)((char *)t4 + 4) = res;
loc_02167AAE:
    return;}
