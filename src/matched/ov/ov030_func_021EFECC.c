/*
 * function: func_021EFECC
 * address:  0x021EFECC
 * packet:   pkt_ov030_021EFECC
 * region:   ov030
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02049B68  0x02049B68  arm
 *   func_02049740  0x02049740  arm
 *   func_02049990  0x02049990  arm
 *   func_02049238  0x02049238  arm
 *   func_0203D34C  0x0203D34C  arm
 *   func_02043598  0x02043598  arm
 *   d_021F0134     0x021F0134  data  ov030  a4
 *   d_021F0140     0x021F0140  data  ov030  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020490F4(u32 id, u32 heap);
extern void *func_020120F4(void *p);
extern void *func_02012944(void *p);
extern int func_02008550(void *p);
extern void func_02049B68(u32 h, u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 func_02049740(u32 h, u32 id, u32 layer, u32 ofs, u32 size, u32 heap);
extern void func_02049990(u32 h, u32 id, u32 layer, u32 ofs, u32 chrOfs, u32 a5, u32 a6,
    u32 heap);
extern void func_02049238(u32 h);
extern void func_0203D34C(u32 a, u16 heap);
extern void func_02043598(u32 mask, u32 enable);
extern const u32 d_021F0134[];
extern const u32 d_021F0140[];

typedef struct {
    u32 pad0[2];
    u16 heap;
    u16 pad1;
    u32 pad2[2];
    u32 w14;
    void *w18;
} Obj;

void func_021EFECC(Obj *p)
{
    u32 h;
    int i;

    h = func_020490F4(0x1E, p->heap);
    i = func_02008550(func_02012944(func_020120F4(p->w18)));
    func_02049B68(h, d_021F0134[i], 4, 0, 0, p->heap);
    p->w14 = func_02049740(h, d_021F0140[i], 6, 0, 0, p->heap);
    func_02049990(h, 3, 6, 0, (u16)p->w14, 0, 0, p->heap);
    func_02049238(h);
    func_0203D34C(0, p->heap);
    func_02043598(0x10, 1);
}
