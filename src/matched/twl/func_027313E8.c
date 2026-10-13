/*
 * function: PMi_PreSleepForNdma
 * address:  0x027313E8
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MI_WaitNDma 0x0272FCB0 arm
 *   MI_StopNDma 0x0272FCE0 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MI_WaitNDma(int ch);
extern void MI_StopNDma(int ch);

typedef struct {
    u32 src;
    u32 dest;
    u32 total;
    u32 wcnt;
    u32 blen;
    u32 fcnt;
    u32 cnt;
} NDmaCh;
#define NDMA ((volatile NDmaCh *)0x04004104)

void PMi_PreSleepForNdma(int ch)
{
    if (NDMA[ch].cnt & 0x10000000) {
        MI_WaitNDma(ch);
        return;
    }
    switch (NDMA[ch].cnt & 0x0F000000) {
    case 0x04000000:
        while (*(volatile u32 *)0x040001A4 & 0x80000000) {
        }
        return;
    case 0x08000000:
    case 0x09000000:
        MI_WaitNDma(ch);
    case 0x0B000000:
        MI_StopNDma(ch);
        return;
    default:
        if (!(NDMA[ch].cnt & 0x20000000)) {
            MI_WaitNDma(ch);
        } else {
            MI_StopNDma(ch);
        }
        return;
    }
}
