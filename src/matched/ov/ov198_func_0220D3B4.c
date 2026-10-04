/*
 * function: func_0220D3B4
 * address: 0x0220D3B4
 * packet: pkt_ov198_0220D3B4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_0201D304 0x0201D304 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct MsgBank;
struct StrObj;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *, u32, u32, u32, u32, u32, u16);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
void func_0220D3B4(char *p, int i)
{
    void *t;
    void *f;
    t = func_02045EC0(*(void **)(p + 0x1EA0), 0x3F);
    func_0201D304(t, *(u32 *)(*(char **)p + 12), 0);
    f = *(void **)(p + 0x1EAC);
    func_0201C724(f, (u32)func_02045770(*(void **)(p + 0x1F70 + i * 8)), 0, 0, (u32)t, *(u32 *)(*(char **)p + 12), 0x3DC0);
    *(u8 *)(p + i * 8 + 0x1F74) = 1;
    func_02045808(t);
}
