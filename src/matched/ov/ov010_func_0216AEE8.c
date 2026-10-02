/*
 * function: func_0216AEE8
 * address: 0x0216AEE8
 * packet: pkt_ov010_0216AEE8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0215A5E4 0x0215A5E4 thumb ov010
 *   func_0215901C 0x0215901C thumb ov010
 *   func_0216AED0 0x0216AED0 thumb ov010
 *   func_0217C274 0x0217C274 thumb ov018
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0215A5F4(void *p);
extern void *func_0215A5E4(void *a0);
extern u32 func_0215901C(int, int, u32);
extern int func_0216AED0(int, u32);
extern void func_0217C274(int *, int);
void func_0216AEE8(int vm, int *out)
{
    void *ws;
    ws = func_0215A5F4((void *)vm);
    func_0217C274(out, func_0216AED0(vm, func_0215901C(ws, func_0215A5E4((void *)vm), 0x8011)));
}
