/*
 * function: func_021DA5D0
 * address:  0x021DA5D0
 * packet:   pkt_021DA5D0
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Unblocked by matching func_02156DC4 (ov009, EXACT): the +004A call site now
 * attests as `matched`.  Every other relocation resolves (the 0x72 argument is
 * an overlay id, attested as overlay_id).
 * symbols:
 *   func_02027858  0x02027858  thumb
 *   func_021D941C  0x021D941C  thumb  ov123
 *   func_021D9A1C  0x021D9A1C  thumb  ov123
 *   func_020307B0  0x020307B0  arm
 *   func_021B9838  0x021B9838  thumb  ov114
 *   func_0203CD98  0x0203CD98  arm
 *   func_02156DC4  0x02156DC4  thumb  ov009
 *   func_020315D4  0x020315D4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   ov114_id       0x00000072  data
 */

extern void func_02027858(int x);
extern void func_021D941C(int x);
extern void func_021D9A1C(int x);
extern void func_020307B0(int x);
extern void func_021B9838(int x);
extern int func_0203CD98(void);
extern void func_02156DC4(int a, int b);
extern void func_020315D4(int x);
extern void func_02034A5C(int handle);
extern unsigned char ov114_id[];

int func_021DA5D0(int a, int b, int c, char *obj)
{
    if (*(int *)(obj + 0x14))
        func_02027858(*(int *)(obj + 0x14));
    func_021D941C(*(int *)(obj + 0x10));
    func_021D9A1C(*(int *)(obj + 0x0c));
    if (*(int *)(obj + 0x04))
        func_020307B0(*(int *)(obj + 0x04));
    if (*(int *)(obj + 0x24))
        func_020307B0(*(int *)(obj + 0x24));
    if (*(int *)(obj + 0x08)) {
        func_021B9838(*(int *)(obj + 0x08));
        *(int *)(obj + 0x08) = 0;
    }
    if (func_0203CD98())
        func_02156DC4(0, 0);
    func_020315D4(a);
    func_02034A5C((int)ov114_id);
    return 1;
}
