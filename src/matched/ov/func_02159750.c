/*
 * function: func_02159750
 * address:  0x02159750
 * packet:   pkt_02159750
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0201296C  0x0201296C  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0201433C  0x0201433C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5E4(void *a0);
struct BigObj;
extern u32 func_0201296C(const struct BigObj *p);
extern int func_02159B10();
extern int func_0201433C();

int func_02159750(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215975C:
    a0 = func_0201296C(v0);
loc_02159760:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10(a0, a1);
loc_0215976A:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0201433C(a0, a1);
loc_02159772:
a0 = 0;
    return a0;}
