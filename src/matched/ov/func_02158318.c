/*
 * function: func_02158318
 * address:  0x02158318
 * packet:   pkt_02158318
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_0202648C  0x0202648C  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
struct BigObj;
extern int func_02012B70(const struct BigObj *p);
extern u32 func_0202648C(void *obj);

int func_02158318(int a0)
{
    int t4;
    int t5;
    void *p;

t5 = a0 + 0;
    a0 = func_02012138((const struct Ctx *)a0);
loc_02158320:
t4 = a0 + 0;
a0 = t5 + 0;
    p = func_020120F4((const struct Ctx *)a0);
loc_02158328:
    a0 = func_02012B70(p);
loc_0215832C:
    if (a0 != 1) goto loc_0215833E;
loc_02158330:
a0 = t4 + 0;
    a0 = func_0202648C((void *)a0);
loc_02158336:
    if (a0 == 0) goto loc_0215833E;
loc_0215833A:
a0 = 0;
    return a0;
loc_0215833E:
a0 = 1;
    return a0;}
