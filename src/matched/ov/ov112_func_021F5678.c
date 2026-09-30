/*
 * function: func_021F5678
 * address: 0x021F5678
 * packet: pkt_ov112_021F5678
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020649D4 0x020649D4 arm
 *   d_02FFFC3C 0x02FFFC3C data a4
 */
typedef unsigned int u32;
extern u32 d_02FFFC3C;
extern void func_020649D4(char *, int);
typedef struct { u32 low:1; u32 paused:1; u32 rest:30; } Flags;
void func_021F5678(char *p)
{
    int i;
    u32 now;
    int delta;
    char *child;
    i = 0;
    now = d_02FFFC3C;
    delta = now - *(u32 *)(p + 24);
    for (; i < *(int *)p; i++) {
        child = (*(char ***)(p + 4))[i];
        if (child && !((Flags *)(child + 236))->paused)
            func_020649D4(child + 40, delta << 12);
    }
    *(u32 *)(p + 24) = now;
}
