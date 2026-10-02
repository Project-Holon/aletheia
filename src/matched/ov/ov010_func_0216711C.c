/*
 * function: func_0216711C
 * address: 0x0216711C
 * packet: pkt_ov010_0216711C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x02167152 precede the next function.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_02188C54 0x02188C54 thumb ov021
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0201210C(const void *p);
extern void *func_020120F4(const void *);
extern void func_02082BCC(void *, int, int);
extern u16 func_02188C84(void *);
extern u32 func_02188C54(void *);
void func_0216711C(u8 *p, void *sys) {
    void *field;
    field = func_0201210C(sys);
    func_02082BCC(p, 0, 32);
    *(u16 *)p = func_02188C84(field);
    *(void **)(p+4) = sys;
    *(void **)(p+8) = func_020120F4(sys);
    *(void **)(p+12) = field;
    *(u32 *)(p+16) = func_02188C54(field);
}
