/*
 * function: func_021DC8B4
 * address: 0x021DC8B4
 * packet: pkt_ov175_021DC8B4
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   func_0200853C 0x0200853C thumb
 *   NHTTP_RAP_Create 0x021B9800 thumb ov114
 *   d_021E2EF8 0x021E2EF8 data
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern const char d_021E2EF8[];
extern void func_02034714(const char *, unsigned, const char *);
extern u8 *GAME_DATA_GetMyStatus(void *);
struct Sub0200852CObj;
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern u8 *NHTTP_RAP_Create(int, int, int);
typedef struct { u32 a, b; } W;
void func_021DC8B4(u8 *p, const W *src, int x)
{
    if (*(u32 *)(p + 0x121C) != 0)
        func_02034714(d_021E2EF8, 0, d_021E2EF8);
    *(u8 **)(p + 0x121C) = NHTTP_RAP_Create(x, func_0200853C((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(*(void **)(p + 8))), *(int *)(p + 0x10));
    *(W *)(p + 0x1228) = *src;
    *(u32 *)(p + 0x12C) = 0;
}
