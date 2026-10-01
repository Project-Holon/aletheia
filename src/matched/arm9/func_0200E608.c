/*
 * function: func_0200E608
 * address:  0x0200E608
 * packet:   pkt_0200E608
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled arm9 function: loads save block 5 into a 0x1000 byte heap buffer,
 * copies its first 0x5C8 bytes to dst, then starts a save of block 5 and spins
 * on OS_WaitIrq until it reports done. Filed as the relocation witness for
 * ov021 func_021D0C58 (wave A1).
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   data_020A721C  0x020A721C  data
 *   func_020072CC  0x020072CC  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_02012E4C  0x02012E4C  thumb
 *   func_02012E7C  0x02012E7C  thumb
 *   OS_WaitIrq     0x0208459C  arm
 *   func_0200734C  0x0200734C  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned int u32;

extern u32 func_02012EBC(void *sys);
extern void *func_02030734(u32 heap, u32 size, int a, const char *file, int line);
extern const char data_020A721C[];
extern int func_020072CC(u32 sv, u32 id, u32 heap, void *buf, u32 size);
extern void func_02082D44(void *src, void *dst, int n);
extern void func_02012E4C(void *sys, int id);
extern int func_02012E7C(void *sys, int id);
extern void OS_WaitIrq(int clear, u32 mask);
extern void func_0200734C(u32 sv, u32 id);
extern void func_020307B0(void *p);

void func_0200E608(void *sys, void *dst, u32 heap)
{
    u32 sv = func_02012EBC(sys);
    void *buf = func_02030734(heap, 0x1000, 0, data_020A721C, 0x99);

    func_020072CC(sv, 5, heap, buf, 0x1000);
    func_02082D44(dst, buf, 0x5C8);
    func_02012E4C(sys, 5);
    for (;;) {
        if (func_02012E7C(sys, 5) == 2) {
            break;
        }
        OS_WaitIrq(1, 1);
    }
    func_0200734C(sv, 5);
    func_020307B0(buf);
}
