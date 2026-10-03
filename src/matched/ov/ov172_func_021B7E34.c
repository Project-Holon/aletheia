/*
 * function: func_021B7E34
 * address: 0x021B7E34
 * packet: pkt_ov172_021B7E34
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE00C 0x021BE00C thumb ov172
 *   func_0203D644 0x0203D644 arm
 *   func_021B8050 0x021B8050 thumb ov172
 *   func_0203CD98 0x0203CD98 arm
 *   func_0203D010 0x0203D010 arm
 *   func_0203D01C 0x0203D01C arm
 *   func_02179328 0x02179328 thumb ov014
 *   func_021B8130 0x021B8130 thumb ov172
 *   func_021B8614 0x021B8614 thumb ov172
 *   func_0203CFF0 0x0203CFF0 arm
 *   func_02039ACC 0x02039ACC arm
 *   func_020399A8 0x020399A8 arm
 *   func_020399B8 0x020399B8 arm
 *   func_0203A574 0x0203A574 arm
 *   d_021C6ED4 0x021C6ED4 data a4
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_021B8154 0x021B8154 thumb ov172
 *   func_021B8448 0x021B8448 thumb ov172
 *   func_0203CEAC 0x0203CEAC arm
 *   func_0203CDBC 0x0203CDBC arm
 *   func_0203A5E4 0x0203A5E4 arm
 *   func_0200FB24 0x0200FB24 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Flags;
extern u16 func_021BE00C(u16 *p);
extern void func_0203D644(int a);
extern void func_021B8050(void *a, void *b);
extern int func_0203CD98(void);
extern void func_0203D010(void);
extern void func_0203D01C(void);
extern void func_02179328(void *v);
extern int func_021B8130(void *a0, u8 *a1);
extern void func_021B8614(int unused, int unused2, void *p);
extern void func_0203CFF0(void *p);
extern int func_02039ACC(void);
extern u32 func_020399A8(void);
extern u32 func_020399B8(u8 *p);
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern u8 d_021C6ED4[];
extern void func_02039C68(u32 h, u32 a, u32 b);
extern u32 func_02039CB4(u32 h, u32 a, u32 b);
extern void func_021B8154(void *p, char *q);
extern void func_021B8448(void *p, char *q);
extern int func_0203CEAC(int a0);
extern int func_0203CDBC(void);
extern void func_0203A5E4(u32 key);
extern u32 func_0200FB24(void);
void func_021B7E34(void *p, char *q)
{
    u32 h;
    u8 i;
    u8 j;
    func_021BE00C(p);
    switch (*(u32 *)(q + 8)) {
    case 0:
        if (*(u32 *)(q + 0x178) == 0)
            break;
        if (*(u32 *)(q + 0x178) == 5) {
            func_0203D644(0);
            *(u32 *)(q + 8) = 5;
            *(u32 *)(q + 0x174) = *(u32 *)(q + 0x178);
        } else {
            *(u32 *)(q + 8) = 1;
        }
        break;
    case 1:
        func_021B8050(p, q);
        *(u32 *)(q + 8) = 2;
        break;
    case 2:
        if (func_0203CD98() != 1)
            break;
        switch (*(u32 *)(q + 0x178)) {
        case 2:
            func_0203D010();
            *(u32 *)(q + 8) = 7;
            break;
        case 3:
            func_0203D01C();
            func_02179328(func_021B8130);
            *(u32 *)(q + 8) = 3;
            break;
        case 4:
            if (*(u32 *)(q + 0x174) == 2)
                func_021B8614((int)p, (int)q, q + 0x64);
            func_0203CFF0(q + 0x17c);
            *(u32 *)(q + 8) = 3;
            break;
        }
        *(u32 *)(q + 0x174) = *(u32 *)(q + 0x178);
        break;
    case 3:
        if (func_02039ACC() == 1)
            *(u32 *)(q + 8) = 4;
        if (*(u32 *)(q + 0x174) != *(u32 *)(q + 0x178))
            *(u32 *)(q + 8) = 8;
        break;
    case 4:
        if (func_020399B8((u8 *)func_020399A8()) == 1)
            *(u32 *)(q + 8) = 7;
        if (*(u32 *)(q + 0x174) != *(u32 *)(q + 0x178))
            *(u32 *)(q + 8) = 8;
        break;
    case 5:
        h = func_020399A8();
        func_0203A574(0x2000, (u32)d_021C6ED4, 4, (u32)q);
        func_02039C68(h, 8, 0x20);
        *(u32 *)(q + 8) = 6;
        break;
    case 6:
        if (func_02039CB4(func_020399A8(), 8, 0x20) == 1)
            *(u32 *)(q + 8) = 7;
        break;
    case 7:
        func_021B8154(p, q);
        if (*(u32 *)(q + 0x174) != *(u32 *)(q + 0x178))
            *(u32 *)(q + 8) = 8;
        if (*(u32 *)(q + 0x174) == 2)
            func_021B8448(p, q);
        break;
    case 8:
        func_0203CEAC(0);
        *(u32 *)(q + 8) = 11;
        break;
    case 11:
        if (func_0203CDBC() != 1)
            break;
        if (*(u32 *)(q + 0x178) == 1)
            *(u32 *)(q + 8) = 12;
        else
            *(u32 *)(q + 8) = 1;
        break;
    case 9:
        func_02039C68(func_020399A8(), 9, 0x20);
        *(u32 *)(q + 8) = 10;
        break;
    case 10:
        if (func_02039CB4(func_020399A8(), 9, 0x20) == 1) {
            func_0203A5E4(0x2000);
            *(u32 *)(q + 8) = 12;
        }
        if (func_0200FB24() != 0) {
            func_0203A5E4(0x2000);
            *(u32 *)(q + 8) = 12;
        }
        break;
    }
    if (*(u16 *)(q + 0x3d0) != 0) {
        (*(u16 *)(q + 0x3d0))--;
        if (*(u16 *)(q + 0x3d0) == 0) {
            for (i = 0; i < 3; i++)
                for (j = 0; j < 6; j++)
                    *(u8 *)(q + i * 6 + j + 0x2e) = 0xff;
            ((Flags *)(q + 0x2d))->b1 = 0;
        }
    }
}
