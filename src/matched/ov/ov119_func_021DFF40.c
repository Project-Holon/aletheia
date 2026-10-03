/*
 * function: func_021DFF40
 * address: 0x021DFF40
 * packet: pkt_ov119_021DFF40
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * 2026-10-02: the 02045CAC/0201F250/021E0FF4 statements are repeated in both arms of
 *  the 0x11EE test (the compiler tail-merges them), which keeps the 0x834 and 0x724
 *  constants live into the merged tail.
 * symbols:
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_021E0FF4 0x021E0FF4 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DFFE0 0x021DFFE0 thumb ov119
 */
extern int func_021D8AA8(void *);
extern void *func_021D8FA4(void *, int);
extern void func_0201EEF4(void *, int, void *);
extern void func_0201F02C(void *, int, int);
extern void func_02045CAC(void *, unsigned, void *);
extern void func_0201F250(void *, void *, void *);
extern void func_021E0FF4(void *, int, int);
extern void func_021D8E84(void *, int);
extern void func_021DFFE0(void *);
void func_021DFF40(char *p)
{
    void *a;
    if (*(int *)(p + 0xF2C) < 0xC8) {
        return;
    }
    if (func_021D8AA8(p)) {
        a = func_021D8FA4(p, 0);
    } else {
        a = func_021D8FA4(p, 1);
    }
    func_0201EEF4(*(void **)(p + 0x724), 1, a);
    func_0201F02C(*(void **)(p + 0x724), 0, *(int *)(p + 0x834));
    if (*(int *)(p + 0x118C) != 7 && *(int *)(p + 0x118C) != 8) {
        if (*(unsigned char *)(p + 0x11EE)) {
            func_02045CAC(*(void **)(p + 0x720), 0x84, *(void **)(p + 0x73C));
            func_0201F250(*(void **)(p + 0x724), *(void **)(p + 0x738), *(void **)(p + 0x73C));
            func_021E0FF4(p, 1, 0);
        } else {
            func_02045CAC(*(void **)(p + 0x720), 0x31, *(void **)(p + 0x73C));
            func_0201F250(*(void **)(p + 0x724), *(void **)(p + 0x738), *(void **)(p + 0x73C));
            func_021E0FF4(p, 1, 0);
        }
    }
    func_021D8E84(p, (int)func_021DFFE0);
}
