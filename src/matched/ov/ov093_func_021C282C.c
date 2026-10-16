/*
 * function: BTL_SERVER_FLOW_CheckSickImmunity
 * address: 0x021C282C
 * packet: pkt_ov093_021C282C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_POKEPARAM_GetMajorStatusIndex 0x021D62A8 thumb ov093
 *   BTL_SERVER_FLOW_GetEffectiveWeather 0x021C2AB0 thumb ov093
 *   BTL_POKEPARAM_GetTypePair 0x021D57FC thumb ov093
 *   BTLV_CORE_HasByte 0x021E8D24 thumb ov093
 *   BTL_POKEPARAM_GetValue 0x021D59B4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Slot { u32 a : 3; u32 rest : 29; };
struct Unk021D62A8 { u8 pad[0x1c]; struct Slot e[6]; };
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *, int);
extern int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *);
extern int BTL_SERVER_FLOW_GetEffectiveWeather(u8 *);
extern u16 BTL_POKEPARAM_GetTypePair(void *);
extern int BTLV_CORE_HasByte(int x, int k);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
int BTL_SERVER_FLOW_CheckSickImmunity(u8 *a, struct Unk021D62A8 *b, int c, int d, u8 e)
{
    u16 t;
    if (BTL_POKEPARAM_HasSick(b, c) && e != 2) return 1;
    if (c < 6 && BTL_POKEPARAM_GetMajorStatusIndex(b) && e == 0) return 3;
    if (BTL_SERVER_FLOW_GetEffectiveWeather(a) == 1 && c == 3) return 3;
    if (c == 5) {
        t = BTL_POKEPARAM_GetTypePair(b);
        if (BTLV_CORE_HasByte(t, 8) || BTLV_CORE_HasByte(t, 3)) return 2;
    }
    if (c == 4 && BTLV_CORE_HasByte(BTL_POKEPARAM_GetTypePair(b), 9)) return 2;
    if (c == 3 && BTLV_CORE_HasByte(BTL_POKEPARAM_GetTypePair(b), 14)) return 2;
    if (c == 18 && BTLV_CORE_HasByte(BTL_POKEPARAM_GetTypePair(b), 11)) return 2;
    if (c == 14 && BTL_POKEPARAM_GetMajorStatusIndex(b)) return 3;
    if (c == 16 && BTL_POKEPARAM_GetValue((u8 *)b, 16) == 121) return 3;
    return 0;
}
