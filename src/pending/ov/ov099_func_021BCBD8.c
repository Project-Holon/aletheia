/*
 * unit:     yes
 * function: func_021BCBD8
 * function: func_021BCC4C
 * address:  0x021BCBD8
 * packet:   pkt_ov099_021BCBD8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker: the THM_CALL at +0x50 to func_0201A354 (arm9, unlabelled Thumb
 * tail-call stub, Ilias's) has no witness outside the unit. Verified C for it
 * (match.py one --thumb, no --region, EXACT, 16 bytes):
 *   extern int func_02048F60(int a, int b, int c);   (0x02048F60 arm)
 *   int func_0201A354(int a, int b) { return func_02048F60(0x69, a, b); }
 * The caller passes (t, 0x21).
 *
 * symbols:
 *   d_021C3A30     0x021C3A30  data  a4
 *   func_020307B0  0x020307B0  arm
 *   func_0201A354  0x0201A354  thumb
 *
 * Unit of the lead function plus the unlabelled 12-byte tail-call stub at
 * 0x021BCC4C (mode 0 -> func_021BCBD8).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

extern const u32 d_021C3A30[];
extern void func_020307B0(int p);
extern int func_0201A354(u32 a, int b);

u32 func_021BCBD8(char *p, int m);

u32 func_021BCBD8(char *p, int m)
{
    int a, b, c;
    u8 *rec;
    u32 t;

    switch (m) {
    case 0:
    default:
        a = *(u16 *)(p + 0x134c);
        b = *(u16 *)(p + 0x134e);
        c = *(u8 *)(*(char **)(p + 0x248) + 0x48);
        break;
    case 1:
        rec = *(u8 **)(p + 0x248);
        a = rec[0x21];
        b = rec[0x22];
        c = rec[0x20];
        break;
    }
    t = d_021C3A30[a + b * 4];
    if (*(int *)(p + 0x1348) != 0) {
        func_020307B0(*(int *)(p + 0x1348));
    }
    *(int *)(p + 0x1348) = func_0201A354(t, 0x21);
    if (c != 0) {
        t |= 0x80000000;
    }
    return t;
}

u32 func_021BCC4C(char *p)
{
    return func_021BCBD8(p, 0);
}
