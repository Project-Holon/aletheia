/*
 * unit: yes
 * function: func_021DCCEC, func_021DCD14
 * address: 0x021DCCEC
 * packet: pkt_ov093_021DCCEC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: callback followed by store-and-return leaf at 021DCD14.
 * stack: the by-value record begins in the fifth argument slot; the body
 * reads its halfword at +0 and byte at +4 using a common stack base.
 * symbols:
 *   func_021D70AC 0x021D70AC thumb ov093
 *   func_021B9A24 0x021B9A24 thumb ov093
 *   PALANM_IsColorCodeKnown 0x020213C0 thumb
 *   d_021F0AE8 0x021F0AE8 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { u16 h0; u16 pad2; u8 b4; u8 pad5[3]; } Args;
extern u8 func_021D70AC(u8 *);
extern int func_021B9A24(unsigned int a, unsigned int b);
typedef unsigned int   u32;
extern int PALANM_IsColorCodeKnown(u32 a);
extern int d_021F0AE8;
int func_021DCCEC(u8 *a,int b,int c,int d,Args e)
{
    if(c==5) {
        if(!func_021B9A24(func_021D70AC(a),e.b4)) {
            if(PALANM_IsColorCodeKnown(e.h0)) return 1;
        }
    }
    return 0;
}
int *func_021DCD14(int *p) { *p=3; return &d_021F0AE8; }
