/*
 * function: func_02164508
 * address:  0x02164508
 * packet:   pkt_02164508
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A30C8  0x021A30C8  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB4B8  0x021AB4B8  thumb
 *   func_02013C20  0x02013C20  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02012AC8();
extern int func_02012B28();
extern void *func_02188CB4(unsigned char *p);
extern int func_021A30C8();
extern int func_021AB0F0();
extern int func_021AB4B8();
extern u32 func_02013C20(u32 id);

int func_02164508(int a0, int a1, int a2)
{
    int t4;
    int t5;
    int t6;
    void *v0;

t5 = a2 + 0;
a0 = t5 + 0;
t4 = a1 + 0;
    a0 = func_02012AC8(a0);
loc_02164514:
t6 = a0 + 0;
a0 = t5 + 0;
    a0 = func_02012B28(a0);
loc_0216451C:
a0 = a0 << 0x18;
t5 = (unsigned)a0 >> 0x18;
a0 = t4 + 0;
    v0 = func_02188CB4((void *)a0);
loc_02164526:
    a0 = func_021A30C8(v0);
loc_0216452A:
    a0 = func_021AB0F0(a0);
loc_0216452E:
    a0 = func_021AB4B8(a0);
loc_02164532:
t4 = a0 + 0;
    if (t5 != 1) goto loc_02164542;
loc_02164538:
a0 = 1;
    if (t4 == 0) goto loc_02164560;
loc_0216453E:
a0 = 0;
    return a0;
loc_02164542:
a0 = t6 + 0;
    a0 = func_02013C20(a0);
loc_02164548:
    if (a0 != 0) goto loc_02164550;
loc_0216454C:
a0 = 0;
    return a0;
loc_02164550:
    if (t5 == 0) goto loc_02164558;
loc_02164554:
a0 = 0;
    return a0;
loc_02164558:
a0 = 1;
    if (t4 == 0) goto loc_02164560;
loc_0216455E:
a0 = 0;
loc_02164560:
    return a0;}
