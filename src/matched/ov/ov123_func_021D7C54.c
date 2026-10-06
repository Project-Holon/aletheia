/*
 * function: func_021D7C54
 * address: 0x021D7C54
 * packet: pkt_ov123_021D7C54
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021D7CB2 follow the return.
 * symbols:
 *   func_02009390 0x02009390 thumb
 *   func_020093A8 0x020093A8 thumb
 *   func_020093F0 0x020093F0 thumb
 *   func_0203EFC8 0x0203EFC8 arm
 */
struct Sub02009210Ent;
struct Sub02009210Obj;
extern struct Sub02009210Ent *func_02009390(struct Sub02009210Obj *obj, int i);
typedef signed int     s32;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
extern void func_020093A8(struct Sub02009210Obj *obj, int i, const void *src);
extern void func_020093F0(struct Sub02009210Obj *obj, int value);
void func_021D7C54(void *p, char *q)
{
    int changed = 0;
    int i;
    for (i = 0; i < 5; i++) {
        if (func_0203EFC8((const u8 *)func_02009390(p, i), (const u8 *)(q + 0x98 + i * 26), 26)) {
            changed = 1;
            break;
        }
    }
    if (changed) {
        for (i = 0; i < 5; i++) func_020093A8(p, i, q + 0x98 + i * 26);
        func_020093F0(p, 127);
    }
}
