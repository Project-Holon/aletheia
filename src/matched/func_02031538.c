/*
 * function: func_02031538
 * address:  0x02031538
 * packet:   pkt_020314F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02030734       0x02030734  arm
 *   func_02031538_File  0x020A783C  data
 *
 * Build a 0x20-byte object from the allocator and fill its tail with the
 * three parameters.  The allocator is three-parameter with the size second
 * (see func_0203159C), plus __FILE__/__LINE__; 0x162 does not fit an ARM
 * immediate so it costs its own pool word loaded early into ip.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02031538.c \
 *       --func func_02031538 --addr 0x02031538 --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef unsigned short u16;

struct Obj02031538 {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
};

extern const char func_02031538_File[];

extern void *func_02030734(u32 heap, u32 size, u32 align, const char *file,
                           u32 line);

struct Obj02031538 *func_02031538(u32 a0, u32 a1, u32 a2, u32 heap)
{
    struct Obj02031538 *obj;

    obj = (struct Obj02031538 *)func_02030734(heap, 0x20, 0,
                                              func_02031538_File, 0x162);
    obj->f04 = a0;
    obj->f00 = a1;
    obj->f08 = 0;
    obj->f0c = 0;
    obj->f10 = a2;
    obj->f14 = 0;
    obj->f18 = 0;
    obj->f1c = 0;
    return obj;
}
