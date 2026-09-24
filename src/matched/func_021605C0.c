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

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02040588();
extern int func_02188C54();
extern int func_02190344();
extern int func_020120F4();
extern int func_02012C0C();
extern int func_021C4F7C();

int func_021605C0(int a0, int a1, int a2, int a3)
{
    unsigned char fr[4];
    int t4;
    int t5;
    int t6;
    int o4;
t4 = a1 + 0;
t5 = a0 + 0;
a0 = *(int *)((char *)t4 + 0xc);
    if (a0 != 0) goto loc_02160608;
loc_021605CE:
a0 = *(int *)((char *)t4 + 0x18);
    if (a0 != 0) goto loc_02160608;
loc_021605D4:
a0 = 1;
a1 = 0;
    a0 = func_02040588(a0, a1);
loc_021605DC:
a0 = *(int *)((char *)t4 + 8);
    a0 = func_02188C54(a0);
loc_021605E2:
    if (a0 == 0) goto loc_021605EA;
loc_021605E6:
    a0 = func_02190344();
loc_021605EA:
a0 = *(int *)((char *)t4 + 4);
    a0 = func_020120F4(a0);
loc_021605F0:
t6 = a0 + 0;
    a0 = func_02012C0C();
loc_021605F6:
a2 = a0 + 0;
a0 = 0x15;
    o4 = a0;
a0 = t6 + 0;
a1 = t5 + 0;
a3 = 0x50;
    a0 = func_021C4F7C(a0, a1, a2, a3, o4);
loc_02160606:
*(int *)((char *)t4 + 0xc) = a0;
loc_02160608:
    return a0;
}
