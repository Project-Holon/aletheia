/*
 * function: func_0202EF60
 * address:  0x0202EF60
 * packet:   pkt_0202EC44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0204384C  0x0204384C  arm
 *   g_020A7814     0x020A7814  data
 */
typedef unsigned char u8;
typedef unsigned int  u32;
typedef unsigned short u16;

struct Obj {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u16 unk10;
    u8  pad[0xa];
};

extern void *func_02030734(void *heap, u32 size, u32 flags, const void *file, u32 line);
extern void *func_0204384C(u32 a, u32 b, u32 c, u32 d);
extern const char g_020A7814[];

struct Obj *func_0202EF60(u32 heap)
{
    struct Obj *obj = func_02030734((void *)heap, 0x1c, 0, g_020A7814, 0xa6);

    obj->unk10 = (u16)heap;
    obj->unk0C = (u32)func_0204384C(0xc6, 0, 1, obj->unk10);
    obj->unk08 = 0;
    obj->unk00 = 0;
    obj->unk04 = 0;
    return obj;
}
