/*
 * function: BTLV_EFFVM_BlendRegisterTaskMain
 * address: 0x021FE79C
 * packet: pkt_ov094_021FE79C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: WININ re-read at 0x021FE7BE; WINOUT and display register accesses.
 * symbols:
 *   BTLV_EFFECT_DeleteTask 0x021F89BC thumb ov094
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern void BTLV_EFFECT_DeleteTask(void *);
#define REG16(a) (*(volatile u16 *)(a))
#define REG32(a) (*(volatile unsigned int *)(a))
static inline void window0(int x1, int y1, int x2, int y2)
{
    REG16(0x04000040) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000044) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}
static inline void window1(int x1, int y1, int x2, int y2)
{
    REG16(0x04000042) = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    REG16(0x04000046) = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}
void BTLV_EFFVM_BlendRegisterTaskMain(void *h, int *s)
{
    switch (s[1]) {
    case 0:
        REG16(0x04000048) = (u16)((REG16(0x04000048) & ~0x3f) | (u8)s[5]);
        REG16(0x04000048) = (u16)((REG16(0x04000048) & ~0x3f00) | (u16)(s[5] << 8));
        REG16(0x0400004a) = (u16)((REG16(0x0400004a) & ~0x3f) | ((s[5] & 0xff00) >> 8));
        REG32(0x04000000) = (REG32(0x04000000) & ~0xe000) | 0x6000;
        REG16(0x04000042) = 0;
        REG16(0x04000046) = 0;
        s[1]++;
    case 1:
        if (s[7] == 0) {
            s[7] = s[8];
            switch (s[2]) {
            case 0: s[4] -= 0x100; s[4]++; break;
            case 1: s[4] += 0x100; s[4]--; break;
            case 2: s[3] -= 0x100; s[3]++; break;
            case 3: s[3] += 0x100; s[3]--; break;
            }
            window0(s[3] >> 8, s[4] >> 8, s[3], s[4]);
            if ((u8)s[3] == 0xff) {
                window1(1, s[4] >> 8, 0, s[4]);
            } else {
                window1(0, 0, 0, 0);
            }
            s[6]--;
            if (s[6] == 0)
                BTLV_EFFECT_DeleteTask(h);
        } else {
            s[7]--;
        }
        break;
    }
}
