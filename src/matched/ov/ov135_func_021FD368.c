/*
 * function: func_021FD368
 * address: 0x021FD368
 * packet: pkt_ov135_021FD368
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B878 0x0204B878 arm
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021FFD1C 0x021FFD1C thumb ov135
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void func_0204B878(struct Obj *p, u16 value);
typedef unsigned char  u8;
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_021FFD1C(void *, int, int);
extern void func_020061E4(u32);
void func_021FD368(unsigned char *p, int i)
{
    if (i != *(int *)(p + 0xd4) && i >= 0) {
        func_0204B878((struct Obj *)(*(u32 *)(p + (i + 1) * 4 + 0xd0c)), i * 4 + 16);
        *(int *)(p + 0x28) = 2;
        func_021F4EC0(p, 3, 17);
        *(int *)(p + 0xd4) = i;
        func_021FFD1C(p, i, 0);
        func_020061E4(0x54c);
        *(int *)(p + 0x12e4) = 1;
        *(int *)(p + 0x12fc) = 1;
    }
}
