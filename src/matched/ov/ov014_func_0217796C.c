/*
 * function: func_0217796C
 * address:  0x0217796C
 * packet:   pkt_0217796C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_pWhPipeWork     0x021797A4  data  a4
 *   func_02177888  0x02177888  thumb
 *   NET_WHPIPE_IsStateScanning  0x02177C1C  thumb
 *   func_02177744  0x02177744  thumb
 *   WIH_SetScanTimerPaused  0x02179664  thumb
 *   WIH_UpdateScanTimer  0x021793F8  thumb
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct Head Head;
struct Head {
    void (*fn)(Head *);
};

void func_02177888(u32 a);
int NET_WHPIPE_IsStateScanning(void);
void func_02177744(void);
void WIH_SetScanTimerPaused(unsigned char v);
void WIH_UpdateScanTimer(void);

void func_0217796C(u32 arg)
{
    Head *p = (Head *)*(u32 *)0x021797A4;
    if (p != 0 && p->fn != 0)
        p->fn(p);
    if (*(u32 *)0x021797A4 != 0)
        func_02177888(arg);
    if (*(u32 *)0x021797A4 != 0) {
        if (NET_WHPIPE_IsStateScanning() != 0)
            func_02177744();
    }
    if (*(u32 *)0x021797A4 != 0) {
        if (*(u16 *)((u8 *)*(u32 *)0x021797A4 + 0xC6C) != 0) {
            WIH_SetScanTimerPaused(1);
            ((u8 *)*(u32 *)0x021797A4)[0xCF3] = 1;
            if (((u8 *)*(u32 *)0x021797A4)[0xCF4] == 0)
                *(u16 *)((u8 *)*(u32 *)0x021797A4 + 0xC6C) -= 1;
        } else {
            WIH_SetScanTimerPaused(0);
            ((u8 *)*(u32 *)0x021797A4)[0xCF3] = 0;
        }
    }
    WIH_UpdateScanTimer();
}
