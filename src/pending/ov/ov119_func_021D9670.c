/*
 * function: func_021D9670
 * address:  0x021D9670
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF (parked)
 *
 * DIFF: codegen, 164/224 bytes.  The image duplicates the whole argument
 * setup of func_0203D3A8 (including its func_020399A8() first argument) in
 * each of the five command arms, with the address-taken byte spilled at a
 * different frame offset per arm (sp+4, sp+3, sp+2, sp+1, sp+0) before a
 * shared `blx func_0203D3A8`; the same C here hoists one setup and one
 * store.  Blocker: stack-slot-per-arm/argument sinking, not evidence.
 *
 * symbols:
 *   func_021D8A24  0x021D8A24  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021D94D4  0x021D94D4  thumb  ov119
 *   func_021D95D0  0x021D95D0  thumb  ov119
 *   func_021D95F0  0x021D95F0  thumb  ov119
 *   func_021D9610  0x021D9610  thumb  ov119
 *   func_021E12AC  0x021E12AC  thumb  ov119
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_02039C68  0x02039C68  arm
 */

typedef unsigned char u8;

extern int func_021D8A24(void *p);
extern void func_021D8E84(void *p, int v);
extern int func_021D94D4(void *p);
extern int func_021D95D0(void *p);
extern int func_021D95F0(void *p);
extern int func_021D9610(void *p);
extern int func_021E12AC(void *p);
extern unsigned int func_020399A8(void);
extern int func_0203D3A8(unsigned int a, unsigned int b, unsigned int c,
                         void *d);
extern void func_02039C68(unsigned int a, unsigned int b, unsigned int c);

void func_021D9670(void *p)
{
    int kind = func_021D8A24(p);
    u8 b;

    if (func_021E12AC(p) == 0)
        return;
    if (kind != 0) {
        if (func_021D94D4(p))
            b = 5;
        else if (func_021D95D0(p))
            b = 7;
        else if (func_021D95F0(p))
            b = 8;
        else if (func_021D9610(p))
            b = 6;
        else
            b = 2;
        if (func_0203D3A8(func_020399A8(), 0xc00, 1, &b) == 0)
            return;
        func_02039C68(func_020399A8(), 0x1b, 8);
        func_021D8E84(p, 0x021DA799);
        return;
    }
    *(u8 *)((char *)p + 0x11e0) = 2;
    *(u8 *)((char *)p + 0x11e1) = 2;
    func_021D8E84(p, 0x021DA799);
}
