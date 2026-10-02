/*
 * function: func_021E4068
 * address: 0x021E4068
 * packet: pkt_ov119_021E4068
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 */
extern int func_020275E4(void);
extern int func_02027618(void);
extern int func_02027614(void);
extern int func_0202761C(int);
extern int func_02027620(int);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204A6C8(void *, int, int, int, unsigned int);
extern int func_0204AC18(void *, int, int, int, int, int, unsigned int);
extern int func_0204AF28(void *, int, int, unsigned int);
extern void func_02049238(void *);
void func_021E4068(char *p)
{
    void *v;
    int a;
    if (*(int *)(p + 0x888) == 0) {
        v = func_020490F4(func_020275E4(), *(unsigned short *)(p + 0x5F4));
        *(int *)(p + 0x8A4) = func_0204A6C8(v, func_02027618(), 0, 1, *(unsigned short *)(p + 0x5F4));
        *(int *)(p + 0x888) = func_0204AC18(v, func_02027614(), 1, 0, 0, 3, *(unsigned short *)(p + 0x5F4));
        a = func_0202761C(2);
        *(int *)(p + 0x8B8) = func_0204AF28(v, a, func_02027620(2), *(unsigned short *)(p + 0x5F4));
        func_02049238(v);
    }
}
