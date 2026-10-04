/*
 * function: func_021F3AA0
 * address:  0x021F3AA0
 * packet:   pkt_ov053_021F3AA0
 * region:   ov053
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218ECE4  0x0218ECE4  thumb  ov021
 *   _fflt  0x0209BDBC  arm
 *   _fdiv  0x0209CE10  arm
 *   _fleq  0x0209BC0C  arm
 *   _fls   0x0209BC74  arm
 *   _fsub  0x0209CB8C  arm
 *   _fmul  0x0209C77C  arm
 *   _ffix  0x0209C494  arm
 */

extern void *func_02188C58(void *p);
extern void func_0218ECE4(int, int *);

int func_021F3AA0(char *a, int b)
{
    int v[3];
    float x;
    float r;

    func_0218ECE4((int)func_02188C58((void *)b), v);
    x = v[1] / 4096.0f;
    if (x <= *(float *)(a + 0x5c))
        return 0;
    if (*(float *)(a + 0x60) < x)
        return 0x7f;
    r = *(float *)(a + 0x60) - *(float *)(a + 0x5c);
    return (int)(127.0f * (x - *(float *)(a + 0x5c)) / r);
}
