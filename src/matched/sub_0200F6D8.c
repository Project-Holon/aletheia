/*
 * function: sub_0200F6D8
 * address:  0x0200F6D8
 * packet:   pkt_0200F6D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02030734  0x02030734  arm
 *
 * Zero-fills the module-wide object at 0x0214617C (see sub_0200F6B8.c and
 * sub_0200FBA0.c for the other users of the same global), then calls
 * func_02030734 three times with the same truncated kind value and the same
 * name pointer at 0x020A7234, each time with a different flag mask and a
 * different tag byte passed on the stack, storing each result into the
 * first three words of the object.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200F6D8.c \
 *       --func sub_0200F6D8 --addr 0x0200F6D8 --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern u32 func_02030734(u16 kind, u32 mask, u32 zero, const void *name, u8 tag);

void sub_0200F6D8(u32 kind)
{
    u32 *obj = (u32 *)0x0214617C;
    const void *name = (const void *)0x020A7234;

    MI_CpuFill8(obj, 0, 0x64);

    obj[0] = func_02030734((u16)kind, 1u << 14, 0, name, 0xbb);
    obj[1] = func_02030734((u16)kind, (1u << 14) >> 3, 0, name, 0xbc);
    obj[2] = func_02030734((u16)kind, 0x20, 0, name, 0xbd);
}
