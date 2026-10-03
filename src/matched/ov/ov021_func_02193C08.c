/*
 * function: func_02193C08
 * address:  0x02193C08
 * packet:   pkt_ov021_02193C08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021867C4  0x021867C4  thumb  ov020
 *   func_02030734  0x02030734  arm
 *   func_02193F6C  0x02193F6C  thumb  ov021
 *   func_020490F4  0x020490F4  arm
 *   func_02186830  0x02186830  thumb
 *   d_021DDA60     0x021DDA60  data  a4
 */

typedef unsigned char u8;

extern int d_021DDA60;
extern int *func_021867C4(int a, int id);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern void func_02193F6C(void *);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_02186830(int, int, int);

void func_02193C08(char *p, int heap)
{
    int i;

    if (*(int *)(p + 0xc) == 0) {
        i = 0;
        *(int *)(p + 0xc) = (int)func_021867C4(0, heap);
        *(void **)(p + 4) = func_02030734(heap, 0x320, 1, (const char *)&d_021DDA60, 0x39e);
        for (i = 0; i < 10; i++) {
            func_02193F6C((char *)*(int *)(p + 4) + i * 0x50);
        }
        *(void **)(p + 0x10) = func_020490F4(0x9a, heap);
        *(void **)(p + 0x14) = func_02030734(heap, 0x600, 1, (const char *)&d_021DDA60, 0x3ab);
        *(int *)(p + 0x118) = func_02186830(*(int *)(p + 0xc), *(u8 *)p, heap);
    }
}
