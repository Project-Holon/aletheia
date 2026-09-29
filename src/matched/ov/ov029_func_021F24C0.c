/*
 * function: func_021F24C0
 * address:  0x021F24C0
 * packet:   pkt_ov029_021F24C0
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F0FF0  0x021F0FF0  thumb  ov029
 *   func_021F0E70  0x021F0E70  thumb  ov029
 *   func_021F1010  0x021F1010  thumb  ov029
 *   func_02030D28  0x02030D28  arm
 */

extern void func_021F0FF0(char *p);
extern void func_021F0E70(char *p);
extern void func_021F1010(char *p);
extern void func_02030D28(int a);

void func_021F24C0(char *p)
{
    func_021F0FF0(p);
    if (*(int *)(p + 0x204) != 0)
        func_02030D28(*(int *)(p + 0x204));
    func_021F0E70(p);
    func_021F1010(p);
    if (*(int *)(p + 0x204) != 0)
        func_02030D28(*(int *)(p + 0x204));
    *(unsigned char *)(p + 0x451) = 1;
}
