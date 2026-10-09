/*
 * file:     dwc_rap_p09.c
 * unit:     yes
 * function: func_02155A80, func_02155B00
 * address:  0x02155A80
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021A8264     0x021A8264  data  ov009  a4
 *   func_02082D44  0x02082D44  arm
 *   func_0216B908  0x0216B908  arm
 *   func_02176FD4  0x02176FD4  arm
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    int hdr;            /* 0x000 */
    u8 b4;
    char pad[0x760 - 5];
    int busy;           /* 0x760 */
    char pad2[0x34 - 4];
    u16 v794;           /* 0x794 */
    char pad3[6];
    u8 cnt;             /* 0x79c */
} G;

void func_02082D44(void *src, void *dst, int n);
int func_0216B908(void);
unsigned long func_02176FD4(unsigned long bitmap, void *buffer, int size);
int func_02155A80(void *src, int len, int c);
int func_02155B00(int a, int b);
extern G *d_021A8264;


int func_02155A80(void *src, int len, int c)
{
    int r;

    if (len >= 0x100)
        return 0;
    if (d_021A8264->busy != 0)
        return 0;
    d_021A8264->hdr = c | (d_021A8264->v794 << 8);
    d_021A8264->cnt = d_021A8264->cnt + 1;
    ((u8 *)d_021A8264)[2] = d_021A8264->cnt;
    func_02082D44(src, (char *)d_021A8264 + 4, len);
    d_021A8264->busy = 1;
    r = (u16)func_0216B908();
    if (r != func_02176FD4(r, d_021A8264, len + 4)) {
        d_021A8264->busy = 0;
        return 0;
    }
    return 1;
}


/*
 * Flag test on the three-argument call.
 */
int func_02155B00(int a, int b)
{
    if (func_02155A80((void *)a, b, 3) != 0) {
        return 1;
    }

    return 0;
}
