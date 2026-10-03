/*
 * function: func_021E0D38
 * address: 0x021E0D38
 * packet: pkt_ov183_021E0D38
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 021E0D8E alignment padding.
 * symbols:
 *   func_0204B404 0x0204B404 arm
 *   func_0204B8C4 0x0204B8C4 arm
 */
typedef unsigned char u8;
typedef short s16;
struct Coordinates { u8 pad[0x298]; u8 rect[32][4]; };
extern void func_0204B404(void *, s16 *, int);
typedef unsigned int   u32;
struct Obj;
extern void func_0204B8C4(struct Obj *p, u32 value);
void func_021E0D38(struct Coordinates *p, int index)
{
    int width = p->rect[index + 12][1] - p->rect[index + 12][0];
    int height = p->rect[index + 12][3] - p->rect[index + 12][2];
    s16 pos[2];
    pos[0] = height / 2 + p->rect[index + 12][2];
    pos[1] = width / 2 + p->rect[index + 12][0];
    func_0204B404(*(void **)((char *)p + 0x1b0), pos, 1);
    func_0204B8C4(*(void **)((char *)p + 0x1b0), 0);
}
