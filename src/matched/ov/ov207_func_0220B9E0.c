/*
 * function: func_0220B9E0
 * address:  0x0220B9E0
 * packet:   pkt_0220B9E0
 * region:   ov207
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020355C4  0x020355C4  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0220270C  0x0220270C  thumb
 *   func_02202DC4  0x02202DC4  thumb
 *   func_020355D8  0x020355D8  arm
 *   func_02202228  0x02202228  thumb
 *   d_0220BBEC     0x0220BBEC  data  ov207
 *   d_0220BBF8     0x0220BBF8  data  ov207
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    int v0;
    int v1;
    int v2;
} S3;

extern u8 func_020355C4(void);
extern int  func_02045B38(int a, int b, int c, int d);
extern int  func_02045EC0(int a, int b);
extern void func_02045808(int a);
extern void func_02045C04(int a);
extern void func_0220270C(int *p, int n, S3 *s);
extern int  func_02202DC4(int *p, void *a, void *b);
extern void func_020355D8(int a);
extern void func_02202228(int *p);

extern char d_0220BBEC[];
extern char d_0220BBF8[];

void func_0220B9E0(int *a)
{
    S3 s;

    switch (a[19]) {
    case 0:
    case 3:
        break;
    case 1:
        ((u8 *)a)[0x50] = (func_020355C4() == 0) ? 1 : 0;
        {
            int r5 = func_02045B38(0, 2, 0xe9, *(u16 *)a);
            s.v0 = func_02045EC0(r5, 0);
            s.v1 = func_02045EC0(r5, 1);
            s.v2 = 1;
            func_0220270C((int *)a[21], 4, &s);
            func_02045808(s.v0);
            func_02045808(s.v1);
            func_02045C04(r5);
            a[19] = 2;
        }
        break;
    case 2:
        {
            int r5 = func_02202DC4((int *)a[21], d_0220BBEC, d_0220BBF8);
            if (r5 == -1)
                break;
            func_0220270C((int *)a[21], 0, 0);
            a[19] = 3;
            if (r5 == 0)
                a[16] = 1;
            else
                a[16] = 0;
            func_020355D8(((u8 *)a)[0x50] ? 0 : 1);
        }
        break;
    }
    func_02202228((int *)a[21]);
}
