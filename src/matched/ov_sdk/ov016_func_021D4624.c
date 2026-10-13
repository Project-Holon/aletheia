/*
 * function: func_021D4624
 * address:  0x021D4624
 * packet:   pkt_ov016_021D4624
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      Parent_StepDataShare (libdwcutil.TWL.HYB.a(dwc_moveid.o))
 *
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_021D3250 0x021D3250 arm ov016
 *   DWCi_MOV_WH_StepDS 0x021D3904 arm ov016
 *   DWCi_MOV_WH_GetBitmap 0x021D323C arm ov016
 *   DWCi_MOV_WH_GetSharedDataAdr 0x021D38DC arm ov016
 *   gDwcMoveidWork 0x021DE668 data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    char pad0[0x100];
    u8 shared[2][0x44];
    char pad188[0x204 - 0x188];
    int counter;
    int valid[2];
    char pad210[0xa90 - 0x210];
    u8 state;
    char padA91;
    u8 sendKind;
    u8 mode;
    char padA94[0xab0 - 0xa94];
    u16 *buf;
} Wk;

extern Wk *gDwcMoveidWork;

extern void MI_CpuCopy8(void *srcp, void *dstp, u32 size);
extern unsigned int func_021D3250(void);
extern int DWCi_MOV_WH_StepDS(void *data);
extern u16 DWCi_MOV_WH_GetBitmap(void);
extern u16 *DWCi_MOV_WH_GetSharedDataAdr(u16 aid);

void func_021D4624(u16 kind, u16 counter, u8 *data)
{
    u16 i;
    u16 *adr;

    if (gDwcMoveidWork->mode == 1) {
        gDwcMoveidWork->buf[0] = kind;
        gDwcMoveidWork->buf[1] = counter;
        MI_CpuCopy8(data, gDwcMoveidWork->buf + 2, 0x40);
    } else {
        gDwcMoveidWork->counter++;
        gDwcMoveidWork->buf[0] = 0xbc;
        ((u8 *)gDwcMoveidWork->buf)[4] = gDwcMoveidWork->sendKind;
    }
    if (func_021D3250() != 5)
        return;
    if (DWCi_MOV_WH_StepDS(gDwcMoveidWork) == 0) {
        gDwcMoveidWork->counter += 4;
        return;
    }
    if (gDwcMoveidWork->mode == 0) {
        gDwcMoveidWork->counter++;
    } else {
        gDwcMoveidWork->counter = 0;
        if (DWCi_MOV_WH_GetBitmap() != 3) {
            gDwcMoveidWork->state = 0x1b;
            return;
        }
    }
    for (i = 0; i < 2; i++) {
        adr = DWCi_MOV_WH_GetSharedDataAdr(i);
        if (adr != 0) {
            MI_CpuCopy8(adr, gDwcMoveidWork->shared[i], 0x44);
            gDwcMoveidWork->valid[i] = 1;
        } else {
            gDwcMoveidWork->valid[i] = 0;
        }
    }
}
