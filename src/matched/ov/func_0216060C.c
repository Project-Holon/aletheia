/*
 * function: func_0216060C
 * address:  0x0216060C
 * packet:   pkt_0216060C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * unblocked: func_021C51A0 is ov021's label across the co-resident
 *   ov010/ov021 pair; the `ov021` token resolves the site as `label`.
 *   Extent runs 92 bytes against 90 compiled: the unlabelled follower.
 *
 * symbols:
 *   func_02040588  0x02040588  arm
 *   func_021C51A0  0x021C51A0  thumb  ov021
 *   func_02188C54  0x02188C54  thumb
 *   func_02190398  0x02190398  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02040588();
extern int func_021C51A0();
extern int func_02188C54();
extern int func_02190398();

int func_0216060C(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
a0 = *(int *)((char *)t5 + 0x18);
    if (a0 != 0) goto loc_02160662;
loc_02160616:
a0 = *(int *)((char *)t5 + 0x1c);
    if (a0 == 0) goto loc_02160626;
loc_0216061C:
    if (a0 == 1) goto loc_0216064A;
loc_02160620:
    if (a0 == 2) goto loc_02160656;
loc_02160624:
    goto loc_0216065E;
loc_02160626:
a0 = *(int *)((char *)t5 + 0xc);
    if (a0 == 0) goto loc_02160644;
loc_0216062C:
a0 = 1;
a1 = 0;
t4 = 1;
t6 = 0;
    a0 = func_02040588(a0, a1);
loc_02160638:
a0 = *(int *)((char *)t5 + 0xc);
    a0 = func_021C51A0(a0);
loc_0216063E:
*(int *)((char *)t5 + 0xc) = t6;
*(int *)((char *)t5 + 0x1c) = t4;
    goto loc_0216065E;
loc_02160644:
a0 = 2;
*(int *)((char *)t5 + 0x1c) = a0;
    goto loc_0216065E;
loc_0216064A:
a0 = *(int *)((char *)t5 + 8);
    a0 = func_02188C54(a0);
loc_02160650:
    a0 = func_02190398(a0);
loc_02160654:
    goto loc_02160644;
loc_02160656:
a0 = 0;
*(int *)((char *)t5 + 0x1c) = a0;
a0 = 1;
    return a0;
loc_0216065E:
a0 = 0;
    return a0;
loc_02160662:
a0 = 1;
    return a0;}
