/*
 * function: func_021B75A8
 * address: 0x021B75A8
 * packet: pkt_ov093_021B75A8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D4270 0x021D4270 thumb ov093
 *   func_021D4294 0x021D4294 thumb ov093
 *   func_021D4348 0x021D4348 thumb ov093
 *   func_021D4360 0x021D4360 thumb ov093
 *   func_021D4378 0x021D4378 thumb ov093
 *   func_021BA1A8 0x021BA1A8 thumb ov093
 *   func_021D43B8 0x021D43B8 thumb ov093
 *   func_021D440C 0x021D440C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 w[6]; } Copy;
typedef struct { u8 a:1; u8 b:1; u8 c:1; } Bits;
typedef struct { u8 a:4; u8 b:4; } Nibbles;
extern int func_021D4270(void);
extern int func_021D4294(u8);
extern int func_021D4348(void);
extern int func_021D4360(void);
extern u8 func_021D4378(void);
extern int func_021BA1A8(void *,int);
extern u32 func_021D43B8(void *);
extern int func_021D440C(void *);
int func_021B75A8(u8 *p,u32 *state)
{
    u8 *q;
    if (func_021D4270()) {
        ((Bits *)(p + 0x473))->a = 1;
        return 1;
    }
    switch (*state) {
    case 0:
        if (func_021D4294(p[0x46c])) ++*state;
        break;
    case 1:
        if (func_021D4348()) {
            p[0x46a] = 0;
            p[0x46e] = func_021D4360();
            (*(u8 **)p)[0x91] = func_021D4378();
            if (func_021D4360()) *state = 2;
            else *state = 3;
        }
        break;
    case 2:
        *(Copy *)(p + 0x408) = *(Copy *)(p + 0x3f0);
        *(u16 *)(p + 0x420) = *(u16 *)(*(u8 **)p + 0x86);
        *(u16 *)(p + 0x422) = *(u16 *)(*(u8 **)p + 0x74);
        *(u16 *)(p + 0x424) = *(u16 *)(*(u8 **)p + 0x76);
        if (func_021BA1A8(p,0x1000)) {
            p[0x426] = *(u32 *)(p + 0x43c);
            ((Nibbles *)(p + 0x427))->a = ((Bits *)(p + 0x473))->c;
        } else {
            p[0x426] = 2;
            ((Nibbles *)(p + 0x427))->a = 1;
        }
        if (func_021D43B8(p + 0x408)) ++*state;
        break;
    case 3:
        if (func_021D440C(p + 0x408)) {
            q = *(u8 **)p;
            *(u16 *)(q + 0x86) = *(u16 *)(p + 0x420);
            *(Copy *)(q + 0x9c) = *(Copy *)(p + 0x408);
            *(Copy *)(p + 0x3f0) = *(Copy *)(p + 0x408);
            ((Bits *)(p + 0x473))->c = ((Nibbles *)(p + 0x427))->a;
            *(u32 *)(p + 0x43c) = p[0x426];
            *(u16 *)(p + 0x440) = *(u16 *)(p + 0x422);
            *(u16 *)(p + 0x442) = *(u16 *)(p + 0x424);
            return 1;
        }
        break;
    }
    return 0;
}
