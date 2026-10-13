/*
 * function: func_021F8A78
 * address:  0x021F8A78
 * packet:   pkt_ov094_021F8A78
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094
 *   func_021F7BEC  0x021F7BEC  thumb  ov094
 *   BTL_MAIN_CheckSetupStatusFlag  0x021BA1A8  thumb  ov093
 *   func_021F7998  0x021F7998  thumb  ov094
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    char pad[0x1E4];
    void *battle;       /* 0x1E4 */
    char pad2[0x50];
    int state;          /* 0x238 */
} Work;

extern Work *d_0220AF20;

extern void func_021F7BEC(void);
extern int BTL_MAIN_CheckSetupStatusFlag(char **p, int m);
extern void func_021F7998(u32 a);

void func_021F8A78(void)
{
    func_021F7BEC();
    if (d_0220AF20->state == 3 && BTL_MAIN_CheckSetupStatusFlag(d_0220AF20->battle, 0x400))
        func_021F7998(0x251);
    else
        func_021F7998(0x236);
    d_0220AF20->state = 0;
}
