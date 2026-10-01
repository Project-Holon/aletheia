/*
 * unit: yes
 * function: func_021BBA14, func_021BBA64, func_021BBA70
 * address: 0x021BBA14
 * packet: pkt_ov225_021BBA14
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: 94-byte unit; two zero alignment bytes at 021BBA72 are outside the unit.
 * followers: parent cleared 021BBA64 tail stub and 021BBA70 empty Thumb leaf.
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021BA740 0x021BA740 thumb ov225
 *   func_020307B0 0x020307B0 arm
 *   func_021BA760 0x021BA760 thumb ov225
 */
typedef unsigned short u16;
struct Node;
extern void func_02030EAC(struct Node *);
extern void func_021BA740(char *);
extern void func_020307B0(void *);
extern void func_021BA760(char *);
void func_021BBA14(char *p)
{
    func_02030EAC(*(struct Node **)(p + 0x20));
    *(u16 *)(*(char **)p + 6) = *(u16 *)(p + 0x14);
    *(u16 *)(*(char **)p + 8) = *(u16 *)(p + 0x16);
    if (*(unsigned *)(p + 0x18) == 0) *(unsigned *)(*(char **)p + 0xc) = 0;
    else if (*(unsigned *)(p + 0x18) == 1) {
        *(unsigned *)(*(char **)p + 0xc) = 1;
        *(u16 *)(*(char **)p + 0x10) = *(u16 *)(*(char **)(p + 0x10) + *(u16 *)(*(char **)p + 8) * 8);
    }
    func_021BA740(*(char **)(p + 0x1c));
    func_020307B0(*(void **)(p + 0x10));
    func_020307B0(p);
}
void func_021BBA64(char *p)
{
    func_021BA760(*(char **)(p + 0x1c));
}
void func_021BBA70(void)
{
}
