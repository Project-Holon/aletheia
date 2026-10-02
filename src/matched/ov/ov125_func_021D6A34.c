/*
 * function: func_021D6A34
 * address: 0x021D6A34
 * packet: pkt_ov125_021D6A34
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D85C0 0x021D85C0 arm ov125
 *   func_021D6B40 0x021D6B40 thumb ov125
 *   func_021D6FB0 0x021D6FB0 thumb ov125
 *   func_02082BCC 0x02082BCC arm
 */
typedef unsigned char u8;
typedef int (*Callback)(void *, void *);
extern unsigned func_021D85C0(void);
extern int func_021D6B40(void *, int *);
extern int func_021D6FB0(char *);
extern void func_02082BCC(void *, int, unsigned);
int func_021D6A34(char *p)
{
    int result;
    if (*(int *)(p + 0x3b4) == 1) {
        if (*(int *)(p + 0x3d8) != 0x55f4) {
            if (*(u8 *)(p + 0x401) != 0) {
                (*(u8 *)(p + 0x401))--;
            } else {
                switch (func_021D85C0()) {
                case 1: case 7: case 8: case 9:
                    if (func_021D6B40(p, &result) == 1) {
                        *(int *)(p + 0x3d8) = 0x55f4;
                        *(u8 *)(p + 0x402) = 0;
                        if (result == 1) {
                            *(int *)(p + 0x168) = 2;
                            *(int *)(p + 0x16c) = 0x55f0;
                            *(int *)(p + 0x170) = *(u8 *)(p + 0x493);
                            *(int *)(p + 0x164) = 1;
                            if (*(Callback *)(p + 0x154) != 0)
                                (*(Callback *)(p + 0x154))(*(void **)(p + 0x148), p + 0x164);
                        }
                    }
                    break;
                case 0: case 2: case 3: case 4: case 5: case 6:
                default: break;
                }
            }
        }
        func_021D6FB0(p);
        if (*(Callback *)(p + 0x3fc) != 0) {
            if ((*(Callback *)(p + 0x3fc))(p, p + 0x3f0) == 1) {
                *(Callback *)(p + 0x3fc) = 0;
                if (*(Callback *)(p + 0x3f0) != 0) {
                    (*(Callback *)(p + 0x3f0))(*(void **)(p + 0x148), p + 0x164);
                    *(Callback *)(p + 0x3f0) = 0;
                }
                func_02082BCC(p + 0x3f0, 0, 16);
                *(int *)(p + 0x3dc) = 0x55f4;
            }
        }
    }
    return 1;
}
