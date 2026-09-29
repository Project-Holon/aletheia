/*
 * function: func_02206A14
 * address:  0x02206A14
 * packet:   pkt_ov094_02206A14
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F8754  0x021F8754  thumb  ov094
 *   func_021B86B8  0x021B86B8  thumb  ov093
 *   func_021F8914  0x021F8914  thumb  ov094
 *   func_02021F64  0x02021F64  thumb
 *   func_021F86E0  0x021F86E0  thumb  ov094
 *   func_020215BC  0x020215BC  thumb
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern void ***func_021F8754(void);
extern void *func_021B86B8(void ***p);
extern int func_021F8914(void);
extern void func_02021F64(u16 *src, u16 *dst, u32 count, int weight, u16 color);
extern int func_021F86E0(void);
extern void func_020215BC(int a, u16 *b, int c, int d, u16 e);

void func_02206A14(char *p)
{
    u16 buf[16];

    if ((int)func_021B86B8(func_021F8754()) != 4 && func_021F8914() == 0) {
        func_02021F64((u16 *)(p + 0x284), buf, 0x10, 8, 0);
        func_020215BC(func_021F86E0(), buf, 1, 0x20, 0x20);
    }
}
