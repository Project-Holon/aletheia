/*
 * function: func_021E3D04
 * address: 0x021E3D04
 * packet: pkt_ov119_021E3D04
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   POKE_TOOL_DecodeBoxParam  0x02017DBC  thumb  arm9
 *   POKE_TOOL_EncodeBoxParam  0x02017DE4  thumb  arm9
 *   POKE_PERSONAL_Create  0x0201ADE4  thumb  arm9
 *   POKE_PERSONAL_Delete  0x0201AE14  thumb  arm9
 *   POKE_PERSONAL_GetParam  0x0201AE1C  thumb  arm9
 */
typedef unsigned int   u32;
struct Personal;
struct Sav;
extern u32 POKE_TOOL_DecodeBoxParam(struct Sav *p);
extern u32 POKE_TOOL_EncodeBoxParam(struct Sav *p, u32 f);
extern u32 func_02017E88(void *p, u32 id, u32 v);
extern void *POKE_PERSONAL_Create(unsigned int, int, unsigned int);
extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);
extern void POKE_PERSONAL_Delete(void *);
unsigned char func_021E3D04(void *mon, unsigned int heap)
{
    int old;
    unsigned short result;
    int species;
    void *data;
    result = 0;
    old = POKE_TOOL_DecodeBoxParam(mon);
    species = func_02017E88(mon, 5, 0);
    if (func_02017E88(mon, 0xA9, 0)) {
        if (!func_02017E88(mon, 0x4C, 0)) {
            unsigned short form = func_02017E88(mon, 0x6F, 0);
            data = POKE_PERSONAL_Create((unsigned short)species, form, heap);
            result = POKE_PERSONAL_GetParam(data, 0x21);
            POKE_PERSONAL_Delete(data);
        } else {
            result = 1;
            if (species != 0x1EA)
                result = 8;
        }
        result++;
    }
    POKE_TOOL_EncodeBoxParam(mon, old);
    return result;
}
