/*
 * function: UI_SCENE_Delete
 * address: 0x021B613C
 * packet: pkt_ov067_021B613C
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 * Parent-cleared leaf of ov218 021B95D0; original loaded overlay 67
 * is proved by its pooled 67 argument to 02034A5C.
 * 021B613C is the eight-byte Thumb ldr-r3/bx-r3 tail call; the pool
 * at 021B6140 holds ARM target 020307B0. The next start is 021B6144.
 */
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void UI_SCENE_Delete(void *p)
{
    func_020307B0(p);
}
