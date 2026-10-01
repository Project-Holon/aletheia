/*
 * function: func_021C15B8
 * address: 0x021C15B8
 * packet: pkt_ov217_021C15B8
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C1610 0x021C1610 thumb ov217
 *   func_021C1628 0x021C1628 thumb ov217
 *   func_021C1638 0x021C1638 thumb ov217
 *   func_021C1648 0x021C1648 thumb ov217
 *   func_021C1658 0x021C1658 thumb ov217
 *   func_021C1670 0x021C1670 thumb ov217
 *   func_021C1680 0x021C1680 thumb ov217
 *   func_021C16C4 0x021C16C4 thumb ov217
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 w0,w4,type,wc,counter; } Rec;
extern void func_021C1610(u32);
extern void func_021C1628(u8 *);
extern void func_021C1638(u8 *);
extern void func_021C1648(u8 *);
extern void func_021C1658(u32);
extern void func_021C1670(u8 *);
extern void func_021C1680(Rec *);
extern void func_021C16C4(void *);
void func_021C15B8(u8 *p)
{
    if (*(u32 *)(p+0x14)==0) {
        switch (*(u32 *)(p+8)) {
        case 0: func_021C1610((u32)p); break;
        case 1: func_021C1628(p); break;
        case 2: func_021C1638(p); break;
        case 3: func_021C1648(p); break;
        case 4: func_021C1658((u32)p); break;
        case 5: func_021C1670(p); break;
        }
    }
    func_021C1680((Rec *)p);
    func_021C16C4(p);
}
