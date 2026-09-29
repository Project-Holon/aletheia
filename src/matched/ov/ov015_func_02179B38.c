/*
 * function: func_02179B38
 * address:  0x02179B38
 * packet:   pkt_ov015_02179B38
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Receive handler for one packet: rejects a length of 0 or over 0xB4 (the
 * over-length case also reports through func_02034714), checks the header
 * checksum at +0 against func_0203F1FC over the rest, filters on the byte
 * at +0xC (through the optional hook at d_0217AB40+0x48), tracks the
 * session words at +4/+8, then hands the payload at +0xE to the callback
 * at d_0217AAC0+0 once per new low nibble of the byte at +3.
 *
 * symbols:
 *   d_0217AB80     0x0217AB80  data   ov015
 *   d_0217AB40     0x0217AB40  data   ov015
 *   d_0217AAAC     0x0217AAAC  data   ov015
 *   d_0217AAC0     0x0217AAC0  data   ov015
 *   d_0217ABA0     0x0217ABA0  data   ov015
 *   func_02034714  0x02034714  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_02179D14  0x02179D14  thumb  ov015
 *   func_02179C98  0x02179C98  thumb  ov015
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct flags_ab80 {
    u8 pad[0xE];
    u8 fE;
    u8 b0 : 1;
    u8 b1 : 1;
};

extern u8 d_0217AB80[];
struct s_ab40 {
    u8 pad[0x38];
    u32 f38;
    u8 pad2[0xC];
    int (*f48)(u8 a, u8 b);
};

struct s_aac0 {
    int (*f0)(u16 id, u8 *data, u16 len);
    u32 f4;
    u32 f8;
    u32 fC;
    u8 f10;
};

extern struct s_ab40 d_0217AB40;
extern u8 d_0217AAAC[];
extern struct s_aac0 d_0217AAC0;
extern u8 d_0217ABA0[];

extern void func_02034714(void *a, int b, void *c);
extern u16 func_0203F1FC(u8 *p, u32 n);
extern void func_02179D14(void);
extern int func_02179C98(void);

typedef int (*filter_fn)(u8 a, u8 b);
typedef int (*recv_fn)(u16 id, u8 *data, u16 len);

void func_02179B38(u8 *pkt, u32 len, u32 type)
{
    u8 buf[6] = {0, 0, 0, 0, 0, 0};
    int lo;
    int hi;
    filter_fn filter;
    recv_fn recv;

    lo = pkt[3] & 0xF;
    hi = pkt[3] >> 4;
    ((struct flags_ab80 *)d_0217AB80)->fE = 1;

    if (len > 0xB4)
        func_02034714(d_0217AAAC, 0, d_0217AAAC);
    if (!(len != 0 && len <= 0xB4))
        return;
    if (*(u16 *)pkt != func_0203F1FC(pkt + 2, len - 2))
        return;

    filter = d_0217AB40.f48;
    if (filter != 0) {
        if (!filter(d_0217AAC0.f10, pkt[0xC]))
            return;
    } else {
        if (d_0217AAC0.f10 != pkt[0xC])
            return;
    }

    if (*(u32 *)(pkt + 8) == d_0217AAC0.f8 &&
        *(u32 *)(pkt + 4) == d_0217AB40.f38) {
        if (!((struct flags_ab80 *)d_0217AB80)->b1) {
            func_02179D14();
            ((struct flags_ab80 *)d_0217AB80)->b1 = 1;
        }
    } else if (*(u32 *)(pkt + 8) == 0 && d_0217AB40.f38 == 0) {
        d_0217AAC0.fC = *(u32 *)(pkt + 4);
        d_0217AB40.f38 = *(u32 *)(pkt + 4);
        return;
    } else if (*(u32 *)(pkt + 8) == d_0217AAC0.f8 &&
               d_0217AB40.f38 == 0) {
        d_0217AAC0.fC = *(u32 *)(pkt + 4);
        d_0217AB40.f38 = *(u32 *)(pkt + 4);
    } else {
        if (((struct flags_ab80 *)d_0217AB80)->b1)
            return;
        if (d_0217AB40.f38 == *(u32 *)(pkt + 4))
            return;
        d_0217AB40.f38 = 0;
        return;
    }

    if (type >= 0xF0)
        return;

    if (d_0217ABA0[1] == 1 && d_0217ABA0[4] == 0) {
        if (hi == d_0217ABA0[2]) {
            if (d_0217ABA0[2] < 0xF)
                d_0217ABA0[2] = d_0217ABA0[2] + 1;
            else
                d_0217ABA0[2] = 0;
            d_0217ABA0[1] = 0;
        } else {
            d_0217ABA0[4] = 1;
        }
    }

    if (type == 0xEE)
        return;
    if (d_0217ABA0[3] == lo)
        return;

    {
        int id = func_02179C98();
        recv = d_0217AAC0.f0;
        if (recv == 0 || recv((u16)id, pkt + 0xE, (u16)(len - 0xE)) != 0)
            d_0217ABA0[3] = lo;
    }
}
