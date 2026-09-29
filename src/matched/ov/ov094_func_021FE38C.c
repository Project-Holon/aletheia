/*
 * function: func_021FE38C
 * address:  0x021FE38C
 * packet:   pkt_ov094_021FE38C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Levers: v and k unsigned (bhi/bhs/blo compares); the middle arm is
 * `mode != 8` and the mode==8 arm last, which puts its block after the
 * cross-jumped func_022003C4 call.
 *
 * symbols:
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_022003C4  0x022003C4  thumb  ov094
 *   func_0202142C  0x0202142C  thumb
 */
extern int func_021F8694(void);
extern int func_022003C4(char *p, int key);
extern int func_0202142C(int a0);

unsigned int func_021FE38C(char *p, unsigned int k)
{
    int mode = *(int *)(p + 0x25c);
    unsigned int v;

    if (mode == 9)
        v = func_022003C4((char *)func_021F8694(), *(int *)(p + 0xdc));
    else if (mode != 8)
        v = func_022003C4((char *)func_021F8694(), mode);
    else
        v = func_0202142C(*(unsigned short *)(p + 0x254));
    if (v == 0 || v > 0x19)
        v = 4;
    v--;
    switch (k) {
    case 3:
        k += v;
        break;
    case 0x1d:
        if (v + 1 == 0x19)
            v = 0x10;
        else if (v + 1 >= 0x10)
            v = 3;
        k += v;
        break;
    case 0x2e:
    case 0x2f:
    case 0x30:
    case 0x31:
        k += v << 2;
        break;
    }
    return k;
}
