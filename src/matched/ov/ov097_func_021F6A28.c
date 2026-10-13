/*
 * function: func_021F6A28
 * address:  0x021F6A28
 * packet:   pkt_ov097_021F6A28
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 */

typedef unsigned int u32;

extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);

void func_021F6A28(int *p)
{
    int *s;
    int a;
    int b;
    unsigned i;

    s = (int *)p[0];
    if (s[2] == 0) {
        a = s[0];
        b = s[1];
    } else {
        a = s[1];
        b = s[0];
    }
    for (i = 0; i < 3; i++) {
        if (POKEPARTY_GetCount((void *)a) > i)
            p[0xf8 / 4 + i] = (int)POKEPARTY_GetMember((void *)a, i);
        else
            p[0xf8 / 4 + i] = 0;
        if (POKEPARTY_GetCount((void *)b) > i)
            p[0x104 / 4 + i] = (int)POKEPARTY_GetMember((void *)b, i);
        else
            p[0x104 / 4 + i] = 0;
    }
}
