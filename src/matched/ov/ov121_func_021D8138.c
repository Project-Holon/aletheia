/*
 * function: func_021D8138
 * address: 0x021D8138
 * packet: pkt_ov121_021D8138
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 0x021D8196.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_021DA038 0x021DA038 thumb ov121
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { int f0, f4, f8, fc, f10, f14, f18; u16 f1c, f1e, f20, f22; } Config;
extern void func_02082BCC(void *, int, int);
extern void *func_021DA038(Config *, int);
void func_021D8138(u8 *p, int unused, int heap)
{
    Config c;
    if (*(int *)(p + 0x260) == 0) {
        func_02082BCC(&c, 0, 0x24);
        c.f0 = *(int *)(p + 0x3a4);
        c.f4 = *(int *)(p + 0x398);
        c.f8 = *(int *)(p + 0x39c);
        c.fc = 0x54;
        c.f10 = 0x55;
        c.f18 = 2;
        c.f1c = 0;
        c.f1e = 15;
        c.f20 = 14;
        c.f22 = 1;
        *(void **)(p + 0x260) = func_021DA038(&c, heap);
    }
}
