/*
 * function: func_021E5098
 * address: 0x021E5098
 * packet: pkt_ov119_021E5098
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: initial guard is a forward goto, with the exit after the body.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020490F4 0x020490F4 arm
 *   func_021D8DD0 0x021D8DD0 thumb ov119
 *   func_02049DF4 0x02049DF4 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   d_021E8530 0x021E8530 data a4
 */
typedef unsigned short u16;
extern char d_021E8530[];
extern int func_02030734(u16, unsigned, int, void *, int);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_021D8DD0(int, int, int, char *);
extern int func_0201BA68(int);
extern int func_0201BABC(int, int, int, int);
extern int func_02049DF4(int, int, int, int *, u16);
extern void func_02082D44(void *, const void *, int);
extern void func_020307B0(int);
extern void func_02049238(int);
void func_021E5098(char *p, int b)
{
    int i, n, x, t, out;
    void *a;
    if (b == 0) *(int *)(p + 0x1184) = func_02030734(*(u16 *)(p + 0x5f4), 0x5ac00, 0, d_021E8530, 0x50b);
    a = func_020490F4(7, *(u16 *)(p + 0x5f4));
    goto check;
body:
    {
        n = b * 30;
        for (i = 0; i < 30; i++) {
            if (b == 24 && i == 6) break;
            x = func_021D8DD0(*(int *)(p + 0x828), b, i, p);
            if (x) x = func_0201BA68(x);
            else x = func_0201BABC(0, 0, 0, 0);
            t = func_02049DF4(a, x, 0, &out, *(u16 *)(p + 0x5f4));
            func_02082D44(*(void **)(out + 0x14), (void *)(*(int *)(p + 0x1184) + n * 512), 512);
            n++;
            func_020307B0(t);
        }
    }
    goto done;
check:
    if (b < 25) goto body;
done:
    func_02049238(a);
}
