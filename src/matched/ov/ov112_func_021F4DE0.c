/*
 * function: func_021F4DE0
 * address: 0x021F4DE0
 * packet: pkt_ov112_021F4DE0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x0204F32C has no label witness. 2026-10-04: filed src/matched/arm9/func_0204F32C.c (EXACT, 24 bytes);
 *   once 0x0204F32C is registered (manifest/label) this should resolve to EXACT*. Scratch blocker.log EXACT.
 *   typedef unsigned int u32;
 *   void func_0204F32C(char *p,u32 i,u32 *out) {
 *       *out = *(u32 *)(*(char **)(p+4)+i*40+36);
 *   }
 * follower: 0x021F4E2C vector/flags leaf left unfiled while ARM9 blocks.
 * symbols:
 *   func_0204F2CC 0x0204F2CC arm
 *   func_0204F32C 0x0204F32C arm
 *   sub_02061CA4 0x02061CA4 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct { u16 low:3; u16 bit3:1; u16 rest:12; } Bits;
extern void func_0204F2CC(int p0, int p1, int p2);
typedef signed int     s32;
extern void func_0204F32C(int p0, int p1, int p2);
extern s32 sub_02061CA4(void *p, u32 a, u32 b, s32 size);
void func_021F4DE0(char *p, char *e, void *a2)
{
    u32 first, second;
    if (!((Bits *)e)->bit3) {
        func_0204F2CC((int)(*(void **)(p+4)),*(u32 *)(e+4),(int)(&first));
        func_0204F32C((int)(*(void **)(p+4)),*(u32 *)(e+4),(int)(&second));
        sub_02061CA4((void *)1,first,(u32)(p+18),((second & 0xffff0000) >> 16) * 8);
        *(u16 *)e |= 8;
    }
}
