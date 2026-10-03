/*
 * unit: yes
 * function: func_021BD924, func_021BD97C
 * address: 0x021BD924
 * packet: pkt_ov099_021BD924
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BCBD8 0x021BCBD8 thumb ov099
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 */
extern int func_021BCBD8(char *, int);
struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned short u16;
extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);
int func_021BD924(char *p, int v)
{
    int t;
    if (*(unsigned char *)(p + 0x1352) == 6) {
        *(unsigned char *)(p + 0x1353) = 0x4d;
        *(int *)(p + 0x1cc) = 0x8a;
    } else {
        if (*(int *)(p + 0x135c) == 3 || *(int *)(p + 0x135c) == 1) {
            t = func_021BCBD8(p, 1);
        } else {
            t = func_021BCBD8(p, 0);
        }
        if (func_0203D3A8(func_020399A8(), 0xa06, 4, &t) != 0) {
            *(int *)(p + 0x1cc) = 0x82;
        }
    }
    return v;
}
int func_021BD97C(char *p, int v)
{
    *(unsigned char *)(p + 0x1353) = 0x5e;
    *(int *)(p + 0x1cc) = 0x8a;
    return v;
}
