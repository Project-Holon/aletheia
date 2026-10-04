/*
 * function: func_02159778
 * address:  0x02159778
 * packet:   pkt_02159778
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_020142E8  0x020142E8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5E4(void *a0);
struct BigObj;
extern u32 func_0201296C(const struct BigObj *p);
extern unsigned int func_02159B10(void *, void *);
extern u16 *func_02159AE8(void *a0, void *a1);
typedef signed int     s32;
extern u32 func_020142E8(void *bitmap, s32 id);

int func_02159778(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    int t7;
    u16 *q;
    void *v0;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_02159784:
    a0 = func_0201296C(v0);
loc_02159788:
t6 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_02159792:
t7 = a0 + 0;
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0215979C:
a0 = t6 + 0;
a1 = t7 + 0;
    a0 = func_020142E8((void *)a0, a1);
loc_021597A6:
*q = a0;
a0 = 0;
    return a0;}
