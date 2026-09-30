/*
 * unit: yes
 * function: func_021D6FB0, func_021D7060
 * address: 0x021D6FB0
 * packet: pkt_ov125_021D6FB0
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D85C0 0x021D85C0 arm ov125
 *   func_021D85DC 0x021D85DC arm ov125
 *   func_021D71D8 0x021D71D8 thumb ov125
 *   func_021D7060 0x021D7060 thumb ov125
 *   func_021D7120 0x021D7120 thumb ov125
 */
extern unsigned int func_021D85C0(void);
extern int func_021D85DC(void);
extern void func_021D71D8(void *);
extern int func_021D7060(void);
extern int func_021D7120(void);
int func_021D6FB0(char *p)
{
    unsigned int state;
    if (*(int *)(p + 0x3dc) == 0x55f4) return 1;
    state = func_021D85C0();
    *(unsigned int *)(p + 0x140) = state;
    if (state != *(unsigned int *)(p + 0x144)) {
        switch (state) {
        case 7:
            *(int *)(p + 0x168) = 1;
            *(int *)(p + 0x16c) = 0;
            *(int *)(p + 0x170) = 7;
            *(int *)(p + 0x164) = 1;
            *(void **)(p + 0x3fc) = func_021D7120;
            break;
        case 8:
            *(void **)(p + 0x3fc) = func_021D7060;
            func_021D71D8(p);
            break;
        case 9:
            *(int *)(p + 0x168) = 0;
            *(int *)(p + 0x16c) = 0;
            *(int *)(p + 0x170) = func_021D85DC();
            *(int *)(p + 0x164) = 1;
            *(void **)(p + 0x3fc) = func_021D7120;
            break;
        case 0: case 1: case 2: case 3: case 4: case 5: case 6:
        default: break;
        }
        *(unsigned int *)(p + 0x144) = *(unsigned int *)(p + 0x140);
    }
    return 1;
}
int func_021D7060(void) { return 1; }
