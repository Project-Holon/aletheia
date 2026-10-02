/*
 * function: func_02157760
 * address:  0x02157760
 * packet:   pkt_ov010_02157760
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker: byte-correct; three callees are unlabelled Thumb leaves in ov014
 *   (0x02177BAC, 0x021780C4, 0x02177BCC print as .word runs) whose only caller
 *   image-wide is this function, so no class can attest them. Seeding them into
 *   layout/function_starts.txt (ov014, thumb) lets sole-ref/code resolve them.
 *   0x02177B2C is labelled in ov014 and resolves (label).
 * levers (lane R1): the old 3-slot frame miss was the `sel`/`sel2` locals, which
 *   copy-propagate into one; the original writes p->sel directly and the two stack
 *   slots are the loop-hoisted 0x31B8 address. `(e+0x60) & (q+0x14)` operand order,
 *   and the CRC result in a named local for `cmp r0, r1`.
 *
 * symbols:
 *   func_02177B2C  0x02177B2C  thumb  ov014
 *   func_02177BAC  0x02177BAC  thumb  ov014
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_021780C4  0x021780C4  thumb  ov014
 *   func_02082D44  0x02082D44  arm
 *   func_02177BCC  0x02177BCC  thumb  ov014
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *func_02177B2C(int);
extern void func_02177BAC(int);
extern u16 func_0203F1FC(const u8 *src, u32 len);
extern void func_021780C4(int);
extern void func_02082D44(void *, void *, u32);
extern void func_02177BCC(void);

typedef struct P {
    u8 pad00[0x31B8];
    u8 sel;
} P;

void func_02157760(u8 *q)
{
    P *p = (P *)q;
    u8 *base;

    int i;
    u8 *e;
    int idx;
    u32 crc;

    base = q;
    base = q + 0x7C;

    for (i = 0; i < 16; i++) {
        e = func_02177B2C(i);
        if (e == 0)
            continue;
        if (e[0x5F] != *(u32 *)(q + 0x10)) {
            func_02177BAC(i);
        } else if ((*(u32 *)(e + 0x60) & *(u32 *)(q + 0x14)) == 0) {
            func_02177BAC(i);
        } else if (e[0x5E] != p->sel && p->sel != 0xFF) {
            func_02177BAC(i);
        } else {
            idx = e[0x5C] - 1;
            if (idx >= 0x12)
                continue;
            if (q[idx * 100 + 0xD8] != 0)
                continue;
            crc = func_0203F1FC(e + 8, 0x54);
            if (crc != *(u16 *)e) {
                func_02177BAC(i);
            } else {
                if (p->sel == 0xFF)
                    p->sel = e[0x5E];
                func_021780C4(i);
                func_02082D44(e, base + idx * 100, 100);
                func_02177BCC();
            }
        }
    }
}
