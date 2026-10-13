/*
 * function: func_021B9820
 * address: 0x021B9820
 * packet: pkt_ov218_021B9820
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 *   func_021B64F8 0x021B64F8 thumb ov067
 *   TOUCHBAR_SetButtonSound 0x021B6568 thumb ov067
 *   d_021BAC20 0x021BAC20 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 *f0; u32 f4; int f8; u32 fC, f10, f14; int f18, f1c; } A;
typedef struct { u32 words[24]; } Table;
typedef struct R R;
extern const Table d_021BAC20;
extern void func_02082BCC(void *, u32, u32);
extern R *TOUCHBAR_Create(A *, int);
extern void func_021B64F8(u8 *, u32);
extern void TOUCHBAR_SetButtonSound(unsigned char *p, unsigned int id, int v);
R *func_021B9820(int heap, int id)
{
    Table table = d_021BAC20;
    A config;
    R *p;
    func_02082BCC(&config, 0, sizeof(config));
    config.f0 = (u8 *)&table;
    config.f4 = 3;
    config.f8 = heap;
    config.fC = 1;
    config.f10 = 13;
    config.f14 = 0;
    config.f18 = 0;
    p = TOUCHBAR_Create(&config, id);
    func_021B64F8((u8 *)p, 1);
    TOUCHBAR_SetButtonSound((unsigned char *)p, 4, 0);
    TOUCHBAR_SetButtonSound((unsigned char *)p, 5, 0);
    return p;
}
