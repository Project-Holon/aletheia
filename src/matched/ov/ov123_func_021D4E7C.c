/*
 * function: func_021D4E7C
 * address: 0x021D4E7C
 * packet: pkt_ov123_021D4E7C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020286C4 0x020286C4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_0201CE38 0x0201CE38 thumb
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_02035C60 0x02035C60 arm
 *   func_02035C38 0x02035C38 arm
 *   func_020061E4 0x020061E4 thumb
 */
extern void func_020286C4(void *, void *, void *);
extern int func_0201CE30(void *);
extern void func_0201CE48(void *);
extern void func_0201CE38(void *);
extern void func_0201CE5C(void *, int);
extern int func_02035C60(void);
extern int func_02035C38(void);
extern void func_020061E4(int);
int func_021D4E7C(char *p)
{
    if (*(void **)(p + 0x228)) {
        if (*(void **)(p + 0x224))
            func_020286C4(*(void **)(p + 0x22c), *(void **)(p + 0x228), *(void **)(p + 0x224));
        switch (func_0201CE30(*(void **)(p + 0x228))) {
        case 2:
            func_0201CE48(*(void **)(p + 0x228));
            *(void **)(p + 0x228) = 0;
            break;
        case 1:
            if (func_02035C60()) {
                func_020061E4(0x547);
                func_0201CE38(*(void **)(p + 0x228));
            }
            break;
        case 0:
            if (func_02035C38()) func_0201CE5C(*(void **)(p + 0x228), 0);
            break;
        }
        return 0;
    }
    return 1;
}
