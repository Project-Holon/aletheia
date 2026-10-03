/*
 * function: func_0221303C
 * address: 0x0221303C
 * packet: pkt_ov199_0221303C
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02213808 0x02213808 thumb ov199
 *   func_0221380C 0x0221380C thumb ov199
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_020307B0(void *);
extern void func_02213808(char *, int);
extern void func_0221380C(void *);
int func_0221303C(char *p, char *q, char *work)
{
    int mode = *(int *)(q + 0x1c);
    func_020307B0(q);
    switch (mode) {
    case 0:
        *(int *)(work + 0x20) = 0;
        func_02213808(p, 1);
        break;
    case 1:
        if (*(int *)(work + 0xc) == 0) func_02213808(p, 0);
        else func_0221380C(p);
        break;
    }
    return 1;
}
