/*
 * function: func_02186694
 * address: 0x02186694
 * packet: pkt_ov023_02186694
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte zero alignment padding at 0x021866C2.
 * symbols:
 *   func_02027858 0x02027858 thumb
 *   func_02045808 0x02045808 arm
 *   func_02027FD8 0x02027FD8 thumb
 */
struct TaskMenu;
struct TaskMenuState;
extern void func_02027858(struct TaskMenu *);
extern void func_02045808(void *);
extern void func_02027FD8(struct TaskMenuState *);
void func_02186694(char *p)
{
    func_02027858(*(struct TaskMenu **)(p + 0x178));
    func_02045808(*(void **)(p + 0x188));
    func_02045808(*(void **)(p + 0x17C));
    func_02027FD8(*(struct TaskMenuState **)(p + 0x174));
    *(int *)(p + 0x178) = 0;
}
