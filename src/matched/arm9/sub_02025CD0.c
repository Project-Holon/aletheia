/*
 * function: CURSOR_MOVE_Create
 * address:  0x02025CD0
 * packet:   pkt_02025C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02030734  0x02030734  arm
 *   str_020A74A0  0x020A74A0  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char str_020A74A0[];

struct Struct_02025CD0 {
    u32 field_0;
    u32 field_4;
    u32 field_8;
    u8 field_C;
    u8 field_D;
    u8 field_E;
    u8 field_F;
    int field_10;
    int field_14;
    u32 field_18;
    u32 field_1C;
};

struct Struct_02025CD0 *CURSOR_MOVE_Create(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 heapId)
{
    struct Struct_02025CD0 *p = (struct Struct_02025CD0 *)sub_02030734(heapId, 0x20, 0, str_020A74A0, 0x6a);

    p->field_0 = a0;
    p->field_18 = a1;
    p->field_1C = a2;
    p->field_C = 0;
    p->field_4 = a3;
    p->field_8 = 0;
    p->field_D = a4;
    p->field_E = 0xff;
    p->field_F = 0xff;
    p->field_10 = -1;
    p->field_14 = -1;

    return p;
}
