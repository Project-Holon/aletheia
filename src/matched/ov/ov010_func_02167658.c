/*
 * function: func_02167658
 * address: 0x02167658
 * packet: pkt_ov010_02167658
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: test the one-bit field directly; == 1 inserts an extra cmp.
 * domain: no index bound assumed; flag base and unsigned scaled offset use modulo-32 address arithmetic, with no fixed-array subscript.
 * address lever: separate flags base and off locals preserve the original base/offset registers; a combined raw address folds i+1, while Row accesses share the scaled pointer.
 * symbols:
 *   func_02194354 0x02194354 thumb ov021
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 used:1; u8 rest:7; u8 pad[3]; u32 f04; u8 tail[20]; } Slot;
typedef struct { void *sys; void *obj; } Work;
typedef struct { u8 pad[28]; Slot slot; } Row;
extern void func_02194354(void *, u32);
void func_02167658(Work *p, int i) {
    Slot *flags;
    u32 off;
    flags = (Slot *)((u32)p + 28u);
    off = (u32)i * 28u;
    if (((Slot *)((u32)flags + off))->used && p->obj != 0) {
        *(u32 *)((u32)p + off + 32u) = 0;
        func_02194354(p->obj, i);
        ((Slot *)((u32)flags + off))->used = 0;
    }
}
