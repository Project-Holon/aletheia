/*
 * function: func_02213278
 * address: 0x02213278
 * packet: pkt_ov199_02213278
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02034714 0x02034714 arm
 *   func_02213808 0x02213808 thumb ov199
 *   func_0221380C 0x0221380C thumb ov199
 *   d_02213D00 0x02213D00 data ov199 a1
 */
extern void func_020307B0(void *);
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02213808(char *, int);
extern void func_0221380C(char *);
extern const char d_02213D00[];
int func_02213278(char *a, void *work, char *p)
{
    switch (*(unsigned int *)(p + 0x1c)) {
    case 0:
        if (*(int *)(p + 0x24) != 0)
            func_0221380C(a);
        else
            func_02213808(a, 0);
        break;
    case 1:
        func_02034714(d_02213D00, 0, d_02213D00);
        break;
    case 2:
    case 3:
        func_0221380C(a);
        break;
    }
    func_020307B0(work);
    return 1;
}
