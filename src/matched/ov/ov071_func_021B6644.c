/*
 * function: func_021B6644
 * address:  0x021B6644
 * packet:   pkt_ov071_021B6644
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02021660  0x02021660  thumb
 *   func_020215EC  0x020215EC  thumb
 *   func_020216B4  0x020216B4  thumb
 *   func_020498F4  0x020498F4  arm
 *   func_02049658  0x02049658  arm
 *   func_020490F4  0x020490F4  arm
 *   func_0203FA08  0x0203FA08  arm
 *   func_02027634  0x02027634  thumb
 *   func_02049238  0x02049238  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02021660(void *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
struct PalAnmSlot;
extern void func_020215EC(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern void func_020216B4(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049658(void *a, u32 b, u32 c, void *d, u32 e, u32 f, u32 g);
extern void *func_020490F4(unsigned int id, u16 heap);
extern void *func_0203FA08(u32 a, u32 b, u32 c);
extern void func_02027634(void *a, u32 b, u32 c, void *d, u32 e);
extern void func_02049238(void *a);
extern void func_020409B4(u32 a);

void func_021B6644(void *a, void *b)
{
    char *d = (char *)a;
    char *r5 = (char *)b;
    void *h;

    func_02021660(*(void **)r5, *(u32 *)(r5 + 0x30), 0x10, 0x61, 0, 0x1c0, 0, 0);
    func_02021660(*(void **)r5, *(u32 *)(r5 + 0x30), 0x11, 0x61, 1, 0x1c0, 0, 0);
    func_02049658(*(void **)(r5 + 0x30), 0xf, 3, 0, 0, 1, 0x61);
    func_020498F4(*(void **)(r5 + 0x30), 0xa, 3, 0, 0, 1, 0x61);
    func_02049658(*(void **)(r5 + 0x30), 0xe, 7, 0, 0, 1, 0x61);
    func_020498F4(*(void **)(r5 + 0x30), 4, 7, 0, 0, 1, 0x61);
    func_020215EC(*(void **)r5, 0x17, 5, 0x61, 0, 0, 0xd0, 0);
    func_020215EC(*(void **)r5, 0x17, 5, 0x61, 1, 0, 0xd0, 0);
    h = func_020490F4(0x53, 0x61);
    *(void **)(d + 0x138) = func_0203FA08(7, 0x80, 1);
    func_02049658(h, 0x1c, 7, *(void **)(d + 0x138), 0x80, 0, 0x61);
    func_02027634(h, 7, 0x61, *(void **)(d + 0x138), 0xc);
    func_020216B4(*(void **)r5, h, 0x1b, 0x61, 1, 0x20, 0xc0);
    func_02049238(h);
    func_020409B4(7);
    func_020409B4(3);
    func_020409B4(7);
}
