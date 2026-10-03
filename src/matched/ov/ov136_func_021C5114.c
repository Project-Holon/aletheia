/*
 * function: func_021C5114
 * address: 0x021C5114
 * packet: pkt_ov136_021C5114
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02021540 0x02021540 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_02030DA4 0x02030DA4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0207D63C 0x0207D63C arm
 */
typedef unsigned char u8;
typedef unsigned int   u32;
struct Node;
struct PalAnmSlot;
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern void func_02021540(void *);
extern void func_02030EAC(struct Node *n);
extern void func_02030DA4(void *);
extern void func_020307B0(void *);
extern void func_0207D63C(void *, int, int, int, int);
void func_021C5114(u8 *p)
{
    func_020215A0(*(void **)(p + 0x38), 0);
    func_02021540(*(void **)(p + 0x38));
    *(void **)(p + 0x38) = 0;
    func_02030EAC(*(void **)(p + 0xFC));
    func_02030DA4(*(void **)(p + 0xF8));
    func_020307B0(*(void **)(p + 0xF4));
    func_0207D63C((void *)0x04000050, 0, 0, 31, 0);
}
