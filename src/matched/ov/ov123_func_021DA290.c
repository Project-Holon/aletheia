/*
 * function: func_021DA290
 * address: 0x021DA290
 * packet: pkt_ov123_021DA290
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DA034 0x021DA034 thumb ov123
 *   func_021D9634 0x021D9634 thumb ov123
 *   func_021DA268 0x021DA268 thumb ov123
 *   func_021DA054 0x021DA054 thumb ov123
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_02027858(struct TaskMenu *m);
extern void func_021DA034(char *, void *, int);
extern void func_021D9634(char *p);
extern void func_021DA268(char *p);
extern void func_021DA054(char *p);
void func_021DA290(char *p)
{
    if (func_020279E8(*(void **)(p + 0x14))) {
        if (!func_02027A04(*(void **)(p + 0x14)))
            func_021DA034(p, func_021DA268, 0x18d);
        else
            func_021DA034(p, func_021DA054, 0x190);
        func_021D9634(*(void **)(p + 0x10));
        func_02027858(*(void **)(p + 0x14));
        *(int *)(p + 0x14) = 0;
    }
}
