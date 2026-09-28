/*
 * function: func_021EC35C
 * address:  0x021EC35C
 * packet:   pkt_ov170_021EC35C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020079BC 0x020079BC thumb
 *   func_021DD2D0 0x021DD2D0 thumb
 *   func_021EC338 0x021EC338 thumb
 *   MIi_CpuCopy32 0x02082A90 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0201BBE8 0x0201BBE8 thumb
 */

extern int func_020079BC(void *save, unsigned box, unsigned slot, int field, int arg);
extern void *func_021DD2D0(char **p, int a, unsigned b);
extern void *func_021EC338(char *p, void *m, void **out);
extern void MIi_CpuCopy32(const void *src, void *dst, unsigned size);
extern void func_020307B0(void *p);
extern unsigned char func_0201BBE8(void *mon);

void func_021EC35C(char **p, int box)
{
    unsigned i;
    void *m;
    void *r;
    void *buf;
    for (i = 0; i < 0x1E; i++) {
        if (func_020079BC(((void **)p[0])[1], box, i, 0xA9, 0) == 0) {
            *(int *)(p[11] + i * 4 + 0x3DF8) = 0;
        } else if (*(int *)(p[0] + 0x24) != 3 && ((unsigned char *)p)[0x14] == ((unsigned char *)p)[0x17]
                   && ((unsigned char *)p)[0x16] == i) {
            *(int *)(p[11] + i * 4 + 0x3DF8) = 0;
        } else {
            m = func_021DD2D0(p, box, i);
            r = func_021EC338(p[11], m, &buf);
            MIi_CpuCopy32(*(void **)((char *)buf + 0x14), p[11] + 0x1B4 + i * 0x200, 0x200);
            func_020307B0(r);
            *(unsigned char *)(p[11] + i + 0x3DB4) = func_0201BBE8(m);
            *(int *)(p[11] + i * 4 + 0x3DF8) = 1;
        }
    }
}
