/*
 * function: FIELD_G3D_MAP_AreAllTargetValuesRecorded
 * address: 0x0216BA08
 * packet: pkt_ov010_0216BA08
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding at 0216BA3E follows.
 * symbols:
 *   func_0200C0E8 0x0200C0E8 thumb
 *   func_0200C32C 0x0200C32C thumb
 *   func_0200C34C 0x0200C34C thumb
 *   FIELD_G3D_MAP_GetMissionTargetCount 0x0216BB80 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0200C0E8(void *);
struct Blk34;
extern u8 func_0200C32C(struct Blk34 *p);
extern u16 func_0200C34C(struct Blk34 *p, u32 i);
extern int FIELD_G3D_MAP_GetMissionTargetCount(int);
int FIELD_G3D_MAP_AreAllTargetValuesRecorded(void *p)
{
    void *q;
    int i, n;
    q = func_0200C0E8(p);
    n = (u8)FIELD_G3D_MAP_GetMissionTargetCount(func_0200C32C(q));
    for (i = 0; i < n; i++) {
        if (func_0200C34C(q, (u8)i) == 0) return 0;
    }
    return 1;
}
