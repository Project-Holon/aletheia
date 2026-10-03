/*
 * function: func_021BA7CC
 * address: 0x021BA7CC
 * packet: pkt_ov110_021BA7CC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021BA8C2, followed by existing 021BA8C4.
 * prototype: retain visibly loaded unused r0 arguments to BB804 and BC728; BF7C4's live return is read through its 02024158 forwarder.
 * symbols:
 *   func_021C00FC 0x021C00FC thumb ov110
 *   func_021BCB50 0x021BCB50 thumb ov110
 *   func_021BFC20 0x021BFC20 thumb ov110
 *   func_021BFB7C 0x021BFB7C thumb ov110
 *   func_021BBEF4 0x021BBEF4 thumb ov110
 *   func_021BFBA0 0x021BFBA0 thumb ov110
 *   func_021BBF54 0x021BBF54 thumb ov110
 *   func_021BB804 0x021BB804 thumb ov110
 *   func_021BAD2C 0x021BAD2C thumb ov110
 *   func_021BB870 0x021BB870 thumb ov110
 *   func_021BF7C4 0x021BF7C4 thumb ov110
 *   func_021BF6D8 0x021BF6D8 thumb ov110
 *   func_021BAD68 0x021BAD68 thumb ov110
 *   func_021BB8AC 0x021BB8AC thumb ov110
 *   func_021BB814 0x021BB814 thumb ov110
 *   func_021BB82C 0x021BB82C thumb ov110
 *   func_021BC23C 0x021BC23C thumb ov110
 *   func_021BC704 0x021BC704 thumb ov110
 *   func_021BC728 0x021BC728 thumb ov110
 *   func_021BC6F8 0x021BC6F8 thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021C00FC(u8 *);
extern void func_021BCB50(u8 *);
extern void func_021BFC20(u8 *, unsigned);
extern void func_021BFB7C(u8 *p);
extern void func_021BBEF4(u8 *, u8);
extern int func_021BFBA0(u8 *);
extern int func_021BBF54(u8 *);
extern void func_021BB804(u8 *);
extern void func_021BAD2C(u8 *, int);
extern void func_021BB870(u8 *);
extern u32 func_021BF7C4(u8 *);
extern u32 func_021BF6D8(u8 *);
extern void func_021BAD68(u8 *, int);
extern int func_021BB8AC(u8 *);
extern void func_021BB814(u8 *p);
extern int func_021BB82C(u8 *);
extern void func_021BC23C(void *);
extern void func_021BC704(u8 *p, u32 flag);
extern void func_021BC728(u8 *);
extern void func_021BC6F8(void *);
extern void func_021B9CBC(u8 *);
void func_021BA7CC(void *unused, u8 *p)
{
    u8 *q;
    int a, b;
    q = *(u8 **)p;
    switch (*(u32 *)(p + 0x14)) {
    case 0:
        ++*(u32 *)(p + 0x14);
        break;
    case 1:
        if (func_021C00FC(*(u8 **)(q + 0x5c))) {
            func_021BCB50(*(u8 **)(q + 0x64));
            func_021BFC20(*(u8 **)(q + 0x5c), 0);
            func_021BFB7C(*(u8 **)(q + 0x5c));
            func_021BBEF4(*(u8 **)(q + 0x54), 1);
            ++*(u32 *)(p + 0x14);
        }
        break;
    case 2:
        a = func_021BFBA0(*(u8 **)(q + 0x5c));
        b = func_021BBF54(*(u8 **)(q + 0x54));
        if (a && b) {
            func_021BB804(*(u8 **)(q + 0x58));
            func_021BAD2C(*(u8 **)p, 0);
            func_021BB870(*(u8 **)(q + 0x58));
            if (func_021BF7C4(*(u8 **)(p + 4)) || func_021BF6D8(*(u8 **)(p + 4)) != 2) func_021BAD68(p, 1);
            else func_021BAD68(p, 0);
            ++*(u32 *)(p + 0x14);
        }
        break;
    case 3:
        if (func_021BB8AC(*(u8 **)(q + 0x58))) {
            func_021BB814(*(u8 **)(q + 0x58));
            ++*(u32 *)(p + 0x14);
        }
        break;
    case 4:
        if (func_021BB82C(*(u8 **)(q + 0x58))) {
            func_021BC23C(*(u8 **)(q + 0x54));
            func_021BC704(*(u8 **)(q + 0x54), 1);
            func_021BC728(*(u8 **)(q + 0x54));
            func_021BC6F8(*(u8 **)(q + 0x54));
            q[0x74] = 0;
            func_021B9CBC(p);
        }
        break;
    }
}
