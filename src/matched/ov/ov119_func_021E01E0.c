/*
 * function: func_021E01E0
 * address: 0x021E01E0
 * packet: pkt_ov119_021E01E0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   ZUKAN_SAVE_GetSize 0x0200C9EC thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 */
extern void *ZUKAN_SAVE_GetFromGameData(void *);
extern unsigned ZUKAN_SAVE_GetSize(void);
extern void MI_CpuCopy8(void *, void *, int);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void func_021E01E0(void *h, void *buf)
{
    void *src = ZUKAN_SAVE_GetFromGameData(h);
    MI_CpuCopy8(buf, src, ZUKAN_SAVE_GetSize());
    func_020307B0(buf);
}
