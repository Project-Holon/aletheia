/*
 * function: func_0216CCDC
 * address:  0x0216CCDC
 * packet:   pkt_ov010_0216CCDC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * lever: The allocation result is the second argument to func_02030CBC; its r1 live range orders the halfword reload.
 *
 * DIFF: original moves the alloc result to r1 (adds r1,r0) and stores it after the ldrh reload
 * (+2 B, pool shifts 4). Tried a result local and a halfword local.
 *
 * symbols:
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030734  0x02030734  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0216D4DC  0x0216D4DC  thumb  ov010
 *   d_02172B48     0x02172B48  data  ov010  a1
 */

typedef unsigned int   u32;
typedef unsigned short u16;
extern u32 func_02030CB0(u32 idx);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02030CBC(int, int);
extern int func_020490F4(int, int);
extern void func_0216D4DC(void *, int);
extern char d_02172B48[];

void func_0216CCDC(char *a, int b, int c, int d, int e, int f)
{
    int t;
    unsigned short h;
    *(int *)(a + 0x34) = e;
    *(short *)(a + 0xa) = b;
    *(int *)(a + 0x30) = c;
    *(int *)(a + 0x3c) = d;
    t = (int)func_02030734(b, func_02030CB0(*(unsigned short *)(a + 4)), 0, d_02172B48, 0x109);
    h = *(unsigned short *)(a + 4);
    *(int *)(a + 0x1c) = t;
    *(int *)(a + 0x20) = func_02030CBC(h, t);
    *(int *)(a + 0x10) = func_020490F4(0x31, b);
    *(int *)(a + 0x38) = f;
    func_0216D4DC(a, 0x10);
}
