/*
 * function: func_021B7F64
 * address: 0x021B7F64
 * packet: pkt_ov173_021B7F64
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02026124 0x02026124 thumb
 *   func_0202614C 0x0202614C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Sound;
extern void func_02026124(struct Sound *obj, u32 idx);
extern void func_0202614C(struct Sound *obj, u32 idx);
void func_021B7F64(char *p)
{
    if (*(u8 *)(p + 0x1b8) < 4) {
        func_02026124(*(void **)(p + 0x1c8), 4);
        func_02026124(*(void **)(p + 0x1c8), 5);
        return;
    }
    if (*(u16 *)(*(char **)p + 0x16) == 0)
        func_02026124(*(void **)(p + 0x1c8), 5);
    else
        func_0202614C(*(void **)(p + 0x1c8), 5);
    if (*(u16 *)(*(char **)p + 0x16) + 4 >= *(u8 *)(p + 0x1b8)) {
        func_02026124(*(void **)(p + 0x1c8), 4);
        return;
    } else {
        func_0202614C(*(void **)(p + 0x1c8), 4);
        return;
    }
}
