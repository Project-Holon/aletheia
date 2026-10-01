/*
 * function: func_022127F0
 * address: 0x022127F0
 * packet: pkt_ov199_022127F0
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0221380C 0x0221380C thumb ov199
 *   func_02213808 0x02213808 thumb ov199
 *   func_02034714 0x02034714 arm
 *   func_020307B0 0x020307B0 arm
 *   d_02213D00 0x02213D00 data a1 ov199
 */
extern void func_0221380C(void *);
extern void func_02213808(void *, int);
extern void func_02034714(const char *, int, const char *);
extern void func_020307B0(void *);
extern const char d_02213D00[];
int func_022127F0(void *obj, int *command, int *ctx)
{
    switch (command[2]) {
    case 0: func_0221380C(obj); break;
    case 1: ctx[7] = 0; func_02213808(obj, 4); break;
    case 2: ctx[7] = 1; func_02213808(obj, 2); break;
    case 3: ctx[7] = 1; func_02213808(obj, 6); break;
    case 4: ctx[7] = 1; func_02213808(obj, 8); break;
    default: func_02034714(d_02213D00, 0, d_02213D00); break;
    }
    func_020307B0(command);
    return 1;
}
