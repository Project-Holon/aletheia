/*
 * function: func_021DA0D4
 * address:  0x021DA0D4
 * packet:   pkt_021DA0D4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203CD98                0x0203CD98  arm
 *   func_0200FA84                0x0200FA84  thumb
 *   DWC_CloseAllConnectionsHard  0x0216B65C  arm
 *   func_021DA4B8                0x021DA4B8  thumb
 *   STD_TSPrintf                 0x0208D7E0  arm
 *   MI_CpuFill8                  0x02082BCC  arm
 *   func_02034714                0x02034714  arm
 *   func_021DA4E8                0x021DA4E8  thumb
 *   func_021DA4F0                0x021DA4F0  thumb
 *   func_021DA4F8                0x021DA4F8  thumb
 *   d_021E2EF8                   0x021E2EF8  data
 *   d_021E2EFC                   0x021E2EFC  data
 *
 * Sets up a matchmaking attempt: closes any connection, publishes the eight match keys (player count, group, 1, four record words, version 0x20015), formats the filter string and picks the evaluation callback for the mode (1 asserts).
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef int (*EvalFn)(int index, void *param);

extern int func_0203CD98(void);
extern void func_0200FA84(void);
extern void DWC_CloseAllConnectionsHard(void);
extern void func_021DA4B8(char *obj, int i, int value);
extern int STD_TSPrintf(char *dst, const char *fmt, ...);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void func_02034714(const char *file, int line, const char *msg);
extern int func_021DA4E8(int index, void *param);
extern int func_021DA4F0(int index, void *param);
extern int func_021DA4F8(int index, void *param);
extern const char d_021E2EF8[];
extern const char d_021E2EFC[];

void func_021DA0D4(char *obj, int mode, int extra, int group, int *rec)
{
    int count = mode;

    if (mode == 1)
        count += extra;
    if (!func_0203CD98())
        func_0200FA84();
    DWC_CloseAllConnectionsHard();
    func_021DA4B8(obj, 0, count);
    func_021DA4B8(obj, 1, group);
    func_021DA4B8(obj, 2, 1);
    func_021DA4B8(obj, 3, rec[0]);
    func_021DA4B8(obj, 5, rec[1]);
    func_021DA4B8(obj, 4, rec[2]);
    func_021DA4B8(obj, 6, rec[3]);
    func_021DA4B8(obj, 7, 0x20015);
    STD_TSPrintf(obj + 0x44, d_021E2EFC, count, group, 1);
    *(u32 *)(obj + 0x40) = 0;
    *(u32 *)(obj + 0x1a0) = 0;
    *(u32 *)(obj + 0x1a4) = 0;
    MI_CpuFill8(obj + 0x138, 0, 0x18);
    switch (mode) {
    case 0:
        *(EvalFn *)(obj + 0x1218) = func_021DA4F8;
        break;
    case 1:
        func_02034714(d_021E2EF8, 0, d_021E2EF8);
        break;
    case 2:
        *(EvalFn *)(obj + 0x1218) = func_021DA4E8;
        break;
    case 3:
        *(EvalFn *)(obj + 0x1218) = func_021DA4F0;
        break;
    default:
        func_02034714(d_021E2EF8, 0, d_021E2EF8);
        break;
    }
}
