/*
 * function: func_02164EB4
 * address:  0x02164EB4
 * packet:   pkt_ov010_02164EB4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clears a 100-byte record and fills its header bitfields from SDK
 * queries; 0x02FFFFA8 is the shared-area halfword read as a cast
 * constant (no relocation).
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_02039414  0x02039414  arm
 *   func_02085D3C  0x02085D3C  arm
 *   func_02087E60  0x02087E60  arm
 *   func_02012944  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Hdr {
    u8 f00;             /* 0x00 */
    u8 f01_lo : 4;      /* 0x01 */
    u8 f01_hi : 4;
    u8 f02_0 : 1;       /* 0x02 */
    u8 f02_1 : 5;
    u8 f02_6 : 1;
    u8 f02_7 : 1;
    u8 f03_0 : 1;       /* 0x03 */
    u8 f03_1 : 1;
    u8 f03_2 : 6;
    u32 f04;            /* 0x04 */
} Hdr;

typedef struct Flags {
    u32 b0 : 1;
    u32 b1 : 4;
    u32 b5 : 1;
    u32 rest : 26;
} Flags;

extern void func_02082BCC(void *p, int v, u32 n);
extern int func_0203D1B4(void);
extern u32 func_02039414(void);
extern int func_02085D3C(void);
extern Flags *func_02087E60(void);
extern u8 *func_02012944(void *p);
extern u32 func_02008530(void *p);

void func_02164EB4(Hdr *p, void *src)
{
    int v;
    int t;

    func_02082BCC(p, 0, 100);
    p->f00 = 3;
    p->f01_lo = (u8)func_0203D1B4();
    p->f01_hi = 3;
    p->f02_0 = (u8)func_02039414();
    p->f02_1 = 0;
    p->f04 = func_02008530(func_02012944(src));
    p->f02_7 = (u8)func_02085D3C();
    p->f02_6 = 0;
    t = (*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15;
    p->f03_1 = (u8)t;
    if (p->f02_7 == 1) {
        v = 1;
        if (func_02087E60()->b0 == 0 || func_02087E60()->b5 == 0)
            v = 0;
        p->f02_6 = v;
    }
}
