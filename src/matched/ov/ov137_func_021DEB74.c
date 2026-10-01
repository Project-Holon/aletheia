/*
 * function: func_021DEB74
 * address: 0x021DEB74
 * packet: pkt_ov137_021DEB74
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021DCBC4(void *, int, void *, int);
int func_021DEB74(u8 *p)
{
    u16 buf[2];
    int i, count;
    u16 mask;
    if (*(int *)(p + 20) == 0) {
        buf[1] = 0; buf[0] = 0;
        if (func_021DCBC4(*(void **)(p + 0xdc), 10249, buf, 4) == 1) (*(int *)(p + 20))++;
        return 0;
    }
    i = 1;
    mask = *(u16 *)(*(u8 **)(p + 0xdc) + 0x42);
    for (count = 1; i < 5; i++) {
        if (mask & (1 << i)) {
            if (count >= *(int *)(p + 20)) {
                buf[1] = i; buf[0] = *(int *)(p + 20);
                if (func_021DCBC4(*(void **)(p + 0xdc), 10249, buf, 4) == 1) (*(int *)(p + 20))++;
                break;
            }
            count++;
        }
    }
    if (*(int *)(p + 20) >= *(int *)(p + 0x30)) *(int *)p = 7;
    return 0;
}
