/*
 * function: func_021B952C
 * address: 0x021B952C
 * packet: pkt_ov133_021B952C
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02035C60 0x02035C60 arm
 *   func_02035CB8 0x02035CB8 arm
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA324 0x021BA324 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   func_021B95AC 0x021B95AC thumb ov133
 */
typedef unsigned char u8;
extern int func_02035C60(void);
extern int func_02035CB8(int *, int *);
extern void *func_021BA184(char *p);
extern unsigned int func_021BA324(u8 *, int, int);
typedef unsigned int   u32;
extern u32 func_021BA208(u8 *p);
extern void func_021B95AC(u8 *);
void func_021B952C(u8 *p)
{
    u8 *e, *best;
    unsigned int distance, n;
    *(int *)(p + 0x24) = *(int *)(p + 0x1c);
    *(int *)(p + 0x28) = *(int *)(p + 0x20);
    *(int *)(p + 0x14) = func_02035C60();
    *(int *)(p + 0x18) = func_02035CB8((int *)(p + 0x1c), (int *)(p + 0x20));
    if (*(int *)(p + 0x14) == 1) {
        best = 0;
        distance = 256;
        e = func_021BA184(*(void **)(p + 0x1824));
        while (e) {
            n = func_021BA324(e, *(int *)(p + 0x1c), *(int *)(p + 0x20));
            if (distance > n) { best = e; distance = n; }
            e = (u8 *)func_021BA208(e);
        }
        if (best) *(u8 **)(p + 0x38) = best;
    }
    if (*(int *)(p + 0x18) == 1 && *(u8 **)(p + 0x38)) func_021B95AC(p);
    if (*(int *)(p + 0x18) == 0) {
        *(int *)(p + 0x30) = 0;
        *(u8 **)(p + 0x38) = 0;
    }
}
