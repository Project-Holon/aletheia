/*
 * function: func_021BF950
 * address: 0x021BF950
 * packet: pkt_ov099_021BF950
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: pointer addition spells base + index + 0x24, avoiding indexed strb.
 * symbols:
 *   func_02006224 0x02006224 thumb
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021C2874 0x021C2874 thumb ov099
 *   func_021C23C8 0x021C23C8 thumb ov099
 *   func_021BDE30 0x021BDE30 thumb ov099
 *   func_021C18C8 0x021C18C8 thumb ov099
 *   func_021C19DC 0x021C19DC thumb ov099
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAADC 0x021BAADC thumb ov099
 *   func_021BC090 0x021BC090 thumb ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_02006224(int);
extern void *func_021C23B8(int);
extern int func_021C2874(void *);
extern int func_021C23C8(char *, int);
extern void func_021BDE30(char *, int, int);
extern void func_021C18C8(char *, int, unsigned);
extern void func_021C19DC(char *, int);
extern void func_021BA874(char *, int);
extern void func_021BAADC(char *, int, int);
extern void func_021BC090(char *);
int func_021BF950(char *p, int ret)
{
    int i = *(u16 *)(p + 0x242) - 1;
    if (func_02006224(0)) return ret;
    *(*(u8 **)(p + 0x248) + i + 0x24) = func_021C2874(func_021C23B8(i));
    if (i >= 0 && i < 32 && func_021C23C8(p, i)) {
        *(int *)(p + 0x1c4) = 0xe10;
        func_021BDE30(p, 4, 3);
        func_021C18C8(p, 4, 3);
        func_021C19DC(p, 0x21);
        func_021BA874(p, i);
        *(int *)(p + 0x1c4) = 0xe10;
        func_021BAADC(p, 0x5e, 0);
        func_021BC090(p);
        *(int *)(p + 0x1cc) = 0x25;
        *(u8 *)(p + 0x1350) = *(u16 *)(p + 0x242);
        return ret;
    }
    *(int *)(p + 0x1cc) = 0xb;
    return ret;
}
