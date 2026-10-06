/*
 * function: func_02158468
 * address:  0x02158468
 * packet:   pkt_02158468
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02012984  0x02012984  thumb
 *   func_0215841C  0x0215841C  thumb  ov010
 *   func_02012B58  0x02012B58  thumb
 *   func_02012B98  0x02012B98  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BigObj;
extern u32 func_02026478(void *obj);
extern int func_02012B70(const struct BigObj *p);
extern u8 func_02012984(const struct BigObj *p);
extern int func_0215841C(void *p);
extern u8 func_02012B58(const struct BigObj *p);
extern u8 func_02012B98(const struct BigObj *p, u32 i);

int func_02158468(int a0)
{
    int a1;
    int t4;
    int t5;

    a0 = func_02026478((void *)a0);
loc_0215846E:
t5 = a0 + 0;
    a0 = func_02012B70((const struct BigObj *)a0);
loc_02158474:
    if (a0 != 0) goto loc_02158480;
loc_02158478:
a0 = t5 + 0;
    a0 = func_02012984((const struct BigObj *)a0);
loc_0215847E:
    return a0;
loc_02158480:
a0 = t5 + 0;
    a0 = func_0215841C((void *)a0);
loc_02158486:
t4 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02012B58((const struct BigObj *)a0);
loc_0215848E:
    if (t4 != a0) goto loc_0215849A;
loc_02158492:
a0 = t5 + 0;
    a0 = func_02012984((const struct BigObj *)a0);
loc_02158498:
    return a0;
loc_0215849A:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = func_02012B98((const struct BigObj *)a0, a1);
loc_021584A2:
    return a0;}
