/*
 * function: func_021E4888
 * address: 0x021E4888
 * packet: pkt_ov119_021E4888
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E69A4 0x021E69A4 thumb ov119
 *   func_021E4810 0x021E4810 thumb ov119
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_020307B0 0x020307B0 arm
 */
extern void func_021E69A4(char *);
extern void func_021E4810(char *, int);
extern void func_0204ADA4(int);
extern void func_0204AFD8(int);
extern void func_020307B0(void *);
void func_021E4888(char *p)
{
    int i;
    func_021E69A4(p);
    for (i = 0; i < 12; i++) func_021E4810(p, i);
    if (*(int *)(p + 0x87c)) {
        func_0204ADA4(*(int *)(p + 0x87c));
        *(int *)(p + 0x87c) = 0;
    }
    if (*(int *)(p + 0x8ac)) {
        func_0204AFD8(*(int *)(p + 0x8ac));
        *(int *)(p + 0x8ac) = 0;
    }
    if (*(void **)(p + 0x1184)) func_020307B0(*(void **)(p + 0x1184));
    *(void **)(p + 0x1184) = 0;
}
