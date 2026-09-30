/*
 * function: func_021E43DC
 * address: 0x021E43DC
 * packet: pkt_ov119_021E43DC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
extern void func_020307B0(void *);
void func_021E43DC(char *p)
{
    if (*(void **)(p + 0x1174)) {
        func_020307B0(*(void **)(p + 0x1174));
        *(void **)(p + 0x1174) = 0;
        func_020307B0(*(void **)(p + 0x1178));
        *(void **)(p + 0x1178) = 0;
        func_020307B0(*(void **)(p + 0x117c));
        *(void **)(p + 0x117c) = 0;
        func_020307B0(*(void **)(p + 0x1180));
        *(void **)(p + 0x1180) = 0;
    }
}
