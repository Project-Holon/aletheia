/*
 * function: func_02154ABC
 * address:  0x02154ABC
 * packet:   pkt_ov006_02154ABC
 * region:   ov006
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cleanup helper. The +0xDC word is freed and cleared only when non-NULL;
 * the six blx sites are ARM func_020307B0. The 0x5A<<2 (0x168) field is a
 * Thumb encoding artefact, not evidence of a second pointer.
 *
 * symbols:
 *   func_020130B4  0x020130B4  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef int s32;

extern int func_020130B4(s32);
extern void func_020307B0(void *p);

void func_02154ABC(s32 *p)
{
    s32 v = p[0x37];
    if (v != 0) {
        func_020130B4(v);
        p[0x37] = 0;
    }
    func_020307B0((void *)(*(s32 *)(*(int *)((char *)p + 0x5c) + 0x14)));
    func_020307B0((void *)(*(s32 *)(*(int *)((char *)p + 0x5c) + 0x18)));
    func_020307B0((void *)(*(s32 *)(*(int *)((char *)p + 0x5c) + 0x1c)));
    func_020307B0((void *)(*(s32 *)((char *)p + 0x168)));
    func_020307B0((void *)(*(s32 *)(*(int *)((char *)p + 0x5c))));
    func_020307B0((void *)(*(int *)((char *)p + 0x5c)));
}
