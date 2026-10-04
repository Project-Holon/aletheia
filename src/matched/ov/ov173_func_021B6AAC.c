/*
 * function: func_021B6AAC
 * address: 0x021B6AAC
 * packet: pkt_ov173_021B6AAC
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027974 0x02027974 thumb
 *   func_02027858 0x02027858 thumb
 *   func_021B81B0 0x021B81B0 thumb ov173
 *   d_021B8228 0x021B8228 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int (*Callback)(u8 *);
typedef struct { Callback a,b; } Pair;
extern Pair d_021B8228[];
struct TaskMenu;
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern void func_02027974(u32);
extern void func_02027858(struct TaskMenu *m);
extern void func_021B81B0(int);
int func_021B6AAC(u8 *p)
{
    int result=4;
    if (func_020279E8((struct TaskMenu *)(*(u32 *)(p+0x1e0)))) {
        if (func_02027A04((const u8 *)(*(u32 *)(p+0x1e0))) == 0)
            result=d_021B8228[p[0x1ba]].a(p);
        else
            result=d_021B8228[p[0x1ba]].b(p);
        func_021B81B0(0);
    }
    func_02027974(*(u32 *)(p+0x1e0));
    if (result != 4) func_02027858((struct TaskMenu *)(*(u32 *)(p+0x1e0)));
    return result;
}
