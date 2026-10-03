/*
 * function: func_0215B328
 * address:  0x0215B328
 * packet:   pkt_0215B328
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
 *   func_0215A4EC  0x0215A4EC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5E4(void *a0);
struct BigObj;
extern u32 func_0201296C(const struct BigObj *p);
extern int func_02159B10();
extern int func_0215A4EC();

int func_0215B328(int a0, int a1)
{
    int t4;
    int t5;
    int t6;
    void *v0;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5E4((void *)a0);
loc_0215B334:
    a0 = func_0201296C(v0);
loc_0215B338:
t4 = a0 + 0;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10(a0, a1);
loc_0215B342:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0215A4EC(a0, a1);
loc_0215B34A:
a0 = 0;
    return a0;}
