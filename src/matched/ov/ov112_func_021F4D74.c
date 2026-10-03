/*
 * function: func_021F4D74
 * address: 0x021F4D74
 * packet: pkt_ov112_021F4D74
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4AA8 0x021F4AA8 thumb ov112
 *   func_021F4F54 0x021F4F54 thumb ov112
 *   func_0204F604 0x0204F604 arm
 *   func_0204F1A0 0x0204F1A0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 low:3; u16 bit3:1; u16 bit4:1; u16 rest:11; } Bits;
extern u16 func_021F4AA8(int);
extern u8 *func_021F4F54(u8 *,int);
extern void func_0204F604(void *,u32,u16 *);
struct Obj0204F1A0;
extern void func_0204F1A0(struct Obj0204F1A0 *a0, u32 a1);
void func_021F4D74(u8 *p, u8 *e, int type, u16 id)
{
    *(u32 *)(e+12) = func_021F4AA8(type);
    *(u8 **)(e+32) = func_021F4F54(*(u8 **)(p+12),type);
    *(u16 *)e = *(u16 *)e & ~8;
    func_0204F604(*(void **)(p+4),*(u32 *)(e+8),&id);
    if (((Bits *)e)->bit4 == 1) func_0204F1A0(*(void **)(p+4),*(u32 *)(e+4));
    *(u16 *)e = *(u16 *)e & ~16;
    *(u32 *)(e+4) = id;
    *(u16 *)e = (*(u16 *)e & ~1) | 1;
    *(u16 *)e |= 2;
}
