/*
 * function: func_0220680C
 * address:  0x0220680C
 * packet:   pkt_ov094_0220680C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F86B4  0x021F86B4  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_02207D78  0x02207D78  thumb  ov094
 *   func_022005C4  0x022005C4  thumb  ov094
 */

extern int func_021F86B4(void);
extern int func_021F8694(void);
extern int func_02207D78(char *p, int i);
extern int func_022005C4(void *w, int key);

void func_0220680C(char *p)
{
    int a = func_02207D78((char *)func_021F86B4(), *(int *)(p + 0x278));
    int b = func_022005C4((void *)func_021F8694(), *(int *)(p + 0x278));
    int i;

    if ((b | a) == 1) {
        for (i = 0; i < 8; i++)
            *(char *)(p + *(int *)(p + 0x27c) * 8 + i + 0x242) = 0;
    }
}
