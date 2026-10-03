/*
 * function: func_021C8FF4
 * address: 0x021C8FF4
 * packet: pkt_ov212_021C8FF4
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020307B0(void *);
int func_021C8FF4(u8 *p) {
    int result;
    switch (*(u32 *)(*(u8 **)(p + 40) + 8)) {
    case 0:
        *(u16 *)(*(u8 **)p + 14) = 0;
        result = 9;
        break;
    case 1:
        *(u16 *)(*(u8 **)p + 14) = 1;
        result = 9;
        break;
    case 2: result = 3; break;
    }
    func_020307B0(*(void **)(p + 40));
    return result;
}
