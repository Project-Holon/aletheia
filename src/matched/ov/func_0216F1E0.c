/*
 * function: func_0216F1E0
 * address:  0x0216F1E0
 * packet:   pkt_0216F1E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 72 compiled 70
 *
 * symbols:
 *   func_02012944  0x02012944  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02027174  0x02027174  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *func_02012944(void *p);
extern int func_02008554();
extern int func_02027174();
extern int func_020307B0();
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);

int func_0216F1E0(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;
    int t6;
    u8 *p;

t5 = a2 + 0;
t6 = a0 + 0;
a0 = *(int *)((char *)t5 + 8);
t4 = a3 + 0;
    if (a0 == 0) goto loc_0216F202;
loc_0216F1EE:
a0 = *(int *)((char *)t5 + 4);
    p = func_02012944((void *)a0);
loc_0216F1F4:
    a0 = func_02008554(p);
loc_0216F1F8:
a1 = *(int *)((char *)t4 + 0x1c);
    if (a1 == a0) goto loc_0216F202;
loc_0216F1FE:
    a0 = func_02027174(a0);
loc_0216F202:
a0 = *(int *)((char *)t4 + 0x18);
a0 = *(int *)((char *)a0 + 0x10);
*(int *)((char *)t5 + 0x10) = a0;
a0 = *(int *)((char *)t4 + 0x18);
a0 = *(int *)((char *)a0);
    a0 = func_020307B0(a0);
loc_0216F210:
a0 = *(int *)((char *)t4 + 0x18);
    a0 = func_020307B0(a0);
loc_0216F216:
a0 = t6 + 0;
    func_020315D4((struct S020315D4 *)a0);
loc_0216F21C:
a0 = 0x26;
    func_020306F0(a0);
loc_0216F222:
a0 = 1;
    return a0;}
