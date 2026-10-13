/*
 * function: func_021F8950
 * address: 0x021F8950
 * packet: pkt_ov135_021F8950
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   BMP_MENULIST_Main  0x020200CC  thumb  arm9
 *   BMP_MENULIST_GetListIndex  0x020202EC  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int     s32;
struct Obj;
extern s32 BMP_MENULIST_Main(struct Obj *o);
extern void BMP_MENULIST_GetListIndex(struct Obj *obj, u16 *out);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
int func_021F8950(void *p, u16 *old)
{
    u16 current;
    int result;
    result = BMP_MENULIST_Main(p);
    BMP_MENULIST_GetListIndex(p, &current);
    if (*old != current) {
        if (*old != 0xFFFF) GFL_USE_PlaySeDefaultVolume(0x548);
        *old = current;
    }
    return result;
}
