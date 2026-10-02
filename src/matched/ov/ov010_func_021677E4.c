/*
 * function: func_021677E4
 * address: 0x021677E4
 * packet: pkt_ov010_021677E4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * domain: the signed i>=4 guard admits negative indices; raw unsigned scaling preserves the original modulo-32 address arithmetic without a fixed-array bound.
 * address lever: Row supplies the +28 load offset after unsigned scaling; combining +28 with the scaled index folds i+1 and changes the instructions.
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_02172A28 0x02172A28 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 used:1; u8 rest:7; u8 pad[27]; } Slot;
typedef struct { u8 pad[28]; Slot slot; } Row;
extern const char d_02172A28[];
extern void func_02034714(const char *, int, const char *);
int func_021677E4(void *p, int i) {
    if (p == 0 || i >= 4) func_02034714(d_02172A28, 0, d_02172A28);
    return ((Row *)((u32)p + (u32)i * 28u))->slot.used;
}
