/*
 * function: func_021E0240
 * address: 0x021E0240
 * packet: pkt_ov119_021E0240
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveBlock1F 0x02012F14 thumb
 *   func_02009D9C 0x02009D9C thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 */
extern void *GAME_DATA_GetSaveBlock1F(void **);
extern unsigned func_02009D9C(void);
extern void MI_CpuCopy8(void *, void *, int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021E0240(void **h, void *dst)
{
    void *src = GAME_DATA_GetSaveBlock1F(h);
    MI_CpuCopy8(dst, src, func_02009D9C());
    func_020307B0(dst);
}
